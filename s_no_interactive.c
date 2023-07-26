#include "shell.h"
/**
* usr_no_interactive_sh - function to handle commands from stdin or other
* processes
* Return: void
*/
void usr_no_interactive_sh(void)
{
	char *strg;
	char **tokens;
	int status = 1;

	while ((status = 1))
	{
		strg = rd_strm();
		tokens = strg_split(strg);
		if (tokens == NULL)
		{
			perror("Error(strig_split)");
			free(strg);
			exit(EXIT_FAILURE);
		}
		status = exec_toks(tokens);
		free(tokens);
	}
	free(strg);
}
