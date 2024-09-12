#include <stdio.h>
#define MAXLINE 1000 /* maximum input line length */
#define LINE_OK 0
#define LINE_TOO_LONG 1

int getline(char s[], int maxline);
void reverse(char s[]);
/* Write a function reverse(s) that reverses the character string s. Use it to write a program that reverses its input a line at a time. */
main()
{
    int len; /* current line length */
    char line[MAXLINE]; /* current input line */
    while ((len = getline(line, MAXLINE)) > 0)
    {
        reverse(line);
        printf("%s", line);
    }
    return 0;
}
/* getline: read a line into s, return length */
int getline(char s[], int lim)
{
    int c, i, state;
    
    state = LINE_OK;
    for (i = 0; state == LINE_OK && (c = getchar()) != EOF && c != '\n'; ++i)
    {
        s[i] = c;
        if(i == lim - 2)
            state = LINE_TOO_LONG;
    }
    if(c == '\n')
    {
        s[i] = '\n';
        ++i;
    }
    s[i] = '\0';

    if(state == LINE_TOO_LONG)
    {
        while((c = getchar()) != EOF && c != '\n')
            ++i;
        if(c == '\n')
            ++i;
    }

    return i;
}
/* reverses the character string s except /n and EOF */
void reverse(char s[])
{
    int index = 0;
    while(s[index] != '\0')
        ++index;
    int lastIndex = index - 2;
    index = 0;
    while(index < lastIndex)
    {
        s[index] ^= s[lastIndex];
        s[lastIndex] ^= s[index];
        s[index] ^= s[lastIndex];
        ++index;
        --lastIndex;
    }
}      