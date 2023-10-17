#include "shell.h"

#define BUFFER_SIZE 1024

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
return line;
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
return line;
}
else
{
size_t segment_len = end - ptr;
line = realloc(line, len + segment_len + 1);
memcpy(line + len, ptr, segment_len);
len += segment_len;
ptr = end;
