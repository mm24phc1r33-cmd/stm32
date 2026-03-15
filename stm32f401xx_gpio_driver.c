#include "stm32f401xx_gpio_driver.h"

/*

* Peripheral Clock Setup
  */

void GPIO_PeriClockControl(GPIO_RegDef_t *pGPIOx , uint8_t EnorDi)
{
if(EnorDi == ENABLE)
{
if(pGPIOx == GPIOA) GPIOA_PCLK_EN();
else if(pGPIOx == GPIOB) GPIOB_PCLK_EN();
else if(pGPIOx == GPIOC) GPIOC_PCLK_EN();
else if(pGPIOx == GPIOD) GPIOD_PCLK_EN();
else if(pGPIOx == GPIOE) GPIOE_PCLK_EN();
else if(pGPIOx == GPIOH) GPIOH_PCLK_EN();
}
else
{
if(pGPIOx == GPIOA) GPIOA_PCLK_DI();
else if(pGPIOx == GPIOB) GPIOB_PCLK_DI();
else if(pGPIOx == GPIOC) GPIOC_PCLK_DI();
else if(pGPIOx == GPIOD) GPIOD_PCLK_DI();
else if(pGPIOx == GPIOE) GPIOE_PCLK_DI();
else if(pGPIOx == GPIOH) GPIOH_PCLK_DI();
}
}

/*

* GPIO Init
  */

void GPIO_Init(GPIO_Handle_t *pGPIOHandle)
{
uint32_t temp = 0;


/* 1. Configure GPIO Mode */
temp = (pGPIOHandle->GPIO_PinConfig.GPIO_PinMode << (2 * pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber));
pGPIOHandle->pGPIOx->MODER &= ~(0x3 << (2 * pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber));
pGPIOHandle->pGPIOx->MODER |= temp;

temp = 0;

/* 2. Configure GPIO Speed */
temp = (pGPIOHandle->GPIO_PinConfig.GPIO_PinSpeed << (2 * pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber));
pGPIOHandle->pGPIOx->OSPEEDR &= ~(0x3 << (2 * pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber));
pGPIOHandle->pGPIOx->OSPEEDR |= temp;

temp = 0;

/* 3. Configure Pull-up / Pull-down */
temp = (pGPIOHandle->GPIO_PinConfig.GPIO_PinPuPdControl << (2 * pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber));
pGPIOHandle->pGPIOx->PUPDR &= ~(0x3 << (2 * pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber));
pGPIOHandle->pGPIOx->PUPDR |= temp;

temp = 0;

/* 4. Configure Output Type */
temp = (pGPIOHandle->GPIO_PinConfig.GPIO_PinOpType << pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber);
pGPIOHandle->pGPIOx->OTYPER &= ~(0x1 << pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber);
pGPIOHandle->pGPIOx->OTYPER |= temp;

temp = 0;

/* 5. Configure Alternate Function */
if(pGPIOHandle->GPIO_PinConfig.GPIO_PinMode == GPIO_MODE_ALTFN)
{
	uint8_t temp1, temp2;

	temp1 = pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber / 8;
	temp2 = pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber % 8;

	pGPIOHandle->pGPIOx->AFR[temp1] &= ~(0xF << (4 * temp2));
	pGPIOHandle->pGPIOx->AFR[temp1] |= (pGPIOHandle->GPIO_PinConfig.GPIO_PinAltFunMode << (4 * temp2));
}


}

/*

* GPIO DeInit
  */

void GPIO_DeInit(GPIO_RegDef_t *pGPIOx)
{
if(pGPIOx == GPIOA) GPIOA_REG_RESET();
else if(pGPIOx == GPIOB) GPIOB_REG_RESET();
else if(pGPIOx == GPIOC) GPIOC_REG_RESET();
else if(pGPIOx == GPIOD) GPIOD_REG_RESET();
else if(pGPIOx == GPIOE) GPIOE_REG_RESET();
else if(pGPIOx == GPIOH) GPIOH_REG_RESET();
}

/*

* Read from Input Pin
  */

uint8_t GPIO_ReadFromInputPin(GPIO_RegDef_t *pGPIOx,uint8_t pinNumber)
{
uint8_t value;


value = (uint8_t)((pGPIOx->IDR >> pinNumber) & 0x1);

return value;


}

/*

* Read from Input Port
  */

uint16_t GPIO_ReadFromInputPort(GPIO_RegDef_t *pGPIOx)
{
uint16_t value;


value = (uint16_t)pGPIOx->IDR;

return value;


}

/*

* Write to Output Pin
  */

void GPIO_WriteToOutputPin(GPIO_RegDef_t *pGPIOx,uint8_t pinNumber,uint8_t value)
{
if(value == GPIO_PIN_SET)
{
pGPIOx->ODR |= (1 << pinNumber);
}
else
{
pGPIOx->ODR &= ~(1 << pinNumber);
}
}

/*

* Write to Output Port
  */

void GPIO_WriteToOutputPort(GPIO_RegDef_t *pGPIOx,uint16_t value)
{
pGPIOx->ODR = value;
}

/*

* Toggle Output Pin
  */

void GPIO_ToggleOutputPin(GPIO_RegDef_t *pGPIOx,uint8_t pinNumber)
{
pGPIOx->ODR ^= (1 << pinNumber);
}

