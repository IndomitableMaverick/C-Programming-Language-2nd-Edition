#include <stdio.h>

int lower(int c);
/* Rewrite the function lower, which converts upper case letters to lower case, with a conditional expression instead of if-else.*/
main()
{
    printf("%c %c", lower('A'), lower(';'));
}

/* lower: convert c to lower case; ASCII only */ 
int lower(int c) 
{ 
    return (c >= 'A' && c <= 'Z') ? c + 'a' - 'A' : c;
}