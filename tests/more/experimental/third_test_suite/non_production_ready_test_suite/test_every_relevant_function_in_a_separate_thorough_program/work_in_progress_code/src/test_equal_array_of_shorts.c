#include "../foundationallib.h"
#include <assert.h>
#include <stdio.h>

#define TEST_CASES 5

// Function to test
int equal_array_of_shorts(const short *array, const short *array2, size_t size);

// Test cases
void test_equal_arrays()
{
    short arr1[] = {1, 2, 3, 4, 5};
    short arr2[] = {1, 2, 3, 4, 5};
    assert(equal_array_of_shorts(arr1, arr2, 5) == 1);
}

void test_unequal_arrays()
{
    short arr1[] = {1, 2, 3, 4, 5};
    short arr2[] = {1, 2, 3, 4, 6};
    assert(equal_array_of_shorts(arr1, arr2, 5) == 0);
}

void test_empty_arrays()
{
    short arr1[] = {};
    short arr2[] = {};
    assert(equal_array_of_shorts(arr1, arr2, 0) == 1);
}

void test_single_element_arrays()
{
    short arr1[] = {1};
    short arr2[] = {2};
    assert(equal_array_of_shorts(arr1, arr2, 1) == 0);
}

void test_null_arrays() { assert(equal_array_of_shorts(NULL, NULL, 0) == 1); }

// Run test cases
int main()
{
    test_equal_arrays();
    test_unequal_arrays();
    test_empty_arrays();
    test_single_element_arrays();
    test_null_arrays();

    printf("All test cases passed!\n");
    return 0;
}
