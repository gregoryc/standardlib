#include "../foundationallib.h"

#include <assert.h>
#include <stdio.h>

FOUNDATIONAL_LIB_FUNC int equal_array_of_long_longs(const long long *array, const long long *array2, size_t size)
{
    for (size_t i = 0; i < size; i++)
    {
        if (array[i] != array2[i])
        {
            return 0;
        }
    }
    return 1;
}

int main()
{
    // Test case 1: Arrays are equal
    long long arr1[] = {1, 2, 3, 4, 5};
    long long arr2[] = {1, 2, 3, 4, 5};
    assert(equal_array_of_long_longs(arr1, arr2, 5) == 1);

    // Test case 2: Arrays are not equal
    long long arr3[] = {1, 2, 3, 4, 5};
    long long arr4[] = {1, 2, 3, 5, 5};
    assert(equal_array_of_long_longs(arr3, arr4, 5) == 0);

    // Test case 3: Empty arrays
    long long arr5[] = {};
    long long arr6[] = {};
    assert(equal_array_of_long_longs(arr5, arr6, 0) == 1);

    // Test case 4: Arrays of different sizes
    long long arr7[] = {1, 2, 3};
    long long arr8[] = {1, 2, 3, 4};
    assert(equal_array_of_long_longs(arr7, arr8, 3) == 0);

    // Test case 5: Large arrays
    const size_t large_size = 1000000;
    long long large_arr1[large_size];
    long long large_arr2[large_size];
    for (size_t i = 0; i < large_size; i++)
    {
        large_arr1[i] = i;
        large_arr2[i] = i;
    }
    assert(equal_array_of_long_longs(large_arr1, large_arr2, large_size) == 1);

    printf("All test cases passed!\n");
    return 0;
}
