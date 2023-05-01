#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

void itoa(int n, char s[]);
size_t strlen(const char *s);

int main(void)
{
    char s[256];
    itoa(INT_MIN, s);

    printf("%s\n", s);

    return EXIT_SUCCESS;
}

void itoa(int n, char s[])
{
    if (n < 0)
    {
        s[0] = '-';
        s[1] = '\0';

        if (n / 10)
            itoa(-(n / 10), s + 1);

        size_t len = strlen(s);
        s[len] = -(n % 10) + '0';
        s[len + 1] = '\0';
    }
    else if (n >= 10)
    {
        itoa(n / 10, s);

        size_t len = strlen(s);
        s[len] = n % 10 + '0';
        s[len + 1] = '\0';
    }
    else
    {
        s[0] = n + '0';
        s[1] = '\0';
    }
}

size_t strlen(const char *s)
{
    size_t i;
    for (i = 0; s[i] != '\0'; i++)
        ;

    return i;
}