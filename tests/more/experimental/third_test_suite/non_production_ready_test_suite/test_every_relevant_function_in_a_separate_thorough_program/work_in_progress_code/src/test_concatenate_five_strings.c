#include "../foundationallib.h"
#include <assert.h>
int main()
{
    // Test case 1: Test with all empty strings
    char *result1 = concatenate_five_strings("", "", "", "", "");
    assert(strcmp(result1, "") == 0);
    free(result1);

    // Test case 2: Test with non-empty strings
    char *result2 = concatenate_five_strings("Hello, ", "world", "!", " This is ", "a test!");
    assert(strcmp(result2, "Hello, world! This is a test!") == 0);
    free(result2);

    // Test case 3: Test with one empty string
    char *result3 = concatenate_five_strings("Hello, ", "world", "!", " This is ", "");
    assert(strcmp(result3, "Hello, world! This is ") == 0);
    free(result3);

    // Test case 4: Test with long strings
    char *result4 = concatenate_five_strings("Lorem ipsum dolor sit amet, ", "consectetur adipiscing elit. ", "Integer ", "nec ", "odio.");
    assert(strcmp(result4, "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Integer nec odio.") == 0);
    free(result4);

    // Test case 5: Test with NULL strings
    char *result5 = concatenate_five_strings(NULL, "world", "!", " This is ", "a test!");
    assert(result5 == NULL);

    printf("All tests passed successfully!\n");

    return 0;
}
