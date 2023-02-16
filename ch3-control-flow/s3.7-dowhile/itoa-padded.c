#include <stdio.h>
#include <string.h>

void itoa_padded(int n, char s[], int w);
void reverse(char s[]);

int main(void)
{
    char s[256];
    itoa_padded(-158, s, 5);

    printf("%s\n", s);

    return 0;
}

void itoa_padded(int n, char s[], int w)
{
    int i, sign;
    unsigned int num;

    if ((sign = n) < 0)
        num = -n;
    else
        num = n;

    i = 0;
    do
    {
        s[i++] = num % 10 + '0';
        w--;
    } while ((num /= 10) > 0);

    if (sign < 0) {
        s[i++] = '-'; 
        w--;
    }

    // pad the remaining width
    while(w > 0) {
        s[i++] = ' ';
        w--;
    }

    s[i] = '\0';
    reverse(s);
}

void reverse(char s[])
{
    int i, j;
    char temp;

    for (i = 0, j = strlen(s) - 1; i < j; i++, j--)
    {
        temp = s[i];
        s[i] = s[j];
        s[j] = temp;
    }
}