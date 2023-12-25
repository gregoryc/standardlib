// Just a little benchmark program to test out libc.
//
// memmem() is REALLY fast.
//
// To compile
// gcc benchmark_libc.c -o benchmark_libc -O2 -Wall -Werror -Wextra -s -fwhole-program&& ./l | editor

#include "foundationallib.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

FOUNDATIONAL_LIB_FUNC void *FOUNDATIONAL_LIB_mempcpy(void *dest, const void *src, size_t n)
{
    char *d = dest;
    const char *s = src;

    while (n--)
    {
        *d++ = *s++;
    }

    return d;
}

FOUNDATIONAL_LIB_FUNC void FOUNDATIONAL_LIB_memcpy(char *restrict dest, const char *restrict src, size_t n)
{
    while (n--)
    {
        *dest++ = *src++;
    }
}
FOUNDATIONAL_LIB_FUNC char *FOUNDATIONAL_LIB_stpcpy(char *restrict dst, const char *restrict src)
{
    char *p;

    p = FOUNDATIONAL_LIB_mempcpy(dst, src, strlen(src));
    *p = '\0';

    return p;
}

FOUNDATIONAL_LIB_FUNC char *FOUNDATIONAL_LIB_STRCPY(char *restrict dst, const char *restrict src)
{
    stpcpy(dst, src);
    return dst;
}

FOUNDATIONAL_LIB_FUNC char *FOUNDATIONAL_LIB_FOUNDATIONAL_LIB_STRCAT(char *restrict dst, const char *restrict src)
{
    stpcpy(dst + strlen(dst), src);
    return dst;
}

FOUNDATIONAL_LIB_FUNC int FOUNDATIONAL_LIB_FUNC_memcmp(const void *s1, const void *s2, size_t n)
{
    const unsigned char *u1 = s1;
    const unsigned char *u2 = s2;

    while (n--)
    {
        if (*u1 != *u2)
        {
            return (*u1 < *u2) ? -1 : 1;
        }

        u1++;
        u2++;
    }

    return 0;
}

FOUNDATIONAL_LIB_FUNC void *memory_locate_(const void *haystack, size_t haystack_len, const void *needle, size_t needle_len)
{
    FOUNDATIONAL_LIB_ASSERT_ARGUMENT_IF_ENABLED(haystack);
    FOUNDATIONAL_LIB_ASSERT_ARGUMENT_IF_ENABLED(needle_len);
    if (FOUNDATIONAL_LIB_UNLIKELY(needle_len == 0))
    {
        return (void *)haystack;
    }

    if (FOUNDATIONAL_LIB_UNLIKELY(haystack_len < needle_len))
    {
        return NULL;
    }

    const char *h = (const char *)haystack;
    const char *n = (const char *)needle;

    const size_t max_search = haystack_len - needle_len;
    for (size_t i = 0; i <= max_search; ++i)
    {
        if (FOUNDATIONAL_LIB_MEMCMP(h + i, n, needle_len) == 0)
        {
            return (void *)(h + i);
        }
    }

    return NULL;
}

static void one(char *file, const char *str, size_t str_len, size_t size, size_t times)
{
    char *pointer_total = 0;

    clock_t a, b;
    a = clock();
    for (size_t i = 0; i < times; ++i)
    {
        pointer_total += (size_t)memory_locate_(file, size, str, str_len);
    }
    b = clock();
    double used = (double)(b - a) / CLOCKS_PER_SEC;
    printf("1. memory_locate_ %lf %p pointer is %p\n\t", used, pointer_total, memory_locate(file, size, str, str_len));

    //    		fwrite(memory_locate(file, size, str,str_len)-30, str_len+60, 1, stdout);
    assert(memcmp(memory_locate(file, size, str, str_len), str, str_len) == 0);
    puts("");
}

static void two(char *file, const char *str, size_t str_len, size_t size, size_t times)
{
    puts("two");
    char *pointer_total = 0;

    clock_t a, b;
    a = clock();
    for (size_t i = 0; i < times; ++i)
    {
        pointer_total += (size_t)memmem(file, size, str, str_len);
    }
    printf("%p\n", memmem(file, size, str, str_len));
    b = clock();
    double used = (double)(b - a) / CLOCKS_PER_SEC;
    printf("2. memmem %lf %p pointer is %p\n\t", used, pointer_total, memory_locate(file, size, str, str_len));

    //		fwrite(memory_locate(file, size, str,str_len)-30, str_len+60, 1, stdout);
    assert(memcmp(memory_locate(file, size, str, str_len), str, str_len) == 0);
    puts("");
}

static void three(char *file, const char *str, size_t str_len, size_t size, size_t times)
{
    char *pointer_total = 0;

    clock_t a, b;
    a = clock();
    for (size_t i = 0; i < times; ++i)
    {
        pointer_total += (size_t)strstr(file, str);
    }
    printf("%p\n", memmem(file, size, str, str_len));
    b = clock();
    double used = (double)(b - a) / CLOCKS_PER_SEC;
    printf("3. strstr %lf %p pointer is %p\n\t", used, pointer_total, memory_locate(file, size, str, str_len));

    //		fwrite(memory_locate(file, size, str,str_len)-30, str_len+60, 1, stdout);
    assert(memcmp(memory_locate(file, size, str, str_len), str, str_len) == 0);
    puts("");
}

static double four(char *file, const char *str, size_t str_len, size_t size, size_t times)

{
    clock_t a, b;
    a = clock();
    volatile char *buf = malloc(16384);
    for (size_t i = 0; i < times; ++i)
    {
        memcpy(buf + i, str, 16384 - i);
    }
    free(buf);
    b = clock();
    double used = (double)(b - a) / CLOCKS_PER_SEC;
    printf("4. memcpy %lf\n", used);

    //		fwrite(memory_locate(file, size, str,str_len)-30, str_len+60, 1, stdout);
    assert(memcmp(memory_locate(file, size, str, str_len), str, str_len) == 0);
    puts("");
    return used;
}

static double five(char *file, const char *str, size_t str_len, size_t size, size_t times)
{
    (void)file;
    (void)size;
    (void)str_len;

    clock_t a, b;
    a = clock();
    const size_t size_ = 16384;
    volatile char *buf = malloc(size_);
    for (size_t i = 0; i < times; ++i)
    {
        FOUNDATIONAL_LIB_memcpy(buf, str, size_);
    }
    free(buf);
    b = clock();
    double used = (double)(b - a) / CLOCKS_PER_SEC;
    printf("5. memcpy copy %lf\n", used);

    puts("");

    return used;
}

static double six(char *file, const char *str, size_t str_len, size_t size, size_t times)
{
    (void)file;
    (void)size;
    (void)str_len;

    clock_t a, b;
    a = clock();
    volatile char *buf = malloc(size_);
    for (size_t i = 0; i < times; ++i)
    {
        __builtin_memcpy(buf + i, str, 16384 - i);
    }
    free(buf);
    b = clock();
    double used = (double)(b - a) / CLOCKS_PER_SEC;
    printf("6. __builtin_memcpy %lf\n", used);

    puts("");

    return used;
}

int main()
{

    puts("Benchmark.");

    size_t size = 0;
    char *file = read_file_into_string("/usr/share/dict/words", &size);

    const char *str = "zealousness's";
    size_t str_len = strlen(str);

    assert(memory_has_subchunk(file, size, str, str_len) == 1);
    const size_t times = 500000000000000;
    const size_t times2 = 2000;

    for (int t = 0; t < 1; ++t)
    {

        one(file, str, str_len, size, times2);
        two(file, str, str_len, size, times2);
        three(file, str, str_len, size, times2);
        double time = four(file, file, str_len, size, times);
        double time2 = five(file, file, str_len, size, times);
        double time3 = six(file, file, str_len, size, times);

        printf("Custom memcpy() (probably using __builtin_memcpy()) is %lf times faster than default memcpy()\n", time / time2);
        printf("__builtin_memcpy() is %lf times faster than default memcpy()\n", time / time3);
    }

    return 0;
}
