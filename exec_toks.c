#include "shell.h"
/**
* exec_toks - function that checks if a command is builtin or not
* @tokens: commands and its flags
* @argc: number of argument count
* Return: 1 on success, 0 on failure
*/
char exec_toks(char **tokens, size_t argc)
{
	size_t nbytes;
	/* check if a command is builtin*/
	int inbuilt_cmd = chk_inbuilt(tokens, nbytes);
	int flag = 0;

	if (inbuilt_cmd != -1)
	{
		handle_builtin(inbuilt_cmd);
		free_array(tokens);
		flag = 1;
	}
	else
	{
		free(tokens[0]);
		tokens[0] = NULL;
	}
	/* check if the executable file exists in PATH*/
	char *fpath = NULL;

	if (!file_status_chk(tokens[0], nbytes))
	{
		f_path = file_path_chk(tokens[0], &status);
		if (!f_path)
		{
			perror("Error(file status)");
			free_array(tokens);
			return (0);
		}
		else
		{
			free(tokens[0]);
			tokens[0] = f_path;
		}
	}
	exec_cmd(tokens);
	free_array(tokens);
	return (1);
}
