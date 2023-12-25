#include "../foundationallib.h"
#include <assert.h>
#include <stdlib.h>
#include <string.h>

char *shellescape(const char *input);

void test_shellescape_empty_string()
{
    char *result = shellescape("");
    assert(strcmp(result, "") == 0);
    free(result);
}

void test_shellescape_no_special_characters()
{
    char *result = shellescape("Hello World");
    assert(strcmp(result, "Hello World") == 0);
    free(result);
}

void test_shellescape_with_special_characters()
{
    char *result = shellescape("This is a $test with *special* characters");
    assert(strcmp(result, "This is a \\$test with \\*special\\* characters") == 0);
    free(result);
}

void test_shellescape_null_input()
{
    char *result = shellescape(NULL);
    assert(result == NULL);
}

void test_shellescape_long_input()
{
    char *input = "A very long input string with special characters $!@*^&";
    char *result = shellescape(input);
    char *expected_result = "A very long input string with special characters \\$\\!\\@\\*^\\&";
    assert(strcmp(result, expected_result) == 0);
    free(result);
}

int main()
{
    test_shellescape_empty_string();
    test_shellescape_no_special_characters();
    test_shellescape_with_special_characters();
    test_shellescape_null_input();
    test_shellescape_long_input();

    return 0;
}
