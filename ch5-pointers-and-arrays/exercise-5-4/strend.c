#include <stdio.h>
#include <stdbool.h>

#define MAX_LEN 100

bool strend(char *restrict s, char *restrict end);

int main(void)
{
    char s1[2 * MAX_LEN];
    char s2[MAX_LEN];

    printf("First string: ");
    scanf("%s", s1);

    printf("Second string: ");
    scanf("%s", s2);

    printf("First string ends with second string: '%s'\n", strend(s1, s2) ? "True" : "False");
}

bool strend(char *restrict s, char *restrict end)
{
    char *start = end;

    while (*s)
    {
        end = *end == *s++ ? end + 1 : start;
    }

    return *end == '\0';
}
