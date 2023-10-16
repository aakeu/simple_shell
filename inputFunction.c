#include "shell.h"

char** read_the_given_command(char *command, size_t size)
{
    char **tokens;
    char *token;
    int i = 0;

    tokens = (char**) malloc(50 * sizeof(char*));

    if (fgets(command, size, stdin) == NULL)
    {
        if (feof(stdin))
        {
            ModesterBola_print_one("\n");
            exit(EXIT_SUCCESS);
        }
        else
        {
            ModesterBola_print_one("Error while reading input.\n");
            exit(EXIT_FAILURE);
        }
    }
    command[strcspn(command, "\n")] = '\0';

    token = strtok(command, " ");
    while (token) {
        tokens[i++] = token;
        token = strtok(NULL, " ");
    }
    tokens[i] = NULL;
    return tokens;
}
