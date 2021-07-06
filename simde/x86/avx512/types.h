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
 *  2020      Evan Nemerson <evan@nemerson.com>
 */

#if !defined(SIMDE_X86_AVX512_TYPES_H)
#define SIMDE_X86_AVX512_TYPES_H

#include "../avx.h"

HEDLEY_DIAGNOSTIC_PUSH
SIMDE_DISABLE_UNWANTED_DIAGNOSTICS
SIMDE_BEGIN_DECLS_

/* The problem is that Microsoft doesn't support 64-byte aligned parameters, except for
 * __m512/__m512i/__m512d.  Since our private union has an __m512 member it will be 64-byte
 * aligned even if we reduce the alignment requirements of other members.
 *
 * Even if we're on x86 and use the native AVX-512 types for arguments/return values, the
 * to/from private functions will break, and I'm not willing to change their APIs to use
 * pointers (which would also require more verbose code on the caller side) just to make
 * MSVC happy.
 *
 * If you want to use AVX-512 in SIMDe, you'll need to either upgrade to MSVC 2017 or later,
 * or upgrade to a different compiler (clang-cl, perhaps?).  If you have an idea of how to
 * fix this without requiring API changes (except transparently through macros), patches
 * are welcome.
 */

#  if defined(HEDLEY_MSVC_VERSION) && !HEDLEY_MSVC_VERSION_CHECK(19,10,0)
#    if defined(SIMDE_X86_AVX512F_NATIVE)
#      undef SIMDE_X86_AVX512F_NATIVE
#      pragma message("Native AVX-512 support requires MSVC 2017 or later.  See comment above (in code) for details.")
#    endif
#    define SIMDE_AVX512_ALIGN SIMDE_ALIGN_TO_32
#  else
#    define SIMDE_AVX512_ALIGN SIMDE_ALIGN_TO_64
#  endif

typedef union {
  #if defined(SIMDE_VECTOR_SUBSCRIPT)
    SIMDE_AVX512_ALIGN int8_t          i8 SIMDE_VECTOR(64) SIMDE_MAY_ALIAS;
    SIMDE_AVX512_ALIGN int16_t        i16 SIMDE_VECTOR(64) SIMDE_MAY_ALIAS;
    SIMDE_AVX512_ALIGN int32_t        i32 SIMDE_VECTOR(64) SIMDE_MAY_ALIAS;
    SIMDE_AVX512_ALIGN int64_t        i64 SIMDE_VECTOR(64) SIMDE_MAY_ALIAS;
    SIMDE_AVX512_ALIGN uint8_t         u8 SIMDE_VECTOR(64) SIMDE_MAY_ALIAS;
    SIMDE_AVX512_ALIGN uint16_t       u16 SIMDE_VECTOR(64) SIMDE_MAY_ALIAS;
    SIMDE_AVX512_ALIGN uint32_t       u32 SIMDE_VECTOR(64) SIMDE_MAY_ALIAS;
    SIMDE_AVX512_ALIGN uint64_t       u64 SIMDE_VECTOR(64) SIMDE_MAY_ALIAS;
    #if defined(SIMDE_HAVE_INT128_)
    SIMDE_AVX512_ALIGN simde_int128  i128 SIMDE_VECTOR(64) SIMDE_MAY_ALIAS;
    SIMDE_AVX512_ALIGN simde_uint128 u128 SIMDE_VECTOR(64) SIMDE_MAY_ALIAS;
    #endif
    SIMDE_AVX512_ALIGN simde_float32  f32 SIMDE_VECTOR(64) SIMDE_MAY_ALIAS;
    SIMDE_AVX512_ALIGN simde_float64  f64 SIMDE_VECTOR(64) SIMDE_MAY_ALIAS;
    SIMDE_AVX512_ALIGN int_fast32_t  i32f SIMDE_VECTOR(64) SIMDE_MAY_ALIAS;
    SIMDE_AVX512_ALIGN uint_fast32_t u32f SIMDE_VECTOR(64) SIMDE_MAY_ALIAS;
  #else
    SIMDE_AVX512_ALIGN int8_t          i8[64];
    SIMDE_AVX512_ALIGN int16_t        i16[32];
    SIMDE_AVX512_ALIGN int32_t        i32[16];
    SIMDE_AVX512_ALIGN int64_t        i64[8];
    SIMDE_AVX512_ALIGN uint8_t         u8[64];
    SIMDE_AVX512_ALIGN uint16_t       u16[32];
    SIMDE_AVX512_ALIGN uint32_t       u32[16];
    SIMDE_AVX512_ALIGN uint64_t       u64[8];
    SIMDE_AVX512_ALIGN int_fast32_t  i32f[64 / sizeof(int_fast32_t)];
    SIMDE_AVX512_ALIGN uint_fast32_t u32f[64 / sizeof(uint_fast32_t)];
    #if defined(SIMDE_HAVE_INT128_)
    SIMDE_AVX512_ALIGN simde_int128  i128[4];
    SIMDE_AVX512_ALIGN simde_uint128 u128[4];
    #endif
    SIMDE_AVX512_ALIGN simde_float32  f32[16];
    SIMDE_AVX512_ALIGN simde_float64  f64[8];
  #endif

    SIMDE_AVX512_ALIGN simde__m128_private m128_private[4];
    SIMDE_AVX512_ALIGN simde__m128         m128[4];
    SIMDE_AVX512_ALIGN simde__m256_private m256_private[2];
    SIMDE_AVX512_ALIGN simde__m256         m256[2];

  #if defined(SIMDE_X86_AVX512F_NATIVE)
    SIMDE_AVX512_ALIGN __m512         n;
  #elif defined(SIMDE_POWER_ALTIVEC_P6_NATIVE)
    SIMDE_ALIGN_TO_16 SIMDE_POWER_ALTIVEC_VECTOR(unsigned char)      altivec_u8[4];
    SIMDE_ALIGN_TO_16 SIMDE_POWER_ALTIVEC_VECTOR(unsigned short)     altivec_u16[4];
    SIMDE_ALIGN_TO_16 SIMDE_POWER_ALTIVEC_VECTOR(unsigned int)       altivec_u32[4];
    SIMDE_ALIGN_TO_16 SIMDE_POWER_ALTIVEC_VECTOR(signed char)        altivec_i8[4];
    SIMDE_ALIGN_TO_16 SIMDE_POWER_ALTIVEC_VECTOR(signed short)       altivec_i16[4];
    SIMDE_ALIGN_TO_16 SIMDE_POWER_ALTIVEC_VECTOR(signed int)         altivec_i32[4];
    SIMDE_ALIGN_TO_16 SIMDE_POWER_ALTIVEC_VECTOR(float)              altivec_f32[4];
    #if defined(SIMDE_POWER_ALTIVEC_P7_NATIVE)
      SIMDE_ALIGN_TO_16 SIMDE_POWER_ALTIVEC_VECTOR(unsigned long long) altivec_u64[4];
      SIMDE_ALIGN_TO_16 SIMDE_POWER_ALTIVEC_VECTOR(signed long long)   altivec_i64[4];
      SIMDE_ALIGN_TO_16 SIMDE_POWER_ALTIVEC_VECTOR(double)             altivec_f64[4];
    #endif
  #endif
} simde__m512_private;

typedef union {
  #if defined(SIMDE_VECTOR_SUBSCRIPT)
    SIMDE_AVX512_ALIGN int8_t          i8 SIMDE_VECTOR(64) SIMDE_MAY_ALIAS;
    SIMDE_AVX512_ALIGN int16_t        i16 SIMDE_VECTOR(64) SIMDE_MAY_ALIAS;
    SIMDE_AVX512_ALIGN int32_t        i32 SIMDE_VECTOR(64) SIMDE_MAY_ALIAS;
    SIMDE_AVX512_ALIGN int64_t        i64 SIMDE_VECTOR(64) SIMDE_MAY_ALIAS;
    SIMDE_AVX512_ALIGN uint8_t         u8 SIMDE_VECTOR(64) SIMDE_MAY_ALIAS;
    SIMDE_AVX512_ALIGN uint16_t       u16 SIMDE_VECTOR(64) SIMDE_MAY_ALIAS;
    SIMDE_AVX512_ALIGN uint32_t       u32 SIMDE_VECTOR(64) SIMDE_MAY_ALIAS;
    SIMDE_AVX512_ALIGN uint64_t       u64 SIMDE_VECTOR(64) SIMDE_MAY_ALIAS;
    #if defined(SIMDE_HAVE_INT128_)
    SIMDE_AVX512_ALIGN simde_int128  i128 SIMDE_VECTOR(64) SIMDE_MAY_ALIAS;
    SIMDE_AVX512_ALIGN simde_uint128 u128 SIMDE_VECTOR(64) SIMDE_MAY_ALIAS;
    #endif
    SIMDE_AVX512_ALIGN simde_float32  f32 SIMDE_VECTOR(64) SIMDE_MAY_ALIAS;
    SIMDE_AVX512_ALIGN simde_float64  f64 SIMDE_VECTOR(64) SIMDE_MAY_ALIAS;
    SIMDE_AVX512_ALIGN int_fast32_t  i32f SIMDE_VECTOR(64) SIMDE_MAY_ALIAS;
    SIMDE_AVX512_ALIGN uint_fast32_t u32f SIMDE_VECTOR(64) SIMDE_MAY_ALIAS;
  #else
    SIMDE_AVX512_ALIGN int8_t          i8[64];
    SIMDE_AVX512_ALIGN int16_t        i16[32];
    SIMDE_AVX512_ALIGN int32_t        i32[16];
    SIMDE_AVX512_ALIGN int64_t        i64[8];
    SIMDE_AVX512_ALIGN uint8_t         u8[64];
    SIMDE_AVX512_ALIGN uint16_t       u16[32];
    SIMDE_AVX512_ALIGN uint32_t       u32[16];
    SIMDE_AVX512_ALIGN uint64_t       u64[8];
    #if defined(SIMDE_HAVE_INT128_)
    SIMDE_AVX512_ALIGN simde_int128  i128[4];
    SIMDE_AVX512_ALIGN simde_uint128 u128[4];
    #endif
    SIMDE_AVX512_ALIGN simde_float32  f32[16];
    SIMDE_AVX512_ALIGN simde_float64  f64[8];
    SIMDE_AVX512_ALIGN int_fast32_t  i32f[64 / sizeof(int_fast32_t)];
    SIMDE_AVX512_ALIGN uint_fast32_t u32f[64 / sizeof(uint_fast32_t)];
  #endif

    SIMDE_AVX512_ALIGN simde__m128d_private m128d_private[4];
    SIMDE_AVX512_ALIGN simde__m128d         m128d[4];
    SIMDE_AVX512_ALIGN simde__m256d_private m256d_private[2];
    SIMDE_AVX512_ALIGN simde__m256d         m256d[2];

  #if defined(SIMDE_X86_AVX512F_NATIVE)
    SIMDE_AVX512_ALIGN __m512d        n;
  #elif defined(SIMDE_POWER_ALTIVEC_P6_NATIVE)
    SIMDE_ALIGN_TO_16 SIMDE_POWER_ALTIVEC_VECTOR(unsigned char)      altivec_u8[4];
    SIMDE_ALIGN_TO_16 SIMDE_POWER_ALTIVEC_VECTOR(unsigned short)     altivec_u16[4];
    SIMDE_ALIGN_TO_16 SIMDE_POWER_ALTIVEC_VECTOR(unsigned int)       altivec_u32[4];
    SIMDE_ALIGN_TO_16 SIMDE_POWER_ALTIVEC_VECTOR(signed char)        altivec_i8[4];
    SIMDE_ALIGN_TO_16 SIMDE_POWER_ALTIVEC_VECTOR(signed short)       altivec_i16[4];
    SIMDE_ALIGN_TO_16 SIMDE_POWER_ALTIVEC_VECTOR(signed int)         altivec_i32[4];
    SIMDE_ALIGN_TO_16 SIMDE_POWER_ALTIVEC_VECTOR(float)              altivec_f32[4];
    #if defined(SIMDE_POWER_ALTIVEC_P7_NATIVE)
      SIMDE_ALIGN_TO_16 SIMDE_POWER_ALTIVEC_VECTOR(unsigned long long) altivec_u64[4];
      SIMDE_ALIGN_TO_16 SIMDE_POWER_ALTIVEC_VECTOR(signed long long)   altivec_i64[4];
      SIMDE_ALIGN_TO_16 SIMDE_POWER_ALTIVEC_VECTOR(double)             altivec_f64[4];
    #endif
  #endif
} simde__m512d_private;

typedef union {
  #if defined(SIMDE_VECTOR_SUBSCRIPT)
    SIMDE_AVX512_ALIGN int8_t          i8 SIMDE_VECTOR(64) SIMDE_MAY_ALIAS;
    SIMDE_AVX512_ALIGN int16_t        i16 SIMDE_VECTOR(64) SIMDE_MAY_ALIAS;
    SIMDE_AVX512_ALIGN int32_t        i32 SIMDE_VECTOR(64) SIMDE_MAY_ALIAS;
    SIMDE_AVX512_ALIGN int64_t        i64 SIMDE_VECTOR(64) SIMDE_MAY_ALIAS;
    SIMDE_AVX512_ALIGN uint8_t         u8 SIMDE_VECTOR(64) SIMDE_MAY_ALIAS;
    SIMDE_AVX512_ALIGN uint16_t       u16 SIMDE_VECTOR(64) SIMDE_MAY_ALIAS;
    SIMDE_AVX512_ALIGN uint32_t       u32 SIMDE_VECTOR(64) SIMDE_MAY_ALIAS;
    SIMDE_AVX512_ALIGN uint64_t       u64 SIMDE_VECTOR(64) SIMDE_MAY_ALIAS;
    #if defined(SIMDE_HAVE_INT128_)
    SIMDE_AVX512_ALIGN simde_int128  i128 SIMDE_VECTOR(64) SIMDE_MAY_ALIAS;
    SIMDE_AVX512_ALIGN simde_uint128 u128 SIMDE_VECTOR(64) SIMDE_MAY_ALIAS;
    #endif
    SIMDE_AVX512_ALIGN simde_float32  f32 SIMDE_VECTOR(64) SIMDE_MAY_ALIAS;
    SIMDE_AVX512_ALIGN simde_float64  f64 SIMDE_VECTOR(64) SIMDE_MAY_ALIAS;
    SIMDE_AVX512_ALIGN int_fast32_t  i32f SIMDE_VECTOR(64) SIMDE_MAY_ALIAS;
    SIMDE_AVX512_ALIGN uint_fast32_t u32f SIMDE_VECTOR(64) SIMDE_MAY_ALIAS;
  #else
    SIMDE_AVX512_ALIGN int8_t          i8[64];
    SIMDE_AVX512_ALIGN int16_t        i16[32];
    SIMDE_AVX512_ALIGN int32_t        i32[16];
    SIMDE_AVX512_ALIGN int64_t        i64[8];
    SIMDE_AVX512_ALIGN uint8_t         u8[64];
    SIMDE_AVX512_ALIGN uint16_t       u16[32];
    SIMDE_AVX512_ALIGN uint32_t       u32[16];
    SIMDE_AVX512_ALIGN uint64_t       u64[8];
    SIMDE_AVX512_ALIGN int_fast32_t  i32f[64 / sizeof(int_fast32_t)];
    SIMDE_AVX512_ALIGN uint_fast32_t u32f[64 / sizeof(uint_fast32_t)];
    #if defined(SIMDE_HAVE_INT128_)
    SIMDE_AVX512_ALIGN simde_int128  i128[4];
    SIMDE_AVX512_ALIGN simde_uint128 u128[4];
    #endif
    SIMDE_AVX512_ALIGN simde_float32  f32[16];
    SIMDE_AVX512_ALIGN simde_float64  f64[8];
  #endif

    SIMDE_AVX512_ALIGN simde__m128i_private m128i_private[4];
    SIMDE_AVX512_ALIGN simde__m128i         m128i[4];
    SIMDE_AVX512_ALIGN simde__m256i_private m256i_private[2];
    SIMDE_AVX512_ALIGN simde__m256i         m256i[2];

  #if defined(SIMDE_X86_AVX512F_NATIVE)
    SIMDE_AVX512_ALIGN __m512i        n;
  #elif defined(SIMDE_POWER_ALTIVEC_P6_NATIVE)
    SIMDE_ALIGN_TO_16 SIMDE_POWER_ALTIVEC_VECTOR(unsigned char)      altivec_u8[4];
    SIMDE_ALIGN_TO_16 SIMDE_POWER_ALTIVEC_VECTOR(unsigned short)     altivec_u16[4];
    SIMDE_ALIGN_TO_16 SIMDE_POWER_ALTIVEC_VECTOR(unsigned int)       altivec_u32[4];
    SIMDE_ALIGN_TO_16 SIMDE_POWER_ALTIVEC_VECTOR(signed char)        altivec_i8[4];
    SIMDE_ALIGN_TO_16 SIMDE_POWER_ALTIVEC_VECTOR(signed short)       altivec_i16[4];
    SIMDE_ALIGN_TO_16 SIMDE_POWER_ALTIVEC_VECTOR(signed int)         altivec_i32[4];
    SIMDE_ALIGN_TO_16 SIMDE_POWER_ALTIVEC_VECTOR(float)              altivec_f32[4];
    #if defined(SIMDE_POWER_ALTIVEC_P7_NATIVE)
      SIMDE_ALIGN_TO_16 SIMDE_POWER_ALTIVEC_VECTOR(unsigned long long) altivec_u64[4];
      SIMDE_ALIGN_TO_16 SIMDE_POWER_ALTIVEC_VECTOR(signed long long)   altivec_i64[4];
      SIMDE_ALIGN_TO_16 SIMDE_POWER_ALTIVEC_VECTOR(double)             altivec_f64[4];
    #endif
  #endif
} simde__m512i_private;

/* Intel uses the same header (immintrin.h) for everything AVX and
 * later.  If native aliases are enabled, and the machine has native
 * support for AVX imintrin.h will already have been included, which
 * means simde__m512* will already have been defined.  So, even
 * if the machine doesn't support AVX512F we need to use the native
 * type; it has already been defined.
 *
 * However, we also can't just assume that including immintrin.h does
 * actually define these.  It could be a compiler which supports AVX
 * but not AVX512F, such as GCC < 4.9 or VS < 2017.  That's why we
 * check to see if _MM_CMPINT_GE is defined; it's part of AVX512F,
 * so we assume that if it's present AVX-512F has already been
 * declared.
 *
 * Note that the choice of _MM_CMPINT_GE is deliberate; while GCC
 * uses the preprocessor to define all the _MM_CMPINT_* members,
 * in most compilers they are simply normal enum members.  However,
 * all compilers I've looked at use an object-like macro for
 * _MM_CMPINT_GE, which is defined to _MM_CMPINT_NLT.  _MM_CMPINT_NLT
 * is included in case a compiler does the reverse, though I haven't
 * run into one which does.
 *
 * As for the ICC check, unlike other compilers, merely using the
 * AVX-512 types causes ICC to generate AVX-512 instructions. */
#if (defined(_MM_CMPINT_GE) || defined(_MM_CMPINT_NLT)) && (defined(SIMDE_X86_AVX512F_NATIVE) || !defined(HEDLEY_INTEL_VERSION))
  typedef __m512 simde__m512;
  typedef __m512i simde__m512i;
  typedef __m512d simde__m512d;

  typedef __mmask8 simde__mmask8;
  typedef __mmask16 simde__mmask16;
#else
 #if defined(SIMDE_VECTOR_SUBSCRIPT)
   typedef simde_float32 simde__m512  SIMDE_AVX512_ALIGN SIMDE_VECTOR(64) SIMDE_MAY_ALIAS;
   typedef int_fast32_t  simde__m512i SIMDE_AVX512_ALIGN SIMDE_VECTOR(64) SIMDE_MAY_ALIAS;
   typedef simde_float64 simde__m512d SIMDE_AVX512_ALIGN SIMDE_VECTOR(64) SIMDE_MAY_ALIAS;
  #else
    typedef simde__m512_private  simde__m512;
    typedef simde__m512i_private simde__m512i;
    typedef simde__m512d_private simde__m512d;
  #endif

  typedef uint8_t simde__mmask8;
  typedef uint16_t simde__mmask16;
#endif

/* These are really part of AVX-512VL / AVX-512BW (in GCC __mmask32 is
 * in avx512vlintrin.h and __mmask64 is in avx512bwintrin.h, in clang
 * both are in avx512bwintrin.h), not AVX-512F.  However, we don't have
 * a good (not-compiler-specific) way to detect if these headers have
 * been included.  In compilers which support AVX-512F but not
 * AVX-512BW/VL (e.g., GCC 4.9) we need typedefs since __mmask{32,64)
 * won't exist.
 *
 * AFAICT __mmask{32,64} are always just typedefs to uint{32,64}_t
 * in all compilers, so it's safe to use these instead of typedefs to
 * __mmask{16,32}. If you run into a problem with this please file an
 * issue and we'll try to figure out a work-around. */
typedef uint32_t simde__mmask32;
typedef uint64_t simde__mmask64;

#if !defined(SIMDE_X86_AVX512F_NATIVE) && defined(SIMDE_ENABLE_NATIVE_ALIASES)
  #if !defined(HEDLEY_INTEL_VERSION)
    typedef simde__m512 __m512;
    typedef simde__m512i __m512i;
    typedef simde__m512d __m512d;
  #else
    #define __m512 simde__m512
    #define __m512i simde__m512i
    #define __m512d simde__m512d
  #endif
#endif

HEDLEY_STATIC_ASSERT(64 == sizeof(simde__m512), "simde__m512 size incorrect");
HEDLEY_STATIC_ASSERT(64 == sizeof(simde__m512_private), "simde__m512_private size incorrect");
HEDLEY_STATIC_ASSERT(64 == sizeof(simde__m512i), "simde__m512i size incorrect");
HEDLEY_STATIC_ASSERT(64 == sizeof(simde__m512i_private), "simde__m512i_private size incorrect");
HEDLEY_STATIC_ASSERT(64 == sizeof(simde__m512d), "simde__m512d size incorrect");
HEDLEY_STATIC_ASSERT(64 == sizeof(simde__m512d_private), "simde__m512d_private size incorrect");
#if defined(SIMDE_CHECK_ALIGNMENT) && defined(SIMDE_ALIGN_OF)
HEDLEY_STATIC_ASSERT(SIMDE_ALIGN_OF(simde__m512) == 32, "simde__m512 is not 32-byte aligned");
HEDLEY_STATIC_ASSERT(SIMDE_ALIGN_OF(simde__m512_private) == 32, "simde__m512_private is not 32-byte aligned");
HEDLEY_STATIC_ASSERT(SIMDE_ALIGN_OF(simde__m512i) == 32, "simde__m512i is not 32-byte aligned");
HEDLEY_STATIC_ASSERT(SIMDE_ALIGN_OF(simde__m512i_private) == 32, "simde__m512i_private is not 32-byte aligned");
HEDLEY_STATIC_ASSERT(SIMDE_ALIGN_OF(simde__m512d) == 32, "simde__m512d is not 32-byte aligned");
HEDLEY_STATIC_ASSERT(SIMDE_ALIGN_OF(simde__m512d_private) == 32, "simde__m512d_private is not 32-byte aligned");
#endif

typedef enum
{
  SIMDE_MM_PERM_AAAA = 0x00, SIMDE_MM_PERM_AAAB = 0x01, SIMDE_MM_PERM_AAAC = 0x02,
  SIMDE_MM_PERM_AAAD = 0x03, SIMDE_MM_PERM_AABA = 0x04, SIMDE_MM_PERM_AABB = 0x05,
  SIMDE_MM_PERM_AABC = 0x06, SIMDE_MM_PERM_AABD = 0x07, SIMDE_MM_PERM_AACA = 0x08,
  SIMDE_MM_PERM_AACB = 0x09, SIMDE_MM_PERM_AACC = 0x0A, SIMDE_MM_PERM_AACD = 0x0B,
  SIMDE_MM_PERM_AADA = 0x0C, SIMDE_MM_PERM_AADB = 0x0D, SIMDE_MM_PERM_AADC = 0x0E,
  SIMDE_MM_PERM_AADD = 0x0F, SIMDE_MM_PERM_ABAA = 0x10, SIMDE_MM_PERM_ABAB = 0x11,
  SIMDE_MM_PERM_ABAC = 0x12, SIMDE_MM_PERM_ABAD = 0x13, SIMDE_MM_PERM_ABBA = 0x14,
  SIMDE_MM_PERM_ABBB = 0x15, SIMDE_MM_PERM_ABBC = 0x16, SIMDE_MM_PERM_ABBD = 0x17,
  SIMDE_MM_PERM_ABCA = 0x18, SIMDE_MM_PERM_ABCB = 0x19, SIMDE_MM_PERM_ABCC = 0x1A,
  SIMDE_MM_PERM_ABCD = 0x1B, SIMDE_MM_PERM_ABDA = 0x1C, SIMDE_MM_PERM_ABDB = 0x1D,
  SIMDE_MM_PERM_ABDC = 0x1E, SIMDE_MM_PERM_ABDD = 0x1F, SIMDE_MM_PERM_ACAA = 0x20,
  SIMDE_MM_PERM_ACAB = 0x21, SIMDE_MM_PERM_ACAC = 0x22, SIMDE_MM_PERM_ACAD = 0x23,
  SIMDE_MM_PERM_ACBA = 0x24, SIMDE_MM_PERM_ACBB = 0x25, SIMDE_MM_PERM_ACBC = 0x26,
  SIMDE_MM_PERM_ACBD = 0x27, SIMDE_MM_PERM_ACCA = 0x28, SIMDE_MM_PERM_ACCB = 0x29,
  SIMDE_MM_PERM_ACCC = 0x2A, SIMDE_MM_PERM_ACCD = 0x2B, SIMDE_MM_PERM_ACDA = 0x2C,
  SIMDE_MM_PERM_ACDB = 0x2D, SIMDE_MM_PERM_ACDC = 0x2E, SIMDE_MM_PERM_ACDD = 0x2F,
  SIMDE_MM_PERM_ADAA = 0x30, SIMDE_MM_PERM_ADAB = 0x31, SIMDE_MM_PERM_ADAC = 0x32,
  SIMDE_MM_PERM_ADAD = 0x33, SIMDE_MM_PERM_ADBA = 0x34, SIMDE_MM_PERM_ADBB = 0x35,
  SIMDE_MM_PERM_ADBC = 0x36, SIMDE_MM_PERM_ADBD = 0x37, SIMDE_MM_PERM_ADCA = 0x38,
  SIMDE_MM_PERM_ADCB = 0x39, SIMDE_MM_PERM_ADCC = 0x3A, SIMDE_MM_PERM_ADCD = 0x3B,
  SIMDE_MM_PERM_ADDA = 0x3C, SIMDE_MM_PERM_ADDB = 0x3D, SIMDE_MM_PERM_ADDC = 0x3E,
  SIMDE_MM_PERM_ADDD = 0x3F, SIMDE_MM_PERM_BAAA = 0x40, SIMDE_MM_PERM_BAAB = 0x41,
  SIMDE_MM_PERM_BAAC = 0x42, SIMDE_MM_PERM_BAAD = 0x43, SIMDE_MM_PERM_BABA = 0x44,
  SIMDE_MM_PERM_BABB = 0x45, SIMDE_MM_PERM_BABC = 0x46, SIMDE_MM_PERM_BABD = 0x47,
  SIMDE_MM_PERM_BACA = 0x48, SIMDE_MM_PERM_BACB = 0x49, SIMDE_MM_PERM_BACC = 0x4A,
  SIMDE_MM_PERM_BACD = 0x4B, SIMDE_MM_PERM_BADA = 0x4C, SIMDE_MM_PERM_BADB = 0x4D,
  SIMDE_MM_PERM_BADC = 0x4E, SIMDE_MM_PERM_BADD = 0x4F, SIMDE_MM_PERM_BBAA = 0x50,
  SIMDE_MM_PERM_BBAB = 0x51, SIMDE_MM_PERM_BBAC = 0x52, SIMDE_MM_PERM_BBAD = 0x53,
  SIMDE_MM_PERM_BBBA = 0x54, SIMDE_MM_PERM_BBBB = 0x55, SIMDE_MM_PERM_BBBC = 0x56,
  SIMDE_MM_PERM_BBBD = 0x57, SIMDE_MM_PERM_BBCA = 0x58, SIMDE_MM_PERM_BBCB = 0x59,
  SIMDE_MM_PERM_BBCC = 0x5A, SIMDE_MM_PERM_BBCD = 0x5B, SIMDE_MM_PERM_BBDA = 0x5C,
  SIMDE_MM_PERM_BBDB = 0x5D, SIMDE_MM_PERM_BBDC = 0x5E, SIMDE_MM_PERM_BBDD = 0x5F,
  SIMDE_MM_PERM_BCAA = 0x60, SIMDE_MM_PERM_BCAB = 0x61, SIMDE_MM_PERM_BCAC = 0x62,
  SIMDE_MM_PERM_BCAD = 0x63, SIMDE_MM_PERM_BCBA = 0x64, SIMDE_MM_PERM_BCBB = 0x65,
  SIMDE_MM_PERM_BCBC = 0x66, SIMDE_MM_PERM_BCBD = 0x67, SIMDE_MM_PERM_BCCA = 0x68,
  SIMDE_MM_PERM_BCCB = 0x69, SIMDE_MM_PERM_BCCC = 0x6A, SIMDE_MM_PERM_BCCD = 0x6B,
  SIMDE_MM_PERM_BCDA = 0x6C, SIMDE_MM_PERM_BCDB = 0x6D, SIMDE_MM_PERM_BCDC = 0x6E,
  SIMDE_MM_PERM_BCDD = 0x6F, SIMDE_MM_PERM_BDAA = 0x70, SIMDE_MM_PERM_BDAB = 0x71,
  SIMDE_MM_PERM_BDAC = 0x72, SIMDE_MM_PERM_BDAD = 0x73, SIMDE_MM_PERM_BDBA = 0x74,
  SIMDE_MM_PERM_BDBB = 0x75, SIMDE_MM_PERM_BDBC = 0x76, SIMDE_MM_PERM_BDBD = 0x77,
  SIMDE_MM_PERM_BDCA = 0x78, SIMDE_MM_PERM_BDCB = 0x79, SIMDE_MM_PERM_BDCC = 0x7A,
  SIMDE_MM_PERM_BDCD = 0x7B, SIMDE_MM_PERM_BDDA = 0x7C, SIMDE_MM_PERM_BDDB = 0x7D,
  SIMDE_MM_PERM_BDDC = 0x7E, SIMDE_MM_PERM_BDDD = 0x7F, SIMDE_MM_PERM_CAAA = 0x80,
  SIMDE_MM_PERM_CAAB = 0x81, SIMDE_MM_PERM_CAAC = 0x82, SIMDE_MM_PERM_CAAD = 0x83,
  SIMDE_MM_PERM_CABA = 0x84, SIMDE_MM_PERM_CABB = 0x85, SIMDE_MM_PERM_CABC = 0x86,
  SIMDE_MM_PERM_CABD = 0x87, SIMDE_MM_PERM_CACA = 0x88, SIMDE_MM_PERM_CACB = 0x89,
  SIMDE_MM_PERM_CACC = 0x8A, SIMDE_MM_PERM_CACD = 0x8B, SIMDE_MM_PERM_CADA = 0x8C,
  SIMDE_MM_PERM_CADB = 0x8D, SIMDE_MM_PERM_CADC = 0x8E, SIMDE_MM_PERM_CADD = 0x8F,
  SIMDE_MM_PERM_CBAA = 0x90, SIMDE_MM_PERM_CBAB = 0x91, SIMDE_MM_PERM_CBAC = 0x92,
  SIMDE_MM_PERM_CBAD = 0x93, SIMDE_MM_PERM_CBBA = 0x94, SIMDE_MM_PERM_CBBB = 0x95,
  SIMDE_MM_PERM_CBBC = 0x96, SIMDE_MM_PERM_CBBD = 0x97, SIMDE_MM_PERM_CBCA = 0x98,
  SIMDE_MM_PERM_CBCB = 0x99, SIMDE_MM_PERM_CBCC = 0x9A, SIMDE_MM_PERM_CBCD = 0x9B,
  SIMDE_MM_PERM_CBDA = 0x9C, SIMDE_MM_PERM_CBDB = 0x9D, SIMDE_MM_PERM_CBDC = 0x9E,
  SIMDE_MM_PERM_CBDD = 0x9F, SIMDE_MM_PERM_CCAA = 0xA0, SIMDE_MM_PERM_CCAB = 0xA1,
  SIMDE_MM_PERM_CCAC = 0xA2, SIMDE_MM_PERM_CCAD = 0xA3, SIMDE_MM_PERM_CCBA = 0xA4,
  SIMDE_MM_PERM_CCBB = 0xA5, SIMDE_MM_PERM_CCBC = 0xA6, SIMDE_MM_PERM_CCBD = 0xA7,
  SIMDE_MM_PERM_CCCA = 0xA8, SIMDE_MM_PERM_CCCB = 0xA9, SIMDE_MM_PERM_CCCC = 0xAA,
  SIMDE_MM_PERM_CCCD = 0xAB, SIMDE_MM_PERM_CCDA = 0xAC, SIMDE_MM_PERM_CCDB = 0xAD,
  SIMDE_MM_PERM_CCDC = 0xAE, SIMDE_MM_PERM_CCDD = 0xAF, SIMDE_MM_PERM_CDAA = 0xB0,
  SIMDE_MM_PERM_CDAB = 0xB1, SIMDE_MM_PERM_CDAC = 0xB2, SIMDE_MM_PERM_CDAD = 0xB3,
  SIMDE_MM_PERM_CDBA = 0xB4, SIMDE_MM_PERM_CDBB = 0xB5, SIMDE_MM_PERM_CDBC = 0xB6,
  SIMDE_MM_PERM_CDBD = 0xB7, SIMDE_MM_PERM_CDCA = 0xB8, SIMDE_MM_PERM_CDCB = 0xB9,
  SIMDE_MM_PERM_CDCC = 0xBA, SIMDE_MM_PERM_CDCD = 0xBB, SIMDE_MM_PERM_CDDA = 0xBC,
  SIMDE_MM_PERM_CDDB = 0xBD, SIMDE_MM_PERM_CDDC = 0xBE, SIMDE_MM_PERM_CDDD = 0xBF,
  SIMDE_MM_PERM_DAAA = 0xC0, SIMDE_MM_PERM_DAAB = 0xC1, SIMDE_MM_PERM_DAAC = 0xC2,
  SIMDE_MM_PERM_DAAD = 0xC3, SIMDE_MM_PERM_DABA = 0xC4, SIMDE_MM_PERM_DABB = 0xC5,
  SIMDE_MM_PERM_DABC = 0xC6, SIMDE_MM_PERM_DABD = 0xC7, SIMDE_MM_PERM_DACA = 0xC8,
  SIMDE_MM_PERM_DACB = 0xC9, SIMDE_MM_PERM_DACC = 0xCA, SIMDE_MM_PERM_DACD = 0xCB,
  SIMDE_MM_PERM_DADA = 0xCC, SIMDE_MM_PERM_DADB = 0xCD, SIMDE_MM_PERM_DADC = 0xCE,
  SIMDE_MM_PERM_DADD = 0xCF, SIMDE_MM_PERM_DBAA = 0xD0, SIMDE_MM_PERM_DBAB = 0xD1,
  SIMDE_MM_PERM_DBAC = 0xD2, SIMDE_MM_PERM_DBAD = 0xD3, SIMDE_MM_PERM_DBBA = 0xD4,
  SIMDE_MM_PERM_DBBB = 0xD5, SIMDE_MM_PERM_DBBC = 0xD6, SIMDE_MM_PERM_DBBD = 0xD7,
  SIMDE_MM_PERM_DBCA = 0xD8, SIMDE_MM_PERM_DBCB = 0xD9, SIMDE_MM_PERM_DBCC = 0xDA,
  SIMDE_MM_PERM_DBCD = 0xDB, SIMDE_MM_PERM_DBDA = 0xDC, SIMDE_MM_PERM_DBDB = 0xDD,
  SIMDE_MM_PERM_DBDC = 0xDE, SIMDE_MM_PERM_DBDD = 0xDF, SIMDE_MM_PERM_DCAA = 0xE0,
  SIMDE_MM_PERM_DCAB = 0xE1, SIMDE_MM_PERM_DCAC = 0xE2, SIMDE_MM_PERM_DCAD = 0xE3,
  SIMDE_MM_PERM_DCBA = 0xE4, SIMDE_MM_PERM_DCBB = 0xE5, SIMDE_MM_PERM_DCBC = 0xE6,
  SIMDE_MM_PERM_DCBD = 0xE7, SIMDE_MM_PERM_DCCA = 0xE8, SIMDE_MM_PERM_DCCB = 0xE9,
  SIMDE_MM_PERM_DCCC = 0xEA, SIMDE_MM_PERM_DCCD = 0xEB, SIMDE_MM_PERM_DCDA = 0xEC,
  SIMDE_MM_PERM_DCDB = 0xED, SIMDE_MM_PERM_DCDC = 0xEE, SIMDE_MM_PERM_DCDD = 0xEF,
  SIMDE_MM_PERM_DDAA = 0xF0, SIMDE_MM_PERM_DDAB = 0xF1, SIMDE_MM_PERM_DDAC = 0xF2,
  SIMDE_MM_PERM_DDAD = 0xF3, SIMDE_MM_PERM_DDBA = 0xF4, SIMDE_MM_PERM_DDBB = 0xF5,
  SIMDE_MM_PERM_DDBC = 0xF6, SIMDE_MM_PERM_DDBD = 0xF7, SIMDE_MM_PERM_DDCA = 0xF8,
  SIMDE_MM_PERM_DDCB = 0xF9, SIMDE_MM_PERM_DDCC = 0xFA, SIMDE_MM_PERM_DDCD = 0xFB,
  SIMDE_MM_PERM_DDDA = 0xFC, SIMDE_MM_PERM_DDDB = 0xFD, SIMDE_MM_PERM_DDDC = 0xFE,
  SIMDE_MM_PERM_DDDD = 0xFF
} SIMDE_MM_PERM_ENUM;

#if !defined(SIMDE_X86_AVX512F_NATIVE) && defined(SIMDE_ENABLE_NATIVE_ALIASES)
  #if !defined(HEDLEY_INTEL_VERSION)
    typedef SIMDE_MM_PERM_AAAA _MM_PERM_AAAA;
    typedef SIMDE_MM_PERM_AAAB _MM_PERM_AAAB;
    typedef SIMDE_MM_PERM_AAAC _MM_PERM_AAAC;
    typedef SIMDE_MM_PERM_AAAD _MM_PERM_AAAD;
    typedef SIMDE_MM_PERM_AABA _MM_PERM_AABA;
    typedef SIMDE_MM_PERM_AABB _MM_PERM_AABB;
    typedef SIMDE_MM_PERM_AABC _MM_PERM_AABC;
    typedef SIMDE_MM_PERM_AABD _MM_PERM_AABD;
    typedef SIMDE_MM_PERM_AACA _MM_PERM_AACA;
    typedef SIMDE_MM_PERM_AACB _MM_PERM_AACB;
    typedef SIMDE_MM_PERM_AACC _MM_PERM_AACC;
    typedef SIMDE_MM_PERM_AACD _MM_PERM_AACD;
    typedef SIMDE_MM_PERM_AADA _MM_PERM_AADA;
    typedef SIMDE_MM_PERM_AADB _MM_PERM_AADB;
    typedef SIMDE_MM_PERM_AADC _MM_PERM_AADC;
    typedef SIMDE_MM_PERM_AADD _MM_PERM_AADD;
    typedef SIMDE_MM_PERM_ABAA _MM_PERM_ABAA;
    typedef SIMDE_MM_PERM_ABAB _MM_PERM_ABAB;
    typedef SIMDE_MM_PERM_ABAC _MM_PERM_ABAC;
    typedef SIMDE_MM_PERM_ABAD _MM_PERM_ABAD;
    typedef SIMDE_MM_PERM_ABBA _MM_PERM_ABBA;
    typedef SIMDE_MM_PERM_ABBB _MM_PERM_ABBB;
    typedef SIMDE_MM_PERM_ABBC _MM_PERM_ABBC;
    typedef SIMDE_MM_PERM_ABBD _MM_PERM_ABBD;
    typedef SIMDE_MM_PERM_ABCA _MM_PERM_ABCA;
    typedef SIMDE_MM_PERM_ABCB _MM_PERM_ABCB;
    typedef SIMDE_MM_PERM_ABCC _MM_PERM_ABCC;
    typedef SIMDE_MM_PERM_ABCD _MM_PERM_ABCD;
    typedef SIMDE_MM_PERM_ABDA _MM_PERM_ABDA;
    typedef SIMDE_MM_PERM_ABDB _MM_PERM_ABDB;
    typedef SIMDE_MM_PERM_ABDC _MM_PERM_ABDC;
    typedef SIMDE_MM_PERM_ABDD _MM_PERM_ABDD;
    typedef SIMDE_MM_PERM_ACAA _MM_PERM_ACAA;
    typedef SIMDE_MM_PERM_ACAB _MM_PERM_ACAB;
    typedef SIMDE_MM_PERM_ACAC _MM_PERM_ACAC;
    typedef SIMDE_MM_PERM_ACAD _MM_PERM_ACAD;
    typedef SIMDE_MM_PERM_ACBA _MM_PERM_ACBA;
    typedef SIMDE_MM_PERM_ACBB _MM_PERM_ACBB;
    typedef SIMDE_MM_PERM_ACBC _MM_PERM_ACBC;
    typedef SIMDE_MM_PERM_ACBD _MM_PERM_ACBD;
    typedef SIMDE_MM_PERM_ACCA _MM_PERM_ACCA;
    typedef SIMDE_MM_PERM_ACCB _MM_PERM_ACCB;
    typedef SIMDE_MM_PERM_ACCC _MM_PERM_ACCC;
    typedef SIMDE_MM_PERM_ACCD _MM_PERM_ACCD;
    typedef SIMDE_MM_PERM_ACDA _MM_PERM_ACDA;
    typedef SIMDE_MM_PERM_ACDB _MM_PERM_ACDB;
    typedef SIMDE_MM_PERM_ACDC _MM_PERM_ACDC;
    typedef SIMDE_MM_PERM_ACDD _MM_PERM_ACDD;
    typedef SIMDE_MM_PERM_ADAA _MM_PERM_ADAA;
    typedef SIMDE_MM_PERM_ADAB _MM_PERM_ADAB;
    typedef SIMDE_MM_PERM_ADAC _MM_PERM_ADAC;
    typedef SIMDE_MM_PERM_ADAD _MM_PERM_ADAD;
    typedef SIMDE_MM_PERM_ADBA _MM_PERM_ADBA;
    typedef SIMDE_MM_PERM_ADBB _MM_PERM_ADBB;
    typedef SIMDE_MM_PERM_ADBC _MM_PERM_ADBC;
    typedef SIMDE_MM_PERM_ADBD _MM_PERM_ADBD;
    typedef SIMDE_MM_PERM_ADCA _MM_PERM_ADCA;
    typedef SIMDE_MM_PERM_ADCB _MM_PERM_ADCB;
    typedef SIMDE_MM_PERM_ADCC _MM_PERM_ADCC;
    typedef SIMDE_MM_PERM_ADCD _MM_PERM_ADCD;
    typedef SIMDE_MM_PERM_ADDA _MM_PERM_ADDA;
    typedef SIMDE_MM_PERM_ADDB _MM_PERM_ADDB;
    typedef SIMDE_MM_PERM_ADDC _MM_PERM_ADDC;
    typedef SIMDE_MM_PERM_ADDD _MM_PERM_ADDD;
    typedef SIMDE_MM_PERM_BAAA _MM_PERM_BAAA;
    typedef SIMDE_MM_PERM_BAAB _MM_PERM_BAAB;
    typedef SIMDE_MM_PERM_BAAC _MM_PERM_BAAC;
    typedef SIMDE_MM_PERM_BAAD _MM_PERM_BAAD;
    typedef SIMDE_MM_PERM_BABA _MM_PERM_BABA;
    typedef SIMDE_MM_PERM_BABB _MM_PERM_BABB;
    typedef SIMDE_MM_PERM_BABC _MM_PERM_BABC;
    typedef SIMDE_MM_PERM_BABD _MM_PERM_BABD;
    typedef SIMDE_MM_PERM_BACA _MM_PERM_BACA;
    typedef SIMDE_MM_PERM_BACB _MM_PERM_BACB;
    typedef SIMDE_MM_PERM_BACC _MM_PERM_BACC;
    typedef SIMDE_MM_PERM_BACD _MM_PERM_BACD;
    typedef SIMDE_MM_PERM_BADA _MM_PERM_BADA;
    typedef SIMDE_MM_PERM_BADB _MM_PERM_BADB;
    typedef SIMDE_MM_PERM_BADC _MM_PERM_BADC;
    typedef SIMDE_MM_PERM_BADD _MM_PERM_BADD;
    typedef SIMDE_MM_PERM_BBAA _MM_PERM_BBAA;
    typedef SIMDE_MM_PERM_BBAB _MM_PERM_BBAB;
    typedef SIMDE_MM_PERM_BBAC _MM_PERM_BBAC;
    typedef SIMDE_MM_PERM_BBAD _MM_PERM_BBAD;
    typedef SIMDE_MM_PERM_BBBA _MM_PERM_BBBA;
    typedef SIMDE_MM_PERM_BBBB _MM_PERM_BBBB;
    typedef SIMDE_MM_PERM_BBBC _MM_PERM_BBBC;
    typedef SIMDE_MM_PERM_BBBD _MM_PERM_BBBD;
    typedef SIMDE_MM_PERM_BBCA _MM_PERM_BBCA;
    typedef SIMDE_MM_PERM_BBCB _MM_PERM_BBCB;
    typedef SIMDE_MM_PERM_BBCC _MM_PERM_BBCC;
    typedef SIMDE_MM_PERM_BBCD _MM_PERM_BBCD;
    typedef SIMDE_MM_PERM_BBDA _MM_PERM_BBDA;
    typedef SIMDE_MM_PERM_BBDB _MM_PERM_BBDB;
    typedef SIMDE_MM_PERM_BBDC _MM_PERM_BBDC;
    typedef SIMDE_MM_PERM_BBDD _MM_PERM_BBDD;
    typedef SIMDE_MM_PERM_BCAA _MM_PERM_BCAA;
    typedef SIMDE_MM_PERM_BCAB _MM_PERM_BCAB;
    typedef SIMDE_MM_PERM_BCAC _MM_PERM_BCAC;
    typedef SIMDE_MM_PERM_BCAD _MM_PERM_BCAD;
    typedef SIMDE_MM_PERM_BCBA _MM_PERM_BCBA;
    typedef SIMDE_MM_PERM_BCBB _MM_PERM_BCBB;
    typedef SIMDE_MM_PERM_BCBC _MM_PERM_BCBC;
    typedef SIMDE_MM_PERM_BCBD _MM_PERM_BCBD;
    typedef SIMDE_MM_PERM_BCCA _MM_PERM_BCCA;
    typedef SIMDE_MM_PERM_BCCB _MM_PERM_BCCB;
    typedef SIMDE_MM_PERM_BCCC _MM_PERM_BCCC;
    typedef SIMDE_MM_PERM_BCCD _MM_PERM_BCCD;
    typedef SIMDE_MM_PERM_BCDA _MM_PERM_BCDA;
    typedef SIMDE_MM_PERM_BCDB _MM_PERM_BCDB;
    typedef SIMDE_MM_PERM_BCDC _MM_PERM_BCDC;
    typedef SIMDE_MM_PERM_BCDD _MM_PERM_BCDD;
    typedef SIMDE_MM_PERM_BDAA _MM_PERM_BDAA;
    typedef SIMDE_MM_PERM_BDAB _MM_PERM_BDAB;
    typedef SIMDE_MM_PERM_BDAC _MM_PERM_BDAC;
    typedef SIMDE_MM_PERM_BDAD _MM_PERM_BDAD;
    typedef SIMDE_MM_PERM_BDBA _MM_PERM_BDBA;
    typedef SIMDE_MM_PERM_BDBB _MM_PERM_BDBB;
    typedef SIMDE_MM_PERM_BDBC _MM_PERM_BDBC;
    typedef SIMDE_MM_PERM_BDBD _MM_PERM_BDBD;
    typedef SIMDE_MM_PERM_BDCA _MM_PERM_BDCA;
    typedef SIMDE_MM_PERM_BDCB _MM_PERM_BDCB;
    typedef SIMDE_MM_PERM_BDCC _MM_PERM_BDCC;
    typedef SIMDE_MM_PERM_BDCD _MM_PERM_BDCD;
    typedef SIMDE_MM_PERM_BDDA _MM_PERM_BDDA;
    typedef SIMDE_MM_PERM_BDDB _MM_PERM_BDDB;
    typedef SIMDE_MM_PERM_BDDC _MM_PERM_BDDC;
    typedef SIMDE_MM_PERM_BDDD _MM_PERM_BDDD;
    typedef SIMDE_MM_PERM_CAAA _MM_PERM_CAAA;
    typedef SIMDE_MM_PERM_CAAB _MM_PERM_CAAB;
    typedef SIMDE_MM_PERM_CAAC _MM_PERM_CAAC;
    typedef SIMDE_MM_PERM_CAAD _MM_PERM_CAAD;
    typedef SIMDE_MM_PERM_CABA _MM_PERM_CABA;
    typedef SIMDE_MM_PERM_CABB _MM_PERM_CABB;
    typedef SIMDE_MM_PERM_CABC _MM_PERM_CABC;
    typedef SIMDE_MM_PERM_CABD _MM_PERM_CABD;
    typedef SIMDE_MM_PERM_CACA _MM_PERM_CACA;
    typedef SIMDE_MM_PERM_CACB _MM_PERM_CACB;
    typedef SIMDE_MM_PERM_CACC _MM_PERM_CACC;
    typedef SIMDE_MM_PERM_CACD _MM_PERM_CACD;
    typedef SIMDE_MM_PERM_CADA _MM_PERM_CADA;
    typedef SIMDE_MM_PERM_CADB _MM_PERM_CADB;
    typedef SIMDE_MM_PERM_CADC _MM_PERM_CADC;
    typedef SIMDE_MM_PERM_CADD _MM_PERM_CADD;
    typedef SIMDE_MM_PERM_CBAA _MM_PERM_CBAA;
    typedef SIMDE_MM_PERM_CBAB _MM_PERM_CBAB;
    typedef SIMDE_MM_PERM_CBAC _MM_PERM_CBAC;
    typedef SIMDE_MM_PERM_CBAD _MM_PERM_CBAD;
    typedef SIMDE_MM_PERM_CBBA _MM_PERM_CBBA;
    typedef SIMDE_MM_PERM_CBBB _MM_PERM_CBBB;
    typedef SIMDE_MM_PERM_CBBC _MM_PERM_CBBC;
    typedef SIMDE_MM_PERM_CBBD _MM_PERM_CBBD;
    typedef SIMDE_MM_PERM_CBCA _MM_PERM_CBCA;
    typedef SIMDE_MM_PERM_CBCB _MM_PERM_CBCB;
    typedef SIMDE_MM_PERM_CBCC _MM_PERM_CBCC;
    typedef SIMDE_MM_PERM_CBCD _MM_PERM_CBCD;
    typedef SIMDE_MM_PERM_CBDA _MM_PERM_CBDA;
    typedef SIMDE_MM_PERM_CBDB _MM_PERM_CBDB;
    typedef SIMDE_MM_PERM_CBDC _MM_PERM_CBDC;
    typedef SIMDE_MM_PERM_CBDD _MM_PERM_CBDD;
    typedef SIMDE_MM_PERM_CCAA _MM_PERM_CCAA;
    typedef SIMDE_MM_PERM_CCAB _MM_PERM_CCAB;
    typedef SIMDE_MM_PERM_CCAC _MM_PERM_CCAC;
    typedef SIMDE_MM_PERM_CCAD _MM_PERM_CCAD;
    typedef SIMDE_MM_PERM_CCBA _MM_PERM_CCBA;
    typedef SIMDE_MM_PERM_CCBB _MM_PERM_CCBB;
    typedef SIMDE_MM_PERM_CCBC _MM_PERM_CCBC;
    typedef SIMDE_MM_PERM_CCBD _MM_PERM_CCBD;
    typedef SIMDE_MM_PERM_CCCA _MM_PERM_CCCA;
    typedef SIMDE_MM_PERM_CCCB _MM_PERM_CCCB;
    typedef SIMDE_MM_PERM_CCCC _MM_PERM_CCCC;
    typedef SIMDE_MM_PERM_CCCD _MM_PERM_CCCD;
    typedef SIMDE_MM_PERM_CCDA _MM_PERM_CCDA;
    typedef SIMDE_MM_PERM_CCDB _MM_PERM_CCDB;
    typedef SIMDE_MM_PERM_CCDC _MM_PERM_CCDC;
    typedef SIMDE_MM_PERM_CCDD _MM_PERM_CCDD;
    typedef SIMDE_MM_PERM_CDAA _MM_PERM_CDAA;
    typedef SIMDE_MM_PERM_CDAB _MM_PERM_CDAB;
    typedef SIMDE_MM_PERM_CDAC _MM_PERM_CDAC;
    typedef SIMDE_MM_PERM_CDAD _MM_PERM_CDAD;
    typedef SIMDE_MM_PERM_CDBA _MM_PERM_CDBA;
    typedef SIMDE_MM_PERM_CDBB _MM_PERM_CDBB;
    typedef SIMDE_MM_PERM_CDBC _MM_PERM_CDBC;
    typedef SIMDE_MM_PERM_CDBD _MM_PERM_CDBD;
    typedef SIMDE_MM_PERM_CDCA _MM_PERM_CDCA;
    typedef SIMDE_MM_PERM_CDCB _MM_PERM_CDCB;
    typedef SIMDE_MM_PERM_CDCC _MM_PERM_CDCC;
    typedef SIMDE_MM_PERM_CDCD _MM_PERM_CDCD;
    typedef SIMDE_MM_PERM_CDDA _MM_PERM_CDDA;
    typedef SIMDE_MM_PERM_CDDB _MM_PERM_CDDB;
    typedef SIMDE_MM_PERM_CDDC _MM_PERM_CDDC;
    typedef SIMDE_MM_PERM_CDDD _MM_PERM_CDDD;
    typedef SIMDE_MM_PERM_DAAA _MM_PERM_DAAA;
    typedef SIMDE_MM_PERM_DAAB _MM_PERM_DAAB;
    typedef SIMDE_MM_PERM_DAAC _MM_PERM_DAAC;
    typedef SIMDE_MM_PERM_DAAD _MM_PERM_DAAD;
    typedef SIMDE_MM_PERM_DABA _MM_PERM_DABA;
    typedef SIMDE_MM_PERM_DABB _MM_PERM_DABB;
    typedef SIMDE_MM_PERM_DABC _MM_PERM_DABC;
    typedef SIMDE_MM_PERM_DABD _MM_PERM_DABD;
    typedef SIMDE_MM_PERM_DACA _MM_PERM_DACA;
    typedef SIMDE_MM_PERM_DACB _MM_PERM_DACB;
    typedef SIMDE_MM_PERM_DACC _MM_PERM_DACC;
    typedef SIMDE_MM_PERM_DACD _MM_PERM_DACD;
    typedef SIMDE_MM_PERM_DADA _MM_PERM_DADA;
    typedef SIMDE_MM_PERM_DADB _MM_PERM_DADB;
    typedef SIMDE_MM_PERM_DADC _MM_PERM_DADC;
    typedef SIMDE_MM_PERM_DADD _MM_PERM_DADD;
    typedef SIMDE_MM_PERM_DBAA _MM_PERM_DBAA;
    typedef SIMDE_MM_PERM_DBAB _MM_PERM_DBAB;
    typedef SIMDE_MM_PERM_DBAC _MM_PERM_DBAC;
    typedef SIMDE_MM_PERM_DBAD _MM_PERM_DBAD;
    typedef SIMDE_MM_PERM_DBBA _MM_PERM_DBBA;
    typedef SIMDE_MM_PERM_DBBB _MM_PERM_DBBB;
    typedef SIMDE_MM_PERM_DBBC _MM_PERM_DBBC;
    typedef SIMDE_MM_PERM_DBBD _MM_PERM_DBBD;
    typedef SIMDE_MM_PERM_DBCA _MM_PERM_DBCA;
    typedef SIMDE_MM_PERM_DBCB _MM_PERM_DBCB;
    typedef SIMDE_MM_PERM_DBCC _MM_PERM_DBCC;
    typedef SIMDE_MM_PERM_DBCD _MM_PERM_DBCD;
    typedef SIMDE_MM_PERM_DBDA _MM_PERM_DBDA;
    typedef SIMDE_MM_PERM_DBDB _MM_PERM_DBDB;
    typedef SIMDE_MM_PERM_DBDC _MM_PERM_DBDC;
    typedef SIMDE_MM_PERM_DBDD _MM_PERM_DBDD;
    typedef SIMDE_MM_PERM_DCAA _MM_PERM_DCAA;
    typedef SIMDE_MM_PERM_DCAB _MM_PERM_DCAB;
    typedef SIMDE_MM_PERM_DCAC _MM_PERM_DCAC;
    typedef SIMDE_MM_PERM_DCAD _MM_PERM_DCAD;
    typedef SIMDE_MM_PERM_DCBA _MM_PERM_DCBA;
    typedef SIMDE_MM_PERM_DCBB _MM_PERM_DCBB;
    typedef SIMDE_MM_PERM_DCBC _MM_PERM_DCBC;
    typedef SIMDE_MM_PERM_DCBD _MM_PERM_DCBD;
    typedef SIMDE_MM_PERM_DCCA _MM_PERM_DCCA;
    typedef SIMDE_MM_PERM_DCCB _MM_PERM_DCCB;
    typedef SIMDE_MM_PERM_DCCC _MM_PERM_DCCC;
    typedef SIMDE_MM_PERM_DCCD _MM_PERM_DCCD;
    typedef SIMDE_MM_PERM_DCDA _MM_PERM_DCDA;
    typedef SIMDE_MM_PERM_DCDB _MM_PERM_DCDB;
    typedef SIMDE_MM_PERM_DCDC _MM_PERM_DCDC;
    typedef SIMDE_MM_PERM_DCDD _MM_PERM_DCDD;
    typedef SIMDE_MM_PERM_DDAA _MM_PERM_DDAA;
    typedef SIMDE_MM_PERM_DDAB _MM_PERM_DDAB;
    typedef SIMDE_MM_PERM_DDAC _MM_PERM_DDAC;
    typedef SIMDE_MM_PERM_DDAD _MM_PERM_DDAD;
    typedef SIMDE_MM_PERM_DDBA _MM_PERM_DDBA;
    typedef SIMDE_MM_PERM_DDBB _MM_PERM_DDBB;
    typedef SIMDE_MM_PERM_DDBC _MM_PERM_DDBC;
    typedef SIMDE_MM_PERM_DDBD _MM_PERM_DDBD;
    typedef SIMDE_MM_PERM_DDCA _MM_PERM_DDCA;
    typedef SIMDE_MM_PERM_DDCB _MM_PERM_DDCB;
    typedef SIMDE_MM_PERM_DDCC _MM_PERM_DDCC;
    typedef SIMDE_MM_PERM_DDCD _MM_PERM_DDCD;
    typedef SIMDE_MM_PERM_DDDA _MM_PERM_DDDA;
    typedef SIMDE_MM_PERM_DDDB _MM_PERM_DDDB;
    typedef SIMDE_MM_PERM_DDDC _MM_PERM_DDDC;
    typedef SIMDE_MM_PERM_DDDD _MM_PERM_DDDD;
    typedef SIMDE_MM_PERM_ENUM _MM_PERM_ENUM;
  #else
    #define _MM_PERM_AAAA SIMDE_MM_PERM_AAAA
    #define _MM_PERM_AAAB SIMDE_MM_PERM_AAAB
    #define _MM_PERM_AAAC SIMDE_MM_PERM_AAAC
    #define _MM_PERM_AAAD SIMDE_MM_PERM_AAAD
    #define _MM_PERM_AABA SIMDE_MM_PERM_AABA
    #define _MM_PERM_AABB SIMDE_MM_PERM_AABB
    #define _MM_PERM_AABC SIMDE_MM_PERM_AABC
    #define _MM_PERM_AABD SIMDE_MM_PERM_AABD
    #define _MM_PERM_AACA SIMDE_MM_PERM_AACA
    #define _MM_PERM_AACB SIMDE_MM_PERM_AACB
    #define _MM_PERM_AACC SIMDE_MM_PERM_AACC
    #define _MM_PERM_AACD SIMDE_MM_PERM_AACD
    #define _MM_PERM_AADA SIMDE_MM_PERM_AADA
    #define _MM_PERM_AADB SIMDE_MM_PERM_AADB
    #define _MM_PERM_AADC SIMDE_MM_PERM_AADC
    #define _MM_PERM_AADD SIMDE_MM_PERM_AADD
    #define _MM_PERM_ABAA SIMDE_MM_PERM_ABAA
    #define _MM_PERM_ABAB SIMDE_MM_PERM_ABAB
    #define _MM_PERM_ABAC SIMDE_MM_PERM_ABAC
    #define _MM_PERM_ABAD SIMDE_MM_PERM_ABAD
    #define _MM_PERM_ABBA SIMDE_MM_PERM_ABBA
    #define _MM_PERM_ABBB SIMDE_MM_PERM_ABBB
    #define _MM_PERM_ABBC SIMDE_MM_PERM_ABBC
    #define _MM_PERM_ABBD SIMDE_MM_PERM_ABBD
    #define _MM_PERM_ABCA SIMDE_MM_PERM_ABCA
    #define _MM_PERM_ABCB SIMDE_MM_PERM_ABCB
    #define _MM_PERM_ABCC SIMDE_MM_PERM_ABCC
    #define _MM_PERM_ABCD SIMDE_MM_PERM_ABCD
    #define _MM_PERM_ABDA SIMDE_MM_PERM_ABDA
    #define _MM_PERM_ABDB SIMDE_MM_PERM_ABDB
    #define _MM_PERM_ABDC SIMDE_MM_PERM_ABDC
    #define _MM_PERM_ABDD SIMDE_MM_PERM_ABDD
    #define _MM_PERM_ACAA SIMDE_MM_PERM_ACAA
    #define _MM_PERM_ACAB SIMDE_MM_PERM_ACAB
    #define _MM_PERM_ACAC SIMDE_MM_PERM_ACAC
    #define _MM_PERM_ACAD SIMDE_MM_PERM_ACAD
    #define _MM_PERM_ACBA SIMDE_MM_PERM_ACBA
    #define _MM_PERM_ACBB SIMDE_MM_PERM_ACBB
    #define _MM_PERM_ACBC SIMDE_MM_PERM_ACBC
    #define _MM_PERM_ACBD SIMDE_MM_PERM_ACBD
    #define _MM_PERM_ACCA SIMDE_MM_PERM_ACCA
    #define _MM_PERM_ACCB SIMDE_MM_PERM_ACCB
    #define _MM_PERM_ACCC SIMDE_MM_PERM_ACCC
    #define _MM_PERM_ACCD SIMDE_MM_PERM_ACCD
    #define _MM_PERM_ACDA SIMDE_MM_PERM_ACDA
    #define _MM_PERM_ACDB SIMDE_MM_PERM_ACDB
    #define _MM_PERM_ACDC SIMDE_MM_PERM_ACDC
    #define _MM_PERM_ACDD SIMDE_MM_PERM_ACDD
    #define _MM_PERM_ADAA SIMDE_MM_PERM_ADAA
    #define _MM_PERM_ADAB SIMDE_MM_PERM_ADAB
    #define _MM_PERM_ADAC SIMDE_MM_PERM_ADAC
    #define _MM_PERM_ADAD SIMDE_MM_PERM_ADAD
    #define _MM_PERM_ADBA SIMDE_MM_PERM_ADBA
    #define _MM_PERM_ADBB SIMDE_MM_PERM_ADBB
    #define _MM_PERM_ADBC SIMDE_MM_PERM_ADBC
    #define _MM_PERM_ADBD SIMDE_MM_PERM_ADBD
    #define _MM_PERM_ADCA SIMDE_MM_PERM_ADCA
    #define _MM_PERM_ADCB SIMDE_MM_PERM_ADCB
    #define _MM_PERM_ADCC SIMDE_MM_PERM_ADCC
    #define _MM_PERM_ADCD SIMDE_MM_PERM_ADCD
    #define _MM_PERM_ADDA SIMDE_MM_PERM_ADDA
    #define _MM_PERM_ADDB SIMDE_MM_PERM_ADDB
    #define _MM_PERM_ADDC SIMDE_MM_PERM_ADDC
    #define _MM_PERM_ADDD SIMDE_MM_PERM_ADDD
    #define _MM_PERM_BAAA SIMDE_MM_PERM_BAAA
    #define _MM_PERM_BAAB SIMDE_MM_PERM_BAAB
    #define _MM_PERM_BAAC SIMDE_MM_PERM_BAAC
    #define _MM_PERM_BAAD SIMDE_MM_PERM_BAAD
    #define _MM_PERM_BABA SIMDE_MM_PERM_BABA
    #define _MM_PERM_BABB SIMDE_MM_PERM_BABB
    #define _MM_PERM_BABC SIMDE_MM_PERM_BABC
    #define _MM_PERM_BABD SIMDE_MM_PERM_BABD
    #define _MM_PERM_BACA SIMDE_MM_PERM_BACA
    #define _MM_PERM_BACB SIMDE_MM_PERM_BACB
    #define _MM_PERM_BACC SIMDE_MM_PERM_BACC
    #define _MM_PERM_BACD SIMDE_MM_PERM_BACD
    #define _MM_PERM_BADA SIMDE_MM_PERM_BADA
    #define _MM_PERM_BADB SIMDE_MM_PERM_BADB
    #define _MM_PERM_BADC SIMDE_MM_PERM_BADC
    #define _MM_PERM_BADD SIMDE_MM_PERM_BADD
    #define _MM_PERM_BBAA SIMDE_MM_PERM_BBAA
    #define _MM_PERM_BBAB SIMDE_MM_PERM_BBAB
    #define _MM_PERM_BBAC SIMDE_MM_PERM_BBAC
    #define _MM_PERM_BBAD SIMDE_MM_PERM_BBAD
    #define _MM_PERM_BBBA SIMDE_MM_PERM_BBBA
    #define _MM_PERM_BBBB SIMDE_MM_PERM_BBBB
    #define _MM_PERM_BBBC SIMDE_MM_PERM_BBBC
    #define _MM_PERM_BBBD SIMDE_MM_PERM_BBBD
    #define _MM_PERM_BBCA SIMDE_MM_PERM_BBCA
    #define _MM_PERM_BBCB SIMDE_MM_PERM_BBCB
    #define _MM_PERM_BBCC SIMDE_MM_PERM_BBCC
    #define _MM_PERM_BBCD SIMDE_MM_PERM_BBCD
    #define _MM_PERM_BBDA SIMDE_MM_PERM_BBDA
    #define _MM_PERM_BBDB SIMDE_MM_PERM_BBDB
    #define _MM_PERM_BBDC SIMDE_MM_PERM_BBDC
    #define _MM_PERM_BBDD SIMDE_MM_PERM_BBDD
    #define _MM_PERM_BCAA SIMDE_MM_PERM_BCAA
    #define _MM_PERM_BCAB SIMDE_MM_PERM_BCAB
    #define _MM_PERM_BCAC SIMDE_MM_PERM_BCAC
    #define _MM_PERM_BCAD SIMDE_MM_PERM_BCAD
    #define _MM_PERM_BCBA SIMDE_MM_PERM_BCBA
    #define _MM_PERM_BCBB SIMDE_MM_PERM_BCBB
    #define _MM_PERM_BCBC SIMDE_MM_PERM_BCBC
    #define _MM_PERM_BCBD SIMDE_MM_PERM_BCBD
    #define _MM_PERM_BCCA SIMDE_MM_PERM_BCCA
    #define _MM_PERM_BCCB SIMDE_MM_PERM_BCCB
    #define _MM_PERM_BCCC SIMDE_MM_PERM_BCCC
    #define _MM_PERM_BCCD SIMDE_MM_PERM_BCCD
    #define _MM_PERM_BCDA SIMDE_MM_PERM_BCDA
    #define _MM_PERM_BCDB SIMDE_MM_PERM_BCDB
    #define _MM_PERM_BCDC SIMDE_MM_PERM_BCDC
    #define _MM_PERM_BCDD SIMDE_MM_PERM_BCDD
    #define _MM_PERM_BDAA SIMDE_MM_PERM_BDAA
    #define _MM_PERM_BDAB SIMDE_MM_PERM_BDAB
    #define _MM_PERM_BDAC SIMDE_MM_PERM_BDAC
    #define _MM_PERM_BDAD SIMDE_MM_PERM_BDAD
    #define _MM_PERM_BDBA SIMDE_MM_PERM_BDBA
    #define _MM_PERM_BDBB SIMDE_MM_PERM_BDBB
    #define _MM_PERM_BDBC SIMDE_MM_PERM_BDBC
    #define _MM_PERM_BDBD SIMDE_MM_PERM_BDBD
    #define _MM_PERM_BDCA SIMDE_MM_PERM_BDCA
    #define _MM_PERM_BDCB SIMDE_MM_PERM_BDCB
    #define _MM_PERM_BDCC SIMDE_MM_PERM_BDCC
    #define _MM_PERM_BDCD SIMDE_MM_PERM_BDCD
    #define _MM_PERM_BDDA SIMDE_MM_PERM_BDDA
    #define _MM_PERM_BDDB SIMDE_MM_PERM_BDDB
    #define _MM_PERM_BDDC SIMDE_MM_PERM_BDDC
    #define _MM_PERM_BDDD SIMDE_MM_PERM_BDDD
    #define _MM_PERM_CAAA SIMDE_MM_PERM_CAAA
    #define _MM_PERM_CAAB SIMDE_MM_PERM_CAAB
    #define _MM_PERM_CAAC SIMDE_MM_PERM_CAAC
    #define _MM_PERM_CAAD SIMDE_MM_PERM_CAAD
    #define _MM_PERM_CABA SIMDE_MM_PERM_CABA
    #define _MM_PERM_CABB SIMDE_MM_PERM_CABB
    #define _MM_PERM_CABC SIMDE_MM_PERM_CABC
    #define _MM_PERM_CABD SIMDE_MM_PERM_CABD
    #define _MM_PERM_CACA SIMDE_MM_PERM_CACA
    #define _MM_PERM_CACB SIMDE_MM_PERM_CACB
    #define _MM_PERM_CACC SIMDE_MM_PERM_CACC
    #define _MM_PERM_CACD SIMDE_MM_PERM_CACD
    #define _MM_PERM_CADA SIMDE_MM_PERM_CADA
    #define _MM_PERM_CADB SIMDE_MM_PERM_CADB
    #define _MM_PERM_CADC SIMDE_MM_PERM_CADC
    #define _MM_PERM_CADD SIMDE_MM_PERM_CADD
    #define _MM_PERM_CBAA SIMDE_MM_PERM_CBAA
    #define _MM_PERM_CBAB SIMDE_MM_PERM_CBAB
    #define _MM_PERM_CBAC SIMDE_MM_PERM_CBAC
    #define _MM_PERM_CBAD SIMDE_MM_PERM_CBAD
    #define _MM_PERM_CBBA SIMDE_MM_PERM_CBBA
    #define _MM_PERM_CBBB SIMDE_MM_PERM_CBBB
    #define _MM_PERM_CBBC SIMDE_MM_PERM_CBBC
    #define _MM_PERM_CBBD SIMDE_MM_PERM_CBBD
    #define _MM_PERM_CBCA SIMDE_MM_PERM_CBCA
    #define _MM_PERM_CBCB SIMDE_MM_PERM_CBCB
    #define _MM_PERM_CBCC SIMDE_MM_PERM_CBCC
    #define _MM_PERM_CBCD SIMDE_MM_PERM_CBCD
    #define _MM_PERM_CBDA SIMDE_MM_PERM_CBDA
    #define _MM_PERM_CBDB SIMDE_MM_PERM_CBDB
    #define _MM_PERM_CBDC SIMDE_MM_PERM_CBDC
    #define _MM_PERM_CBDD SIMDE_MM_PERM_CBDD
    #define _MM_PERM_CCAA SIMDE_MM_PERM_CCAA
    #define _MM_PERM_CCAB SIMDE_MM_PERM_CCAB
    #define _MM_PERM_CCAC SIMDE_MM_PERM_CCAC
    #define _MM_PERM_CCAD SIMDE_MM_PERM_CCAD
    #define _MM_PERM_CCBA SIMDE_MM_PERM_CCBA
    #define _MM_PERM_CCBB SIMDE_MM_PERM_CCBB
    #define _MM_PERM_CCBC SIMDE_MM_PERM_CCBC
    #define _MM_PERM_CCBD SIMDE_MM_PERM_CCBD
    #define _MM_PERM_CCCA SIMDE_MM_PERM_CCCA
    #define _MM_PERM_CCCB SIMDE_MM_PERM_CCCB
    #define _MM_PERM_CCCC SIMDE_MM_PERM_CCCC
    #define _MM_PERM_CCCD SIMDE_MM_PERM_CCCD
    #define _MM_PERM_CCDA SIMDE_MM_PERM_CCDA
    #define _MM_PERM_CCDB SIMDE_MM_PERM_CCDB
    #define _MM_PERM_CCDC SIMDE_MM_PERM_CCDC
    #define _MM_PERM_CCDD SIMDE_MM_PERM_CCDD
    #define _MM_PERM_CDAA SIMDE_MM_PERM_CDAA
    #define _MM_PERM_CDAB SIMDE_MM_PERM_CDAB
    #define _MM_PERM_CDAC SIMDE_MM_PERM_CDAC
    #define _MM_PERM_CDAD SIMDE_MM_PERM_CDAD
    #define _MM_PERM_CDBA SIMDE_MM_PERM_CDBA
    #define _MM_PERM_CDBB SIMDE_MM_PERM_CDBB
    #define _MM_PERM_CDBC SIMDE_MM_PERM_CDBC
    #define _MM_PERM_CDBD SIMDE_MM_PERM_CDBD
    #define _MM_PERM_CDCA SIMDE_MM_PERM_CDCA
    #define _MM_PERM_CDCB SIMDE_MM_PERM_CDCB
    #define _MM_PERM_CDCC SIMDE_MM_PERM_CDCC
    #define _MM_PERM_CDCD SIMDE_MM_PERM_CDCD
    #define _MM_PERM_CDDA SIMDE_MM_PERM_CDDA
    #define _MM_PERM_CDDB SIMDE_MM_PERM_CDDB
    #define _MM_PERM_CDDC SIMDE_MM_PERM_CDDC
    #define _MM_PERM_CDDD SIMDE_MM_PERM_CDDD
    #define _MM_PERM_DAAA SIMDE_MM_PERM_DAAA
    #define _MM_PERM_DAAB SIMDE_MM_PERM_DAAB
    #define _MM_PERM_DAAC SIMDE_MM_PERM_DAAC
    #define _MM_PERM_DAAD SIMDE_MM_PERM_DAAD
    #define _MM_PERM_DABA SIMDE_MM_PERM_DABA
    #define _MM_PERM_DABB SIMDE_MM_PERM_DABB
    #define _MM_PERM_DABC SIMDE_MM_PERM_DABC
    #define _MM_PERM_DABD SIMDE_MM_PERM_DABD
    #define _MM_PERM_DACA SIMDE_MM_PERM_DACA
    #define _MM_PERM_DACB SIMDE_MM_PERM_DACB
    #define _MM_PERM_DACC SIMDE_MM_PERM_DACC
    #define _MM_PERM_DACD SIMDE_MM_PERM_DACD
    #define _MM_PERM_DADA SIMDE_MM_PERM_DADA
    #define _MM_PERM_DADB SIMDE_MM_PERM_DADB
    #define _MM_PERM_DADC SIMDE_MM_PERM_DADC
    #define _MM_PERM_DADD SIMDE_MM_PERM_DADD
    #define _MM_PERM_DBAA SIMDE_MM_PERM_DBAA
    #define _MM_PERM_DBAB SIMDE_MM_PERM_DBAB
    #define _MM_PERM_DBAC SIMDE_MM_PERM_DBAC
    #define _MM_PERM_DBAD SIMDE_MM_PERM_DBAD
    #define _MM_PERM_DBBA SIMDE_MM_PERM_DBBA
    #define _MM_PERM_DBBB SIMDE_MM_PERM_DBBB
    #define _MM_PERM_DBBC SIMDE_MM_PERM_DBBC
    #define _MM_PERM_DBBD SIMDE_MM_PERM_DBBD
    #define _MM_PERM_DBCA SIMDE_MM_PERM_DBCA
    #define _MM_PERM_DBCB SIMDE_MM_PERM_DBCB
    #define _MM_PERM_DBCC SIMDE_MM_PERM_DBCC
    #define _MM_PERM_DBCD SIMDE_MM_PERM_DBCD
    #define _MM_PERM_DBDA SIMDE_MM_PERM_DBDA
    #define _MM_PERM_DBDB SIMDE_MM_PERM_DBDB
    #define _MM_PERM_DBDC SIMDE_MM_PERM_DBDC
    #define _MM_PERM_DBDD SIMDE_MM_PERM_DBDD
    #define _MM_PERM_DCAA SIMDE_MM_PERM_DCAA
    #define _MM_PERM_DCAB SIMDE_MM_PERM_DCAB
    #define _MM_PERM_DCAC SIMDE_MM_PERM_DCAC
    #define _MM_PERM_DCAD SIMDE_MM_PERM_DCAD
    #define _MM_PERM_DCBA SIMDE_MM_PERM_DCBA
    #define _MM_PERM_DCBB SIMDE_MM_PERM_DCBB
    #define _MM_PERM_DCBC SIMDE_MM_PERM_DCBC
    #define _MM_PERM_DCBD SIMDE_MM_PERM_DCBD
    #define _MM_PERM_DCCA SIMDE_MM_PERM_DCCA
    #define _MM_PERM_DCCB SIMDE_MM_PERM_DCCB
    #define _MM_PERM_DCCC SIMDE_MM_PERM_DCCC
    #define _MM_PERM_DCCD SIMDE_MM_PERM_DCCD
    #define _MM_PERM_DCDA SIMDE_MM_PERM_DCDA
    #define _MM_PERM_DCDB SIMDE_MM_PERM_DCDB
    #define _MM_PERM_DCDC SIMDE_MM_PERM_DCDC
    #define _MM_PERM_DCDD SIMDE_MM_PERM_DCDD
    #define _MM_PERM_DDAA SIMDE_MM_PERM_DDAA
    #define _MM_PERM_DDAB SIMDE_MM_PERM_DDAB
    #define _MM_PERM_DDAC SIMDE_MM_PERM_DDAC
    #define _MM_PERM_DDAD SIMDE_MM_PERM_DDAD
    #define _MM_PERM_DDBA SIMDE_MM_PERM_DDBA
    #define _MM_PERM_DDBB SIMDE_MM_PERM_DDBB
    #define _MM_PERM_DDBC SIMDE_MM_PERM_DDBC
    #define _MM_PERM_DDBD SIMDE_MM_PERM_DDBD
    #define _MM_PERM_DDCA SIMDE_MM_PERM_DDCA
    #define _MM_PERM_DDCB SIMDE_MM_PERM_DDCB
    #define _MM_PERM_DDCC SIMDE_MM_PERM_DDCC
    #define _MM_PERM_DDCD SIMDE_MM_PERM_DDCD
    #define _MM_PERM_DDDA SIMDE_MM_PERM_DDDA
    #define _MM_PERM_DDDB SIMDE_MM_PERM_DDDB
    #define _MM_PERM_DDDC SIMDE_MM_PERM_DDDC
    #define _MM_PERM_DDDD SIMDE_MM_PERM_DDDD
    #define _MM_PERM_ENUM SIMDE_MM_PERM_ENUM
  #endif
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512
simde__m512_from_private(simde__m512_private v) {
  simde__m512 r;
  simde_memcpy(&r, &v, sizeof(r));
  return r;
}

SIMDE_FUNCTION_ATTRIBUTES
simde__m512_private
simde__m512_to_private(simde__m512 v) {
  simde__m512_private r;
  simde_memcpy(&r, &v, sizeof(r));
  return r;
}

SIMDE_FUNCTION_ATTRIBUTES
simde__m512i
simde__m512i_from_private(simde__m512i_private v) {
  simde__m512i r;
  simde_memcpy(&r, &v, sizeof(r));
  return r;
}

SIMDE_FUNCTION_ATTRIBUTES
simde__m512i_private
simde__m512i_to_private(simde__m512i v) {
  simde__m512i_private r;
  simde_memcpy(&r, &v, sizeof(r));
  return r;
}

SIMDE_FUNCTION_ATTRIBUTES
simde__m512d
simde__m512d_from_private(simde__m512d_private v) {
  simde__m512d r;
  simde_memcpy(&r, &v, sizeof(r));
  return r;
}

SIMDE_FUNCTION_ATTRIBUTES
simde__m512d_private
simde__m512d_to_private(simde__m512d v) {
  simde__m512d_private r;
  simde_memcpy(&r, &v, sizeof(r));
  return r;
}

SIMDE_END_DECLS_
HEDLEY_DIAGNOSTIC_POP

#endif /* !defined(SIMDE_X86_AVX512_TYPES_H) */
