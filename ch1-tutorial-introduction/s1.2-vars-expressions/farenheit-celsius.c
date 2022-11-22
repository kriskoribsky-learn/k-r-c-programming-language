#include <stdio.h>

int main()
{
    // farenheit to celsius convertion program
    // C = 5/9 * (F-32)
    printf("This program converts degrees farenheit to degrees celsius on given range.\n");

    float fahr, celsius;
    int lower, upper, step;

    lower = 0;
    upper = 300;
    step = 20;

    fahr = lower;
    while (fahr <= upper) {
        celsius = (5.0/9.0) * (fahr-32);
        printf("%3.0f\t%3.1f\n", fahr, celsius);
        fahr += step;
    }
}