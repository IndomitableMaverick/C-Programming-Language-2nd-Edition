#include <stdio.h>
 /* Rewrite the temperature conversion program of Section 1.2 to use a function for conversion. */
float fahr_to_celsius(float fahr);

main()
{
    float fahr, celsius;
    float lower, upper, step;
    lower = 0; /* lower limit of temperatuire scale */
    upper = 300; /* upper limit */
    step = 20; /* step size */
    fahr = lower;
    printf("%s %s\n", "fahr", "celsius");/* print a heading above the table */
    while (fahr <= upper) 
    {
        celsius = fahr_to_celsius(fahr);
        printf("%3.0f %6.1f\n", fahr, celsius);
        fahr = fahr + step;
    }
    return 0;
}

/* convert fahr to celsius */
float fahr_to_celsius(float fahr)
{
    return 5 * (fahr - 32) / 9;
}