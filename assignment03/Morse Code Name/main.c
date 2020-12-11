// Program continuously loops through my name, Melissa, in morse code by blinking LED1

// The length of a dot is one unit
// A dash is three units
// The space between parts of the same letter is one unit
// The space between letters is three units
// The space between words is seven units

#define DOT 100000
#define DASH (3 * DOT)
#define WAIT_PART DOT
#define WAIT_LETTER (3 * DOT)
#define SPACE (7 * DOT) 

#define RCC_BASE 0x40021000
#define RCC_AHB2ENR (*((unsigned int*)(RCC_BASE + 0x4C)))

#define GPIOA_BASE 0x48000000
#define GPIOA_MODER (*((unsigned int*)(GPIOA_BASE + 0x00)))
#define GPIOA_ODR (*((unsigned int*)(GPIOA_BASE + 0x14)))

#define ORD5 0x20

void dot(void);
void dash(void);
void space_part(void);
void space_letter(void);

int counter = 0;

void main(void)
{
    // Enable clock that controls GPIOA
    // Set bit[0] to 1
    RCC_AHB2ENR |= 0x01;
    
    // Set GPIOA Mode to Output
    // Set bit[11:10] to 01
    GPIOA_MODER &= 0xFFFFF7FF;
        
    // Write to GPIOA Output Data Register (ODR) to toggle LED
    while (1)
    {
        // M: --
        dash();
        space_part();
        dash();
        
        // Wait between letters
        space_letter();
        
        // E: .
        dot();
        
        // Wait between letters
        space_letter();
        
        // L: .-..
        dot();
        space_part();
        dash();
        space_part();
        dot();
        space_part();
        dot();
        
        // Wait between letters
        space_letter();
        
        // I: ..
        dot();
        space_part();
        dot();
        
        // Wait between letters
        space_letter();
        
        // S: ...
        dot();
        space_part();
        dot();
        space_part();
        dot();
        
        // Wait between letters
        space_letter();
        
        // S: ...
        dot();
        space_part();
        dot();
        space_part();
        dot();
        
        // Wait between letters
        space_letter();
        
        // A: .-
        dot();
        space_part();
        dash();
        
        // Wait between words
        counter = 0;
        while (counter < SPACE) {
            counter++;
        }
    }
}   

void dot(void){
    counter = 0;
    GPIOA_ODR ^= ORD5;
    while (counter < DOT)
    {
        counter++;
    }
    GPIOA_ODR ^= ORD5;
}

void dash(void) {
    counter = 0;
    GPIOA_ODR ^= ORD5;
    while (counter < DASH)
    {
        counter++;
    }
    GPIOA_ODR ^= ORD5;
}

void space_part(void) {
    counter = 0;
    while (counter < WAIT_PART) {
        counter++;
    }
}

void space_letter(void) {
    counter = 0;
    while (counter < WAIT_LETTER) {
            counter++;
    }
}

