#include <stdio.h>
#define MAXLINE 1000
#define MAX_COLUMNS 80

int getLine(char line[], int maxline);
void fold(char line[]);
int nextLen(char line[], int index);

int main()
{
    int len; 
    char line[MAXLINE];
    int i, j, k, c;

    while((len = getLine(line, MAXLINE)) > 0) {
        fold(line);
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

void fold(char s[])
{
    int i, j, c;
    
    for(i = 0, j = 0; (c = s[i]) != '\0'; i++, j++) 
    {
        int len = nextLen(s, i);

        if ((c == ' ' || c == '\t') && (j + len > MAX_COLUMNS)) {
            while((c = s[i]) == ' ' || c == '\t') i++;
            i--;
            j = 0;
            printf("\n");
            continue;
        }

        if (j + 1 > MAX_COLUMNS) {
            printf("-\n");
            j = 0;
        }
        printf("%c", c);
    }
}

int nextLen(char s[], int i)
{
    int j, c;
    for (j = 0; (c = s[i+j]) != '\n' && (c == ' ' || c == '\t'); j++);

    for (;(c = s[i+j]) != '\n' && c != ' ' && c != '\t'; j++);

    return j;
}

// Input

// Contrary to popular belief, Lorem Ipsum is not simply random text. It has roots in a piece of classical Latin literature from 45 BC, making it over 2000 years old. Richard McClintock, a Latin professor at Hampden-Sydney College in Virginia, looked up one of the more obscure Latin words, consectetur, from a Lorem Ipsum passage, and going through the cites of the word in classical literature, discovered the undoubtable source. Lorem Ipsum comes from sections 1.10.32 and 1.10.33 of "de Finibus Bonorum et Malorum" (The Extremes of Good and Evil) by Cicero, written in 45 BC. This book is a treatise on the theory of ethics, very popular during the Renaissance. The first line of Lorem Ipsum, "Lorem ipsum dolor sit amet..", comes from a line in section 1.10.32.
//


// output

// Contrary to popular belief, Lorem Ipsum is not simply random text. It has roots
// in a piece of classical Latin literature from 45 BC, making it over 2000 years
// old. Richard McClintock, a Latin professor at Hampden-Sydney College in
// Virginia, looked up one of the more obscure Latin words, consectetur, from a
// Lorem Ipsum passage, and going through the cites of the word in classical
// literature, discovered the undoubtable source. Lorem Ipsum comes from sections
// 1.10.32 and 1.10.33 of "de Finibus Bonorum et Malorum" (The Extremes of Good
// and Evil) by Cicero, written in 45 BC. This book is a treatise on the theory of
// ethics, very popular during the Renaissance. The first line of Lorem Ipsum,
// "Lorem ipsum dolor sit amet..", comes from a line in section 1.10.32.

