#include <stdio.h>
#include <string.h>

#define MAX_LEN 100

void reverse(char *s);

int main(void)
{
    char s[MAX_LEN];

    printf("String: ");
    scanf("%s", s);

    reverse(s);

    printf("Reversed: %s\n", s);
}

void reverse(char *s)
{
    char *r = s;

    while (*r != '\0')
    {
        r++;
    }

    for (--r; s < r; s++, r--)
    {
        char tmp = *s;
        *s = *r;
        *r = tmp;
    }
}
