#include <stdio.h>
#include <string.h>

void itoa(int n, char s[]);
void reverse(char s[]);

main()
{
    int n = 1 << sizeof(int) * 8 - 1;
    char s[1024];
    itoa(n, s);
    printf("%s\n", s);

    n = 16;
    itoa(n, s);
    printf("%s\n", s);
}

/* itoa: convert n to characters in s */ 
void itoa(int n, char s[]) 
{ 
    int i, sign; 
    if ((sign = n) < 0) /* record sign */ 
        n = -n; /* make n positive */ 
    i = 0; 
    do { /* generate digits in reverse order */ 
        s[i++] = n % 10 * (n % 10 < 0 ? -1 : 1) + '0'; /* get next digit */ 
    } while ((n /= 10) != 0); /* delete it, using != 0 to handle with -(2^wordsize - 1).*/ 
    if (sign < 0) 
        s[i++] = '-'; 
    s[i] = '\0';
    reverse(s); 
}

void reverse(char s[])
{
    int i, j;
    char c;
    for (i = 0, j = strlen(s) - 1; i < j; i++, j--) 
        c = s[i], s[i] = s[j], s[j] = c;
}