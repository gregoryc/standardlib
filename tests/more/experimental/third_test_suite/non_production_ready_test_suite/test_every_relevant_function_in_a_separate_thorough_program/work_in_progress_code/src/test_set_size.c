#include "../foundationallib.h"
#include <assert.h>
#include <stdio.h>

struct Set
{
    int elements[100];
    size_t size;
};

typedef struct Set Set;

size_t set_size(Set *set) { return set->size; }

int main()
{
    Set set1 = {{1, 2, 3, 4, 5}, 5};
    Set set2 = {{}, 0};

    // Test case 1: Test with non-empty set
    assert(set_size(&set1) == 5);

    // Test case 2: Test with empty set
    assert(set_size(&set2) == 0);

    // Test case 3: Test with set of size 1
    Set set3 = {{10}, 1};
    assert(set_size(&set3) == 1);

    // Test case 4: Test with set of size 100
    Set set4;
    for (int i = 0; i < 100; i++)
    {
        set4.elements[i] = i + 1;
    }
    set4.size = 100;
    assert(set_size(&set4) == 100);

    printf("All test cases passed!\n");

    return 0;
}
