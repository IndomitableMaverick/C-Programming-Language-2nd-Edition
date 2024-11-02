#include <stdio.h>

#define swap(t, x, y) { t temp = (x); (x) = (y); (y) = temp; } /* interchanges two arguments of type t */

int main()
{
    int x = 2024, y = 1102;
    printf("x = %d  y = %d\n", x, y);
    swap(int, x, y);
    printf("x = %d  y = %d\n", x, y);
    return 0;
}