#include "../foundationallib.h"
#include <assert.h>
#include <stdio.h>
void test_equal_arrays()
{
    float arr1[] = {1.0, 2.0, 3.0};
    float arr2[] = {1.0, 2.0, 3.0};
    assert(equal_array_of_floats(arr1, arr2, 3) == 1);
}

void test_unequal_arrays()
{
    float arr1[] = {1.0, 2.0, 3.0};
    float arr2[] = {3.0, 2.0, 1.0};
    assert(equal_array_of_floats(arr1, arr2, 3) == 0);
}

void test_empty_arrays()
{
    float arr1[] = {};
    float arr2[] = {};
    assert(equal_array_of_floats(arr1, arr2, 0) == 1);
}

void test_large_arrays()
{
    float arr1[1000];
    float arr2[1000];
    for (int i = 0; i < 1000; i++)
    {
        arr1[i] = i;
        arr2[i] = i;
    }
    assert(equal_array_of_floats(arr1, arr2, 1000) == 1);
}

int main()
{
    test_equal_arrays();
    test_unequal_arrays();
    test_empty_arrays();
    test_large_arrays();
    printf("All tests passed successfully!\n");
    return 0;
}
