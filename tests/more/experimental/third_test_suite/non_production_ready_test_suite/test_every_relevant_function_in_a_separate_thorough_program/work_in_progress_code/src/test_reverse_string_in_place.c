#include "../foundationallib.h"
#include <assert.h>
#include <stdio.h>
#include <string.h>

void reverse_string_in_place(char *str)
{
    if (str == NULL)
    {
        return;
    }

    int len = strlen(str);
    if (len <= 1)
    {
        return;
    }

    int i = 0;
    int j = len - 1;
    while (i < j)
    {
        char temp = str[i];
        str[i] = str[j];
        str[j] = temp;
        i++;
        j--;
    }
}

void test_reverse_string()
{
    char str1[] = "hello";
    reverse_string_in_place(str1);
    assert(strcmp(str1, "olleh") == 0);

    char str2[] = "racecar";
    reverse_string_in_place(str2);
    assert(strcmp(str2, "racecar") == 0);

    char str3[] = "a";
    reverse_string_in_place(str3);
    assert(strcmp(str3, "a") == 0);

    char str4[] = "1234567890";
    reverse_string_in_place(str4);
    assert(strcmp(str4, "0987654321") == 0);

    char str5[] = "";
    reverse_string_in_place(str5);
    assert(strcmp(str5, "") == 0);
}

int main()
{
    test_reverse_string();
    printf("All tests passed!\n");

    return 0;
}
