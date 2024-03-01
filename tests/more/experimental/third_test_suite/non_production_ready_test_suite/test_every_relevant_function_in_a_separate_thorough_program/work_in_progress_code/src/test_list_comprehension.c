#include "../foundationallib.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the function signature for list_comprehension
typedef void *(*LIST_COMP_FUNC)(const void *, size_t, size_t, void (*)(void *), int (*)(void *), size_t *);

// Function to test list_comprehension with integers
void test_list_comprehension_integers(LIST_COMP_FUNC func)
{
    size_t input[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    size_t input_size = sizeof(input) / sizeof(input[0]);

    void square_transform(void *value)
    {
        size_t *num = (size_t *)value;
        *num = (*num) * (*num);
    }

    int odd_filter(void *value)
    {
        size_t *num = (size_t *)value;
        return (*num) % 2 != 0;
    }

    size_t result_size;
    size_t *result = (size_t *)func(input, input_size, sizeof(size_t), square_transform, odd_filter, &result_size);

    size_t expected_result[] = {1, 9, 25, 49, 81};
    size_t expected_result_size = sizeof(expected_result) / sizeof(expected_result[0]);

    assert(result_size == expected_result_size);
    for (int i = 0; i < result_size; i++)
    {
        assert(result[i] == expected_result[i]);
    }

    free(result);
}

// Function to test list_comprehension with strings
void test_list_comprehension_strings(LIST_COMP_FUNC func)
{
    const char *words[] = {"apple", "banana", "orange", "grape", "kiwi"};
    size_t words_size = sizeof(words) / sizeof(words[0]);

    void uppercase_transform(void *value)
    {
        char **str = (char **)value;
        for (int i = 0; (*str)[i]; ++i)
        {
            (*str)[i] = toupper((*str)[i]);
        }
    }

    int exclude_a_filter(void *value)
    {
        char **str = (char **)value;
        return (*str)[0] != 'a' && (*str)[0] != 'A';
    }

    size_t result_size;
    char **result = (char **)func(words, words_size, sizeof(char *), uppercase_transform, exclude_a_filter, &result_size);

    const char *expected_result[] = {"ORANGE", "GRAPE", "KIWI"};
    size_t expected_result_size = sizeof(expected_result) / sizeof(expected_result[0]);

    assert(result_size == expected_result_size);
    for (int i = 0; i < result_size; i++)
    {
        assert(strcmp(result[i], expected_result[i]) == 0);
    }

    for (int i = 0; i < result_size; i++)
    {
        free(result[i]);
    }
    free(result);
}

int main()
{
    // Test list_comprehension with integers
    printf("Testing list_comprehension with integers...\n");
    test_list_comprehension_integers(list_comprehension);

    // Test list_comprehension with strings
    printf("Testing list_comprehension with strings...\n");
    test_list_comprehension_strings(list_comprehension);

    printf("All tests passed successfully.\n");
    return 0;
}
