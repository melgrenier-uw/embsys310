1. #### Follow the same steps as we did in the class to blink LED1 (PA5) at a visible rate using the bit-band region to enable the clock to Port A, then answer the following: 

   ##### a) What instructions does the compiler produce in assembly for “writing” to the GPIO bit when using bit-band address? 

   It uses the write/store instruction: 

   STR R0, [R1]

   ##### b) What were the instructions produced when writing to the GPIOx_ODR without using bit-banding?

   It would read (LDR), //modify (ORRS.W), and store/write (STR):

   LDR R1, [R0]
   ORRS.W R1, R1, #1
   STR R1, [R0]

2. #### Create a function “func1” with 5 arguments and call “func1” from within another function “func2”. Trace thru the assembler and note: 

   ##### a) How does the **calling** function “func2” pass the values to the **called** function “func1”?

   It does so by loading the values to the stack from the registers where they are stored. It then copies those values into different registers to be used within the "sum" function.

   ##### b) What extra code did the compiler generate before calling the function “func1” with the multiple arguments?

   There was a lot of copying going around. It initially moved the values a-e to registers R4-R8; it then loaded R8 to the stack and moved R4-R7 to R0-R3 before branching to the "sum" label.

   ##### c) What extra code did the compiler generate inside the **called** function “funct1” with the multiple list of arguments?

   It had to create additional instructions to move the values to the stack to ensure they are not lost when it branches back to the main function. It then utilized additional registers to store the values for use within the "sum" function.

   ##### d) Any other observations? 

   When all moving and loading was done in preparation to do the addition in the "sum" function, some of the values were duplicated across multiple registers. It was interesting to see that even the LR was used to store one of the values passed as an argument when there were available registers that were not used in the addition process. The LR value had been pushed to the stack when the branching occured.

   Another observation, when I first ran the code I had forgotten to set Optimization to None (it was set at Low, by default) ; I thought something was off when I couldn't find any mention of the parameter "ans" I had created. I then removed Optimization and re-ran the code and that's when I noticed how much longer the assembly code was, and how much use of the stack there was compared to when Opimization was set to Low.