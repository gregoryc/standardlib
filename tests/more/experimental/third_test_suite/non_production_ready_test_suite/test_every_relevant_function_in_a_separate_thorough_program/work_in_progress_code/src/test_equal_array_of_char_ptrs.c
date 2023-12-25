#include "../foundationallib.h"
#include <assert.h>
#include <stdio.h>

// Function prototype
FOUNDATIONAL_LIB_FUNC int equal_array_of_char_ptrs(const char **array, const char **array2, size_t size);

// Test cases
void test_equal_arrays()
{
    const char *arr1[] = {"abc", "def", "ghi"};
    const char *arr2[] = {"abc", "def", "ghi"};
    assert(equal_array_of_char_ptrs(arr1, arr2, 3) == 1);
}

void test_unequal_arrays()
{
    const char *arr1[] = {"abc", "def", "ghi"};
    const char *arr2[] = {"abc", "xyz", "ghi"};
    assert(equal_array_of_char_ptrs(arr1, arr2, 3) == 0);
}

void test_empty_arrays()
{
    const char *arr1[] = {};
    const char *arr2[] = {};
    assert(equal_array_of_char_ptrs(arr1, arr2, 0) == 1);
}

void test_different_sizes()
{
    const char *arr1[] = {"abc", "def", "ghi"};
    const char *arr2[] = {"abc", "def", "ghi", "jkl"};
    assert(equal_array_of_char_ptrs(arr1, arr2, 3) == 0);
}

void test_null_arrays()
{
    const char *arr1[] = {"abc", "def", "ghi"};
    const char *arr2[] = {NULL, NULL, "ghi"};
    assert(equal_array_of_char_ptrs(arr1, arr2, 3) == 0);
}

int main()
{
    test_equal_arrays();
    test_unequal_arrays();
    test_empty_arrays();
    test_different_sizes();
    test_null_arrays();

    printf("All tests passed successfully!\n");

    return 0;
}
