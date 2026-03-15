#include "stm32f401xx_gpio_driver.h"

void delay(void)
{
    for(volatile uint32_t i = 0; i < 300000; i++);
}

int main(void)
{
    GPIO_Handle_t GpioLed, GpioBtn;

    /* Enable clock for GPIOA and GPIOC */
    GPIO_PeriClockControl(GPIOA, ENABLE);
    GPIO_PeriClockControl(GPIOC, ENABLE);

    /* LED configuration (PA5) */
    GpioLed.pGPIOx = GPIOA;
    GpioLed.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_5;
    GpioLed.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_OUT;
    GpioLed.GPIO_PinConfig.GPIO_PinSpeed = GPIO_SPEED_FAST;
    GpioLed.GPIO_PinConfig.GPIO_PinOpType = GPIO_OP_TYPE_PP;
    GpioLed.GPIO_PinConfig.GPIO_PinPuPdControl = GPIO_NO_PUPD;

    GPIO_Init(&GpioLed);

    /* Button configuration (PC13) */
    GpioBtn.pGPIOx = GPIOC;
    GpioBtn.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_13;
    GpioBtn.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_IN;
    GpioBtn.GPIO_PinConfig.GPIO_PinSpeed = GPIO_SPEED_FAST;
    GpioBtn.GPIO_PinConfig.GPIO_PinPuPdControl = GPIO_NO_PUPD;

    GPIO_Init(&GpioBtn);

    while(1)
    {
        if(GPIO_ReadFromInputPin(GPIOC, GPIO_PIN_NO_13) == 0)
        {
            delay();
            GPIO_ToggleOutputPin(GPIOA, GPIO_PIN_NO_5);
        }
    }
}

