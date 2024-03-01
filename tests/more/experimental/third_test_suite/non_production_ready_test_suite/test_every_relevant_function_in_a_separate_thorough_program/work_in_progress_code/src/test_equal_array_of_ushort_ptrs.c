#include "../foundationallib.h"
#include <assert.h>

int main()
{
    // Test case 1: Arrays are equal
    const unsigned short arr1[] = {1, 2, 3, 4};
    const unsigned short arr2[] = {1, 2, 3, 4};
    const unsigned short *ptr1[] = {arr1, arr1 + 1, arr1 + 2, arr1 + 3};
    const unsigned short *ptr2[] = {arr2, arr2 + 1, arr2 + 2, arr2 + 3};
    assert(equal_array_of_ushort_ptrs(ptr1, ptr2, 4) == 1);

    // Test case 2: Arrays are not equal
    const unsigned short arr3[] = {1, 2, 3, 4};
    const unsigned short arr4[] = {4, 3, 2, 1};
    const unsigned short *ptr3[] = {arr3, arr3 + 1, arr3 + 2, arr3 + 3};
    const unsigned short *ptr4[] = {arr4, arr4 + 1, arr4 + 2, arr4 + 3};
    assert(equal_array_of_ushort_ptrs(ptr3, ptr4, 4) == 0);

    // Test case 3: Arrays of different sizes
    const unsigned short arr5[] = {1, 2, 3};
    const unsigned short arr6[] = {1, 2, 3, 4};
    const unsigned short *ptr5[] = {arr5, arr5 + 1, arr5 + 2};
    const unsigned short *ptr6[] = {arr6, arr6 + 1, arr6 + 2, arr6 + 3};
    assert(equal_array_of_ushort_ptrs(ptr5, ptr6, 3) == 0);

    // Add more test cases for corner cases here...

    return 0;
}
