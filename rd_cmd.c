#include "shell.h"
/**
* rd_cmd - functionto read user input command from terminal or prompt
* Return: pointer to a string from the command argument
*/
char rd_cmd(void)
{
	char *strg = NULL;
	size_t nbytes = 0;
	ssize_t n_chr;

	n_chr = getline(&strg, &nbytes, status);
	if (n_chr == -1)
	{
		perror("Error: getline failed");
		free(strg);
		exit(EXIT_FAILURE);
	}
	if (n_chr == 1 && strg[0] == '\n')
	{
		continue;
	}
	strg[n_chr - 1] = '\0';
	return (strg);
}
