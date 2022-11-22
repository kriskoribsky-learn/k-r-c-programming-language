#include <stdio.h>

int main()
{
    // farenheit to celsius convertion program
    // C = 5/9 * (F-32)
    printf("This program converts degrees farenheit to degrees celsius on given range.\n");

    for (int fahr = 0; fahr <= 300; fahr += 20)
        printf("%3d\t%6.1f\n", fahr, (5.0/9.0) * (fahr-32));
}