#include "../foundationallib.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

void map(void *array, size_t size, size_t elem_size, void (*transform)(void *));

void increment_transform(void *element) { (*(int *)element)++; }

void double_transform(void *element) { (*(double *)element) *= 2; }

void test_map()
{
    int int_array[] = {1, 2, 3, 4, 5};
    double double_array[] = {1.5, 2.5, 3.5, 4.5, 5.5};
    const size_t int_size = sizeof(int);
    const size_t double_size = sizeof(double);

    // Test with increment_transform on int_array
    map(int_array, 5, int_size, increment_transform);
    assert(int_array[0] == 2);
    assert(int_array[1] == 3);
    assert(int_array[2] == 4);
    assert(int_array[3] == 5);
    assert(int_array[4] == 6);

    // Test with double_transform on double_array
    map(double_array, 5, double_size, double_transform);
    assert(double_array[0] == 3.0);
    assert(double_array[1] == 5.0);
    assert(double_array[2] == 7.0);
    assert(double_array[3] == 9.0);
    assert(double_array[4] == 11.0);

    // Test with increment_transform on empty array
    int *empty_array = NULL;
    map(empty_array, 0, int_size, increment_transform);
    assert(empty_array == NULL);
}

int main()
{
    test_map();
    printf("All tests passed successfully!\n");
    return 0;
}
