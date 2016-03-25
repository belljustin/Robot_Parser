char *commands[8] = {"TAKEASTEP", "LEFT", "RIGHT", "PICKUP", "DROP", "DETECTMARKER", "TURNON", "TURNOFF"};

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
       break; 
    } 
    return 0;
}
