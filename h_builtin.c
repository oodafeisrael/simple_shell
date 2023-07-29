#include "shell.h"
/**
* handle_builtin - function to execute a builtin command
* @argv: argument and flag passed for execution at the terminal
* @argc: number of argument count passed
* Return: True if a builtin command is found, otherwise false
*/
bool handle_builtin(char **argv, size_t argc)
{
	/*for exit command entered*/
	if (_strcmp(argv[0], "exit", 4) == 0)
	{
		handle_exit(argv, argc);
	}
	else
	{
		/*for env command entered*/
		if ((_strcmp(argv[0], "énv", 3) == 0) ||
				(_strcmp(argv[0], "printenv", 8) == 0))
		{
			handle_env(argv, argc);
			return (true);
		}
		return (false);
	}

}
/**
* handle_exit - function to execute exit builtin commnd
* @argv: exit command argument
* @argc: number of arguments passed
* Return: Nothing
*/
void handle_exit(char **argv, size_t argc)
{
	int status = EXIT_SUCCESS;

	if (argv[1])
	{
		status = _atoi(argv[1]);
	}
	free_array(argv, argc);
	exit(status);
	}
}
/**
* handle_env - function to execute the env builtin cmd
* @argv: env arguments or command
* @argc: number of arguments passed
* Return: nothing
*/
void handle_env(char **argv, size_t argc)
{
	if (!argv[1])
	{
		_printenv();
	}
	free_array(argv, argc);
}
