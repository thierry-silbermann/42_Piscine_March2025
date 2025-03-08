#include <stdlib.h>

int     **ft_allocate_mem_tab(int size)
{
        int     i;
        int     j;
        int     **tab;

        i = 0;
        tab = malloc(size * sizeof(int *));
        while (i < size)
        {
                tab[i] = malloc(size * sizeof(int));
                j = 0;
                while (j < size)
                {
                        tab[i][j] = 0;
                        j++;
                }
                i++;
        }
        return (tab);
}

void    ft_free_tab(int **tab, int size)
{
        int     i;

        i = 0;
        while(i < size) {
                free(tab[i]);
                i++;
        }
        free(tab);
}

