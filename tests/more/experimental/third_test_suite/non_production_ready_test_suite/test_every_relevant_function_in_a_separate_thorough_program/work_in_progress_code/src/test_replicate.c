#include "../foundationallib.h"
#include <assert.h>
#include <stdio.h>

// Function to be tested
void print_ushort_to_stream(const unsigned short value, FILE *stream) { fprintf(stream, "%hu", value); }

// Test cases

void test_print_ushort_to_stream_positive_value()
{
    FILE *stream = fopen("test_output.txt", "w");
    unsigned short test_value = 123;
    print_ushort_to_stream(test_value, stream);
    fclose(stream);
    FILE *file = fopen("test_output.txt", "r");
    unsigned short result_value;
    fscanf(file, "%hu", &result_value);
    fclose(file);
    assert(result_value == test_value);
}

void test_print_ushort_to_stream_zero_value()
{
    FILE *stream = fopen("test_output.txt", "w");
    unsigned short test_value = 0;
    print_ushort_to_stream(test_value, stream);
    fclose(stream);
    FILE *file = fopen("test_output.txt", "r");
    unsigned short result_value;
    fscanf(file, "%hu", &result_value);
    fclose(file);
    assert(result_value == test_value);
}

void test_print_ushort_to_stream_max_value()
{
    FILE *stream = fopen("test_output.txt", "w");
    unsigned short test_value = USHRT_MAX;
    print_ushort_to_stream(test_value, stream);
    fclose(stream);
    FILE *file = fopen("test_output.txt", "r");
    unsigned short result_value;
    fscanf(file, "%hu", &result_value);
    fclose(file);
    assert(result_value == test_value);
}

int main()
{
    test_print_ushort_to_stream_positive_value();
    test_print_ushort_to_stream_zero_value();
    test_print_ushort_to_stream_max_value();
    printf("All tests passed!\n");
    return 0;
}
