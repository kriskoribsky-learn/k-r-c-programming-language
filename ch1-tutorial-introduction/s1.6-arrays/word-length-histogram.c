#include <stdio.h>

#define MAX_LENGTH 10

int main()
{
    int c, nword;
    int nwords[MAX_LENGTH];

    for (int i=0; i < MAX_LENGTH; i++)
        nwords[i] = 0;

    while ((c = getchar()) != EOF) {
        if (c == ' ' || c == '\n' || c == '\t') {
            if (nword > 0 && nword < MAX_LENGTH) {
                nwords[nword-1]++;
            } else if (nword >= MAX_LENGTH)
                nwords[MAX_LENGTH-1]++;
    
            nword = 0;
        }
        else
            nword++;
    }
    printf("Word lengths histogram:\n");
    for (int i=0; i < MAX_LENGTH; i++) {
        if (i+1 == MAX_LENGTH)
            printf("%d+: ", i+1);
        else
            printf("%d: ", i+1);
        
        for (int j=0; j < nwords[i]; j++)
            printf("-");
        
        printf("\n");
    }
}