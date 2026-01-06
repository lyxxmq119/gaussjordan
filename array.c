#include <stdio.h>
#include <array.h>
#include <strlib.h>

arr(int) build(arr(str) array, int n)
{
    // create the container for the elements of the array
    arr(int) a = new(int, n);
    
    for(int i = 0; i < n; i++)
    {
        a[i] = atoi(array[i+1]);
    };

    return a;
}


void printa(arr(int) a, int n)
{
    for(int i=0; i<n; i++)
    {
        printf("%d ", a[i]);
    };
    
    printf("\n");
}


void printda(arr(double) a, int n)
{
    for(int i=0; i<n; i++)
    {
        printf("%g", a[i]);
        if (i < n - 1) {
            printf(" ");
        }
    };
    
    printf("\n");
}


arr(double) build_double(str s, int n) {
    int len_s = len(s);
    arr(double) res = new(double, n);
    
    int i = 0;
    int k = 0;
    while (i < len_s && k < n) {
        while(i < len_s && s[i] == ' ') i++;
        if (i < len_s) {
            int start = i;
            int end = search(s, start, ' ');
            res[k++] = str2dou(s, start, end);
            i = end;
        }
    }
    return res;
}
