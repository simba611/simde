#if !defined(SIMDE_X86_AVX512_FIXUPIMM_H)
#define SIMDE_X86_AVX512_FIXUPIMM_H

#include "types.h"
#include "flushsubnormal.h"
#include "mov.h"

HEDLEY_DIAGNOSTIC_PUSH
SIMDE_DISABLE_UNWANTED_DIAGNOSTICS
SIMDE_BEGIN_DECLS_

SIMDE_FUNCTION_ATTRIBUTES
simde__m128
simde_mm_fixupimm_ps (simde__m128 a, simde__m128 b, simde__m128i c, int imm8)
    SIMDE_REQUIRE_CONSTANT_RANGE(imm8, 0, 255) {
  HEDLEY_STATIC_CAST(void, imm8);
  simde__m128_private
    r_,
    a_ = simde__m128_to_private(a),
    b_ = simde__m128_to_private(b),
    s_ = simde__m128_to_private(simde_x_mm_flushsubnormal_ps(b));
  simde__m128i_private c_ = simde__m128i_to_private(c);

  SIMDE_VECTORIZE
  for (size_t i = 0 ; i < (sizeof(r_.f32) / sizeof(r_.f32[0])) ; i++) {
    int32_t select;
    #if defined(fpclassify)
      switch(fpclassify(s_.f32[i])) {
        case FP_NORMAL:
          select = ((s_.f32[i] == SIMDE_FLOAT32_C(1.0)) ? 3 : ((s_.f32[i] > 0) ? 7 : 6));
          break;
        case FP_ZERO:
          select = 2;
          break;
        case FP_NAN:
          select = 0;
          break;
        case FP_INFINITE:
          select = ((s_.f32[i] > 0) ? 5 : 4);
          break;
      }
    #elif SIMDE_MATH_BUILTIN_LIBM(fpclassify) && (!defined(__clang__) || SIMDE_DETECT_CLANG_VERSION_CHECK(5, 0, 0))
      int check =
        (__builtin_fpclassify(1, 0, 0, 0, 0, s_.f32[i])     ) |
        (__builtin_fpclassify(0, 1, 0, 0, 0, s_.f32[i]) << 1) |
        (__builtin_fpclassify(0, 0, 1, 0, 0, s_.f32[i]) << 2) |
        (__builtin_fpclassify(0, 0, 0, 0, 1, s_.f32[i]) << 3);
      switch(check) {
        case 4:
          select = ((s_.f32[i] == SIMDE_FLOAT32_C(1.0)) ? 3 : ((s_.f32[i] > 0) ? 7 : 6));
          break;
        case 8:
          select = 2;
          break;
        case 1:
          select = 0;
          break;
        case 2:
          select = ((s_.f32[i] > 0) ? 5 : 4);
          break;
      }
    #else
      if (simde_math_isnanf(s_.f32[i]))
        select = 0;
      else if (s_.f32[i] ==  SIMDE_FLOAT32_C(1.0))
        select = 3;
      else if (s_.f32[i] == -SIMDE_MATH_INFINITYF)
        select = 4;
      else if (s_.f32[i] ==  SIMDE_MATH_INFINITYF)
        select = 5;
      else if (s_.f32[i]  <  0)
        select = 6;
      else if (s_.f32[i]  >  0)
        select = 7;
      else if (s_.f32[i] ==  SIMDE_FLOAT32_C(0.0))
        select = 2;
      else
        select = 1;
    #endif

    switch (((c_.i32[i] >> (select << 2)) & 15)) {
      case 0:
        r_.f32[i] =  a_.f32[i];
        break;
      case 1:
        r_.f32[i] =  b_.f32[i];
        break;
      case 2:
        r_.f32[i] =  SIMDE_MATH_NANF;
        break;
      case 3:
        r_.f32[i] = -SIMDE_MATH_NANF;
        break;
      case 4:
        r_.f32[i] = -SIMDE_MATH_INFINITYF;
        break;
      case 5:
        r_.f32[i] =  SIMDE_MATH_INFINITYF;
        break;
      case 6:
      #if defined(simde_math_copysignf)
        r_.f32[i] =  simde_math_copysignf(SIMDE_MATH_INFINITYF, s_.f32[i]);
      #else
        r_.f32[i] =  simde_uint32_as_float32((simde_float32_as_uint32(s_.f32[i]) & 0x80000000) | simde_float32_as_uint32(SIMDE_MATH_INFINITYF));
      #endif
        break;
      case 7:
        r_.f32[i] =  SIMDE_FLOAT32_C(-0.0);
        break;
      case 8:
        r_.f32[i] =  SIMDE_FLOAT32_C(0.0);
        break;
      case 9:
        r_.f32[i] =  SIMDE_FLOAT32_C(-1.0);
        break;
      case 10:
        r_.f32[i] =  SIMDE_FLOAT32_C(1.0);
        break;
      case 11:
        r_.f32[i] =  SIMDE_FLOAT32_C(0.5);
        break;
      case 12:
        r_.f32[i] =  SIMDE_FLOAT32_C(90.0);
        break;
      case 13:
        r_.f32[i] =  SIMDE_MATH_PIF / 2;
        break;
      case 14:
        r_.f32[i] =  SIMDE_MATH_FLT_MAX;
        break;
      case 15:
        r_.f32[i] = -SIMDE_MATH_FLT_MAX;
        break;
    }
  }

  return simde__m128_from_private(r_);
}
#if defined(SIMDE_X86_AVX512F_NATIVE) && defined(SIMDE_X86_AVX512VL_NATIVE)
  #define simde_mm_fixupimm_ps(a, b, c, imm8) _mm_fixupimm_ps(a, b, c, imm8)
#endif
#if defined(SIMDE_X86_AVX512F_ENABLE_NATIVE_ALIASES) && defined(SIMDE_X86_AVX512VL_ENABLE_NATIVE_ALIASES)
  #undef _mm_fixupimm_ps
  #define _mm_fixupimm_ps(a, b, c, imm8) simde_mm_fixupimm_ps(a, b, c, imm8)
#endif

#if defined(SIMDE_X86_AVX512F_NATIVE) && defined(SIMDE_X86_AVX512VL_NATIVE)
  #define simde_mm_mask_fixupimm_ps(a, k, b, c, imm8) _mm_mask_fixupimm_ps(a, k, b, c, imm8)
#else
  #define simde_mm_mask_fixupimm_ps(a, k, b, c, imm8) simde_mm_mask_mov_ps(a, k, simde_mm_fixupimm_ps(a, b, c, imm8))
#endif
#if defined(SIMDE_X86_AVX512F_ENABLE_NATIVE_ALIASES) && defined(SIMDE_X86_AVX512VL_ENABLE_NATIVE_ALIASES)
  #undef _mm_mask_fixupimm_ps
  #define _mm_mask_fixupimm_ps(a, k, b, c, imm8) simde_mm_mask_fixupimm_ps(a, k, b, c, imm8)
#endif

#if defined(SIMDE_X86_AVX512F_NATIVE) && defined(SIMDE_X86_AVX512VL_NATIVE)
  #define simde_mm_maskz_fixupimm_ps(k, a, b, c, imm8) _mm_maskz_fixupimm_ps(k, a, b, c, imm8)
#else
  #define simde_mm_maskz_fixupimm_ps(k, a, b, c, imm8) simde_mm_maskz_mov_ps(k, simde_mm_fixupimm_ps(a, b, c, imm8))
#endif
#if defined(SIMDE_X86_AVX512F_ENABLE_NATIVE_ALIASES) && defined(SIMDE_X86_AVX512VL_ENABLE_NATIVE_ALIASES)
  #undef _mm_maskz_fixupimm_ps
  #define _mm_maskz_fixupimm_ps(k, a, b, c, imm8) simde_mm_mask_fixupimm_ps(k, a, b, c, imm8)
#endif

SIMDE_END_DECLS_
HEDLEY_DIAGNOSTIC_POP

#endif /* !defined(SIMDE_X86_AVX512_FIXUPIMM_H) */
