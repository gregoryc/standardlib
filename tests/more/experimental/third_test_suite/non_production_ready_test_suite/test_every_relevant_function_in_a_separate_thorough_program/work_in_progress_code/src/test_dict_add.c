#include "../foundationallib.h"
#include <assert.h>
// Define the dictionary structure
struct Dict
{
    char *key;
    void *value;
};

// Test function for dict_add
void test_dict_add()
{
    // Create a new dictionary
    struct Dict *dict = (struct Dict *)malloc(sizeof(struct Dict));
    assert(dict != NULL);

    // Test adding a key-value pair
    const char *key1 = "key1";
    int value1 = 10;
    assert(dict_add(dict, key1, &value1) == 0);
    assert(strcmp(dict->key, key1) == 0);
    assert(*(int *)dict->value == value1);

    // Test adding a duplicate key
    const char *key2 = "key2";
    int value2 = 20;
    assert(dict_add(dict, key2, &value2) == 0);
    assert(strcmp(dict->key, key2) == 0);
    assert(*(int *)dict->value == value2);

    // Test adding NULL key
    assert(dict_add(dict, NULL, &value1) == -1);

    // Test adding NULL value
    const char *key3 = "key3";
    assert(dict_add(dict, key3, NULL) == -1);

    // Test adding to a NULL dictionary
    assert(dict_add(NULL, key1, &value1) == -1);

    free(dict);
}

int main()
{
    test_dict_add();
    printf("All tests passed successfully\n");
    return 0;
}
