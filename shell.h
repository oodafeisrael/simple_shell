#ifndef SHELL_H
#define SHELL_H
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <stdbool.h>
#include <stddef.h>
#define MAX_COMMAND_LENGTH 100
ssize_t getline(char **lineptr, size_t *n, FILE *stream);
void prompt(int argc, char **argv, char **env);
int stat(const char *pathname, struct stat *statbuf);
int execve(const char *pathname, char *const argv[], char *const envp[]);
void displayPrompt(const char *prompt);
size_t rd_cmd(char **strg, size_t *nbytes);
void removeTrailingNewline(char *strg);
char **strg_split(char *strg);
int chk_inbuilt(char **args_arr, size_t argc);
int exec_cmd(char *strg);
void chk_exit(char **args_arr, size_t argc);
bool file_status_chk(char *pathname, struct stat *statbuf);
void chk_env(char **args_arr);
int _atoi(char *strg);
void _printenv(void);
#endif
