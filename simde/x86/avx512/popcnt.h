#if !defined(SIMDE_X86_AVX512_POPCNT_H)
#define SIMDE_X86_AVX512_POPCNT_H

#include "types.h"

HEDLEY_DIAGNOSTIC_PUSH
SIMDE_DISABLE_UNWANTED_DIAGNOSTICS
SIMDE_BEGIN_DECLS_

SIMDE_FUNCTION_ATTRIBUTES
simde__m128i
simde_mm_popcnt_epi16 (simde__m128i a) {
  #if defined(SIMDE_X86_AVX512BITALG_NATIVE) && defined(SIMDE_X86_AVX512VL_NATIVE)
    return _mm_popcnt_epi16(a);
  #else
    simde__m128i_private
      r_,
      a_ = simde__m128i_to_private(a);

    #if defined(SIMDE_ARM_NEON_A32V7_NATIVE)
      r_.neon_i16 = simde_vpaddlq_s8(simde_vcntq_s8(a_.neon_i8));
    #elif defined(SIMDE_WASM_SIMD128_NATIVE)
      r_.wasm_v128 = simde_wasm_i16x8_extadd_pairwise_i8x16(simde_wasm_i8x16_popcnt(a_.wasm_v128));
    #elif defined(SIMDE_VECTOR_SUBSCRIPT_SCALAR)
      a_.u16 -= ((a_.u16 >> 1) & 0x5555);
      a_.u16  = ((a_.u16 & 0x3333) + ((a_.u16 >> 2) & 0x3333));
      a_.u16  = (a_.u16 + (a_.u16 >> 4)) & 0x0F0F;
      r_.u16  = (a_.u16 * 0x0101) >> ((sizeof(uint16_t) - 1) * CHAR_BIT);
    #elif defined(SIMDE_POWER_ALTIVEC_P8_NATIVE)
      r_.altivec_u16 = HEDLEY_REINTERPRET_CAST(SIMDE_POWER_ALTIVEC_VECTOR(unsigned short), vec_popcnt(HEDLEY_REINTERPRET_CAST(SIMDE_POWER_ALTIVEC_VECTOR(unsigned short), a_.altivec_u16)));
    #else
      SIMDE_VECTORIZE
      for (size_t i = 0 ; i < (sizeof(r_.u16) / sizeof(r_.u16[0])) ; i++) {
        uint16_t v = HEDLEY_STATIC_CAST(uint16_t, a_.u16[i]);
        v -= ((v >> 1) & 0x5555);
        v  = ((v & 0x3333) + ((v >> 2) & 0x3333));
        v  = (v + (v >> 4)) & 0x0F0F;
        r_.u16[i] = HEDLEY_STATIC_CAST(uint16_t, (v * 0x0101)) >> ((sizeof(uint16_t) - 1) * CHAR_BIT);
      }
    #endif

    return simde__m128i_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_AVX512BITALG_ENABLE_NATIVE_ALIASES) && defined(SIMDE_X86_AVX512VL_ENABLE_NATIVE_ALIASES)
  #undef _mm_popcnt_epi16
  #define _mm_popcnt_epi16(a) simde_mm_popcnt_epi16(a)
#endif

SIMDE_END_DECLS_
HEDLEY_DIAGNOSTIC_POP

#endif /* !defined(SIMDE_X86_AVX512_POPCNT_H) */
