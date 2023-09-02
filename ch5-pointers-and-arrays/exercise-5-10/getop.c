#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#include "calc.h"

int getop(char s[])
{
    /* remove whitespace */
    while ((s[0] = getch()) == ' ' || s[0] == '\t')
        ;
    s[1] = '\0';

    /* not a number */
    if (!isdigit(s[0]) && s[0] != '.')
    {
        return s[0];
    }

    /* integer part */
    int i = 0;
    if (isdigit(s[0]))
        while (isdigit(s[++i] = getch()))
            ;

    /* fractional part */
    if (s[i] == '.')
        while (isdigit(s[++i] = getch()))
            ;

    if (s[i] != EOF)
        ungetch(s[i]);

    s[i] = '\0';

    return NUMBER;
}
