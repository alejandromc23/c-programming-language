#include <stdio.h>
#define MAXLINE 1000

int getReversed(char line[], char reversed[], int maxline);

int main()
{
    int len; 
    char line[MAXLINE];
    char reversed[MAXLINE];

    while((len = getReversed(line, reversed, MAXLINE)) > 0) {
        printf("%s", reversed);
    }

    return 0;
}

int getReversed(char s[], char r[], int lim)
{
    int c, i, j;

    for(i = 0; i < lim-1 && (c=getchar()) != EOF && c != '\n'; ++i)
        s[i] = c;

    for(j = 0; j < i; ++j) {
        r[j] = s[i - 1 - j];
    }

    if(c == '\n') {
        r[j] = c;
        ++j;
    }
    
    r[j] = '\0';
    return j;
}
