#include <stdio.h>
#include <ctype.h>

#include "getch.c"

int getch(void);
void ungetch(int);

int getfloat(float *pn);

int main(void)
{
    float num;

    printf("Enter a decimal number:\n");
    if (!getfloat(&num))
    {
        printf("Error! Not a number.\n");
        return 1;
    }

    printf("Converted decimal number is: '%f'\n", num);
}

int getfloat(float *pn)
{
    int c;
    while (isspace((c = getch()))) /* skip whitespace */
        ;

    if (!isdigit(c) && c != '-' && c != '+') /* not a number */
    {
        ungetch(c);
        return 0;
    }

    int sign = (c == '-') ? -1 : 1; /* explicit/implicit sign */

    if ((c == '-' || c == '+') && !isdigit(c = getch())) /* not a number after sign */
    {
        ungetch(sign == -1 ? '-' : '+');
        ungetch(c);
        return 0;
    }

    for (*pn = 0; isdigit(c); c = getch()) /* read whole number part */
    {
        *pn = *pn * 10 + (c - '0');
    }

    if (c == '.') /* read integral number part */
    {
        if (!isdigit(c = getch()))
        {
            ungetch('.');
            ungetch(c);
        }
        else
        {
            for (long i = 10; isdigit(c); c = getch(), i *= 10)
            {
                *pn += (float)(c - '0') / i;
            }
        }
    }

    *pn *= sign;

    if (c != EOF)
    {
        ungetch(c);
    }

    return c;
}
