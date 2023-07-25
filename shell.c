#include "shell,h"
/**
* main - This is a shell program that checks if command is from user 
* terminal or from other process
* Return: 0 on success always
*/
int main(int argc, char *argv[], char *env[])
{
	char prompt = "#cisfunc$ ";

	write(STDOUT_FILE, prompt, 9);
	if (isatty(STDIN_FILENO) == 1)
	{
		usr_interactive_sh(void);
	}
	else
	{
		usr_no_interactive_sh(void);
	}
	return (0);
}
