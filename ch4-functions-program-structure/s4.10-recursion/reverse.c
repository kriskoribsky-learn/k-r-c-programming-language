#include <stdio.h>
#include <string.h>

void reverse(char *s);

int main(void)
{
    char s[256] = "hello world";

    printf("%s\n", s);
    reverse(s);
    printf("%s\n", s);
}

void reverse(char *s)
{
    static int i = 0;
    static int j = 0;

    if (s[i] != '\0')
    {
        char c = s[i++];
        reverse(s);

        s[j++] = c;
    }
}
{
    static int i = 0;
    static int j = 0;

    if (s[i] != '\0')
    {
        char c = s[i++];
        reverse(s);

        s[j++] = c;
    }
}