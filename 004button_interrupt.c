#include "stm32f401xx.h"
#include "string.h"
#include "stm32f401xx_gpio_driver.h"

void delay(void)
{
	for(uint32_t i = 0; i < 500000/2; i++);
}

#define HIGH 1
#define LOW 0
#define BTN_PRESSED LOW
int main(void)
{
	GPIO_Handle_t GpioLed, GpioBtn;
    memset(&GpioLed,0,sizeof(GpioLed));
    memset(&GpioBtn,0,sizeof(GpioBtn));

	/* ================= LED CONFIG (PA5) ================= */
	GpioLed.pGPIOx = GPIOA;
	GpioLed.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_5;
	GpioLed.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_OUT;
	GpioLed.GPIO_PinConfig.GPIO_PinSpeed = GPIO_SPEED_FAST;
	GpioLed.GPIO_PinConfig.GPIO_PinOpType = GPIO_OP_TYPE_PP;
	GpioLed.GPIO_PinConfig.GPIO_PinPuPdControl = GPIO_NO_PUPD;

	GPIO_PeriClockControl(GPIOA, ENABLE);
	GPIO_Init(&GpioLed);

	/* ================= BUTTON CONFIG (PD5) ================= */
	GpioBtn.pGPIOx = GPIOC;
	GpioBtn.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_9;
	GpioBtn.GPIO_PinConfig.GPIO_PinMode = GPIO_IT_FT;   //  Falling edge
	GpioBtn.GPIO_PinConfig.GPIO_PinSpeed = GPIO_SPEED_FAST;
	GpioBtn.GPIO_PinConfig.GPIO_PinPuPdControl = GPIO_PIN_PU; // Pull-up
	GpioBtn.GPIO_PinConfig.GPIO_PinOpType = GPIO_OP_TYPE_PP;

	GPIO_PeriClockControl(GPIOC, ENABLE);
	GPIO_Init(&GpioBtn);

	/* ================= IRQ CONFIG ================= */
	GPIO_IRQPriorityConfig(IRQ_NO_EXTI9_5, 15);
	GPIO_IRQInterruptConfig(IRQ_NO_EXTI9_5, ENABLE);

	while(1)
	{
		// main loop empty (interrupt based)
	}
}

/* ================= ISR ================= */
void EXTI9_5_IRQHandler(void)
{
	delay(); // debounce

	GPIO_ISRHandling(GPIO_PIN_NO_9);   // clear interrupt
	GPIO_ToggleOutputPin(GPIOA, GPIO_PIN_NO_5); // toggle LED
}

