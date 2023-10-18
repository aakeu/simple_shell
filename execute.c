#include "shell.h"
<<<<<<< HEAD
void execute_the_command(char **tokens)
{
pid_t the_child_pid;
char *path_command = NULL;
char *path, *path_copy, *dir;
extern char **environ;
int i;
if (tokens[0] && strcmp(tokens[0], "exit") == 0)
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
{
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
=======

/**
 * handle_exit - Handle the "exit" command.
 * @tokens: The array of command tokens.
 *
 * Description:
 * This function is responsible for handling the "exit"
 * command in the shell. It frees the memory allocated
 * for command tokens and exits the shell with
 * a status code of 0, indicating successful termination.
 *
 * Return: void (no return value).
 */

void handle_exit(char **tokens)
{
	free(tokens);
	exit(0);
}

/**
 * handle_env - Handle the "env" command.
 * @tokens: The array of command tokens.
 * @environ: The array of environment variables.
 *
 * Description:
 * This function is responsible for handling the "env" command in
 * the shell. It prints the environment variables to the
 * standard output and frees the memory allocated for command
 * tokens. It takes both the command tokens and
 * the environment variables as arguments.
 *
 * Return: void (no return value).
 */

void handle_env(char **tokens, char **environ)
{
	int i;

	for (i = 0; environ[i]; i++)
	{
		ModesterBola_print_two("%s\n", environ[i]);
	}
	free(tokens);
}

/**
 * get_path_command_from_tokens - Get the full path to
 * a command from tokens.
 * @tokens: The array of command tokens.
 *
 * Description:
 * This function takes an array of command tokens
 * and attempts to find the full path to the command based
 * on the PATH environment variable. It checks
 * if the command exists in the directories listed in PATH
 * and returns the full path if found. If not found, it returns NULL.
 *
 * Return: A pointer to the full path if found, or NULL if not found.
 */

char *get_path_command_from_tokens(char **tokens)
{
	char *path, *path_copy, *dir, *constructed_path;

	if (tokens[0][0] == '/')
	{
		return ((access(tokens[0], F_OK | X_OK) == 0) ? tokens[0] : NULL);
	}
	else
	{
		path = getenv("PATH");
		path_copy = strdup(path);
		dir = strtok(path_copy, ":");

		while (dir != NULL)
		{
			constructed_path = construct_path(dir, tokens[0]);
			if (access(constructed_path, F_OK | X_OK) == 0)
			{
				free(path_copy);
				return (constructed_path);
			}
			free(constructed_path);
			dir = strtok(NULL, ":");
		}
		free(path_copy);
	}
	return (NULL);
}

/**
 * execute_the_command - Execute a command with its arguments.
 * @tokens: The array of command tokens.
 *
 * Description:
 * This function is responsible for executing a command with its arguments.
 * It first checks if the command is "exit" or "env" and handles them
 * accordingly. If it's not one of these commands, it attempts to find the
 * full path to the command and executes it as a child process using `execve`.
 * It also handles fork and execve errors and waits for the child process
 * to complete.
 *
 * Return: void (no return value).
 */

void execute_the_command(char **tokens)
{
	extern char **environ;
	pid_t the_child_pid;
	char *path_command = NULL;

	if (tokens[0] && strcmp(tokens[0], "exit") == 0)
		handle_exit(tokens);

	if (tokens[0] && strcmp(tokens[0], "env") == 0)
	{
		handle_env(tokens, environ);
		return;
	}
	path_command = get_path_command_from_tokens(tokens);
	ModesterBola_print_two("%s\n", path_command);

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
	} else if (the_child_pid == 0)
	{
		execve(path_command, tokens, environ);
		perror("execve");
		exit(EXIT_FAILURE);
	} else
	{
		wait(NULL);
	}

	if (tokens[0][0] != '/')
		free(path_command);
>>>>>>> fadf9e73a10d0a2703538880a586c4bf126921fd
}
