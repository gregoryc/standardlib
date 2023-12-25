#include "../foundationallib.h"
#include <assert.h>
#include <stdio.h>

// Define the filter_int function
typedef size_t (*filter_int_fn)(int *, size_t, int *, int (*)(int));

// Define the condition function
int is_even_condition(int x) { return (x % 2 == 0); }

// Test cases
void test_filter_int(filter_int_fn filter_int)
{
    int source[] = {1, 2, 3, 4, 5};
    int destination[5];

    // Test case 1: Test with even condition
    size_t num_filtered = filter_int(source, 5, destination, is_even_condition);
    assert(num_filtered == 2);
    assert(destination[0] == 2);
    assert(destination[1] == 4);

    // Test case 2: Test with odd condition
    size_t num_filtered_odd = filter_int(source, 5, destination, [](int x) { return (x % 2 != 0); });
    assert(num_filtered_odd == 3);
    assert(destination[0] == 1);
    assert(destination[1] == 3);
    assert(destination[2] == 5);
}

int main()
{
    // Run the test cases
    test_filter_int(filter_int);

    printf("All test cases passed!\n");

    return 0;
}
