#include <string.h>
#include "../include/parse.h"

char *commands[8] = {"TAKEASTEP", "LEFT", "RIGHT", "PICKUP", "DROP",
                    "DETECTMARKER", "TURNON", "TURNOFF"};

void upper(char *string) {
    int size = sizeof(string); 
    for (int i=0; i<=size; i++) {
        if (string[i] > 96 && string[i] < 123) {
            string[i] -= 32;
        }
    } 
}

int isValidCommand(char *token) {
    upper(token);
    for (int i=0; i<8; i++) {
        if (strcmp(token, commands[i]) == 0) return 1;
    } 
    return 0;
}

int isValidExpression(char *expression) {
    initBuffer(expression); 
    return 0;
}
