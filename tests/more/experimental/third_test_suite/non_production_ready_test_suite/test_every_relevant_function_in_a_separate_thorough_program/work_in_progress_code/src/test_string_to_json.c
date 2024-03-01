#include "../foundationallib.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *string_to_json(const char *input_string)
{
    if (input_string == NULL)
    {
        return NULL;
    }

    size_t input_length = strlen(input_string);
    size_t output_length = 0;

    // Calculate the length of the output JSON string
    for (size_t i = 0; i < input_length; i++)
    {
        if (input_string[i] == '"' || input_string[i] == '\\')
        {
            output_length += 2; // Add extra space for escaped character
        }
        else
        {
            output_length++;
        }
    }

    // Allocate memory for the output JSON string
    char *json_string = (char *)malloc(output_length + 1); // Add 1 for null terminator
    if (json_string == NULL)
    {
        return NULL;
    }

    // Convert the input string to JSON format
    size_t index = 0;
    for (size_t i = 0; i < input_length; i++)
    {
        if (input_string[i] == '"')
        {
            json_string[index++] = '\\'; // Escape double quote
            json_string[index++] = '"';
        }
        else if (input_string[i] == '\\')
        {
            json_string[index++] = '\\'; // Escape backslash
            json_string[index++] = '\\';
        }
        else
        {
            json_string[index++] = input_string[i];
        }
    }
    json_string[index] = '\0'; // Null-terminate the JSON string

    return json_string;
}

void test_string_to_json()
{
    // Test cases with various input strings and their corresponding expected JSON strings
    const char *input1 = "Hello, World!";
    const char *expected_output1 = "Hello, World!";
    char *result1 = string_to_json(input1);
    assert(strcmp(result1, expected_output1) == 0); // Input string with no special characters
    free(result1);

    const char *input2 = "It's a \"nice\" day.";
    const char *expected_output2 = "It's a \\\"nice\\\" day.";
    char *result2 = string_to_json(input2);
    assert(strcmp(result2, expected_output2) == 0); // Input string with double quotes
    free(result2);

    const char *input3 = "\\escape\\";
    const char *expected_output3 = "\\\\escape\\\\";
    char *result3 = string_to_json(input3);
    assert(strcmp(result3, expected_output3) == 0); // Input string with backslashes
    free(result3);

    const char *input4 = "";
    const char *expected_output4 = "";
    char *result4 = string_to_json(input4);
    assert(strcmp(result4, expected_output4) == 0); // Empty input string
    free(result4);

    const char *input5 = NULL;
    char *result5 = string_to_json(input5);
    assert(result5 == NULL); // NULL input string
}

int main()
{
    test_string_to_json();
    printf("All tests passed successfully!\n");
    return 0;
}