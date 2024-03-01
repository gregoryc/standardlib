#include "../foundationallib.h"

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    const char *test_strings[] = {"Hello", "World", "This", "Is", "A", "Test"};
    const size_t num_strings = sizeof(test_strings) / sizeof(test_strings[0]);

    // Test 1: Check if the selected string is within the given array
    const char *selected_string = sample_strings(test_strings, num_strings);
    int found = 0;
    for (size_t i = 0; i < num_strings; i++)
    {
        if (selected_string == test_strings[i])
        {
            found = 1;
            break;
        }
    }
    assert(found && "Selected string is not in the given array");

    // Test 2: Check if the returned pointer is not NULL
    assert(selected_string != NULL && "Selected string pointer is NULL");

    // Test 3: Check for correctness of the selected string
    size_t selected_length = 0;
    while (selected_string[selected_length] != '\0')
    {
        selected_length++;
    }
    int matching = 1;
    for (size_t i = 0; i < selected_length; i++)
    {
        if (selected_string[i] != test_strings[0][i])
        {
            matching = 0;
            break;
        }
    }
    assert(matching && "Selected string does not match with the original string in the array");

    printf("All tests passed!\n");
    return 0;
}
