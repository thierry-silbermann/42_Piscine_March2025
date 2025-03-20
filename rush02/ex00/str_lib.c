/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_lib.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilberm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 19:52:37 by tsilberm          #+#    #+#             */
/*   Updated: 2025/03/16 20:26:11 by smarques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_header.h"

void    ft_putstr(char *str)
{
        int     i;

        i = 0;
        while(str[i])
        {
                write(1, &str[i], 1);
                i++;
        }
}

int     str_len(const char *str)
{
        int len;

        len = 0;
        while (str[len] != '\0')
                len++;
        return (len);
}

void    str_copy(char *dest, const char *src, int maxLen)
{
        int     i;

        i = 0;
        while (i < maxLen && src[i] != '\0')
        {
                dest[i] = src[i];
                i++;
        }
        dest[i] = '\0';
}

void trimSpaces(char *str)
{
	int	start;
	int	end;
	int	i;

	start = 0;
	end = str_len(str) - 1;
	while (str[start] == ' ' || (str[start] >= 9 && str[start] <= 13))
		start++;
	while (end > start && (str[end] == ' ' || (str[end] >= 9 && str[end] <= 13)))
		end--;
	i = 0;
	while (start <= end)
	{
		str[i] = str[start];
		i++;
		start++;
	}
	str[i] = '\0';
}
