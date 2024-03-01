#include "../foundationallib.h"
#include <assert.h>
#include <stddef.h>

FOUNDATIONAL_LIB_FUNC int equal_array_of_double_ptrs(const double **array, const double **array2, size_t size)
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

int main()
{
    // Test case 1: Equal arrays
    const double a[] = {1.1, 2.2, 3.3};
    const double b[] = {1.1, 2.2, 3.3};
    const double *array1[] = {a, b};
    const double *array2[] = {a, b};
    assert(equal_array_of_double_ptrs(array1, array2, 2) == 1);

    // Test case 2: Unequal arrays
    const double c[] = {1.1, 2.2, 3.3};
    const double d[] = {4.4, 5.5, 6.6};
    const double *array3[] = {c, d};
    const double *array4[] = {c, c};
    assert(equal_array_of_double_ptrs(array3, array4, 2) == 0);

    // Test case 3: Empty arrays
    const double *emptyArray1[] = {};
    const double *emptyArray2[] = {};
    assert(equal_array_of_double_ptrs(emptyArray1, emptyArray2, 0) == 1);

    // Test case 4: Arrays with null pointers
    const double *nullArray1[] = {NULL, NULL, NULL};
    const double *nullArray2[] = {NULL, NULL, NULL};
    assert(equal_array_of_double_ptrs(nullArray1, nullArray2, 3) == 1);

    // Test case 5: Arrays with mixed content
    const double e = 2.2;
    const double *mixedArray1[] = {&e};
    const double *mixedArray2[] = {&e};
    assert(equal_array_of_double_ptrs(mixedArray1, mixedArray2, 1) == 1);

    return 0;
}
