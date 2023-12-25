#include "../foundationallib.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int test_replace_all_with_lens()
{
    const char *source = "Hello world! This is a test";
    const char *find = "is";
    const char *replace = "was";
    size_t source_len = strlen(source);
    size_t find_len = strlen(find);
    size_t replace_len = strlen(replace);

    int caller_should_use_orig_string_without_modification;
    size_t num_matches;
    char *new_text;

    // Test case 1: Replace 'is' with 'was'
    int result = replace_all_with_lens(source, find, replace, source_len, find_len, replace_len, &caller_should_use_orig_string_without_modification, &num_matches, &new_text);
    assert(result == 0);
    assert(caller_should_use_orig_string_without_modification == 0);
    assert(num_matches == 2);
    assert(strcmp(new_text, "Hello world! Thwas was a test") == 0);
    free(new_text);

    // Test case 2: No replacement, should use original string without modification
    find = "xyz";
    replace = "abc";
    find_len = strlen(find);
    replace_len = strlen(replace);

    result = replace_all_with_lens(source, find, replace, source_len, find_len, replace_len, &caller_should_use_orig_string_without_modification, &num_matches, &new_text);
    assert(result == SUCCESS);
    assert(caller_should_use_orig_string_without_modification == 1);
    assert(num_matches == 0);
    assert(new_text == NULL);

    // Test case 3: Empty source string
    source = "";
    source_len = strlen(source);
    find = "abc";
    replace = "def";
    find_len = strlen(find);
    replace_len = strlen(replace);

    result = replace_all_with_lens(source, find, replace, source_len, find_len, replace_len, &caller_should_use_orig_string_without_modification, &num_matches, &new_text);
    assert(result == SUCCESS);
    assert(caller_should_use_orig_string_without_modification == 1);
    assert(num_matches == 0);
    assert(new_text == NULL);

    return 0;
}

int main()
{
    test_replace_all_with_lens();
    printf("All tests passed!\n");
    return 0;
}
