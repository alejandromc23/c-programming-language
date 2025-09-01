/* This an example of C program with syntax errors,
 * it will be used to validate ex_1.24.c file.
 * It contains rudimentary syntax errors like
 * unmatched parentheses, brackets and braces. Also contains quotes, 
 * both single and double, escape sequences, and comments.
*/

#include <stdio.h>

// write a program with syntax errors
int main() {
    int i = 0;
    int j = 10;

    // unmatched parentheses
    if (i < j {
        printf("i is less than j\n");
    }

    // unmatched brackets
    int arr[5;
    arr[0] = 1;

    // unmatched braces
    for (int k = 0; k < 5; k++) 
        printf("%d\n", arr[k]);
    }

    // unmatched single quote
    char ch = 'a;

    // unmatched double quote
    char *str = "Hello, World;

    // unterminated comment
    /* code considered comment {]} should be ignored
    printf("This is a test\n");

    return 0;
}
