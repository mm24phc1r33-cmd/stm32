/*
 * 003led_button_ext.c
 *
 *  Created on: Mar 17, 2026
 *      Author: Monika
 */

#include "stm32f401xx_gpio_driver.h"

void delay(void)
{
    for(uint32_t i=0;i<200000;i++);
}

int main(void)
{
    GPIO_Handle_t GpioLed, GpioBtn;

    // Enable clocks
    GPIO_PeriClockControl(GPIOA, ENABLE);
    GPIO_PeriClockControl(GPIOB, ENABLE);

    // LED configuration (PA14)
    GpioLed.pGPIOx = GPIOA;
    GpioLed.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_6;
    GpioLed.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_OUT;
    GpioLed.GPIO_PinConfig.GPIO_PinSpeed = GPIO_SPEED_FAST;
    GpioLed.GPIO_PinConfig.GPIO_PinOpType = GPIO_OP_TYPE_PP;
    GpioLed.GPIO_PinConfig.GPIO_PinPuPdControl = GPIO_NO_PUPD;

    GPIO_Init(&GpioLed);

    // Button configuration (PB12)
    GpioBtn.pGPIOx = GPIOB;
    GpioBtn.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_12;
    GpioBtn.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_IN;
    GpioBtn.GPIO_PinConfig.GPIO_PinSpeed = GPIO_SPEED_FAST;
    GpioBtn.GPIO_PinConfig.GPIO_PinPuPdControl = GPIO_PIN_PU;


    GPIO_Init(&GpioBtn);

    while(1)
    {
        if(GPIO_ReadFromInputPin(GPIOB, GPIO_PIN_NO_12) == 0)
        {
            delay();
            GPIO_WriteToOutputPin(GPIOA, GPIO_PIN_NO_6, 1);
        }
        else
        {
            GPIO_WriteToOutputPin(GPIOA, GPIO_PIN_NO_6, 0);
        }
    }
}

