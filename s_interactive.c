#include "shell.h"
/**
* usr_interactive_sh - function that runs shell commands, Displays a prompt
* and wait for the user to type a command. A command line always ends
* with a new line. The prompt is displayed again each time a
* command has been executed.The input is the path to an executable
* Return: void
*/
void usr_interactive_sh(void)
{
	char *strg;
	char **tokens;
	int status = 1;
	size_t nbytes = 0;

	while ((status = 1))
	{
		strg = rd_cmd();
		tokens = strg_split(strg);
		if (tokens == NULL)
		{
			perror("error(strig_split)");
			free(strg);
			exit(EXIT_FAILURE);
		}
		status = exec_toks(tokens, nbytes);
		free(tokens);
	}
	free(strg);
}
