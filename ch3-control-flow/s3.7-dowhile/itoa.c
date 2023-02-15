#include <stdio.h>
#include <string.h>

void itoa(int n, char s[]);
void reverse(char s[]);

int main (void)
{
    char s[256];
    itoa(-2147483648, s);

    printf("%s\n", s);

    return 0;
}

// version of itoe from the book doesn't handle the largest negative integer because it's
// convertion to positive integer will overflow as range of two's complement signed integer is -2**(n-1) - 2**(n-1)-1
// so the largest negative integer doesn't have its positive equivalent
// we can correct this by using unsigned int
void itoa(int n, char s[])
{
    int i, sign;
    unsigned int num;

    if ((sign = n) < 0)
        num = -n;
    else
        num = n;
    
    i = 0;
    do {
        s[i++] = num % 10 + '0';
    } while ((num /= 10) > 0);
    
    if (sign < 0)
        s[i++] = '-';
    
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