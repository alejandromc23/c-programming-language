#include <stdio.h>

float fahr_to_celsius(float fahr);

int main() 
{
    float fahr, celsius;
    int lower, upper, step;

    lower = 0;
    upper = 300;
    step = 20;

    fahr = lower;

    for(fahr = lower; fahr <= upper; fahr = fahr + step) {
        celsius = fahr_to_celsius(fahr);
        printf("%3.0f %6.1f\n", fahr, celsius); 
    }

    return 0;
}

float fahr_to_celsius(float fahr) 
{
    int celsius;

    celsius = (5.0 / 9.0) * (fahr - 32.0);

    return celsius;
}
