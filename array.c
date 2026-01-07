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
    arr(double) result = new(double, n);

    int start = 0;
    int end;
    
    for (int i = 0; i < n; i++) {
        end = search(s, start, ' ');
        str sliced_string = slice(s, start, end);
        result[i] = atof(sliced_string);
        free(sliced_string);
        start = end + 1;
    }
    
    return result;
}
