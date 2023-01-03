#include <stdio.h>
#include <stdlib.h>



void squeeze(char s1[], char s2[]);

int main(int argc, char *argv[])
{
    if (argc != 3) {
        fprintf(stderr, "Wrong number of arguments!\nUsage: ./squeeze <original string> <string of values to exclude>\n");
        return EXIT_FAILURE;
    }

    squeeze(argv[1], argv[2]);

    printf("%s\n", argv[1]);
    return EXIT_SUCCESS;
}

// void squeeze(char s1[], char s2[])
// {
//     int i, j, k, match;

//     // iterate s1
//     for (i = j = 0; s1[i] != '\0'; i++) {
//         // iterate s2
//         match = 0;
//         for (k = 0; s2[k] != '\0'; k++)
//             if (s2[k] == s1[i]) {
//                 match = 1;
//                 break;
//             }
                
//         if (!match)
//             s1[j++] = s1[i];
//     }
//     s1[j] = '\0';
// }

void squeeze(char str1[], char str2[])
{
    int i, j, k;
    for (k = 0; str2[k] != '\0'; k++)
    {
        for (i = j = 0; str1[i] != '\0'; i++)
        {
            if (str1[i] != str2[k])
            {
                str1[j++] = str1[i];
            }
        }

        str1[j] = '\0';
    }
}