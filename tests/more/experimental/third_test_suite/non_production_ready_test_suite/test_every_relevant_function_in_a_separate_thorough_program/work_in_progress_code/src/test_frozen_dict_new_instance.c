#include "../foundationallib.h"
#include <assert.h>
#include <stdarg.h>
#include <stdio.h>

int main()
{
    // Test case 1: Creating an empty dictionary
    struct FrozenDict *empty_dict = frozen_dict_new_instance(0);
    assert(empty_dict != NULL);

    // Test case 2: Creating a dictionary with one key-value pair
    char *key1 = "key1";
    int value1 = 100;
    struct FrozenDict *single_dict = frozen_dict_new_instance(1, key1, &value1);
    assert(single_dict != NULL);
    assert(single_dict->size == 1); // Assuming size is a member of FrozenDict

    // Add more test cases for different scenarios and edge cases

    printf("All tests passed successfully\n");
    return 0;
}
