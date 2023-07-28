#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>


void exec_cmd(char *command);

int main(void)
{
	char *strg = NULL;
	char prompt[] = "s_shell$";
	size_t nbytes = 0;
	ssize_t num_char;
	while (1)
	{
		write(STDOUT_FILENO, prompt, strlen(prompt));

		num_char = getline(&strg, &nbytes, stdin);
		if (num_char == -1)
		{
			perror("Error (getline)");
			free(strg);
			exit(EXIT_FAILURE);
		}

		if (num_char == 1 && strg[0] == '\n')
		{
			continue;
		}
		strg[num_char - 1] = '\0';

		exec_cmd(strg);
	}

	free(strg);

	return (0);
}
