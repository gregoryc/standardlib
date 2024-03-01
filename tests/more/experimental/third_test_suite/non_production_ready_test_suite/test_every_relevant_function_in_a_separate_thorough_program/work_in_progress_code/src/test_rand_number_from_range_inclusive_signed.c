#include "../foundationallib.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

FOUNDATIONAL_LIB_FUNC long rand_number_from_range_inclusive_signed(signed long min, signed long max) { return min + rand() % (max - min + 1); }

int main()
{
    // Test for range [-10, 10]
    for (int i = 0; i < 1000; i++)
    {
        long num = rand_number_from_range_inclusive_signed(-10, 10);
        assert(num >= -10 && num <= 10);
    }

    // Test for range [0, 100]
    for (int i = 0; i < 1000; i++)
    {
        long num = rand_number_from_range_inclusive_signed(0, 100);
        assert(num >= 0 && num <= 100);
    }

    // Test for range [-100, 0]
    for (int i = 0; i < 1000; i++)
    {
        long num = rand_number_from_range_inclusive_signed(-100, 0);
        assert(num >= -100 && num <= 0);
    }

    // Test for range [-10000, 10000]
    for (int i = 0; i < 1000; i++)
    {
        long num = rand_number_from_range_inclusive_signed(-10000, 10000);
        assert(num >= -10000 && num <= 10000);
    }

    printf("All tests passed successfully!\n");

    return 0;
}
