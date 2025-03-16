#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_DIGITS 100 // Supports numbers up to 100 digits

typedef struct {
    char digits[MAX_DIGITS + 1]; // Number stored in reverse order
    int length; // Actual number of digits
} BigNumber;

// Function to create a BigNumber from a string
BigNumber createBigNumber(const char *numStr) {
    BigNumber num;
    num.length = strlen(numStr);
    
    // Store the number in reverse order for easy calculation
    for (int i = 0; i < num.length; i++) {
        num.digits[i] = numStr[num.length - i - 1] - '0';
    }
    
    num.digits[num.length] = '\0';
    return num;
}

// Function to print a BigNumber
void printBigNumber(BigNumber num) {
    for (int i = num.length - 1; i >= 0; i--) {
        printf("%d", num.digits[i]);
    }
    printf("\n");
}

// Function to add two BigNumbers
BigNumber addBigNumbers(BigNumber a, BigNumber b) {
    BigNumber result;
    result.length = 0;
    int carry = 0;

    int maxLength = (a.length > b.length) ? a.length : b.length;

    for (int i = 0; i < maxLength || carry; i++) {
        int sum = carry;
        if (i < a.length) sum += a.digits[i];
        if (i < b.length) sum += b.digits[i];

        result.digits[result.length++] = sum % 10;
        carry = sum / 10;
    }

    return result;
}

// Function to subtract two BigNumbers (assuming a >= b)
BigNumber subtractBigNumbers(BigNumber a, BigNumber b) {
    BigNumber result;
    result.length = 0;
    int borrow = 0;

    for (int i = 0; i < a.length; i++) {
        int diff = a.digits[i] - (i < b.length ? b.digits[i] : 0) - borrow;

        if (diff < 0) {
            diff += 10;
            borrow = 1;
        } else {
            borrow = 0;
        }

        result.digits[result.length++] = diff;
    }

    // Remove leading zeros
    while (result.length > 1 && result.digits[result.length - 1] == 0) {
        result.length--;
    }

    return result;
}

// Function to compare two BigNumbers (returns 1 if a > b, 0 if a == b, -1 if a < b)
int compareBigNumbers(BigNumber a, BigNumber b) {
    if (a.length > b.length) return 1;
    if (a.length < b.length) return -1;

    for (int i = a.length - 1; i >= 0; i--) {
        if (a.digits[i] > b.digits[i]) return 1;
        if (a.digits[i] < b.digits[i]) return -1;
    }

    return 0;
}

// Function to divide a BigNumber by an integer (returns quotient)
BigNumber divideBigNumber(BigNumber a, int divisor, int *remainder) {
    BigNumber quotient;
    quotient.length = 0;
    *remainder = 0;

    for (int i = a.length - 1; i >= 0; i--) {
        int current = *remainder * 10 + a.digits[i];
        quotient.digits[i] = current / divisor;
        *remainder = current % divisor;
    }

    // Remove leading zeros
    quotient.length = a.length;
    while (quotient.length > 1 && quotient.digits[quotient.length - 1] == 0) {
        quotient.length--;
    }

    return quotient;
}

// Function to get modulo of a BigNumber with an integer
int modBigNumber(BigNumber a, int divisor) {
    int remainder = 0;
    
    for (int i = a.length - 1; i >= 0; i--) {
        remainder = (remainder * 10 + a.digits[i]) % divisor;
    }
    
    return remainder;
}

// Main function to test operations
int main() {
    BigNumber num1 = createBigNumber("1000000000000000000000000000000000"); // Decillion
    BigNumber num2 = createBigNumber( "999999999999999999999999999999999"); // Just below Decillion

    printf("Num1: ");
    printBigNumber(num1);
    
    printf("Num2: ");
    printBigNumber(num2);
    
    // Addition
    BigNumber sum = addBigNumbers(num1, num2);
    printf("Sum: ");
    printBigNumber(sum);
    
    // Subtraction
    BigNumber diff = subtractBigNumbers(num1, num2);
    printf("Difference: ");
    printBigNumber(diff);

    // Division
    int remainder;
    BigNumber quotient = divideBigNumber(num1, 2, &remainder);
    printf("Quotient (Num1 / 2): ");
    printBigNumber(quotient);
    printf("Remainder: %d\n", remainder);

    // Modulo
    int modResult = modBigNumber(num1, 1000);
    printf("Num1 %% 1000 = %d\n", modResult);

    return 0;
}

