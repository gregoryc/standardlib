
#ifndef _FOUNDATIONAL_LIB_HEADER_GUARD
#define _FOUNDATIONAL_LIB_HEADER_GUARD

#include <ctype.h>
#include <stdarg.h>
#include <stdio.h>
#ifdef _WIN32
#define _CRT_RAND_S
#endif
#include <stdlib.h>

#include <string.h>

#include <errno.h>

#ifndef FOUNDATIONAL_LIB_AGGRESSIVE_DIE_TYPE
/**
 * @brief Type of the aggressive die variable.
 *
 * This macro defines the type of the aggressive die variable, which
 * uses 1 byte of overhead by default. It can be configured as static
 * or nonstatic based on user preference.
 */
#define FOUNDATIONAL_LIB_AGGRESSIVE_DIE_TYPE static unsigned char
#endif

struct Dict;
struct FrozenDict;
struct Set;
struct FrozenSet;

#endif