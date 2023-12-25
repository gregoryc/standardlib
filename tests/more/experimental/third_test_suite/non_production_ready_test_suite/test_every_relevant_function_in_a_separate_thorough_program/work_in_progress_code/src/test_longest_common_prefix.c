#include "../foundationallib.h"
#include <assert.h>
void test_longest_common_prefix()
{
    const char *input1[] = {"flower", "flow", "flight"};
    char *result1 = longest_common_prefix(input1, 3);
    assert(strcmp(result1, "fl") == 0);
    free(result1);

    const char *input2[] = {"dog", "racecar", "car"};
    char *result2 = longest_common_prefix(input2, 3);
    assert(result2 == NULL);

    const char *input3[] = {"", "abc", "def"};
    char *result3 = longest_common_prefix(input3, 3);
    assert(strcmp(result3, "") == 0);
    free(result3);

    const char *input4[] = {"", "", ""};
    char *result4 = longest_common_prefix(input4, 3);
    assert(strcmp(result4, "") == 0);
    free(result4);

    const char *input5[] = {"abcd", "abcd", "abcd"};
    char *result5 = longest_common_prefix(input5, 3);
    assert(strcmp(result5, "abcd") == 0);
    free(result5);
}

int main()
{
    test_longest_common_prefix();
    printf("All tests passed!\n");
    return 0;
}
