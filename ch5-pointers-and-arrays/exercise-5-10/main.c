#include <stdio.h>
#include <stdlib.h>

#include "calc.h"

#define MAXOP 100

int main(void)
{
    int type;
    double op2; /* the order of function call evaluation is not defined */
    char s[MAXOP];

    while ((type = getop(s)) != EOF && type != '\n')
    {
        switch (type)
        {
        case NUMBER:
            push(atof(s));
            break;

        case '+':
            push(pop() + pop());
            break;

        case '-':
            op2 = pop();
            push(pop() - op2);
            break;

        case '*':
            push(pop() * pop());
            break;

        case '/':
            op2 = pop();
            if (op2 == 0.0)
            {
                fprintf(stderr, "Error: divison by zero\n");
                exit(EXIT_FAILURE);
            }
            push(pop() / op2);
            break;

        default:
            fprintf(stderr, "Error: unknown expression '%s'\n", s);
            break;
        }
    }

    return EXIT_SUCCESS;
}
