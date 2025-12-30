#include <stdio.h>
#define MAXLINE 1000

/* Exercise 2.10: Rewrite the function lower, which converts upper case letters to lower case letters,
   to use a conditional expression instead of if-else. */ 

int getLine(char s[], int limit);
int lower(int c);

int main() {
    int c, i;
    char line[MAXLINE];

    while((c = getLine(line, MAXLINE)) > 0) {
       for(i = 0; i < c; i++) printf("%c", lower(line[i]));
       printf("\n");
    }

    return 0;
}

int getLine(char s[], int limit) {
    int c, i;

    for (i = 0; i < limit && ((c = getchar()) != EOF && c != '\n'); i++) {
        s[i] = c;
    }

    if(c == '\n') {
        s[i] = c;
        i++;
    }

    s[i] = '\0';
    return i;
}

int lower(int c) {
    return (c >= 'A' && c <= 'Z') ?  (c + 'a' - 'A') : c;
}
