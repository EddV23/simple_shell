#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>

void cmd_prompt(void);
void signal_handler(int __attribute__((__unused__)) s);
void quit_shell(char *cmd[]);
void end_of_file(char *buf);
int main(int __attribute__((__unused__)) ac, char *av[], char *ev[]);
char *_getline(const int fd);

/*int cwd(const char *wd);*/
void cwd(char *token, char **prev_dir, char *home);
void child_proc(char *cmd[], char *n, char *ev[], int c);

int sh_cd(char *token, char **prev_dir, char *home);

void display_ev(char *ev[]);
void error_msg(char *n, int c, char *cmd[]);
char **ev_path(char *ev[]);
void exec(char *cmd[], char *n, char *ev[], int c);

void handle_commands(char **cmds, int n, char **ev, char *name);

char **create_str_cmd(char *buf, const char *str);

void free_cmd_mem(char *cmd[]);
void free_cmd_ex(char *cmd[]);

int _atoi(char *s);
int _strcmp(char *s1, char *s2);
char *_strcpy(char *dest, char *src);
unsigned int _strlen(char *s);
char *_strcat(char *dest, char *src);

int sh_setenv(char *variable, char *value, int overwrite);
int sh_unsetenv(char *variable);
/*int handle_builtin(char **cmd);*/
int handle_builtin(char **cmd, char **prev_dir, char *home);

#endif /* SHELL_H */
