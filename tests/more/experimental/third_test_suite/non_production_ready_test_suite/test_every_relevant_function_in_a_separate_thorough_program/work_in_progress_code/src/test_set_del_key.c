#include "../foundationallib.h"
#include <assert.h>
#include <stdio.h>

// Test cases
void test_set_del_key()
{
    struct Set set;
    // initialize the set with some keys

    // Test deleting a key that exists in the set
    const char *existing_key = "existing_key";
    set_del_key(&set, existing_key);
    // assert that the key has been deleted from the set
    assert(!has_key(&set, existing_key));

    // Test deleting a key that does not exist in the set
    const char *non_existing_key = "non_existing_key";
    set_del_key(&set, non_existing_key);
    // assert that the set remains unchanged
    assert(get_size(&set) == initial_size);
}

int main()
{
    test_set_del_key();
    printf("All tests passed!\n");
    return 0;
}
