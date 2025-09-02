#include <stdio.h>
#include <limits.h>
#include <float.h>

/* 
 * Exercise 2-1: Write a program to determine the ranges of char, short, int,
 * and long variables, both signed and unsigned, by printing appropriate values
 * from standard headers and by direct computation. Harder if you compute them:
 * determine the ranges of the various floating-point types.
 */

void compute_unsigned_char_range();
void compute_signed_char_range();
void compute_unsigned_short_range();
void compute_signed_short_range();
void compute_unsigned_int_range();
void compute_signed_int_range();
void compute_unsigned_long_range();
void compute_signed_long_range();
void compute_float_range();
void compute_double_range();
void print_standard_ranges();

int main() {
    printf("=== COMPUTED RANGES (Direct Calculation) ===\n\n");
    
    compute_signed_char_range();
    compute_unsigned_char_range();
    printf("\n");
    
    compute_signed_short_range();
    compute_unsigned_short_range();
    printf("\n");
    
    compute_signed_int_range();
    compute_unsigned_int_range();
    printf("\n");
    
    compute_signed_long_range();
    compute_unsigned_long_range();
    printf("\n");
    
    compute_float_range();
    compute_double_range();
    
    printf("\n");
    print_standard_ranges();

    return 0;
}

void compute_unsigned_char_range() {
    unsigned char c = 1;
    int i;
    
    for(i = 0; i < 8; i++) {
        if (i == 7) c = c * 2 - 1;
        else c = c * 2;
    }
    printf("unsigned char:    0 to %u\n", c);
}

void compute_signed_char_range() {
    signed char positive = 1;
    signed char negative = -1;
    int i;
    
    for(i = 0; i < 7; i++) {
        if (i == 6) positive = positive * 2 - 1;
        else positive = positive * 2;
    }
    
    for(i = 0; i < 7; i++) {
        negative = negative * 2;
    }
    
    printf("signed char:      %d to %d\n", negative, positive);
}

void compute_unsigned_short_range() {
    unsigned short j = 1;
    int i;
    
    for(i = 0; i < 16; i++) {
        if (i == 15) j = j * 2 - 1;
        else j = j * 2;
    }
    printf("unsigned short:   0 to %u\n", j);
}

void compute_signed_short_range() {
    signed short positive = 1;
    signed short negative = -1;
    int i;
    
    for(i = 0; i < 15; i++) {
        if (i == 14) positive = 2 * positive - 1; 
        else positive = positive * 2;
    }
    
    for(i = 0; i < 15; i++) {
        negative = negative * 2;
    }
    
    printf("signed short:     %d to %d\n", negative, positive);
}

void compute_unsigned_int_range() {
    unsigned int n = 1;
    int i;
    
    for(i = 0; i < 32; i++) {
        if (i == 31) n = n * 2 - 1;
        else n = n * 2;
    }
    printf("unsigned int:     0 to %u\n", n);
}

void compute_signed_int_range() {
    signed int positive = 1;
    signed int negative = -1;
    int i;
    
    for(i = 0; i < 31; i++) {
        if (i == 30) positive = 2 * positive - 1;
        else positive = positive * 2;
    }
    
    for(i = 0; i < 31; i++) {
        negative = negative * 2;
    }
    
    printf("signed int:       %d to %d\n", negative, positive);
}

void compute_unsigned_long_range() {
    unsigned long k = 1;
    int i;
    
    for(i = 0; i < 64; i++) {
        if (i == 63) k = k * 2 - 1;
        else k = k * 2;
    }
    printf("unsigned long:    0 to %lu\n", k);
}

void compute_signed_long_range() {
    signed long positive = 1;
    signed long negative = -1;
    int i;
    
    for(i = 0; i < 63; i++) {
        if (i == 62) positive = 2 * positive - 1;
        else positive = positive * 2;
    }
    
    for(i = 0; i < 63; i++) {
        negative = negative * 2;
    }
    
    printf("signed long:      %ld to %ld\n", negative, positive);
}

void compute_float_range() {
    float f_max = 1.0f;
    float prev_max = f_max;
    
    while (1) {
        float next = f_max * 2.0f;
        if (next <= f_max || next == (1.0f/0.0f)) 
            break;
        prev_max = f_max;
        f_max = next;
    }

    float step = f_max/2.0f;
    while ((f_max + step) > f_max) {
        prev_max = f_max;
        f_max += step;
        step /= 2.0f;
    }

    float f_min = 1.0f;
    float prev_min = f_min;

    while(1) {
        float next = f_min / 2.0f;
        if (next >= f_min || next == 0.0f) break;
        prev_min = f_min;
        f_min = next;
    }

    float step_min = f_min * 2.0f;
    float mid;
    while((mid = (step_min - f_min)) < f_min && mid > 0) {
        prev_min = f_min;
        step_min = f_min;
        f_min = mid;
    }
    
    printf("float:            %e to %e (smallest positive: %e)\n", 
           -prev_max, prev_max, prev_min);
}

void compute_double_range() {
    double d_max = 1.0;
    double prev_max = d_max; 

    while (1) {
        double next = d_max * 2.0;
        if (next <= d_max || next == (1.0/0.0)) 
            break;
        prev_max = d_max;
        d_max = next;
    }

    double step = d_max/2.0;
    while ((d_max + step) > d_max) {
        prev_max = d_max;
        d_max += step;
        step /= 2.0;
    }

    double d_min = 1.0;
    double prev_min = d_min;

    while(1) {
        double next = d_min / 2.0;
        if (next >= d_min || next == 0.0) break;
        prev_min = d_min;
        d_min = next;
    }

    double step_min = d_min * 2.0;
    double mid;
    while((mid = (step_min - d_min)) < d_min && mid > 0) {
        prev_min = d_min;
        step_min = d_min;
        d_min = mid;
    }
    
    printf("double:           %e to %e (smallest positive: %e)\n", 
           -prev_max, prev_max, prev_min);
}

void print_standard_ranges() {
    printf("=== STANDARD LIBRARY RANGES (limits.h & float.h) ===\n\n");
    printf("signed char:      %d to %d\n", CHAR_MIN, CHAR_MAX);
    printf("unsigned char:    0 to %d\n\n", UCHAR_MAX);
    printf("signed short:     %d to %d\n", SHRT_MIN, SHRT_MAX);
    printf("unsigned short:   0 to %d\n\n", USHRT_MAX);
    printf("signed int:       %d to %d\n", INT_MIN, INT_MAX);
    printf("unsigned int:     0 to %u\n\n", UINT_MAX);
    printf("signed long:      %ld to %ld\n", LONG_MIN, LONG_MAX);
    printf("unsigned long:    0 to %lu\n\n", ULONG_MAX);
    printf("float:            %e to %e (FLT_MIN: %e)\n", -FLT_MAX, FLT_MAX, FLT_MIN);
    printf("double:           %e to %e (DBL_MIN: %e)\n\n", -DBL_MAX, DBL_MAX, DBL_MIN);
}

