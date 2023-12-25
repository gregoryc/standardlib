#include "../foundationallib.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
void test_select_array()
{
    int source1[] = {1, 2, 3, 4, 5};
    size_t result_size;
    int *result1 = select_array(source1, 5, sizeof(int), even_condition, &result_size);
    assert(result1[0] == 2);
    assert(result1[1] == 4);
    assert(result_size == 2);
    free(result1);

    int source2[] = {1, -2, 3, -4, 5};
    int *result2 = select_array(source2, 5, sizeof(int), positive_condition, &result_size);
    assert(result2[0] == 1);
    assert(result2[1] == 3);
    assert(result2[2] == 5);
    assert(result_size == 3);
    free(result2);
}

int main()
{
    test_select_array();
    printf("All tests passed!\n");
    return 0;
}
