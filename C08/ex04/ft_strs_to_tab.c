#include <stdlib.h>
#include "ft_stock_str.h"

char *ft_strdup(char *src)
{
    int i = 0;
    char *dup;
    
    while (src[i])
        i++;
    dup = (char *)malloc(sizeof(char) * (i + 1));
    if (!dup)
        return (NULL);
    i = 0;
    while (src[i])
    {
        dup[i] = src[i];
        i++;
    }
    dup[i] = '\0';
    return (dup);
}

struct s_stock_str *ft_strs_to_tab(int ac, char **av)
{
    t_stock_str *array;
    int i;
    
    array = (t_stock_str *)malloc(sizeof(t_stock_str) * (ac + 1));
    if (!array)
        return (NULL);
    i = 0;
    while (i < ac)
    {
        array[i].size = 0;
        while (av[i][array[i].size])
            array[i].size++;
        array[i].str = av[i];
        array[i].copy = ft_strdup(av[i]);
        if (!array[i].copy)
        {
            while (i-- > 0)
                free(array[i].copy);
            free(array);
            return (NULL);
        }
        i++;
    }
    array[i].str = 0;
    return (array);
}
