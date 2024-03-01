#include "../foundationallib.h"
#include <assert.h>
#include <stdio.h>
#include <string.h>

// Test function for split
void test_split()
{
    const char *input = "Hello,World,How,Are,You?";
    const char *delimiter = ",";
    size_t max_times = 0;
    size_t output_size = 0;

    // Test Case 1: Normal Split
    char **result = split(input, &output_size, delimiter, max_times, 0);
    assert(output_size == 5);
    assert(strcmp(result[0], "Hello") == 0);
    assert(strcmp(result[1], "World") == 0);
    assert(strcmp(result[2], "How") == 0);
    assert(strcmp(result[3], "Are") == 0);
    assert(strcmp(result[4], "You?") == 0);

    // Test Case 2: Split with limited times
    max_times = 2;
    result = split(input, &output_size, delimiter, max_times, 0);
    assert(output_size == 3);
    assert(strcmp(result[0], "Hello") == 0);
    assert(strcmp(result[1], "World") == 0);
    assert(strcmp(result[2], "How,Are,You?") == 0);

    // Test Case 3: Keep delimiters in result
    result = split(input, &output_size, delimiter, max_times, 1);
    assert(output_size == 3);
    assert(strcmp(result[0], "Hello,") == 0);
    assert(strcmp(result[1], "World,") == 0);
    assert(strcmp(result[2], "How,Are,You?") == 0);

    // Test Case 4: Split with non-existent delimiter
    const char *non_existent_delim = "/";
    result = split(input, &output_size, non_existent_delim, max_times, 0);
    assert(output_size == 1);
    assert(strcmp(result[0], input) == 0);

    // Test Case 5: Input string is empty
    const char *empty_input = "";
    result = split(empty_input, &output_size, delimiter, max_times, 0);
    assert(output_size == 0);
    assert(result == NULL);

    // Free memory
    for (size_t i = 0; i < output_size; i++)
    {
        free(result[i]);
    }
    free(result);

    printf("All tests passed!\n");
}

int main()
{
    test_split();
    return 0;
}
