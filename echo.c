#include "headers.h"
#include "echo.h"

void handle_echo_command(char *input) {
    char input_copy[strlen(input)];
    strcpy(input_copy, input);
    char *result = strstr(input_copy, " ") + 1;
    int isString=0;
    int len = strlen(result);
    if (len >= 3 && result[0] == '"' && result[len - 2] == '"') {
        isString=1;
        for (int i = 0; i < len - 3; i++) {
            result[i] = result[i + 1];
        }
        result[len - 1] = '\0';
        result[len - 2] = '\0';
        result[len - 3] = '\0';
    }
    char *token = strtok(input, " \t");
    if (token != NULL && strcmp(token, "echo") == 0) {
        token = strtok(NULL, " \t");
        int first_arg = 1;
        while (token != NULL) {
            if (!first_arg) {
                printf(" ");
            }
            if (isString) {
                printf("%s\n",result);
                break;
            }
            else {
                printf("%s", token);
            }
            token = strtok(NULL, " \t");
            first_arg = 0;
        }
    } else {
        printf("Unknown command: %s", input);
    }
}