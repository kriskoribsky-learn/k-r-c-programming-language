#include <stdio.h>
#include <limits.h>
#include <float.h>

float x = 5.849;


int main(void)
{
    // Using information from headers
    // ==========================================================================
    printf("Headers:\n");
    printf("------------\n");
    printf("Unsigned char: \t%d - %d\n", 0, UCHAR_MAX);
    printf("Signed char: \t%d - %d\n", SCHAR_MIN, SCHAR_MAX);

    printf("\n");

    printf("Unsigned short: \t%d - %d\n", 0, USHRT_MAX);
    printf("Signed short: \t%d - %d\n", SHRT_MIN, SHRT_MAX);

    printf("\n");

    printf("Unsigned int: \t%u - %u\n", 0, UINT_MAX);
    printf("Signed int: \t%d - %d\n", INT_MIN, INT_MAX);

    printf("\n");

    printf("Unsigned long: \t%lu - %lu\n", 0lu, ULONG_MAX);
    printf("Signed long: \t%ld - %ld\n", LONG_MIN, LONG_MAX);

    printf("\n");

    printf("Unsigned long long: \t%llu - %llu\n", 0llu, ULLONG_MAX);
    printf("Signed long long long: \t%lld - %lld\n", LLONG_MIN, LLONG_MAX);

    printf("Signed long size: %lu bits | Signed long long size: %lu bits\n", sizeof(long), sizeof(long long));

    printf("Float: \t%f - %f\n", FLT_MIN, FLT_MAX);
    printf("Double: \t%f - %f\n", DBL_MIN, DBL_MAX);
    printf("Long double: \t%Lf - %Lf\n", LDBL_MIN, LDBL_MAX);
}
