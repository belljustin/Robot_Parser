#include <stdio.h>

#include "../include/syntax.h"

#define BUFFER_SIZE 300

int main(int argv, char *argc[]) {
    FILE *ptr_file;
    if (argv > 1) {
        ptr_file = fopen(argc[1], "r");
        if (ptr_file == NULL) {
            printf("Not a valid file. Supported formatting: \n\
                    ./a.out file.txt \n\
                    ./a.out ../dir/file/txt");
            return 0;
        }
    }

    char buffer[BUFFER_SIZE];
    fgets(buffer, BUFFER_SIZE, ptr_file);
    isValidExpression(buffer);

    fclose(ptr_file);
}
