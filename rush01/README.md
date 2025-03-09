# Parse input

gcc -Wall -Wextra -Werror parse_input.c create_grid.c 
./a.out  "4 3 2 1 1 2 2 2 4 3 2 1 1 2 2 2" | cat -e


# Check solution to a valid grid

check_col_row.c
create_grid.c
examples.c
gcc -Wall -Wextra -Werror check_col_row.c create_grid.c examples.c

In the main, you can either use the example line or the manual line, 


# Create all valid grid for N

create_comb.c
gcc -Wall -Wextra -Werror create_comb.c create_grid.c
> Enter a N (between 1 and 9 included)
