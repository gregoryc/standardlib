#include "../foundationallib.h"

#define CTEST_MAIN
#define CTEST_SEGFAULT

#include <assert.h>
#include <stddef.h>

int equal_array_of_uchars(const unsigned char *array, const unsigned char *array2, size_t size)
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
    unsigned char arr1[] = {1, 2, 3};
    unsigned char arr2[] = {1, 2, 3};
    size_t size1 = 3;
    assert(equal_array_of_uchars(arr1, arr2, size1) == 1);

    // Test case 2: Arrays are not equal
    unsigned char arr3[] = {1, 2, 3};
    unsigned char arr4[] = {1, 2, 4};
    size_t size2 = 3;
    assert(equal_array_of_uchars(arr3, arr4, size2) == 0);

    // Test case 3: Arrays are of different sizes
    unsigned char arr5[] = {1, 2, 3};
    unsigned char arr6[] = {1, 2, 3, 4};
    size_t size3 = 3;
    assert(equal_array_of_uchars(arr5, arr6, size3) == 0);

    // Test case 4: Empty arrays
    unsigned char arr7[] = {};
    unsigned char arr8[] = {};
    size_t size4 = 0;
    assert(equal_array_of_uchars(arr7, arr8, size4) == 1);

    // Test case 5: Large arrays
    unsigned char arr9[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    unsigned char arr10[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    size_t size5 = 10;
    assert(equal_array_of_uchars(arr9, arr10, size5) == 1);

    // Test case 6: Large arrays with different elements
    unsigned char arr11[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    unsigned char arr12[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 11};
    size_t size6 = 10;
    assert(equal_array_of_uchars(arr11, arr12, size6) == 0);

    return 0;
}
