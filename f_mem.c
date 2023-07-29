#include "shell.h"
#include <stdlib.h>
/**
* free_array - function that frees memory allocated for an array of strings
* @array: array of arguments
* @size: number of arguments
* Return: nothing
*/
void free_array(char **array, int size)
{
	if (array == NULL)
	{
		return;
	}
	for (int i = 0; i < size; i++)
	{
		free(array[i]);
	}
	free(array);
}
