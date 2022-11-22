#include <stdio.h>

float farenheit_to_celsius(float);
float celsius_to_farenheit(float);

int main()
{
    printf("120 Farenheit to Celsius: %.1f\n", farenheit_to_celsius(120));
    printf("50 Celsius to Farenheit: %.1f\n", celsius_to_farenheit(50));

    return 0;
}

float farenheit_to_celsius(float fahr) {
    return (5.0/9.0) * (fahr-32);
}

float celsius_to_farenheit(float celsius) {
    return (celsius * (9.0/5.0)) + 32;
}