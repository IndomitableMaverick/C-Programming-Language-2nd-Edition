#include <stdio.h>
 /* print Celsius-Fahrenheit table
 for Celsius = 0, 20, ..., 300; floating−point version */
main()
{
    float fahr, celsius;
    float lower, upper, step;
    lower = 0; /* lower limit of temperatuire scale */
    upper = 300; /* upper limit */
    step = 20; /* step size */
    celsius = lower;
    printf("%s  %s\n", "celsius", "fahr");/* print a heading above the table */
    while (celsius <= upper) 
    {
        fahr = 9.0 / 5.0 * celsius + 32.0;
        printf("%7.0f %6.1f\n", celsius, fahr);
        celsius = celsius + step;
    }
}