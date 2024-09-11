#include <stdio.h>
#define MAXLINE 1000 /* maximum input line length */
#define LINE_OK 0
#define LINE_TOO_LONG 1
int getline(char line[], int maxline);
void copy(char to[], char from[]);
/* correctly print the length of arbitrary long input lines, and as much as possible of the text. */
main()
{
    int len; /* current line length */
    int max; /* maximum length seen so far */
    char line[MAXLINE]; /* current input line */
    char longest[MAXLINE]; /* longest line saved here */
    max = 0;
    while ((len = getline(line, MAXLINE)) > 0)
        if (len > max) 
        {
            max = len;
            copy(longest, line);
        }
    if (max > 0) /* there was a line */
        printf("maxLength: %d\n%s", max, longest);
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
/* copy: copy 'from' into 'to'; assume to is big enough */
void copy(char to[], char from[])
{
    int i;
    i = 0;
    while ((to[i] = from[i]) != '\0') 
        ++i;
}