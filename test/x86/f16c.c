/* Copyright (c) 2020 Evan Nemerson <evan@nemerson.com>
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
 */

#define SIMDE_TESTS_CURRENT_ISAX f16c
#include <simde/x86/f16c.h>
#include <test/x86/test-avx.h>

static int
test_simde_mm_cvtps_ph (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const simde_float32 a[4];
    const int16_t r[8];
  } test_vec[] = {
    { { SIMDE_FLOAT32_C(  -922.45), SIMDE_FLOAT32_C(  -417.52), SIMDE_FLOAT32_C(   576.56), SIMDE_FLOAT32_C(   -16.40) },
      { -INT16_C(  7371), -INT16_C(  8570),  INT16_C( 24705), -INT16_C( 13286),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0) } },
    { { SIMDE_FLOAT32_C(  -847.35), SIMDE_FLOAT32_C(  -868.69), SIMDE_FLOAT32_C(   190.03), SIMDE_FLOAT32_C(  -263.75) },
      { -INT16_C(  7521), -INT16_C(  7479),  INT16_C( 23024), -INT16_C(  9185),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0) } },
    { { SIMDE_FLOAT32_C(   550.95), SIMDE_FLOAT32_C(   691.22), SIMDE_FLOAT32_C(   972.58), SIMDE_FLOAT32_C(   645.93) },
      {  INT16_C( 24654),  INT16_C( 24934),  INT16_C( 25497),  INT16_C( 24844),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0) } },
    { { SIMDE_FLOAT32_C(  -961.75), SIMDE_FLOAT32_C(   626.33), SIMDE_FLOAT32_C(   597.48), SIMDE_FLOAT32_C(   793.15) },
      { -INT16_C(  7292),  INT16_C( 24805),  INT16_C( 24747),  INT16_C( 25138),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0) } },
    { { SIMDE_FLOAT32_C(  -582.37), SIMDE_FLOAT32_C(  -225.09), SIMDE_FLOAT32_C(   -65.32), SIMDE_FLOAT32_C(   452.55) },
      { -INT16_C(  8051), -INT16_C(  9463), -INT16_C( 11243),  INT16_C( 24338),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0) } },
    { { SIMDE_FLOAT32_C(   125.78), SIMDE_FLOAT32_C(  -683.39), SIMDE_FLOAT32_C(  -348.27), SIMDE_FLOAT32_C(  -309.07) },
      {  INT16_C( 22492), -INT16_C(  7849), -INT16_C(  8847), -INT16_C(  9004),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0) } },
    { { SIMDE_FLOAT32_C(  -141.60), SIMDE_FLOAT32_C(   503.26), SIMDE_FLOAT32_C(  -451.69), SIMDE_FLOAT32_C(  -298.51) },
      { -INT16_C( 10131),  INT16_C( 24541), -INT16_C(  8433), -INT16_C(  9046),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0) } },
    { { SIMDE_FLOAT32_C(   899.79), SIMDE_FLOAT32_C(   611.12), SIMDE_FLOAT32_C(  -363.24), SIMDE_FLOAT32_C(   977.33) },
      {  INT16_C( 25352),  INT16_C( 24774), -INT16_C(  8787),  INT16_C( 25507),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m128 a = simde_mm_loadu_ps(test_vec[i].a);
    simde__m128i r = simde_mm_cvtps_ph(a, SIMDE_MM_FROUND_NO_EXC);
    simde_test_x86_assert_equal_i16x8(r, simde_x_mm_loadu_epi16(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m128 a = simde_test_x86_random_f32x4(-1000.0f, 1000.0f);
    simde__m128i r = simde_mm_cvtps_ph(a, SIMDE_MM_FROUND_NO_EXC);

    simde_test_x86_write_f32x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i16x8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm_cvtph_ps (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const uint16_t a[8];
    const simde_float32 r[4];
  } test_vec[] = {
    { { UINT16_C(57665), UINT16_C(57418), UINT16_C(25491), UINT16_C(23593), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0) },
      { SIMDE_FLOAT32_C(  -672.50), SIMDE_FLOAT32_C(  -549.00), SIMDE_FLOAT32_C(   969.50), SIMDE_FLOAT32_C(   266.25) } },
    { { UINT16_C(24529), UINT16_C(25120), UINT16_C(57577), UINT16_C(55544), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0) },
      { SIMDE_FLOAT32_C(   500.25), SIMDE_FLOAT32_C(   784.00), SIMDE_FLOAT32_C(  -628.50), SIMDE_FLOAT32_C(  -159.00) } },
    { { UINT16_C(56338), UINT16_C(24788), UINT16_C(58146), UINT16_C(25256), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0) },
      { SIMDE_FLOAT32_C(  -260.50), SIMDE_FLOAT32_C(   618.00), SIMDE_FLOAT32_C(  -913.00), SIMDE_FLOAT32_C(   852.00) } },
    { { UINT16_C(25457), UINT16_C(24637), UINT16_C(23890), UINT16_C(56982), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0) },
      { SIMDE_FLOAT32_C(   952.50), SIMDE_FLOAT32_C(   542.50), SIMDE_FLOAT32_C(   340.50), SIMDE_FLOAT32_C(  -421.50) } },
    { { UINT16_C(22950), UINT16_C(21640), UINT16_C(54779), UINT16_C(22774), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0) },
      { SIMDE_FLOAT32_C(   180.75), SIMDE_FLOAT32_C(    72.50), SIMDE_FLOAT32_C(   -95.69), SIMDE_FLOAT32_C(   158.75) } },
    { { UINT16_C(24293), UINT16_C(55275), UINT16_C(56350), UINT16_C(24325), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0) },
      { SIMDE_FLOAT32_C(   441.25), SIMDE_FLOAT32_C(  -126.69), SIMDE_FLOAT32_C(  -263.50), SIMDE_FLOAT32_C(   449.25) } },
    { { UINT16_C(22402), UINT16_C(24502), UINT16_C(57033), UINT16_C(56678), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0) },
      { SIMDE_FLOAT32_C(   120.12), SIMDE_FLOAT32_C(   493.50), SIMDE_FLOAT32_C(  -434.25), SIMDE_FLOAT32_C(  -345.50) } },
    { { UINT16_C(57623), UINT16_C(22385), UINT16_C(56989), UINT16_C(56592), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0) },
      { SIMDE_FLOAT32_C(  -651.50), SIMDE_FLOAT32_C(   119.06), SIMDE_FLOAT32_C(  -423.25), SIMDE_FLOAT32_C(  -324.00) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m128i a = simde_mm_loadu_si128(test_vec[i].a);
    simde__m128 r = simde_mm_cvtph_ps(a);
    simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[i].r), 1);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m128i a = simde_mm_cvtps_ph(simde_test_x86_random_f32x4(SIMDE_FLOAT32_C(-1000.0), SIMDE_FLOAT32_C(1000.0)), SIMDE_MM_FROUND_NO_EXC);
    simde__m128 r = simde_mm_cvtph_ps(a);

    simde_test_x86_write_u16x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_f32x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm_f16c_round_trip (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const simde_float32 a[4];
    const simde_float32 r[4];
  } test_vec[] = {
    #if !defined(SIMDE_FAST_NANS)
    { {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(  -423.73),            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(   160.78) },
      {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(  -423.73),            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(   160.78) } },
    #endif
    { { SIMDE_FLOAT32_C(  -981.67), SIMDE_FLOAT32_C(   318.53), SIMDE_FLOAT32_C(  -890.10), SIMDE_FLOAT32_C(   443.08) },
      { SIMDE_FLOAT32_C(  -981.67), SIMDE_FLOAT32_C(   318.53), SIMDE_FLOAT32_C(  -890.10), SIMDE_FLOAT32_C(   443.08) } },
    { { SIMDE_FLOAT32_C(  -316.07), SIMDE_FLOAT32_C(   436.20), SIMDE_FLOAT32_C(   506.18), SIMDE_FLOAT32_C(   324.31) },
      { SIMDE_FLOAT32_C(  -316.07), SIMDE_FLOAT32_C(   436.20), SIMDE_FLOAT32_C(   506.18), SIMDE_FLOAT32_C(   324.31) } },
    { { SIMDE_FLOAT32_C(  -232.13), SIMDE_FLOAT32_C(   547.61), SIMDE_FLOAT32_C(   521.27), SIMDE_FLOAT32_C(  -153.90) },
      { SIMDE_FLOAT32_C(  -232.13), SIMDE_FLOAT32_C(   547.61), SIMDE_FLOAT32_C(   521.27), SIMDE_FLOAT32_C(  -153.90) } },
    { { SIMDE_FLOAT32_C(   819.91), SIMDE_FLOAT32_C(   215.00), SIMDE_FLOAT32_C(   715.88), SIMDE_FLOAT32_C(   525.54) },
      { SIMDE_FLOAT32_C(   819.91), SIMDE_FLOAT32_C(   215.00), SIMDE_FLOAT32_C(   715.88), SIMDE_FLOAT32_C(   525.54) } },
    { { SIMDE_FLOAT32_C(  -199.45), SIMDE_FLOAT32_C(  -914.59), SIMDE_FLOAT32_C(  -600.24), SIMDE_FLOAT32_C(  -579.28) },
      { SIMDE_FLOAT32_C(  -199.45), SIMDE_FLOAT32_C(  -914.59), SIMDE_FLOAT32_C(  -600.24), SIMDE_FLOAT32_C(  -579.28) } },
    { { SIMDE_FLOAT32_C(   950.34), SIMDE_FLOAT32_C(   142.00), SIMDE_FLOAT32_C(  -931.01), SIMDE_FLOAT32_C(   915.71) },
      { SIMDE_FLOAT32_C(   950.34), SIMDE_FLOAT32_C(   142.00), SIMDE_FLOAT32_C(  -931.01), SIMDE_FLOAT32_C(   915.71) } },
    { { SIMDE_FLOAT32_C(  -390.34), SIMDE_FLOAT32_C(   580.78), SIMDE_FLOAT32_C(  -866.48), SIMDE_FLOAT32_C(  -588.08) },
      { SIMDE_FLOAT32_C(  -390.34), SIMDE_FLOAT32_C(   580.78), SIMDE_FLOAT32_C(  -866.48), SIMDE_FLOAT32_C(  -588.08) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m128 a = simde_mm_loadu_ps(test_vec[i].a);
    simde__m128 r = simde_mm_cvtph_ps(simde_mm_cvtps_ph(a, SIMDE_MM_FROUND_NO_EXC));
    simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[i].r), 0);
  }

  return 0;
#else
  fputc('\n', stdout);
  simde_float32 values[8 * 2 * sizeof(simde__m128)];
  simde_test_x86_random_f32x4_full(8, 2, values, -1000.0f, 1000.0f, SIMDE_TEST_VEC_FLOAT_NAN);

  for (size_t i = 0 ; i < 8 ; i++) {
    simde__m128 a = simde_test_x86_random_extract_f32x4(i, 2, 0, values);
    simde__m128 r = a; // simde_mm_cvtph_ps(simde_mm_cvtps_ph(a, SIMDE_MM_FROUND_NO_EXC));

    simde_test_x86_write_f32x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_f32x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

SIMDE_TEST_FUNC_LIST_BEGIN
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_cvtps_ph)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_cvtph_ps)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_f16c_round_trip)
SIMDE_TEST_FUNC_LIST_END

#include <test/x86/test-x86-footer.h>
