#include "../foundationallib.h"

#include <assert.h>
#include <stdio.h>

size_t filter(void *source, size_t source_size, size_t elem_size, void *destination, size_t dest_size, int (*condition)(void *))
{
    size_t num_filtered = 0;
    for (size_t i = 0; i < source_size; i++)
    {
        if (condition((char *)source + (i * elem_size)))
        {
            if (num_filtered < dest_size)
            {
                memcpy((char *)destination + (num_filtered * elem_size), (char *)source + (i * elem_size), elem_size);
                num_filtered++;
            }
            else
            {
                break; // Destination array full
            }
        }
    }
    return num_filtered;
}

int main()
{
    // Test case 1: source array is empty
    int source_empty[] = {};
    int destination_empty[5];
    size_t num_filtered_empty = filter(source_empty, 0, sizeof(int), destination_empty, 5, is_even_condition);
    assert(num_filtered_empty == 0);

    // Test case 2: destination array is empty
    int source_not_empty[] = {1, 2, 3, 4, 5};
    int destination_full[1];
    size_t num_filtered_full = filter(source_not_empty, 5, sizeof(int), destination_full, 0, is_even_condition);
    assert(num_filtered_full == 0);

    // Test case 3: all elements satisfy the condition
    int source_all_even[] = {2, 4, 6, 8, 10};
    int destination_all_even[5];
    size_t num_filtered_all_even = filter(source_all_even, 5, sizeof(int), destination_all_even, 5, is_even_condition);
    assert(num_filtered_all_even == 5);
    for (size_t i = 0; i < num_filtered_all_even; i++)
    {
        assert(*(int *)((char *)destination_all_even + (i * sizeof(int))) == source_all_even[i]);
    }

    // Test case 4: no elements satisfy the condition
    int source_none_even[] = {1, 3, 5, 7, 9};
    int destination_none_even[5];
    size_t num_filtered_none_even = filter(source_none_even, 5, sizeof(int), destination_none_even, 5, is_even_condition);
    assert(num_filtered_none_even == 0);

    printf("All test cases passed!\n");
    return 0;
}
