#include "prompt.h"
#include "headers.h"

extern char current_directory[PATH_MAX]; //Store the current directory
extern char code_directory[PATH_MAX];  // Store the code directory
extern char previous_directory[PATH_MAX]; // Store the previous directory

char* get_username() {
    return getlogin();
}

char* get_system_name() {
    static char hostname[256];
    if (gethostname(hostname, sizeof(hostname)) != 0) {
        perror("gethostname");
        exit(EXIT_FAILURE);
    }
    return hostname;
}

char* get_current_directory() {
    if (getcwd(current_directory, sizeof(current_directory)) == NULL) {
        perror("getcwd");
        exit(EXIT_FAILURE);
    }
    return current_directory;
}

void initialize_code_directory(){
    if (getcwd(code_directory, sizeof(code_directory)) == NULL) {
        perror("getcwd");
        exit(EXIT_FAILURE);
    }
}

char* display_directory(char* directory){
    if (strcmp(directory,code_directory) == 0) {
        return "~";
    } else if(strcmp(directory,code_directory) < 0) {
        return directory;
    }
    else {
        size_t code_length = strlen(code_directory);
        char result[PATH_MAX + 1];
        sprintf(result, "~%s", directory + code_length);
        return strdup(result);   
    }
}

