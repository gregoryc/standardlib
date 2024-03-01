#include "../foundationallib.h"

#include <assert.h>
#include <stdio.h>

FOUNDATIONAL_LIB_FUNC int is_array_lower(const char *arr[], size_t size)
{
    for (size_t i = 0; i < size; i++)
    {
        const char *str = arr[i];
        while (*str)
        {
            if (*str < 'a' || *str > 'z')
            {
                return 0;
            }
            str++;
        }
    }
    return 1;
}

int main()
{
    // Test case 1: All lowercase
    const char *arr1[] = {"hello", "world", "this", "is", "a", "test"};
    size_t size1 = sizeof(arr1) / sizeof(arr1[0]);
    assert(is_array_lower(arr1, size1) == 1);

    // Test case 2: Mixed case
    const char *arr2[] = {"hello", "World", "tHis", "IS", "a", "teSt"};
    size_t size2 = sizeof(arr2) / sizeof(arr2[0]);
    assert(is_array_lower(arr2, size2) == 0);

    // Test case 3: Empty array
    const char *arr3[] = {};
    size_t size3 = 0;
    assert(is_array_lower(arr3, size3) == 1);

    // Test case 4: Single empty string
    const char *arr4[] = {""};
    size_t size4 = 1;
    assert(is_array_lower(arr4, size4) == 1);

    // Test case 5: Single uppercase character
    const char *arr5[] = {"Hello"};
    size_t size5 = 1;
    assert(is_array_lower(arr5, size5) == 0);

    printf("All test cases passed!\n");
    return 0;
}
