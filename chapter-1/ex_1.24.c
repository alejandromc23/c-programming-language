#include <stdio.h>
#define MAXLINE 1000
#define MAXSTACK 1000

// Write a program to check a C program for rudimentary syntax errors like
// unmatched parentheses, brackets and braces. Don't forget about quotes, both single and
// double, escape sequences, and comments. (This program is hard if you do it in full generality.)

int getLine(char s[], int l);
void processLine(char c[], char s[], int p[], int l[], int si[], int ln);

int main()
{
    int len, i;
    int lineNumber = 1;
    int stackIndex = 0;
    int isMultilineComment = 0;
    int stackIndexAndIsComment[2] = {stackIndex, isMultilineComment};
    char line[MAXLINE];
    char stack[MAXSTACK];
    int positions[MAXSTACK];
    int lineNumbers[MAXSTACK];

    while((len = getLine(line, MAXLINE)) > 0) {
        processLine(line, stack, positions, lineNumbers, stackIndexAndIsComment, lineNumber);
        lineNumber++;
    }

    if (stackIndexAndIsComment[0] == 0) {
        printf("Code without syntax errors detected\n");
        return 1;
    }

    for(i = 0; i < stackIndexAndIsComment[0]; i++) { 
        if (stack[i] == '*') {
            printf("Unclosed comment, at line: %d and position: %d\n", lineNumbers[i], positions[i]);
            continue;
        } else printf("Unclosing %c, at line: %d and position: %d\n", stack[i], lineNumbers[i], positions[i]);
    }

   return 0;
}

int getLine(char s[], int limit) {
    int c, i;

    for (i = 0; i < limit && (c = getchar()) != EOF && c != '\n'; i++) {
        s[i] = c;
    }

    if (c == '\n') {
        s[i] = '\n';
        i++;
    }

    s[i] = '\0';

    return i;
}

void processLine(char s[], char stack [], int positions[], int lineNumbers[], int stackIndexAndIsComment[], int lineNumber) { 
    int i, c;
    int isString = 0;
    int stackIndex = stackIndexAndIsComment[0];
    int isMultilineComment = stackIndexAndIsComment[1];
    int isValid = 1;
    int slashCount = 0;

    for (i = 0; (c = s[i]) != '\0'; i++) {
        if (isMultilineComment == 1) {
            if (c == '/' && (i > 0 && s[i-1] == '*')) {
                stackIndex--;
                isMultilineComment = 0;
            }

            continue;
        }

        if (isString == 1) {
            if (i > 1 && s[i - 1] == '\\' && s[i - 2] != '\\') {
                continue;
            }
            if ((c == '\'' || c == '"') && stackIndex > 0 && stack[stackIndex - 1] == c) {
                stackIndex--; 
                isString = 0;
            }

            continue;
        }

        if (slashCount > 1) break; 

        if (c == '/') {
            slashCount++;
            continue; 
        }
        slashCount = 0;

        if (c == '[' || c == '(' || c == '{') { 
            stack[stackIndex] = c;
            positions[stackIndex] = i;
            lineNumbers[stackIndex] = lineNumber; 
            stackIndex++;
        } else if (c == '\'' || c == '"' ) {
            isString = 1;

            stack[stackIndex] = c;
            positions[stackIndex] = i;
            lineNumbers[stackIndex] = lineNumber; 
            stackIndex++; 
        } else if (c == ']') { 
            if (stackIndex > 0 && stack[stackIndex - 1] == '[') stackIndex--; 
        } else if (c == ')') { 
            if (stackIndex > 0 && stack[stackIndex - 1] == '(') stackIndex--; 
        } else if (c == '}') { 
            if (stackIndex > 0 && stack[stackIndex - 1] == '{') stackIndex--; 
        } else if (c == '*') {
            if (i > 0 && s[i-1] == '/') {
                isMultilineComment = 1;
                stack[stackIndex] = c;
                positions[stackIndex] = i;
                lineNumbers[stackIndex] = lineNumber; 
                stackIndex++; 
            }
        }
   }

    stackIndexAndIsComment[0] = stackIndex;
    stackIndexAndIsComment[1] = isMultilineComment;
}
