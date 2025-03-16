#ifndef FT_HEADER_H
# define FT_HEADER_H

#include <fcntl.h>   // open
#include <unistd.h>  // read, close
#include <stdlib.h>  // malloc, free
#include <stdio.h>   // printf (for testing)

#define MAX_DIGITS 100   // Maximum number length
#define MAX_NAME 50      // Maximum name length
#define MAX_ENTRIES 50   // Maximum dictionary entries
#define BUFFER_SIZE 1024 // Buffer for file reading
#define DICT_FILE "numbers.dict"  // Dictionary file name

typedef struct {
        char    *number;  // Dynamically allocated string for number
        int             length;    // Actual digit count
        char    *name;    // Dynamically allocated string for word
} BigNumberDictionaryEntry;

void			convertNumberToWords(char *numStr, BigNumberDictionaryEntry *dict, int dictSize);
int			loadDictionary(int fd, BigNumberDictionaryEntry *dict, int maxEntries);
void			printDictionary(BigNumberDictionaryEntry *dict, int dictSize);
void			freeDictionary(BigNumberDictionaryEntry *dict, int dictSize);
int			compareBigNumbers(const char *num1, const char *num2);
BigNumberDictionaryEntry *findFloorNumber(char *str, BigNumberDictionaryEntry *dict, int dictSize);
int			divideBigNumber(char *numStr, int divisor, int *remainder);
void			ft_putstr(char *str);
int			str_len(const char *str);
void			str_copy(char *dest, const char *src, int maxLen);
void			trimSpaces(char *str);
int			ft_putstr_error(char *str);
int			check_input(int argc, char **argv);
unsigned long long	ft_atoi(char *str);
int			is_positive_number(char *str);
int			check_argc_size(int argc);

#endif
