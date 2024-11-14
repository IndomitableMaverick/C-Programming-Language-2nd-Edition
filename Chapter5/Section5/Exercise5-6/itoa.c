/* itoa: convert n to characters in s */ 
void itoa(int n, char *s) 
{ 
    void reverse(char *s);

    int sign; 
    char *start = s;
    if ((sign = n) < 0) /* record sign */ 
        n = -n; /* make n positive */  
    do { /* generate digits in reverse order */ 
        *s++ = n % 10 * (n % 10 < 0 ? -1 : 1) + '0'; /* get next digit */ 
    } while ((n /= 10) != 0); /* delete it, using != 0 to handle with -(2^wordsize - 1).*/ 
    if (sign < 0) 
        *s++ = '-'; 
    *s = '\0';
    reverse(start); 
}