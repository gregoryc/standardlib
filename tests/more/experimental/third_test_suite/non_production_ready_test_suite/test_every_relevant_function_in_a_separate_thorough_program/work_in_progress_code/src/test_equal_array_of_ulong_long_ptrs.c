#include "../foundationallib.h"
#include <assert.h>
#include <stdio.h>

FOUNDATIONAL_LIB_FUNC int equal_array_of_ulong_long_ptrs(const unsigned long long **array, const unsigned long long **array2, size_t size)
{
    for (size_t i = 0; i < size; i++)
    {
        if (*array[i] != *array2[i])
        {
            return 0;
        }
    }
    return 1;
}

int main()
{
    // Test case 1: Identical arrays
    const unsigned long long arr1[] = {1, 2, 3};
    const unsigned long long arr2[] = {1, 2, 3};

    const unsigned long long *ptr1[] = {arr1, arr1, arr1};
    const unsigned long long *ptr2[] = {arr2, arr2, arr2};

    assert(equal_array_of_ulong_long_ptrs(ptr1, ptr2, 3) == 1);

    // Test case 2: Different arrays
    const unsigned long long arr3[] = {4, 5, 6};
    const unsigned long long *ptr3[] = {arr1, arr1, arr3};

    assert(equal_array_of_ulong_long_ptrs(ptr1, ptr3, 3) == 0);

    // Test case 3: Empty arrays
    const unsigned long long *ptr4[] = {NULL, NULL, NULL};
    const unsigned long long *ptr5[] = {NULL, NULL, NULL};

    assert(equal_array_of_ulong_long_ptrs(ptr4, ptr5, 3) == 1);

    // Test case 4: Arrays with NULL values
    const unsigned long long arr4[] = {1, 2, 3};
    const unsigned long long *ptr6[] = {arr4, NULL, arr4};
    const unsigned long long *ptr7[] = {arr4, NULL, arr4};

    assert(equal_array_of_ulong_long_ptrs(ptr6, ptr7, 3) == 0);

    // Test case 5: Arrays with different sizes
    const unsigned long long *ptr8[] = {arr1, arr1};
    const unsigned long long *ptr9[] = {arr2, arr2, arr2};

    assert(equal_array_of_ulong_long_ptrs(ptr8, ptr9, 2) == 0);

    printf("All tests passed!\n");

    return 0;
}
