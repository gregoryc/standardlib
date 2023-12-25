#include "../foundationallib.h"
#include <assert.h>
int main()
{
    // Test cases
    assert(last_index_of_char("hello", 'l') == 3);
    assert(last_index_of_char("hello", 'o') == 4);
    assert(last_index_of_char("hello", 'h') == 0);
    assert(last_index_of_char("hello", 'z') == -1);
    assert(last_index_of_char("", 'a') == -1);
    assert(last_index_of_char("hello", '\0') == -1);

    printf("All tests passed!\n");
    return 0;
}
