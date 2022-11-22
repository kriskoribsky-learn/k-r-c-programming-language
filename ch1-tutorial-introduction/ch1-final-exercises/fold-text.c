#include <stdio.h>
#define FOLD_LIMIT 20

int fold_line(char[], int);

int main()
{
    char s[FOLD_LIMIT+3]; // 1 for potential needed hyphen 1 for newline 1 for the null operator

    while (fold_line(s, FOLD_LIMIT) != 0)
        printf("%s", s);

    return 0;
}

// folds line into input string & returns 0 if there is no more input in stdin
int fold_line(char s[], int fold_limit)
{
    int i, c;

    for (i=0; i < fold_limit && (c = getchar()) != EOF && c != '\n'; i++) {
        s[i] = c;
    }

    if (i == fold_limit && c != ' ' && c != '\t') {
        s[i] = '-';
        i++;
    }

    s[i] = '\n';
    s[i+1] = '\0';

    if (c == EOF)
        return 0;
    else
        return 1;
}
