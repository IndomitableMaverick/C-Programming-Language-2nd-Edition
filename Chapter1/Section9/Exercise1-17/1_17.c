#include <stdio.h>
#define MAXLINE 1000 /* maximum input line length */
#define THRESHOLD 80
#define LINE_OK 0
#define LINE_TOO_LONG 1
int getline(char line[], int maxline);
/* print all input lines that are longer than 80 characters. */
main()
{
    int len; /* current line length */
    char line[MAXLINE]; /* current input line */
    while ((len = getline(line, MAXLINE)) > 0)
        if (len >= THRESHOLD) 
            printf("%s", line);
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