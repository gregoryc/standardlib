#include "../foundationallib.h"

#include <assert.h>
#include <stdio.h>

FOUNDATIONAL_LIB_FUNC int equal_array_of_ulongs(const unsigned long *array, const unsigned long *array2, size_t size)
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
    // Test cases
    unsigned long arr1[] = {1, 2, 3, 4, 5};
    unsigned long arr2[] = {1, 2, 3, 4, 5};
    unsigned long arr3[] = {1, 2, 3, 4, 6};
    unsigned long arr4[] = {1, 2, 3, 4};
    unsigned long arr5[] = {1, 2, 3, 4, 5, 6};
    unsigned long arr6[] = {0, 0, 0, 0, 0};

    // Test cases using assert.h
    assert(equal_array_of_ulongs(arr1, arr2, 5) == 1); // Identical arrays
    assert(equal_array_of_ulongs(arr1, arr3, 5) == 0); // Arrays with one different element
    assert(equal_array_of_ulongs(arr1, arr4, 4) == 1); // Arrays with different size
    assert(equal_array_of_ulongs(arr1, arr5, 6) == 0); // Arrays with different size
    assert(equal_array_of_ulongs(arr1, arr6, 5) == 0); // Arrays with all elements as 0

    printf("All tests passed!\n");
    return 0;
}
