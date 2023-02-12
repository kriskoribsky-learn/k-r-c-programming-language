#include <stdio.h>

char lower(char ch);

int main(void)
{
    printf("%c\n", lower('A'));

    return 0;
}

char lower(char ch)
{
    return (ch >= 'A' && ch <= 'Z') ? ch - 'A' + 'a' : ch;
}