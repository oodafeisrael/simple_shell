#include "shell.h"
/**
* rd_strm - function to read string from stdin stream
* Return: pointer to the read strg
*/
char *rd_strm(void)
{
	char *strg;
	size_t nbytes = 0;
	ssize_t n_chr;
	char **tokens;
	int fd;

	fd = open(file_path, O_RDONLY);
	if (fd == -1)
	{
		perror("Error(open failed)");
		exit(EXIT_FAILURE);
	}
	while ((n_chr = getline(&strg, &nbytes, fd)) != -1)
	{
		if (n_chr == 1 && strg[0] == '\n')
		{
			continue;
		}
		strg[n_chr - 1] = '\0';
		return (strg);
	}
	close(fd);
}

