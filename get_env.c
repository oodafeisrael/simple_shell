#include "shell.h"
/**
* _getenv - function that gets environmental variables
* @key: variable key
* Return: pointer to start index value
*/
char *_getenv(char *key)
{
	char **ptr = environ;
	size_t namelen = _strlen(key);

	while (*ptr)
	{
		if (_strcmp(*ptr, key, namelen) == 0 &&
				(*ptr)[namelen] == "=")
		{
			return (&((*ptr)[namelen + 1]));
		}
		ptr++;
	}
	return (NULL);
}
