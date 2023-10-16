#include "shell.h"
#define TESTING_GETLINE 0


/**
 * main - Entry point for the custom shell.
 *
 * Description:
 * This function serves as the entry point for a custom shell program.
 * It continuously displays a shell prompt, reads user input, and
 * executes the entered command.
 *
 * Return: Always returns 0 to indicate successful execution.
 */

int main(void)
{
	char command[152];
	char **tokens;

	while (true)
	{
		display_the_prompt();
		tokens = read_the_given_command(command, sizeof(command));
		execute_the_command(tokens);

	}
	return (0);
}

/**
 * construct_path - Concatenate directory and command to form a full path.
 * @dir: The directory path.
 * @command: The command name.
 *
 * Description:
 * This function takes a directory path and a command name and concatenates
 * them to form a full path. It allocates memory for the result and returns
 * it.
 *
 * Return: A pointer to the concatenated path, or NULL on failure.
 */

char *construct_path(const char *dir, const char *command)
{
	int i, j;
	char *result = malloc(512);

	if (!result)
	{
		perror("malloc");
		exit(EXIT_FAILURE);
	}

	for (i = 0; dir[i] != '\0'; i++)
	{
		result[i] = dir[i];
	}
	result[i] = '/';
	i++;
	for (j = 0; command[j] != '\0'; j++, i++)
	{
		result[i] = command[j];
	}
	result[i] = '\0';

	return (result);
}

#if TESTING_GETLINE

/**
 * main - Entry point for testing the custom getline function.
 *
 * Description:
 * This function serves as the entry point for testing the custom
 * getline function, `my_getline`. It reads lines from standard input
 * using `my_getline`, prints them, and frees the allocated memory
 * for each line.
 *
 * Return: Always returns 0 to indicate successful execution.
 */

int main(void)
{
	char *line;

	while ((line = my_getline(STDIN_FILENO)))
	{
		ModesterBola_print("Read: %s", line);
		free(line);
	}
	return (0);
}
#endif
