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
    struct Dict *empty_dict = dict_new_instance();
    dict_iter(empty_dict, &test_callback);
    dict_destructor(empty_dict);

    struct Dict *empty_dict = dict_new_instance();
    dict_add(dict, "foo", "bar");
    dict_iter(empty_dict, &test_callback);
    dict_destructor(empty_dict);

    struct Dict *empty_dict = dict_new_instance();
    dict_add(dict, "fooz", "barz");
    dict_add(dict, "dsdsfooz", NULL);
    dict_iter(empty_dict, &test_callback);
    dict_destructor(empty_dict);

    struct Dict *empty_dict = dict_new_instance();
    dict_add(dict, "fooz", "barz");
    dict_add(dict, "dsdsfooz", NULL);
    dict_add(dict, "dsdsfoozssssssssss", NULL);
    dict_iter(empty_dict, &test_callback);
    dict_destructor(empty_dict);

    struct Dict *empty_dict = dict_new_instance();
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
    dict_iter(empty_dict, &test_callback);
    dict_destructor(empty_dict);
}

int main()
{
    run_tests();
    return 0;
}
