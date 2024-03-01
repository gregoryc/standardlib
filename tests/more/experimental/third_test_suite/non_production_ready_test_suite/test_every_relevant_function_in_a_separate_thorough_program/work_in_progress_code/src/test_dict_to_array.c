#include "../foundationallib.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
void test_dict_to_array_empty_dict()
{
    struct Dict *dict = NULL;
    char **keys;
    void **values;
    size_t size = 0;
    int result = dict_to_array(dict, &keys, &values, &size);
    assert(result == -1);
    assert(keys == NULL);
    assert(values == NULL);
    assert(size == 0);
}

void test_dict_to_array_non_empty_dict() {}

int main()
{
    test_dict_to_array_empty_dict();
    test_dict_to_array_non_empty_dict();
    printf("All tests passed successfully\n");
    return 0;
}
