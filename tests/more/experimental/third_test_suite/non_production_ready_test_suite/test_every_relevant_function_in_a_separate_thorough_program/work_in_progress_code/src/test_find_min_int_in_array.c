#include "../foundationallib.h"

#include <assert.h>
#include <stddef.h>
#include <stdio.h>
int main()
{
    // Test case 1: Minimum at the beginning of the array
    {
        int arr[] = {1, 2, 3, 4, 5};
        size_t size = sizeof(arr) / sizeof(arr[0]);
        int min = find_min_int_in_array(arr, size);
        assert(min == 1);
    }

    // Test case 2: Minimum at the end of the array
    {
        int arr[] = {5, 4, 3, 2, 1};
        size_t size = sizeof(arr) / sizeof(arr[0]);
        int min = find_min_int_in_array(arr, size);
        assert(min == 1);
    }

    // Test case 3: Minimum in the middle of the array
    {
        int arr[] = {5, 4, 1, 2, 3};
        size_t size = sizeof(arr) / sizeof(arr[0]);
        int min = find_min_int_in_array(arr, size);
        assert(min == 1);
    }

    // Test case 4: Array with only one element
    {
        int arr[] = {5};
        size_t size = sizeof(arr) / sizeof(arr[0]);
        int min = find_min_int_in_array(arr, size);
        assert(min == 5);
    }

    // Test case 5: Array with negative numbers
    {
        int arr[] = {-5, -3, -1, -2, -4};
        size_t size = sizeof(arr) / sizeof(arr[0]);
        int min = find_min_int_in_array(arr, size);
        assert(min == -5);
    }

    // Test case 6: Array with duplicate minimum elements
    {
        int arr[] = {3, 1, 2, 1, 4};
        size_t size = sizeof(arr) / sizeof(arr[0]);
        int min = find_min_int_in_array(arr, size);
        assert(min == 1);
    }

    printf("All test cases passed!\n");
    return 0;
}
