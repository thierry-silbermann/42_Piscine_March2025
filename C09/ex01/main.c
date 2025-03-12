#include <stdio.h>
#include "libft.h"

void test_putchar()
{
    printf("Testing ft_putchar: ");
    ft_putchar('A');
    ft_putchar('\n');
}

void test_swap()
{
    int x = 5, y = 10;
    printf("Before swap: x = %d, y = %d\n", x, y);
    ft_swap(&x, &y);
    printf("After swap: x = %d, y = %d\n", x, y);
}

void test_putstr()
{
    printf("Testing ft_putstr: ");
    ft_putstr("Hello, libft!\n");
}

void test_strlen()
{
    char *str = "Hello, World!";
    printf("Testing ft_strlen: \"%s\" has length %d\n", str, ft_strlen(str));
}

void test_strcmp()
{
    char *s1 = "apple";
    char *s2 = "apricot";
    printf("Testing ft_strcmp: Comparing \"%s\" and \"%s\" -> %d\n", s1, s2, ft_strcmp(s1, s2));

    char *s3 = "banana";
    char *s4 = "banana";
    printf("Testing ft_strcmp: Comparing \"%s\" and \"%s\" -> %d\n", s3, s4, ft_strcmp(s3, s4));

    char *s5 = "orange";
    char *s6 = "apple";
    printf("Testing ft_strcmp: Comparing \"%s\" and \"%s\" -> %d\n", s5, s6, ft_strcmp(s5, s6));
}

int main()
{
    test_putchar();
    test_swap();
    test_putstr();
    test_strlen();
    test_strcmp();

    return 0;
}
