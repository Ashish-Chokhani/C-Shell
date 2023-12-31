#include "headers.h"
#include "pwd.h"

void handle_pwd_command() {
    char *current_dir = get_current_directory();
    printf("%s\n", display_directory(current_dir));
}