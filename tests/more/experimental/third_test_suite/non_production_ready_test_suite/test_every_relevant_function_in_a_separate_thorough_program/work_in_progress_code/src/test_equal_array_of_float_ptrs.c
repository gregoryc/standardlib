#include "../foundationallib.h"
#include <assert.h>
#include <stdio.h>

int equal_array_of_float_ptrs(const float **array, const float **array2, size_t size)
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

void test_equal_array_of_float_ptrs()
{
    const float a[3] = {1.0, 2.0, 3.0};
    const float b[3] = {1.0, 2.0, 3.0};
    const float c[3] = {1.0, 2.1, 3.0};

    const float *array1[3] = {&a[0], &a[1], &a[2]};
    const float *array2[3] = {&b[0], &b[1], &b[2]};
    const float *array3[3] = {&c[0], &c[1], &c[2]};

    assert(equal_array_of_float_ptrs(array1, array2, 3) == 1); // Same arrays should return 1
    assert(equal_array_of_float_ptrs(array1, array3, 3) == 0); // Different arrays should return 0
}

int main()
{
    test_equal_array_of_float_ptrs();
    printf("All tests passed successfully!\n");
    return 0;
}
