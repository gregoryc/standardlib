#include "../foundationallib.h"
#include <assert.h>
#include <stddef.h>
#include <stdio.h>

FOUNDATIONAL_LIB_FUNC int equal_array_of_longs(const long *array, const long *array2, size_t size)
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
    long array1[] = {1, 2, 3, 4};
    long array2[] = {1, 2, 3, 4};
    assert(equal_array_of_longs(array1, array2, 4) == 1);

    // Test case 2: Arrays are not equal
    long array3[] = {1, 2, 3, 4};
    long array4[] = {1, 2, 3, 5};
    assert(equal_array_of_longs(array3, array4, 4) == 0);

    // Test case 3: Arrays are empty
    long *array5 = NULL;
    long *array6 = NULL;
    assert(equal_array_of_longs(array5, array6, 0) == 1);

    // Test case 4: Arrays have one element and are equal
    long array7[] = {1000};
    long array8[] = {1000};
    assert(equal_array_of_longs(array7, array8, 1) == 1);

    // Test case 5: Arrays have one element and are not equal
    long array9[] = {1000};
    long array10[] = {999};
    assert(equal_array_of_longs(array9, array10, 1) == 0);

    printf("All tests passed successfully!\n");
    return 0;
}
