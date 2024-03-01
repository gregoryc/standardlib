#include "../foundationallib.h"
#include <assert.h>

// The function to be tested
size_t count_occurrences_of_substr_len(const char *string, size_t string_length, const char *substring, size_t substring_length);

void test_0_occurrences()
{
    const char *str = "This is a test string.";
    const char *sub = "apple";
    size_t count = count_occurrences_of_substr_len(str, strlen(str), sub, strlen(sub));
    assert(count == 0);
}

void test_1_occurrence()
{
    const char *str = "This is a test string.";
    const char *sub = "test";
    size_t count = count_occurrences_of_substr_len(str, strlen(str), sub, strlen(sub));
    assert(count == 1);
}

void test_case_sensitive()
{
    const char *str = "This is a test string for testing.";
    const char *sub = "Test";
    size_t count = count_occurrences_of_substr_len(str, strlen(str), sub, strlen(sub));
    assert(count == 0);
}

void test_overlapping_occurrences()
{
    const char *str = "aaaaaa";
    const char *sub = "aaa";
    size_t count = count_occurrences_of_substr_len(str, strlen(str), sub, strlen(sub));
    assert(count == 4);
}

void test_empty_string()
{
    const char *str = "";
    const char *sub = "test";
    size_t count = count_occurrences_of_substr_len(str, strlen(str), sub, strlen(sub));
    assert(count == 0);
}

void test_empty_substring()
{
    const char *str = "This is a test string.";
    const char *sub = "";
    size_t count = count_occurrences_of_substr_len(str, strlen(str), sub, strlen(sub));
    assert(count == strlen(str) + 1);
}

int main()
{
    test_0_occurrences();
    test_1_occurrence();
    test_case_sensitive();
    test_overlapping_occurrences();
    test_empty_string();
    test_empty_substring();

    printf("All tests passed successfully!\n");
    return 0;
}
