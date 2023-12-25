#include "../foundationallib.h"

#include <assert.h>
#include <stdio.h>

int equal_array_of_size_t_ptrs(const size_t **array, const size_t **array2, size_t size)
{
    if (array == NULL && array2 == NULL)
    {
        return 1;
    }
    if (array == NULL || array2 == NULL)
    {
        return 0;
    }
    for (size_t i = 0; i < size; i++)
    {
        if (array[i] != array2[i])
        {
            return 0;
        }
    }
    return 1;
}

void test_equal_array_of_size_t_ptrs()
{
    // Test case 1: Empty arrays
    const size_t *empty_array1[] = {NULL};
    const size_t *empty_array2[] = {NULL};
    assert(equal_array_of_size_t_ptrs(empty_array1, empty_array2, 0) == 1);

    // Test case 2: Arrays with same single element
    const size_t value = 42;
    const size_t *array1[] = {&value};
    const size_t *array2[] = {&value};
    assert(equal_array_of_size_t_ptrs(array1, array2, 1) == 1);

    // Test case 3: Arrays with different single elements
    const size_t different_value = 100;
    const size_t *array3[] = {&value};
    const size_t *array4[] = {&different_value};
    assert(equal_array_of_size_t_ptrs(array3, array4, 1) == 0);

    // Test case 4: Arrays with multiple elements
    const size_t value1 = 10, value2 = 20, value3 = 30;
    const size_t *array5[] = {&value1, &value2, &value3};
    const size_t *array6[] = {&value1, &value2, &value3};
    assert(equal_array_of_size_t_ptrs(array5, array6, 3) == 1);

    // Test case 5: Arrays with different multiple elements
    const size_t *array7[] = {&value1, &value2, &value3};
    const size_t *array8[] = {&value1, &value3, &value2};
    assert(equal_array_of_size_t_ptrs(array7, array8, 3) == 0);
}

int main()
{
    test_equal_array_of_size_t_ptrs();
    printf("All tests passed!\n");
    return 0;
}
