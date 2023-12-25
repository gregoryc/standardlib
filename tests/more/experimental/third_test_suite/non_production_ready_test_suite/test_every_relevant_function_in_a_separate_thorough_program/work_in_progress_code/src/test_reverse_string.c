#include "../foundationallib.h"
#include <assert.h>
#include <string.h>

char *reverse_string(const char *str)
{
    if (str == NULL)
    {
        return NULL;
    }

    size_t len = strlen(str);
    char *reversed = (char *)malloc((len + 1) * sizeof(char));

    if (reversed == NULL)
    {
        return NULL;
    }

    for (size_t i = 0; i < len; i++)
    {
        reversed[i] = str[len - 1 - i];
    }
    reversed[len] = '\0';

    return reversed;
}

int main()
{
    char *result;

    // Test case 1: Empty string
    result = reverse_string("");
    assert(strcmp(result, "") == 0);
    free(result);

    // Test case 2: Single character string
    result = reverse_string("a");
    assert(strcmp(result, "a") == 0);
    free(result);

    // Test case 3: String with even length
    result = reverse_string("hello");
    assert(strcmp(result, "olleh") == 0);
    free(result);

    // Test case 4: String with odd length
    result = reverse_string("world");
    assert(strcmp(result, "dlrow") == 0);
    free(result);

    // Test case 5: Null input
    result = reverse_string(NULL);
    assert(result == NULL);

    return 0;
}