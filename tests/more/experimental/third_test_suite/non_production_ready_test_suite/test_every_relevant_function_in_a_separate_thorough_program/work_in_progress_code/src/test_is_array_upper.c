#include "../foundationallib.h"
#include <assert.h>
int main()
{
    // Test case 1: Array containing only uppercase characters
    const char *arr1[] = {"HELLO", "WORLD", "THIS", "IS", "A", "TEST"};
    assert(is_array_upper(arr1, 6) == 1);

    // Test case 2: Array containing both uppercase and lowercase characters
    const char *arr2[] = {"Hello", "World", "This", "Is", "A", "Test"};
    assert(is_array_upper(arr2, 6) == 0);

    // Test case 3: Array containing only one string
    const char *arr3[] = {"HELLO"};
    assert(is_array_upper(arr3, 1) == 1);

    // Test case 4: Array containing an empty string
    const char *arr4[] = {""};
    assert(is_array_upper(arr4, 1) == 1);

    // Test case 5: Array containing special characters
    const char *arr5[] = {"HELLO!", "WORLD@", "THIS#", "IS$", "A%", "TEST^"};
    assert(is_array_upper(arr5, 6) == 0);

    printf("All tests passed successfully!\n");

    return 0;
}
