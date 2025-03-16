#include "ft_header.h"

// Function to convert a number (char *) into words
void convertNumberToWords(char *numStr, BigNumberDictionaryEntry *dict, int dictSize) {
    if (compareBigNumbers(numStr, "0") == 0) {
        write(1, "zero\n", 5);
        return;
    }

    int firstWord = 1;  // To handle spacing properly

    while (compareBigNumbers(numStr, "0") > 0) {
        // Find the closest floor number in the dictionary
        BigNumberDictionaryEntry *floor = findFloorNumber(numStr, dict, dictSize);
        if (!floor) break;

        // Compute the multiplier
        int remainder;
        int multiplier = divideBigNumber(numStr, atoi(floor->number), &remainder);

        // Special case for 11-19 (teen numbers)
        if (compareBigNumbers(floor->number, "10") >= 0 && compareBigNumbers(floor->number, "20") < 0) {
            if (!firstWord) write(1, " ", 1);
            write(1, floor->name, str_len(floor->name));
            firstWord = 0;
            remainder = 0; // No further processing needed for teen numbers
        } 
        else {
            // If it's ≥ 100, we need to add a multiplier (e.g., "four hundred")
            if (compareBigNumbers(floor->number, "100") >= 0) {
                // Convert multiplier (1-9 or 10-19) into words
                char multiplierStr[3];  
                if (multiplier >= 10) { // Handle 10-19 cases in thousands correctly
                    multiplierStr[0] = (multiplier / 10) + '0';
                    multiplierStr[1] = (multiplier % 10) + '0';
                    multiplierStr[2] = '\0';
                } else { // Handle 1-9
                    multiplierStr[0] = multiplier + '0';
                    multiplierStr[1] = '\0';
                }

                BigNumberDictionaryEntry *multiplierEntry = findFloorNumber(multiplierStr, dict, dictSize);
                if (multiplierEntry) {
                    if (!firstWord) write(1, " ", 1);
                    write(1, multiplierEntry->name, str_len(multiplierEntry->name));
                    firstWord = 0;
                }
            }

            // Print the name of the floor value
            if (!firstWord) write(1, " ", 1);
            write(1, floor->name, str_len(floor->name));
            firstWord = 0;
        }

        // If there's a remainder, continue processing
        if (remainder > 0) {
            //write(1, " ", 1);

            // Convert remainder to string for the next iteration
            char remainderStr[MAX_DIGITS];
            int remLen = 0;
            while (remainder > 0) {
                remainderStr[remLen++] = (remainder % 10) + '0';
                remainder /= 10;
            }
            for (int i = 0; i < remLen / 2; i++) { // Reverse string
                char temp = remainderStr[i];
                remainderStr[i] = remainderStr[remLen - i - 1];
                remainderStr[remLen - i - 1] = temp;
            }
            remainderStr[remLen] = '\0';

            numStr = remainderStr;
        } else {
            write(1, "\n", 1);
            return;
        }
    }
}


int loadDictionary(int fd, BigNumberDictionaryEntry *dict, int maxEntries)
{
    //int fd = open(DICT_FILE, O_RDONLY);
    //if (fd < 0) return -1;  // File open error

    char *buffer = (char *)malloc(BUFFER_SIZE);
    if (!buffer)
    {
        close(fd);
        return -1;
    }

    int bytesRead = read(fd, buffer, BUFFER_SIZE - 1);
    if (bytesRead <= 0)
    {
        free(buffer);
        close(fd);
        return -1;
    }
    buffer[bytesRead] = '\0';  // Ensure null-termination

    //close(fd);  // File no longer needed

    int count = 0;
    char *ptr = buffer;
    while (*ptr && count < maxEntries)
    {
        char *colon = ptr;
        while (*colon && *colon != ':') colon++;
        if (*colon == '\0') break;

        *colon = '\0';  // Split number and name
        char *numberPart = ptr;
        char *namePart = colon + 1;

        // Find next line
        char *nextLine = namePart;
        while (*nextLine && *nextLine != '\n') nextLine++;
        if (*nextLine == '\n') *nextLine++ = '\0';

        trimSpaces(numberPart);
        trimSpaces(namePart);

        dict[count].number = (char *)malloc(MAX_DIGITS + 1);
        dict[count].name = (char *)malloc(MAX_NAME + 1);
        dict[count].length = str_len(numberPart);

        str_copy(dict[count].number, numberPart, MAX_DIGITS);
        str_copy(dict[count].name, namePart, MAX_NAME);

        count++;
        ptr = nextLine;
    }

    free(buffer);
    return count;
}


// Function to print dictionary using `write`
void printDictionary(BigNumberDictionaryEntry *dict, int dictSize)
{

    for (int i = 0; i < dictSize; i++) {
        int numLen = str_len(dict[i].number);
        write(1, dict[i].number, numLen);
        write(1, " -> ", 4);

        int nameLen = str_len(dict[i].name);
        write(1, dict[i].name, nameLen);
        write(1, "\n", 1);
    }
}

// Function to free allocated memory
void freeDictionary(BigNumberDictionaryEntry *dict, int dictSize)
{
    for (int i = 0; i < dictSize; i++) {
        free(dict[i].number);
        free(dict[i].name);
    }
}
/*
// Main function
int	main()
{
	BigNumberDictionaryEntry bigNumberDictionary[MAX_ENTRIES];

	int dictSize = loadDictionary(bigNumberDictionary, MAX_ENTRIES);
	if (dictSize < 0)
	{
		write(2, "Error loading dictionary\n", 25);
		return (1);
	}

	//printDictionary(bigNumberDictionary, dictSize);

	// Example test case
	ft_putstr("442 -> ");
	convertNumberToWords("442", bigNumberDictionary, dictSize);
	ft_putstr("42 -> ");
	convertNumberToWords("42", bigNumberDictionary, dictSize);
	ft_putstr("100 -> ");
	convertNumberToWords("100", bigNumberDictionary, dictSize);
	ft_putstr("17952 -> ");
	convertNumberToWords("17952", bigNumberDictionary, dictSize);

	freeDictionary(bigNumberDictionary, dictSize);
	return (0);
}*/
