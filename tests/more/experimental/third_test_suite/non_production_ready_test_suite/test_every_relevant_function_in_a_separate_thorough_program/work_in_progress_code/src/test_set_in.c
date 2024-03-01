#include "../foundationallib.h"
#include <assert.h>
#include <stdlib.h>
#include <string.h>
// Function to check if a key is present in the Set
int set_in(struct Set *set, const char *key)
{
    for (int i = 0; i < set->size; i++)
    {
        if (strcmp(set->keys[i], key) == 0)
        {
            return 1; // Key is present
        }
    }
    return 0; // Key is not present
}

int main()
{
    // Create a new Set
    struct Set *test_set = create_set();

    // Test case 1: Set is empty
    assert(set_in(test_set, "test1") == 0);

    // Add keys to the set for further tests
    add_to_set(test_set, "test1");
    add_to_set(test_set, "test2");
    add_to_set(test_set, "test3");

    // Test case 2: Key present in the set
    assert(set_in(test_set, "test2") == 1);

    // Test case 3: Key not present in the set
    assert(set_in(test_set, "test4") == 0);

    // Test case 4: Set is full
    struct Set *full_set = create_set();
    for (int i = 0; i < 100; i++)
    {
        char key[10];
        snprintf(key, 10, "key%d", i);
        add_to_set(full_set, key);
    }
    assert(set_in(full_set, "key99") == 1);
    assert(set_in(full_set, "key100") == 0);

    // All tests passed
    printf("All tests passed!\n");

    return 0;
}
