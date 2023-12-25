#include "../foundationallib.h"
#include <assert.h>
// Test Suite
int main()
{
    const char *test_strings1[] = {"Hello, ", "world!"};
    char *result1 = concatenate_string_array(test_strings1, 2);
    assert(strcmp(result1, "Hello, world!") == 0);
    free(result1);

    const char *test_strings2[] = {"This ", "is ", "a ", "test."};
    char *result2 = concatenate_string_array(test_strings2, 4);
    assert(strcmp(result2, "This is a test.") == 0);
    free(result2);

    const char *test_strings3[] = {"One string only."};
    char *result3 = concatenate_string_array(test_strings3, 1);
    assert(strcmp(result3, "One string only.") == 0);
    free(result3);

    const char *test_strings4[] = {NULL};
    char *result4 = concatenate_string_array(test_strings4, 0);
    assert(result4 == NULL);
    free(result4);

    printf("All tests passed!\n");
    return 0;
}
