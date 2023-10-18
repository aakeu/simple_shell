#include "shell.h"

/**
 * ModesterBola_print_one - Print a formatted string to standard output.
 * @fmt: The format string to be printed.
 *
 * Description:
 * This function takes a format string (`fmt`) and prints it to the standard
 * output (usually the console). It does not support format specifiers or
 * variable arguments. The function is designed for simple
 * string printing.
 *
 * Return: void (no return value).
 */

void ModesterBola_print_one(const char *fmt)
{
	write(STDOUT_FILENO, fmt, strlen(fmt));
}

/**
 * ModesterBola_print_two - Print a formatted string to standard output
 * with one argument.
 * @fmt: The format string with placeholders.
 * @arg1: The string argument to be inserted into the format string.
 *
 * Description:
 * This function takes a format string (`fmt`) with one placeholder ("%s")
 * and an argument (`arg1`). It replaces the placeholder in the format
 * string with the provided argument and then prints the resulting
 * string to the standard output. This function is designed
 * for simple string formatting and printing.
 *
 * Return: void (no return value).
 */

void ModesterBola_print_two(const char *fmt, const char *arg1)
{
	char print_function[512];  /* Buffer to hold the final string */
	int i = 0, j = 0;  /* Iterators */
	int k = 0;  /* For print_function */

	for (i = 0; fmt[i]; ++i)
	{
		if (fmt[i] == '%' && fmt[i + 1] == 's')
		{
			for (j = 0; arg1[j]; ++j, ++k)
			{
				print_function[k] = arg1[j];
			}
			++i;
		}
		else
		{
			print_function[k] = fmt[i];
			++k;
		}
	}
	print_function[k] = '\0';
	write(STDOUT_FILENO, print_function, strlen(print_function));
}

/**
 * ModesterBola_print_three - Print a formatted string to standard output
 * with two arguments.
 * @fmt: The format string with placeholders.
 * @arg1: The first string argument to be inserted into the format string.
 * @arg2: The second string argument to be inserted into the format string.
 *
 * Description:
 * This function takes a format string (`fmt`) with two placeholders ("%s")
 * and two arguments (`arg1` and `arg2`). It replaces the placeholders
 * in the format string with the provided arguments and then prints
 * the resulting string to the standard output. This function is
 * designed for simple string formatting and printing with
 * multiple arguments.
 *
 * Return: void (no return value).
 */

void ModesterBola_print_three(const char *fmt,
		const char *arg1, const char *arg2)
{
	char buffer[512];
	int index = 0, i = 0;
	int first_arg_used = 0;
	int j;

	while (fmt[i])
	{
		if (fmt[i] == '%' && fmt[i + 1] == 's')
		{
			const char *arg = first_arg_used ? arg2 : arg1;

			first_arg_used = 1;
			for (j = 0; arg[j]; ++j)
			{
				buffer[index++] = arg[j];
			}
			i += 2;
		}
		else
		{
			buffer[index++] = fmt[i++];
		}
	}
	buffer[index] = '\0';
	write(STDOUT_FILENO, buffer, strlen(buffer));
}

