/* strncmp(cs,ct,n): compare at most n characters of string cs to string ct; 
return <0 if cs<ct, 0 if cs==ct, or >0 if cs>ct. */
int my_strncmp(const char *cs, const char *ct, int n)
{
    for (int cnt = 1; cnt < n && *cs == *ct; cs++, ct++, cnt++) 
        if (*cs == '\0') 
            return 0; 
    return *cs - *ct;
}