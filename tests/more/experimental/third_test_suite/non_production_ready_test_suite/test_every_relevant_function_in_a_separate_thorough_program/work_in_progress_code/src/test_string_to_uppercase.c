#include "../foundationallib.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *string_to_uppercase(char *str)
{
    if (str == NULL)
    {
        return NULL;
    }

    size_t len = strlen(str);
    char *result = (char *)malloc(len + 1);
    if (result == NULL)
    {
        return NULL;
    }

    for (size_t i = 0; i < len; i++)
    {
        if (str[i] >= 'a' && str[i] <= 'z')
        {
            result[i] = str[i] - 'a' + 'A';
        }
        else
        {
            result[i] = str[i];
        }
    }
    result[len] = '\0';

    return result;
}

void test_string_to_uppercase_null()
{
    char *result = string_to_uppercase(NULL);
    assert(result == NULL);
}

void test_string_to_uppercase_empty_string()
{
    char *result = string_to_uppercase("");
    assert(strcmp(result, "") == 0);
    free(result);
}

void test_string_to_uppercase_all_lowercase()
{
    char *input = "abcdefghijklmnopqrstuvwxyz";
    char *expected = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char *result = string_to_uppercase(input);
    assert(strcmp(result, expected) == 0);
    free(result);
}

void test_string_to_uppercase_mixed_case()
{
    char *input = "AbCdeFgHiJkLmNoPqRsTuVwXyZ";
    char *expected = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char *result = string_to_uppercase(input);
    assert(strcmp(result, expected) == 0);
    free(result);
}

int main()
{
    test_string_to_uppercase_null();
    test_string_to_uppercase_empty_string();
    test_string_to_uppercase_all_lowercase();
    test_string_to_uppercase_mixed_case();

    printf("All tests passed!\n");

    return 0;
}
