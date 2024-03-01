#include "../foundationallib.h"

#include <assert.h>

FOUNDATIONAL_LIB_FUNC int is_string_alpha(const char *str)
{
    if (!str)
    {
        return 0;
    }
    while (*str)
    {
        if (!isalnum(*str))
        {
            return 0;
        }
        str++;
    }
    return 1;
}

int main()
{
    // Test case 1: Empty string should return 1
    assert(is_string_alpha("") == 1);

    // Test case 2: String with only alphabets should return 1
    assert(is_string_alpha("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ") == 1);

    // Test case 3: String with only digits should return 1
    assert(is_string_alpha("0123456789") == 1);

    // Test case 4: String with both alphabets and digits should return 1
    assert(is_string_alpha("abc123") == 1);

    // Test case 5: String with special characters should return 0
    assert(is_string_alpha("abc!@#") == 0);

    // Test case 6: Null string should return 0
    assert(is_string_alpha(NULL) == 0);

    return 0;
}
