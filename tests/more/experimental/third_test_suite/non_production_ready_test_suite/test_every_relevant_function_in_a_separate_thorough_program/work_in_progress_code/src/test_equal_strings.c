#include "../foundationallib.h"
#include <assert.h>
#include <stdio.h>

#define TEST_CASES 6

void test_equal_strings()
{
    // Test case 1: Both strings are empty
    const char *str1 = "";
    const char *str2 = "";
    assert(equal_strings(str1, str2) == 1);

    // Test case 2: Both strings are "hello"
    str1 = "hello";
    str2 = "hello";
    assert(equal_strings(str1, str2) == 1);

    // Test case 3: First string is "apple" and second string is "applesauce"
    str1 = "apple";
    str2 = "applesauce";
    assert(equal_strings(str1, str2) == 0);

    // Test case 4: First string is "testing" and second string is "testing"
    str1 = "testing";
    str2 = "testing";
    assert(equal_strings(str1, str2) == 1);

    // Test case 5: First string is "Hello" and second string is "hello"
    str1 = "Hello";
    str2 = "hello";
    assert(equal_strings(str1, str2) == 0);

    // Test case 6: First string is "12345" and second string is "54321"
    str1 = "12345";
    str2 = "54321";
    assert(equal_strings(str1, str2) == 0);
}

int main()
{
    test_equal_strings();
    printf("All test cases passed!\n");
    return 0;
}