#include "../foundationallib.h"
#include <assert.h>
#include <stdlib.h>

// Function to be tested
void free_array(void **array, size_t len)
{
    for (size_t i = 0; i < len; i++)
    {
        free(array[i]);
    }
    free(array);
}

// Test cases
void test_free_array_null_array()
{
    void **array = NULL;
    free_array(array, 0);
    // No assertion, just making sure it doesn't crash
}

void test_free_array_empty_array()
{
    void **array = malloc(0);
    free_array(array, 0);
    // No assertion, just making sure it doesn't crash
}

void test_free_array_single_element()
{
    void *element = malloc(sizeof(int));
    void **array = malloc(sizeof(void *));
    array[0] = element;

    free_array(array, 1);
    assert(array[0] == NULL);
    free(array);
}

void test_free_array_multiple_elements()
{
    void *element1 = malloc(sizeof(int));
    void *element2 = malloc(sizeof(int));
    void **array = malloc(2 * sizeof(void *));
    array[0] = element1;
    array[1] = element2;

    free_array(array, 2);
    assert(array[0] == NULL);
    assert(array[1] == NULL);
    free(array);
}

int main()
{
    test_free_array_null_array();
    test_free_array_empty_array();
    test_free_array_single_element();
    test_free_array_multiple_elements();

    return 0;
}
