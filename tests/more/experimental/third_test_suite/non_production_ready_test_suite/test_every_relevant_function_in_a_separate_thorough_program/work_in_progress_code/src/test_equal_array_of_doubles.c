#include "../foundationallib.h"
#include <assert.h>
#include <stddef.h>

#define TEST_CASES 5

void test_equal_array_of_doubles()
{
    double array1[] = {1.0, 2.0, 3.0};
    double array2[] = {1.0, 2.0, 3.0};
    double array3[] = {3.0, 2.0, 1.0};
    double array4[] = {1.0, 2.0, 3.0, 4.0};
    double array5[] = {1.0, 2.0, 3.00000000001};

    // Test case 1: Arrays are equal
    assert(equal_array_of_doubles(array1, array2, 3) == 1);

    // Test case 2: Arrays are not equal
    assert(equal_array_of_doubles(array1, array3, 3) == 0);

    // Test case 3: Arrays have different sizes
    assert(equal_array_of_doubles(array1, array4, 3) == 0);

    // Test case 4: Arrays are almost equal
    assert(equal_array_of_doubles(array1, array5, 3) == 1);

    // Test case 5: Empty arrays are equal
    assert(equal_array_of_doubles(NULL, NULL, 0) == 1);
}

int main()
{
    test_equal_array_of_doubles();
    return 0;
}
