#include "../foundationallib.h"
#include <assert.h>
#include <stddef.h>

// Function to test
int equal_array_of_ints(const int *array, const int *array2, size_t size)
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
    // Test case 1: Arrays with same elements
    int arr1[] = {1, 2, 3, 4, 5};
    int arr2[] = {1, 2, 3, 4, 5};
    assert(equal_array_of_ints(arr1, arr2, 5) == 1);

    // Test case 2: Arrays with different elements
    int arr3[] = {1, 2, 3, 4, 5};
    int arr4[] = {1, 3, 2, 4, 5};
    assert(equal_array_of_ints(arr3, arr4, 5) == 0);

    // Test case 3: Arrays with one element
    int arr5[] = {10};
    int arr6[] = {10};
    assert(equal_array_of_ints(arr5, arr6, 1) == 1);

    // Test case 4: Arrays with different sizes
    int arr7[] = {1, 1, 1};
    int arr8[] = {1, 1, 1, 1};
    assert(equal_array_of_ints(arr7, arr8, 3) == 0);

    // Additional corner cases
    // Test case 5: Empty arrays
    assert(equal_array_of_ints(NULL, NULL, 0) == 1);

    // Test case 6: Large arrays
    int largeArr1[1000], largeArr2[1000];
    for (size_t i = 0; i < 1000; i++)
    {
        largeArr1[i] = i;
        largeArr2[i] = i;
    }
    assert(equal_array_of_ints(largeArr1, largeArr2, 1000) == 1);

    // All tests passed
    return 0;
}
