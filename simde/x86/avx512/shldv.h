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
      c_ = simde__m128i_to_private(c);

    #if defined(SIMDE_SHUFFLE_VECTOR_) && SIMDE_NATURAL_VECTOR_SIZE_GE(256)
      simde__m256i_private
        tmp,
        a_ = simde__m256i_to_private(simde_mm256_castsi128_si256(a)),
        b_ = simde__m256i_to_private(simde_mm256_castsi128_si256(b));

      tmp.u64 = HEDLEY_REINTERPRET_CAST(__typeof__(tmp.u64), SIMDE_SHUFFLE_VECTOR_(32, 32, b_.i32, a_.i32, 0, 8, 1, 9, 2, 10, 3, 11));

      SIMDE_VECTORIZE
      for (size_t i = 0 ; i < (sizeof(tmp.u64) / sizeof(tmp.u64[0])) ; i++) {
        tmp.u64[i] = tmp.u64[i] << (c_.u32[i] & 31);
      }

      tmp.i32 = SIMDE_SHUFFLE_VECTOR_(32, 32, tmp.i32, tmp.i32, 1, 3, 5, 7, -1, -1, -1, -1);
      r_ = simde__m128i_to_private(simde_mm256_castsi256_si128(simde__m256i_from_private(tmp)));
    #elif SIMDE_NATURAL_VECTOR_SIZE_LE(128)
      simde__m128i_private
        lo,
        hi;

      lo = simde__m128i_to_private(simde_mm_unpacklo_epi32(b, a));
      hi = simde__m128i_to_private(simde_mm_unpackhi_epi32(b, a));

      size_t halfway = (sizeof(r_.u32) / sizeof(r_.u32[0]) / 2);
      SIMDE_VECTORIZE
      for (size_t i = 0 ; i < halfway ; i++) {
        lo.u64[i] = lo.u64[i] << (c_.u32[i] & 31);
        hi.u64[i] = hi.u64[i] << (c_.u32[halfway + i] & 31);
      }

      r_ = simde__m128i_to_private(simde_mm_castps_si128(simde_mm_shuffle_ps(simde_mm_castsi128_ps(simde__m128i_from_private(lo)), simde_mm_castsi128_ps(simde__m128i_from_private(hi)), 221)));
    #else
      simde__m128i_private
        a_ = simde__m128i_to_private(a),
        b_ = simde__m128i_to_private(b);

      SIMDE_VECTORIZE
      for (size_t i = 0 ; i < (sizeof(r_.u32) / sizeof(r_.u32[0])) ; i++) {
        r_.u32[i] = HEDLEY_STATIC_CAST(uint32_t, (((HEDLEY_STATIC_CAST(uint64_t, a_.u32[i]) << 32) | b_.u32[i]) << (c_.u32[i] & 31)) >> 32);
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
