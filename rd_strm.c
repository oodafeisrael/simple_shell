#include "shell.h"
/**
* rd_strm - function to read string from stdin stream
* Return: pointer to the read strg
*/
char *rd_strm(const char *file_path)
{
	char *strg = NULL;
	size_t nbytes = 0;
	ssize_t n_chr;
	int fd = STDIN_FILENO;

	/*fd = open(file_path, O_RDONLY);*/
	n_chr = read(fd, &strg, nbytes);
	if (fd == -1)
	{
		perror("Error(open failed)");
		exit(EXIT_FAILURE);
	}
	/*n_chr = getline(&strg, &nbytes, fd);*/
	/* check for EOF */
	else if (n_chr == 0)
	{
		free(strg);
		return (NULL);
	}
	/* remove trailling newline character*/
	if (n_chr > 0 && strg[n_chr - 1] == '\n')
		strg[n_chr - 1] = '\0';
		return (strg);
	return (strg);
}
