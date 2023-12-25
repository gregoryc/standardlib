#include "../foundationallib.h"

#include <assert.h>
#include <stdio.h>

int is_string_lower(const char *str)
{
    if (str == NULL)
    {
        return 0;
    }

    while (*str != '\0')
    {
        if (*str < 'a' || *str > 'z')
        {
            return 0;
        }
        str++;
    }

    return 1;
}

int main()
{
    // Test case 1: All lowercase characters
    const char *test_string1 = "abcdefghijklmnopqrstuvwxyz";
    assert(is_string_lower(test_string1) == 1);

    // Test case 2: Uppercase characters
    const char *test_string2 = "abcDefg";
    assert(is_string_lower(test_string2) == 0);

    // Test case 3: Empty string
    const char *test_string3 = "";
    assert(is_string_lower(test_string3) == 1);

    // Test case 4: NULL input
    const char *test_string4 = NULL;
    assert(is_string_lower(test_string4) == 0);

    // Test case 5: Numbers and special characters
    const char *test_string5 = "abc123";
    assert(is_string_lower(test_string5) == 0);

    printf("All test cases passed successfully.\n");

    return 0;
}
