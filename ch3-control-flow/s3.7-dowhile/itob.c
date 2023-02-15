#include <stdio.h>
#include <string.h>

#define BASE 'A';

void itob(int n, char s[], int b);
void reverse(char s[]);

int main(void)
{
    char s[256];

    itob(4184945, s, 16);
    printf("%s\n", s);

    return 0;
}

void itob(int n, char s[], int b)
{
    int i, sign;
    unsigned int num, remainder;

    if ((sign = n) < 0)
        num = -n;
    else
        num = n;

    i = 0;
    do {
        remainder = num % b;
        s[i++] = remainder > 9 ? remainder - 10 + 'a' : remainder + '0';
    } while ((num /= b) > 0);

    if (sign < 0)
        s[i++] = '-';

    s[i] = '\0';
    reverse(s);
}

void reverse(char s[])
{
    int i, j;
    char temp;

    for (i=0, j=strlen(s)-1; i < j; i++, j--) {
        temp = s[i];
        s[i] = s[j];
        s[j] = temp;
    }
}