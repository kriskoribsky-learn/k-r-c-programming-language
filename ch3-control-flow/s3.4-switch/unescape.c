#include <stdio.h>

// converts escape sequences into real characters
void unescape(char s[], char t[]);

int main(void)
{
    char s[] = "asdasd\\tsadlpasd\\t\\tasd-endofline|\\nthis should be on new line";
    char t[256];

    unescape(s, t);

    printf("original: '%s'\n", s);
    printf("result: '%s'\n", t);

    return 0;
}

void unescape(char s[], char t[])
{
    int ch, i, j;

    i = j = 0;
    while ((ch = s[i]) != '\0') {
        switch (ch) {
            case '\\':
                switch (s[i+1]) {
                    case 'n':
                        t[j++] = '\n';
                        i++;
                        break;
                    case 't':
                        t[j++] = '\t';
                        i++;
                        break;
                    default:
                        t[j++] = '\\';
                        break;
                }
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