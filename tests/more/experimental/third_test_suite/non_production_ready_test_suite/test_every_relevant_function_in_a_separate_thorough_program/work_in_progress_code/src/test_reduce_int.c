#include "../foundationallib.h"
#include <assert.h>

FOUNDATIONAL_LIB_FUNC int reduce_int(int *array, size_t size, int (*operation)(int, int))
{
    int result = array[0];
    for (size_t i = 1; i < size; i++)
    {
        result = operation(result, array[i]);
    }
    return result;
}

// Test cases
void test_add_operation()
{
    int test_array[] = {1, 2, 3, 4, 5};
    int result = reduce_int(test_array, 5, add_operation);
    assert(result == 15);
}

void test_multiply_operation()
{
    int test_array[] = {1, 2, 3, 4, 5};
    int result = reduce_int(test_array, 5, multiply_operation);
    assert(result == 120);
}

int main()
{
    // Run test cases
    test_add_operation();
    test_multiply_operation();

    printf("All test cases passed!\n");

    return 0;
}

// Example binary operation function: addition
int add_operation(int x, int y) { return x + y; }

// Example binary operation function: multiplication
int multiply_operation(int x, int y) { return x * y; }
