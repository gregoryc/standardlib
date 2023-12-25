#include "../foundationallib.h"
#include <assert.h>

// Function to test
ssize_t index_of_char(const char *str, char chr);

// Test cases
void test_index_of_char_normal_case()
{
    const char *str = "hello";
    char chr = 'e';
    ssize_t result = index_of_char(str, chr);
    assert(result == 1);
}

void test_index_of_char_not_found()
{
    const char *str = "hello";
    char chr = 'z';
    ssize_t result = index_of_char(str, chr);
    assert(result == -1);
}

void test_index_of_char_empty_string()
{
    const char *str = "";
    char chr = 'a';
    ssize_t result = index_of_char(str, chr);
    assert(result == -1);
}

void test_index_of_char_null_string()
{
    const char *str = NULL;
    char chr = 'a';
    ssize_t result = index_of_char(str, chr);
    assert(result == -1);
}

void test_index_of_char_null_character()
{
    const char *str = "hello";
    char chr = '\0';
    ssize_t result = index_of_char(str, chr);
    assert(result == -1);
}

void test_index_of_char_single_character_string_found()
{
    const char *str = "h";
    char chr = 'h';
    ssize_t result = index_of_char(str, chr);
    assert(result == 0);
}

void test_index_of_char_single_character_string_not_found()
{
    const char *str = "a";
    char chr = 'b';
    ssize_t result = index_of_char(str, chr);
    assert(result == -1);
}

// Main function to run all the test cases
int main()
{
    test_index_of_char_normal_case();
    test_index_of_char_not_found();
    test_index_of_char_empty_string();
    test_index_of_char_null_string();
    test_index_of_char_null_character();
    test_index_of_char_single_character_string_found();
    test_index_of_char_single_character_string_not_found();

    printf("All test cases passed successfully!\n");
    return 0;
}
