#include "shell.h"
int the_command_exists(const char *command)
{
char *path = getenv("PATH");
char *path_copy = strdup(path);
char *dir = strtok(path_copy, ":");
while (dir != NULL)
{
char full_path[512];/* Manually combining strings */
int i, j;
for (i = 0; dir[i] != '\0'; i++)
{
full_path[i] = dir[i];
}
full_path[i] = '/';
i++;
for (j = 0; command[j] != '\0'; j++, i++)
{
full_path[i] = command[j];
}
full_path[i] = '\0';

<<<<<<< HEAD
ModesterBola_print_two("Checking path: %s\n", full_path);
if (access(full_path, F_OK | X_OK) == 0)
{
free(path_copy);
return 1;
}
dir = strtok(NULL, ":");
}
free(path_copy);
return 0;
=======
/**
 * the_command_exists - Check if a command exists in the system's
 * PATH directories.
 * @command: The command to check for existence.
 *
 * Description:
 * This function takes a command as input and checks if it exists
 * in any of the directories listed in the system's PATH
 * environment variable. It iterates through the PATH directories,
 * constructs the full path to the command, and checks if the
 * command is executable. If the command is found and is
 * executable, the function returns 1; otherwise, it returns 0.
 *
 * Return: 1 if the command exists and is executable; 0 otherwise.
 */

int the_command_exists(const char *command)
{
	char *path = getenv("PATH");
	char *path_copy = strdup(path);
	char *dir = strtok(path_copy, ":");

	while (dir != NULL)
	{
		char full_path[512];

		/* Manually combining strings */
		int i, j;

		for (i = 0; dir[i] != '\0'; i++)
		{
			full_path[i] = dir[i];
		}
		full_path[i] = '/';
		i++;
		for (j = 0; command[j] != '\0'; j++, i++)
		{
			full_path[i] = command[j];
		}
		full_path[i] = '\0';

		ModesterBola_print_two("Checking path: %s\n", full_path);

		if (access(full_path, F_OK | X_OK) == 0)
		{

			free(path_copy);
			return (1);
		}

		dir = strtok(NULL, ":");
	}

	free(path_copy);
	return (0);
>>>>>>> fadf9e73a10d0a2703538880a586c4bf126921fd
}
