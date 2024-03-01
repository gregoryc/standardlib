#include "../foundationallib.h"
#include <assert.h>
#include <stdio.h>

FOUNDATIONAL_LIB_FUNC int equal_array_of_ulong_longs(const unsigned long long *array, const unsigned long long *array2, size_t size)
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
    unsigned long long arr1[] = {1, 2, 3, 4, 5};
    unsigned long long arr2[] = {1, 2, 3, 4, 5};
    size_t size = sizeof(arr1) / sizeof(arr1[0]);
    assert(equal_array_of_ulong_longs(arr1, arr2, size) == 1);

    // Test case 2: Arrays are not equal
    unsigned long long arr3[] = {1, 2, 3, 4, 5};
    unsigned long long arr4[] = {1, 2, 3, 5, 5};
    size = sizeof(arr3) / sizeof(arr3[0]);
    assert(equal_array_of_ulong_longs(arr3, arr4, size) == 0);

    // Test case 3: Arrays are empty
    unsigned long long arr5[] = {};
    unsigned long long arr6[] = {};
    size = sizeof(arr5) / sizeof(arr5[0]);
    assert(equal_array_of_ulong_longs(arr5, arr6, size) == 1);

    // Test case 4: Arrays are of different sizes
    unsigned long long arr7[] = {1, 2, 3, 4, 5};
    unsigned long long arr8[] = {1, 2, 3, 4};
    size_t size1 = sizeof(arr7) / sizeof(arr7[0]);
    size_t size2 = sizeof(arr8) / sizeof(arr8[0]);
    assert(equal_array_of_ulong_longs(arr7, arr8, size1) == 0);

    printf("All test cases passed!\n");
    return 0;
}
