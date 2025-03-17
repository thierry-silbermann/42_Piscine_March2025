/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_header.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilberm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 16:24:11 by tsilberm          #+#    #+#             */
/*   Updated: 2025/03/17 19:59:09 by tsilberm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_HEADER_H
# define FT_HEADER_H

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>

# define BUFFER_SIZE 1024

typedef struct map_s
{
	char	empty;
	char	obstacle;
	char	full;
	int		row_size;     // updated
	int		col_size;     // updated
	char	**map;
}	t_map;

typedef struct answer_s
{
	int	i;
	int	j;
	int	size;
}	t_answer;

char	*get_line(int fd);
void	print_map(t_map *map);
int		check_duplicates_char(t_map *map_info);
int		validate_row(int i, int j, int len, t_map *map_info);
int		validate_map(t_map *map_info);
int		ft_strlen(char *str);
void		find_biggest_square(t_map *map_info); 				// new line
void		ft_putchar(char c);						// new line

#endif
