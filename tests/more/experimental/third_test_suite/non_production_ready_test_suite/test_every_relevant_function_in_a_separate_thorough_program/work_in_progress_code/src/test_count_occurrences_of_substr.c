#include "../foundationallib.h"
#include <assert.h>

int main()
{
    // Test cases and assertions for count_occurrences_of_subst
    assert(count_occurrences_of_substr("hellohellohello", "hello") == 3);
    assert(count_occurrences_of_substr("abcabcabc", "abc") == 3);
    assert(count_occurrences_of_substr("aaaaaaa", "aaa") == 4);
    assert(count_occurrences_of_substr("not found", "abc") == 0);
    assert(count_occurrences_of_substr("Case sensitive", "case") == 0);
    assert(count_occurrences_of_substr("Case sensitive", "Case") == 1);

    // Additional edge cases
    assert(count_occurrences_of_substr("aaaaa", "aa") == 4);
    assert(count_occurrences_of_substr("ababababa", "aba") == 3);
    assert(count_occurrences_of_substr("", "abc") == 0);
    assert(count_occurrences_of_substr("abc", "") == 0);

    return 0;
}
