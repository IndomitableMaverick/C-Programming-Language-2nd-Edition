#include <stdio.h>
#include <ctype.h>

long htoi(char s[]);

main()
{
    printf("%ld\n", htoi(""));
    printf("%ld\n", htoi("-917"));
    printf("%ld\n", htoi("0x2024"));
}

/* converts a string of hexadecimal digits (including an optional 0x or 0X) into its equivalent integer value. 
The allowable digits are 0 through 9, a through f, and A through F. */
long htoi(char s[])
{
    if(s[0] == '\0')
        return 0;//empty input

    int i = 0;
    long n = 0;
    int sign = 1;

    if(s[0] == '-')
    {
        sign = -1;
        i = 1;
    }
    while(isdigit(s[i]) || isalpha(s[i]))
    {
        n <<= 4;
        if(isdigit(s[i]))
            n += s[i] - '0';
        else
        {
            char c = tolower(s[i]);
            if(c >= 'a' && c <= 'f')
                n += c - 'a' + 10;
            else if (c != 'x' || !(i == 1 && sign == 1 || i == 2 && sign == -1))
                return -1;//invalid input
        }
        ++i;
    }
    return sign * n;
}