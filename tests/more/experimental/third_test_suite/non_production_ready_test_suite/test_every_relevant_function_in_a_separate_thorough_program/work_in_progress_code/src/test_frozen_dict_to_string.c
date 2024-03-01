#include "../foundationallib.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void test_frozen_dict_to_string()
{
    struct FrozenDict *dict = frozen_dict_new_instance(); // Create a test frozen dictionary

    char *result = frozen_dict_to_string(dict, 0);
    // Test pointer format result
    assert(result != NULL);

    // Test the result matches the expected format for pointer
    // Assume expected pointer format for the test
    // Example: assert(strcmp(result, "0x1234, 0x5678") == 0);

    free(result);

    result = frozen_dict_to_string(dict, 1);
    // Test string format result
    assert(result != NULL);

    // Test the result matches the expected format for string
    // Assume expected string format for the test
    // Example: assert(strcmp(result, "{key1: value1, key2: value2}") == 0);

    free(result);

    // Test with NULL dictionary
    result = frozen_dict_to_string(NULL, 0);
    assert(result == NULL);

    // Test with NULL dictionary and string format
    result = frozen_dict_to_string(NULL, 1);
    assert(result == NULL);

    // Free the test frozen dictionary
    free_test_frozen_dict(dict);
}

int main()
{
    test_frozen_dict_to_string();
    printf("All tests passed!\n");
    return 0;
}
