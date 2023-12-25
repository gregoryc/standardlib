#include "../foundationallib.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
// Test cases for the frozen_dict_to_array function
void test_frozen_dict_to_array()
{
    // Test case 1: Empty dictionary
    {
        struct FrozenDict empty_dict;
        char **empty_keys;
        void **empty_values;
        size_t size_empty;

        size_t result = frozen_dict_to_array(&empty_dict, &empty_keys, &empty_values, &size_empty);

        assert(result == 0);     // Check for success
        assert(size_empty == 0); // Check for empty size
    }

    // Test case 2: Non-empty dictionary
    {
        struct FrozenDict non_empty_dict;
        char **non_empty_keys;
        void **non_empty_values;
        size_t size_non_empty;

        // Assuming non_empty_dict has some data

        size_t result = frozen_dict_to_array(&non_empty_dict, &non_empty_keys, &non_empty_values, &size_non_empty);

        assert(result == 0);              // Check for success
        assert(size_non_empty > 0);       // Check for non-empty size
        assert(non_empty_keys != NULL);   // Check keys array
        assert(non_empty_values != NULL); // Check values array

        // Clean up
        free(non_empty_keys);
        free(non_empty_values);
    }
}

int main()
{
    // Run the test suite
    test_frozen_dict_to_array();

    printf("All tests passed!\n");

    return 0;
}
