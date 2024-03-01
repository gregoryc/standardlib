#include "../foundationallib.h"
#include <assert.h>
#include <stdio.h>

FOUNDATIONAL_LIB_FUNC int equal_array_of_ulong_ptrs(const unsigned long **array, const unsigned long **array2, size_t size)
{
    for (size_t i = 0; i < size; i++)
    {
        if (*array[i] != *array2[i])
        {
            return 0;
        }
    }
    return 1;
}

void test_equal_array_of_ulong_ptrs()
{
    const unsigned long arr1[] = {1, 2, 3, 4, 5};
    const unsigned long arr2[] = {1, 2, 3, 4, 5};
    const unsigned long arr3[] = {1, 2, 3, 4, 10};
    const unsigned long arr4[] = {1, 2, 3, 4};
    const unsigned long *ptr1 = arr1;
    const unsigned long *ptr2 = arr2;
    const unsigned long *ptr3 = arr3;
    const unsigned long *ptr4 = arr4;

    assert(equal_array_of_ulong_ptrs(&ptr1, &ptr2, 5) == 1);
    assert(equal_array_of_ulong_ptrs(&ptr1, &ptr3, 5) == 0);
    assert(equal_array_of_ulong_ptrs(&ptr1, &ptr4, 4) == 1);
}

int main()
{
    test_equal_array_of_ulong_ptrs();
    printf("All tests passed!\n");
    return 0;
}
