/*
 * Exercise 2-3: Write a function htoi(s), which converts a string of
 * hexadecimal digits (including an optional 0x or 0X) into its
 * equivalent integer value. The allowable digits are 0 through 9, a
 * through f, and A through F.
 */

#include <stdio.h>

int htoi(char s[]);

int main()
{
    printf("%d\n", htoi("FF"));
    printf("%d\n", htoi("0xFF"));
    printf("%d\n", htoi("0XFF"));
    printf("%d\n", htoi("1A3"));
    printf("%d\n", htoi("0x1A3"));
    printf("%d\n", htoi("0X1A3"));
    printf("%d\n", htoi("abcdef"));
    printf("%d\n", htoi("0xabcdef"));
    printf("%d\n", htoi("0XABCDEF"));
    printf("%d\n", htoi("123456"));
    printf("%d\n", htoi("0x123456"));
    printf("%d\n", htoi("0X123456"));

    return 0;
}

int htoi(char hexadecimal[]) {
    unsigned int i, c, step, number = 0;
    unsigned int start = 0;

    if(hexadecimal[0] == '0' && (hexadecimal[1] == 'x' || hexadecimal[1] == 'X'))
        start = 2;

    for(i = start; hexadecimal[i] != '\0'; i++) {
        c = hexadecimal[i];

        if(c >= '0' && c <= '9') step = c - '0';
        else if(c >= 'a' && c <= 'f') step = c - 'a' + 10;
        else if(c >= 'A' && c <= 'F') step = c - 'A' + 10;
        else continue;

        number = number * 16 + step;
    }

    return number;
}
