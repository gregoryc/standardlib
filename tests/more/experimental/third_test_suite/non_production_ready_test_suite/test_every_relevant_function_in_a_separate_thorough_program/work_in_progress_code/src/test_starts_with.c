#include "../foundationallib.h"
#include <assert.h>
#include <stdio.h>
#include <string.h>

FOUNDATIONAL_LIB_FUNC int starts_with(const char *str, const char *prefix)
{
    if (str == NULL || prefix == NULL)
    {
        return 0;
    }
    while (*prefix)
    {
        if (*prefix++ != *str++)
        {
            return 0;
        }
    }
    return 1;
}

int main()
{
    // Test cases
    assert(starts_with("hello world", "hello") == 1);
    assert(starts_with("hello world", "world") == 0);
    assert(starts_with("", "prefix") == 0);
    assert(starts_with("prefix", "") == 1);
    assert(starts_with("prefix", "pre") == 1);
    assert(starts_with("prefix", "prefiX") == 0);
    assert(starts_with("Hello", "hello") == 0);
    assert(starts_with("hello", "Hello") == 0);
    assert(starts_with("hello", "he") == 1);
    assert(starts_with("hello", "hello") == 1);

    printf("All tests passed!\n");

    return 0;
}
