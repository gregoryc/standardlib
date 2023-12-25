#include "../foundationallib.h"

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
void transform_function(void *value)
{
    int *val = (int *)value;
    *val = *val * 2;
}

int filter_function(void *value)
{
    int *val = (int *)value;
    return *val % 2 == 0;
}

void test_list_comprehension_multithreaded()
{
    size_t input_array[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    size_t array_size = sizeof(input_array) / sizeof(input_array[0]);
    size_t elem_size = sizeof(input_array[0]);
    size_t result_size;

    int expected_output[] = {4, 8, 12, 16, 20};
    void *result = list_comprehension_multithreaded(input_array, array_size, elem_size, transform_function, filter_function, &result_size, 2);

    assert(result_size == sizeof(expected_output) / sizeof(expected_output[0]));
    for (size_t i = 0; i < result_size; i++)
    {
        assert(*(int *)(result + (i * elem_size)) == expected_output[i]);
    }

    free(result);
}

int main()
{
    test_list_comprehension_multithreaded();
    return 0;
}
