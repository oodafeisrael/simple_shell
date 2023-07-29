#include "shell.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * strg_split - This function splits a string into
 * individual words based on a delimiter.
 * @str: The input string to be split
 * @count: number of argument tokens
 * Return: An array of strings (words)
 */
char **strg_split(char *str, char *delim, size_t *count)
{
	char **args_arr;
	int arg_count = 0, i;
	char *token;

	args_arr = malloc(50 * sizeof(char *));
	if (!args_arr)
	{
		perror("strg_split allocation error");
		exit(EXIT_FAILURE);
	}

	token = strtok(str, " ");
	while (token != NULL)
	{
		for (i = 0; token[i] != '\0'; i++)
		{
			if (token[i] == '\n')
				token[i] = '\0';
		}
		args_arr[arg_count] = token;
		arg_count++;
		token = strtok(NULL, " ");
	}

	args_arr[arg_count] = NULL;
	return (args_arr);
}
