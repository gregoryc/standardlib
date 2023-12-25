#include "../foundationallib.h"
#include <assert.h>
#include <stdio.h>
#include <string.h>

FOUNDATIONAL_LIB_FUNC ssize_t find_first_of(const char *str, const char *char_set)
{
    for (size_t i = 0; str[i] != '\0'; i++)
    {
        for (size_t j = 0; char_set[j] != '\0'; j++)
        {
            if (str[i] == char_set[j])
            {
                return i;
            }
        }
    }
    return -1;
}

void test_find_first_of()
{
    const char *str = "Hello, World!";

    // Test cases for finding individual characters
    assert(find_first_of(str, "aeiou") == 1); // 'e' at index 1
    assert(find_first_of(str, "l") == 2);     // 'l' at index 2
    assert(find_first_of(str, "xy") == -1);   // None of 'x' or 'y' found

    // Test cases for empty string and char_set
    assert(find_first_of("", "abc") == -1); // Empty string
    assert(find_first_of(str, "") == -1);   // Empty char_set

    // Test cases for all characters in the string
    assert(find_first_of(str, "Hed!") == 0); // 'H' at index 0
    assert(find_first_of(str, "d!!") == 7);  // 'd' at index 7

    // Test cases for not finding any characters
    assert(find_first_of(str, "123") == -1); // None of '1', '2', '3' found

    printf("All test cases passed!\n");
}

int main()
{
    test_find_first_of();
    return 0;
}
