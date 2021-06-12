#if !defined(SIMDE_X86_AVX512_SHLDV_H)
#define SIMDE_X86_AVX512_SHLDV_H

#include "types.h"
#include "../avx2.h"

HEDLEY_DIAGNOSTIC_PUSH
SIMDE_DISABLE_UNWANTED_DIAGNOSTICS
SIMDE_BEGIN_DECLS_

SIMDE_FUNCTION_ATTRIBUTES
simde__m128i
simde_mm_shldv_epi32(simde__m128i a, simde__m128i b, simde__m128i c) {
  #if defined(SIMDE_X86_AVX512VBMI2_NATIVE) && defined(SIMDE_X86_AVX512VL_NATIVE)
    return _mm_shldv_epi32(a, b, c);
  #else
    simde__m128i_private
      r_,
      a_ = simde__m128i_to_private(a),
      b_ = simde__m128i_to_private(b),
      c_ = simde__m128i_to_private(c);

    simde__m256i_private tmp;

    #if defined(SIMDE_SHUFFLE_VECTOR_)
      HEDLEY_STATIC_CAST(void, c_);
      tmp.i32 = SIMDE_SHUFFLE_VECTOR_(32, 32, b_.i32, a_.i32, 0, 4, 1, 5, 2, 6, 3, 7);

      SIMDE_VECTORIZE
      for (size_t i = 0 ; i < (sizeof(tmp.u64) / sizeof(tmp.u64[0])) ; i++) {
          tmp.u64[i] = tmp.u64[i] << (c_.u32[i] & 31);
      }

      r_.i32 = SIMDE_SHUFFLE_VECTOR_(32, 16, tmp.i32, tmp.i32, 1, 3, 5, 7);
    #else
      SIMDE_VECTORIZE
      for (size_t i = 0 ; i < (sizeof(r_.u32) / sizeof(r_.u32[0])) ; i++) {
        r_.u32[i] = HEDLEY_STATIC_CAST(int32_t, (((HEDLEY_STATIC_CAST(int64_t, a_.u32[i]) << 32) | b_.u32[i]) << (c_.u32[i] & 31)) >> 32);
      }
    #endif

    return simde__m128i_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_AVX512VBMI2_ENABLE_NATIVE_ALIASES) && defined(SIMDE_X86_AVX512VL_ENABLE_NATIVE_ALIASES)
  #undef _mm_shldv_epi32
  #define _mm_shldv_epi32(a, b, c) simde_mm_shldv_epi32(a, b, c)
#endif

SIMDE_END_DECLS_
HEDLEY_DIAGNOSTIC_POP

#endif /* !defined(SIMDE_X86_AVX512_SHLDV_H) */
