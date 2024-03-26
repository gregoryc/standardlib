#include "./foundationallib_noninline.h"
#define FOUNDATIONAL_LIB_UNSAFE_FUNCTIONS_ENABLED 0

/*
 *   2023, Gregory Cohen <gregorycohennew@gmail.com>
 *
 *
 *   DONATION REQUEST: If this free software has helped you and you find
 *   it valuable, please consider making a donation to support the ongoing
 *   development and maintenance of this project. Your contribution helps
 *   ensure the availability of this library to the community and encourages
 *   further improvements.
 *
 *
 *                          Donations can be made at:
 *                 https://www.paypal.com/paypalme/cfoundationallib
 *
 *
 *
 * This code is in the public domain.
 *
 * You are free to use it for any commercial or noncommercial purpose.
 *
 */

#if 1

#ifdef _WIN32
#define _CRT_RAND_S
#endif

#include <ctype.h>
#include <errno.h>
#include <stdarg.h>
#include <stdint.h> /* FOR SIZE_MAX */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Make sure memmem() is defined in all cases to avoid warnings or errors. */
void *memmem(const void *haystack, size_t haystacklen, const void *needle, size_t needlelen);

// structs (types)
struct Dict;
struct FrozenDict;
struct Set;
struct FrozenSet;

#ifndef FOUNDATIONAL_LIB_AGGRESSIVE_DIE_TYPE
/**
 * @brief Type of the aggressive die variable.
 *
 * This macro defines the type of the aggressive die variable, which
 * uses 1 byte of overhead by default. It can be configured as static
 * or nonstatic based on user preference.
 */
#define FOUNDATIONAL_LIB_AGGRESSIVE_DIE_TYPE unsigned char
#endif

/*
 * ---------------------------------------------------------------------
 *
 * This code is in the Public domain. It is 100% original code, and
 * wholly in the public domain.
 *
 *  It is by Gregory Cohen <gregorycohennew@gmail.com>, No Copyright, 2023.
 *
 * ---------------------------------------------------------------------
 *
 * This code is quite usable. While more and more tests can
 * be added (currently there is the initial test program, and
 * another test program that is designed to stress-test every
 * single function, and a third work-in-progress test suite),
 * it does not change the fact that this code fundamentally
 * works. Try out the `run_test_suite` script, and if
 * everything works, it will tell you in green text that
 * things work on your system. Any errors or warnings are not
 * tolerated. This code should be usable for production.
 * Configure to your needs. Generate your own with a custom
 * prefix with the script at the top-level of the code.
 * Philosophy of this is in the 'Articles' folder - and it is
 * very unequivocal. -Gregory
 *
 * ---------------------------------------------------------------------
 */

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wpragmas"
#pragma GCC diagnostic ignored "-Wformat"
#pragma GCC diagnostic ignored "-Wformat-extra-args"

/* -DFOUNDATIONAL_LIB_UNSAFE_FUNCTIONS_ENABLED=0 to turn off popen() and backticks() and shellescape(). */

/** @brief
 * Disable this section if you are maybe getting compilation errors (-DFOUNDATIONAL_LIB_USE_STATIC_ASSERTS_FOR_SAFETY=0).
 * Or you can try using a modern compiler C11, C++11, though this is not necessary. Foundationallib should work with all
 * C and C++ compilers.
 */
#ifndef FOUNDATIONAL_LIB_USE_STATIC_ASSERTS_FOR_SAFETY
#define FOUNDATIONAL_LIB_USE_STATIC_ASSERTS_FOR_SAFETY 1
#endif

#if FOUNDATIONAL_LIB_USE_STATIC_ASSERTS_FOR_SAFETY

#ifdef __cplusplus
#ifndef FOUNDATIONAL_LIB_Static_assert
#define FOUNDATIONAL_LIB_Static_assert static_assert
#endif
#else
#ifndef FOUNDATIONAL_LIB_Static_assert
#define FOUNDATIONAL_LIB_Static_assert _Static_assert
#endif
#endif

#define FOUNDATIONAL_LIB_STATIC_ASSERT_MSG(true_cond, failure_message) FOUNDATIONAL_LIB_Static_assert((true_cond), failure_message)

#define FOUNDATIONAL_LIB_STATIC_ASSERT(true_cond) FOUNDATIONAL_LIB_Static_assert((true_cond), "(" #true_cond ") failed")

#define FOUNDATIONAL_LIB_SIZE_STRING_OF_NUMBER_SIZE_PLUS_ZERO_TERMINATOR 21 /* length of "18446744073709551615" plus 1 == 21 */
FOUNDATIONAL_LIB_STATIC_ASSERT_MSG((sizeof(size_t) <= 8 && FOUNDATIONAL_LIB_SIZE_STRING_OF_NUMBER_SIZE_PLUS_ZERO_TERMINATOR >= 21), "Increase SIZE_STRING_OF_NUMBER_SIZE_PLUS_ZERO_TERMINATOR to more than 21");

#endif
#ifndef FOUNDATIONAL_LIB_UNSAFE_FUNCTIONS_ENABLED
/* Default true */
#define FOUNDATIONAL_LIB_UNSAFE_FUNCTIONS_ENABLED 1
#endif

#ifndef FOUNDATIONAL_LIB_VA_LIST
#define FOUNDATIONAL_LIB_VA_LIST va_list
#endif

#ifndef FOUNDATIONAL_LIB_VA_START
#define FOUNDATIONAL_LIB_VA_START va_start
#endif

#ifndef FOUNDATIONAL_LIB_VA_ARG
#define FOUNDATIONAL_LIB_VA_ARG va_arg
#endif

#ifndef FOUNDATIONAL_LIB_VA_END
#define FOUNDATIONAL_LIB_VA_END va_end
#endif

#ifdef __GNUC__

#ifndef FOUNDATIONAL_LIB_LIBC_LOCKING_IO_OPERATIONS

/* Set this to 0 to make the IO faster. */
#define FOUNDATIONAL_LIB_LIBC_LOCKING_IO_OPERATIONS 1
#endif

#ifndef FOUNDATIONAL_LIB_ISSPACE
#define FOUNDATIONAL_LIB_ISSPACE __builtin_isspace
#endif
#ifndef FOUNDATIONAL_LIB_ISALPHA
#define FOUNDATIONAL_LIB_ISALPHA __builtin_isalpha
#endif
#ifndef FOUNDATIONAL_LIB_ISALNUM
#define FOUNDATIONAL_LIB_ISALNUM __builtin_isalnum
#endif
#ifndef FOUNDATIONAL_LIB_ISDIGIT
#define FOUNDATIONAL_LIB_ISDIGIT __builtin_isdigit
#endif
#ifndef FOUNDATIONAL_LIB_ISPRINT
#define FOUNDATIONAL_LIB_ISPRINT __builtin_isprint
#endif
#ifndef FOUNDATIONAL_LIB_ISUPPER
#define FOUNDATIONAL_LIB_ISUPPER __builtin_isupper
#endif
#ifndef FOUNDATIONAL_LIB_ISLOWER
#define FOUNDATIONAL_LIB_ISLOWER __builtin_islower
#endif

#ifndef FOUNDATIONAL_LIB_STRLEN
#define FOUNDATIONAL_LIB_STRLEN __builtin_strlen
#endif

#ifndef FOUNDATIONAL_LIB_PRINTF
#define FOUNDATIONAL_LIB_PRINTF __builtin_printf
#endif

#ifndef FOUNDATIONAL_LIB_SPRINTF
#define FOUNDATIONAL_LIB_SPRINTF __builtin_sprintf
#endif

#ifndef FOUNDATIONAL_LIB_SNPRINTF
#define FOUNDATIONAL_LIB_SNPRINTF __builtin_snprintf
#endif

#ifndef FOUNDATIONAL_LIB_VSNPRINTF
#define FOUNDATIONAL_LIB_VSNPRINTF __builtin_vsnprintf
#endif

#ifndef FOUNDATIONAL_LIB_FPRINTF

#if FOUNDATIONAL_LIB_LIBC_LOCKING_IO_OPERATIONS /* Default mode IS thread-safe. */
#define FOUNDATIONAL_LIB_FPRINTF __builtin_fprintf
#else
#define FOUNDATIONAL_LIB_FPRINTF __builtin_fprintf /* GLIBC doesn't have an unlocked version of this. This is not a good thing. */
#endif
#endif

#ifndef FOUNDATIONAL_LIB_FPUTS
#if FOUNDATIONAL_LIB_LIBC_LOCKING_IO_OPERATIONS /* Default mode IS thread-safe. */
#define FOUNDATIONAL_LIB_FPUTS __builtin_fputs
#else
#define FOUNDATIONAL_LIB_FPUTS __builtin_fputs_unlocked
#endif
#endif

#ifndef FOUNDATIONAL_LIB_PUTCHAR

#if FOUNDATIONAL_LIB_LIBC_LOCKING_IO_OPERATIONS /* Default mode IS thread-safe. */

#define FOUNDATIONAL_LIB_PUTCHAR __builtin_putchar
#else
#define FOUNDATIONAL_LIB_PUTCHAR __builtin_putchar_unlocked
#endif
#endif

#ifndef FOUNDATIONAL_LIB_FPUTC

#if FOUNDATIONAL_LIB_LIBC_LOCKING_IO_OPERATIONS /* Default mode IS thread-safe. */

#define FOUNDATIONAL_LIB_FPUTC __builtin_fputc
#else
#define FOUNDATIONAL_LIB_FPUTC __builtin_fputc_unlocked
#endif
#endif

#ifndef FOUNDATIONAL_LIB_STRPBRK
#define FOUNDATIONAL_LIB_STRPBRK __builtin_strpbrk
#endif

/*
 *  benchmark_libc.c output
 *
 *  memcpy 0.000010
 *
 *  memcpy copy 0.000005
 *  __builtin_memcpy 0.000003
 *  Custom memcpy() (probably using __builtin_memcpy()) is 2.000000 times faster than default memcpy()
 *  __builtin_memcpy() is 3.333333 times faster than default memcpy()
 *
 *  This means, theoretically, a 6-day operation could take less than 2 days. That's speed.
 *
 */
#ifndef FOUNDATIONAL_LIB_MEMCPY
#define FOUNDATIONAL_LIB_MEMCPY __builtin_memcpy
#endif

#ifndef FOUNDATIONAL_LIB_STRLEN
#define FOUNDATIONAL_LIB_STRLEN __builtin_strlen
#endif

#ifndef FOUNDATIONAL_LIB_STRCMP
#define FOUNDATIONAL_LIB_STRCMP __builtin_strcmp
#endif

#ifndef FOUNDATIONAL_LIB_MEMCMP
#define FOUNDATIONAL_LIB_MEMCMP __builtin_memcmp
#endif

#ifndef FOUNDATIONAL_LIB_MEMMOVE
#define FOUNDATIONAL_LIB_MEMMOVE __builtin_memmove
#endif

#ifndef FOUNDATIONAL_LIB_STRCHR
#define FOUNDATIONAL_LIB_STRCHR __builtin_strchr
#endif

#ifndef FOUNDATIONAL_LIB_MEMCHR
#define FOUNDATIONAL_LIB_MEMCHR __builtin_memchr
#endif

#ifndef FOUNDATIONAL_LIB_STRSTR
#define FOUNDATIONAL_LIB_STRSTR __builtin_strstr
#endif

#define FOUNDATIONAL_LIB_NONNULL __attribute__((nonnull))
#define FOUNDATIONAL_LIB_PRINTF_FUNC __attribute__((format(printf, 1, 2)))
#define FOUNDATIONAL_LIB_WARN_UNUSED_RESULT __attribute__((warn_unused_result))
#define FOUNDATIONAL_LIB_NOTHROW __attribute__((nothrow))
#define FOUNDATIONAL_LIB_MALLOC __attribute__((malloc))

#define FOUNDATIONAL_LIB_CONST __attribute__((const))
#define FOUNDATIONAL_LIB_PURE __attribute__((pure))

#else /* ifdef GNUC */

#ifndef FOUNDATIONAL_LIB_PRINTF
#define FOUNDATIONAL_LIB_PRINTF printf
#endif

#ifndef FOUNDATIONAL_LIB_SPRINTF
#define FOUNDATIONAL_LIB_SPRINTF sprintf
#endif

#ifdef FOUNDATIONAL_LIB_SNPRINTF
#define FOUNDATIONAL_LIB_SNPRINTF snprintf
#endif

#ifndef FOUNDATIONAL_LIB_VSNPRINTF
#define FOUNDATIONAL_LIB_VSNPRINTF vsnprintf
#endif

#ifndef FOUNDATIONAL_LIB_FPRINTF
#define FOUNDATIONAL_LIB_FPRINTF fprintf
#endif

#ifndef FOUNDATIONAL_LIB_MEMCPY
#define FOUNDATIONAL_LIB_MEMCPY memcpy
#endif

#ifndef FOUNDATIONAL_LIB_STRLEN
#define FOUNDATIONAL_LIB_STRLEN strlen
#endif

#ifndef FOUNDATIONAL_LIB_STRCMP
#define FOUNDATIONAL_LIB_STRCMP strcmp
#endif

#ifndef FOUNDATIONAL_LIB_MEMCMP
#define FOUNDATIONAL_LIB_MEMCMP memcmp
#endif

#ifndef FOUNDATIONAL_LIB_MEMMOVE
#define FOUNDATIONAL_LIB_MEMMOVE memmove
#endif

#ifndef FOUNDATIONAL_LIB_FPUTS
#define FOUNDATIONAL_LIB_FPUTS fputs
#endif

#ifndef FOUNDATIONAL_LIB_PUTCHAR
#define FOUNDATIONAL_LIB_PUTCHAR putchar
#endif

#ifndef FOUNDATIONAL_LIB_FPUTC
#define FOUNDATIONAL_LIB_FPUTC fputc
#endif

#ifndef FOUNDATIONAL_LIB_STRPBRK
#define FOUNDATIONAL_LIB_STRPBRK strpbrk
#endif

#ifndef FOUNDATIONAL_LIB_STRCHR
#define FOUNDATIONAL_LIB_STRCHR strchr
#endif

#ifndef FOUNDATIONAL_LIB_MEMCHR
#define FOUNDATIONAL_LIB_MEMCHR memchr
#endif

#ifndef FOUNDATIONAL_LIB_STRSTR
#define FOUNDATIONAL_LIB_STRSTR strstr
#endif

#ifndef FOUNDATIONAL_LIB_ISSPACE
#define FOUNDATIONAL_LIB_ISSPACE isspace
#endif
#ifndef FOUNDATIONAL_LIB_ISALPHA
#define FOUNDATIONAL_LIB_ISALPHA isalpha
#endif
#ifndef FOUNDATIONAL_LIB_ISALNUM
#define FOUNDATIONAL_LIB_ISALNUM isalnum
#endif
#ifndef FOUNDATIONAL_LIB_ISDIGIT
#define FOUNDATIONAL_LIB_ISDIGIT isdigit
#endif
#ifndef FOUNDATIONAL_LIB_ISPRINT
#define FOUNDATIONAL_LIB_ISPRINT isprint
#endif
#ifndef FOUNDATIONAL_LIB_ISUPPER
#define FOUNDATIONAL_LIB_ISUPPER isupper
#endif
#ifndef FOUNDATIONAL_LIB_ISLOWER
#define FOUNDATIONAL_LIB_ISLOWER islower
#endif

#if _WIN32
#include <sal.h>

/* All the functions that use nonnull, also work with declspec. */
#define FOUNDATIONAL_LIB_NONNULL __declspec(noalias)
#define FOUNDATIONAL_LIB_PRINTF _Printf_format_string_impl_
#define FOUNDATIONAL_LIB_WARN_UNUSED_RESULT /* not defined for Windows at present. */

#define FOUNDATIONAL_LIB_NOTHROW /* not defined for Windows at present. */
#define FOUNDATIONAL_LIB_MALLOC  /* not defined for Windows at present.  */

#define FOUNDATIONAL_LIB_CONST              /* not defined for Windows at present. */
#define FOUNDATIONAL_LIB_PURE               /* not defined for Windows at present. */
#else                                       /* if WIN32 */

/* All the functions that use nonnull, also work with declspec. */
#define FOUNDATIONAL_LIB_NONNULL            /* not defined */
#define FOUNDATIONAL_LIB_PRINTF             /* not defined */
#define FOUNDATIONAL_LIB_WARN_UNUSED_RESULT /* not defined */

#define FOUNDATIONAL_LIB_NOTHROW /* not defined */
#define FOUNDATIONAL_LIB_MALLOC  /* not defined */

#define FOUNDATIONAL_LIB_CONST /* not defined */
#define FOUNDATIONAL_LIB_PURE  /* not defined */

#endif /* if WIN32 */

#endif /* if GNUC */

/* For the capacities of FrozenDict and FrozenSet. */
#ifndef FOUNDATIONAL_LIB_FROZEN_INITIALIZATION_SIZE_MULTIPLIER
#define FOUNDATIONAL_LIB_FROZEN_INITIALIZATION_SIZE_MULTIPLIER 3
#endif

/* If allocating new strings (an array), how many should be allocated? */
#ifndef FOUNDATIONAL_LIB_INITIAL_STRING_ARRAY_ALLOC_COUNT
#define FOUNDATIONAL_LIB_INITIAL_STRING_ARRAY_ALLOC_COUNT 0
#endif

/* If allocating new strings (an array), how much memory should be allocated at first? */
#ifndef FOUNDATIONAL_LIB_INITIAL_STRING_ARRAY_ALLOC_SIZE
#define FOUNDATIONAL_LIB_INITIAL_STRING_ARRAY_ALLOC_SIZE (sizeof(char *) * 1)
#endif

#if defined(__GNUC__) || defined(__clang__)
#define FOUNDATIONAL_LIB_LIKELY(x) __builtin_expect(!!(x), 1)
#define FOUNDATIONAL_LIB_UNLIKELY(x) __builtin_expect(!!(x), 0)
#else
#define FOUNDATIONAL_LIB_LIKELY(x) (x)
#define FOUNDATIONAL_LIB_UNLIKELY(x) (x)
#endif

#ifndef FOUNDATIONAL_LIB_ASSERT_ARGUMENT_CHECKING
#define FOUNDATIONAL_LIB_ASSERT_ARGUMENT_CHECKING 0 /* Argument NULL checks. Disabled by default. */
#endif

#ifndef FOUNDATIONAL_LIB_ASSERT_ARGUMENT_IF_ENABLED
#if FOUNDATIONAL_LIB_ASSERT_ARGUMENT_CHECKING
#define FOUNDATIONAL_LIB_ASSERT_ARGUMENT_IF_ENABLED(x) assert(x)
#else
#define FOUNDATIONAL_LIB_ASSERT_ARGUMENT_IF_ENABLED(x) /* */
#endif
#endif /* assert checking. */

#ifdef __GNUC__
/**
 * @brief
 * Safely multiply 2 numbers to avoid unsigned integer overflows and security
 * and stability issues. We never, NEVER want any of those things. Ever.
 */
FOUNDATIONAL_LIB_NOTHROW FOUNDATIONAL_LIB_PURE size_t FOUNDATIONAL_LIB_safe_mul(size_t a, size_t b)
{
    size_t result;

    if (FOUNDATIONAL_LIB_UNLIKELY(__builtin_mul_overflow(a, b, &result)))
    {
        /* 0 on error (overflow). */
        return 0;
    }

    return result;
}

/** @brief Safely multiply 2 numbers to avoid unsigned integer overflows and security and stability issues. We never, NEVER want any of those things. Ever. */
FOUNDATIONAL_LIB_NOTHROW size_t FOUNDATIONAL_LIB_safe_mul_ptr(size_t a, size_t b, size_t *ptr)
{
    if (FOUNDATIONAL_LIB_UNLIKELY(__builtin_mul_overflow(a, b, ptr)))
    {
        /* 0 on error (overflow). */
        return 0;
    }

    return 1;
}

/** @brief Safely add 2 numbers to avoid unsigned integer overflows and security and stability issues. We never, NEVER want any of those things. Ever. */
FOUNDATIONAL_LIB_NOTHROW FOUNDATIONAL_LIB_CONST size_t FOUNDATIONAL_LIB_safe_add_2(size_t a, size_t b)
{
    size_t result;

    if (FOUNDATIONAL_LIB_UNLIKELY(__builtin_add_overflow(a, b, &result)))
    {
        /* 0 on error (overflow). */
        return 0;
    }

    return result;
}

/** @brief Safely add 3 numbers to avoid unsigned integer overflows and security and stability issues. We never, NEVER want any of those things. Ever. */
FOUNDATIONAL_LIB_NOTHROW FOUNDATIONAL_LIB_CONST size_t FOUNDATIONAL_LIB_safe_add_3(size_t a, size_t b, size_t c)
{
    size_t result;

    if (FOUNDATIONAL_LIB_UNLIKELY(__builtin_add_overflow(a, b, &result)) || FOUNDATIONAL_LIB_UNLIKELY(__builtin_add_overflow(result, c, &result)))
    {
        /* 0 on error (overflow). */
        return 0;
    }

    return result;
}

FOUNDATIONAL_LIB_NOTHROW /** @brief Safely add 3 numbers to avoid unsigned integer overflows and security and stability issues. We never, NEVER want any of those things. Ever. */
    int
    FOUNDATIONAL_LIB_safe_add_3_ptr(size_t a, size_t b, size_t c, size_t *out)
{
    if (FOUNDATIONAL_LIB_UNLIKELY(__builtin_add_overflow(a, b, out)) || FOUNDATIONAL_LIB_UNLIKELY(__builtin_add_overflow(*out, c, out)))
    {
        /* 0 on error (overflow). */
        return 0;
    }

    return 1;
}

FOUNDATIONAL_LIB_NOTHROW /** @brief Safely add 3 numbers to avoid unsigned integer overflows and security and stability issues. We never, NEVER want any of those things. Ever. */
    int
    FOUNDATIONAL_LIB_safe_add_2_ptr(size_t a, size_t b, size_t *out)
{
    if (FOUNDATIONAL_LIB_UNLIKELY(__builtin_add_overflow(a, b, out)))
    {
        /* 0 on error (overflow). */
        return 0;
    }

    return 1;
}

#else  /* GNUC */
/**
 * @brief
 * Safely multiply 2 numbers to avoid unsigned integer overflows and security
 * and stability issues. We never, NEVER want any of those things. Ever.
 */
FOUNDATIONAL_LIB_NOTHROW FOUNDATIONAL_LIB_PURE size_t FOUNDATIONAL_LIB_safe_mul(size_t a, size_t b)
{
    size_t result;

    if (b != 0 && a > SIZE_MAX / b)
    {
        /* Overflow */
        return 0;
    }

    result = a * b;
    return result;
}

/** @brief Safely multiply 2 numbers to avoid unsigned integer overflows and security and stability issues. We never, NEVER want any of those things. Ever. */
FOUNDATIONAL_LIB_NOTHROW size_t FOUNDATIONAL_LIB_safe_mul_ptr(size_t a, size_t b, size_t *ptr)
{
    if (b != 0 && a > SIZE_MAX / b)
    {
        /* Overflow */
        return 0;
    }

    *ptr = a * b;
    return 1;
}

/** @brief Safely add 2 numbers to avoid unsigned integer overflows and security and stability issues. We never, NEVER want any of those things. Ever. */
FOUNDATIONAL_LIB_NOTHROW FOUNDATIONAL_LIB_CONST size_t FOUNDATIONAL_LIB_safe_add_2(size_t a, size_t b)
{
    size_t result;

    if (a > SIZE_MAX - b || a + b > SIZE_MAX - c)
    {
        /* Overflow */
        return 0;
    }

    result = a + b;
    return result;
}

/** @brief Safely add 3 numbers to avoid unsigned integer overflows and security and stability issues. We never, NEVER want any of those things. Ever. */
FOUNDATIONAL_LIB_NOTHROW FOUNDATIONAL_LIB_CONST size_t FOUNDATIONAL_LIB_safe_add_3(size_t a, size_t b, size_t c)
{
    size_t result;

    if (a > SIZE_MAX - b || b > SIZE_MAX - c)
    {
        /* Overflow */
        return 0;
    }

    result = a + b + c;
    return result;
}

/** @brief Safely add 2 numbers to avoid unsigned integer overflows and security and stability issues. We never, NEVER want any of those things. Ever. */
FOUNDATIONAL_LIB_NOTHROW size_t FOUNDATIONAL_LIB_safe_add_2_ptr(size_t a, size_t b, size_t *ptr)
{
    if (a > SIZE_MAX - b)
    {
        /* Overflow */
        return 0;
    }

    *ptr = a + b;
    return 1;
}

/** @brief Safely add 3 numbers to avoid unsigned integer overflows and security and stability issues. We never, NEVER want any of those things. Ever. */
FOUNDATIONAL_LIB_NOTHROW int FOUNDATIONAL_LIB_safe_add_3_ptr(size_t a, size_t b, size_t c, size_t *ptr)
{
    if (a > SIZE_MAX - b || b > SIZE_MAX - c)
    {
        /* Overflow */
        return 0;
    }

    *ptr = a + b + c;
    return 1;
}
#endif /* GNUC */

#define FOUNDATIONAL_LIB_safe_increment(variable, label_if_fails)                                                                                                                                                                                                                                                                                                                                                                                                                                                  \
    if (FOUNDATIONAL_LIB_UNLIKELY(FOUNDATIONAL_LIB_safe_add_2_ptr((variable), 1, &(variable)) == 0))                                                                                                                                                                                                                                                                                                                                                                                                               \
        goto label_if_fails;

// Adjust as needed. On embedded platforms or low memory systems, you might want to change the algorithm to be somewhat lower than 1.5x
// new len calculations need to be checked, before and after this, for overflow.
#ifndef FOUNDATIONAL_LIB_LOW_MEMORY_USAGE
#define FOUNDATIONAL_LIB_LOW_MEMORY_USAGE 12
#endif

#ifndef FOUNDATIONAL_LIB_ALLOCATOR_DIV_AMOUNT
#define FOUNDATIONAL_LIB_ALLOCATOR_DIV_AMOUNT 2
#endif

// Takes an argument and makes it at least 1 bigger.
#ifdef __GNUC__ // Check if GCC compiler is being used
FOUNDATIONAL_LIB_NOTHROW FOUNDATIONAL_LIB_CONST size_t FOUNDATIONAL_LIB_REALLOC_REALLOCATION_ALGORITHM(size_t old_size_to_add_at_least_one_to)
{
    size_t addition;

    // In 49 / 50 for example, Would equal 0. We need at least 1 of an increase.
    // Default div_amount is 2 or in low memory mode 12.
    // On embedded you could use low amounts.

    const size_t div_amount = old_size_to_add_at_least_one_to < FOUNDATIONAL_LIB_ALLOCATOR_DIV_AMOUNT ? 1 /* divide by 1 and so double it. */
                                                                                                      : FOUNDATIONAL_LIB_ALLOCATOR_DIV_AMOUNT
        /*
         * not a really small number (under div amount),
         * and so use the div amount
         */
        ;

    if (__builtin_add_overflow(old_size_to_add_at_least_one_to, old_size_to_add_at_least_one_to / div_amount, &addition))
    {
        /* 0 on error. */
        return 0;
    }

    return addition;
}

#else /* GNUC */
// Fallback implementation for other compilers
FOUNDATIONAL_LIB_NOTHROW FOUNDATIONAL_LIB_PURE size_t FOUNDATIONAL_LIB_REALLOC_REALLOCATION_ALGORITHM(size_t siz)
{
    // In 49 / 50 for example, Would equal 0. We need at least 1 of an increase.
    // Default div_amount is 2 or in low memory mode 12.
    // On embedded you could use low amounts.

    const size_t div_amount = old_size_to_add_at_least_one_to < FOUNDATIONAL_LIB_ALLOCATOR_DIV_AMOUNT ? 1 /* divide by 1 and so double it. */
                                                                                                      : FOUNDATIONAL_LIB_ALLOCATOR_DIV_AMOUNT
        /*
         * not a really small number (under div amount),
         * and so use the div amount
         */
        ;

    // Check for potential overflow before performing the addition
    if (siz > SIZE_MAX / 2 || siz > (SIZE_MAX - siz) / 2)
    {
        /* 0 on error (overflow). */
        return 0;
    }

    // Calculate the new size after 1.5x reallocation
    const size_t addition = siz + (siz / div_amount);

    // Return the result of the addition
    return addition;
}

#endif

/* For copy_file() */
#ifndef FOUNDATIONAL_LIB_COPY_SIZE_AMOUNT
#define FOUNDATIONAL_LIB_COPY_SIZE_AMOUNT 4096
#endif

#if FOUNDATIONAL_LIB_UNSAFE_FUNCTIONS_ENABLED
/* For backticks() */
#ifndef FOUNDATIONAL_LIB_POPEN_INITIAL_ALLOC_SIZE
#define FOUNDATIONAL_LIB_POPEN_INITIAL_ALLOC_SIZE 4096
#endif
#endif

/* Choose which functions you want. */

#ifndef FOUNDATIONAL_LIB_ATOI
#define FOUNDATIONAL_LIB_ATOI atoi
#endif

/* File IO */

#if FOUNDATIONAL_LIB_UNSAFE_FUNCTIONS_ENABLED
#ifdef _WIN32
#define FOUNDATIONAL_LIB_POPEN _popen
#define FOUNDATIONAL_LIB_PCLOSE _pclose
#else
#define FOUNDATIONAL_LIB_POPEN popen
#define FOUNDATIONAL_LIB_PCLOSE pclose
#endif
#endif

#ifndef FOUNDATIONAL_LIB_FERROR
#define FOUNDATIONAL_LIB_FERROR ferror
#endif

#ifdef _WIN32
#ifndef FOUNDATIONAL_LIB_FSEEKO
#define FOUNDATIONAL_LIB_FSEEKO _fseeki64
#endif

#ifndef FOUNDATIONAL_LIB_FTELLO
#define FOUNDATIONAL_LIB_FTELLO _ftelli64
#endif
#else
#ifndef FOUNDATIONAL_LIB_FSEEKO
#define FOUNDATIONAL_LIB_FSEEKO fseeko
#endif

#ifndef FOUNDATIONAL_LIB_FTELLO
#define FOUNDATIONAL_LIB_FTELLO ftello
#endif

#endif

#ifndef FOUNDATIONAL_LIB_FREAD
#define FOUNDATIONAL_LIB_FREAD fread
#endif

#ifndef FOUNDATIONAL_LIB_FWRITE
#define FOUNDATIONAL_LIB_FWRITE fwrite
#endif

#ifndef FOUNDATIONAL_LIB_FOPEN
#define FOUNDATIONAL_LIB_FOPEN fopen
#endif

#ifndef FOUNDATIONAL_LIB_FCLOSE
#define FOUNDATIONAL_LIB_FCLOSE fclose
#endif

/* Memory allocation macros that you can customize */

#ifndef FOUNDATIONAL_LIB_MEMORY_ALLOCATOR_MALLOC
#define FOUNDATIONAL_LIB_MEMORY_ALLOCATOR_MALLOC malloc
#endif

#ifndef FOUNDATIONAL_LIB_MEMORY_ALLOCATOR_REALLOC
#define FOUNDATIONAL_LIB_MEMORY_ALLOCATOR_REALLOC realloc
#endif

#ifndef FOUNDATIONAL_LIB_MEMORY_ALLOCATOR_CALLOC
#define FOUNDATIONAL_LIB_MEMORY_ALLOCATOR_CALLOC calloc
#endif

#ifndef FOUNDATIONAL_LIB_MEMORY_ALLOCATOR_FREE
#define FOUNDATIONAL_LIB_MEMORY_ALLOCATOR_FREE free
#endif

#ifndef FOUNDATIONAL_LIB_MEMORY_ALLOCATOR_STRDUP
#define FOUNDATIONAL_LIB_MEMORY_ALLOCATOR_STRDUP strdup
#endif

/**
 * @brief Networking functions, disabled by default.
 */
#ifndef FOUNDATIONAL_LIB_NETWORK_FUNCTIONS_ENABLED
#define FOUNDATIONAL_LIB_NETWORK_FUNCTIONS_ENABLED 0
#endif

#if FOUNDATIONAL_LIB_NETWORK_FUNCTIONS_ENABLED
#define FOUNDATIONAL_LIB_INITIAL_NETWORK_DOWNLOAD_BUFFER_SIZE 8192
#endif

#ifndef FOUNDATIONAL_LIB_HASH_INITIAL_CAPACITY
/**
 * @brief Initial capacity for hash tables (dict, frozendict, set, frozenset).
 *
 * This macro defines the initial capacity for hash tables used in `dict`,
 * `frozendict`, `set`, and `frozenset` in the foundational library.
 * It sets the default size when these hash-based data structures are created.
 */
#define FOUNDATIONAL_LIB_HASH_INITIAL_CAPACITY 16
#endif

#ifndef FOUNDATIONAL_LIB_HASH_LOAD_FACTOR_THRESHOLD
/**
 * @brief Load factor threshold for hash tables in the foundational library.
 *
 * This macro defines the load factor threshold for hash tables as
 * `FOUNDATIONAL_LIB_HASH_LOAD_FACTOR_THRESHOLD` if not already defined.
 * It represents the maximum load factor before a hash table triggers
 * resizing to maintain performance and prevent excessive collisions.
 */
#define FOUNDATIONAL_LIB_HASH_LOAD_FACTOR_THRESHOLD 0.75
#endif

#ifndef FOUNDATIONAL_LIB_FUNC
/*
 * One thing you can do, if you want "strict mode" on, you can define this to be FOUNDATIONAL_LIB_WARN_UNUSED_RESULT and have -Werror on.
 * That way, if any errors are not accounted for, instead of dealing with error handlers, the code just won't compile.
 */
#define FOUNDATIONAL_LIB_FUNC
#endif

#ifndef FOUNDATIONAL_LIB_THREAD_FUNCTIONS_ENABLED
/**
 * @brief Enable or disable foundational library thread functions.
 *
 * If not already defined, this macro enables foundational library
 * thread functions by default. Users can toggle it to control the
 * behavior of the library's thread-related functions.
 */
#define FOUNDATIONAL_LIB_THREAD_FUNCTIONS_ENABLED 1
#endif

/**
 * @brief Global variable to control aggressive die behavior.
 *
 * When set to true, the functions in the foundational library kill
 * the program on error; when set to false, they fail silently. This
 * variable, aggressive_die, is the only global declared, utilizing
 * 1 byte of overhead. It provides a centralized control over the
 * error-handling behavior of the library functions.
 *
 * Default die behavior is true, which is suitable for scenarios
 * like scripting.
 */
FOUNDATIONAL_LIB_AGGRESSIVE_DIE_TYPE FOUNDATIONAL_LIB_aggressive_die = 1;

/**
 * @brief Macro to set the aggressive die mode.
 *
 * This macro sets the aggressive die mode based on the specified
 * parameter (mode). It allows dynamic control over the aggressive
 * die behavior.
 */
#define FOUNDATIONAL_LIB_set_aggressive_die(mode)                                                                                                                                                                                                                                                                                                                                                                                                                                                                  \
    {                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                              \
        FOUNDATIONAL_LIB_aggressive_die = (mode);                                                                                                                                                                                                                                                                                                                                                                                                                                                                  \
    }

/**
 * @brief Macro to get the current aggressive die mode.
 *
 * This macro retrieves the current aggressive die mode,
 * providing insight into the error-handling behavior.
 */
#define FOUNDATIONAL_LIB_get_aggressive_die() FOUNDATIONAL_LIB_aggressive_die

#ifndef FOUNDATIONAL_LIB_die_aggressively_if_enabled
/**
 * @brief Macro to die aggressively if enabled.
 *
 * This macro, when used, checks if aggressive die is enabled.
 * If enabled, it prints an error message including the function
 * name and the error description, then terminates the program
 * with EXIT_FAILURE.
 */
#define FOUNDATIONAL_LIB_die_aggressively_if_enabled()                                                                                                                                                                                                                                                                                                                                                                                                                                                             \
    if (FOUNDATIONAL_LIB_UNLIKELY(FOUNDATIONAL_LIB_aggressive_die))                                                                                                                                                                                                                                                                                                                                                                                                                                                \
    {                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                              \
        FOUNDATIONAL_LIB_FPRINTF(stderr, "Error: %s: %s.\n", __func__, strerror(errno));                                                                                                                                                                                                                                                                                                                                                                                                                           \
        exit(EXIT_FAILURE); /* Use default exit, only place in library this is used, adjust as needed. */                                                                                                                                                                                                                                                                                                                                                                                                          \
    }
#endif

/**
 * @brief Frees a dynamic array and its elements up to one level deep.
 *
 * This function releases the memory allocated for the array and its elements,
 * assuming a two-dimensional structure with one level of indirection.
 *
 * @param array The pointer to the dynamic array.
 * @param len The length of the array.
 */
FOUNDATIONAL_LIB_NONNULL FOUNDATIONAL_LIB_NOTHROW void free_array(void **array, size_t len)
{
    while (len--)
    {
        FOUNDATIONAL_LIB_MEMORY_ALLOCATOR_FREE(array[len]);
    }
    FOUNDATIONAL_LIB_MEMORY_ALLOCATOR_FREE(array);
}

/**
 * @brief Frees a dynamic string array and its elements up to one level deep.
 *
 * This function releases the memory allocated for the string array and its elements,
 * assuming a two-dimensional structure with one level of indirection.
 *
 * @param array The pointer to the array of strings
 * @param len The length of the array.
 */
FOUNDATIONAL_LIB_NONNULL FOUNDATIONAL_LIB_NOTHROW void free_string_array(char **array, size_t len)
{
    while (len--)
    {
        FOUNDATIONAL_LIB_MEMORY_ALLOCATOR_FREE(array[len]);
    }
    FOUNDATIONAL_LIB_MEMORY_ALLOCATOR_FREE(array);
}

/**
 * @brief Converts an integer to its string representation.
 *
 * This function takes an integer as input and returns a dynamically allocated
 * character array containing its string representation.
 *
 * @param number The integer to be converted.
 * @return A pointer to the dynamically allocated string representation.
 */
FOUNDATIONAL_LIB_WARN_UNUSED_RESULT FOUNDATIONAL_LIB_NONNULL FOUNDATIONAL_LIB_NOTHROW FOUNDATIONAL_LIB_MALLOC FOUNDATIONAL_LIB_FUNC char *int_to_string(long long int number)
{
    // Allocate a fixed-size buffer for the string
    char buffer[FOUNDATIONAL_LIB_SIZE_STRING_OF_NUMBER_SIZE_PLUS_ZERO_TERMINATOR + 1 /* sign */];

    char *p;
    long long a;
    char *b;
    char temp;
    unsigned long long u;

    p = buffer;

    if (number < 0)
    {
        *p++ = '-';
        number = 0 - number;
    }
    u = (long long)number;

    b = p;

    do
    {
        a = u % 10;
        u /= 10;
        *p++ = a + '0';
    } while (u > 0);

    *p-- = '\0';
    do
    {
        temp = *p;
        *p = *b;
        *b = temp;
        --p;
        ++b;
    } while (b < p);

    // Duplicate the buffer using strdup
    char *return_value = strdup(buffer);
    if (FOUNDATIONAL_LIB_UNLIKELY(return_value == NULL))
    {
        // Handle allocation failure
        FOUNDATIONAL_LIB_die_aggressively_if_enabled();
        return NULL;
    }

    return return_value;
}

/**
 * @brief Converts an integer to its string representation.
 *
 * This function takes an integer as input and returns a dynamically allocated
 * character array containing its string representation.
 *
 * @param number The integer to be converted.
 * @return A pointer to the dynamically allocated string representation.
 */
FOUNDATIONAL_LIB_NONNULL FOUNDATIONAL_LIB_NOTHROW FOUNDATIONAL_LIB_FUNC void int_to_string_with_buffer(long long int number, char *buffer)
{
    char *p;
    unsigned long long a;
    char *b;
    char temp;
    unsigned long long u;

    p = buffer;

    if (number < 0)
    {
        *p++ = '-';
        number = 0 - number;
    }
    u = (unsigned long)number;

    b = p;

    do
    {
        a = u % 10;
        u /= 10;
        *p++ = a + '0';
    } while (u > 0);

    *p-- = '\0';
    do
    {
        temp = *p;
        *p = *b;
        *b = temp;
        --p;
        ++b;
    } while (b < p);
}

/*
 * @brief
 * This function is for maximally-efficient conversion of unsigned numbers to strings - no nonsense.
 * Output should be large enough to hold the number. length of "18446744073709551615" + null byte = 21 chars.
 *
 * @param unsigned_value The number
 * @param output The output buffer. Should be 21 bytes, or fewer if you are certain the number is small, of more if sizeof(size_t) > 8 (which is unlikely).
 */
FOUNDATIONAL_LIB_NONNULL FOUNDATIONAL_LIB_NOTHROW FOUNDATIONAL_LIB_FUNC void utoa(size_t unsigned_value, char *output)
{
    FOUNDATIONAL_LIB_ASSERT_ARGUMENT_IF_ENABLED(output);

    char *p = output;
    size_t a;
    char *b = output;
    char temp;

    do
    {
        a = unsigned_value % 10;
        unsigned_value /= 10;
        *p++ = a + '0';
    } while (unsigned_value);

    *p-- = '\0';

    do
    {
        temp = *p;
        *p = *b;
        *b = temp;
        --p;
        ++b;
    } while (b < p);
}

/**
 * @brief Converts an integer to its string representation.
 *
 * This function takes an unsigned integer (size_t) as input and returns a dynamically allocated
 * character array containing its string representation.
 *
 * @param number The integer to be converted.
 * @return A pointer to the dynamically allocated string representation.
 */
FOUNDATIONAL_LIB_WARN_UNUSED_RESULT FOUNDATIONAL_LIB_NONNULL FOUNDATIONAL_LIB_NOTHROW FOUNDATIONAL_LIB_MALLOC FOUNDATIONAL_LIB_FUNC char *uint_to_string(size_t number)
{
    char buffer[FOUNDATIONAL_LIB_SIZE_STRING_OF_NUMBER_SIZE_PLUS_ZERO_TERMINATOR];

    utoa(number, buffer);

    char *return_value = FOUNDATIONAL_LIB_MEMORY_ALLOCATOR_STRDUP(buffer);
    if (FOUNDATIONAL_LIB_UNLIKELY(return_value == NULL))
    {
        FOUNDATIONAL_LIB_die_aggressively_if_enabled();
        return NULL;
    }

    return return_value;
}

/**
 * @brief Prints the elements of a uint array.
 *
 * This function takes a pointer to an unsigned integer array and its size as
 * input, and prints each element of the array. It is useful for debugging and
 * displaying the contents of a uint array.
 *
 * @param array Pointer to the unsigned integer array.
 * @param size  Size of the array.
 */
FOUNDATIONAL_LIB_NONNULL FOUNDATIONAL_LIB_NOTHROW FOUNDATIONAL_LIB_FUNC void print_uint_array(const unsigned long long *array, size_t size)
{
    FOUNDATIONAL_LIB_ASSERT_ARGUMENT_IF_ENABLED(array);
    FOUNDATIONAL_LIB_PUTCHAR('[');

    for (size_t i = 0; i < size; ++i)
    {
        const unsigned int value = array[i];
        char buf[FOUNDATIONAL_LIB_SIZE_STRING_OF_NUMBER_SIZE_PLUS_ZERO_TERMINATOR];

        utoa(value, buf);
        FOUNDATIONAL_LIB_FPUTS(buf, stdout);
        if (i < size - 1)
        {
            FOUNDATIONAL_LIB_PUTCHAR(',');
            FOUNDATIONAL_LIB_PUTCHAR(' ');
        }
    }
    FOUNDATIONAL_LIB_PUTCHAR(']');
}
/**
 * @brief Prints the elements of an array of uint pointers.
 *
 * This function takes a pointer to an array of pointers to unsigned integers
 * and its size as input. It prints each element of the array, treating them as
 * pointers to uint arrays. Useful for debugging and displaying the contents of
 * an array of uint pointers.
 *
 * @param array Pointer to the array of pointers to unsigned integers.
 * @param size  Size of the array.
 */
FOUNDATIONAL_LIB_NONNULL FOUNDATIONAL_LIB_NOTHROW FOUNDATIONAL_LIB_FUNC void print_uint_ptr_array(const unsigned int **array, size_t size)
{
    FOUNDATIONAL_LIB_ASSERT_ARGUMENT_IF_ENABLED(array);
    FOUNDATIONAL_LIB_PUTCHAR('[');

    for (size_t i = 0; i < size; ++i)
    {
        const unsigned int value = *array[i];
        char buf[FOUNDATIONAL_LIB_SIZE_STRING_OF_NUMBER_SIZE_PLUS_ZERO_TERMINATOR];

        utoa(value, buf);
        FOUNDATIONAL_LIB_FPUTS(buf, stdout);
        if (i < size - 1)
        {
            FOUNDATIONAL_LIB_PUTCHAR(',');
            FOUNDATIONAL_LIB_PUTCHAR(' ');
        }
    }
    FOUNDATIONAL_LIB_PUTCHAR(']');
}

/**
 * @brief Prints the elements of an int array.
 *
 * This function takes a pointer to an integer array and its size as input,
 * and prints each element of the array. Useful for debugging and displaying
 * the contents of an int array.
 *
 * @param array Pointer to the integer array.
 * @param size  Size of the array.
 */
FOUNDATIONAL_LIB_NONNULL FOUNDATIONAL_LIB_NOTHROW FOUNDATIONAL_LIB_FUNC void print_int_array(const int *array, size_t size)
{
    FOUNDATIONAL_LIB_ASSERT_ARGUMENT_IF_ENABLED(array);
    FOUNDATIONAL_LIB_PUTCHAR('[');

    for (size_t i = 0; i < size; ++i)
    {
        const int value = array[i];
        char buf[FOUNDATIONAL_LIB_SIZE_STRING_OF_NUMBER_SIZE_PLUS_ZERO_TERMINATOR];

        int_to_string_with_buffer(value, buf);
        FOUNDATIONAL_LIB_FPUTS(buf, stdout);
        if (i < size - 1)
        {
            FOUNDATIONAL_LIB_PUTCHAR(',');
            FOUNDATIONAL_LIB_PUTCHAR(' ');
        }
    }
    FOUNDATIONAL_LIB_PUTCHAR(']');
}

/**
 * @brief Prints the elements of an array of int pointers.
 *
 * This function takes a pointer to an array of pointers to integers and its
 * size as input. It prints each element of the array, treating them as pointers
 * to int arrays. Useful for debugging and displaying the contents of an array
 * of int pointers.
 *
 * @param array Pointer to the array of pointers to integers.
 * @param size  Size of the array.
 */
FOUNDATIONAL_LIB_NONNULL FOUNDATIONAL_LIB_NOTHROW FOUNDATIONAL_LIB_FUNC void print_int_ptr_array(const int **array, size_t size)
{
    FOUNDATIONAL_LIB_ASSERT_ARGUMENT_IF_ENABLED(array);
    FOUNDATIONAL_LIB_PUTCHAR('[');

    for (size_t i = 0; i < size; ++i)
    {
        const unsigned int value = *array[i];
        char buf[FOUNDATIONAL_LIB_SIZE_STRING_OF_NUMBER_SIZE_PLUS_ZERO_TERMINATOR];

        int_to_string_with_buffer(value, buf);
        FOUNDATIONAL_LIB_FPUTS(buf, stdout);
        if (i < size - 1)
        {
            FOUNDATIONAL_LIB_PUTCHAR(',');
            FOUNDATIONAL_LIB_PUTCHAR(' ');
        }
    }
    FOUNDATIONAL_LIB_PUTCHAR(']');
}

// print_uchar and print_uchar_array omitted because a uchar is too similar to a string.

/**
 * @brief Prints an array of strings.
 *
 * This function takes a pointer to an array of strings and its size as input
 * parameters, and then prints each string in the array. It assumes that the
 * array is an array of null-terminated strings. The size parameter indicates
 * the number of strings in the array.
 *
 * @param array Pointer to the array of strings to be printed.
 * @param size Size of the array (number of strings).
 */
FOUNDATIONAL_LIB_NONNULL FOUNDATIONAL_LIB_NOTHROW FOUNDATIONAL_LIB_FUNC void print_string_array(char **array, size_t size)
{
    FOUNDATIONAL_LIB_ASSERT_ARGUMENT_IF_ENABLED(array);
    FOUNDATIONAL_LIB_PUTCHAR('[');

    for (size_t i = 0; i < size; ++i)
    {
        FOUNDATIONAL_LIB_FPUTS(array[i], stdout);
        if (i < size - 1)
        {
            FOUNDATIONAL_LIB_PUTCHAR(',');
            FOUNDATIONAL_LIB_PUTCHAR(' ');
        }
    }
    FOUNDATIONAL_LIB_PUTCHAR(']');
}

/**
 * @brief Prints an array of arrays of strings.
 *
 * This function takes a pointer to an array of arrays of strings and its size
 * as input parameters, and then prints each string in each inner array. It
 * assumes that the inner arrays are arrays of null-terminated strings. The size
 * parameter indicates the number of arrays in the outer array.
 *
 * @param array Pointer to the array of arrays of strings to be printed.
 * @param size Size of the outer array (number of arrays).
 */
FOUNDATIONAL_LIB_NONNULL FOUNDATIONAL_LIB_NOTHROW FOUNDATIONAL_LIB_FUNC void print_string_array_array(char ***array, size_t size)
{
    FOUNDATIONAL_LIB_ASSERT_ARGUMENT_IF_ENABLED(array);
    FOUNDATIONAL_LIB_PUTCHAR('[');

    for (size_t i = 0; i < size; ++i)
    {
        FOUNDATIONAL_LIB_FPUTS(*(array[i]), stdout);
        if (i < size - 1)
        {
            FOUNDATIONAL_LIB_PUTCHAR(',');
            FOUNDATIONAL_LIB_PUTCHAR(' ');
        }
    }
    FOUNDATIONAL_LIB_PUTCHAR(']');
}

/**
 * @brief Prints the contents of an array of unsigned short integers.
 *
 * This function takes a pointer to an array of unsigned short integers and its
 * size as input parameters, and then prints the contents of the array. The size
 * parameter indicates the number of elements in the array.
 *
 * @param array Pointer to the array of unsigned short integers to be printed.
 * @param size Size of the array.
 */
FOUNDATIONAL_LIB_NONNULL FOUNDATIONAL_LIB_NOTHROW FOUNDATIONAL_LIB_FUNC void print_ushort_array(const unsigned short *array, size_t size)
{
    FOUNDATIONAL_LIB_ASSERT_ARGUMENT_IF_ENABLED(array);
    FOUNDATIONAL_LIB_PUTCHAR('[');

    for (size_t i = 0; i < size; ++i)
    {
        const unsigned short value = array[i];
        char buf[FOUNDATIONAL_LIB_SIZE_STRING_OF_NUMBER_SIZE_PLUS_ZERO_TERMINATOR];

        utoa(value, buf);
        FOUNDATIONAL_LIB_FPUTS(buf, stdout);
        if (i < size - 1)
        {
            FOUNDATIONAL_LIB_PUTCHAR(',');
            FOUNDATIONAL_LIB_PUTCHAR(' ');
        }
    }
    FOUNDATIONAL_LIB_PUTCHAR(']');
}

/**
 * @brief Prints an array of pointers to unsigned short integers.
 *
 * This function takes a pointer to an array of pointers to unsigned short
 * integers and its size as input parameters, and then prints the contents of
 * each pointed array. The size parameter indicates the number of pointers in
 * the array.
 *
 * @param array Pointer to the array of pointers to unsigned short integers to
 * be printed.
 * @param size Size of the array (number of pointers).
 */
FOUNDATIONAL_LIB_NONNULL FOUNDATIONAL_LIB_NOTHROW FOUNDATIONAL_LIB_FUNC void print_ushort_ptr_array(const unsigned short **array, size_t size)
{
    FOUNDATIONAL_LIB_ASSERT_ARGUMENT_IF_ENABLED(array);
    FOUNDATIONAL_LIB_PUTCHAR('[');

    for (size_t i = 0; i < size; ++i)
    {
        const unsigned short value = *(array[i]);
        char buf[FOUNDATIONAL_LIB_SIZE_STRING_OF_NUMBER_SIZE_PLUS_ZERO_TERMINATOR];

        utoa(value, buf);
        FOUNDATIONAL_LIB_FPUTS(buf, stdout);
        if (i < size - 1)
        {
            FOUNDATIONAL_LIB_PUTCHAR(',');
            FOUNDATIONAL_LIB_PUTCHAR(' ');
        }
    }
    FOUNDATIONAL_LIB_PUTCHAR(']');
}

/**
 * @brief Prints the contents of an array of short integers.
 *
 * This function takes a pointer to an array of short integers and its
 * size as input parameters, and then prints the contents of the array.
 * The size parameter indicates the number of elements in the array.
 *
 * @param array Pointer to the array of short integers to be printed.
 * @param size Size of the array.
 */
FOUNDATIONAL_LIB_NONNULL FOUNDATIONAL_LIB_NOTHROW FOUNDATIONAL_LIB_FUNC void print_short_array(const short *array, size_t size)
{
    FOUNDATIONAL_LIB_ASSERT_ARGUMENT_IF_ENABLED(array);
    FOUNDATIONAL_LIB_PUTCHAR('[');

    for (size_t i = 0; i < size; ++i)
    {
        const short value = array[i];
        char buf[FOUNDATIONAL_LIB_SIZE_STRING_OF_NUMBER_SIZE_PLUS_ZERO_TERMINATOR];

        int_to_string_with_buffer(value, buf);
        FOUNDATIONAL_LIB_FPUTS(buf, stdout);
        if (i < size - 1)
        {
            FOUNDATIONAL_LIB_PUTCHAR(',');
            FOUNDATIONAL_LIB_PUTCHAR(' ');
        }
    }
    FOUNDATIONAL_LIB_PUTCHAR(']');
}

/**
 * @brief Prints an array of pointers to short integers.
 *
 * This function takes a pointer to an array of pointers to short integers
 * and its size as input parameters, and then prints the contents of each
 * pointed array. The size parameter indicates the number of pointers in the
 * array.
 *
 * @param array Pointer to the array of pointers to short integers to be
 * printed.
 * @param size Size of the array (number of pointers).
 */
FOUNDATIONAL_LIB_NONNULL FOUNDATIONAL_LIB_NOTHROW FOUNDATIONAL_LIB_FUNC void print_short_ptr_array(const short **array, size_t size)
{
    FOUNDATIONAL_LIB_ASSERT_ARGUMENT_IF_ENABLED(array);
    FOUNDATIONAL_LIB_PUTCHAR('[');

    for (size_t i = 0; i < size; ++i)
    {
        const short value = *(array[i]);
        char buf[FOUNDATIONAL_LIB_SIZE_STRING_OF_NUMBER_SIZE_PLUS_ZERO_TERMINATOR];

        int_to_string_with_buffer(value, buf);
        FOUNDATIONAL_LIB_FPUTS(buf, stdout);
        if (i < size - 1)
        {
            FOUNDATIONAL_LIB_PUTCHAR(',');
            FOUNDATIONAL_LIB_PUTCHAR(' ');
        }
    }
    FOUNDATIONAL_LIB_PUTCHAR(']');
}

/**
 * @brief Prints the contents of an array of unsigned long integers.
 *
 * This function takes a pointer to an array of unsigned long integers and its
 * size as input parameters, and then prints the contents of the array. The size
 * parameter indicates the number of elements in the array.
 *
 * @param array Pointer to the array of unsigned long integers to be printed.
 * @param size Size of the array.
 */
FOUNDATIONAL_LIB_NONNULL FOUNDATIONAL_LIB_NOTHROW FOUNDATIONAL_LIB_FUNC void print_ulong_array(const unsigned long *array, size_t size)
{
    FOUNDATIONAL_LIB_ASSERT_ARGUMENT_IF_ENABLED(array);
    FOUNDATIONAL_LIB_PUTCHAR('[');

    for (size_t i = 0; i < size; ++i)
    {
        const unsigned long value = array[i];
        char buf[FOUNDATIONAL_LIB_SIZE_STRING_OF_NUMBER_SIZE_PLUS_ZERO_TERMINATOR];

        utoa(value, buf);
        FOUNDATIONAL_LIB_FPUTS(buf, stdout);
        if (i < size - 1)
        {
            FOUNDATIONAL_LIB_PUTCHAR(',');
            FOUNDATIONAL_LIB_PUTCHAR(' ');
        }
    }
    FOUNDATIONAL_LIB_PUTCHAR(']');
}

/**
 * @brief Prints an array of pointers to unsigned long integers.
 *
 * This function takes a pointer to an array of pointers to unsigned long
 * integers and its size as input parameters, and then prints the contents of
 * each pointed array. The size parameter indicates the number of pointers in
 * the array.
 *
 * @param array Pointer to the array of pointers to unsigned long integers to be
 * printed.
 * @param size Size of the array (number of pointers).
 */
FOUNDATIONAL_LIB_NONNULL FOUNDATIONAL_LIB_NOTHROW FOUNDATIONAL_LIB_FUNC void print_ulong_ptr_array(const unsigned long **array, size_t size)
{
    FOUNDATIONAL_LIB_ASSERT_ARGUMENT_IF_ENABLED(array);
    FOUNDATIONAL_LIB_PUTCHAR('[');

    for (size_t i = 0; i < size; ++i)
    {
        const unsigned long value = *(array[i]);
        char buf[FOUNDATIONAL_LIB_SIZE_STRING_OF_NUMBER_SIZE_PLUS_ZERO_TERMINATOR];

        utoa(value, buf);
        FOUNDATIONAL_LIB_FPUTS(buf, stdout);
        if (i < size - 1)
        {
            FOUNDATIONAL_LIB_PUTCHAR(',');
            FOUNDATIONAL_LIB_PUTCHAR(' ');
        }
    }
    FOUNDATIONAL_LIB_PUTCHAR(']');
}

/**
 * @brief Prints the elements of a long array.
 *
 * This function takes a pointer to a long array and the size of the array
 * as input parameters. It prints each element of the array to the standard
 * output.
 *
 * @param array Pointer to the long array.
 * @param size Size of the array.
 */
FOUNDATIONAL_LIB_NONNULL FOUNDATIONAL_LIB_NOTHROW FOUNDATIONAL_LIB_FUNC void print_long_array(const long *array, size_t size)
{
    FOUNDATIONAL_LIB_ASSERT_ARGUMENT_IF_ENABLED(array);
    FOUNDATIONAL_LIB_PUTCHAR('[');

    for (size_t i = 0; i < size; ++i)
    {
        const long value = array[i];
        char buf[FOUNDATIONAL_LIB_SIZE_STRING_OF_NUMBER_SIZE_PLUS_ZERO_TERMINATOR];

        int_to_string_with_buffer(value, buf);
        FOUNDATIONAL_LIB_FPUTS(buf, stdout);
        if (i < size - 1)
        {
            FOUNDATIONAL_LIB_PUTCHAR(',');
            FOUNDATIONAL_LIB_PUTCHAR(' ');
        }
    }
    FOUNDATIONAL_LIB_PUTCHAR(']');
}

/**
 * @brief Prints the elements of a long array.
 *
 * This function takes a pointer to a long array and its size as parameters.
 * It prints each element of the array to the standard output.
 *
 * @param array Pointer to the long array.
 * @param size Size of the array.
 */
FOUNDATIONAL_LIB_NONNULL FOUNDATIONAL_LIB_NOTHROW FOUNDATIONAL_LIB_FUNC void print_long_ptr_array(const long **array, size_t size)
{
    FOUNDATIONAL_LIB_ASSERT_ARGUMENT_IF_ENABLED(array);
    FOUNDATIONAL_LIB_PUTCHAR('[');

    for (size_t i = 0; i < size; ++i)
    {
        const long value = *(array[i]);
        char buf[FOUNDATIONAL_LIB_SIZE_STRING_OF_NUMBER_SIZE_PLUS_ZERO_TERMINATOR];

        int_to_string_with_buffer(value, buf);
        FOUNDATIONAL_LIB_FPUTS(buf, stdout);
        if (i < size - 1)
        {
            FOUNDATIONAL_LIB_PUTCHAR(',');
            FOUNDATIONAL_LIB_PUTCHAR(' ');
        }
    }
    FOUNDATIONAL_LIB_PUTCHAR(']');
}

/**
 * @brief Prints the elements of an unsigned long long array.
 *
 * This function takes a pointer to an unsigned long long array and its size as
 * parameters. It prints each element of the array to the standard output.
 *
 * @param array Pointer to the unsigned long long array.
 * @param size Size of the array.
 */
FOUNDATIONAL_LIB_NONNULL FOUNDATIONAL_LIB_NOTHROW FOUNDATIONAL_LIB_FUNC void print_ulong_long_array(const unsigned long long *array, size_t size)
{
    FOUNDATIONAL_LIB_ASSERT_ARGUMENT_IF_ENABLED(array);
    FOUNDATIONAL_LIB_PUTCHAR('[');

    for (size_t i = 0; i < size; ++i)
    {
        const unsigned long long value = array[i];
        char buf[FOUNDATIONAL_LIB_SIZE_STRING_OF_NUMBER_SIZE_PLUS_ZERO_TERMINATOR];

        utoa(value, buf);
        FOUNDATIONAL_LIB_FPUTS(buf, stdout);
        if (i < size - 1)
        {
            FOUNDATIONAL_LIB_PUTCHAR(',');
            FOUNDATIONAL_LIB_PUTCHAR(' ');
        }
    }
    FOUNDATIONAL_LIB_PUTCHAR(']');
}

/**
 * @brief Prints the elements of an unsigned long long array through a pointer.
 *
 * This function takes a pointer to a pointer to an unsigned long long array
 * and the size of the array as parameters. It prints each element of the array
 * to the standard output.
 *
 * @param array Pointer to a pointer to the unsigned long long array.
 * @param size Size of the array.
 */
FOUNDATIONAL_LIB_NONNULL FOUNDATIONAL_LIB_NOTHROW FOUNDATIONAL_LIB_FUNC void print_ulong_long_ptr_array(const unsigned long long **array, size_t size)
{
    FOUNDATIONAL_LIB_ASSERT_ARGUMENT_IF_ENABLED(array);
    FOUNDATIONAL_LIB_PUTCHAR('[');

    for (size_t i = 0; i < size; ++i)
    {
        const unsigned long long value = *(array[i]);
        char buf[FOUNDATIONAL_LIB_SIZE_STRING_OF_NUMBER_SIZE_PLUS_ZERO_TERMINATOR];

        utoa(value, buf);
        FOUNDATIONAL_LIB_FPUTS(buf, stdout);
        if (i < size - 1)
        {
            FOUNDATIONAL_LIB_PUTCHAR(',');
            FOUNDATIONAL_LIB_PUTCHAR(' ');
        }
    }
    FOUNDATIONAL_LIB_PUTCHAR(']');
}

/**
 * @brief Prints the elements of a long long array.
 *
 * This function takes a pointer to a long long array and its size as
 * parameters. It prints each element of the array to the standard output.
 *
 * @param array Pointer to the long long array.
 * @param size Size of the array.
 */
FOUNDATIONAL_LIB_NONNULL FOUNDATIONAL_LIB_NOTHROW FOUNDATIONAL_LIB_FUNC void print_long_long_array(const long long *array, size_t size)
{
    FOUNDATIONAL_LIB_ASSERT_ARGUMENT_IF_ENABLED(array);
    FOUNDATIONAL_LIB_PUTCHAR('[');

    for (size_t i = 0; i < size; ++i)
    {
        const long long value = array[i];
        char buf[FOUNDATIONAL_LIB_SIZE_STRING_OF_NUMBER_SIZE_PLUS_ZERO_TERMINATOR];

        int_to_string_with_buffer(value, buf);
        FOUNDATIONAL_LIB_FPUTS(buf, stdout);
        if (i < size - 1)
        {
            FOUNDATIONAL_LIB_PUTCHAR(',');
            FOUNDATIONAL_LIB_PUTCHAR(' ');
        }
    }
    FOUNDATIONAL_LIB_PUTCHAR(']');
}

/**
 * @brief Prints the elements of a long long array through a pointer.
 *
 * This function takes a pointer to a pointer to a long long array
 * and the size of the array as parameters. It prints each element of the array
 * to the standard output.
 *
 * @param array Pointer to a pointer to the long long array.
 * @param size Size of the array.
 */
FOUNDATIONAL_LIB_NONNULL FOUNDATIONAL_LIB_NOTHROW FOUNDATIONAL_LIB_FUNC void print_long_long_ptr_array(const long long **array, size_t size)
{
    FOUNDATIONAL_LIB_ASSERT_ARGUMENT_IF_ENABLED(array);
    FOUNDATIONAL_LIB_PUTCHAR('[');

    for (size_t i = 0; i < size; ++i)
    {
        const long long value = *(array[i]);
        char buf[FOUNDATIONAL_LIB_SIZE_STRING_OF_NUMBER_SIZE_PLUS_ZERO_TERMINATOR];

        int_to_string_with_buffer(value, buf);
        FOUNDATIONAL_LIB_FPUTS(buf, stdout);
        if (i < size - 1)
        {
            FOUNDATIONAL_LIB_PUTCHAR(',');
            FOUNDATIONAL_LIB_PUTCHAR(' ');
        }
    }
    FOUNDATIONAL_LIB_PUTCHAR(']');
}

/**
 * @brief Prints the elements of a float array.
 *
 * This function takes a pointer to a float array and its size as parameters.
 * It prints each element of the array to the standard output.
 *
 * @param array Pointer to the float array.
 * @param size Size of the array.
 */
FOUNDATIONAL_LIB_NONNULL FOUNDATIONAL_LIB_NOTHROW FOUNDATIONAL_LIB_FUNC void print_float_array(const float *array, size_t size)
{
    FOUNDATIONAL_LIB_ASSERT_ARGUMENT_IF_ENABLED(array);
    FOUNDATIONAL_LIB_PUTCHAR('[');
    for (size_t i = 0; i < size; ++i)
    {
        FOUNDATIONAL_LIB_PRINTF("%f", array[i]);
        if (i < size - 1)
        {
            FOUNDATIONAL_LIB_FPUTS(", ", stdout);
        }
    }

    FOUNDATIONAL_LIB_PUTCHAR(']');
}

/**
 * @brief Prints the elements of a float array through a pointer.
 *
 * This function takes a pointer to a pointer to a float array
 * and the size of the array as parameters. It prints each element of the array
 * to the standard output.
 *
 * @param array Pointer to a pointer to the float array.
 * @param size Size of the array.
 */
FOUNDATIONAL_LIB_NONNULL FOUNDATIONAL_LIB_NOTHROW FOUNDATIONAL_LIB_FUNC void print_float_ptr_array(const float **array, size_t size)
{
    FOUNDATIONAL_LIB_ASSERT_ARGUMENT_IF_ENABLED(array);
    FOUNDATIONAL_LIB_PUTCHAR('[');
    for (size_t i = 0; i < size; ++i)
    {
        FOUNDATIONAL_LIB_PRINTF("%f", *array[i]);
        if (i < size - 1)
        {
            FOUNDATIONAL_LIB_FPUTS(", ", stdout);
        }
    }

    FOUNDATIONAL_LIB_PUTCHAR(']');
}

/**
 * @brief Prints the elements of a double array.
 *
 * This function takes a pointer to a double array and its size as parameters.
 * It prints each element of the array to the standard output.
 *
 * @param array Pointer to the double array.
 * @param size Size of the array.
 */
FOUNDATIONAL_LIB_NONNULL FOUNDATIONAL_LIB_NOTHROW FOUNDATIONAL_LIB_FUNC void print_double_array(const double *array, size_t size)
{
    FOUNDATIONAL_LIB_ASSERT_ARGUMENT_IF_ENABLED(array);
    FOUNDATIONAL_LIB_PUTCHAR('[');
    for (size_t i = 0; i < size; ++i)
    {
        FOUNDATIONAL_LIB_PRINTF("%lf", array[i]);
        if (i < size - 1)
        {
            FOUNDATIONAL_LIB_FPUTS(", ", stdout);
        }
    }

    FOUNDATIONAL_LIB_PUTCHAR(']');
}

/**
 * @brief Prints the elements of a double array through a pointer.
 *
 * This function takes a pointer to a pointer to a double array
 * and the size of the array as parameters. It prints each element of the array
 * to the standard output.
 *
 * @param array Pointer to a pointer to the double array.
 * @param size Size of the array.
 */
FOUNDATIONAL_LIB_NONNULL FOUNDATIONAL_LIB_NOTHROW FOUNDATIONAL_LIB_FUNC void print_double_ptr_array(const double **array, size_t size)
{
    FOUNDATIONAL_LIB_ASSERT_ARGUMENT_IF_ENABLED(array);
    FOUNDATIONAL_LIB_PUTCHAR('[');
    for (size_t i = 0; i < size; ++i)
    {
        FOUNDATIONAL_LIB_PRINTF("%lf", *array[i]);
        if (i < size - 1)
        {
            FOUNDATIONAL_LIB_FPUTS(", ", stdout);
        }
    }

    FOUNDATIONAL_LIB_PUTCHAR(']');
}

/**
 * @brief Prints the elements of a size_t array.
 *
 * This function takes a pointer to a size_t array and its size as parameters.
 * It prints each element of the array to the standard output.
 *
 * @param array Pointer to the size_t array.
 * @param size Size of the array.
 */
FOUNDATIONAL_LIB_NONNULL FOUNDATIONAL_LIB_NOTHROW FOUNDATIONAL_LIB_FUNC void print_size_t_array(const size_t *array, size_t size)
{
    FOUNDATIONAL_LIB_ASSERT_ARGUMENT_IF_ENABLED(array);
    FOUNDATIONAL_LIB_PUTCHAR('[');

    for (size_t i = 0; i < size; ++i)
    {
        const size_t value = array[i];
        char buf[FOUNDATIONAL_LIB_SIZE_STRING_OF_NUMBER_SIZE_PLUS_ZERO_TERMINATOR];

        int_to_string_with_buffer(value, buf);
        FOUNDATIONAL_LIB_FPUTS(buf, stdout);
        if (i < size - 1)
        {
            FOUNDATIONAL_LIB_PUTCHAR(',');
            FOUNDATIONAL_LIB_PUTCHAR(' ');
        }
    }
    FOUNDATIONAL_LIB_PUTCHAR(']');
}

/**
 * @brief Prints the elements of a size_t array through a pointer.
 *
 * This function takes a pointer to a pointer to a size_t array
 * and the size of the array as parameters. It prints each element of the array
 * to the standard output.
 *
 * @param array Pointer to a pointer to the size_t array.
 * @param size Size of the array.
 */
FOUNDATIONAL_LIB_NONNULL FOUNDATIONAL_LIB_NOTHROW FOUNDATIONAL_LIB_FUNC void print_size_t_ptr_array(const size_t **array, size_t size)
{
    FOUNDATIONAL_LIB_ASSERT_ARGUMENT_IF_ENABLED(array);
    FOUNDATIONAL_LIB_PUTCHAR('[');

    for (size_t i = 0; i < size; ++i)
    {
        const size_t value = *(array[i]);
        char buf[FOUNDATIONAL_LIB_SIZE_STRING_OF_NUMBER_SIZE_PLUS_ZERO_TERMINATOR];

        int_to_string_with_buffer(value, buf);
        FOUNDATIONAL_LIB_FPUTS(buf, stdout);
        if (i < size - 1)
        {
            FOUNDATIONAL_LIB_PUTCHAR(',');
            FOUNDATIONAL_LIB_PUTCHAR(' ');
        }
    }
    FOUNDATIONAL_LIB_PUTCHAR(']');
}

/**
 * @brief Prints the elements of an unsigned int array to a specified stream.
 *
 * This function takes a pointer to an unsigned int array, its size, and a FILE
 * stream as parameters. It prints each element of the array to the specified
 * stream.
 *
 * @param array Pointer to the unsigned int array.
 * @param size Size of the array.
 * @param stream FILE stream to which the elements are printed.
 */
FOUNDATIONAL_LIB_NONNULL FOUNDATIONAL_LIB_NOTHROW FOUNDATIONAL_LIB_FUNC void print_uint_array_to_stream(const unsigned int *array, size_t size, FILE *stream)
{
    FOUNDATIONAL_LIB_ASSERT_ARGUMENT_IF_ENABLED(array);
    FOUNDATIONAL_LIB_FPUTC('[', stream);
    for (size_t i = 0; i < size; ++i)
    {
        FOUNDATIONAL_LIB_FPRINTF(stream, "%u", array[i]);
        if (i < size - 1)
        {
            FOUNDATIONAL_LIB_FPUTS(", ", stream);
        }
    }
    FOUNDATIONAL_LIB_FPUTS("]", stream);
}

/**
 * @brief Prints the elements of an unsigned int array through a pointer to a
 * specified stream.
 *
 * This function takes a pointer to a pointer to an unsigned int array,
 * the size of the array, and a FILE stream as parameters. It prints each
 * element of the array to the specified stream.
 *
 * @param array Pointer to a pointer to the unsigned int array.
 * @param size Size of the array.
 * @param stream FILE stream to which the elements are printed.
 */
FOUNDATIONAL_LIB_NONNULL FOUNDATIONAL_LIB_NOTHROW FOUNDATIONAL_LIB_FUNC void print_uint_ptr_array_to_stream(const unsigned int **array, size_t size, FILE *stream)
{
    FOUNDATIONAL_LIB_ASSERT_ARGUMENT_IF_ENABLED(array);
    FOUNDATIONAL_LIB_FPUTC('[', stream);
    for (size_t i = 0; i < size; ++i)
    {
        FOUNDATIONAL_LIB_FPRINTF(stream, "%u", *array[i]);
        if (i < size - 1)
        {
            FOUNDATIONAL_LIB_FPUTS(", ", stream);
        }
    }
    FOUNDATIONAL_LIB_FPUTS("]", stream);
}

/**
 * @brief Prints the elements of an int array to a specified stream.
 *
 * This function takes a pointer to an int array, its size, and a FILE stream as
 * parameters. It prints each element of the array to the specified stream.
 *
 * @param array Pointer to the int array.
 * @param size Size of the array.
 * @param stream FILE stream to which the elements are printed.
 */
FOUNDATIONAL_LIB_NONNULL FOUNDATIONAL_LIB_NOTHROW FOUNDATIONAL_LIB_FUNC void print_int_array_to_stream(const int *array, size_t size, FILE *stream)
{
    FOUNDATIONAL_LIB_ASSERT_ARGUMENT_IF_ENABLED(array);
    FOUNDATIONAL_LIB_FPUTC('[', stream);
    for (size_t i = 0; i < size; ++i)
    {
        FOUNDATIONAL_LIB_FPRINTF(stream, "%d", array[i]);
        if (i < size - 1)
        {
            FOUNDATIONAL_LIB_FPUTS(", ", stream);
        }
    }
    FOUNDATIONAL_LIB_FPUTS("]", stream);
}

/**
 * @brief Prints the elements of an int array through a pointer to a specified
 * stream.
 *
 * This function takes a pointer to a pointer to an int array,
 * the size of the array, and a FILE stream as parameters. It prints each
 * element of the array to the specified stream.
 *
 * @param array Pointer to a pointer to the int array.
 * @param size Size of the array.
 * @param stream FILE stream to which the elements are printed.
 */
FOUNDATIONAL_LIB_NONNULL FOUNDATIONAL_LIB_NOTHROW FOUNDATIONAL_LIB_FUNC void print_int_ptr_array_to_stream(const int **array, size_t size, FILE *stream)
{
    FOUNDATIONAL_LIB_ASSERT_ARGUMENT_IF_ENABLED(array);
    FOUNDATIONAL_LIB_FPUTC('[', stream);
    for (size_t i = 0; i < size; ++i)
    {
        FOUNDATIONAL_LIB_FPRINTF(stream, "%d", *array[i]);
        if (i < size - 1)
        {
            FOUNDATIONAL_LIB_FPUTS(", ", stream);
        }
    }
    FOUNDATIONAL_LIB_FPUTS("]", stream);
}

/**
 * @brief Prints the elements of an unsigned char array to a specified stream.
 *
 * This function takes a pointer to an unsigned char array, its size, and a FILE
 * stream as parameters. It prints each element of the array to the specified
 * stream.
 *
 * @param array Pointer to the unsigned char array.
 * @param size Size of the array.
 * @param stream FILE stream to which the elements are printed.
 */
FOUNDATIONAL_LIB_NONNULL FOUNDATIONAL_LIB_NOTHROW FOUNDATIONAL_LIB_FUNC void print_uchar_array_to_stream(const unsigned char *array, size_t size, FILE *stream)
{
    FOUNDATIONAL_LIB_ASSERT_ARGUMENT_IF_ENABLED(array);
    FOUNDATIONAL_LIB_FPUTC('[', stream);
    for (size_t i = 0; i < size; ++i)
    {
        FOUNDATIONAL_LIB_FPRINTF(stream, "%c", array[i]);
        if (i < size - 1)
        {
            FOUNDATIONAL_LIB_FPUTS(", ", stream);
        }
    }
    FOUNDATIONAL_LIB_FPUTS("]", stream);
}

/**
 * @brief Prints the elements of a char array to a specified stream.
 *
 * This function takes a pointer to a char array, its size, and a FILE stream as
 * parameters. It prints each element of the array to the specified stream.
 *
 * @param array Pointer to the char array.
 * @param size Size of the array.
 * @param stream FILE stream to which the elements are printed.
 */
FOUNDATIONAL_LIB_NONNULL FOUNDATIONAL_LIB_NOTHROW FOUNDATIONAL_LIB_FUNC void print_char_array_to_stream(const char *array, size_t size, FILE *stream)
{
    FOUNDATIONAL_LIB_ASSERT_ARGUMENT_IF_ENABLED(array);
    FOUNDATIONAL_LIB_FPUTC('[', stream);
    for (size_t i = 0; i < size; ++i)
    {
        FOUNDATIONAL_LIB_FPRINTF(stream, "%c", array[i]);
        if (i < size - 1)
        {
            FOUNDATIONAL_LIB_FPUTS(", ", stream);
        }
    }
    FOUNDATIONAL_LIB_FPUTS("]", stream);
}

/**
 * @brief Prints the elements of a string array to a specified stream.
 *
 * This function takes a pointer to a pointer to a char array (string),
 * the size of the array, and a FILE stream as parameters. It prints each
 * element of the array (string) to the specified stream.
 *
 * @param array Pointer to a pointer to the char array (string).
 * @param size Size of the array.
 * @param stream FILE stream to which the elements (strings) are printed.
 */
FOUNDATIONAL_LIB_NONNULL FOUNDATIONAL_LIB_NOTHROW FOUNDATIONAL_LIB_FUNC void print_string_array_to_stream(char **array, size_t size, FILE *stream)
{
    FOUNDATIONAL_LIB_ASSERT_ARGUMENT_IF_ENABLED(array);
    FOUNDATIONAL_LIB_FPUTC('[', stream);
    for (size_t i = 0; i < size; ++i)
    {
        FOUNDATIONAL_LIB_FPUTS(array[i], stream);
        if (i < size - 1)
        {
            FOUNDATIONAL_LIB_FPUTS(", ", stream);
        }
    }
    FOUNDATIONAL_LIB_FPUTS("]", stream);
}

/**
 * @brief Prints the elements of an array of string arrays to a specified
 * stream.
 *
 * This function takes a pointer to a pointer to a pointer to a char array
 * (string), the size of the array, and a FILE stream as parameters. It prints
 * each element of the array of string arrays to the specified stream.
 *
 * @param array Pointer to a pointer to a pointer to the char array (string).
 * @param size Size of the array.
 * @param stream FILE stream to which the elements (strings) are printed.
 */
FOUNDATIONAL_LIB_NONNULL FOUNDATIONAL_LIB_NOTHROW FOUNDATIONAL_LIB_FUNC void print_string_array_array_to_stream(char ***array, size_t size, FILE *stream)
{
    FOUNDATIONAL_LIB_ASSERT_ARGUMENT_IF_ENABLED(array);
    FOUNDATIONAL_LIB_FPUTC('[', stream);
    for (size_t i = 0; i < size; ++i)
    {
        FOUNDATIONAL_LIB_FPUTS(*array[i], stream);
        if (i < size - 1)
        {
            FOUNDATIONAL_LIB_FPUTS(", ", stream);
        }
    }
    FOUNDATIONAL_LIB_FPUTS("]", stream);
}

/**
 * @brief Prints the elements of an unsigned short array to a specified stream.
 *
 * This function takes a pointer to an unsigned short array, its size, and a
 * FILE stream as parameters. It prints each element of the array to the
 * specified stream.
 *
 * @param array Pointer to the unsigned short array.
 * @param size Size of the array.
 * @param stream FILE stream to which the elements are printed.
 */
FOUNDATIONAL_LIB_NONNULL FOUNDATIONAL_LIB_NOTHROW FOUNDATIONAL_LIB_FUNC void print_ushort_array_to_stream(const unsigned short *array, size_t size, FILE *stream)
{
    FOUNDATIONAL_LIB_ASSERT_ARGUMENT_IF_ENABLED(array);
    FOUNDATIONAL_LIB_FPUTC('[', stream);
    for (size_t i = 0; i < size; ++i)
    {
        FOUNDATIONAL_LIB_FPRINTF(stream, "%hu", array[i]);
        if (i < size - 1)
        {
            FOUNDATIONAL_LIB_FPUTS(", ", stream);
        }
    }
    FOUNDATIONAL_LIB_FPUTS("]", stream);
}

/**
 * @brief Prints the elements of an unsigned short array through a pointer to a
 * specified stream.
 *
 * This function takes a pointer to a pointer to an unsigned short array,
 * the size of the array, and a FILE stream as parameters. It prints each
 * element of the array to the specified stream.
 *
 * @param array Pointer to a pointer to the unsigned short array.
 * @param size Size of the array.
 * @param stream FILE stream to which the elements are printed.
 */
FOUNDATIONAL_LIB_NONNULL FOUNDATIONAL_LIB_NOTHROW FOUNDATIONAL_LIB_FUNC void print_ushort_ptr_array_to_stream(const unsigned short **array, size_t size, FILE *stream)
{
    FOUNDATIONAL_LIB_ASSERT_ARGUMENT_IF_ENABLED(array);
    FOUNDATIONAL_LIB_FPUTC('[', stream);
    for (size_t i = 0; i < size; ++i)
    {
        FOUNDATIONAL_LIB_FPRINTF(stream, "%hu", *array[i]);
        if (i < size - 1)
        {
            FOUNDATIONAL_LIB_FPUTS(", ", stream);
        }
    }
    FOUNDATIONAL_LIB_FPUTS("]", stream);
}

/**
 * @brief Prints the elements of a short array to a specified stream.
 *
 * This function takes a pointer to a short array, its size, and a FILE stream
 * as parameters. It prints each element of the array to the specified stream.
 *
 * @param array Pointer to the short array.
 * @param size Size of the array.
 * @param stream FILE stream to which the elements are printed.
 */
FOUNDATIONAL_LIB_NONNULL FOUNDATIONAL_LIB_NOTHROW FOUNDATIONAL_LIB_FUNC void print_short_array_to_stream(const short *array, size_t size, FILE *stream)
{
    FOUNDATIONAL_LIB_ASSERT_ARGUMENT_IF_ENABLED(array);
    FOUNDATIONAL_LIB_FPUTC('[', stream);
    for (size_t i = 0; i < size; ++i)
    {
        FOUNDATIONAL_LIB_FPRINTF(stream, "%d", array[i]);
        if (i < size - 1)
        {
            FOUNDATIONAL_LIB_FPUTS(", ", stream);
        }
    }
    FOUNDATIONAL_LIB_FPUTS("]", stream);
}

/**
 * @brief Prints the elements of a short array through a pointer to a specified
 * stream.
 *
 * This function takes a pointer to a pointer to a short array,
 * the size of the array, and a FILE stream as parameters. It prints each
 * element of the array to the specified stream.
 *
 * @param array Pointer to a pointer to the short array.
 * @param size Size of the array.
 * @param stream FILE stream to which the elements are printed.
 */
FOUNDATIONAL_LIB_NONNULL FOUNDATIONAL_LIB_NOTHROW FOUNDATIONAL_LIB_FUNC void print_short_ptr_array_to_stream(const short **array, size_t size, FILE *stream)
{
    FOUNDATIONAL_LIB_ASSERT_ARGUMENT_IF_ENABLED(array);
    FOUNDATIONAL_LIB_FPUTC('[', stream);
    for (size_t i = 0; i < size; ++i)
    {
        FOUNDATIONAL_LIB_FPRINTF(stream, "%d", *array[i]);
        if (i < size - 1)
        {
            FOUNDATIONAL_LIB_FPUTS(", ", stream);
        }
    }
    FOUNDATIONAL_LIB_FPUTS("]", stream);
}

/**
 * @brief Prints the elements of an unsigned long array to a specified stream.
 *
 * This function takes a pointer to an unsigned long array, its size, and a FILE
 * stream as parameters. It prints each element of the array to the specified
 * stream.
 *
 * @param array Pointer to the unsigned long array.
 * @param size Size of the array.
 * @param stream FILE stream to which the elements are printed.
 */
FOUNDATIONAL_LIB_NONNULL FOUNDATIONAL_LIB_NOTHROW FOUNDATIONAL_LIB_FUNC void print_ulong_array_to_stream(const unsigned long *array, size_t size, FILE *stream)
{
    FOUNDATIONAL_LIB_ASSERT_ARGUMENT_IF_ENABLED(array);
    FOUNDATIONAL_LIB_FPUTC('[', stream);
    for (size_t i = 0; i < size; ++i)
    {
        FOUNDATIONAL_LIB_FPRINTF(stream, "%lu", array[i]);
        if (i < size - 1)
        {
            FOUNDATIONAL_LIB_FPUTS(", ", stream);
        }
    }
    FOUNDATIONAL_LIB_FPUTS("]", stream);
}

/**
 * @brief Prints the elements of an unsigned long array through a pointer to a
 * specified stream.
 *
 * This function takes a pointer to a pointer to an unsigned long array,
 * the size of the array, and a FILE stream as parameters. It prints each
 * element of the array to the specified stream.
 *
 * @param array Pointer to a pointer to the unsigned long array.
 * @param size Size of the array.
 * @param stream FILE stream to which the elements are printed.
 */
FOUNDATIONAL_LIB_NONNULL FOUNDATIONAL_LIB_NOTHROW FOUNDATIONAL_LIB_FUNC void print_ulong_ptr_array_to_stream(const unsigned long **array, size_t size, FILE *stream)
{
    FOUNDATIONAL_LIB_ASSERT_ARGUMENT_IF_ENABLED(array);
    FOUNDATIONAL_LIB_FPUTC('[', stream);
    for (size_t i = 0; i < size; ++i)
    {
        FOUNDATIONAL_LIB_FPRINTF(stream, "%lu", *array[i]);
        if (i < size - 1)
        {
            FOUNDATIONAL_LIB_FPUTS(", ", stream);
        }
    }
    FOUNDATIONAL_LIB_FPUTS("]", stream);
}

/**
 * @brief Prints the elements of a long array to a specified stream.
 *
 * This function takes a pointer to a long array, its size, and a FILE stream as
 * parameters. It prints each element of the array to the specified stream.
 *
 * @param array Pointer to the long array.
 * @param size Size of the array.
 * @param stream FILE stream to which the elements are printed.
 */
FOUNDATIONAL_LIB_NONNULL FOUNDATIONAL_LIB_NOTHROW FOUNDATIONAL_LIB_FUNC void print_long_array_to_stream(const long *array, size_t size, FILE *stream)
{
    FOUNDATIONAL_LIB_ASSERT_ARGUMENT_IF_ENABLED(array);
    FOUNDATIONAL_LIB_FPUTC('[', stream);
    for (size_t i = 0; i < size; ++i)
    {
        FOUNDATIONAL_LIB_FPRINTF(stream, "%ld", array[i]);
        if (i < size - 1)
        {
            FOUNDATIONAL_LIB_FPUTS(", ", stream);
        }
    }
    FOUNDATIONAL_LIB_FPUTS("]", stream);
}

/**
 * @brief Prints the elements of a long array through a pointer to a specified
 * stream.
 *
 * This function takes a pointer to a pointer to a long array,
 * the size of the array, and a FILE stream as parameters. It prints each
 * element of the array to the specified stream.
 *
 * @param array Pointer to a pointer to the long array.
 * @param size Size of the array.
 * @param stream FILE stream to which the elements are printed.
 */
FOUNDATIONAL_LIB_NONNULL FOUNDATIONAL_LIB_NOTHROW FOUNDATIONAL_LIB_FUNC void print_long_ptr_array_to_stream(const long **array, size_t size, FILE *stream)
{
    FOUNDATIONAL_LIB_ASSERT_ARGUMENT_IF_ENABLED(array);
    FOUNDATIONAL_LIB_FPUTC('[', stream);
    for (size_t i = 0; i < size; ++i)
    {
        FOUNDATIONAL_LIB_FPRINTF(stream, "%ld", *array[i]);
        if (i < size - 1)
        {
            FOUNDATIONAL_LIB_FPUTS(", ", stream);
        }
    }
    FOUNDATIONAL_LIB_FPUTS("]", stream);
}

/**
 * @brief Prints the elements of an unsigned long long array to a specified
 * stream.
 *
 * This function takes a pointer to an unsigned long long array, its size,
 * and a FILE stream as parameters. It prints each element of the array
 * to the specified stream.
 *
 * @param array Pointer to the unsigned long long array.
 * @param size Size of the array.
 * @param stream FILE stream to which the elements are printed.
 */
FOUNDATIONAL_LIB_NONNULL FOUNDATIONAL_LIB_NOTHROW FOUNDATIONAL_LIB_FUNC void print_ulong_long_array_to_stream(const unsigned long long *array, size_t size, FILE *stream)
{
    FOUNDATIONAL_LIB_ASSERT_ARGUMENT_IF_ENABLED(array);
    FOUNDATIONAL_LIB_FPUTC('[', stream);
    for (size_t i = 0; i < size; ++i)
    {
        const unsigned long long value = array[i];
        char buffer[FOUNDATIONAL_LIB_SIZE_STRING_OF_NUMBER_SIZE_PLUS_ZERO_TERMINATOR];

        utoa(value, buffer);
        FOUNDATIONAL_LIB_FPUTS(buffer, stream);
        if (i < size - 1)
        {
            FOUNDATIONAL_LIB_FPUTS(", ", stream);
        }
    }
    FOUNDATIONAL_LIB_FPUTS("]", stream);
}

/**
 * @brief Prints the elements of an unsigned long long array through a pointer
 * to a specified stream.
 *
 * This function takes a pointer to a pointer to an unsigned long long array,
 * the size of the array, and a FILE stream as parameters. It prints each
 * element of the array to the specified stream.
 *
 * @param array Pointer to a pointer to the unsigned long long array.
 * @param size Size of the array.
 * @param stream FILE stream to which the elements are printed.
 */
FOUNDATIONAL_LIB_NONNULL FOUNDATIONAL_LIB_NOTHROW FOUNDATIONAL_LIB_FUNC void print_ulong_long_ptr_array_to_stream(const unsigned long long **array, size_t size, FILE *stream)
{
    FOUNDATIONAL_LIB_ASSERT_ARGUMENT_IF_ENABLED(array);
    FOUNDATIONAL_LIB_FPUTC('[', stream);
    for (size_t i = 0; i < size; ++i)
    {
        const unsigned long long value = *(array[i]);
        char buffer[FOUNDATIONAL_LIB_SIZE_STRING_OF_NUMBER_SIZE_PLUS_ZERO_TERMINATOR];

        utoa(value, buffer);
        FOUNDATIONAL_LIB_FPUTS(buffer, stream);
        if (i < size - 1)
        {
            FOUNDATIONAL_LIB_FPUTS(", ", stream);
        }
    }
    FOUNDATIONAL_LIB_FPUTS("]", stream);
}

/**
 * @brief Outputs elements of a long_long array to a stream.
 *
 * This function takes an array of long long integers and a specified size,
 * then writes each element to the provided file stream. Useful for displaying
 * or logging long_long arrays in a human-readable format.
 *
 * @param array Pointer to the long long array.
 * @param size Size of the array.
 * @param stream File stream to which the array elements will be written.
 */
FOUNDATIONAL_LIB_NONNULL FOUNDATIONAL_LIB_NOTHROW FOUNDATIONAL_LIB_FUNC void print_long_long_array_to_stream(const long long *array, size_t size, FILE *stream)
{
    FOUNDATIONAL_LIB_ASSERT_ARGUMENT_IF_ENABLED(array);
    FOUNDATIONAL_LIB_FPUTC('[', stream);
    for (size_t i = 0; i < size; ++i)
    {
        const unsigned long long value = array[i];
        char buffer[FOUNDATIONAL_LIB_SIZE_STRING_OF_NUMBER_SIZE_PLUS_ZERO_TERMINATOR];

        int_to_string_with_buffer(value, buffer);

        FOUNDATIONAL_LIB_FPUTS(buffer, stream);
        if (i < size - 1)
        {
            FOUNDATIONAL_LIB_FPUTS(", ", stream);
        }
    }
    FOUNDATIONAL_LIB_FPUTS("]", stream);
}

/**
 * @brief Outputs elements of an array of pointers to long long to a stream.
 *
 * This function takes an array of pointers to long long integers and a
 * specified size, then writes each referenced long long element to the provided
 * file stream. Useful for displaying or logging arrays of pointers to long long
 * integers.
 *
 * @param array Pointer to the array of pointers to long long.
 * @param size Size of the array.
 * @param stream File stream to which the referenced long long elements will be
 * written.
 */
FOUNDATIONAL_LIB_NONNULL FOUNDATIONAL_LIB_NOTHROW FOUNDATIONAL_LIB_FUNC void print_long_long_ptr_array_to_stream(const long long **array, size_t size, FILE *stream)
{
    FOUNDATIONAL_LIB_ASSERT_ARGUMENT_IF_ENABLED(array);
    FOUNDATIONAL_LIB_FPUTC('[', stream);
    for (size_t i = 0; i < size; ++i)
    {
        const long long value = *(array[i]);

        char buffer[FOUNDATIONAL_LIB_SIZE_STRING_OF_NUMBER_SIZE_PLUS_ZERO_TERMINATOR];

        int_to_string_with_buffer(value, buffer);
        FOUNDATIONAL_LIB_FPUTS(buffer, stream);
        if (i < size - 1)
        {
            FOUNDATIONAL_LIB_FPUTS(", ", stream);
        }
    }
    FOUNDATIONAL_LIB_FPUTS("]", stream);
}

/**
 * @brief Outputs elements of a float array to a stream.
 *
 * This function takes an array of float values and a specified size,
 * then writes each element to the provided file stream. Useful for displaying
 * or logging float arrays in a human-readable format.
 *
 * @param array Pointer to the float array.
 * @param size Size of the array.
 * @param stream File stream to which the array elements will be written.
 */
FOUNDATIONAL_LIB_NONNULL FOUNDATIONAL_LIB_NOTHROW FOUNDATIONAL_LIB_FUNC void print_float_array_to_stream(const float *array, size_t size, FILE *stream)
{
    FOUNDATIONAL_LIB_ASSERT_ARGUMENT_IF_ENABLED(array);
    FOUNDATIONAL_LIB_FPUTC('[', stream);
    for (size_t i = 0; i < size; ++i)
    {
        FOUNDATIONAL_LIB_FPRINTF(stream, "%f", array[i]);
        if (i < size - 1)
        {
            FOUNDATIONAL_LIB_FPUTS(", ", stream);
        }
    }
    FOUNDATIONAL_LIB_FPUTS("]", stream);
}

/**
 * @brief Outputs elements of an array of pointers to float to a stream.
 *
 * This function takes an array of pointers to float values and a specified
 * size, then writes each referenced float element to the provided file stream.
 * Useful for displaying or logging arrays of pointers to float values.
 *
 * @param array Pointer to the array of pointers to float.
 * @param size Size of the array.
 * @param stream File stream to which the referenced float elements will be
 * written.
 */
FOUNDATIONAL_LIB_NONNULL FOUNDATIONAL_LIB_NOTHROW FOUNDATIONAL_LIB_FUNC void print_float_ptr_array_to_stream(const float **array, size_t size, FILE *stream)
{
    FOUNDATIONAL_LIB_ASSERT_ARGUMENT_IF_ENABLED(array);
    FOUNDATIONAL_LIB_FPUTC('[', stream);
    for (size_t i = 0; i < size; ++i)
    {
        FOUNDATIONAL_LIB_FPRINTF(stream, "%f", *array[i]);
        if (i < size - 1)
        {
            FOUNDATIONAL_LIB_FPUTS(", ", stream);
        }
    }
    FOUNDATIONAL_LIB_FPUTS("]", stream);
}

/**
 * @brief Outputs elements of a double array to a stream.
 *
 * This function takes an array of double values and a specified size,
 * then writes each element to the provided file stream. Useful for displaying
 * or logging double arrays in a human-readable format.
 *
 * @param array Pointer to the double array.
 * @param size Size of the array.
 * @param stream File stream to which the array elements will be written.
 */
FOUNDATIONAL_LIB_NONNULL FOUNDATIONAL_LIB_NOTHROW FOUNDATIONAL_LIB_FUNC void print_double_array_to_stream(const double *array, size_t size, FILE *stream)
{
    FOUNDATIONAL_LIB_ASSERT_ARGUMENT_IF_ENABLED(array);
    FOUNDATIONAL_LIB_FPUTC('[', stream);
    for (size_t i = 0; i < size; ++i)
    {
        FOUNDATIONAL_LIB_FPRINTF(stream, "%lf", array[i]);
        if (i < size - 1)
        {
            FOUNDATIONAL_LIB_FPUTS(", ", stream);
        }
    }
    FOUNDATIONAL_LIB_FPUTS("]", stream);
}

/**
 * @brief Outputs elements of an array of pointers to double to a stream.
 *
 * This function takes an array of pointers to double values and a specified
 * size, then writes each referenced double element to the provided file stream.
 * Useful for displaying or logging arrays of pointers to double values.
 *
 * @param array Pointer to the array of pointers to double.
 * @param size Size of the array.
 * @param stream File stream to which the referenced double elements will be
 * written.
 */
FOUNDATIONAL_LIB_NONNULL FOUNDATIONAL_LIB_NOTHROW FOUNDATIONAL_LIB_FUNC void print_double_ptr_array_to_stream(const double **array, size_t size, FILE *stream)
{
    FOUNDATIONAL_LIB_ASSERT_ARGUMENT_IF_ENABLED(array);
    FOUNDATIONAL_LIB_FPUTC('[', stream);
    for (size_t i = 0; i < size; ++i)
    {
        FOUNDATIONAL_LIB_FPRINTF(stream, "%lf", *array[i]);
        if (i < size - 1)
        {
            FOUNDATIONAL_LIB_FPUTS(", ", stream);
        }
    }
    FOUNDATIONAL_LIB_FPUTS("]", stream);
}

/**
 * @brief Outputs elements of a size_t array to a stream.
 *
 * This function takes an array of size_t values and a specified size,
 * then writes each element to the provided file stream. Useful for displaying
 * or logging size_t arrays in a human-readable format.
 *
 * @param array Pointer to the size_t array.
 * @param size Size of the array.
 * @param stream File stream to which the array elements will be written.
 */
FOUNDATIONAL_LIB_NONNULL FOUNDATIONAL_LIB_NOTHROW FOUNDATIONAL_LIB_FUNC void print_size_t_array_to_stream(const size_t *array, size_t size, FILE *stream)
{
    FOUNDATIONAL_LIB_ASSERT_ARGUMENT_IF_ENABLED(array);
    FOUNDATIONAL_LIB_FPUTC('[', stream);
    for (size_t i = 0; i < size; ++i)
    {
        FOUNDATIONAL_LIB_FPRINTF(stream, "%zu", array[i]);

        if (i < size - 1)
        {
            FOUNDATIONAL_LIB_FPUTS(", ", stream);
        }
    }
    FOUNDATIONAL_LIB_FPUTS("]", stream);
}

/**
 * @brief Outputs elements of an array of pointers to size_t to a stream.
 *
 * This function takes an array of pointers to size_t values and a specified
 * size, then writes each referenced size_t element to the provided file stream.
 * Useful for displaying or logging arrays of pointers to size_t values.
 *
 * @param array Pointer to the array of pointers to size_t.
 * @param size Size of the array.
 * @param stream File stream to which the referenced size_t elements will be
 * written.
 */
FOUNDATIONAL_LIB_NONNULL FOUNDATIONAL_LIB_NOTHROW FOUNDATIONAL_LIB_FUNC void print_size_t_ptr_array_to_stream(const size_t **array, size_t size, FILE *stream)
{
    FOUNDATIONAL_LIB_ASSERT_ARGUMENT_IF_ENABLED(array);
    FOUNDATIONAL_LIB_FPUTC('[', stream);
    for (size_t i = 0; i < size; ++i)
    {

        FOUNDATIONAL_LIB_FPRINTF(stream, "%zu", *array[i]);
        if (i < size - 1)
        {
            FOUNDATIONAL_LIB_FPUTS(", ", stream);
        }
    }
    FOUNDATIONAL_LIB_FPUTS("]", stream);
}

/**
 * @brief Duplicates an array of elements at a shallow level.
 *
 * This function creates a new array by duplicating the elements of the input
 * array up to one level deep.
 *
 * @param array Pointer to the source array.
 * @param num_mem Number of elements in the source array.
 * @param size Size (in bytes) of each element in the array.
 *
 * @return A pointer to the newly created array or NULL if allocation fails.
 *         It is the caller's responsibility to free the allocated memory.
 */
FOUNDATIONAL_LIB_WARN_UNUSED_RESULT FOUNDATIONAL_LIB_NONNULL FOUNDATIONAL_LIB_NOTHROW FOUNDATIONAL_LIB_MALLOC FOUNDATIONAL_LIB_FUNC void *arraydup(const void *array, size_t num_mem, size_t size)
{
    FOUNDATIONAL_LIB_ASSERT_ARGUMENT_IF_ENABLED(array);
    const size_t tot_size = FOUNDATIONAL_LIB_safe_mul(num_mem, size);

    // Check num_mem so safe_mul doesn't get confused.
    if (FOUNDATIONAL_LIB_UNLIKELY(num_mem && tot_size == 0))
    {
        /* Handle memory allocation failure */
        FOUNDATIONAL_LIB_die_aggressively_if_enabled();
        return NULL;
    }
    char *duplicate = (char *)FOUNDATIONAL_LIB_MEMORY_ALLOCATOR_MALLOC(tot_size);

    if (FOUNDATIONAL_LIB_UNLIKELY(duplicate == NULL))
    {
        /* Handle memory allocation failure */
        FOUNDATIONAL_LIB_die_aggressively_if_enabled();
        return NULL;
    }

    for (size_t i = 0; i < tot_size; ++i)
    {
        duplicate[i] = ((char *)array)[i];
    }

    return (void *)duplicate;
}

/**
 * @brief Compares two strings for equality.
 *
 * This function compares two strings for equality.
 *
 * @param first The first string to compare.
 * @param second The second string to compare.
 * @return Returns 1 if the strings are equal, 0 otherwise.
 */
FOUNDATIONAL_LIB_NONNULL FOUNDATIONAL_LIB_WARN_UNUSED_RESULT FOUNDATIONAL_LIB_NOTHROW FOUNDATIONAL_LIB_PURE int equal_strings(const char *first, const char *second) { return FOUNDATIONAL_LIB_STRCMP(first, second) == 0; }

/**
 * @brief Checks if two arrays of unsigned integers are equal.
 *
 * This function compares each element of two arrays of unsigned integers to
 * determine if they are equal. Returns 1 if the arrays are identical, and 0
 * otherwise.
 *
 * @param array Pointer to the first array of unsigned integers.
 * @param array2 Pointer to the second array of unsigned integers.
 * @param size Size of the arrays to compare.
 * @return 1 if arrays are equal, 0 otherwise.
 */
FOUNDATIONAL_LIB_NONNULL FOUNDATIONAL_LIB_WARN_UNUSED_RESULT FOUNDATIONAL_LIB_NOTHROW FOUNDATIONAL_LIB_PURE int equal_array_of_uints(const unsigned int *array, const unsigned int *array2, size_t size)
{
    for (size_t i = 0; i < size; ++i)
    {
        if (array[i] != array2[i])
        {
            return 0;
        }
    }
    return 1;
}

/**
 * @brief Checks if two arrays of pointers to unsigned integers are equal.
 *
 * This function compares each element of two arrays of pointers to unsigned
 * integers to determine if they are equal. Returns 1 if the arrays of pointers
 * are identical, and 0 otherwise.
 *
 * @param array Pointer to the first array of pointers to unsigned integers.
 * @param array2 Pointer to the second array of pointers to unsigned integers.
 * @param size Size of the arrays to compare.
 * @return 1 if arrays of pointers are equal, 0 otherwise.
 */
FOUNDATIONAL_LIB_NONNULL FOUNDATIONAL_LIB_WARN_UNUSED_RESULT FOUNDATIONAL_LIB_NOTHROW FOUNDATIONAL_LIB_PURE int equal_array_of_uint_ptrs(const unsigned int **array, const unsigned int **array2, size_t size)
{
    for (size_t i = 0; i < size; ++i)
    {
        if (array[i] != array2[i])
        {
            return 0;
        }
    }
    return 1;
}

/**
 * @brief Checks if two arrays of integers are equal.
 *
 * This function compares each element of two arrays of integers to determine
 * if they are equal. Returns 1 if the arrays are identical, and 0 otherwise.
 *
 * @param array Pointer to the first array of integers.
 * @param array2 Pointer to the second array of integers.
 * @param size Size of the arrays to compare.
 * @return 1 if arrays are equal, 0 otherwise.
 */
FOUNDATIONAL_LIB_NONNULL FOUNDATIONAL_LIB_WARN_UNUSED_RESULT FOUNDATIONAL_LIB_NOTHROW FOUNDATIONAL_LIB_PURE int equal_array_of_ints(const int *array, const int *array2, size_t size)
{
    for (size_t i = 0; i < size; ++i)
    {
        if (array[i] != array2[i])
        {
            return 0;
        }
    }
    return 1;
}

/**
 * @brief Checks if two arrays of pointers to integers are equal.
 *
 * This function compares each element of two arrays of pointers to integers
 * to determine if they are equal. Returns 1 if the arrays of pointers are
 * identical, and 0 otherwise.
 *
 * @param array Pointer to the first array of pointers to integers.
 * @param array2 Pointer to the second array of pointers to integers.
 * @param size Size of the arrays to compare.
 * @return 1 if arrays of pointers are equal, 0 otherwise.
 */
FOUNDATIONAL_LIB_NONNULL FOUNDATIONAL_LIB_WARN_UNUSED_RESULT FOUNDATIONAL_LIB_NOTHROW FOUNDATIONAL_LIB_PURE int equal_array_of_int_ptrs(const int **array, const int **array2, size_t size)
{
    for (size_t i = 0; i < size; ++i)
    {
        if (array[i] != array2[i])
        {
            return 0;
        }
    }
    return 1;
}

/**
 * @brief Checks if two arrays of unsigned characters are equal.
 *
 * This function compares each element of two arrays of unsigned characters to
 * determine if they are equal. Returns 1 if the arrays are identical, and 0
 * otherwise.
 *
 * @param array Pointer to the first array of unsigned characters.
 * @param array2 Pointer to the second array of unsigned characters.
 * @param size Size of the arrays to compare.
 * @return 1 if arrays are equal, 0 otherwise.
 */
FOUNDATIONAL_LIB_NONNULL FOUNDATIONAL_LIB_WARN_UNUSED_RESULT FOUNDATIONAL_LIB_NOTHROW FOUNDATIONAL_LIB_PURE int equal_array_of_uchars(const unsigned char *array, const unsigned char *array2, size_t size)
{
    for (size_t i = 0; i < size; ++i)
    {
        if (array[i] != array2[i])
        {
            return 0;
        }
    }
    return 1;
}

/**
 * @brief Checks if two arrays of pointers to unsigned characters are equal.
 *
 * This function compares each element of two arrays of pointers to unsigned
 * characters to determine if they are equal. Returns 1 if the arrays of
 * pointers are identical, and 0 otherwise.
 *
 * @param array Pointer to the first array of pointers to unsigned characters.
 * @param array2 Pointer to the second array of pointers to unsigned characters.
 * @param size Size of the arrays to compare.
 * @return 1 if arrays of pointers are equal, 0 otherwise.
 */
FOUNDATIONAL_LIB_NONNULL FOUNDATIONAL_LIB_WARN_UNUSED_RESULT FOUNDATIONAL_LIB_NOTHROW FOUNDATIONAL_LIB_PURE int equal_array_of_uchar_ptrs(const unsigned char **array, const unsigned char **array2, size_t size)
{
    for (size_t i = 0; i < size; ++i)
    {
        if (array[i] != array2[i])
        {
            return 0;
        }
    }
    return 1;
}

/**
 * @brief Checks if two arrays of characters are equal.
 *
 * This function compares each element of two arrays of characters to determine
 * if they are equal. Returns 1 if the arrays are identical, and 0 otherwise.
 *
 * @param array Pointer to the first array of characters.
 * @param array2 Pointer to the second array of characters.
 * @param size Size of the arrays to compare.
 * @return 1 if arrays are equal, 0 otherwise.
 */
FOUNDATIONAL_LIB_NONNULL FOUNDATIONAL_LIB_WARN_UNUSED_RESULT FOUNDATIONAL_LIB_NOTHROW FOUNDATIONAL_LIB_PURE int equal_array_of_chars(const char *array, const char *array2, size_t size)
{
    for (size_t i = 0; i < size; ++i)
    {
        if (array[i] != array2[i])
        {
            return 0;
        }
    }
    return 1;
}

/**
 * @brief Checks if two arrays of pointers to characters are equal.
 *
 * This function compares each element of two arrays of pointers to characters
 * to determine if they are equal. Returns 1 if the arrays of pointers are
 * identical, and 0 otherwise.
 *
 * @param array Pointer to the first array of pointers to characters.
 * @param array2 Pointer to the second array of pointers to characters.
 * @param size Size of the arrays to compare.
 * @return 1 if arrays of pointers are equal, 0 otherwise.
 */
FOUNDATIONAL_LIB_NONNULL FOUNDATIONAL_LIB_WARN_UNUSED_RESULT FOUNDATIONAL_LIB_NOTHROW FOUNDATIONAL_LIB_PURE int equal_array_of_char_ptrs(const char **array, const char **array2, size_t size)
{
    for (size_t i = 0; i < size; ++i)
    {
        if (array[i] != array2[i])
        {
            return 0;
        }
    }
    return 1;
}

/**
 * @brief Checks if two arrays of unsigned short integers are equal.
 *
 * This function compares each element of two arrays of unsigned short integers
 * to determine if they are equal. Returns 1 if the arrays are identical, and 0
 * otherwise.
 *
 * @param array Pointer to the first array of unsigned short integers.
 * @param array2 Pointer to the second array of unsigned short integers.
 * @param size Size of the arrays to compare.
 * @return 1 if arrays are equal, 0 otherwise.
 */
FOUNDATIONAL_LIB_NONNULL FOUNDATIONAL_LIB_WARN_UNUSED_RESULT FOUNDATIONAL_LIB_NOTHROW FOUNDATIONAL_LIB_PURE int equal_array_of_ushorts(const unsigned short *array, const unsigned short *array2, size_t size)
{
    for (size_t i = 0; i < size; ++i)
    {
        if (array[i] != array2[i])
        {
            return 0;
        }
    }
    return 1;
}

/**
 * @brief Checks if two arrays of pointers to unsigned short integers are equal.
 *
 * This function compares each element of two arrays of pointers to unsigned
 * short integers to determine if they are equal. Returns 1 if the arrays of
 * pointers are identical, and 0 otherwise.
 *
 * @param array Pointer to the first array of pointers to unsigned short
 * integers.
 * @param array2 Pointer to the second array of pointers to unsigned short
 * integers.
 * @param size Size of the arrays to compare.
 * @return 1 if arrays of pointers are equal, 0 otherwise.
 */
FOUNDATIONAL_LIB_NONNULL FOUNDATIONAL_LIB_WARN_UNUSED_RESULT FOUNDATIONAL_LIB_NOTHROW FOUNDATIONAL_LIB_PURE int equal_array_of_ushort_ptrs(const unsigned short **array, const unsigned short **array2, size_t size)
{
    for (size_t i = 0; i < size; ++i)
    {
        if (array[i] != array2[i])
        {
            return 0;
        }
    }
    return 1;
}

/**
 * @brief Checks if two arrays of short integers are equal.
 *
 * This function compares each element of two arrays of short integers to
 * determine if they are equal. Returns 1 if the arrays are identical, and 0
 * otherwise.
 *
 * @param array Pointer to the first array of short integers.
 * @param array2 Pointer to the second array of short integers.
 * @param size Size of the arrays to compare.
 * @return 1 if arrays are equal, 0 otherwise.
 */
FOUNDATIONAL_LIB_NONNULL FOUNDATIONAL_LIB_WARN_UNUSED_RESULT FOUNDATIONAL_LIB_NOTHROW FOUNDATIONAL_LIB_PURE int equal_array_of_shorts(const short *array, const short *array2, size_t size)
{
    for (size_t i = 0; i < size; ++i)
    {
        if (array[i] != array2[i])
        {
            return 0;
        }
    }
    return 1;
}

/**
 * @brief Checks if two arrays of pointers to short integers are equal.
 *
 * This function compares each element of two arrays of pointers to short
 * integers to determine if they are equal. Returns 1 if the arrays of pointers
 * are identical, and 0 otherwise.
 *
 * @param array Pointer to the first array of pointers to short integers.
 * @param array2 Pointer to the second array of pointers to short integers.
 * @param size Size of the arrays to compare.
 * @return 1 if arrays of pointers are equal, 0 otherwise.
 */
FOUNDATIONAL_LIB_NONNULL FOUNDATIONAL_LIB_WARN_UNUSED_RESULT FOUNDATIONAL_LIB_NOTHROW FOUNDATIONAL_LIB_PURE int equal_array_of_short_ptrs(const short **array, const short **array2, size_t size)
{
    for (size_t i = 0; i < size; ++i)
    {
        if (array[i] != array2[i])
        {
            return 0;
        }
    }
    return 1;
}

/**
 * @brief Checks if two arrays of unsigned long integers are equal.
 *
 * This function compares each element of two arrays of unsigned long integers
 * to determine if they are equal. Returns 1 if the arrays are identical, and 0
 * otherwise.
 *
 * @param array Pointer to the first array of unsigned long integers.
 * @param array2 Pointer to the second array of unsigned long integers.
 * @param size Size of the arrays to compare.
 * @return 1 if arrays are equal, 0 otherwise.
 */
FOUNDATIONAL_LIB_NONNULL FOUNDATIONAL_LIB_WARN_UNUSED_RESULT FOUNDATIONAL_LIB_NOTHROW FOUNDATIONAL_LIB_PURE int equal_array_of_ulongs(const unsigned long *array, const unsigned long *array2, size_t size)
{
    for (size_t i = 0; i < size; ++i)
    {
        if (array[i] != array2[i])
        {
            return 0;
        }
    }
    return 1;
}

/**
 * @brief Checks if two arrays of pointers to unsigned long integers are equal.
 *
 * This function compares each element of two arrays of pointers to unsigned
 * long integers to determine if they are equal. Returns 1 if the arrays of
 * pointers are identical, and 0 otherwise.
 *
 * @param array Pointer to the first array of pointers to unsigned long
 * integers.
 * @param array2 Pointer to the second array of pointers to unsigned long
 * integers.
 * @param size Size of the arrays to compare.
 * @return 1 if arrays of pointers are equal, 0 otherwise.
 */
FOUNDATIONAL_LIB_NONNULL FOUNDATIONAL_LIB_WARN_UNUSED_RESULT FOUNDATIONAL_LIB_NOTHROW FOUNDATIONAL_LIB_PURE int equal_array_of_ulong_ptrs(const unsigned long **array, const unsigned long **array2, size_t size)
{
    for (size_t i = 0; i < size; ++i)
    {
        if (array[i] != array2[i])
        {
            return 0;
        }
    }
    return 1;
}

/**
 * @brief Checks if two arrays of long integers are equal.
 *
 * This function compares each element of two arrays of long integers to
 * determine if they are equal. Returns 1 if the arrays are identical, and 0
 * otherwise.
 *
 * @param array Pointer to the first array of long integers.
 * @param array2 Pointer to the second array of long integers.
 * @param size Size of the arrays to compare.
 * @return 1 if arrays are equal, 0 otherwise.
 */
FOUNDATIONAL_LIB_NONNULL FOUNDATIONAL_LIB_WARN_UNUSED_RESULT FOUNDATIONAL_LIB_NOTHROW FOUNDATIONAL_LIB_PURE int equal_array_of_longs(const long *array, const long *array2, size_t size)
{
    for (size_t i = 0; i < size; ++i)
    {
        if (array[i] != array2[i])
        {
            return 0;
        }
    }
    return 1;
}

/**
 * @brief Checks if two arrays of pointers to long integers are equal.
 *
 * This function compares each element of two arrays of pointers to long
 * integers to determine if they are equal. Returns 1 if the arrays of pointers
 * are identical, and 0 otherwise.
 *
 * @param array Pointer to the first array of pointers to long integers.
 * @param array2 Pointer to the second array of pointers to long integers.
 * @param size Size of the arrays to compare.
 * @return 1 if arrays of pointers are equal, 0 otherwise.
 */
FOUNDATIONAL_LIB_NONNULL FOUNDATIONAL_LIB_WARN_UNUSED_RESULT FOUNDATIONAL_LIB_NOTHROW FOUNDATIONAL_LIB_PURE int equal_array_of_long_ptrs(const long **array, const long **array2, size_t size)
{
    for (size_t i = 0; i < size; ++i)
    {
        if (array[i] != array2[i])
        {
            return 0;
        }
    }
    return 1;
}

/**
 * @brief Checks if two arrays of unsigned long long integers are equal.
 *
 * This function compares each element of two arrays of unsigned long long
 * integers to determine if they are equal. Returns 1 if the arrays are
 * identical, and 0 otherwise.
 *
 * @param array Pointer to the first array of unsigned long long integers.
 * @param array2 Pointer to the second array of unsigned long long integers.
 * @param size Size of the arrays to compare.
 * @return 1 if arrays are equal, 0 otherwise.
 */
FOUNDATIONAL_LIB_NONNULL FOUNDATIONAL_LIB_WARN_UNUSED_RESULT FOUNDATIONAL_LIB_NOTHROW FOUNDATIONAL_LIB_PURE int equal_array_of_ulong_longs(const unsigned long long *array, const unsigned long long *array2, size_t size)
{
    for (size_t i = 0; i < size; ++i)
    {
        if (array[i] != array2[i])
        {
            return 0;
        }
    }
    return 1;
}

/**
 * @brief Checks if two arrays of pointers to unsigned long long integers are
 * equal.
 *
 * This function compares each element of two arrays of pointers to unsigned
 * long long integers to determine if they are equal. Returns 1 if the arrays of
 * pointers are identical, and 0 otherwise.
 *
 * @param array Pointer to the first array of pointers to unsigned long long
 * integers.
 * @param array2 Pointer to the second array of pointers to unsigned long long
 * integers.
 * @param size Size of the arrays to compare.
 * @return 1 if arrays of pointers are equal, 0 otherwise.
 */
FOUNDATIONAL_LIB_NONNULL FOUNDATIONAL_LIB_WARN_UNUSED_RESULT FOUNDATIONAL_LIB_NOTHROW FOUNDATIONAL_LIB_PURE int equal_array_of_ulong_long_ptrs(const unsigned long long **array, const unsigned long long **array2, size_t size)
{
    for (size_t i = 0; i < size; ++i)
    {
        if (array[i] != array2[i])
        {
            return 0;
        }
    }
    return 1;
}

/**
 * @brief Checks if two arrays of long long integers are equal.
 *
 * This function compares each element of two arrays of long long integers to
 * determine if they are equal. Returns 1 if the arrays are identical, and 0
 * otherwise.
 *
 * @param array Pointer to the first array of long long integers.
 * @param array2 Pointer to the second array of long long integers.
 * @param size Size of the arrays to compare.
 * @return 1 if arrays are equal, 0 otherwise.
 */
FOUNDATIONAL_LIB_NONNULL FOUNDATIONAL_LIB_WARN_UNUSED_RESULT FOUNDATIONAL_LIB_NOTHROW FOUNDATIONAL_LIB_PURE int equal_array_of_long_longs(const long long *array, const long long *array2, size_t size)
{
    for (size_t i = 0; i < size; ++i)
    {
        if (array[i] != array2[i])
        {
            return 0;
        }
    }
    return 1;
}

/**
 * @brief Checks if two arrays of pointers to long long integers are equal.
 *
 * This function compares each element of two arrays of pointers to long long
 * integers to determine if they are equal. Returns 1 if the arrays of pointers
 * are identical, and 0 otherwise.
 *
 * @param array Pointer to the first array of pointers to long long integers.
 * @param array2 Pointer to the second array of pointers to long long integers.
 * @param size Size of the arrays to compare.
 * @return 1 if arrays of pointers are equal, 0 otherwise.
 */
FOUNDATIONAL_LIB_NONNULL FOUNDATIONAL_LIB_WARN_UNUSED_RESULT FOUNDATIONAL_LIB_NOTHROW FOUNDATIONAL_LIB_PURE int equal_array_of_long_long_ptrs(const long long **array, const long long **array2, size_t size)
{
    for (size_t i = 0; i < size; ++i)
    {
        if (array[i] != array2[i])
        {
            return 0;
        }
    }
    return 1;
}

/**
 * @brief Checks if two arrays of float values are equal.
 *
 * This function compares each element of two arrays of float values to
 * determine if they are equal. Returns 1 if the arrays are identical, and 0
 * otherwise.
 *
 * @param array Pointer to the first array of float values.
 * @param array2 Pointer to the second array of float values.
 * @param size Size of the arrays to compare.
 * @return 1 if arrays are equal, 0 otherwise.
 */
FOUNDATIONAL_LIB_NONNULL FOUNDATIONAL_LIB_WARN_UNUSED_RESULT FOUNDATIONAL_LIB_NOTHROW FOUNDATIONAL_LIB_PURE int equal_array_of_floats(const float *array, const float *array2, size_t size)
{
    for (size_t i = 0; i < size; ++i)
    {
        if (array[i] != array2[i])
        {
            return 0;
        }
    }
    return 1;
}

/**
 * @brief Checks if two arrays of pointers to float values are equal.
 *
 * This function compares each element of two arrays of pointers to float values
 * to determine if they are equal. Returns 1 if the arrays of pointers are
 * identical, and 0 otherwise.
 *
 * @param array Pointer to the first array of pointers to float values.
 * @param array2 Pointer to the second array of pointers to float values.
 * @param size Size of the arrays to compare.
 * @return 1 if arrays of pointers are equal, 0 otherwise.
 */
FOUNDATIONAL_LIB_NONNULL FOUNDATIONAL_LIB_WARN_UNUSED_RESULT FOUNDATIONAL_LIB_NOTHROW FOUNDATIONAL_LIB_PURE int equal_array_of_float_ptrs(const float **array, const float **array2, size_t size)
{
    for (size_t i = 0; i < size; ++i)
    {
        if (array[i] != array2[i])
        {
            return 0;
        }
    }
    return 1;
}

/**
 * @brief Checks if two arrays of doubles are equal.
 *
 * This function compares two arrays of doubles element-wise to determine if
 * they are equal.
 *
 * @param array Pointer to the first array.
 * @param array2 Pointer to the second array.
 * @param size Size of the arrays.
 * @return An integer value: 1 if arrays are equal, 0 otherwise.
 */
FOUNDATIONAL_LIB_NONNULL FOUNDATIONAL_LIB_WARN_UNUSED_RESULT FOUNDATIONAL_LIB_NOTHROW FOUNDATIONAL_LIB_PURE int equal_array_of_doubles(const double *array, const double *array2, size_t size)
{
    for (size_t i = 0; i < size; ++i)
    {
        if (array[i] != array2[i])
        {
            return 0;
        }
    }
    return 1;
}

/**
 * @brief Compares arrays of double pointers for equality.
 *
 * This function compares two arrays of double pointers element-wise to check if
 * they are equal.
 *
 * @param array Pointer to the first array of double pointers.
 * @param array2 Pointer to the second array of double pointers.
 * @param size Size of the arrays.
 * @return An integer value: 1 if arrays are equal, 0 otherwise.
 */
FOUNDATIONAL_LIB_NONNULL FOUNDATIONAL_LIB_WARN_UNUSED_RESULT FOUNDATIONAL_LIB_NOTHROW FOUNDATIONAL_LIB_PURE int equal_array_of_double_ptrs(const double **array, const double **array2, size_t size)
{
    for (size_t i = 0; i < size; ++i)
    {
        if (array[i] != array2[i])
        {
            return 0;
        }
    }
    return 1;
}

/**
 * @brief Checks if two arrays of size_t values are equal.
 *
 * This function compares two arrays of size_t values element-wise to determine
 * if they are equal.
 *
 * @param array Pointer to the first array of size_t values.
 * @param array2 Pointer to the second array of size_t values.
 * @param size Size of the arrays.
 * @return An integer value: 1 if arrays are equal, 0 otherwise.
 */
FOUNDATIONAL_LIB_NONNULL FOUNDATIONAL_LIB_WARN_UNUSED_RESULT FOUNDATIONAL_LIB_NOTHROW FOUNDATIONAL_LIB_PURE int equal_array_of_size_ts(const size_t *array, const size_t *array2, size_t size)
{
    for (size_t i = 0; i < size; ++i)
    {
        if (array[i] != array2[i])
        {
            return 0;
        }
    }
    return 1;
}

/**
 * @brief Compares arrays of size_t pointers for equality.
 *
 * This function compares two arrays of size_t pointers element-wise to check if
 * they are equal.
 *
 * @param array Pointer to the first array of size_t pointers.
 * @param array2 Pointer to the second array of size_t pointers.
 * @param size Size of the arrays.
 * @return An integer value: 1 if arrays are equal, 0 otherwise.
 */
FOUNDATIONAL_LIB_NONNULL FOUNDATIONAL_LIB_WARN_UNUSED_RESULT FOUNDATIONAL_LIB_NOTHROW FOUNDATIONAL_LIB_PURE int equal_array_of_size_t_ptrs(const size_t **array, const size_t **array2, size_t size)
{
    FOUNDATIONAL_LIB_ASSERT_ARGUMENT_IF_ENABLED(array);
    for (size_t i = 0; i < size; ++i)
    {
        if (array[i] != array2[i])
        {
            return 0;
        }
    }
    return 1;
}

/**
 * @brief Converts a given input string to its JSON representation.
 *
 * This function iterates through each character of the input string, escaping
 * special characters like double quotes and backslashes to create a valid JSON
 * string.
 *
 * @param input_string The input string to be converted to JSON format.
 *
 * @return A pointer to the newly created JSON string, or NULL if memory
 * allocation fails. The caller is responsible for freeing the allocated memory.
 */
FOUNDATIONAL_LIB_NONNULL FOUNDATIONAL_LIB_WARN_UNUSED_RESULT FOUNDATIONAL_LIB_NOTHROW FOUNDATIONAL_LIB_MALLOC FOUNDATIONAL_LIB_FUNC char *string_to_json(const char *input_string)
{
    FOUNDATIONAL_LIB_ASSERT_ARGUMENT_IF_ENABLED(input_string);
    size_t escaped_length = 0;
    size_t input_length = 0;

    /* Calculate the length of the escaped string */

    while (input_string[input_length])
    {
        if (input_string[input_length] == '"' || input_string[input_length] == '\\')
        {
            // If the string uses most of memory and is filled with \ or ", there could be an overflow.
            // Check for this.
            // If you find this too slow, just change the macro definition.
            FOUNDATIONAL_LIB_safe_increment(escaped_length, overflow); // Need to escape with a backslash
        }

        // If the string uses most of memory and is filled with \ or ", there could be an overflow.
        // Check for this.
        FOUNDATIONAL_LIB_safe_increment(escaped_length, overflow);

        // Cannot overflow because it's a size_t that starts from 0.
        // (Actually, it can, if all of memory is nonzero.)
        // Do not check for this.
        ++input_length;
    }

    /* Calculate the length of the resulting JSON string */

    size_t json_length;

    json_length = escaped_length;

    // add 2 for double quotes
    if (FOUNDATIONAL_LIB_safe_add_2_ptr(json_length, 2, &json_length) == 0)
        goto overflow;

    size_t alloc_size;

    alloc_size = json_length + sizeof(""); // +1 for null terminator
    if (FOUNDATIONAL_LIB_UNLIKELY(alloc_size == 0))
        goto overflow;

    char *json_result;

    json_result = (char *)FOUNDATIONAL_LIB_MEMORY_ALLOCATOR_MALLOC(alloc_size);

    if (FOUNDATIONAL_LIB_UNLIKELY(json_result == NULL))
    {
        goto memory_error;
    }

    /* Add double quotes around the escaped string */
    json_result[0] = '"';

    // Start a 1 for j because index 0 is a quote mark.
    for (size_t j = 1, i = 0; i < input_length; ++i, ++j)
    {
        // Add unlikely because this isn't that probable.
        if (FOUNDATIONAL_LIB_UNLIKELY(input_string[i] == '"' || input_string[i] == '\\'))
        {
            json_result[j] = '\\';
            ++j;
        }

        // i is the index for the input string and j is the index for the json result
        json_result[j] = input_string[i];
    }

    // Add the second quote
    json_result[json_length - 1] = '"';

    // Null-terminate the string
    json_result[json_length] = '\0';

    return json_result;

overflow:
memory_error:
    FOUNDATIONAL_LIB_die_aggressively_if_enabled();
    return NULL;
}

/**
 * @brief Trims leading and trailing whitespace from a given string.
 *
 * This function takes a string as input and removes any leading and trailing
 * whitespace characters, returning a new dynamically allocated string with
 * the trimmed content. It is the caller's responsibility to free the memory
 * allocated for the new string.
 *
 * @param str The input string to be trimmed.
 * @return A pointer to the trimmed string or NULL if memory allocation fails.
 *         The caller should free the returned pointer when done using it.
 */
FOUNDATIONAL_LIB_NONNULL FOUNDATIONAL_LIB_WARN_UNUSED_RESULT FOUNDATIONAL_LIB_NOTHROW FOUNDATIONAL_LIB_MALLOC FOUNDATIONAL_LIB_FUNC char *strip(const char *str)
{
    FOUNDATIONAL_LIB_ASSERT_ARGUMENT_IF_ENABLED(str);
    size_t end = FOUNDATIONAL_LIB_STRLEN(str);

    size_t start;

    start = 0;

    /* Trim leading whitespace */
    while (FOUNDATIONAL_LIB_ISSPACE(str[start]))
    {
        ++start;
    }

    /* Trim trailing whitespace */
    while (end > start && FOUNDATIONAL_LIB_ISSPACE(str[end - 1]))
    {
        --end;
    }

    /* Copy the stripped portion into a new string */

    // End is always greater than start. Should never underflow.

    const size_t memcpy_len = end - start;
    size_t alloc_len = memcpy_len;

    if (FOUNDATIONAL_LIB_UNLIKELY(alloc_len == SIZE_MAX))
        goto overflow;
    ++alloc_len;

    char *result;
    result = (char *)FOUNDATIONAL_LIB_MEMORY_ALLOCATOR_MALLOC(alloc_len); /* Safe. */

    if (FOUNDATIONAL_LIB_UNLIKELY(result == NULL))
        goto memory_error;

    // Copy everything before the null byte.
    FOUNDATIONAL_LIB_MEMCPY(result, str + start, memcpy_len); /* Safe. */
    result[memcpy_len] = '\0';

    return result;

overflow:
memory_error:
    FOUNDATIONAL_LIB_die_aggressively_if_enabled();
    return NULL;
}

/**
 * @brief Splits a given string into an array based on a specified delimiter.
 *
 * This function takes a string as input and splits it into an array of strings,
 * using the provided delimiter. Delimiters are included in the result if
 * keep_delim_in_result is true. Memory is dynamically allocated for the array
 * of strings, and the caller is responsible for freeing this memory.
 *
 * @param str The input string to be split.
 * @param output_size A pointer to a size_t variable to store the number of tokens.
 * @param delim The delimiter string for splitting the input string.
 * @param max_times Maximum number of times to split the string (0 for unlimited).
 * @param keep_delim_in_result A boolean indicating whether to keep delimiters in the result.
 * @return An array of strings representing the tokens, or NULL in case of
 * errors. The caller should free the memory allocated for the array and its
 * elements.
 */
FOUNDATIONAL_LIB_NONNULL FOUNDATIONAL_LIB_WARN_UNUSED_RESULT FOUNDATIONAL_LIB_NOTHROW FOUNDATIONAL_LIB_FUNC char **split(const char *str, size_t *output_size, const char *delim, size_t max_times, int keep_delim_in_result)
{
    FOUNDATIONAL_LIB_ASSERT_ARGUMENT_IF_ENABLED(str);
    FOUNDATIONAL_LIB_ASSERT_ARGUMENT_IF_ENABLED(output_size);
    FOUNDATIONAL_LIB_ASSERT_ARGUMENT_IF_ENABLED(delim);

    /* Count the number of tokens */
    *output_size = 1;
    const size_t delim_len = FOUNDATIONAL_LIB_STRLEN(delim);

    for (const char *ptr = FOUNDATIONAL_LIB_STRSTR(str, delim); ptr != NULL && (max_times == 0 || *output_size < max_times); ptr = FOUNDATIONAL_LIB_STRSTR(ptr + delim_len, delim))
    {
        ++(*output_size);
    }

    const size_t new_len = FOUNDATIONAL_LIB_safe_mul(*output_size, sizeof(char *));

    // Check output_size so safe_mul doesn't get confused.
    if (FOUNDATIONAL_LIB_UNLIKELY(new_len == 0 && *output_size))
        goto overflow;

    /* Allocate memory for the array of strings */
    char **result;

    result = (char **)FOUNDATIONAL_LIB_MEMORY_ALLOCATOR_MALLOC(new_len);
    if (FOUNDATIONAL_LIB_UNLIKELY(result == NULL))
        goto memory_error;

    const char *token_start;

    token_start = str;
    const char *ptr;

    /* Split the string into tokens */
    for (size_t i = 0; i < *output_size; ++i)
    {
        ptr = FOUNDATIONAL_LIB_STRSTR(token_start, delim);

        if (ptr != NULL)
        {
            // Should not overflow.
            size_t token_length = (size_t)(ptr - token_start);

            if (keep_delim_in_result)
            {
                token_length += delim_len;
            }

            const size_t alloc_len = token_length + sizeof("");

            result[i] = (char *)FOUNDATIONAL_LIB_MEMORY_ALLOCATOR_MALLOC(alloc_len); /* Safe. */
            if (FOUNDATIONAL_LIB_UNLIKELY(result[i] == NULL))
            {
                FOUNDATIONAL_LIB_MEMORY_ALLOCATOR_FREE(result);
                goto memory_error;
            }

            FOUNDATIONAL_LIB_MEMCPY(result[i], token_start, token_length); /* Safe. */
            result[i][token_length] = '\0';

            token_start = ptr + delim_len; // Move to the next token
        }
        else /* ptr is NULL */
        {
            // Last token, copy the remaining part of the string
            const size_t token_length = FOUNDATIONAL_LIB_STRLEN(token_start);

            // The only way this could overflow is if strlen(token_length) == SIZE_MAX.
            //
            // But I don't see how that would be possible, because there would have to
            // be a null terminator for strlen() to work. So it would have to be
            // SIZE_MAX - 1, unless strlen() is broken. Since it would have to be
            // SIZE_MAX - 1, adding 1 to it wouldn't cause an overflow.
            // Therefore, this is safe code.

            const size_t alloc_len = token_length + sizeof("");

            result[i] = (char *)FOUNDATIONAL_LIB_MEMORY_ALLOCATOR_MALLOC(alloc_len); /* Safe. */

            if (FOUNDATIONAL_LIB_UNLIKELY(result[i] == NULL))
            {
                FOUNDATIONAL_LIB_MEMORY_ALLOCATOR_FREE(result);
                goto memory_error;
            }

            FOUNDATIONAL_LIB_MEMCPY(result[i], token_start, token_length); /* Safe. */
            result[i][token_length] = '\0';
        }
    }

    return result;

overflow:
memory_error:
    FOUNDATIONAL_LIB_die_aggressively_if_enabled();
    return NULL;
}

/**
 * @brief Joins an array of strings into a single string using a specified
 * delimiter.
 *
 * This function takes an array of strings, a count of elements in the array,
 * and a delimiter. It concatenates the strings with the delimiter in between,
 * creating a new dynamically allocated string. The caller is responsible for
 * freeing the memory allocated for the resulting string.
 *
 * @param array An array of strings to be joined.
 * @param count The number of elements in the array.
 * @param delimiter The string used as a delimiter between joined elements.
 * @return A new string representing the joined elements, or NULL in case of
 * errors. The caller should free the memory allocated for the resulting string.
 */
FOUNDATIONAL_LIB_NONNULL FOUNDATIONAL_LIB_WARN_UNUSED_RESULT FOUNDATIONAL_LIB_NOTHROW FOUNDATIONAL_LIB_MALLOC FOUNDATIONAL_LIB_FUNC char *join(const char **array, size_t count, const char *delimiter)
{
    FOUNDATIONAL_LIB_ASSERT_ARGUMENT_IF_ENABLED(array);
    FOUNDATIONAL_LIB_ASSERT_ARGUMENT_IF_ENABLED(delimiter);

    const size_t new_size = FOUNDATIONAL_LIB_safe_mul(sizeof(size_t), count);
    // Check count so safe_mul doesn't get confused.
    if (FOUNDATIONAL_LIB_UNLIKELY(new_size == 0 && count))
        goto overflow;
    size_t *lens;

    lens = (size_t *)FOUNDATIONAL_LIB_MEMORY_ALLOCATOR_MALLOC(new_size);
    if (FOUNDATIONAL_LIB_UNLIKELY(lens == NULL))
        goto memory_error;
    size_t delimeter_length;

    delimeter_length = FOUNDATIONAL_LIB_STRLEN(delimiter);
    /* Calculate the total length of the resulting string */
    size_t total_length;

    total_length = 1; // NUL byte
    for (size_t i = 0; i < count; ++i)
    {
        const size_t new_len = FOUNDATIONAL_LIB_STRLEN(array[i]);
        lens[i] = new_len;
        total_length += new_len;
        if (i < count - 1)
        {
            total_length += delimeter_length;
        }
    }

    /* Allocate memory for the resulting string */
    char *result;

    result = (char *)FOUNDATIONAL_LIB_MEMORY_ALLOCATOR_MALLOC(total_length);
    if (FOUNDATIONAL_LIB_UNLIKELY(result == NULL))
    {
        goto memory_error;
    }
    size_t len_so_far;

    len_so_far = 0;
    size_t array_index;

    /* Concatenate strings with the delimiter */
    for (array_index = 0; array_index < count; ++array_index)
    {
        const size_t len = lens[array_index];

        /* Copy string */
        for (size_t x = 0; x < len; ++x)
        {
            result[len_so_far + x] = array[array_index][x];
        }

        len_so_far += len;
        if (array_index < count - 1)
        {
            /* Copy delimiter */
            for (size_t i = 0; i < delimeter_length; ++i)
            {
                result[len_so_far + i] = delimiter[i];
            }
            len_so_far += delimeter_length;
        }
    }

    result[len_so_far] = '\0';

    FOUNDATIONAL_LIB_MEMORY_ALLOCATOR_FREE(lens);

    return result;

memory_error:
overflow:
    FOUNDATIONAL_LIB_die_aggressively_if_enabled();
    return NULL;
}

/**
 * @brief Appends a new string to an existing string and updates its length and
 * allocation size.
 *
 * This function appends the specified string to the end of the target string.
 * If the target string has not been allocated yet or its current allocation
 * size is insufficient, the function dynamically reallocates memory as needed.
 * The caller is responsible for freeing the memory allocated for the target
 * string.
 *
 * @param string A pointer to the target string.
 * @param string_length A pointer to the size_t variable representing the
 * current length of the target string.
 * @param string_alloc_size A pointer to the size_t variable representing the
 * current allocated size of the target string.
 * @param string_to_get_appended The string to be appended.
 * @param string_to_get_appended_length A pointer to the size_t variable
 * representing the length of the string to be appended.
 * @return 0 on success, -1 on error.
 */
FOUNDATIONAL_LIB_NONNULL FOUNDATIONAL_LIB_NOTHROW FOUNDATIONAL_LIB_FUNC int append_string_to_string(char **string, size_t *string_length, size_t *string_alloc_size, const char *string_to_get_appended, size_t string_to_get_appended_length)
{
    FOUNDATIONAL_LIB_ASSERT_ARGUMENT_IF_ENABLED(string);
    FOUNDATIONAL_LIB_ASSERT_ARGUMENT_IF_ENABLED(string_length);
    FOUNDATIONAL_LIB_ASSERT_ARGUMENT_IF_ENABLED(string_alloc_size);
    FOUNDATIONAL_LIB_ASSERT_ARGUMENT_IF_ENABLED(string_to_get_appended);

    // Calculate the new length after appending the new string.
    size_t new_size = FOUNDATIONAL_LIB_safe_add_3(*string_length, string_to_get_appended_length, 1); // Adding 1 for null terminator.

    if (FOUNDATIONAL_LIB_UNLIKELY(new_size == 0))
        goto overflow;

    // If the new length exceeds the current allocation size, reallocate memory.
    if (new_size > *string_alloc_size)
    {
        new_size = FOUNDATIONAL_LIB_REALLOC_REALLOCATION_ALGORITHM(new_size);

        if (FOUNDATIONAL_LIB_UNLIKELY(new_size == 0))
            goto overflow;

        char *new_string = (char *)FOUNDATIONAL_LIB_MEMORY_ALLOCATOR_REALLOC(*string, new_size);

        if (FOUNDATIONAL_LIB_UNLIKELY(new_string == NULL))
            goto memory_error;
        *string = new_string;
        *string_alloc_size = new_size;
    }

    // Append the new string to the target string.
    FOUNDATIONAL_LIB_MEMCPY(*string + *string_length, string_to_get_appended, string_to_get_appended_length); /* Safe. */
    *string_length = *string_length + string_to_get_appended_length;

    // Null-terminate the resulting string.
    (*string)[*string_length] = '\0';

    return 0;

memory_error:
overflow:
    FOUNDATIONAL_LIB_die_aggressively_if_enabled();
    return -1;
}

#define FOUNDATIONAL_LIB_INITIAL_DATA_ARRAY_ALLOC_SIZE FOUNDATIONAL_LIB_INITIAL_STRING_ARRAY_ALLOC_SIZE

/**
 * @brief Appends a new element to the end of a dynamically allocated
 * array and updates its size.
 *
 * This function adds a new element to the end of the specified array. If the
 * array has already been allocated with malloc, the function
 * resizes it accordingly. If the array's current allocation size is 0, a new
 * array is dynamically allocated. Memory is reallocated as needed to
 * accommodate the new element. The caller is responsible for freeing the memory
 * allocated for the array.
 *
 * @param array A pointer to the array of strings.
 * @param array_size A pointer to the size_t variable representing the current
 * size of the array.
 * @param array_current_alloc_size A pointer to the size_t variable representing
 * the current allocated size of the array.
 * @param element The string element to be appended.
 * @return 0 on success, -1 on error.
 * @note The caller should free the memory allocated for the array. Make sure
 * that *array_current_alloc_size is initialized to 0 or a higher value when
 * calling this function.
 */
FOUNDATIONAL_LIB_NONNULL FOUNDATIONAL_LIB_NOTHROW FOUNDATIONAL_LIB_FUNC int append_data_to_array(void **array, size_t *array_size, size_t *array_current_alloc_size, void *data, size_t data_size)
{
    FOUNDATIONAL_LIB_ASSERT_ARGUMENT_IF_ENABLED(array);
    FOUNDATIONAL_LIB_ASSERT_ARGUMENT_IF_ENABLED(array_size);

    FOUNDATIONAL_LIB_ASSERT_ARGUMENT_IF_ENABLED(array_current_alloc_size);
    FOUNDATIONAL_LIB_ASSERT_ARGUMENT_IF_ENABLED(data);

    // The _no_alloc functions omit this for optimization.
    if (*array_current_alloc_size == 0)
    {
        *array = (void *)FOUNDATIONAL_LIB_MEMORY_ALLOCATOR_MALLOC(FOUNDATIONAL_LIB_INITIAL_DATA_ARRAY_ALLOC_SIZE);
        if (FOUNDATIONAL_LIB_UNLIKELY(*array == NULL))
        {
            *array_size = 0;
            *array_current_alloc_size = 0;
            goto memory_error;
        }
        *array_size = FOUNDATIONAL_LIB_INITIAL_STRING_ARRAY_ALLOC_COUNT;
        *array_current_alloc_size = FOUNDATIONAL_LIB_INITIAL_STRING_ARRAY_ALLOC_SIZE;
    }

    size_t new_size;

    new_size = FOUNDATIONAL_LIB_safe_add_2(*array_size, 1);

    size_t mul;

    if (FOUNDATIONAL_LIB_UNLIKELY(new_size == 0))
        goto overflow;

    mul = FOUNDATIONAL_LIB_safe_mul(new_size, data_size);

    // Check new_size and data_size so safe_mul doesn't get confused.
    if (FOUNDATIONAL_LIB_UNLIKELY(mul == 0 && new_size && data_size))
        goto overflow;

    // Realloc if needed.
    if (mul > *array_current_alloc_size)
    {
        const size_t new_size_total = FOUNDATIONAL_LIB_REALLOC_REALLOCATION_ALGORITHM(mul);

        if (FOUNDATIONAL_LIB_UNLIKELY(new_size_total == 0))
            goto overflow;

        void **new_array = (void **)FOUNDATIONAL_LIB_MEMORY_ALLOCATOR_REALLOC(*array, new_size_total);
        if (FOUNDATIONAL_LIB_UNLIKELY(new_array == NULL))
            goto memory_error;

        *array = new_array;
        *array_current_alloc_size = new_size_total;
    }

    /* Copy the data. */

    // Safe because *array_size * data_size is smaller than the number that
    // we checked for overflow.
    FOUNDATIONAL_LIB_MEMCPY((char *)*array + (*array_size) * data_size, data, data_size); /* Safe. */
    ++*array_size;
    return 0;

overflow:
memory_error:
    FOUNDATIONAL_LIB_die_aggressively_if_enabled();
    return -1;
}

/**
 * @brief Appends a new element to the end of a dynamically allocated
 * array and updates its size.
 *
 * This function adds a new element to the end of the specified array. If the
 * array has already been allocated with malloc, the function
 * resizes it accordingly. Memory is reallocated as needed to
 * accommodate the new element. The caller is responsible for freeing the memory
 * allocated for the array.
 *
 * @param array A pointer to the array of strings.
 * @param array_size A pointer to the size_t variable representing the current
 * size of the array.
 * @param array_current_alloc_size A pointer to the size_t variable representing
 * the current allocated size of the array.
 * @param element The string element to be appended.
 * @return 0 on success, -1 on error.
 * @note The caller should free the memory allocated for the array. This
 * function is an optimization of append_data_to_array that doesn't check "if
 * (*array_current_alloc_size == 0)" constantly. Use wisely. Make sure that
 * *array_current_alloc_size is initialized to 0 or a higher value when calling
 * this function.
 */
FOUNDATIONAL_LIB_NONNULL FOUNDATIONAL_LIB_NOTHROW FOUNDATIONAL_LIB_FUNC int append_data_to_array_no_initial_alloc(void **array, size_t *array_size, size_t *array_current_alloc_size, void *data, size_t data_size)
{
    FOUNDATIONAL_LIB_ASSERT_ARGUMENT_IF_ENABLED(array);
    FOUNDATIONAL_LIB_ASSERT_ARGUMENT_IF_ENABLED(array_size);

    FOUNDATIONAL_LIB_ASSERT_ARGUMENT_IF_ENABLED(array_current_alloc_size);
    FOUNDATIONAL_LIB_ASSERT_ARGUMENT_IF_ENABLED(data);

    const size_t new_size = FOUNDATIONAL_LIB_safe_add_2(*array_size, 1);

    if (FOUNDATIONAL_LIB_UNLIKELY(new_size == 0))
        goto overflow;

    size_t nsize;

    nsize = FOUNDATIONAL_LIB_safe_mul(new_size, data_size);

    if (FOUNDATIONAL_LIB_UNLIKELY(nsize == 0 && new_size && data_size))
        goto overflow;

    if (nsize > *array_current_alloc_size)
    {
        const size_t new_size_total = FOUNDATIONAL_LIB_REALLOC_REALLOCATION_ALGORITHM(nsize);

        if (FOUNDATIONAL_LIB_UNLIKELY(new_size_total == 0))
            goto overflow;

        void **new_array = (void **)FOUNDATIONAL_LIB_MEMORY_ALLOCATOR_REALLOC(*array, new_size_total);
        if (FOUNDATIONAL_LIB_UNLIKELY(new_array == NULL))
            goto memory_error;
        *array = new_array;
        *array_current_alloc_size = new_size_total;
    }

    /* Copy the data. */

    // Safe because *array_size * data_size is smaller than the number that
    // we checked for overflow.
    FOUNDATIONAL_LIB_MEMCPY((char *)*array + (*array_size) * data_size, data, data_size); /* Safe. */

    ++*array_size;
    return 0;

overflow:
memory_error:
    FOUNDATIONAL_LIB_die_aggressively_if_enabled();
    return -1;
}

/**
 * @brief Appends a new string element to the end of a dynamically allocated
 * array of strings and updates its size.
 *
 * This function adds a new string element to the end of the specified array of
 * strings. If the array has already been allocated with malloc, the function
 * resizes it accordingly. If the array's current allocation size is 0, a new
 * array is dynamically allocated. Memory is reallocated as needed to
 * accommodate the new element. The caller is responsible for freeing the memory
 * allocated for the array.
 *
 * @param array A pointer to the array of strings.
 * @param array_size A pointer to the size_t variable representing the current
 * size of the array.
 * @param array_current_alloc_size A pointer to the size_t variable representing
 * the current allocated size of the array.
 * @param element The string element to be appended.
 * @return 0 on success, -1 on error.
 * @note The caller should free the memory allocated for the array. Make sure
 * that *array_current_alloc_size is initialized to 0 or a higher value when
 * calling this function.
 */
FOUNDATIONAL_LIB_NONNULL FOUNDATIONAL_LIB_NOTHROW FOUNDATIONAL_LIB_FUNC int append_string_to_array(char ***array, size_t *array_size, size_t *array_current_alloc_size, const char *string)
{
    FOUNDATIONAL_LIB_ASSERT_ARGUMENT_IF_ENABLED(array);
    FOUNDATIONAL_LIB_ASSERT_ARGUMENT_IF_ENABLED(array_size);

    FOUNDATIONAL_LIB_ASSERT_ARGUMENT_IF_ENABLED(array_current_alloc_size);
    FOUNDATIONAL_LIB_ASSERT_ARGUMENT_IF_ENABLED(string);

    // The _no_alloc functions omit this for optimization.
    if (*array_current_alloc_size == 0)
    {
        *array = (char **)FOUNDATIONAL_LIB_MEMORY_ALLOCATOR_MALLOC(FOUNDATIONAL_LIB_INITIAL_STRING_ARRAY_ALLOC_SIZE);
        if (FOUNDATIONAL_LIB_UNLIKELY(*array == NULL))
        {
            *array_size = 0;
            *array_current_alloc_size = 0;
            goto memory_error;
        }
        *array_size = FOUNDATIONAL_LIB_INITIAL_STRING_ARRAY_ALLOC_COUNT;
        *array_current_alloc_size = FOUNDATIONAL_LIB_INITIAL_STRING_ARRAY_ALLOC_SIZE;
    }

    size_t new_size;

    new_size = FOUNDATIONAL_LIB_safe_add_2(*array_size, 1); // Null terminator

    if (FOUNDATIONAL_LIB_UNLIKELY(new_size == 0))
        goto overflow;
    size_t new_size_total;

    new_size_total = FOUNDATIONAL_LIB_safe_mul(new_size, sizeof(char *));

    // Array size can be 0, which would confuse FOUNDATIONAL_LIB_safe_mul.
    if (FOUNDATIONAL_LIB_UNLIKELY(new_size_total == 0 && *array_size))
        goto overflow;

    if (new_size_total > *array_current_alloc_size)
    {
        new_size_total = FOUNDATIONAL_LIB_REALLOC_REALLOCATION_ALGORITHM(new_size_total);
        if (FOUNDATIONAL_LIB_UNLIKELY(new_size_total == 0))
            goto overflow;

        char **new_array = (char **)FOUNDATIONAL_LIB_MEMORY_ALLOCATOR_REALLOC(*array, new_size_total);
        if (FOUNDATIONAL_LIB_UNLIKELY(new_array == NULL))
            goto memory_error;
        *array = new_array;
        *array_current_alloc_size = new_size_total;
    }

    (*array)[*array_size] = (char *)string;

    ++*array_size;
    return 0;

overflow:
memory_error:
    FOUNDATIONAL_LIB_die_aggressively_if_enabled();
    return -1;
}

/**
 * @brief Appends a new string element to the end of a dynamically allocated
 * array of strings and updates its size.
 *
 * This function adds a new string element to the end of the specified array of
 * strings. If the array has already been allocated with malloc, the function
 * resizes it accordingly. If the array's current allocation size is 0, an error
 * will occur - do not do this. Memory is reallocated as needed to accommodate
 * the new element. The caller is responsible for freeing the memory allocated
 * for the array.
 *
 * @param array A pointer to the array of strings.
 * @param array_size A pointer to the size_t variable representing the current
 * size of the array.
 * @param array_current_alloc_size A pointer to the size_t variable representing
 * the current allocated size of the array.
 * @param element The string element to be appended.
 * @return 0 on success, -1 on error.
 * @note The caller should free the memory allocated for the array. This
 * function is an optimization of append_string_to_array that doesn't check "if
 * (*array_current_alloc_size == 0)" constantly. Use wisely. Make sure that
 * *array_current_alloc_size is initialized to 0 or a higher value when calling
 * this function.
 */
FOUNDATIONAL_LIB_NONNULL FOUNDATIONAL_LIB_NOTHROW FOUNDATIONAL_LIB_FUNC int append_string_to_array_no_initial_alloc(char ***array, size_t *array_size, size_t *array_current_alloc_size, const char *string)
{

    FOUNDATIONAL_LIB_ASSERT_ARGUMENT_IF_ENABLED(array);
    FOUNDATIONAL_LIB_ASSERT_ARGUMENT_IF_ENABLED(array_size);

    FOUNDATIONAL_LIB_ASSERT_ARGUMENT_IF_ENABLED(array_current_alloc_size);
    FOUNDATIONAL_LIB_ASSERT_ARGUMENT_IF_ENABLED(string);

    const size_t new_size = FOUNDATIONAL_LIB_safe_add_2(*array_size, 1); // Null terminator

    if (FOUNDATIONAL_LIB_UNLIKELY(new_size == 0))
        goto overflow;
    size_t new_size_total;

    new_size_total = FOUNDATIONAL_LIB_safe_mul(new_size, sizeof(char *));

    // Array size can be 0, which would confuse FOUNDATIONAL_LIB_safe_mul.
    if (FOUNDATIONAL_LIB_UNLIKELY(new_size_total == 0 && *array_size))
        goto overflow;

    if (new_size_total > *array_current_alloc_size)
    {
        new_size_total = FOUNDATIONAL_LIB_REALLOC_REALLOCATION_ALGORITHM(new_size_total);
        if (FOUNDATIONAL_LIB_UNLIKELY(new_size_total == 0))
            goto overflow;

        char **new_array = (char **)FOUNDATIONAL_LIB_MEMORY_ALLOCATOR_REALLOC(*array, new_size_total);
        if (FOUNDATIONAL_LIB_UNLIKELY(new_array == NULL))
            goto memory_error;
        *array = new_array;
        *array_current_alloc_size = new_size_total;
    }

    (*array)[*array_size] = (char *)string;

    ++*array_size;
    return 0;

overflow:
memory_error:
    FOUNDATIONAL_LIB_die_aggressively_if_enabled();
    return -1;
}

/**
 * @brief Prepends a new string element to the beginning of a dynamically
 * allocated array of strings and updates its size.
 *
 * This function adds a new string element to the beginning of the specified
 * array of strings. If the array has already been allocated with malloc, the
 * function resizes it accordingly. If the array's current allocation size is 0,
 * a new array is dynamically allocated. Memory is reallocated as needed to
 * accommodate the new element, and existing elements are shifted to make room
 * for the prepended element. The caller is responsible for freeing the memory
 * allocated for the array.
 *
 * @param array A pointer to the array of strings.
 * @param array_size A pointer to the size_t variable representing the current
 * size of the array.
 * @param array_current_alloc_size A pointer to the size_t variable representing
 * the current allocated size of the array.
 * @param element The string element to be prepended.
 * @return 0 on success, -1 on error.
 * @note The caller should free the memory allocated for the array. Make sure
 * that *array_current_alloc_size is initialized to 0 or a higher value when
 * calling this function.
 */
FOUNDATIONAL_LIB_NONNULL FOUNDATIONAL_LIB_NOTHROW FOUNDATIONAL_LIB_FUNC int prepend_string_to_array(char ***array, size_t *array_size, size_t *array_current_alloc_size, char *string)
{
    FOUNDATIONAL_LIB_ASSERT_ARGUMENT_IF_ENABLED(array);
    FOUNDATIONAL_LIB_ASSERT_ARGUMENT_IF_ENABLED(array_size);

    FOUNDATIONAL_LIB_ASSERT_ARGUMENT_IF_ENABLED(array_current_alloc_size);
    FOUNDATIONAL_LIB_ASSERT_ARGUMENT_IF_ENABLED(string);
    // The _no_alloc functions omit this for optimization.
    if (*array_current_alloc_size == 0)
    {
        *array = (char **)FOUNDATIONAL_LIB_MEMORY_ALLOCATOR_MALLOC(FOUNDATIONAL_LIB_INITIAL_STRING_ARRAY_ALLOC_SIZE);
        if (FOUNDATIONAL_LIB_UNLIKELY(*array == NULL))
        {
            /* Die immediately if enabled */
            FOUNDATIONAL_LIB_die_aggressively_if_enabled();

            *array_size = *array_current_alloc_size = 0;
            return -1;
        }

        *array_size = FOUNDATIONAL_LIB_INITIAL_STRING_ARRAY_ALLOC_COUNT;
        *array_current_alloc_size = FOUNDATIONAL_LIB_INITIAL_STRING_ARRAY_ALLOC_SIZE;
    }

    const size_t new_size = FOUNDATIONAL_LIB_safe_add_2(*array_size, 1);

    if (FOUNDATIONAL_LIB_UNLIKELY(new_size == 0))
        goto overflow;

    if (new_size > *array_current_alloc_size)
    {
        const size_t new_size_total = FOUNDATIONAL_LIB_REALLOC_REALLOCATION_ALGORITHM(new_size);
        if (FOUNDATIONAL_LIB_UNLIKELY(new_size_total == 0))
            goto overflow;

        char **new_array = (char **)FOUNDATIONAL_LIB_MEMORY_ALLOCATOR_REALLOC(*array, new_size_total);
        if (FOUNDATIONAL_LIB_UNLIKELY(new_array == NULL))
            goto memory_error;
        *array = new_array;

        *array_current_alloc_size = new_size_total;
    }

    /* Move everything forward by 1 */
    FOUNDATIONAL_LIB_MEMMOVE(*array + 1 /* dest location */, *array /* src location */, ((*array_size++) * sizeof(char *)) /* size */);

    /* Set the string in the 0th position. */
    **array = string;
    return 0;

overflow:
memory_error:
    FOUNDATIONAL_LIB_die_aggressively_if_enabled();
    return -1;
}

/**
 * @brief Prepends a new string element to the beginning of a dynamically
 * allocated array of strings and updates its size.
 *
 * This function adds a new string element to the beginning of the specified
 * array of strings. If the array has already been allocated with malloc, the
 * function resizes it accordingly. If the array's current allocation size is 0,
 * an error will occur - do not do this. Memory is reallocated as needed to
 * accommodate the new element, and existing elements are shifted to make room
 * for the prepended element. The caller is responsible for freeing the memory
 * allocated for the array.
 *
 * @param array A pointer to the array of strings.
 * @param array_size A pointer to the size_t variable representing the current
 * size of the array.
 * @param array_current_alloc_size A pointer to the size_t variable representing
 * the current allocated size of the array.
 * @param element The string element to be prepended.
 * @return 0 on success, -1 on error.
 * @note The caller should free the memory allocated for the array. This
 * function is an optimization of prepend_string_to_array that doesn't check "if
 * (*array_current_alloc_size == 0)" constantly. Use wisely. Make sure that
 * *array_current_alloc_size is initialized to 0 or a higher value when calling
 * this function.
 */
FOUNDATIONAL_LIB_NONNULL FOUNDATIONAL_LIB_NOTHROW FOUNDATIONAL_LIB_FUNC int prepend_string_to_array_no_initial_alloc(char ***array, size_t *array_size, size_t *array_current_alloc_size, char *string)
{
    FOUNDATIONAL_LIB_ASSERT_ARGUMENT_IF_ENABLED(array);
    FOUNDATIONAL_LIB_ASSERT_ARGUMENT_IF_ENABLED(array_size);

    FOUNDATIONAL_LIB_ASSERT_ARGUMENT_IF_ENABLED(array_current_alloc_size);
    FOUNDATIONAL_LIB_ASSERT_ARGUMENT_IF_ENABLED(string);
    const size_t copy_size = FOUNDATIONAL_LIB_safe_mul((*array_size), sizeof(char *));

    if (FOUNDATIONAL_LIB_UNLIKELY(copy_size == 0 && *array_size))
        goto overflow;

    size_t new_size;

    new_size = FOUNDATIONAL_LIB_safe_add_2(*array_size, 1);

    if (FOUNDATIONAL_LIB_UNLIKELY(new_size == 0))
        goto overflow;

    if (new_size > *array_current_alloc_size)
    {
        const size_t new_size_total = FOUNDATIONAL_LIB_REALLOC_REALLOCATION_ALGORITHM(new_size);

        if (FOUNDATIONAL_LIB_UNLIKELY(new_size_total == 0))
            goto overflow;

        char **new_array = (char **)FOUNDATIONAL_LIB_MEMORY_ALLOCATOR_REALLOC(*array, new_size_total);

        if (FOUNDATIONAL_LIB_UNLIKELY(new_array == NULL))
            goto memory_error;

        *array = new_array;
        *array_current_alloc_size = new_size_total;
    }

    /* Move everything forward by 1 */
    /* Does not return an error. */

    // If array size plus 1 does not overflow, this should be safe.
    FOUNDATIONAL_LIB_MEMMOVE(*array + 1 /* dest location */, *array /* src location */, (copy_size) /* size */);
    ++array_size;

    // Set the string in the 0th position.
    **array = string;
    return 0;

overflow:
memory_error:
    FOUNDATIONAL_LIB_die_aggressively_if_enabled();
    return -1;
}
/**
 * @brief Calculates the total length of strings in an array.
 *
 * This function computes the cumulative length of strings in the provided array
 * of strings. It does not include any additional memory needed for null
 * terminators.
 *
 * @param array An array of strings.
 * @param count The number of elements in the array.
 * @return The total length of strings in the array.
 */
FOUNDATIONAL_LIB_NONNULL FOUNDATIONAL_LIB_PURE FOUNDATIONAL_LIB_NOTHROW FOUNDATIONAL_LIB_FUNC size_t array_total_string_length(char **array, size_t count)
{
    FOUNDATIONAL_LIB_ASSERT_ARGUMENT_IF_ENABLED(array);
    size_t length = 0;

    for (size_t i = 0; i < count; ++i)
    {
        // NOTE: Do not check for overflows here.
        length += FOUNDATIONAL_LIB_STRLEN(array[i]);
    }

    return length;
}

#if FOUNDATIONAL_LIB_UNSAFE_FUNCTIONS_ENABLED

/**
 * @brief Escapes special characters in a given string for shell usage.
 *
 * This function takes a string as input and escapes special characters commonly
 * used in shell commands. The resulting escaped string is dynamically
 * allocated, and the caller is responsible for freeing the memory.
 *
 * @param input The input string to be escaped.
 * @return A new dynamically allocated string with escaped special characters,
 *         or NULL in case of memory allocation failure. The caller should free
 *         the memory allocated for the escaped string.
 *
 * @note Caution: Avoid using the escaped string with system() or similar
 * functions as they may introduce security vulnerabilities. Consider using
 * alternative methods such as execvp() for safer command execution in a
 * controlled environment.
 */
FOUNDATIONAL_LIB_WARN_UNUSED_RESULT FOUNDATIONAL_LIB_NONNULL FOUNDATIONAL_LIB_NOTHROW FOUNDATIONAL_LIB_MALLOC FOUNDATIONAL_LIB_FUNC char *shellescape(const char *input)
{
    FOUNDATIONAL_LIB_ASSERT_ARGUMENT_IF_ENABLED(input);
    const size_t input_len = FOUNDATIONAL_LIB_STRLEN(input);

    const size_t size_with_null_t = input_len + 1;
    if (FOUNDATIONAL_LIB_UNLIKELY(size_with_null_t == 0))
        goto overflow;
    size_t escaped_len;

    escaped_len = FOUNDATIONAL_LIB_safe_mul(2, size_with_null_t);

    if (FOUNDATIONAL_LIB_UNLIKELY(escaped_len == 0))
        goto overflow;

    char *escaped;

    escaped = (char *)FOUNDATIONAL_LIB_MEMORY_ALLOCATOR_MALLOC(escaped_len);

    if (FOUNDATIONAL_LIB_UNLIKELY(escaped == NULL))
        goto memory_error;

    size_t j;

    j = 0;

    for (size_t i = 0; i < input_len; ++i)
    {
        // Escape special characters
        if (!isalpha(input[i]) && !isdigit(input[i]))
        {
            escaped[j++] = '\\';
        }
        escaped[j++] = input[i];
    }

    escaped[j] = '\0';

    return escaped;

overflow:
memory_error:
    FOUNDATIONAL_LIB_die_aggressively_if_enabled();
    return NULL;
}
#endif

/**
 * @brief Reverses a given string.
 *
 * This function takes a string as input and reverses its order. It allocates
 * memory for the reversed string, and the caller is responsible for freeing
 * the memory.
 *
 * @param str The input string to be reversed.
 * @return A new dynamically allocated string representing the reversed input
 * string, or NULL in case of memory allocation failure. The caller should free
 *         the memory allocated for the reversed string.
 */
FOUNDATIONAL_LIB_WARN_UNUSED_RESULT FOUNDATIONAL_LIB_NONNULL FOUNDATIONAL_LIB_NOTHROW FOUNDATIONAL_LIB_MALLOC FOUNDATIONAL_LIB_FUNC char *reverse_string(const char *str)
{
    FOUNDATIONAL_LIB_ASSERT_ARGUMENT_IF_ENABLED(str);
    char *new_str = FOUNDATIONAL_LIB_MEMORY_ALLOCATOR_STRDUP(str);
    if (FOUNDATIONAL_LIB_UNLIKELY(new_str == NULL))
    {
        FOUNDATIONAL_LIB_die_aggressively_if_enabled();
        return NULL;
    }
    size_t length = FOUNDATIONAL_LIB_STRLEN(new_str);
    size_t i, j;

    for (i = 0, j = length - 1; i < j; ++i, j--)
    {
        char temp = new_str[i];
        new_str[i] = new_str[j];
        new_str[j] = temp;
    }

    return new_str;
}

/**
 *
  Checks if a string starts with a specified prefix.
 *
 * This function compares the beginning of a string with a specified prefix.
 *
 * @param str The input string to be checked.
 * @param prefix The prefix to check for at the beginning of the input string.
 * @return 1 if the input string starts with the given prefix, 0 otherwise.
 */
FOUNDATIONAL_LIB_WARN_UNUSED_RESULT FOUNDATIONAL_LIB_NONNULL FOUNDATIONAL_LIB_NOTHROW FOUNDATIONAL_LIB_PURE int starts_with(const char *str, const char *prefix) { return strncmp(str, prefix, FOUNDATIONAL_LIB_STRLEN(prefix)) == 0; }

/**
 * @brief Checks whether a given string ends with a specified suffix.
 *
 * This function compares the provided string with the specified suffix to
 * determine if the string ends with the given suffix. It calculates the lengths
 * of both the string and the suffix and performs a comparison. If the suffix is
 * longer than the string, the function returns 0; otherwise, it checks for
 * equality in the suffix portion at the end of the string.
 *
 * @param str The input string to be checked.
 * @param suffix The suffix to check for at the end of the string.
 * @return Returns 1 if the string ends with the specified suffix; otherwise,
 * returns 0.
 */
FOUNDATIONAL_LIB_WARN_UNUSED_RESULT FOUNDATIONAL_LIB_NONNULL FOUNDATIONAL_LIB_NOTHROW FOUNDATIONAL_LIB_PURE int ends_with(const char *str, const char *suffix)
{
    const size_t str_len = FOUNDATIONAL_LIB_STRLEN(str);
    const size_t suffix_len = FOUNDATIONAL_LIB_STRLEN(suffix);

    if (suffix_len > str_len)
    {
        return 0; // Suffix is longer than the string
    }

    return strncmp(str + str_len - suffix_len, suffix, suffix_len) == 0;
}

#if defined(__GNUC__) && !defined(_WIN32)

/* @brief Cross platform memmem() */

#define memory_locate memmem

#else

/* @brief Cross platform memmem(). Slower though. We need to find a faster solution for Windows. Maybe using assembly. */
FOUNDATIONAL_LIB_FUNC void *memory_locate(const void *haystack, size_t haystack_len, const void *needle, size_t needle_len)
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
#endif

/**
 * @brief Counts the occurrences of a specified substring within a given string.
 *
 * This function takes a source string and a target substring as input and
 * returns the number of times the substring appears in the source string. It
 * performs a case-sensitive search and provides an accurate count of
 * occurrences.
 *
 * @param str The source string in which occurrences are counted.
 * @param substring The target substring whose occurrences are being counted.
 *
 * @return The number of times the specified substring appears in the source
 * string.
 */
FOUNDATIONAL_LIB_WARN_UNUSED_RESULT FOUNDATIONAL_LIB_NONNULL FOUNDATIONAL_LIB_NOTHROW FOUNDATIONAL_LIB_PURE FOUNDATIONAL_LIB_FUNC size_t count_occurrences_of_substr(const char *str, const char *substring)
{
    FOUNDATIONAL_LIB_ASSERT_ARGUMENT_IF_ENABLED(str);
    FOUNDATIONAL_LIB_ASSERT_ARGUMENT_IF_ENABLED(substring);
    const size_t substring_length = FOUNDATIONAL_LIB_STRLEN(substring);
    const char *pos = str;
    size_t count = 0;

    while ((pos = FOUNDATIONAL_LIB_STRSTR(pos, substring)) != NULL)
    {
        ++count;
        pos += substring_length;
    }

    return count;
}

/**
 * @brief Checks if a substring exists within a given string.
 *
 * This function examines the specified string to determine if a substring
 * with the specified content and length is present.
 *
 * @param string Pointer to the start of the string to search.
 * @param string_length Length of the string in characters.
 * @param substring Pointer to the substring to search for within the string.
 * @param substring_length Length of the substring in characters.
 *
 * @return Returns 1 (true) if the substring is found, 0 (false) otherwise.
 *
 * @note This function assumes that the provided string and substring pointers
 *       are valid and that the lengths are non-negative.
 *       It is the responsibility of the caller to ensure the correctness of
 *       the inputs to prevent undefined behavior.
 * @note The function uses character-based lengths for strings, not byte-based.
 *       Ensure that the string and substring lengths represent the number of
 *       characters, not the number of bytes.
 */
FOUNDATIONAL_LIB_WARN_UNUSED_RESULT FOUNDATIONAL_LIB_NONNULL FOUNDATIONAL_LIB_NOTHROW FOUNDATIONAL_LIB_PURE FOUNDATIONAL_LIB_FUNC int string_has_substr(const char *string, size_t string_length, const char *substring, size_t substring_length)
{
    FOUNDATIONAL_LIB_ASSERT_ARGUMENT_IF_ENABLED(string);

    FOUNDATIONAL_LIB_ASSERT_ARGUMENT_IF_ENABLED(substring);

    if (FOUNDATIONAL_LIB_UNLIKELY(string_length == 0))
    {
        return 0;
    }

    if (FOUNDATIONAL_LIB_UNLIKELY(substring_length == 0))
    {
        return 0;
    }

    const char *beginning_of_substr_or_null = FOUNDATIONAL_LIB_STRSTR(string, substring);
    return beginning_of_substr_or_null != NULL;
}

/**
 * @brief Checks if a subchunk exists within a given memory block.
 *
 * This function examines the specified memory block to determine if a subchunk
 * with the specified content and length is present.
 *
 * @param memory Pointer to the start of the memory block to search.
 * @param memory_length Length of the memory block in bytes.
 * @param subchunk Pointer to the subchunk to search for within the memory block.
 * @param subchunk_length Length of the subchunk in bytes.
 *
 * @return Returns 1 (true) if the subchunk is found, 0 (false) otherwise.
 *
 * @note This function assumes that the provided memory and subchunk pointers
 *       are valid and that the lengths are non-negative.
 *       It is the responsibility of the caller to ensure the correctness of
 *       the inputs to prevent undefined behavior.
 */
FOUNDATIONAL_LIB_WARN_UNUSED_RESULT FOUNDATIONAL_LIB_NONNULL FOUNDATIONAL_LIB_NOTHROW FOUNDATIONAL_LIB_PURE FOUNDATIONAL_LIB_FUNC int memory_has_subchunk(void *memory, size_t memory_length, void *subchunk, size_t subchunk_length)
{
    FOUNDATIONAL_LIB_ASSERT_ARGUMENT_IF_ENABLED(memory);

    FOUNDATIONAL_LIB_ASSERT_ARGUMENT_IF_ENABLED(subchunk);

    if (FOUNDATIONAL_LIB_UNLIKELY(memory_length == 0))
    {
        return 0;
    }

    // Alias to memmem() if we can.
    return (const char *)memory_locate(memory, memory_length, subchunk, subchunk_length) != NULL;
}

/**
 * @brief Counts the occurrences of a specified substring within a given string.
 *
 * This function takes a source string and a target substring as input and
 * returns the number of times the substring appears in the source string. It
 * performs a case-sensitive search and provides an accurate count of
 * occurrences.
 *
 * @param str The source string in which occurrences are counted.
 * @param substring The target substring whose occurrences are being counted.
 * @param substring_length The length of the substring.
 *
 * @return The number of times the specified substring appears in the source
 * string.
 *
 * @note It is undefined behavior how this function works if a NUL terminator
 * is present in the array.
 */
FOUNDATIONAL_LIB_WARN_UNUSED_RESULT FOUNDATIONAL_LIB_NONNULL FOUNDATIONAL_LIB_NOTHROW FOUNDATIONAL_LIB_PURE FOUNDATIONAL_LIB_FUNC size_t count_occurrences_of_substr_len(const char *string, size_t string_length, const char *substring, size_t substring_length)
{
    FOUNDATIONAL_LIB_ASSERT_ARGUMENT_IF_ENABLED(string);

    FOUNDATIONAL_LIB_ASSERT_ARGUMENT_IF_ENABLED(substring);

    if (FOUNDATIONAL_LIB_UNLIKELY(string_length == 0))
    {
        return 0;
    }

    if (FOUNDATIONAL_LIB_UNLIKELY(substring_length == 0))
    {
        return 0;
    }

#if defined(__GNUC__) && defined(__unix__)
    size_t count = 0;
    size_t pos = 0;

    const size_t orig_string_length = string_length;
    /* This might be significantly faster than FOUNDATIONAL_LIB_STRSTR() */
    for (;;)
    {
        const char *beginning_of_substr_or_null = (const char *)memmem(string + pos, string_length, substring, substring_length);

        if (FOUNDATIONAL_LIB_UNLIKELY(beginning_of_substr_or_null == NULL))
            break;

        ++count;

        /* Update pos */
        pos = beginning_of_substr_or_null - string + substring_length;
        string_length = orig_string_length - pos;
    }
#else
    const char *pos = string;
    size_t count = 0;
    while ((pos = FOUNDATIONAL_LIB_STRSTR(pos, substring)) != NULL)
    {
        ++count;
        pos += substring_length;
    }
#endif

    return count;
}

/**
 * @brief Finds the index of the first occurrence of a specified character in a
 * string.
 *
 * This function searches for the first occurrence of the given target character
 * in the provided string and returns its index. If the character is not found,
 * it returns -1.
 *
 * @param str The null-terminated string to search.
 * @param chr The character to locate within the string.
 * @return The index of the target character in the string, or -1 if not found.
 */
FOUNDATIONAL_LIB_WARN_UNUSED_RESULT FOUNDATIONAL_LIB_NONNULL FOUNDATIONAL_LIB_NOTHROW FOUNDATIONAL_LIB_PURE ssize_t index_of_char(const char *str, char chr)
{
    FOUNDATIONAL_LIB_ASSERT_ARGUMENT_IF_ENABLED(str);
    const char *result = FOUNDATIONAL_LIB_STRCHR(str, chr);
    return result != NULL ? result - str : -1;
}

/**
 * @brief Finds the index of the last occurrence of a specified character in a
 * given string.
 *
 * This function scans the provided string from the end to the beginning,
 * searching for the last occurrence of the specified target character. If
 * found, it returns the index of that occurrence; otherwise, it returns a
 * special value indicating that the character was not found in the string.
 *
 * @param str The input string to be searched.
 * @param chr The character to be found within the string.
 * @return The index of the last occurrence of the target character, or -1 if
 * not found.
 */
FOUNDATIONAL_LIB_WARN_UNUSED_RESULT FOUNDATIONAL_LIB_NONNULL FOUNDATIONAL_LIB_NOTHROW FOUNDATIONAL_LIB_PURE ssize_t last_index_of_char(const char *str, char chr)
{
    FOUNDATIONAL_LIB_ASSERT_ARGUMENT_IF_ENABLED(str);
    const char *result = strrchr(str, chr);
    return result != NULL ? result - str : -1;
}

/**
 * @brief Checks if the provided string consists solely of numeric characters.
 *
 * This function iterates through each character in the given string, verifying
 * whether it is a numeric digit. If a non-numeric character is encountered, the
 * function concludes that the string contains characters other than digits and
 * returns 0. Otherwise, if all characters are numeric, the function returns 1.
 *
 * @param str Pointer to the input string to be checked.
 * @return 1 if the string contains only numeric characters, 0 otherwise.
 */
FOUNDATIONAL_LIB_WARN_UNUSED_RESULT FOUNDATIONAL_LIB_NONNULL FOUNDATIONAL_LIB_NOTHROW FOUNDATIONAL_LIB_PURE FOUNDATIONAL_LIB_FUNC int is_string_numeric(const char *str)
{

    FOUNDATIONAL_LIB_ASSERT_ARGUMENT_IF_ENABLED(str);

    const size_t len = FOUNDATIONAL_LIB_STRLEN(str);

    for (size_t i = 0; i < len; ++i)
    {
        if (!FOUNDATIONAL_LIB_ISDIGIT(str[i]))
        {
            return 0; // Contains non-numeric character
        }
    }

    return 1; // Contains only numeric characters
}

/**
 * @brief Determines whether a given string consists solely of alphanumeric
 * characters.
 *
 * This function examines each character in the input string and verifies if it
 * is an alphanumeric character. Alphanumeric characters include both letters
 * (A-Z, a-z) and digits (0-9). The function returns a non-zero value if the
 * string contains only alphanumeric characters; otherwise, it returns 0.
 *
 * @param str Pointer to the input string to be checked.
 * @return An integer indicating whether the string is alphanumeric (non-zero)
 * or not (0).
 *
 */
FOUNDATIONAL_LIB_WARN_UNUSED_RESULT FOUNDATIONAL_LIB_NONNULL FOUNDATIONAL_LIB_NOTHROW FOUNDATIONAL_LIB_PURE FOUNDATIONAL_LIB_FUNC int is_string_alphanumeric(const char *str)
{
    FOUNDATIONAL_LIB_ASSERT_ARGUMENT_IF_ENABLED(str);

    size_t len = FOUNDATIONAL_LIB_STRLEN(str);

    for (size_t i = 0; i < len; ++i)
    {
        if (!FOUNDATIONAL_LIB_ISALNUM(str[i]))
        {
            return 0; // Contains non-alphanumeric character
        }
    }

    return 1; // Contains only alphanumeric characters
}

/**
 * @brief Finds the longest common prefix among an array of strings.
 *
 * This function takes an array of strings and determines the longest common
 * prefix shared by all strings. The input array 'strings' and its count 'count'
 * are used to perform the comparison.
 *
 * @param strings An array of C-style strings for which the common prefix is to
 * be found.
 * @param count The number of strings in the 'strings' array.
 * @return A pointer to the longest common prefix string. If no common prefix is
 * found, the function returns NULL.
 */
FOUNDATIONAL_LIB_WARN_UNUSED_RESULT FOUNDATIONAL_LIB_NONNULL FOUNDATIONAL_LIB_NOTHROW FOUNDATIONAL_LIB_MALLOC FOUNDATIONAL_LIB_FUNC char *longest_common_prefix(const char **strings, size_t count)
{
    FOUNDATIONAL_LIB_ASSERT_ARGUMENT_IF_ENABLED(strings);
    if (FOUNDATIONAL_LIB_UNLIKELY(count == 0))
    {
        char *ret = FOUNDATIONAL_LIB_MEMORY_ALLOCATOR_STRDUP(""); // Empty string for an empty array
        if (FOUNDATIONAL_LIB_UNLIKELY(ret == NULL))
        {
            FOUNDATIONAL_LIB_die_aggressively_if_enabled();
            return NULL;
        }

        return ret;
    }

    size_t max_common_len = FOUNDATIONAL_LIB_STRLEN(strings[0]);

    /* Find the max common length among the strings */
    for (size_t i = 1; i < count; ++i)
    {
        size_t current_len = FOUNDATIONAL_LIB_STRLEN(strings[i]);
        if (current_len < max_common_len)
        {
            max_common_len = current_len;
        }
    }

    /* Compare characters across the strings until a mismatch is found */
    for (size_t i = 0; i < max_common_len; ++i)
    {
        for (size_t j = 1; j < count; ++j)
        {
            if (strings[j][i] != strings[0][i])
            {
                /* Mismatch found, return the prefix up to this point */

                // Don't FOUNDATIONAL_LIB_MEMORY_ALLOCATOR_MALLOC 0.
                if (FOUNDATIONAL_LIB_UNLIKELY(i == SIZE_MAX))
                {
                    FOUNDATIONAL_LIB_die_aggressively_if_enabled();
                    return NULL;
                }

                char *result = (char *)FOUNDATIONAL_LIB_MEMORY_ALLOCATOR_MALLOC(i + sizeof("")); /* Safe. */
                if (FOUNDATIONAL_LIB_UNLIKELY(result == NULL))
                {
                    FOUNDATIONAL_LIB_die_aggressively_if_enabled();
                    return NULL;
                }
                FOUNDATIONAL_LIB_MEMCPY(result, strings[0], i);
                result[i] = '\0';
                return result;
            }
        }
    }

    /* All strings match up to the minimum length, return the entire prefix */
    char *dup = FOUNDATIONAL_LIB_MEMORY_ALLOCATOR_STRDUP(strings[0]);
    if (FOUNDATIONAL_LIB_UNLIKELY(dup == NULL))
    {
        FOUNDATIONAL_LIB_die_aggressively_if_enabled();
        return NULL;
    }

    return dup;
}

/**
 * @brief Finds the longest common suffix among an array of strings.
 *
 * This function takes an array of strings and determines the longest common
 * suffix shared by all the strings. The result is dynamically allocated, and
 * the caller is responsible for freeing the memory when done using the returned
 * string.
 *
 * @param strings An array of strings to find the common suffix from.
 * @param count The number of strings in the array.
 * @return A dynamically allocated string representing the longest common
 * suffix. It is the caller's responsibility to free this memory using free().
 */
FOUNDATIONAL_LIB_WARN_UNUSED_RESULT FOUNDATIONAL_LIB_NONNULL FOUNDATIONAL_LIB_NOTHROW FOUNDATIONAL_LIB_MALLOC FOUNDATIONAL_LIB_FUNC char *longest_common_suffix(const char **strings, size_t count)
{
    FOUNDATIONAL_LIB_ASSERT_ARGUMENT_IF_ENABLED(strings);

    if (FOUNDATIONAL_LIB_UNLIKELY(count == 0))
    {
        char *return_value = FOUNDATIONAL_LIB_MEMORY_ALLOCATOR_STRDUP(""); // Empty string for an empty array
        if (FOUNDATIONAL_LIB_UNLIKELY(return_value == NULL))
        {
            FOUNDATIONAL_LIB_die_aggressively_if_enabled();
            return NULL;
        }
        return return_value;
    }

    size_t max_common_len = FOUNDATIONAL_LIB_STRLEN(strings[0]);

    /* Find the max common length among the strings */
    for (size_t i = 1; i < count; ++i)
    {
        size_t current_len = FOUNDATIONAL_LIB_STRLEN(strings[i]);
        if (current_len < max_common_len)
        {
            max_common_len = current_len;
        }
    }

    /* Compare characters across the strings until a mismatch is found */
    for (size_t i = 0; i < max_common_len; ++i)
    {
        for (size_t j = 1; j < count; ++j)
        {
            size_t current_len = FOUNDATIONAL_LIB_STRLEN(strings[j]);
            if (strings[j][current_len - i - 1] != strings[0][max_common_len - i - 1])
            {
                /* Mismatch found, return the suffix up to this point */

                // Don't FOUNDATIONAL_LIB_MEMORY_ALLOCATOR_MALLOC 0.
                if (FOUNDATIONAL_LIB_UNLIKELY(i == SIZE_MAX))
                {
                    FOUNDATIONAL_LIB_die_aggressively_if_enabled();
                    return NULL;
                }

                char *result = (char *)FOUNDATIONAL_LIB_MEMORY_ALLOCATOR_MALLOC(i + sizeof("")); /* Safe. */
                if (FOUNDATIONAL_LIB_UNLIKELY(result == NULL))
                {
                    FOUNDATIONAL_LIB_die_aggressively_if_enabled();
                    return NULL;
                }

                FOUNDATIONAL_LIB_MEMCPY(result, strings[0] + max_common_len - i, i); /* Safe. */
                result[i] = '\0';
                return result;
            }
        }
    }

    /* All strings match up to the minimum length, return the entire suffix */
    char *return_value = FOUNDATIONAL_LIB_MEMORY_ALLOCATOR_STRDUP(strings[0] + max_common_len); /* Should be Safe. */
    if (FOUNDATIONAL_LIB_UNLIKELY(return_value == NULL))
    {
        FOUNDATIONAL_LIB_die_aggressively_if_enabled();
        return NULL;
    }

    return return_value;
}

/**
 * @brief Converts a string to a double-precision floating-point number.
 *
 * Parses the given null-terminated string to extract a numerical value
 * and returns it as a double-precision floating-point number.
 *
 * @param str The input string to be converted.
 * @return The resulting double-precision floating-point number.
 */
FOUNDATIONAL_LIB_WARN_UNUSED_RESULT FOUNDATIONAL_LIB_NONNULL FOUNDATIONAL_LIB_NOTHROW FOUNDATIONAL_LIB_PURE double str_to_double(const char *string)
{

    FOUNDATIONAL_LIB_ASSERT_ARGUMENT_IF_ENABLED(string);

    return atof(string);
}

/**
 * @brief Finds the first occurrence of any character from a set in a string.
 *
 * Searches the given null-terminated string for the first occurrence of any
 * character from the specified character set. Returns the index of the first
 * matching character if found; otherwise, returns -1.
 *
 * @param str The input string to search within.
 * @param char_set The set of characters to look for in the string.
 * @return The index of the first matching character, or -1 if not found.
 */
FOUNDATIONAL_LIB_WARN_UNUSED_RESULT FOUNDATIONAL_LIB_NONNULL FOUNDATIONAL_LIB_NOTHROW FOUNDATIONAL_LIB_PURE FOUNDATIONAL_LIB_FUNC ssize_t find_first_of(const char *str, const char *char_set)
{
    FOUNDATIONAL_LIB_ASSERT_ARGUMENT_IF_ENABLED(str);
    FOUNDATIONAL_LIB_ASSERT_ARGUMENT_IF_ENABLED(char_set);

    const char *result = strpbrk(str, char_set);

    return FOUNDATIONAL_LIB_LIKELY(result != NULL) ? result - str : -1;
}

/**
 * @brief Finds the last occurrence of any character from a specified set within
 * a given string.
 *
 * This function takes a string (`str`) and a character set (`char_set`) as
 * input and searches for the last occurrence of any character from the
 * specified set within the string.
 *
 * @param str The input string to be searched.
 * @param char_set The set of characters to look for in the string.
 * @return Returns the index of the last occurrence if found; otherwise, returns
 * -1.
 */
FOUNDATIONAL_LIB_WARN_UNUSED_RESULT FOUNDATIONAL_LIB_NONNULL FOUNDATIONAL_LIB_NOTHROW FOUNDATIONAL_LIB_PURE FOUNDATIONAL_LIB_FUNC ssize_t find_last_of(const char *str, const char *char_set)
{
    FOUNDATIONAL_LIB_ASSERT_ARGUMENT_IF_ENABLED(str);
    FOUNDATIONAL_LIB_ASSERT_ARGUMENT_IF_ENABLED(char_set);

    const size_t len = FOUNDATIONAL_LIB_STRLEN(str);

    for (ssize_t i = len - 1; i >= 0; i--)
    {
        if (FOUNDATIONAL_LIB_STRCHR(char_set, str[i]) != NULL)
        {
            return i;
        }
    }
    return -1;
}

/**
 * @brief Reverses a string in place.
 *
 * This function takes a null-terminated string and reverses its contents in
 * place.
 *
 * @param str Pointer to the null-terminated string to be reversed.
 */
FOUNDATIONAL_LIB_NONNULL FOUNDATIONAL_LIB_NOTHROW FOUNDATIONAL_LIB_FUNC void reverse_string_in_place(char *str)
{
    FOUNDATIONAL_LIB_ASSERT_ARGUMENT_IF_ENABLED(str);

    const size_t len = FOUNDATIONAL_LIB_STRLEN(str);

    /* Swap characters from both ends towards the center */
    for (size_t i = 0, j = len - 1; i < j; ++i, --j)
    {
        char temp = str[i];
        str[i] = str[j];
        str[j] = temp;
    }
}

/**
 * @brief Checks if a string is a valid integer.
 *
 * This function examines the given string to determine if it represents a valid
 * integer.
 *
 * @param str Pointer to the string to be checked.
 * @return 1 if the string is a valid integer, 0 otherwise.
 */
FOUNDATIONAL_LIB_WARN_UNUSED_RESULT FOUNDATIONAL_LIB_NONNULL FOUNDATIONAL_LIB_NOTHROW FOUNDATIONAL_LIB_PURE FOUNDATIONAL_LIB_FUNC int is_string_valid_integer(const char *str)
{
    FOUNDATIONAL_LIB_ASSERT_ARGUMENT_IF_ENABLED(str);

    if (*str == '\0')
    {
        return 0; // Empty string is not a valid integer
    }

    /* Check for optional sign */
    if (*str == '+' || *str == '-')
    {
        ++str;
    }

    /* Check for at least one digit */
    if (!FOUNDATIONAL_LIB_ISDIGIT(*str))
    {
        return 0;
    }

    /* Check for remaining digits */
    while (*str != '\0')
    {
        if (!FOUNDATIONAL_LIB_ISDIGIT(*str))
        {
            return 0;
        }
        ++str;
    }

    return 1; // Valid integer
}

/**
 * @brief Finds the length of the common prefix of two strings.
 *
 * This function determines the length of the common prefix between two strings.
 *
 * @param str1 Pointer to the first string.
 * @param str2 Pointer to the second string.
 * @return Length of the common prefix.
 */
FOUNDATIONAL_LIB_WARN_UNUSED_RESULT FOUNDATIONAL_LIB_NONNULL FOUNDATIONAL_LIB_NOTHROW FOUNDATIONAL_LIB_PURE FOUNDATIONAL_LIB_FUNC size_t common_prefix_length(const char *str1, const char *str2)
{
    FOUNDATIONAL_LIB_ASSERT_ARGUMENT_IF_ENABLED(str1);
    FOUNDATIONAL_LIB_ASSERT_ARGUMENT_IF_ENABLED(str2);

    const size_t len1 = FOUNDATIONAL_LIB_STRLEN(str1);
    const size_t len2 = FOUNDATIONAL_LIB_STRLEN(str2);

    const size_t min_len = (len1 < len2) ? len1 : len2;

    for (size_t i = 0; i < min_len; ++i)
    {
        if (str1[i] != str2[i])
        {
            return i; // Mismatch found, return current index
        }
    }

    return min_len; // No mismatch found, return the minimum length
}

/**
 * @brief Finds the length of the common suffix of two strings.
 *
 * This function determines the length of the common suffix between two strings.
 *
 * @param str1 Pointer to the first string.
 * @param str2 Pointer to the second string.
 * @return Length of the common suffix.
 */
FOUNDATIONAL_LIB_WARN_UNUSED_RESULT FOUNDATIONAL_LIB_NONNULL FOUNDATIONAL_LIB_NOTHROW FOUNDATIONAL_LIB_PURE FOUNDATIONAL_LIB_FUNC size_t common_suffix_length(const char *str1, const char *str2)
{
    FOUNDATIONAL_LIB_ASSERT_ARGUMENT_IF_ENABLED(str1);
    FOUNDATIONAL_LIB_ASSERT_ARGUMENT_IF_ENABLED(str2);

    const size_t len1 = FOUNDATIONAL_LIB_STRLEN(str1);
    const size_t len2 = FOUNDATIONAL_LIB_STRLEN(str2);

    const size_t min_len = (len1 < len2) ? len1 : len2;

    for (size_t i = 1; i <= min_len; ++i)
    {
        if (str1[len1 - i] != str2[len2 - i])
        {
            return i - 1; // Mismatch found, return previous index
        }
    }

    return min_len; // No mismatch found, return the minimum length
}

/**
 * @brief Converts a string to title case.
 *
 * This function converts the input string to title case, allocating memory for
 * the new string. The caller is responsible for freeing the allocated memory.
 *
 * @param str Pointer to the input string.
 * @return Pointer to the new title case string or NULL if allocation fails.
 *         The caller must free the allocated memory.
 */
FOUNDATIONAL_LIB_WARN_UNUSED_RESULT FOUNDATIONAL_LIB_NONNULL FOUNDATIONAL_LIB_NOTHROW FOUNDATIONAL_LIB_MALLOC FOUNDATIONAL_LIB_FUNC char *string_to_title_case(const char *str)
{
    FOUNDATIONAL_LIB_ASSERT_ARGUMENT_IF_ENABLED(str);

    const size_t len = FOUNDATIONAL_LIB_STRLEN(str);
    if (FOUNDATIONAL_LIB_UNLIKELY(len == SIZE_MAX))
    {
        FOUNDATIONAL_LIB_die_aggressively_if_enabled();
        return NULL;
    }

    char *title_case = (char *)FOUNDATIONAL_LIB_MEMORY_ALLOCATOR_MALLOC(len + sizeof("")); /* Safe. */

    if (FOUNDATIONAL_LIB_UNLIKELY(title_case == NULL))
    {
        FOUNDATIONAL_LIB_die_aggressively_if_enabled();
        return NULL;
    }

    int make_upper = 1; // Start with the first character as uppercase

    for (size_t i = 0; i < len; ++i)
    {
        if (FOUNDATIONAL_LIB_ISSPACE(str[i]))
        {
            make_upper = 1; // Set the flag to capitalize the next character
            title_case[i] = str[i];
        }
        else
        {
            title_case[i] = make_upper ? toupper(str[i]) : tolower(str[i]);
            make_upper = 0; // Reset the flag
        }
    }

    title_case[len] = '\0';

    return title_case;
}

/**
 * @brief Finds the maximum element in an array of integers.
 *
 * This function determines the maximum element in the given array of integers.
 *
 * @param array Pointer to the array of integers.
 * @param size Size of the array.
 * @return Maximum element in the array.
 */
FOUNDATIONAL_LIB_WARN_UNUSED_RESULT FOUNDATIONAL_LIB_NONNULL FOUNDATIONAL_LIB_NOTHROW FOUNDATIONAL_LIB_PURE FOUNDATIONAL_LIB_FUNC int find_max_int_in_array(const int *array, size_t size)
{
    FOUNDATIONAL_LIB_ASSERT_ARGUMENT_IF_ENABLED(array);
    if (FOUNDATIONAL_LIB_UNLIKELY(size == 0))
    {
        /* Handle empty array case */
        return -1;
    }

    int max = array[0];

    for (size_t i = 1; i < size; ++i)
    {
        if (array[i] > max)
        {
            max = array[i];
        }
    }

    return max;
}

/**
 * @brief Finds the minimum element in an array of integers.
 *
 * This function determines the minimum element in the given array of integers.
 *
 * @param array Pointer to the array of integers.
 * @param size Size of the array.
 * @return Minimum element in the array.
 */
FOUNDATIONAL_LIB_WARN_UNUSED_RESULT FOUNDATIONAL_LIB_NONNULL FOUNDATIONAL_LIB_NOTHROW FOUNDATIONAL_LIB_PURE FOUNDATIONAL_LIB_FUNC int find_min_int_in_array(const int *array, size_t size)
{
    FOUNDATIONAL_LIB_ASSERT_ARGUMENT_IF_ENABLED(array);
    if (FOUNDATIONAL_LIB_UNLIKELY(size == 0))
    {
        /* Handle empty array case */
        return -1;
    }

    int min = array[0];

    for (size_t i = 1; i < size; ++i)
    {
        if (array[i] < min)
        {
            min = array[i];
        }
    }

    return min;
}

/**
 * @brief Calculates the sum of elements in an array of integers.
 *
 * This function computes the sum of elements in the given array of integers.
 *
 * @param array Pointer to the array of integers.
 * @param size Size of the array.
 * @return Sum of elements in the array.
 */
FOUNDATIONAL_LIB_WARN_UNUSED_RESULT FOUNDATIONAL_LIB_NONNULL FOUNDATIONAL_LIB_NOTHROW FOUNDATIONAL_LIB_PURE FOUNDATIONAL_LIB_FUNC int sum_of_int_array(const int *array, size_t size)
{
    FOUNDATIONAL_LIB_ASSERT_ARGUMENT_IF_ENABLED(array);
    int sum = 0;

    for (size_t i = 0; i < size; ++i)
    {
        sum += array[i];
    }

    return sum;
}

/**
 * @brief Reverses an array of integers in place.
 *
 * This function takes an array of integers and reverses its order in place.
 *
 * @param array Pointer to the array of integers to be reversed.
 * @param size Size of the array.
 */
FOUNDATIONAL_LIB_NONNULL FOUNDATIONAL_LIB_NOTHROW FOUNDATIONAL_LIB_FUNC void reverse_int_array_in_place(int *array, size_t size)
{
    FOUNDATIONAL_LIB_ASSERT_ARGUMENT_IF_ENABLED(array);

    for (size_t i = 0, j = size - 1; i < j; ++i, --j)
    {
        int temp = array[i];
        array[i] = array[j];
        array[j] = temp;
    }
}

/**
 * @brief Checks if an array of integers is sorted in ascending order.
 *
 * This function examines the given array of integers to determine if it is
 * sorted in ascending order.
 *
 * @param array Pointer to the array of integers.
 * @param size Size of the array.
 * @return 1 if the array is sorted in ascending order, 0 otherwise.
 */
FOUNDATIONAL_LIB_WARN_UNUSED_RESULT FOUNDATIONAL_LIB_NONNULL FOUNDATIONAL_LIB_NOTHROW FOUNDATIONAL_LIB_PURE FOUNDATIONAL_LIB_FUNC int ints_are_sorted_ascending(const int *array, size_t size)
{
    FOUNDATIONAL_LIB_ASSERT_ARGUMENT_IF_ENABLED(array);
    for (size_t i = 1; i < size; ++i)
    {
        if (array[i] < array[i - 1])
        {
            return 0; // Not sorted in ascending order
        }
    }
    return 1; // Sorted in ascending order
}

/**
 * @brief Checks if an array of integers is sorted in descending order.
 *
 * This function examines the given array of integers to determine if it is
 * sorted in descending order.
 *
 * @param array Pointer to the array of integers.
 * @param size Size of the array.
 * @return 1 if the array is sorted in descending order, 0 otherwise.
 */
FOUNDATIONAL_LIB_WARN_UNUSED_RESULT FOUNDATIONAL_LIB_NONNULL FOUNDATIONAL_LIB_NOTHROW FOUNDATIONAL_LIB_PURE FOUNDATIONAL_LIB_FUNC int ints_are_sorted_descending(const int *array, size_t size)
{
    FOUNDATIONAL_LIB_ASSERT_ARGUMENT_IF_ENABLED(array);
    for (size_t i = 1; i < size; ++i)
    {
        if (array[i] > array[i - 1])
        {
            return 0; // Not sorted in descending order
        }
    }
    return 1; // Sorted in descending order
}

/**
 * @brief Generates a range of integers.
 *
 * This function creates an array of integers within the specified range and
 * step.
 *
 * @param start Starting value of the range.
 * @param end Ending value of the range.
 * @param step Step size between consecutive elements.
 * @param range_size Pointer to store the size of the generated range.
 * @return Pointer to the dynamically allocated array of integers representing
 * the range. The caller is responsible for freeing the allocated memory.
 */
FOUNDATIONAL_LIB_WARN_UNUSED_RESULT FOUNDATIONAL_LIB_NONNULL FOUNDATIONAL_LIB_NOTHROW FOUNDATIONAL_LIB_FUNC size_t *generate_range(size_t start, size_t end, size_t step, size_t *range_size)
{
    FOUNDATIONAL_LIB_ASSERT_ARGUMENT_IF_ENABLED(range_size);
    // Check for invalid range
    if (FOUNDATIONAL_LIB_UNLIKELY(start > end || step == 0))
    {
        FOUNDATIONAL_LIB_die_aggressively_if_enabled();
        return NULL;
    }
    const size_t size = (end - start) / step + 1;

    if (FOUNDATIONAL_LIB_UNLIKELY(size == 0))
    { // Overflow
        FOUNDATIONAL_LIB_die_aggressively_if_enabled();
        return NULL;
    }

    const size_t alloc_size = FOUNDATIONAL_LIB_safe_mul(size, sizeof(size_t));

    if (FOUNDATIONAL_LIB_UNLIKELY(alloc_size == 0))
    { // Overflow
        FOUNDATIONAL_LIB_die_aggressively_if_enabled();
        return NULL;
    }

    size_t *range = (size_t *)FOUNDATIONAL_LIB_MEMORY_ALLOCATOR_MALLOC(alloc_size);

    if (FOUNDATIONAL_LIB_UNLIKELY(range == NULL))
    {
        FOUNDATIONAL_LIB_die_aggressively_if_enabled();
        return NULL;
    }

    for (size_t i = 0, value = start; i < size; ++i, value += step)
    {
        range[i] = value;
    }

    *range_size = size;
    return range;
}

/**
 * Compare two strings pointed to by pointers for foundational library.
 *
 * This function is designed for use with sorting algorithms that require a
 * comparison function, such as qsort. It compares two strings pointed to by
 * @p p1 and @p p2.
 *
 * @param p1 Pointer to the first string.
 * @param p2 Pointer to the second string.
 * @return An integer less than, equal to, or greater than zero if the first
 *         string is found to be less than, equal to, or greater than the
 *         second string, respectively.
 */
FOUNDATIONAL_LIB_WARN_UNUSED_RESULT FOUNDATIONAL_LIB_NONNULL FOUNDATIONAL_LIB_NOTHROW FOUNDATIONAL_LIB_PURE FOUNDATIONAL_LIB_FUNC int FOUNDATIONAL_LIB_cmpstringp(const void *p1, const void *p2)
{
    FOUNDATIONAL_LIB_ASSERT_ARGUMENT_IF_ENABLED(p1);
    FOUNDATIONAL_LIB_ASSERT_ARGUMENT_IF_ENABLED(p2);
    return FOUNDATIONAL_LIB_STRCMP(*(const char **)p1, *(const char **)p2);
}

/**
 * @brief Sorts an array of strings.
 *
 * @param strings Pointer to the array of strings to be sorted.
 * @param size Size of the array.
 */
FOUNDATIONAL_LIB_NONNULL FOUNDATIONAL_LIB_FUNC void sort_strings(char **strings, size_t size)
{

    FOUNDATIONAL_LIB_ASSERT_ARGUMENT_IF_ENABLED(strings);
    qsort(strings, size, sizeof(char *), FOUNDATIONAL_LIB_cmpstringp);
}

/**
 * @brief Creates a new array of strings sorted in ascending order.
 *
 * This function takes an array of strings and returns a new array containing
 * the strings sorted in ascending order. The original array remains unchanged.
 *
 * @param strings Pointer to the array of strings to be sorted.
 * @param size Size of the array.
 * @return Pointer to the dynamically allocated array of strings sorted in
 * ascending order. The caller is responsible for freeing the allocated memory.
 */
FOUNDATIONAL_LIB_WARN_UNUSED_RESULT FOUNDATIONAL_LIB_NONNULL FOUNDATIONAL_LIB_FUNC char **sorted_strings(char **strings, size_t size)
{

    FOUNDATIONAL_LIB_ASSERT_ARGUMENT_IF_ENABLED(strings);

    char **dup_strings = (char **)arraydup(strings, size, sizeof(char *));
    if (FOUNDATIONAL_LIB_UNLIKELY(dup_strings == NULL))
    {
        return NULL; /* No need to re die aggressively. */
    }
    qsort(dup_strings, size, sizeof(char *), FOUNDATIONAL_LIB_cmpstringp);
    return dup_strings;
}

/**
 * Compare two unsigned integers for foundational library.
 *
 * This function is designed for use with sorting algorithms that require a
 * comparison function, such as qsort. It compares two unsigned integers pointed
 * to by @p a and @p b.
 *
 * @param a Pointer to the first unsigned integer.
 * @param b Pointer to the second unsigned integer.
 * @return An integer less than, equal to, or greater than zero if the first
 *         unsigned integer is found to be less than, equal to, or greater than
 *         the second unsigned integer, respectively.
 */
FOUNDATIONAL_LIB_WARN_UNUSED_RESULT FOUNDATIONAL_LIB_NONNULL FOUNDATIONAL_LIB_NOTHROW FOUNDATIONAL_LIB_PURE FOUNDATIONAL_LIB_FUNC int FOUNDATIONAL_LIB_cmp_uints(const void *a, const void *b)
{

    FOUNDATIONAL_LIB_ASSERT_ARGUMENT_IF_ENABLED(a);
    FOUNDATIONAL_LIB_ASSERT_ARGUMENT_IF_ENABLED(b);
    return (*(unsigned int *)a - *(unsigned int *)b);
}

/**
 * Sort an array of unsigned integers for foundational library.
 *
 * This function uses a sorting algorithm to arrange the elements in the array
 * pointed to by @p uints in ascending order.
 *
 * @param uints Pointer to the array of unsigned integers.
 * @param size Size of the array.
 */
FOUNDATIONAL_LIB_NONNULL FOUNDATIONAL_LIB_FUNC void sort_uints(unsigned int *uints, size_t size)
{
    FOUNDATIONAL_LIB_ASSERT_ARGUMENT_IF_ENABLED(uints);

    qsort(uints, size, sizeof(unsigned int), FOUNDATIONAL_LIB_cmp_uints);
}

/**
 * Get a sorted copy of an array of unsigned integers for foundational library.
 *
 * This function creates a sorted copy of the array pointed to by @p uints and
 * returns a pointer to the sorted array. The original array remains unchanged.
 *
 * @param uints Pointer to the array of unsigned integers.
 * @param size Size of the array.
 * @return A pointer to the sorted array of unsigned integers.
 *         @note The caller is responsible for freeing the memory allocated for
 *         the sorted array using the free() function.
 */
FOUNDATIONAL_LIB_WARN_UNUSED_RESULT FOUNDATIONAL_LIB_NONNULL FOUNDATIONAL_LIB_FUNC unsigned int *sorted_uints(unsigned int *uints, size_t size)
{
    FOUNDATIONAL_LIB_ASSERT_ARGUMENT_IF_ENABLED(uints);

    unsigned int *dup_uints = (unsigned int *)arraydup(uints, size, sizeof(unsigned int));
    if (FOUNDATIONAL_LIB_UNLIKELY(dup_uints == NULL))
    {
        return NULL;
    }
    qsort(uints, size, sizeof(unsigned int), FOUNDATIONAL_LIB_cmp_uints);
    return dup_uints;
}

/**
 * Compare two pointers to unsigned integers for foundational library.
 *
 * This function is designed for use with sorting algorithms that require a
 * comparison function, such as qsort. It compares two pointers to unsigned
 * integers pointed to by @p a and @p b.
 *
 * @param a Pointer to the first pointer to unsigned integer.
 * @param b Pointer to the second pointer to unsigned integer.
 * @return An integer less than, equal to, or greater than zero if the first
 *         pointer to unsigned integer is found to be less than, equal to, or
 *         greater than the second pointer to unsigned integer, respectively.
 */
FOUNDATIONAL_LIB_WARN_UNUSED_RESULT FOUNDATIONAL_LIB_NONNULL FOUNDATIONAL_LIB_NOTHROW FOUNDATIONAL_LIB_PURE FOUNDATIONAL_LIB_FUNC int FOUNDATIONAL_LIB_cmp_uint_ptrs(const void *a, const void *b)
{
    FOUNDATIONAL_LIB_ASSERT_ARGUMENT_IF_ENABLED(a);
    FOUNDATIONAL_LIB_ASSERT_ARGUMENT_IF_ENABLED(b);
    return (*(unsigned int **)a - *(unsigned int **)b);
}

/**
 * Sort an array of pointers to unsigned integers for foundational library.
 *
 * This function uses a sorting algorithm to arrange the pointers to unsigned
 * integers pointed to by @p uint_ptrs based on their values in ascending order.
 *
 * @param uint_ptrs Pointer to the array of pointers to unsigned integers.
 * @param size Size of the array of pointers.
 */
FOUNDATIONAL_LIB_NONNULL FOUNDATIONAL_LIB_FUNC void sort_uint_ptrs(unsigned int **uint_ptrs, size_t size)
{
    FOUNDATIONAL_LIB_ASSERT_ARGUMENT_IF_ENABLED(uint_ptrs);

    qsort(uint_ptrs, size, sizeof(unsigned int *), FOUNDATIONAL_LIB_cmp_uint_ptrs);
}

/**
 * Get a sorted copy of an array of pointers to unsigned integers for
 * foundational library.
 *
 * This function creates a sorted copy of the array of pointers to unsigned
 * integers pointed to by @p uint_ptrs and returns a pointer to the sorted array
 * of pointers. The original array of pointers remains unchanged.
 *
 * @param uint_ptrs Pointer to the array of pointers to unsigned integers.
 * @param size Size of the array of pointers.
 * @return A pointer to the sorted array of pointers to unsigned integers.
 *         @note The caller is responsible for freeing the memory allocated for
 *         the sorted array of pointers using free().
 */
FOUNDATIONAL_LIB_WARN_UNUSED_RESULT FOUNDATIONAL_LIB_NONNULL FOUNDATIONAL_LIB_FUNC unsigned int **sorted_uint_ptrs(unsigned int **uint_ptrs, size_t size)
{

    FOUNDATIONAL_LIB_ASSERT_ARGUMENT_IF_ENABLED(uint_ptrs);

    unsigned int **dup_uint_ptrs = (unsigned int **)arraydup(uint_ptrs, size, sizeof(unsigned int *));
    if (FOUNDATIONAL_LIB_UNLIKELY(dup_uint_ptrs == NULL))
    {
        return NULL;
    }
    qsort(uint_ptrs, size, sizeof(unsigned int *), FOUNDATIONAL_LIB_cmp_uint_ptrs);
    return dup_uint_ptrs;
}

/**
 * Compare two integers for foundational library.
 *
 * This function is designed for use with sorting algorithms that require a
 * comparison function, such as qsort. It compares two integers pointed to by
 * @p a and @p b.
 *
 * @param a Pointer to the first integer.
 * @param b Pointer to the second integer.
 * @return An integer less than, equal to, or greater than zero if the first
 *         integer is found to be less than, equal to, or greater than the
 *         second integer, respectively.
 */
FOUNDATIONAL_LIB_WARN_UNUSED_RESULT FOUNDATIONAL_LIB_NONNULL FOUNDATIONAL_LIB_NOTHROW FOUNDATIONAL_LIB_PURE FOUNDATIONAL_LIB_FUNC int FOUNDATIONAL_LIB_cmp_ints(const void *a, const void *b)
{

    FOUNDATIONAL_LIB_ASSERT_ARGUMENT_IF_ENABLED(a);
    FOUNDATIONAL_LIB_ASSERT_ARGUMENT_IF_ENABLED(b);

    return (*(int *)a - *(int *)b);
}

/**
 * Sort an array of integers for foundational library.
 *
 * This function uses a sorting algorithm to arrange the elements in the array
 * pointed to by @p ints in ascending order.
 *
 * @param ints Pointer to the array of integers.
 * @param size Size of the array.
 */
FOUNDATIONAL_LIB_NONNULL FOUNDATIONAL_LIB_FUNC void sort_ints(int *ints, size_t size)
{

    FOUNDATIONAL_LIB_ASSERT_ARGUMENT_IF_ENABLED(ints);
    qsort(ints, size, sizeof(int), FOUNDATIONAL_LIB_cmp_ints);
}

/**
 * Get a sorted copy of an array of integers for foundational library.
 *
 * This function creates a sorted copy of the array pointed to by @p ints and
 * returns a pointer to the sorted array. The original array remains unchanged.
 *
 * @param ints Pointer to the array of integers.
 * @param size Size of the array.
 * @return A pointer to the sorted array of integers. Note: The caller is
 *         responsible for freeing the memory allocated for the sorted array
 *         using the appropriate deallocation function, such as free().
 */
FOUNDATIONAL_LIB_WARN_UNUSED_RESULT FOUNDATIONAL_LIB_NONNULL FOUNDATIONAL_LIB_FUNC int *sorted_ints(int *ints, size_t size)
{

    FOUNDATIONAL_LIB_ASSERT_ARGUMENT_IF_ENABLED(ints);

    int *dup_ints = (int *)arraydup(ints, size, sizeof(int));
    if (FOUNDATIONAL_LIB_UNLIKELY(dup_ints == NULL))
    {
        return NULL;
    }

    qsort(ints, size, sizeof(int), FOUNDATIONAL_LIB_cmp_ints);
    return dup_ints;
}

/**
 * Compare two pointers to integers for foundational library.
 *
 * This function is designed for use with sorting algorithms that require a
 * comparison function, such as qsort. It compares two pointers to integers
 * pointed to by @p a and @p b.
 *
 * @param a Pointer to the first pointer to integer.
 * @param b Pointer to the second pointer to integer.
 * @return An integer less than, equal to, or greater than zero if the first
 *         pointer to integer is found to be less than, equal to, or greater
 *         than the second pointer to integer, respectively.
 */
FOUNDATIONAL_LIB_WARN_UNUSED_RESULT FOUNDATIONAL_LIB_NONNULL FOUNDATIONAL_LIB_NOTHROW FOUNDATIONAL_LIB_PURE FOUNDATIONAL_LIB_FUNC int FOUNDATIONAL_LIB_cmp_int_ptrs(const void *a, const void *b)
{

    FOUNDATIONAL_LIB_ASSERT_ARGUMENT_IF_ENABLED(a);
    FOUNDATIONAL_LIB_ASSERT_ARGUMENT_IF_ENABLED(b);
    return (*(int **)a - *(int **)b);
}

/**
 * Sort an array of pointers to integers for foundational library.
 *
 * This function uses a sorting algorithm to arrange the pointers to integers
 * pointed to by @p int_ptrs based on their values in ascending order.
 *
 * @param int_ptrs Pointer to the array of pointers to integers.
 * @param size Size of the array of pointers.
 */
FOUNDATIONAL_LIB_NONNULL FOUNDATIONAL_LIB_FUNC void sort_int_ptrs(int **int_ptrs, size_t size)
{
    FOUNDATIONAL_LIB_ASSERT_ARGUMENT_IF_ENABLED(int_ptrs);
    qsort(int_ptrs, size, sizeof(int *), FOUNDATIONAL_LIB_cmp_int_ptrs);
}

/**
 * Get a sorted copy of an array of pointers to integers for foundational
 * library.
 *
 * This function creates a sorted copy of the array of pointers to integers
 * pointed to by @p int_ptrs and returns a pointer to the sorted array of
 * pointers. The original array of pointers remains unchanged.
 *
 * @param int_ptrs Pointer to the array of pointers to integers.
 * @param size Size of the array of pointers.
 * @return A pointer to the sorted array of pointers to integers.
 *         @note The caller is responsible for freeing the memory allocated for
 *         the sorted array of pointers using free().
 */
FOUNDATIONAL_LIB_WARN_UNUSED_RESULT FOUNDATIONAL_LIB_NONNULL FOUNDATIONAL_LIB_FUNC int **sorted_int_ptrs(int **int_ptrs, size_t size)
{
    FOUNDATIONAL_LIB_ASSERT_ARGUMENT_IF_ENABLED(int_ptrs);
    int **dup_int_ptrs = (int **)arraydup(int_ptrs, size, sizeof(int *));
    if (FOUNDATIONAL_LIB_UNLIKELY(dup_int_ptrs == NULL))
    {
        return NULL;
    }
    qsort(int_ptrs, size, sizeof(int *), FOUNDATIONAL_LIB_cmp_int_ptrs);
    return dup_int_ptrs;
}

/**
 * @brief Compare function for sorting unsigned chars.
 *
 * This function is used as a comparison function for qsort to sort an array of
 * unsigned chars in ascending order.
 *
 * @param a Pointer to the first element to be compared.
 * @param b Pointer to the second element to be compared.
 * @return Integer less than, equal to, or greater than zero if the first
 * element is found to be less than, equal to, or greater than the second
 * element.
 */
FOUNDATIONAL_LIB_WARN_UNUSED_RESULT FOUNDATIONAL_LIB_NONNULL FOUNDATIONAL_LIB_NOTHROW FOUNDATIONAL_LIB_PURE FOUNDATIONAL_LIB_FUNC int FOUNDATIONAL_LIB_cmp_uchars(const void *a, const void *b)
{
    FOUNDATIONAL_LIB_ASSERT_ARGUMENT_IF_ENABLED(a);
    FOUNDATIONAL_LIB_ASSERT_ARGUMENT_IF_ENABLED(b);
    return (*(unsigned char *)a - *(unsigned char *)b);
}

/**
 * @brief Sorts an array of unsigned chars in ascending order.
 *
 * This function uses the qsort algorithm to sort the given array of unsigned
 * chars.
 *
 * @param uchars Pointer to the array of unsigned chars to be sorted.
 * @param size   Number of elements in the array.
 */
FOUNDATIONAL_LIB_NONNULL FOUNDATIONAL_LIB_FUNC void sort_uchars(unsigned char *uchars, size_t size)
{

    FOUNDATIONAL_LIB_ASSERT_ARGUMENT_IF_ENABLED(uchars);
    qsort(uchars, size, sizeof(unsigned char), FOUNDATIONAL_LIB_cmp_uchars);
}

/**
 * @brief Creates a new array containing sorted unsigned chars.
 *
 * This function takes an array of unsigned chars, creates a new array, and
 * returns it after sorting the original array in ascending order. The caller is
 * responsible for freeing the memory allocated for the returned array using
 * free().
 *
 * @param uchars Pointer to the array of unsigned chars to be sorted.
 * @param size   Number of elements in the array.
 * @return       Pointer to the newly created and sorted array of unsigned
 * chars. The caller is responsible for freeing the memory using free().
 */
FOUNDATIONAL_LIB_WARN_UNUSED_RESULT FOUNDATIONAL_LIB_NONNULL FOUNDATIONAL_LIB_FUNC unsigned char *sorted_uchars(unsigned char *uchars, size_t size)
{
    FOUNDATIONAL_LIB_ASSERT_ARGUMENT_IF_ENABLED(uchars);

    unsigned char *dup_uchars = (unsigned char *)arraydup(uchars, size, sizeof(unsigned char));
    if (FOUNDATIONAL_LIB_UNLIKELY(dup_uchars == NULL))
    {
        return NULL;
    }
    qsort(uchars, size, sizeof(unsigned char), FOUNDATIONAL_LIB_cmp_uchars);
    return dup_uchars;
}

/**
 * @brief Compare function for sorting pointers to unsigned chars.
 *
 * This function is used as a comparison function for qsort to sort an array of
 * pointers to unsigned chars in ascending order.
 *
 * @param a Pointer to the first element (pointer to unsigned char) to be
 * compared.
 * @param b Pointer to the second element (pointer to unsigned char) to be
 * compared.
 * @return Integer less than, equal to, or greater than zero if the first
 * element is found to be less than, equal to, or greater than the second
 * element.
 */
FOUNDATIONAL_LIB_WARN_UNUSED_RESULT FOUNDATIONAL_LIB_NONNULL FOUNDATIONAL_LIB_NOTHROW FOUNDATIONAL_LIB_PURE FOUNDATIONAL_LIB_FUNC int FOUNDATIONAL_LIB_cmp_uchar_ptrs(const void *a, const void *b)
{
    FOUNDATIONAL_LIB_ASSERT_ARGUMENT_IF_ENABLED(a);
    FOUNDATIONAL_LIB_ASSERT_ARGUMENT_IF_ENABLED(b);
    return (*(unsigned char **)a - *(unsigned char **)b);
}
/**
 * @brief Sorts an array of pointers to unsigned chars in ascending order.
 *
 * This function uses the qsort algorithm to sort the given array of pointers to
 * unsigned chars.
 *
 * @param uchar_ptrs Pointer to the array of pointers to unsigned chars to be
 * sorted.
 * @param size       Number of elements in the array.
 */
FOUNDATIONAL_LIB_NONNULL FOUNDATIONAL_LIB_FUNC void sort_uchar_ptrs(unsigned char **uchar_ptrs, size_t size)
{

    FOUNDATIONAL_LIB_ASSERT_ARGUMENT_IF_ENABLED(uchar_ptrs);
    qsort(uchar_ptrs, size, sizeof(unsigned char *), FOUNDATIONAL_LIB_cmp_uchar_ptrs);
}

/**
 * @brief Creates a new array containing sorted pointers to unsigned chars.
 *
 * This function takes an array of pointers to unsigned chars, creates a new
 * array, and returns it after sorting the original array in ascending order.
 * The caller is responsible for freeing the memory allocated for the returned
 * array using free().
 *
 * @param uchar_ptrs Pointer to the array of pointers to unsigned chars to be
 * sorted.
 * @param size       Number of elements in the array.
 * @return           Pointer to the newly created and sorted array of pointers
 * to unsigned chars. The caller is responsible for freeing the memory using
 * free().
 */
FOUNDATIONAL_LIB_WARN_UNUSED_RESULT FOUNDATIONAL_LIB_NONNULL FOUNDATIONAL_LIB_FUNC unsigned char **sorted_uchar_ptrs(unsigned char **uchar_ptrs, size_t size)
{
    FOUNDATIONAL_LIB_ASSERT_ARGUMENT_IF_ENABLED(uchar_ptrs);
    unsigned char **dup_uchar_ptrs = (unsigned char **)arraydup(uchar_ptrs, size, sizeof(unsigned char *));
    if (FOUNDATIONAL_LIB_UNLIKELY(dup_uchar_ptrs == NULL))
    {
        return NULL;
    }
    qsort(uchar_ptrs, size, sizeof(unsigned char *), FOUNDATIONAL_LIB_cmp_uchar_ptrs);
    return dup_uchar_ptrs;
}

/**
 * @brief Compare function for sorting chars.
 *
 * This function is used as a comparison function for qsort to sort an array of
 * chars in ascending order.
 *
 * @param a Pointer to the first element (char) to be compared.
 * @param b Pointer to the second element (char) to be compared.
 * @return Integer less than, equal to, or greater than zero if the first
 * element is found to be less than, equal to, or greater than the second
 * element.
 */
FOUNDATIONAL_LIB_WARN_UNUSED_RESULT FOUNDATIONAL_LIB_NONNULL FOUNDATIONAL_LIB_NOTHROW FOUNDATIONAL_LIB_PURE FOUNDATIONAL_LIB_FUNC int FOUNDATIONAL_LIB_cmp_chars(const void *a, const void *b)
{
    FOUNDATIONAL_LIB_ASSERT_ARGUMENT_IF_ENABLED(a);
    FOUNDATIONAL_LIB_ASSERT_ARGUMENT_IF_ENABLED(b);
    return (*(char *)a - *(char *)b);
}

/**
 * @brief Sorts an array of chars in ascending order.
 *
 * This function uses the qsort algorithm to sort the given array of chars.
 *
 * @param chars Pointer to the array of chars to be sorted.
 * @param size  Number of elements in the array.
 */
FOUNDATIONAL_LIB_NONNULL FOUNDATIONAL_LIB_FUNC void sort_chars(char *chars, size_t size)
{
    FOUNDATIONAL_LIB_ASSERT_ARGUMENT_IF_ENABLED(chars);
    qsort(chars, size, sizeof(char), FOUNDATIONAL_LIB_cmp_chars);
}

/**
 * @brief Creates a new array containing sorted chars.
 *
 * This function takes an array of chars, creates a new array, and returns
 * it after sorting the original array in ascending order. The caller is
 * responsible for freeing the memory allocated for the returned array using
 * free().
 *
 * @param chars Pointer to the array of chars to be sorted.
 * @param size  Number of elements in the array.
 * @return      Pointer to the newly created and sorted array of chars. The
 * caller is responsible for freeing the memory using free().
 */
FOUNDATIONAL_LIB_WARN_UNUSED_RESULT FOUNDATIONAL_LIB_NONNULL FOUNDATIONAL_LIB_FUNC char *sorted_chars(char *chars, size_t size)
{
    FOUNDATIONAL_LIB_ASSERT_ARGUMENT_IF_ENABLED(chars);
    char *dup_chars = (char *)arraydup(chars, size, sizeof(char));
    if (FOUNDATIONAL_LIB_UNLIKELY(dup_chars == NULL))
    {
        return NULL;
    }
    qsort(chars, size, sizeof(char), FOUNDATIONAL_LIB_cmp_chars);
    return dup_chars;
}

/**
 * @brief Compare function for sorting pointers to chars.
 *
 * This function is used as a comparison function for qsort to sort an array of
 * pointers to chars in ascending order.
 *
 * @param a Pointer to the first element (pointer to char) to be compared.
 * @param b Pointer to the second element (pointer to char) to be compared.
 * @return Integer less than, equal to, or greater than zero if the first
 * element is found to be less than, equal to, or greater than the second
 * element.
 */
FOUNDATIONAL_LIB_WARN_UNUSED_RESULT FOUNDATIONAL_LIB_NONNULL FOUNDATIONAL_LIB_NOTHROW FOUNDATIONAL_LIB_PURE FOUNDATIONAL_LIB_FUNC int FOUNDATIONAL_LIB_cmp_char_ptrs(const void *a, const void *b)
{
    FOUNDATIONAL_LIB_ASSERT_ARGUMENT_IF_ENABLED(a);
    FOUNDATIONAL_LIB_ASSERT_ARGUMENT_IF_ENABLED(b);

    return (*(char **)a - *(char **)b);
}
/**
 * @brief Sorts an array of pointers to chars in ascending order.
 *
 * This function uses the qsort algorithm to sort the given array of pointers to
 * chars.
 *
 * @param char_ptrs Pointer to the array of pointers to chars to be sorted.
 * @param size      Number of elements in the array.
 */
FOUNDATIONAL_LIB_NONNULL FOUNDATIONAL_LIB_FUNC void sort_char_ptrs(char **char_ptrs, size_t size)
{
    FOUNDATIONAL_LIB_ASSERT_ARGUMENT_IF_ENABLED(char_ptrs);

    qsort(char_ptrs, size, sizeof(char *), FOUNDATIONAL_LIB_cmp_char_ptrs);
}

/**
 * @brief Creates a new array containing sorted pointers to chars.
 *
 * This function takes an array of pointers to chars, creates a new array,
 * and returns it after sorting the original array in ascending order. The
 * caller is responsible for freeing the memory allocated for the returned array
 * using free().
 *
 * @param char_ptrs Pointer to the array of pointers to chars to be sorted.
 * @param size      Number of elements in the array.
 * @return          Pointer to the newly created and sorted array of pointers to
 *                  chars. The caller is responsible for freeing the memory
 * using free().
 */
FOUNDATIONAL_LIB_WARN_UNUSED_RESULT FOUNDATIONAL_LIB_NONNULL FOUNDATIONAL_LIB_FUNC char **sorted_char_ptrs(char **char_ptrs, size_t size)
{
    FOUNDATIONAL_LIB_ASSERT_ARGUMENT_IF_ENABLED(char_ptrs);
    char **dup_char_ptrs = (char **)arraydup(char_ptrs, size, sizeof(char *));

    if (FOUNDATIONAL_LIB_UNLIKELY(dup_char_ptrs == NULL))
    {
        return NULL;
    }

    qsort(char_ptrs, size, sizeof(char *), FOUNDATIONAL_LIB_cmp_char_ptrs);
    return dup_char_ptrs;
}

/**
 * @brief Compare function for sorting unsigned shorts.
 *
 * This function is used as a comparison function for qsort to sort an array of
 * unsigned shorts in ascending order.
 *
 * @param a Pointer to the first element (unsigned short) to be compared.
 * @param b Pointer to the second element (unsigned short) to be compared.
 * @return Integer less than, equal to, or greater than zero if the first
 * element is found to be less than, equal to, or greater than the second
 * element.
 */
FOUNDATIONAL_LIB_WARN_UNUSED_RESULT FOUNDATIONAL_LIB_NONNULL FOUNDATIONAL_LIB_NOTHROW FOUNDATIONAL_LIB_PURE FOUNDATIONAL_LIB_FUNC int FOUNDATIONAL_LIB_cmp_ushorts(const void *a, const void *b)
{

    FOUNDATIONAL_LIB_ASSERT_ARGUMENT_IF_ENABLED(a);
    FOUNDATIONAL_LIB_ASSERT_ARGUMENT_IF_ENABLED(b);
    return (*(unsigned short *)a - *(unsigned short *)b);
}

/**
 * @brief Sorts an array of unsigned shorts in ascending order.
 *
 * This function uses the qsort algorithm to sort the given array of unsigned
 * shorts.
 *
 * @param ushorts Pointer to the array of unsigned shorts to be sorted.
 * @param size    Number of elements in the array.
 */
FOUNDATIONAL_LIB_NONNULL FOUNDATIONAL_LIB_FUNC void sort_ushorts(unsigned short *ushorts, size_t size)
{

    FOUNDATIONAL_LIB_ASSERT_ARGUMENT_IF_ENABLED(ushorts);

    qsort(ushorts, size, sizeof(unsigned short), FOUNDATIONAL_LIB_cmp_ushorts);
}

/**
 * @brief Creates a new array containing sorted unsigned shorts.
 *
 * This function takes an array of unsigned shorts, creates a new array, and
 * returns it after sorting the original array in ascending order. The caller is
 * responsible for freeing the memory allocated for the returned array using
 * free().
 *
 * @param ushorts Pointer to the array of unsigned shorts to be sorted.
 * @param size    Number of elements in the array.
 * @return        Pointer to the newly created and sorted array of unsigned
 * shorts. The caller is responsible for freeing the memory using free().
 */
FOUNDATIONAL_LIB_WARN_UNUSED_RESULT FOUNDATIONAL_LIB_NONNULL FOUNDATIONAL_LIB_FUNC unsigned short *sorted_ushorts(unsigned short *ushorts, size_t size)
{
    FOUNDATIONAL_LIB_ASSERT_ARGUMENT_IF_ENABLED(ushorts);
    unsigned short *dup_ushorts = (unsigned short *)arraydup(ushorts, size, sizeof(unsigned short));

    if (FOUNDATIONAL_LIB_UNLIKELY(dup_ushorts == NULL))
    {
        return NULL;
    }

    qsort(ushorts, size, sizeof(unsigned short), FOUNDATIONAL_LIB_cmp_ushorts);
    return dup_ushorts;
}

/**
 * @brief Compare function for sorting pointers to unsigned shorts.
 *
 * This function is used as a comparison function for qsort to sort an array of
 * pointers to unsigned shorts in ascending order.
 *
 * @param a Pointer to the first element (pointer to unsigned short) to be
 * compared.
 * @param b Pointer to the second element (pointer to unsigned short) to be
 * compared.
 * @return Integer less than, equal to, or greater than zero if the first
 * element is found to be less than, equal to, or greater than the second
 * element.
 */
FOUNDATIONAL_LIB_WARN_UNUSED_RESULT FOUNDATIONAL_LIB_NONNULL FOUNDATIONAL_LIB_NOTHROW FOUNDATIONAL_LIB_PURE FOUNDATIONAL_LIB_FUNC int FOUNDATIONAL_LIB_cmp_ushort_ptrs(const void *a, const void *b)
{

    FOUNDATIONAL_LIB_ASSERT_ARGUMENT_IF_ENABLED(a);
    FOUNDATIONAL_LIB_ASSERT_ARGUMENT_IF_ENABLED(b);

    return (*(unsigned short **)a - *(unsigned short **)b);
}

/**
 * @brief Sorts an array of pointers to unsigned shorts in ascending order.
 *
 * This function uses the qsort algorithm to sort the given array of pointers to
 * unsigned shorts.
 *
 * @param ushort_ptrs Pointer to the array of pointers to unsigned shorts to be
 * sorted.
 * @param size        Number of elements in the array.
 */
FOUNDATIONAL_LIB_NONNULL FOUNDATIONAL_LIB_FUNC void sort_ushort_ptrs(unsigned short **ushort_ptrs, size_t size)
{

    FOUNDATIONAL_LIB_ASSERT_ARGUMENT_IF_ENABLED(ushort_ptrs);
    qsort(ushort_ptrs, size, sizeof(unsigned short *), FOUNDATIONAL_LIB_cmp_ushort_ptrs);
}

/**
 * @brief Creates a new array containing sorted pointers to unsigned shorts.
 *
 * This function takes an array of pointers to unsigned shorts, creates a new
 * array, and returns it after sorting the original array in ascending order.
 * The caller is responsible for freeing the memory allocated for the returned
 * array using free().
 *
 * @param ushort_ptrs Pointer to the array of pointers to unsigned shorts to be
 * sorted.
 * @param size        Number of elements in the array.
 * @return            Pointer to the newly created and sorted array of pointers
 * to unsigned shorts. The caller is responsible for freeing the memory using
 * free().
 */
FOUNDATIONAL_LIB_WARN_UNUSED_RESULT FOUNDATIONAL_LIB_NONNULL FOUNDATIONAL_LIB_FUNC unsigned short **sorted_ushort_ptrs(unsigned short **ushort_ptrs, size_t size)
{
    FOUNDATIONAL_LIB_ASSERT_ARGUMENT_IF_ENABLED(ushort_ptrs);

    unsigned short **dup_ushort_ptrs = (unsigned short **)arraydup(ushort_ptrs, size, sizeof(unsigned short *));
    if (FOUNDATIONAL_LIB_UNLIKELY(dup_ushort_ptrs == NULL))
    {
        return NULL;
    }

    qsort(ushort_ptrs, size, sizeof(unsigned short *), FOUNDATIONAL_LIB_cmp_ushort_ptrs);
    return dup_ushort_ptrs;
}

/**
 * @brief Compare function for sorting shorts.
 *
 * This function is used as a comparison function for qsort to sort an array of
 * shorts in ascending order.
 *
 * @param a Pointer to the first element (short) to be compared.
 * @param b Pointer to the second element (short) to be compared.
 * @return Integer less than, equal to, or greater than zero if the first
 * element is found to be less than, equal to, or greater than the second
 * element.
 */
FOUNDATIONAL_LIB_WARN_UNUSED_RESULT FOUNDATIONAL_LIB_NONNULL FOUNDATIONAL_LIB_NOTHROW FOUNDATIONAL_LIB_PURE FOUNDATIONAL_LIB_FUNC int FOUNDATIONAL_LIB_cmp_shorts(const void *a, const void *b)
{
    FOUNDATIONAL_LIB_ASSERT_ARGUMENT_IF_ENABLED(a);
    FOUNDATIONAL_LIB_ASSERT_ARGUMENT_IF_ENABLED(b);
    return (*(short *)a - *(short *)b);
}
/**
 * @brief Sorts an array of shorts in ascending order.
 *
 * This function uses the qsort algorithm to sort the given array of shorts.
 *
 * @param shorts Pointer to the array of shorts to be sorted.
 * @param size   Number of elements in the array.
 */
FOUNDATIONAL_LIB_NONNULL FOUNDATIONAL_LIB_FUNC void sort_shorts(short *shorts, size_t size)
{

    FOUNDATIONAL_LIB_ASSERT_ARGUMENT_IF_ENABLED(shorts);
    qsort(shorts, size, sizeof(short), FOUNDATIONAL_LIB_cmp_shorts);
}

/**
 * @brief Creates a new array containing sorted shorts.
 *
 * This function takes an array of shorts, creates a new array, and returns
 * it after sorting the original array in ascending order. The caller is
 * responsible for freeing the memory allocated for the returned array using
 * free().
 *
 * @param shorts Pointer to the array of shorts to be sorted.
 * @param size   Number of elements in the array.
 * @return       Pointer to the newly created and sorted array of shorts. The
 * caller is responsible for freeing the memory using free().
 */
FOUNDATIONAL_LIB_WARN_UNUSED_RESULT FOUNDATIONAL_LIB_NONNULL FOUNDATIONAL_LIB_FUNC short *sorted_shorts(short *shorts, size_t size)
{
    FOUNDATIONAL_LIB_ASSERT_ARGUMENT_IF_ENABLED(shorts);

    short *dup_shorts = (short *)arraydup(shorts, size, sizeof(short));

    if (FOUNDATIONAL_LIB_UNLIKELY(dup_shorts == NULL))
    {
        return NULL;
    }

    qsort(shorts, size, sizeof(short), FOUNDATIONAL_LIB_cmp_shorts);
    return dup_shorts;
}

/**
 * @brief Compare function for sorting pointers to shorts.
 *
 * This function is used as a comparison function for qsort to sort an array of
 * pointers to shorts in ascending order.
 *
 * @param a Pointer to the first element (pointer to short) to be compared.
 * @param b Pointer to the second element (pointer to short) to be compared.
 * @return Integer less than, equal to, or greater than zero if the first
 * element is found to be less than, equal to, or greater than the second
 * element.
 */
FOUNDATIONAL_LIB_WARN_UNUSED_RESULT FOUNDATIONAL_LIB_NONNULL FOUNDATIONAL_LIB_NOTHROW FOUNDATIONAL_LIB_PURE FOUNDATIONAL_LIB_FUNC int FOUNDATIONAL_LIB_cmp_short_ptrs(const void *a, const void *b)
{

    FOUNDATIONAL_LIB_ASSERT_ARGUMENT_IF_ENABLED(a);
    FOUNDATIONAL_LIB_ASSERT_ARGUMENT_IF_ENABLED(b);
    return (*(short **)a - *(short **)b);
}

/**
 * @brief Sorts an array of pointers to shorts in ascending order.
 *
 * This function uses the qsort algorithm to sort the given array of pointers to
 * shorts.
 *
 * @param short_ptrs Pointer to the array of pointers to shorts to be sorted.
 * @param size       Number of elements in the array.
 */
FOUNDATIONAL_LIB_NONNULL FOUNDATIONAL_LIB_FUNC void sort_short_ptrs(short **short_ptrs, size_t size)
{

    FOUNDATIONAL_LIB_ASSERT_ARGUMENT_IF_ENABLED(short_ptrs);
    qsort(short_ptrs, size, sizeof(short *), FOUNDATIONAL_LIB_cmp_short_ptrs);
}

/**
 * @brief Creates a new array containing sorted pointers to shorts.
 *
 * This function takes an array of pointers to shorts, creates a new array,
 * and returns it after sorting the original array in ascending order. The
 * caller is responsible for freeing the memory allocated for the returned array
 * using free().
 *
 * @param short_ptrs Pointer to the array of pointers to shorts to be sorted.
 * @param size       Number of elements in the array.
 * @return           Pointer to the newly created and sorted array of pointers
 * to shorts. The caller is responsible for freeing the memory using free().
 */
FOUNDATIONAL_LIB_WARN_UNUSED_RESULT FOUNDATIONAL_LIB_NONNULL FOUNDATIONAL_LIB_FUNC short **sorted_short_ptrs(short **short_ptrs, size_t size)
{
    FOUNDATIONAL_LIB_ASSERT_ARGUMENT_IF_ENABLED(short_ptrs);

    short **dup_short_ptrs = (short **)arraydup(short_ptrs, size, sizeof(short *));

    if (FOUNDATIONAL_LIB_UNLIKELY(dup_short_ptrs == NULL))
    {
        return NULL;
    }

    qsort(short_ptrs, size, sizeof(short *), FOUNDATIONAL_LIB_cmp_short_ptrs);
    return dup_short_ptrs;
}

/**
 * @brief Compare function for sorting unsigned longs.
 *
 * This function is used as a comparison function for qsort to sort an array of
 * unsigned longs in ascending order.
 *
 * @param a Pointer to the first element (unsigned long) to be compared.
 * @param b Pointer to the second element (unsigned long) to be compared.
 * @return Integer less than, equal to, or greater than zero if the first
 * element is found to be less than, equal to, or greater than the second
 * element.
 */
FOUNDATIONAL_LIB_WARN_UNUSED_RESULT FOUNDATIONAL_LIB_NONNULL FOUNDATIONAL_LIB_NOTHROW FOUNDATIONAL_LIB_PURE FOUNDATIONAL_LIB_FUNC int FOUNDATIONAL_LIB_cmp_ulongs(const void *a, const void *b)
{
    FOUNDATIONAL_LIB_ASSERT_ARGUMENT_IF_ENABLED(a);
    FOUNDATIONAL_LIB_ASSERT_ARGUMENT_IF_ENABLED(b);
    return (*(unsigned long *)a - *(unsigned long *)b);
}

/**
 * @brief Sorts an array of unsigned longs in ascending order.
 *
 * This function uses the qsort algorithm to sort the given array of unsigned
 * longs.
 *
 * @param ulongs Pointer to the array of unsigned longs to be sorted.
 * @param size   Number of elements in the array.
 */
FOUNDATIONAL_LIB_NONNULL FOUNDATIONAL_LIB_FUNC void sort_ulongs(unsigned long *ulongs, size_t size)
{
    FOUNDATIONAL_LIB_ASSERT_ARGUMENT_IF_ENABLED(ulongs);
    qsort(ulongs, size, sizeof(unsigned long), FOUNDATIONAL_LIB_cmp_ulongs);
}

/**
 * @brief Creates a new array containing sorted unsigned longs.
 *
 * This function takes an array of unsigned longs, creates a new array, and
 * returns it after sorting the original array in ascending order. The caller is
 * responsible for freeing the memory allocated for the returned array using
 * free().
 *
 * @param ulongs Pointer to the array of unsigned longs to be sorted.
 * @param size   Number of elements in the array.
 * @return       Pointer to the newly created and sorted array of unsigned
 * longs. The caller is responsible for freeing the memory using free().
 */
FOUNDATIONAL_LIB_WARN_UNUSED_RESULT FOUNDATIONAL_LIB_NONNULL FOUNDATIONAL_LIB_FUNC unsigned long *sorted_ulongs(unsigned long *ulongs, size_t size)
{
    FOUNDATIONAL_LIB_ASSERT_ARGUMENT_IF_ENABLED(ulongs);
    unsigned long *dup_ulongs = (unsigned long *)arraydup(ulongs, size, sizeof(unsigned long));

    if (FOUNDATIONAL_LIB_UNLIKELY(dup_ulongs == NULL))
    {
        return NULL;
    }

    qsort(ulongs, size, sizeof(unsigned long), FOUNDATIONAL_LIB_cmp_ulongs);
    return dup_ulongs;
}

/**
 * @brief Compare function for sorting pointers to unsigned longs.
 *
 * This function is used as a comparison function for qsort to sort an array of
 * pointers to unsigned longs in ascending order.
 *
 * @param a Pointer to the first element (pointer to unsigned long) to be
 * compared.
 * @param b Pointer to the second element (pointer to unsigned long) to be
 * compared.
 * @return Integer less than, equal to, or greater than zero if the first
 * element is found to be less than, equal to, or greater than the second
 * element.
 */
FOUNDATIONAL_LIB_WARN_UNUSED_RESULT FOUNDATIONAL_LIB_NONNULL FOUNDATIONAL_LIB_NOTHROW FOUNDATIONAL_LIB_PURE FOUNDATIONAL_LIB_FUNC int FOUNDATIONAL_LIB_cmp_ulong_ptrs(const void *a, const void *b)
{
    FOUNDATIONAL_LIB_ASSERT_ARGUMENT_IF_ENABLED(a);
    FOUNDATIONAL_LIB_ASSERT_ARGUMENT_IF_ENABLED(b);

    return (*(unsigned long **)a - *(unsigned long **)b);
}

/**
 * @brief Sorts an array of pointers to unsigned longs in ascending order.
 *
 * This function uses the qsort algorithm to sort the given array of pointers to
 * unsigned longs.
 *
 * @param ulong_ptrs Pointer to the array of pointers to unsigned longs to be
 * sorted.
 * @param size       Number of elements in the array.
 */
FOUNDATIONAL_LIB_NONNULL FOUNDATIONAL_LIB_FUNC void sort_ulong_ptrs(unsigned long **ulong_ptrs, size_t size)
{

    FOUNDATIONAL_LIB_ASSERT_ARGUMENT_IF_ENABLED(ulong_ptrs);
    qsort(ulong_ptrs, size, sizeof(unsigned long *), FOUNDATIONAL_LIB_cmp_ulong_ptrs);
}

/**
 * @brief Creates a new array containing sorted pointers to unsigned longs.
 *
 * This function takes an array of pointers to unsigned longs, creates a new
 * array, and returns it after sorting the original array in ascending order.
 * The caller is responsible for freeing the memory allocated for the returned
 * array using free().
 *
 * @param ulong_ptrs Pointer to the array of pointers to unsigned longs to be
 * sorted.
 * @param size       Number of elements in the array.
 * @return           Pointer to the newly created and sorted array of pointers
 * to unsigned longs. The caller is responsible for freeing the memory using
 * free().
 */
FOUNDATIONAL_LIB_WARN_UNUSED_RESULT FOUNDATIONAL_LIB_NONNULL FOUNDATIONAL_LIB_FUNC unsigned long **sorted_ulong_ptrs(unsigned long **ulong_ptrs, size_t size)
{
    FOUNDATIONAL_LIB_ASSERT_ARGUMENT_IF_ENABLED(ulong_ptrs);

    unsigned long **dup_ulong_ptrs = (unsigned long **)arraydup(ulong_ptrs, size, sizeof(unsigned long *));
    if (FOUNDATIONAL_LIB_UNLIKELY(dup_ulong_ptrs == NULL))
    {
        return NULL;
    }

    qsort(ulong_ptrs, size, sizeof(unsigned long *), FOUNDATIONAL_LIB_cmp_ulong_ptrs);
    return dup_ulong_ptrs;
}

/**
 * @brief Compare function for sorting pointers to unsigned longs.
 *
 * This function is used as a comparison function for qsort to sort an array of
 * pointers to unsigned longs in ascending order.
 *
 * @param a Pointer to the first element (pointer to unsigned long) to be
 * compared.
 * @param b Pointer to the second element (pointer to unsigned long) to be
 * compared.
 * @return Integer less than, equal to, or greater than zero if the first
 * element is found to be less than, equal to, or greater than the second
 * element.
 */
FOUNDATIONAL_LIB_WARN_UNUSED_RESULT FOUNDATIONAL_LIB_NONNULL FOUNDATIONAL_LIB_NOTHROW FOUNDATIONAL_LIB_PURE FOUNDATIONAL_LIB_FUNC int FOUNDATIONAL_LIB_cmp_longs(const void *a, const void *b)
{

    FOUNDATIONAL_LIB_ASSERT_ARGUMENT_IF_ENABLED(a);
    FOUNDATIONAL_LIB_ASSERT_ARGUMENT_IF_ENABLED(b);
    return (*(long *)a - *(long *)b);
}

/**
 * @brief Sorts an array of pointers to unsigned longs in ascending order.
 *
 * This function uses the qsort algorithm to sort the given array of pointers to
 * unsigned longs.
 *
 * @param ulong_ptrs Pointer to the array of pointers to unsigned longs to be
 * sorted.
 * @param size       Number of elements in the array.
 */
FOUNDATIONAL_LIB_NONNULL FOUNDATIONAL_LIB_FUNC void sort_longs(long *longs, size_t size)
{

    FOUNDATIONAL_LIB_ASSERT_ARGUMENT_IF_ENABLED(longs);

    qsort(longs, size, sizeof(long), FOUNDATIONAL_LIB_cmp_longs);
}

/**
 * @brief Creates a new array containing sorted pointers to unsigned longs.
 *
 * This function takes an array of pointers to unsigned longs, creates a new
 * array, and returns it after sorting the original array in ascending order.
 * The caller is responsible for freeing the memory allocated for the returned
 * array using free().
 *
 * @param ulong_ptrs Pointer to the array of pointers to unsigned longs to be
 * sorted.
 * @param size       Number of elements in the array.
 * @return           Pointer to the newly created and sorted array of pointers
 * to unsigned longs. The caller is responsible for freeing the memory using
 * free().
 */
FOUNDATIONAL_LIB_WARN_UNUSED_RESULT FOUNDATIONAL_LIB_NONNULL FOUNDATIONAL_LIB_FUNC long *sorted_longs(long *longs, size_t size)
{

    FOUNDATIONAL_LIB_ASSERT_ARGUMENT_IF_ENABLED(longs);

    long *dup_longs = (long *)arraydup(longs, size, sizeof(long));
    if (FOUNDATIONAL_LIB_UNLIKELY(dup_longs == NULL))
    {
        return NULL;
    }

    qsort(longs, size, sizeof(long), FOUNDATIONAL_LIB_cmp_longs);
    return dup_longs;
}

/**
 * @brief Compare function for sorting pointers to longs.
 *
 * This function is used as a comparison function for qsort to sort an array of
 * pointers to longs in ascending order.
 *
 * @param a Pointer to the first element (pointer to long) to be compared.
 * @param b Pointer to the second element (pointer to long) to be compared.
 * @return Integer less than, equal to, or greater than zero if the first
 * element is found to be less than, equal to, or greater than the second
 * element.
 */
FOUNDATIONAL_LIB_WARN_UNUSED_RESULT FOUNDATIONAL_LIB_NONNULL FOUNDATIONAL_LIB_NOTHROW FOUNDATIONAL_LIB_PURE FOUNDATIONAL_LIB_FUNC int FOUNDATIONAL_LIB_cmp_long_ptrs(const void *a, const void *b)
{

    FOUNDATIONAL_LIB_ASSERT_ARGUMENT_IF_ENABLED(a);
    FOUNDATIONAL_LIB_ASSERT_ARGUMENT_IF_ENABLED(b);
    return (*(long **)a - *(long **)b);
}
/**
 * @brief Sorts an array of pointers to longs in ascending order.
 *
 * This function uses the qsort algorithm to sort the given array of pointers to
 * longs.
 *
 * @param long_ptrs Pointer to the array of pointers to longs to be sorted.
 * @param size      Number of elements in the array.
 */
FOUNDATIONAL_LIB_NONNULL FOUNDATIONAL_LIB_FUNC void sort_long_ptrs(long **long_ptrs, size_t size)
{
    FOUNDATIONAL_LIB_ASSERT_ARGUMENT_IF_ENABLED(long_ptrs);
    qsort(long_ptrs, size, sizeof(long *), FOUNDATIONAL_LIB_cmp_long_ptrs);
}
/**
 * @brief Creates a new array containing sorted pointers to longs.
 *
 * This function takes an array of pointers to longs, creates a new array,
 * and returns it after sorting the original array in ascending order. The
 * caller is responsible for freeing the memory allocated for the returned array
 * using free().
 *
 * @param long_ptrs Pointer to the array of pointers to longs to be sorted.
 * @param size      Number of elements in the array.
 * @return          Pointer to the newly created and sorted array of pointers to
 *                  longs. The caller is responsible for freeing the memory
 *                  using free().
 */
FOUNDATIONAL_LIB_WARN_UNUSED_RESULT FOUNDATIONAL_LIB_NONNULL FOUNDATIONAL_LIB_FUNC long **sorted_long_ptrs(long **long_ptrs, size_t size)
{
    FOUNDATIONAL_LIB_ASSERT_ARGUMENT_IF_ENABLED(long_ptrs);
    long **dup_long_ptrs = (long **)arraydup(long_ptrs, size, sizeof(long *));
    if (FOUNDATIONAL_LIB_UNLIKELY(dup_long_ptrs == NULL))
    {
        return NULL;
    }

    qsort(long_ptrs, size, sizeof(long *), FOUNDATIONAL_LIB_cmp_long_ptrs);
    return dup_long_ptrs;
}

/**
 * @brief Compare function for sorting unsigned long longs.
 *
 * This function is used as a comparison function for qsort to sort an array of
 * unsigned long longs in ascending order.
 *
 * @param a Pointer to the first element (unsigned long long) to be compared.
 * @param b Pointer to the second element (unsigned long long) to be compared.
 * @return Integer less than, equal to, or greater than zero if the first
 * element is found to be less than, equal to, or greater than the second
 * element.
 */
FOUNDATIONAL_LIB_WARN_UNUSED_RESULT FOUNDATIONAL_LIB_NONNULL FOUNDATIONAL_LIB_NOTHROW FOUNDATIONAL_LIB_PURE FOUNDATIONAL_LIB_FUNC int FOUNDATIONAL_LIB_cmp_ulong_longs(const void *a, const void *b)
{
    FOUNDATIONAL_LIB_ASSERT_ARGUMENT_IF_ENABLED(a);
    FOUNDATIONAL_LIB_ASSERT_ARGUMENT_IF_ENABLED(b);
    return (*(unsigned long long *)a - *(unsigned long long *)b);
}
/**
 * @brief Sorts an array of unsigned long longs in ascending order.
 *
 * This function uses the qsort algorithm to sort the given array of unsigned
 * long longs.
 *
 * @param ulong_longs Pointer to the array of unsigned long longs to be sorted.
 * @param size        Number of elements in the array.
 */
FOUNDATIONAL_LIB_NONNULL FOUNDATIONAL_LIB_FUNC void sort_ulong_longs(unsigned long long *ulong_longs, size_t size)
{

    FOUNDATIONAL_LIB_ASSERT_ARGUMENT_IF_ENABLED(ulong_longs);

    qsort(ulong_longs, size, sizeof(unsigned long long), FOUNDATIONAL_LIB_cmp_ulong_longs);
}
/**
 * @brief Creates a new array containing sorted unsigned long longs.
 *
 * This function takes an array of unsigned long longs, creates a new array, and
 * returns it after sorting the original array in ascending order. The caller is
 * responsible for freeing the memory allocated for the returned array using
 * free().
 *
 * @param ulong_longs Pointer to the array of unsigned long longs to be sorted.
 * @param size        Number of elements in the array.
 * @return            Pointer to the newly created and sorted array of unsigned
 * long longs. The caller is responsible for freeing the memory using free().
 */
FOUNDATIONAL_LIB_WARN_UNUSED_RESULT FOUNDATIONAL_LIB_NONNULL FOUNDATIONAL_LIB_FUNC unsigned long long *sorted_ulong_longs(unsigned long long *ulong_longs, size_t size)
{
    FOUNDATIONAL_LIB_ASSERT_ARGUMENT_IF_ENABLED(ulong_longs);
    unsigned long long *dup_ulong_longs = (unsigned long long *)arraydup(ulong_longs, size, sizeof(unsigned long long));
    if (FOUNDATIONAL_LIB_UNLIKELY(dup_ulong_longs == NULL))
    {
        return NULL;
    }

    qsort(ulong_longs, size, sizeof(unsigned long long), FOUNDATIONAL_LIB_cmp_ulong_longs);
    return dup_ulong_longs;
}

/**
 * @brief Compare function for sorting pointers to unsigned long longs.
 *
 * This function is used as a comparison function for qsort to sort an array of
 * pointers to unsigned long longs in ascending order.
 *
 * @param a Pointer to the first element (pointer to unsigned long long) to be
 * compared.
 * @param b Pointer to the second element (pointer to unsigned long long) to be
 * compared.
 * @return Integer less than, equal to, or greater than zero if the first
 * element is found to be less than, equal to, or greater than the second
 * element.
 */
FOUNDATIONAL_LIB_WARN_UNUSED_RESULT FOUNDATIONAL_LIB_NONNULL FOUNDATIONAL_LIB_NOTHROW FOUNDATIONAL_LIB_PURE FOUNDATIONAL_LIB_FUNC int FOUNDATIONAL_LIB_cmp_ulong_long_ptrs(const void *a, const void *b)
{
    FOUNDATIONAL_LIB_ASSERT_ARGUMENT_IF_ENABLED(a);
    FOUNDATIONAL_LIB_ASSERT_ARGUMENT_IF_ENABLED(b);

    return (*(unsigned long long **)a - *(unsigned long long **)b);
}

/**
 * @brief Sorts an array of pointers to unsigned long longs in ascending order.
 *
 * This function uses the qsort algorithm to sort the given array of pointers to
 * unsigned long longs.
 *
 * @param ulong_long_ptrs Pointer to the array of pointers to unsigned long
 * longs to be sorted.
 * @param size            Number of elements in the array.
 */
FOUNDATIONAL_LIB_NONNULL FOUNDATIONAL_LIB_FUNC void sort_ulong_long_ptrs(unsigned long long **ulong_long_ptrs, size_t size)
{
    FOUNDATIONAL_LIB_ASSERT_ARGUMENT_IF_ENABLED(ulong_long_ptrs);
    qsort(ulong_long_ptrs, size, sizeof(unsigned long long *), FOUNDATIONAL_LIB_cmp_ulong_long_ptrs);
}
/**
 * @brief Creates a new array containing sorted pointers to unsigned long longs.
 *
 * This function takes an array of pointers to unsigned long longs, creates a
 * new array, and returns it after sorting the original array in ascending
 * order. The caller is responsible for freeing the memory allocated for the
 * returned array using free().
 *
 * @param ulong_long_ptrs Pointer to the array of pointers to unsigned long
 * longs to be sorted.
 * @param size            Number of elements in the array.
 * @return                Pointer to the newly created and sorted array of
 * pointers to unsigned long longs. The caller is responsible for freeing the
 * memory using free().
 */
FOUNDATIONAL_LIB_WARN_UNUSED_RESULT FOUNDATIONAL_LIB_NONNULL FOUNDATIONAL_LIB_FUNC unsigned long long **sorted_ulong_long_ptrs(unsigned long long **ulong_long_ptrs, size_t size)
{
    FOUNDATIONAL_LIB_ASSERT_ARGUMENT_IF_ENABLED(ulong_long_ptrs);

    unsigned long long **dup_ulong_long_ptrs = (unsigned long long **)arraydup(ulong_long_ptrs, size, sizeof(unsigned long long *));
    if (FOUNDATIONAL_LIB_UNLIKELY(dup_ulong_long_ptrs == NULL))
    {
        return NULL;
    }

    qsort(ulong_long_ptrs, size, sizeof(unsigned long long *), FOUNDATIONAL_LIB_cmp_ulong_long_ptrs);
    return dup_ulong_long_ptrs;
}

/**
 * @brief Compare function for sorting long longs.
 *
 * This function is used as a comparison function for qsort to sort an array of
 * long longs in ascending order.
 *
 * @param a Pointer to the first element (long long) to be compared.
 * @param b Pointer to the second element (long long) to be compared.
 * @return Integer less than, equal to, or greater than zero if the first
 * element is found to be less than, equal to, or greater than the second
 * element.
 */
FOUNDATIONAL_LIB_WARN_UNUSED_RESULT FOUNDATIONAL_LIB_NONNULL FOUNDATIONAL_LIB_NOTHROW FOUNDATIONAL_LIB_PURE FOUNDATIONAL_LIB_FUNC int FOUNDATIONAL_LIB_cmp_long_longs(const void *a, const void *b)
{
    FOUNDATIONAL_LIB_ASSERT_ARGUMENT_IF_ENABLED(a);
    FOUNDATIONAL_LIB_ASSERT_ARGUMENT_IF_ENABLED(b);
    return (*(long long *)a - *(long long *)b);
}
/**
 * @brief Sorts an array of long longs in ascending order.
 *
 * This function uses the qsort algorithm to sort the given array of long longs.
 *
 * @param long_longs Pointer to the array of long longs to be sorted.
 * @param size       Number of elements in the array.
 */
FOUNDATIONAL_LIB_NONNULL FOUNDATIONAL_LIB_FUNC void sort_long_longs(long long *long_longs, size_t size)
{
    FOUNDATIONAL_LIB_ASSERT_ARGUMENT_IF_ENABLED(long_longs);
    qsort(long_longs, size, sizeof(long long), FOUNDATIONAL_LIB_cmp_long_longs);
}
/**
 * @brief Creates a new array containing sorted long longs.
 *
 * This function takes an array of long longs, creates a new array, and returns
 * it after sorting the original array in ascending order. The caller is
 * responsible for freeing the memory allocated for the returned array using
 * free().
 *
 * @param long_longs Pointer to the array of long longs to be sorted.
 * @param size       Number of elements in the array.
 * @return           Pointer to the newly created and sorted array of long
 * longs. The caller is responsible for freeing the memory using free().
 */
FOUNDATIONAL_LIB_WARN_UNUSED_RESULT FOUNDATIONAL_LIB_NONNULL FOUNDATIONAL_LIB_FUNC long long *sorted_long_longs(long long *long_longs, size_t size)
{
    FOUNDATIONAL_LIB_ASSERT_ARGUMENT_IF_ENABLED(long_longs);
    long long *dup_long_longs = (long long *)arraydup(long_longs, size, sizeof(long long));

    if (FOUNDATIONAL_LIB_UNLIKELY(dup_long_longs == NULL))
    {
        return NULL;
    }

    qsort(long_longs, size, sizeof(long long), FOUNDATIONAL_LIB_cmp_long_longs);
    return dup_long_longs;
}

/**
 * @brief Compare function for sorting pointers to long longs.
 *
 * This function is used as a comparison function for qsort to sort an array of
 * pointers to long longs in ascending order.
 *
 * @param a Pointer to the first element (pointer to long long) to be compared.
 * @param b Pointer to the second element (pointer to long long) to be compared.
 * @return Integer less than, equal to, or greater than zero if the first
 * element is found to be less than, equal to, or greater than the second
 * element.
 */
FOUNDATIONAL_LIB_WARN_UNUSED_RESULT FOUNDATIONAL_LIB_NONNULL FOUNDATIONAL_LIB_NOTHROW FOUNDATIONAL_LIB_PURE FOUNDATIONAL_LIB_FUNC int FOUNDATIONAL_LIB_cmp_long_long_ptrs(const void *a, const void *b)
{
    FOUNDATIONAL_LIB_ASSERT_ARGUMENT_IF_ENABLED(a);
    FOUNDATIONAL_LIB_ASSERT_ARGUMENT_IF_ENABLED(b);
    return (*(long long **)a - *(long long **)b);
}

/**
 * @brief Sorts an array of pointers to long longs in ascending order.
 *
 * This function uses the qsort algorithm to sort the given array of pointers to
 * long longs.
 *
 * @param long_long_ptrs Pointer to the array of pointers to long longs to be
 * sorted.
 * @param size           Number of elements in the array.
 */
FOUNDATIONAL_LIB_NONNULL FOUNDATIONAL_LIB_FUNC void sort_long_long_ptrs(long long **long_long_ptrs, size_t size)
{
    FOUNDATIONAL_LIB_ASSERT_ARGUMENT_IF_ENABLED(long_long_ptrs);
    qsort(long_long_ptrs, size, sizeof(long long *), FOUNDATIONAL_LIB_cmp_long_long_ptrs);
}

/**
 * @brief Creates a new array containing sorted pointers to long longs.
 *
 * This function takes an array of pointers to long longs, creates a new array,
 * and returns it after sorting the original array in ascending order. The
 * caller is responsible for freeing the memory allocated for the returned array
 * using free().
 *
 * @param long_long_ptrs Pointer to the array of pointers to long longs to be
 * sorted.
 * @param size           Number of elements in the array.
 * @return               Pointer to the newly created and sorted array of
 * pointers to long longs. The caller is responsible for freeing the memory
 *                       using free().
 */
FOUNDATIONAL_LIB_WARN_UNUSED_RESULT FOUNDATIONAL_LIB_NONNULL FOUNDATIONAL_LIB_FUNC long long **sorted_long_long_ptrs(long long **long_long_ptrs, size_t size)
{
    FOUNDATIONAL_LIB_ASSERT_ARGUMENT_IF_ENABLED(long_long_ptrs);

    long long **dup_long_long_ptrs = (long long **)arraydup(long_long_ptrs, size, sizeof(long long *));
    if (FOUNDATIONAL_LIB_UNLIKELY(dup_long_long_ptrs == NULL))
    {
        return NULL;
    }

    qsort(long_long_ptrs, size, sizeof(long long *), FOUNDATIONAL_LIB_cmp_long_long_ptrs);
    return dup_long_long_ptrs;
}

/**
 * @brief Compare function for sorting floats.
 *
 * This function is used as a comparison function for qsort to sort an array of
 * floats in ascending order.
 *
 * @param a Pointer to the first element (float) to be compared.
 * @param b Pointer to the second element (float) to be compared.
 * @return Integer less than, equal to, or greater than zero if the first
 * element is found to be less than, equal to, or greater than the second
 * element.
 */
FOUNDATIONAL_LIB_WARN_UNUSED_RESULT FOUNDATIONAL_LIB_NONNULL FOUNDATIONAL_LIB_NOTHROW FOUNDATIONAL_LIB_PURE FOUNDATIONAL_LIB_FUNC int FOUNDATIONAL_LIB_cmp_floats(const void *a, const void *b)
{
    FOUNDATIONAL_LIB_ASSERT_ARGUMENT_IF_ENABLED(a);
    FOUNDATIONAL_LIB_ASSERT_ARGUMENT_IF_ENABLED(b);
    return (*(float *)a - *(float *)b);
}

/**
 * @brief Sorts an array of floats in ascending order.
 *
 * This function uses the qsort algorithm to sort the given array of floats.
 *
 * @param floats Pointer to the array of floats to be sorted.
 * @param size   Number of elements in the array.
 */
FOUNDATIONAL_LIB_NONNULL FOUNDATIONAL_LIB_FUNC void sort_floats(float *floats, size_t size)
{
    FOUNDATIONAL_LIB_ASSERT_ARGUMENT_IF_ENABLED(floats);
    qsort(floats, size, sizeof(float), FOUNDATIONAL_LIB_cmp_floats);
}

/**
 * @brief Creates a new array containing sorted floats.
 *
 * This function takes an array of floats, creates a new array, and returns
 * it after sorting the original array in ascending order. The caller is
 * responsible for freeing the memory allocated for the returned array using
 * free().
 *
 * @param floats Pointer to the array of floats to be sorted.
 * @param size   Number of elements in the array.
 * @return       Pointer to the newly created and sorted array of floats. The
 * caller is responsible for freeing the memory using free().
 */
FOUNDATIONAL_LIB_WARN_UNUSED_RESULT FOUNDATIONAL_LIB_NONNULL FOUNDATIONAL_LIB_FUNC float *sorted_floats(float *floats, size_t size)
{
    FOUNDATIONAL_LIB_ASSERT_ARGUMENT_IF_ENABLED(floats);

    float *dup_floats = (float *)arraydup(floats, size, sizeof(float));
    if (FOUNDATIONAL_LIB_UNLIKELY(dup_floats == NULL))
    {
        return NULL;
    }

    qsort(floats, size, sizeof(float), FOUNDATIONAL_LIB_cmp_floats);
    return dup_floats;
}

/**
 * @brief Compare function for sorting pointers to floats.
 *
 * This function is used as a comparison function for qsort to sort an array of
 * pointers to floats in ascending order.
 *
 * @param a Pointer to the first element (pointer to float) to be compared.
 * @param b Pointer to the second element (pointer to float) to be compared.
 * @return Integer less than, equal to, or greater than zero if the first
 * element is found to be less than, equal to, or greater than the second
 * element.
 */
FOUNDATIONAL_LIB_WARN_UNUSED_RESULT FOUNDATIONAL_LIB_NONNULL FOUNDATIONAL_LIB_NOTHROW FOUNDATIONAL_LIB_PURE FOUNDATIONAL_LIB_FUNC int FOUNDATIONAL_LIB_cmp_float_ptrs(const void *a, const void *b)
{
    FOUNDATIONAL_LIB_ASSERT_ARGUMENT_IF_ENABLED(a);
    FOUNDATIONAL_LIB_ASSERT_ARGUMENT_IF_ENABLED(b);
    return (*(float **)a - *(float **)b);
}

/**
 * @brief Sorts an array of pointers to floats in ascending order.
 *
 * This function uses the qsort algorithm to sort the given array of pointers to
 * floats.
 *
 * @param float_ptrs Pointer to the array of pointers to floats to be sorted.
 * @param size       Number of elements in the array.
 */
FOUNDATIONAL_LIB_NONNULL FOUNDATIONAL_LIB_FUNC void sort_float_ptrs(float **float_ptrs, size_t size)
{

    FOUNDATIONAL_LIB_ASSERT_ARGUMENT_IF_ENABLED(float_ptrs);
    qsort(float_ptrs, size, sizeof(float *), FOUNDATIONAL_LIB_cmp_float_ptrs);
}

/**
 * @brief Creates a new array containing sorted pointers to floats.
 *
 * This function takes an array of pointers to floats, creates a new array,
 * and returns it after sorting the original array in ascending order. The
 * caller is responsible for freeing the memory allocated for the returned array
 * using free().
 *
 * @param float_ptrs Pointer to the array of pointers to floats to be sorted.
 * @param size       Number of elements in the array.
 * @return           Pointer to the newly created and sorted array of pointers
 * to floats. The caller is responsible for freeing the memory using free().
 */
FOUNDATIONAL_LIB_WARN_UNUSED_RESULT FOUNDATIONAL_LIB_NONNULL FOUNDATIONAL_LIB_FUNC float **sorted_float_ptrs(float **float_ptrs, size_t size)
{
    FOUNDATIONAL_LIB_ASSERT_ARGUMENT_IF_ENABLED(float_ptrs);

    float **dup_float_ptrs = (float **)arraydup(float_ptrs, size, sizeof(float *));

    if (FOUNDATIONAL_LIB_UNLIKELY(dup_float_ptrs == NULL))
    {
        return NULL;
    }
    qsort(float_ptrs, size, sizeof(float *), FOUNDATIONAL_LIB_cmp_float_ptrs);
    return dup_float_ptrs;
}

/**
 * @brief Compare function for sorting doubles.
 *
 * This function is used as a comparison function for qsort to sort an array of
 * doubles in ascending order.
 *
 * @param a Pointer to the first element (double) to be compared.
 * @param b Pointer to the second element (double) to be compared.
 * @return Integer less than, equal to, or greater than zero if the first
 * element is found to be less than, equal to, or greater than the second
 * element.
 */
FOUNDATIONAL_LIB_WARN_UNUSED_RESULT FOUNDATIONAL_LIB_NONNULL FOUNDATIONAL_LIB_NOTHROW FOUNDATIONAL_LIB_PURE FOUNDATIONAL_LIB_FUNC int FOUNDATIONAL_LIB_cmp_doubles(const void *a, const void *b)
{
    FOUNDATIONAL_LIB_ASSERT_ARGUMENT_IF_ENABLED(a);
    FOUNDATIONAL_LIB_ASSERT_ARGUMENT_IF_ENABLED(b);

    return (*(double *)a - *(double *)b);
}

/**
 * @brief Sorts an array of doubles in ascending order.
 *
 * This function uses the qsort algorithm to sort the given array of doubles.
 *
 * @param doubles Pointer to the array of doubles to be sorted.
 * @param size    Number of elements in the array.
 */
FOUNDATIONAL_LIB_NONNULL FOUNDATIONAL_LIB_FUNC void sort_doubles(double *doubles, size_t size)
{
    FOUNDATIONAL_LIB_ASSERT_ARGUMENT_IF_ENABLED(doubles);
    qsort(doubles, size, sizeof(double), FOUNDATIONAL_LIB_cmp_doubles);
}

/**
 * @brief Creates a new array containing sorted doubles.
 *
 * This function takes an array of doubles, creates a new array, and returns
 * it after sorting the original array in ascending order. The caller is
 * responsible for freeing the memory allocated for the returned array using
 * free().
 *
 * @param doubles Pointer to the array of doubles to be sorted.
 * @param size    Number of elements in the array.
 * @return        Pointer to the newly created and sorted array of doubles. The
 * caller is responsible for freeing the memory using free().
 */
FOUNDATIONAL_LIB_WARN_UNUSED_RESULT FOUNDATIONAL_LIB_NONNULL FOUNDATIONAL_LIB_FUNC double *sorted_doubles(double *doubles, size_t size)
{
    FOUNDATIONAL_LIB_ASSERT_ARGUMENT_IF_ENABLED(doubles);
    double *dup_doubles = (double *)arraydup(doubles, size, sizeof(double));
    if (FOUNDATIONAL_LIB_UNLIKELY(dup_doubles == NULL))
    {
        return NULL;
    }
    qsort(doubles, size, sizeof(double), FOUNDATIONAL_LIB_cmp_doubles);
    return dup_doubles;
}
/**
 * @brief Compare function for sorting pointers to doubles.
 *
 * This function is used as a comparison function for qsort to sort an array of
 * pointers to doubles in ascending order.
 *
 * @param a Pointer to the first element (pointer to double) to be compared.
 * @param b Pointer to the second element (pointer to double) to be compared.
 * @return Integer less than, equal to, or greater than zero if the first
 * element is found to be less than, equal to, or greater than the second
 * element.
 */
FOUNDATIONAL_LIB_WARN_UNUSED_RESULT FOUNDATIONAL_LIB_NONNULL FOUNDATIONAL_LIB_NOTHROW FOUNDATIONAL_LIB_PURE FOUNDATIONAL_LIB_FUNC int FOUNDATIONAL_LIB_cmp_double_ptrs(const void *a, const void *b)
{

    FOUNDATIONAL_LIB_ASSERT_ARGUMENT_IF_ENABLED(a);
    FOUNDATIONAL_LIB_ASSERT_ARGUMENT_IF_ENABLED(b);
    return (*(double **)a - *(double **)b);
}

/**
 * @brief Sorts an array of pointers to doubles in ascending order.
 *
 * This function uses the qsort algorithm to sort the given array of pointers to
 * doubles.
 *
 * @param double_ptrs Pointer to the array of pointers to doubles to be sorted.
 * @param size        Number of elements in the array.
 */
FOUNDATIONAL_LIB_NONNULL FOUNDATIONAL_LIB_FUNC void sort_double_ptrs(double **double_ptrs, size_t size)
{

    FOUNDATIONAL_LIB_ASSERT_ARGUMENT_IF_ENABLED(double_ptrs);
    qsort(double_ptrs, size, sizeof(double *), FOUNDATIONAL_LIB_cmp_double_ptrs);
}

/**
 * @brief Creates a new array containing sorted pointers to doubles.
 *
 * This function takes an array of pointers to doubles, creates a new array,
 * and returns it after sorting the original array in ascending order. The
 * caller is responsible for freeing the memory allocated for the returned array
 * using free().
 *
 * @param double_ptrs Pointer to the array of pointers to doubles to be sorted.
 * @param size        Number of elements in the array.
 * @return            Pointer to the newly created and sorted array of pointers
 * to doubles. The caller is responsible for freeing the memory using free().
 */
FOUNDATIONAL_LIB_WARN_UNUSED_RESULT FOUNDATIONAL_LIB_NONNULL FOUNDATIONAL_LIB_FUNC double **sorted_double_ptrs(double **double_ptrs, size_t size)
{

    FOUNDATIONAL_LIB_ASSERT_ARGUMENT_IF_ENABLED(double_ptrs);

    double **dup_double_ptrs = (double **)arraydup(double_ptrs, size, sizeof(double *));
    if (FOUNDATIONAL_LIB_UNLIKELY(dup_double_ptrs == NULL))
    {
        return NULL;
    }
    qsort(double_ptrs, size, sizeof(double *), FOUNDATIONAL_LIB_cmp_double_ptrs);
    return dup_double_ptrs;
}

/**
 * @brief Compare function for sorting size_t values.
 *
 * This function is used as a comparison function for qsort to sort an array of
 * size_t values in ascending order.
 *
 * @param a Pointer to the first element (size_t) to be compared.
 * @param b Pointer to the second element (size_t) to be compared.
 * @return Integer less than, equal to, or greater than zero if the first
 * element is found to be less than, equal to, or greater than the second
 * element.
 */
FOUNDATIONAL_LIB_WARN_UNUSED_RESULT FOUNDATIONAL_LIB_NONNULL FOUNDATIONAL_LIB_NOTHROW FOUNDATIONAL_LIB_PURE FOUNDATIONAL_LIB_FUNC int FOUNDATIONAL_LIB_cmp_size_ts(const void *a, const void *b)
{

    FOUNDATIONAL_LIB_ASSERT_ARGUMENT_IF_ENABLED(a);
    FOUNDATIONAL_LIB_ASSERT_ARGUMENT_IF_ENABLED(b);
    return (*(size_t *)a - *(size_t *)b);
}

/**
 * @brief Sorts an array of size_t values in ascending order.
 *
 * This function uses the qsort algorithm to sort the given array of size_t
 * values.
 *
 * @param size_ts Pointer to the array of size_t values to be sorted.
 * @param size    Number of elements in the array.
 */
FOUNDATIONAL_LIB_NONNULL FOUNDATIONAL_LIB_FUNC void sort_size_ts(size_t *size_ts, size_t size)
{

    FOUNDATIONAL_LIB_ASSERT_ARGUMENT_IF_ENABLED(size_ts);
    qsort(size_ts, size, sizeof(size_t), FOUNDATIONAL_LIB_cmp_size_ts);
}

/**
 * @brief Creates a new array containing sorted size_t values.
 *
 * This function takes an array of size_t values, creates a new array,
 * and returns it after sorting the original array in ascending order. The
 * caller is responsible for freeing the memory allocated for the returned array
 * using free().
 *
 * @param size_ts Pointer to the array of size_t values to be sorted.
 * @param size    Number of elements in the array.
 * @return        Pointer to the newly created and sorted array of size_t
 * values. The caller is responsible for freeing the memory using free().
 */
FOUNDATIONAL_LIB_WARN_UNUSED_RESULT FOUNDATIONAL_LIB_NONNULL FOUNDATIONAL_LIB_FUNC size_t *sorted_size_ts(size_t *size_ts, size_t size)
{
    FOUNDATIONAL_LIB_ASSERT_ARGUMENT_IF_ENABLED(size_ts);

    size_t *dup_size_ts = (size_t *)arraydup(size_ts, size, sizeof(size_t));
    if (FOUNDATIONAL_LIB_UNLIKELY(dup_size_ts == NULL))
    {
        return NULL;
    }
    qsort(size_ts, size, sizeof(size_t), FOUNDATIONAL_LIB_cmp_size_ts);
    return dup_size_ts;
}

/**
 * @brief Compare function for sorting pointers to size_t values.
 *
 * This function is used as a comparison function for qsort to sort an array of
 * pointers to size_t values in ascending order.
 *
 * @param a Pointer to the first element (pointer to size_t) to be compared.
 * @param b Pointer to the second element (pointer to size_t) to be compared.
 * @return Integer less than, equal to, or greater than zero if the first
 * element is found to be less than, equal to, or greater than the second
 * element.
 */
FOUNDATIONAL_LIB_WARN_UNUSED_RESULT FOUNDATIONAL_LIB_NONNULL FOUNDATIONAL_LIB_NOTHROW FOUNDATIONAL_LIB_PURE FOUNDATIONAL_LIB_FUNC int FOUNDATIONAL_LIB_cmp_size_t_ptrs(const void *a, const void *b)
{
    FOUNDATIONAL_LIB_ASSERT_ARGUMENT_IF_ENABLED(a);
    FOUNDATIONAL_LIB_ASSERT_ARGUMENT_IF_ENABLED(b);
    return (*(size_t **)a - *(size_t **)b);
}

/**
 * @brief Sorts an array of pointers to size_t values in ascending order.
 *
 * This function uses the qsort algorithm to sort the given array of pointers to
 * size_t values.
 *
 * @param size_t_ptrs Pointer to the array of pointers to size_t values to be
 * sorted.
 * @param size        Number of elements in the array.
 */
FOUNDATIONAL_LIB_NONNULL FOUNDATIONAL_LIB_FUNC void sort_size_t_ptrs(size_t **size_t_ptrs, size_t size)
{

    FOUNDATIONAL_LIB_ASSERT_ARGUMENT_IF_ENABLED(size_t_ptrs);
    qsort(size_t_ptrs, size, sizeof(size_t *), FOUNDATIONAL_LIB_cmp_size_t_ptrs);
}
/**
 * @brief Creates a new array containing sorted pointers to size_t values.
 *
 * This function takes an array of pointers to size_t values, creates a new
 * array, and returns it after sorting the original array in ascending order.
 * The caller is responsible for freeing the memory allocated for the returned
 * array using free().
 *
 * @param size_t_ptrs Pointer to the array of pointers to size_t values to be
 * sorted.
 * @param size        Number of elements in the array.
 * @return            Pointer to the newly created and sorted array of pointers
 * to size_t values. The caller is responsible for freeing the memory using
 * free().
 */
FOUNDATIONAL_LIB_WARN_UNUSED_RESULT FOUNDATIONAL_LIB_NONNULL FOUNDATIONAL_LIB_FUNC size_t **sorted_size_t_ptrs(size_t **size_t_ptrs, size_t size)
{
    FOUNDATIONAL_LIB_ASSERT_ARGUMENT_IF_ENABLED(size_t_ptrs);

    size_t **dup_size_t_ptrs = (size_t **)arraydup(size_t_ptrs, size, sizeof(size_t *));

    if (FOUNDATIONAL_LIB_UNLIKELY(dup_size_t_ptrs == NULL))
    {
        return NULL;
    }

    qsort(size_t_ptrs, size, sizeof(size_t *), FOUNDATIONAL_LIB_cmp_size_t_ptrs);

    return dup_size_t_ptrs;
}

/**
 * @brief Converts a string to an integer.
 *
 * This function converts a string representation of an integer to an actual
 * integer value.
 *
 * @param str Pointer to the string to be converted.
 * @return Integer value representing the converted string. If the string is not
 * a valid integer representation, the behavior is undefined.
 */
FOUNDATIONAL_LIB_WARN_UNUSED_RESULT FOUNDATIONAL_LIB_NONNULL FOUNDATIONAL_LIB_NOTHROW FOUNDATIONAL_LIB_PURE FOUNDATIONAL_LIB_FUNC int string_to_int(const char *str)
{

    FOUNDATIONAL_LIB_ASSERT_ARGUMENT_IF_ENABLED(str);
    return FOUNDATIONAL_LIB_ATOI(str);
}

/**
 * @brief Reads the contents of a file into a string.
 *
 * This function reads the contents of the specified file into a dynamically
 * allocated string and returns a pointer to the created string. The size of the
 * string is stored in the variable pointed to by the 'size' parameter. The
 * caller is responsible for freeing the memory allocated for the returned
 * string using free().
 *
 * @param filename Pointer to the name of the file to be read.
 * @param size     Pointer to a variable where the size of the read string will
 * be stored.
 * @return         Pointer to the dynamically allocated string containing the
 * file contents. Returns NULL if there is an error or the file is empty. The
 * caller is responsible for freeing the memory using free().
 */
FOUNDATIONAL_LIB_WARN_UNUSED_RESULT FOUNDATIONAL_LIB_NONNULL FOUNDATIONAL_LIB_NOTHROW FOUNDATIONAL_LIB_FUNC char *read_file_into_string(const char *filename, size_t *size)
{
    FOUNDATIONAL_LIB_ASSERT_ARGUMENT_IF_ENABLED(filename);
    FOUNDATIONAL_LIB_ASSERT_ARGUMENT_IF_ENABLED(size);

    *size = 0;

    FILE *file = fopen(filename, "rb");
    if (FOUNDATIONAL_LIB_UNLIKELY(file == NULL))
    {
        FOUNDATIONAL_LIB_die_aggressively_if_enabled();
        return NULL; // Indicate error by returning NULL
    }

    // Determine the file size by seeking
    if (FOUNDATIONAL_LIB_FSEEKO(file, 0, SEEK_END) != 0)
    {
        FOUNDATIONAL_LIB_FCLOSE(file); // No need to error check here because already going wrong.
        FOUNDATIONAL_LIB_die_aggressively_if_enabled();
        return NULL;
    }

    // Get file size with tell
    const off_t file_size = FOUNDATIONAL_LIB_FTELLO(file); /* signed int type */
    if (FOUNDATIONAL_LIB_UNLIKELY(file_size == -1))
    {
        FOUNDATIONAL_LIB_FCLOSE(file); // No need to error check here because already going wrong.
        FOUNDATIONAL_LIB_die_aggressively_if_enabled();
        return NULL;
    }

    *size = (size_t)file_size;

    // Since off_t is signed, it should be less than SIZE_MAX, so don't check
    // if it equals SIZE_MAX before adding 1 more to it to FOUNDATIONAL_LIB_MEMORY_ALLOCATOR_MALLOC()

    // Seek to the beginning again
    if (FOUNDATIONAL_LIB_FSEEKO(file, 0, SEEK_SET) != 0)
    {
        FOUNDATIONAL_LIB_FCLOSE(file); // No need to error check here because already going wrong.
        FOUNDATIONAL_LIB_die_aggressively_if_enabled();
        return NULL;
    }

    // Allocate memory for the file contents
    char *content = (char *)FOUNDATIONAL_LIB_MEMORY_ALLOCATOR_MALLOC(file_size + 1); /* Safe. */
    if (FOUNDATIONAL_LIB_UNLIKELY(content == NULL))
    {
        FOUNDATIONAL_LIB_FCLOSE(file); // No need to error check here because already going wrong.
        FOUNDATIONAL_LIB_die_aggressively_if_enabled();
        return NULL;
    }

    // Read the file contents into the string
    size_t total_read = 0;
    const size_t file_size_size_t = (size_t)file_size;

    while (total_read < file_size_size_t)
    {
        const size_t read_size = FOUNDATIONAL_LIB_FREAD(content + total_read, 1, file_size - total_read, file);

        if (read_size == 0) // Not likely or unlikely.
        {
            const int error_code = FOUNDATIONAL_LIB_FERROR(file);
            if (FOUNDATIONAL_LIB_UNLIKELY(error_code))
            {
                FOUNDATIONAL_LIB_MEMORY_ALLOCATOR_FREE(content);
                FOUNDATIONAL_LIB_FCLOSE(file); // Don't need to error check here because things are going
                                               // wrong.
                FOUNDATIONAL_LIB_die_aggressively_if_enabled();
                return NULL;
            }
            else
            {
                break;
            }
        }
        total_read += read_size;
    }

    // Null-terminate the string
    content[total_read] = '\0';

    // Close the file
    if (FOUNDATIONAL_LIB_UNLIKELY(fclose(file) != 0)) // Check for errors.
    {
        FOUNDATIONAL_LIB_MEMORY_ALLOCATOR_FREE(content);
        FOUNDATIONAL_LIB_die_aggressively_if_enabled();
        return NULL;
    }

    return content;
}

/**
 * @brief Writes a string or data to a file with a specified mode.
 *
 * This function writes the specified content string to the specified file.
 *
 * @param filename        Pointer to the name of the file to be written.
 * @param content         Pointer to the string content to be written to the
 * file.
 * @param content_length  The length of the data to be written.
 * @param mode            Pointer to the mode of the file to be written to.
 * @return                Returns 0 on success and -1 on failure. The function
 * fails if the file cannot be opened or if there is an error during the writing
 * process.
 */
FOUNDATIONAL_LIB_NONNULL FOUNDATIONAL_LIB_NOTHROW FOUNDATIONAL_LIB_FUNC int write_to_file_with_mode(const char *filename, const char *content, size_t content_length, const char *mode)
{
    FOUNDATIONAL_LIB_ASSERT_ARGUMENT_IF_ENABLED(filename);
    FOUNDATIONAL_LIB_ASSERT_ARGUMENT_IF_ENABLED(content);
    FOUNDATIONAL_LIB_ASSERT_ARGUMENT_IF_ENABLED(mode);
    FILE *file = fopen(filename, mode);
    if (FOUNDATIONAL_LIB_UNLIKELY(file == NULL))
    {
        FOUNDATIONAL_LIB_die_aggressively_if_enabled();
        return -1;
    }

    /* Write the string to the file */
    size_t write_size;
    size_t total_written = 0;

    /* No need to check for EINTR. It would just slow things down here. */
    while ((write_size = FOUNDATIONAL_LIB_FWRITE(content + total_written, 1, content_length - total_written, file)) > 0)
    {
        total_written += write_size;
    }

    // Close the file
    if (FOUNDATIONAL_LIB_UNLIKELY(fclose(file) != 0)) // Check for errors.
    {
        FOUNDATIONAL_LIB_die_aggressively_if_enabled();
        return -1;
    }

    return 0;
}

/**
 * @brief Writes a string to a file.
 *
 * This function writes the specified content string to the specified file.
 *
 * @param filename Pointer to the name of the file to be written.
 * @param content  Pointer to the string content to be written to the file.
 * @param mode     Pointer to the mode of the file to be written to.
 * @return         Returns 0 on success and -1 on failure. The function fails if
 *                 the file cannot be opened or if there is an error during the
 * writing process.
 */
FOUNDATIONAL_LIB_NONNULL FOUNDATIONAL_LIB_NOTHROW FOUNDATIONAL_LIB_FUNC int write_file(const char *filename, const char *content)
{
    FOUNDATIONAL_LIB_ASSERT_ARGUMENT_IF_ENABLED(filename);
    FOUNDATIONAL_LIB_ASSERT_ARGUMENT_IF_ENABLED(content);

    /* This function is  d by default. */
    return write_to_file_with_mode(filename, content, FOUNDATIONAL_LIB_STRLEN(content), "w");
}

/**
 * @brief Appends a string to a file.
 *
 * This function appends the specified content string of a given size to the end
 * of the specified file.
 *
 * @param filename     Pointer to the name of the file to which the content will
 * be appended.
 * @param content      Pointer to the string content to be appended to the file.
 * @param content_size Size of the content to be appended.
 * @return             Returns 0 on success and -1 on failure. The function
 * fails if the file cannot be opened or if there is an error during the
 * appending process.
 */
FOUNDATIONAL_LIB_NONNULL FOUNDATIONAL_LIB_NOTHROW FOUNDATIONAL_LIB_FUNC int append_string_to_file(const char *filename, const char *content)
{
    FOUNDATIONAL_LIB_ASSERT_ARGUMENT_IF_ENABLED(filename);
    FOUNDATIONAL_LIB_ASSERT_ARGUMENT_IF_ENABLED(content);

    /* This function is  d by default. */
    return write_to_file_with_mode(filename, content, FOUNDATIONAL_LIB_STRLEN(content), "a");
}

#ifdef _WIN32
#include <io.h>
#else
#include <unistd.h>
#endif

#include <sys/stat.h>

/**
 * @brief Checks if a file exists.
 *
 * This function checks if the specified file exists in the file system.
 *
 * @param filename Pointer to the name of the file to be checked for existence.
 * @return         Returns 1 if the file exists, and 0 otherwise.
 */
FOUNDATIONAL_LIB_WARN_UNUSED_RESULT FOUNDATIONAL_LIB_NONNULL FOUNDATIONAL_LIB_NOTHROW FOUNDATIONAL_LIB_FUNC int file_exists(const char *filename)
{
    FOUNDATIONAL_LIB_ASSERT_ARGUMENT_IF_ENABLED(filename);

#ifdef _WIN32
    return _access(filename, 0) == 0;
#else
    return access(filename, F_OK) == 0;
#endif
}

/**
 * @brief Checks if a file is a regular file.
 *
 * This function checks if the specified file is a regular file in the file
 * system.
 *
 * @param filename Pointer to the name of the file to be checked.
 * @return         Returns 1 if the file is a regular file, and 0 otherwise.
 */
FOUNDATIONAL_LIB_WARN_UNUSED_RESULT FOUNDATIONAL_LIB_NONNULL FOUNDATIONAL_LIB_NOTHROW FOUNDATIONAL_LIB_FUNC int file_is_regular(const char *filename)
{
    FOUNDATIONAL_LIB_ASSERT_ARGUMENT_IF_ENABLED(filename);

    struct stat st;
#ifdef _WIN32
    if (stat(filename, &st) == 0)
        return (st.st_mode & _S_IFREG) != 0;
#else
    if (stat(filename, &st) == 0)
        return S_ISREG(st.st_mode);
#endif
    return 0;
}

/**
 * @brief Checks if a file is a directory.
 *
 * This function checks if the specified file is a directory in the file system.
 *
 * @param filename Pointer to the name of the file to be checked.
 * @return         Returns 1 if the file is a directory, and 0 otherwise.
 */
FOUNDATIONAL_LIB_WARN_UNUSED_RESULT FOUNDATIONAL_LIB_NONNULL FOUNDATIONAL_LIB_NOTHROW FOUNDATIONAL_LIB_FUNC int file_is_directory(const char *filename)
{
    FOUNDATIONAL_LIB_ASSERT_ARGUMENT_IF_ENABLED(filename);

    struct stat st;
#ifdef _WIN32
    if (stat(filename, &st) == 0)
        return (st.st_mode & _S_IFDIR) != 0;
#else
    if (stat(filename, &st) == 0)
        return S_ISDIR(st.st_mode);
#endif
    return 0;
}

/**
 * @brief Checks if a file is readable.
 *
 * This function checks if the specified file is readable by the current
 * process.
 *
 * @param filename Pointer to the name of the file to be checked for
 * readability.
 * @return         Returns 1 if the file is readable, and 0 otherwise.
 */
FOUNDATIONAL_LIB_WARN_UNUSED_RESULT FOUNDATIONAL_LIB_NONNULL FOUNDATIONAL_LIB_NOTHROW FOUNDATIONAL_LIB_FUNC int file_is_readable(const char *filename)
{
    FOUNDATIONAL_LIB_ASSERT_ARGUMENT_IF_ENABLED(filename);

#ifdef _WIN32
    return _access(filename, 4) == 0; // 4 is for read permission on Windows
#else
    return access(filename, R_OK) == 0; // R_OK is for read permission on POSIX systems
#endif
}

/**
 * @brief Checks if a file is writable.
 *
 * This function checks if the specified file is writable by the current
 * process.
 *
 * @param filename Pointer to the name of the file to be checked for
 * writability.
 * @return         Returns 1 if the file is writable, and 0 otherwise.
 */
FOUNDATIONAL_LIB_WARN_UNUSED_RESULT FOUNDATIONAL_LIB_NONNULL FOUNDATIONAL_LIB_NOTHROW FOUNDATIONAL_LIB_FUNC int file_is_writable(const char *filename)
{
    FOUNDATIONAL_LIB_ASSERT_ARGUMENT_IF_ENABLED(filename);

#ifdef _WIN32
    return _access(filename, 2) == 0; // 2 is for write permission on Windows
#else
    return access(filename, W_OK) == 0; // W_OK is for write permission on POSIX systems
#endif
}

/**
 * @brief Checks if a file is executable.
 *
 * This function checks if the specified file is executable by the current
 * process.
 *
 * @param filename Pointer to the name of the file to be checked for
 * executability.
 * @return         Returns 1 if the file is executable, and 0 otherwise.
 */
FOUNDATIONAL_LIB_WARN_UNUSED_RESULT FOUNDATIONAL_LIB_NONNULL FOUNDATIONAL_LIB_NOTHROW FOUNDATIONAL_LIB_FUNC int file_is_executable(const char *filename)
{
    FOUNDATIONAL_LIB_ASSERT_ARGUMENT_IF_ENABLED(filename);

#ifdef _WIN32
    return _access(filename, 1) == 0; // 1 is for execute permission on Windows
#else
    return access(filename, X_OK) == 0; // X_OK is for execute permission on POSIX systems
#endif
}

/**
 * @brief Gets the size of a file.
 *
 * This function retrieves the size of the specified file and stores it in the
 * variable pointed to by the 'size' parameter.
 *
 * @param filename Pointer to the name of the file to get the size.
 * @param size     Pointer to a variable where the size of the file will be
 * stored.
 * @return         Returns 0 on success and -1 on error. The function fails if
 * the file cannot be opened or if there is an error during the size retrieval.
 */
FOUNDATIONAL_LIB_WARN_UNUSED_RESULT FOUNDATIONAL_LIB_NONNULL FOUNDATIONAL_LIB_NOTHROW FOUNDATIONAL_LIB_FUNC int get_file_size(const char *filename, size_t *size)
{
    FOUNDATIONAL_LIB_ASSERT_ARGUMENT_IF_ENABLED(filename);
    FOUNDATIONAL_LIB_ASSERT_ARGUMENT_IF_ENABLED(size);

    FILE *file = fopen(filename, "r");
    if (FOUNDATIONAL_LIB_UNLIKELY(file == NULL))
    {
        FOUNDATIONAL_LIB_die_aggressively_if_enabled();
        return -1;
    }

    // Determine the file size with seek
    if (FOUNDATIONAL_LIB_UNLIKELY(FOUNDATIONAL_LIB_FSEEKO(file, 0, SEEK_END) != 0))
    {
        FOUNDATIONAL_LIB_FCLOSE(file); // No need to error check here because already going wrong.
        FOUNDATIONAL_LIB_die_aggressively_if_enabled();
        return -1;
    }

    // Get the file size with tell
    const off_t file_size = ftello(file);
    if (FOUNDATIONAL_LIB_UNLIKELY(file_size == -1))
    {
        FOUNDATIONAL_LIB_FCLOSE(file); // No need to error check here because already going wrong.
        FOUNDATIONAL_LIB_die_aggressively_if_enabled();
        return -1;
    }

    // Close the file
    if (FOUNDATIONAL_LIB_UNLIKELY(fclose(file) != 0)) // Error check
    {
        FOUNDATIONAL_LIB_die_aggressively_if_enabled();
        return -1;
    }

    *size = file_size;
    return 0;
}

/**
 * @brief Removes a file.
 *
 * This function removes (deletes) the specified file from the file system.
 *
 * @param filename Pointer to the name of the file to be removed.
 * @return         Returns 0 on success and -1 on error. The function fails if
 *                 the file cannot be removed or if there is an error during the
 * removal process.
 */
FOUNDATIONAL_LIB_NONNULL FOUNDATIONAL_LIB_NOTHROW FOUNDATIONAL_LIB_FUNC int remove_file(const char *filename)
{
    FOUNDATIONAL_LIB_ASSERT_ARGUMENT_IF_ENABLED(filename);

    /* Standard c function */
    if (FOUNDATIONAL_LIB_UNLIKELY(remove(filename) != 0))
    {
        FOUNDATIONAL_LIB_die_aggressively_if_enabled();
        return -1;
    }
    return 0;
}

/**
 * @brief Copies a file from source to destination.
 *
 * This function copies the content of the source file to the destination file.
 *
 * @param source_filename      Pointer to the name of the source file.
 * @param destination_filename Pointer to the name of the destination file.
 * @return                     Returns 0 on success and -1 on error. The
 * function fails if the source file cannot be opened, the destination file
 *                             cannot be created or written to, or if there is
 * an error during the copying process.
 */
FOUNDATIONAL_LIB_WARN_UNUSED_RESULT FOUNDATIONAL_LIB_NONNULL FOUNDATIONAL_LIB_NOTHROW FOUNDATIONAL_LIB_FUNC int copy_file(const char *source_filename, const char *destination_filename)
{
    FOUNDATIONAL_LIB_ASSERT_ARGUMENT_IF_ENABLED(source_filename);
    FOUNDATIONAL_LIB_ASSERT_ARGUMENT_IF_ENABLED(destination_filename);
    FILE *source_file = fopen(source_filename, "rb");

    if (FOUNDATIONAL_LIB_UNLIKELY(source_file == NULL))
    {
        FOUNDATIONAL_LIB_die_aggressively_if_enabled();
        return -1;
    }

    FILE *destination_file = fopen(destination_filename, "wb");
    if (FOUNDATIONAL_LIB_UNLIKELY(destination_file == NULL))
    {
        FOUNDATIONAL_LIB_FCLOSE(source_file); // No need to error check here because already going
                                              // wrong.

        FOUNDATIONAL_LIB_die_aggressively_if_enabled();
        return -1;
    }

    char buffer[FOUNDATIONAL_LIB_COPY_SIZE_AMOUNT];

    for (;;)
    {
        // Read from the file.
        size_t read_size;
        int error_code;

        /* Handle interrupted system calls */

        do
        {
            read_size = FOUNDATIONAL_LIB_FREAD(buffer, 1, sizeof(buffer), source_file);
        } while (FOUNDATIONAL_LIB_UNLIKELY((error_code = FOUNDATIONAL_LIB_FERROR(source_file)) && errno == EINTR)); /* Check for EINTR */

        // If it has finished reading or if an error has occured.
        if (read_size == 0) // Not likely or unlikely.
        {
            if (FOUNDATIONAL_LIB_UNLIKELY(error_code))
            {
                /*
                 * Here, we can distinuish between errors to ignore, and errors to to
                 * about. Adjust this based on your environment or preferences.
                 */

                FOUNDATIONAL_LIB_FCLOSE(destination_file); // Don't need to error check here because
                                                           // things are going wrong.
                FOUNDATIONAL_LIB_FCLOSE(source_file);      // Don't need to error check here because things
                                                           // are going wrong.

                FOUNDATIONAL_LIB_die_aggressively_if_enabled();
                return -1;
            }
            else
            {
                break;
            }
        }

        /* Handle interrupted system calls */

        size_t write_size = 0;
        size_t new_write_size;
        do
        {
            new_write_size = FOUNDATIONAL_LIB_FWRITE(buffer + write_size, 1, read_size - write_size, destination_file);
            write_size += new_write_size;
        } while (write_size != read_size || FOUNDATIONAL_LIB_UNLIKELY(errno == EINTR)); /* Check for EINTR */
    }

    if (FOUNDATIONAL_LIB_UNLIKELY(ferror(source_file) != 0 || FOUNDATIONAL_LIB_FERROR(destination_file) != 0))
    {
        FOUNDATIONAL_LIB_FCLOSE(source_file);      // No need to error check here because already going
                                                   // wrong.
        FOUNDATIONAL_LIB_FCLOSE(destination_file); // No need to error check here because already
                                                   // going wrong.

        FOUNDATIONAL_LIB_die_aggressively_if_enabled();
        return -1;
    }

    if (FOUNDATIONAL_LIB_UNLIKELY(fclose(source_file) != 0 || FOUNDATIONAL_LIB_FCLOSE(destination_file) != 0)) // Error check
    {
        FOUNDATIONAL_LIB_die_aggressively_if_enabled();
        return -1;
    }

    return 0;
}

#ifdef _WIN32
#include <windows.h>

/**
 * @brief Lists files in a directory using a wildcard pattern.
 *
 * This function retrieves the list of files in the specified directory that
 * match the specified wildcard pattern. The function returns an array of
 * strings containing the file names. The length of the array is stored in the
 * variable pointed to by the 'len' parameter. The caller is responsible for
 * freeing the memory allocated for the returned array and each string within it
 * using free() or simply using free_array().
 *
 * @param directory Pointer to the name of the directory to list files from.
 * @param pattern   Pointer to the wildcard pattern for filtering files.
 * @param len       Pointer to a variable where the length of the file list
 * array will be stored.
 * @return          Pointer to the dynamically allocated array of strings
 * containing the file names. Returns NULL if there is an error or if no files
 * match the pattern. The caller is responsible for freeing the memory using
 * free().
 */
FOUNDATIONAL_LIB_WARN_UNUSED_RESULT FOUNDATIONAL_LIB_NONNULL FOUNDATIONAL_LIB_NOTHROW FOUNDATIONAL_LIB_FUNC char **list_files_with_pattern(const char *directory, const char *pattern, size_t *len)
{
    FOUNDATIONAL_LIB_ASSERT_ARGUMENT_IF_ENABLED(directory);
    FOUNDATIONAL_LIB_ASSERT_ARGUMENT_IF_ENABLED(pattern);
    FOUNDATIONAL_LIB_ASSERT_ARGUMENT_IF_ENABLED(len);

    *len = 0;
    char search_path[MAX_PATH];
    FOUNDATIONAL_LIB_SNPRINTF(search_path, MAX_PATH, "%s\\%s", directory, pattern);

    WIN32_FIND_DATA find_file_data;
    HANDLE find_handle = FindFirstFile(search_path, &find_file_data);

    if (FOUNDATIONAL_LIB_UNLIKELY(find_handle == INVALID_HANDLE_VALUE))
    {

        /* One element of size zero. */
        char **new_array = (char **)FOUNDATIONAL_LIB_MEMORY_ALLOCATOR_MALLOC(sizeof(char *));
        *new_array = NULL;
        return new_array;
    }

    /* Count the number of files matching the pattern */
    int file_count = 0;
    do
    {
        if (!(find_file_data.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY))
        {
            ++file_count;
        }
    } while (FindNextFile(find_handle, &find_file_data) != 0);

    size_t mul;

    if (FOUNDATIONAL_LIB_UNLIKELY(file_count == 0))
    {
        mul = FOUNDATIONAL_LIB_INITIAL_STRING_ARRAY_ALLOC_SIZE;
    }
    else if (FOUNDATIONAL_LIB_UNLIKELY(FOUNDATIONAL_LIB_safe_mul_ptr(file_count, sizeof(char *), &mul) == 0))
    {
        FOUNDATIONAL_LIB_die_aggressively_if_enabled();
        return NULL;
    }

    /* Allocate memory for the array of strings */
    char **files_array = (char **)FOUNDATIONAL_LIB_MEMORY_ALLOCATOR_MALLOC(mul);
    if (FOUNDATIONAL_LIB_UNLIKELY(files_array == NULL))
    {
        FOUNDATIONAL_LIB_die_aggressively_if_enabled();
        return NULL;
    }

    /* Populate the array with file names matching the pattern */
    int index = 0;
    if (FOUNDATIONAL_LIB_UNLIKELY(FindClose(find_handle) == 0))
    {
        FOUNDATIONAL_LIB_die_aggressively_if_enabled();
        return NULL;
    }
    find_handle = FindFirstFile(search_path, &find_file_data);
    do
    {
        if (!(find_file_data.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY))
        {
            files_array[index] = FOUNDATIONAL_LIB_MEMORY_ALLOCATOR_STRDUP(find_file_data.cFileName);
            if (FOUNDATIONAL_LIB_UNLIKELY(files_array[index] == NULL))
            {
                return NULL;
            }
            ++index;
        }
    } while (FindNextFile(find_handle, &find_file_data) != 0);

    /* Close the find handle */
    if (FOUNDATIONAL_LIB_UNLIKELY(FindClose(find_handle) == 0))
    {
        FOUNDATIONAL_LIB_die_aggressively_if_enabled();
        return NULL;
    }

    *len = index;

    return files_array;
}

#else

#include <dirent.h>
#include <fnmatch.h>

/**
 * @brief Lists files in a directory using a wildcard pattern.
 *
 * This function retrieves the list of files in the specified directory that
 * match the specified wildcard pattern. The function returns an array of
 * strings containing the file names. The length of the array is stored in the
 * variable pointed to by the 'len' parameter. The caller is responsible for
 * freeing the memory allocated for the returned array and each string within it
 * using free() or simply using free_array().
 *
 * @param directory Pointer to the name of the directory to list files from.
 * @param pattern   Pointer to the wildcard pattern for filtering files.
 * @param len       Pointer to a variable where the length of the file list
 * array will be stored.
 * @return          Pointer to the dynamically allocated array of strings
 * containing the file names. Returns NULL if there is an error or if no files
 * match the pattern. The caller is responsible for freeing the memory using
 * free().
 */
FOUNDATIONAL_LIB_WARN_UNUSED_RESULT FOUNDATIONAL_LIB_NONNULL FOUNDATIONAL_LIB_NOTHROW FOUNDATIONAL_LIB_FUNC char **list_files_with_pattern(const char *directory, const char *pattern, size_t *len)
{
    FOUNDATIONAL_LIB_ASSERT_ARGUMENT_IF_ENABLED(directory);
    FOUNDATIONAL_LIB_ASSERT_ARGUMENT_IF_ENABLED(pattern);
    FOUNDATIONAL_LIB_ASSERT_ARGUMENT_IF_ENABLED(len);

    *len = 0;
    DIR *dir = opendir(directory);
    if (FOUNDATIONAL_LIB_UNLIKELY(dir == NULL))
    {
        FOUNDATIONAL_LIB_die_aggressively_if_enabled();
        return NULL;
    }

    /* Count the number of files matching the pattern */
    int file_count = 0;
    struct dirent *entry;
    while ((entry = readdir(dir)) != NULL)
    {
        if (fnmatch(pattern, entry->d_name, FNM_PERIOD) == 0)
        {
            ++file_count;
        }
    }

    rewinddir(dir); // No errors with this function

    size_t mul;

    if (FOUNDATIONAL_LIB_UNLIKELY(file_count == 0))
    {
        mul = FOUNDATIONAL_LIB_INITIAL_STRING_ARRAY_ALLOC_SIZE;
    }
    else if (FOUNDATIONAL_LIB_UNLIKELY(FOUNDATIONAL_LIB_safe_mul_ptr(file_count, sizeof(char *), &mul) == 0))
    {
        FOUNDATIONAL_LIB_die_aggressively_if_enabled();
        return NULL;
    }

    /* Allocate memory for the array of strings */
    char **files_array = (char **)FOUNDATIONAL_LIB_MEMORY_ALLOCATOR_MALLOC(mul);

    /* Populate the array with file names matching the pattern */
    size_t index = 0;
    while ((entry = readdir(dir)) != NULL)
    {
        if (fnmatch(pattern, entry->d_name, FNM_PERIOD) == 0)
        {
            files_array[index] = FOUNDATIONAL_LIB_MEMORY_ALLOCATOR_STRDUP(entry->d_name);
            if (FOUNDATIONAL_LIB_UNLIKELY(files_array[index] == NULL))
            {
                FOUNDATIONAL_LIB_die_aggressively_if_enabled();
                return NULL;
            }
            ++index;
        }
    }
    if (FOUNDATIONAL_LIB_UNLIKELY(closedir(dir) == -1))
    {
        FOUNDATIONAL_LIB_die_aggressively_if_enabled();
        return NULL;
    }

    *len = index;

    return files_array;
}

#endif

/**
 * @brief Concatenates an array of strings into a single string.
 *
 * This function takes an array of strings and concatenates them into a single
 * string. The resulting string is dynamically allocated and the caller is
 * responsible for freeing the memory using free().
 *
 * @param strings An array of C-style strings (const char**) to be concatenated.
 * @param num_strings The number of strings in the array.
 *
 * @return A dynamically allocated string containing the concatenated result.
 *         The caller is responsible for freeing the memory using free().
 *
 * @warning The caller is responsible for freeing the memory of the returned
 *          string using free() to prevent memory leaks.
 */
FOUNDATIONAL_LIB_WARN_UNUSED_RESULT FOUNDATIONAL_LIB_NONNULL FOUNDATIONAL_LIB_NOTHROW FOUNDATIONAL_LIB_MALLOC FOUNDATIONAL_LIB_FUNC char *concatenate_string_array(const char **strings, size_t num_strings)
{
    FOUNDATIONAL_LIB_ASSERT_ARGUMENT_IF_ENABLED(strings);

    /* Initialize total length and allocate initial memory for result */
    size_t alloc_size = FOUNDATIONAL_LIB_INITIAL_STRING_ARRAY_ALLOC_SIZE;
    char *result = (char *)FOUNDATIONAL_LIB_MEMORY_ALLOCATOR_MALLOC(alloc_size);

    // Check for initial memory allocation failure
    if (FOUNDATIONAL_LIB_UNLIKELY(result == NULL))
        goto memory_error;

    size_t new_len;

    // If no strings, new_len will still be 0, and then a null terminator will be put at byte 0.
    new_len = 0;

    // Concatenate the strings char by char using FOUNDATIONAL_LIB_MEMCPY and FOUNDATIONAL_LIB_MEMORY_ALLOCATOR_REALLOC
    for (size_t i = 0; i < num_strings; ++i)
    {
        const char *current_string = strings[i];

        // Iterate through each character and append to the result
        size_t current_length_of_current_string = 0;
        while (current_string[current_length_of_current_string] != '\0')
        {
            if (FOUNDATIONAL_LIB_UNLIKELY(new_len == SIZE_MAX))
                goto overflow;
            /* FOUNDATIONAL_LIB_REALLOC_REALLOCATION_ALGORITHM returns always at least one more */
            const size_t new_size = FOUNDATIONAL_LIB_REALLOC_REALLOCATION_ALGORITHM(new_len + sizeof("")); /* Safe. */

            if (FOUNDATIONAL_LIB_UNLIKELY(new_size == 0))
            {
                FOUNDATIONAL_LIB_MEMORY_ALLOCATOR_FREE(result);
                goto memory_error;
            }
            // Resize the result string if necessary
            if (FOUNDATIONAL_LIB_UNLIKELY(new_size > alloc_size))
            {
                char *new_result = (char *)FOUNDATIONAL_LIB_MEMORY_ALLOCATOR_REALLOC(result, new_size);

                // Check for realloc failure
                if (FOUNDATIONAL_LIB_UNLIKELY(new_result == NULL))
                {
                    FOUNDATIONAL_LIB_MEMORY_ALLOCATOR_FREE(result);
                    goto memory_error;
                }

                result = new_result;
            }

            // Append the current character to the result
            result[new_len++] = current_string[current_length_of_current_string++];
        }
    }

    // Add the null terminator
    result[new_len] = '\0';

    return result;

overflow:
memory_error:
    FOUNDATIONAL_LIB_die_aggressively_if_enabled();
    return NULL;
}

/**
 * @brief Concatenates two strings.
 *
 * This function concatenates the contents of the two given strings and returns
 * a dynamically allocated string containing the result. The caller is
 * responsible for freeing the memory allocated for the returned string using
 * free().
 *
 * @param str1 Pointer to the first null-terminated string.
 * @param str2 Pointer to the second null-terminated string.
 * @return     Pointer to the dynamically allocated string containing the
 * concatenated result. Returns NULL if there is an allocation error. The caller
 * is responsible for freeing the memory using free().
 */
FOUNDATIONAL_LIB_WARN_UNUSED_RESULT FOUNDATIONAL_LIB_NONNULL FOUNDATIONAL_LIB_NOTHROW FOUNDATIONAL_LIB_MALLOC FOUNDATIONAL_LIB_FUNC char *concatenate_strings(const char *str1, const char *str2)
{
    FOUNDATIONAL_LIB_ASSERT_ARGUMENT_IF_ENABLED(str1);
    FOUNDATIONAL_LIB_ASSERT_ARGUMENT_IF_ENABLED(str2);

    const char *strs[2] = {str1, str2};

    return concatenate_string_array(strs, 2);
}

/**
 * @brief Performs memory replacement with specified lengths.
 *
 * This function replaces occurrences of the 'find' memory unit with the 'replace'
 * memory unit within the 'source' memory unit. It operates on memory blocks.
 *
 * 'output' is aliased to the original value, if so, there was no text replacement,
 * and no new memory was allocated. As such, there is no new memory that needs to be
 * freed().
 *
 *
 * @param source The original block to search.
 * @param find The block to be replaced.
 * @param replace The block to replace 'find' with.
 * @param source_len The length of the 'source' block.
 * @param find_len The length of the 'find' block.
 * @param replace_len The length of the 'replace' block.
 * @param output A pointer to the new string resulting from the replacements.
 *        The caller is responsible for freeing the memory allocated for 'output'.
 *
 *        If should_free_after_use is non-zero, a new dynamically allocated array with the replacements made.
 *        If should_free_after_use is zero, output aliases source, and they refer to the same memory.
 * @param should_free_after_use A pointer to a int indicating whether one should free the memory after using the function.
 * @param num_matches A pointer to a variable to store the number of replacements made.
 * @param matches_max A pointer to the maximum number of replacements to make. If zero, there is no maximum.
 *
 * @return Returns 0 on success, -1 on failure.
 *
 * @note This function is designed for performance but requires careful memory
 * management. Ensure that the caller frees the memory allocated for 'new_text' if appropriate
 * and checks the return value.
 *
 * @note For efficiency, null terminated strings are not checked. As such, the blocks of memory that are being replaced CAN contain null bytes.
 *
 *       This function is just about the most powerful and most efficient memory replacement that you will find anywhere.
 *
 *       It seems impementations of memmem() and FOUNDATIONAL_LIB_STRSTR() can vary speed-wise depending on machine. On one of my machines, memmem() was MUCH faster
 *       whereas on my other machine, FOUNDATIONAL_LIB_STRSTR() was faster (strangely). We should reimplement these functions in assembly, or use a library to have
 *       IDEAL version of these.
 */
FOUNDATIONAL_LIB_FUNC int replace_memory(void *source, size_t source_len, void *find, size_t find_len, void *replace, size_t replace_len, void **output, size_t *output_length_without_nullt, int *should_free_after_use, size_t matches_max /* 0 for unlimited replacement */, size_t *num_matches_found, int should_nullt)
{
    FOUNDATIONAL_LIB_ASSERT_ARGUMENT_IF_ENABLED(source);
    FOUNDATIONAL_LIB_ASSERT_ARGUMENT_IF_ENABLED(find);
    FOUNDATIONAL_LIB_ASSERT_ARGUMENT_IF_ENABLED(replace);
    FOUNDATIONAL_LIB_ASSERT_ARGUMENT_IF_ENABLED(output);
    FOUNDATIONAL_LIB_ASSERT_ARGUMENT_IF_ENABLED(output_length_without_nullt);
    FOUNDATIONAL_LIB_ASSERT_ARGUMENT_IF_ENABLED(should_free_after_use);
    FOUNDATIONAL_LIB_ASSERT_ARGUMENT_IF_ENABLED(num_matches_found);

    if (FOUNDATIONAL_LIB_UNLIKELY(find_len == 0))
        goto no_matches;

    size_t matches;

    matches = 0;

    // Count the occurrences of 'find' in 'source'
    const char *p;

    p = (const char *)source;

    const char *end_of_memory;
    end_of_memory = (const char *)source + source_len;

    for (;;)
    {
        if ((p = (const char *)memory_locate((const void *)p, (end_of_memory - p), find, find_len)) == NULL)
            break;
        if (matches_max && matches == matches_max)
            break;

        ++matches;
        p += find_len;
    }

    // Let's assume that it's 'likely' to find a match.
    if (FOUNDATIONAL_LIB_UNLIKELY(matches == 0))
    {
    no_matches:
        *should_free_after_use = 0;
        *output_length_without_nullt = source_len;
        *output = source;
        return 0;
    }

    *should_free_after_use = 1;
    *num_matches_found = matches;

    size_t final_len = source_len - matches * find_len + matches * replace_len; // Overflow should not be an issue here.

    if (should_nullt)
    {
        ++final_len;
    }

    // Allocate memory for the replaced string
    char *result;

    result = (char *)FOUNDATIONAL_LIB_MEMORY_ALLOCATOR_MALLOC(final_len);
    if (FOUNDATIONAL_LIB_UNLIKELY(result == NULL))
    {
        goto memory_error;
    }
    *output_length_without_nullt = final_len;

    *output = result;

    // Perform the replacement
    char *rp;

    rp = result;

    p = (const char *)source;

    matches = 0;

    // If matches is 0, this is not run.
    for (matches = 0; !matches_max || (matches < matches_max); ++matches)
    {
        if ((p = (const char *)memory_locate((const void *)p, end_of_memory - p, find, find_len)) == NULL)
            break;

        if (matches_max && matches == matches_max)
            break;

        size_t prefix_len = p - (const char *)source;
        FOUNDATIONAL_LIB_MEMCPY(rp, source, prefix_len);
        rp += prefix_len;
        FOUNDATIONAL_LIB_MEMCPY(rp, replace, replace_len);
        rp += replace_len;
        p += find_len;
        source = (void *)p;
    }

    // Copy the remaining part of the source string
    size_t remaining_len;

    remaining_len = end_of_memory - (const char *)source;
    FOUNDATIONAL_LIB_MEMCPY(rp, source, remaining_len);

    if (should_nullt)
    {
        rp[remaining_len] = '\0';
    }

    return 0;

memory_error:
    *output = NULL;
    *output_length_without_nullt = 0;
    FOUNDATIONAL_LIB_die_aggressively_if_enabled();
    return -1;
}

/**
 * @brief Performs string replacement with specified lengths.
 *
 * This function replaces occurrences of the 'find' substring with the 'replace'
 * substring within the 'source' string. It operates on strings with explicitly
 * provided lengths to handle cases where null characters may be present in the
 * strings. It's designed to be more efficient than other string replace
 * functions but takes more arguments.
 *
 * 'output' is aliased to the original value, if so, there was no text replacement,
 * and no new memory was allocated. As such, there is no new memory that needs to be
 * freed().
 *
 *
 * @param source The original string to search and modify.
 * @param find The substring to be replaced.
 * @param replace The substring to replace 'find' with.
 * @param source_len The length of the 'source' string.
 * @param find_len The length of the 'find' substring.
 * @param replace_len The length of the 'replace' substring.
 * @param output A pointer to the new string resulting from the replacements.
 *        The caller is responsible for freeing the memory allocated for
 *        'output'.
 *
 *        If should_free_after_use is non-zero, a new dynamically allocated array with the replacements made.
 *        If should_free_after_use is zero, output aliases source, and they refer to the same memory.
 * @param should_free_after_use A pointer to a int indicating whether
 * @param num_matches A pointer to a variable to store the number of replacements made.
 * @param matches_max A pointer to the maximum number of replacements to make. If zero, there is no maximum.
 *
 * @return Returns 0 on success, -1 on failure.
 * @note This function is designed for performance but requires careful memory
 * management. Ensure that the caller frees the memory allocated for 'new_text' only when appropriate.
 *
 * @note For efficiency, null terminated strings are not checked. As such, the blocks of memory that are being replaced CAN contain null bytes.
 *       Internally, memmem() / memory_locate() is used to locate memory. See benchark_lib.c to see just how much FASTER this function can make things.
 *       It is likely optimized with platform specific code, making searches as fast as possible. It is much better to not have to
 *       constantly check for a null byte in every byte.
 *
 *       This function is just about the most powerful and most efficient memory replacement that you will find anywhere.
 */
FOUNDATIONAL_LIB_NONNULL FOUNDATIONAL_LIB_NOTHROW FOUNDATIONAL_LIB_FUNC int replace_all_with_lens(const char *source, size_t source_len, const char *find, size_t find_len, const char *replace, size_t replace_len, char **output, size_t *new_len, int *should_free_after_use, size_t matches_max, size_t *num_matches)
{
    /* replace_memory checks args if enabled. */
    return replace_memory((void *)source, source_len, (void *)find, find_len, (void *)replace, replace_len, (void **)output, new_len, should_free_after_use, matches_max, num_matches, 1);
}

/**
 * @brief Replaces all occurrences of a specified substring in a given string.
 *
 * This function takes an input string and replaces all occurrences of a
 * specified old substring with a new substring. The result is a modified string
 * with all instances of the old substring replaced by the new substring.
 *
 * @param str The input string in which replacements will be performed.
 * @param old_substring The substring to be replaced.
 * @param new_substring The substring that replaces the old substring.
 * @return Returns a dynamically allocated string containing the modified
 * result. The caller is responsible for freeing the memory when no longer
 * needed.
 */
FOUNDATIONAL_LIB_WARN_UNUSED_RESULT FOUNDATIONAL_LIB_NONNULL FOUNDATIONAL_LIB_NOTHROW FOUNDATIONAL_LIB_MALLOC FOUNDATIONAL_LIB_FUNC char *replace_all(const char *source, const char *find, const char *replace)
{
    /* replace_memory checks args if enabled. */

    size_t new_len;
    char *output;
    int should_free_after_use;
    size_t num_matches;
    const size_t matches_max = 0;

    if (replace_memory((void *)source, strlen(source), (void *)find, strlen(find), (void *)replace, strlen(replace), (void **)&output, &new_len, &should_free_after_use, matches_max, &num_matches, 1) == -1)
    {
        FOUNDATIONAL_LIB_die_aggressively_if_enabled();
        return NULL;
    }

    if (!should_free_after_use)
    {
        if (FOUNDATIONAL_LIB_UNLIKELY(new_len == SIZE_MAX))
        {
            FOUNDATIONAL_LIB_die_aggressively_if_enabled();
            return NULL;
        }

        char *new_output = (char *)FOUNDATIONAL_LIB_MEMORY_ALLOCATOR_MALLOC(new_len + 1); /* Safe. */
        memcpy(new_output, output, new_len + 1);                                          /* It was already null terminated */
        return new_output;
    }

    return output;
}

/**
 * @brief Replaces the first occurrence of a specified substring in a given string.
 *
 * This function takes an input string and replaces the first occurence of a
 * specified old substring with a new substring. The result is a modified string
 * with all instances of the old substring replaced by the new substring.
 *
 * @param str The input string in which replacements will be performed.
 * @param old_substring The substring to be replaced.
 * @param new_substring The substring that replaces the old substring.
 * @return Returns a dynamically allocated string containing the modified
 * result. The caller is responsible for freeing the memory when no longer
 * needed.
 */
FOUNDATIONAL_LIB_WARN_UNUSED_RESULT FOUNDATIONAL_LIB_NONNULL FOUNDATIONAL_LIB_NOTHROW FOUNDATIONAL_LIB_MALLOC FOUNDATIONAL_LIB_FUNC char *replace_first(const char *source, const char *find, const char *replace)
{
    /* replace_memory checks args if enabled. */

    size_t new_len;
    char *output;
    int should_free_after_use;
    size_t num_matches;
    const size_t matches_max = 1;

    if (replace_memory((void *)source, strlen(source), (void *)find, strlen(find), (void *)replace, strlen(replace), (void **)&output, &new_len, &should_free_after_use, matches_max, &num_matches, 1) == -1)
    {
        FOUNDATIONAL_LIB_die_aggressively_if_enabled();
        return NULL;
    }

    if (!should_free_after_use)
    {
        if (FOUNDATIONAL_LIB_UNLIKELY(new_len == SIZE_MAX))
        {
            FOUNDATIONAL_LIB_die_aggressively_if_enabled();
            return NULL;
        }

        char *new_output = (char *)FOUNDATIONAL_LIB_MEMORY_ALLOCATOR_MALLOC(new_len + 1); /* Safe. */
        memcpy(new_output, output, new_len + 1);                                          /* It was already null terminated */
        return new_output;
    }

    return output;
}

/**
 * @brief Replaces the first N occurrences of a specified substring in a given string.
 *
 * This function takes an input string and replaces the first N occurences of a
 * specified old substring with a new substring. The result is a modified string
 * with all instances of the old substring replaced by the new substring.
 *
 * @param str The input string in which replacements will be performed.
 * @param old_substring The substring to be replaced.
 * @param new_substring The substring that replaces the old substring.
 * @return Returns a dynamically allocated string containing the modified
 * result. The caller is responsible for freeing the memory when no longer
 * needed.
 */
FOUNDATIONAL_LIB_FUNC char *replace_count(const char *source, const char *find, const char *replace, const size_t matches_max)
{
    /* replace_memory checks args if enabled. */

    size_t new_len;
    char *output;
    int should_free_after_use;
    size_t num_matches;
    if (replace_memory((void *)source, strlen(source), (void *)find, strlen(find), (void *)replace, strlen(replace), (void **)&output, &new_len, &should_free_after_use, matches_max, &num_matches, 1) == -1)
    {
        FOUNDATIONAL_LIB_die_aggressively_if_enabled();
        return NULL;
    }

    if (!should_free_after_use)
    {
        if (FOUNDATIONAL_LIB_UNLIKELY(new_len == SIZE_MAX))
        {
            FOUNDATIONAL_LIB_die_aggressively_if_enabled();
            return NULL;
        }

        char *new_output = (char *)FOUNDATIONAL_LIB_MEMORY_ALLOCATOR_MALLOC(new_len + 1); /* Safe. */
        memcpy(new_output, output, new_len + 1);                                          /* It was already null terminated */
        return new_output;
    }

    return output;
}

/**
 * @brief Replaces all occurrences of a substring in a string using a callback function.
 *
 * This function searches for all occurrences of the specified substring in the given string
 * and replaces them by invoking a callback function. The callback function is responsible for
 * providing the replacement for each occurrence.
 *
 * @param str The input string to be processed.
 * @param old_substring The substring to be replaced.
 * @param callback A callback function that receives the matched substring and user data,
 *                 and returns a dynamically allocated replacement string.
 * @param data_for_callback User data to be passed to the callback function.
 *
 * @return A dynamically allocated string containing the result of the replacements.
 *         The caller is responsible for freeing the memory allocated for this string.
 *
 * @note The returned string must be freed by the caller using free() when it is no longer needed.
 */
FOUNDATIONAL_LIB_FUNC char *replace_all_with_callback(const char *str, const char *old_substring, char *(*callback)(const char *, void *), void *data_for_callback)
{
    FOUNDATIONAL_LIB_ASSERT_ARGUMENT_IF_ENABLED(str);
    FOUNDATIONAL_LIB_ASSERT_ARGUMENT_IF_ENABLED(old_substring);
    FOUNDATIONAL_LIB_ASSERT_ARGUMENT_IF_ENABLED(callback);

    const size_t str_len = strlen(str);
    const size_t old_substring_len = strlen(old_substring);
    size_t alloc_size = str_len + 1; // Start with the original string length + 1 for the null terminator

    // Allocate memory for the result string
    char *result = (char *)FOUNDATIONAL_LIB_MEMORY_ALLOCATOR_MALLOC(str_len);
    if (FOUNDATIONAL_LIB_UNLIKELY(result == NULL))
    {
        FOUNDATIONAL_LIB_die_aggressively_if_enabled();
        return NULL;
    }

    // Copy and replace substrings
    const char *pos = str;

    size_t new_len = 0;

    for (;;)
    {
        const char *found_pos = (const char *)memory_locate(pos, str_len - (pos - str), old_substring, old_substring_len);
        if (FOUNDATIONAL_LIB_UNLIKELY(found_pos == NULL))
        {
            size_t remaining_len = str_len - (pos - str);
            memcpy(result + new_len, pos, remaining_len);
            new_len += remaining_len;

            result[new_len] = '\0';

            new_len += remaining_len;
            break;
        }

        // Copy the segment

        char *replacement = callback(old_substring, data_for_callback);

        // Resize the result buffer if needed
        size_t replacement_len = strlen(replacement);

        size_t nlen;

        const size_t diff = found_pos - pos;

        if (FOUNDATIONAL_LIB_UNLIKELY(FOUNDATIONAL_LIB_safe_add_3_ptr(new_len, diff, replacement_len, &nlen) == 0))
        {
            goto overflow;
        }

        if (FOUNDATIONAL_LIB_UNLIKELY(nlen == SIZE_MAX))
            goto overflow;

        ++nlen;

        if (nlen >= alloc_size)
        {
            /* Makes it at least 1 bigger. */
            alloc_size = FOUNDATIONAL_LIB_REALLOC_REALLOCATION_ALGORITHM(nlen);
            char *new_result = (char *)FOUNDATIONAL_LIB_MEMORY_ALLOCATOR_REALLOC(result, alloc_size);
            if (FOUNDATIONAL_LIB_UNLIKELY(new_result == NULL))
            {
                FOUNDATIONAL_LIB_MEMORY_ALLOCATOR_FREE(replacement);
                goto error;
            }
            result = new_result;
        }

        memcpy(result + new_len, pos, found_pos - pos); /* Safe. */
        new_len += found_pos - pos;
        memcpy(result + new_len, replacement, replacement_len);
        FOUNDATIONAL_LIB_MEMORY_ALLOCATOR_FREE(replacement);
        new_len += replacement_len;
        pos = found_pos + old_substring_len;
    }

    return result;
overflow:

error:
    FOUNDATIONAL_LIB_MEMORY_ALLOCATOR_FREE(result);
    FOUNDATIONAL_LIB_die_aggressively_if_enabled();
    return NULL;
}

/**
 * @brief Duplicates a formatted string.
 *
 * This function duplicates a formatted string created using FOUNDATIONAL_LIB_PRINTF-style
 * formatting. It returns a dynamically allocated string containing the
 * formatted result. The caller is responsible for freeing the memory allocated
 * for the returned string using free().
 *
 * @param format  Pointer to the null-terminated format string.
 * @param ...     Variable arguments to be formatted into the string.
 * @return        Pointer to the dynamically allocated string containing the
 * formatted result. Returns NULL if there is an allocation error. The caller is
 * responsible for freeing the memory using free().
 */
FOUNDATIONAL_LIB_WARN_UNUSED_RESULT FOUNDATIONAL_LIB_NONNULL FOUNDATIONAL_LIB_PRINTF_FUNC FOUNDATIONAL_LIB_NOTHROW FOUNDATIONAL_LIB_MALLOC FOUNDATIONAL_LIB_FUNC char *dup_format(const char *format, ...)
{
    FOUNDATIONAL_LIB_ASSERT_ARGUMENT_IF_ENABLED(format);

    FOUNDATIONAL_LIB_VA_LIST args;
    FOUNDATIONAL_LIB_VA_START(args, format);

    /* Determine the length of the formatted string */
    const int len = FOUNDATIONAL_LIB_VSNPRINTF(NULL, 0, format, args);

    FOUNDATIONAL_LIB_VA_END(args);

    if (len == -1)
        goto memory_error;

    /* Would-be Overflow */
    if (FOUNDATIONAL_LIB_UNLIKELY(sizeof(int) >= sizeof(size_t) && (size_t)len == SIZE_MAX))
        goto memory_error;

    /* Allocate memory for the formatted string */
    char *result;

    result = (char *)FOUNDATIONAL_LIB_MEMORY_ALLOCATOR_MALLOC(len + sizeof("")); /* Safe */
    if (FOUNDATIONAL_LIB_UNLIKELY(result == NULL))
        goto memory_error;

    FOUNDATIONAL_LIB_VA_START(args, format);
    if (FOUNDATIONAL_LIB_VSNPRINTF(result, len + 1, format, args) == -1)
    {
        FOUNDATIONAL_LIB_MEMORY_ALLOCATOR_FREE(result);
        FOUNDATIONAL_LIB_VA_END(args);
        goto memory_error;
    }

    FOUNDATIONAL_LIB_VA_END(args);

    return result;

memory_error:
    FOUNDATIONAL_LIB_die_aggressively_if_enabled();
    return NULL;
}
/**
 * @brief Applies a transformation to each element of an integer array.
 *
 * This function applies a user-defined transformation to each element of the
 * input integer array and stores the results back in the array.
 *
 * @param array Pointer to the integer array to be transformed.
 * @param size Size of the array.
 * @param transform Pointer to the transformation function.
 *                 The function should take an integer as input and return
 *                 an integer as the transformed result.
 *
 * @note The input array is modified in place.
 * @note The user-defined transformation function should be provided as a
 * pointer.
 *
 * @code
 *   // Example transformation function: square the input
 *   int square_transform(int x) {
 *       return x * x;
 *   }
 *
 *   // Example usage:
 *   int my_array[] = {1, 2, 3, 4, 5};
 *   map_ints(my_array, 5, square_transform);
 *   // After the call, my_array will be {1, 4, 9, 16, 25}
 * @endcode
 */
FOUNDATIONAL_LIB_NONNULL FOUNDATIONAL_LIB_NOTHROW FOUNDATIONAL_LIB_FUNC void map_ints(int *array, size_t size, int (*transform)(int))
{
    FOUNDATIONAL_LIB_ASSERT_ARGUMENT_IF_ENABLED(array);
    FOUNDATIONAL_LIB_ASSERT_ARGUMENT_IF_ENABLED(transform);

    for (size_t i = 0; i < size; ++i)
    {
        array[i] = transform(array[i]);
    }
}

/**
 * @brief Performs a reduction on an integer array using a binary operation.
 *
 * This function applies a user-defined binary operation to reduce the elements
 * of the input integer array to a single result.
 *
 * @param array Pointer to the integer array to be reduced.
 * @param size Size of the array.
 * @param operation Pointer to the binary operation function.
 *                 The function should take two integers as input and return
 *                 an integer as the result of the binary operation.
 *
 * @return The result of the reduction operation.
 *
 * @note The reduction operation is performed from left to right.
 * @note The user-defined binary operation function should be provided as a
 * pointer.
 *
 * @code
 *   // Example binary operation function: addition
 *   int add_operation(int x, int y) {
 *       return x + y;
 *   }
 *
 *   // Example usage:
 *   int my_array[] = {1, 2, 3, 4, 5};
 *   int result = reduce_ints(my_array, 5, add_operation);
 *   // After the call, result will be the sum of elements: 1 + 2 + 3 + 4 + 5 =
 * 15
 * @endcode
 */
FOUNDATIONAL_LIB_WARN_UNUSED_RESULT FOUNDATIONAL_LIB_NONNULL FOUNDATIONAL_LIB_NOTHROW FOUNDATIONAL_LIB_FUNC int reduce_ints(int *array, size_t size, int (*operation)(int, int))
{
    FOUNDATIONAL_LIB_ASSERT_ARGUMENT_IF_ENABLED(array);
    FOUNDATIONAL_LIB_ASSERT_ARGUMENT_IF_ENABLED(operation);

    int result = array[0];
    for (size_t i = 1; i < size; ++i)
    {
        result = operation(result, array[i]);
    }
    return result;
}

/**
 * @brief Filters elements of an integer array based on a specified condition.
 *
 * This function applies a user-defined condition to filter elements from the
 * source integer array and stores the filtered elements in the destination
 * array.
 *
 * @param source Pointer to the source integer array to be filtered.
 * @param source_size Size of the source array.
 * @param destination Pointer to the destination array to store filtered
 * elements.
 * @param condition Pointer to the condition function.
 *                 The function should take an integer as input and return
 *                 a boolean (int) indicating whether the element satisfies the
 * condition.
 *
 * @return The number of elements that satisfy the condition and are stored in
 * the destination array.
 *
 * @note The destination array should have sufficient space to accommodate
 * filtered elements.
 * @note The user-defined condition function should be provided as a pointer.
 *
 * @code
 *   // Example condition function: check if the element is even
 *   int is_even_condition(int x) {
 *       return (x % 2 == 0);
 *   }
 *
 *   // Example usage:
 *   int my_array[] = {1, 2, 3, 4, 5};
 *   int filtered_array[5]; // Assuming the worst case where all elements
 * satisfy the condition size_t num_filtered = filter_ints(my_array, 5,
 * filtered_array, is_even_condition);
 *   // After the call, filtered_array will contain {2, 4}, and num_filtered
 * will be 2
 * @endcode
 */
FOUNDATIONAL_LIB_WARN_UNUSED_RESULT FOUNDATIONAL_LIB_NONNULL FOUNDATIONAL_LIB_NOTHROW FOUNDATIONAL_LIB_FUNC int filter_ints(int *source, size_t source_size, int *destination, int (*condition)(int))
{

    FOUNDATIONAL_LIB_ASSERT_ARGUMENT_IF_ENABLED(source);
    FOUNDATIONAL_LIB_ASSERT_ARGUMENT_IF_ENABLED(destination);
    FOUNDATIONAL_LIB_ASSERT_ARGUMENT_IF_ENABLED(condition);

    size_t count = 0;
    for (size_t i = 0; i < source_size; ++i)
    {
        if (condition(source[i]))
        {
            destination[count++] = source[i];
        }
    }
    return count;
}

/**
 * @brief Applies a transformation to each element of an array (void* version).
 *
 * This function applies a user-defined transformation to each element of the
 * input array with support for generic data types using void pointers.
 *
 * @param array Pointer to the array to be transformed.
 * @param size Size of the array.
 * @param elem_size Size of each element in bytes.
 * @param transform Pointer to the transformation function.
 *                 The function should take a void pointer as input, which
 * points to an individual element in the array.
 *
 * @note The input array is modified in place.
 * @note The user-defined transformation function should be provided as a
 * pointer.
 *
 * @code
 *   // Example transformation function: increment an integer element
 *   void increment_transform(void *element) {
 *       (*(int *)element)++;
 *   }
 *
 *   // Example usage:
 *   int my_array[] = {1, 2, 3, 4, 5};
 *   map(my_array, 5, sizeof(int), increment_transform);
 *   // After the call, my_array will be {2, 3, 4, 5, 6}
 * @endcode
 */
FOUNDATIONAL_LIB_NONNULL FOUNDATIONAL_LIB_NOTHROW FOUNDATIONAL_LIB_FUNC void map(void *array, size_t size, size_t elem_size, void (*transform)(void *))
{

    FOUNDATIONAL_LIB_ASSERT_ARGUMENT_IF_ENABLED(array);
    FOUNDATIONAL_LIB_ASSERT_ARGUMENT_IF_ENABLED(transform);

    for (size_t i = 0; i < size; ++i)
    {
        transform(((char *)array) + i * elem_size);
    }
}

/**
 * @brief Performs a reduction on an array (void* version) using a binary
 * operation.
 *
 * This function applies a user-defined binary operation to reduce the elements
 * of the input array with support for generic data types using void pointers.
 *
 * @param array Pointer to the array to be reduced.
 * @param size Size of the array.
 * @param elem_size Size of each element in bytes.
 * @param result Pointer to the memory location to store the result of the
 * reduction.
 * @param operation Pointer to the binary operation function.
 *                 The function should take two void pointers as input, which
 * point to individual elements in the array, and update the result.
 *
 * @note The reduction operation is performed from left to right.
 * @note The user-defined binary operation function should be provided as a
 * pointer.
 *
 * @code
 *   // Example binary operation function: sum two integer elements
 *   void sum_operation(void *element1, void *element2) {
 *       (*(int *)element1) += (*(int *)element2);
 *   }
 *
 *   // Example usage:
 *   int my_array[] = {1, 2, 3, 4, 5};
 *   int result = 0;
 *   reduce(my_array, 5, sizeof(int), &result, sum_operation);
 *   // After the call, result will be the sum of elements: 1 + 2 + 3 + 4 + 5 =
 * 15
 * @endcode
 */
FOUNDATIONAL_LIB_NONNULL FOUNDATIONAL_LIB_NOTHROW FOUNDATIONAL_LIB_FUNC void reduce(void *array, size_t size, size_t elem_size, void *result, void (*operation)(void *, void *))
{
    FOUNDATIONAL_LIB_ASSERT_ARGUMENT_IF_ENABLED(array);
    FOUNDATIONAL_LIB_ASSERT_ARGUMENT_IF_ENABLED(result);
    FOUNDATIONAL_LIB_ASSERT_ARGUMENT_IF_ENABLED(operation);

    char *char_array = (char *)array;
    char *char_result = (char *)result;

    /* Initialize the result with the first element */
    for (size_t i = 0; i < elem_size; ++i)
    {
        char_result[i] = char_array[i];
    }

    for (size_t i = 1; i < size; ++i)
    {
        operation(char_result, char_array + i * elem_size);
    }
}

// filter_data() to avoid conflicts with curses

/**
 * @brief Filters elements of an array (void* version) based on a specified
 * condition.
 *
 * This function applies a user-defined condition to filter elements from the
 * source array with support for generic data types using void pointers.
 * The filtered elements are stored in the destination array.
 *
 * @param source Pointer to the source array to be filtered.
 * @param source_size Size of the source array.
 * @param elem_size Size of each element in bytes.
 * @param destination Pointer to the destination array to store filtered
 * elements.
 * @param dest_size Size of the destination array.
 * @param condition Pointer to the condition function.
 *                 The function should take a void pointer as input, which
 * points to an individual element in the source array, and return an integer
 * (boolean) indicating whether the element satisfies the condition.
 *
 * @return The number of elements that satisfy the condition and are stored in
 * the destination array.
 *
 * @note The destination array should have sufficient space to accommodate
 * filtered elements.
 * @note The user-defined condition function should be provided as a pointer.
 *
 * @code
 *   // Example condition function: check if the integer element is even
 *   int is_even_condition(void *element) {
 *       return (*(int *)element % 2 == 0);
 *   }
 *
 *   // Example usage:
 *   int my_array[] = {1, 2, 3, 4, 5};
 *   int filtered_array[5]; // Assuming the worst case where all elements
 * satisfy the condition size_t num_filtered = filter_data(my_array, 5, sizeof(int),
 * filtered_array, 5, is_even_condition);
 *   // After the call, filtered_array will contain {2, 4}, and num_filtered
 * will be 2
 * @endcode
 */
FOUNDATIONAL_LIB_WARN_UNUSED_RESULT FOUNDATIONAL_LIB_NONNULL FOUNDATIONAL_LIB_NOTHROW FOUNDATIONAL_LIB_FUNC size_t filter_data(void *source, size_t source_size, size_t elem_size, void *destination, size_t dest_size, int (*condition)(void *))
{
    FOUNDATIONAL_LIB_ASSERT_ARGUMENT_IF_ENABLED(source);
    FOUNDATIONAL_LIB_ASSERT_ARGUMENT_IF_ENABLED(destination);
    FOUNDATIONAL_LIB_ASSERT_ARGUMENT_IF_ENABLED(condition);

    char *char_source = (char *)source;
    char *char_destination = (char *)destination;

    size_t count = 0;
    for (size_t i = 0; i < source_size; ++i)
    {
        if (condition(char_source + i * elem_size))
        {
            if (count < dest_size)
            {
                for (size_t j = 0; j < elem_size; ++j)
                {
                    char_destination[count * elem_size + j] = char_source[i * elem_size + j];
                }
            }

            ++count;
        }
    }
    return count;
}

/**
 * @brief Perform a list comprehension operation.
 *
 * This function applies a transformation function and a filter function to each
 * element of the input array, creating a new array as a result.
 *
 * @param input_array Pointer to the input array.
 * @param array_size Size of the input array.
 * @param elem_size Size of each element in the array.
 * @param transform_func Pointer to the transformation function applied to each
 * element.
 * @param filter_func Pointer to the filter function determining inclusion in
 * the result.
 * @param result_size Pointer to store the size of the resulting array.
 * @return Pointer to the dynamically allocated result array. Make sure to
 * free() after.
 *
 * @details
 * The list_comprehension function performs a list comprehension operation on
 * the input array. It applies the provided transformation and filter functions
 * to each element of the array, creating a new array containing only the
 * elements that pass the filter condition.
 *
 * The transformation function is applied to each element to derive a modified
 * value, and the filter function determines whether an element should be
 * included in the result array.
 *
 * @note
 * The input_array is expected to contain homogeneous elements, and the
 * transform_func and filter_func should be designed accordingly.
 *
 * @warning
 * The resulting array is dynamically allocated and should be freed by the
 * caller using the free() function to avoid memory leaks.
 *
 * @see list_comprehension_multithreaded for a version of this function
 * optimized for multi-threaded execution.
 *
 * @param example_usage Example Usage:
 * @code
 * // Example Usage 1: Transform each element to its square and filter out even
 * numbers size_t input[] = {1, 2, 3, 4, 5, 6, 7, 8, 9}; size_t input_size =
 * sizeof(input) / sizeof(input[0]);
 *
 * // Transformation function: Square each element
 * void square_transform(void *value) {
 *     size_t *num = (size_t *)value;
 *     *num = (*num) * (*num);
 * }
 *
 * // Filter function: Include only odd numbers
 * int odd_filter(void *value) {
 *     size_t *num = (size_t *)value;
 *     return (*num) % 2 != 0;
 * }
 *
 * size_t result_size;
 * size_t *result = (size_t *)list_comprehension(input, input_size,
 * sizeof(size_t), square_transform, odd_filter, &result_size);
 * // Use the result array
 * free(result);
 * @endcode
 * @code
 * // Example Usage 2: Transform each string to uppercase and filter out those
 * starting with 'a' const char *words[] = {"apple", "banana", "orange",
 * "grape", "kiwi"}; size_t words_size = sizeof(words) / sizeof(words[0]);
 *
 * // Transformation function: Convert string to uppercase
 * void uppercase_transform(void *value) {
 *     char **str = (char **)value;
 *     for (int i = 0; (*str)[i]; ++i) {
 *         (*str)[i] = toupper((*str)[i]);
 *     }
 * }
 *
 * // Filter function: Exclude strings starting with 'a'
 * int exclude_a_filter(void *value) {
 *     char **str = (char **)value;
 *     return (*str)[0] != 'a' && (*str)[0] != 'A';
 * }
 *
 * size_t result_size;
 * char **result = (char **)list_comprehension(words, words_size, sizeof(char
 * *), uppercase_transform, exclude_a_filter, &result_size);
 * // Use the result array
 * free(result);
 * @endcode
 */
FOUNDATIONAL_LIB_WARN_UNUSED_RESULT FOUNDATIONAL_LIB_NONNULL FOUNDATIONAL_LIB_NOTHROW FOUNDATIONAL_LIB_FUNC void *list_comprehension(const void *input_array, size_t array_size, size_t elem_size, void (*transform_func)(void *value), int (*filter_func)(void *value), size_t *result_size)
{
    FOUNDATIONAL_LIB_ASSERT_ARGUMENT_IF_ENABLED(input_array);
    FOUNDATIONAL_LIB_ASSERT_ARGUMENT_IF_ENABLED(transform_func);
    FOUNDATIONAL_LIB_ASSERT_ARGUMENT_IF_ENABLED(filter_func);

    FOUNDATIONAL_LIB_ASSERT_ARGUMENT_IF_ENABLED(result_size);

    // Set result size to 0 first thing.
    *result_size = 0;

    const size_t alloc_size = FOUNDATIONAL_LIB_safe_mul(array_size, elem_size);

    if (FOUNDATIONAL_LIB_UNLIKELY(alloc_size == 0))
    {
        /* Handle overflow error. */
        FOUNDATIONAL_LIB_die_aggressively_if_enabled();
        return NULL;
    }

    /* Allocate memory for the result array */
    void *result = FOUNDATIONAL_LIB_MEMORY_ALLOCATOR_MALLOC(alloc_size);

    if (FOUNDATIONAL_LIB_UNLIKELY(result == NULL))
    {
        /* Handle memory allocation error */
        FOUNDATIONAL_LIB_die_aggressively_if_enabled();
        return NULL;
    }

    /* Iterate through the input array */
    for (size_t i = 0; i < array_size; ++i)
    {
        /* Apply the filter function */

        // Assume that there cannot be an overflow error
        // because iterating through a size_t array from 0.
        if (filter_func((void *)((char *)input_array + i * elem_size)))
        {
            /* Apply the transformation function */

            void *addr = (char *)result + (*result_size) * elem_size;
            FOUNDATIONAL_LIB_MEMCPY(addr, (char *)input_array + (i * elem_size), elem_size); /* Safe. */
            transform_func(addr);
            ++(*result_size);
        }
    }

    // We need this so that gcc with -std=c11 under mingw32 doesn't give a
    // warning about memory possibly being accessed after freeing()
    // This only seems to happen with mingw32, and is a bug in it.
    // I included a relevant ISO/IEC statement about realloc in this file.
    //
    // This code has no bug.

    /*
     * Make the result smaller to free a bit of memory. Not necessary, but it saves memory.
     * array_size * (*result_size) will not be larger than the current size.
     *
     * Dont do safe mul here because this should be smaller than current amounts.
     */
    char *new_result = (char *)FOUNDATIONAL_LIB_MEMORY_ALLOCATOR_REALLOC(result, array_size * (*result_size)); /* Safe. */

    if (FOUNDATIONAL_LIB_UNLIKELY(new_result == NULL))
    {
        FOUNDATIONAL_LIB_die_aggressively_if_enabled();
        return result;
    }

    /*
    ISO/IEC 9899:2011:

    "If memory for the new object cannot be allocated,
    the old object is not deallocated and its value is unchanged."
    */

    return new_result;
}

/* For Set */
struct SetKey
{
    char *key;
    struct SetKey *next;
};

struct Dict
{
    struct DictKeyValue **table;
    size_t capacity;
    size_t size;
};

struct Set
{
    struct SetKey **table;
    size_t capacity;
    size_t size;
};

/**  Dict */
struct DictKeyValue
{
    char *key;
    void *value;
    struct DictKeyValue *next;
};
/* FrozenDict struct */
struct FrozenDict
{
    struct DictKeyValue **table;
    size_t capacity;
    size_t size;
};

/* FrozenSet struct. */
struct FrozenSet
{
    struct SetKey **table;
    size_t capacity;
    size_t size;
};

/* Sets */
typedef struct FrozenSet FrozenSet;
typedef struct Set Set;

/* Dicts */
typedef struct Dict Dict;
typedef struct FrozenDict FrozenDict;

#if FOUNDATIONAL_LIB_THREAD_FUNCTIONS_ENABLED
#include <threads.h>

// Define a structure to hold thread-specific data
struct ThreadData
{
    const void *input_array;
    size_t array_size;
    size_t elem_size;
    void (*transform_func)(void *value);
    int (*filter_func)(void *value);
    size_t *result_size;
    void *result;
    size_t start_index;
    size_t end_index;
};

/*
 * Define the worker function for each thread, as used by
 * list_comprehension_multithreaded()
 */
FOUNDATIONAL_LIB_WARN_UNUSED_RESULT FOUNDATIONAL_LIB_NONNULL FOUNDATIONAL_LIB_NOTHROW FOUNDATIONAL_LIB_FUNC int FOUNDATIONAL_LIB_list_comprehension_worker(void *data)
{
    FOUNDATIONAL_LIB_ASSERT_ARGUMENT_IF_ENABLED(data);
    struct ThreadData *thread_data = (struct ThreadData *)data;
    *thread_data->result_size = 0;

    const size_t subtraction = (thread_data->end_index - thread_data->start_index);

    const size_t mul = FOUNDATIONAL_LIB_safe_mul(thread_data->elem_size, subtraction);

    if (FOUNDATIONAL_LIB_UNLIKELY(mul == 0)) // Overflow
    {
        FOUNDATIONAL_LIB_die_aggressively_if_enabled();
        return -1;
    }

    void *buffer = FOUNDATIONAL_LIB_MEMORY_ALLOCATOR_MALLOC(mul);

    if (FOUNDATIONAL_LIB_UNLIKELY(buffer == NULL))
    {
        FOUNDATIONAL_LIB_die_aggressively_if_enabled();
        return -1;
    }

    // Iterate through the assigned chunk of the input array

    // Start index and end index should be valid indices and no possiblity
    // for overflow error.
    for (size_t i = thread_data->start_index; i < thread_data->end_index; ++i)
    {
        // Apply the filter function
        if (thread_data->filter_func((void *)((char *)thread_data->input_array + i * thread_data->elem_size)))
        {
            // Copy the value to the result array
            FOUNDATIONAL_LIB_MEMCPY((char *)buffer + (*thread_data->result_size) * thread_data->elem_size, (char *)thread_data->input_array + i * thread_data->elem_size, thread_data->elem_size); /* Safe. */

            ++(*thread_data->result_size);
        }
    }

    // Apply the transformation function to the entire result chunk
    for (size_t i = 0; i < (*thread_data->result_size); ++i)
    {
        thread_data->transform_func((void *)((char *)buffer + i * thread_data->elem_size));
    }

    thread_data->result = buffer;
    return 0;
}

/**
 *  Perform a list comprehension operation in a multithreaded fashion.
 *
 * This function applies a transformation function and a filter function to each
 * element of the input array, creating a new array as a result.
 *
 * @param input_array Pointer to the input array.
 * @param array_size Size of the input array.
 * @param elem_size Size of each element in the array.
 * @param transform_func Pointer to the transformation function applied to each
 * element.
 * @param filter_func Pointer to the filter function determining inclusion in
 * the result.
 * @param result_size Pointer to store the size of the resulting array.
 * @param thread_count Number of threads to use for parallel processing.
 * @return Pointer to the dynamically allocated result array. Make sure to
 * free() after.
 */
FOUNDATIONAL_LIB_WARN_UNUSED_RESULT FOUNDATIONAL_LIB_NONNULL FOUNDATIONAL_LIB_NOTHROW FOUNDATIONAL_LIB_FUNC void *list_comprehension_multithreaded(const void *input_array, size_t array_size, size_t elem_size, void (*transform_func)(void *value), int (*filter_func)(void *value), size_t *result_size, size_t thread_count)
{
    FOUNDATIONAL_LIB_ASSERT_ARGUMENT_IF_ENABLED(input_array);
    FOUNDATIONAL_LIB_ASSERT_ARGUMENT_IF_ENABLED(transform_func);
    FOUNDATIONAL_LIB_ASSERT_ARGUMENT_IF_ENABLED(filter_func);
    FOUNDATIONAL_LIB_ASSERT_ARGUMENT_IF_ENABLED(result_size);

    if (FOUNDATIONAL_LIB_UNLIKELY(thread_count == 0))
    {
        // This doesn't make sense, so assume they mean 1.
        thread_count = 1;
    }

    // Set result size to 0 first thing.
    *result_size = 0;

    const size_t alloc_size_for_result = FOUNDATIONAL_LIB_safe_mul(array_size, elem_size);

    if (FOUNDATIONAL_LIB_UNLIKELY(alloc_size_for_result == 0))
    {
        /* Handle overflow error. */
        FOUNDATIONAL_LIB_die_aggressively_if_enabled();
        return NULL;
    }

    /* Allocate memory for the result array */
    void *result = FOUNDATIONAL_LIB_MEMORY_ALLOCATOR_MALLOC(alloc_size_for_result);

    if (FOUNDATIONAL_LIB_UNLIKELY(result == NULL))
    {
        /* Handle memory allocation error */
        FOUNDATIONAL_LIB_die_aggressively_if_enabled();
        return NULL;
    }

    /* Allocate memory for result sizes */

    const size_t alloc_size_for_thread_result_sizes = FOUNDATIONAL_LIB_safe_mul(thread_count, sizeof(size_t));
    if (FOUNDATIONAL_LIB_UNLIKELY(alloc_size_for_thread_result_sizes == 0))
    {
        /* Handle overflow error. */
        FOUNDATIONAL_LIB_MEMORY_ALLOCATOR_FREE(result);
        FOUNDATIONAL_LIB_die_aggressively_if_enabled();
        return NULL;
    }

    size_t *thread_result_sizes = (size_t *)FOUNDATIONAL_LIB_MEMORY_ALLOCATOR_MALLOC(alloc_size_for_thread_result_sizes);
    if (FOUNDATIONAL_LIB_UNLIKELY(thread_result_sizes == NULL))
    {
        // Handle memory allocation error
        FOUNDATIONAL_LIB_MEMORY_ALLOCATOR_FREE(result);
        FOUNDATIONAL_LIB_die_aggressively_if_enabled();
        return NULL;
    }

    const size_t alloc_size_for_threads = FOUNDATIONAL_LIB_safe_mul(thread_count, sizeof(thrd_t));
    if (FOUNDATIONAL_LIB_UNLIKELY(alloc_size_for_threads == 0))
    {
        /* Handle overflow error. */
        FOUNDATIONAL_LIB_MEMORY_ALLOCATOR_FREE(result);
        FOUNDATIONAL_LIB_MEMORY_ALLOCATOR_FREE(thread_result_sizes);
        FOUNDATIONAL_LIB_die_aggressively_if_enabled();
        return NULL;
    }

    // Initialize thread data
    thrd_t *threads = (thrd_t *)FOUNDATIONAL_LIB_MEMORY_ALLOCATOR_MALLOC(alloc_size_for_threads);
    if (FOUNDATIONAL_LIB_UNLIKELY(threads == NULL))
    {
        // Handle memory allocation error
        FOUNDATIONAL_LIB_MEMORY_ALLOCATOR_FREE(result);
        FOUNDATIONAL_LIB_MEMORY_ALLOCATOR_FREE(thread_result_sizes);
        FOUNDATIONAL_LIB_die_aggressively_if_enabled();
        return NULL;
    }
    const size_t alloc_size_for_thread_data = FOUNDATIONAL_LIB_safe_mul(thread_count, sizeof(struct ThreadData));
    if (FOUNDATIONAL_LIB_UNLIKELY(alloc_size_for_thread_data == 0))
    {
        /* Handle overflow error. */
        FOUNDATIONAL_LIB_MEMORY_ALLOCATOR_FREE(result);
        FOUNDATIONAL_LIB_MEMORY_ALLOCATOR_FREE(thread_result_sizes);
        FOUNDATIONAL_LIB_die_aggressively_if_enabled();
        return NULL;
    }
    struct ThreadData *thread_data = (struct ThreadData *)FOUNDATIONAL_LIB_MEMORY_ALLOCATOR_MALLOC(alloc_size_for_thread_data);
    if (FOUNDATIONAL_LIB_UNLIKELY(thread_data == NULL))
    {
    cannot_allocate_or_create:
        FOUNDATIONAL_LIB_MEMORY_ALLOCATOR_FREE(result);
        FOUNDATIONAL_LIB_MEMORY_ALLOCATOR_FREE(thread_result_sizes);

        FOUNDATIONAL_LIB_MEMORY_ALLOCATOR_FREE(threads);

        FOUNDATIONAL_LIB_die_aggressively_if_enabled();
        return NULL;
    }

    // Divide the input array into chunks for each thread
    size_t chunk_size = array_size / thread_count;
    size_t remaining = array_size % thread_count;
    size_t current_index = 0;

    for (size_t i = 0; i < thread_count; ++i)
    {
        size_t e_index;
        const size_t ret = FOUNDATIONAL_LIB_safe_add_3_ptr(current_index, chunk_size, (remaining > 0 ? 1 : 0), &e_index);

        if (FOUNDATIONAL_LIB_UNLIKELY(ret == 0))
            goto cannot_allocate_or_create; // Overflow

        thread_data[i].input_array = input_array;
        thread_data[i].array_size = array_size;
        thread_data[i].elem_size = elem_size;
        thread_data[i].transform_func = transform_func;
        thread_data[i].filter_func = filter_func;
        thread_data[i].result_size = &thread_result_sizes[i];
        thread_data[i].result = result;
        thread_data[i].start_index = current_index;
        thread_data[i].end_index = e_index;

        if (remaining > 0)
        {
            --remaining;
        }

        current_index = thread_data[i].end_index;

        // Create a thread for each chunk
        if (FOUNDATIONAL_LIB_UNLIKELY(thrd_create(&threads[i], FOUNDATIONAL_LIB_list_comprehension_worker, (void *)&thread_data[i]) != thrd_success))
            goto cannot_allocate_or_create;
    }

    // Wait for all threads to finish
    for (size_t i = 0; i < thread_count; ++i)
    {
        int return_value_of_thread;
        thrd_join(threads[i], &return_value_of_thread);

        // The thread failed.
        if (FOUNDATIONAL_LIB_UNLIKELY(return_value_of_thread == -1))
            goto cannot_allocate_or_create;
    }
    // Calculate the total result size
    size_t total_result_size = 0;
    for (size_t i = 0; i < thread_count; ++i)
    {
        FOUNDATIONAL_LIB_MEMCPY((char *)result + total_result_size * elem_size, thread_data[i].result, thread_result_sizes[i] * elem_size); /* Safe. */
        FOUNDATIONAL_LIB_MEMORY_ALLOCATOR_FREE(thread_data[i].result);

        // Should always be <= SIZE_MAX
        total_result_size += thread_result_sizes[i];
    }

    // Update the final result size
    *result_size = total_result_size;

    FOUNDATIONAL_LIB_MEMORY_ALLOCATOR_FREE(thread_result_sizes);
    FOUNDATIONAL_LIB_MEMORY_ALLOCATOR_FREE(thread_data);
    FOUNDATIONAL_LIB_MEMORY_ALLOCATOR_FREE(threads);

    return result;
}

#endif

/**
 *  Filters elements from an array based on a specified condition.
 *
 * This function creates a new array by rejecting elements from the source array
 * that do not satisfy the given condition.
 *
 * @param source      Pointer to the source array.
 * @param source_size Size of the source array.
 * @param elem_size   Size of each element in the array.
 * @param condition   Pointer to the condition function.
 *                    The function should return a non-zero value for elements
 * to be rejected.
 * @param result_size Pointer to a variable to store the size of the resulting
 * array.
 *
 * @return Pointer to the newly allocated array containing filtered elements.
 *         It is the responsibility of the caller to free the memory when done.
 */
FOUNDATIONAL_LIB_WARN_UNUSED_RESULT FOUNDATIONAL_LIB_NONNULL FOUNDATIONAL_LIB_NOTHROW FOUNDATIONAL_LIB_FUNC void *reject_array(const void *source, size_t source_size, size_t elem_size, int (*condition)(const void *), size_t *result_size)
{

    FOUNDATIONAL_LIB_ASSERT_ARGUMENT_IF_ENABLED(source);
    FOUNDATIONAL_LIB_ASSERT_ARGUMENT_IF_ENABLED(condition);

    FOUNDATIONAL_LIB_ASSERT_ARGUMENT_IF_ENABLED(result_size);
    *result_size = 0;
    /* Allocate memory for the result array */

    const size_t mul = FOUNDATIONAL_LIB_safe_mul(source_size, elem_size);
    if (FOUNDATIONAL_LIB_UNLIKELY(mul == 0))
    {
        FOUNDATIONAL_LIB_die_aggressively_if_enabled();
        return NULL;
    }

    void *result = FOUNDATIONAL_LIB_MEMORY_ALLOCATOR_MALLOC(mul);
    if (FOUNDATIONAL_LIB_UNLIKELY(result == NULL))
    {
        FOUNDATIONAL_LIB_die_aggressively_if_enabled();
        return NULL;
    }

    size_t result_index = 0;

    /* Apply the rejection condition to each element */
    for (size_t i = 0; i < source_size; ++i)
    {
        // Should be a valid index if passed a valid argument.
        const void *current_source = (char *)source + i * elem_size;

        /* Check condition */
        if (!condition(current_source))
        {
            void *current_result = (char *)result + result_index * elem_size;
            FOUNDATIONAL_LIB_MEMCPY(current_result, current_source, elem_size);
            result_index++;
        }
    }

    /* Set the result size */
    *result_size = result_index;

    return result;
}

/**
 *  Filters elements from an array based on a specified condition.
 *
 * This function creates a new array by selecting elements from the source array
 * that satisfy the given condition.
 *
 * @param source      Pointer to the source array.
 * @param source_size Size of the source array.
 * @param elem_size   Size of each element in the array.
 * @param condition   Pointer to the condition function.
 *                    The function should return a non-zero value for elements
 * to be selected.
 * @param result_size Pointer to a variable to store the size of the resulting
 * array.
 *
 * @return Pointer to the newly allocated array containing selected elements.
 *         It is the responsibility of the caller to free the memory when done.
 */
FOUNDATIONAL_LIB_WARN_UNUSED_RESULT FOUNDATIONAL_LIB_NONNULL FOUNDATIONAL_LIB_NOTHROW FOUNDATIONAL_LIB_FUNC void *select_array(const void *source, size_t source_size, size_t elem_size, int (*condition)(const void *), size_t *result_size)
{

    FOUNDATIONAL_LIB_ASSERT_ARGUMENT_IF_ENABLED(source);

    FOUNDATIONAL_LIB_ASSERT_ARGUMENT_IF_ENABLED(condition);
    FOUNDATIONAL_LIB_ASSERT_ARGUMENT_IF_ENABLED(result_size);

    *result_size = 0;
    /* Allocate memory for the result array */

    const size_t mul = FOUNDATIONAL_LIB_safe_mul(source_size, elem_size);
    if (FOUNDATIONAL_LIB_UNLIKELY(mul == 0))
    {
        FOUNDATIONAL_LIB_die_aggressively_if_enabled();
        return NULL;
    }

    void *result = FOUNDATIONAL_LIB_MEMORY_ALLOCATOR_MALLOC(mul);
    if (FOUNDATIONAL_LIB_UNLIKELY(result == NULL))
    {
        FOUNDATIONAL_LIB_die_aggressively_if_enabled();
        return NULL;
    }

    size_t result_index = 0;

    /* Apply the selection condition to each element */
    for (size_t i = 0; i < source_size; ++i)
    {
        const void *current_source = (char *)source + i * elem_size;

        /* Check condition */
        if (condition(current_source))
        {
            void *current_result = (char *)result + result_index * elem_size;
            FOUNDATIONAL_LIB_MEMCPY(current_result, current_source, elem_size);
            ++result_index;
        }
    }

    /* Set the result size */
    *result_size = result_index;

    return result;
}

/**
 *  Replicates an array a specified number of times.
 *
 * This function creates a new array by replicating the elements of the source
 * array a given number of times.
 *
 * @param source       Pointer to the source array.
 * @param source_size  Size of the source array.
 * @param elem_size    Size of each element in the array.
 * @param repetitions  Number of times to replicate the array.
 *
 * @return Pointer to the newly allocated array containing replicated elements
 * or NULL on error. It is the responsibility of the caller to free the memory
 * when done.
 */
FOUNDATIONAL_LIB_WARN_UNUSED_RESULT FOUNDATIONAL_LIB_NONNULL FOUNDATIONAL_LIB_NOTHROW FOUNDATIONAL_LIB_MALLOC FOUNDATIONAL_LIB_FUNC void *replicate(const void *source, size_t source_size, size_t elem_size, size_t repetitions)
{

    FOUNDATIONAL_LIB_ASSERT_ARGUMENT_IF_ENABLED(source);

    /* elem_size * source_size * repetitions */

    const size_t elem_times_source = FOUNDATIONAL_LIB_safe_mul(elem_size, source_size);
    if (FOUNDATIONAL_LIB_UNLIKELY(elem_times_source == 0))
    {
        FOUNDATIONAL_LIB_die_aggressively_if_enabled();
        return NULL;
    }

    const size_t result_total_size = FOUNDATIONAL_LIB_safe_mul(elem_times_source, repetitions);
    if (FOUNDATIONAL_LIB_UNLIKELY(result_total_size == 0))
    {
        FOUNDATIONAL_LIB_die_aggressively_if_enabled();
        return NULL;
    }

    /* Allocate memory for the result array */
    void *result = FOUNDATIONAL_LIB_MEMORY_ALLOCATOR_MALLOC(result_total_size);
    if (FOUNDATIONAL_LIB_UNLIKELY(result == NULL))
    {
        FOUNDATIONAL_LIB_die_aggressively_if_enabled();
        return NULL;
    }

    /* Copy the source array to the result array multiple times */
    for (size_t i = 0; i < repetitions; ++i)
    {
        // Counting from zero so it should not be an overflow.
        FOUNDATIONAL_LIB_MEMCPY((char *)result + (i * elem_times_source), source, elem_times_source); /* Safe. */
    }

    return result;
}

/**
 * @brief Convert a string to lowercase.
 *
 * This function takes a null-terminated string as input and converts all its
 * characters to lowercase. The resulting lowercase string is allocated
 * dynamically and returned. It is the caller's responsibility to free the
 * memory allocated for the new string.
 *
 * @param str The input string to be converted to lowercase.
 *
 * @return A pointer to the newly allocated lowercase string, or NULL if memory
 * allocation fails. Make sure to free the memory using free() when done with
 * the returned string.
 */
FOUNDATIONAL_LIB_WARN_UNUSED_RESULT FOUNDATIONAL_LIB_NONNULL FOUNDATIONAL_LIB_NOTHROW FOUNDATIONAL_LIB_MALLOC FOUNDATIONAL_LIB_FUNC char *string_to_lowercase(char *string)
{

    FOUNDATIONAL_LIB_ASSERT_ARGUMENT_IF_ENABLED(string);

    char *new_str = FOUNDATIONAL_LIB_MEMORY_ALLOCATOR_STRDUP(string);

    if (FOUNDATIONAL_LIB_UNLIKELY(new_str == NULL))
    {
        FOUNDATIONAL_LIB_die_aggressively_if_enabled();
        return NULL;
    }
    char *orig_str = new_str;
    while (*new_str)
    {
        *new_str = tolower(*new_str);
        ++new_str;
    }

    return orig_str;
}

/**
 * @brief Convert a string to uppercase.
 *
 * This function takes a null-terminated string as input and converts all its
 * characters to uppercase. The resulting uppercase string is allocated
 * dynamically and returned. It is the caller's responsibility to free the
 * memory allocated for the new string.
 *
 * @param str The input string to be converted to uppercase.
 *
 * @return A pointer to the newly allocated uppercase string, or NULL if memory
 * allocation fails. Make sure to free the memory using free() when done with
 * the returned string.
 */
FOUNDATIONAL_LIB_WARN_UNUSED_RESULT FOUNDATIONAL_LIB_NONNULL FOUNDATIONAL_LIB_NOTHROW FOUNDATIONAL_LIB_MALLOC FOUNDATIONAL_LIB_FUNC char *string_to_uppercase(char *string)
{

    FOUNDATIONAL_LIB_ASSERT_ARGUMENT_IF_ENABLED(string);
    char *new_str = FOUNDATIONAL_LIB_MEMORY_ALLOCATOR_STRDUP(string);
    if (FOUNDATIONAL_LIB_UNLIKELY(new_str == NULL))
    {
        FOUNDATIONAL_LIB_die_aggressively_if_enabled();
        return NULL;
    }
    char *orig_str = new_str;
    while (*new_str)
    {
        *new_str = toupper(*new_str);
        ++new_str;
    }

    return orig_str;
}

/**
 * @brief Check if all characters in a string are uppercase.
 *
 * This function takes a null-terminated string as input and checks if all
 * characters in the string are uppercase letters.
 *
 * @param str The input string to be checked for uppercase characters.
 *
 * @return Returns 1 (true) if all characters in the string are uppercase,
 *         0 (false) otherwise. Returns 1 for an empty string as there are no
 *         lowercase characters to check.
 */
FOUNDATIONAL_LIB_WARN_UNUSED_RESULT FOUNDATIONAL_LIB_NONNULL FOUNDATIONAL_LIB_NOTHROW FOUNDATIONAL_LIB_PURE FOUNDATIONAL_LIB_FUNC int is_string_upper(const char *string)
{

    FOUNDATIONAL_LIB_ASSERT_ARGUMENT_IF_ENABLED(string);
    while (*string)
    {
        if (!FOUNDATIONAL_LIB_ISUPPER(*string))
        {
            return 0;
        }
        ++string;
    }
    return 1;
}

/**
 * @brief Check if all characters in a string are lowercase.
 *
 * This function takes a null-terminated string as input and checks if all
 * characters in the string are lowercase letters.
 *
 * @param str The input string to be checked for uppercase characters.
 *
 * @return Returns 1 (true) if all characters in the string are uppercase,
 *         0 (false) otherwise. Returns 1 for an empty string as there are no
 *         lowercase characters to check.
 */
FOUNDATIONAL_LIB_WARN_UNUSED_RESULT FOUNDATIONAL_LIB_NONNULL FOUNDATIONAL_LIB_NOTHROW FOUNDATIONAL_LIB_PURE FOUNDATIONAL_LIB_FUNC int is_string_lower(const char *string)
{
    FOUNDATIONAL_LIB_ASSERT_ARGUMENT_IF_ENABLED(string);

    while (*string)
    {
        if (!FOUNDATIONAL_LIB_ISLOWER(*string))
        {
            return 0;
        }
        ++string;
    }
    return 1;
}

/**
 * @brief Check if all characters in a string are alphanumeric.
 *
 * This function takes a null-terminated string as input and checks if all
 * characters in the string are alphanumeric (either letters or digits).
 *
 * @param str The input string to be checked for alphanumeric characters.
 *
 * @return Returns 1 (true) if all characters in the string are alphanumeric,
 *         0 (false) otherwise. Returns 1 for an empty string as there are no
 *         non-alphanumeric characters to check.
 */
FOUNDATIONAL_LIB_WARN_UNUSED_RESULT FOUNDATIONAL_LIB_NONNULL FOUNDATIONAL_LIB_NOTHROW FOUNDATIONAL_LIB_PURE FOUNDATIONAL_LIB_FUNC int is_string_alpha(const char *string)
{
    FOUNDATIONAL_LIB_ASSERT_ARGUMENT_IF_ENABLED(string);
    while (*string)
    {
        if (!FOUNDATIONAL_LIB_ISALNUM(*string))
        {
            return 0;
        }

        ++string;
    }
    return 1;
}

/**
 * @brief Check if all characters in a string are digits.
 *
 * This function takes a null-terminated string as input and checks if all
 * characters in the string are numeric digits (0-9).
 *
 * @param str The input string to be checked for digit characters.
 *
 * @return Returns 1 (true) if all characters in the string are digits,
 *         0 (false) otherwise. Returns 1 for an empty string as there are no
 *         non-digit characters to check.
 */
FOUNDATIONAL_LIB_WARN_UNUSED_RESULT FOUNDATIONAL_LIB_NONNULL FOUNDATIONAL_LIB_NOTHROW FOUNDATIONAL_LIB_PURE FOUNDATIONAL_LIB_FUNC int is_string_digit(const char *string)
{
    FOUNDATIONAL_LIB_ASSERT_ARGUMENT_IF_ENABLED(string);
    while (*string)
    {
        if (!FOUNDATIONAL_LIB_ISDIGIT(*string))
        {
            return 0;
        }
        ++string;
    }
    return 1;
}

/**
 * @brief Check if all characters in a string are spaces.
 *
 * This function takes a null-terminated string as input and checks if all
 * characters in the string are whitespace characters, such as spaces or tabs.
 *
 * @param str The input string to be checked for space characters.
 *
 * @return Returns 1 (true) if all characters in the string are spaces,
 *         0 (false) otherwise. Returns 1 for an empty string as there are no
 *         non-space characters to check.
 */
FOUNDATIONAL_LIB_WARN_UNUSED_RESULT FOUNDATIONAL_LIB_NONNULL FOUNDATIONAL_LIB_NOTHROW FOUNDATIONAL_LIB_PURE FOUNDATIONAL_LIB_FUNC int is_string_space(const char *string)
{
    FOUNDATIONAL_LIB_ASSERT_ARGUMENT_IF_ENABLED(string);

    while (*string)
    {
        if (!FOUNDATIONAL_LIB_ISSPACE(*string))
        {
            return 0;
        }
        ++string;
    }
    return 1;
}
/**
 * @brief Check if all characters in a string are printable.
 *
 * This function determines whether all characters in the given string are
 * printable. Printable characters are those that can be displayed or printed
 * and include alphanumeric characters, punctuation, and whitespace, excluding
 * control characters.
 *
 * @param str Pointer to the null-terminated string to be checked.
 * @return Returns 1 (true) if all characters are printable, 0 (false)
 * otherwise.
 *
 * @note The function considers a string with an empty or NULL pointer as
 * printable.
 * @warning This function does not handle wide characters or multi-byte
 * character encodings. It assumes a single-byte character encoding or UTF-8
 * with one byte per character. Use caution when using this function with
 * multi-byte character strings.
 */
FOUNDATIONAL_LIB_WARN_UNUSED_RESULT FOUNDATIONAL_LIB_NONNULL FOUNDATIONAL_LIB_NOTHROW FOUNDATIONAL_LIB_PURE FOUNDATIONAL_LIB_FUNC int is_string_printable(const char *string)
{
    FOUNDATIONAL_LIB_ASSERT_ARGUMENT_IF_ENABLED(string);
    while (*string)
    {
        if (!FOUNDATIONAL_LIB_ISPRINT(*string))
        {
            return 0;
        }
        ++string;
    }
    return 1;
}

/**
 * @brief Check if a string array contains only digits.
 *
 * This function determines whether all strings in the given array consist
 * solely of digit characters ('0' to '9').
 *
 * @param array Pointer to the array of strings to be checked.
 * @param size Number of elements in the array.
 * @return Returns 1 (true) if all strings contain only digits, 0 (false)
 * otherwise.
 *
 * @note The function considers an empty or NULL array as containing only
 * digits.
 * @note If the array contains NULL pointers, they are treated as empty strings.
 * @warning This function assumes that the input strings are null-terminated.
 *          Use caution when using this function with non-null-terminated
 * strings.
 *
 * Example usage:
 * @code
 * const char *myArray[] = {"123", "456", "789"};
 * if (is_array_digit(myArray, 3)) {
 *     // All strings in the array are composed of digits.
 * } else {
 *     // At least one string in the array contains non-digit characters.
 * }
 * @endcode
 */
FOUNDATIONAL_LIB_WARN_UNUSED_RESULT FOUNDATIONAL_LIB_NONNULL FOUNDATIONAL_LIB_NOTHROW FOUNDATIONAL_LIB_PURE FOUNDATIONAL_LIB_FUNC int is_array_digit(const char **array, size_t size)
{

    FOUNDATIONAL_LIB_ASSERT_ARGUMENT_IF_ENABLED(array);
    for (size_t i = 0; i < size; ++i)
    {
        const char *str = array[i];
        while (*str)
        {
            if (!FOUNDATIONAL_LIB_ISDIGIT(*str))
            {
                return 0;
            }
            ++str;
        }
    }
    return 1;
}
/**
 * @brief Checks if a string array contains only uppercase characters.
 *
 * This function examines each string in the given array to determine if it
 * contains only uppercase characters. The comparison is case-sensitive.
 *
 * @param array   Pointer to an array of strings.
 * @param size    The number of elements in the array.
 *
 * @return        Returns 1 if all strings in the array are composed of uppercase
 *                characters only. Returns 0 otherwise.
 */
FOUNDATIONAL_LIB_WARN_UNUSED_RESULT FOUNDATIONAL_LIB_NONNULL FOUNDATIONAL_LIB_NOTHROW FOUNDATIONAL_LIB_PURE FOUNDATIONAL_LIB_FUNC int is_array_upper(const char **array, size_t size)
{

    FOUNDATIONAL_LIB_ASSERT_ARGUMENT_IF_ENABLED(array);
    for (size_t i = 0; i < size; ++i)
    {
        const char *str = array[i];
        while (*str)
        {
            if (!FOUNDATIONAL_LIB_ISUPPER(*str))
            {
                return 0;
            }
            ++str;
        }
    }
    return 1;
}

/**
 * @brief Checks if a string array contains only lowercase characters.
 *
 * This function examines each string in the given array to determine if it
 * contains only lowercase characters. The comparison is case-sensitive.
 *
 * @param array Pointer to an array of strings.
 * @param size  The number of elements in the array.
 *
 * @return      Returns 1 if all strings in the array are composed of lowercase
 *              characters only. Returns 0 otherwise.
 */
FOUNDATIONAL_LIB_WARN_UNUSED_RESULT FOUNDATIONAL_LIB_NONNULL FOUNDATIONAL_LIB_NOTHROW FOUNDATIONAL_LIB_PURE FOUNDATIONAL_LIB_FUNC int is_array_lower(const char **array, size_t size)
{

    FOUNDATIONAL_LIB_ASSERT_ARGUMENT_IF_ENABLED(array);
    for (size_t i = 0; i < size; ++i)
    {
        const char *str = array[i];
        while (*str)
        {
            if (!FOUNDATIONAL_LIB_ISLOWER(*str))
            {
                return 0;
            }
            ++str;
        }
    }
    return 1;
}

/**
 * @brief Remove duplicate strings from a string array.
 *
 * This function takes an array of strings, removes duplicate entries, and
 * returns the result in a dynamically allocated array. The input array remains
 * unchanged.
 *
 * @param array The input string array.
 * @param size The size of the input array.
 * @param output A pointer to the location where the result array will be
 * stored. The caller is responsible for freeing the memory allocated for the
 * result.
 * @param output_size A pointer to the location where the size of the result
 * array will be stored.
 *
 * @return -1 if an error occurs (e.g., invalid input or memory allocation
 * failure), 0 if the operation is successful, and the result array is
 * dynamically allocated.
 *
 * @note The caller is responsible for freeing the memory allocated for the
 * result array.
 *
 * @code
 * const char *input_array[] = {"apple", "orange", "banana", "apple", "grape"};
 * char **result_array;
 * size_t result_size;
 * int status = string_array_uniq(input_array, 5, &result_array, &result_size);
 * if (!status) {
 *     // Successfully obtained the unique string array.
 *     // Use result_array and result_size as needed.
 *     // Don't forget to free(result_array) when done.
 * } else {
 *     // Handle the error.
 * }
 * @endcode
 */
FOUNDATIONAL_LIB_WARN_UNUSED_RESULT FOUNDATIONAL_LIB_NONNULL FOUNDATIONAL_LIB_NOTHROW FOUNDATIONAL_LIB_FUNC int string_array_uniq(const char **array, size_t size, char ***output, size_t *output_size)
{
    FOUNDATIONAL_LIB_ASSERT_ARGUMENT_IF_ENABLED(array);

    FOUNDATIONAL_LIB_ASSERT_ARGUMENT_IF_ENABLED(output);
    FOUNDATIONAL_LIB_ASSERT_ARGUMENT_IF_ENABLED(output_size);

    *output_size = 0;

    const size_t alloc_size = FOUNDATIONAL_LIB_safe_mul(size, sizeof(char *));

    if (FOUNDATIONAL_LIB_UNLIKELY(alloc_size == 0))
    {
        FOUNDATIONAL_LIB_die_aggressively_if_enabled();
        return -1;
    }

    // Count the number of unique strings
    size_t count = 0;

    // Allocate memory for the array to store unique strings
    *output = (char **)FOUNDATIONAL_LIB_MEMORY_ALLOCATOR_MALLOC(alloc_size);
    if (FOUNDATIONAL_LIB_UNLIKELY(*output == NULL))
    {
        // Memory allocation failed
        FOUNDATIONAL_LIB_die_aggressively_if_enabled();
        return -1;
    }

    // Initialize all elements to NULL
    for (size_t i = 0; i < size; ++i)
    {
        (*output)[i] = NULL;
    }

    // Iterate through the input array to find unique strings
    for (size_t i = 0; i < size; ++i)
    {
        int is_unique = 1;

        // Check if the current string is not equal to any previous strings
        for (size_t j = 0; j < count; ++j)
        {
            if ((*output)[j] != NULL && FOUNDATIONAL_LIB_STRCMP(array[i], (*output)[j]) == 0)
            {
                is_unique = 0; // Not unique
                break;
            }
        }

        if (is_unique)
        {
            (*output)[count] = ((char **)array)[i]; // No strdup used.

            ++count;
        }
    }

    // Set the output size
    *output_size = count;

    return 0;
}

/**
 * @brief Remove adjacent duplicate strings from a string array.
 *
 * This function takes an array of strings, removes duplicates that are adjacent
 * to each other, and returns the result in a dynamically allocated array. The
 * input array remains unchanged.
 *
 * @param first_array The input string array.
 * @param size The size of the input array.
 * @param new_array A pointer to the location where the result array will be
 * stored. The caller is responsible for freeing the memory allocated for the
 * result.
 * @param new_size A pointer to the location where the size of the result array
 * will be stored.
 *
 * @return -1 if an error occurs (e.g., invalid input or memory allocation
 * failure), 0 if the operation is successful, and the result array is malloced.
 *
 * @note The caller is responsible for freeing the memory allocated for the
 * result array.
 *
 * @code
 * const char *input_array[] = {"apple", "orange", "orange", "banana", "banana", "apple", "grape"};
 * char **result_array;
 * size_t result_size;
 * int status = string_array_uniq_adjacent(input_array, 7, &result_array, &result_size);
 * if (!status) {
 *     // Successfully obtained the string array with adjacent duplicates removed.
 *     // Use result_array and result_size as needed.
 *     // Don't forget to free(result_array) when done.
 * } else {
 *     // Handle the error.
 * }
 *
 * @endcode
 */
FOUNDATIONAL_LIB_NONNULL FOUNDATIONAL_LIB_NOTHROW FOUNDATIONAL_LIB_FUNC int string_array_uniq_adjacent(const char **first_array, size_t size, char ***new_array, size_t *new_size)
{
    FOUNDATIONAL_LIB_ASSERT_ARGUMENT_IF_ENABLED(first_array);

    FOUNDATIONAL_LIB_ASSERT_ARGUMENT_IF_ENABLED(new_array);
    FOUNDATIONAL_LIB_ASSERT_ARGUMENT_IF_ENABLED(new_size);

    FOUNDATIONAL_LIB_ASSERT_ARGUMENT_IF_ENABLED(first_array);
    FOUNDATIONAL_LIB_ASSERT_ARGUMENT_IF_ENABLED(new_array);
    FOUNDATIONAL_LIB_ASSERT_ARGUMENT_IF_ENABLED(new_size);

    *new_size = 0;
    const size_t alloc_size = FOUNDATIONAL_LIB_safe_mul(size, sizeof(char *));

    if (FOUNDATIONAL_LIB_UNLIKELY(alloc_size == 0))
    {
        FOUNDATIONAL_LIB_die_aggressively_if_enabled();
        return -1;
    }

    // Create a new dynamically allocated array
    *new_array = (char **)FOUNDATIONAL_LIB_MEMORY_ALLOCATOR_MALLOC(alloc_size);
    if (FOUNDATIONAL_LIB_UNLIKELY(*new_array == NULL))
    {
        FOUNDATIONAL_LIB_die_aggressively_if_enabled();
        return -1;
    }

    // Remove adjacent duplicates from arr1 and copy to arr2
    for (size_t i = 0; i < size; ++i)
    {
        if (i == 0 || FOUNDATIONAL_LIB_STRCMP(first_array[i], first_array[i - 1]) != 0)
        {
            (*new_array)[(*new_size)++] = (char *)first_array[i]; // No strdup
        }
    }

    return 0;
}

/**
 * @brief Concatenates three strings into a new dynamically allocated array.
 *
 * This function concatenates the given three strings into a new dynamically
 * allocated character array. The caller is responsible for freeing the memory
 * allocated for the result using the free() function.
 *
 * @param str1  The first string to be concatenated.
 * @param str2  The second string to be concatenated.
 * @param str3  The third string to be concatenated.
 *
 * @return      Returns a pointer to the newly allocated character array
 *              containing the concatenated strings. If the allocation fails,
 *              returns NULL. The caller must free the memory when done using
 *              free().
 */
FOUNDATIONAL_LIB_WARN_UNUSED_RESULT FOUNDATIONAL_LIB_NONNULL FOUNDATIONAL_LIB_NOTHROW FOUNDATIONAL_LIB_MALLOC FOUNDATIONAL_LIB_FUNC char *concatenate_three_strings(const char *str1, const char *str2, const char *str3)
{
    FOUNDATIONAL_LIB_ASSERT_ARGUMENT_IF_ENABLED(str1);
    FOUNDATIONAL_LIB_ASSERT_ARGUMENT_IF_ENABLED(str2);
    FOUNDATIONAL_LIB_ASSERT_ARGUMENT_IF_ENABLED(str3);

    const char *strs[3] = {str1, str2, str3};

    return concatenate_string_array(strs, 3);
}

/**
 * @brief Concatenates four strings into a new dynamically allocated array.
 *
 * This function concatenates the given four strings into a new dynamically
 * allocated character array. The caller is responsible for freeing the memory
 * allocated for the result using the free() function.
 *
 * @param str1  The first string to be concatenated.
 * @param str2  The second string to be concatenated.
 * @param str3  The third string to be concatenated.
 * @param str4  The fourth string to be concatenated.
 *
 * @return      Returns a pointer to the newly allocated character array
 *              containing the concatenated strings. If the allocation fails,
 *              returns NULL. The caller must free the memory when done using
 *              free().
 */
FOUNDATIONAL_LIB_WARN_UNUSED_RESULT FOUNDATIONAL_LIB_NONNULL FOUNDATIONAL_LIB_NOTHROW FOUNDATIONAL_LIB_MALLOC FOUNDATIONAL_LIB_FUNC char *concatenate_four_strings(const char *str1, const char *str2, const char *str3, const char *str4)
{
    FOUNDATIONAL_LIB_ASSERT_ARGUMENT_IF_ENABLED(str1);
    FOUNDATIONAL_LIB_ASSERT_ARGUMENT_IF_ENABLED(str2);
    FOUNDATIONAL_LIB_ASSERT_ARGUMENT_IF_ENABLED(str3);
    FOUNDATIONAL_LIB_ASSERT_ARGUMENT_IF_ENABLED(str4);

    const char *strs[4] = {str1, str2, str3, str4};

    return concatenate_string_array(strs, 4);
}

/**
 * @brief Concatenates five strings into a new dynamically allocated array.
 *
 * This function concatenates the given five strings into a new dynamically
 * allocated character array. The caller is responsible for freeing the memory
 * allocated for the result using the free() function.
 *
 * @param str1  The first string to be concatenated.
 * @param str2  The second string to be concatenated.
 * @param str3  The third string to be concatenated.
 * @param str4  The fourth string to be concatenated.
 * @param str5  The fifth string to be concatenated.
 *
 * @return      Returns a pointer to the newly allocated character array
 *              containing the concatenated strings. If the allocation fails,
 *              returns NULL. The caller must free the memory when done using
 *              free().
 */
FOUNDATIONAL_LIB_WARN_UNUSED_RESULT FOUNDATIONAL_LIB_NONNULL FOUNDATIONAL_LIB_NOTHROW FOUNDATIONAL_LIB_MALLOC FOUNDATIONAL_LIB_FUNC char *concatenate_five_strings(const char *str1, const char *str2, const char *str3, const char *str4, const char *str5)
{
    FOUNDATIONAL_LIB_ASSERT_ARGUMENT_IF_ENABLED(str1);
    FOUNDATIONAL_LIB_ASSERT_ARGUMENT_IF_ENABLED(str2);
    FOUNDATIONAL_LIB_ASSERT_ARGUMENT_IF_ENABLED(str3);
    FOUNDATIONAL_LIB_ASSERT_ARGUMENT_IF_ENABLED(str4);
    FOUNDATIONAL_LIB_ASSERT_ARGUMENT_IF_ENABLED(str5);

    const char *strs[5] = {str1, str2, str3, str4, str5};

    return concatenate_string_array(strs, 5);
}

#ifdef _WIN32
#include <tchar.h>
#include <windows.h>
#else
#include <dirent.h>
#endif

#ifdef _WIN32
#define FOUNDATIONAL_LIB_DIR_SEPARATOR '\\'
#else
#define FOUNDATIONAL_LIB_DIR_SEPARATOR '/'
#endif

/**
 * @brief Applies a map operation on files in a directory, working with strings.
 *
 * This function applies the given map function to each file in the specified
 * directory, treating the file content as a string. The map function is
 * expected to take the file string data and its size as its input and return a
 * dynamically allocated string which then will afterwards be written back to
 * the corresponding file, in effect "mapping" all the files in the directory to
 * a given function's result - establishing a level of easy power over the
 * filesystem that is difficult in C.  The caller is responsible for freeing the
 * memory allocated by the map function.
 *
 *
 * @param directory         The path to the directory containing files to be
 * processed.
 *
 * @param map_function      The map function to be applied to each file's string
 * data. It should have the signature: `char *(*map_function)(const char
 * *file_string_data, size_t string_size)`. The map function should return a
 * dynamically allocated string.
 *
 * @return                  Returns 0 on success (non-error) or -1 on error.
 */
FOUNDATIONAL_LIB_WARN_UNUSED_RESULT FOUNDATIONAL_LIB_NONNULL FOUNDATIONAL_LIB_NOTHROW FOUNDATIONAL_LIB_FUNC int map_filesystem_files_as_strings(const char *directory, char *(*map_function)(const char *file_string_data, size_t string_size))
{

    FOUNDATIONAL_LIB_ASSERT_ARGUMENT_IF_ENABLED(directory);
    FOUNDATIONAL_LIB_ASSERT_ARGUMENT_IF_ENABLED(map_function);

#ifdef _WIN32
    WIN32_FIND_DATA findFileData;
    HANDLE hFind = FindFirstFile(directory, &findFileData);

    if (FOUNDATIONAL_LIB_UNLIKELY(hFind == INVALID_HANDLE_VALUE))
    {
        FOUNDATIONAL_LIB_die_aggressively_if_enabled();
        return -1;
    }

    do
    {
        if (!(findFileData.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY))
        {
            // Regular file
            char *file_data;
            size_t size;

            // Get the regular file.
            char fullFilePath[MAX_PATH];
            _stprintf(fullFilePath, _T("%s%c%s"), directory, FOUNDATIONAL_LIB_DIR_SEPARATOR, findFileData.cFileName);

            file_data = read_file_into_string(fullFilePath, &size);
            if (FOUNDATIONAL_LIB_UNLIKELY(file_data == NULL))
            {
                // No need to re-die aggressively.
                FindClose(hFind); /* No need to error check here because there already is an error. */
                return -1;
            }

            // The result of the map operation
            const char *new_str = map_function(file_data, size);

            // Write the result to disk
            if (FOUNDATIONAL_LIB_UNLIKELY(write_file(fullFilePath, new_str) == -1))
            {
                // No need to re-die aggressively.
                FOUNDATIONAL_LIB_MEMORY_ALLOCATOR_FREE(file_data);
                FOUNDATIONAL_LIB_MEMORY_ALLOCATOR_FREE((char *)new_str);
                FindClose(hFind); // No need to error check here because there already is an error.
                return -1;
            }

            // Free memory.
            FOUNDATIONAL_LIB_MEMORY_ALLOCATOR_FREE(file_data);
            FOUNDATIONAL_LIB_MEMORY_ALLOCATOR_FREE((char *)new_str);
        }

    } while (FindNextFile(hFind, &findFileData) != 0);

    if (FOUNDATIONAL_LIB_UNLIKELY(FindClose(hFind) == 0))
    {
        FOUNDATIONAL_LIB_die_aggressively_if_enabled();
        return -1;
    }

#else
    DIR *dir = opendir(directory);
    if (FOUNDATIONAL_LIB_UNLIKELY(dir == NULL))
    {
        FOUNDATIONAL_LIB_die_aggressively_if_enabled();
        return -1;
    }

    struct dirent *entry;
    while ((entry = readdir(dir)) != NULL)
    {
        if (entry->d_type == DT_REG)
        { // Regular file
            char *file_data;
            size_t size;

            // Get the regular file.
            char fullFilePath[PATH_MAX];
            FOUNDATIONAL_LIB_SNPRINTF(fullFilePath, PATH_MAX, "%s%c%s", directory, FOUNDATIONAL_LIB_DIR_SEPARATOR, entry->d_name);

            file_data = read_file_into_string(fullFilePath, &size);
            if (FOUNDATIONAL_LIB_UNLIKELY(file_data == NULL))
            {
                // No need to re-die aggressively.
                return -1;
            }

            // The result of the map operation
            const char *new_str = map_function(file_data, size);

            // Write the result to disk
            if (write_file(fullFilePath, new_str) == -1)
            {
                // No need to re-die aggressively.
                FOUNDATIONAL_LIB_MEMORY_ALLOCATOR_FREE(file_data);
                FOUNDATIONAL_LIB_MEMORY_ALLOCATOR_FREE((char *)new_str);
                return -1;
            }

            // Free memory.
            FOUNDATIONAL_LIB_MEMORY_ALLOCATOR_FREE(file_data);
            FOUNDATIONAL_LIB_MEMORY_ALLOCATOR_FREE((char *)new_str);
        }
    }

    if (FOUNDATIONAL_LIB_UNLIKELY(closedir(dir) == -1))
    {
        FOUNDATIONAL_LIB_die_aggressively_if_enabled();
        return -1;
    }

#endif

    return 0;
}

/**
 * @brief Applies a filter operation on files in the specified directory.
 *
 * This function iterates through the files in the given directory and applies
 * the provided filter function to each file. The filter function should return
 * 1 to keep the file or 0 to delete it. The overall result of the filter
 * operation is returned by this function.
 *
 * @param directory The path to the directory containing the files to be
 * filtered.
 * @param filter_function A pointer to the filter function that takes a filename
 * as a parameter and returns 1 to keep the file or 0 to delete it.
 *
 * @return Returns -1 on error, 0 on non-error.
 */
FOUNDATIONAL_LIB_WARN_UNUSED_RESULT FOUNDATIONAL_LIB_NONNULL FOUNDATIONAL_LIB_NOTHROW FOUNDATIONAL_LIB_FUNC int filter_filesystem_files_as_strings(const char *directory, int (*filter_function)(const char *filename))
{
    FOUNDATIONAL_LIB_ASSERT_ARGUMENT_IF_ENABLED(directory);
    FOUNDATIONAL_LIB_ASSERT_ARGUMENT_IF_ENABLED(filter_function);
#ifdef _WIN32
    WIN32_FIND_DATA findFileData;
    HANDLE hFind = FindFirstFile(directory, &findFileData);

    if (FOUNDATIONAL_LIB_UNLIKELY(hFind == INVALID_HANDLE_VALUE))
    {
        FOUNDATIONAL_LIB_die_aggressively_if_enabled();
        return -1;
    }

    do
    {
        if (!(findFileData.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) && !filter_function(findFileData.cFileName))
        {
            // Regular file to be removed
            char fullFilePath[MAX_PATH];
            _stprintf(fullFilePath, _T("%s%c%s"), directory, FOUNDATIONAL_LIB_DIR_SEPARATOR, findFileData.cFileName);

            if (remove_file(fullFilePath) == -1)
            {
                // Handle error or return -1
                if (FindClose(hFind) == 0)
                {
                    FOUNDATIONAL_LIB_die_aggressively_if_enabled();
                    return -1;
                }
                return -1;
            }
        }

    } while (FindNextFile(hFind, &findFileData) != 0);

    FindClose(hFind);

#else
    DIR *dir = opendir(directory);
    if (FOUNDATIONAL_LIB_UNLIKELY(dir == NULL))
    {
        FOUNDATIONAL_LIB_die_aggressively_if_enabled();
        return -1;
    }

    struct dirent *entry;
    while ((entry = readdir(dir)) != NULL)
    {
        if (entry->d_type == DT_REG)
        {
            if (!filter_function(entry->d_name))
            {
                // Regular file to be removed
                char fullFilePath[PATH_MAX];
                FOUNDATIONAL_LIB_SNPRINTF(fullFilePath, PATH_MAX, "%s%c%s", directory, FOUNDATIONAL_LIB_DIR_SEPARATOR, entry->d_name);

                if (remove_file(fullFilePath) == -1)
                {
                    // Handle error or return -1
                    if (closedir(dir) == -1)
                    {
                        FOUNDATIONAL_LIB_die_aggressively_if_enabled();
                        return -1;
                    }
                    return -1;
                }
            }
        }
    }

    if (FOUNDATIONAL_LIB_UNLIKELY(closedir(dir) == -1))
    {
        FOUNDATIONAL_LIB_die_aggressively_if_enabled();
        return -1;
    }
#endif

    return 0;
}

/**
 * @brief Applies a reduce operation on files in the specified directory, and
 * outputs the result as a string.
 *
 * This function iterates through the files in the given directory and applies
 * the provided reduce function to each file. The reduce function takes variable
 * arguments (char pointers) and produces a result that is then concatenated.
 * The final result is returned as a dynamically allocated string. The caller is
 * responsible for freeing the memory allocated for the result.
 *
 * @param directory The path to the directory containing the files to be
 * processed.
 * @param out_file The path to the output file where the final result will be
 * stored.
 * @param reduce_function A pointer to the reduce function that takes variable
 * arguments (char pointers) and produces a result to be concatenated.
 *
 * @return Returns a dynamically allocated string containing the result of the
 * reduce operation. The caller is responsible for freeing the memory allocated
 * for the result.
 */
FOUNDATIONAL_LIB_WARN_UNUSED_RESULT FOUNDATIONAL_LIB_NONNULL FOUNDATIONAL_LIB_NOTHROW FOUNDATIONAL_LIB_FUNC char *reduce_filesystem_files_as_strings(const char *directory, const char *out_file, char *(*reduce_function)(char *value1, ...))
{
    FOUNDATIONAL_LIB_ASSERT_ARGUMENT_IF_ENABLED(directory);
    FOUNDATIONAL_LIB_ASSERT_ARGUMENT_IF_ENABLED(out_file);
    FOUNDATIONAL_LIB_ASSERT_ARGUMENT_IF_ENABLED(reduce_function);
#ifdef _WIN32
    WIN32_FIND_DATA findFileData;
    HANDLE hFind = FindFirstFile(directory, &findFileData);

    if (FOUNDATIONAL_LIB_UNLIKELY(hFind == INVALID_HANDLE_VALUE))
    {
        FOUNDATIONAL_LIB_die_aggressively_if_enabled();
        return NULL;
    }

    char *last_value = NULL;
    char *value = NULL;

    do
    {
        if (!(findFileData.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) && findFileData.dwFileAttributes & FILE_ATTRIBUTE_NORMAL)
        {
            // Regular file
            size_t size;

            // Get the regular file.
            char fullFilePath[MAX_PATH];
            _stprintf(fullFilePath, _T("%s%c%s"), directory, FOUNDATIONAL_LIB_DIR_SEPARATOR, findFileData.cFileName);

            value = read_file_into_string(fullFilePath, &size);
            if (FOUNDATIONAL_LIB_UNLIKELY(value == NULL))
            {
                // No need to re-die aggressively.
                FindClose(hFind); /* Don't need to care about the return value because there already is an error. */
                return NULL;
            }

            char *new_value = reduce_function(last_value, value, findFileData.cFileName);
            if (last_value)
            {
                FOUNDATIONAL_LIB_MEMORY_ALLOCATOR_FREE(last_value);
            }

            FOUNDATIONAL_LIB_MEMORY_ALLOCATOR_FREE(value);
            last_value = new_value;

            if (FOUNDATIONAL_LIB_UNLIKELY(remove_file(fullFilePath) == -1))
            {
                FOUNDATIONAL_LIB_die_aggressively_if_enabled();
                return NULL;
            }
        }

    } while (FindNextFile(hFind, &findFileData) != 0);

    if (FOUNDATIONAL_LIB_UNLIKELY(FindClose(hFind) == 0))
    {
        FOUNDATIONAL_LIB_die_aggressively_if_enabled();
        return NULL;
    }
#else
    DIR *dir = opendir(directory);
    if (FOUNDATIONAL_LIB_UNLIKELY(dir == NULL))
    {
        FOUNDATIONAL_LIB_die_aggressively_if_enabled();
        return NULL;
    }

    char *last_value = NULL;
    char *value = NULL;
    struct dirent *entry;

    while ((entry = readdir(dir)) != NULL)
    {
        if (entry->d_type == DT_REG)
        {
            // Regular file
            size_t size;

            // Get the regular file.
            char fullFilePath[PATH_MAX];
            FOUNDATIONAL_LIB_SNPRINTF(fullFilePath, PATH_MAX, "%s%c%s", directory, FOUNDATIONAL_LIB_DIR_SEPARATOR, entry->d_name);

            value = read_file_into_string(fullFilePath, &size);
            if (FOUNDATIONAL_LIB_UNLIKELY(value == NULL))
            {
                // No need to re-die aggressively.
                if (FOUNDATIONAL_LIB_UNLIKELY(closedir(dir) == -1))
                {
                    FOUNDATIONAL_LIB_die_aggressively_if_enabled();
                    return NULL;
                }
                return NULL;
            }

            char *new_value = reduce_function(last_value, value, entry->d_name);
            if (last_value)
            {
                FOUNDATIONAL_LIB_MEMORY_ALLOCATOR_FREE(last_value);
            }

            FOUNDATIONAL_LIB_MEMORY_ALLOCATOR_FREE(value);
            last_value = new_value;

            if (FOUNDATIONAL_LIB_UNLIKELY(remove_file(fullFilePath) == -1))
            {
                FOUNDATIONAL_LIB_die_aggressively_if_enabled();
                return NULL;
            }
        }
    }

    if (FOUNDATIONAL_LIB_UNLIKELY(closedir(dir) == -1))
    {
        FOUNDATIONAL_LIB_die_aggressively_if_enabled();
        return NULL;
    }
#endif

    if (FOUNDATIONAL_LIB_UNLIKELY(write_file(out_file, value) == -1))
    {
        /* No need to re-die aggressively. */
        FOUNDATIONAL_LIB_MEMORY_ALLOCATOR_FREE(last_value);
        return NULL;
    }

    return last_value;
}

/**
 * @brief Deallocates memory associated with a dictionary, freeing resources.
 *
 * This function is the destructor for the provided dictionary, freeing the
 * memory allocated for the hash table and its elements. It is important to call
 * this function to prevent memory leaks when a dictionary is no longer needed.
 *
 * @param dict A pointer to the dictionary instance to be deallocated.
 */
FOUNDATIONAL_LIB_NONNULL FOUNDATIONAL_LIB_NOTHROW FOUNDATIONAL_LIB_FUNC void dict_destructor(struct Dict *dict)
{

    FOUNDATIONAL_LIB_ASSERT_ARGUMENT_IF_ENABLED(dict);

    for (size_t i = 0; i < dict->capacity; ++i)
    {
        struct DictKeyValue *current_pair = dict->table[i];
        while (current_pair != NULL)
        {
            struct DictKeyValue *next_pair = current_pair->next;
            FOUNDATIONAL_LIB_MEMORY_ALLOCATOR_FREE(current_pair->key);
            FOUNDATIONAL_LIB_MEMORY_ALLOCATOR_FREE(current_pair);
            current_pair = next_pair;
        }
    }
    FOUNDATIONAL_LIB_MEMORY_ALLOCATOR_FREE(dict->table);
    FOUNDATIONAL_LIB_MEMORY_ALLOCATOR_FREE(dict);
}

/**
 * @brief Hashes a null-terminated string using the djb2 algorithm.
 *
 * The djb2 hash function is a simple and effective algorithm for hashing
 * strings. It iterates over each character in the input string, combining the
 * current hash value with the ASCII value of the character using the formula
 * `hash = (hash << 5) + hash + c`. The algorithm is known for its simplicity,
 * good distribution properties, and reduced likelihood of collisions.
 *
 * @param key Pointer to the null-terminated character array (string) used as
 * the key.
 * @param capacity Capacity of the hash table.
 * @return The computed hash value within the specified capacity.
 */
FOUNDATIONAL_LIB_WARN_UNUSED_RESULT FOUNDATIONAL_LIB_NONNULL FOUNDATIONAL_LIB_NOTHROW FOUNDATIONAL_LIB_PURE FOUNDATIONAL_LIB_FUNC size_t dict_hash(const char *key, size_t capacity)
{
    FOUNDATIONAL_LIB_ASSERT_ARGUMENT_IF_ENABLED(key);

    size_t hash = 5381; // Initial hash value
    int c;              // Variable to store the current character

    while ((c = *key++))
    {
        hash = ((hash << 5) + hash) + c; /* hash * 33 + c */
    }

    return hash % capacity;
}

/**
 * @brief Reserves additional space in a Dictionary for anticipated new
 * elements.
 *
 * This function reserves additional space in the provided dictionary's internal
 * hash table to accommodate an anticipated number of new elements. The
 * reservation helps avoid frequent resizes, optimizing performance when a known
 * number of new elements is expected. Calling this function will trigger a
 * resize and rehash of the dictionary, but it will only happen (ideally) once,
 * if you accurately predict the future size of the dictionary.
 *
 * @param dict A pointer to the Dict instance for which space is to be reserved.
 * @param number_of_new_elements_max_one_is_expecting The anticipated number of
 * new elements (above the current capacity).
 *
 * @return Returns 0 on success, -1 on failure.
 */
FOUNDATIONAL_LIB_WARN_UNUSED_RESULT FOUNDATIONAL_LIB_NONNULL FOUNDATIONAL_LIB_NOTHROW FOUNDATIONAL_LIB_FUNC int dict_reserve_more(struct Dict *dict, size_t number_of_new_elements_max_one_is_expecting)
{
    FOUNDATIONAL_LIB_ASSERT_ARGUMENT_IF_ENABLED(dict);

    const size_t new_capacity = FOUNDATIONAL_LIB_safe_add_2(dict->capacity, number_of_new_elements_max_one_is_expecting);

    if (FOUNDATIONAL_LIB_UNLIKELY(new_capacity == 0))
    {
        FOUNDATIONAL_LIB_die_aggressively_if_enabled();
        return -1;
    }

    /* Either calloc or realloc would be ideal here, but, if the block is large,
       then calloc might be better because there might be a cleared block of
       memory that is very large that is readily available. */
    struct DictKeyValue **new_table = (struct DictKeyValue **)FOUNDATIONAL_LIB_MEMORY_ALLOCATOR_CALLOC(new_capacity, sizeof(struct DictKeyValue *));
    if (FOUNDATIONAL_LIB_UNLIKELY(new_table == NULL))
    {
        FOUNDATIONAL_LIB_die_aggressively_if_enabled();
        return -1;
    }

    for (size_t i = 0; i < dict->capacity; ++i)
    {
        struct DictKeyValue *current_pair = dict->table[i];
        while (current_pair)
        {
            struct DictKeyValue *next_pair = current_pair->next;
            const size_t new_index = dict_hash(current_pair->key, new_capacity);
            current_pair->next = new_table[new_index];
            new_table[new_index] = current_pair;
            current_pair = next_pair;
        }
    }

    FOUNDATIONAL_LIB_MEMORY_ALLOCATOR_FREE(dict->table);
    dict->table = new_table;
    dict->capacity = new_capacity;

    return 0;
}
/**
 * @brief Resizes the hash table of the dictionary to optimize performance.
 *
 * This function adjusts the size of the hash table in the provided dictionary
 * to enhance performance. The new capacity is determined using a reallocation
 * algorithm specified by the FOUNDATIONAL_LIB_REALLOC_REALLOCATION_ALGORITHM
 * macro. The function reallocates memory for the hash table, rehashes all
 * existing key-value pairs, and updates the dictionary's capacity accordingly.
 *
 * @param dict A pointer to the dictionary instance to be resized.
 *
 * @return Returns 0 on success, -1 on failure.
 */
FOUNDATIONAL_LIB_WARN_UNUSED_RESULT FOUNDATIONAL_LIB_NONNULL FOUNDATIONAL_LIB_NOTHROW FOUNDATIONAL_LIB_FUNC int dict_resize(struct Dict *dict)
{

    FOUNDATIONAL_LIB_ASSERT_ARGUMENT_IF_ENABLED(dict);

    const size_t new_capacity = FOUNDATIONAL_LIB_REALLOC_REALLOCATION_ALGORITHM(dict->capacity);
    if (FOUNDATIONAL_LIB_UNLIKELY(new_capacity == 0)) // Overflow.
    {
        FOUNDATIONAL_LIB_die_aggressively_if_enabled();
        return -1;
    }

    /* Either calloc or realloc would be ideal here, but, if the block is large,
       then calloc might be better because there might be a cleared block of
       memory that is very large that is readily available. */
    struct DictKeyValue **new_table = (struct DictKeyValue **)FOUNDATIONAL_LIB_MEMORY_ALLOCATOR_CALLOC(new_capacity, sizeof(struct DictKeyValue *));
    if (FOUNDATIONAL_LIB_UNLIKELY(new_table == NULL))
    {
        dict_destructor(dict);
        FOUNDATIONAL_LIB_die_aggressively_if_enabled();
        return -1;
    }

    for (size_t i = 0; i < dict->capacity; ++i)
    {
        struct DictKeyValue *current_pair = dict->table[i];
        while (current_pair)
        {
            struct DictKeyValue *next_pair = current_pair->next;
            const size_t new_index = dict_hash(current_pair->key, new_capacity);
            current_pair->next = new_table[new_index];
            new_table[new_index] = current_pair;
            current_pair = next_pair;
        }
    }

    FOUNDATIONAL_LIB_MEMORY_ALLOCATOR_FREE(dict->table);
    dict->table = new_table;
    dict->capacity = new_capacity;

    return 0;
}

/**
 * @brief Deletes a key-value pair from the dictionary based on the provided
 * key.
 *
 * This function removes the key-value pair associated with the specified key
 * from the provided dictionary. If the key is not found, the dictionary remains
 * unchanged.
 *
 * @param dict A pointer to the dictionary instance.
 * @param key The key for which the associated key-value pair is to be deleted.
 */
FOUNDATIONAL_LIB_NONNULL FOUNDATIONAL_LIB_NOTHROW FOUNDATIONAL_LIB_FUNC void dict_del_key(struct Dict *dict, const char *key)
{
    FOUNDATIONAL_LIB_ASSERT_ARGUMENT_IF_ENABLED(dict);
    FOUNDATIONAL_LIB_ASSERT_ARGUMENT_IF_ENABLED(key);
    const size_t index = dict_hash(key, dict->capacity);

    struct DictKeyValue *current = dict->table[index];
    struct DictKeyValue *prev = NULL;

    while (current != NULL)
    {
        if (FOUNDATIONAL_LIB_STRCMP(current->key, key) == 0)
        {
            /* Key found, remove the entry */
            if (prev == NULL)
            {
                /* If it's the first node in the linked list */
                dict->table[index] = current->next;
            }
            else
            {
                prev->next = current->next;
            }

            /* Free memory */
            FOUNDATIONAL_LIB_MEMORY_ALLOCATOR_FREE(current->key);
            FOUNDATIONAL_LIB_MEMORY_ALLOCATOR_FREE(current);

            /* Update size */
            --dict->size;

            return;
        }

        /* Move to the next node in the linked list */
        prev = current;
        current = current->next;
    }
}

/**
 * @brief Adds a key-value pair to the dictionary.
 *
 * This function adds a new key-value pair to the provided dictionary. It
 * associates them in the dictionary.
 *
 * @param dict A pointer to the dictionary instance.
 * @param key The key to be added.
 * @param value A pointer to the value to be associated with the key.
 *
 * @return Returns -1 on error, 0 on success.
 */
FOUNDATIONAL_LIB_NONNULL FOUNDATIONAL_LIB_NOTHROW FOUNDATIONAL_LIB_FUNC int dict_add(struct Dict *dict, const char *key, void *value)
{

    FOUNDATIONAL_LIB_ASSERT_ARGUMENT_IF_ENABLED(dict);
    FOUNDATIONAL_LIB_ASSERT_ARGUMENT_IF_ENABLED(key);
    FOUNDATIONAL_LIB_ASSERT_ARGUMENT_IF_ENABLED(value);
    if ((double)dict->size / dict->capacity > FOUNDATIONAL_LIB_HASH_LOAD_FACTOR_THRESHOLD)
    {
        if (FOUNDATIONAL_LIB_UNLIKELY(dict_resize(dict) == -1))
        {
            // Don't need to re die aggressively if enabled here because dict resize
            // does it.
            return -1;
        }
    }

    const size_t index = dict_hash(key, dict->capacity);

    struct DictKeyValue *new_pair = (struct DictKeyValue *)FOUNDATIONAL_LIB_MEMORY_ALLOCATOR_MALLOC(sizeof(struct DictKeyValue));
    if (FOUNDATIONAL_LIB_UNLIKELY(new_pair == NULL))
    {
        /* Keep the old key if there was one. */
        FOUNDATIONAL_LIB_die_aggressively_if_enabled();
        return -1;
    }

    new_pair->key = FOUNDATIONAL_LIB_MEMORY_ALLOCATOR_STRDUP(key);
    if (FOUNDATIONAL_LIB_UNLIKELY(new_pair->key == NULL))
    {
        FOUNDATIONAL_LIB_MEMORY_ALLOCATOR_FREE(new_pair);
        FOUNDATIONAL_LIB_die_aggressively_if_enabled();
        return -1;
    }
    new_pair->next = dict->table[index];
    new_pair->value = value;

    /* If there is a hash collision */
    if (dict->table[index] != NULL)
    {
        struct DictKeyValue *current = new_pair->next; // First one
        struct DictKeyValue *prev = new_pair;          // New one
        /* Traverse the linked list to check for duplicates */
        do
        {
            /* This should only ever happen once unless the dict is corrupt, so we return. */
            if (FOUNDATIONAL_LIB_STRCMP(current->key, key) == 0)
            {
                prev->next = current->next;
                /* Duplicate key found */
                FOUNDATIONAL_LIB_MEMORY_ALLOCATOR_FREE(current->key);
                FOUNDATIONAL_LIB_MEMORY_ALLOCATOR_FREE(current);
                /* Dont increment size */
                /* Assume the list only has 1 key with the value (it should unless
                 * something is really wrong). */
                goto end;
            }

            prev = current;
            current = current->next;
        } while (current != NULL);
    }
    ++dict->size;

end:
    dict->table[index] = new_pair;
    return 0;
}

/**
 * @brief Retrieves the value associated with the specified key from the
 * dictionary.
 *
 * This function retrieves the value associated with the provided key from the
 * dictionary. If the key is not found, it returns NULL. Note that this function
 * does not differentiate between a NULL value and the key not being present in
 * the dictionary. If such differentiation is needed, use dict_get_check(dict,
 * key, &key_is_in_dict), instead
 *
 * @param dict A pointer to the dictionary instance.
 * @param key The key for which the associated value is to be retrieved.
 *
 * @return Returns a pointer to the value associated with the key, or NULL if
 * the key is not found.
 */
FOUNDATIONAL_LIB_WARN_UNUSED_RESULT FOUNDATIONAL_LIB_NONNULL FOUNDATIONAL_LIB_NOTHROW FOUNDATIONAL_LIB_PURE FOUNDATIONAL_LIB_FUNC void *dict_get(struct Dict *dict, const char *key)
{
    FOUNDATIONAL_LIB_ASSERT_ARGUMENT_IF_ENABLED(dict);
    FOUNDATIONAL_LIB_ASSERT_ARGUMENT_IF_ENABLED(key);
    const size_t index = dict_hash(key, dict->capacity);
    struct DictKeyValue *current_pair = dict->table[index];

    while (current_pair != NULL)
    {
        if (FOUNDATIONAL_LIB_STRCMP(current_pair->key, key) == 0)
        {
            return current_pair->value;
        }

        // Hash collision, continue with linked list.
        current_pair = current_pair->next;
    }

    return NULL;
}

/**
 * @brief Retrieves the value associated with the specified key from the
 dictionary.
 *
 * This function retrieves the value associated with the provided key from the
 * dictionary. If the key is found, it sets key_is_in_dict to 1 (true) and
 returns
 * a pointer to the associated value. If the key is not present, it sets
 * key_is_in_dict to 0 (false) and returns NULL.
 *
 * @param dict A pointer to the dictionary instance.
 * @param key The key for which the associated value is to be retrieved.
 * @param key_is_in_dict A pointer to an integer that is set to 1 if the key is
 in the dictionary, and 0 if the key is not found.
 *
 * @return Returns a pointer to the value associated with
 *         the key if present, or NULL if the key is not found.
 */
FOUNDATIONAL_LIB_WARN_UNUSED_RESULT FOUNDATIONAL_LIB_NONNULL FOUNDATIONAL_LIB_NOTHROW FOUNDATIONAL_LIB_PURE FOUNDATIONAL_LIB_FUNC void *dict_get_check(struct Dict *dict, const char *key, int *key_is_in_dict)
{
    FOUNDATIONAL_LIB_ASSERT_ARGUMENT_IF_ENABLED(dict);
    FOUNDATIONAL_LIB_ASSERT_ARGUMENT_IF_ENABLED(key);
    FOUNDATIONAL_LIB_ASSERT_ARGUMENT_IF_ENABLED(key_is_in_dict);

    const size_t index = dict_hash(key, dict->capacity);
    struct DictKeyValue *current_pair = dict->table[index];

    while (current_pair != NULL)
    {
        if (FOUNDATIONAL_LIB_STRCMP(current_pair->key, key) == 0)
        {
            *key_is_in_dict = 1;
            return current_pair->value;
        }
        current_pair = current_pair->next;
    }

    *key_is_in_dict = 0;
    return NULL;
}

/**
 * @brief Deallocates memory associated with a frozen dictionary, freeing
 * resources.
 *
 * This function serves as the destructor for the provided frozen dictionary,
 * freeing the memory allocated for the immutable hash table and its elements.
 * It is important to call this function to prevent memory leaks when a frozen
 * dictionary is no longer needed.
 *
 * @param dict A pointer to the frozen dictionary instance to be deallocated.
 */
FOUNDATIONAL_LIB_NONNULL FOUNDATIONAL_LIB_NOTHROW FOUNDATIONAL_LIB_FUNC void frozen_dict_destructor(struct FrozenDict *dict)
{
    FOUNDATIONAL_LIB_ASSERT_ARGUMENT_IF_ENABLED(dict);
    dict_destructor((struct Dict *)dict);
}

/**
 * @brief Creates a new instance of a frozen dictionary.
 *
 * This function creates a new instance of a frozen dictionary, which is an
 * immutable hash table containing the specified key-value pairs. The key-value
 * pairs are provided as variable arguments with the format (const char *key,
 * void *value).
 *
 * @param num_pairs The number of key-value pairs provided as arguments.
 * @param ... Variable arguments representing key-value pairs.
 *
 * @return Returns a pointer to the newly created frozen dictionary instance.
 */
FOUNDATIONAL_LIB_WARN_UNUSED_RESULT FOUNDATIONAL_LIB_NONNULL FOUNDATIONAL_LIB_NOTHROW FOUNDATIONAL_LIB_MALLOC FOUNDATIONAL_LIB_FUNC struct FrozenDict *frozen_dict_new_instance(size_t num_pairs, ...)
{
    struct FrozenDict *frozen_dict = (struct FrozenDict *)FOUNDATIONAL_LIB_MEMORY_ALLOCATOR_MALLOC(sizeof(struct FrozenDict));
    if (FOUNDATIONAL_LIB_UNLIKELY(frozen_dict == NULL))
    {
        FOUNDATIONAL_LIB_die_aggressively_if_enabled();
        return NULL;
    }

    frozen_dict->capacity = num_pairs * FOUNDATIONAL_LIB_FROZEN_INITIALIZATION_SIZE_MULTIPLIER;
    frozen_dict->size = 0;
    frozen_dict->table = (struct DictKeyValue **)FOUNDATIONAL_LIB_MEMORY_ALLOCATOR_CALLOC(FOUNDATIONAL_LIB_HASH_INITIAL_CAPACITY, sizeof(struct DictKeyValue *));
    if (FOUNDATIONAL_LIB_UNLIKELY(frozen_dict->table == NULL))
    {
        FOUNDATIONAL_LIB_MEMORY_ALLOCATOR_FREE(frozen_dict);
        FOUNDATIONAL_LIB_die_aggressively_if_enabled();
        return NULL;
    }

    FOUNDATIONAL_LIB_VA_LIST args;
    FOUNDATIONAL_LIB_VA_START(args, num_pairs);

    for (size_t i = 0; i < num_pairs; ++i)
    {
        char *key;
        void *value;

        key = FOUNDATIONAL_LIB_VA_ARG(args, char *);
        value = FOUNDATIONAL_LIB_VA_ARG(args, void *);

        dict_add((struct Dict *)frozen_dict, key, value);
    }

    FOUNDATIONAL_LIB_VA_END(args); // Clean up the va_list

    return frozen_dict;
}

/**
 * @brief Retrieves the value associated with the specified key from the frozen
 * dictionary.
 *
 * This function retrieves the value associated with the provided key from the
 * immutable frozen dictionary. If the key is found, it returns a pointer to the
 * associated value; otherwise, it returns NULL.
 *
 * @param dict A pointer to the frozen dictionary instance.
 * @param key The key for which the associated value is to be retrieved.
 *
 * @return Returns a pointer to the value associated with the key if present, or
 * NULL if the key is not found.
 */
FOUNDATIONAL_LIB_WARN_UNUSED_RESULT FOUNDATIONAL_LIB_NONNULL FOUNDATIONAL_LIB_NOTHROW FOUNDATIONAL_LIB_PURE FOUNDATIONAL_LIB_FUNC void *frozen_dict_get(struct FrozenDict *dict, const char *key)
{
    FOUNDATIONAL_LIB_ASSERT_ARGUMENT_IF_ENABLED(dict);
    FOUNDATIONAL_LIB_ASSERT_ARGUMENT_IF_ENABLED(key);
    const size_t index = dict_hash(key, dict->capacity);
    struct DictKeyValue *current_pair = dict->table[index];

    while (current_pair != NULL)
    {
        if (FOUNDATIONAL_LIB_STRCMP(current_pair->key, key) == 0)
        {
            return current_pair->value;
        }
        current_pair = current_pair->next;
    }

    return NULL;
}

/**
 * @brief Retrieves the value associated with the specified key from the frozen
 * dictionary.
 *
 * This function retrieves the value associated with the provided key from the
 * immutable frozen dictionary. If the key is found, it returns a pointer to the
 * associated value and sets key_is_in_dict to 1 (true); otherwise, it returns
 * NULL and sets key_is_in_dict to 0 (false).
 *
 * @param dict A pointer to the frozen dictionary instance.
 * @param key The key for which the associated value is to be retrieved.
 * @param key_is_in_dict A pointer to an integer that is set to 1 if the key is
 * in the dictionary, and 0 if the key is not found.
 *
 * @return Returns a pointer to the value associated with the key if present, or
 * NULL if the key is not found.
 */
FOUNDATIONAL_LIB_WARN_UNUSED_RESULT FOUNDATIONAL_LIB_NONNULL FOUNDATIONAL_LIB_NOTHROW FOUNDATIONAL_LIB_PURE FOUNDATIONAL_LIB_FUNC void *frozen_dict_get_check(struct FrozenDict *dict, const char *key, int *key_is_in_dict)
{
    FOUNDATIONAL_LIB_ASSERT_ARGUMENT_IF_ENABLED(dict);
    FOUNDATIONAL_LIB_ASSERT_ARGUMENT_IF_ENABLED(key);
    FOUNDATIONAL_LIB_ASSERT_ARGUMENT_IF_ENABLED(key_is_in_dict);

    const size_t index = dict_hash(key, dict->capacity);
    struct DictKeyValue *current_pair = dict->table[index];

    while (current_pair != NULL)
    {
        if (FOUNDATIONAL_LIB_STRCMP(current_pair->key, key) == 0)
        {
            *key_is_in_dict = 1;
            return current_pair->value;
        }
        current_pair = current_pair->next;
    }

    *key_is_in_dict = 0;
    return NULL;
}

/**
 * @brief Iterates through the key-value pairs in the dictionary, applying a
 * callback function.
 *
 * This function iterates through the key-value pairs in the provided dictionary
 * and applies the specified callback function to each pair. The callback
 * function takes a key and a value as parameters and is applied for each
 * element in the dictionary.
 *
 * @param dict A pointer to the dictionary instance.
 * @param callback A function pointer to the callback function taking a key and
 * a value as parameters.
 */
FOUNDATIONAL_LIB_NONNULL FOUNDATIONAL_LIB_NOTHROW FOUNDATIONAL_LIB_FUNC void dict_iter(struct Dict *dict, void (*callback)(char *key, void *value))
{
    FOUNDATIONAL_LIB_ASSERT_ARGUMENT_IF_ENABLED(dict);
    FOUNDATIONAL_LIB_ASSERT_ARGUMENT_IF_ENABLED(callback);

    for (size_t i = 0; i < dict->capacity; ++i)
    {
        struct DictKeyValue *current = dict->table[i];

        while (current != NULL)
        {
            /* Call the callback function with the key and value */
            callback(current->key, current->value);

            /* Move to the next node in the linked list */
            current = current->next;
        }
    }
}

/**
 * @brief Iterates through the key-value pairs in the FrozenDict, applying a
 * callback function.
 *
 * This function iterates through the key-value pairs in the provided FrozenDict
 * and applies the specified callback function to each pair. The callback
 * function takes a key and a value as parameters and is applied for each
 * element in the FrozenDict.
 *
 * @param dict A pointer to the FrozenDict instance.
 * @param callback A function pointer to the callback function taking a key and
 * a value as parameters.
 */
FOUNDATIONAL_LIB_NONNULL FOUNDATIONAL_LIB_NOTHROW FOUNDATIONAL_LIB_FUNC void frozen_dict_iter(struct FrozenDict *frozen_dict, void (*callback)(char *key, void *value))
{
    FOUNDATIONAL_LIB_ASSERT_ARGUMENT_IF_ENABLED(frozen_dict);
    FOUNDATIONAL_LIB_ASSERT_ARGUMENT_IF_ENABLED(callback);
    for (size_t i = 0; i < frozen_dict->capacity; ++i)
    {
        struct DictKeyValue *current = frozen_dict->table[i];

        while (current != NULL)
        {
            /* Call the callback function with the key and value */
            callback(current->key, current->value);

            /* Move to the next node in the linked list */
            current = current->next;
        }
    }
}
/**
 * @brief Returns the number of key-value pairs in the dictionary.
 *
 * This function returns the current size, representing the number of key-value
 * pairs, in the provided dictionary.
 *
 * @param dict A pointer to the dictionary instance.
 *
 * @return Returns the number of key-value pairs in the dictionary.
 */
FOUNDATIONAL_LIB_WARN_UNUSED_RESULT FOUNDATIONAL_LIB_NONNULL FOUNDATIONAL_LIB_NOTHROW FOUNDATIONAL_LIB_PURE FOUNDATIONAL_LIB_FUNC size_t dict_size(struct Dict *dict)
{

    FOUNDATIONAL_LIB_ASSERT_ARGUMENT_IF_ENABLED(dict);
    return dict->size;
}

/**
 * @brief Returns the number of key-value pairs in the frozen dictionary.
 *
 * This function returns the current size, representing the number of key-value
 * pairs, in the provided frozen dictionary.
 *
 * @param dict A pointer to the frozen dictionary instance.
 *
 * @return Returns the number of key-value pairs in the frozen dictionary.
 */
FOUNDATIONAL_LIB_WARN_UNUSED_RESULT FOUNDATIONAL_LIB_NONNULL FOUNDATIONAL_LIB_NOTHROW FOUNDATIONAL_LIB_PURE FOUNDATIONAL_LIB_FUNC size_t frozen_dict_size(struct FrozenDict *dict)
{
    FOUNDATIONAL_LIB_ASSERT_ARGUMENT_IF_ENABLED(dict);

    return dict->size;
}

/**
 * @brief Converts the key-value pairs from the dictionary into separate arrays
 * for keys and values.
 *
 * This function converts the key-value pairs from the provided dictionary into
 * separate arrays for keys and values. The resulting arrays are allocated
 * dynamically and should be freed by the caller when no longer needed. The
 * size_of_keys_and_values parameter is set to the number of key-value pairs in
 * the dictionary.
 *
 * @param dict A pointer to the dictionary instance.
 * @param keys A pointer to store the dynamically allocated array of keys.
 * @param values A pointer to store the dynamically allocated array of values.
 * @param size_of_keys_and_values A pointer to store the size of the resulting
 * arrays.
 *
 * @return Returns -1 on error, 0 on success.
 *
 * @note The caller is responsible for freeing the memory allocated for keys and
 * values arrays using dict_del_keys() and dict_del_values() (or just free() -
 * these have the same effect) when they are no longer needed.
 */
FOUNDATIONAL_LIB_WARN_UNUSED_RESULT FOUNDATIONAL_LIB_NONNULL FOUNDATIONAL_LIB_NOTHROW FOUNDATIONAL_LIB_FUNC int dict_to_array(struct Dict *dict, char ***keys, void ***values, size_t *size_of_keys_and_values)
{
    FOUNDATIONAL_LIB_ASSERT_ARGUMENT_IF_ENABLED(dict);
    FOUNDATIONAL_LIB_ASSERT_ARGUMENT_IF_ENABLED(keys);
    FOUNDATIONAL_LIB_ASSERT_ARGUMENT_IF_ENABLED(values);
    FOUNDATIONAL_LIB_ASSERT_ARGUMENT_IF_ENABLED(size_of_keys_and_values);

    const size_t alloc_size1 = FOUNDATIONAL_LIB_safe_mul(dict->size, sizeof(char *));
    if (FOUNDATIONAL_LIB_UNLIKELY(alloc_size1 == 0))
        goto overflow;
    size_t alloc_size2;

    alloc_size2 = FOUNDATIONAL_LIB_safe_mul(dict->size, sizeof(void *));
    if (FOUNDATIONAL_LIB_UNLIKELY(alloc_size2 == 0))
        goto overflow;

    *keys = (char **)FOUNDATIONAL_LIB_MEMORY_ALLOCATOR_MALLOC(alloc_size1);
    if (FOUNDATIONAL_LIB_UNLIKELY(*keys == NULL))
        goto error_handler;

    *values = (void **)FOUNDATIONAL_LIB_MEMORY_ALLOCATOR_MALLOC(alloc_size2);

    if (FOUNDATIONAL_LIB_UNLIKELY(*values == NULL))
    {
        FOUNDATIONAL_LIB_MEMORY_ALLOCATOR_FREE(*keys);
        *keys = NULL;
        // Values is already NULL here.
        goto error_handler;
    }

    for (size_t i = 0, index = 0; i < dict->capacity; ++i)
    {
        struct DictKeyValue *current_pair = dict->table[i];
        while (current_pair != NULL)
        {
            (*keys)[index] = (current_pair->key);
            (*values)[index] = current_pair->value;

            ++index;
            current_pair = current_pair->next;
        }
    }

    *size_of_keys_and_values = dict->size;

    return 0;

overflow:
error_handler:

    FOUNDATIONAL_LIB_die_aggressively_if_enabled();
    return -1;
}

/**
 * @brief Converts the key-value pairs from the frozen dictionary into separate
 * arrays for keys and values.
 *
 * This function converts the key-value pairs from the provided frozen
 * dictionary into separate arrays for keys and values. The resulting arrays are
 * allocated dynamically and should be freed by the caller when no longer
 * needed. The size_of_keys_and_values parameter is set to the number of
 * key-value pairs in the frozen dictionary.
 *
 * @param dict A pointer to the frozen dictionary instance.
 * @param keys A pointer to store the dynamically allocated array of keys.
 * @param values A pointer to store the dynamically allocated array of values.
 * @param size_of_keys_and_values A pointer to store the size of the resulting
 * arrays.
 *
 * @return Returns -1 on error, 0 on success.
 *
 * @note The caller is responsible for freeing the memory allocated for keys and
 * values arrays using dict_del_keys() and dict_del_values() (or just free() -
 * these have the same effect) when they are no longer needed.
 */
FOUNDATIONAL_LIB_WARN_UNUSED_RESULT FOUNDATIONAL_LIB_NONNULL FOUNDATIONAL_LIB_NOTHROW FOUNDATIONAL_LIB_FUNC size_t frozen_dict_to_array(struct FrozenDict *dict, char ***keys, void ***values, size_t *size_of_keys_and_values)
{

    FOUNDATIONAL_LIB_ASSERT_ARGUMENT_IF_ENABLED(dict);
    FOUNDATIONAL_LIB_ASSERT_ARGUMENT_IF_ENABLED(keys);
    FOUNDATIONAL_LIB_ASSERT_ARGUMENT_IF_ENABLED(values);
    FOUNDATIONAL_LIB_ASSERT_ARGUMENT_IF_ENABLED(size_of_keys_and_values);

    const size_t alloc_size1 = FOUNDATIONAL_LIB_safe_mul(dict->size, sizeof(char *));
    if (FOUNDATIONAL_LIB_UNLIKELY(alloc_size1 == 0))
        goto overflow;
    size_t alloc_size2;

    alloc_size2 = FOUNDATIONAL_LIB_safe_mul(dict->size, sizeof(void *));
    if (FOUNDATIONAL_LIB_UNLIKELY(alloc_size2 == 0))
        goto overflow;

    *keys = (char **)FOUNDATIONAL_LIB_MEMORY_ALLOCATOR_MALLOC(alloc_size1);
    if (FOUNDATIONAL_LIB_UNLIKELY(*keys == NULL))
        goto error_handler;

    *values = (void **)FOUNDATIONAL_LIB_MEMORY_ALLOCATOR_MALLOC(alloc_size2);

    if (FOUNDATIONAL_LIB_UNLIKELY(*values == NULL))
    {
        FOUNDATIONAL_LIB_MEMORY_ALLOCATOR_FREE(*keys);
        *keys = NULL;
        // Values is already NULL here.
        goto error_handler;
    }

    for (size_t i = 0, index = 0; i < dict->capacity; ++i)
    {
        struct DictKeyValue *current_pair = dict->table[i];
        while (current_pair != NULL)
        {
            (*keys)[index] = (current_pair->key);
            (*values)[index] = current_pair->value;

            ++index;
            current_pair = current_pair->next;
        }
    }

    *size_of_keys_and_values = dict->size;

    return 0;

overflow:
error_handler:

    FOUNDATIONAL_LIB_die_aggressively_if_enabled();
    return -1;
}

/**
 * @brief Deallocates memory associated with an array of keys.
 *
 * This function serves as the destructor for an array of Dict keys, freeing the
 * memory allocated for the array. It is functionally identical to just calling
 * free().
 *
 * @param keys A pointer to the array of keys to be deallocated.
 */
FOUNDATIONAL_LIB_NONNULL FOUNDATIONAL_LIB_NOTHROW void dict_del_keys(char **keys)
{

    FOUNDATIONAL_LIB_ASSERT_ARGUMENT_IF_ENABLED(keys);
    FOUNDATIONAL_LIB_MEMORY_ALLOCATOR_FREE(keys);
}

/**
 * @brief Deallocates memory associated with an array of values.
 *
 * This function serves as the destructor for an array of Dict values, freeing
 * the memory allocated for the array. It is functionally identical to just
 * calling free().
 *
 * @param keys A pointer to the array of keys to be deallocated.
 */
FOUNDATIONAL_LIB_NONNULL FOUNDATIONAL_LIB_NOTHROW void dict_del_values(void **values)
{
    FOUNDATIONAL_LIB_ASSERT_ARGUMENT_IF_ENABLED(values);
    FOUNDATIONAL_LIB_MEMORY_ALLOCATOR_FREE(values);
}

/**
 * @brief Converts a dictionary to a string representation.
 *
 * This function converts the provided dictionary to a string representation.
 * The resulting string can either contain pointers to the key-value pairs
 * (pointer format) or the actual key-value pairs as strings (string format).
 * The choice is determined by the pointer_or_string parameter, where 0
 * represents the pointer format and 1 represents the string format.
 *
 * @param dict A pointer to the dictionary instance.
 * @param pointer_or_string Determines the format of the resulting string (0 =
 * pointer, 1 = string).
 *
 * @return Returns a dynamically allocated string representing the dictionary.
 *
 * @note The caller is responsible for freeing the memory allocated for the
 * resulting string using free() when it is no longer needed.
 */
FOUNDATIONAL_LIB_WARN_UNUSED_RESULT FOUNDATIONAL_LIB_NONNULL FOUNDATIONAL_LIB_NOTHROW FOUNDATIONAL_LIB_MALLOC FOUNDATIONAL_LIB_FUNC char *dict_to_string(struct Dict *dict, int pointer_or_string) /* 0 = pointer, 1 = string */
{
    FOUNDATIONAL_LIB_ASSERT_ARGUMENT_IF_ENABLED(dict);
    FOUNDATIONAL_LIB_ASSERT_ARGUMENT_IF_ENABLED(pointer_or_string == 0 || pointer_or_string == 1);

    /* Allocate memory for the string representation */
    size_t total_length = 2;
    for (size_t i = 0; i < dict->capacity; ++i)
    {
        struct DictKeyValue *current_pair = dict->table[i];
        while (current_pair != NULL)
        {
            /* Calculate the length of the string representation for each key-value
             * pair */
            total_length += FOUNDATIONAL_LIB_STRLEN(current_pair->key) + 2; // 2 for ": "
            if (pointer_or_string == 0)
            {
                total_length += FOUNDATIONAL_LIB_SNPRINTF(NULL, 0, "%p",
                                                          current_pair->value); // Calculate the length of the value string
            }
            else
            {
                total_length += FOUNDATIONAL_LIB_SNPRINTF(NULL, 0, "%s",
                                                          (char *)current_pair->value); // Calculate the length of the value string
            }
            total_length += 2; // 2 for ", "
            current_pair = current_pair->next;
        }
    }

    // Should not reach SIZE_MAX

    // Add 1 for the null-terminator, at least 3 chars additional
    char *result = (char *)FOUNDATIONAL_LIB_MEMORY_ALLOCATOR_MALLOC(total_length + sizeof("")); /* Should be Safe. */
    if (FOUNDATIONAL_LIB_UNLIKELY(result == NULL))
    {
        FOUNDATIONAL_LIB_die_aggressively_if_enabled();
        return NULL;
    }

    result[0] = '{';
    size_t index = 1;

    for (size_t i = 0; i < dict->capacity; ++i)
    {
        struct DictKeyValue *current_pair = dict->table[i];
        while (current_pair != NULL)
        {
            /* Append the key and value to the string representation */
            if (pointer_or_string == 0)
            {
                index += FOUNDATIONAL_LIB_SNPRINTF(result + index, total_length - index, "%s: %p", current_pair->key, current_pair->value);
            }
            else if (pointer_or_string == 1)
            {
                index += FOUNDATIONAL_LIB_SNPRINTF(result + index, total_length - index, "%s: %s", current_pair->key, (char *)current_pair->value);
            }
            current_pair = current_pair->next;

            /* Add a separator (comma) if there are more elements */
            if (index < total_length - 2)
            {
                result[index++] = ',';
                result[index++] = ' ';
            }
        }
    }

    if (dict->capacity)
    {
        index -= 2;
    }

    result[index++] = '}';
    result[index++] = '\0'; // Null-terminate the string
    return result;
}

/**
 * @brief Converts a FrozenDict (frozen dictionary) to a string representation.
 *
 * This function converts the provided frozen dictionary to a string
 * representation. The resulting string can either contain pointers to the
 * key-value pairs (pointer format) or the actual key-value pairs as strings
 * (string format). The choice is determined by the pointer_or_string parameter,
 * where 0 represents the pointer format and 1 represents the string format.
 *
 * @param dict A pointer to the frozen dictionary instance.
 * @param pointer_or_string Determines the format of the resulting string (0 =
 * pointer, 1 = string).
 *
 * @return Returns a dynamically allocated string representing the frozen
 * dictionary.
 *
 * @note The caller is responsible for freeing the memory allocated for the
 * resulting string using free() when it is no longer needed.
 */
FOUNDATIONAL_LIB_WARN_UNUSED_RESULT FOUNDATIONAL_LIB_NONNULL FOUNDATIONAL_LIB_NOTHROW FOUNDATIONAL_LIB_MALLOC FOUNDATIONAL_LIB_FUNC char *frozen_dict_to_string(struct FrozenDict *dict, int pointer_or_string) /* 0 = pointer, 1 = string */
{
    FOUNDATIONAL_LIB_ASSERT_ARGUMENT_IF_ENABLED(dict);
    FOUNDATIONAL_LIB_ASSERT_ARGUMENT_IF_ENABLED(pointer_or_string == 0 || pointer_or_string == 1);
    /* Allocate memory for the string representation */
    size_t total_length = 2;
    for (size_t i = 0; i < dict->capacity; ++i)
    {
        struct DictKeyValue *current_pair = dict->table[i];
        while (current_pair != NULL)
        {
            /* Calculate the length of the string representation for each key-value
             * pair */
            total_length += FOUNDATIONAL_LIB_STRLEN(current_pair->key) + 2; // 2 for ": "

            if (pointer_or_string == 0)
            {
                total_length += FOUNDATIONAL_LIB_SNPRINTF(NULL, 0, "%p",
                                                          current_pair->value); // Calculate the length of the value string
            }
            else
            {
                total_length += FOUNDATIONAL_LIB_SNPRINTF(NULL, 0, "%s",
                                                          (char *)current_pair->value); // Calculate the length of the value string
            }
            total_length += 2; // 2 for ", "
            current_pair = current_pair->next;
        }
    }

    // Should not reach SIZE_MAX

    // Add 1 for the null-terminator, at least 3 chars additional
    char *result = (char *)FOUNDATIONAL_LIB_MEMORY_ALLOCATOR_MALLOC(total_length + sizeof("")); /* Safe. */
    if (FOUNDATIONAL_LIB_UNLIKELY(result == NULL))
    {
        FOUNDATIONAL_LIB_die_aggressively_if_enabled();
        return NULL;
    }

    result[0] = '{';
    size_t index = 1;

    for (size_t i = 0; i < dict->capacity; ++i)
    {
        struct DictKeyValue *current_pair = dict->table[i];
        while (current_pair != NULL)
        {
            /* Append the key and value to the string representation */
            if (pointer_or_string == 0)
            {
                index += FOUNDATIONAL_LIB_SNPRINTF(result + index, total_length - index, "%s: %p", current_pair->key, current_pair->value);
            }
            else if (pointer_or_string == 1)
            {
                index += FOUNDATIONAL_LIB_SNPRINTF(result + index, total_length - index, "%s: %s", current_pair->key, (char *)current_pair->value);
            }
            current_pair = current_pair->next;

            /* Add a separator (comma) if there are more elements */
            if (index < total_length - 2)
            {
                result[index++] = ',';
                result[index++] = ' ';
            }
        }
    }

    if (dict->capacity)
    {
        index -= 2;
    }

    result[index++] = '}';
    result[index++] = '\0'; // Null-terminate the string
    return result;
}

/**
 * @brief Deletes keys from a frozen dictionary.
 *
 * This function deletes keys from a frozen dictionary.
 *
 * @param keys The keys to delete.
 */
FOUNDATIONAL_LIB_NONNULL FOUNDATIONAL_LIB_NOTHROW void frozen_dict_del_keys(char **keys)
{
    FOUNDATIONAL_LIB_ASSERT_ARGUMENT_IF_ENABLED(keys);
    FOUNDATIONAL_LIB_MEMORY_ALLOCATOR_FREE(keys);
}

/**
 * @brief Deletes values from a frozen dictionary.
 *
 * This function deletes values from a frozen dictionary.
 *
 * @param values The values to delete.
 */
FOUNDATIONAL_LIB_NONNULL FOUNDATIONAL_LIB_NOTHROW void frozen_dict_del_values(void **values)
{
    FOUNDATIONAL_LIB_ASSERT_ARGUMENT_IF_ENABLED(values);
    FOUNDATIONAL_LIB_MEMORY_ALLOCATOR_FREE(values);
}

/**
 * @brief The destructor for a Set.
 *
 * This function sets the destructor for a Set data structure.
 *
 * @param set The Set data structure.
 */
FOUNDATIONAL_LIB_NONNULL FOUNDATIONAL_LIB_NOTHROW FOUNDATIONAL_LIB_FUNC void set_destructor(struct Set *set)
{
    FOUNDATIONAL_LIB_ASSERT_ARGUMENT_IF_ENABLED(set);

    for (size_t i = 0; i < set->capacity; ++i)
    {
        struct SetKey *current_key = set->table[i];
        while (current_key != NULL)
        {
            struct SetKey *next_key = current_key->next;
            FOUNDATIONAL_LIB_MEMORY_ALLOCATOR_FREE(current_key->key);
            FOUNDATIONAL_LIB_MEMORY_ALLOCATOR_FREE(current_key);
            current_key = next_key;
        }
    }
    FOUNDATIONAL_LIB_MEMORY_ALLOCATOR_FREE(set->table);
    FOUNDATIONAL_LIB_MEMORY_ALLOCATOR_FREE(set);
}

/**
 * @brief Creates a new instance of a Set.
 *
 * This function creates a new instance of a Set data structure.
 *
 * @return Returns a pointer to the new Set instance.
 */
FOUNDATIONAL_LIB_WARN_UNUSED_RESULT FOUNDATIONAL_LIB_NONNULL FOUNDATIONAL_LIB_NOTHROW FOUNDATIONAL_LIB_MALLOC FOUNDATIONAL_LIB_FUNC struct Set *set_new_instance(void)
{
    struct Set *set = (struct Set *)FOUNDATIONAL_LIB_MEMORY_ALLOCATOR_MALLOC(sizeof(struct Set));
    if (FOUNDATIONAL_LIB_UNLIKELY(set == NULL))
    {
        FOUNDATIONAL_LIB_die_aggressively_if_enabled();
        return NULL;
    }

    set->capacity = FOUNDATIONAL_LIB_HASH_INITIAL_CAPACITY;
    set->size = 0;
    set->table = (struct SetKey **)FOUNDATIONAL_LIB_MEMORY_ALLOCATOR_CALLOC(FOUNDATIONAL_LIB_HASH_INITIAL_CAPACITY, sizeof(struct SetKey *));
    if (FOUNDATIONAL_LIB_UNLIKELY(set->table == NULL))
    {
        FOUNDATIONAL_LIB_MEMORY_ALLOCATOR_FREE(set);
        FOUNDATIONAL_LIB_die_aggressively_if_enabled();
        return NULL;
    }

    return set;
}

/**
 * @brief Hashes a null-terminated string using the djb2 algorithm.
 *
 * The djb2 hash function is a simple and effective algorithm for hashing
 * strings. It iterates over each character in the input string, combining the
 * current hash value with the ASCII value of the character using the formula
 * `hash = (hash << 5) + hash + c`. The algorithm is known for its simplicity,
 * good distribution properties, and reduced likelihood of collisions.
 *
 * @param key Pointer to the null-terminated character array (string) used as
 * the key.
 * @param capacity Capacity of the hash table.
 * @return The computed hash value within the specified capacity.
 */
FOUNDATIONAL_LIB_WARN_UNUSED_RESULT FOUNDATIONAL_LIB_NONNULL FOUNDATIONAL_LIB_NOTHROW FOUNDATIONAL_LIB_PURE FOUNDATIONAL_LIB_FUNC size_t set_hash(const char *key, size_t capacity)
{
    FOUNDATIONAL_LIB_ASSERT_ARGUMENT_IF_ENABLED(key);
    size_t hash = 5381; // Initial hash value
    int c;              // Variable to store the current character

    while ((c = *key++))
    {
        hash = ((hash << 5) + hash) + c; /* hash * 33 + c */
    }

    return hash % capacity;
}

/**
 * @brief Resizes a Set data structure.
 *
 * This function resizes a Set data structure.
 *
 * @param dict The Set data structure to resize.
 * @return Returns 1 on success, 0 on failure.
 */
FOUNDATIONAL_LIB_WARN_UNUSED_RESULT FOUNDATIONAL_LIB_NONNULL FOUNDATIONAL_LIB_NOTHROW FOUNDATIONAL_LIB_FUNC int set_resize(struct Set *set)
{
    FOUNDATIONAL_LIB_ASSERT_ARGUMENT_IF_ENABLED(set);

    const size_t new_capacity = FOUNDATIONAL_LIB_REALLOC_REALLOCATION_ALGORITHM(set->capacity);
    if (FOUNDATIONAL_LIB_UNLIKELY(new_capacity == 0)) // Overflow.
    {
        FOUNDATIONAL_LIB_die_aggressively_if_enabled();
        return -1;
    }
    /* Either calloc or realloc would be ideal here, but, if the block is large,
       then calloc might be better because there might be a cleared block of
       memory that is very large that is readily available. */
    struct SetKey **new_table = (struct SetKey **)FOUNDATIONAL_LIB_MEMORY_ALLOCATOR_CALLOC(new_capacity, sizeof(struct SetKey *));
    if (FOUNDATIONAL_LIB_UNLIKELY(new_table == NULL))
    {
        set_destructor(set);
        FOUNDATIONAL_LIB_die_aggressively_if_enabled();
        return -1;
    }

    for (size_t i = 0; i < set->capacity; ++i)
    {
        struct SetKey *current_key = set->table[i];
        while (current_key)
        {
            struct SetKey *next_key = current_key->next;
            const size_t new_index = set_hash(current_key->key, new_capacity);
            current_key->next = new_table[new_index];
            new_table[new_index] = current_key;
            current_key = next_key;
        }
    }

    FOUNDATIONAL_LIB_MEMORY_ALLOCATOR_FREE(set->table);
    set->table = new_table;
    set->capacity = new_capacity;

    return 0;
}

/**
 * @brief Deletes a key from a Set.
 *
 * This function deletes a key from a Set data structure.
 *
 * @param set The Set data structure.
 * @param key The key to delete.
 */
FOUNDATIONAL_LIB_NONNULL FOUNDATIONAL_LIB_NOTHROW FOUNDATIONAL_LIB_FUNC void set_del_key(struct Set *set, const char *key)
{
    FOUNDATIONAL_LIB_ASSERT_ARGUMENT_IF_ENABLED(set);
    FOUNDATIONAL_LIB_ASSERT_ARGUMENT_IF_ENABLED(key);

    const size_t index = set_hash(key, set->capacity);

    struct SetKey *current = set->table[index];
    struct SetKey *prev = NULL;

    while (current != NULL)
    {
        if (FOUNDATIONAL_LIB_STRCMP(current->key, key) == 0)
        {
            /* Key found, remove the entry */
            if (prev == NULL)
            {
                /* If it's the first node in the linked list */
                set->table[index] = current->next;
            }
            else
            {
                prev->next = current->next;
            }

            /* Free memory */
            FOUNDATIONAL_LIB_MEMORY_ALLOCATOR_FREE(current->key);
            FOUNDATIONAL_LIB_MEMORY_ALLOCATOR_FREE(current);

            /* Update size */
            --set->size;

            return;
        }

        /* Move to the next node in the linked list */
        prev = current;
        current = current->next;
    }
}

/**
 * @brief Adds a key pair to the set.
 *
 * This function adds a new key-value pair to the provided set. It associates
 * them in the setionary.
 *
 * @param set A pointer to the setionary instance.
 * @param key The key to be added.
 *
 * @return Returns -1 on error, 0 on success.
 */
FOUNDATIONAL_LIB_NONNULL FOUNDATIONAL_LIB_NOTHROW FOUNDATIONAL_LIB_FUNC int set_add(struct Set *set, const char *key)
{
    FOUNDATIONAL_LIB_ASSERT_ARGUMENT_IF_ENABLED(set);
    FOUNDATIONAL_LIB_ASSERT_ARGUMENT_IF_ENABLED(key);

    if ((double)set->size / set->capacity > FOUNDATIONAL_LIB_HASH_LOAD_FACTOR_THRESHOLD)
    {
        if (FOUNDATIONAL_LIB_UNLIKELY(set_resize(set) == -1))
        {
            // Don't need to re die aggressively if enabled here because set resize does it.
            return -1;
        }
    }

    const size_t index = set_hash(key, set->capacity);

    struct SetKey *new_set_key = (struct SetKey *)FOUNDATIONAL_LIB_MEMORY_ALLOCATOR_MALLOC(sizeof(struct SetKey));
    if (FOUNDATIONAL_LIB_UNLIKELY(new_set_key == NULL))
    {
        /* Keep the old key if there was one. */
        FOUNDATIONAL_LIB_die_aggressively_if_enabled();
        return -1;
    }

    new_set_key->key = FOUNDATIONAL_LIB_MEMORY_ALLOCATOR_STRDUP(key);
    if (FOUNDATIONAL_LIB_UNLIKELY(new_set_key->key == NULL))
    {
        FOUNDATIONAL_LIB_MEMORY_ALLOCATOR_FREE(new_set_key);
        FOUNDATIONAL_LIB_die_aggressively_if_enabled();
        return -1;
    }
    new_set_key->next = set->table[index];

    /* If there is a hash collision */
    if (set->table[index] != NULL)
    {
        struct SetKey *current = new_set_key->next; // First one
        struct SetKey *prev = new_set_key;          // New one
        /* Traverse the linked list to check for duplicates */
        do
        {
            /* This should only ever happen once unless the set is corrupt, so we return. */

            if (FOUNDATIONAL_LIB_STRCMP(current->key, key) == 0)
            { /* Duplicate key found */
                prev->next = current->next;

                // Free the old key
                FOUNDATIONAL_LIB_MEMORY_ALLOCATOR_FREE(current->key);
                FOUNDATIONAL_LIB_MEMORY_ALLOCATOR_FREE(current);

                /* Dont increment size */
                /* Assume the list only has 1 key with the value (it should unless
                 * something is really wrong). */

                goto end;
            }

            prev = current;
            current = current->next;
        } while (current != NULL);
    }

    ++set->size;
end:
    set->table[index] = new_set_key;
    return 0;
}

/**
 * @brief Reserves additional space in a Set for anticipated new elements.
 *
 * This function reserves additional space in the provided Set's internal hash
 * table to accommodate an anticipated number of new elements. The reservation
 * helps avoid frequent resizes, optimizing performance when a known number of
 * new elements is expected. Calling this function will trigger a resize and
 * rehash of the Set, but it will only happen (ideally) once, if you
 * accurately predict the future size of the Set.
 *
 * @param set A pointer to the Set instance for which space is to be reserved.
 * @param number_of_new_elements_max_one_is_expecting The anticipated number of
 * new elements (above the current capacity).
 *
 * @return Returns 0 on success, -1 on failure.
 */
FOUNDATIONAL_LIB_WARN_UNUSED_RESULT FOUNDATIONAL_LIB_NONNULL FOUNDATIONAL_LIB_NOTHROW FOUNDATIONAL_LIB_FUNC int set_reserve_more(struct Set *set, size_t number_of_new_elements_max_one_is_expecting)
{
    FOUNDATIONAL_LIB_ASSERT_ARGUMENT_IF_ENABLED(set);

    const size_t new_capacity = FOUNDATIONAL_LIB_safe_add_2(set->capacity, number_of_new_elements_max_one_is_expecting);
    if (FOUNDATIONAL_LIB_UNLIKELY(new_capacity == 0)) // Overflow.
    {
        FOUNDATIONAL_LIB_die_aggressively_if_enabled();
        return -1;
    }
    /* Either calloc or realloc would be ideal here, but, if the block is large,
       then calloc might be better because there might be a cleared block of
       memory that is very large that is readily available. */
    struct SetKey **new_table = (struct SetKey **)FOUNDATIONAL_LIB_MEMORY_ALLOCATOR_CALLOC(new_capacity, sizeof(struct SetKey *));
    if (FOUNDATIONAL_LIB_UNLIKELY(new_table == NULL))
    {
        FOUNDATIONAL_LIB_die_aggressively_if_enabled();
        return -1;
    }

    for (size_t i = 0; i < set->capacity; ++i)
    {
        struct SetKey *current_key = set->table[i];
        while (current_key)
        {
            struct SetKey *next_key = current_key->next;
            const size_t new_index = set_hash(current_key->key, new_capacity);
            current_key->next = new_table[new_index];
            new_table[new_index] = current_key;
            current_key = next_key;
        }
    }

    FOUNDATIONAL_LIB_MEMORY_ALLOCATOR_FREE(set->table);
    set->table = new_table;
    set->capacity = new_capacity;

    return 0;
}

/**
 * @brief Checks if a key is in a Set.
 *
 * This function checks if a key is present in a Set.
 *
 * @param set The Set data structure.
 * @param key The key to check.
 * @return Returns 1 if the key is present, 0 otherwise.
 */
FOUNDATIONAL_LIB_WARN_UNUSED_RESULT FOUNDATIONAL_LIB_NONNULL FOUNDATIONAL_LIB_NOTHROW FOUNDATIONAL_LIB_PURE FOUNDATIONAL_LIB_FUNC int set_in(struct Set *set, const char *key)
{
    FOUNDATIONAL_LIB_ASSERT_ARGUMENT_IF_ENABLED(set);
    FOUNDATIONAL_LIB_ASSERT_ARGUMENT_IF_ENABLED(key);

    const size_t index = set_hash(key, set->capacity);
    struct SetKey *current_key = set->table[index];

    while (current_key != NULL)
    {
        if (FOUNDATIONAL_LIB_STRCMP(current_key->key, key) == 0)
        {
            return 1;
        }
        current_key = current_key->next;
    }

    return 0;
}

/**
 * @brief The destructor for a Frozen Set.
 *
 * This function sets the destructor for a Set data structure.
 *
 * @param dict The Frozen Set data structure.
 */
FOUNDATIONAL_LIB_NONNULL FOUNDATIONAL_LIB_NOTHROW FOUNDATIONAL_LIB_FUNC void frozen_set_destructor(struct FrozenSet *frozen_set)
{

    FOUNDATIONAL_LIB_ASSERT_ARGUMENT_IF_ENABLED(frozen_set);
    set_destructor((struct Set *)frozen_set);
}

/**
 * @brief Creates a new instance of a FrozenSet.
 *
 * This function creates a new instance of a FrozenSet data structure.
 *
 * @param num_args The number of arguments provided.
 * @param ... The variable arguments representing keys.
 * @return Returns a pointer to the new FrozenSet instance.
 */
FOUNDATIONAL_LIB_WARN_UNUSED_RESULT FOUNDATIONAL_LIB_NONNULL FOUNDATIONAL_LIB_NOTHROW FOUNDATIONAL_LIB_MALLOC FOUNDATIONAL_LIB_FUNC struct FrozenSet *frozen_set_new_instance(size_t num_args, ...)
{
    struct FrozenSet *frozen_set = (struct FrozenSet *)FOUNDATIONAL_LIB_MEMORY_ALLOCATOR_MALLOC(sizeof(struct FrozenSet));
    if (FOUNDATIONAL_LIB_UNLIKELY(frozen_set == NULL))
    {
        FOUNDATIONAL_LIB_die_aggressively_if_enabled();
        return NULL;
    }

    frozen_set->capacity = num_args * FOUNDATIONAL_LIB_FROZEN_INITIALIZATION_SIZE_MULTIPLIER;
    frozen_set->size = 0;
    frozen_set->table = (struct SetKey **)FOUNDATIONAL_LIB_MEMORY_ALLOCATOR_CALLOC(FOUNDATIONAL_LIB_HASH_INITIAL_CAPACITY, sizeof(struct SetKey *));
    if (FOUNDATIONAL_LIB_UNLIKELY(frozen_set->table == NULL))
    {
        FOUNDATIONAL_LIB_MEMORY_ALLOCATOR_FREE(frozen_set);
        FOUNDATIONAL_LIB_die_aggressively_if_enabled();
        return NULL;
    }

    FOUNDATIONAL_LIB_VA_LIST args;
    FOUNDATIONAL_LIB_VA_START(args, num_args);

    for (size_t i = 0; i < num_args; ++i)
    {
        char *key;

        key = FOUNDATIONAL_LIB_VA_ARG(args, char *);
        set_add((struct Set *)frozen_set, key);
    }

    FOUNDATIONAL_LIB_VA_END(args); // Clean up the va_list

    return frozen_set;
}

/**
 * @brief Checks if a key is in a FrozenSet.
 *
 * This function checks if a key is present in a FrozenSet data structure.
 *
 * @param set The FrozenSet data structure.
 * @param key The key to check.
 * @return Returns 1 if the key is present, 0 otherwise.
 */
FOUNDATIONAL_LIB_WARN_UNUSED_RESULT FOUNDATIONAL_LIB_NONNULL FOUNDATIONAL_LIB_NOTHROW FOUNDATIONAL_LIB_PURE FOUNDATIONAL_LIB_FUNC int frozen_set_in(struct FrozenSet *set, const char *key)
{
    FOUNDATIONAL_LIB_ASSERT_ARGUMENT_IF_ENABLED(set);

    const size_t index = set_hash(key, set->capacity);
    struct SetKey *current_key = set->table[index];

    while (current_key != NULL)
    {
        if (FOUNDATIONAL_LIB_STRCMP(current_key->key, key) == 0)
        {
            return 1;
        }
        current_key = current_key->next;
    }

    return 0;
}

/**
 * @brief Iterates over a Set and applies a callback to each key.
 *
 * This function iterates over a Set data structure and applies a callback to each key.
 *
 * @param set The Set data structure.
 * @param callback The callback function to apply to each key.
 */
FOUNDATIONAL_LIB_NONNULL FOUNDATIONAL_LIB_NOTHROW FOUNDATIONAL_LIB_FUNC void set_iter(struct Set *set, void (*callback)(char *key))
{
    FOUNDATIONAL_LIB_ASSERT_ARGUMENT_IF_ENABLED(set);

    FOUNDATIONAL_LIB_ASSERT_ARGUMENT_IF_ENABLED(callback);
    for (size_t i = 0; i < set->capacity; ++i)
    {
        struct SetKey *current = set->table[i];

        while (current != NULL)
        {
            /* Call the callback function with the key and value */
            callback(current->key);

            /* Move to the next node in the linked list */
            current = current->next;
        }
    }
}

/**
 * @brief Returns the size of a Set.
 *
 * This function returns the size of a Set data structure.
 *
 * @param set The Set data structure.
 * @return Returns the size of the Set.
 */
FOUNDATIONAL_LIB_WARN_UNUSED_RESULT FOUNDATIONAL_LIB_NONNULL FOUNDATIONAL_LIB_NOTHROW FOUNDATIONAL_LIB_PURE FOUNDATIONAL_LIB_FUNC size_t set_size(struct Set *set)
{

    FOUNDATIONAL_LIB_ASSERT_ARGUMENT_IF_ENABLED(set);
    return set->size;
}

/**
 * @brief Returns the size of a FrozenSet.
 *
 * This function returns the size of a FrozenSet data structure.
 *
 * @param set The FrozenSet data structure.
 * @return Returns the size of the FrozenSet.
 */
FOUNDATIONAL_LIB_WARN_UNUSED_RESULT FOUNDATIONAL_LIB_NONNULL FOUNDATIONAL_LIB_NOTHROW FOUNDATIONAL_LIB_PURE FOUNDATIONAL_LIB_FUNC size_t frozen_set_size(struct FrozenSet *set)
{
    FOUNDATIONAL_LIB_ASSERT_ARGUMENT_IF_ENABLED(set);
    return set->size;
}

/**
 * @brief Converts a Set to an array of keys.
 *
 * This function converts a Set data structure to an array of keys. The resulting array
 * is allocated dynamically and needs to be freed by the caller using FOUNDATIONAL_LIB_MEMORY_ALLOCATOR_FREE.
 *
 * @param set The Set data structure.
 * @param keys A pointer to the array of keys (output parameter).
 * @param size_of_keys A pointer to the size of the array (output parameter).
 */
FOUNDATIONAL_LIB_WARN_UNUSED_RESULT FOUNDATIONAL_LIB_NONNULL FOUNDATIONAL_LIB_NOTHROW FOUNDATIONAL_LIB_FUNC int set_to_array(struct Set *set, char ***keys, size_t *size_of_keys)
{
    FOUNDATIONAL_LIB_ASSERT_ARGUMENT_IF_ENABLED(set);
    FOUNDATIONAL_LIB_ASSERT_ARGUMENT_IF_ENABLED(keys);

    FOUNDATIONAL_LIB_ASSERT_ARGUMENT_IF_ENABLED(size_of_keys);

    const size_t alloc_size1 = FOUNDATIONAL_LIB_safe_mul(set->size, sizeof(char *));
    if (FOUNDATIONAL_LIB_UNLIKELY(alloc_size1 == 0))
        goto overflow;

    *keys = (char **)FOUNDATIONAL_LIB_MEMORY_ALLOCATOR_MALLOC(alloc_size1);
    if (FOUNDATIONAL_LIB_UNLIKELY(*keys == NULL))
        goto error_handler;

    for (size_t i = 0, index = 0; i < set->capacity; ++i)
    {
        struct SetKey *current_pair = set->table[i];
        while (current_pair != NULL)
        {
            (*keys)[index] = (current_pair->key);

            ++index;
            current_pair = current_pair->next;
        }
    }

    *size_of_keys = set->size;

    return 0;

overflow:
error_handler:

    FOUNDATIONAL_LIB_die_aggressively_if_enabled();
    return -1;
}

/**
 * @brief Converts a FrozenSet to an array of keys.
 *
 * This function converts a FrozenSet data structure to an array of keys.
 *
 * @param set The FrozenSet data structure.
 * @param keys A pointer to the array of keys.
 * @param size_of_keys A pointer to the size of the array.
 * @return Returns 1 on success, 0 on failure.
 */
FOUNDATIONAL_LIB_WARN_UNUSED_RESULT FOUNDATIONAL_LIB_NONNULL FOUNDATIONAL_LIB_NOTHROW FOUNDATIONAL_LIB_FUNC int frozen_set_to_array(struct FrozenSet *set, char ***keys, size_t *size_of_keys)
{

    FOUNDATIONAL_LIB_ASSERT_ARGUMENT_IF_ENABLED(set);
    FOUNDATIONAL_LIB_ASSERT_ARGUMENT_IF_ENABLED(keys);

    FOUNDATIONAL_LIB_ASSERT_ARGUMENT_IF_ENABLED(size_of_keys);

    const size_t alloc_size1 = FOUNDATIONAL_LIB_safe_mul(set->size, sizeof(char *));
    if (FOUNDATIONAL_LIB_UNLIKELY(alloc_size1 == 0))
        goto overflow;

    *keys = (char **)FOUNDATIONAL_LIB_MEMORY_ALLOCATOR_MALLOC(alloc_size1);
    if (FOUNDATIONAL_LIB_UNLIKELY(*keys == NULL))
        goto error_handler;

    for (size_t i = 0, index = 0; i < set->capacity; ++i)
    {
        struct SetKey *current_pair = set->table[i];
        while (current_pair != NULL)
        {
            (*keys)[index] = (current_pair->key);

            ++index;
            current_pair = current_pair->next;
        }
    }

    *size_of_keys = set->size;

    return 0;

overflow:
error_handler:

    FOUNDATIONAL_LIB_die_aggressively_if_enabled();
    return -1;
}

/**
 * @brief Deletes keys from a Set.
 *
 * This function deletes keys from a Set data structure.
 *
 * @param keys The keys to delete.
 */
FOUNDATIONAL_LIB_NONNULL FOUNDATIONAL_LIB_FUNC void set_del_keys(char **keys) { FOUNDATIONAL_LIB_MEMORY_ALLOCATOR_FREE(keys); }

/** Convert a set to a string representation */
FOUNDATIONAL_LIB_WARN_UNUSED_RESULT FOUNDATIONAL_LIB_NONNULL FOUNDATIONAL_LIB_NOTHROW FOUNDATIONAL_LIB_MALLOC FOUNDATIONAL_LIB_FUNC char *set_to_string(struct Set *set)
{

    FOUNDATIONAL_LIB_ASSERT_ARGUMENT_IF_ENABLED(set);

    /* Allocate memory for the string representation */
    size_t total_length = 2;
    for (size_t i = 0; i < set->capacity; ++i)
    {
        struct SetKey *current_key = set->table[i];
        while (current_key != NULL)
        {
            /* Calculate the length of the string representation for each key-value
             * pair */
            total_length += FOUNDATIONAL_LIB_STRLEN(current_key->key);
            total_length += 2; // 2 for ", "
            current_key = current_key->next;
        }
    }

    // Should not reach SIZE_MAX

    // Add 1 for the null-terminator, at least 3 chars additional

    char *result = (char *)FOUNDATIONAL_LIB_MEMORY_ALLOCATOR_MALLOC(total_length + sizeof("")); /* Safe */

    if (FOUNDATIONAL_LIB_UNLIKELY(result == NULL))
    {
        FOUNDATIONAL_LIB_die_aggressively_if_enabled();
        return NULL;
    }

    result[0] = '{';
    size_t index = 1;

    for (size_t i = 0; i < set->capacity; ++i)
    {
        struct SetKey *current_key = set->table[i];
        while (current_key != NULL)
        {
            /* Append the key and value to the string representation */
            index += FOUNDATIONAL_LIB_SNPRINTF(result + index, total_length - index, "%s", current_key->key);
            current_key = current_key->next;

            /* Add a separator (comma) if there are more elements */
            if (index < total_length - 2)
            {
                result[index++] = ',';
                result[index++] = ' ';
            }
        }
    }

    if (set->capacity)
    {
        index -= 2;
    }
    result[index++] = '}';
    result[index++] = '\0'; // Null-terminate the string
    return result;
}

/**
 * @brief Converts a frozen set to a string representation.
 *
 * This function converts the provided frozen set to a string
 * representation.
 * @param set A pointer to the frozen set instance.
 *
 * @return Returns a dynamically allocated string representing the frozen
 * set.
 *
 * @note The caller is responsible for freeing the memory allocated for the
 * resulting string using free() when it is no longer needed.
 */
FOUNDATIONAL_LIB_WARN_UNUSED_RESULT FOUNDATIONAL_LIB_NONNULL FOUNDATIONAL_LIB_NOTHROW FOUNDATIONAL_LIB_MALLOC FOUNDATIONAL_LIB_FUNC char *frozen_set_to_string(struct FrozenSet *frozen_set)
{
    FOUNDATIONAL_LIB_ASSERT_ARGUMENT_IF_ENABLED(frozen_set);

    /* Allocate memory for the string representation */
    size_t total_length = 2;
    for (size_t i = 0; i < frozen_set->capacity; ++i)
    {
        struct SetKey *current_key = frozen_set->table[i];
        while (current_key != NULL)
        {
            /* Calculate the length of the string representation for each key-value
             * pair */
            total_length += FOUNDATIONAL_LIB_STRLEN(current_key->key);
            total_length += 2; // 2 for ", "
            current_key = current_key->next;
        }
    }

    // Should not reach SIZE_MAX

    // Add 1 for the null-terminator, at least 3 chars
    char *result = (char *)FOUNDATIONAL_LIB_MEMORY_ALLOCATOR_MALLOC(total_length + 1 /* Safe, should not reach SIZE_MAX */);
    if (FOUNDATIONAL_LIB_UNLIKELY(result == NULL))
    {
        FOUNDATIONAL_LIB_die_aggressively_if_enabled();
        return NULL;
    }

    result[0] = '{';
    size_t index = 1;

    for (size_t i = 0; i < frozen_set->capacity; ++i)
    {
        struct SetKey *current_key = frozen_set->table[i];
        while (current_key != NULL)
        {
            /* Append the key and value to the string representation */
            index += FOUNDATIONAL_LIB_SNPRINTF(result + index, total_length - index, "%s", current_key->key);
            current_key = current_key->next;

            /* Add a separator (comma) if there are more elements */
            if (index < total_length - 2)
            {
                result[index++] = ',';
                result[index++] = ' ';
            }
        }
    }

    if (frozen_set->capacity)
    {
        index -= 2;
    }

    result[index++] = '}';
    result[index++] = '\0'; // Null-terminate the string

    return result;
}

/**
 * @brief Deletes keys from a FrozenSet.
 *
 * This function deletes keys from a FrozenSet data structure and frees the memory allocated for the keys.
 *
 * @param keys The keys to delete and free.
 */
FOUNDATIONAL_LIB_NONNULL FOUNDATIONAL_LIB_NOTHROW FOUNDATIONAL_LIB_FUNC void frozen_set_del_keys(char **keys)
{
    FOUNDATIONAL_LIB_ASSERT_ARGUMENT_IF_ENABLED(keys);
    FOUNDATIONAL_LIB_MEMORY_ALLOCATOR_FREE(keys);
}

/**
 * @brief Iterates over a Set and applies a callback to each key.
 *
 * This function iterates over a Set data structure and applies a callback function to each key.
 * The callback function should take a single parameter, a pointer to a char representing the key.
 *
 * @param set The Set data structure.
 * @param callback The callback function to apply to each key.
 */
FOUNDATIONAL_LIB_NONNULL FOUNDATIONAL_LIB_NOTHROW FOUNDATIONAL_LIB_FUNC void frozen_set_iter(struct Set *set, void (*callback)(char *key))
{
    FOUNDATIONAL_LIB_ASSERT_ARGUMENT_IF_ENABLED(set);
    FOUNDATIONAL_LIB_ASSERT_ARGUMENT_IF_ENABLED(callback);

    for (size_t i = 0; i < set->capacity; ++i)
    {
        struct SetKey *current_key = set->table[i];

        while (current_key != NULL)
        {
            /* Call the callback function with the key and value */
            callback(current_key->key);

            /* Move to the next node in the linked list */
            current_key = current_key->next;
        }
    }
}

/**
 * @brief Checks if a string is a valid UTF-8 sequence.
 *
 * This function checks if a string is a valid UTF-8 sequence.
 *
 * @param str The string to check.
 * @param len The length of the string.
 * @return Returns 1 if the string is valid UTF-8, 0 otherwise.
 */
FOUNDATIONAL_LIB_WARN_UNUSED_RESULT FOUNDATIONAL_LIB_NONNULL FOUNDATIONAL_LIB_NOTHROW FOUNDATIONAL_LIB_PURE FOUNDATIONAL_LIB_FUNC int is_valid_utf8(const char *str, size_t len)
{
    FOUNDATIONAL_LIB_ASSERT_ARGUMENT_IF_ENABLED(str);

    size_t i = 0;

    while (i < len)
    {
        if ((str[i] & 0x80) == 0)
        {
            // ASCII character (0xxxxxxx)
            ++i;
        }
        else if ((str[i] & 0xE0) == 0xC0)
        {
            // 2-byte UTF-8 character (110xxxxx)
            if (i + 1 >= len || (str[i + 1] & 0xC0) != 0x80)
                return 0;
            i += 2;
        }
        else if ((str[i] & 0xF0) == 0xE0)
        {
            // 3-byte UTF-8 character (1110xxxx)
            if (i + 2 >= len || (str[i + 1] & 0xC0) != 0x80 || (str[i + 2] & 0xC0) != 0x80)
                return 0;
            i += 3;
        }
        else if ((str[i] & 0xF8) == 0xF0)
        {
            // 4-byte UTF-8 character (11110xxx)
            if (i + 3 >= len || (str[i + 1] & 0xC0) != 0x80 || (str[i + 2] & 0xC0) != 0x80 || (str[i + 3] & 0xC0) != 0x80)
                return 0;
            i += 4;
        }
        else
        {
            // Invalid UTF-8 encoding
            return 0;
        }
    }

    return 1;
}

/**
 * @brief Selects a random string from an array of strings without dynamic memory allocation.
 *
 * This function selects a random string from an array of strings without dynamically allocating memory.
 *
 * @param strings An array of strings.
 * @param size The size of the array.
 * @return Returns a pointer to the selected string.
 */
FOUNDATIONAL_LIB_WARN_UNUSED_RESULT FOUNDATIONAL_LIB_NONNULL FOUNDATIONAL_LIB_NOTHROW FOUNDATIONAL_LIB_FUNC const char *sample_strings(const char **strings, size_t size) /* Does not dynamically allocate memory. */
{
    FOUNDATIONAL_LIB_ASSERT_ARGUMENT_IF_ENABLED(strings);

    long j;

#ifdef _WIN32
    unsigned int rand_val;
    if (rand_s(&rand_val) != 0)
    {
        FOUNDATIONAL_LIB_die_aggressively_if_enabled();
        return NULL;
    }

    j = rand_val % size;
#elif defined(__linux__)
    j = (long)(drand48() * size);
#else
    j = rand() % size;
#endif

    return strings[j];
}

/**
 * @brief Shuffles an array of strings in place.
 *
 * This function shuffles an array of strings in place.
 *
 * @param strings An array of strings.
 * @param size The size of the array.
 * @return Returns 1 on success, 0 on failure.
 */
FOUNDATIONAL_LIB_NONNULL FOUNDATIONAL_LIB_NOTHROW FOUNDATIONAL_LIB_FUNC int shuffle_strings_in_place(char **strings, size_t size)
{
    FOUNDATIONAL_LIB_ASSERT_ARGUMENT_IF_ENABLED(strings);

    for (size_t i = size - 1; i; --i)
    {
        long j;
#ifdef _WIN32
        unsigned int rand_val;
        if (FOUNDATIONAL_LIB_UNLIKELY(rand_s(&rand_val) != 0))
        {
            FOUNDATIONAL_LIB_die_aggressively_if_enabled();
            return -1;
        }

        j = rand_val % (i + 1);
#elif defined(__linux__)
        j = (long)(drand48() * (i + 1));
#else
        j = rand() % (i + 1);
#endif

        // Swap strings[i] and strings[j]
        char *temp = strings[i];
        strings[i] = strings[j];
        strings[j] = temp;
    }

    return 0;
}

/**
 * @brief Generates a random signed number within a specified range (inclusive).
 *
 * This function generates a random signed number within a specified range (inclusive).
 *
 * @param min The minimum value of the range.
 * @param max The maximum value of the range.
 * @return Returns the generated random number.
 */
FOUNDATIONAL_LIB_WARN_UNUSED_RESULT FOUNDATIONAL_LIB_NONNULL FOUNDATIONAL_LIB_NOTHROW FOUNDATIONAL_LIB_FUNC long rand_number_from_range_inclusive_signed(signed long min, signed long max)
{
    const signed long long range = max - min + 1;

#ifdef _WIN32
    unsigned int rand_val;
    if (rand_s(&rand_val) != 0)
    {
        FOUNDATIONAL_LIB_die_aggressively_if_enabled();
        return 0;
    }

    return min + (rand_val % range);
#elif defined(__linux__)
    return min + (long)(drand48() * range);
#else
    return min + (rand() % range);
#endif
}

/**
 * @brief Generates a random unsigned number within a specified range (inclusive).
 *
 * This function generates a random unsigned number within a specified range (inclusive).
 *
 * @param min The minimum value of the range.
 * @param max The maximum value of the range.
 * @return Returns the generated random number.
 */
FOUNDATIONAL_LIB_WARN_UNUSED_RESULT FOUNDATIONAL_LIB_NONNULL FOUNDATIONAL_LIB_NOTHROW FOUNDATIONAL_LIB_FUNC unsigned long rand_number_from_range_inclusive_unsigned(unsigned long min, unsigned long max)
{
    const unsigned long range = max - min + 1;

#ifdef _WIN32
    unsigned int rand_val;
    if (rand_s(&rand_val) != 0)
    {
        FOUNDATIONAL_LIB_die_aggressively_if_enabled();
        return 0;
    }

    return min + (rand_val % range);
#elif defined(__linux__)
    return min + (unsigned long)(drand48() * range);
#else
    return min + (rand() % range);
#endif
}

#if FOUNDATIONAL_LIB_UNSAFE_FUNCTIONS_ENABLED
/**
 * @brief Executes a command and reads its output into a string.
 *
 * This function executes the specified command using popen and reads the output
 * into a dynamically allocated string. The size of the string is stored in the
 * variable pointed to by the 'size' parameter. The caller is responsible for
 * freeing the memory allocated for the returned string using free().
 *
 * @param command  Pointer to the command to be executed.
 * @param size     Pointer to a variable where the size of the read string will
 * be stored.
 * @return         Pointer to the dynamically allocated string containing the
 * command output. Returns NULL if there is an error or the command output is
 * empty. The caller is responsible for freeing the memory using free().
 *
 * @note Caution: This function may introduce security vulnerabilities.
 * Consider using alternative methods such as execvp() for safer command
 * execution in a controlled environment.

 */
FOUNDATIONAL_LIB_WARN_UNUSED_RESULT FOUNDATIONAL_LIB_NONNULL FOUNDATIONAL_LIB_NOTHROW FOUNDATIONAL_LIB_FUNC char *backticks(const char *command, size_t *size)
{
    FOUNDATIONAL_LIB_ASSERT_ARGUMENT_IF_ENABLED(command);
    FOUNDATIONAL_LIB_ASSERT_ARGUMENT_IF_ENABLED(size);

    FILE *pipe = FOUNDATIONAL_LIB_POPEN(command, "r");
    if (FOUNDATIONAL_LIB_UNLIKELY(pipe == NULL))
    {
        FOUNDATIONAL_LIB_die_aggressively_if_enabled();
        return NULL; // Indicate error by returning NULL
    }

    // Read the command output into the string
    size_t output_size = FOUNDATIONAL_LIB_POPEN_INITIAL_ALLOC_SIZE; // Initial output buffer size
    char *output = (char *)FOUNDATIONAL_LIB_MEMORY_ALLOCATOR_MALLOC(output_size);
    if (FOUNDATIONAL_LIB_UNLIKELY(output == NULL))
    {
        pclose(pipe); // No need to check errors here because things are already
                      // going wrong.
        FOUNDATIONAL_LIB_die_aggressively_if_enabled();
        return NULL;
    }

    size_t total_read = 0;

    for (;;)
    {
        const size_t read_size = FOUNDATIONAL_LIB_FREAD(output + total_read, 1, 4096, pipe);

        if (FOUNDATIONAL_LIB_UNLIKELY(read_size == 0))
        {
            const int error_code = FOUNDATIONAL_LIB_FERROR(pipe);
            if (FOUNDATIONAL_LIB_UNLIKELY(error_code))
            {
                FOUNDATIONAL_LIB_MEMORY_ALLOCATOR_FREE(output);
                pclose(pipe); // No need to check errors here because things are already
                              // going wrong.
                FOUNDATIONAL_LIB_die_aggressively_if_enabled();
                return NULL;
            }
            else
            {
                break;
            }
        }
        else if (total_read + read_size + 1 > output_size)
        {
            const size_t new_realloc_length = FOUNDATIONAL_LIB_safe_add_3(total_read, read_size, 1);

            if (FOUNDATIONAL_LIB_UNLIKELY(new_realloc_length == 0))
            {
                FOUNDATIONAL_LIB_MEMORY_ALLOCATOR_FREE(output);
                FOUNDATIONAL_LIB_die_aggressively_if_enabled();
                return NULL;
            }
            // Expand the buffer
            output_size = FOUNDATIONAL_LIB_REALLOC_REALLOCATION_ALGORITHM(new_realloc_length);

            if (FOUNDATIONAL_LIB_UNLIKELY(output_size == 0)) // Overflow.
            {
                FOUNDATIONAL_LIB_die_aggressively_if_enabled();
                return NULL;
            }
            char *new_output = (char *)FOUNDATIONAL_LIB_MEMORY_ALLOCATOR_REALLOC(output, output_size);

            if (FOUNDATIONAL_LIB_UNLIKELY(new_output == NULL))
            {
                FOUNDATIONAL_LIB_MEMORY_ALLOCATOR_FREE(output);
                pclose(pipe); // No need to check errors here because things are already
                              // going wrong.
                FOUNDATIONAL_LIB_die_aggressively_if_enabled();
                return NULL;
            }

            output = new_output;
        }
        total_read += read_size;
    }

    if (FOUNDATIONAL_LIB_UNLIKELY(ferror(pipe) != 0))
    {
        FOUNDATIONAL_LIB_MEMORY_ALLOCATOR_FREE(output);

        pclose(pipe); // No need to re check for errors because things are going wrong.

        FOUNDATIONAL_LIB_die_aggressively_if_enabled();

        return NULL; // Error reading from pipe
    }

    // Null-terminate the string
    output[total_read] = '\0';

    *size = total_read;

    // Close the pipe
    if (FOUNDATIONAL_LIB_UNLIKELY(pclose(pipe) != 0)) // Check for errors.
    {
        FOUNDATIONAL_LIB_MEMORY_ALLOCATOR_FREE(output);
        FOUNDATIONAL_LIB_die_aggressively_if_enabled();
        return NULL;
    }

    return output;
}

#endif

/**
 * @brief Reads the contents of a file into an array of strings.
 *
 * This function reads the contents of the specified file into a dynamically
 * allocated array of strings, using the specified delimiter. The size of the
 * array is stored in the variable pointed to by the 'num_lines' parameter.
 * The caller is responsible for freeing the memory allocated for the array
 * and its strings using free().
 *
 * @param filename Pointer to the name of the file to be read.
 * @param delim    The delimiter used to split the file content into lines.
 * @param num_lines Pointer to a variable where the number of lines in the file
 * will be stored.
 * @return         Pointer to the dynamically allocated array of strings.
 * Returns NULL if there is an error or the file is empty. The caller is
 * responsible for freeing the memory using free().
 * @note This function reads a file into an array of character arrays.
 *       Don't use this with binary data. The result CAN contain '\0'
 *       but you won't know how long each string is.
 */
FOUNDATIONAL_LIB_WARN_UNUSED_RESULT FOUNDATIONAL_LIB_NONNULL FOUNDATIONAL_LIB_NOTHROW FOUNDATIONAL_LIB_MALLOC FOUNDATIONAL_LIB_FUNC char **read_file_into_array(const char *filename, const char *delim, size_t *num_lines)
{
    FOUNDATIONAL_LIB_ASSERT_ARGUMENT_IF_ENABLED(filename);
    FOUNDATIONAL_LIB_ASSERT_ARGUMENT_IF_ENABLED(delim);
    FOUNDATIONAL_LIB_ASSERT_ARGUMENT_IF_ENABLED(num_lines);

    size_t size_of_file;

    *num_lines = 0;

    /*
     * This approach uses very few system calls and is rather efficient.
     * It first gets the entire file into memory, then splits it.
     * There would be very few fread() calls, and it can predict the buffer
     * size ahead of time, for low memory usage.
     *
     * One issue with this is that it has to allocate memory twice -
     * first for read_file_into_array - second for the new array,
     * after which the first array is freed(). So that means for
     * a time, the computer needs around 2x the memory.
     * However, if you are concerned about memory usage, probably
     * better might be read_file_into_string() with strtok() used
     * to extract the parts you want, or manual code withFOUNDATIONAL_LIB_FREAD().
     *
     * Any which way, this implementation is decent and efficient
     * for many purposes.
     */
    const char *file = read_file_into_string(filename, &size_of_file);
    if (FOUNDATIONAL_LIB_UNLIKELY(file == NULL))
    {
        /* read_file_into_string() would already call die_aggressively_if_enabled */

        return NULL;
    }

    char **lines = split(file, num_lines, delim, 0, 1);

    FOUNDATIONAL_LIB_MEMORY_ALLOCATOR_FREE((void *)file);
    if (FOUNDATIONAL_LIB_UNLIKELY(lines == NULL))
    {
        /* split() would already call die_aggressively_if_enabled */

        return NULL;
    }

    return lines;
}

/**
 * @brief Prints a character value to the standard output.
 *
 * @param value The character value to be printed.
 */
FOUNDATIONAL_LIB_NONNULL FOUNDATIONAL_LIB_NOTHROW FOUNDATIONAL_LIB_FUNC void print_char(const char value) { FOUNDATIONAL_LIB_PRINTF("%c", value); }

/**
 * @brief Prints a character value to the specified stream.
 *
 * @param value  The character value to be printed.
 * @param stream The file stream where the output will be directed.
 */
FOUNDATIONAL_LIB_NONNULL FOUNDATIONAL_LIB_NOTHROW FOUNDATIONAL_LIB_FUNC void print_char_to_stream(const char value, FILE *stream)
{
    FOUNDATIONAL_LIB_ASSERT_ARGUMENT_IF_ENABLED(stream);
    FOUNDATIONAL_LIB_FPRINTF(stream, "%c", value);
}

/**
 * @brief Prints a double-precision floating-point value to the standard output.
 *
 * @param value The double value to be printed.
 */
FOUNDATIONAL_LIB_NONNULL FOUNDATIONAL_LIB_NOTHROW FOUNDATIONAL_LIB_FUNC void print_double(const double value) { FOUNDATIONAL_LIB_PRINTF("%f", value); }

/**
 * @brief Prints a double-precision floating-point value to the specified stream.
 *
 * @param value  The double value to be printed.
 * @param stream The file stream where the output will be directed.
 */
FOUNDATIONAL_LIB_NONNULL FOUNDATIONAL_LIB_NOTHROW FOUNDATIONAL_LIB_FUNC void print_double_to_stream(const double value, FILE *stream)
{
    FOUNDATIONAL_LIB_ASSERT_ARGUMENT_IF_ENABLED(stream);
    FOUNDATIONAL_LIB_FPRINTF(stream, "%f", value);
}

/**
 * @brief Prints a single-precision floating-point value to the standard output.
 *
 * @param value The float value to be printed.
 */
FOUNDATIONAL_LIB_NONNULL FOUNDATIONAL_LIB_NOTHROW FOUNDATIONAL_LIB_FUNC void print_float(const float value) { FOUNDATIONAL_LIB_PRINTF("%f", value); }

/**
 * @brief Prints a single-precision floating-point value to the specified stream.
 *
 * @param value  The float value to be printed.
 * @param stream The file stream where the output will be directed.
 */
FOUNDATIONAL_LIB_NONNULL FOUNDATIONAL_LIB_NOTHROW FOUNDATIONAL_LIB_FUNC void print_float_to_stream(const float value, FILE *stream)
{
    FOUNDATIONAL_LIB_ASSERT_ARGUMENT_IF_ENABLED(stream);
    FOUNDATIONAL_LIB_FPRINTF(stream, "%f", value);
}

/**
 * @brief Prints an integer value to the standard output.
 *
 * @param value The integer value to be printed.
 */
FOUNDATIONAL_LIB_NONNULL FOUNDATIONAL_LIB_NOTHROW FOUNDATIONAL_LIB_FUNC void print_int(const int value) { FOUNDATIONAL_LIB_PRINTF("%d", value); }

/**
 * @brief Prints an integer value to the specified stream.
 *
 * @param value  The integer value to be printed.
 * @param stream The file stream where the output will be directed.
 */
FOUNDATIONAL_LIB_NONNULL FOUNDATIONAL_LIB_NOTHROW FOUNDATIONAL_LIB_FUNC void print_int_to_stream(const int value, FILE *stream)
{
    FOUNDATIONAL_LIB_ASSERT_ARGUMENT_IF_ENABLED(stream);
    FOUNDATIONAL_LIB_FPRINTF(stream, "%d", value);
}

/**
 * @brief Prints a long integer value to the standard output.
 *
 * @param value The long integer value to be printed.
 */
FOUNDATIONAL_LIB_NONNULL FOUNDATIONAL_LIB_NOTHROW FOUNDATIONAL_LIB_FUNC void print_long(const long value) { FOUNDATIONAL_LIB_PRINTF("%ld", value); }

/**
 * @brief Prints a long integer value to the specified stream.
 *
 * @param value  The long integer value to be printed.
 * @param stream The file stream where the output will be directed.
 */
FOUNDATIONAL_LIB_NONNULL FOUNDATIONAL_LIB_NOTHROW FOUNDATIONAL_LIB_FUNC void print_long_to_stream(const long value, FILE *stream)
{
    FOUNDATIONAL_LIB_ASSERT_ARGUMENT_IF_ENABLED(stream);
    FOUNDATIONAL_LIB_FPRINTF(stream, "%ld", value);
}

/**
 * @brief Prints a long long integer value to the standard output.
 *
 * @param value The long long integer value to be printed.
 */
FOUNDATIONAL_LIB_NONNULL FOUNDATIONAL_LIB_NOTHROW FOUNDATIONAL_LIB_FUNC void print_long_long(const long long value) { FOUNDATIONAL_LIB_PRINTF("%lld", value); }

/**
 * @brief Prints a long long integer value to the specified stream.
 *
 * @param value  The long long integer value to be printed.
 * @param stream The file stream where the output will be directed.
 */
FOUNDATIONAL_LIB_NONNULL FOUNDATIONAL_LIB_NOTHROW FOUNDATIONAL_LIB_FUNC void print_long_long_to_stream(const long long value, FILE *stream)
{
    FOUNDATIONAL_LIB_ASSERT_ARGUMENT_IF_ENABLED(stream);

    FOUNDATIONAL_LIB_FPRINTF(stream, "%lld", value);
}

/**
 * @brief Prints a short integer value to the standard output.
 *
 * @param value The short integer value to be printed.
 */
FOUNDATIONAL_LIB_NONNULL FOUNDATIONAL_LIB_NOTHROW FOUNDATIONAL_LIB_FUNC void print_short(const short value) { FOUNDATIONAL_LIB_PRINTF("%hd", value); }

/**
 * @brief Prints a short integer value to the specified stream.
 *
 * @param value  The short integer value to be printed.
 * @param stream The file stream where the output will be directed.
 */
FOUNDATIONAL_LIB_NONNULL FOUNDATIONAL_LIB_NOTHROW FOUNDATIONAL_LIB_FUNC void print_short_to_stream(const short value, FILE *stream)
{
    FOUNDATIONAL_LIB_ASSERT_ARGUMENT_IF_ENABLED(stream);
    FOUNDATIONAL_LIB_FPRINTF(stream, "%hd", value);
}
/**
 * @brief Prints a size_t value to the standard output.
 *
 * @param value The size_t value to be printed.
 */
FOUNDATIONAL_LIB_NONNULL FOUNDATIONAL_LIB_NOTHROW FOUNDATIONAL_LIB_FUNC void print_size_t(const size_t value) { FOUNDATIONAL_LIB_PRINTF("%zu", value); }

/**
 * @brief Prints a size_t value to the specified stream.
 *
 * @param value  The size_t value to be printed.
 * @param stream The file stream where the output will be directed.
 */
FOUNDATIONAL_LIB_NONNULL FOUNDATIONAL_LIB_NOTHROW FOUNDATIONAL_LIB_FUNC void print_size_t_to_stream(const size_t value, FILE *stream)
{
    FOUNDATIONAL_LIB_ASSERT_ARGUMENT_IF_ENABLED(stream);

    FOUNDATIONAL_LIB_FPRINTF(stream, "%zu", value);
}

/**
 * @brief Prints a string value to the standard output.
 *
 * @param value The string to be printed.
 */
FOUNDATIONAL_LIB_NONNULL FOUNDATIONAL_LIB_NOTHROW FOUNDATIONAL_LIB_FUNC void print_string(char *value)
{
    FOUNDATIONAL_LIB_ASSERT_ARGUMENT_IF_ENABLED(value);
    FOUNDATIONAL_LIB_PRINTF("%s", value);
}

/**
 * @brief Prints a string value to the specified stream.
 *
 * @param value  The string to be printed.
 * @param stream The file stream where the output will be directed.
 */
FOUNDATIONAL_LIB_NONNULL FOUNDATIONAL_LIB_NOTHROW FOUNDATIONAL_LIB_FUNC void print_string_to_stream(char *value, FILE *stream)
{
    FOUNDATIONAL_LIB_ASSERT_ARGUMENT_IF_ENABLED(stream);
    FOUNDATIONAL_LIB_ASSERT_ARGUMENT_IF_ENABLED(value);

    FOUNDATIONAL_LIB_FPRINTF(stream, "%s", value);
}

/**
 * @brief Prints an unsigned char value to the standard output.
 *
 * @param value The unsigned char value to be printed.
 */
FOUNDATIONAL_LIB_NONNULL FOUNDATIONAL_LIB_NOTHROW FOUNDATIONAL_LIB_FUNC void print_uchar(const unsigned char value) { FOUNDATIONAL_LIB_PRINTF("%c", value); }

/**
 * @brief Prints an unsigned char value to the specified stream.
 *
 * @param value  The unsigned char value to be printed.
 * @param stream The file stream where the output will be directed.
 */
FOUNDATIONAL_LIB_NONNULL FOUNDATIONAL_LIB_NOTHROW FOUNDATIONAL_LIB_FUNC void print_uchar_to_stream(const unsigned char value, FILE *stream)
{
    FOUNDATIONAL_LIB_ASSERT_ARGUMENT_IF_ENABLED(stream);
    FOUNDATIONAL_LIB_FPRINTF(stream, "%c", value);
}

/**
 * @brief Prints an unsigned int value to the standard output.
 *
 * @param value The unsigned int value to be printed.
 */
FOUNDATIONAL_LIB_NONNULL FOUNDATIONAL_LIB_NOTHROW FOUNDATIONAL_LIB_FUNC void print_uint(const unsigned int value) { FOUNDATIONAL_LIB_PRINTF("%u", value); }

/**
 * @brief Prints an unsigned int value to the specified stream.
 *
 * @param value  The unsigned int value to be printed.
 * @param stream The file stream where the output will be directed.
 */
FOUNDATIONAL_LIB_NONNULL FOUNDATIONAL_LIB_NOTHROW FOUNDATIONAL_LIB_FUNC void print_uint_to_stream(const unsigned int value, FILE *stream)
{
    FOUNDATIONAL_LIB_ASSERT_ARGUMENT_IF_ENABLED(stream);
    FOUNDATIONAL_LIB_FPRINTF(stream, "%u", value);
}
/**
 * @brief Prints an unsigned long value to the standard output.
 *
 * @param value The unsigned long value to be printed.
 */
FOUNDATIONAL_LIB_NONNULL FOUNDATIONAL_LIB_NOTHROW FOUNDATIONAL_LIB_FUNC void print_ulong(const unsigned long value) { FOUNDATIONAL_LIB_PRINTF("%lu", value); }

/**
 * @brief Prints an unsigned long value to the specified stream.
 *
 * @param value  The unsigned long value to be printed.
 * @param stream The file stream where the output will be directed.
 */
FOUNDATIONAL_LIB_NONNULL FOUNDATIONAL_LIB_NOTHROW FOUNDATIONAL_LIB_FUNC void print_ulong_to_stream(const unsigned long value, FILE *stream)
{
    FOUNDATIONAL_LIB_ASSERT_ARGUMENT_IF_ENABLED(stream);
    FOUNDATIONAL_LIB_FPRINTF(stream, "%lu", value);
}

/**
 * @brief Prints an unsigned long long value to the standard output.
 *
 * @param value The unsigned long long value to be printed.
 */
FOUNDATIONAL_LIB_NONNULL FOUNDATIONAL_LIB_NOTHROW FOUNDATIONAL_LIB_FUNC void print_ulong_long(const unsigned long long value) { FOUNDATIONAL_LIB_PRINTF("%llu", value); }

/**
 * @brief Prints an unsigned long long value to the specified stream.
 *
 * @param value  The unsigned long long value to be printed.
 * @param stream The file stream where the output will be directed.
 */
FOUNDATIONAL_LIB_NONNULL FOUNDATIONAL_LIB_NOTHROW FOUNDATIONAL_LIB_FUNC void print_ulong_long_to_stream(const unsigned long long value, FILE *stream)
{
    FOUNDATIONAL_LIB_ASSERT_ARGUMENT_IF_ENABLED(stream);
    FOUNDATIONAL_LIB_FPRINTF(stream, "%llu", value);
}
/**
 * @brief Print an unsigned short value.
 *
 * @param value   Unsigned short value to be printed.
 */
FOUNDATIONAL_LIB_NONNULL FOUNDATIONAL_LIB_NOTHROW FOUNDATIONAL_LIB_FUNC void print_ushort(const unsigned short value) { FOUNDATIONAL_LIB_PRINTF("%hu", value); }

/**
 * @brief Print an unsigned short value to a stream.
 *
 * @param value   Unsigned short value to be printed.
 * @param stream  FILE stream where the output will be printed.
 */
FOUNDATIONAL_LIB_NONNULL FOUNDATIONAL_LIB_NOTHROW FOUNDATIONAL_LIB_FUNC void print_ushort_to_stream(const unsigned short value, FILE *stream)
{

    FOUNDATIONAL_LIB_ASSERT_ARGUMENT_IF_ENABLED(stream);
    FOUNDATIONAL_LIB_FPRINTF(stream, "%hu", value);
}

/**
 * @brief Counts the occurrences of a string in an array of strings.
 *
 * This function iterates through the given array of strings and counts
 * how many times the specified string appears in the array.
 *
 * @param array         The array of strings to search.
 * @param string        The string to count occurrences of.
 * @param array_length  The number of elements in the array.
 *
 * @return The count of occurrences of the specified string in the array.
 */
FOUNDATIONAL_LIB_WARN_UNUSED_RESULT FOUNDATIONAL_LIB_NONNULL FOUNDATIONAL_LIB_NOTHROW FOUNDATIONAL_LIB_PURE FOUNDATIONAL_LIB_FUNC size_t count_occurrences_of_string_in_array(const char **array, const char *string, size_t array_length)
{
    FOUNDATIONAL_LIB_ASSERT_ARGUMENT_IF_ENABLED(array);

    FOUNDATIONAL_LIB_ASSERT_ARGUMENT_IF_ENABLED(string);

    size_t count = 0;

    // Iterate through the array
    for (size_t i = 0; i < array_length; ++i)
    {
        // Compare each string in the array with the target string
        if (FOUNDATIONAL_LIB_STRCMP(array[i], string) == 0)
        {
            ++count;
        }
    }

    return count;
}

/**
 * @brief Counts the occurrences of a block of memory in an array of memory blocks.
 *
 * This function iterates through the given array of memory blocks and counts
 * how many times the specified memory block appears in the array.
 *
 * @param array_of_adjacent_values    The array of memory blocks to search.
 * @param array_length                The number of elements in the array.
 * @param memory                      The memory block to count occurrences of.
 * @param memory_length               The size of the memory block.
 *
 * @return The count of occurrences of the specified memory block in the array.
 */
FOUNDATIONAL_LIB_WARN_UNUSED_RESULT FOUNDATIONAL_LIB_NONNULL FOUNDATIONAL_LIB_NOTHROW FOUNDATIONAL_LIB_PURE FOUNDATIONAL_LIB_FUNC size_t count_occurrences_of_adjacent_data_in_array(const void *array_of_adjacent_values, size_t array_length, const void *memory, size_t memory_length)
{

    FOUNDATIONAL_LIB_ASSERT_ARGUMENT_IF_ENABLED(array_of_adjacent_values);
    FOUNDATIONAL_LIB_ASSERT_ARGUMENT_IF_ENABLED(memory_length);
    size_t count = 0;

    // Iterate through the array
    for (size_t i = 0; i < array_length; ++i)
    {
        // Dereferences each pointer in the array and compare memory_length bytes.
        if (FOUNDATIONAL_LIB_MEMCMP(array_of_adjacent_values, memory, memory_length) == 0)
        {
            count++;
        }
    }

    return count;
}

/**
 * @brief Counts the occurrences of a block of memory in an array of memory blocks.
 *
 * This function iterates through the given array of memory blocks and counts
 * how many times the specified memory block appears in the array.
 *
 * @param array_of_pointers    The array of memory blocks to search.
 * @param array_length         The number of elements in the array.
 * @param memory               The memory block to count occurrences of.
 * @param memory_length        The size of the memory block.
 *
 * @return The count of occurrences of the specified memory block in the array.
 */
FOUNDATIONAL_LIB_WARN_UNUSED_RESULT FOUNDATIONAL_LIB_NONNULL FOUNDATIONAL_LIB_NOTHROW FOUNDATIONAL_LIB_PURE FOUNDATIONAL_LIB_FUNC size_t count_occurrences_of_data_in_array(const void **array_of_pointers, size_t array_length, const void *memory, size_t memory_length)
{

    FOUNDATIONAL_LIB_ASSERT_ARGUMENT_IF_ENABLED(array_of_pointers);
    FOUNDATIONAL_LIB_ASSERT_ARGUMENT_IF_ENABLED(memory);

    size_t count = 0;

    // Iterate through the array
    for (size_t i = 0; i < array_length; ++i)
    {
        // Dereferences each pointer in the array and compare memory_length bytes.
        if (FOUNDATIONAL_LIB_MEMCMP(array_of_pointers[i], memory, memory_length) == 0)
        {
            count++;
        }
    }

    return count;
}

#if FOUNDATIONAL_LIB_NETWORK_FUNCTIONS_ENABLED

/* Chrome by default */

#define FOUNDATIONAL_LIB_DEFAULT_USER_AGENT "Mozilla/5.0 (X11; Linux x86_64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/119.0.0.0 Safari/537.36"

#include <curl/curl.h>

/* Write callback */
FOUNDATIONAL_LIB_WARN_UNUSED_RESULT FOUNDATIONAL_LIB_NONNULL FOUNDATIONAL_LIB_NOTHROW FOUNDATIONAL_LIB_FUNC size_t FOUNDATIONAL_LIB_libcurl_write_callback(char *data, size_t n, size_t l, void *userp)
{

    FOUNDATIONAL_LIB_ASSERT_ARGUMENT_IF_ENABLED(data);

    FOUNDATIONAL_LIB_ASSERT_ARGUMENT_IF_ENABLED(userp);
    struct StringData
    {
        char *string;

        size_t size;
        size_t alloc_size;

        size_t byte_max_cutoff;
    } *string = userp;

    const size_t both = n * l;
    append_string_to_string(&string->string, &string->size, &string->alloc_size, data, both);

    if (string->byte_max_cutoff != 0 && string->size >= string->byte_max_cutoff)
    {
        /* Curl can read in big blocks, like 9,370 bytes. So if the cutoff is low,
         * the read size still might be high. */
        /* FOUNDATIONAL_LIB_PRINTF("%zu.size >= %zu.byte_max_cutoff\n", string->size,
               string->byte_max_cutoff); */
        return CURLE_OK;
    }
    return both;
}

/**
 * @brief Downloads the content of a website using HTTP(S) with libcurl.
 *
 * This function utilizes the libcurl library to send an HTTP(S) request to the
 * specified website and retrieves the content. The retrieved content is stored
 * in the dynamically allocated memory pointed to by the 'string' parameter.
 * The size of the retrieved content, including the null terminator, is stored
 * in the 'size' parameter. The allocated size of the 'string' buffer is stored
 * in 'str_alloc_size'. If the retrieved content exceeds the specified
 * byte_max_cutoff, the function stops downloading and returns the content
 * retrieved up to that point. Note that the actual retrieved content size may
 * exceed the byte_max_cutoff value.
 *
 * The default User-Agent string used in the HTTP request headers is set to
 * emulate Chrome. If a custom User-Agent is desired, it can be provided through
 * the 'user_agent' parameter.
 *
 * @param website The URL of the website to download.
 * @param string A pointer to the buffer where the website content will be stored.
 *               The buffer is dynamically allocated and should be freed by the caller.
 * @param size A pointer to the variable where the size of the retrieved content
 *             (including the null terminator) will be stored.
 * @param str_alloc_size A pointer to the variable where the allocated size of the
 *                      'string' buffer will be stored.
 * @param byte_max_cutoff The maximum number of bytes to retrieve. If the content
 *                        exceeds this size, downloading stops.
 * @param user_agent The User-Agent string to include in the HTTP request headers.
 *                   This identifies the client making the request. If NULL, the
 *                   function uses a default User-Agent emulating Chrome.
 *
 * @return Returns 0 on success, and a non-zero value on failure.
 *         Possible failure reasons include network errors, invalid URL, memory
 *         allocation failure, and others.
 *
 * @note The caller is responsible for freeing the 'string' buffer using free()
 *       when it is no longer needed.
 */
FOUNDATIONAL_LIB_WARN_UNUSED_RESULT FOUNDATIONAL_LIB_NONNULL FOUNDATIONAL_LIB_NOTHROW FOUNDATIONAL_LIB_FUNC int download_website(const char *website, char **string, size_t *size, size_t *str_alloc_size, size_t byte_max_cutoff, const char *user_agent)
{

    FOUNDATIONAL_LIB_ASSERT_ARGUMENT_IF_ENABLED(website);
    FOUNDATIONAL_LIB_ASSERT_ARGUMENT_IF_ENABLED(string);
    FOUNDATIONAL_LIB_ASSERT_ARGUMENT_IF_ENABLED(size);
    FOUNDATIONAL_LIB_ASSERT_ARGUMENT_IF_ENABLED(str_alloc_size);

    CURL *curl = curl_easy_init();
    if (FOUNDATIONAL_LIB_UNLIKELY(curl == NULL))
    {
        return -1;
    }

    if (user_agent == NULL)
    {
        user_agent = FOUNDATIONAL_LIB_DEFAULT_USER_AGENT;
    }

    curl_easy_setopt(curl, CURLOPT_BUFFERSIZE, 102400L);
    curl_easy_setopt(curl, CURLOPT_URL, website);
    curl_easy_setopt(curl, CURLOPT_NOPROGRESS, 1L);
    curl_easy_setopt(curl, CURLOPT_USERAGENT, user_agent);
    curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);
    curl_easy_setopt(curl, CURLOPT_MAXREDIRS, 50L);
    curl_easy_setopt(curl, CURLOPT_HTTP_VERSION, (long)CURL_HTTP_VERSION_2TLS);
    curl_easy_setopt(curl, CURLOPT_FTP_SKIP_PASV_IP, 1L);
    curl_easy_setopt(curl, CURLOPT_TCP_KEEPALIVE, 1L);
    struct StringData
    {
        char *string;
        size_t size;
        size_t alloc_size;
        size_t byte_max_cutoff;
    } data;
    data.string = FOUNDATIONAL_LIB_MEMORY_ALLOCATOR_MALLOC(FOUNDATIONAL_LIB_INITIAL_NETWORK_DOWNLOAD_BUFFER_SIZE);
    data.alloc_size = FOUNDATIONAL_LIB_INITIAL_NETWORK_DOWNLOAD_BUFFER_SIZE;
    data.size = 0;
    data.byte_max_cutoff = byte_max_cutoff;

    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, FOUNDATIONAL_LIB_libcurl_write_callback);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, &data);
    CURLcode curlcode = curl_easy_perform(curl);

    curl_easy_cleanup(curl);

    *string = data.string;
    *size = data.size;
    *str_alloc_size = data.alloc_size;

    return curlcode == CURLE_OK;
}

/**
 * @brief Downloads content from a list of websites.
 *
 * This function downloads content from the specified websites and stores the results in
 * dynamically allocated memory. The caller is responsible for freeing the allocated memory.
 *
 * @param[in] websites_to_download An array of C-strings representing the URLs of websites to download.
 * @param[in] num_websites The number of websites in the 'websites_to_download' array.
 * @param[out] outputs A pointer to an array of C-strings representing the downloaded content.
 *                     The caller is responsible for freeing each individual string and the array itself.
 * @param[out] lens A pointer to an array of size_t values representing the length of each downloaded content.
 *                  The caller is responsible for freeing the array itself.
 * @param[in] byte_limit The maximum total size, in bytes, for each downloaded url.
 * @param[in] aggressive_stop_on_error If set to 1, the function will stop downloading remaining websites
 *                                     if an error occurs during any download; if set to 0, the function
 *                                     will attempt to download all websites even if errors occur.
 *
 * @return 0 indicates successful execution, while -1 is returned on error.
 * @note The caller is responsible for freeing the memory allocated for 'outputs' and 'lens'.
 */
FOUNDATIONAL_LIB_WARN_UNUSED_RESULT FOUNDATIONAL_LIB_NONNULL FOUNDATIONAL_LIB_NOTHROW FOUNDATIONAL_LIB_FUNC int download_websites(const char **websites_to_download, size_t num_websites, char ***outputs, size_t **lens, size_t byte_limit, int aggressive_stop_on_error)
{

    FOUNDATIONAL_LIB_ASSERT_ARGUMENT_IF_ENABLED(websites_to_download);
    FOUNDATIONAL_LIB_ASSERT_ARGUMENT_IF_ENABLED(outputs);
    FOUNDATIONAL_LIB_ASSERT_ARGUMENT_IF_ENABLED(lens);
    // Initalize all to NULL in case a site can't download
    *outputs = (char **)FOUNDATIONAL_LIB_MEMORY_ALLOCATOR_CALLOC(num_websites, sizeof(char *));

    // Initalize all to 0 in case a site can't download
    *lens = (size_t *)FOUNDATIONAL_LIB_MEMORY_ALLOCATOR_CALLOC(num_websites, sizeof(size_t));

    for (size_t i = 0; i < num_websites; ++i)
    {
        size_t alloc_size;
        if (download_website(websites_to_download[i], (*outputs) + i, (*lens) + i, &alloc_size, byte_limit, NULL) == -1)
        {
            if (aggressive_stop_on_error)
            {
                FOUNDATIONAL_LIB_die_aggressively_if_enabled();
                return -1;
            }
        }
    }

    return 0;
}

#pragma GCC diagnostic pop

#endif /* Networking. */

/**
 * @brief Reads content from multiple files into an array.
 *
 * This function reads the content of multiple files specified by an array of
 * file paths and stores the content and corresponding lengths in output arrays.
 *
 * @param files_to_open An array of file paths to be opened and read.
 * @param num_files The number of files in the files_to_open array.
 * @param outputs A pointer to an array that will store the content of each file.
 *                The content will be stored as an array of null-terminated strings.
 * @param lens A pointer to an array that will store the length of each file's content.
 * @param aggressive_stop_on_error If set to 1, the function will stop reading files
 *                                 if an error occurs while reading a file. If set to 0,
 *                                 the function will continue reading other files even
 *                                 if an error occurs.
 *
 * @return Returns 0 on success, -1 on failure. If aggressive_stop_on_error is set to 1,
 *         the function will return -1 as soon as an error is encountered; otherwise,
 *         it will attempt to read all files before returning.
 *
 * @note The outputs array is dynamically allocated and should be freed by the caller
 *       after use to prevent memory leaks.
 * @note The lens array is dynamically allocated and contains the lengths of the
 *       corresponding file contents in the outputs array.
 * @note If an error occurs while reading a file, the content for that file in the
 *       outputs array will be set to NULL, and its length in the lens array will be 0.
 * @note It is the responsibility of the caller to free the memory allocated for
 *       outputs and lens arrays after use.
 */
FOUNDATIONAL_LIB_FUNC int read_files_into_array(const char **files_to_open, size_t num_files, char ***outputs, size_t **lens, int aggressive_stop_on_error)
{
    FOUNDATIONAL_LIB_ASSERT_ARGUMENT_IF_ENABLED(files_to_open);
    FOUNDATIONAL_LIB_ASSERT_ARGUMENT_IF_ENABLED(outputs);
    FOUNDATIONAL_LIB_ASSERT_ARGUMENT_IF_ENABLED(lens);
    // Initalize all to NULL in case a site can't download
    *outputs = (char **)FOUNDATIONAL_LIB_MEMORY_ALLOCATOR_CALLOC(num_files, sizeof(char *));

    // Initalize all to 0 in case a site can't download
    *lens = (size_t *)FOUNDATIONAL_LIB_MEMORY_ALLOCATOR_CALLOC(num_files, sizeof(size_t));

    for (size_t i = 0; i < num_files; ++i)
    {
        size_t size;

        (*outputs)[i] = read_file_into_string(files_to_open[i], &size);
        (*lens)[i] = size;

        if ((*outputs)[i] == NULL)
        {
            if (aggressive_stop_on_error)
            {
                FOUNDATIONAL_LIB_die_aggressively_if_enabled();
                return -1;
            }
        }
    }

    return 0;
}

#endif