#include <string.h>

#define BUFFER_SIZE 300

char buffer[BUFFER_SIZE];
char original_buffer[BUFFER_SIZE];

void initBuffer(char *inputLine) {
    strcpy(buffer, inputLine);
    strcpy(original_buffer, inputLine);     
}
