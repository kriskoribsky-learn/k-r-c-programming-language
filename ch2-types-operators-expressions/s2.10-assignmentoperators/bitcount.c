#include <stdio.h>

// in two's complement number system x &= (x-1) deletes the rightmost 1-bit in x because
// the rightmost 1-bit represents the ones difference between x and x-1 which is that deleted by bitwise and
int bitcount(unsigned int x);

int main ( void )
{
    printf("%d\n", bitcount(4548));

    return 0;
}

int bitcount(unsigned int x)
{
    int b;

    for (b=0; x != 0; x &= x-1)
        b++;

    return b;
}