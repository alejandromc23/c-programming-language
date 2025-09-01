#include <stdio.h>
#define MAXLINE 1000

int getLine(char s[], int limit);
int cleanComments(char s[], int imc);

// Write a program to remove all comments from a C program. Don't forget to
// handle quoted strings and character constants properly. C comments don't nest.

int main()
{
    char line[MAXLINE];
    int len;
    int isMultilineComment = 0;

    while((len = getLine(line, MAXLINE)) > 0) {
        isMultilineComment = cleanComments(line, isMultilineComment);    
    }
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

// comment to delete
int cleanComments(char s[], int isMultilineComment) {
    int c, i;
    int slashCount = 0;
    int inString = 0;

    for (i = 0; s[i] != '\0'; i++) { //comment to delete
        if (isMultilineComment == 1) {
            if (i > 0 && s[i] == '/' && s[i-1] == '*') {
                isMultilineComment = 0;
            }

            continue;
        }

        if (slashCount > 1) {
            printf("\n");
            break;
        }

        
        /* this comments
         * should also 
         * be 
         * deleted //*/

        /* another comment to delete // */

        if (s[i] == '\'' || s[i] == '"') {
            if (inString == 1 && s[i-1] != '\\') inString = 0;
            else inString = 1;
        } else if (s[i] == '/' && inString == 0) {
            slashCount++;
            continue;
        }

        if (slashCount > 0) {
            if (s[i] != '*') printf("%c", s[i]);
            else {
                isMultilineComment = 1;
                continue;
            }
        }

        slashCount = 0;
        printf("%c", s[i]);
    }

    return isMultilineComment;
}

// this logic assummes that everything inside '' or "" is a string no matter if the C looking program compiles or not 
