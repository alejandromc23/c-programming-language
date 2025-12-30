#include <stdio.h>

/* 
 * Exercice 3.2: Write a function escape(s,t) that converts characters like newline and tab
 * into visible escape sequences like \n and \t as it copies the string t to s. Use a switch. Write a
 * function for the other direction as well, converting escape sequences into the real characters.
 */

#define MAXLINE 1000

void escape(char s[], char t[]);
void unescape(char s[], char t[]);

int main()
{
    int c;
    int i = 0;
    char line[MAXLINE];
    char escaped[MAXLINE];
    char unescaped[MAXLINE];
    printf("Enter text (Ctrl+D to end input):\n");

    while ((c = getchar()) != EOF) {
        line[i++] = c;
    }
    line[i] = '\0';

   escape(escaped, line);


   printf("\nEscaped version:\n"); 
   for (int i = 0; i < MAXLINE && escaped[i] != '\0'; i++) {
       printf("%c", escaped[i]);
   }
   printf("\n");

   unescape(unescaped, escaped);
   printf("\nUnescaped version:\n");

    for (int i = 0; i < MAXLINE && unescaped[i] != '\0'; i++) {
         printf("%c", unescaped[i]);
    }
    printf("\n");

    return 0;
}

void escape(char s[], char t[])
{
    int c, i, j;

    for(i = 0, j = 0; i < MAXLINE && j < MAXLINE - 1 && (c = t[i]) != '\0'; i++) {
        switch (c) {
            case '\t':
                s[j++] = '\\';
                s[j++] = 't';
                break;
            case '\n':
                s[j++] = '\\';
                s[j++] = 'n';
                break;
            default:
                s[j++] = c;
                break;
        }
    }
    s[j] = '\0';
}

void unescape(char s[], char t[])
{
    int c, i, j;

    for(i = 0, j = 0; i < MAXLINE && j < MAXLINE - 1 && (c = t[i]) != '\0'; i++) {
        if (c == '\\') {
            c = t[++i];
            switch (c) {
                case 't':
                    s[j++] = '\t';
                    break;
                case 'n':
                    s[j++] = '\n';
                    break;
                default:
                    s[j++] = '\\';
                    s[j++] = c;
                    break;
            }
        } else {
            s[j++] = c;
        }
    }
    s[j] = '\0';
}
