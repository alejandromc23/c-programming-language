#include <stdio.h>

/* Exercise 2-7. Write a function invert(x,p,n) that returns x with the n bits
   that begin at position p inverted (i.e., 1 changed into 0 and vice versa),
   leaving the others unchanged. */

unsigned invert(unsigned x, int p, int n);

int main() 
{
    unsigned x1 = 108; // 01101100
    int p1 = 4;
    int n1 = 3;
    printf("invert(%u, %d, %d) = %u\n", x1, p1, n1, invert(x1, p1, n1)); // should return 112

    unsigned x2 = 255; // 11111111
    int p2 = 5;
    int n2 = 4;
    printf("invert(%u, %d, %d) = %u\n", x2, p2, n2, invert(x2, p2, n2)); // should return 195

    unsigned x3 = 0; // 00000000
    int p3 = 3;
    int n3 = 2;
    printf("invert(%u, %d, %d) = %u\n", x3, p3, n3, invert(x3, p3, n3)); // should return 12

    unsigned x4 = 170; // 10101010
    int p4 = 6;
    int n4 = 5;
    printf("invert(%u, %d, %d) = %u\n", x4, p4, n4, invert(x4, p4, n4)); // should return 214

    return 0;
}

unsigned invert(unsigned x, int p, int n)
{
    unsigned mask = ~(~0 << n);  
    return x ^ (mask << (p+1-n));
}
