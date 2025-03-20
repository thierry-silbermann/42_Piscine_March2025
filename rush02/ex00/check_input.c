/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilberm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 20:05:24 by tsilberm          #+#    #+#             */
/*   Updated: 2025/03/16 20:24:17 by smarques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_header.h"

int     ft_atoi(char *str)
{
        int     sign;

        sign = 1;
        while (*str == ' ' || (*str >= 9 && *str <= 13))
                str++;
        while (*str == '+' || *str == '-')
        {
                if (*str == '-')
                        sign = -sign;
                str++;
        }
        if (sign < 0)
                return (-1);
        while (*str >= '0' && *str <= '9')
                str++;
        if (*str == '.')
                return (-1);
        return (1);
}

int	ft_putstr_error(char *str)
{
        while (*str)
                write(2, str++, 1); 
        write(2, "\n", 1);
	return (1);
}

int     check_input(int argc, char **argv)
{
        if (argc < 2) // Not enough arguments
                return (ft_putstr_error("Error"));
        if (argc > 3) // Too many arguments
                return (ft_putstr_error("Error"));
        if (argc == 2)
        {
                if (ft_atoi(argv[1]) != 1)
                        return (ft_putstr_error("Error"));
        }
	else if (argc == 3)
	{
		if (ft_atoi(argv[2]) != 1)
			return (ft_putstr_error("Error"));
	}
        return (0);
}
