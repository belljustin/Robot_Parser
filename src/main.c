#include <stdio.h>
#include <string.h>

#include "../include/syntax.h"

#define BUFFER_SIZE 300

int main(int argv, char *argc[]) {
    FILE *ptr_file = NULL;
    if (argv > 1) {
        ptr_file = fopen(argc[1], "r");
        if (ptr_file == NULL) {
            printf("Not a valid file. Supported formatting: \n\
                    ./a.out file.txt \n\
                    ./a.out ../dir/file/txt");
        }
    }

    char buffer[BUFFER_SIZE];
    int currentLine=1;
    while (fgets(buffer, BUFFER_SIZE, ptr_file) != NULL){
        if (!isValidExpression(buffer)) printf("line: %d\n\n", currentLine);
        currentLine++;
    }
    fclose(ptr_file); 
}
