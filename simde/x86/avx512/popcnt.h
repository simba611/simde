#if !defined(SIMDE_X86_AVX512_POPCNT_H)
#define SIMDE_X86_AVX512_POPCNT_H

#include "types.h"

HEDLEY_DIAGNOSTIC_PUSH
SIMDE_DISABLE_UNWANTED_DIAGNOSTICS
SIMDE_BEGIN_DECLS_

SIMDE_FUNCTION_ATTRIBUTES
simde__m128i
simde_mm_popcnt_epi8 (simde__m128i a) {
  #if defined(SIMDE_X86_AVX512BITALG_NATIVE) && defined(SIMDE_X86_AVX512VL_NATIVE)
    return _mm_popcnt_epi8(a);
  #else
    simde__m128i_private
      r_,
      a_ = simde__m128i_to_private(a);

    #if defined(SIMDE_ARM_NEON_A32V7_NATIVE)
      r_.neon_i8 = vcntq_s8(a_.neon_i8);
    #elif defined(SIMDE_WASM_SIMD128_NATIVE)
      r_.wasm_v128 = wasm_i8x16_popcnt(a_.wasm_v128);
    #elif defined(SIMDE_X86_SSSE3_NATIVE)
      const __m128i low_nibble_set = _mm_set1_epi8(0x0f);
      const __m128i high_nibble_of_input = _mm_andnot_si128(low_nibble_set, a_.n);
      const __m128i low_nibble_of_input = _mm_and_si128(low_nibble_set, a_.n);
      const __m128i lut = _mm_set_epi8(4, 3, 3, 2, 3, 2, 2, 1, 3, 2, 2, 1, 2, 1, 1, 0);

      r_.n =
        _mm_add_epi8(
          _mm_shuffle_epi8(
            lut,
            low_nibble_of_input
          ),
          _mm_shuffle_epi8(
            lut,
            _mm_srli_epi16(
              high_nibble_of_input,
              4
            )
          )
        );
    #elif defined(SIMDE_X86_SSE2_NATIVE)
      /* v -= ((v >> 1) & 0x55); */
      r_.n =
        _mm_sub_epi8(
          a_.n,
          _mm_and_si128(
            _mm_srli_epi16(a_.n, 1),
            _mm_set1_epi8(0x55)
          )
        );

      /* v  = (v & 0x33) + ((v >> 2) & 0x33); */
      r_.n =
        _mm_add_epi8(
          _mm_and_si128(
            r_.n,
            _mm_set1_epi8(0x33)
          ),
          _mm_and_si128(
            _mm_srli_epi16(r_.n, 2),
            _mm_set1_epi8(0x33)
          )
        );

      /* v = (v + (v >> 4)) & 0xf */
      r_.n =
        _mm_and_si128(
          _mm_add_epi8(
            r_.n,
            _mm_srli_epi16(r_.n, 4)
          ),
          _mm_set1_epi8(0x0f)
        );
    #elif defined(SIMDE_POWER_ALTIVEC_P8_NATIVE)
      r_.altivec_i8 = HEDLEY_REINTERPRET_CAST(SIMDE_POWER_ALTIVEC_VECTOR(signed char), vec_popcnt(HEDLEY_REINTERPRET_CAST(SIMDE_POWER_ALTIVEC_VECTOR(unsigned char), a_.altivec_i8)));
    #elif defined(SIMDE_VECTOR_SUBSCRIPT_SCALAR)
      a_.u8 -= ((a_.u8 >> 1) & 0x55);
      a_.u8  = ((a_.u8 & 0x33) + ((a_.u8 >> 2) & 0x33));
      a_.u8  = (a_.u8 + (a_.u8 >> 4)) & 15;
      r_.u8  = a_.u8 >> ((sizeof(uint8_t) - 1) * CHAR_BIT);
    #else
      SIMDE_VECTORIZE
      for (size_t i = 0 ; i < (sizeof(r_.u8) / sizeof(r_.u8[0])) ; i++) {
        uint8_t v = HEDLEY_STATIC_CAST(uint8_t, a_.u8[i]);
        v -= ((v >> 1) & 0x55);
        v  = (v & 0x33) + ((v >> 2) & 0x33);
        v  = (v + (v >> 4)) & 0xf;
        r_.u8[i] = v >> (sizeof(uint8_t) - 1) * CHAR_BIT;
      }
    #endif

    return simde__m128i_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_AVX512BITALG_ENABLE_NATIVE_ALIASES) && defined(SIMDE_X86_AVX512VL_ENABLE_NATIVE_ALIASES)
  #undef _mm_popcnt_epi8
  #define _mm_popcnt_epi8(a) simde_mm_popcnt_epi8(a)
#endif

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
      r_.neon_i16 = vpaddlq_s8(vcntq_s8(a_.neon_i8));
    #elif defined(SIMDE_WASM_SIMD128_NATIVE)
      r_.wasm_v128 = wasm_i16x8_extadd_pairwise_i8x16(wasm_i8x16_popcnt(a_.wasm_v128));
    #elif defined(SIMDE_POWER_ALTIVEC_P8_NATIVE)
      r_.altivec_u16 = HEDLEY_REINTERPRET_CAST(SIMDE_POWER_ALTIVEC_VECTOR(unsigned short), vec_popcnt(HEDLEY_REINTERPRET_CAST(SIMDE_POWER_ALTIVEC_VECTOR(unsigned short), a_.altivec_u16)));
    #elif defined(SIMDE_X86_XOP_NATIVE)
      const __m128i low_nibble_set = _mm_set1_epi8(0x0f);
      const __m128i high_nibble_of_input = _mm_andnot_si128(low_nibble_set, a_.n);
      const __m128i low_nibble_of_input = _mm_and_si128(low_nibble_set, a_.n);
      const __m128i lut = _mm_set_epi8(4, 3, 3, 2, 3, 2, 2, 1, 3, 2, 2, 1, 2, 1, 1, 0);

      r_.n =
        _mm_haddw_epi8(
          _mm_add_epi8(
            _mm_shuffle_epi8(
              lut,
              low_nibble_of_input
            ),
            _mm_shuffle_epi8(
              lut,
              _mm_srli_epi16(
                high_nibble_of_input,
                4
              )
            )
          );
        )
    #elif defined(SIMDE_VECTOR_SUBSCRIPT_SCALAR)
      a_.u16 -= ((a_.u16 >> 1) & 0x5555);
      a_.u16  = ((a_.u16 & 0x3333) + ((a_.u16 >> 2) & 0x3333));
      a_.u16  = (a_.u16 + (a_.u16 >> 4)) & 0x0f0f;
      r_.u16  = (a_.u16 * 0x0101) >> ((sizeof(uint16_t) - 1) * CHAR_BIT);
    #else
      SIMDE_VECTORIZE
      for (size_t i = 0 ; i < (sizeof(r_.u16) / sizeof(r_.u16[0])) ; i++) {
        uint16_t v = HEDLEY_STATIC_CAST(uint16_t, a_.u16[i]);
        v -= ((v >> 1) & 0x5555);
        v  = ((v & 0x3333) + ((v >> 2) & 0x3333));
        v  = (v + (v >> 4)) & 0x0f0f;
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
