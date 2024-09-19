#include <stdio.h>

int rightrot(int x, int n);

main()
{
    printf("%o", rightrot(065, 2));
    return 0;
}

/* returns the value of the integer x rotated to the right by n positions. */
int rightrot(int x, int n)
{
    int mask = ~(~0 << n);
    return (x & mask) << (sizeof(x) << 3) - n | x >> n;
}