#include <stdio.h>

/* strcat: concatenate t to end of s */ 
void my_strcat(char *s, char *t) 
{ 
    while(*s)
        ++s;
    while(*s++ = *t++)
        ;
}