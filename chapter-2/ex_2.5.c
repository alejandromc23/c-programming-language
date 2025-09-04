#include <stdio.h>
#define MAXSIZE 1000
 
/*
 * Exercise 2-5: Write the function any(s1, s2), which returns the first location in the string s1
 * where any character from the string s2 occurs, or -1 if s1 contains no
 * characters from s2. (The standard library function strpbrk does the same job but
 * returns a pointer to the location.)
 */

int any(char s1[], char s2[]);

int main() {
    char s1[MAXSIZE], s2[MAXSIZE];
    int i;

    printf("Enter the first string: ");
    scanf("%s", s1);
    printf("Enter the second string: ");
    scanf("%s", s2);

    i = any(s1, s2);
    
    if(i == -1) printf("No characters matching\n");
    else printf("First match found for character: %c at position: %d\n", s1[i], i);


    return 0;
}

int any(char s1[], char s2[]) {
    int i, j;

    for(i = 0; s1[i] != '\0'; i++) {
        for(j = 0; s2[j] != '\0' && s2[j] != s1[i]; j++);

        if (s2[j] != '\0') return i;
    }

    return -1;
}
