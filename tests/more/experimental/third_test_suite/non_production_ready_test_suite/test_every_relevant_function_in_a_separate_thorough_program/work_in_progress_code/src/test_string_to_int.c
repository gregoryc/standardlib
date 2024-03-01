#include "../foundationallib.h"
#include <assert.h>
#include <stdio.h>
void test_valid_integer()
{
    const char *str = "12345";
    int result = string_to_int(str);
    assert(result == 12345);
}

void test_negative_integer()
{
    const char *str = "-54321";
    int result = string_to_int(str);
    assert(result == -54321);
}

void test_zero()
{
    const char *str = "0";
    int result = string_to_int(str);
    assert(result == 0);
}

void test_large_integer()
{
    const char *str = "2147483647"; // INT_MAX
    int result = string_to_int(str);
    assert(result == 2147483647);
    // edge case for signed int
    const char *negative_str = "-2147483648"; // INT_MIN
    int negative_result = string_to_int(negative_str);
    assert(negative_result == -2147483648);
}

void test_invalid_integer()
{
    const char *str = "123abc";
    // behavior is undefined for invalid integer representation
    // so we can't use assert for this case
    string_to_int(str);
    // no assert for this case
}

int main()
{
    test_valid_integer();
    test_negative_integer();
    test_zero();
    test_large_integer();
    test_invalid_integer();

    printf("All tests passed successfully\n");
    return 0;
}
