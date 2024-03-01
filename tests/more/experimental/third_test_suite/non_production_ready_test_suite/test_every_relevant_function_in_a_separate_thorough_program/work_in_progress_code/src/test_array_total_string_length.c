#include "../foundationallib.h"
#include <assert.h>

void test_array_total_string_length()
{
    const char *array1[] = {"abc", "def", "ghi"};
    const char *array2[] = {"hello", "world"};
    const char *array3[] = {"", "", ""};
    const char *array4[] = {NULL, "test", "string"};
    const char *array5[] = {"this is a test", "of the array", "of strings"};

    assert(array_total_string_length(array1, 3) == 9);
    assert(array_total_string_length(array2, 2) == 10);
    assert(array_total_string_length(array3, 3) == 0);
    assert(array_total_string_length(array4, 3) == 11);
    assert(array_total_string_length(array5, 3) == 31);
}

int main()
{
    test_array_total_string_length();
    printf("All tests passed!\n");

    return 0;
}
