#include "shell.h"
#include <stdbool.h>
#include <stddef.h> /* For size_t */
/**
* chk_inbuilt - This function checks for built-in commands
* @args_arr: Command argument passed by the user at the terminal
* @argc: Number of arguments passed
* Return: 1 if command is found, else 0
*/
int chk_inbuilt(char **args_arr, size_t argc)
{
	/* Check for the "exit" command */
	if (strcmp(args_arr[0], "exit") == 0)
	{
		chk_exit(args_arr, argc);
		return (1);
	}
	/* Check for environmental commands "env" and "printenv" */
	else if ((strcmp(args_arr[0], "env") == 0) ||
			(strcmp(args_arr[0], "printenv") == 0))
	{
		chk_env(args_arr);
		return (1);
	}
	return (0);
}
/**
* chk_exit - This function checks for built-in exit command
* @args_arr: Command argument passed by the user at the terminal
* @argc: Number of arguments passed
* Return: nothing
*/
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
/**
* chk_env - Function to check for built-in env.
* @env_args: Environment arguments or commands.
* Return: Nothing.
*/
void chk_env(char **env_args)
{
	if (!env_args[1])
	{
		_printenv();
	}
}
/**
* _printenv - Function to print environmental variables.
* Return: Nothing.
*/
void _printenv(void)
{
	char **environ = 0;
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
