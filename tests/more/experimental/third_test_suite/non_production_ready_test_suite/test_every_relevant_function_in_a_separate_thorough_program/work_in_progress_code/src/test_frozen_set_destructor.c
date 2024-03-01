#include "../foundationallib.h"
#include <assert.h>
#include <stdio.h>

// Define the Set and SetKey structures
struct SetKey
{
    const char *key;
    struct SetKey *next;
};

struct Set
{
    struct SetKey **table;
    size_t capacity;
};

// Define the FOUNDATIONAL_LIB_FUNC macro

// Include the set_in function
#include "set_in.c"

// Test the set_in function
void test_set_in()
{
    // Create a Set
    struct Set set;
    set.capacity = 10;
    set.table = calloc(set.capacity, sizeof(struct SetKey *));

    // Add some keys to the Set
    struct SetKey key1 = {"key1", NULL};
    set.table[0] = &key1;

    struct SetKey key2 = {"key2", NULL};
    set.table[1] = &key2;

    // Test for present key
    assert(set_in(&set, "key1") == 1);

    // Test for absent key
    assert(set_in(&set, "key3") == 0);

    // Free the memory used by the Set
    free(set.table);
}

int main()
{
    test_set_in();

    printf("All tests passed.\n");

    return 0;
}
