#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdbool.h>
#include <sys/wait.h>
#include <sys/types.h>

void display_the_prompt(void);
void ModesterBola_print_one(const char *fmt);
void ModesterBola_print_two(const char *fmt, const char *arg1);
void ModesterBola_print_three(const char *fmt,
		const char *arg1, const char *arg2);
char **read_the_given_command(char *command, size_t size);
void execute_the_command(char **tokens);
int the_command_exists(const char *command);
char *construct_path(const char *dir, const char *command);
char *my_getline(int fd);
void handle_exit(char **tokens);
void handle_env(char **tokens, char **environ);
char *get_path_command_from_tokens(char **tokens);
void handle_special_commands(char **tokens, char **environ);




#endif /* SHELL_H */
