#include "shell.h"
/**
* main - This is a shell program that checks if command is from user 
* terminal or from other process
* Return: 0 on success always
*/
int main(void)
{
	char prompt[] = "#cisfunc$ ";

	write(STDOUT_FILENO, prompt, sizeof(prompt) - 1);
	if (isatty(STDIN_FILENO) == 1)
	{
		usr_interactive_sh();
	}
	else
	{
		usr_no_interactive_sh();
	}
	return (0);
}
