#include "shell.h"

/**
 * display_the_prompt - Display the custom shell prompt.
 *
 * Description:
 * This function is responsible for displaying the custom shell prompt,
 * which is typically shown to the user before they enter a command.
 * The prompt is a simple string, "Modesterbola_shell$", followed by a space.
 *
 * Return: void (no return value).
 */

void display_the_prompt(void)
{
	ModesterBola_print_one("Modesterbola_shell$ ");
}
