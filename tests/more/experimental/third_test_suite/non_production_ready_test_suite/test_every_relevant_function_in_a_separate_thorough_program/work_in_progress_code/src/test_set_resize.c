#include "../foundationallib.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
int main()
{
    // Test case 1: Resize a Set with initial size 3
    Set *set1 = set_init(3);
    assert(set1 != NULL);
    assert(set1->size == 0);
    assert(set1->capacity == 3);
    assert(set_resize(set1) == 1);
    assert(set1->capacity == 6);

    // Test case 2: Resize a Set with initial size 0
    Set *set2 = set_init(0);
    assert(set2 != NULL);
    assert(set2->size == 0);
    assert(set2->capacity == 0);
    assert(set_resize(set2) == 1);
    assert(set2->capacity == 0); // Should remain 0

    // Test case 3: Resize a NULL Set
    Set *set3 = NULL;
    assert(set_resize(set3) == 0);

    printf("All tests passed successfully.\n");

    // Free memory and return
    if (set1)
        free(set1->data);
    free(set1);
    if (set2)
        free(set2->data);
    free(set2);
    return 0;
}
