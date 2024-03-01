#include "../foundationallib.h"
#include <assert.h>
#include <stdio.h>
int main()
{
    // Test case 1: Empty arrays
    const unsigned int *empty_array1[] = {};
    const unsigned int *empty_array2[] = {};
    assert(equal_array_of_uint_ptrs(empty_array1, empty_array2, 0) == 1);

    // Test case 2: Arrays with one element
    const unsigned int value1 = 42;
    const unsigned int value2 = 42;
    const unsigned int *array1[] = {&value1};
    const unsigned int *array2[] = {&value2};
    assert(equal_array_of_uint_ptrs(array1, array2, 1) == 1);

    // Test case 3: Arrays with multiple elements
    const unsigned int val1 = 10, val2 = 20, val3 = 30;
    const unsigned int *arr1[] = {&val1, &val2, &val3};
    const unsigned int *arr2[] = {&val1, &val2, &val3};
    assert(equal_array_of_uint_ptrs(arr1, arr2, 3) == 1);

    // Test case 4: Arrays with different elements
    const unsigned int v1 = 100, v2 = 200;
    const unsigned int *a1[] = {&v1};
    const unsigned int *a2[] = {&v2};
    assert(equal_array_of_uint_ptrs(a1, a2, 1) == 0);

    // Test case 5: Arrays with different number of elements
    assert(equal_array_of_uint_ptrs(arr1, arr2, 2) == 0);

    // All tests passed
    printf("All tests passed successfully!\n");

    return 0;
}
