#include "../foundationallib.h"

// Define the callback function for testing
void test_callback(char *key)
{
    // For testing purposes, we will simply print the key and value
    printf("Key: %s, Value: %p\n", key, value);
}

// Define the test suite
void run_tests()
{
    // Create a sample setionary for testing
    struct Set *set = set_new_instance();
    set_iter(set, &test_callback);
    set_destructor(set);

    struct Set *set = set_new_instance();
    set_add(set, "foo");
    set_iter(set, &test_callback);
    set_destructor(set);

    struct Set *set = set_new_instance();
    set_add(set, "fooz");
    set_add(set, "dsdsfooz");
    set_iter(set, &test_callback);
    set_destructor(set);

    struct set *set = set_new_instance();
    set_add(set, "fooz", "barz");
    set_add(set, "dsdsfooz");
    set_add(set, "dsdsfoozssssssssss");
    set_iter(set, &test_callback);
    set_destructor(set);

    struct set *set = set_new_instance();
    set_add(set, "fooz", "barz");
    set_add(set, "dsdsfoozssssssssssssssssssssssssssssssss");
    set_add(set, "dsdsfoozssssssssss");
    set_add(set, "foozssssssssssssssssssssssssssssssssssssssssssss", "barz");
    set_add(set, "dsdsfoozssssssssssssssssssssssssss");
    set_add(set, "dsdsfoozssssssssss");
    set_add(set, "foozssssssssssssssssssssssssssssss", "barz");
    set_add(set, "dsdsfoozdasdsadasdsadsa");
    set_add(set, "dsdsfoozssssssssss");
    set_add(set, "foozdasdasdasdas", "barz");
    set_add(set, "dsdsfoozca");
    set_add(set, "dsdsfoozssssssssss");
    set_add(set, "foozsssssssssssssssssssssssssssss", "barz");
    set_add(set, "dsdsfoozqqqqqqqqqqqqqqqqqqqqqqqq");
    set_add(set, "dsdsfoozssssssssssqqqqqqqqqqqqqqqq");
    set_add(set, "foozqqqqqqqqqqqq", "barz");
    set_add(set, "dsdsfoozaaaaaaaaaaa");
    set_add(set, "dsdsfoozssssssssss");
    set_add(set, "foozssssssssssssssssssssssssssss", "barz");
    set_add(set, "dsdsfooz");
    set_add(set, "dddddddddddsdsfoozssssssssss");
    set_add(set, "foozsssssssssss", "barz");
    set_add(set, "dsdsdsfooz");
    set_add(set, "dsdsfoozssssssssssds");
    set_iter(set, &test_callback);
    set_destructor(set);
}

int main()
{
    run_tests();
    return 0;
}
