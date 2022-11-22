#include <stdio.h>
#define MAXLINE 1000

int getline(char[], int);
void reverse(char[], int);

int main ()
{
    int len;
    char s[MAXLINE];

    while ((len = getline(s, MAXLINE)) > 0) {
        reverse(s, len);
        printf("%s", s);
    }
    return 0;
}

int getline(char s[], int max) 
{
    int i, c;

    for (i=0; i <= max && (c = getchar())!=EOF && c!='\n'; i++)
        s[i] = c;

    if (c == '\n') {
        s[i] = c;
        i++;
    }
    s[i] = '\0'; // important to not forget the null terminator
    return i;
}

void reverse(char s[], int len)
{
    len--; // ingore the last newline character, as well as null terminator
    char tmp;
    for (int i=0; i < len/2; i++) {
        tmp = s[i];
        s[i] = s[len-i-1];
        s[len-i-1] = tmp;
    }
}
