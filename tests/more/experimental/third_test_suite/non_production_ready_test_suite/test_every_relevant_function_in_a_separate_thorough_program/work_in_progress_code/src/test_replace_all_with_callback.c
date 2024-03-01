#include "../foundationallib.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/* Callback function for testing */
const char *test_callback(const char *old_substring)
{
    if (strcmp(old_substring, "old") == 0)
    {
        return "new";
    }
    else
    {
        return old_substring;
    }
}

int main()
{
    char *result;

    // Test case 1: Empty string
    result = replace_all_with_callback("", "old", test_callback);
    assert(strcmp(result, "") == 0);
    free(result);

    // Test case 2: No occurrences of old substring
    result = replace_all_with_callback("test", "old", test_callback);
    assert(strcmp(result, "test") == 0);
    free(result);

    // Test case 3: Single occurrence of old substring
    result = replace_all_with_callback("old test", "old", test_callback);
    assert(strcmp(result, "new test") == 0);
    free(result);

    // Test case 4: Multiple occurrences of old substring
    result = replace_all_with_callback("old old test old", "old", test_callback);
    assert(strcmp(result, "new new test new") == 0);
    free(result);

    printf("All tests passed!\n");

    return 0;
}
