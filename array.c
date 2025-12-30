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
