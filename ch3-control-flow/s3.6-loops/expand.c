#include <stdio.h>
#include <stdbool.h>

#define SIZE 1024

void expand(char s1[], char s2[]);
bool is_alnum(char ch);

int main(void)
{
    char s1[] = "a-b-c a-z0-9 -a-z";
    char s2[SIZE];

    expand(s1, s2);

    printf("%s\n", s1);
    printf("%s\n", s2);

    return 0;
}

void expand(char s1[], char s2[])
{
    int i, j;
    char start, end;

    start = end = '\0';
    for (i=0, j=0; s1[i] != '\0'; i++) {
        while (is_alnum(s1[i]) && s1[i+1] == '-' && is_alnum(s1[i+2]) && s1[i] < s1[i+2]) {
            start = s1[i];
            end = s1[i+2];

            while (start < end)
                s2[j++] = start++;
            
            i+=2;
        }
        s2[j++] = s1[i];
    }
    // add a terminator
    s2[j] = '\0';
}

bool is_alnum(char ch)
{
    return (ch >= '0' && ch <= '9') || (ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z');
}