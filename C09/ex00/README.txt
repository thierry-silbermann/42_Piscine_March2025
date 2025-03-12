chmod +x libft_creator.sh

After running sh libft_creator.sh to generate libft.a, compile and test the library:

gcc main.c -L. -lft -o test_libft
./test_libft


# Expected output

Testing ft_putchar: A
Before swap: x = 5, y = 10
After swap: x = 10, y = 5
Testing ft_putstr: Hello, libft!
Testing ft_strlen: "Hello, World!" has length 13
Testing ft_strcmp: Comparing "apple" and "apricot" -> -15
Testing ft_strcmp: Comparing "banana" and "banana" -> 0
Testing ft_strcmp: Comparing "orange" and "apple" -> 15

