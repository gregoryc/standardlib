#include "../foundationallib.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

struct Set
{
    int *elements;
    int size;
};

char *set_to_string(struct Set *set)
{
    // Assuming the set is not empty
    char *str = malloc(set->size * 2 + 3);
    if (str == NULL)
    {
        return NULL; // Memory allocation failed
    }
    str[0] = '{';
    int index = 1;
    for (int i = 0; i < set->size; i++)
    {
        index += sprintf(&str[index], "%d", set->elements[i]);
        if (i != set->size - 1)
        {
            str[index++] = ',';
            str[index++] = ' ';
        }
    }
    str[index++] = '}';
    str[index] = '\0';

    return str;
}

// Test cases
void test_set_to_string_empty()
{
    struct Set set = {NULL, 0};
    char *str = set_to_string(&set);
    assert(str != NULL);
    assert(strcmp(str, "{}") == 0);
    free(str);
}

void test_set_to_string_single_element()
{
    int elements[] = {5};
    struct Set set = {elements, 1};
    char *str = set_to_string(&set);
    assert(str != NULL);
    assert(strcmp(str, "{5}") == 0);
    free(str);
}

void test_set_to_string_multiple_elements()
{
    int elements[] = {3, 7, 12};
    struct Set set = {elements, 3};
    char *str = set_to_string(&set);
    assert(str != NULL);
    assert(strcmp(str, "{3, 7, 12}") == 0);
    free(str);
}

void test_set_to_string_null_set()
{
    char *str = set_to_string(NULL);
    assert(str == NULL);
}

int main()
{
    test_set_to_string_empty();
    test_set_to_string_single_element();
    test_set_to_string_multiple_elements();
    test_set_to_string_null_set();
    printf("All tests passed\n");
    return 0;
}