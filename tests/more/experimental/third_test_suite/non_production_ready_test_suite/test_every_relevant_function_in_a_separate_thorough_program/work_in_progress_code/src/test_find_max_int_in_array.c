#include "../foundationallib.h"
#include <assert.h>
#include <stddef.h>

FOUNDATIONAL_LIB_FUNC int find_max_int_in_array(const int *array, size_t size)
{
    if (array == NULL || size == 0)
    {
        return 0; // Return 0 if the array is empty or NULL
    }

    int max = array[0];
    for (size_t i = 1; i < size; i++)
    {
        if (array[i] > max)
        {
            max = array[i]; // Update max if a larger element is found
        }
    }

    return max;
}

int main()
{
    // Test case 1: array with positive integers
    int test1[] = {5, 10, 3, 8, 15};
    assert(find_max_int_in_array(test1, 5) == 15);

    // Test case 2: array with negative integers
    int test2[] = {-5, -10, -3, -8, -15};
    assert(find_max_int_in_array(test2, 5) == -3);

    // Test case 3: array with a single element
    int test3[] = {100};
    assert(find_max_int_in_array(test3, 1) == 100);

    // Test case 4: array with all elements equal
    int test4[] = {7, 7, 7, 7};
    assert(find_max_int_in_array(test4, 4) == 7);

    // Test case 5: empty array
    int *test5 = NULL;
    assert(find_max_int_in_array(test5, 0) == 0);

    // Test case 6: array with one big number
    int test6[] = {9999999};
    assert(find_max_int_in_array(test6, 1) == 9999999);

    // Test case 7: array with one small number
    int test7[] = {-9999999};
    assert(find_max_int_in_array(test7, 1) == -9999999);

    return 0;
}
