#include "shell.h"

void ModesterBola_print_one(const char *fmt) {
    write(STDOUT_FILENO, fmt, strlen(fmt));
}

void ModesterBola_print_two(const char *fmt, const char *arg1) {
    char print_function[512];  /* Buffer to hold the final string */
    int i = 0, j = 0;  /* Iterators */
    int k = 0;  /* For print_function */

    for (i = 0; fmt[i]; ++i) {
        if (fmt[i] == '%' && fmt[i + 1] == 's') {
            for (j = 0; arg1[j]; ++j, ++k) {
                print_function[k] = arg1[j];
            }
            ++i;
        } else {
            print_function[k] = fmt[i];
            ++k;
        }
    }
    print_function[k] = '\0';
    write(STDOUT_FILENO, print_function, strlen(print_function));
}

void ModesterBola_print_three(const char *fmt, const char *arg1, const char *arg2) {
    char buffer[512];
    int index = 0, i = 0;
    int first_arg_used = 0;
    int j;

    while (fmt[i]) {
        if (fmt[i] == '%' && fmt[i + 1] == 's') {
            const char *arg = first_arg_used ? arg2 : arg1;
            first_arg_used = 1;
            for (j = 0; arg[j]; ++j) {
                buffer[index++] = arg[j];
            }
            i += 2;
        } else {
            buffer[index++] = fmt[i++];
        }
    }
    buffer[index] = '\0';
    write(STDOUT_FILENO, buffer, strlen(buffer));
}

