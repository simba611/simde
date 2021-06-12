/* SPDX-License-Identifier: MIT
 *
 * Permission is hereby granted, free of charge, to any person
 * obtaining a copy of this software and associated documentation
 * files (the "Software"), to deal in the Software without
 * restriction, including without limitation the rights to use, copy,
 * modify, merge, publish, distribute, sublicense, and/or sell copies
 * of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be
 * included in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
 * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS
 * BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN
 * ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
 * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 *
 * Copyright:
 *   2020      Evan Nemerson <evan@nemerson.com>
 */

/* Constify macros.  For internal use only.
 *
 * These are used to make it possible to call a function which takes
 * an Integer Constant Expression (ICE) using a compile time constant.
 * Technically it would also be possible to use a value not trivially
 * known by the compiler, but there would be a siginficant performance
 * hit (a switch switch is used).
 *
 * The basic idea is pretty simple; we just emit a do while loop which
 * contains a switch with a case for every possible value of the
 * constant.
 *
 * As long as the value you pass to the function in constant, pretty
 * much any copmiler shouldn't have a problem generating exactly the
 * same code as if you had used an ICE.
 *
 * This is intended to be used in the SIMDe implementations of
 * functions the compilers require to be an ICE, but the other benefit
 * is that if we also disable the warnings from
 * SIMDE_REQUIRE_CONSTANT_RANGE we can actually just allow the tests
 * to use non-ICE parameters
 */

#if !defined(SIMDE_CONSTIFY_H)
#define SIMDE_CONSTIFY_H

#include "simde-diagnostic.h"

HEDLEY_DIAGNOSTIC_PUSH
SIMDE_DIAGNOSTIC_DISABLE_VARIADIC_MACROS_
SIMDE_DIAGNOSTIC_DISABLE_CPP98_COMPAT_PEDANTIC_

#define SIMDE_CONSTIFY_2_(func_name, result, default_case, imm, ...) \
  do { \
    switch(imm) { \
      case 0: result = func_name(__VA_ARGS__, 0); break; \
      case 1: result = func_name(__VA_ARGS__, 1); break; \
      default: result = default_case; break; \
    } \
  } while (0)

#define SIMDE_CONSTIFY_4_(func_name, result, default_case, imm, ...) \
  do { \
    switch(imm) { \
      case 0: result = func_name(__VA_ARGS__, 0); break; \
      case 1: result = func_name(__VA_ARGS__, 1); break; \
      case 2: result = func_name(__VA_ARGS__, 2); break; \
      case 3: result = func_name(__VA_ARGS__, 3); break; \
      default: result = default_case; break; \
    } \
  } while (0)

#define SIMDE_CONSTIFY_8_(func_name, result, default_case, imm, ...) \
  do { \
    switch(imm) { \
      case 0: result = func_name(__VA_ARGS__, 0); break; \
      case 1: result = func_name(__VA_ARGS__, 1); break; \
      case 2: result = func_name(__VA_ARGS__, 2); break; \
      case 3: result = func_name(__VA_ARGS__, 3); break; \
      case 4: result = func_name(__VA_ARGS__, 4); break; \
      case 5: result = func_name(__VA_ARGS__, 5); break; \
      case 6: result = func_name(__VA_ARGS__, 6); break; \
      case 7: result = func_name(__VA_ARGS__, 7); break; \
      default: result = default_case; break; \
    } \
  } while (0)

#define SIMDE_CONSTIFY_16_(func_name, result, default_case, imm, ...) \
  do { \
    switch(imm) { \
      case  0: result = func_name(__VA_ARGS__,  0); break; \
      case  1: result = func_name(__VA_ARGS__,  1); break; \
      case  2: result = func_name(__VA_ARGS__,  2); break; \
      case  3: result = func_name(__VA_ARGS__,  3); break; \
      case  4: result = func_name(__VA_ARGS__,  4); break; \
      case  5: result = func_name(__VA_ARGS__,  5); break; \
      case  6: result = func_name(__VA_ARGS__,  6); break; \
      case  7: result = func_name(__VA_ARGS__,  7); break; \
      case  8: result = func_name(__VA_ARGS__,  8); break; \
      case  9: result = func_name(__VA_ARGS__,  9); break; \
      case 10: result = func_name(__VA_ARGS__, 10); break; \
      case 11: result = func_name(__VA_ARGS__, 11); break; \
      case 12: result = func_name(__VA_ARGS__, 12); break; \
      case 13: result = func_name(__VA_ARGS__, 13); break; \
      case 14: result = func_name(__VA_ARGS__, 14); break; \
      case 15: result = func_name(__VA_ARGS__, 15); break; \
      default: result = default_case; break; \
    } \
  } while (0)

#define SIMDE_CONSTIFY_16_NEW(func_name, result, default_case, imm, sae, ...) \
  do { \
    if(sae & SIMDE_MM_FROUND_NO_EXC) { \
      switch(imm) { \
        case  0: result = func_name(__VA_ARGS__,  0, SIMDE_MM_FROUND_NO_EXC); break; \
        case  1: result = func_name(__VA_ARGS__,  1, SIMDE_MM_FROUND_NO_EXC); break; \
        case  2: result = func_name(__VA_ARGS__,  2, SIMDE_MM_FROUND_NO_EXC); break; \
        case  3: result = func_name(__VA_ARGS__,  3, SIMDE_MM_FROUND_NO_EXC); break; \
        case  4: result = func_name(__VA_ARGS__,  4, SIMDE_MM_FROUND_NO_EXC); break; \
        case  5: result = func_name(__VA_ARGS__,  5, SIMDE_MM_FROUND_NO_EXC); break; \
        case  6: result = func_name(__VA_ARGS__,  6, SIMDE_MM_FROUND_NO_EXC); break; \
        case  7: result = func_name(__VA_ARGS__,  7, SIMDE_MM_FROUND_NO_EXC); break; \
        case  8: result = func_name(__VA_ARGS__,  8, SIMDE_MM_FROUND_NO_EXC); break; \
        case  9: result = func_name(__VA_ARGS__,  9, SIMDE_MM_FROUND_NO_EXC); break; \
        case 10: result = func_name(__VA_ARGS__, 10, SIMDE_MM_FROUND_NO_EXC); break; \
        case 11: result = func_name(__VA_ARGS__, 11, SIMDE_MM_FROUND_NO_EXC); break; \
        case 12: result = func_name(__VA_ARGS__, 12, SIMDE_MM_FROUND_NO_EXC); break; \
        case 13: result = func_name(__VA_ARGS__, 13, SIMDE_MM_FROUND_NO_EXC); break; \
        case 14: result = func_name(__VA_ARGS__, 14, SIMDE_MM_FROUND_NO_EXC); break; \
        case 15: result = func_name(__VA_ARGS__, 15, SIMDE_MM_FROUND_NO_EXC); break; \
        default: result = default_case; break; \
      } \
    } \
    else { \
      switch(imm) { \
        case  0: result = func_name(__VA_ARGS__,  0, SIMDE_MM_FROUND_CUR_DIRECTION); break; \
        case  1: result = func_name(__VA_ARGS__,  1, SIMDE_MM_FROUND_CUR_DIRECTION); break; \
        case  2: result = func_name(__VA_ARGS__,  2, SIMDE_MM_FROUND_CUR_DIRECTION); break; \
        case  3: result = func_name(__VA_ARGS__,  3, SIMDE_MM_FROUND_CUR_DIRECTION); break; \
        case  4: result = func_name(__VA_ARGS__,  4, SIMDE_MM_FROUND_CUR_DIRECTION); break; \
        case  5: result = func_name(__VA_ARGS__,  5, SIMDE_MM_FROUND_CUR_DIRECTION); break; \
        case  6: result = func_name(__VA_ARGS__,  6, SIMDE_MM_FROUND_CUR_DIRECTION); break; \
        case  7: result = func_name(__VA_ARGS__,  7, SIMDE_MM_FROUND_CUR_DIRECTION); break; \
        case  8: result = func_name(__VA_ARGS__,  8, SIMDE_MM_FROUND_CUR_DIRECTION); break; \
        case  9: result = func_name(__VA_ARGS__,  9, SIMDE_MM_FROUND_CUR_DIRECTION); break; \
        case 10: result = func_name(__VA_ARGS__, 10, SIMDE_MM_FROUND_CUR_DIRECTION); break; \
        case 11: result = func_name(__VA_ARGS__, 11, SIMDE_MM_FROUND_CUR_DIRECTION); break; \
        case 12: result = func_name(__VA_ARGS__, 12, SIMDE_MM_FROUND_CUR_DIRECTION); break; \
        case 13: result = func_name(__VA_ARGS__, 13, SIMDE_MM_FROUND_CUR_DIRECTION); break; \
        case 14: result = func_name(__VA_ARGS__, 14, SIMDE_MM_FROUND_CUR_DIRECTION); break; \
        case 15: result = func_name(__VA_ARGS__, 15, SIMDE_MM_FROUND_CUR_DIRECTION); break; \
        default: result = default_case; break; \
      } \
    } \
  } while (0)

#define SIMDE_CONSTIFY_32_(func_name, result, default_case, imm, ...) \
  do { \
    switch(imm) { \
      case  0: result = func_name(__VA_ARGS__,  0); break; \
      case  1: result = func_name(__VA_ARGS__,  1); break; \
      case  2: result = func_name(__VA_ARGS__,  2); break; \
      case  3: result = func_name(__VA_ARGS__,  3); break; \
      case  4: result = func_name(__VA_ARGS__,  4); break; \
      case  5: result = func_name(__VA_ARGS__,  5); break; \
      case  6: result = func_name(__VA_ARGS__,  6); break; \
      case  7: result = func_name(__VA_ARGS__,  7); break; \
      case  8: result = func_name(__VA_ARGS__,  8); break; \
      case  9: result = func_name(__VA_ARGS__,  9); break; \
      case 10: result = func_name(__VA_ARGS__, 10); break; \
      case 11: result = func_name(__VA_ARGS__, 11); break; \
      case 12: result = func_name(__VA_ARGS__, 12); break; \
      case 13: result = func_name(__VA_ARGS__, 13); break; \
      case 14: result = func_name(__VA_ARGS__, 14); break; \
      case 15: result = func_name(__VA_ARGS__, 15); break; \
      case 16: result = func_name(__VA_ARGS__, 16); break; \
      case 17: result = func_name(__VA_ARGS__, 17); break; \
      case 18: result = func_name(__VA_ARGS__, 18); break; \
      case 19: result = func_name(__VA_ARGS__, 19); break; \
      case 20: result = func_name(__VA_ARGS__, 20); break; \
      case 21: result = func_name(__VA_ARGS__, 21); break; \
      case 22: result = func_name(__VA_ARGS__, 22); break; \
      case 23: result = func_name(__VA_ARGS__, 23); break; \
      case 24: result = func_name(__VA_ARGS__, 24); break; \
      case 25: result = func_name(__VA_ARGS__, 25); break; \
      case 26: result = func_name(__VA_ARGS__, 26); break; \
      case 27: result = func_name(__VA_ARGS__, 27); break; \
      case 28: result = func_name(__VA_ARGS__, 28); break; \
      case 29: result = func_name(__VA_ARGS__, 29); break; \
      case 30: result = func_name(__VA_ARGS__, 30); break; \
      case 31: result = func_name(__VA_ARGS__, 31); break; \
      default: result = default_case; break; \
    } \
  } while (0)

#define SIMDE_CONSTIFY_32_2(func_name, result, default_case, imm, ...) \
  do { \
    switch(imm) { \
      case ( 0+32): result = func_name(__VA_ARGS__, ( 0+32)); break; \
      case ( 1+32): result = func_name(__VA_ARGS__, ( 1+32)); break; \
      case ( 2+32): result = func_name(__VA_ARGS__, ( 2+32)); break; \
      case ( 3+32): result = func_name(__VA_ARGS__, ( 3+32)); break; \
      case ( 4+32): result = func_name(__VA_ARGS__, ( 4+32)); break; \
      case ( 5+32): result = func_name(__VA_ARGS__, ( 5+32)); break; \
      case ( 6+32): result = func_name(__VA_ARGS__, ( 6+32)); break; \
      case ( 7+32): result = func_name(__VA_ARGS__, ( 7+32)); break; \
      case ( 8+32): result = func_name(__VA_ARGS__, ( 8+32)); break; \
      case ( 9+32): result = func_name(__VA_ARGS__, ( 9+32)); break; \
      case (10+32): result = func_name(__VA_ARGS__, (10+32)); break; \
      case (11+32): result = func_name(__VA_ARGS__, (11+32)); break; \
      case (12+32): result = func_name(__VA_ARGS__, (12+32)); break; \
      case (13+32): result = func_name(__VA_ARGS__, (13+32)); break; \
      case (14+32): result = func_name(__VA_ARGS__, (14+32)); break; \
      case (15+32): result = func_name(__VA_ARGS__, (15+32)); break; \
      case (16+32): result = func_name(__VA_ARGS__, (16+32)); break; \
      case (17+32): result = func_name(__VA_ARGS__, (17+32)); break; \
      case (18+32): result = func_name(__VA_ARGS__, (18+32)); break; \
      case (19+32): result = func_name(__VA_ARGS__, (19+32)); break; \
      case (20+32): result = func_name(__VA_ARGS__, (20+32)); break; \
      case (21+32): result = func_name(__VA_ARGS__, (21+32)); break; \
      case (22+32): result = func_name(__VA_ARGS__, (22+32)); break; \
      case (23+32): result = func_name(__VA_ARGS__, (23+32)); break; \
      case (24+32): result = func_name(__VA_ARGS__, (24+32)); break; \
      case (25+32): result = func_name(__VA_ARGS__, (25+32)); break; \
      case (26+32): result = func_name(__VA_ARGS__, (26+32)); break; \
      case (27+32): result = func_name(__VA_ARGS__, (27+32)); break; \
      case (28+32): result = func_name(__VA_ARGS__, (28+32)); break; \
      case (29+32): result = func_name(__VA_ARGS__, (29+32)); break; \
      case (30+32): result = func_name(__VA_ARGS__, (30+32)); break; \
      case (31+32): result = func_name(__VA_ARGS__, (31+32)); break; \
      default: result = default_case; break; \
    } \
  } while (0)

#define SIMDE_CONSTIFY_32_3(func_name, result, default_case, imm, ...) \
  do { \
    switch(imm) { \
      case ( 0+64): result = func_name(__VA_ARGS__, ( 0+64)); break; \
      case ( 1+64): result = func_name(__VA_ARGS__, ( 1+64)); break; \
      case ( 2+64): result = func_name(__VA_ARGS__, ( 2+64)); break; \
      case ( 3+64): result = func_name(__VA_ARGS__, ( 3+64)); break; \
      case ( 4+64): result = func_name(__VA_ARGS__, ( 4+64)); break; \
      case ( 5+64): result = func_name(__VA_ARGS__, ( 5+64)); break; \
      case ( 6+64): result = func_name(__VA_ARGS__, ( 6+64)); break; \
      case ( 7+64): result = func_name(__VA_ARGS__, ( 7+64)); break; \
      case ( 8+64): result = func_name(__VA_ARGS__, ( 8+64)); break; \
      case ( 9+64): result = func_name(__VA_ARGS__, ( 9+64)); break; \
      case (10+64): result = func_name(__VA_ARGS__, (10+64)); break; \
      case (11+64): result = func_name(__VA_ARGS__, (11+64)); break; \
      case (12+64): result = func_name(__VA_ARGS__, (12+64)); break; \
      case (13+64): result = func_name(__VA_ARGS__, (13+64)); break; \
      case (14+64): result = func_name(__VA_ARGS__, (14+64)); break; \
      case (15+64): result = func_name(__VA_ARGS__, (15+64)); break; \
      case (16+64): result = func_name(__VA_ARGS__, (16+64)); break; \
      case (17+64): result = func_name(__VA_ARGS__, (17+64)); break; \
      case (18+64): result = func_name(__VA_ARGS__, (18+64)); break; \
      case (19+64): result = func_name(__VA_ARGS__, (19+64)); break; \
      case (20+64): result = func_name(__VA_ARGS__, (20+64)); break; \
      case (21+64): result = func_name(__VA_ARGS__, (21+64)); break; \
      case (22+64): result = func_name(__VA_ARGS__, (22+64)); break; \
      case (23+64): result = func_name(__VA_ARGS__, (23+64)); break; \
      case (24+64): result = func_name(__VA_ARGS__, (24+64)); break; \
      case (25+64): result = func_name(__VA_ARGS__, (25+64)); break; \
      case (26+64): result = func_name(__VA_ARGS__, (26+64)); break; \
      case (27+64): result = func_name(__VA_ARGS__, (27+64)); break; \
      case (28+64): result = func_name(__VA_ARGS__, (28+64)); break; \
      case (29+64): result = func_name(__VA_ARGS__, (29+64)); break; \
      case (30+64): result = func_name(__VA_ARGS__, (30+64)); break; \
      case (31+64): result = func_name(__VA_ARGS__, (31+64)); break; \
      default: result = default_case; break; \
    } \
  } while (0)

#define SIMDE_CONSTIFY_32_4(func_name, result, default_case, imm, ...) \
  do { \
    switch(imm) { \
      case ( 0+96): result = func_name(__VA_ARGS__, ( 0+96)); break; \
      case ( 1+96): result = func_name(__VA_ARGS__, ( 1+96)); break; \
      case ( 2+96): result = func_name(__VA_ARGS__, ( 2+96)); break; \
      case ( 3+96): result = func_name(__VA_ARGS__, ( 3+96)); break; \
      case ( 4+96): result = func_name(__VA_ARGS__, ( 4+96)); break; \
      case ( 5+96): result = func_name(__VA_ARGS__, ( 5+96)); break; \
      case ( 6+96): result = func_name(__VA_ARGS__, ( 6+96)); break; \
      case ( 7+96): result = func_name(__VA_ARGS__, ( 7+96)); break; \
      case ( 8+96): result = func_name(__VA_ARGS__, ( 8+96)); break; \
      case ( 9+96): result = func_name(__VA_ARGS__, ( 9+96)); break; \
      case (10+96): result = func_name(__VA_ARGS__, (10+96)); break; \
      case (11+96): result = func_name(__VA_ARGS__, (11+96)); break; \
      case (12+96): result = func_name(__VA_ARGS__, (12+96)); break; \
      case (13+96): result = func_name(__VA_ARGS__, (13+96)); break; \
      case (14+96): result = func_name(__VA_ARGS__, (14+96)); break; \
      case (15+96): result = func_name(__VA_ARGS__, (15+96)); break; \
      case (16+96): result = func_name(__VA_ARGS__, (16+96)); break; \
      case (17+96): result = func_name(__VA_ARGS__, (17+96)); break; \
      case (18+96): result = func_name(__VA_ARGS__, (18+96)); break; \
      case (19+96): result = func_name(__VA_ARGS__, (19+96)); break; \
      case (20+96): result = func_name(__VA_ARGS__, (20+96)); break; \
      case (21+96): result = func_name(__VA_ARGS__, (21+96)); break; \
      case (22+96): result = func_name(__VA_ARGS__, (22+96)); break; \
      case (23+96): result = func_name(__VA_ARGS__, (23+96)); break; \
      case (24+96): result = func_name(__VA_ARGS__, (24+96)); break; \
      case (25+96): result = func_name(__VA_ARGS__, (25+96)); break; \
      case (26+96): result = func_name(__VA_ARGS__, (26+96)); break; \
      case (27+96): result = func_name(__VA_ARGS__, (27+96)); break; \
      case (28+96): result = func_name(__VA_ARGS__, (28+96)); break; \
      case (29+96): result = func_name(__VA_ARGS__, (29+96)); break; \
      case (30+96): result = func_name(__VA_ARGS__, (30+96)); break; \
      case (31+96): result = func_name(__VA_ARGS__, (31+96)); break; \
      default: result = default_case; break; \
    } \
  } while (0)

#define SIMDE_CONSTIFY_32_5(func_name, result, default_case, imm, ...) \
  do { \
    switch(imm) { \
      case ( 0+128): result = func_name(__VA_ARGS__, ( 0+128)); break; \
      case ( 1+128): result = func_name(__VA_ARGS__, ( 1+128)); break; \
      case ( 2+128): result = func_name(__VA_ARGS__, ( 2+128)); break; \
      case ( 3+128): result = func_name(__VA_ARGS__, ( 3+128)); break; \
      case ( 4+128): result = func_name(__VA_ARGS__, ( 4+128)); break; \
      case ( 5+128): result = func_name(__VA_ARGS__, ( 5+128)); break; \
      case ( 6+128): result = func_name(__VA_ARGS__, ( 6+128)); break; \
      case ( 7+128): result = func_name(__VA_ARGS__, ( 7+128)); break; \
      case ( 8+128): result = func_name(__VA_ARGS__, ( 8+128)); break; \
      case ( 9+128): result = func_name(__VA_ARGS__, ( 9+128)); break; \
      case (10+128): result = func_name(__VA_ARGS__, (10+128)); break; \
      case (11+128): result = func_name(__VA_ARGS__, (11+128)); break; \
      case (12+128): result = func_name(__VA_ARGS__, (12+128)); break; \
      case (13+128): result = func_name(__VA_ARGS__, (13+128)); break; \
      case (14+128): result = func_name(__VA_ARGS__, (14+128)); break; \
      case (15+128): result = func_name(__VA_ARGS__, (15+128)); break; \
      case (16+128): result = func_name(__VA_ARGS__, (16+128)); break; \
      case (17+128): result = func_name(__VA_ARGS__, (17+128)); break; \
      case (18+128): result = func_name(__VA_ARGS__, (18+128)); break; \
      case (19+128): result = func_name(__VA_ARGS__, (19+128)); break; \
      case (20+128): result = func_name(__VA_ARGS__, (20+128)); break; \
      case (21+128): result = func_name(__VA_ARGS__, (21+128)); break; \
      case (22+128): result = func_name(__VA_ARGS__, (22+128)); break; \
      case (23+128): result = func_name(__VA_ARGS__, (23+128)); break; \
      case (24+128): result = func_name(__VA_ARGS__, (24+128)); break; \
      case (25+128): result = func_name(__VA_ARGS__, (25+128)); break; \
      case (26+128): result = func_name(__VA_ARGS__, (26+128)); break; \
      case (27+128): result = func_name(__VA_ARGS__, (27+128)); break; \
      case (28+128): result = func_name(__VA_ARGS__, (28+128)); break; \
      case (29+128): result = func_name(__VA_ARGS__, (29+128)); break; \
      case (30+128): result = func_name(__VA_ARGS__, (30+128)); break; \
      case (31+128): result = func_name(__VA_ARGS__, (31+128)); break; \
      default: result = default_case; break; \
    } \
  } while (0)

#define SIMDE_CONSTIFY_32_6(func_name, result, default_case, imm, ...) \
  do { \
    switch(imm) { \
      case ( 0+128+32): result = func_name(__VA_ARGS__, ( 0+128+32)); break; \
      case ( 1+128+32): result = func_name(__VA_ARGS__, ( 1+128+32)); break; \
      case ( 2+128+32): result = func_name(__VA_ARGS__, ( 2+128+32)); break; \
      case ( 3+128+32): result = func_name(__VA_ARGS__, ( 3+128+32)); break; \
      case ( 4+128+32): result = func_name(__VA_ARGS__, ( 4+128+32)); break; \
      case ( 5+128+32): result = func_name(__VA_ARGS__, ( 5+128+32)); break; \
      case ( 6+128+32): result = func_name(__VA_ARGS__, ( 6+128+32)); break; \
      case ( 7+128+32): result = func_name(__VA_ARGS__, ( 7+128+32)); break; \
      case ( 8+128+32): result = func_name(__VA_ARGS__, ( 8+128+32)); break; \
      case ( 9+128+32): result = func_name(__VA_ARGS__, ( 9+128+32)); break; \
      case (10+128+32): result = func_name(__VA_ARGS__, (10+128+32)); break; \
      case (11+128+32): result = func_name(__VA_ARGS__, (11+128+32)); break; \
      case (12+128+32): result = func_name(__VA_ARGS__, (12+128+32)); break; \
      case (13+128+32): result = func_name(__VA_ARGS__, (13+128+32)); break; \
      case (14+128+32): result = func_name(__VA_ARGS__, (14+128+32)); break; \
      case (15+128+32): result = func_name(__VA_ARGS__, (15+128+32)); break; \
      case (16+128+32): result = func_name(__VA_ARGS__, (16+128+32)); break; \
      case (17+128+32): result = func_name(__VA_ARGS__, (17+128+32)); break; \
      case (18+128+32): result = func_name(__VA_ARGS__, (18+128+32)); break; \
      case (19+128+32): result = func_name(__VA_ARGS__, (19+128+32)); break; \
      case (20+128+32): result = func_name(__VA_ARGS__, (20+128+32)); break; \
      case (21+128+32): result = func_name(__VA_ARGS__, (21+128+32)); break; \
      case (22+128+32): result = func_name(__VA_ARGS__, (22+128+32)); break; \
      case (23+128+32): result = func_name(__VA_ARGS__, (23+128+32)); break; \
      case (24+128+32): result = func_name(__VA_ARGS__, (24+128+32)); break; \
      case (25+128+32): result = func_name(__VA_ARGS__, (25+128+32)); break; \
      case (26+128+32): result = func_name(__VA_ARGS__, (26+128+32)); break; \
      case (27+128+32): result = func_name(__VA_ARGS__, (27+128+32)); break; \
      case (28+128+32): result = func_name(__VA_ARGS__, (28+128+32)); break; \
      case (29+128+32): result = func_name(__VA_ARGS__, (29+128+32)); break; \
      case (30+128+32): result = func_name(__VA_ARGS__, (30+128+32)); break; \
      case (31+128+32): result = func_name(__VA_ARGS__, (31+128+32)); break; \
      default: result = default_case; break; \
    } \
  } while (0)

#define SIMDE_CONSTIFY_32_7(func_name, result, default_case, imm, ...) \
  do { \
    switch(imm) { \
      case ( 0+192): result = func_name(__VA_ARGS__, ( 0+192)); break; \
      case ( 1+192): result = func_name(__VA_ARGS__, ( 1+192)); break; \
      case ( 2+192): result = func_name(__VA_ARGS__, ( 2+192)); break; \
      case ( 3+192): result = func_name(__VA_ARGS__, ( 3+192)); break; \
      case ( 4+192): result = func_name(__VA_ARGS__, ( 4+192)); break; \
      case ( 5+192): result = func_name(__VA_ARGS__, ( 5+192)); break; \
      case ( 6+192): result = func_name(__VA_ARGS__, ( 6+192)); break; \
      case ( 7+192): result = func_name(__VA_ARGS__, ( 7+192)); break; \
      case ( 8+192): result = func_name(__VA_ARGS__, ( 8+192)); break; \
      case ( 9+192): result = func_name(__VA_ARGS__, ( 9+192)); break; \
      case (10+192): result = func_name(__VA_ARGS__, (10+192)); break; \
      case (11+192): result = func_name(__VA_ARGS__, (11+192)); break; \
      case (12+192): result = func_name(__VA_ARGS__, (12+192)); break; \
      case (13+192): result = func_name(__VA_ARGS__, (13+192)); break; \
      case (14+192): result = func_name(__VA_ARGS__, (14+192)); break; \
      case (15+192): result = func_name(__VA_ARGS__, (15+192)); break; \
      case (16+192): result = func_name(__VA_ARGS__, (16+192)); break; \
      case (17+192): result = func_name(__VA_ARGS__, (17+192)); break; \
      case (18+192): result = func_name(__VA_ARGS__, (18+192)); break; \
      case (19+192): result = func_name(__VA_ARGS__, (19+192)); break; \
      case (20+192): result = func_name(__VA_ARGS__, (20+192)); break; \
      case (21+192): result = func_name(__VA_ARGS__, (21+192)); break; \
      case (22+192): result = func_name(__VA_ARGS__, (22+192)); break; \
      case (23+192): result = func_name(__VA_ARGS__, (23+192)); break; \
      case (24+192): result = func_name(__VA_ARGS__, (24+192)); break; \
      case (25+192): result = func_name(__VA_ARGS__, (25+192)); break; \
      case (26+192): result = func_name(__VA_ARGS__, (26+192)); break; \
      case (27+192): result = func_name(__VA_ARGS__, (27+192)); break; \
      case (28+192): result = func_name(__VA_ARGS__, (28+192)); break; \
      case (29+192): result = func_name(__VA_ARGS__, (29+192)); break; \
      case (30+192): result = func_name(__VA_ARGS__, (30+192)); break; \
      case (31+192): result = func_name(__VA_ARGS__, (31+192)); break; \
      default: result = default_case; break; \
    } \
  } while (0)

#define SIMDE_CONSTIFY_32_8(func_name, result, default_case, imm, ...) \
  do { \
    switch(imm) { \
      case ( 0+192+32): result = func_name(__VA_ARGS__, ( 0+192+32)); break; \
      case ( 1+192+32): result = func_name(__VA_ARGS__, ( 1+192+32)); break; \
      case ( 2+192+32): result = func_name(__VA_ARGS__, ( 2+192+32)); break; \
      case ( 3+192+32): result = func_name(__VA_ARGS__, ( 3+192+32)); break; \
      case ( 4+192+32): result = func_name(__VA_ARGS__, ( 4+192+32)); break; \
      case ( 5+192+32): result = func_name(__VA_ARGS__, ( 5+192+32)); break; \
      case ( 6+192+32): result = func_name(__VA_ARGS__, ( 6+192+32)); break; \
      case ( 7+192+32): result = func_name(__VA_ARGS__, ( 7+192+32)); break; \
      case ( 8+192+32): result = func_name(__VA_ARGS__, ( 8+192+32)); break; \
      case ( 9+192+32): result = func_name(__VA_ARGS__, ( 9+192+32)); break; \
      case (10+192+32): result = func_name(__VA_ARGS__, (10+192+32)); break; \
      case (11+192+32): result = func_name(__VA_ARGS__, (11+192+32)); break; \
      case (12+192+32): result = func_name(__VA_ARGS__, (12+192+32)); break; \
      case (13+192+32): result = func_name(__VA_ARGS__, (13+192+32)); break; \
      case (14+192+32): result = func_name(__VA_ARGS__, (14+192+32)); break; \
      case (15+192+32): result = func_name(__VA_ARGS__, (15+192+32)); break; \
      case (16+192+32): result = func_name(__VA_ARGS__, (16+192+32)); break; \
      case (17+192+32): result = func_name(__VA_ARGS__, (17+192+32)); break; \
      case (18+192+32): result = func_name(__VA_ARGS__, (18+192+32)); break; \
      case (19+192+32): result = func_name(__VA_ARGS__, (19+192+32)); break; \
      case (20+192+32): result = func_name(__VA_ARGS__, (20+192+32)); break; \
      case (21+192+32): result = func_name(__VA_ARGS__, (21+192+32)); break; \
      case (22+192+32): result = func_name(__VA_ARGS__, (22+192+32)); break; \
      case (23+192+32): result = func_name(__VA_ARGS__, (23+192+32)); break; \
      case (24+192+32): result = func_name(__VA_ARGS__, (24+192+32)); break; \
      case (25+192+32): result = func_name(__VA_ARGS__, (25+192+32)); break; \
      case (26+192+32): result = func_name(__VA_ARGS__, (26+192+32)); break; \
      case (27+192+32): result = func_name(__VA_ARGS__, (27+192+32)); break; \
      case (28+192+32): result = func_name(__VA_ARGS__, (28+192+32)); break; \
      case (29+192+32): result = func_name(__VA_ARGS__, (29+192+32)); break; \
      case (30+192+32): result = func_name(__VA_ARGS__, (30+192+32)); break; \
      case (31+192+32): result = func_name(__VA_ARGS__, (31+192+32)); break; \
      default: result = default_case; break; \
    } \
  } while (0)

#define SIMDE_CONSTIFY_64_(func_name, result, default_case, imm, ...) \
  do { \
    switch(imm) { \
      case  0: result = func_name(__VA_ARGS__,  0); break; \
      case  1: result = func_name(__VA_ARGS__,  1); break; \
      case  2: result = func_name(__VA_ARGS__,  2); break; \
      case  3: result = func_name(__VA_ARGS__,  3); break; \
      case  4: result = func_name(__VA_ARGS__,  4); break; \
      case  5: result = func_name(__VA_ARGS__,  5); break; \
      case  6: result = func_name(__VA_ARGS__,  6); break; \
      case  7: result = func_name(__VA_ARGS__,  7); break; \
      case  8: result = func_name(__VA_ARGS__,  8); break; \
      case  9: result = func_name(__VA_ARGS__,  9); break; \
      case 10: result = func_name(__VA_ARGS__, 10); break; \
      case 11: result = func_name(__VA_ARGS__, 11); break; \
      case 12: result = func_name(__VA_ARGS__, 12); break; \
      case 13: result = func_name(__VA_ARGS__, 13); break; \
      case 14: result = func_name(__VA_ARGS__, 14); break; \
      case 15: result = func_name(__VA_ARGS__, 15); break; \
      case 16: result = func_name(__VA_ARGS__, 16); break; \
      case 17: result = func_name(__VA_ARGS__, 17); break; \
      case 18: result = func_name(__VA_ARGS__, 18); break; \
      case 19: result = func_name(__VA_ARGS__, 19); break; \
      case 20: result = func_name(__VA_ARGS__, 20); break; \
      case 21: result = func_name(__VA_ARGS__, 21); break; \
      case 22: result = func_name(__VA_ARGS__, 22); break; \
      case 23: result = func_name(__VA_ARGS__, 23); break; \
      case 24: result = func_name(__VA_ARGS__, 24); break; \
      case 25: result = func_name(__VA_ARGS__, 25); break; \
      case 26: result = func_name(__VA_ARGS__, 26); break; \
      case 27: result = func_name(__VA_ARGS__, 27); break; \
      case 28: result = func_name(__VA_ARGS__, 28); break; \
      case 29: result = func_name(__VA_ARGS__, 29); break; \
      case 30: result = func_name(__VA_ARGS__, 30); break; \
      case 31: result = func_name(__VA_ARGS__, 31); break; \
      case 32: result = func_name(__VA_ARGS__, 32); break; \
      case 33: result = func_name(__VA_ARGS__, 33); break; \
      case 34: result = func_name(__VA_ARGS__, 34); break; \
      case 35: result = func_name(__VA_ARGS__, 35); break; \
      case 36: result = func_name(__VA_ARGS__, 36); break; \
      case 37: result = func_name(__VA_ARGS__, 37); break; \
      case 38: result = func_name(__VA_ARGS__, 38); break; \
      case 39: result = func_name(__VA_ARGS__, 39); break; \
      case 40: result = func_name(__VA_ARGS__, 40); break; \
      case 41: result = func_name(__VA_ARGS__, 41); break; \
      case 42: result = func_name(__VA_ARGS__, 42); break; \
      case 43: result = func_name(__VA_ARGS__, 43); break; \
      case 44: result = func_name(__VA_ARGS__, 44); break; \
      case 45: result = func_name(__VA_ARGS__, 45); break; \
      case 46: result = func_name(__VA_ARGS__, 46); break; \
      case 47: result = func_name(__VA_ARGS__, 47); break; \
      case 48: result = func_name(__VA_ARGS__, 48); break; \
      case 49: result = func_name(__VA_ARGS__, 49); break; \
      case 50: result = func_name(__VA_ARGS__, 50); break; \
      case 51: result = func_name(__VA_ARGS__, 51); break; \
      case 52: result = func_name(__VA_ARGS__, 52); break; \
      case 53: result = func_name(__VA_ARGS__, 53); break; \
      case 54: result = func_name(__VA_ARGS__, 54); break; \
      case 55: result = func_name(__VA_ARGS__, 55); break; \
      case 56: result = func_name(__VA_ARGS__, 56); break; \
      case 57: result = func_name(__VA_ARGS__, 57); break; \
      case 58: result = func_name(__VA_ARGS__, 58); break; \
      case 59: result = func_name(__VA_ARGS__, 59); break; \
      case 60: result = func_name(__VA_ARGS__, 60); break; \
      case 61: result = func_name(__VA_ARGS__, 61); break; \
      case 62: result = func_name(__VA_ARGS__, 62); break; \
      case 63: result = func_name(__VA_ARGS__, 63); break; \
      default: result = default_case; break; \
    } \
  } while (0)

#define SIMDE_CONSTIFY_256_(func_name, result, default_case, imm, ...) \
  do { \
    switch(imm) { \
      case   0: result = func_name(__VA_ARGS__,   0); break; \
      case   1: result = func_name(__VA_ARGS__,   1); break; \
      case   2: result = func_name(__VA_ARGS__,   2); break; \
      case   3: result = func_name(__VA_ARGS__,   3); break; \
      case   4: result = func_name(__VA_ARGS__,   4); break; \
      case   5: result = func_name(__VA_ARGS__,   5); break; \
      case   6: result = func_name(__VA_ARGS__,   6); break; \
      case   7: result = func_name(__VA_ARGS__,   7); break; \
      case   8: result = func_name(__VA_ARGS__,   8); break; \
      case   9: result = func_name(__VA_ARGS__,   9); break; \
      case  10: result = func_name(__VA_ARGS__,  10); break; \
      case  11: result = func_name(__VA_ARGS__,  11); break; \
      case  12: result = func_name(__VA_ARGS__,  12); break; \
      case  13: result = func_name(__VA_ARGS__,  13); break; \
      case  14: result = func_name(__VA_ARGS__,  14); break; \
      case  15: result = func_name(__VA_ARGS__,  15); break; \
      case  16: result = func_name(__VA_ARGS__,  16); break; \
      case  17: result = func_name(__VA_ARGS__,  17); break; \
      case  18: result = func_name(__VA_ARGS__,  18); break; \
      case  19: result = func_name(__VA_ARGS__,  19); break; \
      case  20: result = func_name(__VA_ARGS__,  20); break; \
      case  21: result = func_name(__VA_ARGS__,  21); break; \
      case  22: result = func_name(__VA_ARGS__,  22); break; \
      case  23: result = func_name(__VA_ARGS__,  23); break; \
      case  24: result = func_name(__VA_ARGS__,  24); break; \
      case  25: result = func_name(__VA_ARGS__,  25); break; \
      case  26: result = func_name(__VA_ARGS__,  26); break; \
      case  27: result = func_name(__VA_ARGS__,  27); break; \
      case  28: result = func_name(__VA_ARGS__,  28); break; \
      case  29: result = func_name(__VA_ARGS__,  29); break; \
      case  30: result = func_name(__VA_ARGS__,  30); break; \
      case  31: result = func_name(__VA_ARGS__,  31); break; \
      case  32: result = func_name(__VA_ARGS__,  32); break; \
      case  33: result = func_name(__VA_ARGS__,  33); break; \
      case  34: result = func_name(__VA_ARGS__,  34); break; \
      case  35: result = func_name(__VA_ARGS__,  35); break; \
      case  36: result = func_name(__VA_ARGS__,  36); break; \
      case  37: result = func_name(__VA_ARGS__,  37); break; \
      case  38: result = func_name(__VA_ARGS__,  38); break; \
      case  39: result = func_name(__VA_ARGS__,  39); break; \
      case  40: result = func_name(__VA_ARGS__,  40); break; \
      case  41: result = func_name(__VA_ARGS__,  41); break; \
      case  42: result = func_name(__VA_ARGS__,  42); break; \
      case  43: result = func_name(__VA_ARGS__,  43); break; \
      case  44: result = func_name(__VA_ARGS__,  44); break; \
      case  45: result = func_name(__VA_ARGS__,  45); break; \
      case  46: result = func_name(__VA_ARGS__,  46); break; \
      case  47: result = func_name(__VA_ARGS__,  47); break; \
      case  48: result = func_name(__VA_ARGS__,  48); break; \
      case  49: result = func_name(__VA_ARGS__,  49); break; \
      case  50: result = func_name(__VA_ARGS__,  50); break; \
      case  51: result = func_name(__VA_ARGS__,  51); break; \
      case  52: result = func_name(__VA_ARGS__,  52); break; \
      case  53: result = func_name(__VA_ARGS__,  53); break; \
      case  54: result = func_name(__VA_ARGS__,  54); break; \
      case  55: result = func_name(__VA_ARGS__,  55); break; \
      case  56: result = func_name(__VA_ARGS__,  56); break; \
      case  57: result = func_name(__VA_ARGS__,  57); break; \
      case  58: result = func_name(__VA_ARGS__,  58); break; \
      case  59: result = func_name(__VA_ARGS__,  59); break; \
      case  60: result = func_name(__VA_ARGS__,  60); break; \
      case  61: result = func_name(__VA_ARGS__,  61); break; \
      case  62: result = func_name(__VA_ARGS__,  62); break; \
      case  63: result = func_name(__VA_ARGS__,  63); break; \
      case  64: result = func_name(__VA_ARGS__,  64); break; \
      case  65: result = func_name(__VA_ARGS__,  65); break; \
      case  66: result = func_name(__VA_ARGS__,  66); break; \
      case  67: result = func_name(__VA_ARGS__,  67); break; \
      case  68: result = func_name(__VA_ARGS__,  68); break; \
      case  69: result = func_name(__VA_ARGS__,  69); break; \
      case  70: result = func_name(__VA_ARGS__,  70); break; \
      case  71: result = func_name(__VA_ARGS__,  71); break; \
      case  72: result = func_name(__VA_ARGS__,  72); break; \
      case  73: result = func_name(__VA_ARGS__,  73); break; \
      case  74: result = func_name(__VA_ARGS__,  74); break; \
      case  75: result = func_name(__VA_ARGS__,  75); break; \
      case  76: result = func_name(__VA_ARGS__,  76); break; \
      case  77: result = func_name(__VA_ARGS__,  77); break; \
      case  78: result = func_name(__VA_ARGS__,  78); break; \
      case  79: result = func_name(__VA_ARGS__,  79); break; \
      case  80: result = func_name(__VA_ARGS__,  80); break; \
      case  81: result = func_name(__VA_ARGS__,  81); break; \
      case  82: result = func_name(__VA_ARGS__,  82); break; \
      case  83: result = func_name(__VA_ARGS__,  83); break; \
      case  84: result = func_name(__VA_ARGS__,  84); break; \
      case  85: result = func_name(__VA_ARGS__,  85); break; \
      case  86: result = func_name(__VA_ARGS__,  86); break; \
      case  87: result = func_name(__VA_ARGS__,  87); break; \
      case  88: result = func_name(__VA_ARGS__,  88); break; \
      case  89: result = func_name(__VA_ARGS__,  89); break; \
      case  90: result = func_name(__VA_ARGS__,  90); break; \
      case  91: result = func_name(__VA_ARGS__,  91); break; \
      case  92: result = func_name(__VA_ARGS__,  92); break; \
      case  93: result = func_name(__VA_ARGS__,  93); break; \
      case  94: result = func_name(__VA_ARGS__,  94); break; \
      case  95: result = func_name(__VA_ARGS__,  95); break; \
      case  96: result = func_name(__VA_ARGS__,  96); break; \
      case  97: result = func_name(__VA_ARGS__,  97); break; \
      case  98: result = func_name(__VA_ARGS__,  98); break; \
      case  99: result = func_name(__VA_ARGS__,  99); break; \
      case 100: result = func_name(__VA_ARGS__, 100); break; \
      case 101: result = func_name(__VA_ARGS__, 101); break; \
      case 102: result = func_name(__VA_ARGS__, 102); break; \
      case 103: result = func_name(__VA_ARGS__, 103); break; \
      case 104: result = func_name(__VA_ARGS__, 104); break; \
      case 105: result = func_name(__VA_ARGS__, 105); break; \
      case 106: result = func_name(__VA_ARGS__, 106); break; \
      case 107: result = func_name(__VA_ARGS__, 107); break; \
      case 108: result = func_name(__VA_ARGS__, 108); break; \
      case 109: result = func_name(__VA_ARGS__, 109); break; \
      case 110: result = func_name(__VA_ARGS__, 110); break; \
      case 111: result = func_name(__VA_ARGS__, 111); break; \
      case 112: result = func_name(__VA_ARGS__, 112); break; \
      case 113: result = func_name(__VA_ARGS__, 113); break; \
      case 114: result = func_name(__VA_ARGS__, 114); break; \
      case 115: result = func_name(__VA_ARGS__, 115); break; \
      case 116: result = func_name(__VA_ARGS__, 116); break; \
      case 117: result = func_name(__VA_ARGS__, 117); break; \
      case 118: result = func_name(__VA_ARGS__, 118); break; \
      case 119: result = func_name(__VA_ARGS__, 119); break; \
      case 120: result = func_name(__VA_ARGS__, 120); break; \
      case 121: result = func_name(__VA_ARGS__, 121); break; \
      case 122: result = func_name(__VA_ARGS__, 122); break; \
      case 123: result = func_name(__VA_ARGS__, 123); break; \
      case 124: result = func_name(__VA_ARGS__, 124); break; \
      case 125: result = func_name(__VA_ARGS__, 125); break; \
      case 126: result = func_name(__VA_ARGS__, 126); break; \
      case 127: result = func_name(__VA_ARGS__, 127); break; \
      case 128: result = func_name(__VA_ARGS__, 128); break; \
      case 129: result = func_name(__VA_ARGS__, 129); break; \
      case 130: result = func_name(__VA_ARGS__, 130); break; \
      case 131: result = func_name(__VA_ARGS__, 131); break; \
      case 132: result = func_name(__VA_ARGS__, 132); break; \
      case 133: result = func_name(__VA_ARGS__, 133); break; \
      case 134: result = func_name(__VA_ARGS__, 134); break; \
      case 135: result = func_name(__VA_ARGS__, 135); break; \
      case 136: result = func_name(__VA_ARGS__, 136); break; \
      case 137: result = func_name(__VA_ARGS__, 137); break; \
      case 138: result = func_name(__VA_ARGS__, 138); break; \
      case 139: result = func_name(__VA_ARGS__, 139); break; \
      case 140: result = func_name(__VA_ARGS__, 140); break; \
      case 141: result = func_name(__VA_ARGS__, 141); break; \
      case 142: result = func_name(__VA_ARGS__, 142); break; \
      case 143: result = func_name(__VA_ARGS__, 143); break; \
      case 144: result = func_name(__VA_ARGS__, 144); break; \
      case 145: result = func_name(__VA_ARGS__, 145); break; \
      case 146: result = func_name(__VA_ARGS__, 146); break; \
      case 147: result = func_name(__VA_ARGS__, 147); break; \
      case 148: result = func_name(__VA_ARGS__, 148); break; \
      case 149: result = func_name(__VA_ARGS__, 149); break; \
      case 150: result = func_name(__VA_ARGS__, 150); break; \
      case 151: result = func_name(__VA_ARGS__, 151); break; \
      case 152: result = func_name(__VA_ARGS__, 152); break; \
      case 153: result = func_name(__VA_ARGS__, 153); break; \
      case 154: result = func_name(__VA_ARGS__, 154); break; \
      case 155: result = func_name(__VA_ARGS__, 155); break; \
      case 156: result = func_name(__VA_ARGS__, 156); break; \
      case 157: result = func_name(__VA_ARGS__, 157); break; \
      case 158: result = func_name(__VA_ARGS__, 158); break; \
      case 159: result = func_name(__VA_ARGS__, 159); break; \
      case 160: result = func_name(__VA_ARGS__, 160); break; \
      case 161: result = func_name(__VA_ARGS__, 161); break; \
      case 162: result = func_name(__VA_ARGS__, 162); break; \
      case 163: result = func_name(__VA_ARGS__, 163); break; \
      case 164: result = func_name(__VA_ARGS__, 164); break; \
      case 165: result = func_name(__VA_ARGS__, 165); break; \
      case 166: result = func_name(__VA_ARGS__, 166); break; \
      case 167: result = func_name(__VA_ARGS__, 167); break; \
      case 168: result = func_name(__VA_ARGS__, 168); break; \
      case 169: result = func_name(__VA_ARGS__, 169); break; \
      case 170: result = func_name(__VA_ARGS__, 170); break; \
      case 171: result = func_name(__VA_ARGS__, 171); break; \
      case 172: result = func_name(__VA_ARGS__, 172); break; \
      case 173: result = func_name(__VA_ARGS__, 173); break; \
      case 174: result = func_name(__VA_ARGS__, 174); break; \
      case 175: result = func_name(__VA_ARGS__, 175); break; \
      case 176: result = func_name(__VA_ARGS__, 176); break; \
      case 177: result = func_name(__VA_ARGS__, 177); break; \
      case 178: result = func_name(__VA_ARGS__, 178); break; \
      case 179: result = func_name(__VA_ARGS__, 179); break; \
      case 180: result = func_name(__VA_ARGS__, 180); break; \
      case 181: result = func_name(__VA_ARGS__, 181); break; \
      case 182: result = func_name(__VA_ARGS__, 182); break; \
      case 183: result = func_name(__VA_ARGS__, 183); break; \
      case 184: result = func_name(__VA_ARGS__, 184); break; \
      case 185: result = func_name(__VA_ARGS__, 185); break; \
      case 186: result = func_name(__VA_ARGS__, 186); break; \
      case 187: result = func_name(__VA_ARGS__, 187); break; \
      case 188: result = func_name(__VA_ARGS__, 188); break; \
      case 189: result = func_name(__VA_ARGS__, 189); break; \
      case 190: result = func_name(__VA_ARGS__, 190); break; \
      case 191: result = func_name(__VA_ARGS__, 191); break; \
      case 192: result = func_name(__VA_ARGS__, 192); break; \
      case 193: result = func_name(__VA_ARGS__, 193); break; \
      case 194: result = func_name(__VA_ARGS__, 194); break; \
      case 195: result = func_name(__VA_ARGS__, 195); break; \
      case 196: result = func_name(__VA_ARGS__, 196); break; \
      case 197: result = func_name(__VA_ARGS__, 197); break; \
      case 198: result = func_name(__VA_ARGS__, 198); break; \
      case 199: result = func_name(__VA_ARGS__, 199); break; \
      case 200: result = func_name(__VA_ARGS__, 200); break; \
      case 201: result = func_name(__VA_ARGS__, 201); break; \
      case 202: result = func_name(__VA_ARGS__, 202); break; \
      case 203: result = func_name(__VA_ARGS__, 203); break; \
      case 204: result = func_name(__VA_ARGS__, 204); break; \
      case 205: result = func_name(__VA_ARGS__, 205); break; \
      case 206: result = func_name(__VA_ARGS__, 206); break; \
      case 207: result = func_name(__VA_ARGS__, 207); break; \
      case 208: result = func_name(__VA_ARGS__, 208); break; \
      case 209: result = func_name(__VA_ARGS__, 209); break; \
      case 210: result = func_name(__VA_ARGS__, 210); break; \
      case 211: result = func_name(__VA_ARGS__, 211); break; \
      case 212: result = func_name(__VA_ARGS__, 212); break; \
      case 213: result = func_name(__VA_ARGS__, 213); break; \
      case 214: result = func_name(__VA_ARGS__, 214); break; \
      case 215: result = func_name(__VA_ARGS__, 215); break; \
      case 216: result = func_name(__VA_ARGS__, 216); break; \
      case 217: result = func_name(__VA_ARGS__, 217); break; \
      case 218: result = func_name(__VA_ARGS__, 218); break; \
      case 219: result = func_name(__VA_ARGS__, 219); break; \
      case 220: result = func_name(__VA_ARGS__, 220); break; \
      case 221: result = func_name(__VA_ARGS__, 221); break; \
      case 222: result = func_name(__VA_ARGS__, 222); break; \
      case 223: result = func_name(__VA_ARGS__, 223); break; \
      case 224: result = func_name(__VA_ARGS__, 224); break; \
      case 225: result = func_name(__VA_ARGS__, 225); break; \
      case 226: result = func_name(__VA_ARGS__, 226); break; \
      case 227: result = func_name(__VA_ARGS__, 227); break; \
      case 228: result = func_name(__VA_ARGS__, 228); break; \
      case 229: result = func_name(__VA_ARGS__, 229); break; \
      case 230: result = func_name(__VA_ARGS__, 230); break; \
      case 231: result = func_name(__VA_ARGS__, 231); break; \
      case 232: result = func_name(__VA_ARGS__, 232); break; \
      case 233: result = func_name(__VA_ARGS__, 233); break; \
      case 234: result = func_name(__VA_ARGS__, 234); break; \
      case 235: result = func_name(__VA_ARGS__, 235); break; \
      case 236: result = func_name(__VA_ARGS__, 236); break; \
      case 237: result = func_name(__VA_ARGS__, 237); break; \
      case 238: result = func_name(__VA_ARGS__, 238); break; \
      case 239: result = func_name(__VA_ARGS__, 239); break; \
      case 240: result = func_name(__VA_ARGS__, 240); break; \
      case 241: result = func_name(__VA_ARGS__, 241); break; \
      case 242: result = func_name(__VA_ARGS__, 242); break; \
      case 243: result = func_name(__VA_ARGS__, 243); break; \
      case 244: result = func_name(__VA_ARGS__, 244); break; \
      case 245: result = func_name(__VA_ARGS__, 245); break; \
      case 246: result = func_name(__VA_ARGS__, 246); break; \
      case 247: result = func_name(__VA_ARGS__, 247); break; \
      case 248: result = func_name(__VA_ARGS__, 248); break; \
      case 249: result = func_name(__VA_ARGS__, 249); break; \
      case 250: result = func_name(__VA_ARGS__, 250); break; \
      case 251: result = func_name(__VA_ARGS__, 251); break; \
      case 252: result = func_name(__VA_ARGS__, 252); break; \
      case 253: result = func_name(__VA_ARGS__, 253); break; \
      case 254: result = func_name(__VA_ARGS__, 254); break; \
      case 255: result = func_name(__VA_ARGS__, 255); break; \
      default: result = default_case; break; \
    } \
  } while (0)

#define SIMDE_CONSTIFY_256_NEW(func_name, result, default_case, imm, sae, ...) \
  do { \
    if(sae & SIMDE_MM_FROUND_NO_EXC){ \
      switch(imm) { \
        case   0: result = func_name(__VA_ARGS__,   0, SIMDE_MM_FROUND_NO_EXC); break; \
        case   1: result = func_name(__VA_ARGS__,   1, SIMDE_MM_FROUND_NO_EXC); break; \
        case   2: result = func_name(__VA_ARGS__,   2, SIMDE_MM_FROUND_NO_EXC); break; \
        case   3: result = func_name(__VA_ARGS__,   3, SIMDE_MM_FROUND_NO_EXC); break; \
        case   4: result = func_name(__VA_ARGS__,   4, SIMDE_MM_FROUND_NO_EXC); break; \
        case   5: result = func_name(__VA_ARGS__,   5, SIMDE_MM_FROUND_NO_EXC); break; \
        case   6: result = func_name(__VA_ARGS__,   6, SIMDE_MM_FROUND_NO_EXC); break; \
        case   7: result = func_name(__VA_ARGS__,   7, SIMDE_MM_FROUND_NO_EXC); break; \
        case   8: result = func_name(__VA_ARGS__,   8, SIMDE_MM_FROUND_NO_EXC); break; \
        case   9: result = func_name(__VA_ARGS__,   9, SIMDE_MM_FROUND_NO_EXC); break; \
        case  10: result = func_name(__VA_ARGS__,  10, SIMDE_MM_FROUND_NO_EXC); break; \
        case  11: result = func_name(__VA_ARGS__,  11, SIMDE_MM_FROUND_NO_EXC); break; \
        case  12: result = func_name(__VA_ARGS__,  12, SIMDE_MM_FROUND_NO_EXC); break; \
        case  13: result = func_name(__VA_ARGS__,  13, SIMDE_MM_FROUND_NO_EXC); break; \
        case  14: result = func_name(__VA_ARGS__,  14, SIMDE_MM_FROUND_NO_EXC); break; \
        case  15: result = func_name(__VA_ARGS__,  15, SIMDE_MM_FROUND_NO_EXC); break; \
        case  16: result = func_name(__VA_ARGS__,  16, SIMDE_MM_FROUND_NO_EXC); break; \
        case  17: result = func_name(__VA_ARGS__,  17, SIMDE_MM_FROUND_NO_EXC); break; \
        case  18: result = func_name(__VA_ARGS__,  18, SIMDE_MM_FROUND_NO_EXC); break; \
        case  19: result = func_name(__VA_ARGS__,  19, SIMDE_MM_FROUND_NO_EXC); break; \
        case  20: result = func_name(__VA_ARGS__,  20, SIMDE_MM_FROUND_NO_EXC); break; \
        case  21: result = func_name(__VA_ARGS__,  21, SIMDE_MM_FROUND_NO_EXC); break; \
        case  22: result = func_name(__VA_ARGS__,  22, SIMDE_MM_FROUND_NO_EXC); break; \
        case  23: result = func_name(__VA_ARGS__,  23, SIMDE_MM_FROUND_NO_EXC); break; \
        case  24: result = func_name(__VA_ARGS__,  24, SIMDE_MM_FROUND_NO_EXC); break; \
        case  25: result = func_name(__VA_ARGS__,  25, SIMDE_MM_FROUND_NO_EXC); break; \
        case  26: result = func_name(__VA_ARGS__,  26, SIMDE_MM_FROUND_NO_EXC); break; \
        case  27: result = func_name(__VA_ARGS__,  27, SIMDE_MM_FROUND_NO_EXC); break; \
        case  28: result = func_name(__VA_ARGS__,  28, SIMDE_MM_FROUND_NO_EXC); break; \
        case  29: result = func_name(__VA_ARGS__,  29, SIMDE_MM_FROUND_NO_EXC); break; \
        case  30: result = func_name(__VA_ARGS__,  30, SIMDE_MM_FROUND_NO_EXC); break; \
        case  31: result = func_name(__VA_ARGS__,  31, SIMDE_MM_FROUND_NO_EXC); break; \
        case  32: result = func_name(__VA_ARGS__,  32, SIMDE_MM_FROUND_NO_EXC); break; \
        case  33: result = func_name(__VA_ARGS__,  33, SIMDE_MM_FROUND_NO_EXC); break; \
        case  34: result = func_name(__VA_ARGS__,  34, SIMDE_MM_FROUND_NO_EXC); break; \
        case  35: result = func_name(__VA_ARGS__,  35, SIMDE_MM_FROUND_NO_EXC); break; \
        case  36: result = func_name(__VA_ARGS__,  36, SIMDE_MM_FROUND_NO_EXC); break; \
        case  37: result = func_name(__VA_ARGS__,  37, SIMDE_MM_FROUND_NO_EXC); break; \
        case  38: result = func_name(__VA_ARGS__,  38, SIMDE_MM_FROUND_NO_EXC); break; \
        case  39: result = func_name(__VA_ARGS__,  39, SIMDE_MM_FROUND_NO_EXC); break; \
        case  40: result = func_name(__VA_ARGS__,  40, SIMDE_MM_FROUND_NO_EXC); break; \
        case  41: result = func_name(__VA_ARGS__,  41, SIMDE_MM_FROUND_NO_EXC); break; \
        case  42: result = func_name(__VA_ARGS__,  42, SIMDE_MM_FROUND_NO_EXC); break; \
        case  43: result = func_name(__VA_ARGS__,  43, SIMDE_MM_FROUND_NO_EXC); break; \
        case  44: result = func_name(__VA_ARGS__,  44, SIMDE_MM_FROUND_NO_EXC); break; \
        case  45: result = func_name(__VA_ARGS__,  45, SIMDE_MM_FROUND_NO_EXC); break; \
        case  46: result = func_name(__VA_ARGS__,  46, SIMDE_MM_FROUND_NO_EXC); break; \
        case  47: result = func_name(__VA_ARGS__,  47, SIMDE_MM_FROUND_NO_EXC); break; \
        case  48: result = func_name(__VA_ARGS__,  48, SIMDE_MM_FROUND_NO_EXC); break; \
        case  49: result = func_name(__VA_ARGS__,  49, SIMDE_MM_FROUND_NO_EXC); break; \
        case  50: result = func_name(__VA_ARGS__,  50, SIMDE_MM_FROUND_NO_EXC); break; \
        case  51: result = func_name(__VA_ARGS__,  51, SIMDE_MM_FROUND_NO_EXC); break; \
        case  52: result = func_name(__VA_ARGS__,  52, SIMDE_MM_FROUND_NO_EXC); break; \
        case  53: result = func_name(__VA_ARGS__,  53, SIMDE_MM_FROUND_NO_EXC); break; \
        case  54: result = func_name(__VA_ARGS__,  54, SIMDE_MM_FROUND_NO_EXC); break; \
        case  55: result = func_name(__VA_ARGS__,  55, SIMDE_MM_FROUND_NO_EXC); break; \
        case  56: result = func_name(__VA_ARGS__,  56, SIMDE_MM_FROUND_NO_EXC); break; \
        case  57: result = func_name(__VA_ARGS__,  57, SIMDE_MM_FROUND_NO_EXC); break; \
        case  58: result = func_name(__VA_ARGS__,  58, SIMDE_MM_FROUND_NO_EXC); break; \
        case  59: result = func_name(__VA_ARGS__,  59, SIMDE_MM_FROUND_NO_EXC); break; \
        case  60: result = func_name(__VA_ARGS__,  60, SIMDE_MM_FROUND_NO_EXC); break; \
        case  61: result = func_name(__VA_ARGS__,  61, SIMDE_MM_FROUND_NO_EXC); break; \
        case  62: result = func_name(__VA_ARGS__,  62, SIMDE_MM_FROUND_NO_EXC); break; \
        case  63: result = func_name(__VA_ARGS__,  63, SIMDE_MM_FROUND_NO_EXC); break; \
        case  64: result = func_name(__VA_ARGS__,  64, SIMDE_MM_FROUND_NO_EXC); break; \
        case  65: result = func_name(__VA_ARGS__,  65, SIMDE_MM_FROUND_NO_EXC); break; \
        case  66: result = func_name(__VA_ARGS__,  66, SIMDE_MM_FROUND_NO_EXC); break; \
        case  67: result = func_name(__VA_ARGS__,  67, SIMDE_MM_FROUND_NO_EXC); break; \
        case  68: result = func_name(__VA_ARGS__,  68, SIMDE_MM_FROUND_NO_EXC); break; \
        case  69: result = func_name(__VA_ARGS__,  69, SIMDE_MM_FROUND_NO_EXC); break; \
        case  70: result = func_name(__VA_ARGS__,  70, SIMDE_MM_FROUND_NO_EXC); break; \
        case  71: result = func_name(__VA_ARGS__,  71, SIMDE_MM_FROUND_NO_EXC); break; \
        case  72: result = func_name(__VA_ARGS__,  72, SIMDE_MM_FROUND_NO_EXC); break; \
        case  73: result = func_name(__VA_ARGS__,  73, SIMDE_MM_FROUND_NO_EXC); break; \
        case  74: result = func_name(__VA_ARGS__,  74, SIMDE_MM_FROUND_NO_EXC); break; \
        case  75: result = func_name(__VA_ARGS__,  75, SIMDE_MM_FROUND_NO_EXC); break; \
        case  76: result = func_name(__VA_ARGS__,  76, SIMDE_MM_FROUND_NO_EXC); break; \
        case  77: result = func_name(__VA_ARGS__,  77, SIMDE_MM_FROUND_NO_EXC); break; \
        case  78: result = func_name(__VA_ARGS__,  78, SIMDE_MM_FROUND_NO_EXC); break; \
        case  79: result = func_name(__VA_ARGS__,  79, SIMDE_MM_FROUND_NO_EXC); break; \
        case  80: result = func_name(__VA_ARGS__,  80, SIMDE_MM_FROUND_NO_EXC); break; \
        case  81: result = func_name(__VA_ARGS__,  81, SIMDE_MM_FROUND_NO_EXC); break; \
        case  82: result = func_name(__VA_ARGS__,  82, SIMDE_MM_FROUND_NO_EXC); break; \
        case  83: result = func_name(__VA_ARGS__,  83, SIMDE_MM_FROUND_NO_EXC); break; \
        case  84: result = func_name(__VA_ARGS__,  84, SIMDE_MM_FROUND_NO_EXC); break; \
        case  85: result = func_name(__VA_ARGS__,  85, SIMDE_MM_FROUND_NO_EXC); break; \
        case  86: result = func_name(__VA_ARGS__,  86, SIMDE_MM_FROUND_NO_EXC); break; \
        case  87: result = func_name(__VA_ARGS__,  87, SIMDE_MM_FROUND_NO_EXC); break; \
        case  88: result = func_name(__VA_ARGS__,  88, SIMDE_MM_FROUND_NO_EXC); break; \
        case  89: result = func_name(__VA_ARGS__,  89, SIMDE_MM_FROUND_NO_EXC); break; \
        case  90: result = func_name(__VA_ARGS__,  90, SIMDE_MM_FROUND_NO_EXC); break; \
        case  91: result = func_name(__VA_ARGS__,  91, SIMDE_MM_FROUND_NO_EXC); break; \
        case  92: result = func_name(__VA_ARGS__,  92, SIMDE_MM_FROUND_NO_EXC); break; \
        case  93: result = func_name(__VA_ARGS__,  93, SIMDE_MM_FROUND_NO_EXC); break; \
        case  94: result = func_name(__VA_ARGS__,  94, SIMDE_MM_FROUND_NO_EXC); break; \
        case  95: result = func_name(__VA_ARGS__,  95, SIMDE_MM_FROUND_NO_EXC); break; \
        case  96: result = func_name(__VA_ARGS__,  96, SIMDE_MM_FROUND_NO_EXC); break; \
        case  97: result = func_name(__VA_ARGS__,  97, SIMDE_MM_FROUND_NO_EXC); break; \
        case  98: result = func_name(__VA_ARGS__,  98, SIMDE_MM_FROUND_NO_EXC); break; \
        case  99: result = func_name(__VA_ARGS__,  99, SIMDE_MM_FROUND_NO_EXC); break; \
        case 100: result = func_name(__VA_ARGS__, 100, SIMDE_MM_FROUND_NO_EXC); break; \
        case 101: result = func_name(__VA_ARGS__, 101, SIMDE_MM_FROUND_NO_EXC); break; \
        case 102: result = func_name(__VA_ARGS__, 102, SIMDE_MM_FROUND_NO_EXC); break; \
        case 103: result = func_name(__VA_ARGS__, 103, SIMDE_MM_FROUND_NO_EXC); break; \
        case 104: result = func_name(__VA_ARGS__, 104, SIMDE_MM_FROUND_NO_EXC); break; \
        case 105: result = func_name(__VA_ARGS__, 105, SIMDE_MM_FROUND_NO_EXC); break; \
        case 106: result = func_name(__VA_ARGS__, 106, SIMDE_MM_FROUND_NO_EXC); break; \
        case 107: result = func_name(__VA_ARGS__, 107, SIMDE_MM_FROUND_NO_EXC); break; \
        case 108: result = func_name(__VA_ARGS__, 108, SIMDE_MM_FROUND_NO_EXC); break; \
        case 109: result = func_name(__VA_ARGS__, 109, SIMDE_MM_FROUND_NO_EXC); break; \
        case 110: result = func_name(__VA_ARGS__, 110, SIMDE_MM_FROUND_NO_EXC); break; \
        case 111: result = func_name(__VA_ARGS__, 111, SIMDE_MM_FROUND_NO_EXC); break; \
        case 112: result = func_name(__VA_ARGS__, 112, SIMDE_MM_FROUND_NO_EXC); break; \
        case 113: result = func_name(__VA_ARGS__, 113, SIMDE_MM_FROUND_NO_EXC); break; \
        case 114: result = func_name(__VA_ARGS__, 114, SIMDE_MM_FROUND_NO_EXC); break; \
        case 115: result = func_name(__VA_ARGS__, 115, SIMDE_MM_FROUND_NO_EXC); break; \
        case 116: result = func_name(__VA_ARGS__, 116, SIMDE_MM_FROUND_NO_EXC); break; \
        case 117: result = func_name(__VA_ARGS__, 117, SIMDE_MM_FROUND_NO_EXC); break; \
        case 118: result = func_name(__VA_ARGS__, 118, SIMDE_MM_FROUND_NO_EXC); break; \
        case 119: result = func_name(__VA_ARGS__, 119, SIMDE_MM_FROUND_NO_EXC); break; \
        case 120: result = func_name(__VA_ARGS__, 120, SIMDE_MM_FROUND_NO_EXC); break; \
        case 121: result = func_name(__VA_ARGS__, 121, SIMDE_MM_FROUND_NO_EXC); break; \
        case 122: result = func_name(__VA_ARGS__, 122, SIMDE_MM_FROUND_NO_EXC); break; \
        case 123: result = func_name(__VA_ARGS__, 123, SIMDE_MM_FROUND_NO_EXC); break; \
        case 124: result = func_name(__VA_ARGS__, 124, SIMDE_MM_FROUND_NO_EXC); break; \
        case 125: result = func_name(__VA_ARGS__, 125, SIMDE_MM_FROUND_NO_EXC); break; \
        case 126: result = func_name(__VA_ARGS__, 126, SIMDE_MM_FROUND_NO_EXC); break; \
        case 127: result = func_name(__VA_ARGS__, 127, SIMDE_MM_FROUND_NO_EXC); break; \
        case 128: result = func_name(__VA_ARGS__, 128, SIMDE_MM_FROUND_NO_EXC); break; \
        case 129: result = func_name(__VA_ARGS__, 129, SIMDE_MM_FROUND_NO_EXC); break; \
        case 130: result = func_name(__VA_ARGS__, 130, SIMDE_MM_FROUND_NO_EXC); break; \
        case 131: result = func_name(__VA_ARGS__, 131, SIMDE_MM_FROUND_NO_EXC); break; \
        case 132: result = func_name(__VA_ARGS__, 132, SIMDE_MM_FROUND_NO_EXC); break; \
        case 133: result = func_name(__VA_ARGS__, 133, SIMDE_MM_FROUND_NO_EXC); break; \
        case 134: result = func_name(__VA_ARGS__, 134, SIMDE_MM_FROUND_NO_EXC); break; \
        case 135: result = func_name(__VA_ARGS__, 135, SIMDE_MM_FROUND_NO_EXC); break; \
        case 136: result = func_name(__VA_ARGS__, 136, SIMDE_MM_FROUND_NO_EXC); break; \
        case 137: result = func_name(__VA_ARGS__, 137, SIMDE_MM_FROUND_NO_EXC); break; \
        case 138: result = func_name(__VA_ARGS__, 138, SIMDE_MM_FROUND_NO_EXC); break; \
        case 139: result = func_name(__VA_ARGS__, 139, SIMDE_MM_FROUND_NO_EXC); break; \
        case 140: result = func_name(__VA_ARGS__, 140, SIMDE_MM_FROUND_NO_EXC); break; \
        case 141: result = func_name(__VA_ARGS__, 141, SIMDE_MM_FROUND_NO_EXC); break; \
        case 142: result = func_name(__VA_ARGS__, 142, SIMDE_MM_FROUND_NO_EXC); break; \
        case 143: result = func_name(__VA_ARGS__, 143, SIMDE_MM_FROUND_NO_EXC); break; \
        case 144: result = func_name(__VA_ARGS__, 144, SIMDE_MM_FROUND_NO_EXC); break; \
        case 145: result = func_name(__VA_ARGS__, 145, SIMDE_MM_FROUND_NO_EXC); break; \
        case 146: result = func_name(__VA_ARGS__, 146, SIMDE_MM_FROUND_NO_EXC); break; \
        case 147: result = func_name(__VA_ARGS__, 147, SIMDE_MM_FROUND_NO_EXC); break; \
        case 148: result = func_name(__VA_ARGS__, 148, SIMDE_MM_FROUND_NO_EXC); break; \
        case 149: result = func_name(__VA_ARGS__, 149, SIMDE_MM_FROUND_NO_EXC); break; \
        case 150: result = func_name(__VA_ARGS__, 150, SIMDE_MM_FROUND_NO_EXC); break; \
        case 151: result = func_name(__VA_ARGS__, 151, SIMDE_MM_FROUND_NO_EXC); break; \
        case 152: result = func_name(__VA_ARGS__, 152, SIMDE_MM_FROUND_NO_EXC); break; \
        case 153: result = func_name(__VA_ARGS__, 153, SIMDE_MM_FROUND_NO_EXC); break; \
        case 154: result = func_name(__VA_ARGS__, 154, SIMDE_MM_FROUND_NO_EXC); break; \
        case 155: result = func_name(__VA_ARGS__, 155, SIMDE_MM_FROUND_NO_EXC); break; \
        case 156: result = func_name(__VA_ARGS__, 156, SIMDE_MM_FROUND_NO_EXC); break; \
        case 157: result = func_name(__VA_ARGS__, 157, SIMDE_MM_FROUND_NO_EXC); break; \
        case 158: result = func_name(__VA_ARGS__, 158, SIMDE_MM_FROUND_NO_EXC); break; \
        case 159: result = func_name(__VA_ARGS__, 159, SIMDE_MM_FROUND_NO_EXC); break; \
        case 160: result = func_name(__VA_ARGS__, 160, SIMDE_MM_FROUND_NO_EXC); break; \
        case 161: result = func_name(__VA_ARGS__, 161, SIMDE_MM_FROUND_NO_EXC); break; \
        case 162: result = func_name(__VA_ARGS__, 162, SIMDE_MM_FROUND_NO_EXC); break; \
        case 163: result = func_name(__VA_ARGS__, 163, SIMDE_MM_FROUND_NO_EXC); break; \
        case 164: result = func_name(__VA_ARGS__, 164, SIMDE_MM_FROUND_NO_EXC); break; \
        case 165: result = func_name(__VA_ARGS__, 165, SIMDE_MM_FROUND_NO_EXC); break; \
        case 166: result = func_name(__VA_ARGS__, 166, SIMDE_MM_FROUND_NO_EXC); break; \
        case 167: result = func_name(__VA_ARGS__, 167, SIMDE_MM_FROUND_NO_EXC); break; \
        case 168: result = func_name(__VA_ARGS__, 168, SIMDE_MM_FROUND_NO_EXC); break; \
        case 169: result = func_name(__VA_ARGS__, 169, SIMDE_MM_FROUND_NO_EXC); break; \
        case 170: result = func_name(__VA_ARGS__, 170, SIMDE_MM_FROUND_NO_EXC); break; \
        case 171: result = func_name(__VA_ARGS__, 171, SIMDE_MM_FROUND_NO_EXC); break; \
        case 172: result = func_name(__VA_ARGS__, 172, SIMDE_MM_FROUND_NO_EXC); break; \
        case 173: result = func_name(__VA_ARGS__, 173, SIMDE_MM_FROUND_NO_EXC); break; \
        case 174: result = func_name(__VA_ARGS__, 174, SIMDE_MM_FROUND_NO_EXC); break; \
        case 175: result = func_name(__VA_ARGS__, 175, SIMDE_MM_FROUND_NO_EXC); break; \
        case 176: result = func_name(__VA_ARGS__, 176, SIMDE_MM_FROUND_NO_EXC); break; \
        case 177: result = func_name(__VA_ARGS__, 177, SIMDE_MM_FROUND_NO_EXC); break; \
        case 178: result = func_name(__VA_ARGS__, 178, SIMDE_MM_FROUND_NO_EXC); break; \
        case 179: result = func_name(__VA_ARGS__, 179, SIMDE_MM_FROUND_NO_EXC); break; \
        case 180: result = func_name(__VA_ARGS__, 180, SIMDE_MM_FROUND_NO_EXC); break; \
        case 181: result = func_name(__VA_ARGS__, 181, SIMDE_MM_FROUND_NO_EXC); break; \
        case 182: result = func_name(__VA_ARGS__, 182, SIMDE_MM_FROUND_NO_EXC); break; \
        case 183: result = func_name(__VA_ARGS__, 183, SIMDE_MM_FROUND_NO_EXC); break; \
        case 184: result = func_name(__VA_ARGS__, 184, SIMDE_MM_FROUND_NO_EXC); break; \
        case 185: result = func_name(__VA_ARGS__, 185, SIMDE_MM_FROUND_NO_EXC); break; \
        case 186: result = func_name(__VA_ARGS__, 186, SIMDE_MM_FROUND_NO_EXC); break; \
        case 187: result = func_name(__VA_ARGS__, 187, SIMDE_MM_FROUND_NO_EXC); break; \
        case 188: result = func_name(__VA_ARGS__, 188, SIMDE_MM_FROUND_NO_EXC); break; \
        case 189: result = func_name(__VA_ARGS__, 189, SIMDE_MM_FROUND_NO_EXC); break; \
        case 190: result = func_name(__VA_ARGS__, 190, SIMDE_MM_FROUND_NO_EXC); break; \
        case 191: result = func_name(__VA_ARGS__, 191, SIMDE_MM_FROUND_NO_EXC); break; \
        case 192: result = func_name(__VA_ARGS__, 192, SIMDE_MM_FROUND_NO_EXC); break; \
        case 193: result = func_name(__VA_ARGS__, 193, SIMDE_MM_FROUND_NO_EXC); break; \
        case 194: result = func_name(__VA_ARGS__, 194, SIMDE_MM_FROUND_NO_EXC); break; \
        case 195: result = func_name(__VA_ARGS__, 195, SIMDE_MM_FROUND_NO_EXC); break; \
        case 196: result = func_name(__VA_ARGS__, 196, SIMDE_MM_FROUND_NO_EXC); break; \
        case 197: result = func_name(__VA_ARGS__, 197, SIMDE_MM_FROUND_NO_EXC); break; \
        case 198: result = func_name(__VA_ARGS__, 198, SIMDE_MM_FROUND_NO_EXC); break; \
        case 199: result = func_name(__VA_ARGS__, 199, SIMDE_MM_FROUND_NO_EXC); break; \
        case 200: result = func_name(__VA_ARGS__, 200, SIMDE_MM_FROUND_NO_EXC); break; \
        case 201: result = func_name(__VA_ARGS__, 201, SIMDE_MM_FROUND_NO_EXC); break; \
        case 202: result = func_name(__VA_ARGS__, 202, SIMDE_MM_FROUND_NO_EXC); break; \
        case 203: result = func_name(__VA_ARGS__, 203, SIMDE_MM_FROUND_NO_EXC); break; \
        case 204: result = func_name(__VA_ARGS__, 204, SIMDE_MM_FROUND_NO_EXC); break; \
        case 205: result = func_name(__VA_ARGS__, 205, SIMDE_MM_FROUND_NO_EXC); break; \
        case 206: result = func_name(__VA_ARGS__, 206, SIMDE_MM_FROUND_NO_EXC); break; \
        case 207: result = func_name(__VA_ARGS__, 207, SIMDE_MM_FROUND_NO_EXC); break; \
        case 208: result = func_name(__VA_ARGS__, 208, SIMDE_MM_FROUND_NO_EXC); break; \
        case 209: result = func_name(__VA_ARGS__, 209, SIMDE_MM_FROUND_NO_EXC); break; \
        case 210: result = func_name(__VA_ARGS__, 210, SIMDE_MM_FROUND_NO_EXC); break; \
        case 211: result = func_name(__VA_ARGS__, 211, SIMDE_MM_FROUND_NO_EXC); break; \
        case 212: result = func_name(__VA_ARGS__, 212, SIMDE_MM_FROUND_NO_EXC); break; \
        case 213: result = func_name(__VA_ARGS__, 213, SIMDE_MM_FROUND_NO_EXC); break; \
        case 214: result = func_name(__VA_ARGS__, 214, SIMDE_MM_FROUND_NO_EXC); break; \
        case 215: result = func_name(__VA_ARGS__, 215, SIMDE_MM_FROUND_NO_EXC); break; \
        case 216: result = func_name(__VA_ARGS__, 216, SIMDE_MM_FROUND_NO_EXC); break; \
        case 217: result = func_name(__VA_ARGS__, 217, SIMDE_MM_FROUND_NO_EXC); break; \
        case 218: result = func_name(__VA_ARGS__, 218, SIMDE_MM_FROUND_NO_EXC); break; \
        case 219: result = func_name(__VA_ARGS__, 219, SIMDE_MM_FROUND_NO_EXC); break; \
        case 220: result = func_name(__VA_ARGS__, 220, SIMDE_MM_FROUND_NO_EXC); break; \
        case 221: result = func_name(__VA_ARGS__, 221, SIMDE_MM_FROUND_NO_EXC); break; \
        case 222: result = func_name(__VA_ARGS__, 222, SIMDE_MM_FROUND_NO_EXC); break; \
        case 223: result = func_name(__VA_ARGS__, 223, SIMDE_MM_FROUND_NO_EXC); break; \
        case 224: result = func_name(__VA_ARGS__, 224, SIMDE_MM_FROUND_NO_EXC); break; \
        case 225: result = func_name(__VA_ARGS__, 225, SIMDE_MM_FROUND_NO_EXC); break; \
        case 226: result = func_name(__VA_ARGS__, 226, SIMDE_MM_FROUND_NO_EXC); break; \
        case 227: result = func_name(__VA_ARGS__, 227, SIMDE_MM_FROUND_NO_EXC); break; \
        case 228: result = func_name(__VA_ARGS__, 228, SIMDE_MM_FROUND_NO_EXC); break; \
        case 229: result = func_name(__VA_ARGS__, 229, SIMDE_MM_FROUND_NO_EXC); break; \
        case 230: result = func_name(__VA_ARGS__, 230, SIMDE_MM_FROUND_NO_EXC); break; \
        case 231: result = func_name(__VA_ARGS__, 231, SIMDE_MM_FROUND_NO_EXC); break; \
        case 232: result = func_name(__VA_ARGS__, 232, SIMDE_MM_FROUND_NO_EXC); break; \
        case 233: result = func_name(__VA_ARGS__, 233, SIMDE_MM_FROUND_NO_EXC); break; \
        case 234: result = func_name(__VA_ARGS__, 234, SIMDE_MM_FROUND_NO_EXC); break; \
        case 235: result = func_name(__VA_ARGS__, 235, SIMDE_MM_FROUND_NO_EXC); break; \
        case 236: result = func_name(__VA_ARGS__, 236, SIMDE_MM_FROUND_NO_EXC); break; \
        case 237: result = func_name(__VA_ARGS__, 237, SIMDE_MM_FROUND_NO_EXC); break; \
        case 238: result = func_name(__VA_ARGS__, 238, SIMDE_MM_FROUND_NO_EXC); break; \
        case 239: result = func_name(__VA_ARGS__, 239, SIMDE_MM_FROUND_NO_EXC); break; \
        case 240: result = func_name(__VA_ARGS__, 240, SIMDE_MM_FROUND_NO_EXC); break; \
        case 241: result = func_name(__VA_ARGS__, 241, SIMDE_MM_FROUND_NO_EXC); break; \
        case 242: result = func_name(__VA_ARGS__, 242, SIMDE_MM_FROUND_NO_EXC); break; \
        case 243: result = func_name(__VA_ARGS__, 243, SIMDE_MM_FROUND_NO_EXC); break; \
        case 244: result = func_name(__VA_ARGS__, 244, SIMDE_MM_FROUND_NO_EXC); break; \
        case 245: result = func_name(__VA_ARGS__, 245, SIMDE_MM_FROUND_NO_EXC); break; \
        case 246: result = func_name(__VA_ARGS__, 246, SIMDE_MM_FROUND_NO_EXC); break; \
        case 247: result = func_name(__VA_ARGS__, 247, SIMDE_MM_FROUND_NO_EXC); break; \
        case 248: result = func_name(__VA_ARGS__, 248, SIMDE_MM_FROUND_NO_EXC); break; \
        case 249: result = func_name(__VA_ARGS__, 249, SIMDE_MM_FROUND_NO_EXC); break; \
        case 250: result = func_name(__VA_ARGS__, 250, SIMDE_MM_FROUND_NO_EXC); break; \
        case 251: result = func_name(__VA_ARGS__, 251, SIMDE_MM_FROUND_NO_EXC); break; \
        case 252: result = func_name(__VA_ARGS__, 252, SIMDE_MM_FROUND_NO_EXC); break; \
        case 253: result = func_name(__VA_ARGS__, 253, SIMDE_MM_FROUND_NO_EXC); break; \
        case 254: result = func_name(__VA_ARGS__, 254, SIMDE_MM_FROUND_NO_EXC); break; \
        case 255: result = func_name(__VA_ARGS__, 255, SIMDE_MM_FROUND_NO_EXC); break; \
        default: result = default_case; break; \
      } \
    } \
    else { \
      switch(imm) { \
        case   0: result = func_name(__VA_ARGS__,   0, SIMDE_MM_FROUND_CUR_DIRECTION); break; \
        case   1: result = func_name(__VA_ARGS__,   1, SIMDE_MM_FROUND_CUR_DIRECTION); break; \
        case   2: result = func_name(__VA_ARGS__,   2, SIMDE_MM_FROUND_CUR_DIRECTION); break; \
        case   3: result = func_name(__VA_ARGS__,   3, SIMDE_MM_FROUND_CUR_DIRECTION); break; \
        case   4: result = func_name(__VA_ARGS__,   4, SIMDE_MM_FROUND_CUR_DIRECTION); break; \
        case   5: result = func_name(__VA_ARGS__,   5, SIMDE_MM_FROUND_CUR_DIRECTION); break; \
        case   6: result = func_name(__VA_ARGS__,   6, SIMDE_MM_FROUND_CUR_DIRECTION); break; \
        case   7: result = func_name(__VA_ARGS__,   7, SIMDE_MM_FROUND_CUR_DIRECTION); break; \
        case   8: result = func_name(__VA_ARGS__,   8, SIMDE_MM_FROUND_CUR_DIRECTION); break; \
        case   9: result = func_name(__VA_ARGS__,   9, SIMDE_MM_FROUND_CUR_DIRECTION); break; \
        case  10: result = func_name(__VA_ARGS__,  10, SIMDE_MM_FROUND_CUR_DIRECTION); break; \
        case  11: result = func_name(__VA_ARGS__,  11, SIMDE_MM_FROUND_CUR_DIRECTION); break; \
        case  12: result = func_name(__VA_ARGS__,  12, SIMDE_MM_FROUND_CUR_DIRECTION); break; \
        case  13: result = func_name(__VA_ARGS__,  13, SIMDE_MM_FROUND_CUR_DIRECTION); break; \
        case  14: result = func_name(__VA_ARGS__,  14, SIMDE_MM_FROUND_CUR_DIRECTION); break; \
        case  15: result = func_name(__VA_ARGS__,  15, SIMDE_MM_FROUND_CUR_DIRECTION); break; \
        case  16: result = func_name(__VA_ARGS__,  16, SIMDE_MM_FROUND_CUR_DIRECTION); break; \
        case  17: result = func_name(__VA_ARGS__,  17, SIMDE_MM_FROUND_CUR_DIRECTION); break; \
        case  18: result = func_name(__VA_ARGS__,  18, SIMDE_MM_FROUND_CUR_DIRECTION); break; \
        case  19: result = func_name(__VA_ARGS__,  19, SIMDE_MM_FROUND_CUR_DIRECTION); break; \
        case  20: result = func_name(__VA_ARGS__,  20, SIMDE_MM_FROUND_CUR_DIRECTION); break; \
        case  21: result = func_name(__VA_ARGS__,  21, SIMDE_MM_FROUND_CUR_DIRECTION); break; \
        case  22: result = func_name(__VA_ARGS__,  22, SIMDE_MM_FROUND_CUR_DIRECTION); break; \
        case  23: result = func_name(__VA_ARGS__,  23, SIMDE_MM_FROUND_CUR_DIRECTION); break; \
        case  24: result = func_name(__VA_ARGS__,  24, SIMDE_MM_FROUND_CUR_DIRECTION); break; \
        case  25: result = func_name(__VA_ARGS__,  25, SIMDE_MM_FROUND_CUR_DIRECTION); break; \
        case  26: result = func_name(__VA_ARGS__,  26, SIMDE_MM_FROUND_CUR_DIRECTION); break; \
        case  27: result = func_name(__VA_ARGS__,  27, SIMDE_MM_FROUND_CUR_DIRECTION); break; \
        case  28: result = func_name(__VA_ARGS__,  28, SIMDE_MM_FROUND_CUR_DIRECTION); break; \
        case  29: result = func_name(__VA_ARGS__,  29, SIMDE_MM_FROUND_CUR_DIRECTION); break; \
        case  30: result = func_name(__VA_ARGS__,  30, SIMDE_MM_FROUND_CUR_DIRECTION); break; \
        case  31: result = func_name(__VA_ARGS__,  31, SIMDE_MM_FROUND_CUR_DIRECTION); break; \
        case  32: result = func_name(__VA_ARGS__,  32, SIMDE_MM_FROUND_CUR_DIRECTION); break; \
        case  33: result = func_name(__VA_ARGS__,  33, SIMDE_MM_FROUND_CUR_DIRECTION); break; \
        case  34: result = func_name(__VA_ARGS__,  34, SIMDE_MM_FROUND_CUR_DIRECTION); break; \
        case  35: result = func_name(__VA_ARGS__,  35, SIMDE_MM_FROUND_CUR_DIRECTION); break; \
        case  36: result = func_name(__VA_ARGS__,  36, SIMDE_MM_FROUND_CUR_DIRECTION); break; \
        case  37: result = func_name(__VA_ARGS__,  37, SIMDE_MM_FROUND_CUR_DIRECTION); break; \
        case  38: result = func_name(__VA_ARGS__,  38, SIMDE_MM_FROUND_CUR_DIRECTION); break; \
        case  39: result = func_name(__VA_ARGS__,  39, SIMDE_MM_FROUND_CUR_DIRECTION); break; \
        case  40: result = func_name(__VA_ARGS__,  40, SIMDE_MM_FROUND_CUR_DIRECTION); break; \
        case  41: result = func_name(__VA_ARGS__,  41, SIMDE_MM_FROUND_CUR_DIRECTION); break; \
        case  42: result = func_name(__VA_ARGS__,  42, SIMDE_MM_FROUND_CUR_DIRECTION); break; \
        case  43: result = func_name(__VA_ARGS__,  43, SIMDE_MM_FROUND_CUR_DIRECTION); break; \
        case  44: result = func_name(__VA_ARGS__,  44, SIMDE_MM_FROUND_CUR_DIRECTION); break; \
        case  45: result = func_name(__VA_ARGS__,  45, SIMDE_MM_FROUND_CUR_DIRECTION); break; \
        case  46: result = func_name(__VA_ARGS__,  46, SIMDE_MM_FROUND_CUR_DIRECTION); break; \
        case  47: result = func_name(__VA_ARGS__,  47, SIMDE_MM_FROUND_CUR_DIRECTION); break; \
        case  48: result = func_name(__VA_ARGS__,  48, SIMDE_MM_FROUND_CUR_DIRECTION); break; \
        case  49: result = func_name(__VA_ARGS__,  49, SIMDE_MM_FROUND_CUR_DIRECTION); break; \
        case  50: result = func_name(__VA_ARGS__,  50, SIMDE_MM_FROUND_CUR_DIRECTION); break; \
        case  51: result = func_name(__VA_ARGS__,  51, SIMDE_MM_FROUND_CUR_DIRECTION); break; \
        case  52: result = func_name(__VA_ARGS__,  52, SIMDE_MM_FROUND_CUR_DIRECTION); break; \
        case  53: result = func_name(__VA_ARGS__,  53, SIMDE_MM_FROUND_CUR_DIRECTION); break; \
        case  54: result = func_name(__VA_ARGS__,  54, SIMDE_MM_FROUND_CUR_DIRECTION); break; \
        case  55: result = func_name(__VA_ARGS__,  55, SIMDE_MM_FROUND_CUR_DIRECTION); break; \
        case  56: result = func_name(__VA_ARGS__,  56, SIMDE_MM_FROUND_CUR_DIRECTION); break; \
        case  57: result = func_name(__VA_ARGS__,  57, SIMDE_MM_FROUND_CUR_DIRECTION); break; \
        case  58: result = func_name(__VA_ARGS__,  58, SIMDE_MM_FROUND_CUR_DIRECTION); break; \
        case  59: result = func_name(__VA_ARGS__,  59, SIMDE_MM_FROUND_CUR_DIRECTION); break; \
        case  60: result = func_name(__VA_ARGS__,  60, SIMDE_MM_FROUND_CUR_DIRECTION); break; \
        case  61: result = func_name(__VA_ARGS__,  61, SIMDE_MM_FROUND_CUR_DIRECTION); break; \
        case  62: result = func_name(__VA_ARGS__,  62, SIMDE_MM_FROUND_CUR_DIRECTION); break; \
        case  63: result = func_name(__VA_ARGS__,  63, SIMDE_MM_FROUND_CUR_DIRECTION); break; \
        case  64: result = func_name(__VA_ARGS__,  64, SIMDE_MM_FROUND_CUR_DIRECTION); break; \
        case  65: result = func_name(__VA_ARGS__,  65, SIMDE_MM_FROUND_CUR_DIRECTION); break; \
        case  66: result = func_name(__VA_ARGS__,  66, SIMDE_MM_FROUND_CUR_DIRECTION); break; \
        case  67: result = func_name(__VA_ARGS__,  67, SIMDE_MM_FROUND_CUR_DIRECTION); break; \
        case  68: result = func_name(__VA_ARGS__,  68, SIMDE_MM_FROUND_CUR_DIRECTION); break; \
        case  69: result = func_name(__VA_ARGS__,  69, SIMDE_MM_FROUND_CUR_DIRECTION); break; \
        case  70: result = func_name(__VA_ARGS__,  70, SIMDE_MM_FROUND_CUR_DIRECTION); break; \
        case  71: result = func_name(__VA_ARGS__,  71, SIMDE_MM_FROUND_CUR_DIRECTION); break; \
        case  72: result = func_name(__VA_ARGS__,  72, SIMDE_MM_FROUND_CUR_DIRECTION); break; \
        case  73: result = func_name(__VA_ARGS__,  73, SIMDE_MM_FROUND_CUR_DIRECTION); break; \
        case  74: result = func_name(__VA_ARGS__,  74, SIMDE_MM_FROUND_CUR_DIRECTION); break; \
        case  75: result = func_name(__VA_ARGS__,  75, SIMDE_MM_FROUND_CUR_DIRECTION); break; \
        case  76: result = func_name(__VA_ARGS__,  76, SIMDE_MM_FROUND_CUR_DIRECTION); break; \
        case  77: result = func_name(__VA_ARGS__,  77, SIMDE_MM_FROUND_CUR_DIRECTION); break; \
        case  78: result = func_name(__VA_ARGS__,  78, SIMDE_MM_FROUND_CUR_DIRECTION); break; \
        case  79: result = func_name(__VA_ARGS__,  79, SIMDE_MM_FROUND_CUR_DIRECTION); break; \
        case  80: result = func_name(__VA_ARGS__,  80, SIMDE_MM_FROUND_CUR_DIRECTION); break; \
        case  81: result = func_name(__VA_ARGS__,  81, SIMDE_MM_FROUND_CUR_DIRECTION); break; \
        case  82: result = func_name(__VA_ARGS__,  82, SIMDE_MM_FROUND_CUR_DIRECTION); break; \
        case  83: result = func_name(__VA_ARGS__,  83, SIMDE_MM_FROUND_CUR_DIRECTION); break; \
        case  84: result = func_name(__VA_ARGS__,  84, SIMDE_MM_FROUND_CUR_DIRECTION); break; \
        case  85: result = func_name(__VA_ARGS__,  85, SIMDE_MM_FROUND_CUR_DIRECTION); break; \
        case  86: result = func_name(__VA_ARGS__,  86, SIMDE_MM_FROUND_CUR_DIRECTION); break; \
        case  87: result = func_name(__VA_ARGS__,  87, SIMDE_MM_FROUND_CUR_DIRECTION); break; \
        case  88: result = func_name(__VA_ARGS__,  88, SIMDE_MM_FROUND_CUR_DIRECTION); break; \
        case  89: result = func_name(__VA_ARGS__,  89, SIMDE_MM_FROUND_CUR_DIRECTION); break; \
        case  90: result = func_name(__VA_ARGS__,  90, SIMDE_MM_FROUND_CUR_DIRECTION); break; \
        case  91: result = func_name(__VA_ARGS__,  91, SIMDE_MM_FROUND_CUR_DIRECTION); break; \
        case  92: result = func_name(__VA_ARGS__,  92, SIMDE_MM_FROUND_CUR_DIRECTION); break; \
        case  93: result = func_name(__VA_ARGS__,  93, SIMDE_MM_FROUND_CUR_DIRECTION); break; \
        case  94: result = func_name(__VA_ARGS__,  94, SIMDE_MM_FROUND_CUR_DIRECTION); break; \
        case  95: result = func_name(__VA_ARGS__,  95, SIMDE_MM_FROUND_CUR_DIRECTION); break; \
        case  96: result = func_name(__VA_ARGS__,  96, SIMDE_MM_FROUND_CUR_DIRECTION); break; \
        case  97: result = func_name(__VA_ARGS__,  97, SIMDE_MM_FROUND_CUR_DIRECTION); break; \
        case  98: result = func_name(__VA_ARGS__,  98, SIMDE_MM_FROUND_CUR_DIRECTION); break; \
        case  99: result = func_name(__VA_ARGS__,  99, SIMDE_MM_FROUND_CUR_DIRECTION); break; \
        case 100: result = func_name(__VA_ARGS__, 100, SIMDE_MM_FROUND_CUR_DIRECTION); break; \
        case 101: result = func_name(__VA_ARGS__, 101, SIMDE_MM_FROUND_CUR_DIRECTION); break; \
        case 102: result = func_name(__VA_ARGS__, 102, SIMDE_MM_FROUND_CUR_DIRECTION); break; \
        case 103: result = func_name(__VA_ARGS__, 103, SIMDE_MM_FROUND_CUR_DIRECTION); break; \
        case 104: result = func_name(__VA_ARGS__, 104, SIMDE_MM_FROUND_CUR_DIRECTION); break; \
        case 105: result = func_name(__VA_ARGS__, 105, SIMDE_MM_FROUND_CUR_DIRECTION); break; \
        case 106: result = func_name(__VA_ARGS__, 106, SIMDE_MM_FROUND_CUR_DIRECTION); break; \
        case 107: result = func_name(__VA_ARGS__, 107, SIMDE_MM_FROUND_CUR_DIRECTION); break; \
        case 108: result = func_name(__VA_ARGS__, 108, SIMDE_MM_FROUND_CUR_DIRECTION); break; \
        case 109: result = func_name(__VA_ARGS__, 109, SIMDE_MM_FROUND_CUR_DIRECTION); break; \
        case 110: result = func_name(__VA_ARGS__, 110, SIMDE_MM_FROUND_CUR_DIRECTION); break; \
        case 111: result = func_name(__VA_ARGS__, 111, SIMDE_MM_FROUND_CUR_DIRECTION); break; \
        case 112: result = func_name(__VA_ARGS__, 112, SIMDE_MM_FROUND_CUR_DIRECTION); break; \
        case 113: result = func_name(__VA_ARGS__, 113, SIMDE_MM_FROUND_CUR_DIRECTION); break; \
        case 114: result = func_name(__VA_ARGS__, 114, SIMDE_MM_FROUND_CUR_DIRECTION); break; \
        case 115: result = func_name(__VA_ARGS__, 115, SIMDE_MM_FROUND_CUR_DIRECTION); break; \
        case 116: result = func_name(__VA_ARGS__, 116, SIMDE_MM_FROUND_CUR_DIRECTION); break; \
        case 117: result = func_name(__VA_ARGS__, 117, SIMDE_MM_FROUND_CUR_DIRECTION); break; \
        case 118: result = func_name(__VA_ARGS__, 118, SIMDE_MM_FROUND_CUR_DIRECTION); break; \
        case 119: result = func_name(__VA_ARGS__, 119, SIMDE_MM_FROUND_CUR_DIRECTION); break; \
        case 120: result = func_name(__VA_ARGS__, 120, SIMDE_MM_FROUND_CUR_DIRECTION); break; \
        case 121: result = func_name(__VA_ARGS__, 121, SIMDE_MM_FROUND_CUR_DIRECTION); break; \
        case 122: result = func_name(__VA_ARGS__, 122, SIMDE_MM_FROUND_CUR_DIRECTION); break; \
        case 123: result = func_name(__VA_ARGS__, 123, SIMDE_MM_FROUND_CUR_DIRECTION); break; \
        case 124: result = func_name(__VA_ARGS__, 124, SIMDE_MM_FROUND_CUR_DIRECTION); break; \
        case 125: result = func_name(__VA_ARGS__, 125, SIMDE_MM_FROUND_CUR_DIRECTION); break; \
        case 126: result = func_name(__VA_ARGS__, 126, SIMDE_MM_FROUND_CUR_DIRECTION); break; \
        case 127: result = func_name(__VA_ARGS__, 127, SIMDE_MM_FROUND_CUR_DIRECTION); break; \
        case 128: result = func_name(__VA_ARGS__, 128, SIMDE_MM_FROUND_CUR_DIRECTION); break; \
        case 129: result = func_name(__VA_ARGS__, 129, SIMDE_MM_FROUND_CUR_DIRECTION); break; \
        case 130: result = func_name(__VA_ARGS__, 130, SIMDE_MM_FROUND_CUR_DIRECTION); break; \
        case 131: result = func_name(__VA_ARGS__, 131, SIMDE_MM_FROUND_CUR_DIRECTION); break; \
        case 132: result = func_name(__VA_ARGS__, 132, SIMDE_MM_FROUND_CUR_DIRECTION); break; \
        case 133: result = func_name(__VA_ARGS__, 133, SIMDE_MM_FROUND_CUR_DIRECTION); break; \
        case 134: result = func_name(__VA_ARGS__, 134, SIMDE_MM_FROUND_CUR_DIRECTION); break; \
        case 135: result = func_name(__VA_ARGS__, 135, SIMDE_MM_FROUND_CUR_DIRECTION); break; \
        case 136: result = func_name(__VA_ARGS__, 136, SIMDE_MM_FROUND_CUR_DIRECTION); break; \
        case 137: result = func_name(__VA_ARGS__, 137, SIMDE_MM_FROUND_CUR_DIRECTION); break; \
        case 138: result = func_name(__VA_ARGS__, 138, SIMDE_MM_FROUND_CUR_DIRECTION); break; \
        case 139: result = func_name(__VA_ARGS__, 139, SIMDE_MM_FROUND_CUR_DIRECTION); break; \
        case 140: result = func_name(__VA_ARGS__, 140, SIMDE_MM_FROUND_CUR_DIRECTION); break; \
        case 141: result = func_name(__VA_ARGS__, 141, SIMDE_MM_FROUND_CUR_DIRECTION); break; \
        case 142: result = func_name(__VA_ARGS__, 142, SIMDE_MM_FROUND_CUR_DIRECTION); break; \
        case 143: result = func_name(__VA_ARGS__, 143, SIMDE_MM_FROUND_CUR_DIRECTION); break; \
        case 144: result = func_name(__VA_ARGS__, 144, SIMDE_MM_FROUND_CUR_DIRECTION); break; \
        case 145: result = func_name(__VA_ARGS__, 145, SIMDE_MM_FROUND_CUR_DIRECTION); break; \
        case 146: result = func_name(__VA_ARGS__, 146, SIMDE_MM_FROUND_CUR_DIRECTION); break; \
        case 147: result = func_name(__VA_ARGS__, 147, SIMDE_MM_FROUND_CUR_DIRECTION); break; \
        case 148: result = func_name(__VA_ARGS__, 148, SIMDE_MM_FROUND_CUR_DIRECTION); break; \
        case 149: result = func_name(__VA_ARGS__, 149, SIMDE_MM_FROUND_CUR_DIRECTION); break; \
        case 150: result = func_name(__VA_ARGS__, 150, SIMDE_MM_FROUND_CUR_DIRECTION); break; \
        case 151: result = func_name(__VA_ARGS__, 151, SIMDE_MM_FROUND_CUR_DIRECTION); break; \
        case 152: result = func_name(__VA_ARGS__, 152, SIMDE_MM_FROUND_CUR_DIRECTION); break; \
        case 153: result = func_name(__VA_ARGS__, 153, SIMDE_MM_FROUND_CUR_DIRECTION); break; \
        case 154: result = func_name(__VA_ARGS__, 154, SIMDE_MM_FROUND_CUR_DIRECTION); break; \
        case 155: result = func_name(__VA_ARGS__, 155, SIMDE_MM_FROUND_CUR_DIRECTION); break; \
        case 156: result = func_name(__VA_ARGS__, 156, SIMDE_MM_FROUND_CUR_DIRECTION); break; \
        case 157: result = func_name(__VA_ARGS__, 157, SIMDE_MM_FROUND_CUR_DIRECTION); break; \
        case 158: result = func_name(__VA_ARGS__, 158, SIMDE_MM_FROUND_CUR_DIRECTION); break; \
        case 159: result = func_name(__VA_ARGS__, 159, SIMDE_MM_FROUND_CUR_DIRECTION); break; \
        case 160: result = func_name(__VA_ARGS__, 160, SIMDE_MM_FROUND_CUR_DIRECTION); break; \
        case 161: result = func_name(__VA_ARGS__, 161, SIMDE_MM_FROUND_CUR_DIRECTION); break; \
        case 162: result = func_name(__VA_ARGS__, 162, SIMDE_MM_FROUND_CUR_DIRECTION); break; \
        case 163: result = func_name(__VA_ARGS__, 163, SIMDE_MM_FROUND_CUR_DIRECTION); break; \
        case 164: result = func_name(__VA_ARGS__, 164, SIMDE_MM_FROUND_CUR_DIRECTION); break; \
        case 165: result = func_name(__VA_ARGS__, 165, SIMDE_MM_FROUND_CUR_DIRECTION); break; \
        case 166: result = func_name(__VA_ARGS__, 166, SIMDE_MM_FROUND_CUR_DIRECTION); break; \
        case 167: result = func_name(__VA_ARGS__, 167, SIMDE_MM_FROUND_CUR_DIRECTION); break; \
        case 168: result = func_name(__VA_ARGS__, 168, SIMDE_MM_FROUND_CUR_DIRECTION); break; \
        case 169: result = func_name(__VA_ARGS__, 169, SIMDE_MM_FROUND_CUR_DIRECTION); break; \
        case 170: result = func_name(__VA_ARGS__, 170, SIMDE_MM_FROUND_CUR_DIRECTION); break; \
        case 171: result = func_name(__VA_ARGS__, 171, SIMDE_MM_FROUND_CUR_DIRECTION); break; \
        case 172: result = func_name(__VA_ARGS__, 172, SIMDE_MM_FROUND_CUR_DIRECTION); break; \
        case 173: result = func_name(__VA_ARGS__, 173, SIMDE_MM_FROUND_CUR_DIRECTION); break; \
        case 174: result = func_name(__VA_ARGS__, 174, SIMDE_MM_FROUND_CUR_DIRECTION); break; \
        case 175: result = func_name(__VA_ARGS__, 175, SIMDE_MM_FROUND_CUR_DIRECTION); break; \
        case 176: result = func_name(__VA_ARGS__, 176, SIMDE_MM_FROUND_CUR_DIRECTION); break; \
        case 177: result = func_name(__VA_ARGS__, 177, SIMDE_MM_FROUND_CUR_DIRECTION); break; \
        case 178: result = func_name(__VA_ARGS__, 178, SIMDE_MM_FROUND_CUR_DIRECTION); break; \
        case 179: result = func_name(__VA_ARGS__, 179, SIMDE_MM_FROUND_CUR_DIRECTION); break; \
        case 180: result = func_name(__VA_ARGS__, 180, SIMDE_MM_FROUND_CUR_DIRECTION); break; \
        case 181: result = func_name(__VA_ARGS__, 181, SIMDE_MM_FROUND_CUR_DIRECTION); break; \
        case 182: result = func_name(__VA_ARGS__, 182, SIMDE_MM_FROUND_CUR_DIRECTION); break; \
        case 183: result = func_name(__VA_ARGS__, 183, SIMDE_MM_FROUND_CUR_DIRECTION); break; \
        case 184: result = func_name(__VA_ARGS__, 184, SIMDE_MM_FROUND_CUR_DIRECTION); break; \
        case 185: result = func_name(__VA_ARGS__, 185, SIMDE_MM_FROUND_CUR_DIRECTION); break; \
        case 186: result = func_name(__VA_ARGS__, 186, SIMDE_MM_FROUND_CUR_DIRECTION); break; \
        case 187: result = func_name(__VA_ARGS__, 187, SIMDE_MM_FROUND_CUR_DIRECTION); break; \
        case 188: result = func_name(__VA_ARGS__, 188, SIMDE_MM_FROUND_CUR_DIRECTION); break; \
        case 189: result = func_name(__VA_ARGS__, 189, SIMDE_MM_FROUND_CUR_DIRECTION); break; \
        case 190: result = func_name(__VA_ARGS__, 190, SIMDE_MM_FROUND_CUR_DIRECTION); break; \
        case 191: result = func_name(__VA_ARGS__, 191, SIMDE_MM_FROUND_CUR_DIRECTION); break; \
        case 192: result = func_name(__VA_ARGS__, 192, SIMDE_MM_FROUND_CUR_DIRECTION); break; \
        case 193: result = func_name(__VA_ARGS__, 193, SIMDE_MM_FROUND_CUR_DIRECTION); break; \
        case 194: result = func_name(__VA_ARGS__, 194, SIMDE_MM_FROUND_CUR_DIRECTION); break; \
        case 195: result = func_name(__VA_ARGS__, 195, SIMDE_MM_FROUND_CUR_DIRECTION); break; \
        case 196: result = func_name(__VA_ARGS__, 196, SIMDE_MM_FROUND_CUR_DIRECTION); break; \
        case 197: result = func_name(__VA_ARGS__, 197, SIMDE_MM_FROUND_CUR_DIRECTION); break; \
        case 198: result = func_name(__VA_ARGS__, 198, SIMDE_MM_FROUND_CUR_DIRECTION); break; \
        case 199: result = func_name(__VA_ARGS__, 199, SIMDE_MM_FROUND_CUR_DIRECTION); break; \
        case 200: result = func_name(__VA_ARGS__, 200, SIMDE_MM_FROUND_CUR_DIRECTION); break; \
        case 201: result = func_name(__VA_ARGS__, 201, SIMDE_MM_FROUND_CUR_DIRECTION); break; \
        case 202: result = func_name(__VA_ARGS__, 202, SIMDE_MM_FROUND_CUR_DIRECTION); break; \
        case 203: result = func_name(__VA_ARGS__, 203, SIMDE_MM_FROUND_CUR_DIRECTION); break; \
        case 204: result = func_name(__VA_ARGS__, 204, SIMDE_MM_FROUND_CUR_DIRECTION); break; \
        case 205: result = func_name(__VA_ARGS__, 205, SIMDE_MM_FROUND_CUR_DIRECTION); break; \
        case 206: result = func_name(__VA_ARGS__, 206, SIMDE_MM_FROUND_CUR_DIRECTION); break; \
        case 207: result = func_name(__VA_ARGS__, 207, SIMDE_MM_FROUND_CUR_DIRECTION); break; \
        case 208: result = func_name(__VA_ARGS__, 208, SIMDE_MM_FROUND_CUR_DIRECTION); break; \
        case 209: result = func_name(__VA_ARGS__, 209, SIMDE_MM_FROUND_CUR_DIRECTION); break; \
        case 210: result = func_name(__VA_ARGS__, 210, SIMDE_MM_FROUND_CUR_DIRECTION); break; \
        case 211: result = func_name(__VA_ARGS__, 211, SIMDE_MM_FROUND_CUR_DIRECTION); break; \
        case 212: result = func_name(__VA_ARGS__, 212, SIMDE_MM_FROUND_CUR_DIRECTION); break; \
        case 213: result = func_name(__VA_ARGS__, 213, SIMDE_MM_FROUND_CUR_DIRECTION); break; \
        case 214: result = func_name(__VA_ARGS__, 214, SIMDE_MM_FROUND_CUR_DIRECTION); break; \
        case 215: result = func_name(__VA_ARGS__, 215, SIMDE_MM_FROUND_CUR_DIRECTION); break; \
        case 216: result = func_name(__VA_ARGS__, 216, SIMDE_MM_FROUND_CUR_DIRECTION); break; \
        case 217: result = func_name(__VA_ARGS__, 217, SIMDE_MM_FROUND_CUR_DIRECTION); break; \
        case 218: result = func_name(__VA_ARGS__, 218, SIMDE_MM_FROUND_CUR_DIRECTION); break; \
        case 219: result = func_name(__VA_ARGS__, 219, SIMDE_MM_FROUND_CUR_DIRECTION); break; \
        case 220: result = func_name(__VA_ARGS__, 220, SIMDE_MM_FROUND_CUR_DIRECTION); break; \
        case 221: result = func_name(__VA_ARGS__, 221, SIMDE_MM_FROUND_CUR_DIRECTION); break; \
        case 222: result = func_name(__VA_ARGS__, 222, SIMDE_MM_FROUND_CUR_DIRECTION); break; \
        case 223: result = func_name(__VA_ARGS__, 223, SIMDE_MM_FROUND_CUR_DIRECTION); break; \
        case 224: result = func_name(__VA_ARGS__, 224, SIMDE_MM_FROUND_CUR_DIRECTION); break; \
        case 225: result = func_name(__VA_ARGS__, 225, SIMDE_MM_FROUND_CUR_DIRECTION); break; \
        case 226: result = func_name(__VA_ARGS__, 226, SIMDE_MM_FROUND_CUR_DIRECTION); break; \
        case 227: result = func_name(__VA_ARGS__, 227, SIMDE_MM_FROUND_CUR_DIRECTION); break; \
        case 228: result = func_name(__VA_ARGS__, 228, SIMDE_MM_FROUND_CUR_DIRECTION); break; \
        case 229: result = func_name(__VA_ARGS__, 229, SIMDE_MM_FROUND_CUR_DIRECTION); break; \
        case 230: result = func_name(__VA_ARGS__, 230, SIMDE_MM_FROUND_CUR_DIRECTION); break; \
        case 231: result = func_name(__VA_ARGS__, 231, SIMDE_MM_FROUND_CUR_DIRECTION); break; \
        case 232: result = func_name(__VA_ARGS__, 232, SIMDE_MM_FROUND_CUR_DIRECTION); break; \
        case 233: result = func_name(__VA_ARGS__, 233, SIMDE_MM_FROUND_CUR_DIRECTION); break; \
        case 234: result = func_name(__VA_ARGS__, 234, SIMDE_MM_FROUND_CUR_DIRECTION); break; \
        case 235: result = func_name(__VA_ARGS__, 235, SIMDE_MM_FROUND_CUR_DIRECTION); break; \
        case 236: result = func_name(__VA_ARGS__, 236, SIMDE_MM_FROUND_CUR_DIRECTION); break; \
        case 237: result = func_name(__VA_ARGS__, 237, SIMDE_MM_FROUND_CUR_DIRECTION); break; \
        case 238: result = func_name(__VA_ARGS__, 238, SIMDE_MM_FROUND_CUR_DIRECTION); break; \
        case 239: result = func_name(__VA_ARGS__, 239, SIMDE_MM_FROUND_CUR_DIRECTION); break; \
        case 240: result = func_name(__VA_ARGS__, 240, SIMDE_MM_FROUND_CUR_DIRECTION); break; \
        case 241: result = func_name(__VA_ARGS__, 241, SIMDE_MM_FROUND_CUR_DIRECTION); break; \
        case 242: result = func_name(__VA_ARGS__, 242, SIMDE_MM_FROUND_CUR_DIRECTION); break; \
        case 243: result = func_name(__VA_ARGS__, 243, SIMDE_MM_FROUND_CUR_DIRECTION); break; \
        case 244: result = func_name(__VA_ARGS__, 244, SIMDE_MM_FROUND_CUR_DIRECTION); break; \
        case 245: result = func_name(__VA_ARGS__, 245, SIMDE_MM_FROUND_CUR_DIRECTION); break; \
        case 246: result = func_name(__VA_ARGS__, 246, SIMDE_MM_FROUND_CUR_DIRECTION); break; \
        case 247: result = func_name(__VA_ARGS__, 247, SIMDE_MM_FROUND_CUR_DIRECTION); break; \
        case 248: result = func_name(__VA_ARGS__, 248, SIMDE_MM_FROUND_CUR_DIRECTION); break; \
        case 249: result = func_name(__VA_ARGS__, 249, SIMDE_MM_FROUND_CUR_DIRECTION); break; \
        case 250: result = func_name(__VA_ARGS__, 250, SIMDE_MM_FROUND_CUR_DIRECTION); break; \
        case 251: result = func_name(__VA_ARGS__, 251, SIMDE_MM_FROUND_CUR_DIRECTION); break; \
        case 252: result = func_name(__VA_ARGS__, 252, SIMDE_MM_FROUND_CUR_DIRECTION); break; \
        case 253: result = func_name(__VA_ARGS__, 253, SIMDE_MM_FROUND_CUR_DIRECTION); break; \
        case 254: result = func_name(__VA_ARGS__, 254, SIMDE_MM_FROUND_CUR_DIRECTION); break; \
        case 255: result = func_name(__VA_ARGS__, 255, SIMDE_MM_FROUND_CUR_DIRECTION); break; \
        default: result = default_case; break; \
      } \
    } \
  } while (0)

#define SIMDE_CONSTIFY_2_NO_RESULT_(func_name, default_case, imm, ...) \
  do { \
    switch(imm) { \
      case 0: func_name(__VA_ARGS__, 0); break; \
      case 1: func_name(__VA_ARGS__, 1); break; \
      default: default_case; break; \
    } \
  } while (0)

#define SIMDE_CONSTIFY_4_NO_RESULT_(func_name, default_case, imm, ...) \
  do { \
    switch(imm) { \
      case 0: func_name(__VA_ARGS__, 0); break; \
      case 1: func_name(__VA_ARGS__, 1); break; \
      case 2: func_name(__VA_ARGS__, 2); break; \
      case 3: func_name(__VA_ARGS__, 3); break; \
      default: default_case; break; \
    } \
  } while (0)

#define SIMDE_CONSTIFY_8_NO_RESULT_(func_name, default_case, imm, ...) \
  do { \
    switch(imm) { \
      case 0: func_name(__VA_ARGS__, 0); break; \
      case 1: func_name(__VA_ARGS__, 1); break; \
      case 2: func_name(__VA_ARGS__, 2); break; \
      case 3: func_name(__VA_ARGS__, 3); break; \
      case 4: func_name(__VA_ARGS__, 4); break; \
      case 5: func_name(__VA_ARGS__, 5); break; \
      case 6: func_name(__VA_ARGS__, 6); break; \
      case 7: func_name(__VA_ARGS__, 7); break; \
      default: default_case; break; \
    } \
  } while (0)

#define SIMDE_CONSTIFY_16_NO_RESULT_(func_name, default_case, imm, ...) \
  do { \
    switch(imm) { \
      case  0: func_name(__VA_ARGS__,  0); break; \
      case  1: func_name(__VA_ARGS__,  1); break; \
      case  2: func_name(__VA_ARGS__,  2); break; \
      case  3: func_name(__VA_ARGS__,  3); break; \
      case  4: func_name(__VA_ARGS__,  4); break; \
      case  5: func_name(__VA_ARGS__,  5); break; \
      case  6: func_name(__VA_ARGS__,  6); break; \
      case  7: func_name(__VA_ARGS__,  7); break; \
      case  8: func_name(__VA_ARGS__,  8); break; \
      case  9: func_name(__VA_ARGS__,  9); break; \
      case 10: func_name(__VA_ARGS__, 10); break; \
      case 11: func_name(__VA_ARGS__, 11); break; \
      case 12: func_name(__VA_ARGS__, 12); break; \
      case 13: func_name(__VA_ARGS__, 13); break; \
      case 14: func_name(__VA_ARGS__, 14); break; \
      case 15: func_name(__VA_ARGS__, 15); break; \
      default: default_case; break; \
    } \
  } while (0)

#define SIMDE_CONSTIFY_32_NO_RESULT_(func_name, default_case, imm, ...) \
  do { \
    switch(imm) { \
      case  0: func_name(__VA_ARGS__,  0); break; \
      case  1: func_name(__VA_ARGS__,  1); break; \
      case  2: func_name(__VA_ARGS__,  2); break; \
      case  3: func_name(__VA_ARGS__,  3); break; \
      case  4: func_name(__VA_ARGS__,  4); break; \
      case  5: func_name(__VA_ARGS__,  5); break; \
      case  6: func_name(__VA_ARGS__,  6); break; \
      case  7: func_name(__VA_ARGS__,  7); break; \
      case  8: func_name(__VA_ARGS__,  8); break; \
      case  9: func_name(__VA_ARGS__,  9); break; \
      case 10: func_name(__VA_ARGS__, 10); break; \
      case 11: func_name(__VA_ARGS__, 11); break; \
      case 12: func_name(__VA_ARGS__, 12); break; \
      case 13: func_name(__VA_ARGS__, 13); break; \
      case 14: func_name(__VA_ARGS__, 14); break; \
      case 15: func_name(__VA_ARGS__, 15); break; \
      case 16: func_name(__VA_ARGS__, 16); break; \
      case 17: func_name(__VA_ARGS__, 17); break; \
      case 18: func_name(__VA_ARGS__, 18); break; \
      case 19: func_name(__VA_ARGS__, 19); break; \
      case 20: func_name(__VA_ARGS__, 20); break; \
      case 21: func_name(__VA_ARGS__, 21); break; \
      case 22: func_name(__VA_ARGS__, 22); break; \
      case 23: func_name(__VA_ARGS__, 23); break; \
      case 24: func_name(__VA_ARGS__, 24); break; \
      case 25: func_name(__VA_ARGS__, 25); break; \
      case 26: func_name(__VA_ARGS__, 26); break; \
      case 27: func_name(__VA_ARGS__, 27); break; \
      case 28: func_name(__VA_ARGS__, 28); break; \
      case 29: func_name(__VA_ARGS__, 29); break; \
      case 30: func_name(__VA_ARGS__, 30); break; \
      case 31: func_name(__VA_ARGS__, 31); break; \
      default: default_case; break; \
    } \
  } while (0)

#define SIMDE_CONSTIFY_64_NO_RESULT_(func_name, default_case, imm, ...) \
  do { \
    switch(imm) { \
      case  0: func_name(__VA_ARGS__,  0); break; \
      case  1: func_name(__VA_ARGS__,  1); break; \
      case  2: func_name(__VA_ARGS__,  2); break; \
      case  3: func_name(__VA_ARGS__,  3); break; \
      case  4: func_name(__VA_ARGS__,  4); break; \
      case  5: func_name(__VA_ARGS__,  5); break; \
      case  6: func_name(__VA_ARGS__,  6); break; \
      case  7: func_name(__VA_ARGS__,  7); break; \
      case  8: func_name(__VA_ARGS__,  8); break; \
      case  9: func_name(__VA_ARGS__,  9); break; \
      case 10: func_name(__VA_ARGS__, 10); break; \
      case 11: func_name(__VA_ARGS__, 11); break; \
      case 12: func_name(__VA_ARGS__, 12); break; \
      case 13: func_name(__VA_ARGS__, 13); break; \
      case 14: func_name(__VA_ARGS__, 14); break; \
      case 15: func_name(__VA_ARGS__, 15); break; \
      case 16: func_name(__VA_ARGS__, 16); break; \
      case 17: func_name(__VA_ARGS__, 17); break; \
      case 18: func_name(__VA_ARGS__, 18); break; \
      case 19: func_name(__VA_ARGS__, 19); break; \
      case 20: func_name(__VA_ARGS__, 20); break; \
      case 21: func_name(__VA_ARGS__, 21); break; \
      case 22: func_name(__VA_ARGS__, 22); break; \
      case 23: func_name(__VA_ARGS__, 23); break; \
      case 24: func_name(__VA_ARGS__, 24); break; \
      case 25: func_name(__VA_ARGS__, 25); break; \
      case 26: func_name(__VA_ARGS__, 26); break; \
      case 27: func_name(__VA_ARGS__, 27); break; \
      case 28: func_name(__VA_ARGS__, 28); break; \
      case 29: func_name(__VA_ARGS__, 29); break; \
      case 30: func_name(__VA_ARGS__, 30); break; \
      case 31: func_name(__VA_ARGS__, 31); break; \
      case 32: func_name(__VA_ARGS__, 32); break; \
      case 33: func_name(__VA_ARGS__, 33); break; \
      case 34: func_name(__VA_ARGS__, 34); break; \
      case 35: func_name(__VA_ARGS__, 35); break; \
      case 36: func_name(__VA_ARGS__, 36); break; \
      case 37: func_name(__VA_ARGS__, 37); break; \
      case 38: func_name(__VA_ARGS__, 38); break; \
      case 39: func_name(__VA_ARGS__, 39); break; \
      case 40: func_name(__VA_ARGS__, 40); break; \
      case 41: func_name(__VA_ARGS__, 41); break; \
      case 42: func_name(__VA_ARGS__, 42); break; \
      case 43: func_name(__VA_ARGS__, 43); break; \
      case 44: func_name(__VA_ARGS__, 44); break; \
      case 45: func_name(__VA_ARGS__, 45); break; \
      case 46: func_name(__VA_ARGS__, 46); break; \
      case 47: func_name(__VA_ARGS__, 47); break; \
      case 48: func_name(__VA_ARGS__, 48); break; \
      case 49: func_name(__VA_ARGS__, 49); break; \
      case 50: func_name(__VA_ARGS__, 50); break; \
      case 51: func_name(__VA_ARGS__, 51); break; \
      case 52: func_name(__VA_ARGS__, 52); break; \
      case 53: func_name(__VA_ARGS__, 53); break; \
      case 54: func_name(__VA_ARGS__, 54); break; \
      case 55: func_name(__VA_ARGS__, 55); break; \
      case 56: func_name(__VA_ARGS__, 56); break; \
      case 57: func_name(__VA_ARGS__, 57); break; \
      case 58: func_name(__VA_ARGS__, 58); break; \
      case 59: func_name(__VA_ARGS__, 59); break; \
      case 60: func_name(__VA_ARGS__, 60); break; \
      case 61: func_name(__VA_ARGS__, 61); break; \
      case 62: func_name(__VA_ARGS__, 62); break; \
      case 63: func_name(__VA_ARGS__, 63); break; \
      default: default_case; break; \
    } \
  } while (0)

HEDLEY_DIAGNOSTIC_POP

#endif
