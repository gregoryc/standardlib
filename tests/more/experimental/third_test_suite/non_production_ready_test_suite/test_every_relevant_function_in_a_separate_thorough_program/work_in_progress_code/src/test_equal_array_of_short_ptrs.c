#include "../foundationallib.h"

#include <assert.h>
#include <stdio.h>

FOUNDATIONAL_LIB_FUNC int equal_array_of_short_ptrs(const short **array, const short **array2, size_t size)
{
    for (size_t i = 0; i < size; i++)
    {
        if (*array[i] != *array2[i])
        {
            return 0;
        }
    }
    return 1;
}

void test_equal_array_of_short_ptrs()
{
    const short s1[] = {1, 2, 3};
    const short s2[] = {1, 2, 3};
    const short s3[] = {1, 3, 3};
    const short *p1[] = {s1, s2};
    const short *p2[] = {s1, s2};
    const short *p3[] = {s1, s3};

    assert(equal_array_of_short_ptrs(p1, p2, 2) == 1);
    assert(equal_array_of_short_ptrs(p1, p3, 2) == 0);
}

int main()
{
    test_equal_array_of_short_ptrs();
    printf("All tests passed successfully!\n");
    return 0;
}
