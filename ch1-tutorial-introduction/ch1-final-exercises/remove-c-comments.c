#include <stdio.h>

#define IN 1
#define OUT 0

void skip_quoted(char);
void clear_multiline_comment(void);
void clear_singleline_comment(void);

int main()
{
    int c1, c2;

    while ((c1 = getchar()) != EOF) {
        c2 = getchar(); // get next char

        if (c1 == '\'' || c1 == '"') {
            putchar(c1);
            putchar(c2);
            skip_quoted(c1);
        }
        else if (c1 == '/' && c2 == '*')
            clear_multiline_comment();
        else if (c1 == '/' && c2 == '/')
            clear_singleline_comment();
        else {
            putchar(c1);
            putchar(c2);
        }
    }
    return 0;
}

// iterates to the end of quoted string || character constant
void skip_quoted(char quote_type)
{
    int c;
    while ((c = getchar()) != quote_type)
        putchar(c);

    putchar(c); // return quote
}

void clear_multiline_comment(void)
{
    while (getchar() != '*' && getchar() != '/')
        ;
}

void clear_singleline_comment(void)
{
    while (getchar() != '\n')
        ;
}

