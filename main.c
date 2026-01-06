#include <stdio.h>
#include <stdlib.h>
#include <array.h>
#include <strlib.h>
#include <file.h>
#include <gaussjordan.h>

int main(int argc, arr(str) argv)
{

    file f = new_file(argv[1]);

    if(has_next_line(f)) {
        str line = get_next_line(f);
        int n = atoi(line);
        
        arr(arr(double)) matrix = new(arr(double), n);
        
        for(int i = 0; i < n; i++) {
            if(has_next_line(f)) {
                line = get_next_line(f);
                if (line[len(line)-1] == '\n') {
                    line[len(line)-1] = '\0';
                }
                matrix[i] = build_double(line, n + 1);
            }
        }
        
        arr(double) result = solve(n, matrix);
        
        if (result[0] == 0.0) {
            printf("no unique solution\n");
        } else {
            printda(result + 1, n);
        }
        
        // Cleanup
        for(int i = 0; i < n; i++) {
            free(matrix[i]);
        }
        free(matrix);
        // free(result);
    }

    return 0;
}
