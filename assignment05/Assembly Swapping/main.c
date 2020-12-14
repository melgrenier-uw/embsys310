// "Swap Function using Inline Assembly" Program
#include <assert.h>

int swapCharsAsm(char *var1, char *var2);

void main(void)
{
    int swapped = 0;
    char x = 'M';
    char y = 'Z';
    
    // Verify return is 1 because they're not identical
    swapped = swapCharsAsm(&x,&y);
    assert(1 == swapped);
    
    x = 'Y';
    y = 'Y';
    
    // Verify return is 0 since they're identical
    swapped = swapCharsAsm(&x,&y);
    assert(0 == swapped);
}

int swapCharsAsm(char *var1, char *var2) {
    int ident;
    
    asm("LDRB R2, [R0]\n"      // Load x value from address in R0 into R2
        "LDRB R3, [R1]\n"      // Load y value from address in R1 into R3
        "STRB R2, [R1]\n"      // Store value in R2 to address in R1
        "STRB R3, [R0]\n"      // Store value in R3 to address in R0
        "CMP R2, R3\n"         // Compare values to see if they're the same
        "BEQ same\n"           // Branch to "same" label if they're equal (Z flag is set)
        "MOVS R0, #1\n"        // If they're not equal, set R0 = 1
        "B out\n"              // Jump to end of function (skip "same" branch)
        "same:\n"              // Start of "same" branch instruction
        "MOVS R0, #0\n"        // Set R0 = 0 if values are equal (Z flag is set)
        "out:\n"               // Start of "out" branch instruction
        : "=r"(ident)          // Set "ident" variable to value in R0 (ident = R0)
        );
    
    return ident;
}
