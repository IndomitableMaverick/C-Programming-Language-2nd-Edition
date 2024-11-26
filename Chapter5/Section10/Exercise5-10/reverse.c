#include <string.h>

void reverse(char *s)
{
    char c, *start = s, *end = (s + strlen(s) - 1);
    while(start < end) 
        c = *start, *start++ = *end, *end-- = c;
}