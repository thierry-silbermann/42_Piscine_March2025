#include "ft_header.h"

// Function to compare two big numbers as strings
int compareBigNumbers(const char *num1, const char *num2) {
    int len1 = str_len(num1);
    int len2 = str_len(num2);

    if (len1 > len2) return 1;
    if (len1 < len2) return -1;

    for (int i = 0; i < len1; i++) {
        if (num1[i] > num2[i]) return 1;
        if (num1[i] < num2[i]) return -1;
    }
    return 0;
}

// Function to find the largest number in the dictionary that is less than or equal to `str`
BigNumberDictionaryEntry *findFloorNumber(char *str, BigNumberDictionaryEntry *dict, int dictSize) {
    BigNumberDictionaryEntry *floor = NULL;

    for (int i = 0; i < dictSize; i++) {
        if (compareBigNumbers(str, dict[i].number) >= 0) { // If str >= dict[i].number
            if (!floor || compareBigNumbers(dict[i].number, floor->number) > 0) {
                floor = &dict[i]; // Update floor if this number is greater than the current floor
            }
        }
    }

    return floor; // Return found floor number or NULL if not found
}

// Function to divide a BigNumber by an integer, returning the quotient
int divideBigNumber(char *numStr, int divisor, int *remainder) {
    int quotient = 0;
    int rem = 0;
    for (int i = 0; numStr[i] != '\0'; i++) {
        rem = rem * 10 + (numStr[i] - '0');
        if (quotient || rem / divisor) {
            quotient = quotient * 10 + (rem / divisor);
        }
        rem %= divisor;
    }
    *remainder = rem;
    return quotient;
}


