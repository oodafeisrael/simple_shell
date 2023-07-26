#include "shell.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * strg_split - This function splits a string into
 * individual words based on a delimiter.
 * @str: The input string to be split
 * Return: An array of strings (words)
 */
char **strg_split(char *str)
{
    char **args_arr = NULL;
    int arg_count = 0, i;
    char *token;
    const char *delimiter = " ";

    args_arr = malloc(50 * sizeof(char *));
    if (!args_arr)
    {
        perror("strg_split allocation error");
        exit(EXIT_FAILURE);
    }

    token = strtok(str, delimiter);
    while (token != NULL)
    {
        for (i = 0; token[i] != '\0'; i++)
        {
            if (token[i] == '\n')
            {
                token[i] = '\0';
            }
        }

        args_arr[arg_count] = strdup(token);
        if (!args_arr[arg_count])
        {
            perror("strg_split allocation error");
            exit(EXIT_FAILURE);
        }

        arg_count++;

        if (arg_count >= 50)
        {
            fprintf(stderr, "Maximum number of words reached.\n");
        break;
        }

      token = strtok(NULL, delimiter);

    }

    args_arr[arg_count] = NULL;

    return (args_arr);
}
