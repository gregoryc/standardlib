#include "../foundationallib.h"

#include <assert.h>
#include <stdio.h>

// Define if necessary

// Function to be tested
FOUNDATIONAL_LIB_FUNC int equal_array_of_int_ptrs(const int **array, const int **array2, size_t size)
{
    for (size_t i = 0; i < size; i++)
    {
        if (*array[i] != *array2[i])
        {
            return 0; // Arrays are not equal
        }
    }
    return 1; // Arrays are equal
}

// Test cases
int main()
{
    const int a1[] = {1, 2, 3};
    const int a2[] = {1, 2, 3};
    const int a3[] = {1, 2, 4};
    const int a4[] = {1, 2, 3};

    const int *p1[] = {a1, a2, a3};
    const int *p2[] = {a1, a2, a4};

    // Test case 1: Equal arrays
    assert(equal_array_of_int_ptrs(p1, p2, 3) == 1);

    // Test case 2: Unequal arrays
    assert(equal_array_of_int_ptrs(p1, p1, 3) == 1);

    // Test case 3: Null arrays
    assert(equal_array_of_int_ptrs(NULL, NULL, 0) == 1);

    // Test case 4: Single element arrays
    const int a5[] = {5};
    const int a6[] = {5};
    const int *p3[] = {a5};
    const int *p4[] = {a6};
    assert(equal_array_of_int_ptrs(p3, p4, 1) == 1);

    printf("All test cases passed!\n");

    return 0;
}
