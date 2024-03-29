/**
 * @file base.h
 * @author JacobLinCool <hi@jacoblin.cool> (github.com/JacobLinCool)
 * @brief The base header file of Cister Lib.
 * @version
 * @date
 *
 * @copyright Copyright (c) 2023 JacobLinCool (MIT License)
 * @see https://github.com/JacobLinCool/Cimple-Lib
 */
#ifndef __CISTER_UTILS_BASE_H
#define __CISTER_UTILS_BASE_H

// #region Include Common Header Files. Remember to use -lm flag when compiling.
#include <assert.h>
#include <ctype.h>
#include <errno.h>
#include <inttypes.h>
#include <math.h>
#include <regex.h>
#include <setjmp.h>
#include <signal.h>
#include <stdarg.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
// #endregion

// #region Type Alias for Standard Types.
typedef int8_t      i8;
typedef int16_t     i16;
typedef int32_t     i32;
typedef int64_t     i64;
typedef uint8_t     u8;
typedef uint16_t    u16;
typedef uint32_t    u32;
typedef uint64_t    u64;
typedef float       f32;
typedef double      f64;
typedef long double f128;
typedef size_t      szt;
typedef char *      str;
// #endregion

#endif  // __CISTER_UTILS_BASE_H