#include "shell.h"

/**
 * read_the_given_command - Read and tokenize a command from
 * standard input.
 * @command: A buffer to store the read command.
 * @size: The size of the buffer.
 *
 * Description:
 * This function reads a command from standard input,
 * tokenizes it into separate words, and returns an array
 * of tokens. It takes a buffer `command` to store
 * the read command and its maximum `size`.
 * It also dynamically allocates memory for the token array.
 * If an error occurs during input reading, the function
 * handles it and may exit the program with an appropriate message.
 *
 * Return: An array of tokens representing the command,
 * or NULL if an error occurs.
 */

char **read_the_given_command(char *command, size_t size)
{
	char **tokens;
	char *token;
	int i = 0;

	tokens = (char **) malloc(50 * sizeof(char *));

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
	while (token)
	{
		tokens[i++] = token;
		token = strtok(NULL, " ");
	}
	tokens[i] = NULL;
	return (tokens);
}
