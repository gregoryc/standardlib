#include "../foundationallib.h"
#include <assert.h>
#include <string.h>

// Define this if the function is part of a library

// Function to test
FOUNDATIONAL_LIB_FUNC char *longest_common_suffix(const char **strings, size_t count);

// Test cases
void testSingleString()
{
    const char *input[] = {"hello"};
    char *result = longest_common_suffix(input, 1);
    assert(strcmp(result, "hello") == 0);
    free(result);
}

void testEmptyStrings()
{
    const char *input[] = {"", "", ""};
    char *result = longest_common_suffix(input, 3);
    assert(strcmp(result, "") == 0);
    free(result);
}

void testNoCommonSuffix()
{
    const char *input[] = {"hello", "world", "foo"};
    char *result = longest_common_suffix(input, 3);
    assert(strcmp(result, "") == 0);
    free(result);
}

void testCommonSuffix()
{
    const char *input[] = {"testing", "ing", "string"};
    char *result = longest_common_suffix(input, 3);
    assert(strcmp(result, "ing") == 0);
    free(result);
}

void testLongestCommonSuffix()
{
    const char *input[] = {"apple", "people", "staple"};
    char *result = longest_common_suffix(input, 3);
    assert(strcmp(result, "ple") == 0);
    free(result);
}

int main()
{
    testSingleString();
    testEmptyStrings();
    testNoCommonSuffix();
    testCommonSuffix();
    testLongestCommonSuffix();

    printf("All tests passed!\n");
    return 0;
}
