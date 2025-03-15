#include <fcntl.h>   // open
#include <unistd.h>  // read, close
#include <stdlib.h>  // malloc, free
#include <stdio.h>   // printf (for testing)

#define BUFFER_SIZE 1  // Read character by character

// Function to read a single line from a file descriptor
char *get_next_line(int fd) {
    if (fd < 0)
        return NULL;

    char *line = malloc(1024); // Initial buffer for line storage
    if (!line)
        return NULL;

    int i = 0;
    char buf;
    int bytes_read;

    while ((bytes_read = read(fd, &buf, 1)) > 0) {
        line[i++] = buf;
        if (buf == '\n')  // Stop at newline
            break;
    }

    if (bytes_read == 0 && i == 0) { // End of file case
        free(line);
        return NULL;
    }

    line[i] = '\0'; // Null-terminate the string
    return line;
}

// Test the function
int main() {
    int fd = open("numbers.dict", O_RDONLY);
    if (fd == -1) {
        return 1; // Error opening file
    }

    char *line;
    while ((line = get_next_line(fd)) != NULL) {
        printf("%s", line); // Print line (newline is already included)
        free(line); // Free allocated memory
    }

    close(fd);
    return 0;
}

