#include <stdio.h>
#define MAXLINE 1000

// helpers
int line_len(char s[])
{
    int i=0;
    while (s[i] != '\0')
        i++;

    return i;
}

int get_line(char[], int);
void rstrip(char[], int);

int main()
{
    int len;
    char line[MAXLINE];

    while ((len = get_line(line, MAXLINE)) > 0)
    {
        printf("Input line legth: %d\n", len);
        printf("Input line:\n %s\n", line); 
        rstrip(line, len);
        printf("Rstripped line lenth: %d\n", line_len(line));
        printf("Rstripped line:\n %s\n", line);
    }
    return 0;
}

// gets line from stdin and outputs its length (0 for EOF)
int get_line(char s[], int maxline)
{
    int i, c;

    for (i = 0; i <= maxline && (c = getchar()) != EOF && c != '\n'; i++)
        s[i] = c;

    if (c == '\n')
    {
        s[i] = '\n';
        i++;
    }
    s[i] = '\0'; // don't forget the null terminator
    return i;
}

void rstrip(char s[], int len)
{
    int i;
    int had_newline = 0;
    for (i=len; i >= 0 && (s[i] == ' ' || s[i] == '\t' || s[i] == '\n'); i--) {
        if (s[i] == '\n')
            had_newline = 1;
    }
    if (had_newline)
        s[i] = '\n';
        i++;

    s[i] = '\0'; // // trim the string at the last position of whitespace or 0
}
