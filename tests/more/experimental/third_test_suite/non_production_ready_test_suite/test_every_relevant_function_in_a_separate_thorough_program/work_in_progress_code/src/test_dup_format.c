#include "../foundationallib.h"

#include <assert.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>

// define this macro for library functions

// Function to duplicate a formatted string
char *dup_format(const char *format, ...)
{
    va_list args;
    va_start(args, format);
    int length = vsnprintf(NULL, 0, format, args);
    va_end(args);

    char *result = (char *)malloc(length + 1);
    if (result)
    {
        va_start(args, format);
        vsnprintf(result, length + 1, format, args);
        va_end(args);
    }

    return result;
}

int main()
{
    // Test suite for dup_format function
    char *result;

    // Test case 1: Basic format string
    result = dup_format("%s %d", "Test", 123);
    assert(strcmp(result, "Test 123") == 0);
    free(result);

    // Test case 2: Empty format string
    result = dup_format("");
    assert(strcmp(result, "") == 0);
    free(result);

    // Test case 3: Format string with large number of variables
    result = dup_format("%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d", 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20);
    assert(strcmp(result, "1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20") == 0);
    free(result);

    // Test case 4: NULL format string
    result = dup_format(NULL);
    assert(result == NULL);

    // Add more test cases for corner cases

    printf("All test cases passed!\n");

    return 0;
}
