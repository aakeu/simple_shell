#include "shell.h"

void execute_the_command(char **tokens)
{
    pid_t the_child_pid;
    char *path_command = NULL;
    char *path, *path_copy, *dir;
    extern char **environ;
    int i;

    if(tokens[0] && strcmp(tokens[0], "exit") == 0)
    {
        free(tokens);

        exit(0);
    }

     if (tokens[0] && strcmp(tokens[0], "env") == 0)
    {
        for (i = 0; environ[i]; i++)
        {
            printf("%s\n", environ[i]);
        }
        free(tokens);
        return;
    }

    if (tokens[0][0] == '/')
    {   
        if (access(tokens[0], F_OK | X_OK) == 0)
        {   
            path_command = tokens[0];
        }
    }
    else
    {
        path_command = malloc(512);
        path = getenv("PATH");
        path_copy = strdup(path);
        dir = strtok(path_copy, ":");

        while (dir != NULL)
        {
            char *constructed_path = construct_path(dir, tokens[0]);
            if (access(constructed_path, F_OK | X_OK) == 0)
            {
                path_command = constructed_path;
                break;
            }
            free(constructed_path);
            dir = strtok(NULL, ":");
        }

        free(path_copy);
    }

    ModesterBola_print_two("Executing command: %s\n", path_command);

    if (!path_command)
    {
        ModesterBola_print_two("%s: command not found\n", tokens[0]);
        free(tokens);
        return;
    }

    the_child_pid = fork();

    if (the_child_pid == -1)
    {
        perror("fork");
        free(tokens);
        exit(EXIT_FAILURE);
    }
    else if (the_child_pid == 0)
    {
        execve(path_command, tokens, environ);
        perror("execve");
        exit(EXIT_FAILURE);
    }
    else
    {
        wait(NULL);
    }

    if (tokens[0][0] != '/')
    {
        free(path_command);
    }
}

