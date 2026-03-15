/*

* stm32f401xx_gpio_driver.h
*
* Created on: March 15, 2026
* Author: Monika
  */

#ifndef INC_STM32F401XX_GPIO_DRIVER_H_
#define INC_STM32F401XX_GPIO_DRIVER_H_

#include "stm32f401xx.h"

/*

* GPIO Pin Configuration Structure
  */

typedef struct
{
uint8_t GPIO_PinNumber;       /* Possible values from @GPIO_PIN_NUMBERS */
uint8_t GPIO_PinMode;         /* Possible values from @GPIO_PIN_MODES */
uint8_t GPIO_PinSpeed;        /* Possible values from @GPIO_SPEED */
uint8_t GPIO_PinPuPdControl;  /* Possible values from @GPIO_PUPD */
uint8_t GPIO_PinOpType;       /* Possible values from @GPIO_OUTPUT_TYPES */
uint8_t GPIO_PinAltFunMode;   /* Possible values from @GPIO_ALT_FUNCTIONS */

} GPIO_PinConfig_t;

/*

* GPIO Handle Structure
  */

typedef struct
{
GPIO_RegDef_t *pGPIOx;        /* Holds the base address of GPIO port */
GPIO_PinConfig_t GPIO_PinConfig;

} GPIO_Handle_t;

/*

* GPIO PIN NUMBERS
  */

#define GPIO_PIN_NO_0        0
#define GPIO_PIN_NO_1        1
#define GPIO_PIN_NO_2        2
#define GPIO_PIN_NO_3        3
#define GPIO_PIN_NO_4        4
#define GPIO_PIN_NO_5        5
#define GPIO_PIN_NO_6        6
#define GPIO_PIN_NO_7        7
#define GPIO_PIN_NO_8        8
#define GPIO_PIN_NO_9        9
#define GPIO_PIN_NO_10       10
#define GPIO_PIN_NO_11       11
#define GPIO_PIN_NO_12       12
#define GPIO_PIN_NO_13       13
#define GPIO_PIN_NO_14       14
#define GPIO_PIN_NO_15       15

/*

* GPIO PIN MODES
  */

#define GPIO_MODE_IN         0
#define GPIO_MODE_OUT        1
#define GPIO_MODE_ALTFN      2
#define GPIO_MODE_ANALOG     3

/* Interrupt modes */

#define GPIO_MODE_IT_FT      4
#define GPIO_MODE_IT_RT      5
#define GPIO_MODE_IT_RFT     6

/*

* GPIO OUTPUT TYPES
  */

#define GPIO_OP_TYPE_PP      0
#define GPIO_OP_TYPE_OD      1

/*

* GPIO OUTPUT SPEEDS
  */

#define GPIO_SPEED_LOW       0
#define GPIO_SPEED_MEDIUM    1
#define GPIO_SPEED_FAST      2
#define GPIO_SPEED_HIGH      3

/*

* GPIO PULL-UP / PULL-DOWN
  */

#define GPIO_NO_PUPD         0
#define GPIO_PIN_PU          1
#define GPIO_PIN_PD          2

/**********************************************************************

* APIs Supported by this driver
  **********************************************************************/

/*

* Peripheral Clock Setup
  */

void GPIO_PeriClockControl(GPIO_RegDef_t *pGPIOx , uint8_t EnorDi);

/*

* Init and DeInit
  */

void GPIO_Init(GPIO_Handle_t *pGPIOHandle);
void GPIO_DeInit(GPIO_RegDef_t *pGPIOx);

/*

* Data Read and Write
  */

uint8_t GPIO_ReadFromInputPin(GPIO_RegDef_t *pGPIOx,uint8_t pinNumber);
uint16_t GPIO_ReadFromInputPort(GPIO_RegDef_t *pGPIOx);

void GPIO_WriteToOutputPin(GPIO_RegDef_t *pGPIOx,uint8_t pinNumber,uint8_t value);
void GPIO_WriteToOutputPort(GPIO_RegDef_t *pGPIOx,uint16_t value);

void GPIO_ToggleOutputPin(GPIO_RegDef_t *pGPIOx,uint8_t pinNumber);

/*

* IRQ Configuration and ISR Handling
  */

void GPIO_IRQConfig(uint8_t IRQNumber,uint8_t IRQPriority,uint8_t EnorDi);
void GPIO_IRQHandling(uint8_t PinNumber);

#endif /* INC_STM32F401XX_GPIO_DRIVER_H_ */
