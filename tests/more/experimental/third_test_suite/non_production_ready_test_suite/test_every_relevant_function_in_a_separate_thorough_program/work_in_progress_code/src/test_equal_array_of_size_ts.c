#include <assert.h>

#include "../foundationallib.h"
int main()
{
    // Test case 1: Arrays are equal
    {
        const size_t arr1[] = {1, 2, 3, 4, 5};
        const size_t arr2[] = {1, 2, 3, 4, 5};
        size_t size = 5;
        int result = equal_array_of_size_ts(arr1, arr2, size);
        assert(result == 1);
    }

    // Test case 2: Arrays are not equal
    {
        const size_t arr1[] = {1, 2, 3};
        const size_t arr2[] = {1, 2, 4};
        size_t size = 3;
        int result = equal_array_of_size_ts(arr1, arr2, size);
        assert(result == 0);
    }

    // Test case 3: Empty arrays
    {
        const size_t *arr1 = NULL;
        const size_t *arr2 = NULL;
        size_t size = 0;
        int result = equal_array_of_size_ts(arr1, arr2, size);
        assert(result == 1);
    }

    // Test case 4: Arrays of different sizes
    {
        const size_t arr1[] = {1, 2, 3};
        const size_t arr2[] = {1, 2};
        size_t size1 = 3;
        size_t size2 = 2;
        int result = equal_array_of_size_ts(arr1, arr2, size1);
        assert(result == 0);
    }

    // Test case 5: Large arrays
    {
        const size_t size = 10000;
        size_t *arr1 = (size_t *)malloc(size * sizeof(size_t));
        size_t *arr2 = (size_t *)malloc(size * sizeof(size_t));
        for (size_t i = 0; i < size; i++)
        {
            arr1[i] = i;
            arr2[i] = i;
        }
        int result = equal_array_of_size_ts(arr1, arr2, size);
        assert(result == 1);
        free(arr1);
        free(arr2);
    }

    printf("All test cases passed successfully!\n");

    return 0;
}
