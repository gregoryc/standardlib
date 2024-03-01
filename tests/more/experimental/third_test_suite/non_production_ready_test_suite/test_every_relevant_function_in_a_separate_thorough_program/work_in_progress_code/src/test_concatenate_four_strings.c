#include "../foundationallib.h"
// Test cases
void test_concatenate_four_strings()
{
    // Test case 1: All empty strings
    char *result1 = concatenate_four_strings("", "", "", "");
    assert(result1 != NULL);
    assert(strcmp(result1, "") == 0);
    free(result1);

    // Test case 2: One empty string
    char *result2 = concatenate_four_strings("abc", "", "def", "ghi");
    assert(result2 != NULL);
    assert(strcmp(result2, "abcdefghi") == 0);
    free(result2);

    // Test case 3: All non-empty strings
    char *result3 = concatenate_four_strings("This ", "is a ", "test ", "string");
    assert(result3 != NULL);
    assert(strcmp(result3, "This is a test string") == 0);
    free(result3);

    // Test case 4: Testing long strings
    char *result4 = concatenate_four_strings("Lorem ipsum ", "dolor sit amet, ", "consectetur adipiscing ", "elit");
    assert(result4 != NULL);
    assert(strcmp(result4, "Lorem ipsum dolor sit amet, consectetur adipiscing elit") == 0);
    free(result4);

    // Test case 5: Testing NULL input
    char *result5 = concatenate_four_strings(NULL, "abc", "def", "ghi");
    assert(result5 == NULL);
}

int main()
{
    test_concatenate_four_strings();
    printf("All tests passed!\n");
    return 0;
}
