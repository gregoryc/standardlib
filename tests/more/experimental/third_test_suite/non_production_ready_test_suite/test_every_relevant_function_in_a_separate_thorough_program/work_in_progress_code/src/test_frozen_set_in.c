#include "../foundationallib.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define FrozenSet structure
struct FrozenSet
{
    const char **elements;
    size_t size;
};

// Initialize a new FrozenSet
struct FrozenSet *frozen_set_init(const char **elements, size_t size)
{
    struct FrozenSet *set = (struct FrozenSet *)malloc(sizeof(struct FrozenSet));
    set->elements = elements;
    set->size = size;
    return set;
}

// Free memory allocated for the FrozenSet
void frozen_set_free(struct FrozenSet *set) { free(set); }

// Function to check if a key is in the FrozenSet
int frozen_set_in(struct FrozenSet *set, const char *key)
{
    for (size_t i = 0; i < set->size; i++)
    {
        if (strcmp(set->elements[i], key) == 0)
        {
            return 1;
        }
    }
    return 0;
}

// Comprehensive test suite for frozen_set_in function
void test_frozen_set_in()
{
    const char *elements[] = {"apple", "banana", "cherry"};
    struct FrozenSet *set = frozen_set_init(elements, 3);

    // Test for keys present in the FrozenSet
    assert(frozen_set_in(set, "apple") == 1);
    assert(frozen_set_in(set, "banana") == 1);
    assert(frozen_set_in(set, "cherry") == 1);

    // Test for keys not present in the FrozenSet
    assert(frozen_set_in(set, "orange") == 0);
    assert(frozen_set_in(set, "grape") == 0);

    // Test for empty FrozenSet
    const char *empty_elements[] = {};
    struct FrozenSet *empty_set = frozen_set_init(empty_elements, 0);
    assert(frozen_set_in(empty_set, "any_key") == 0);

    // Free allocated memory
    frozen_set_free(set);
    frozen_set_free(empty_set);

    printf("All test cases passed successfully!\n");
}

int main()
{
    test_frozen_set_in();
    return 0;
}
