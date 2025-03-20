/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilberm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 19:52:37 by tsilberm          #+#    #+#             */
/*   Updated: 2025/03/16 20:25:11 by smarques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_header.h"

int	main(int argc, char **argv)
{
	int			fd;
	dict_struct		bigNumberDictionary[MAX_ENTRIES];
	char		*input_str;

	fd = -1;
	if (check_input(argc, argv) == 1)
		return (1);
	if (argc == 2)
	{
		fd = open("numbers.dict", O_RDONLY);
		input_str = argv[1];
	}
	else if (argc == 3)
	{
		fd = open(argv[1], O_RDONLY);
		input_str = argv[2];
	}
	if (fd == -1)
	{
		ft_putstr_error("Dict Error");
		return (1); // Error opening file
	}
	int dictSize = loadDictionary(fd, bigNumberDictionary, MAX_ENTRIES);
	if (dictSize < 0)
	{
		write(2, "Error loading dictionary\n", 25);
		return (1);
	}
	//printDictionary(bigNumberDictionary, dictSize);
	convertNumberToWords(input_str, bigNumberDictionary, dictSize);
        /* Example test case
        ft_putstr("442 -> ");
        convertNumberToWords("442", bigNumberDictionary, dictSize);
        ft_putstr("42 -> ");
        convertNumberToWords("42", bigNumberDictionary, dictSize);
        ft_putstr("100 -> ");
        convertNumberToWords("100", bigNumberDictionary, dictSize);
        ft_putstr("17952 -> ");
        convertNumberToWords("17952", bigNumberDictionary, dictSize);
	*/
        freeDictionary(bigNumberDictionary, dictSize);
	close(fd);
	return (0);
}
