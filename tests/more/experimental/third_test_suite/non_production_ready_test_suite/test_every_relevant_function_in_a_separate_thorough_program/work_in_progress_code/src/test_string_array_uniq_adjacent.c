#include "../foundationallib.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void test_string_array_uniq_adjacent()
{
    const char *input_array[] = {"apple", "orange", "orange", "banana", "banana", "apple", "grape"};
    char **result_array;
    size_t result_size;
    int status;

    // Test case 1: Full duplicate array
    const char *test1_input[] = {"hello", "hello", "hello"};
    status = string_array_uniq_adjacent(test1_input, 3, &result_array, &result_size);
    assert(status == 0);
    assert(result_size == 1);
    assert(strcmp(result_array[0], "hello") == 0);
    free(result_array[0]);
    free(result_array);

    // Test case 2: No duplicates
    const char *test2_input[] = {"apple", "banana", "orange"};
    status = string_array_uniq_adjacent(test2_input, 3, &result_array, &result_size);
    assert(status == 0);
    assert(result_size == 3);
    for (size_t i = 0; i < result_size; i++)
    {
        assert(strcmp(test2_input[i], result_array[i]) == 0);
        free(result_array[i]);
    }
    free(result_array);

    // Test case 3: Mixed array
    const char *test3_input[] = {"apple", "apple", "banana", "orange", "orange", "grape", "grape"};
    status = string_array_uniq_adjacent(test3_input, 7, &result_array, &result_size);
    assert(status == 0);
    assert(result_size == 4);
    const char *expected_result[4] = {"apple", "banana", "orange", "grape"};
    for (size_t i = 0; i < result_size; i++)
    {
        assert(strcmp(expected_result[i], result_array[i]) == 0);
        free(result_array[i]);
    }
    free(result_array);
}

int main()
{
    test_string_array_uniq_adjacent();
    printf("All tests passed!\n");
    return 0;
}
