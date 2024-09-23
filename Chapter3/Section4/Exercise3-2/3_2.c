#include <stdio.h>

void escape(char s[], char t[]);
void unescape(char s[], char t[]);

main()
{
    char s[1024];
    char t[] = "Hello\tWorld\n";
    printf("%s\n", t);
    escape(s, t);
    printf("%s\n", s);
    unescape(s, s);
    printf("%s\n", s);
}

/* converts characters like newline and tab into visible escape sequences like \n and \t as it copies the string t to s. */
void escape(char s[], char t[])
{
    int indexS, indexT;
    indexS = indexT = 0;
    while(t[indexT] != '\0')
    {
        s[indexS] = '\\';
        switch (t[indexT])
        {
            case '\n':
                s[++indexS] = 'n';
                break;
            case '\t':
                s[++indexS] = 't';
                break;
            default:
                s[indexS] = t[indexT];
                break;
        }
        ++indexS;
        ++indexT;
    }
    s[indexS] = '\0';
}

/* converts visible escape sequences like \n and \t into characters like newline and tab as it copies the string t to s. */
void unescape(char s[], char t[])
{
    int indexS, indexT;
    indexS = indexT = 0;
    while(t[indexT] != '\0')
    {
        if(t[indexT] == '\\')
            switch (t[++indexT])
            {
                case 't':
                    s[indexS] = '\t';
                    break;
                case 'n':
                    s[indexS] = '\n';
                    break;
                default:
                    break;
            }
        else
            s[indexS] = t[indexT];
        ++indexS;
        ++indexT;
    }
    s[indexS] = '\0';
}