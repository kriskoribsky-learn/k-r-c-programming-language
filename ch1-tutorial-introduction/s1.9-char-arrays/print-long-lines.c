#include <stdio.h>
#define MAXLINE 1000
#define LENGTH_TRESHOLD 80

int get_line(char[], int);

int main()
{
    int len;
    char line[MAXLINE];

    while ((len = get_line(line, MAXLINE)) > 0) {
        printf("%d\n", len);
        if (len > LENGTH_TRESHOLD)
            printf("%s", line);
    }
    return 0;
}

// gets line from stdin and outputs its length (0 for EOF)
int get_line(char s[], int maxline)
{
    int i, c;

    for (i = 0; i <= maxline && (c = getchar())!=EOF && c!='\n'; i++)
        s[i] = c;

    if (c == '\n') {
        s[i] = '\n';
        i++;
    }
    s[i] = '\0'; // don't forget the null terminator
    return i;
}