#include "../foundationallib.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to test
int string_array_uniq(const char **arr, size_t size, char ***output, size_t *output_size);

// Test cases
void test_empty_array()
{
    const char *input_array[] = {};
    char **result_array;
    size_t result_size;
    int status = string_array_uniq(input_array, 0, &result_array, &result_size);
    assert(status == 0);
    assert(result_size == 0);
    free(result_array);
}

void test_no_duplicates()
{
    const char *input_array[] = {"apple", "orange", "banana", "grape"};
    char **result_array;
    size_t result_size;
    int status = string_array_uniq(input_array, 4, &result_array, &result_size);
    assert(status == 0);
    assert(result_size == 4);
    assert(strcmp(result_array[0], "apple") == 0);
    assert(strcmp(result_array[1], "orange") == 0);
    assert(strcmp(result_array[2], "banana") == 0);
    assert(strcmp(result_array[3], "grape") == 0);
    free(result_array);
}

void test_with_duplicates()
{
    const char *input_array[] = {"apple", "orange", "banana", "apple", "grape"};
    char **result_array;
    size_t result_size;
    int status = string_array_uniq(input_array, 5, &result_array, &result_size);
    assert(status == 0);
    assert(result_size == 4);
    assert(strcmp(result_array[0], "apple") == 0);
    assert(strcmp(result_array[1], "orange") == 0);
    assert(strcmp(result_array[2], "banana") == 0);
    assert(strcmp(result_array[3], "grape") == 0);
    free(result_array);
}

// Test runner
int main()
{
    test_empty_array();
    test_no_duplicates();
    test_with_duplicates();
    printf("All tests passed successfully!\n");
    return 0;
}
