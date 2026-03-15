
/*

* stm32f401xx.h
*
* Created on: March 15, 2026
* Author: Monika
  */

#ifndef INC_STM32F401XX_H_
#define INC_STM32F401XX_H_

#include <stdint.h>

#define __vo volatile

/*

* Base addresses of Flash and SRAM memories
  */
  #define FLASH_BASEADDR     0x08000000U
  #define SRAM1_BASEADDR     0x20000000U
  #define SRAM2_BASEADDR     0x2001C000U
  #define ROM_BASEADDR       0x1FFF0000U
  #define SRAM               SRAM1_BASEADDR

/*

* AHBx and APBx Bus Peripheral Base Addresses
  */

#define PERIPH_BASE        0x40000000U
#define APB1PERIPH_BASE    PERIPH_BASE
#define APB2PERIPH_BASE    0x40010000U
#define AHB1PERIPH_BASE    0x40020000U
#define AHB2PERIPH_BASE    0x50000000U

/*

* Base addresses of peripherals on AHB1 Bus
  */

#define GPIOA_BASEADDR     (AHB1PERIPH_BASE + 0x0000)
#define GPIOB_BASEADDR     (AHB1PERIPH_BASE + 0x0400)
#define GPIOC_BASEADDR     (AHB1PERIPH_BASE + 0x0800)
#define GPIOD_BASEADDR     (AHB1PERIPH_BASE + 0x0C00)
#define GPIOE_BASEADDR     (AHB1PERIPH_BASE + 0x1000)
#define GPIOF_BASEADDR     (AHB1PERIPH_BASE + 0x1400)
#define GPIOG_BASEADDR     (AHB1PERIPH_BASE + 0x1800)
#define GPIOH_BASEADDR     (AHB1PERIPH_BASE + 0x1C00)
#define GPIOI_BASEADDR     (AHB1PERIPH_BASE + 0x2000)

#define RCC_BASEADDR       (AHB1PERIPH_BASE + 0x3800)

/*

* Base addresses of peripherals on APB1 Bus
  */

#define I2C1_BASEADDR      (APB1PERIPH_BASE + 0x5400)
#define I2C2_BASEADDR      (APB1PERIPH_BASE + 0x5800)
#define I2C3_BASEADDR      (APB1PERIPH_BASE + 0x5C00)

#define SPI2_BASEADDR      (APB1PERIPH_BASE + 0x3800)
#define SPI3_BASEADDR      (APB1PERIPH_BASE + 0x3C00)

#define USART2_BASEADDR    (APB1PERIPH_BASE + 0x4400)

/*

* Base addresses of peripherals on APB2 Bus
  */

#define EXTI_BASEADDR      (APB2PERIPH_BASE + 0x3C00)
#define SPI1_BASEADDR      (APB2PERIPH_BASE + 0x3000)

#define USART1_BASEADDR    (APB2PERIPH_BASE + 0x1100)
#define USART6_BASEADDR    (APB2PERIPH_BASE + 0x1400)

#define SYSCFG_BASEADDR    (APB2PERIPH_BASE + 0x3800)

/*********************************************************************

* GPIO Register Definition Structure
  *********************************************************************/

typedef struct
{
__vo uint32_t MODER;
__vo uint32_t OTYPER;
__vo uint32_t OSPEEDR;
__vo uint32_t PUPDR;
__vo uint32_t IDR;
__vo uint32_t ODR;
__vo uint32_t BSRR;
__vo uint32_t LCKR;
__vo uint32_t AFR[2];

}GPIO_RegDef_t;

/*********************************************************************

* RCC Register Definition Structure
  *********************************************************************/

typedef struct
{
__vo uint32_t CR;
__vo uint32_t PLLCFGR;
__vo uint32_t CFGR;
__vo uint32_t CIR;
__vo uint32_t AHB1RSTR;
__vo uint32_t AHB2RSTR;
uint32_t RESERVED0[2];
__vo uint32_t APB1RSTR;
__vo uint32_t APB2RSTR;
uint32_t RESERVED1[2];
__vo uint32_t AHB1ENR;
__vo uint32_t AHB2ENR;
uint32_t RESERVED2[2];
__vo uint32_t APB1ENR;
__vo uint32_t APB2ENR;
uint32_t RESERVED3[2];
__vo uint32_t AHB1LPENR;
__vo uint32_t AHB2LPENR;
uint32_t RESERVED4[2];
__vo uint32_t APB1LPENR;
__vo uint32_t APB2LPENR;
uint32_t RESERVED5[2];
__vo uint32_t BDCR;
__vo uint32_t CSR;
uint32_t RESERVED6[2];
__vo uint32_t SSCGR;
__vo uint32_t PLLI2SCFGR;

}RCC_RegDef_t;

/*********************************************************************

* Peripheral Definitions
  *********************************************************************/

#define GPIOA   ((GPIO_RegDef_t*)GPIOA_BASEADDR)
#define GPIOB   ((GPIO_RegDef_t*)GPIOB_BASEADDR)
#define GPIOC   ((GPIO_RegDef_t*)GPIOC_BASEADDR)
#define GPIOD   ((GPIO_RegDef_t*)GPIOD_BASEADDR)
#define GPIOE   ((GPIO_RegDef_t*)GPIOE_BASEADDR)
#define GPIOF   ((GPIO_RegDef_t*)GPIOF_BASEADDR)
#define GPIOG   ((GPIO_RegDef_t*)GPIOG_BASEADDR)
#define GPIOH   ((GPIO_RegDef_t*)GPIOH_BASEADDR)
#define GPIOI   ((GPIO_RegDef_t*)GPIOI_BASEADDR)

#define RCC     ((RCC_RegDef_t*)RCC_BASEADDR)

/*********************************************************************

* Clock Enable Macros
  *********************************************************************/

#define GPIOA_PCLK_EN()    (RCC->AHB1ENR |= (1<<0))
#define GPIOB_PCLK_EN()    (RCC->AHB1ENR |= (1<<1))
#define GPIOC_PCLK_EN()    (RCC->AHB1ENR |= (1<<2))
#define GPIOD_PCLK_EN()    (RCC->AHB1ENR |= (1<<3))
#define GPIOE_PCLK_EN()    (RCC->AHB1ENR |= (1<<4))
#define GPIOH_PCLK_EN()    (RCC->AHB1ENR |= (1<<7))

/*********************************************************************

* Clock Disable Macros
  *********************************************************************/

#define GPIOA_PCLK_DI()    (RCC->AHB1ENR &= ~(1<<0))
#define GPIOB_PCLK_DI()    (RCC->AHB1ENR &= ~(1<<1))
#define GPIOC_PCLK_DI()    (RCC->AHB1ENR &= ~(1<<2))
#define GPIOD_PCLK_DI()    (RCC->AHB1ENR &= ~(1<<3))
#define GPIOE_PCLK_DI()    (RCC->AHB1ENR &= ~(1<<4))
#define GPIOH_PCLK_DI()    (RCC->AHB1ENR &= ~(1<<7))

/*********************************************************************

* GPIO Reset Macros
  *********************************************************************/

#define GPIOA_REG_RESET()  do{ (RCC->AHB1RSTR |= (1<<0)); (RCC->AHB1RSTR &= ~(1<<0)); }while(0)
#define GPIOB_REG_RESET()  do{ (RCC->AHB1RSTR |= (1<<1)); (RCC->AHB1RSTR &= ~(1<<1)); }while(0)
#define GPIOC_REG_RESET()  do{ (RCC->AHB1RSTR |= (1<<2)); (RCC->AHB1RSTR &= ~(1<<2)); }while(0)
#define GPIOD_REG_RESET()  do{ (RCC->AHB1RSTR |= (1<<3)); (RCC->AHB1RSTR &= ~(1<<3)); }while(0)
#define GPIOE_REG_RESET()  do{ (RCC->AHB1RSTR |= (1<<4)); (RCC->AHB1RSTR &= ~(1<<4)); }while(0)
#define GPIOH_REG_RESET()  do{ (RCC->AHB1RSTR |= (1<<7)); (RCC->AHB1RSTR &= ~(1<<7)); }while(0)

/*********************************************************************

* Generic Macros
  *********************************************************************/

#define ENABLE              1
#define DISABLE             0

#define SET                 ENABLE
#define RESET               DISABLE

#define GPIO_PIN_SET        SET
#define GPIO_PIN_RESET      RESET

#endif /* INC_STM32F401XX_H_ */
