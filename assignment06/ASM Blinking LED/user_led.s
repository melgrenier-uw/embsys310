/*******************************************************************************
File name       : user_led.s
Description     : Assembly language function for controlling the user LED
*******************************************************************************/   

    EXTERN delay                    // delay() is defined outside this file

    PUBLIC control_user_led1        // Exports symbols to other modules

// Code is split into logical sections using the SECTION directive.
// Source: http://ftp.iar.se/WWWfiles/arm/webic/doc/EWARM_AssemblerReference.ENU.pdf
// SECTION  section  :type [:flag] [(align)]
//      The data section is used for declaring initialized data or constants. This data does not change at runtime
//      The bss section is used for declaring variables. The syntax for declaring bss section is -
//      The text section is used for keeping the actual code.

// CODE: Interprets subsequent instructions as Arm or Thumb instructions, 
// depending on the setting of related assembler options.

// NOREORDER (the default mode) starts a new fragment in the section
// with the given name, or a new section if no such section exists.
// REORDER starts a new section with the given name.

// NOROOT means that the section fragment is discarded by the linker if
// no symbols in this section fragment are referred to. Normally, all
// section fragments except startup code and interrupt vectors should
// set this flag.

// The (2) is for the (align)
// The power of two to which the address should be aligned.
// The permitted range is 0 to 8. 
// Code aligned at 4 Bytes.

    SECTION .text:CODE:REORDER:NOROOT(2)
    
    THUMB               // Indicates THUMB code is used
                        // Subsequent instructions are assembled as THUMB instructions
    
/*******************************************************************************
Function Name   : control_user_led1
Description     : - Uses Peripheral registers at base 0x4800.0000
                    to set GPIOA Output Data Register.
                  - Calls another assembly function delay to insert
                    delay loop

C Prototype     : void control_user_led(uint8_t state, uint32_t duration)
                : Where state indicates if LED should be on or off.
Parameters      : R0: uint8_t state
                : R1: uint32_t duration
Return value    : None
*******************************************************************************/  

GPIOA_BASE  EQU 0x48000000              // EQU is used to define constant values
GPIOA_ODR   EQU 0x14
GPIOA_BIT_5 EQU 0x20

// R0 has desired state
// R1 has desired duration

control_user_led1
    // Implement function in assembly
    PUSH {LR}                   // Push LR to stack for safekeeping
    LDR R3, =GPIOA_BASE         // Load GPIO Port A base address to R3
    CMP R0, #1                  // Check if desired state is LED ON (1)
    BEQ ON_STATE                // If equal, desired LED state is on, branch to ON_STATE
    MOV R2, #0x0                // Else desired LED state is off, turn LED off by resetting ODR
    B LOAD_STATE                // Branch to LOAD_STATE label (skip ON_STATE)
    ON_STATE:                   // Start of ON_STATE branch
    MOV R2, #0x20               // Turn LED on
    LOAD_STATE:                 // Start of LOAD_STATE branch
    STR R2, [R3, #GPIOA_ODR]    // Load desired state to GPIOA->ODR address
    MOV R0, R1                  // Set R0 = desired duration for delay function
    BL delay                    // Branch to delay function
    POP {LR}                    // Restore LR
    BX LR                       // Return to calling function (main)

    END
