/* atoi: convert s to integer */ 
int atoi(const char *s) 
{ 
    int i, n; 
    n = 0; 
    while(*s >= '0' && *s <= '9') 
        n = 10 * n + (*s++ - '0'); 
    return n; 
}