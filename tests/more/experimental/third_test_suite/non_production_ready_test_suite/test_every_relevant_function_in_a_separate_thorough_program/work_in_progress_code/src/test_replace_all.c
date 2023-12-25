#include "../foundationallib.h"

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void test_replace_all()
{
    char *input1 = "Hello, world!";
    char *input2 = "aaa";
    char *input3 = "abcdabcd";
    char *input4 = "abcdabcdabcd";
    char *input5 = "abcdabcdabcdabcd";
    char *input6 = "";
    char *input7 = "xyz";
    char *input8 = "mississippi";

    char *old_substring = "world";
    char *new_substring = "universe";
    char *result1 = replace_all(input1, old_substring, new_substring);
    assert(strcmp(result1, "Hello, universe!") == 0);
    free(result1);

    old_substring = "aa";
    new_substring = "bb";
    char *result2 = replace_all(input2, old_substring, new_substring);
    assert(strcmp(result2, "bb") == 0);
    free(result2);

    old_substring = "abcd";
    new_substring = "xy";
    char *result3 = replace_all(input3, old_substring, new_substring);
    assert(strcmp(result3, "xyxy") == 0);
    free(result3);

    old_substring = "abcd";
    new_substring = "xy";
    char *result4 = replace_all(input4, old_substring, new_substring);
    assert(strcmp(result4, "xyxyxy") == 0);
    free(result4);

    old_substring = "abcd";
    new_substring = "xy";
    char *result5 = replace_all(input5, old_substring, new_substring);
    assert(strcmp(result5, "xyxyxyxy") == 0);
    free(result5);

    old_substring = "xyz";
    new_substring = "abc";
    char *result6 = replace_all(input6, old_substring, new_substring);
    assert(strcmp(result6, "") == 0);
    free(result6);

    old_substring = "iss";
    new_substring = "ix";
    char *result7 = replace_all(input7, old_substring, new_substring);
    assert(strcmp(result7, "xy") == 0);
    free(result7);

    old_substring = "is";
    new_substring = "was";
    char *result8 = replace_all(input8, old_substring, new_substring);
    assert(strcmp(result8, "wasswasppi") == 0);
    free(result8);

    printf("All tests passed successfully!\n");
}

int main()
{
    test_replace_all();
    return 0;
}
