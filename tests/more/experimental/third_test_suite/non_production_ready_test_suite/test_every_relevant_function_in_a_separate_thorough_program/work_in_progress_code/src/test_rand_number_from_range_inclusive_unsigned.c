#include "../foundationallib.h"
#include <assert.h>
#include <stdio.h>
void test_rand_number_from_range_inclusive_unsigned()
{
    // Test with min equal to max
    assert(rand_number_from_range_inclusive_unsigned(5, 5) == 5);

    // Test with min less than max
    unsigned long result = rand_number_from_range_inclusive_unsigned(5, 10);
    assert(result >= 5 && result <= 10);

    // Test with min greater than max
    result = rand_number_from_range_inclusive_unsigned(10, 5);
    assert(result >= 5 && result <= 10);
}

int main()
{
    test_rand_number_from_range_inclusive_unsigned();
    printf("All tests passed successfully!\n");
    return 0;
}
