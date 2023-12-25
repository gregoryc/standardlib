#include "../foundationallib.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// Test cases for the function
void test_frozen_dict_get_check()
{
    // Test case 1: key is found
    struct FrozenDict dict1[] = {{"key1", "value1"}, {"key2", "value2"}, {NULL, NULL}};
    int key_is_in_dict1;
    void *result1 = frozen_dict_get_check(dict1, "key1", &key_is_in_dict1);
    assert(key_is_in_dict1 == 1);
    assert(strcmp((char *)result1, "value1") == 0);

    // Test case 2: key is not found
    struct FrozenDict dict2[] = {{"key1", "value1"}, {"key2", "value2"}, {NULL, NULL}};
    int key_is_in_dict2;
    void *result2 = frozen_dict_get_check(dict2, "key3", &key_is_in_dict2);
    assert(key_is_in_dict2 == 0);
    assert(result2 == NULL);

    // Additional test cases for corner cases
    //... (add more test cases as needed)
}

int main()
{
    test_frozen_dict_get_check();
    printf("All tests passed!\n");
    return 0;
}
