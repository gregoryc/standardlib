#include "../foundationallib.h"
#include <assert.h>

int main()
{
    // Create a new Set instance
    struct Set *set = create_set();

    // Test case 1: Reserving additional space for 0 new elements
    assert(set_reserve_more(set, 0) == 0);

    // Test case 2: Reserving additional space for 10 new elements
    assert(set_reserve_more(set, 10) == 0);

    // Test case 3: Reserving additional space for a large number of new elements
    assert(set_reserve_more(set, 100000) == 0);

    // Test case 4: Reserving additional space for a negative number of new elements
    assert(set_reserve_more(set, -5) == -1);

    // Test case 5: Reserving additional space for a very large number of new elements
    assert(set_reserve_more(set, 1000000000) == 0);

    // Test case 6: Reserving additional space for the maximum possible number of new elements
    assert(set_reserve_more(set, SIZE_MAX) == 0);

    // Test case 7: Reserving additional space for an excessively large number of new elements
    // (Assuming SIZE_MAX is the maximum value for size_t)
    assert(set_reserve_more(set, SIZE_MAX + 1) == -1);

    // Clean up and free the Set instance
    destroy_set(set);

    printf("All tests passed!\n");
    return 0;
}
