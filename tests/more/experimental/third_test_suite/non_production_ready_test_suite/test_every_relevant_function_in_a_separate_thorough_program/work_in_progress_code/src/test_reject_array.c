#include "../foundationallib.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
// Define a condition function for testing
int is_even(const void *element)
{
    const int *value = (const int *)element;
    return *value % 2 != 0;
}

// Define the test suite
void test_reject_array()
{
    // Test case 1: Reject all elements
    {
        int source[] = {1, 3, 5};
        size_t source_size = sizeof(source) / sizeof(source[0]);
        size_t result_size;
        int *result = reject_array(source, source_size, sizeof(int), is_even, &result_size);
        assert(result_size == 0);
        free(result);
    }

    // Test case 2: Reject no elements
    {
        int source[] = {2, 4, 6};
        size_t source_size = sizeof(source) / sizeof(source[0]);
        size_t result_size;
        int *result = reject_array(source, source_size, sizeof(int), is_even, &result_size);
        assert(result_size == source_size);
        for (size_t i = 0; i < result_size; i++)
        {
            assert(result[i] == source[i]);
        }
        free(result);
    }

    // Additional test cases can be added here
}

int main()
{
    test_reject_array();
    printf("All tests pass!\n");
    return 0;
}
