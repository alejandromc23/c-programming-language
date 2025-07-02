#include <stdio.h>
#define MAXLINE 1000
#define TAB_COLUMNS 8

int getLine(char line[], int maxline);
void entab(char line[]);

int main()
{
    int len; 
    char line[MAXLINE];
    int i, j, k, c;

    while((len = getLine(line, MAXLINE)) > 0) {
        entab(line);
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

void entab(char s[])
{
    int i, j, k, r, c;

    for(i = 0, j = 0; (c = s[i]) != '\0'; i++) {
        if (j >= TAB_COLUMNS) j = 0;

        if (c != ' ') {
            j++;
            printf("%c", c);
            continue;
        }

        r = 1;
        for (k = 0; k < TAB_COLUMNS - j && s[i + k] != '\0'; k++) {
            if (s[i + k] != ' ') r = 0;
        }

        if (r == 0) {
            j++;
            printf("%c", c);
            continue;
        }

        printf("%c", '\t');
        i = i + k - 1;
        j = 0;
    }
}
