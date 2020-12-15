// "Blinking LED1 (PA5) using CMSIS" Program

#include "stm32l475xx.h"
#include "system_stm32l4xx.h"

int counter = 0;

void main(void)
{
    
    // Enable clock that controls GPIOA
    // Set bit[0] to 1
    RCC->AHB2ENR |= RCC_AHB2ENR_GPIOAEN;
    
    // Set GPIOA Mode to Output
    // Set bit[11:10] to 01
    GPIOA->MODER |= GPIO_MODER_MODE5_0;
    GPIOA->MODER &= ~GPIO_MODER_MODE5_1;
        
    // Write to GPIOA Output Data Register (ODR) to toggle LED
    while (1)
    {
        counter = 0;
        while (counter < 100000)
        {
            counter++;
        }
        GPIOA->ODR ^= GPIO_ODR_OD5;
    }
}
