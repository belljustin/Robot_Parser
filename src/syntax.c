#include <string.h>
#include <stdio.h>

#include "../include/parse.h"

char *commands[8] = {"TAKEASTEP", "LEFT", "RIGHT", "PICKUP", "DROP",
                    "DETECTMARKER", "TURNON", "TURNOFF"};

void upper(char *string) {
    int size = strlen(string); 
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

int isCommaSeperatedCommands() {
    while (hasNextToken()) {
        char token[80];
        strcpy(token, nextToken());
        upper(token);

        if (token[strlen(token)-1] == ',') {
            char command_token[80];
            strncpy(command_token, token, strlen(token)-1);
            command_token[strlen(token)-1] = '\0';
            if (!isValidCommand(command_token)) return 0;
        } else { 
            if (!isValidCommand(token)) return 0;
            char *end_token = nextToken();
            upper(end_token);
            if (strcmp(end_token, "END") != 0) return 0; 
            break;
        }
    }
    return 1;
}

int isInteger(char *token) {
    for (int i=0; i<strlen(token); i++) {
        if (token[i] < 48 || token[i] > 57) return 0;
    }
    return 1;
}

int isValidExpression(char *expression) {
    initBuffer(expression); 
     
    char *token;
    if (hasNextToken()) {
        token = nextToken();
    } else return 0;
    upper(token);
    
    if (isValidCommand(token)) return 1; 
    
    if (strcmp(token, "REPEAT")) {
        
    }
    
    return 0;
}
