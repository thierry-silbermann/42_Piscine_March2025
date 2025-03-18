/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rogde-so <rogde-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 18:56:57 by rogde-so          #+#    #+#             */
/*   Updated: 2025/03/06 17:07:38 by rogde-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

void	print_non_printable(unsigned char c)
{
	char	*hex;
	char	writearray[3];

	hex = "0123456789abcdef";
	writearray[0] = '\\';
	writearray[1] = hex[c / 16];
	writearray[2] = hex[c % 16];
	write(1, writearray, 3);
}

void	ft_putstr_non_printable(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] < 32 || str[i] > 126)
		{
			print_non_printable((unsigned char)str[i]);
			i++;
		}
		else
		{
			write(1, &str[i], 1);
			i++;
		}
	}
}
/*
void	ft_putstr_non_printable(char *str)
{
	int	i;
	int	d;
	int	m;
	char	*hex;
	char	barra;
	char	hexdec1;
	char	hexdec2;
	char	writearray[3];

	hex = "0123456789abcdef";
	i = 0;
	barra = '\\';
	while (str[i] != '\0')
	{
		d = 0;
		m = 0;
		if (str[i] < 32 || str[i] > 126)
		{
			d = str[i] / 16;
			m = str[i] % 16;
			hexdec1 = hex[d];
			hexdec2 = hex[m];
			writearray[0] = barra;
			writearray[1] = hexdec1;
			writearray[2] = hexdec2;
			write(1, writearray, 3);
		}
		else
		{
			write(1, &str[i], 1);
		}
		i++;
	}
}*/
/*
int	main()
{
	char	str[] = "AI caram\nm®B\0A";

	ft_putstr_non_printable(str);
}*/
