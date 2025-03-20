/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_header.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilberm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 16:24:11 by tsilberm          #+#    #+#             */
/*   Updated: 2025/03/19 21:28:53 by tsilberm         ###   ########.fr       */
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
	int		row_size;
	int		col_size;
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
void	print_error_and_free_map(t_map *map);
int		check_duplicates_char(t_map *map_info);
int		validate_row(int i, int j, int len, t_map *map_info);
int		validate_map(t_map *map_info);
int		ft_strlen(char *str);
void	find_biggest_square(t_map *map_info);
void	ft_putchar(char c);
int		ft_max(int a, int b);
int		ft_isdigit(char c);
int		ft_len_int(int nb);
void	print_error(void);
void	free_map(t_map *map_info);
int		read_map(int fd, t_map *map_info);
char	**allocate_map_memory(t_map *map_info);
int		ft_isprintable(char c);

#endif
