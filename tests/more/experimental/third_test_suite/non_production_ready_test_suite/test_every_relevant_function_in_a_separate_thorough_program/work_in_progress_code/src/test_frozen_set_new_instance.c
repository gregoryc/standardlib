#include "../foundationallib.h"
#include <assert.h>
#include <stdarg.h>

void test_frozen_set_new_instance()
{
    // Test creating an empty FrozenSet
    struct FrozenSet *empty_set = frozen_set_new_instance(0);
    assert(empty_set->size == 0);

    // Test creating a FrozenSet with single element
    struct FrozenSet *single_set = frozen_set_new_instance(1, "key1");
    assert(single_set->size == 1);
    // Check if the single element is "key1"

    // Test creating a FrozenSet with multiple elements
    struct FrozenSet *multiple_set = frozen_set_new_instance(3, "key1", "key2", "key3");
    assert(multiple_set->size == 3);
    // Check if all the elements are "key1", "key2", "key3"
}

int main()
{
    test_frozen_set_new_instance();
    return 0;
}
