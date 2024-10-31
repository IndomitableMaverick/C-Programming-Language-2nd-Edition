int i;

/* itoa: convert n to characters in s (recursive version) */ 
void itoa(int n, char s[]) 
{ 
    int sign; 
    if ((sign = n) < 0){ /* record sign */
        s[i++] = '-';
        n = -n; /* make n positive */ 
    }  
    if (n / 10)/* generate digits */ 
        itoa(n / 10 * (n / 10 < 0 ? -1 : 1), s);
    s[i++] = n % 10 * (n % 10 < 0 ? -1 : 1) + '0';
}