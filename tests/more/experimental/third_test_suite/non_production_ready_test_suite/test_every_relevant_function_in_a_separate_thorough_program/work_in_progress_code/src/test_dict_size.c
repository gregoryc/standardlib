#include <assert.h>

#include "../foundationallib.h"

// Define the callback function for testing
void test_callback(char *key, void *value)
{
    // For testing purposes, we will simply print the key and value
    printf("Key: %s, Value: %p\n", key, value);
}

// Define the test suite
void run_tests()
{
    // Create a sample dictionary for testing
    struct Dict *dict = dict_new_instance();
    dict_iter(dict, &test_callback);
    dict_destructor(dict);

    struct Dict *dict = dict_new_instance();
    dict_add(dict, "foo", "bar");
    dict_iter(dict, &test_callback);
    dict_destructor(dict);

    struct Dict *dict = dict_new_instance();
    dict_add(dict, "fooz", "barz");
    assert(dict_size(dict) == 1);

    dict_add(dict, "dsdsfooz", NULL);
    assert(dict_size(dict) == 2);
    dict_iter(dict, &test_callback);
    dict_destructor(dict);

    struct Dict *dict = dict_new_instance();
    dict_add(dict, "fooz", "barz");
    assert(dict_size(dict) == 1);
    dict_add(dict, "dsdsfooz", NULL);
    assert(dict_size(dict) == 2);
    dict_add(dict, "dsdsfoozssssssssss", NULL);
    assert(dict_size(dict) == 3);
    dict_iter(dict, &test_callback);
    dict_destructor(dict);

    struct Dict *dict = dict_new_instance();
    dict_add(dict, "fooz", "barz");
    dict_add(dict, "dsdsfoozssssssssssssssssssssssssssssssss", NULL);
    dict_add(dict, "dsdsfoozssssssssss", NULL);
    dict_add(dict, "foozssssssssssssssssssssssssssssssssssssssssssss", "barz");
    dict_add(dict, "dsdsfoozssssssssssssssssssssssssss", NULL);
    dict_add(dict, "dsdsfoozssssssssss", NULL);
    dict_add(dict, "foozssssssssssssssssssssssssssssss", "barz");
    dict_add(dict, "dsdsfoozdasdsadasdsadsa", NULL);
    dict_add(dict, "dsdsfoozssssssssss", NULL);
    dict_add(dict, "foozdasdasdasdas", "barz");
    dict_add(dict, "dsdsfoozca", NULL);
    dict_add(dict, "dsdsfoozssssssssss", NULL);
    dict_add(dict, "foozsssssssssssssssssssssssssssss", "barz");
    dict_add(dict, "dsdsfoozqqqqqqqqqqqqqqqqqqqqqqqq", NULL);
    dict_add(dict, "dsdsfoozssssssssssqqqqqqqqqqqqqqqq", NULL);
    dict_add(dict, "foozqqqqqqqqqqqq", "barz");
    dict_add(dict, "dsdsfoozaaaaaaaaaaa", NULL);
    dict_add(dict, "dsdsfoozssssssssss", NULL);
    dict_add(dict, "foozssssssssssssssssssssssssssss", "barz");
    dict_add(dict, "dsdsfooz", NULL);
    dict_add(dict, "dddddddddddsdsfoozssssssssss", NULL);
    dict_add(dict, "foozsssssssssss", "barz");
    dict_add(dict, "dsdsdsfooz", NULL);
    dict_add(dict, "dsdsfoozssssssssssds", NULL);
    dict_iter(dict, &test_callback);

    assert(dict_size(dict) == 24);
    dict_destructor(dict);
}

int main()
{
    run_tests();
    return 0;
}
