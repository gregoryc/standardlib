#include "../foundationallib.h"

#define ASSERT_EQUAL_ARRAY(arr1, arr2, size, expected)                                                                                                                                                                                                                                                                                                                                                                                                                                                             \
    do                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                             \
    {                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                              \
        int result = equal_array_of_long_long_ptrs(arr1, arr2, size);                                                                                                                                                                                                                                                                                                                                                                                                                                              \
        if (result != expected)                                                                                                                                                                                                                                                                                                                                                                                                                                                                                    \
        {                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                          \
            fprintf(stderr, "Assertion failed: %s, line %d\n", __FILE__, __LINE__);                                                                                                                                                                                                                                                                                                                                                                                                                                \
            fprintf(stderr, "   Expected: %d\n", expected);                                                                                                                                                                                                                                                                                                                                                                                                                                                        \
            fprintf(stderr, "   Actual: %d\n", result);                                                                                                                                                                                                                                                                                                                                                                                                                                                            \
        }                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                          \
    } while (0)

int main()
{
    const long long *arr1[] = {(long long[]){1, 2, 3}, (long long[]){4, 5, 6}, (long long[]){7, 8, 9}};
    const long long *arr2[] = {(long long[]){1, 2, 3}, (long long[]){4, 5, 6}, (long long[]){7, 8, 9}};
    const long long *arr3[] = {(long long[]){9, 8, 7}, (long long[]){6, 5, 4}, (long long[]){3, 2, 1}};

    size_t size = sizeof(arr1) / sizeof(arr1[0]);

    ASSERT_EQUAL_ARRAY(arr1, arr2, size, 1); // Equal arrays should return 1
    ASSERT_EQUAL_ARRAY(arr1, arr3, size, 0); // Non-equal arrays should return 0

    return 0;
}