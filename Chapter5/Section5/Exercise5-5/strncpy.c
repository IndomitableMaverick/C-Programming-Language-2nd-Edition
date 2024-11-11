/* strncpy(s,ct,n): copy at most n characters of string ct to s; return s. 
Pad with '\0''s if ct has fewer than n characters. */
char *my_strncpy(char *s, const char *ct, int n)
{
    int cnt = 0;
    char *start = s;
    while(cnt++ < n && (*s++ = *ct++))
        ;
    while(cnt++ < n)
        *s++ = '\0';
    return start;
}