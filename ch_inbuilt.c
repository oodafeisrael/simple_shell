#include "shell.h"
#include <stdbool.h>
#include <stddef.h> /* For size_t */

int chk_inbuilt(char **args_arr, size_t argc)
{
	/* Check for the "exit" command */
	if (strcmp(args_arr[0], "exit") == 0)
	{
		chk_exit(args_arr, argc);
		return (1);
	}
	/* Check for environmental commands "env" and "printenv" */
	else if ((strcmp(args_arr[0], "env") == 0) || (strcmp(args_arr[0], "printenv") == 0))
	{
		chk_env(args_arr);
		return (1);
	}
	return (0);
}

void chk_exit(char **args_arr, size_t argc)
{
	int status = EXIT_SUCCESS;

	if (argc > 1) /* Checking if there are flag arguments */
	{
		/* Convert the exit status argument to an integer */
		status = _atoi(args_arr[1]);
		if (status == -1) /* Check for conversion failure */
		{
			perror("Error: exit status failed");
			return;
		}
	}

	free(args_arr);
	exit(status);
}

void chk_env(char **env_args)
{
	if (!env_args[1])
	{
		_printenv();
	}
}

void _printenv(void)
{
	extern char **environ;
	int x;
	size_t len;

	for (x = 0; environ[x]; x++)
	{
		len = 0;
		while (environ[x][len])
			len++;
		write(STDOUT_FILENO, environ[x], len);
		write(STDOUT_FILENO, "\n", 1);
	}
}
