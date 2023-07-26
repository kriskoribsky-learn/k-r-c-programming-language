#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>

#include "getch.c"

int getch(void);
void ungetch(int);
int getint(int *pn);

int main(void)
{
    int num;

    printf("Enter a number:\n");
    if (!getint(&num))
    {
        printf("Error! Not a number.\n");
        return 1;
    }

    printf("Converted number is: '%d'\n", num);
}

int getint(int *pn)
{
    int c, sign;

    // skip whitespace
    while (isspace(c = getch()) != 0)
        ;

    if (!isdigit(c) && c != EOF && c != '+' && c != '-')
    {
        ungetch(c);
        return 0;
    }

    sign = (c == '-') ? -1 : 1;

    if ((c == '-' || c == '+') && !isdigit(c = getch()))
    {
        ungetch(c);
        ungetch(sign == -1 ? '-' : '+');
        return 0;
    }

    for (*pn = 0; isdigit(c); c = getch())
    {
        *pn = *pn * 10 + (c - '0');
    }

    *pn *= sign;

    if (c != EOF)
    {
        ungetch(c);
    }
    return c;
}
