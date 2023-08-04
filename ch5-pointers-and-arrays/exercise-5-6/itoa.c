#include <stdio.h>

#define MAX_LEN 100

void itoa(int n, char *s);

int main(void)
{
    int n;
    char s[MAX_LEN];

    printf("Int to convert to string: ");
    scanf("%d", &n);

    itoa(n, s);

    printf("Resulting int: '%s'\n", s);
}

void itoa(int n, char *s)
{
    if (n < 0)
    {
        *s++ = '-';
        n *= -1;
    }

    if (n / 10 != 0)
    {
        itoa(n / 10, s);
    }

    while (*s != '\0')
    {
        *s++;
    }

    *s++ = '0' + n % 10;
    *s = '\0';
}
    