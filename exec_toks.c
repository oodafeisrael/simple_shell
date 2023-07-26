#include "shell.h"
/**
* exec_toks - function that checks if a command is builtin or not
* @tokens: commands and its flags
* Return: 1 on success, 0 on failure
*/
char exec_toks(char **tokens)
{
	/* check if a command is builtin*/
	int inbuilt_cmd = chk_inbuilt(tokens);
	int flag = 0;

	if (inbuilt_cmd != -1)
	{
		handle_builtin_cmd(inbuilt_cmd);
		free_array(tokens);
		flag = 1;
	}
	else
	{
		free(toens[0]);
		tokens[0] = NULL;
	}
	/* check if the executable file exists in PATH*/
	char *fpath = NULL;

	if (!file_status_chk(token[0]))
	{
		fpath = file_path_chk(tokens[0]);
		if (!fpath)
		{
			perrors("Error(file status)");
			free_array(tokens);
			return (0);
		}
		else
		{
			free(tokens[0]);
			token[0] = fpath;
		}
	}
	exec_cmd(tokens);
	free_array(tokens);
	return (1);
}
