#include "shell.h"

#define BUFFER_SIZE 1024

/**
 * my_getline - Read a line from a file descriptor.
 * @fd: The file descriptor from which to read the line.
 *
 * Description:
 * This function reads a line from the specified file descriptor `fd`.
 * It reads data from the file descriptor in chunks, dynamically
 * allocates memory to hold the line, and returns the read line as a string.
 * It continues reading and appending data until it encounters a newline
 * character ('\n') or reaches the end of the file.
 *
 * Return: A dynamically allocated string containing the read line, or NULL if
 * an error occurs or the end of the file is reached.
 */

char *my_getline(int fd)
{
	static char buffer[BUFFER_SIZE];
	static char *ptr = buffer;
	static char *end = buffer;
	char *line = NULL;
	size_t len = 0;

	while (1)
	{
		char *newline_ptr;

		if (ptr == end)
		{
			ssize_t bytes_read = read(fd, buffer, BUFFER_SIZE);

			if (bytes_read <= 0)
			{
				return (line);
			}
			ptr = buffer;
			end = buffer + bytes_read;
		}

		newline_ptr = (char *)memchr(ptr, '\n', end - ptr);
		if (newline_ptr)
		{
			size_t segment_len = newline_ptr - ptr;

			line = realloc(line, len + segment_len + 1);
			memcpy(line + len, ptr, segment_len);
			len += segment_len;
			line[len] = '\0';
			ptr = newline_ptr + 1;
			return (line);
		}
		else
		{
			size_t segment_len = end - ptr;

			line = realloc(line, len + segment_len + 1);
			memcpy(line + len, ptr, segment_len);
			len += segment_len;
			ptr = end;
		}
	}
}
