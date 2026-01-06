#include <file.h>
#include <stdio.h>
#include <stdlib.h>
#include <strlib.h>
#include <array.h>

#define BUF_SIZE 1024

file new_file(str path) {
    file res = fopen(path,"r");
    return res;
}

int has_next_line(file f) {
    int res = 1;
    fgetc(f);
    if(feof(f)) {
        res = 0;
        fclose(f);
    }
    else {
        fseek(f, -1, SEEK_CUR);
    }
    return res;
}

str get_next_line(file f) {
    str res = new(char, BUF_SIZE);
    size_t length = BUF_SIZE;
    getline(&res, &length, f);
    return res;
}
