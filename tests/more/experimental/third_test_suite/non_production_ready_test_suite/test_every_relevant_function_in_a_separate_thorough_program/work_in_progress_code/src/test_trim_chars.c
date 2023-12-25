#include "../foundationallib.h"

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

FOUNDATIONAL_LIB_FUNC char *trim_chars(const char *str, const char *chars_to_trim)
{
    size_t length = strlen(str);

    // Trim leading characters
    size_t start = 0;
    while (str[start] != '\0' && strchr(chars_to_trim, str[start]) != NULL)
    {
        start++;
    }

    // Trim trailing characters
    size_t end = length;
    while (end > start && strchr(chars_to_trim, str[end - 1]) != NULL)
    {
        end--;
    }

    size_t trimmed_length = end - start;
    char *trimmed_str = (char *)malloc(trimmed_length + 1);

    if (trimmed_str == NULL)
    {
        return NULL;
    }

    memcpy(trimmed_str, &str[start], trimmed_length);
    trimmed_str[trimmed_length] = '\0';

    return trimmed_str;
}

void test_trim_chars()
{
    // Test cases
    char *test_str = "  hello world  ";
    char *expected_result = "hello world";
    char *actual_result = trim_chars(test_str, " ");

    assert(strcmp(actual_result, expected_result) == 0);
    free(actual_result);

    test_str = ">>>hello<<<";
    expected_result = "hello";
    actual_result = trim_chars(test_str, ">>><<");

    assert(strcmp(actual_result, expected_result) == 0);
    free(actual_result);

    test_str = "!!!";
    expected_result = "";
    actual_result = trim_chars(test_str, "!");

    assert(strcmp(actual_result, expected_result) == 0);
    free(actual_result);

    test_str = "abc";
    expected_result = "abc";
    actual_result = trim_chars(test_str, "!");

    assert(strcmp(actual_result, expected_result) == 0);
    free(actual_result);

    test_str = "  ";
    expected_result = "";
    actual_result = trim_chars(test_str, " ");

    assert(strcmp(actual_result, expected_result) == 0);
    free(actual_result);
}

int main()
{
    test_trim_chars();

    printf("All tests passed\n");
    return 0;
}
