#include "../foundationallib.h"

#include <assert.h>

int equal_array_of_uchar_ptrs(const unsigned char **array, const unsigned char **array2, size_t size)
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
    const unsigned char *arr1[] = {"foo", "bar", "baz"};
    const unsigned char *arr2[] = {"foo", "bar", "baz"};
    const unsigned char *arr3[] = {"foo", "bar", "qux"};

    // Test case 1: Arrays are equal
    assert(equal_array_of_uchar_ptrs(arr1, arr2, 3) == 1);

    // Test case 2: Arrays are not equal
    assert(equal_array_of_uchar_ptrs(arr1, arr3, 3) == 0);

    // Test case 3: Arrays with different sizes are not equal
    assert(equal_array_of_uchar_ptrs(arr1, arr2, 2) == 0);

    // Test case 4: Empty arrays are equal
    assert(equal_array_of_uchar_ptrs(NULL, NULL, 0) == 1);

    // Test case 5: Single-element arrays are equal
    const unsigned char *arr4[] = {"foo"};
    const unsigned char *arr5[] = {"foo"};
    assert(equal_array_of_uchar_ptrs(arr4, arr5, 1) == 1);

    // Test case 6: Single-element arrays are not equal
    const unsigned char *arr6[] = {"foo"};
    const unsigned char *arr7[] = {"bar"};
    assert(equal_array_of_uchar_ptrs(arr6, arr7, 1) == 0);

    return 0;
}
