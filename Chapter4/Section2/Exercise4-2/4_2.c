# include <stdio.h>
# include <ctype.h>

int main()
{
    double atof(char []);
    printf("%lf\n", atof("123.45"));
    printf("%lf\n", atof("123.45e6"));
    printf("%lf\n", atof("123.45e-6"));
}

/* atof: convert string s to double */ 
double atof(char s[]) 
{ 
    double val, power; 
    int i, sign; 
    for (i = 0; isspace(s[i]); i++) /* skip white space */ 
        ; 
    sign = (s[i] == '-') ? -1 : 1; 
    if (s[i] == '+' || s[i] == '-') 
        i++; 
    for (val = 0.0; isdigit(s[i]); i++) 
        val = 10.0 * val + (s[i] - '0'); 
    if (s[i] == '.') 
        i++; 
    for (power = 1.0; isdigit(s[i]); i++) 
    { 
        val = 10.0 * val + (s[i] - '0'); 
        power *= 10; 
    }
    if(s[i] == 'e' || s[i] == 'E')
    {
        int expVal, expSign;
        expSign = (s[++i] == '-') ? -1 : 1;
        if (s[i] == '+' || s[i] == '-') 
            i++; 
        for (expVal = 0; isdigit(s[i]); i++) 
            expVal = 10 * expVal + (s[i] - '0');
        if(expSign == 1)
            while(expVal-- >= 0)
                power /= 10;
        else if(expSign == -1)
            while(expVal-- >= 0)
                power *= 10;
    }
    return sign * val / power; 
}