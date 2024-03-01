#include "../foundationallib.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *string_to_title_case(const char *str)
{
    if (str == NULL)
    {
        return NULL;
    }

    size_t len = strlen(str);
    char *result = (char *)malloc((len + 1) * sizeof(char));
    if (result == NULL)
    {
        return NULL;
    }

    strncpy(result, str, len);

    int capitalize_next = 1;
    for (size_t i = 0; i < len; i++)
    {
        if (result[i] == ' ')
        {
            capitalize_next = 1;
        }
        else
        {
            if (capitalize_next)
            {
                result[i] = (char)toupper(result[i]);
                capitalize_next = 0;
            }
            else
            {
                result[i] = (char)tolower(result[i]);
            }
        }
    }

    return result;
}

int main()
{
    // Test case 1: Empty string
    char *empty_string = string_to_title_case("");
    assert(empty_string != NULL);
    assert(strcmp(empty_string, "") == 0);
    free(empty_string);

    // Test case 2: All uppercase string
    char *all_uppercase = string_to_title_case("HELLO WORLD");
    assert(all_uppercase != NULL);
    assert(strcmp(all_uppercase, "Hello World") == 0);
    free(all_uppercase);

    // Test case 3: All lowercase string
    char *all_lowercase = string_to_title_case("hello world");
    assert(all_lowercase != NULL);
    assert(strcmp(all_lowercase, "Hello World") == 0);
    free(all_lowercase);

    // Test case 4: Mixed case string
    char *mixed_case = string_to_title_case("hElLo WoRlD");
    assert(mixed_case != NULL);
    assert(strcmp(mixed_case, "Hello World") == 0);
    free(mixed_case);

    // Test case 5: NULL input
    char *null_input = string_to_title_case(NULL);
    assert(null_input == NULL);

    printf("All tests passed!\n");

    return 0;
}