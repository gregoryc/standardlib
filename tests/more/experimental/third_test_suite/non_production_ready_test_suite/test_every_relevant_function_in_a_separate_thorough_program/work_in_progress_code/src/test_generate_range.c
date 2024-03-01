#include "../foundationallib.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

int *generate_range(int start, int end, int step, size_t *range_size)
{
    if (step == 0)
    {
        *range_size = 0;
        return NULL;
    }

    int size = (end - start) / step + 1;
    int *result = (int *)malloc(size * sizeof(int));

    int value = start;
    for (int i = 0; i < size; i++)
    {
        result[i] = value;
        value += step;
    }

    *range_size = size;
    return result;
}

void test_generate_range()
{
    size_t range_size;

    // Test case 1: Normal range
    int *range1 = generate_range(0, 5, 1, &range_size);
    assert(range1 != NULL);
    assert(range_size == 6);
    for (int i = 0; i < 6; i++)
    {
        assert(range1[i] == i);
    }
    free(range1);

    // Test case 2: Negative step
    int *range2 = generate_range(10, 5, -2, &range_size);
    assert(range2 != NULL);
    assert(range_size == 3);
    assert(range2[0] == 10);
    assert(range2[1] == 8);
    assert(range2[2] == 6);
    free(range2);

    // Test case 3: Step is zero
    int *range3 = generate_range(-2, 2, 0, &range_size);
    assert(range3 == NULL);
    assert(range_size == 0);
}

int main()
{
    test_generate_range();
    printf("All tests passed successfully!\n");
    return 0;
}
