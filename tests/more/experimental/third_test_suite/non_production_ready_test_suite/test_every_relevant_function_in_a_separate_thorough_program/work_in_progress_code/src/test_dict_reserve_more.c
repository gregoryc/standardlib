#include <assert.h>

#include "../foundationallib.h"

void test_dict_reserve_more()
{
    // Test case 1: testing with a valid dictionary and a positive number of new elements
    struct Dict *dict1 = dict_new_instance();
    assert(dict_reserve_more(dict1, 10) == 0);

    // Test case 2: testing with a valid dictionary and zero number of new elements
    struct Dict *dict2 = dict_new_instance();
    assert(dict_reserve_more(dict2, 0) == 0);
}

int main()
{
    test_dict_reserve_more();
    printf("All tests passed successfully!\n");
    return 0;
}
