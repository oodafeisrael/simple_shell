#include "shell.h"
/**
* exec_toks - function that checks if a command is builtin or not
* @argv: commands and its flags
* Return: 1 on success, 0 on failure
*/
char exec_toks(char **argv)
{
	/* check if a command is builtin*/
	int inbuilt_cmd = chk_inbuilt(tokens);

	if (inbuilt_cmd != -1)
	{
		handle_builtin_cmd(inbuilt_cmd);
		free_array(tokens);
		continue;
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
			continue
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
