# Parse input

gcc -Wall -Wextra -Werror parse_input.c create_grid.c 
./a.out  "4 3 2 1 1 2 2 2 4 3 2 1 1 2 2 2" | cat -e


# Check solution to a valid grid

gcc -Wall -Wextra -Werror check_col_row.c create_grid.c examples.c
./a.out

In the main, you can either use the example line or the manual line, 

# Create all valid grid for N

gcc -Wall -Wextra -Werror create_comb.c create_grid.c
./a.out

> Enter a N (between 1 and 9 included) // Never tried above 6 as it might take time



---------------------------------------


# Algorithm execution

- Parse input to know the size of N we need to execute
- Generate all valid combinations of Latin Square of size N
	- For each valid combination, create the rules 
	- Check for if the current rule matches the input rule
	- If yes, print the corresponding grid
- If no match, print "Error"
