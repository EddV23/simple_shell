#ifndef SHELL_H
#define SHELL_H

#include <errno.h>
#include <fcntl.h>
#include <limits.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

#define BUFFER_SIZE 1024
#define _printf(c) (write(STDOUT_FILENO, c, _strlen(c)))

extern char **environ;

/**
 * struct hxbltin - handles and executes builtin commands
 * @tok: the tokenized command
 * @myexec: execute the builtin commands in the simple shell
 */
typedef struct  hxbltin
{
	char *tok;
	int (*myexec)(char **buf, int exstat);
} cmd_blt;

/* ========== _getenv.c ========== */
char *_getenv(char *n);
int ev_path(char *cmd[]);
void ev_clear(char *ev[]);
char *exec(char *cmd, char *loc);

/* ========== _getline.c ========== */
void clear_stdin_buffer(void);
void hd_hash(char *n);
char *_getline(void);
void signal_handler(int s);

/* ========== file_handlers.c ========== */
void file_p(char *buf, int c, FILE *myfile, char *ev[]);
void file_r(char *n, char *ev[]);
void file_exit(char *cmd[], char *buf, FILE *myfile);
int my_hist(char *n);

/* ========== handle_builtin_1.c ========== */
int my_echo(char *cmd[], int exstat);
int print_ev(char *cmd[], int exstat);
int _help(char *cmd[], int exstat);
int cwd(char **cmd, int exstat);
void quit_shell(char *cmd[], char *n, char *ev[], int c);

/* ========== handle_builtin_2.c ========== */
int child_proc(char *cmd[], char *n, int c, char *ev[]);
int builtin_hd(char **cmd, int exstat);
int builtin_ch(char **cmd);
void ev_crt(char *ev[]);

/* ========== handle_builtin_3.c ========== */
void pr_error(char *av[], int c, char *cmd[]);
int print_hist(char **cmd, int stt);
int echo_disp(char **cmd);
void _abs(int n);
void _num(unsigned int n);

/* ========== helper_functions_1.c ========== */
char *_strncpy(char *dest, char *src, int n);
int _strcmp(char *str1, char *str2);
int len_int(int n);
int _atoi(char *s);
char *_itoa(unsigned int n);

/* ========== helper_functions_2.c ========== */
int _strlen(char *s);
int _isalpha(int c);
void rev_arr(char *arr, int length);
void _puts(char *str);
int _putchar(char c);

/* ========== helper_functions_3.c ========== */
char *_strcat(char *dest, char *src);
int _strncmp(const char *str1, const char *str2, size_t n);
char *_strcpy(char *dest, char *src);
char *_strdup(char *str);
char *_strchr(char *str, char c);

/* ========== mem_handle.c ========== */
void *mem_calloc(unsigned int s);
char *mem_copy(char *dest, char *src, unsigned int n);
void mem_clear(char *cmd[], char *buf);
void *alloc_delim(void *bytes, int n, unsigned int s);
void *mem_realloc(void *buf, unsigned int s1, unsigned int s2);

/* ========== my_token.c ========== */
void cmd_prompt(void);
char *_strtok(char *str, const char *bytes);
unsigned int is_delim(char a, const char *str);
char **crt_token(char *n);
void error_msg(char *n, int c, char *cmd[]);

/* ========== shell.c ========== */
int main(int ac, char *av[]);

#endif /* SHELL_H */
