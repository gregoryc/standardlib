#include "../foundationallib.h"
#include <assert.h>

void test_concatenate_three_strings()
{
    // Test case 1: all empty strings
    const char *str1 = "";
    const char *str2 = "";
    const char *str3 = "";
    char *result = concatenate_three_strings(str1, str2, str3);
    assert(strcmp(result, "") == 0);
    free(result);

    // Test case 2: one empty string
    str1 = "hello";
    str2 = "";
    str3 = "world";
    result = concatenate_three_strings(str1, str2, str3);
    assert(strcmp(result, "helloworld") == 0);
    free(result);

    // Test case 3: all non-empty strings
    str1 = "This ";
    str2 = "is a ";
    str3 = "test";
    result = concatenate_three_strings(str1, str2, str3);
    assert(strcmp(result, "This is a test") == 0);
    free(result);

    // Test case 4: memory allocation failure
    char *ptr = (char *)malloc(1);
    assert(ptr != NULL); // Ensure that memory allocation works fine
    free(ptr);
    ptr = (char *)malloc(1);
    assert(ptr == NULL); // Ensure that memory allocation fails
}

int main()
{
    test_concatenate_three_strings();
    printf("All tests passed successfully.\n");
    return 0;
}
