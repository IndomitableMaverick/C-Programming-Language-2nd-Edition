/* strncat(s,ct,n): concatenate at most n characters of string ct to string s, 
terminate s with '\0'; return s */
char *my_strncat(char *s, const char *ct, int n)
{
    int cnt = 0;
    char *start = s;
    while(*s)
        ++s;
    while(cnt++ < n && (*s++ = *ct++))
        ;
    return start;
}