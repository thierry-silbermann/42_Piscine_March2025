#ifndef FT_HEADER_H
# define FT_HEADER_H

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

#define MAX_DIGITS 100
#define MAX_NAME 50
#define MAX_ENTRIES 50
#define BUFFER_SIZE 1024
#define DICT_FILE "numbers.dict"

typedef struct {
        char    *number;
        int             length;
        char    *name;
} dict_struct;

void			convertNumberToWords(char *numStr, dict_struct *dict, int dictSize);
int			loadDictionary(int fd, dict_struct *dict, int maxEntries);
void			printDictionary(dict_struct *dict, int dictSize);
void			freeDictionary(dict_struct *dict, int dictSize);
int			compareBigNumbers(const char *num1, const char *num2);
dict_struct	*findFloorNumber(char *str, dict_struct *dict, int dictSize);
int			divideBigNumber(char *numStr, int divisor, int *remainder);
void			ft_putstr(char *str);
int			str_len(const char *str);
void			str_copy(char *dest, const char *src, int maxLen);
void			trimSpaces(char *str);
int			ft_putstr_error(char *str);
int			check_input(int argc, char **argv);
int			ft_atoi(char *str);
int			check_argc_size(int argc);

#endif
