#include "../foundationallib.h"

#include <assert.h>
#include <string.h>

int is_array_digit(const char *arr[], size_t size)
{
    // Check for NULL array or empty array
    if (arr == NULL || size == 0)
    {
        return 1;
    }

    // Iterate through the array to check each string
    for (size_t i = 0; i < size; i++)
    {
        if (arr[i] == NULL || *arr[i] == '\0')
        {
            continue; // Treat NULL or empty string as containing only digits
        }

        // Check if the string contains non-digit characters
        for (size_t j = 0; j < strlen(arr[i]); j++)
        {
            if (arr[i][j] < '0' || arr[i][j] > '9')
            {
                return 0; // Non-digit character found
            }
        }
    }

    return 1; // All strings contain only digits
}

int main()
{
    // Test cases for is_array_digit function

    // Empty array
    const char *emptyArray[] = {};
    assert(is_array_digit(emptyArray, 0) == 1);

    // NULL array
    assert(is_array_digit(NULL, 5) == 1);

    // Array with all digit strings
    const char *allDigitArray[] = {"123", "456", "789"};
    assert(is_array_digit(allDigitArray, 3) == 1);

    // Array with non-digit strings
    const char *nonDigitArray[] = {"123", "4A6", "789"};
    assert(is_array_digit(nonDigitArray, 3) == 0);

    // Array with empty strings
    const char *emptyStringArray[] = {"123", "", "789"};
    assert(is_array_digit(emptyStringArray, 3) == 1);

    // Array with NULL strings
    const char *nullStringArray[] = {"123", NULL, "789"};
    assert(is_array_digit(nullStringArray, 3) == 1);

    // Array with non-null-terminated string
    const char *nonNullTerminatedArray[] = {"123", "4567", "789"};
    assert(is_array_digit(nonNullTerminatedArray, 3) == 0);

    return 0;
}
