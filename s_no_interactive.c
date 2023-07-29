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
	size_t nbytes = 0;

	while (status == 1)
	{
		strg = rd_strm();
		if (strg == NULL)
			break;
		tokens = strg_split(strg);
		if (tokens == NULL)
		{
			perror("Error(strig_split)");
			free(strg);
			exit(EXIT_FAILURE);
		}
		status = exec_toks(tokens, nbytes);
		free(tokens);
		free(strg);
	}
}
