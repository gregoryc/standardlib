#include "../foundationallib.h"
#include <assert.h>
int main()
{
    // Test cases
    const char *testCases[] = {
        "hello",                      // basic test case
        "",                           // empty string
        "1234567890",                 // numeric string
        "abcdefghijklmnopqrstuvwxyz", // lowercase alphabets
        "ABCDEFGHIJKLMNOPQRSTUVWXYZ", // uppercase alphabets
        "!@#$%^&*()",                 // special characters
        "12345abcde!",                // combination of numbers and characters
        "hello",                      // identical to first test case for collision
        "world",                      // different from first test case for non-collision
    };

    size_t capacities[] = {
        10,   // small capacity
        100,  // medium capacity
        1000, // large capacity
        10000 // very large capacity
    };

    int numTestCases = sizeof(testCases) / sizeof(testCases[0]);
    int numCapacities = sizeof(capacities) / sizeof(capacities[0]);

    for (int i = 0; i < numTestCases; i++)
    {
        for (int j = 0; j < numCapacities; j++)
        {
            size_t hashValue = set_hash(testCases[i], capacities[j]);

            printf("Hash value for '%s' with capacity %zu: %zu\n", testCases[i], capacities[j], hashValue);

            // Test capacity range
            assert(hashValue < capacities[j]);
        }
    }

    printf("All tests passed!\n");

    return 0;
}
