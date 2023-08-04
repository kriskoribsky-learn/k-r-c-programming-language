#include <stdio.h>

#define MAX_LEN 100

void itoa(int n, char *s);

int main(void)
{
    int n;
    char s[MAX_LEN];

    printf("Int to convert to string: ");
    scanf("%d", n);

    itoa(n, s);

    printf("Resulting int: '%s'\n", s);
}

void itoa(int n, char *s)
{
    if (n < 0)
    {
        *s++ = '-';
    }

    if (n < 10)
    {
        *s++ = '0' + n;
    } else
    {
        itoa(n/10, s);
    }




}
