#include "../foundationallib.h"
#include <assert.h>
#include <stdio.h>
int main()
{
    char *keys1[] = {"key1", "key2", "key3"};
    char *keys2[] = {"a", "b", "c", "d", "e", "f", "g", "h", "i", "j"};

    // Test case 1: Delete keys from a frozen dictionary with 3 keys
    frozen_dict_del_keys(keys1);

    // Add assertion to check the result
    assert(keys1[0] == NULL);
    assert(keys1[1] == NULL);
    assert(keys1[2] == NULL);

    // Test case 2: Delete keys from a frozen dictionary with 10 keys
    frozen_dict_del_keys(keys2);

    // Add assertion to check the result
    for (int i = 0; i < 10; i++)
    {
        assert(keys2[i] == NULL);
    }

    printf("All test cases passed\n");
    return 0;
}
