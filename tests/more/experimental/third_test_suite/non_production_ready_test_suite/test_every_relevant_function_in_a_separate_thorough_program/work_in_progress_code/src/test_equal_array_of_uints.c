#include "../foundationallib.h"

#include <assert.h>
#include <stdio.h>

FOUNDATIONAL_LIB_FUNC int equal_array_of_uints(const unsigned int *array, const unsigned int *array2, size_t size)
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
    unsigned int arr1[] = {1, 2, 3, 4, 5};
    unsigned int arr2[] = {1, 2, 3, 4, 5};
    unsigned int arr3[] = {1, 2, 3, 4, 6};

    // Test case 1: Equal arrays
    assert(equal_array_of_uints(arr1, arr2, 5) == 1);

    // Test case 2: Non-equal arrays
    assert(equal_array_of_uints(arr1, arr3, 5) == 0);

    // Test case 3: Empty arrays
    assert(equal_array_of_uints(NULL, NULL, 0) == 1);

    printf("All test cases passed successfully.\n");
    return 0;
}
