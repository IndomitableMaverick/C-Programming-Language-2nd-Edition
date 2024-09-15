#include <stdio.h>
#include <limits.h>
#include <float.h>
/*  the ranges of char, short, int, and long variables, both signed and unsigned, by printing appropriate values from standard headers */
main()
{
    printf("signed char: %d ~ %d    unsigned char: %d ~ %d\n", CHAR_MIN, CHAR_MAX, 0, UCHAR_MAX);
    printf("signed short: %d ~ %d    unsigned short: %d ~ %d\n", SHRT_MIN, SHRT_MAX, 0, USHRT_MAX);
    printf("signed int: %d ~ %d    unsigned int: %d ~ %lld\n", INT_MIN, INT_MAX, 0, UINT_MAX);
    printf("signed long: %ld ~ %ld    unsigned long: %ld ~ %lld\n", LONG_MIN, LONG_MAX, 0, ULONG_MAX);
    printf("float: %f ~ %f\n", FLT_MIN, FLT_MAX);
    printf("double: %f ~ %f\n", DBL_MIN, DBL_MAX);
    return 0;
}