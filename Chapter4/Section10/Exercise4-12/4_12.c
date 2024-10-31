#include <stdio.h>

void itoa(int n, char s[]);

int i;

int main()
{
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

/* itoa: convert n to characters in s (recursive version) */ 
void itoa(int n, char s[]) 
{ 
    int sign; 
    if ((sign = n) < 0){ /* record sign */
        s[i++] = '-';
        n = -n; /* make n positive */ 
    }  
    if (n / 10)/* generate digits */ 
        itoa(n / 10 * (n / 10 < 0 ? -1 : 1), s);
    s[i++] = n % 10 * (n % 10 < 0 ? -1 : 1) + '0';
}