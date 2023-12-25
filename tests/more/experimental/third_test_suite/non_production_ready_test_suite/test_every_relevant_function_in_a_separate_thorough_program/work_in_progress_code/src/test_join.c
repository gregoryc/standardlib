#include "../foundationallib.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void test_join()
{
    const char *array1[] = {"hello", "world", "good", "morning"};
    const char *delimiter1 = ",";
    char *expected_result1 = "hello,world,good,morning";
    char *result1 = join(array1, 4, delimiter1);
    assert(strcmp(result1, expected_result1) == 0);
    free(result1);

    const char *array2[] = {"apple", "orange"};
    const char *delimiter2 = "|";
    char *expected_result2 = "apple|orange";
    char *result2 = join(array2, 2, delimiter2);
    assert(strcmp(result2, expected_result2) == 0);
    free(result2);

    const char *array3[] = {"This", "is", "a", "test"};
    const char *delimiter3 = " ";
    char *expected_result3 = "This is a test";
    char *result3 = join(array3, 4, delimiter3);
    assert(strcmp(result3, expected_result3) == 0);
    free(result3);

    const char *array4[] = {"Hello"};
    const char *delimiter4 = "-";
    char *expected_result4 = "Hello";
    char *result4 = join(array4, 1, delimiter4);
    assert(strcmp(result4, expected_result4) == 0);
    free(result4);

    const char *array5[] = {""};
    const char *delimiter5 = ":";
    char *expected_result5 = "";
    char *result5 = join(array5, 1, delimiter5);
    assert(strcmp(result5, expected_result5) == 0);
    free(result5);

    const char *array6[] = {NULL, "world", "hello"};
    const char *delimiter6 = " ";
    char *result6 = join(array6, 3, delimiter6);
    assert(result6 == NULL);
}

int main()
{
    test_join();
    return 0;
}
