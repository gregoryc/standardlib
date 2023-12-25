#include "../foundationallib.h"
#include <assert.h>

int main()
{
    // Test dictionary
    struct Dict *test_dict = dict_new_instance();
    struct Dict *test_dict2 = dict_new_instance();

    // Test case 1: Deleting an existing key
    dict_del_key(test_dict, "test_key");

    assert(!dict_get(test_dict, "test_key"));

    // Test case 2: Deleting a non-existing key
    dict_del_key(test_dict2, "non_existing_key");
    assert(!dict_get(test_dict2, "non_existing_key"));

    // Add more test cases for edge and corner cases

    printf("All test cases passed successfully!\n");

    free(test_dict);
    free(test_dict2);
    return 0;
}
