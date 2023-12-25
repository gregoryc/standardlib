#include "../foundationallib.h"
#include <assert.h>

void test_concatenate_strings()
{
    // Test case 1: both strings are empty
    const char *str1 = "";
    const char *str2 = "";
    char *result = concatenate_strings(str1, str2);
    assert(strcmp(result, "") == 0);
    free(result);

    // Test case 2: one string is empty
    str1 = "Hello";
    str2 = "";
    result = concatenate_strings(str1, str2);
    assert(strcmp(result, "Hello") == 0);
    free(result);

    // Test case 3: both strings are non-empty
    str1 = "Hello, ";
    str2 = "World!";
    result = concatenate_strings(str1, str2);
    assert(strcmp(result, "Hello, World!") == 0);
    free(result);

    // Test case 4: one string is NULL
    str1 = "Hello";
    str2 = NULL;
    result = concatenate_strings(str1, str2);
    assert(result == NULL);
    free(result);

    // Test case 5: both strings are NULL
    str1 = NULL;
    str2 = NULL;
    result = concatenate_strings(str1, str2);
    assert(result == NULL);
    free(result);
}

int main()
{
    test_concatenate_strings();
    printf("All tests passed!\n");
    return 0;
}
