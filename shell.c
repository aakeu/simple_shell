#include "shell.h"

int main(void)
{
	char command[152];
	char**tokens;

	while(true)
	{
		display_the_prompt();
		tokens=
			read_the_given_command(command,sizeof(command));

		execute_the_command(tokens);
	}
	return 0;
}

char *construct_path(const char *dir, const char *command){
	int i, j;
	char *result = malloc(512);

	if (!result){
		perror("malloc");
		exit(EXIT_FAILURE);
	}

	for (i = 0; dir[i]!= '\0';i++){
		result[i] = dir[i];
	}
	result[i] = '/';
	i++;
	for(j = 0; command[j]!= '\0';j++,i++){
	}
	result[i] = '/0';

	return result;
}
