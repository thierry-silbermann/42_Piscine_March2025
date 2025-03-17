make fclean
make

valgrind --leak-check=full ./bsq map_example map_example
gdb --args bsq map_example map_example

