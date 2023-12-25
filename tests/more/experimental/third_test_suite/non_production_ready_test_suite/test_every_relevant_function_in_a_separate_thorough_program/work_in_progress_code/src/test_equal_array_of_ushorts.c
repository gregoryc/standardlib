#include "../foundationallib.h"
#include <assert.h>
#include <stdio.h>

FOUNDATIONAL_LIB_FUNC int equal_array_of_ushorts(const unsigned short *array, const unsigned short *array2, size_t size)
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
    // Test 1: Arrays are equal
    {
        unsigned short array1[] = {1, 2, 3, 4};
        unsigned short array2[] = {1, 2, 3, 4};
        size_t size = 4;
        assert(equal_array_of_ushorts(array1, array2, size) == 1);
    }

    // Test 2: Arrays are not equal
    {
        unsigned short array1[] = {1, 2, 3, 4};
        unsigned short array2[] = {1, 2, 3, 5};
        size_t size = 4;
        assert(equal_array_of_ushorts(array1, array2, size) == 0);
    }

    // Test 3: Arrays of different sizes
    {
        unsigned short array1[] = {1, 2, 3};
        unsigned short array2[] = {1, 2, 3, 4, 5};
        size_t size1 = 3;
        size_t size2 = 5;
        assert(equal_array_of_ushorts(array1, array2, size1) == 0);
        assert(equal_array_of_ushorts(array1, array2, size2) == 0);
    }

    // Test 4: Empty arrays
    {
        unsigned short array1[] = {};
        unsigned short array2[] = {};
        size_t size = 0;
        assert(equal_array_of_ushorts(array1, array2, size) == 1);
    }

    printf("All tests passed!\n");
    return 0;
}
