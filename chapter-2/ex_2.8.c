#include <stdio.h>

/* Exercise 2-8: Write a function rightrot(x,n) that returns the value of the
   integer x rotated to the right by n bit positions.
*/

unsigned rightrot(unsigned x, int n);
int unsignedLength();

int main() 
{
    unsigned x1 = 179; 
    int n1 = 3;
    printf("rightrot(%u, %d) = %u\n", x1, n1, rightrot(x1, n1));
    
    unsigned x2 = 225;
    int n2 = 4;
    printf("rightrot(%u, %d) = %u\n", x2, n2, rightrot(x2, n2));

    return 0;
}

unsigned rightrot(unsigned x, int n) 
{
    int size = unsignedLength();
    n = n % size; 

    return (x >> n) | ((x & ~(~0 << n)) << (size-n));
}

int unsignedLength() {
    unsigned x = ~0;
    int length = 0;
    while (x != 0) {
        length++;
        x >>= 1;
    }
    return length;
}
