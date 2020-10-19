# Why use two's complement to represent negative numbers

There are several reasons to use two's complement to represent negative numbers:
- Allows arithmetic operations to be performed using the same method that would be used for two unsigned numbers
- Easier to implement in hardware to add/subtract: the same adder circuit can be used for subtraction.
- There is only one representation of "0" whereas in sign-magnitude and in 1s complement, there is a "+0" and a "-0".
- In some architectures, sign extension is easier in 2s complement. For example, resizing a 4-bit number into an 8-bit number is done by copying the most significant bit of the smaller number to fill the larger number, which works for both negative and positive numbers represented in 2s complement.
  * 1010 = -6 (4-bit)
  * 1111 1010 = -6 (8-bit)
  <br>or
  * 0110 = 6 (4-bit)
  * 0000 0110 = 6 (8-bit)
  
