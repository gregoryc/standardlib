#include "../foundationallib.h"

#include <assert.h>
#include <stdio.h>
int main()
{
    assert(is_valid_integer("123456") == 1);
    assert(is_valid_integer("-123456") == 0);
    assert(is_valid_integer("12a3456") == 0);
    assert(is_valid_integer("0") == 1);
    assert(is_valid_integer("12345678901234567890") == 1);
    assert(is_valid_integer("") == 0);

    printf("All tests pass!\n");
    return 0;
}
