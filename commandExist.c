#include "shell.h"

int the_command_exists(const char *command) {
    char *path = getenv("PATH");
    char *path_copy = strdup(path);
    char *dir = strtok(path_copy, ":");

    while (dir != NULL) {
        char full_path[512];
        
        /* Manually combining strings */
        int i, j;
        for (i = 0; dir[i] != '\0'; i++) {
            full_path[i] = dir[i];
        }
        full_path[i] = '/';
        i++;
        for (j = 0; command[j] != '\0'; j++, i++) {
            full_path[i] = command[j];
        }
        full_path[i] = '\0';

	ModesterBola_print_two("Checking path: %s\n", full_path);

        if (access(full_path, F_OK | X_OK) == 0) {
            free(path_copy);
            return 1;
        }

        dir = strtok(NULL, ":");
    }

    free(path_copy);
    return 0;
}
