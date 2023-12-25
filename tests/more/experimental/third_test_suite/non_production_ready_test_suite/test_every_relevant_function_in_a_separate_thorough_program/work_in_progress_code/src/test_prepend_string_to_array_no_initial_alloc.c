#include "../foundationallib.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* The function to be tested */
FOUNDATIONAL_LIB_FUNC int prepend_string_to_array_no_initial_alloc(const char ***array, size_t *array_size, size_t *array_current_alloc_size, const char *string)
{
    // Implementation of the function
}

/* Test for adding a string to an empty array */
void test_prepend_to_empty_array()
{
    const char **array = NULL;
    size_t array_size = 0;
    size_t array_current_alloc_size = 0;
    const char *new_string = "test";

    prepend_string_to_array_no_initial_alloc(&array, &array_size, &array_current_alloc_size, new_string);

    assert(array_size == 1);
    assert(array_current_alloc_size >= 1);
    assert(strcmp(array[0], new_string) == 0);

    free(array);
}

/* Test for adding a string to a non-empty array */
void test_prepend_to_non_empty_array()
{
    const char *initial_array[] = {"existing1", "existing2"};
    const char **array = initial_array;
    size_t array_size = 2;
    size_t array_current_alloc_size = 2;
    const char *new_string = "test";

    prepend_string_to_array_no_initial_alloc(&array, &array_size, &array_current_alloc_size, new_string);

    assert(array_size == 3);
    assert(array_current_alloc_size >= 3);
    assert(strcmp(array[0], new_string) == 0);
    assert(strcmp(array[1], "existing1") == 0);
    assert(strcmp(array[2], "existing2") == 0);

    free(array);
}

int main()
{
    test_prepend_to_empty_array();
    test_prepend_to_non_empty_array();

    printf("All tests passed!\n");
    return 0;
}
