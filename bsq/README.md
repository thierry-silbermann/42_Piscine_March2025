make re
make clean
./bsq map_example map_dir/*

valgrind --leak-check=full ./bsq map_example map_example
valgrind --leak-check=full ./bsq map_example map_dir/error_map_1 map_example
gdb --args bsq map_example map_example






To check
- DONE - Never using the exit command
- DONE - The characters can be any printable character, even numbers.
- DONE - The map is invalid if a character is missing from the first line
- DONE - There’s at least one line of at least one box.

We have no leaks on the example map, but we have leaks when handling the errors. TO BE HANDLED.

