#include "../foundationallib.h"
#include <assert.h>
FOUNDATIONAL_LIB_FUNC int calculate_sum_in_int_array(const int *array, size_t size)
{
    int sum = 0;
    for (size_t i = 0; i < size; i++)
    {
        sum += array[i];
    }
    return sum;
}

int main()
{
    // Test Case 1: Empty array
    const int arr1[] = {};
    assert(calculate_sum_in_int_array(arr1, 0) == 0);

    // Test Case 2: Array with one element
    const int arr2[] = {5};
    assert(calculate_sum_in_int_array(arr2, 1) == 5);

    // Test Case 3: Array with positive integers
    const int arr3[] = {1, 2, 3, 4, 5};
    assert(calculate_sum_in_int_array(arr3, 5) == 15);

    // Test Case 4: Array with negative integers
    const int arr4[] = {-1, -2, -3, -4, -5};
    assert(calculate_sum_in_int_array(arr4, 5) == -15);

    // Test Case 5: Array with mixed positive and negative integers
    const int arr5[] = {1, -2, 3, -4, 5};
    assert(calculate_sum_in_int_array(arr5, 5) == 3);

    // Test Case 6: Array with maximum size
    const int max_size = 1000000; // Maximum size for array
    int arr6[max_size];
    for (int i = 0; i < max_size; i++)
    {
        arr6[i] = 1;
    }
    assert(calculate_sum_in_int_array(arr6, max_size) == max_size);

    printf("All test cases passed successfully!\n");

    return 0;
}
