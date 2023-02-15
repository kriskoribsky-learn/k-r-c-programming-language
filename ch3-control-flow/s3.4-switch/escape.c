#include <stdio.h>

// converts characters like newline and tab into visible escape sequences like \n and \t
void escape(char s[], char t[]);

int main (void)
{
    char s[] = "asdasd\tsadlpasd\t\tasd-endofline|\nthis should be on new line";
    char t[256];

    escape(s, t);

    printf("original: '%s'\n", s);
    printf("result: '%s'\n", t);

    return 0;
}

void escape(char s[], char t[])
{
    int ch, i, j;
    
    i = j = 0;
    while ((ch = s[i]) != '\0') {
        switch (ch) {
            case '\n':
                t[j++] = '\\';
                t[j++] = 'n';
                break;
            case '\t':
                t[j++] = '\\';
                t[j++] = 't';
                break;
            default:
                t[j++] = ch;
                break;
        }
        i++;
    }
    // add a terminator
    t[j] = '\0';
}