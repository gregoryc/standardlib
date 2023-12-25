#include "../foundationallib.h"
#include <assert.h>
void test_common_suffix_length()
{
    // Test cases
    assert(common_suffix_length("hello", "world") == 0);
    assert(common_suffix_length("hello", "hello") == 5);
    assert(common_suffix_length("hello", "o") == 1);
    assert(common_suffix_length("", "") == 0);
    assert(common_suffix_length("abc", "def") == 0);
    assert(common_suffix_length("abcdef", "def") == 3);
    assert(common_suffix_length("abcdef", "de") == 2);
    assert(common_suffix_length("abcdef", "") == 0);
    assert(common_suffix_length("", "abcdef") == 0);
    assert(common_suffix_length("foo/bar", "bar") == 3);
}

int main()
{
    test_common_suffix_length();
    printf("All tests passed!\n");
    return 0;
}
