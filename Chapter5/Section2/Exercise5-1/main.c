#include <stdio.h>

int getint(int *pn);

int main()
{
    int num = -1;
    while(getint(&num) != EOF)
        printf("%d\n", num);
    return 0;
}