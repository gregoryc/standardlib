#include "../foundationallib.h"

#include <assert.h>
#include <stdio.h>

int is_string_space(const char *str)
{
    if (str == NULL)
    {
        return 0;
    }
    while (*str != '\0')
    {
        if (*str != ' ' && *str != '\t')
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
    const char *empty = "";
    assert(is_string_space(empty) == 1);

    // Test case 2: String with only spaces
    const char *spaces = "    ";
    assert(is_string_space(spaces) == 1);

    // Test case 3: String with only tabs
    const char *tabs = "\t\t\t";
    assert(is_string_space(tabs) == 1);

    // Test case 4: String with spaces and tabs
    const char *mixed = "  \t  \t  ";
    assert(is_string_space(mixed) == 1);

    // Test case 5: String with other characters
    const char *non_space = "not all spaces";
    assert(is_string_space(non_space) == 0);

    printf("All test cases passed!\n");

    return 0;
}
