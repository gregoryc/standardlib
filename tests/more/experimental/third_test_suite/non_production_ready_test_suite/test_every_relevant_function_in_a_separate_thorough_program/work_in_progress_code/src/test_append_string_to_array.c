#include "../foundationallib.h"
#include <assert.h>
int test_append_string_to_array()
{
    const char **array = NULL;
    size_t array_size = 0;
    size_t array_current_alloc_size = 0;

    // Test case 1: Append to empty array
    const char *test_string_1 = "Hello";
    int result = append_string_to_array(&array, &array_size, &array_current_alloc_size, test_string_1);
    assert(result == 0);
    assert(array_size == 1);
    printf("Alloc size is %zu\n", array_current_alloc_size);
    assert(array_current_alloc_size >= 1);
    assert(strcmp(array[0], test_string_1) == 0);

    // Test case 2: Append to non-empty array
    const char *test_string_2 = "World";
    result = append_string_to_array(&array, &array_size, &array_current_alloc_size, test_string_2);
    assert(result == 0);
    assert(array_size == 2);
    assert(array_current_alloc_size >= 2);
    assert(strcmp(array[1], test_string_2) == 0);

    return 0;
}

int main()
{
    test_append_string_to_array();
    return 0;
}
