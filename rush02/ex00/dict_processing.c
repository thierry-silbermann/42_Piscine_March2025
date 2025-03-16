/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict_processing.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilberm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 19:52:37 by tsilberm          #+#    #+#             */
/*   Updated: 2025/03/15 20:45:37 by tsilberm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_header.h"

#define BUFFER_SIZE 1  // Read character by character

int	valid_line(char *str)
{
	int	i;
	
	i = 0;
	while (str[i] >= '0' && str[i] <= '9')
		i++;
	if (i < 1)
		return (0);
	while (str[i] != ' ' || str[i])
		i++;
	if (!(str[i] == ':'))
		return (0);
	else
		i++;
	while (str[i] || str[i] == ' ')
		i++;
	
}

// Function to read a single line from a file descriptor
char	*get_next_line(int fd)
{
	char	*line;
	int		i;
	char		buf;
	int		bytes_read;

	line = malloc(1024); // Initial buffer for line storage
	if (!line)
		return NULL;
	i = 0;
	bytes_read = read(fd, &buf, 1);
	while (bytes_read > 0)
	{
		line[i++] = buf;
		if (buf == '\n')  // Stop at newline
			break;
		bytes_read = read(fd, &buf, 1);
	}
	if (bytes_read == 0 && i == 0)
	{ // End of file case
		free(line);
		return NULL;
	}
	line[i] = '\0'; // Null-terminate the string
	return (line);
}

void	fill_dict(int fd)
{
	char	*line;
	//t_dict	*dict;

	line = get_next_line(fd);
	while (line != NULL)
	{
		printf("%s", line); // Print line (newline is already included)
		free(line); // Free allocated memory
		line = get_next_line(fd);
	}
}
