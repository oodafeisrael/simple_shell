#include "shell.h"
#include <stdio.h>
#include <stdbool.h>

/**
 * _atoi - Converts a string to an integer.
 * @str: The input string to be converted.
 * Return: The integer value.
 */
int _atoi(char *str)
{
	int result = 0;
	int sign = 1;
	int i = 0;

	while (str[i] == ' ')
	{
		i++;
	}

	/* Checking for a + or - character (+ or -) */
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	else if (str[i] == '+')
	{
		i++;
	}

	/* To convert the string to an integer */
	while (str[i] != '\0')
	{
		if (str[i] >= '0' && str[i] <= '9')
		{
			result = result * 10 + (str[i] - '0');
		}
		else
		{
			break;
		}
		i++;
	}
	return (result * sign);
}
