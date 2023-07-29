#include "shell.h"
/**
* file_status_chk - this function checksif a file exists in the system
* @path_name:This the path to the file
* @status: storage location for file information
* Return: True if it is found, otherwise false
*/
bool file_status_chk(char *path_name, struct stat *status)
{
	int status_ret;
	struct stat status;

	status_ret = stat(path_name, status);
	if (status_ret == 0)
	{
		return (true);
	}
	return (false);
}
/**
* file_path_concat - function to concatenate a path with the executable
* @filename: name of file to be concatenated
* @status: storage location for file information
* Return: The full path of the file or NULLif
*          file does not exist
*/
char *file_path_concat(char *filename, struct stat status)
{
	size_t j, pathcount;
	char *f_path;
	char *pres_path = _getenv("PATH");
	char **pathtok = strg_split(pres_path, ":", &pathcount);

	for (j = 0, j < pathcount; j++)
	{
		f_path = strg_concat(3, pathtok, "/", filename);
		if (file_status_chk(f_path, status))
		{
			free_array(pathtok, pathcount);
			return (f_path);
		}
		free(f_path);
	}
	/*if file does not exist in path */
	free_array(pathtok, pathcount);
	return (NULL);
}
