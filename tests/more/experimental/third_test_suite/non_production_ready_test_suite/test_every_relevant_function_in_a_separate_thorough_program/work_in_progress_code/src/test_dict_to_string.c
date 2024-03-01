#include "../foundationallib.h"

#include <assert.h>
#include <stdlib.h>
#include <string.h>
void test_dict_to_string()
{
    struct Dict *d = dict_new_instance();

    // Test pointer format
    char *ptr_str = dict_to_string(&d, 0);
    // Check that ptr_str is not NULL
    assert(ptr_str != NULL);
    // Free the memory allocated for ptr_str
    free(ptr_str);

    // Test string format
    char *str_str = dict_to_string(&d, 1);
    // Check that str_str is not NULL
    assert(str_str != NULL);
    // Free the memory allocated for str_str
    free(str_str);
}

int main()
{
    test_dict_to_string();
    return 0;
}
