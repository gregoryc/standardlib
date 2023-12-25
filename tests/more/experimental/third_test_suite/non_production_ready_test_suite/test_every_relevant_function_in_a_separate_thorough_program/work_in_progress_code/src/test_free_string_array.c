#include "../foundationallib.h"

#include <assert.h>
#include <stdlib.h>

void free_string_array(char **array, size_t len)
{
    if (array == NULL)
        return;

    for (size_t i = 0; i < len; i++)
    {
        free(array[i]);
    }

    free(array);
}

int main()
{
    // Test case 1: array is NULL
    char **test1 = NULL;
    free_string_array(test1, 0);

    // Test case 2: len is 0
    char **test2 = (char **)malloc(0 * sizeof(char *));
    free_string_array(test2, 0);

    // Test case 3: len is 1
    char **test3 = (char **)malloc(1 * sizeof(char *));
    test3[0] = (char *)malloc(6);
    test3[0] = "Hello";
    free_string_array(test3, 1);
    assert(test3 == NULL); // Check if test3 is NULL after freeing

    // Test case 4: len is greater than 1
    char **test4 = (char **)malloc(3 * sizeof(char *));
    test4[0] = (char *)malloc(6);
    test4[1] = (char *)malloc(6);
    test4[2] = (char *)malloc(6);
    test4[0] = "Hello";
    test4[1] = "World";
    test4[2] = "!";
    free_string_array(test4, 3);
    assert(test4 == NULL); // Check if test4 is NULL after freeing

    // Add more test cases for different corner cases

    return 0;
}
