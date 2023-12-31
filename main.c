#include "headers.h"

char current_directory[PATH_MAX]; //Store the current directory
char code_directory[PATH_MAX];  // Store the code directory
char previous_directory[PATH_MAX]; // Store the previous directory

int main() {
    int flag=1;
    while (1) {
        if(flag){
            initialize_code_directory();
            flag=0;
        }

        char input[MAX_INPUT_LENGTH];
        char *username = get_username();
        char *system_name = get_system_name();
        get_current_directory();
        printf("<%s@%s:%s> $ ", username, system_name,display_directory(current_directory));

        if (fgets(input, MAX_INPUT_LENGTH, stdin) == NULL) {
            break;
        }
        if (strcmp(input, "pwd\n") == 0) {
            handle_pwd_command();
        } else if (strstr(input, "echo") == input) {
            handle_echo_command(input);
        } else if (strstr(input, "cd") == input) {
            handle_cd_command(input);
        } else {
            printf("Unknown command: %s", input);
        }
    }

    return 0;
}