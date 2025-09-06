#include <stdio.h>

/* Exercise 2-6: Write a function setbits(x,p,n,y) that returns x with the n bits
   that begin at position p set to the rightmost n bits of y, leaving the other
   bits unchanged. */

unsigned setbits(unsigned x, int p, int n, unsigned y);

int main()
{
    unsigned x1 = 41;   // 00101001
    unsigned y1 = 102;  // 01100110
    int n1 = 3;
    int p1 = 4;

    unsigned x2 = 255;  // 11111111
    unsigned y2 = 0;    // 00000000
    int n2 = 4;
    int p2 = 5;

    unsigned x3 = 170;  // 10101010
    unsigned y3 = 85;   // 01010101
    int n3 = 5;
    int p3 = 6;

    printf("Example 1:\n");
    printf("x = %u, y = %u, n = %d, p = %d\n", x1, y1, n1, p1);
    printf("setbits(x, p, n, y) = %u\n\n", setbits(x1, p1, n1, y1)); // 00111001 (57)

    printf("Example 2:\n");
    printf("x = %u, y = %u, n = %d, p = %d\n", x2, y2, n2, p2);
    printf("setbits(x, p, n, y) = %u\n\n", setbits(x2, p2, n2, y2)); // 11000011 (195)

    printf("Example 3:\n");
    printf("x = %u, y = %u, n = %d, p = %d\n", x3, y3, n3, p3);
    printf("setbits(x, p, n, y) = %u\n\n", setbits(x3, p3, n3, y3)); // 11010110 (214)

    return 0;
}

unsigned setbits(unsigned x, int p, int n, unsigned y) {
    unsigned mask = ~(~0 << n);
    return (~(mask << (p+1-n)) & x) | ((y & mask) << (p+1-n));
}
