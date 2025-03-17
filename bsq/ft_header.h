#ifndef FT_HEADER_H
# define FT_HEADER_H

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define BUFFER_SIZE 1024

typedef struct {
        char    	empty;
        char    	obstacle;
	char		full;
	int		size;
	char	**map;
} map_struct;

#endif
