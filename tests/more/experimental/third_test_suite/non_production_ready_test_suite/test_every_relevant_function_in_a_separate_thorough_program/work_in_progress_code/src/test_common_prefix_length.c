#include "../foundationallib.h"
#include <assert.h>

int main()
{
    // Test cases
    assert(common_prefix_length("abcdef", "abcde") == 5);
    assert(common_prefix_length("abc", "abcde") == 3);
    assert(common_prefix_length("abcdef", "xyz") == 0);
    assert(common_prefix_length("abc", "abcdef") == 3);
    assert(common_prefix_length("", "") == 0);
    assert(common_prefix_length("abc", "abc") == 3);
    assert(common_prefix_length("a", "b") == 0);
    assert(common_prefix_length("abc", "") == 0);

    // Additional corner cases
    assert(common_prefix_length(NULL, "abc") == 0);
    assert(common_prefix_length("abc", NULL) == 0);
    assert(common_prefix_length(NULL, NULL) == 0);

    printf("All tests passed!\n");
    return 0;
}
