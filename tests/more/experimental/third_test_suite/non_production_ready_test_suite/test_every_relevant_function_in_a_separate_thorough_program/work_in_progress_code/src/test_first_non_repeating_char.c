#include "../foundationallib.h"
#include <assert.h>

FOUNDATIONAL_LIB_FUNC char first_non_repeating_char(const char *str)
{
    int charCount[256] = {0};

    for (int i = 0; str[i] != '\0'; i++)
    {
        charCount[(int)str[i]]++;
    }

    for (int i = 0; str[i] != '\0'; i++)
    {
        if (charCount[(int)str[i]] == 1)
        {
            return str[i];
        }
    }

    return '\0';
}

int main()
{
    // Test cases for the first_non_repeating_char function
    assert(first_non_repeating_char("") == '\0');
    assert(first_non_repeating_char("a") == 'a');
    assert(first_non_repeating_char("aa") == '\0');
    assert(first_non_repeating_char("leetcode") == 'l');
    assert(first_non_repeating_char("loveleetcode") == 'v');

    // Additional test cases
    assert(first_non_repeating_char("hello") == 'h');
    assert(first_non_repeating_char("helloworld") == 'e');
    assert(first_non_repeating_char("abcdefghijklmnopqrstuvwxyz") == 'a');
    assert(first_non_repeating_char("aabbccddeeffgghhii") == '\0');

    printf("All tests passed!\n");

    return 0;
}
