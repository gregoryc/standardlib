#include "../foundationallib.h"
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wpragmas"
#pragma GCC diagnostic ignored "-Wformat"
#pragma GCC diagnostic ignored "-Wformat-extra-args"
#include <assert.h>

#define die()                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                      \
    {                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                              \
        fprintf(stderr, "Error on line %d\n", __LINE__);                                                                                                                                                                                                                                                                                                                                                                                                                                                           \
        exit(1);                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                   \
    }

void test_append_string_to_array()
{
    puts("Test 1");

    // Initialize variables for array testing
    size_t array_size = 0;
    size_t current_array_alloc_size = 0;
    char **array = NULL;

    // Test data
    char *element1 = (char *)"test1";
    char *element2 = (char *)"test2";
    char *element3 = (char *)"test3";

    // Test appending the first element
    puts("First element");
    if (append_string_to_array((char ***)&array, &array_size, &current_array_alloc_size, element1))
        die();

    // Assertions for the first element
    assert(array != NULL);
    assert(array_size == 1);
    assert(strcmp(array[0], "test1") == 0);
    assert(current_array_alloc_size >= sizeof(char *));
    puts("First element is good.");
    printf("Alloc size is %zu\n", current_array_alloc_size);

    // Test appending another element
    if (append_string_to_array((char ***)&array, &array_size, &current_array_alloc_size, element2))
        die();

    // Additional assertions for the second element
    assert(array_size == 2);
    assert(current_array_alloc_size > sizeof(char *));
    assert(strcmp(array[0], "test1") == 0);
    assert(strcmp(array[1], "test2") == 0);

    // Test appending another element
    if (append_string_to_array((char ***)&array, &array_size, &current_array_alloc_size, element3))
        die();

    // Additional assertions for the third element
    assert(array_size == 3);
    assert(current_array_alloc_size > sizeof(char *));
    assert(strcmp(array[0], "test1") == 0);
    assert(strcmp(array[1], "test2") == 0);
    assert(strcmp(array[2], "test3") == 0);

    // Stress test: Append a large number of elements
    size_t stress_test_size = 1000 * 1000;
    char stress_test_data[21];
    for (size_t i = 4; i < stress_test_size + 4; ++i)
    {
        sprintf(stress_test_data, "test%zu", i);
        if (i % 50000 == 0)
        {
            printf("i = %zu, size [%zu => %zu]\n", i, array_size, current_array_alloc_size);
        }
        if (append_string_to_array((char ***)&array, &array_size, &current_array_alloc_size, stress_test_data))
            die();
    }

    // Verify the last element added in the stress test
    assert(array_size == stress_test_size + 3);
    assert(strcmp(array[stress_test_size + 2], stress_test_data) == 0);

    // Free memory
    free(array);
}

int main()
{
    // Run the test functions
    test_append_string_to_array();

    // Print a success message if all tests passed
    printf("All tests passed!\n");

    return 0;
}

#pragma GCC diagnostic pop
