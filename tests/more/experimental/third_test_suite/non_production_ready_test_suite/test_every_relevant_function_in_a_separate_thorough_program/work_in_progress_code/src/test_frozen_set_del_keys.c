#include "../foundationallib.h"

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    // Test case 1: Deleting keys from an empty FrozenSet
    char **empty_keys = NULL;
    frozen_set_del_keys(empty_keys);
    assert(empty_keys == NULL);

    // Test case 2: Deleting keys from a FrozenSet with single key
    char **single_key = (char **)malloc(2 * sizeof(char *));
    single_key[0] = strdup("key1");
    single_key[1] = NULL;
    frozen_set_del_keys(single_key);
    assert(single_key[0] == NULL);
    assert(single_key == NULL);

    // Test case 3: Deleting keys from a FrozenSet with multiple keys
    char **multiple_keys = (char **)malloc(4 * sizeof(char *));
    multiple_keys[0] = strdup("key1");
    multiple_keys[1] = strdup("key2");
    multiple_keys[2] = strdup("key3");
    multiple_keys[3] = NULL;
    frozen_set_del_keys(multiple_keys);
    assert(multiple_keys[0] == NULL);
    assert(multiple_keys == NULL);

    printf("All test cases passed!\n");

    return 0;
}
