#include <stdio.h>

/* Write a loop equivalent to the for loop above without using && or ||. */

/* the original loop is
 * for(i = 0; i<lim-1 && (c=getchar()) != '\n' && c != EOF; ++i)
 */

void loop_equivalent();

int main() {
    loop_equivalent();
    return 0;
}

void loop_equivalent() {
    int lim = 10;
    int c, i;
    for(i = 0; i<lim-1; ++i) {
        if( (c = getchar()) == '\n') break;
        if (c == EOF) break;
    }
}
