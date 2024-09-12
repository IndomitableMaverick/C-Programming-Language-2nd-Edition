#include <stdio.h>
#define MAXLINE 1000 /* maximum input line length */
#define LINE_OK 0
#define LINE_TOO_LONG 1
#define LINE_EMPTY 2  
int getline(char line[], int maxline);
int clean(char line[], int lastIndex);
/* remove trailing blanks and tabs from each line of input, and to delete entirely blank lines. */
main()
{
    int len; /* current line length */
    char line[MAXLINE]; /* current input line */
    while ((len = getline(line, MAXLINE)) > 0)
        if(clean(line, len - 1) != LINE_EMPTY)
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

int clean(char line[], int lastIndex)
{
    char temp = line[lastIndex--];/* temporary store \n or EOF */
    while(lastIndex >= 0 && (line[lastIndex] == ' ' || line[lastIndex] == '\t'))
        --lastIndex;
    if(lastIndex == -1)
        return LINE_EMPTY;
    line[++lastIndex] = temp;
    line[++lastIndex] = '\0';
    return LINE_OK;
}      