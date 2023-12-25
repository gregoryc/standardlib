#include "../foundationallib.h"

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// Test function
int test_set_to_array()
{
    // Test case 1: empty set
    struct Set *empty_set = NULL;
    char **empty_keys;
    size_t empty_size_of_keys;
    int result1 = set_to_array(empty_set, &empty_keys, &empty_size_of_keys);
    assert(result1 == 1);
    assert(empty_keys == NULL);
    assert(empty_size_of_keys == 0);

    // Test case 2: non-empty set
    struct Set *non_empty_set = NULL; // Initialize non-empty set with some values
    char **non_empty_keys;
    size_t non_empty_size_of_keys;
    int result2 = set_to_array(non_empty_set, &non_empty_keys, &non_empty_size_of_keys);
    // Add assertions for expected values in non_empty_keys and non_empty_size_of_keys

    return 0;
}

int main()
{
    int res = test_set_to_array();
    if (res == 0)
    {
        printf("All tests passed\n");
    }
    else
    {
        printf("Some tests failed\n");
    }
    return 0;
}
