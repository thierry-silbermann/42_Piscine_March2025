#include <stdlib.h>
#include <stdio.h>

int	is_separator(char c, char *charset)
{
	while (*charset)
	{
		if (c == *charset)
			return (1);
		charset++;
	}
	return (0);
}

int	count_words(char *str, char *charset)
{
	int	count;
	int	in_word;

	count = 0;
	in_word = 0;
	while (*str)
	{
		if (is_separator(*str, charset))
		{
			in_word = 0;
		} 
		else if (!in_word)
		{
			in_word = 1;
			count++;
		}
		str++;
	}
	return (count);
}

char	*allocate_word(char *start, char *end)
{
	int		len;
	int		i;
	char	*word;

	len = end - start;
	word = (char *)malloc(len + 1);
	if (!word)
		return (NULL);
	i = 0;
	while(i < len)
	{
		word[i] = start[i];
		i++;
	}
	word[len] = '\0';
	return (word);
}

char	**ft_split(char *str, char *charset)
{
	int		word_count;
	int		index;
	char	**result;
	char	*start;

	word_count = count_words(str, charset);
	result = (char **)malloc(sizeof(char *) * (word_count + 1));
	if (!result)
		return (NULL);
	index = 0;
	while (*str)
	{
		if (!is_separator(*str, charset))
		{
			start = str;
			while (*str && !is_separator(*str, charset))
				str++;
			result[index++] = allocate_word(start, str);
		}
		else
		{
			str++;
		}
	}
	result[index] = NULL; // Last element should be NULL (0)
	return (result);
}

int main()
{
	char str[] = "Hello, world! This is a test.";
	char charset[] = " ,!.";
	char **result = ft_split(str, charset);

	for (int i = 0; result[i] != NULL; i++)
	{
		printf("%s\n", result[i]);
		free(result[i]); // Free allocated memory
	}
	free(result); // Free array itself

	return (0);
}
