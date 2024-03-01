#include "../foundationallib.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *string_to_lowercase(char *str)
{
    if (str == NULL)
    {
        return NULL;
    }

    char *result = strdup(str);
    if (result == NULL)
    {
        return NULL;
    }

    for (int i = 0; result[i]; i++)
    {
        result[i] = tolower(result[i]);
    }

    return result;
}

void test_string_to_lowercase()
{
    // Test with a normal string
    char *input1 = "Hello, World!";
    char *expected_output1 = "hello, world!";
    char *output1 = string_to_lowercase(input1);
    assert(strcmp(output1, expected_output1) == 0);

    free(output1);

    // Test with an empty string
    char *input2 = "";
    char *expected_output2 = "";
    char *output2 = string_to_lowercase(input2);
    assert(strcmp(output2, expected_output2) == 0);

    free(output2);

    // Test with a string containing only uppercase letters
    char *input3 = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char *expected_output3 = "abcdefghijklmnopqrstuvwxyz";
    char *output3 = string_to_lowercase(input3);
    assert(strcmp(output3, expected_output3) == 0);

    free(output3);

    // Test with a string containing non-alphabetic characters
    char *input4 = "123!@#";
    char *expected_output4 = "123!@#";
    char *output4 = string_to_lowercase(input4);
    assert(strcmp(output4, expected_output4) == 0);

    free(output4);

    // Test with a NULL input
    char *input5 = NULL;
    char *output5 = string_to_lowercase(input5);
    assert(output5 == NULL);
}

int main()
{
    test_string_to_lowercase();
    printf("All tests passed!\n");
    return 0;
}
