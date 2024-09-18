#include <stdio.h>
#define CHAR_SET_SIZE 128
/* an alternative version of squeeze(s1,s2) that deletes each character in s1 that matches any character in the string s2. */
void squeeze(char s1[], char s2[]);

main()
{
    char s1[] = "Hello World";
    squeeze(s1, "oe");
    printf(s1); 
}

void squeeze(char s1[], char s2[]) 
{ 
    int i, j; 
    char exist[CHAR_SET_SIZE];
    for(int i = 0; i < CHAR_SET_SIZE; ++i)
        exist[i] = 0;
    for(i = 0; s2[i] != '\0'; ++i)
        exist[s2[i]] = 1;
    for (i = j = 0; s1[i] != '\0'; i++) 
        if (!exist[s1[i]]) 
            s1[j++] = s1[i]; 
    s1[j] = '\0'; 
}