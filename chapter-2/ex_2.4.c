#include <stdio.h>
#define MAXSIZE 1000
 
/*
 * Exercise 2-4: Write a function squeeze(s1, s2) that deletes each character in
 * the string s1 that matches any character in the string s2.
 */

void squeeze(char s1[], char s2[]);

int main() {
    char s1[MAXSIZE];
    char s2[MAXSIZE];

    printf("Enter the first string: ");
    scanf("%s", s1);
    printf("Enter the second string: ");
    scanf("%s", s2);

    printf("Original string: %s\n", s1);
    squeeze(s1, s2);
    printf("After squeeze: %s\n", s1);

    return 0;
}

void squeeze(char s1[], char s2[]) {
    int i, j, k;

    for(i = 0; s1[i] != '\0'; i++) {
        for(j = 0; s2[j] != '\0' && s2[j] != s1[i]; j++);

        if(s2[j] == '\0') s1[k++] = s1[i];
    }

    s1[k] = '\0';
}
