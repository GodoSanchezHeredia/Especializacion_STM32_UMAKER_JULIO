
#include "main.h"
#include "Clock_Config.h"
#include "Gpio.h"
#include "Systick.h"
#include "Display.h"
#include "ExtInt.h"
#include "defines.h"
#include "USART.h"


#define USART2_TX A, 2
#define USART2_RX A, 3

volatile uint32_t i = 0;

USART_Handle_t husart2;

uint8_t mensaje[] = "caracter invalido\n\r";
uint8_t mensaje1[] =
        "\r\n"
        "========================================\r\n"
        " STM32 - TRANSMISION POR INTERRUPCION\r\n"
        "========================================\r\n"
        "El boton PC13 ha sido presionado.\r\n"
        "Este mensaje se envia byte por byte\r\n"
        "utilizando las interrupciones TXE y TC.\r\n"
        "El CPU puede seguir ejecutando el main.\r\n"
        "========================================\r\n\r\n";

volatile uint8_t rxByte = 0;
uint8_t botonActual;
uint8_t botonAnterior = 1;

void USART_GPIO_INIT(void);

int main(void){

	 Init_Clock_HSE();
	 SystickConfig(84000);
	 USART_GPIO_INIT();
	 USART_Init(USART2, 42E+6, 115200, 0);
	 Gpio_Init(PORT_A, 5,OUTPUT	, OUT2, NO_PULLUP_NO_PULL_DOWN);
	 Gpio_Init(PORT_C, 13, INPUT, OUT2, NO_PULLUP_NO_PULL_DOWN);
	 // USART_SendData(USART2, &mensaje, sizeof(mensaje)-1U);
	 //USART_SendData(USART2, &dato, 1);

	 husart2.pUSARTx = USART2;
	 husart2.TxBusyState = USART_READY;
	 husart2.RxBusyState = USART_READY;

	 USART_IRQPriorityConfig(USART2_IRQn, 1);
	 USART_IRQInterruptConfig(USART2_IRQn, ENABLE);

	 USART_ReceiveDataIT(&husart2, &rxByte, 1U);
	for (;;) {


        botonActual = (GPIOC->IDR & (1U << 13)) ? 1U : 0U;

        if((botonAnterior == 1U) &&
           (botonActual == 0U))
        {

            if(husart2.TxBusyState == USART_READY)
            {

                USART_SendDataIT(&husart2,mensaje1,sizeof(mensaje1) - 1U);
            }

        }


        /* Actualizar estado anterior */
        botonAnterior = botonActual;


	}


}

void USART2_IRQHandler(void){

	USART_IRQHandling(&husart2);
}

void USART_ApplicationEventCallback(USART_Handle_t *pUSARTHandle,uint8_t event){

	if ((pUSARTHandle->pUSARTx==USART2) && (event == USART_EVENT_RX_CMPLT)) {

		switch (rxByte) {
			case 'A':
				Gpio_Write(PORT_A, 5, 1);
				break;
			case 'B':
				Gpio_Write(PORT_A, 5, 0);
				break;
			default:
				USART_SendData(USART2, &mensaje, sizeof(mensaje)-1U);
				break;
		}
		 USART_ReceiveDataIT(&husart2, &rxByte, 1U);

	}
	if(pUSARTHandle->pUSARTx == USART2)
	    {


	        if(event == USART_EVENT_TX_CMPLT)
	        {
	        	Gpio_Write(PORT_A, 5, 1);
	        }

	    }

}


void USART_GPIO_INIT(void){
	RCC->AHB1ENR |= GPIOX_CLOCK(USART2_TX);//PUERTO A
	// PIN TX
	GPIOX_MODER(MODE_ALTER,USART2_TX);
	GPIOX_OSPEEDR(MODE_SPD_VHIGH,USART2_TX);
	GPIOX_AFR(7U,USART2_TX);

	//PIN RX
	GPIOX_MODER(MODE_ALTER,USART2_RX);
	GPIOX_OSPEEDR(MODE_SPD_VHIGH,USART2_RX);
	GPIOX_AFR(7U,USART2_RX);

	return;

}
