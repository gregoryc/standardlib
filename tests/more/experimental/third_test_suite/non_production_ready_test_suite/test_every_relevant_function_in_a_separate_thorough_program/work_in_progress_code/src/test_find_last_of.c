#include "../foundationallib.h"
#include <assert.h>
#include <stdio.h>

FOUNDATIONAL_LIB_FUNC ssize_t find_last_of(const char *str, const char *char_set)
{
    if (str == NULL || char_set == NULL)
    {
        return -1;
    }

    ssize_t last_index = -1;

    for (const char *ptr = str; *ptr != '\0'; ptr++)
    {
        const char *found = strchr(char_set, *ptr);
        if (found != NULL)
        {
            last_index = ptr - str;
        }
    }

    return last_index;
}

void test_find_last_of()
{
    // Test cases
    assert(find_last_of("hello", "abc") == -1); // No matching characters
    assert(find_last_of("hello", "el") == 4);   // 'o' is the last matching character
    assert(find_last_of("hello", "ohl") == 4);  // 'o' is the last matching character
    assert(find_last_of("hello", "ox") == -1);  // No matching characters
    assert(find_last_of("hello", "") == -1);    // Empty char_set

    // Edge cases
    assert(find_last_of("", "abc") == -1);     // Empty string
    assert(find_last_of(NULL, "abc") == -1);   // Null string
    assert(find_last_of("hello", NULL) == -1); // Null char_set
    assert(find_last_of(NULL, NULL) == -1);    // Null string and char_set
}

int main()
{
    test_find_last_of();
    printf("All tests passed!\n");

    return 0;
}
