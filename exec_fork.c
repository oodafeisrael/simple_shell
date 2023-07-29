#include "shell.h"
/**
* exec_cmd - This function executes the command entered by the users
* @argv: command arguments entered by the user
* @argc: number of arguments entered by the user
* @envp: array of environmental variables
* Return: void
*/
int exec_cmd(char **argv, argc, envp)
{
	pid_t child_pid;
	int status;

	child_pid = fork();
	if (child_pid == -1)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	if (child_pid == 0)
	{
		char **aargs = (char **)malloc(2 * sizzeof(char *));

		argv[0] = strg;
		argv[1] = NULL;
		/* child process*/
		execve(strg, args, NULL);
		perror("ëxecve");
		exit(EXIT_FAILURE);
	} else
	{
		/* parent process*/
		waitpid(child_pid, &status, 0);
	}
	free_array(argv, argc);
}
