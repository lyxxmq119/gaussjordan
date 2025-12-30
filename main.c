#include <stdio.h>
#include <stdlib.h>
#include <array.h>
#include <strlib.h>
#include <file.h>

int main(int argc, arr(str) argv)
{

    file f = new_file(argv[1]);

    str line; 
    while(has_next_line(f)) {
        line = get_next_line(f); 
        printf("%s", line);
    }

    return 0;
}
