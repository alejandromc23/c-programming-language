#include <stdio.h>

int main() {
    int i, j, size, c;
    int nc[44]; // longest word size in english is 45 characters

    size = 0;

    for (i = 0; i <= 44; i++) {
        nc[i] = 0;
    }

    while((c = getchar()) != EOF) {
        if(c != ' ' && c != '\t' && c!= '\n') {
            ++size;
            continue;
        }
        
        if (size > 0) ++nc[size-1]; 
        size = 0;
    }

    for (i = 0; i<=44; i++) {
        printf("word size %d:", i + 1);
        for (j = 1; j<=nc[i]; j++) {
            printf("#");
        }
        printf("\n");
    }
}
