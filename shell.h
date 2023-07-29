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
/*size_t rd_cmd(char **strg, size_t *nbytes);*/
void removeTrailingNewline(char *strg);
char **strg_split(char *strg, char *delim, size_t *count);
int chk_inbuilt(char **args_arr, size_t argc);
int exec_cmd(char **strg);
void chk_exit(char **args_arr, size_t argc);
bool file_status_chk(char *pathname, struct stat *statbuf);
void chk_env(char **args_arr);
int _atoi(char *strg);
void _printenv(void);
char exec_toks(char **tokens, size_t argc);
char *rd_strm(const char *file_path);
void usr_interactive_sh(void);
char *rd_cmd(void);
void usr_no_interactive_sh(void);
bool handle_builtin(char **argv, size_t argc);
void handle_exit(char **argv, size_t argc);
void handle_env(char **argv, size_t argc);
void free_array(char **array, int size);
bool file_status_chk(char *path_name, struct stat *status);
char *file_path_concat(char *filename, struct stat *status);
#endif
