#include <string.h>
#include <stdio.h>

#define BUFFER_SIZE 300
#define TOKEN_SIZE 80 


char buffer[BUFFER_SIZE];
char *bufferPtr = &buffer[0];
char token[TOKEN_SIZE];

char* nextToken() {
    char *startBufferPtr = bufferPtr;
    while(*bufferPtr != ' ' && *bufferPtr != '\r') {
        bufferPtr += sizeof(char);
    }
    strncpy(token, startBufferPtr, bufferPtr-startBufferPtr); 
    token[bufferPtr-startBufferPtr] = '\0';
    if (*bufferPtr != '\r') bufferPtr += sizeof(char);
    return token;
}

int hasNextToken() {
    if (*bufferPtr == '\r') return 0;
    return 1;
}

void myRewind() {
    bufferPtr = &buffer[0];
}

void initBuffer(char *inputLine) {
    strcpy(buffer, inputLine);
    myRewind();
}
