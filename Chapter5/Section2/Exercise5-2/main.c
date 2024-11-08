#include <stdio.h>

int getfloat(float *pn);

int main()
{
    float num = -1;
    while(getfloat(&num) != EOF)
        printf("%f\n", num);
    return 0;
}