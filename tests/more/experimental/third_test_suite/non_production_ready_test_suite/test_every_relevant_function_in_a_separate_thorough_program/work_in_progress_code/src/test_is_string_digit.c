#include "../foundationallib.h"
#include <assert.h>
#include <stdio.h>

int is_string_digit(const char *str)
{
    if (*str == '\0')
    {
        return 1;
    }

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

int main()
{
    // Test case 1: Empty string
    assert(is_string_digit("") == 1);

    // Test case 2: Single non-digit character
    assert(is_string_digit("a") == 0);

    // Test case 3: Single digit character
    assert(is_string_digit("5") == 1);

    // Test case 4: String with all digits
    assert(is_string_digit("1234567890") == 1);

    // Test case 5: String with mixed characters including digits
    assert(is_string_digit("abc123") == 0);

    // Test case 6: String with special characters
    assert(is_string_digit("!@#%$") == 0);

    // Test case 7: String with leading whitespace
    assert(is_string_digit(" 123") == 0);

    // Test case 8: String with trailing whitespace
    assert(is_string_digit("123 ") == 0);

    // Test case 9: String with a mix of whitespace and digits
    assert(is_string_digit("12 34") == 0);

    printf("All tests passed successfully.\n");
    return 0;
}
