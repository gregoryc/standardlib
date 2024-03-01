#include "../foundationallib.h"
#include <assert.h>

// Test cases
void test_arraydup()
{
    int source[] = {1, 2, 3, 4, 5};
    int num_elements = 5;

    // Test case 1: Test duplication of integers
    int *result = (int *)arraydup(source, num_elements, sizeof(int));
    for (int i = 0; i < num_elements; i++)
    {
        assert(result[i] == source[i]);
    }
    free(result);

    // Test case 2: Test duplication of characters
    char source_chars[] = {'a', 'b', 'c', 'd', 'e'};
    char *result_chars = (char *)arraydup(source_chars, num_elements, sizeof(char));
    for (int i = 0; i < num_elements; i++)
    {
        assert(result_chars[i] == source_chars[i]);
    }
    free(result_chars);
}

int main()
{
    test_arraydup();
    printf("All test cases passed!\n");
    return 0;
}
