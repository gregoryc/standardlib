#include "../foundationallib.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
// Test function for the frozen_dict_del_values
void test_frozen_dict_del_values()
{
    // Test case 1: Deleting a single value
    {
        void *singleValue = malloc(sizeof(int));
        frozen_dict_del_values(&singleValue);
        assert(singleValue == NULL);
    }

    // Test case 2: Deleting multiple values
    {
        void *value1 = malloc(sizeof(int));
        void *value2 = malloc(sizeof(double));
        void *value3 = malloc(sizeof(char));

        void *values[] = {value1, value2, value3};
        frozen_dict_del_values(values);

        assert(value1 == NULL);
        assert(value2 == NULL);
        assert(value3 == NULL);
    }

    // Test case 3: Deleting from an empty dictionary
    {
        void *values[] = {NULL};
        frozen_dict_del_values(values);
        // No assertion because the function should handle this case gracefully
    }

    // Test case 4: Deleting from a large dictionary
    {
        const int dictSize = 1000;
        void *values[dictSize];
        for (int i = 0; i < dictSize; i++)
        {
            values[i] = malloc(sizeof(int));
        }

        // Delete all values
        frozen_dict_del_values(values);

        for (int i = 0; i < dictSize; i++)
        {
            assert(values[i] == NULL);
        }
    }

    // Additional corner cases can be added here
}

int main()
{
    // Run the test cases
    test_frozen_dict_del_values();
    printf("All tests passed!\n");

    return 0;
}
