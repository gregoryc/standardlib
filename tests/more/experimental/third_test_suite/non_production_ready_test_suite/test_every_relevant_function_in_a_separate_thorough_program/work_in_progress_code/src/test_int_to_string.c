#include "../foundationallib.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// Test function
void test_int_to_string()
{
    // Test case 1
    int num1 = 12345;
    char *expected_str1 = "12345";
    char *result_str1 = int_to_string(num1);
    assert(strcmp(expected_str1, result_str1) == 0);

    // Test case 2
    int num2 = -54321;
    char *expected_str2 = "-54321";
    char *result_str2 = int_to_string(num2);
    assert(strcmp(expected_str2, result_str2) == 0);

    // Test case 3
    int num3 = 0;
    char *expected_str3 = "0";
    char *result_str3 = int_to_string(num3);
    assert(strcmp(expected_str3, result_str3) == 0);

    // Test case 4 (corner case: largest positive number)
    int num4 = 2147483647;
    char *expected_str4 = "2147483647";
    char *result_str4 = int_to_string(num4);
    assert(strcmp(expected_str4, result_str4) == 0);

    // Test case 5 (corner case: smallest negative number)
    int num5 = -2147483648;
    char *expected_str5 = "-2147483648";
    char *result_str5 = int_to_string(num5);
    assert(strcmp(expected_str5, result_str5) == 0);

    // Free dynamically allocated memory
    free(result_str1);
    free(result_str2);
    free(result_str3);
    free(result_str4);
    free(result_str5);

    printf("All test cases passed!\n");
}

// Main function
int main()
{
    test_int_to_string();
    return 0;
}
