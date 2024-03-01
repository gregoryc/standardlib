#include "../foundationallib.h"

#include <assert.h>
#include <stdio.h>

FOUNDATIONAL_LIB_FUNC int ends_with(const char *str, const char *suffix)
{
    if (str == NULL || suffix == NULL)
    {
        return 0;
    }

    size_t str_len = strlen(str);
    size_t suffix_len = strlen(suffix);

    if (suffix_len > str_len)
    {
        return 0;
    }

    return (strncmp(str + (str_len - suffix_len), suffix, suffix_len) == 0) ? 1 : 0;
}

int main()
{
    // Test cases
    assert(ends_with("hello", "lo") == 1);
    assert(ends_with("hello", "hello") == 1);
    assert(ends_with("hello", "llo") == 1);
    assert(ends_with("hello", "hello!") == 0);
    assert(ends_with("hello", "o") == 1);
    assert(ends_with("hello", "h") == 0);
    assert(ends_with("hello", "") == 1);
    assert(ends_with("", "suffix") == 0);
    assert(ends_with("", "") == 1);

    // Additional corner cases
    assert(ends_with("hello", "HELLO") == 0);  // Case-sensitive check
    assert(ends_with("hello", "lo!") == 0);    // Partial match
    assert(ends_with("hello", "hello") == 1);  // Full match
    assert(ends_with("hello", "o") == 1);      // Single character suffix
    assert(ends_with("hello", "hello!") == 0); // Suffix longer than string
    assert(ends_with("hello", "H") == 0);      // Case-sensitive check

    printf("All test cases passed!\n");

    return 0;
}
