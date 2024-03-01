#include "../foundationallib.h"

#define _CRT_SECURE_NO_WARNINGS
#include <assert.h>
#include <stdio.h>

// Function to be tested
void map_int(int *array, size_t size, int (*transform)(int))
{
    for (size_t i = 0; i < size; i++)
    {
        array[i] = transform(array[i]);
    }
}

// Test suite
void test_map_int()
{
    // Test case 1: Test with an empty array
    int empty_array[] = {};
    map_int(empty_array, 0, NULL); // No transformation function, should not crash

    // Test case 2: Test with positive numbers
    int positive_array[] = {1, 2, 3, 4, 5};
    map_int(positive_array, 5, NULL); // No transformation function, should not crash
    assert(positive_array[0] == 1);
    assert(positive_array[1] == 2);
    assert(positive_array[2] == 3);
    assert(positive_array[3] == 4);
    assert(positive_array[4] == 5);

    // Test case 3: Test with a transformation function
    int square_array[] = {1, 2, 3, 4, 5};
    map_int(square_array, 5, square_transform); // User-defined transformation function
    assert(square_array[0] == 1);
    assert(square_array[1] == 4);
    assert(square_array[2] == 9);
    assert(square_array[3] == 16);
    assert(square_array[4] == 25);

    // Test case 4: Test with negative numbers
    int negative_array[] = {-1, -2, -3, -4, -5};
    map_int(negative_array, 5, NULL); // No transformation function, should not crash
    assert(negative_array[0] == -1);
    assert(negative_array[1] == -2);
    assert(negative_array[2] == -3);
    assert(negative_array[3] == -4);
    assert(negative_array[4] == -5);
}

// User-defined transformation function
int square_transform(int x) { return x * x; }

int main()
{
    test_map_int();
    printf("All tests passed!\n");
    return 0;
}
