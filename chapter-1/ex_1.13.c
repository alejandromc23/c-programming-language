#include <stdio.h>

// Horizontal histogram of word lengths
// int main() {
//     int i, j, size, c;
//     int nc[44]; // longest word size in english is 45 characters
//
//     size = 0;
//
//     for (i = 0; i <= 44; i++) {
//         nc[i] = 0;
//     }
//
//     while((c = getchar()) != EOF) {
//         if((c <= 'Z' && c >= 'A') || (c <= 'z' && c >= 'a')) {
//             ++size;
//             continue;
//         }
//         
//         if (size > 0) ++nc[size-1]; 
//         size = 0;
//     }
//
//     for (i = 0; i<=44; i++) {
//         printf("word size %d:", i + 1);
//         for (j = 1; j<=nc[i]; j++) {
//             printf("#");
//         }
//         printf("\n");
//     }
// }

// Vertical histogram
int main() 
{
    int i, j, k, size, c, max;
    int nc[44]; // longest word size in english is 45 characters

    size = 0;
    max = 0;

    for (i = 0; i <= 44; i++) {
        nc[i] = 0;
    }

    while((c = getchar()) != EOF) {
        if((c <= 'Z' && c >= 'A') || (c <= 'z' && c >= 'a')) {
            ++size;
            continue;
        }
        
        if (size > 0) {
            ++nc[size-1];
        }

        if (nc[size-1] > max) max = nc[size-1]; 

        size = 0;
    }

    for(k = max; k >= 0; k--) {
        for(j = 0; j <= 44; j++) {
            if (k == 0) { 
                if (j>8) printf(" %d", j+1);
                else printf(" %d ", j+1);
                continue;
            }
            else if (nc[j] < k) printf("   ");
            else printf(" # ");
        }
        printf("\n");
    }
}

// Test
// Contrary to popular belief, Lorem Ipsum is not simply random text. It has roots in a piece of classical Latin literature from 45 BC, making it over 2000 years old. Richard McClintock, a Latin professor at Hampden-Sydney College in Virginia, looked up one of the more obscure Latin words, consectetur, from a Lorem Ipsum passage, and going through the cites of the word in classical literature, discovered the undoubtable source. Lorem Ipsum comes from sections 1.10.32 and 1.10.33 of "de Finibus Bonorum et Malorum" (The Extremes of Good and Evil) by Cicero, written in 45 BC. This book is a treatise on the theory of ethics, very popular during the Renaissance. The first line of Lorem Ipsum, "Lorem ipsum dolor sit amet..", comes from a line in section 1.10.32.


// Result
 
 //    #                                                                                                                                  
 //    #                                                                                                                                  
 //    #        #                                                                                                                         
 //    #        #                                                                                                                         
 //    #        #                                                                                                                         
 //    #        #                                                                                                                         
 //    #        #                                                                                                                         
 //    #        #                                                                                                                         
 //    #        #                                                                                                                         
 //    #  #  #  #                                                                                                                         
 //    #  #  #  #                                                                                                                         
 //    #  #  #  #                                                                                                                         
 //    #  #  #  #     #                                                                                                                   
 //    #  #  #  #     #                                                                                                                   
 //    #  #  #  #  #  #                                                                                                                   
 //    #  #  #  #  #  #                                                                                                                   
 //    #  #  #  #  #  #                                                                                                                   
 //    #  #  #  #  #  #                                                                                                                   
 //    #  #  #  #  #  #                                                                                                                   
 //    #  #  #  #  #  #                                                                                                                   
 // #  #  #  #  #  #  #  #                                                                                                                
 // #  #  #  #  #  #  #  #     #                                                                                                          
 // #  #  #  #  #  #  #  #  #  #  #                                                                                                       
 // #  #  #  #  #  #  #  #  #  #  #                                                                                                       
 // #  #  #  #  #  #  #  #  #  #  #                                                                                                       
 // 1  2  3  4  5  6  7  8  9  10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 29 30 31 32 33 34 35 36 37 38 39 40 41 42 43 44 45
