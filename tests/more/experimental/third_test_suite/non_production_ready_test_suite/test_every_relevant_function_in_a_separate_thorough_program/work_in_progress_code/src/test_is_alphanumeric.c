#include "../foundationallib.h"
#include <assert.h>
#include <stdio.h>

FOUNDATIONAL_LIB_FUNC int is_alphanumeric(const char *str)
{
    if (str == NULL)
    {
        return 0;
    }
    while (*str)
    {
        if ((*str < 'a' || *str > 'z') && (*str < 'A' || *str > 'Z') && (*str < '0' || *str > '9'))
        {
            return 0;
        }
        str++;
    }
    return 1;
}

int main()
{
    // Test cases for empty string
    assert(is_alphanumeric("") == 0);

    // Test cases for only alphabets
    assert(is_alphanumeric("abc") == 1);
    assert(is_alphanumeric("ABC") == 1);
    assert(is_alphanumeric("abC") == 1);
    assert(is_alphanumeric("aBc") == 1);
    assert(is_alphanumeric("123") == 0);

    // Test cases for only digits
    assert(is_alphanumeric("123") == 1);
    assert(is_alphanumeric("456") == 1);
    assert(is_alphanumeric("789") == 1);
    assert(is_alphanumeric("312") == 1);
    assert(is_alphanumeric("abc123") == 0);

    // Test case for special characters
    assert(is_alphanumeric("abc123@") == 0);

    // Test case for NULL input
    assert(is_alphanumeric(NULL) == 0);

    printf("All tests passed!\n");

    return 0;
}
