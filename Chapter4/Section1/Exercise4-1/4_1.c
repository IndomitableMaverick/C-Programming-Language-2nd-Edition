#include <stdio.h>

int strindex(char s[], char t[]);

int main()
{
    printf("%d\n", strindex("Re-mould it nearer to the Heart's Desire!", "ea"));
    return 0;
}

/* strindex(s,t): returns the position of the rightmost occurrence of t in s, or -1 if there is none. */
int strindex(char s[], char t[]) 
{ 
    int i, j, k, res;
    res = -1; 
    for (i = 0; s[i] != '\0'; i++) 
    { 
        for (j = i, k = 0; t[k] != '\0' && s[j] == t[k]; j++, k++) 
            ; 
        if (k > 0 && t[k] == '\0') 
            res = i; 
    } 
    return res; 
}