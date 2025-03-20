/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilberm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 15:29:34 by tsilberm          #+#    #+#             */
/*   Updated: 2025/03/19 20:29:49 by tsilberm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	while (i < len)
	{
		word[i] = start[i];
		i++;
	}
	word[len] = '\0';
	return (word);
}

void	ft_split2(char *str, char *charset, char **result)
{
	int		index;
	char	*start;

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
			str++;
	}
	result[index] = NULL;
}

char	**ft_split(char *str, char *charset)
{
	int		word_count;
	char	**result;

	word_count = count_words(str, charset);
	result = (char **)malloc(sizeof(char *) * (word_count + 1));
	if (!result)
		return (NULL);
	ft_split2(str, charset, result);
	return (result);
}

int main()
{
	char str[] = "Hello, world! This is a test.";
	char charset[] = " ,!.";
	char **result = ft_split(str, charset);
	int i = 0;
	while (result[i] != NULL)
	{
		printf("%s\n", result[i]);
		free(result[i]);
		i++;
	}
	free(result);

	return (0);
}
