#include "../foundationallib.h"

#include <assert.h>
#include <stdio.h>

FOUNDATIONAL_LIB_FUNC int is_string_upper(const char *str)
{
    if (str == NULL)
    {
        return 0;
    }

    while (*str)
    {
        if (!(*str >= 'A' && *str <= 'Z'))
        {
            return 0;
        }
        str++;
    }
    return 1;
}

void test_is_string_upper()
{
    // Test with empty string
    assert(is_string_upper("") == 1);

    // Test with all uppercase string
    assert(is_string_upper("HELLO") == 1);

    // Test with mixed case string
    assert(is_string_upper("Hello") == 0);

    // Test with lowercase string
    assert(is_string_upper("hello") == 0);

    // Test with special characters
    assert(is_string_upper("!@#$%") == 0);

    // Test with NULL input
    assert(is_string_upper(NULL) == 0);

    // Test with long uppercase string
    char long_upper[1000];
    for (int i = 0; i < 1000; i++)
    {
        long_upper[i] = 'A';
    }
    long_upper[1000] = '\0';
    assert(is_string_upper(long_upper) == 1);

    // Test with long mixed case string
    char long_mixed[1000];
    for (int i = 0; i < 500; i++)
    {
        long_mixed[i] = 'A';
    }
    for (int i = 500; i < 1000; i++)
    {
        long_mixed[i] = 'a';
    }
    long_mixed[1000] = '\0';
    assert(is_string_upper(long_mixed) == 0);
}

int main()
{
    test_is_string_upper();
    printf("All tests passed successfully.\n");
    return 0;
}
