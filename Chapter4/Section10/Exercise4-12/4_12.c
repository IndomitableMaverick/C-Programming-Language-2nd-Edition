#include <stdio.h>

void itoa(int n, char s[]);

int main()
{
    extern int i;

    int n = 1 << sizeof(int) * 8 - 1;
    char s[1024];
    i = 0;
    itoa(n, s);
    s[i] = '\0';
    printf("%s\n", s);

    n = 16;
    i = 0;
    itoa(n, s);
    s[i] = '\0';
    printf("%s\n", s);

    n = 0;
    i = 0;
    itoa(n, s);
    s[i] = '\0';
    printf("%s\n", s);
}