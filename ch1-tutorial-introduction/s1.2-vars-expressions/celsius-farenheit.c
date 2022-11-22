#include <stdio.h>

int main()
{
    // celsius to farenheit convertion program
    // F = (9/5) * C + 32
    printf("This program converts degrees celsius to degrees farenheit on given range.\n");

    float fahr, celsius;
    int lower, upper, step;

    lower = 0;
    upper = 300;
    step = 20;

    celsius = lower;
    while (celsius <= upper)
    {
        fahr = (9.0/5.0) * celsius + 32;
        printf("%3.0f\t%3.1f\n", celsius, fahr);
        celsius += step;
    }
}