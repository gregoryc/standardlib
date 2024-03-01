#include "../foundationallib.h"
#include <assert.h>

// Function to be tested
double calculate_average_in_int_array(const int *array, size_t size);

// Test cases
void test_empty_array()
{
    int array[] = {};
    size_t size = 0;
    double result = calculate_average_in_int_array(array, size);
    assert(result == 0.0);
}

void test_single_element_array()
{
    int array[] = {5};
    size_t size = 1;
    double result = calculate_average_in_int_array(array, size);
    assert(result == 5.0);
}

void test_positive_numbers_array()
{
    int array[] = {1, 2, 3, 4, 5};
    size_t size = 5;
    double result = calculate_average_in_int_array(array, size);
    assert(result == 3.0);
}

void test_negative_numbers_array()
{
    int array[] = {-3, -1, 2, 4, 6};
    size_t size = 5;
    double result = calculate_average_in_int_array(array, size);
    assert(result == 1.6);
}

void test_mixed_numbers_array()
{
    int array[] = {-2, 5, -8, 10, 4};
    size_t size = 5;
    double result = calculate_average_in_int_array(array, size);
    assert(result == 1.8);
}

void test_large_numbers_array()
{
    int array[10000];
    for (int i = 0; i < 10000; i++)
    {
        array[i] = i * 2;
    }
    size_t size = 10000;
    double result = calculate_average_in_int_array(array, size);
    assert(result == 9999.0);
}

int main()
{
    test_empty_array();
    test_single_element_array();
    test_positive_numbers_array();
    test_negative_numbers_array();
    test_mixed_numbers_array();
    test_large_numbers_array();

    return 0;
}
