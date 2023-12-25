#include "../foundationallib.h"
#include <assert.h>

#define EPSILON 0.0000001

void test_str_to_double()
{
    assert(fabs(str_to_double("0") - 0.0) < EPSILON);
    assert(fabs(str_to_double("1") - 1.0) < EPSILON);
    assert(fabs(str_to_double("-1") + 1.0) < EPSILON);
    assert(fabs(str_to_double("3.14") - 3.14) < EPSILON);
    assert(fabs(str_to_double("-3.14") + 3.14) < EPSILON);
    assert(fabs(str_to_double("2.71828") - 2.71828) < EPSILON);
    assert(fabs(str_to_double("-2.71828") + 2.71828) < EPSILON);
    assert(fabs(str_to_double("1234567890.1234567890") - 1234567890.1234567890) < EPSILON);
    assert(fabs(str_to_double("-1234567890.1234567890") + 1234567890.1234567890) < EPSILON);

    // Add more test cases for corner cases such as
    // - Empty string
    // - String with only whitespace
    // - String with invalid characters
    // - String with extremely large or small numbers
    // - String with scientific notation

    // assert statements for corner cases will go here
}

int main()
{
    test_str_to_double();
    return 0;
}