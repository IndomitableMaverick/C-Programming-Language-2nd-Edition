#include <stdio.h> 
#include <string.h> 
#include <time.h> /* for clock() */

#define MAXLINES 5000 /* max #lines to be sorted */ 
#define BUFSIZE 100000

char *lineptr[MAXLINES]; /* pointers to text lines */ 
char buffer[BUFSIZE]; /* storage for text lines */

// int readlines(char *lineptr[], int nlines); 
int readlines(char *lineptr[], int maxlines, char buffer[], int bufsize);
void writelines(char *lineptr[], int nlines); 
void qsort(char *lineptr[], int left, int right); 

/* sort input lines */ 
int main() 
{ 
    clock_t start = clock();

    int nlines; /* number of input lines read */ 
    if ((nlines = readlines(lineptr, MAXLINES, buffer, BUFSIZE)) >= 0) { 
        qsort(lineptr, 0, nlines - 1); 
        writelines(lineptr, nlines); 

        clock_t end = clock();
        printf("time: %lld\n", (end - start));

        return 0; 
    } 
    else { 
        printf("error: input too big to sort\n"); 

        clock_t end = clock();
        printf("time: %f\n", (end - start));

        return 1; 
    } 
} 

#define MAXLEN 1000 /* max length of any input line */

int getline(char *, int); 
char *alloc(int); 

// /* readlines: read input lines */ 
// int readlines(char *lineptr[], int maxlines) 
// { 
//     int len, nlines; 
//     char *p, line[MAXLEN]; 
//     nlines = 0; 
//     while ((len = getline(line, MAXLEN)) > 0) 
//         if (nlines >= maxlines || (p = alloc(len)) == NULL) 
//             return -1; 
//         else {line[len-1] = '\0'; /* delete newline */ 
//         strcpy(p, line); 
//         lineptr[nlines++] = p; 
//     } 
//     return nlines; 
// } 

/* readlines: read input lines */ 
int readlines(char *lineptr[], int maxlines, char buf[], int bufsize) 
{ 
    int len, nlines; 
    char *p, line[MAXLEN]; 
    p = buf;
    nlines = 0; 
    while ((len = getline(line, MAXLEN)) > 0) 
        if (nlines >= maxlines || p + len > buffer + bufsize) 
            return -1; 
        else {line[len-1] = '\0'; /* delete newline */ 
        strcpy(p, line); 
        lineptr[nlines++] = p; 
        p += len;
    } 
    return nlines; 
} 

/* writelines: write output lines */ 
void writelines(char *lineptr[], int nlines) 
{ 
    while (nlines-- > 0) 
        printf("%s\n", *lineptr++); 
}

/* qsort: sort v[left]...v[right] into increasing order */ 
void qsort(char *v[], int left, int right) 
{ 
    int i, last; 
    void swap(char *v[], int i, int j); 
    if (left >= right) /* do nothing if array contains */ 
        return; /* fewer than two elements */ 
    swap(v, left, (left + right)/2); 
    last = left; 
    for (i = left+1; i <= right; i++) 
        if (strcmp(v[i], v[left]) < 0) 
            swap(v, ++last, i); 
    swap(v, left, last); 
    qsort(v, left, last-1);
    qsort(v, last+1, right); 
}

/* swap: interchange v[i] and v[j] */ 
void swap(char *v[], int i, int j) 
{ 
    char *temp; 
    temp = v[i]; 
    v[i] = v[j]; 
    v[j] = temp; 
}