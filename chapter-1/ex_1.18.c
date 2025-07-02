#include <stdio.h>
#define MAXLINE 1000

int getTrimmedLine(char line[], char trimmed[], int maxline);

int main()
{
    int len; 
    char line[MAXLINE];
    char trimmed[MAXLINE];

    while((len = getTrimmedLine(line, trimmed, MAXLINE)) > 0) {
        printf("%s", trimmed);
    }

    return 0;
}

int getTrimmedLine(char s[], char t[], int lim)
{
    int i, j, k, c;
    

    for (i = 0; i < lim-1 && (c=getchar()) != EOF && (c == ' ' || c == '\n' || c == '\t'); i++) {
        
    }

    if (c == EOF) return 0; 

    j = 0;
    s[0] = c;
    for(i = 1; i < lim-1 && (c=getchar()) != EOF && c != '\n'; ++i) {
        if (c == ' ' || c == '\t')  j++;
        else j = 0;

        s[i] = c;
    }

    for(k = 0; k < i - j; ++k) {
        t[k] = s[k];
    }

    if(c == '\n') {
        t[k] = '\n';
        k++;
    }

    t[k] = '\0';

    return k;
}
