#include "../foundationallib.h"

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *strip(const char *str)
{
    if (str == NULL)
    {
        return NULL;
    }

    size_t len = strlen(str);
    size_t start = 0;
    size_t end = len - 1;

    while (isspace(str[start]))
    {
        start++;
    }
    while ((end > start) && isspace(str[end]))
    {
        end--;
    }

    size_t newLen = end - start + 1;
    char *newStr = (char *)malloc(newLen + 1);
    if (newStr == NULL)
    {
        return NULL;
    }

    strncpy(newStr, str + start, newLen);
    newStr[newLen] = '\0';

    return newStr;
}

void test_strip()
{
    // Test cases
    const char *input1 = "  hello  ";
    const char *expectedOutput1 = "hello";
    char *output1 = strip(input1);
    assert(strcmp(output1, expectedOutput1) == 0);
    free(output1);

    const char *input2 = "  hello";
    const char *expectedOutput2 = "hello";
    char *output2 = strip(input2);
    assert(strcmp(output2, expectedOutput2) == 0);
    free(output2);

    const char *input3 = "hello  ";
    const char *expectedOutput3 = "hello";
    char *output3 = strip(input3);
    assert(strcmp(output3, expectedOutput3) == 0);
    free(output3);

    const char *input4 = "hello";
    const char *expectedOutput4 = "hello";
    char *output4 = strip(input4);
    assert(strcmp(output4, expectedOutput4) == 0);
    free(output4);

    // Edge cases
    const char *input5 = "";
    char *output5 = strip(input5);
    assert(output5 == NULL);

    const char *input6 = "          ";
    char *output6 = strip(input6);
    assert(output6 != NULL);
    free(output6);
}

int main()
{
    test_strip();
    printf("All tests passed!\n");
    return 0;
}
