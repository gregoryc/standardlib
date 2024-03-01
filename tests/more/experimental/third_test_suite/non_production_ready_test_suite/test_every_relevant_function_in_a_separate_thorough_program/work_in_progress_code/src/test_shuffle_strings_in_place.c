#include "../foundationallib.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void test_shuffle_strings_in_place()
{
    char *test_strings[] = {"apple", "banana", "cherry", "date", "elderberry"};
    size_t num_strings = sizeof(test_strings) / sizeof(test_strings[0]);

    // Test for shuffling a valid array of strings
    char **original_strings = malloc(sizeof(char *) * num_strings);
    memcpy(original_strings, test_strings, sizeof(test_strings));
    int result = shuffle_strings_in_place(test_strings, num_strings);
    assert(result == 1);

    // Test for strings being shuffled in place
    int any_strings_moved = 0;
    for (size_t i = 0; i < num_strings; i++)
    {
        if (strcmp(original_strings[i], test_strings[i]) != 0)
        {
            any_strings_moved = 1;
            break;
        }
    }
    assert(any_strings_moved == 1);

    free(original_strings);

    printf("All tests pass!\n");
}

int main()
{
    test_shuffle_strings_in_place();
    return 0;
}
