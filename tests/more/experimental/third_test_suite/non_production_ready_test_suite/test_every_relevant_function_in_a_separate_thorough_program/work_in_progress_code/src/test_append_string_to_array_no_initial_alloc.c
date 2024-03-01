#include "../foundationallib.h"
#include <assert.h>
void test_append_string_to_array_no_initial_alloc()
{
    const char **array = NULL;
    size_t array_size = 0;
    size_t array_current_alloc_size = 0;

    // Test empty array with initial allocation size other than 0
    {
        const char *new_string = "Test String 1";
        int result = append_string_to_array_no_initial_alloc(&array, &array_size, &array_current_alloc_size, new_string);
        assert(result == 0);
        assert(array_size == 1);
        assert(array_current_alloc_size > 0);
        assert(strcmp(array[0], new_string) == 0);
    }

    // Test adding multiple strings
    {
        const char *new_string = "Test String 2";
        int result = append_string_to_array_no_initial_alloc(&array, &array_size, &array_current_alloc_size, new_string);
        assert(result == 0);
        assert(array_size == 2);
        assert(array_current_alloc_size > 0);
        assert(strcmp(array[1], new_string) == 0);
    }

    // Test error when allocating size is 0
    {
        array_current_alloc_size = 0;
        const char *new_string = "Test String 3";
        int result = append_string_to_array_no_initial_alloc(&array, &array_size, &array_current_alloc_size, new_string);
        assert(result == -1);
    }

    // Free memory
    for (size_t i = 0; i < array_size; i++)
    {
        free((void *)array[i]);
    }
    free(array);
    array = NULL;
}

int main()
{
    test_append_string_to_array_no_initial_alloc();
    printf("All tests passed successfully!\n");
    return 0;
}
