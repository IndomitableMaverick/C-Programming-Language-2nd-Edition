#include <stdio.h>

int binsearch(int x, int v[], int n);

main()
{
    int v[] = {1, 2, 5, 7, 9};
    printf("%d\n", binsearch(2, v, 5));
    printf("%d\n", binsearch(5, v, 5));
    printf("%d\n", binsearch(10, v, 5));
    return 0;
}

/* binsearch: find x in v[0] <= v[1] <= ... <= v[n-1] (only one test inside the loop)*/ 
int binsearch(int x, int v[], int n) 
{ 
    int low, high, mid; 
    low = 0; 
    high = n - 1; 
    while (low <= high) 
    { 
        mid = (low + high) / 2; 
        if (x <= v[mid]) 
            high = mid - 1; 
        else
            low = mid + 1; 
    } 
    if(v[mid] == x || (++mid < n && v[mid] == x))
        return mid;
    return -1; /* no match */ 
}