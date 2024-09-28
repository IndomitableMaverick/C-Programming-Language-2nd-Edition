#include <stdio.h>
#include <string.h>

void itob(int n, char s[], int b);
void reverse(char s[]);

char bitString[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9',
                    'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j',
                    'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't',
                    'u', 'v', 'w', 'x', 'y', 'z'};

main()
{
    int n = 1 << sizeof(int) * 8 - 1;
    char s[1024];
    itob(n, s, 16);
    printf("%s\n", s);

    n = 16;
    itob(n, s, 16);
    printf("%s\n", s);
}

/* itob: convert the integer n into a base b character representation in the string s. */ 
void itob(int n, char s[], int b) 
{ 
    if(b < 2 || b > 36)
        s[0] = '\0';
    else
    {
        int i, sign; 
        if ((sign = n) < 0) /* record sign */ 
            n = -n; /* make n positive */ 
        i = 0; 
        do { /* generate digits in reverse order */ 
            s[i++] = bitString[n % b * (n % b < 0 ? -1 : 1)]; /* get next digit */ 
        } while ((n /= b) != 0); /* delete it, using != 0 to handle with -(2^wordsize - 1).*/ 
        if (sign < 0) 
            s[i++] = '-'; 
        s[i] = '\0';
        reverse(s); 
    }
}

void reverse(char s[])
{
    int i, j;
    char c;
    for (i = 0, j = strlen(s) - 1; i < j; i++, j--) 
        c = s[i], s[i] = s[j], s[j] = c;
}