#include "../foundationallib.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Set
{
    char *key;
    struct Set *next;
};

FOUNDATIONAL_LIB_FUNC int set_add(struct Set *set, const char *key)
{
    if (set == NULL || key == NULL)
    {
        return -1; // Error: NULL pointer
    }

    struct Set *new_set = (struct Set *)malloc(sizeof(struct Set));
    if (new_set == NULL)
    {
        return -1; // Error: Memory allocation failed
    }

    new_set->key = strdup(key);
    new_set->next = set->next;
    set->next = new_set;

    return 0; // Success
}

void test_set_add()
{
    struct Set *set = (struct Set *)malloc(sizeof(struct Set));
    assert(set_add(set, "key1") == -1); // Error: NULL pointer
    free(set);

    set = (struct Set *)malloc(sizeof(struct Set));
    set->key = strdup("key1");
    set->next = NULL;
    assert(set_add(NULL, "key2") == -1); // Error: NULL pointer
    free(set->key);
    free(set);

    set = (struct Set *)malloc(sizeof(struct Set));
    set->key = strdup("key1");
    set->next = NULL;
    assert(set_add(set, NULL) == -1); // Error: NULL pointer
    free(set->key);
    free(set);

    set = (struct Set *)malloc(sizeof(struct Set));
    set->key = strdup("key1");
    set->next = NULL;
    assert(set_add(set, "key2") == 0); // Success
    assert(strcmp(set->next->key, "key2") == 0);
    free(set->next->key);
    free(set->next);
    free(set);

    printf("All tests passed!\n");
}

int main()
{
    test_set_add();
    return 0;
}
