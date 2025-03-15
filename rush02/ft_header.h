#ifndef FT_HEADER_H
# define FT_HEADER_H

#define DICT_SIZE 50
#define BUFFER_SIZE 4096

typedef struct s_dict
{
    int number;
    char word[50];
} t_dict;

void    ft_putstr_error(char *str);
int	is_positive_number(char *str);
int	parse_dictionary(char *filename, t_dict *dict, int *dict_count);

#endif
