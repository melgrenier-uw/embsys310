1. #### Inject 0x7FFFFFFF for the “counter” value in the variable window, then step thru the program only once to increment “counter”.

   **a) What is the value of the “counter” from the “Locals” window?**
   -2147483648

   **b) What is the value of the “counter” in the “Registers” window?**
   0x80000000

   **c) Please note down if the N and/or V flags are set in the APSR register. And explain why.**
   N is set because the msb is now 1, which is the sign bit. The CPU treats it as negative number (2s complement). The V is set because of overflow: the positive number turned negative because it did not fit in the data type and set the sign bit. The arithmetic result is wrong.

2. ####  If your write all Fs (0XFFFFFFFF) in the Register value for “counter” then step thru the program once to increment “counter” 

   **a) What happens to the value of “counter” in the “Locals” window?** 
   Goes from '-1' to ‘0’

   **b) Please note down if the N and/or V flags are set in the APSR register. And explain why.**
   The N and V flags are not set because it's a valid addition, -1+1=0

3. #### Change the “counter” variable type in your code to “unsigned int”. Inject the values “0x7FFFFFFF” then step thru the program to increment the “counter” once: 

   **a) What is the value of “counter” in the “Locals” window after incrementing for each value?** 
   2147483648

   **b) Please note down if the N and/or V flags are set in the APSR register. And explain why.** 
   N and V flags are set because the program does not differentiate between signed and unsigned. It treats everything as signed so it thinks there is an overflow due to the sign bit (msb) being set to '1' and sets the ASPR values accordingly. It is up to the programmer to interpret and use the flags appropriately. The application layer understands it is an unsigned number and thus shows it correctly in the Locals window.

4. #### Change the “counter” variable type in your code to “unsigned”. Inject the values “**0xFFFFFFFF**” then step thru the program to increment the “counter” once: 

   **a) What is the value of “counter” in the “Locals” window after incrementing for each value?** 
   Goes to '0'

   **b) Please note down if the N and/or V flags are set in the APSR register. And explain why.** 
   The N and V flags were not set. The N flag is not set because the sign bit is '0' and so the program treats it as a positive number. The V flag is not set because the addition was between what the program considers a "negative" number (counter) and a "positive" number (+1 increment). The overflow flag is only set when two negatives yield a positive result or two positives yield a negative result, which is not the case in this instance.

5. #### Move the “counter’ variable outside of main (at the top of the file): 

   **a) What is the scope of the variable “counter”?** 
   It is now a global variable.

   **b) Is it still visible in the “Locals” view?** 
   No, it is not visible in the Locals view.

   **c) In which window view can we track “counter” now?** 
   In the Watch view.

   **d) What is the address of the “counter” variable in memory?** 
   0x20000000

6. #### Change the source code to the following, then run the program in the simulator: 

   **a) What is the value of “counter” at the end of the program (halting at the return 0 statement)** 
   4

   **b) Explain why the counter value has changed?** 
   Because the pointer p_int is accessing the value stored in address in 0x20000000 and modifying it (de-referencing).

7. #### Change the setting of IAR to run the same program on the **evaluation board**: 

   **a) What is the address where “counter” is stored?** 
   0x20000000

   **b) Is the “counter” variable stored in RAM or ROM?** 
   RAM

   **c) What is the value of “counter” at the end of the program (halting at the 'return 0' statement).** 
   4