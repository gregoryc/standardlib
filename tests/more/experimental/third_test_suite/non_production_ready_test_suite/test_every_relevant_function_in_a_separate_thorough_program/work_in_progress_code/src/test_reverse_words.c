#include "../foundationallib.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *reverse_words(const char *str);

void test_reverse_words()
{
    char *result = reverse_words("hello world");
    assert(strcmp(result, "world hello") == 0);
    free(result);

    result = reverse_words("a b c");
    assert(strcmp(result, "c b a") == 0);
    free(result);

    result = reverse_words("   a   b    c   ");
    assert(strcmp(result, "c b a") == 0);
    free(result);

    result = reverse_words("test");
    assert(strcmp(result, "test") == 0);
    free(result);

    result = reverse_words("");
    assert(strcmp(result, "") == 0);
    free(result);

    result = reverse_words("one");
    assert(strcmp(result, "one") == 0);
    free(result);

    result = reverse_words("one two three");
    assert(strcmp(result, "three two one") == 0);
    free(result);

    // Test a very long string
    char long_str[1000000];
    for (int i = 0; i < 1000000; i++)
    {
        long_str[i] = 'a';
    }
    result = reverse_words(long_str);
    for (int i = 0; i < 1000000; i++)
    {
        assert(long_str[999999 - i] == result[i]);
    }
    free(result);
}

int main()
{
    test_reverse_words();
    printf("All tests passed!\n");
    return 0;
}
