#include "../foundationallib.h"
#include <assert.h>
#include <stdio.h>
// Test cases for the frozen_dict_size function
void test_frozen_dict_size()
{
    struct FrozenDict dict;

    // Test case 1: Empty dictionary
    size_t size = frozen_dict_size(&dict);
    assert(size == 0);

    // Test case 2: Dictionary with one key-value pair
    // Add key-value pair to the dictionary
    size = frozen_dict_size(&dict);
    assert(size == 1);

    // Test case 3: Dictionary with multiple key-value pairs
    // Add multiple key-value pairs to the dictionary
    size = frozen_dict_size(&dict);
    assert(size == 2);
}

int main()
{
    printf("Running tests for frozen_dict_size function\n");

    test_frozen_dict_size();

    printf("All tests passed!\n");

    return 0;
}
