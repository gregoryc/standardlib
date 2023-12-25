#include "../foundationallib.h"
#include <assert.h>

// Test cases
void test_null_keys()
{
    struct Dict *dict = dict_new_instance();
    size_t size;
    char **keys;

    void **values;
    dict_to_array(dict, &keys, &values, &size);
    dict_del_keys(keys);
    dict_del_values(values);

    dict_destructor(dict);
}

void test_single_key()
{
    struct Dict *dict = dict_new_instance();
    size_t size;
    dict_add(dict, "foo", "bar");

    char **keys;

    void **values;
    dict_to_array(dict, &keys, &values, &size);
    dict_del_keys(keys);
    dict_del_values(values);
    dict_destructor(dict);
}

void test_multiple_keys()
{
    struct Dict *dict = dict_new_instance();
    size_t size;
    dict_add(dict, "foo", "bar");
    dict_add(dict, "dasdasdasdas", "dasdasdasdas");
    dict_add(dict, "q1qqqqqqqqqqqqq", "bar");
    dict_add(dict, "qqqqqqqqqqqqqqqqqqqfoo", "bardas");
    dict_add(dict, "fossssssso", "badsar");
    dict_add(dict, "cat", "dsabar");
    dict_add(dict, "leopard", "dasdasdasbar");
    dict_add(dict, "!!!!!!!!!!!!!!!!!!", "badddr");
    dict_add(dict, "fdsadasoo", "bar");
    dict_add(dict, "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^", "bar");
    dict_add(dict, "$$$$$$$$$$$$$$$$$$", "bar");
    dict_add(dict, "_", "bar");
    dict_add(dict, "fodso", "bar");
    dict_add(dict, "foodsa", "bar");

    char **keys;

    void **values;
    dict_to_array(dict, &keys, &values, &size);
    dict_del_keys(keys);
    dict_del_values(values);
    dict_destructor(dict);
}

int main()
{

    test_null_keys();
    test_single_key();
    test_multiple_keys();
    return 0;
}
