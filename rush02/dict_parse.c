#include <unistd.h>
#include <fcntl.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "ft_header.h"

#define BUFFER_SIZE 4096
#define DICT_SIZE 50

char	*trim_whitespace(char *str)
{
	char	*end;

	while (*str == ' ' || *str == '\t')
		str++;
	end = str + strlen(str) - 1;
	while (end > str && (*end == ' ' || *end == '\t'))
		*end-- = '\0';
	return (str);
}

char	*ft_strtok(char *str, const char *delim)
{
	static char *saved_str = NULL;
	if (str)
		saved_str = str;
	if (!saved_str || *saved_str == '\0')
		return NULL;
	char *token_start = saved_str;
	while (*token_start && strchr(delim, *token_start))
		token_start++;
	if (*token_start == '\0')
	{
		saved_str = NULL;
		return (NULL);
	}
    
 	char *token_end = token_start;
	while (*token_end && !strchr(delim, *token_end))
		token_end++;
    
	if (*token_end)
	{
		*token_end = '\0';
		saved_str = token_end + 1;
	}
	else
		saved_str = NULL;
    	return (token_start);
}

int	parse_dictionary(char *filename, t_dict *dict, int *dict_count)
{
	int		fd;
	char		buffer[BUFFER_SIZE + 1];
	ssize_t		bytes_read;
	char	*line;
//	char	*num_str;
//	char	*word;
	
	dict[0].number = 1;
//	dict[0].word = NULL;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		ft_putstr_error("Cannot read file");
		return (0);
	}
	*dict_count = 0;
	bytes_read = read(fd, buffer, BUFFER_SIZE);
	while (bytes_read > 0)
	{
		buffer[bytes_read] = '\0';
		//line = ft_strtok(buffer, "\n");
		//printf("%d / %s\n", *dict_count, line);
		while (line && *dict_count < DICT_SIZE)
		{
			line = ft_strtok(buffer, "\n");
                	printf("%d / %s\n", *dict_count, line);
			/*num_str = ft_strtok(line, ":");
			word = ft_strtok(NULL, "");
			if (!num_str || !word)
			{
				ft_putstr_error("Dict Error");
				close(fd);
				return (0);
			}
			num_str = trim_whitespace(num_str);
			word = trim_whitespace(word);
			if (!is_positive_number(num_str) || strlen(word) == 0)
			{
				ft_putstr_error("Dict Error");
				close(fd);
				return (0);
			}
			dict[*dict_count].number = atoi(num_str);
			strncpy(dict[*dict_count].word, word, sizeof(dict[*dict_count].word) - 1);
			dict[*dict_count].word[sizeof(dict[*dict_count].word) - 1] = '\0';
 			(*dict_count)++;
			*/
			line = ft_strtok(NULL, "\n");
		}
		bytes_read = read(fd, buffer, BUFFER_SIZE);
	}
	close(fd);
	return (1);
}
