// Blinking LED1 (PA5) using Bit-Band Region Program

// bit_band_address = bit_band_base + (byte_offset*32) + (bit_number*4)
// bit_band_base (for peripherals) = 0x42000000 
// byte_offset (for peripherals) = address_containing_target_bit - 0x40000000 (peripheral bit-band region base)

#define RCC_BASE 0x40021000
#define RCC_AHB2ENR (*((unsigned int*)(RCC_BASE + 0x4C)))

#define GPIOA_BASE 0x48000000
#define GPIOA_MODER (*((unsigned int*)(GPIOA_BASE + 0x00)))
#define GPIOA_ODR (*((unsigned int*)(GPIOA_BASE + 0x14)))

#define ORD5 0x20

int counter = 0;

void main(void)
{
    
    // Enable clock that controls GPIOA
    // Set bit[0] to 1
    // RCC_AHB2ENR |= 0x01;
    *((unsigned int*)(0x42000000+(0x2104C*32) + (0*4))) = 0x1;
    
    // Set GPIOA Mode to Output
    // Set bit[11:10] to 01
    GPIOA_MODER &= 0xFFFFF7FF;
        
    // Write to GPIOA Output Data Register (ODR) to toggle LED
    while (1)
    {
        counter = 0;
        while (counter < 100000)
        {
            counter++;
        }
        GPIOA_ODR ^= ORD5;
    }
}
