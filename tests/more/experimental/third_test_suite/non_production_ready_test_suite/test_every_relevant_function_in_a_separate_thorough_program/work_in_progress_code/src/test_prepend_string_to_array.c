#include "../foundationallib.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int prepend_string_to_array(const char ***array, size_t *array_size, size_t *array_current_alloc_size, const char *string)
{
    if (*array_size >= *array_current_alloc_size)
    {
        size_t new_size = *array_current_alloc_size == 0 ? 1 : *array_current_alloc_size * 2;
        const char **new_array = realloc(*array, new_size * sizeof(const char *));
        if (!new_array)
        {
            return -1; // Realloc failed
        }
        *array = new_array;
        *array_current_alloc_size = new_size;
    }

    memmove(*array + 1, *array, *array_size * sizeof(const char *)); // Shift existing elements
    (*array)[0] = strdup(string);
    (*array_size)++;

    return 0;
}

void test_prepend_string()
{
    const char **array = NULL;
    size_t array_size = 0;
    size_t array_current_alloc_size = 0;

    // Test prepending to an empty array
    prepend_string_to_array(&array, &array_size, &array_current_alloc_size, "first");
    assert(array_size == 1);
    assert(array_current_alloc_size >= 1);
    assert(strcmp(array[0], "first") == 0);

    // Test prepending to a non-empty array
    prepend_string_to_array(&array, &array_size, &array_current_alloc_size, "second");
    assert(array_size == 2);
    assert(array_current_alloc_size >= 2);
    assert(strcmp(array[0], "second") == 0);
    assert(strcmp(array[1], "first") == 0);

    // Test prepending to a full array
    prepend_string_to_array(&array, &array_size, &array_current_alloc_size, "third");
    assert(array_size == 3);
    assert(array_current_alloc_size >= 3);
    assert(strcmp(array[0], "third") == 0);
    assert(strcmp(array[1], "second") == 0);
    assert(strcmp(array[2], "first") == 0);

    // Clean up
    for (size_t i = 0; i < array_size; i++)
    {
        free((void *)array[i]);
    }
    free(array);
}

int main()
{
    test_prepend_string();
    printf("All tests passed successfully\n");
    return 0;
}
