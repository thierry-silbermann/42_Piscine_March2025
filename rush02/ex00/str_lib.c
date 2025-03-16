#include "ft_header.h"

void    ft_putstr(char *str)
{
        int     i;

        i = 0;
        while(str[i])
        {
                write(1, &str[i], 1);
                i++;
        }
}

// Function to calculate string length
int     str_len(const char *str)
{
        int len;

        len = 0;
        while (str[len] != '\0')
                len++;
        return (len);
}

// Function to copy strings manually
void    str_copy(char *dest, const char *src, int maxLen)
{
        int     i;

        i = 0;
        while (i < maxLen && src[i] != '\0')
        {
                dest[i] = src[i];
                i++;
        }
        dest[i] = '\0';
}

// Function to trim spaces manually (leading & trailing)
void trimSpaces(char *str)
{
    int start = 0, end = str_len(str) - 1;

    // Trim leading spaces
    while (str[start] == ' ' || str[start] == '\t' || str[start] == '\n') start++;

    // Trim trailing spaces
    while (end > start && (str[end] == ' ' || str[end] == '\t' || str[end] == '\n')) end--;

    // Shift trimmed string to start of buffer
    int i;
    for (i = 0; start <= end; i++, start++) {
        str[i] = str[start];
    }
    str[i] = '\0';  // Null-terminate the trimmed string
}
