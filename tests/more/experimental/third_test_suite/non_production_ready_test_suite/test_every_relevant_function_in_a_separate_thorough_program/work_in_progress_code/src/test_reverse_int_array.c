#include "../foundationallib.h"
#include <assert.h>
#include <stdio.h>

// Define the function prototype
void reverse_int_array(int *array, size_t size);

// Test cases
void test_reverse_int_array_empty()
{
    int array[] = {};
    reverse_int_array(array, 0);
    assert(1); // No assertion to check for empty array
}

void test_reverse_int_array_single()
{
    int array[] = {5};
    reverse_int_array(array, 1);
    assert(array[0] == 5);
}

void test_reverse_int_array_even()
{
    int array[] = {1, 2, 3, 4};
    reverse_int_array(array, 4);
    assert(array[0] == 4);
    assert(array[1] == 3);
    assert(array[2] == 2);
    assert(array[3] == 1);
}

void test_reverse_int_array_odd()
{
    int array[] = {1, 2, 3, 4, 5};
    reverse_int_array(array, 5);
    assert(array[0] == 5);
    assert(array[1] == 4);
    assert(array[2] == 3);
    assert(array[3] == 2);
    assert(array[4] == 1);
}

void run_tests()
{
    test_reverse_int_array_empty();
    test_reverse_int_array_single();
    test_reverse_int_array_even();
    test_reverse_int_array_odd();

    printf("All tests passed!\n");
}

int main()
{
    run_tests();
    return 0;
}
