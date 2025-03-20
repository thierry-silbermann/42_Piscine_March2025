/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilberm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 16:42:03 by tsilberm          #+#    #+#             */
/*   Updated: 2025/03/03 19:02:11 by tsilberm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_strcmp(char *s1, char *s2)
{
	while (*s1 && (*s1 == *s2))
	{
		s1++;
		s2++;
	}
	return ((unsigned char)*s1 - (unsigned char)*s2);
}
/*
int main()
{
    char s1[] = "Hello";
    char s2[] = "Hello";
    char s3[] = "Hell";
    char s4[] = "Hella";

    printf("Comparison of s1 and s2: %d, should be 0\n", ft_strcmp(s1, s2));
    printf("Comparison of s1 and s3: %d, should be +\n", ft_strcmp(s1, s3));
    printf("Comparison of s1 and s4: %d, should be +\n", ft_strcmp(s1, s4));
    printf("Comparison of s3 and s4: %d, should be -\n", ft_strcmp(s3, s4));

    return 0;
}*/
