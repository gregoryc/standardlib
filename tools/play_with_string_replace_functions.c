#include "./foundationallib.h"
#include <assert.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

FOUNDATIONAL_LIB_FUNC char *replace_all_with_callback_(const char *str, const char *old_substring, char *(*callback)(const char *, void *), void *data_for_callback)
{
    size_t str_len = strlen(str);
    size_t old_substring_len = strlen(old_substring);
    size_t alloc_size = str_len + 1; // Start with the original string length + 1 for the null terminator

    // Allocate memory for the result string
    char *result = (char *)FOUNDATIONAL_LIB_MEMORY_ALLOCATOR_MALLOC(str_len);
    if (FOUNDATIONAL_LIB_UNLIKELY(result == NULL))
    {
        FOUNDATIONAL_LIB_die_aggressively_if_enabled();
        return NULL;
    }

    // Copy and replace substrings
    const char *pos = str;

    size_t new_len = 0;

    for (;;)
    {
        const char *found_pos = memory_locate(pos, str_len - (pos - str), old_substring, old_substring_len);
        if (found_pos == NULL)
        {
            puts("Done");
            size_t remaining_len = str_len - (pos - str);
            printf("%ld %ld\n", str_len, pos - str);
            memcpy(result + new_len, pos, remaining_len);
            new_len += remaining_len;

            result[new_len] = '\0';

            new_len += remaining_len;
            break;
        }

        // Copy the segment

        char *replacement = callback(old_substring, data_for_callback);

        // Resize the result buffer if needed
        size_t replacement_len = strlen(replacement);

        const size_t diff = found_pos - pos;

        const size_t nlen = new_len + diff + replacement_len + 1;

        printf("%d <=> %d\n", nlen, alloc_size);

        if ((nlen >= alloc_size))
        {
            puts("REALLOC");
            /* Makes it at least 1 bigger. */
            alloc_size = FOUNDATIONAL_LIB_REALLOC_REALLOCATION_ALGORITHM(nlen * 4);
            char *new_result = (char *)FOUNDATIONAL_LIB_MEMORY_ALLOCATOR_REALLOC(result, alloc_size);
            if (FOUNDATIONAL_LIB_UNLIKELY(new_result == NULL))
            {
                FOUNDATIONAL_LIB_MEMORY_ALLOCATOR_FREE(replacement);
                goto error;
            }
            result = new_result;
        }

        // printf("MEM %ld %zu\n", (long)segment_len, replacement_len);
        memcpy(result + new_len, pos, found_pos - pos); /* Safe. */
        new_len += found_pos - pos;

        memcpy(result + new_len, replacement, replacement_len); /* Safe. */
        FOUNDATIONAL_LIB_MEMORY_ALLOCATOR_FREE(replacement);
        new_len += replacement_len;
        pos = found_pos + old_substring_len;
    }

    return result;
overflow:
error:
    puts("BAD");
    FOUNDATIONAL_LIB_MEMORY_ALLOCATOR_FREE(result);
    *result = 0;
    FOUNDATIONAL_LIB_die_aggressively_if_enabled();
    return NULL;
}

// Example callback function
char *test_replacement_callback(const char *old_substring, void *time)
{
    ++*(size_t *)time;

    if (*(size_t *)time == 1)
    {
        return concatenate_three_strings("[", old_substring, ", Dog]");
    }
    else
    {
        // Return the number of replacement.
        char buf[21];
        utoa(*(size_t *)time, buf);
        return concatenate_three_strings("[Replacement #", buf, "]");
    }
}

void test_new_1()
{
    puts("Test new 1");
    const char *input_str = "foo example foo";
    const char *old_substring = "foo";

    size_t first_time = 0;

    char *result = replace_all_with_callback_(input_str, old_substring, test_replacement_callback, &first_time);
    printf("Original: %s\n", input_str);
    printf("Replaced: %s\n", result);

    free(result);
    exit(0);
}

void test_new_2()
{
    puts("Test new 2");
    const char *strs[2] = {"Hello", " world"};
    const char *c = concatenate_string_array(strs, 2);
    assert(equal_strings(c, "Hello world"));
    puts(c);
    FOUNDATIONAL_LIB_MEMORY_ALLOCATOR_FREE((void *)c);

    const char *input = "Cat Hello, world! Hello, universe!";
    puts(input);
    const char *old_substring = "Hello";
    const char *new_substring = "aaaaaaaaaaaaa";

    const size_t matches_max = 0;

    char *out;
    int should_free_after_use;
    size_t num_matches;
    size_t out_len;
    replace_memory((void *)input, strlen(input), (void *)old_substring, strlen(old_substring), (void *)new_substring, strlen(new_substring), (void **)&out, &out_len, &should_free_after_use, matches_max, &num_matches, 1);
    puts(out);

    assert(equal_strings("Cat aaaaaaaaaaaaa, world! aaaaaaaaaaaaa, universe!", out));
    assert(should_free_after_use);

    if (should_free_after_use)
    {
        FOUNDATIONAL_LIB_MEMORY_ALLOCATOR_FREE((void *)out);
    }

    replace_all_with_lens(input, strlen(input), old_substring, strlen(old_substring), new_substring, strlen(new_substring), &out, &out_len, &should_free_after_use, matches_max, &num_matches);

    puts(out);

    assert(should_free_after_use);

    if (should_free_after_use)
    {
        FOUNDATIONAL_LIB_MEMORY_ALLOCATOR_FREE((void *)out);
    }

    puts("1000 iterations");

    for (size_t i = 0; i < 1000; ++i)
    {
        old_substring = "";
        new_substring = "Foo";
        printf("%d\n", i);
        replace_memory((void *)input, strlen(input), (void *)old_substring, strlen(old_substring), (void *)new_substring, strlen(new_substring), (void **)&out, &out_len, &should_free_after_use, matches_max, &num_matches, 1);

        assert(!should_free_after_use);
        assert(out_len == strlen(input));
    }

    char *new_ = replace_all(input, old_substring, new_substring);
    puts(new_);
    FOUNDATIONAL_LIB_MEMORY_ALLOCATOR_FREE(new_);

    puts("Test new 2");
}

void test_new_2_with_argv(int argc, char **argv)
{
    const char *strs[2] = {"Hello", " world"};
    const char *c = concatenate_string_array(strs, 2);
    puts(c);
    free((void *)c);

    const char *input = "Cat Hello, world! Hello, universe!";
    puts(input);
    const char *old_substring = (argc == 4) ? argv[1] : "Hello";
    const char *new_substring = (argc == 4) ? argv[2] : "aaaaaaaaaaaaa";

    // printf("%s => %s\n", old_substring,new_substring);
    const size_t matches_max = (argc == 4) ? atol(argv[3]) : 0;

    char *out;
    int should_free_after_use;
    size_t num_matches;
    size_t out_len;
    replace_memory((void *)input, strlen(input), (void *)old_substring, strlen(old_substring), (void *)new_substring, strlen(new_substring), (void **)&out, &out_len, &should_free_after_use, matches_max, &num_matches, 1);
    puts(out);

    if (should_free_after_use)
        free((void *)out);

    replace_all_with_lens(input, strlen(input), old_substring, strlen(old_substring), new_substring, strlen(new_substring), &out, &out_len, &should_free_after_use, matches_max, &num_matches);

    puts(out);

    if (should_free_after_use)
        free((void *)out);

    char *new_ = replace_all(input, old_substring, new_substring);
    puts(new_);
    free(new_);
}

int main(int argc, char **argv)
{
    /*	for (int i = 0;i <40000; ++i) {
            const char      * a[2] = {"Foo", "Bar"};
            free(concatenate_string_array(a, 2));
            }*/
    (void)argc;
    (void)argv;
    // test_new_2_with_argv(argc, argv);

    test_new_1();
    // test_new_2();
}
