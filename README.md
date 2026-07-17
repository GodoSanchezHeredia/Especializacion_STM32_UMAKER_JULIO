# Especialización en STM32: Programación a Nivel de Registros

Repositorio oficial del curso de **Especialización en STM32**, orientado al desarrollo de firmware en lenguaje C mediante la configuración directa de los registros del microcontrolador.

## Profesor

**Ing. Godo Sánchez Heredia**

## Microcontrolador principal

Durante el curso se utilizará principalmente el:

**STM32F401RE**

Características principales:

* Arquitectura ARM Cortex-M4.
* Unidad de punto flotante, FPU.
* Frecuencia máxima de 84 MHz.
* Memoria Flash de hasta 512 KB.
* Memoria SRAM de 96 KB.
* GPIO.
* SysTick.
* Temporizadores.
* ADC.
* UART.
* SPI.
* I2C.
* DMA.
* Controlador de interrupciones NVIC.

La tarjeta de desarrollo principal será la:

**NUCLEO-F401RE**

---

# Descripción del curso

Este curso está enfocado en comprender cómo funciona internamente un microcontrolador STM32.

El objetivo no es únicamente utilizar librerías de alto nivel, sino aprender a configurar los diferentes periféricos accediendo directamente a sus registros.

Durante las clases se estudiará cómo interpretar:

* El datasheet.
* El Reference Manual.
* El Programming Manual.
* Los diagramas de bloques.
* El mapa de memoria.
* Los registros de configuración.
* Los campos de bits.
* Las tablas de selección de funciones alternativas.
* Los esquemas eléctricos de la tarjeta.
* Los archivos de cabecera CMSIS.

Esto permitirá comprender qué ocurre internamente cuando se utilizan librerías como HAL o LL.

---

# Objetivos del curso

Al finalizar el curso, el estudiante deberá ser capaz de:

* Comprender la arquitectura básica de un microcontrolador STM32.
* Reconocer la arquitectura ARM Cortex-M4.
* Interpretar el mapa de memoria del microcontrolador.
* Identificar los buses AHB y APB.
* Consultar correctamente un datasheet.
* Consultar correctamente un Reference Manual.
* Configurar los relojes del microcontrolador.
* Configurar GPIO directamente mediante registros.
* Crear bases de tiempo utilizando SysTick.
* Configurar interrupciones mediante NVIC.
* Configurar temporizadores.
* Configurar comunicaciones UART, SPI e I2C.
* Utilizar el ADC.
* Generar señales PWM.
* Crear drivers básicos en lenguaje C.
* Utilizar máscaras y operadores a nivel de bits.
* Depurar firmware desde STM32CubeIDE.
* Analizar registros durante la ejecución.
* Organizar proyectos de firmware de manera modular.
* Utilizar Git y GitHub para controlar versiones.

---

# Contenido del curso

Entre los principales temas del curso se encuentran:

## Fundamentos

* Introducción a los microcontroladores.
* Diferencias entre microcontrolador, microprocesador, PLC y SBC.
* Arquitectura ARM.
* Arquitectura Cortex-M4.
* Registros internos del procesador.
* Mapa de memoria.
* Memoria Flash y SRAM.
* Periféricos mapeados en memoria.
* Buses AHB y APB.
* CMSIS.

## Lenguaje C aplicado a sistemas embebidos

* Tipos de datos.
* Variables locales y globales.
* Variables estáticas.
* Punteros.
* Estructuras.
* Enumeraciones.
* Operadores lógicos.
* Operadores a nivel de bits.
* Máscaras de bits.
* Desplazamientos.
* Uso de `volatile`.
* Uso de `const`.
* Organización en archivos `.c` y `.h`.

## Sistema de reloj

* HSI.
* HSE.
* PLL.
* AHB Prescaler.
* APB1 Prescaler.
* APB2 Prescaler.
* Configuración del sistema a 84 MHz.
* Selección de la fuente de reloj.
* Verificación de las banderas de estabilidad.
* Configuración de latencia de memoria Flash.

## GPIO

* Habilitación del reloj del puerto.
* Registro `MODER`.
* Registro `OTYPER`.
* Registro `OSPEEDR`.
* Registro `PUPDR`.
* Registro `IDR`.
* Registro `ODR`.
* Registro `BSRR`.
* Funciones alternativas.
* Salidas Push-Pull.
* Salidas Open-Drain.
* Resistencias Pull-Up.
* Resistencias Pull-Down.
* Lectura de entradas digitales.
* Control de LED.
* Lectura de pulsadores.

## SysTick

* Temporizador interno del procesador.
* Registro `CTRL`.
* Registro `LOAD`.
* Registro `VAL`.
* Cálculo del valor de recarga.
* Generación de una interrupción cada milisegundo.
* Creación de contadores de tiempo.
* Creación de funciones de retardo.
* Diferencia entre retardos bloqueantes y no bloqueantes.

## Interrupciones

* Concepto de interrupción.
* Excepciones del procesador.
* Controlador NVIC.
* Prioridades.
* Habilitación de interrupciones.
* Interrupciones externas.
* EXTI.
* Rutinas de atención de interrupción.
* Variables compartidas con interrupciones.

## Periféricos

* Temporizadores.
* PWM.
* Input Capture.
* Output Compare.
* ADC.
* UART.
* SPI.
* I2C.
* DMA.
* Watchdog.

---

# Herramientas necesarias

Para desarrollar las prácticas se utilizarán las siguientes herramientas:

* STM32CubeIDE.
* Lenguaje de programación C.
* Git.
* GitHub.
* Tarjeta NUCLEO-F401RE.
* Cable USB.
* Depurador ST-LINK integrado.
* Terminal serial.
* Analizador lógico, cuando sea necesario.
* Multímetro, cuando sea necesario.

---

# STM32CubeIDE

Para mantener la compatibilidad entre los proyectos realizados por el profesor y los estudiantes, se recomienda utilizar:

## STM32CubeIDE 1.19

Los ejemplos del curso serán creados y probados utilizando esta versión.

Página oficial de descarga y documentación:

[Descargar STM32CubeIDE](https://www.st.com/en/development-tools/stm32cubeide.html#documentation)

Durante la instalación se recomienda incluir:

* STM32CubeIDE.
* GNU Tools for STM32.
* STM32CubeProgrammer.
* Controladores ST-LINK.
* Paquetes de soporte para STM32F4.

Después de la instalación se recomienda comprobar:

* Que STM32CubeIDE abre correctamente.
* Que la tarjeta NUCLEO es reconocida.
* Que ST-LINK aparece conectado.
* Que se puede compilar un proyecto.
* Que se puede cargar y depurar el firmware.

---

# Documentación oficial

La documentación oficial será una parte fundamental del curso.

No se busca únicamente copiar configuraciones. El estudiante deberá aprender a encontrar la información correspondiente dentro de los documentos oficiales.

## Datasheet del STM32F401RE

El datasheet contiene:

* Características generales.
* Distribución de pines.
* Encapsulados.
* Características eléctricas.
* Límites de voltaje.
* Corriente máxima.
* Frecuencia máxima.
* Memoria disponible.
* Lista de periféricos.
* Funciones alternativas de los pines.

[STM32F401RE Datasheet](https://www.st.com/resource/en/datasheet/stm32f401re.pdf)

## Programming Manual del Cortex-M4

Este documento describe principalmente el núcleo ARM Cortex-M4.

Incluye:

* Registros del procesador.
* Modelo de programación.
* Stack Pointer.
* Link Register.
* Program Counter.
* Registro de estado.
* Excepciones.
* SysTick.
* NVIC.
* Instrucciones del procesador.
* Modos de operación.

[PM0214 – STM32 Cortex-M4 Programming Manual](https://www.st.com/resource/en/programming_manual/pm0214-stm32-cortexm4-mcus-and-mpus-programming-manual-stmicroelectronics.pdf)

## Reference Manual del STM32F401

Este es el documento principal para programar el STM32F401 a nivel de registros.

Contiene:

* Mapa de memoria.
* Sistema de reloj RCC.
* Registros GPIO.
* Interrupciones EXTI.
* SysCfg.
* Temporizadores.
* ADC.
* UART.
* SPI.
* I2C.
* DMA.
* Watchdog.
* Modos de bajo consumo.
* Descripción de cada registro.
* Posición y función de cada bit.

[RM0368 – STM32F401 Reference Manual](https://www.st.com/resource/en/reference_manual/rm0368-stm32f401xbc-and-stm32f401xde-advanced-armbased-32bit-mcus-stmicroelectronics.pdf)

## User Manual complementario

Documento complementario de STMicroelectronics relacionado con la biblioteca de autodiagnóstico para la familia STM32F4.

[UM3461 – STM32F4 Series User Manual](https://www.st.com/resource/en/user_manual/um3461-stm32f4-series-ulcsaiec-607301603351-selftest-library-user-guide-stmicroelectronics.pdf)

---

# Diferencia entre los documentos

| Documento          | Información principal                                   |
| ------------------ | ------------------------------------------------------- |
| Datasheet          | Pines, características eléctricas y capacidades         |
| Reference Manual   | Registros y funcionamiento de periféricos               |
| Programming Manual | Funcionamiento del núcleo ARM Cortex-M4                 |
| User Manual        | Uso de una tarjeta, biblioteca o herramienta específica |

Para configurar un periférico mediante registros, normalmente se utilizará principalmente el **Reference Manual**.

---

# Metodología para configurar un periférico

Para configurar un periférico durante el curso se seguirá generalmente este procedimiento:

1. Identificar el periférico.
2. Revisar su diagrama de bloques.
3. Identificar en qué bus se encuentra.
4. Habilitar su señal de reloj.
5. Localizar la dirección base del periférico.
6. Identificar los registros necesarios.
7. Limpiar los campos que se configurarán.
8. Escribir la nueva configuración.
9. Habilitar el periférico.
10. Compilar el proyecto.
11. Cargar el firmware.
12. Verificar el funcionamiento.
13. Revisar los registros desde el depurador.

Por ejemplo, antes de utilizar el puerto GPIOA es necesario habilitar su reloj:

```c
RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN;
```

Después se configura el modo del pin:

```c
GPIOA->MODER &= ~(3U << (5U * 2U));
GPIOA->MODER |=  (1U << (5U * 2U));
```

Finalmente se puede cambiar el estado de la salida:

```c
GPIOA->ODR ^= GPIO_ODR_OD5;
```

---

# Programación a nivel de registros

Durante el curso se utilizarán expresiones como:

```c
RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN;

GPIOA->MODER &= ~(3U << (5U * 2U));
GPIOA->MODER |=  (1U << (5U * 2U));

GPIOA->OTYPER &= ~(1U << 5);

GPIOA->OSPEEDR &= ~(3U << (5U * 2U));
GPIOA->OSPEEDR |=  (2U << (5U * 2U));

GPIOA->PUPDR &= ~(3U << (5U * 2U));

GPIOA->ODR ^= GPIO_ODR_OD5;
```

El objetivo no es solamente lograr que el LED encienda.

El estudiante deberá comprender:

* Qué registro se está modificando.
* Qué periférico contiene ese registro.
* En qué bus se encuentra el periférico.
* Por qué se habilita previamente su reloj.
* Qué bits se están limpiando.
* Qué bits se están escribiendo.
* Por qué se utiliza una máscara.
* Qué efecto produce cada configuración.
* Qué relación existe entre el código y el hardware.

---

# Operadores a nivel de bits

La programación de microcontroladores requiere modificar bits individuales dentro de los registros.

Los operadores principales son:

| Operador | Nombre                        | Uso principal                      |                     |
| -------- | ----------------------------- | ---------------------------------- | ------------------- |
| `&`      | AND                           | Limpiar bits o consultar su estado |                     |
| `        | `                             | OR                                 | Colocar bits en `1` |
| `^`      | XOR                           | Invertir bits                      |                     |
| `~`      | NOT                           | Invertir todos los bits            |                     |
| `<<`     | Desplazamiento a la izquierda | Crear máscaras                     |                     |
| `>>`     | Desplazamiento a la derecha   | Extraer o desplazar información    |                     |

---

# Numeración de bits

Los bits se numeran empezando desde cero y de derecha a izquierda.

```text
Número de bit:   7  6  5  4  3  2  1  0
Valor binario:   0  0  1  0  0  0  0  0
                       ↑
                     bit 5
```

En un registro de 32 bits:

```text
Bit:  31 ........................................ 3 2 1 0
```

El bit ubicado más a la derecha es el bit `0`.

---

# Creación de máscaras

Para trabajar con un bit específico se puede utilizar:

```c
1U << numero_bit
```

Por ejemplo, para seleccionar el bit 5:

```text
1U                  = 0000 0001
1U << 5             = 0010 0000
```

Visualmente:

```text
Número de bit:        7 6 5 4 3 2 1 0
Máscara:              0 0 1 0 0 0 0 0
                          ↑
                        bit 5
```

Ejemplo en C:

```c
uint32_t mascara = 1U << 5;
```

Se utiliza el sufijo `U` para indicar que el valor es un entero sin signo.

---

# Operación OR `|`

La operación OR se utiliza principalmente para colocar uno o varios bits en `1` sin modificar los demás.

## Tabla lógica OR

|  A |  B | A OR B |
| -: | -: | -----: |
|  0 |  0 |      0 |
|  0 |  1 |      1 |
|  1 |  0 |      1 |
|  1 |  1 |      1 |

## Ejemplo: colocar el bit 5 en uno

Registro inicial:

```text
W = 0100 1100
```

Se desea colocar el bit 5 en `1`.

Primero se crea la máscara:

```text
1U                  = 0000 0001
1U << 5             = 0010 0000
```

Se realiza la operación OR:

```text
Registro W          = 0100 1100
Máscara             = 0010 0000
                      ---------
Resultado           = 0110 1100
```

Representación visual:

```text
ANTES:              0 1 0 0 1 1 0 0
MÁSCARA:            0 0 1 0 0 0 0 0
                    -----------------
DESPUÉS:            0 1 1 0 1 1 0 0
                        ↑
                     activado
```

En C:

```c
W = W | (1U << 5);
```

Forma abreviada:

```c
W |= (1U << 5);
```

Ejemplo con un registro STM32:

```c
GPIOA->ODR |= GPIO_ODR_OD5;
```

Esto coloca la salida correspondiente al pin 5 en nivel alto.

---

# Operación AND `&`

La operación AND se utiliza para:

* Limpiar bits.
* Aplicar máscaras.
* Consultar el estado de uno o varios bits.

## Tabla lógica AND

|  A |  B | A AND B |
| -: | -: | ------: |
|  0 |  0 |       0 |
|  0 |  1 |       0 |
|  1 |  0 |       0 |
|  1 |  1 |       1 |

Para limpiar un bit normalmente se combina AND con NOT:

```c
REGISTRO &= ~(1U << bit);
```

## Ejemplo: limpiar el bit 7

Registro inicial:

```text
W = 1101 1011
```

Se desea colocar el bit 7 en `0`.

Primero se crea la máscara:

```text
1U                  = 0000 0001
1U << 7             = 1000 0000
```

Luego se invierte:

```text
1U << 7             = 1000 0000
~(1U << 7)          = 0111 1111
```

Finalmente se realiza AND:

```text
Registro W          = 1101 1011
Máscara invertida   = 0111 1111
                      ---------
Resultado           = 0101 1011
```

Representación visual:

```text
ANTES:              1 1 0 1 1 0 1 1
MÁSCARA:            0 1 1 1 1 1 1 1
                    -----------------
DESPUÉS:            0 1 0 1 1 0 1 1
                    ↑
                 limpiado
```

En C:

```c
W = W & ~(1U << 7);
```

Forma abreviada:

```c
W &= ~(1U << 7);
```

Ejemplo con STM32:

```c
GPIOA->ODR &= ~GPIO_ODR_OD5;
```

Esto coloca el pin 5 en nivel bajo.

---

# Operación XOR `^`

La operación XOR se utiliza para invertir el estado de uno o varios bits.

* Si el bit estaba en `0`, pasa a `1`.
* Si el bit estaba en `1`, pasa a `0`.

## Tabla lógica XOR

|  A |  B | A XOR B |
| -: | -: | ------: |
|  0 |  0 |       0 |
|  0 |  1 |       1 |
|  1 |  0 |       1 |
|  1 |  1 |       0 |

## Ejemplo: invertir el bit 5

Estado inicial:

```text
OUT                 = 0000 0000
Máscara             = 0010 0000
                      ---------
Resultado           = 0010 0000
```

Al ejecutar nuevamente la misma operación:

```text
OUT                 = 0010 0000
Máscara             = 0010 0000
                      ---------
Resultado           = 0000 0000
```

En C:

```c
OUT ^= (1U << 5);
```

Ejemplo con STM32:

```c
GPIOA->ODR ^= GPIO_ODR_OD5;
```

Comportamiento:

```text
Ejecución 1: apagado   → encendido
Ejecución 2: encendido → apagado
Ejecución 3: apagado   → encendido
Ejecución 4: encendido → apagado
```

Esta operación se conoce como **toggle**.

---

# Operación NOT `~`

El operador NOT invierte todos los bits de un valor.

```text
Valor original      = 0010 1100
Valor invertido     = 1101 0011
```

En C:

```c
resultado = ~valor;
```

NOT se utiliza frecuentemente junto con AND para limpiar bits:

```c
REGISTRO &= ~(1U << bit);
```

La expresión:

```c
1U << bit
```

genera una máscara que contiene un `1` en la posición seleccionada.

La expresión:

```c
~(1U << bit)
```

genera una máscara que contiene un `0` en la posición seleccionada y `1` en las demás posiciones.

---

# Consultar el estado de un bit

La operación AND también permite comprobar si un bit se encuentra en `1`.

```c
if (REGISTRO & (1U << 5))
{
    // El bit 5 está en 1
}
else
{
    // El bit 5 está en 0
}
```

Ejemplo para leer el pin 13 del puerto C:

```c
if (GPIOC->IDR & GPIO_IDR_ID13)
{
    // El pin está en nivel alto
}
else
{
    // El pin está en nivel bajo
}
```

También puede compararse explícitamente con cero:

```c
if ((GPIOC->IDR & GPIO_IDR_ID13) != 0U)
{
    // Bit activo
}
```

---

# Consultar una bandera

Muchos periféricos contienen banderas de estado.

Por ejemplo, para esperar hasta que el oscilador HSE esté estable:

```c
while ((RCC->CR & RCC_CR_HSERDY) == 0U)
{
    // Esperar
}
```

La expresión:

```c
RCC->CR & RCC_CR_HSERDY
```

aísla la bandera `HSERDY`.

Cuando la bandera sea diferente de cero, significa que el oscilador está listo.

---

# Configurar campos de varios bits

No todos los parámetros ocupan un solo bit.

Algunas configuraciones utilizan campos de dos, tres o más bits.

Por ejemplo, cada pin en el registro `GPIOx_MODER` utiliza dos bits.

| MODERy[1:0] | Modo                |
| ----------- | ------------------- |
| `00`        | Entrada             |
| `01`        | Salida              |
| `10`        | Función alternativa |
| `11`        | Analógico           |

Para el pin 5, los bits correspondientes son:

```text
Bit inicial = pin × 2
Bit inicial = 5 × 2
Bit inicial = 10
```

Por lo tanto, el pin 5 utiliza los bits 10 y 11 del registro `MODER`.

## Limpiar el campo

```c
GPIOA->MODER &= ~(3U << (5U * 2U));
```

El valor `3U` en binario es:

```text
3U = 0000 0011
```

Al desplazarlo 10 posiciones:

```text
3U << 10 = 0000 0000 0000 0000 0000 1100 0000 0000
```

Después de invertirlo, los bits 10 y 11 quedan en cero dentro de la máscara.

## Escribir el modo salida

El modo salida corresponde a `01`.

```c
GPIOA->MODER |= (1U << (5U * 2U));
```

Configuración completa:

```c
GPIOA->MODER &= ~(3U << (5U * 2U));
GPIOA->MODER |=  (1U << (5U * 2U));
```

Primero se limpia el campo y luego se escribe el nuevo valor.

---

# Por qué primero se limpia y después se escribe

Supongamos que un campo de dos bits contiene:

```text
11
```

Se desea cambiarlo a:

```text
01
```

Utilizar únicamente OR no sería suficiente:

```text
11 OR 01 = 11
```

El valor anterior permanecería.

Por eso primero se limpia el campo:

```text
11 AND 00 = 00
```

Después se escribe la nueva configuración:

```text
00 OR 01 = 01
```

En C:

```c
REGISTRO &= ~MASCARA;
REGISTRO |= NUEVO_VALOR;
```

---

# Modificar varios bits al mismo tiempo

También se pueden combinar máscaras.

Para activar los bits 2, 4 y 7:

```c
REGISTRO |= (1U << 2) |
            (1U << 4) |
            (1U << 7);
```

Representación:

```text
Bit 2               = 0000 0100
Bit 4               = 0001 0000
Bit 7               = 1000 0000
                      ---------
Máscara final       = 1001 0100
```

Para limpiar esos mismos bits:

```c
REGISTRO &= ~((1U << 2) |
              (1U << 4) |
              (1U << 7));
```

---

# Desplazamiento a la izquierda `<<`

El operador `<<` desplaza los bits hacia la izquierda.

```text
0000 0001 << 1 = 0000 0010
0000 0001 << 2 = 0000 0100
0000 0001 << 3 = 0000 1000
0000 0001 << 4 = 0001 0000
0000 0001 << 5 = 0010 0000
```

En términos matemáticos:

```text
1 << n = 2ⁿ
```

Ejemplos:

| Expresión | Valor decimal | Valor binario |
| --------- | ------------: | ------------- |
| `1U << 0` |             1 | `0000 0001`   |
| `1U << 1` |             2 | `0000 0010`   |
| `1U << 2` |             4 | `0000 0100`   |
| `1U << 3` |             8 | `0000 1000`   |
| `1U << 4` |            16 | `0001 0000`   |
| `1U << 5` |            32 | `0010 0000`   |
| `1U << 6` |            64 | `0100 0000`   |
| `1U << 7` |           128 | `1000 0000`   |

---

# Desplazamiento a la derecha `>>`

El operador `>>` desplaza los bits hacia la derecha.

```text
1000 0000 >> 1 = 0100 0000
1000 0000 >> 2 = 0010 0000
1000 0000 >> 3 = 0001 0000
```

Se puede utilizar para extraer un campo.

Supongamos que los bits 4 y 5 contienen una configuración:

```c
uint32_t valor = (REGISTRO >> 4) & 0x03U;
```

Primero se desplaza el campo hacia la derecha y luego se aplica una máscara.

---

# Resumen rápido de operaciones

## Colocar un bit en uno

```c
REGISTRO |= (1U << bit);
```

## Colocar un bit en cero

```c
REGISTRO &= ~(1U << bit);
```

## Invertir un bit

```c
REGISTRO ^= (1U << bit);
```

## Consultar un bit

```c
if (REGISTRO & (1U << bit))
{
    // El bit está activo
}
```

## Limpiar un campo

```c
REGISTRO &= ~(mascara << posicion);
```

## Escribir un campo

```c
REGISTRO |= (valor << posicion);
```

## Configurar un campo de forma completa

```c
REGISTRO = (REGISTRO & ~(mascara << posicion)) |
           ((valor & mascara) << posicion);
```

---

# Ejemplo completo: LED en PA5

El LED de usuario de la tarjeta NUCLEO-F401RE se encuentra conectado normalmente al pin PA5.

## Habilitar el reloj de GPIOA

```c
RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN;
```

## Configurar PA5 como salida

```c
GPIOA->MODER &= ~(3U << (5U * 2U));
GPIOA->MODER |=  (1U << (5U * 2U));
```

## Configurar salida Push-Pull

```c
GPIOA->OTYPER &= ~(1U << 5);
```

## Configurar velocidad

```c
GPIOA->OSPEEDR &= ~(3U << (5U * 2U));
GPIOA->OSPEEDR |=  (2U << (5U * 2U));
```

## Desactivar Pull-Up y Pull-Down

```c
GPIOA->PUPDR &= ~(3U << (5U * 2U));
```

## Encender el LED

```c
GPIOA->ODR |= GPIO_ODR_OD5;
```

## Apagar el LED

```c
GPIOA->ODR &= ~GPIO_ODR_OD5;
```

## Cambiar el estado del LED

```c
GPIOA->ODR ^= GPIO_ODR_OD5;
```

---

# Uso del registro BSRR

Para establecer o limpiar salidas GPIO también se puede utilizar el registro `BSRR`.

## Colocar PA5 en uno

```c
GPIOA->BSRR = GPIO_BSRR_BS5;
```

## Colocar PA5 en cero

```c
GPIOA->BSRR = GPIO_BSRR_BR5;
```

El registro `BSRR` permite modificar una salida sin realizar una operación de lectura-modificación-escritura sobre `ODR`.

---

# Ejemplo básico de SysTick

Para crear una interrupción cada milisegundo con un reloj de 84 MHz:

```text
Frecuencia del sistema = 84 000 000 Hz
Tiempo requerido       = 1 ms
Frecuencia requerida   = 1 000 Hz

Valor de recarga:

84 000 000 / 1 000 = 84 000
```

Como SysTick cuenta desde `LOAD` hasta cero:

```c
SysTick->LOAD = 84000U - 1U;
```

Configuración de ejemplo:

```c
void SysTickConfig(uint32_t ticks)
{
    SysTick->CTRL = 0U;
    SysTick->LOAD = ticks - 1U;
    SysTick->VAL  = 0U;

    SysTick->CTRL =
        SysTick_CTRL_CLKSOURCE_Msk |
        SysTick_CTRL_TICKINT_Msk   |
        SysTick_CTRL_ENABLE_Msk;
}
```

Manejador de interrupción:

```c
volatile uint32_t msTicks = 0U;

void SysTick_Handler(void)
{
    msTicks++;
}
```

Función para obtener el tiempo:

```c
uint32_t msGetTicks(void)
{
    return msTicks;
}
```

Retardo básico:

```c
void delay_ms(uint32_t delay)
{
    uint32_t start = msGetTicks();

    while ((msGetTicks() - start) < delay)
    {
        // Esperar
    }
}
```

---

# Organización sugerida del repositorio

Cada carpeta puede corresponder a una clase, práctica o proyecto.

```text
Especializacion_STM32_UMAKER_JULIO/
│
├── Clase_01_Introduccion/
├── Clase_02_Arquitectura_ARM/
├── Clase_03_Operadores_Bit/
├── Clase_04_Clock_Config/
├── Clase_05_GPIO/
├── Clase_06_SysTick/
├── Clase_07_Interrupciones/
├── Clase_08_UART/
├── Clase_09_Timers/
├── Clase_10_PWM/
├── Clase_11_ADC/
├── Clase_12_SPI/
├── Clase_13_I2C/
│
├── Documentacion/
├── Ejercicios/
├── Proyectos/
├── .gitignore
└── README.md
```

---

# Archivos que deben mantenerse en Git

Para los proyectos de STM32CubeIDE se recomienda mantener:

```text
.project
.cproject
.mxproject
*.ioc
Core/
Drivers/
Middlewares/
Startup/
STM32*.ld
README.md
```

Los archivos `.project` y `.cproject` contienen información importante para importar y compilar los proyectos desde STM32CubeIDE.

---

# Archivos que no deben subirse

Se recomienda ignorar:

```text
Debug/
Release/
.metadata/
.settings/
.launch
.DS_Store
Thumbs.db
```

Ejemplo de `.gitignore`:

```gitignore
# Carpetas de compilación
[Dd]ebug/
[Rr]elease/

# Workspace de Eclipse y STM32CubeIDE
.metadata/
.settings/

# Archivos del depurador
.launch

# Archivos temporales de macOS
.DS_Store
.DS_Store?
._*
.Spotlight-V100
.Trashes

# Archivos temporales de Windows
ehthumbs.db
Thumbs.db
```

El archivo `.gitignore` debe colocarse en la raíz del repositorio. Sus reglas se aplicarán también a los proyectos ubicados dentro de las diferentes carpetas.

---

# Recomendaciones para los estudiantes

* Revisar el Reference Manual antes de configurar un periférico.
* Identificar siempre el bus del periférico.
* Habilitar el reloj antes de acceder al periférico.
* Limpiar un campo antes de escribir una nueva configuración.
* Utilizar máscaras de bits.
* Evitar números mágicos.
* Utilizar las definiciones de CMSIS cuando estén disponibles.
* Comentar el propósito de cada configuración.
* No copiar código sin entenderlo.
* Compilar después de realizar cambios pequeños.
* Utilizar el depurador.
* Revisar los registros durante la ejecución.
* Crear funciones pequeñas y específicas.
* Separar el código en archivos `.c` y `.h`.
* Utilizar Git para registrar los avances.
* Realizar commits con mensajes descriptivos.
* No subir carpetas de compilación.
* Mantener una copia actualizada del repositorio.

---

# Convenciones de código

Se recomienda utilizar tipos definidos en `stdint.h`:

```c
uint8_t
uint16_t
uint32_t
int8_t
int16_t
int32_t
```

Para constantes sin signo:

```c
1U
84U
84000U
```

Para variables modificadas por interrupciones o hardware:

```c
volatile uint32_t msTicks;
```

Para registros de solo lectura:

```c
const uint32_t valor;
```

Ejemplo de nombres:

```c
void Clock_Init(void);
void GPIO_Init(void);
void SysTick_ConfigMs(void);
uint32_t msGetTicks(void);
void delay_ms(uint32_t delay);
```

---

# Buenas prácticas

## Evitar números mágicos

En lugar de:

```c
RCC->AHB1ENR |= (1U << 0);
```

puede utilizarse:

```c
RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN;
```

Las dos expresiones pueden ser equivalentes, pero la segunda explica mejor qué bit se está configurando.

## Usar paréntesis

```c
REGISTRO &= ~(3U << (pin * 2U));
```

## Utilizar máscaras

```c
#define GPIO_MODE_MASK  0x03U
```

## Mantener módulos separados

```text
Clock_Config.c
Clock_Config.h
GPIO.c
GPIO.h
SysTick.c
SysTick.h
main.c
```

---

# Filosofía del curso

En este curso no se busca únicamente escribir:

```c
HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, GPIO_PIN_SET);
```

También se busca comprender qué ocurre internamente:

```c
GPIOA->BSRR = GPIO_BSRR_BS5;
```

De esta manera, el estudiante podrá:

* Comprender las librerías existentes.
* Detectar errores con mayor facilidad.
* Optimizar el uso de memoria.
* Reducir dependencias.
* Crear drivers propios.
* Migrar entre diferentes familias de microcontroladores.
* Leer documentación técnica.
* Comprender el comportamiento real del hardware.

---

# Uso académico

Este repositorio contiene material desarrollado con fines educativos para el curso de especialización en microcontroladores STM32.

Los ejemplos pueden utilizarse y modificarse para actividades académicas, prácticas y proyectos, mencionando al autor y profesor del curso.

---

## Información del curso

**Curso:** Especialización en STM32
**Profesor:** Ing. Godo Sánchez Heredia
**Microcontrolador:** STM32F401RE
**Tarjeta:** NUCLEO-F401RE
**Arquitectura:** ARM Cortex-M4
**Entorno de desarrollo:** STM32CubeIDE 1.19
**Lenguaje:** C
**Metodología:** Programación a nivel de registros
