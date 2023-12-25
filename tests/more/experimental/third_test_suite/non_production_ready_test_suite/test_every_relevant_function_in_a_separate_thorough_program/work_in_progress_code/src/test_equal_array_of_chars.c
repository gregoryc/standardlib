#include "../foundationallib.h"
#include <assert.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>

FOUNDATIONAL_LIB_FUNC int equal_array_of_chars(const char *array, const char *array2, size_t size)
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

void test_equal_array_of_chars()
{
    const char test1[] = {'a', 'b', 'c'};
    const char test2[] = {'a', 'b', 'c'};
    const char test3[] = {'a', 'b', 'd'};

    // Test equal arrays
    assert(equal_array_of_chars(test1, test2, 3) == 1);

    // Test unequal arrays
    assert(equal_array_of_chars(test1, test3, 3) == 0);

    // Test arrays of different sizes
    assert(equal_array_of_chars(test1, test2, 2) == 0);

    // Test empty arrays
    assert(equal_array_of_chars("", "", 0) == 1);

    // Test large arrays
    char largeArray1[100];
    char largeArray2[100];
    for (size_t i = 0; i < 100; i++)
    {
        largeArray1[i] = 'a';
        largeArray2[i] = 'a';
    }
    assert(equal_array_of_chars(largeArray1, largeArray2, 100) == 1);
}

int main()
{
    test_equal_array_of_chars();
    printf("All tests passed successfully!\n");
    return 0;
}
