#include "../foundationallib.h"
#include <assert.h>
#include <stdio.h>

// Function to test
FOUNDATIONAL_LIB_FUNC int is_numeric(const char *str)
{
    while (*str)
    {
        if (*str < '0' || *str > '9')
        {
            return 0;
        }
        str++;
    }
    return 1;
}

// Test suite
int main()
{
    // Test cases for is_numeric function
    assert(is_numeric("12345") == 1);   // All numbers
    assert(is_numeric("abc123") == 0);  // Alphanumeric
    assert(is_numeric("9999999") == 1); // All numbers
    assert(is_numeric("") == 1);        // Empty string
    assert(is_numeric("00123") == 1);   // Leading zeros
    assert(is_numeric("12 34") == 0);   // Space
    assert(is_numeric("12.34") == 0);   // Decimal point
    assert(is_numeric("+123") == 0);    // Positive sign
    assert(is_numeric("-123") == 0);    // Negative sign

    printf("All tests passed!\n");

    return 0;
}
