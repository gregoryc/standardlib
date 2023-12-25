#include "../foundationallib.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// Test suite for set_del_keys function
void test_set_del_keys()
{
    // Test case 1: Deleting single key from an empty set
    Set set1 = {NULL, 0};
    set_del_keys(NULL);
    assert(set1.size == 0);

    // Test case 2: Deleting single key from a non-empty set
    char *key1 = "key1";
    Set set2 = {&key1, 1};
    set_del_keys(&key1);
    assert(set2.size == 0);

    // Test case 3: Deleting multiple keys from a non-empty set
    char *key2 = "key2";
    char *key3 = "key3";
    Set set3 = {&key1, 3};
    set_del_keys(&key2);
    set_del_keys(&key3);
    assert(set3.size == 1);

    printf("All test cases passed!\n");
}

int main()
{
    test_set_del_keys();
    return 0;
}
