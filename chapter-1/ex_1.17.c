#include <stdio.h>
#define MAXLINE 1000
#define THRESHOLD 80

int getLine(char line[], int maxline);

int main()
{
    int len; 
    char line[MAXLINE];

    while((len = getLine(line, MAXLINE)) > 0) {
        if (len <= THRESHOLD) continue;

        printf("%s", line);
    }

    return 0;
}

int getLine(char s[], int lim)
{
    int c, i;

    for(i = 0; i < lim-1 && (c=getchar()) != EOF && c != '\n'; ++i)
        s[i] = c;

    if(c == '\n') {
        s[i] = c;
        ++i;
    }

    s[i] = '\0';
    return i;
}
