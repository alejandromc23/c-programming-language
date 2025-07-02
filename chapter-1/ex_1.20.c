#include <stdio.h>
#define MAXLINE 1000
#define TAB_COLUMNS 8

int getLine(char line[], int maxline);
void detab(char line[]);

int main()
{
    int len; 
    char line[MAXLINE];
    int i, j, k, c;

    while((len = getLine(line, MAXLINE)) > 0) {
        detab(line);
    }

    return 0;
}

int getLine(char s[], int lim)
{
    int c, i, j;

    for(i = 0; i < lim-1 && (c=getchar()) != EOF && c != '\n'; ++i) {
        s[i] = c;
    }

    if(c == '\n') {
        s[i] = c;
        ++i;
    }

    s[i] = '\0';
    return i;
}

void detab(char s[])
{
    int i, j, k, c;

    for(i = 0, j = 0; (c = s[i]) != '\0'; i++) {
        if (j >= TAB_COLUMNS) j = 0;

        if (c != '\t') {
            printf("%c", c);
            j++;
            continue;
        }

        while((k = TAB_COLUMNS - j) > 0) {
            printf(" ");
            j++;
        } 
    }
}
