/* strend(s,t): returns 1 if the string t occurs at the end of the string s, and zero otherwise. */
int strend(char *s, char *t)
{
    char *tempPtrS = s; /* Save the head of s for later use */
    char *tempPtrT = t; /* Save the head of t for later use */
    
    while(*s)
        ++s;
    while(*t)
        ++t;
    if(s - tempPtrS < t - tempPtrT)
        return 0;
    while(t >= tempPtrT && *s == *t)
        --s, --t;
    return t == tempPtrT - 1 ? 1 : 0;
}