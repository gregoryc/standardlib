#include "../foundationallib.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

struct FrozenSet
{
    int elements[100]; // Example data structure
    int size;          // Size of the set
};

size_t frozen_set_size(struct FrozenSet *set) { return set->size; }

int main()
{
    // Test 1: Set with size 0
    struct FrozenSet set1 = {{}, 0};
    assert(frozen_set_size(&set1) == 0);

    // Test 2: Set with size 5
    struct FrozenSet set2 = {{1, 2, 3, 4, 5}, 5};
    assert(frozen_set_size(&set2) == 5);

    // Test 3: Set with size 10
    struct FrozenSet set3 = {{1, 2, 3, 4, 5, 6, 7, 8, 9, 10}, 10};
    assert(frozen_set_size(&set3) == 10);

    // Test 4: Set with size 100 (maximum size)
    struct FrozenSet set4;
    for (int i = 0; i < 100; i++)
    {
        set4.elements[i] = i;
    }
    set4.size = 100;
    assert(frozen_set_size(&set4) == 100);

    // Test 5: Set with size 100000 (unrealistically large size)
    struct FrozenSet *set5 = (struct FrozenSet *)malloc(sizeof(struct FrozenSet));
    set5->size = 100000;
    assert(frozen_set_size(set5) == 100000);
    free(set5);

    printf("All tests passed!\n");

    return 0;
}
