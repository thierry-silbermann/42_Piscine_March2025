#include "ft_header.h"
#include <stdio.h>


void	display_dict(t_dict *d, int dict_count)
{
	int	i;

	i = 0;
	while (i < dict_count)
	{
		printf("%d -> %s \n", d[i].number, d[i].word);
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_dict	dict[DICT_SIZE];
	int	dict_count;

	if (argc < 2)
	{
		ft_putstr_error("File name missing.");
		return (1);
	}
	if (argc > 3)
	{
		ft_putstr_error("Too many arguments.");
		return (1);	
	}
	if (argc == 2)
	{
		if (!is_positive_number(argv[1]))
		{
			ft_putstr_error("Error");
			return (1);
		}
		if (!parse_dictionary(argv[1], dict, &dict_count))
                        return (1);
		display_dict(dict, dict_count);
	}
	else if (argc == 3)
	{
		if (!parse_dictionary(argv[1], dict, &dict_count))
			return (1);
		if (!is_positive_number(argv[2]))
		{
			ft_putstr_error("Error");
			return (1);
		}
		printf("dict count: %d\n", dict_count);
		display_dict(dict, dict_count);
	}
	return (0);
}
