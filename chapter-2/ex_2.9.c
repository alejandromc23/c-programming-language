#include <stdio.h>

/* Exercise 2-9: In a two's complement number system, the operation x &= (x-1) removes the rightmost 1-bit in x.
 * Explain why. Use this observation to write a faster version of bitcount.

   Explanation: When subtracting 1 from x, all the bits from position 0 up to the rightmost 1-bit are flipped 
   (0's become 1's and 1's become 0's). Performing a bitwise AND operation between x and (x-1) sets these flipped 
   bits to 0, effectively removing the rightmost 1-bit.

   Example with a positive number: 92
   Binary representation:
   x      = 01011100 (92)
   x - 1  = 01011011 (91)
   Result = 01011000 (88), where the rightmost 1-bit is removed.

   Example with a negative number: -6
   Binary representation:
   x      = 11111010 (-6)
   x - 1  = 11111001 (-7)
   Result = 11111000 (-8), where the rightmost 1-bit is removed.
*/

int bitcount(unsigned x);

int main()
{
    printf("bitcount(92) = %d\n", bitcount(92));   // Example: 92 in binary is 01011100, expected output: 4
    printf("bitcount(15) = %d\n", bitcount(15));   // Example: 15 in binary is 00001111, expected output: 4
    printf("bitcount(0) = %d\n", bitcount(0));     // Example: 0 in binary is 00000000, expected output: 0
    printf("bitcount(255) = %d\n", bitcount(255)); // Example: 255 in binary is 11111111, expected output: 8
    
    return 0;
}

int bitcount(unsigned x) {
    int b = 0;

    while (x != 0) {
        x &= (x-1);
        b++;
    }

    return b;
}
