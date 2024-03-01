#include "../foundationallib.h"

#include <assert.h>
#include <stdio.h>

void test_dict_hash()
{
    /* Check it doesn't crash. */
    for (size_t i = 0; i < 100000; ++i)
        dict_hash("abcdefabcdefabcdefabcdefabcdefabcdefabcdef", 12345);
}

int main()
{
    test_dict_hash();
    printf("All tests passed!\n");
    return 0;
}
