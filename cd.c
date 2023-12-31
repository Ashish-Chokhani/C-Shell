#include "headers.h"
#include "cd.h"

extern char previous_directory[PATH_MAX];
extern char code_directory[PATH_MAX];

void handle_cd_command(char *input) {
    char input_copy[MAX_INPUT_LENGTH];
    strcpy(input_copy, input);
    char *temp_directory = get_current_directory();
    int flag=0;

    char *token = strtok(input_copy, " \t\n");
    int argumentCount = -1;
    while (token != NULL) {
        argumentCount++;
        token = strtok(NULL, " \t\n");
    }
    if (argumentCount > 1) {
        printf("cd: too many arguments\n");
        return;
    }
    if (argumentCount == 0 || strcmp(input, "cd ~\n")==0) {
        if (chdir(code_directory) != 0) {
            perror("chdir");
        }
        else flag=1;
    }else if (strcmp(input, "cd .\n") == 0) {
        flag=1;
    } 
    else if (strcmp(input, "cd ..\n") == 0) {
        if (chdir("..") != 0) {
            perror("chdir");
        }
        else flag=1;
    } else if (strcmp(input, "cd -\n") == 0) {
        if (previous_directory[0] != '\0') {
            printf("%s\n",display_directory(previous_directory));
            chdir(previous_directory);
            flag=1;
        } else {
            printf("cd: no previous directory\n");
        }
    } else {
        token = strtok(input, " \t\n");
        token = strtok(NULL, " \t\n");
        if (chdir(token) != 0) {
            perror("chdir");
        }
        else flag=1;
    }
    // Save the current directory as the previous directory
    if(flag) strcpy(previous_directory,temp_directory);
}