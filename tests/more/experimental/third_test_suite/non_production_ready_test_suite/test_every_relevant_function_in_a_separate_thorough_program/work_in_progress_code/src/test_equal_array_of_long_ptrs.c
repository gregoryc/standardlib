#include "../foundationallib.h"

#include <assert.h>
#include <stddef.h>

// Foundational library function to be tested
int equal_array_of_long_ptrs(const long **array, const long **array2, size_t size);

// Test cases
void test_equal_arrays()
{
    const long arr1[] = {1, 2, 3};
    const long arr2[] = {1, 2, 3};
    const long *ptr1[] = {arr1, arr1, arr1};
    const long *ptr2[] = {arr2, arr2, arr2};

    assert(equal_array_of_long_ptrs(ptr1, ptr2, 3) == 1);
}

void test_unequal_arrays()
{
    const long arr1[] = {1, 2, 3};
    const long arr2[] = {3, 2, 1};
    const long *ptr1[] = {arr1, arr1, arr1};
    const long *ptr2[] = {arr2, arr2, arr2};

    assert(equal_array_of_long_ptrs(ptr1, ptr2, 3) == 0);
}

void test_empty_arrays()
{
    const long *ptr1[] = {};
    const long *ptr2[] = {};

    assert(equal_array_of_long_ptrs(ptr1, ptr2, 0) == 1);
}

void test_null_arrays()
{
    const long *ptr1[] = {NULL, NULL};
    const long *ptr2[] = {NULL, NULL};

    assert(equal_array_of_long_ptrs(ptr1, ptr2, 2) == 1);
}

void test_null_element()
{
    const long arr1[] = {1, 2, 3};
    const long *ptr1[] = {arr1, arr1, NULL};
    const long *ptr2[] = {arr1, arr1, NULL};

    assert(equal_array_of_long_ptrs(ptr1, ptr2, 3) == 1);
}

// Main function to run all test cases
int main()
{
    test_equal_arrays();
    test_unequal_arrays();
    test_empty_arrays();
    test_null_arrays();
    test_null_element();

    printf("All tests passed!\n");
    return 0;
}
