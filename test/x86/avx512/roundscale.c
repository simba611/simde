#define SIMDE_TEST_X86_AVX512_INSN roundscale

#include <test/x86/avx512/test-avx512.h>
#include <simde/x86/avx512/roundscale.h>
#include <simde/x86/avx512/setzero.h>

static int
test_simde_mm_roundscale_ps (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const simde_float32 a[4];
    const int32_t imm8;
    const simde_float32 r[4];
  } test_vec[] = {
    { { SIMDE_FLOAT32_C(   184.58), SIMDE_FLOAT32_C(  -477.45), SIMDE_FLOAT32_C(  -816.99), SIMDE_FLOAT32_C(  -969.27) },
       INT32_C(           0),
      { SIMDE_FLOAT32_C(   185.00), SIMDE_FLOAT32_C(  -477.00), SIMDE_FLOAT32_C(  -817.00), SIMDE_FLOAT32_C(  -969.00) } },
    { { SIMDE_FLOAT32_C(  -630.66), SIMDE_FLOAT32_C(  -650.78), SIMDE_FLOAT32_C(   424.73), SIMDE_FLOAT32_C(  -953.66) },
       INT32_C(          16),
      { SIMDE_FLOAT32_C(  -630.50), SIMDE_FLOAT32_C(  -651.00), SIMDE_FLOAT32_C(   424.50), SIMDE_FLOAT32_C(  -953.50) } },
    { {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(    49.10), SIMDE_FLOAT32_C(   398.66), SIMDE_FLOAT32_C(   620.43) },
       INT32_C(          32),
      {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(    49.00), SIMDE_FLOAT32_C(   398.75), SIMDE_FLOAT32_C(   620.50) } },
    { { SIMDE_FLOAT32_C(   -29.44), SIMDE_FLOAT32_C(  -399.88), SIMDE_FLOAT32_C(    -8.17), SIMDE_FLOAT32_C(  -624.68) },
       INT32_C(          48),
      { SIMDE_FLOAT32_C(   -29.50), SIMDE_FLOAT32_C(  -399.88), SIMDE_FLOAT32_C(    -8.12), SIMDE_FLOAT32_C(  -624.62) } },
    { {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(   762.14), SIMDE_FLOAT32_C(   463.35), SIMDE_FLOAT32_C(  -105.13) },
       INT32_C(          64),
      {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(   762.12), SIMDE_FLOAT32_C(   463.38), SIMDE_FLOAT32_C(  -105.12) } },
    { { SIMDE_FLOAT32_C(  -338.82), SIMDE_FLOAT32_C(  -677.32), SIMDE_FLOAT32_C(  -711.13), SIMDE_FLOAT32_C(    39.83) },
       INT32_C(          80),
      { SIMDE_FLOAT32_C(  -338.81), SIMDE_FLOAT32_C(  -677.31), SIMDE_FLOAT32_C(  -711.12), SIMDE_FLOAT32_C(    39.84) } },
    { {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(   222.84), SIMDE_FLOAT32_C(   537.98), SIMDE_FLOAT32_C(   127.16) },
       INT32_C(          96),
      {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(   222.84), SIMDE_FLOAT32_C(   537.98), SIMDE_FLOAT32_C(   127.16) } },
    { { SIMDE_FLOAT32_C(  -448.10),     -SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(  -985.10), SIMDE_FLOAT32_C(   -93.24) },
       INT32_C(         112),
      { SIMDE_FLOAT32_C(  -448.10),     -SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(  -985.10), SIMDE_FLOAT32_C(   -93.24) } },
    { { SIMDE_FLOAT32_C(   426.07),      SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(   497.75), SIMDE_FLOAT32_C(  -973.80) },
       INT32_C(         128),
      { SIMDE_FLOAT32_C(   426.07),      SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(   497.75), SIMDE_FLOAT32_C(  -973.80) } },
    { {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(   635.20), SIMDE_FLOAT32_C(   314.85), SIMDE_FLOAT32_C(   453.80) },
       INT32_C(         144),
      {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(   635.20), SIMDE_FLOAT32_C(   314.85), SIMDE_FLOAT32_C(   453.80) } },
    { { SIMDE_FLOAT32_C(  -885.03), SIMDE_FLOAT32_C(   407.49), SIMDE_FLOAT32_C(  -605.40), SIMDE_FLOAT32_C(   154.81) },
       INT32_C(         160),
      { SIMDE_FLOAT32_C(  -885.03), SIMDE_FLOAT32_C(   407.49), SIMDE_FLOAT32_C(  -605.40), SIMDE_FLOAT32_C(   154.81) } },
    { { SIMDE_FLOAT32_C(   206.02),      SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(  -547.27), SIMDE_FLOAT32_C(  -666.82) },
       INT32_C(         176),
      { SIMDE_FLOAT32_C(   206.02),      SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(  -547.27), SIMDE_FLOAT32_C(  -666.82) } },
    { { SIMDE_FLOAT32_C(   608.35),      SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(   791.84), SIMDE_FLOAT32_C(  -704.03) },
       INT32_C(         192),
      { SIMDE_FLOAT32_C(   608.35),      SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(   791.84), SIMDE_FLOAT32_C(  -704.03) } },
    { { SIMDE_FLOAT32_C(   413.65), SIMDE_FLOAT32_C(   816.78), SIMDE_FLOAT32_C(   748.24), SIMDE_FLOAT32_C(  -949.28) },
       INT32_C(         208),
      { SIMDE_FLOAT32_C(   413.65), SIMDE_FLOAT32_C(   816.78), SIMDE_FLOAT32_C(   748.24), SIMDE_FLOAT32_C(  -949.28) } },
    { { SIMDE_FLOAT32_C(   599.73), SIMDE_FLOAT32_C(  -390.36), SIMDE_FLOAT32_C(   325.04), SIMDE_FLOAT32_C(   -85.42) },
       INT32_C(         224),
      { SIMDE_FLOAT32_C(   599.73), SIMDE_FLOAT32_C(  -390.36), SIMDE_FLOAT32_C(   325.04), SIMDE_FLOAT32_C(   -85.42) } },
    { { SIMDE_FLOAT32_C(  -590.15),     -SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(  -821.59), SIMDE_FLOAT32_C(   817.34) },
       INT32_C(         240),
      { SIMDE_FLOAT32_C(  -590.15),     -SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(  -821.59), SIMDE_FLOAT32_C(   817.34) } },
    { {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(   710.86), SIMDE_FLOAT32_C(   184.82), SIMDE_FLOAT32_C(   -45.89) },
       INT32_C(           1),
      {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(   710.00), SIMDE_FLOAT32_C(   184.00), SIMDE_FLOAT32_C(   -46.00) } },
    { {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(   289.03), SIMDE_FLOAT32_C(   879.59), SIMDE_FLOAT32_C(   631.03) },
       INT32_C(          17),
      {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(   289.00), SIMDE_FLOAT32_C(   879.50), SIMDE_FLOAT32_C(   631.00) } },
    { { SIMDE_FLOAT32_C(   950.06), SIMDE_FLOAT32_C(   307.04), SIMDE_FLOAT32_C(    61.64), SIMDE_FLOAT32_C(   766.84) },
       INT32_C(          33),
      { SIMDE_FLOAT32_C(   950.00), SIMDE_FLOAT32_C(   307.00), SIMDE_FLOAT32_C(    61.50), SIMDE_FLOAT32_C(   766.75) } },
    { { SIMDE_FLOAT32_C(   112.35),     -SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(  -344.99), SIMDE_FLOAT32_C(   721.99) },
       INT32_C(          49),
      { SIMDE_FLOAT32_C(   112.25),     -SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(  -345.00), SIMDE_FLOAT32_C(   721.88) } },
    { {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(  -410.10), SIMDE_FLOAT32_C(   963.84), SIMDE_FLOAT32_C(     8.91) },
       INT32_C(          65),
      {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(  -410.12), SIMDE_FLOAT32_C(   963.81), SIMDE_FLOAT32_C(     8.88) } },
    { {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(  -374.27), SIMDE_FLOAT32_C(     7.92), SIMDE_FLOAT32_C(   -74.18) },
       INT32_C(          81),
      {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(  -374.28), SIMDE_FLOAT32_C(     7.91), SIMDE_FLOAT32_C(   -74.19) } },
    { { SIMDE_FLOAT32_C(  -549.43), SIMDE_FLOAT32_C(   419.03), SIMDE_FLOAT32_C(   977.64), SIMDE_FLOAT32_C(  -669.85) },
       INT32_C(          97),
      { SIMDE_FLOAT32_C(  -549.44), SIMDE_FLOAT32_C(   419.02), SIMDE_FLOAT32_C(   977.62), SIMDE_FLOAT32_C(  -669.86) } },
    { { SIMDE_FLOAT32_C(   562.65), SIMDE_FLOAT32_C(   978.14), SIMDE_FLOAT32_C(     0.12), SIMDE_FLOAT32_C(  -130.31) },
       INT32_C(         113),
      { SIMDE_FLOAT32_C(   562.65), SIMDE_FLOAT32_C(   978.13), SIMDE_FLOAT32_C(     0.12), SIMDE_FLOAT32_C(  -130.31) } },
    { {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(   924.97), SIMDE_FLOAT32_C(  -847.87), SIMDE_FLOAT32_C(  -776.36) },
       INT32_C(         129),
      {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(   924.97), SIMDE_FLOAT32_C(  -847.87), SIMDE_FLOAT32_C(  -776.36) } },
    { { SIMDE_FLOAT32_C(     5.36),     -SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(   659.56), SIMDE_FLOAT32_C(  -803.07) },
       INT32_C(         145),
      { SIMDE_FLOAT32_C(     5.36),     -SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(   659.56), SIMDE_FLOAT32_C(  -803.07) } },
    { { SIMDE_FLOAT32_C(  -255.70), SIMDE_FLOAT32_C(   -79.54), SIMDE_FLOAT32_C(   -53.15), SIMDE_FLOAT32_C(   370.03) },
       INT32_C(         161),
      { SIMDE_FLOAT32_C(  -255.70), SIMDE_FLOAT32_C(   -79.54), SIMDE_FLOAT32_C(   -53.15), SIMDE_FLOAT32_C(   370.03) } },
    { { SIMDE_FLOAT32_C(   872.67), SIMDE_FLOAT32_C(   -50.13), SIMDE_FLOAT32_C(  -383.01), SIMDE_FLOAT32_C(  -676.76) },
       INT32_C(         177),
      { SIMDE_FLOAT32_C(   872.67), SIMDE_FLOAT32_C(   -50.13), SIMDE_FLOAT32_C(  -383.01), SIMDE_FLOAT32_C(  -676.76) } },
    { { SIMDE_FLOAT32_C(  -405.36),     -SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(   418.96), SIMDE_FLOAT32_C(  -842.72) },
       INT32_C(         193),
      { SIMDE_FLOAT32_C(  -405.36),     -SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(   418.96), SIMDE_FLOAT32_C(  -842.72) } },
    { { SIMDE_FLOAT32_C(   671.31), SIMDE_FLOAT32_C(   186.05), SIMDE_FLOAT32_C(   -48.06), SIMDE_FLOAT32_C(   823.45) },
       INT32_C(         209),
      { SIMDE_FLOAT32_C(   671.31), SIMDE_FLOAT32_C(   186.05), SIMDE_FLOAT32_C(   -48.06), SIMDE_FLOAT32_C(   823.45) } },
    { { SIMDE_FLOAT32_C(   531.93), SIMDE_FLOAT32_C(   697.57), SIMDE_FLOAT32_C(  -584.95), SIMDE_FLOAT32_C(   681.51) },
       INT32_C(         225),
      { SIMDE_FLOAT32_C(   531.93), SIMDE_FLOAT32_C(   697.57), SIMDE_FLOAT32_C(  -584.95), SIMDE_FLOAT32_C(   681.51) } },
    { { SIMDE_FLOAT32_C(  -388.02), SIMDE_FLOAT32_C(  -579.00), SIMDE_FLOAT32_C(   -19.47), SIMDE_FLOAT32_C(   817.83) },
       INT32_C(         241),
      { SIMDE_FLOAT32_C(  -388.02), SIMDE_FLOAT32_C(  -579.00), SIMDE_FLOAT32_C(   -19.47), SIMDE_FLOAT32_C(   817.83) } },
    { {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(  -235.32), SIMDE_FLOAT32_C(  -464.67), SIMDE_FLOAT32_C(   829.38) },
       INT32_C(           2),
      {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(  -235.00), SIMDE_FLOAT32_C(  -464.00), SIMDE_FLOAT32_C(   830.00) } },
    { {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(   -39.42), SIMDE_FLOAT32_C(   854.11), SIMDE_FLOAT32_C(    41.00) },
       INT32_C(          18),
      {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(   -39.00), SIMDE_FLOAT32_C(   854.50), SIMDE_FLOAT32_C(    41.00) } },
    { { SIMDE_FLOAT32_C(   198.28), SIMDE_FLOAT32_C(  -754.49), SIMDE_FLOAT32_C(   692.15), SIMDE_FLOAT32_C(  -774.75) },
       INT32_C(          34),
      { SIMDE_FLOAT32_C(   198.50), SIMDE_FLOAT32_C(  -754.25), SIMDE_FLOAT32_C(   692.25), SIMDE_FLOAT32_C(  -774.75) } },
    { { SIMDE_FLOAT32_C(  -121.80), SIMDE_FLOAT32_C(   177.20), SIMDE_FLOAT32_C(   740.27), SIMDE_FLOAT32_C(  -712.11) },
       INT32_C(          50),
      { SIMDE_FLOAT32_C(  -121.75), SIMDE_FLOAT32_C(   177.25), SIMDE_FLOAT32_C(   740.38), SIMDE_FLOAT32_C(  -712.00) } },
    { { SIMDE_FLOAT32_C(   437.85), SIMDE_FLOAT32_C(  -297.06), SIMDE_FLOAT32_C(  -609.36), SIMDE_FLOAT32_C(  -205.02) },
       INT32_C(          66),
      { SIMDE_FLOAT32_C(   437.88), SIMDE_FLOAT32_C(  -297.00), SIMDE_FLOAT32_C(  -609.31), SIMDE_FLOAT32_C(  -205.00) } },
    { { SIMDE_FLOAT32_C(  -188.36), SIMDE_FLOAT32_C(   775.51), SIMDE_FLOAT32_C(   132.74), SIMDE_FLOAT32_C(   976.93) },
       INT32_C(          82),
      { SIMDE_FLOAT32_C(  -188.34), SIMDE_FLOAT32_C(   775.53), SIMDE_FLOAT32_C(   132.75), SIMDE_FLOAT32_C(   976.94) } },
    { {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(  -487.74), SIMDE_FLOAT32_C(   505.88), SIMDE_FLOAT32_C(  -465.24) },
       INT32_C(          98),
      {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(  -487.73), SIMDE_FLOAT32_C(   505.89), SIMDE_FLOAT32_C(  -465.23) } },
    { { SIMDE_FLOAT32_C(   495.34), SIMDE_FLOAT32_C(   851.57), SIMDE_FLOAT32_C(    -6.75), SIMDE_FLOAT32_C(   109.32) },
       INT32_C(         114),
      { SIMDE_FLOAT32_C(   495.34), SIMDE_FLOAT32_C(   851.57), SIMDE_FLOAT32_C(    -6.75), SIMDE_FLOAT32_C(   109.32) } },
    { { SIMDE_FLOAT32_C(  -808.46), SIMDE_FLOAT32_C(   354.82), SIMDE_FLOAT32_C(  -183.20), SIMDE_FLOAT32_C(  -583.21) },
       INT32_C(         130),
      { SIMDE_FLOAT32_C(  -808.46), SIMDE_FLOAT32_C(   354.82), SIMDE_FLOAT32_C(  -183.20), SIMDE_FLOAT32_C(  -583.21) } },
    { { SIMDE_FLOAT32_C(   695.00), SIMDE_FLOAT32_C(   593.99), SIMDE_FLOAT32_C(    11.92), SIMDE_FLOAT32_C(   982.89) },
       INT32_C(         146),
      { SIMDE_FLOAT32_C(   695.00), SIMDE_FLOAT32_C(   593.99), SIMDE_FLOAT32_C(    11.92), SIMDE_FLOAT32_C(   982.89) } },
    { {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(  -314.18), SIMDE_FLOAT32_C(  -306.25), SIMDE_FLOAT32_C(   244.74) },
       INT32_C(         162),
      {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(  -314.18), SIMDE_FLOAT32_C(  -306.25), SIMDE_FLOAT32_C(   244.74) } },
    { { SIMDE_FLOAT32_C(    20.26), SIMDE_FLOAT32_C(   133.48), SIMDE_FLOAT32_C(   482.32), SIMDE_FLOAT32_C(  -303.23) },
       INT32_C(         178),
      { SIMDE_FLOAT32_C(    20.26), SIMDE_FLOAT32_C(   133.48), SIMDE_FLOAT32_C(   482.32), SIMDE_FLOAT32_C(  -303.23) } },
    { {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(  -797.35), SIMDE_FLOAT32_C(   565.65), SIMDE_FLOAT32_C(   992.05) },
       INT32_C(         194),
      {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(  -797.35), SIMDE_FLOAT32_C(   565.65), SIMDE_FLOAT32_C(   992.05) } },
    { { SIMDE_FLOAT32_C(   843.62), SIMDE_FLOAT32_C(   148.16), SIMDE_FLOAT32_C(  -829.69), SIMDE_FLOAT32_C(   -31.74) },
       INT32_C(         210),
      { SIMDE_FLOAT32_C(   843.62), SIMDE_FLOAT32_C(   148.16), SIMDE_FLOAT32_C(  -829.69), SIMDE_FLOAT32_C(   -31.74) } },
    { { SIMDE_FLOAT32_C(   525.13),      SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(   756.48), SIMDE_FLOAT32_C(  -203.22) },
       INT32_C(         226),
      { SIMDE_FLOAT32_C(   525.13),      SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(   756.48), SIMDE_FLOAT32_C(  -203.22) } },
    { { SIMDE_FLOAT32_C(   462.95), SIMDE_FLOAT32_C(   653.59), SIMDE_FLOAT32_C(  -741.53), SIMDE_FLOAT32_C(  -851.23) },
       INT32_C(         242),
      { SIMDE_FLOAT32_C(   462.95), SIMDE_FLOAT32_C(   653.59), SIMDE_FLOAT32_C(  -741.53), SIMDE_FLOAT32_C(  -851.23) } },
    { {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(  -850.49), SIMDE_FLOAT32_C(   852.73), SIMDE_FLOAT32_C(  -476.53) },
       INT32_C(           3),
      {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(  -850.00), SIMDE_FLOAT32_C(   852.00), SIMDE_FLOAT32_C(  -476.00) } },
    { { SIMDE_FLOAT32_C(   220.24), SIMDE_FLOAT32_C(  -686.13), SIMDE_FLOAT32_C(   329.63), SIMDE_FLOAT32_C(   422.89) },
       INT32_C(          19),
      { SIMDE_FLOAT32_C(   220.00), SIMDE_FLOAT32_C(  -686.00), SIMDE_FLOAT32_C(   329.50), SIMDE_FLOAT32_C(   422.50) } },
    { { SIMDE_FLOAT32_C(   321.68), SIMDE_FLOAT32_C(   577.80), SIMDE_FLOAT32_C(   -59.48), SIMDE_FLOAT32_C(   165.30) },
       INT32_C(          35),
      { SIMDE_FLOAT32_C(   321.50), SIMDE_FLOAT32_C(   577.75), SIMDE_FLOAT32_C(   -59.25), SIMDE_FLOAT32_C(   165.25) } },
    { { SIMDE_FLOAT32_C(   110.83), SIMDE_FLOAT32_C(  -866.44), SIMDE_FLOAT32_C(  -934.35), SIMDE_FLOAT32_C(  -364.04) },
       INT32_C(          51),
      { SIMDE_FLOAT32_C(   110.75), SIMDE_FLOAT32_C(  -866.38), SIMDE_FLOAT32_C(  -934.25), SIMDE_FLOAT32_C(  -364.00) } },
    { { SIMDE_FLOAT32_C(   822.13), SIMDE_FLOAT32_C(   432.74), SIMDE_FLOAT32_C(   398.69), SIMDE_FLOAT32_C(   172.60) },
       INT32_C(          67),
      { SIMDE_FLOAT32_C(   822.12), SIMDE_FLOAT32_C(   432.69), SIMDE_FLOAT32_C(   398.69), SIMDE_FLOAT32_C(   172.56) } },
    { { SIMDE_FLOAT32_C(  -138.37),      SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(   499.91), SIMDE_FLOAT32_C(    10.40) },
       INT32_C(          83),
      { SIMDE_FLOAT32_C(  -138.34),      SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(   499.91), SIMDE_FLOAT32_C(    10.38) } },
    { {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(   526.59), SIMDE_FLOAT32_C(  -557.11), SIMDE_FLOAT32_C(  -638.70) },
       INT32_C(          99),
      {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(   526.58), SIMDE_FLOAT32_C(  -557.11), SIMDE_FLOAT32_C(  -638.69) } },
    { {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(  -830.28), SIMDE_FLOAT32_C(  -363.71), SIMDE_FLOAT32_C(    12.61) },
       INT32_C(         115),
      {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(  -830.27), SIMDE_FLOAT32_C(  -363.70), SIMDE_FLOAT32_C(    12.61) } },
    { { SIMDE_FLOAT32_C(  -822.09),      SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(  -312.37), SIMDE_FLOAT32_C(  -688.53) },
       INT32_C(         131),
      { SIMDE_FLOAT32_C(  -822.09),      SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(  -312.37), SIMDE_FLOAT32_C(  -688.53) } },
    { { SIMDE_FLOAT32_C(  -638.75),      SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(   628.78), SIMDE_FLOAT32_C(   533.85) },
       INT32_C(         147),
      { SIMDE_FLOAT32_C(  -638.75),      SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(   628.78), SIMDE_FLOAT32_C(   533.85) } },
    { { SIMDE_FLOAT32_C(   497.68), SIMDE_FLOAT32_C(   500.82), SIMDE_FLOAT32_C(   533.57), SIMDE_FLOAT32_C(  -499.20) },
       INT32_C(         163),
      { SIMDE_FLOAT32_C(   497.68), SIMDE_FLOAT32_C(   500.82), SIMDE_FLOAT32_C(   533.57), SIMDE_FLOAT32_C(  -499.20) } },
    { { SIMDE_FLOAT32_C(  -440.17), SIMDE_FLOAT32_C(  -972.62), SIMDE_FLOAT32_C(   103.62), SIMDE_FLOAT32_C(   -78.87) },
       INT32_C(         179),
      { SIMDE_FLOAT32_C(  -440.17), SIMDE_FLOAT32_C(  -972.62), SIMDE_FLOAT32_C(   103.62), SIMDE_FLOAT32_C(   -78.87) } },
    { { SIMDE_FLOAT32_C(   860.38),      SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(   -56.08), SIMDE_FLOAT32_C(  -503.33) },
       INT32_C(         195),
      { SIMDE_FLOAT32_C(   860.38),      SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(   -56.08), SIMDE_FLOAT32_C(  -503.33) } },
    { {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(   164.90), SIMDE_FLOAT32_C(  -238.89), SIMDE_FLOAT32_C(  -885.95) },
       INT32_C(         211),
      {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(   164.90), SIMDE_FLOAT32_C(  -238.89), SIMDE_FLOAT32_C(  -885.95) } },
    { { SIMDE_FLOAT32_C(  -655.85), SIMDE_FLOAT32_C(  -934.74), SIMDE_FLOAT32_C(  -158.97), SIMDE_FLOAT32_C(   972.94) },
       INT32_C(         227),
      { SIMDE_FLOAT32_C(  -655.85), SIMDE_FLOAT32_C(  -934.74), SIMDE_FLOAT32_C(  -158.97), SIMDE_FLOAT32_C(   972.94) } },
    { { SIMDE_FLOAT32_C(  -161.19), SIMDE_FLOAT32_C(  -536.65), SIMDE_FLOAT32_C(   959.15), SIMDE_FLOAT32_C(  -663.51) },
       INT32_C(         243),
      { SIMDE_FLOAT32_C(  -161.19), SIMDE_FLOAT32_C(  -536.65), SIMDE_FLOAT32_C(   959.15), SIMDE_FLOAT32_C(  -663.51) } },
    { { SIMDE_FLOAT32_C(   492.72), SIMDE_FLOAT32_C(  -162.72), SIMDE_FLOAT32_C(  -375.10), SIMDE_FLOAT32_C(  -947.45) },
       INT32_C(           4),
      { SIMDE_FLOAT32_C(   493.00), SIMDE_FLOAT32_C(  -163.00), SIMDE_FLOAT32_C(  -375.00), SIMDE_FLOAT32_C(  -947.00) } },
    { { SIMDE_FLOAT32_C(   728.52), SIMDE_FLOAT32_C(   -26.32), SIMDE_FLOAT32_C(   638.87), SIMDE_FLOAT32_C(   588.91) },
       INT32_C(          20),
      { SIMDE_FLOAT32_C(   728.50), SIMDE_FLOAT32_C(   -26.50), SIMDE_FLOAT32_C(   639.00), SIMDE_FLOAT32_C(   589.00) } },
    { {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(  -914.42), SIMDE_FLOAT32_C(   210.42), SIMDE_FLOAT32_C(   274.23) },
       INT32_C(          36),
      {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(  -914.50), SIMDE_FLOAT32_C(   210.50), SIMDE_FLOAT32_C(   274.25) } },
    { { SIMDE_FLOAT32_C(  -560.87),     -SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(   127.05), SIMDE_FLOAT32_C(  -856.85) },
       INT32_C(          52),
      { SIMDE_FLOAT32_C(  -560.88),     -SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(   127.00), SIMDE_FLOAT32_C(  -856.88) } },
    { { SIMDE_FLOAT32_C(   845.91), SIMDE_FLOAT32_C(   444.14), SIMDE_FLOAT32_C(   807.52), SIMDE_FLOAT32_C(  -315.29) },
       INT32_C(          68),
      { SIMDE_FLOAT32_C(   845.94), SIMDE_FLOAT32_C(   444.12), SIMDE_FLOAT32_C(   807.50), SIMDE_FLOAT32_C(  -315.31) } },
    { { SIMDE_FLOAT32_C(   766.67), SIMDE_FLOAT32_C(    21.20), SIMDE_FLOAT32_C(   871.67), SIMDE_FLOAT32_C(   259.40) },
       INT32_C(          84),
      { SIMDE_FLOAT32_C(   766.66), SIMDE_FLOAT32_C(    21.19), SIMDE_FLOAT32_C(   871.66), SIMDE_FLOAT32_C(   259.41) } },
    { {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(   311.95), SIMDE_FLOAT32_C(  -276.85), SIMDE_FLOAT32_C(  -774.90) },
       INT32_C(         100),
      {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(   311.95), SIMDE_FLOAT32_C(  -276.84), SIMDE_FLOAT32_C(  -774.91) } },
    { { SIMDE_FLOAT32_C(   814.00), SIMDE_FLOAT32_C(   871.38), SIMDE_FLOAT32_C(   -55.18), SIMDE_FLOAT32_C(   899.58) },
       INT32_C(         116),
      { SIMDE_FLOAT32_C(   814.00), SIMDE_FLOAT32_C(   871.38), SIMDE_FLOAT32_C(   -55.18), SIMDE_FLOAT32_C(   899.58) } },
    { { SIMDE_FLOAT32_C(  -780.95),      SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(  -905.21), SIMDE_FLOAT32_C(  -341.82) },
       INT32_C(         132),
      { SIMDE_FLOAT32_C(  -780.95),      SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(  -905.21), SIMDE_FLOAT32_C(  -341.82) } },
    { { SIMDE_FLOAT32_C(   983.68), SIMDE_FLOAT32_C(  -306.95), SIMDE_FLOAT32_C(     9.74), SIMDE_FLOAT32_C(   829.59) },
       INT32_C(         148),
      { SIMDE_FLOAT32_C(   983.68), SIMDE_FLOAT32_C(  -306.95), SIMDE_FLOAT32_C(     9.74), SIMDE_FLOAT32_C(   829.59) } },
    { { SIMDE_FLOAT32_C(  -182.74),      SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(  -955.30), SIMDE_FLOAT32_C(  -416.07) },
       INT32_C(         164),
      { SIMDE_FLOAT32_C(  -182.74),      SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(  -955.30), SIMDE_FLOAT32_C(  -416.07) } },
    { { SIMDE_FLOAT32_C(   393.98),      SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(   155.28), SIMDE_FLOAT32_C(  -882.87) },
       INT32_C(         180),
      { SIMDE_FLOAT32_C(   393.98),      SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(   155.28), SIMDE_FLOAT32_C(  -882.87) } },
    { { SIMDE_FLOAT32_C(  -547.96), SIMDE_FLOAT32_C(   312.29), SIMDE_FLOAT32_C(   423.96), SIMDE_FLOAT32_C(  -648.38) },
       INT32_C(         196),
      { SIMDE_FLOAT32_C(  -547.96), SIMDE_FLOAT32_C(   312.29), SIMDE_FLOAT32_C(   423.96), SIMDE_FLOAT32_C(  -648.38) } },
    { {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(  -589.74), SIMDE_FLOAT32_C(  -511.12), SIMDE_FLOAT32_C(  -698.81) },
       INT32_C(         212),
      {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(  -589.74), SIMDE_FLOAT32_C(  -511.12), SIMDE_FLOAT32_C(  -698.81) } },
    { { SIMDE_FLOAT32_C(   102.53), SIMDE_FLOAT32_C(   372.75), SIMDE_FLOAT32_C(  -596.22), SIMDE_FLOAT32_C(  -887.73) },
       INT32_C(         228),
      { SIMDE_FLOAT32_C(   102.53), SIMDE_FLOAT32_C(   372.75), SIMDE_FLOAT32_C(  -596.22), SIMDE_FLOAT32_C(  -887.73) } },
    { { SIMDE_FLOAT32_C(  -459.02), SIMDE_FLOAT32_C(   -70.47), SIMDE_FLOAT32_C(   716.63), SIMDE_FLOAT32_C(  -414.33) },
       INT32_C(         244),
      { SIMDE_FLOAT32_C(  -459.02), SIMDE_FLOAT32_C(   -70.47), SIMDE_FLOAT32_C(   716.63), SIMDE_FLOAT32_C(  -414.33) } },
  };

  simde__m128 a, r;

  a = simde_mm_loadu_ps(test_vec[0].a);
  r = simde_mm_roundscale_ps(a, INT32_C(           0));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[0].r), 1);

  a = simde_mm_loadu_ps(test_vec[1].a);
  r = simde_mm_roundscale_ps(a, INT32_C(          16));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[1].r), 1);

  a = simde_mm_loadu_ps(test_vec[2].a);
  r = simde_mm_roundscale_ps(a, INT32_C(          32));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[2].r), 1);

  a = simde_mm_loadu_ps(test_vec[3].a);
  r = simde_mm_roundscale_ps(a, INT32_C(          48));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[3].r), 1);

  a = simde_mm_loadu_ps(test_vec[4].a);
  r = simde_mm_roundscale_ps(a, INT32_C(          64));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[4].r), 1);

  a = simde_mm_loadu_ps(test_vec[5].a);
  r = simde_mm_roundscale_ps(a, INT32_C(          80));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[5].r), 1);

  a = simde_mm_loadu_ps(test_vec[6].a);
  r = simde_mm_roundscale_ps(a, INT32_C(          96));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[6].r), 1);

  a = simde_mm_loadu_ps(test_vec[7].a);
  r = simde_mm_roundscale_ps(a, INT32_C(         112));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[7].r), 1);

  a = simde_mm_loadu_ps(test_vec[8].a);
  r = simde_mm_roundscale_ps(a, INT32_C(         128));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[8].r), 1);

  a = simde_mm_loadu_ps(test_vec[9].a);
  r = simde_mm_roundscale_ps(a, INT32_C(         144));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[9].r), 1);

  a = simde_mm_loadu_ps(test_vec[10].a);
  r = simde_mm_roundscale_ps(a, INT32_C(         160));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[10].r), 1);

  a = simde_mm_loadu_ps(test_vec[11].a);
  r = simde_mm_roundscale_ps(a, INT32_C(         176));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[11].r), 1);

  a = simde_mm_loadu_ps(test_vec[12].a);
  r = simde_mm_roundscale_ps(a, INT32_C(         192));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[12].r), 1);

  a = simde_mm_loadu_ps(test_vec[13].a);
  r = simde_mm_roundscale_ps(a, INT32_C(         208));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[13].r), 1);

  a = simde_mm_loadu_ps(test_vec[14].a);
  r = simde_mm_roundscale_ps(a, INT32_C(         224));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[14].r), 1);

  a = simde_mm_loadu_ps(test_vec[15].a);
  r = simde_mm_roundscale_ps(a, INT32_C(         240));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[15].r), 1);

  a = simde_mm_loadu_ps(test_vec[16].a);
  r = simde_mm_roundscale_ps(a, INT32_C(           1));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[16].r), 1);

  a = simde_mm_loadu_ps(test_vec[17].a);
  r = simde_mm_roundscale_ps(a, INT32_C(          17));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[17].r), 1);

  a = simde_mm_loadu_ps(test_vec[18].a);
  r = simde_mm_roundscale_ps(a, INT32_C(          33));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[18].r), 1);

  a = simde_mm_loadu_ps(test_vec[19].a);
  r = simde_mm_roundscale_ps(a, INT32_C(          49));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[19].r), 1);

  a = simde_mm_loadu_ps(test_vec[20].a);
  r = simde_mm_roundscale_ps(a, INT32_C(          65));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[20].r), 1);

  a = simde_mm_loadu_ps(test_vec[21].a);
  r = simde_mm_roundscale_ps(a, INT32_C(          81));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[21].r), 1);

  a = simde_mm_loadu_ps(test_vec[22].a);
  r = simde_mm_roundscale_ps(a, INT32_C(          97));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[22].r), 1);

  a = simde_mm_loadu_ps(test_vec[23].a);
  r = simde_mm_roundscale_ps(a, INT32_C(         113));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[23].r), 1);

  a = simde_mm_loadu_ps(test_vec[24].a);
  r = simde_mm_roundscale_ps(a, INT32_C(         129));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[24].r), 1);

  a = simde_mm_loadu_ps(test_vec[25].a);
  r = simde_mm_roundscale_ps(a, INT32_C(         145));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[25].r), 1);

  a = simde_mm_loadu_ps(test_vec[26].a);
  r = simde_mm_roundscale_ps(a, INT32_C(         161));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[26].r), 1);

  a = simde_mm_loadu_ps(test_vec[27].a);
  r = simde_mm_roundscale_ps(a, INT32_C(         177));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[27].r), 1);

  a = simde_mm_loadu_ps(test_vec[28].a);
  r = simde_mm_roundscale_ps(a, INT32_C(         193));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[28].r), 1);

  a = simde_mm_loadu_ps(test_vec[29].a);
  r = simde_mm_roundscale_ps(a, INT32_C(         209));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[29].r), 1);

  a = simde_mm_loadu_ps(test_vec[30].a);
  r = simde_mm_roundscale_ps(a, INT32_C(         225));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[30].r), 1);

  a = simde_mm_loadu_ps(test_vec[31].a);
  r = simde_mm_roundscale_ps(a, INT32_C(         241));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[31].r), 1);

  a = simde_mm_loadu_ps(test_vec[32].a);
  r = simde_mm_roundscale_ps(a, INT32_C(           2));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[32].r), 1);

  a = simde_mm_loadu_ps(test_vec[33].a);
  r = simde_mm_roundscale_ps(a, INT32_C(          18));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[33].r), 1);

  a = simde_mm_loadu_ps(test_vec[34].a);
  r = simde_mm_roundscale_ps(a, INT32_C(          34));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[34].r), 1);

  a = simde_mm_loadu_ps(test_vec[35].a);
  r = simde_mm_roundscale_ps(a, INT32_C(          50));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[35].r), 1);

  a = simde_mm_loadu_ps(test_vec[36].a);
  r = simde_mm_roundscale_ps(a, INT32_C(          66));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[36].r), 1);

  a = simde_mm_loadu_ps(test_vec[37].a);
  r = simde_mm_roundscale_ps(a, INT32_C(          82));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[37].r), 1);

  a = simde_mm_loadu_ps(test_vec[38].a);
  r = simde_mm_roundscale_ps(a, INT32_C(          98));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[38].r), 1);

  a = simde_mm_loadu_ps(test_vec[39].a);
  r = simde_mm_roundscale_ps(a, INT32_C(         114));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[39].r), 1);

  a = simde_mm_loadu_ps(test_vec[40].a);
  r = simde_mm_roundscale_ps(a, INT32_C(         130));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[40].r), 1);

  a = simde_mm_loadu_ps(test_vec[41].a);
  r = simde_mm_roundscale_ps(a, INT32_C(         146));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[41].r), 1);

  a = simde_mm_loadu_ps(test_vec[42].a);
  r = simde_mm_roundscale_ps(a, INT32_C(         162));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[42].r), 1);

  a = simde_mm_loadu_ps(test_vec[43].a);
  r = simde_mm_roundscale_ps(a, INT32_C(         178));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[43].r), 1);

  a = simde_mm_loadu_ps(test_vec[44].a);
  r = simde_mm_roundscale_ps(a, INT32_C(         194));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[44].r), 1);

  a = simde_mm_loadu_ps(test_vec[45].a);
  r = simde_mm_roundscale_ps(a, INT32_C(         210));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[45].r), 1);

  a = simde_mm_loadu_ps(test_vec[46].a);
  r = simde_mm_roundscale_ps(a, INT32_C(         226));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[46].r), 1);

  a = simde_mm_loadu_ps(test_vec[47].a);
  r = simde_mm_roundscale_ps(a, INT32_C(         242));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[47].r), 1);

  a = simde_mm_loadu_ps(test_vec[48].a);
  r = simde_mm_roundscale_ps(a, INT32_C(           3));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[48].r), 1);

  a = simde_mm_loadu_ps(test_vec[49].a);
  r = simde_mm_roundscale_ps(a, INT32_C(          19));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[49].r), 1);

  a = simde_mm_loadu_ps(test_vec[50].a);
  r = simde_mm_roundscale_ps(a, INT32_C(          35));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[50].r), 1);

  a = simde_mm_loadu_ps(test_vec[51].a);
  r = simde_mm_roundscale_ps(a, INT32_C(          51));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[51].r), 1);

  a = simde_mm_loadu_ps(test_vec[52].a);
  r = simde_mm_roundscale_ps(a, INT32_C(          67));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[52].r), 1);

  a = simde_mm_loadu_ps(test_vec[53].a);
  r = simde_mm_roundscale_ps(a, INT32_C(          83));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[53].r), 1);

  a = simde_mm_loadu_ps(test_vec[54].a);
  r = simde_mm_roundscale_ps(a, INT32_C(          99));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[54].r), 1);

  a = simde_mm_loadu_ps(test_vec[55].a);
  r = simde_mm_roundscale_ps(a, INT32_C(         115));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[55].r), 1);

  a = simde_mm_loadu_ps(test_vec[56].a);
  r = simde_mm_roundscale_ps(a, INT32_C(         131));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[56].r), 1);

  a = simde_mm_loadu_ps(test_vec[57].a);
  r = simde_mm_roundscale_ps(a, INT32_C(         147));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[57].r), 1);

  a = simde_mm_loadu_ps(test_vec[58].a);
  r = simde_mm_roundscale_ps(a, INT32_C(         163));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[58].r), 1);

  a = simde_mm_loadu_ps(test_vec[59].a);
  r = simde_mm_roundscale_ps(a, INT32_C(         179));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[59].r), 1);

  a = simde_mm_loadu_ps(test_vec[60].a);
  r = simde_mm_roundscale_ps(a, INT32_C(         195));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[60].r), 1);

  a = simde_mm_loadu_ps(test_vec[61].a);
  r = simde_mm_roundscale_ps(a, INT32_C(         211));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[61].r), 1);

  a = simde_mm_loadu_ps(test_vec[62].a);
  r = simde_mm_roundscale_ps(a, INT32_C(         227));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[62].r), 1);

  a = simde_mm_loadu_ps(test_vec[63].a);
  r = simde_mm_roundscale_ps(a, INT32_C(         243));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[63].r), 1);

  a = simde_mm_loadu_ps(test_vec[64].a);
  r = simde_mm_roundscale_ps(a, INT32_C(           4));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[64].r), 1);

  a = simde_mm_loadu_ps(test_vec[65].a);
  r = simde_mm_roundscale_ps(a, INT32_C(          20));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[65].r), 1);

  a = simde_mm_loadu_ps(test_vec[66].a);
  r = simde_mm_roundscale_ps(a, INT32_C(          36));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[66].r), 1);

  a = simde_mm_loadu_ps(test_vec[67].a);
  r = simde_mm_roundscale_ps(a, INT32_C(          52));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[67].r), 1);

  a = simde_mm_loadu_ps(test_vec[68].a);
  r = simde_mm_roundscale_ps(a, INT32_C(          68));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[68].r), 1);

  a = simde_mm_loadu_ps(test_vec[69].a);
  r = simde_mm_roundscale_ps(a, INT32_C(          84));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[69].r), 1);

  a = simde_mm_loadu_ps(test_vec[70].a);
  r = simde_mm_roundscale_ps(a, INT32_C(         100));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[70].r), 1);

  a = simde_mm_loadu_ps(test_vec[71].a);
  r = simde_mm_roundscale_ps(a, INT32_C(         116));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[71].r), 1);

  a = simde_mm_loadu_ps(test_vec[72].a);
  r = simde_mm_roundscale_ps(a, INT32_C(         132));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[72].r), 1);

  a = simde_mm_loadu_ps(test_vec[73].a);
  r = simde_mm_roundscale_ps(a, INT32_C(         148));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[73].r), 1);

  a = simde_mm_loadu_ps(test_vec[74].a);
  r = simde_mm_roundscale_ps(a, INT32_C(         164));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[74].r), 1);

  a = simde_mm_loadu_ps(test_vec[75].a);
  r = simde_mm_roundscale_ps(a, INT32_C(         180));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[75].r), 1);

  a = simde_mm_loadu_ps(test_vec[76].a);
  r = simde_mm_roundscale_ps(a, INT32_C(         196));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[76].r), 1);

  a = simde_mm_loadu_ps(test_vec[77].a);
  r = simde_mm_roundscale_ps(a, INT32_C(         212));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[77].r), 1);

  a = simde_mm_loadu_ps(test_vec[78].a);
  r = simde_mm_roundscale_ps(a, INT32_C(         228));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[78].r), 1);

  a = simde_mm_loadu_ps(test_vec[79].a);
  r = simde_mm_roundscale_ps(a, INT32_C(         244));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[79].r), 1);

  return 0;
#else
  fputc('\n', stdout);
  int round_type[5] = {SIMDE_MM_FROUND_TO_NEAREST_INT, SIMDE_MM_FROUND_TO_NEG_INF, SIMDE_MM_FROUND_TO_POS_INF, SIMDE_MM_FROUND_TO_ZERO, SIMDE_MM_FROUND_CUR_DIRECTION};
  for (int i = 0 ; i < 5 ; i++) {
    for (int j = 0 ; j < 16 ; j++) {
      simde__m128 a = simde_test_x86_random_f32x4(SIMDE_FLOAT32_C(-1000.0), SIMDE_FLOAT32_C(1000.0));
      if((simde_test_codegen_rand() & 1)) {
        if((simde_test_codegen_rand() & 1))
          a = simde_mm_blend_ps(a, simde_mm_set1_ps(SIMDE_MATH_NANF), 1);
        else {
          if((simde_test_codegen_rand() & 1))
            a = simde_mm_blend_ps(a, simde_mm_set1_ps(SIMDE_MATH_INFINITY), 2);
          else
            a = simde_mm_blend_ps(a, simde_mm_set1_ps(-SIMDE_MATH_INFINITY), 2);
        }
      }
      int imm8 = ((j << 4) | round_type[i]) & 255;
      simde__m128 r;
      SIMDE_CONSTIFY_256_(simde_mm_roundscale_ps, r, simde_mm_setzero_ps(), imm8, a);

      simde_test_x86_write_f32x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
      simde_test_codegen_write_i32(2, imm8, SIMDE_TEST_VEC_POS_MIDDLE);
      simde_test_x86_write_f32x4(2, r, SIMDE_TEST_VEC_POS_LAST);
    }
  }
  return 1;
#endif
}

static int
test_simde_mm_mask_roundscale_ps (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const simde_float32 src[4];
    const simde__mmask8 k;
    const simde_float32 a[4];
    const int32_t imm8;
    const simde_float32 r[4];
  } test_vec[] = {
    { { SIMDE_FLOAT32_C(  -316.31), SIMDE_FLOAT32_C(   649.73), SIMDE_FLOAT32_C(   200.80), SIMDE_FLOAT32_C(   -79.92) },
      UINT8_C(161),
      {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(   963.57), SIMDE_FLOAT32_C(  -663.71), SIMDE_FLOAT32_C(  -906.90) },
       INT32_C(         112),
      {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(   649.73), SIMDE_FLOAT32_C(   200.80), SIMDE_FLOAT32_C(   -79.92) } },
    { { SIMDE_FLOAT32_C(  -584.01), SIMDE_FLOAT32_C(  -683.67), SIMDE_FLOAT32_C(   359.10), SIMDE_FLOAT32_C(   539.12) },
      UINT8_C( 84),
      { SIMDE_FLOAT32_C(  -642.45), SIMDE_FLOAT32_C(   980.52), SIMDE_FLOAT32_C(   709.42), SIMDE_FLOAT32_C(  -815.38) },
       INT32_C(          49),
      { SIMDE_FLOAT32_C(  -584.01), SIMDE_FLOAT32_C(  -683.67), SIMDE_FLOAT32_C(   709.38), SIMDE_FLOAT32_C(   539.12) } },
    { { SIMDE_FLOAT32_C(  -716.00), SIMDE_FLOAT32_C(  -111.36), SIMDE_FLOAT32_C(  -489.38), SIMDE_FLOAT32_C(   896.66) },
      UINT8_C(244),
      { SIMDE_FLOAT32_C(   -57.08), SIMDE_FLOAT32_C(  -626.52), SIMDE_FLOAT32_C(  -249.57), SIMDE_FLOAT32_C(   626.60) },
       INT32_C(          18),
      { SIMDE_FLOAT32_C(  -716.00), SIMDE_FLOAT32_C(  -111.36), SIMDE_FLOAT32_C(  -249.50), SIMDE_FLOAT32_C(   896.66) } },
    { { SIMDE_FLOAT32_C(  -453.32), SIMDE_FLOAT32_C(   134.70), SIMDE_FLOAT32_C(   315.58), SIMDE_FLOAT32_C(  -489.75) },
      UINT8_C(109),
      { SIMDE_FLOAT32_C(   408.68), SIMDE_FLOAT32_C(   792.03), SIMDE_FLOAT32_C(   887.75), SIMDE_FLOAT32_C(   573.55) },
       INT32_C(           3),
      { SIMDE_FLOAT32_C(   408.00), SIMDE_FLOAT32_C(   134.70), SIMDE_FLOAT32_C(   887.00), SIMDE_FLOAT32_C(   573.00) } },
    { { SIMDE_FLOAT32_C(   -67.35), SIMDE_FLOAT32_C(   747.13), SIMDE_FLOAT32_C(  -632.66), SIMDE_FLOAT32_C(   290.20) },
      UINT8_C(224),
      { SIMDE_FLOAT32_C(  -923.24),     -SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(   963.50), SIMDE_FLOAT32_C(  -799.60) },
       INT32_C(         148),
      { SIMDE_FLOAT32_C(   -67.35), SIMDE_FLOAT32_C(   747.13), SIMDE_FLOAT32_C(  -632.66), SIMDE_FLOAT32_C(   290.20) } },
    { { SIMDE_FLOAT32_C(  -984.94), SIMDE_FLOAT32_C(   653.94), SIMDE_FLOAT32_C(  -971.04), SIMDE_FLOAT32_C(  -234.51) },
      UINT8_C(123),
      { SIMDE_FLOAT32_C(  -947.82),     -SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(   827.23), SIMDE_FLOAT32_C(   186.88) },
       INT32_C(          64),
      { SIMDE_FLOAT32_C(  -947.81),     -SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(  -971.04), SIMDE_FLOAT32_C(   186.88) } },
    { { SIMDE_FLOAT32_C(  -870.49), SIMDE_FLOAT32_C(  -454.38), SIMDE_FLOAT32_C(    14.54), SIMDE_FLOAT32_C(  -662.48) },
      UINT8_C( 52),
      { SIMDE_FLOAT32_C(   947.19),      SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(   117.04), SIMDE_FLOAT32_C(   237.39) },
       INT32_C(          65),
      { SIMDE_FLOAT32_C(  -870.49), SIMDE_FLOAT32_C(  -454.38), SIMDE_FLOAT32_C(   117.00), SIMDE_FLOAT32_C(  -662.48) } },
    { { SIMDE_FLOAT32_C(   394.20), SIMDE_FLOAT32_C(  -528.97), SIMDE_FLOAT32_C(  -372.06), SIMDE_FLOAT32_C(  -894.77) },
      UINT8_C( 34),
      { SIMDE_FLOAT32_C(  -357.00),      SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(  -844.53), SIMDE_FLOAT32_C(   408.49) },
       INT32_C(          34),
      { SIMDE_FLOAT32_C(   394.20),      SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(  -372.06), SIMDE_FLOAT32_C(  -894.77) } },
  };

  simde__m128 src, a, r;

  src = simde_mm_loadu_ps(test_vec[0].src);
  a = simde_mm_loadu_ps(test_vec[0].a);
  r = simde_mm_mask_roundscale_ps(src, test_vec[0].k, a, INT32_C(         112));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[0].r), 1);

  src = simde_mm_loadu_ps(test_vec[1].src);
  a = simde_mm_loadu_ps(test_vec[1].a);
  r = simde_mm_mask_roundscale_ps(src, test_vec[1].k, a, INT32_C(          49));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[1].r), 1);

  src = simde_mm_loadu_ps(test_vec[2].src);
  a = simde_mm_loadu_ps(test_vec[2].a);
  r = simde_mm_mask_roundscale_ps(src, test_vec[2].k, a, INT32_C(          18));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[2].r), 1);

  src = simde_mm_loadu_ps(test_vec[3].src);
  a = simde_mm_loadu_ps(test_vec[3].a);
  r = simde_mm_mask_roundscale_ps(src, test_vec[3].k, a, INT32_C(           3));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[3].r), 1);

  src = simde_mm_loadu_ps(test_vec[4].src);
  a = simde_mm_loadu_ps(test_vec[4].a);
  r = simde_mm_mask_roundscale_ps(src, test_vec[4].k, a, INT32_C(         148));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[4].r), 1);

  src = simde_mm_loadu_ps(test_vec[5].src);
  a = simde_mm_loadu_ps(test_vec[5].a);
  r = simde_mm_mask_roundscale_ps(src, test_vec[5].k, a, INT32_C(          64));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[5].r), 1);

  src = simde_mm_loadu_ps(test_vec[6].src);
  a = simde_mm_loadu_ps(test_vec[6].a);
  r = simde_mm_mask_roundscale_ps(src, test_vec[6].k, a, INT32_C(          65));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[6].r), 1);

  src = simde_mm_loadu_ps(test_vec[7].src);
  a = simde_mm_loadu_ps(test_vec[7].a);
  r = simde_mm_mask_roundscale_ps(src, test_vec[7].k, a, INT32_C(          34));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[7].r), 1);

  return 0;
#else
  fputc('\n', stdout);
  int round_type[5] = {SIMDE_MM_FROUND_TO_NEAREST_INT, SIMDE_MM_FROUND_TO_NEG_INF, SIMDE_MM_FROUND_TO_POS_INF, SIMDE_MM_FROUND_TO_ZERO, SIMDE_MM_FROUND_CUR_DIRECTION};
  for (int i = 0 ; i < 8 ; i++) {
    simde__m128 src = simde_test_x86_random_f32x4(SIMDE_FLOAT32_C(-1000.0), SIMDE_FLOAT32_C(1000.0));
    simde__mmask8 k = simde_test_x86_random_mmask8();
    simde__m128 a = simde_test_x86_random_f32x4(SIMDE_FLOAT32_C(-1000.0), SIMDE_FLOAT32_C(1000.0));
    if((simde_test_codegen_rand() & 1)) {
      if((simde_test_codegen_rand() & 1))
        a = simde_mm_blend_ps(a, simde_mm_set1_ps(SIMDE_MATH_NANF), 1);
      else {
        if((simde_test_codegen_rand() & 1))
          a = simde_mm_blend_ps(a, simde_mm_set1_ps(SIMDE_MATH_INFINITY), 2);
        else
          a = simde_mm_blend_ps(a, simde_mm_set1_ps(-SIMDE_MATH_INFINITY), 2);
      }
    }
    int imm8 = (((simde_test_codegen_rand() & 15) << 4) | round_type[i % 5]) & 255;
    simde__m128 r;
    SIMDE_CONSTIFY_256_(simde_mm_mask_roundscale_ps, r, simde_mm_setzero_ps(), imm8, src, k, a);

    simde_test_x86_write_f32x4(2, src, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_mmask8(2, k, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_f32x4(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i32(2, imm8, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_f32x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm_maskz_roundscale_ps (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const simde__mmask8 k;
    const simde_float32 a[4];
    const int32_t imm8;
    const simde_float32 r[4];
  } test_vec[] = {
    { UINT8_C(155),
      { SIMDE_FLOAT32_C(  -842.49), SIMDE_FLOAT32_C(   204.44), SIMDE_FLOAT32_C(  -947.60), SIMDE_FLOAT32_C(   598.50) },
       INT32_C(         176),
      { SIMDE_FLOAT32_C(  -842.49), SIMDE_FLOAT32_C(   204.44), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(   598.50) } },
    { UINT8_C(208),
      { SIMDE_FLOAT32_C(   671.48), SIMDE_FLOAT32_C(   347.71), SIMDE_FLOAT32_C(  -439.78), SIMDE_FLOAT32_C(   756.13) },
       INT32_C(         161),
      { SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00) } },
    { UINT8_C(139),
      {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(  -490.18), SIMDE_FLOAT32_C(   344.22), SIMDE_FLOAT32_C(    52.75) },
       INT32_C(          82),
      {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(  -490.16), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(    52.75) } },
    { UINT8_C( 73),
      {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(   -82.84), SIMDE_FLOAT32_C(   262.82), SIMDE_FLOAT32_C(  -976.36) },
       INT32_C(         195),
      {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(  -976.36) } },
    { UINT8_C(175),
      {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(  -693.64), SIMDE_FLOAT32_C(  -971.72), SIMDE_FLOAT32_C(   -82.61) },
       INT32_C(          52),
      {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(  -693.62), SIMDE_FLOAT32_C(  -971.75), SIMDE_FLOAT32_C(   -82.62) } },
    { UINT8_C( 93),
      {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(  -136.88), SIMDE_FLOAT32_C(    78.11), SIMDE_FLOAT32_C(  -210.16) },
       INT32_C(          16),
      {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(    78.00), SIMDE_FLOAT32_C(  -210.00) } },
    { UINT8_C(240),
      { SIMDE_FLOAT32_C(   385.54), SIMDE_FLOAT32_C(   702.48), SIMDE_FLOAT32_C(  -960.83), SIMDE_FLOAT32_C(  -633.62) },
       INT32_C(         225),
      { SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00) } },
    { UINT8_C(112),
      { SIMDE_FLOAT32_C(  -710.21),      SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(  -263.45), SIMDE_FLOAT32_C(  -686.56) },
       INT32_C(         226),
      { SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00) } },
  };

  simde__m128 a, r;

  a = simde_mm_loadu_ps(test_vec[0].a);
  r = simde_mm_maskz_roundscale_ps(test_vec[0].k, a, INT32_C(         176));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[0].r), 1);

  a = simde_mm_loadu_ps(test_vec[1].a);
  r = simde_mm_maskz_roundscale_ps(test_vec[1].k, a, INT32_C(         161));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[1].r), 1);

  a = simde_mm_loadu_ps(test_vec[2].a);
  r = simde_mm_maskz_roundscale_ps(test_vec[2].k, a, INT32_C(          82));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[2].r), 1);

  a = simde_mm_loadu_ps(test_vec[3].a);
  r = simde_mm_maskz_roundscale_ps(test_vec[3].k, a, INT32_C(         195));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[3].r), 1);

  a = simde_mm_loadu_ps(test_vec[4].a);
  r = simde_mm_maskz_roundscale_ps(test_vec[4].k, a, INT32_C(          52));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[4].r), 1);

  a = simde_mm_loadu_ps(test_vec[5].a);
  r = simde_mm_maskz_roundscale_ps(test_vec[5].k, a, INT32_C(          16));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[5].r), 1);

  a = simde_mm_loadu_ps(test_vec[6].a);
  r = simde_mm_maskz_roundscale_ps(test_vec[6].k, a, INT32_C(         225));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[6].r), 1);

  a = simde_mm_loadu_ps(test_vec[7].a);
  r = simde_mm_maskz_roundscale_ps(test_vec[7].k, a, INT32_C(         226));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[7].r), 1);

  return 0;
#else
  fputc('\n', stdout);
  int round_type[5] = {SIMDE_MM_FROUND_TO_NEAREST_INT, SIMDE_MM_FROUND_TO_NEG_INF, SIMDE_MM_FROUND_TO_POS_INF, SIMDE_MM_FROUND_TO_ZERO, SIMDE_MM_FROUND_CUR_DIRECTION};
  for (int i = 0 ; i < 8 ; i++) {
    simde__mmask8 k = simde_test_x86_random_mmask8();
    simde__m128 a = simde_test_x86_random_f32x4(SIMDE_FLOAT32_C(-1000.0), SIMDE_FLOAT32_C(1000.0));
    if((simde_test_codegen_rand() & 1)) {
      if((simde_test_codegen_rand() & 1))
        a = simde_mm_blend_ps(a, simde_mm_set1_ps(SIMDE_MATH_NANF), 1);
      else {
        if((simde_test_codegen_rand() & 1))
          a = simde_mm_blend_ps(a, simde_mm_set1_ps(SIMDE_MATH_INFINITY), 2);
        else
          a = simde_mm_blend_ps(a, simde_mm_set1_ps(-SIMDE_MATH_INFINITY), 2);
      }
    }
    int imm8 = ((simde_test_codegen_rand() & 15) << 4 | round_type[i % 5]) & 255;
    simde__m128 r;
    SIMDE_CONSTIFY_256_(simde_mm_maskz_roundscale_ps, r, simde_mm_setzero_ps(), imm8, k, a);

    simde_test_x86_write_mmask8(2, k, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_f32x4(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i32(2, imm8, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_f32x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm256_roundscale_ps (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const simde_float32 a[8];
    const int32_t imm8;
    const simde_float32 r[8];
  } test_vec[] = {
    { { SIMDE_FLOAT32_C(   680.63),      SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(   441.98), SIMDE_FLOAT32_C(   661.29),
        SIMDE_FLOAT32_C(    38.40), SIMDE_FLOAT32_C(  -974.53), SIMDE_FLOAT32_C(   579.66), SIMDE_FLOAT32_C(  -989.32) },
       INT32_C(           0),
      { SIMDE_FLOAT32_C(   681.00),      SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(   442.00), SIMDE_FLOAT32_C(   661.00),
        SIMDE_FLOAT32_C(    38.00), SIMDE_FLOAT32_C(  -975.00), SIMDE_FLOAT32_C(   580.00), SIMDE_FLOAT32_C(  -989.00) } },
    { { SIMDE_FLOAT32_C(  -684.35), SIMDE_FLOAT32_C(   -10.18), SIMDE_FLOAT32_C(  -771.27), SIMDE_FLOAT32_C(  -448.98),
        SIMDE_FLOAT32_C(   301.51), SIMDE_FLOAT32_C(   239.71), SIMDE_FLOAT32_C(   730.34), SIMDE_FLOAT32_C(   112.35) },
       INT32_C(          16),
      { SIMDE_FLOAT32_C(  -684.50), SIMDE_FLOAT32_C(   -10.00), SIMDE_FLOAT32_C(  -771.50), SIMDE_FLOAT32_C(  -449.00),
        SIMDE_FLOAT32_C(   301.50), SIMDE_FLOAT32_C(   239.50), SIMDE_FLOAT32_C(   730.50), SIMDE_FLOAT32_C(   112.50) } },
    { { SIMDE_FLOAT32_C(   927.48), SIMDE_FLOAT32_C(  -663.37), SIMDE_FLOAT32_C(  -126.17), SIMDE_FLOAT32_C(   917.27),
        SIMDE_FLOAT32_C(   824.25), SIMDE_FLOAT32_C(  -774.04), SIMDE_FLOAT32_C(   704.40), SIMDE_FLOAT32_C(  -459.07) },
       INT32_C(          32),
      { SIMDE_FLOAT32_C(   927.50), SIMDE_FLOAT32_C(  -663.25), SIMDE_FLOAT32_C(  -126.25), SIMDE_FLOAT32_C(   917.25),
        SIMDE_FLOAT32_C(   824.25), SIMDE_FLOAT32_C(  -774.00), SIMDE_FLOAT32_C(   704.50), SIMDE_FLOAT32_C(  -459.00) } },
    { { SIMDE_FLOAT32_C(  -841.48),      SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(   -22.59), SIMDE_FLOAT32_C(   528.01),
        SIMDE_FLOAT32_C(    -3.94), SIMDE_FLOAT32_C(  -361.30), SIMDE_FLOAT32_C(  -433.59), SIMDE_FLOAT32_C(    21.54) },
       INT32_C(          48),
      { SIMDE_FLOAT32_C(  -841.50),      SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(   -22.62), SIMDE_FLOAT32_C(   528.00),
        SIMDE_FLOAT32_C(    -4.00), SIMDE_FLOAT32_C(  -361.25), SIMDE_FLOAT32_C(  -433.62), SIMDE_FLOAT32_C(    21.50) } },
    { { SIMDE_FLOAT32_C(  -339.97), SIMDE_FLOAT32_C(   658.60), SIMDE_FLOAT32_C(   408.96), SIMDE_FLOAT32_C(   649.85),
        SIMDE_FLOAT32_C(   887.33), SIMDE_FLOAT32_C(   959.98), SIMDE_FLOAT32_C(   -48.64), SIMDE_FLOAT32_C(   127.05) },
       INT32_C(          64),
      { SIMDE_FLOAT32_C(  -340.00), SIMDE_FLOAT32_C(   658.62), SIMDE_FLOAT32_C(   408.94), SIMDE_FLOAT32_C(   649.88),
        SIMDE_FLOAT32_C(   887.31), SIMDE_FLOAT32_C(   960.00), SIMDE_FLOAT32_C(   -48.62), SIMDE_FLOAT32_C(   127.06) } },
    { {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(  -528.44), SIMDE_FLOAT32_C(   617.81), SIMDE_FLOAT32_C(  -599.66),
        SIMDE_FLOAT32_C(   345.39), SIMDE_FLOAT32_C(   535.08), SIMDE_FLOAT32_C(  -775.41), SIMDE_FLOAT32_C(   571.35) },
       INT32_C(          80),
      {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(  -528.44), SIMDE_FLOAT32_C(   617.81), SIMDE_FLOAT32_C(  -599.66),
        SIMDE_FLOAT32_C(   345.38), SIMDE_FLOAT32_C(   535.09), SIMDE_FLOAT32_C(  -775.41), SIMDE_FLOAT32_C(   571.34) } },
    { { SIMDE_FLOAT32_C(  -131.87), SIMDE_FLOAT32_C(   397.99), SIMDE_FLOAT32_C(  -680.39), SIMDE_FLOAT32_C(   845.53),
        SIMDE_FLOAT32_C(   -74.00), SIMDE_FLOAT32_C(   315.67), SIMDE_FLOAT32_C(  -515.77), SIMDE_FLOAT32_C(   492.41) },
       INT32_C(          96),
      { SIMDE_FLOAT32_C(  -131.88), SIMDE_FLOAT32_C(   397.98), SIMDE_FLOAT32_C(  -680.39), SIMDE_FLOAT32_C(   845.53),
        SIMDE_FLOAT32_C(   -74.00), SIMDE_FLOAT32_C(   315.67), SIMDE_FLOAT32_C(  -515.77), SIMDE_FLOAT32_C(   492.41) } },
    { {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(  -930.49), SIMDE_FLOAT32_C(   430.51), SIMDE_FLOAT32_C(   362.62),
        SIMDE_FLOAT32_C(   728.11), SIMDE_FLOAT32_C(  -160.53), SIMDE_FLOAT32_C(    12.46), SIMDE_FLOAT32_C(   615.44) },
       INT32_C(         112),
      {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(  -930.49), SIMDE_FLOAT32_C(   430.51), SIMDE_FLOAT32_C(   362.62),
        SIMDE_FLOAT32_C(   728.11), SIMDE_FLOAT32_C(  -160.53), SIMDE_FLOAT32_C(    12.46), SIMDE_FLOAT32_C(   615.44) } },
    { {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(  -510.23), SIMDE_FLOAT32_C(  -972.46), SIMDE_FLOAT32_C(   214.05),
        SIMDE_FLOAT32_C(  -892.43), SIMDE_FLOAT32_C(  -572.12), SIMDE_FLOAT32_C(  -440.56), SIMDE_FLOAT32_C(   642.65) },
       INT32_C(         128),
      {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(  -510.23), SIMDE_FLOAT32_C(  -972.46), SIMDE_FLOAT32_C(   214.05),
        SIMDE_FLOAT32_C(  -892.43), SIMDE_FLOAT32_C(  -572.12), SIMDE_FLOAT32_C(  -440.56), SIMDE_FLOAT32_C(   642.65) } },
    { { SIMDE_FLOAT32_C(  -117.87), SIMDE_FLOAT32_C(   418.00), SIMDE_FLOAT32_C(    -1.08), SIMDE_FLOAT32_C(  -719.88),
        SIMDE_FLOAT32_C(   737.60), SIMDE_FLOAT32_C(  -155.55), SIMDE_FLOAT32_C(   206.13), SIMDE_FLOAT32_C(    53.27) },
       INT32_C(         144),
      { SIMDE_FLOAT32_C(  -117.87), SIMDE_FLOAT32_C(   418.00), SIMDE_FLOAT32_C(    -1.08), SIMDE_FLOAT32_C(  -719.88),
        SIMDE_FLOAT32_C(   737.60), SIMDE_FLOAT32_C(  -155.55), SIMDE_FLOAT32_C(   206.13), SIMDE_FLOAT32_C(    53.27) } },
    { {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(   390.47), SIMDE_FLOAT32_C(  -968.73), SIMDE_FLOAT32_C(  -231.95),
        SIMDE_FLOAT32_C(  -179.02), SIMDE_FLOAT32_C(   393.89), SIMDE_FLOAT32_C(  -503.84), SIMDE_FLOAT32_C(   660.45) },
       INT32_C(         160),
      {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(   390.47), SIMDE_FLOAT32_C(  -968.73), SIMDE_FLOAT32_C(  -231.95),
        SIMDE_FLOAT32_C(  -179.02), SIMDE_FLOAT32_C(   393.89), SIMDE_FLOAT32_C(  -503.84), SIMDE_FLOAT32_C(   660.45) } },
    { { SIMDE_FLOAT32_C(  -540.10), SIMDE_FLOAT32_C(  -629.83), SIMDE_FLOAT32_C(  -145.91), SIMDE_FLOAT32_C(   -50.34),
        SIMDE_FLOAT32_C(  -602.29), SIMDE_FLOAT32_C(  -931.86), SIMDE_FLOAT32_C(    57.24), SIMDE_FLOAT32_C(  -174.41) },
       INT32_C(         176),
      { SIMDE_FLOAT32_C(  -540.10), SIMDE_FLOAT32_C(  -629.83), SIMDE_FLOAT32_C(  -145.91), SIMDE_FLOAT32_C(   -50.34),
        SIMDE_FLOAT32_C(  -602.29), SIMDE_FLOAT32_C(  -931.86), SIMDE_FLOAT32_C(    57.24), SIMDE_FLOAT32_C(  -174.41) } },
    { { SIMDE_FLOAT32_C(  -300.11), SIMDE_FLOAT32_C(   478.06), SIMDE_FLOAT32_C(  -241.63), SIMDE_FLOAT32_C(   582.02),
        SIMDE_FLOAT32_C(  -103.95), SIMDE_FLOAT32_C(   757.29), SIMDE_FLOAT32_C(   862.15), SIMDE_FLOAT32_C(  -366.35) },
       INT32_C(         192),
      { SIMDE_FLOAT32_C(  -300.11), SIMDE_FLOAT32_C(   478.06), SIMDE_FLOAT32_C(  -241.63), SIMDE_FLOAT32_C(   582.02),
        SIMDE_FLOAT32_C(  -103.95), SIMDE_FLOAT32_C(   757.29), SIMDE_FLOAT32_C(   862.15), SIMDE_FLOAT32_C(  -366.35) } },
    { { SIMDE_FLOAT32_C(    68.27), SIMDE_FLOAT32_C(   686.92), SIMDE_FLOAT32_C(   930.42), SIMDE_FLOAT32_C(   766.81),
        SIMDE_FLOAT32_C(    77.39), SIMDE_FLOAT32_C(   961.69), SIMDE_FLOAT32_C(  -465.14), SIMDE_FLOAT32_C(   898.37) },
       INT32_C(         208),
      { SIMDE_FLOAT32_C(    68.27), SIMDE_FLOAT32_C(   686.92), SIMDE_FLOAT32_C(   930.42), SIMDE_FLOAT32_C(   766.81),
        SIMDE_FLOAT32_C(    77.39), SIMDE_FLOAT32_C(   961.69), SIMDE_FLOAT32_C(  -465.14), SIMDE_FLOAT32_C(   898.37) } },
    { { SIMDE_FLOAT32_C(    31.02), SIMDE_FLOAT32_C(   558.82), SIMDE_FLOAT32_C(   761.92), SIMDE_FLOAT32_C(   142.63),
        SIMDE_FLOAT32_C(  -981.28), SIMDE_FLOAT32_C(  -867.91), SIMDE_FLOAT32_C(   996.72), SIMDE_FLOAT32_C(   -31.62) },
       INT32_C(         224),
      { SIMDE_FLOAT32_C(    31.02), SIMDE_FLOAT32_C(   558.82), SIMDE_FLOAT32_C(   761.92), SIMDE_FLOAT32_C(   142.63),
        SIMDE_FLOAT32_C(  -981.28), SIMDE_FLOAT32_C(  -867.91), SIMDE_FLOAT32_C(   996.72), SIMDE_FLOAT32_C(   -31.62) } },
    { { SIMDE_FLOAT32_C(  -935.13),      SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(   355.39), SIMDE_FLOAT32_C(  -307.55),
        SIMDE_FLOAT32_C(  -274.48), SIMDE_FLOAT32_C(  -166.56), SIMDE_FLOAT32_C(   450.82), SIMDE_FLOAT32_C(  -692.46) },
       INT32_C(         240),
      { SIMDE_FLOAT32_C(  -935.13),      SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(   355.39), SIMDE_FLOAT32_C(  -307.55),
        SIMDE_FLOAT32_C(  -274.48), SIMDE_FLOAT32_C(  -166.56), SIMDE_FLOAT32_C(   450.82), SIMDE_FLOAT32_C(  -692.46) } },
    { {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(   809.84), SIMDE_FLOAT32_C(   237.96), SIMDE_FLOAT32_C(  -949.93),
        SIMDE_FLOAT32_C(   740.26), SIMDE_FLOAT32_C(     4.77), SIMDE_FLOAT32_C(   127.46), SIMDE_FLOAT32_C(   701.95) },
       INT32_C(           1),
      {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(   809.00), SIMDE_FLOAT32_C(   237.00), SIMDE_FLOAT32_C(  -950.00),
        SIMDE_FLOAT32_C(   740.00), SIMDE_FLOAT32_C(     4.00), SIMDE_FLOAT32_C(   127.00), SIMDE_FLOAT32_C(   701.00) } },
    { { SIMDE_FLOAT32_C(    57.52), SIMDE_FLOAT32_C(  -429.34), SIMDE_FLOAT32_C(  -415.34), SIMDE_FLOAT32_C(  -180.55),
        SIMDE_FLOAT32_C(   713.28), SIMDE_FLOAT32_C(  -396.62), SIMDE_FLOAT32_C(   -48.46), SIMDE_FLOAT32_C(   710.01) },
       INT32_C(          17),
      { SIMDE_FLOAT32_C(    57.50), SIMDE_FLOAT32_C(  -429.50), SIMDE_FLOAT32_C(  -415.50), SIMDE_FLOAT32_C(  -181.00),
        SIMDE_FLOAT32_C(   713.00), SIMDE_FLOAT32_C(  -397.00), SIMDE_FLOAT32_C(   -48.50), SIMDE_FLOAT32_C(   710.00) } },
    { {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(   774.87), SIMDE_FLOAT32_C(   597.38), SIMDE_FLOAT32_C(  -163.27),
        SIMDE_FLOAT32_C(  -532.68), SIMDE_FLOAT32_C(  -677.10), SIMDE_FLOAT32_C(   670.17), SIMDE_FLOAT32_C(   918.14) },
       INT32_C(          33),
      {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(   774.75), SIMDE_FLOAT32_C(   597.25), SIMDE_FLOAT32_C(  -163.50),
        SIMDE_FLOAT32_C(  -532.75), SIMDE_FLOAT32_C(  -677.25), SIMDE_FLOAT32_C(   670.00), SIMDE_FLOAT32_C(   918.00) } },
    { { SIMDE_FLOAT32_C(   126.25), SIMDE_FLOAT32_C(  -199.87), SIMDE_FLOAT32_C(   762.81), SIMDE_FLOAT32_C(   -63.91),
        SIMDE_FLOAT32_C(  -961.91), SIMDE_FLOAT32_C(   812.88), SIMDE_FLOAT32_C(  -323.65), SIMDE_FLOAT32_C(    42.86) },
       INT32_C(          49),
      { SIMDE_FLOAT32_C(   126.25), SIMDE_FLOAT32_C(  -199.88), SIMDE_FLOAT32_C(   762.75), SIMDE_FLOAT32_C(   -64.00),
        SIMDE_FLOAT32_C(  -962.00), SIMDE_FLOAT32_C(   812.88), SIMDE_FLOAT32_C(  -323.75), SIMDE_FLOAT32_C(    42.75) } },
    { { SIMDE_FLOAT32_C(  -621.70), SIMDE_FLOAT32_C(  -417.51), SIMDE_FLOAT32_C(   966.17), SIMDE_FLOAT32_C(   435.83),
        SIMDE_FLOAT32_C(   153.15), SIMDE_FLOAT32_C(  -449.17), SIMDE_FLOAT32_C(  -744.73), SIMDE_FLOAT32_C(  -133.57) },
       INT32_C(          65),
      { SIMDE_FLOAT32_C(  -621.75), SIMDE_FLOAT32_C(  -417.56), SIMDE_FLOAT32_C(   966.12), SIMDE_FLOAT32_C(   435.81),
        SIMDE_FLOAT32_C(   153.12), SIMDE_FLOAT32_C(  -449.19), SIMDE_FLOAT32_C(  -744.75), SIMDE_FLOAT32_C(  -133.62) } },
    { {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(  -423.56), SIMDE_FLOAT32_C(  -274.03), SIMDE_FLOAT32_C(  -311.84),
        SIMDE_FLOAT32_C(  -648.69), SIMDE_FLOAT32_C(  -676.65), SIMDE_FLOAT32_C(   524.89), SIMDE_FLOAT32_C(  -181.37) },
       INT32_C(          81),
      {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(  -423.56), SIMDE_FLOAT32_C(  -274.03), SIMDE_FLOAT32_C(  -311.84),
        SIMDE_FLOAT32_C(  -648.72), SIMDE_FLOAT32_C(  -676.66), SIMDE_FLOAT32_C(   524.88), SIMDE_FLOAT32_C(  -181.38) } },
    { {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(   276.69), SIMDE_FLOAT32_C(  -405.28), SIMDE_FLOAT32_C(   863.01),
        SIMDE_FLOAT32_C(  -923.18), SIMDE_FLOAT32_C(  -642.46), SIMDE_FLOAT32_C(  -200.90), SIMDE_FLOAT32_C(  -885.09) },
       INT32_C(          97),
      {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(   276.69), SIMDE_FLOAT32_C(  -405.28), SIMDE_FLOAT32_C(   863.00),
        SIMDE_FLOAT32_C(  -923.19), SIMDE_FLOAT32_C(  -642.47), SIMDE_FLOAT32_C(  -200.91), SIMDE_FLOAT32_C(  -885.09) } },
    { { SIMDE_FLOAT32_C(   157.77), SIMDE_FLOAT32_C(   110.75), SIMDE_FLOAT32_C(   853.76), SIMDE_FLOAT32_C(   740.26),
        SIMDE_FLOAT32_C(    76.93), SIMDE_FLOAT32_C(   289.58), SIMDE_FLOAT32_C(  -106.60), SIMDE_FLOAT32_C(   627.76) },
       INT32_C(         113),
      { SIMDE_FLOAT32_C(   157.77), SIMDE_FLOAT32_C(   110.75), SIMDE_FLOAT32_C(   853.76), SIMDE_FLOAT32_C(   740.26),
        SIMDE_FLOAT32_C(    76.93), SIMDE_FLOAT32_C(   289.58), SIMDE_FLOAT32_C(  -106.60), SIMDE_FLOAT32_C(   627.76) } },
    { { SIMDE_FLOAT32_C(   759.84), SIMDE_FLOAT32_C(  -218.03), SIMDE_FLOAT32_C(  -248.33), SIMDE_FLOAT32_C(  -663.72),
        SIMDE_FLOAT32_C(   507.94), SIMDE_FLOAT32_C(   439.83), SIMDE_FLOAT32_C(  -312.42), SIMDE_FLOAT32_C(   831.29) },
       INT32_C(         129),
      { SIMDE_FLOAT32_C(   759.84), SIMDE_FLOAT32_C(  -218.03), SIMDE_FLOAT32_C(  -248.33), SIMDE_FLOAT32_C(  -663.72),
        SIMDE_FLOAT32_C(   507.94), SIMDE_FLOAT32_C(   439.83), SIMDE_FLOAT32_C(  -312.42), SIMDE_FLOAT32_C(   831.29) } },
    { {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(  -522.46), SIMDE_FLOAT32_C(  -840.22), SIMDE_FLOAT32_C(  -757.02),
        SIMDE_FLOAT32_C(   754.24), SIMDE_FLOAT32_C(  -245.50), SIMDE_FLOAT32_C(  -894.01), SIMDE_FLOAT32_C(   831.06) },
       INT32_C(         145),
      {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(  -522.46), SIMDE_FLOAT32_C(  -840.22), SIMDE_FLOAT32_C(  -757.02),
        SIMDE_FLOAT32_C(   754.24), SIMDE_FLOAT32_C(  -245.50), SIMDE_FLOAT32_C(  -894.01), SIMDE_FLOAT32_C(   831.06) } },
    { { SIMDE_FLOAT32_C(   945.97), SIMDE_FLOAT32_C(   282.45), SIMDE_FLOAT32_C(  -619.45), SIMDE_FLOAT32_C(   103.74),
        SIMDE_FLOAT32_C(  -606.79), SIMDE_FLOAT32_C(  -765.70), SIMDE_FLOAT32_C(  -156.01), SIMDE_FLOAT32_C(   470.14) },
       INT32_C(         161),
      { SIMDE_FLOAT32_C(   945.97), SIMDE_FLOAT32_C(   282.45), SIMDE_FLOAT32_C(  -619.45), SIMDE_FLOAT32_C(   103.74),
        SIMDE_FLOAT32_C(  -606.79), SIMDE_FLOAT32_C(  -765.70), SIMDE_FLOAT32_C(  -156.01), SIMDE_FLOAT32_C(   470.14) } },
    { { SIMDE_FLOAT32_C(   737.40), SIMDE_FLOAT32_C(    97.90), SIMDE_FLOAT32_C(    68.75), SIMDE_FLOAT32_C(   497.23),
        SIMDE_FLOAT32_C(   879.86), SIMDE_FLOAT32_C(   820.42), SIMDE_FLOAT32_C(   833.51), SIMDE_FLOAT32_C(   387.80) },
       INT32_C(         177),
      { SIMDE_FLOAT32_C(   737.40), SIMDE_FLOAT32_C(    97.90), SIMDE_FLOAT32_C(    68.75), SIMDE_FLOAT32_C(   497.23),
        SIMDE_FLOAT32_C(   879.86), SIMDE_FLOAT32_C(   820.42), SIMDE_FLOAT32_C(   833.51), SIMDE_FLOAT32_C(   387.80) } },
    { { SIMDE_FLOAT32_C(  -478.91), SIMDE_FLOAT32_C(   219.09), SIMDE_FLOAT32_C(  -775.03), SIMDE_FLOAT32_C(  -972.69),
        SIMDE_FLOAT32_C(   696.63), SIMDE_FLOAT32_C(  -615.25), SIMDE_FLOAT32_C(  -729.71), SIMDE_FLOAT32_C(   450.87) },
       INT32_C(         193),
      { SIMDE_FLOAT32_C(  -478.91), SIMDE_FLOAT32_C(   219.09), SIMDE_FLOAT32_C(  -775.03), SIMDE_FLOAT32_C(  -972.69),
        SIMDE_FLOAT32_C(   696.63), SIMDE_FLOAT32_C(  -615.25), SIMDE_FLOAT32_C(  -729.71), SIMDE_FLOAT32_C(   450.87) } },
    { {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(   281.93), SIMDE_FLOAT32_C(  -748.71), SIMDE_FLOAT32_C(   281.37),
        SIMDE_FLOAT32_C(   227.90), SIMDE_FLOAT32_C(   533.74), SIMDE_FLOAT32_C(   661.92), SIMDE_FLOAT32_C(  -668.36) },
       INT32_C(         209),
      {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(   281.93), SIMDE_FLOAT32_C(  -748.71), SIMDE_FLOAT32_C(   281.37),
        SIMDE_FLOAT32_C(   227.90), SIMDE_FLOAT32_C(   533.74), SIMDE_FLOAT32_C(   661.92), SIMDE_FLOAT32_C(  -668.36) } },
    { {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(   397.08), SIMDE_FLOAT32_C(   420.11), SIMDE_FLOAT32_C(   -86.97),
        SIMDE_FLOAT32_C(  -505.02), SIMDE_FLOAT32_C(  -511.14), SIMDE_FLOAT32_C(  -589.74), SIMDE_FLOAT32_C(  -625.15) },
       INT32_C(         225),
      {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(   397.08), SIMDE_FLOAT32_C(   420.11), SIMDE_FLOAT32_C(   -86.97),
        SIMDE_FLOAT32_C(  -505.02), SIMDE_FLOAT32_C(  -511.14), SIMDE_FLOAT32_C(  -589.74), SIMDE_FLOAT32_C(  -625.15) } },
    { { SIMDE_FLOAT32_C(   762.65),     -SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(  -235.14), SIMDE_FLOAT32_C(   -18.26),
        SIMDE_FLOAT32_C(   794.49), SIMDE_FLOAT32_C(  -207.83), SIMDE_FLOAT32_C(  -321.63), SIMDE_FLOAT32_C(  -820.76) },
       INT32_C(         241),
      { SIMDE_FLOAT32_C(   762.65),     -SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(  -235.14), SIMDE_FLOAT32_C(   -18.26),
        SIMDE_FLOAT32_C(   794.49), SIMDE_FLOAT32_C(  -207.83), SIMDE_FLOAT32_C(  -321.63), SIMDE_FLOAT32_C(  -820.76) } },
    { { SIMDE_FLOAT32_C(   438.74),      SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(   569.77), SIMDE_FLOAT32_C(  -279.89),
        SIMDE_FLOAT32_C(  -360.93), SIMDE_FLOAT32_C(   103.51), SIMDE_FLOAT32_C(  -617.97), SIMDE_FLOAT32_C(   -29.30) },
       INT32_C(           2),
      { SIMDE_FLOAT32_C(   439.00),      SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(   570.00), SIMDE_FLOAT32_C(  -279.00),
        SIMDE_FLOAT32_C(  -360.00), SIMDE_FLOAT32_C(   104.00), SIMDE_FLOAT32_C(  -617.00), SIMDE_FLOAT32_C(   -29.00) } },
    { {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(   698.37), SIMDE_FLOAT32_C(    59.36), SIMDE_FLOAT32_C(   -77.47),
        SIMDE_FLOAT32_C(  -812.77), SIMDE_FLOAT32_C(   469.62), SIMDE_FLOAT32_C(   297.37), SIMDE_FLOAT32_C(  -503.49) },
       INT32_C(          18),
      {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(   698.50), SIMDE_FLOAT32_C(    59.50), SIMDE_FLOAT32_C(   -77.00),
        SIMDE_FLOAT32_C(  -812.50), SIMDE_FLOAT32_C(   470.00), SIMDE_FLOAT32_C(   297.50), SIMDE_FLOAT32_C(  -503.00) } },
    { { SIMDE_FLOAT32_C(  -933.97),     -SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(  -958.24), SIMDE_FLOAT32_C(   860.53),
        SIMDE_FLOAT32_C(   270.43), SIMDE_FLOAT32_C(  -279.88), SIMDE_FLOAT32_C(  -960.23), SIMDE_FLOAT32_C(  -667.11) },
       INT32_C(          34),
      { SIMDE_FLOAT32_C(  -933.75),     -SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(  -958.00), SIMDE_FLOAT32_C(   860.75),
        SIMDE_FLOAT32_C(   270.50), SIMDE_FLOAT32_C(  -279.75), SIMDE_FLOAT32_C(  -960.00), SIMDE_FLOAT32_C(  -667.00) } },
    { { SIMDE_FLOAT32_C(  -739.47),     -SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(  -508.26), SIMDE_FLOAT32_C(  -100.40),
        SIMDE_FLOAT32_C(  -968.46), SIMDE_FLOAT32_C(  -126.23), SIMDE_FLOAT32_C(   870.30), SIMDE_FLOAT32_C(    62.01) },
       INT32_C(          50),
      { SIMDE_FLOAT32_C(  -739.38),     -SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(  -508.25), SIMDE_FLOAT32_C(  -100.38),
        SIMDE_FLOAT32_C(  -968.38), SIMDE_FLOAT32_C(  -126.12), SIMDE_FLOAT32_C(   870.38), SIMDE_FLOAT32_C(    62.12) } },
    { { SIMDE_FLOAT32_C(  -149.60), SIMDE_FLOAT32_C(    75.99), SIMDE_FLOAT32_C(  -587.92), SIMDE_FLOAT32_C(    37.62),
        SIMDE_FLOAT32_C(  -454.39), SIMDE_FLOAT32_C(   709.46), SIMDE_FLOAT32_C(   534.13), SIMDE_FLOAT32_C(  -741.00) },
       INT32_C(          66),
      { SIMDE_FLOAT32_C(  -149.56), SIMDE_FLOAT32_C(    76.00), SIMDE_FLOAT32_C(  -587.88), SIMDE_FLOAT32_C(    37.62),
        SIMDE_FLOAT32_C(  -454.38), SIMDE_FLOAT32_C(   709.50), SIMDE_FLOAT32_C(   534.19), SIMDE_FLOAT32_C(  -741.00) } },
    { {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(  -262.74), SIMDE_FLOAT32_C(  -188.77), SIMDE_FLOAT32_C(   460.69),
        SIMDE_FLOAT32_C(  -992.31), SIMDE_FLOAT32_C(   531.36), SIMDE_FLOAT32_C(   500.46), SIMDE_FLOAT32_C(  -659.43) },
       INT32_C(          82),
      {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(  -262.72), SIMDE_FLOAT32_C(  -188.75), SIMDE_FLOAT32_C(   460.72),
        SIMDE_FLOAT32_C(  -992.28), SIMDE_FLOAT32_C(   531.38), SIMDE_FLOAT32_C(   500.47), SIMDE_FLOAT32_C(  -659.41) } },
    { {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(  -358.75), SIMDE_FLOAT32_C(   786.75), SIMDE_FLOAT32_C(  -396.06),
        SIMDE_FLOAT32_C(   540.85), SIMDE_FLOAT32_C(   818.29), SIMDE_FLOAT32_C(   477.71), SIMDE_FLOAT32_C(   411.15) },
       INT32_C(          98),
      {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(  -358.75), SIMDE_FLOAT32_C(   786.75), SIMDE_FLOAT32_C(  -396.05),
        SIMDE_FLOAT32_C(   540.86), SIMDE_FLOAT32_C(   818.30), SIMDE_FLOAT32_C(   477.72), SIMDE_FLOAT32_C(   411.16) } },
    { { SIMDE_FLOAT32_C(   427.78), SIMDE_FLOAT32_C(  -630.14), SIMDE_FLOAT32_C(   480.13), SIMDE_FLOAT32_C(  -496.23),
        SIMDE_FLOAT32_C(  -218.06), SIMDE_FLOAT32_C(  -482.24), SIMDE_FLOAT32_C(    49.39), SIMDE_FLOAT32_C(  -508.60) },
       INT32_C(         114),
      { SIMDE_FLOAT32_C(   427.78), SIMDE_FLOAT32_C(  -630.13), SIMDE_FLOAT32_C(   480.13), SIMDE_FLOAT32_C(  -496.23),
        SIMDE_FLOAT32_C(  -218.05), SIMDE_FLOAT32_C(  -482.23), SIMDE_FLOAT32_C(    49.39), SIMDE_FLOAT32_C(  -508.59) } },
    { {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(   260.88), SIMDE_FLOAT32_C(   652.05), SIMDE_FLOAT32_C(  -954.35),
        SIMDE_FLOAT32_C(  -927.89), SIMDE_FLOAT32_C(   112.74), SIMDE_FLOAT32_C(  -946.67), SIMDE_FLOAT32_C(   603.47) },
       INT32_C(         130),
      {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(   260.88), SIMDE_FLOAT32_C(   652.05), SIMDE_FLOAT32_C(  -954.35),
        SIMDE_FLOAT32_C(  -927.89), SIMDE_FLOAT32_C(   112.74), SIMDE_FLOAT32_C(  -946.67), SIMDE_FLOAT32_C(   603.47) } },
    { { SIMDE_FLOAT32_C(   984.19), SIMDE_FLOAT32_C(   471.92), SIMDE_FLOAT32_C(  -493.89), SIMDE_FLOAT32_C(  -374.56),
        SIMDE_FLOAT32_C(   258.67), SIMDE_FLOAT32_C(   110.05), SIMDE_FLOAT32_C(  -833.71), SIMDE_FLOAT32_C(    76.97) },
       INT32_C(         146),
      { SIMDE_FLOAT32_C(   984.19), SIMDE_FLOAT32_C(   471.92), SIMDE_FLOAT32_C(  -493.89), SIMDE_FLOAT32_C(  -374.56),
        SIMDE_FLOAT32_C(   258.67), SIMDE_FLOAT32_C(   110.05), SIMDE_FLOAT32_C(  -833.71), SIMDE_FLOAT32_C(    76.97) } },
    { { SIMDE_FLOAT32_C(   577.43),      SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(   217.49), SIMDE_FLOAT32_C(     5.21),
        SIMDE_FLOAT32_C(  -672.88), SIMDE_FLOAT32_C(  -302.38), SIMDE_FLOAT32_C(   508.99), SIMDE_FLOAT32_C(   109.06) },
       INT32_C(         162),
      { SIMDE_FLOAT32_C(   577.43),      SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(   217.49), SIMDE_FLOAT32_C(     5.21),
        SIMDE_FLOAT32_C(  -672.88), SIMDE_FLOAT32_C(  -302.38), SIMDE_FLOAT32_C(   508.99), SIMDE_FLOAT32_C(   109.06) } },
    { {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(   866.76), SIMDE_FLOAT32_C(  -138.66), SIMDE_FLOAT32_C(   -80.68),
        SIMDE_FLOAT32_C(   912.41), SIMDE_FLOAT32_C(   -66.55), SIMDE_FLOAT32_C(  -967.94), SIMDE_FLOAT32_C(   965.74) },
       INT32_C(         178),
      {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(   866.76), SIMDE_FLOAT32_C(  -138.66), SIMDE_FLOAT32_C(   -80.68),
        SIMDE_FLOAT32_C(   912.41), SIMDE_FLOAT32_C(   -66.55), SIMDE_FLOAT32_C(  -967.94), SIMDE_FLOAT32_C(   965.74) } },
    { { SIMDE_FLOAT32_C(  -640.35),     -SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(  -882.80), SIMDE_FLOAT32_C(  -134.25),
        SIMDE_FLOAT32_C(   146.55), SIMDE_FLOAT32_C(   375.87), SIMDE_FLOAT32_C(   975.80), SIMDE_FLOAT32_C(   312.84) },
       INT32_C(         194),
      { SIMDE_FLOAT32_C(  -640.35),     -SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(  -882.80), SIMDE_FLOAT32_C(  -134.25),
        SIMDE_FLOAT32_C(   146.55), SIMDE_FLOAT32_C(   375.87), SIMDE_FLOAT32_C(   975.80), SIMDE_FLOAT32_C(   312.84) } },
    { {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(   781.05), SIMDE_FLOAT32_C(   895.48), SIMDE_FLOAT32_C(  -262.78),
        SIMDE_FLOAT32_C(  -521.33), SIMDE_FLOAT32_C(   404.47), SIMDE_FLOAT32_C(   846.28), SIMDE_FLOAT32_C(   694.05) },
       INT32_C(         210),
      {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(   781.05), SIMDE_FLOAT32_C(   895.48), SIMDE_FLOAT32_C(  -262.78),
        SIMDE_FLOAT32_C(  -521.33), SIMDE_FLOAT32_C(   404.47), SIMDE_FLOAT32_C(   846.28), SIMDE_FLOAT32_C(   694.05) } },
    { {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(   829.61), SIMDE_FLOAT32_C(  -691.92), SIMDE_FLOAT32_C(   880.64),
        SIMDE_FLOAT32_C(   742.02), SIMDE_FLOAT32_C(   241.53), SIMDE_FLOAT32_C(   912.71), SIMDE_FLOAT32_C(   707.76) },
       INT32_C(         226),
      {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(   829.61), SIMDE_FLOAT32_C(  -691.92), SIMDE_FLOAT32_C(   880.64),
        SIMDE_FLOAT32_C(   742.02), SIMDE_FLOAT32_C(   241.53), SIMDE_FLOAT32_C(   912.71), SIMDE_FLOAT32_C(   707.76) } },
    { {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(  -700.45), SIMDE_FLOAT32_C(  -324.83), SIMDE_FLOAT32_C(   -66.85),
        SIMDE_FLOAT32_C(   446.10), SIMDE_FLOAT32_C(  -948.96), SIMDE_FLOAT32_C(   -91.05), SIMDE_FLOAT32_C(  -241.06) },
       INT32_C(         242),
      {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(  -700.45), SIMDE_FLOAT32_C(  -324.83), SIMDE_FLOAT32_C(   -66.85),
        SIMDE_FLOAT32_C(   446.10), SIMDE_FLOAT32_C(  -948.96), SIMDE_FLOAT32_C(   -91.05), SIMDE_FLOAT32_C(  -241.06) } },
    { { SIMDE_FLOAT32_C(   649.21), SIMDE_FLOAT32_C(   -86.03), SIMDE_FLOAT32_C(   253.56), SIMDE_FLOAT32_C(   544.69),
        SIMDE_FLOAT32_C(   651.19), SIMDE_FLOAT32_C(   732.23), SIMDE_FLOAT32_C(   -50.84), SIMDE_FLOAT32_C(   497.48) },
       INT32_C(           3),
      { SIMDE_FLOAT32_C(   649.00), SIMDE_FLOAT32_C(   -86.00), SIMDE_FLOAT32_C(   253.00), SIMDE_FLOAT32_C(   544.00),
        SIMDE_FLOAT32_C(   651.00), SIMDE_FLOAT32_C(   732.00), SIMDE_FLOAT32_C(   -50.00), SIMDE_FLOAT32_C(   497.00) } },
    { { SIMDE_FLOAT32_C(   -87.99), SIMDE_FLOAT32_C(   -55.78), SIMDE_FLOAT32_C(  -612.39), SIMDE_FLOAT32_C(  -258.38),
        SIMDE_FLOAT32_C(   252.30), SIMDE_FLOAT32_C(  -731.75), SIMDE_FLOAT32_C(  -516.36), SIMDE_FLOAT32_C(  -506.18) },
       INT32_C(          19),
      { SIMDE_FLOAT32_C(   -87.50), SIMDE_FLOAT32_C(   -55.50), SIMDE_FLOAT32_C(  -612.00), SIMDE_FLOAT32_C(  -258.00),
        SIMDE_FLOAT32_C(   252.00), SIMDE_FLOAT32_C(  -731.50), SIMDE_FLOAT32_C(  -516.00), SIMDE_FLOAT32_C(  -506.00) } },
    { { SIMDE_FLOAT32_C(  -808.61), SIMDE_FLOAT32_C(  -727.73), SIMDE_FLOAT32_C(  -261.07), SIMDE_FLOAT32_C(  -741.21),
        SIMDE_FLOAT32_C(  -428.18), SIMDE_FLOAT32_C(   414.11), SIMDE_FLOAT32_C(   191.95), SIMDE_FLOAT32_C(  -982.08) },
       INT32_C(          35),
      { SIMDE_FLOAT32_C(  -808.50), SIMDE_FLOAT32_C(  -727.50), SIMDE_FLOAT32_C(  -261.00), SIMDE_FLOAT32_C(  -741.00),
        SIMDE_FLOAT32_C(  -428.00), SIMDE_FLOAT32_C(   414.00), SIMDE_FLOAT32_C(   191.75), SIMDE_FLOAT32_C(  -982.00) } },
    { { SIMDE_FLOAT32_C(  -899.10),     -SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(   969.02), SIMDE_FLOAT32_C(   573.41),
        SIMDE_FLOAT32_C(  -573.94), SIMDE_FLOAT32_C(  -117.01), SIMDE_FLOAT32_C(  -173.03), SIMDE_FLOAT32_C(   970.75) },
       INT32_C(          51),
      { SIMDE_FLOAT32_C(  -899.00),     -SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(   969.00), SIMDE_FLOAT32_C(   573.38),
        SIMDE_FLOAT32_C(  -573.88), SIMDE_FLOAT32_C(  -117.00), SIMDE_FLOAT32_C(  -173.00), SIMDE_FLOAT32_C(   970.75) } },
    { { SIMDE_FLOAT32_C(  -968.33),      SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(   831.93), SIMDE_FLOAT32_C(   -24.11),
        SIMDE_FLOAT32_C(  -626.91), SIMDE_FLOAT32_C(  -426.45), SIMDE_FLOAT32_C(  -771.82), SIMDE_FLOAT32_C(  -358.66) },
       INT32_C(          67),
      { SIMDE_FLOAT32_C(  -968.31),      SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(   831.88), SIMDE_FLOAT32_C(   -24.06),
        SIMDE_FLOAT32_C(  -626.88), SIMDE_FLOAT32_C(  -426.44), SIMDE_FLOAT32_C(  -771.81), SIMDE_FLOAT32_C(  -358.62) } },
    { {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(    -5.73), SIMDE_FLOAT32_C(   561.23), SIMDE_FLOAT32_C(   507.37),
        SIMDE_FLOAT32_C(   566.09), SIMDE_FLOAT32_C(   -24.66), SIMDE_FLOAT32_C(  -300.68), SIMDE_FLOAT32_C(   584.01) },
       INT32_C(          83),
      {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(    -5.72), SIMDE_FLOAT32_C(   561.22), SIMDE_FLOAT32_C(   507.34),
        SIMDE_FLOAT32_C(   566.06), SIMDE_FLOAT32_C(   -24.66), SIMDE_FLOAT32_C(  -300.66), SIMDE_FLOAT32_C(   584.00) } },
    { { SIMDE_FLOAT32_C(  -639.13), SIMDE_FLOAT32_C(  -590.50), SIMDE_FLOAT32_C(  -626.37), SIMDE_FLOAT32_C(  -213.07),
        SIMDE_FLOAT32_C(   292.50), SIMDE_FLOAT32_C(   200.60), SIMDE_FLOAT32_C(  -242.32), SIMDE_FLOAT32_C(   826.69) },
       INT32_C(          99),
      { SIMDE_FLOAT32_C(  -639.12), SIMDE_FLOAT32_C(  -590.50), SIMDE_FLOAT32_C(  -626.36), SIMDE_FLOAT32_C(  -213.06),
        SIMDE_FLOAT32_C(   292.50), SIMDE_FLOAT32_C(   200.59), SIMDE_FLOAT32_C(  -242.31), SIMDE_FLOAT32_C(   826.69) } },
    { { SIMDE_FLOAT32_C(   677.60),     -SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(   745.29), SIMDE_FLOAT32_C(   509.53),
        SIMDE_FLOAT32_C(  -165.76), SIMDE_FLOAT32_C(  -881.62), SIMDE_FLOAT32_C(  -916.92), SIMDE_FLOAT32_C(    62.43) },
       INT32_C(         115),
      { SIMDE_FLOAT32_C(   677.59),     -SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(   745.29), SIMDE_FLOAT32_C(   509.52),
        SIMDE_FLOAT32_C(  -165.76), SIMDE_FLOAT32_C(  -881.62), SIMDE_FLOAT32_C(  -916.91), SIMDE_FLOAT32_C(    62.43) } },
    { {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(  -611.15), SIMDE_FLOAT32_C(  -221.29), SIMDE_FLOAT32_C(   143.25),
        SIMDE_FLOAT32_C(   896.22), SIMDE_FLOAT32_C(  -655.20), SIMDE_FLOAT32_C(  -881.42), SIMDE_FLOAT32_C(  -404.46) },
       INT32_C(         131),
      {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(  -611.15), SIMDE_FLOAT32_C(  -221.29), SIMDE_FLOAT32_C(   143.25),
        SIMDE_FLOAT32_C(   896.22), SIMDE_FLOAT32_C(  -655.20), SIMDE_FLOAT32_C(  -881.42), SIMDE_FLOAT32_C(  -404.46) } },
    { { SIMDE_FLOAT32_C(   395.76), SIMDE_FLOAT32_C(  -710.33), SIMDE_FLOAT32_C(   -31.43), SIMDE_FLOAT32_C(   769.40),
        SIMDE_FLOAT32_C(    76.60), SIMDE_FLOAT32_C(  -738.93), SIMDE_FLOAT32_C(   -30.00), SIMDE_FLOAT32_C(   834.28) },
       INT32_C(         147),
      { SIMDE_FLOAT32_C(   395.76), SIMDE_FLOAT32_C(  -710.33), SIMDE_FLOAT32_C(   -31.43), SIMDE_FLOAT32_C(   769.40),
        SIMDE_FLOAT32_C(    76.60), SIMDE_FLOAT32_C(  -738.93), SIMDE_FLOAT32_C(   -30.00), SIMDE_FLOAT32_C(   834.28) } },
    { {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(   511.89), SIMDE_FLOAT32_C(   946.11), SIMDE_FLOAT32_C(  -524.91),
        SIMDE_FLOAT32_C(    21.42), SIMDE_FLOAT32_C(  -219.65), SIMDE_FLOAT32_C(  -406.54), SIMDE_FLOAT32_C(   104.50) },
       INT32_C(         163),
      {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(   511.89), SIMDE_FLOAT32_C(   946.11), SIMDE_FLOAT32_C(  -524.91),
        SIMDE_FLOAT32_C(    21.42), SIMDE_FLOAT32_C(  -219.65), SIMDE_FLOAT32_C(  -406.54), SIMDE_FLOAT32_C(   104.50) } },
    { { SIMDE_FLOAT32_C(  -755.23),     -SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(   -64.80), SIMDE_FLOAT32_C(  -366.38),
        SIMDE_FLOAT32_C(  -594.08), SIMDE_FLOAT32_C(  -921.55), SIMDE_FLOAT32_C(  -470.17), SIMDE_FLOAT32_C(  -249.28) },
       INT32_C(         179),
      { SIMDE_FLOAT32_C(  -755.23),     -SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(   -64.80), SIMDE_FLOAT32_C(  -366.38),
        SIMDE_FLOAT32_C(  -594.08), SIMDE_FLOAT32_C(  -921.55), SIMDE_FLOAT32_C(  -470.17), SIMDE_FLOAT32_C(  -249.28) } },
    { { SIMDE_FLOAT32_C(  -243.91), SIMDE_FLOAT32_C(  -478.87), SIMDE_FLOAT32_C(   -30.80), SIMDE_FLOAT32_C(   724.66),
        SIMDE_FLOAT32_C(  -709.47), SIMDE_FLOAT32_C(  -954.20), SIMDE_FLOAT32_C(   985.72), SIMDE_FLOAT32_C(   260.53) },
       INT32_C(         195),
      { SIMDE_FLOAT32_C(  -243.91), SIMDE_FLOAT32_C(  -478.87), SIMDE_FLOAT32_C(   -30.80), SIMDE_FLOAT32_C(   724.66),
        SIMDE_FLOAT32_C(  -709.47), SIMDE_FLOAT32_C(  -954.20), SIMDE_FLOAT32_C(   985.72), SIMDE_FLOAT32_C(   260.53) } },
    { { SIMDE_FLOAT32_C(  -926.52),      SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(   391.97), SIMDE_FLOAT32_C(  -980.41),
        SIMDE_FLOAT32_C(  -534.59), SIMDE_FLOAT32_C(  -586.61), SIMDE_FLOAT32_C(  -200.06), SIMDE_FLOAT32_C(    58.88) },
       INT32_C(         211),
      { SIMDE_FLOAT32_C(  -926.52),      SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(   391.97), SIMDE_FLOAT32_C(  -980.41),
        SIMDE_FLOAT32_C(  -534.59), SIMDE_FLOAT32_C(  -586.61), SIMDE_FLOAT32_C(  -200.06), SIMDE_FLOAT32_C(    58.88) } },
    { { SIMDE_FLOAT32_C(   762.66),     -SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(   347.26), SIMDE_FLOAT32_C(  -603.73),
        SIMDE_FLOAT32_C(  -324.15), SIMDE_FLOAT32_C(   425.71), SIMDE_FLOAT32_C(   -73.89), SIMDE_FLOAT32_C(   426.56) },
       INT32_C(         227),
      { SIMDE_FLOAT32_C(   762.66),     -SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(   347.26), SIMDE_FLOAT32_C(  -603.73),
        SIMDE_FLOAT32_C(  -324.15), SIMDE_FLOAT32_C(   425.71), SIMDE_FLOAT32_C(   -73.89), SIMDE_FLOAT32_C(   426.56) } },
    { { SIMDE_FLOAT32_C(  -621.18),     -SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(    75.29), SIMDE_FLOAT32_C(  -896.52),
        SIMDE_FLOAT32_C(  -136.85), SIMDE_FLOAT32_C(   121.09), SIMDE_FLOAT32_C(  -910.79), SIMDE_FLOAT32_C(  -876.32) },
       INT32_C(         243),
      { SIMDE_FLOAT32_C(  -621.18),     -SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(    75.29), SIMDE_FLOAT32_C(  -896.52),
        SIMDE_FLOAT32_C(  -136.85), SIMDE_FLOAT32_C(   121.09), SIMDE_FLOAT32_C(  -910.79), SIMDE_FLOAT32_C(  -876.32) } },
    { { SIMDE_FLOAT32_C(  -606.86), SIMDE_FLOAT32_C(  -817.73), SIMDE_FLOAT32_C(  -420.58), SIMDE_FLOAT32_C(  -193.47),
        SIMDE_FLOAT32_C(   -17.79), SIMDE_FLOAT32_C(   638.30), SIMDE_FLOAT32_C(  -675.58), SIMDE_FLOAT32_C(   624.93) },
       INT32_C(           4),
      { SIMDE_FLOAT32_C(  -607.00), SIMDE_FLOAT32_C(  -818.00), SIMDE_FLOAT32_C(  -421.00), SIMDE_FLOAT32_C(  -193.00),
        SIMDE_FLOAT32_C(   -18.00), SIMDE_FLOAT32_C(   638.00), SIMDE_FLOAT32_C(  -676.00), SIMDE_FLOAT32_C(   625.00) } },
    { {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(   894.86), SIMDE_FLOAT32_C(   397.62), SIMDE_FLOAT32_C(  -516.64),
        SIMDE_FLOAT32_C(  -429.29), SIMDE_FLOAT32_C(  -176.67), SIMDE_FLOAT32_C(   409.46), SIMDE_FLOAT32_C(   997.28) },
       INT32_C(          20),
      {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(   895.00), SIMDE_FLOAT32_C(   397.50), SIMDE_FLOAT32_C(  -516.50),
        SIMDE_FLOAT32_C(  -429.50), SIMDE_FLOAT32_C(  -176.50), SIMDE_FLOAT32_C(   409.50), SIMDE_FLOAT32_C(   997.50) } },
    { {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(  -175.11), SIMDE_FLOAT32_C(  -966.44), SIMDE_FLOAT32_C(   178.65),
        SIMDE_FLOAT32_C(   -71.63), SIMDE_FLOAT32_C(  -103.29), SIMDE_FLOAT32_C(  -700.26), SIMDE_FLOAT32_C(    17.58) },
       INT32_C(          36),
      {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(  -175.00), SIMDE_FLOAT32_C(  -966.50), SIMDE_FLOAT32_C(   178.75),
        SIMDE_FLOAT32_C(   -71.75), SIMDE_FLOAT32_C(  -103.25), SIMDE_FLOAT32_C(  -700.25), SIMDE_FLOAT32_C(    17.50) } },
    { { SIMDE_FLOAT32_C(   180.26), SIMDE_FLOAT32_C(   134.39), SIMDE_FLOAT32_C(   694.05), SIMDE_FLOAT32_C(   362.54),
        SIMDE_FLOAT32_C(   713.81), SIMDE_FLOAT32_C(  -499.42), SIMDE_FLOAT32_C(  -655.25), SIMDE_FLOAT32_C(   352.11) },
       INT32_C(          52),
      { SIMDE_FLOAT32_C(   180.25), SIMDE_FLOAT32_C(   134.38), SIMDE_FLOAT32_C(   694.00), SIMDE_FLOAT32_C(   362.50),
        SIMDE_FLOAT32_C(   713.75), SIMDE_FLOAT32_C(  -499.38), SIMDE_FLOAT32_C(  -655.25), SIMDE_FLOAT32_C(   352.12) } },
    { {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(   402.47), SIMDE_FLOAT32_C(   -87.92), SIMDE_FLOAT32_C(   864.55),
        SIMDE_FLOAT32_C(  -199.91), SIMDE_FLOAT32_C(   395.44), SIMDE_FLOAT32_C(  -564.74), SIMDE_FLOAT32_C(   623.43) },
       INT32_C(          68),
      {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(   402.50), SIMDE_FLOAT32_C(   -87.94), SIMDE_FLOAT32_C(   864.56),
        SIMDE_FLOAT32_C(  -199.94), SIMDE_FLOAT32_C(   395.44), SIMDE_FLOAT32_C(  -564.75), SIMDE_FLOAT32_C(   623.44) } },
    { {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(  -734.15), SIMDE_FLOAT32_C(  -464.09), SIMDE_FLOAT32_C(  -105.62),
        SIMDE_FLOAT32_C(  -700.59), SIMDE_FLOAT32_C(   714.56), SIMDE_FLOAT32_C(   822.76), SIMDE_FLOAT32_C(   196.12) },
       INT32_C(          84),
      {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(  -734.16), SIMDE_FLOAT32_C(  -464.09), SIMDE_FLOAT32_C(  -105.62),
        SIMDE_FLOAT32_C(  -700.59), SIMDE_FLOAT32_C(   714.56), SIMDE_FLOAT32_C(   822.75), SIMDE_FLOAT32_C(   196.12) } },
    { { SIMDE_FLOAT32_C(  -783.49),     -SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(  -979.40), SIMDE_FLOAT32_C(   350.90),
        SIMDE_FLOAT32_C(     9.25), SIMDE_FLOAT32_C(   383.13), SIMDE_FLOAT32_C(    64.71), SIMDE_FLOAT32_C(   509.83) },
       INT32_C(         100),
      { SIMDE_FLOAT32_C(  -783.48),     -SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(  -979.41), SIMDE_FLOAT32_C(   350.91),
        SIMDE_FLOAT32_C(     9.25), SIMDE_FLOAT32_C(   383.12), SIMDE_FLOAT32_C(    64.70), SIMDE_FLOAT32_C(   509.83) } },
    { { SIMDE_FLOAT32_C(   697.57), SIMDE_FLOAT32_C(   819.29), SIMDE_FLOAT32_C(   246.92), SIMDE_FLOAT32_C(   562.12),
        SIMDE_FLOAT32_C(  -380.62), SIMDE_FLOAT32_C(  -357.64), SIMDE_FLOAT32_C(   997.38), SIMDE_FLOAT32_C(  -757.19) },
       INT32_C(         116),
      { SIMDE_FLOAT32_C(   697.57), SIMDE_FLOAT32_C(   819.29), SIMDE_FLOAT32_C(   246.92), SIMDE_FLOAT32_C(   562.12),
        SIMDE_FLOAT32_C(  -380.62), SIMDE_FLOAT32_C(  -357.64), SIMDE_FLOAT32_C(   997.38), SIMDE_FLOAT32_C(  -757.19) } },
    { { SIMDE_FLOAT32_C(  -570.08), SIMDE_FLOAT32_C(  -687.70), SIMDE_FLOAT32_C(   713.11), SIMDE_FLOAT32_C(   -34.18),
        SIMDE_FLOAT32_C(   206.68), SIMDE_FLOAT32_C(  -987.48), SIMDE_FLOAT32_C(  -319.62), SIMDE_FLOAT32_C(    29.44) },
       INT32_C(         132),
      { SIMDE_FLOAT32_C(  -570.08), SIMDE_FLOAT32_C(  -687.70), SIMDE_FLOAT32_C(   713.11), SIMDE_FLOAT32_C(   -34.18),
        SIMDE_FLOAT32_C(   206.68), SIMDE_FLOAT32_C(  -987.48), SIMDE_FLOAT32_C(  -319.62), SIMDE_FLOAT32_C(    29.44) } },
    { { SIMDE_FLOAT32_C(  -305.32), SIMDE_FLOAT32_C(   869.78), SIMDE_FLOAT32_C(   425.14), SIMDE_FLOAT32_C(  -990.12),
        SIMDE_FLOAT32_C(   890.37), SIMDE_FLOAT32_C(  -223.96), SIMDE_FLOAT32_C(    19.13), SIMDE_FLOAT32_C(   273.51) },
       INT32_C(         148),
      { SIMDE_FLOAT32_C(  -305.32), SIMDE_FLOAT32_C(   869.78), SIMDE_FLOAT32_C(   425.14), SIMDE_FLOAT32_C(  -990.12),
        SIMDE_FLOAT32_C(   890.37), SIMDE_FLOAT32_C(  -223.96), SIMDE_FLOAT32_C(    19.13), SIMDE_FLOAT32_C(   273.51) } },
    { {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(     1.39), SIMDE_FLOAT32_C(  -742.43), SIMDE_FLOAT32_C(  -136.20),
        SIMDE_FLOAT32_C(  -301.04), SIMDE_FLOAT32_C(  -923.15), SIMDE_FLOAT32_C(  -889.28), SIMDE_FLOAT32_C(  -738.92) },
       INT32_C(         164),
      {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(     1.39), SIMDE_FLOAT32_C(  -742.43), SIMDE_FLOAT32_C(  -136.20),
        SIMDE_FLOAT32_C(  -301.04), SIMDE_FLOAT32_C(  -923.15), SIMDE_FLOAT32_C(  -889.28), SIMDE_FLOAT32_C(  -738.92) } },
    { { SIMDE_FLOAT32_C(  -741.54), SIMDE_FLOAT32_C(   -60.96), SIMDE_FLOAT32_C(  -799.67), SIMDE_FLOAT32_C(  -311.62),
        SIMDE_FLOAT32_C(   251.34), SIMDE_FLOAT32_C(   913.44), SIMDE_FLOAT32_C(   654.20), SIMDE_FLOAT32_C(  -541.98) },
       INT32_C(         180),
      { SIMDE_FLOAT32_C(  -741.54), SIMDE_FLOAT32_C(   -60.96), SIMDE_FLOAT32_C(  -799.67), SIMDE_FLOAT32_C(  -311.62),
        SIMDE_FLOAT32_C(   251.34), SIMDE_FLOAT32_C(   913.44), SIMDE_FLOAT32_C(   654.20), SIMDE_FLOAT32_C(  -541.98) } },
    { { SIMDE_FLOAT32_C(  -665.42), SIMDE_FLOAT32_C(   487.46), SIMDE_FLOAT32_C(   134.59), SIMDE_FLOAT32_C(    29.26),
        SIMDE_FLOAT32_C(   357.24), SIMDE_FLOAT32_C(  -440.26), SIMDE_FLOAT32_C(    39.14), SIMDE_FLOAT32_C(   247.61) },
       INT32_C(         196),
      { SIMDE_FLOAT32_C(  -665.42), SIMDE_FLOAT32_C(   487.46), SIMDE_FLOAT32_C(   134.59), SIMDE_FLOAT32_C(    29.26),
        SIMDE_FLOAT32_C(   357.24), SIMDE_FLOAT32_C(  -440.26), SIMDE_FLOAT32_C(    39.14), SIMDE_FLOAT32_C(   247.61) } },
    { { SIMDE_FLOAT32_C(  -941.73),     -SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(   176.53), SIMDE_FLOAT32_C(  -412.77),
        SIMDE_FLOAT32_C(   522.52), SIMDE_FLOAT32_C(   434.09), SIMDE_FLOAT32_C(   451.03), SIMDE_FLOAT32_C(  -778.52) },
       INT32_C(         212),
      { SIMDE_FLOAT32_C(  -941.73),     -SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(   176.53), SIMDE_FLOAT32_C(  -412.77),
        SIMDE_FLOAT32_C(   522.52), SIMDE_FLOAT32_C(   434.09), SIMDE_FLOAT32_C(   451.03), SIMDE_FLOAT32_C(  -778.52) } },
    { { SIMDE_FLOAT32_C(  -792.82), SIMDE_FLOAT32_C(  -685.18), SIMDE_FLOAT32_C(  -258.98), SIMDE_FLOAT32_C(   146.22),
        SIMDE_FLOAT32_C(  -484.85), SIMDE_FLOAT32_C(   429.40), SIMDE_FLOAT32_C(  -602.44), SIMDE_FLOAT32_C(  -571.41) },
       INT32_C(         228),
      { SIMDE_FLOAT32_C(  -792.82), SIMDE_FLOAT32_C(  -685.18), SIMDE_FLOAT32_C(  -258.98), SIMDE_FLOAT32_C(   146.22),
        SIMDE_FLOAT32_C(  -484.85), SIMDE_FLOAT32_C(   429.40), SIMDE_FLOAT32_C(  -602.44), SIMDE_FLOAT32_C(  -571.41) } },
    { { SIMDE_FLOAT32_C(  -144.42), SIMDE_FLOAT32_C(  -645.45), SIMDE_FLOAT32_C(   418.18), SIMDE_FLOAT32_C(  -656.96),
        SIMDE_FLOAT32_C(   489.14), SIMDE_FLOAT32_C(  -552.57), SIMDE_FLOAT32_C(   700.28), SIMDE_FLOAT32_C(  -951.12) },
       INT32_C(         244),
      { SIMDE_FLOAT32_C(  -144.42), SIMDE_FLOAT32_C(  -645.45), SIMDE_FLOAT32_C(   418.18), SIMDE_FLOAT32_C(  -656.96),
        SIMDE_FLOAT32_C(   489.14), SIMDE_FLOAT32_C(  -552.57), SIMDE_FLOAT32_C(   700.28), SIMDE_FLOAT32_C(  -951.12) } },
  };

  simde__m256 a, r;

  a = simde_mm256_loadu_ps(test_vec[0].a);
  r = simde_mm256_roundscale_ps(a, INT32_C(           0));
  simde_test_x86_assert_equal_f32x8(r, simde_mm256_loadu_ps(test_vec[0].r), 1);

  a = simde_mm256_loadu_ps(test_vec[1].a);
  r = simde_mm256_roundscale_ps(a, INT32_C(          16));
  simde_test_x86_assert_equal_f32x8(r, simde_mm256_loadu_ps(test_vec[1].r), 1);

  a = simde_mm256_loadu_ps(test_vec[2].a);
  r = simde_mm256_roundscale_ps(a, INT32_C(          32));
  simde_test_x86_assert_equal_f32x8(r, simde_mm256_loadu_ps(test_vec[2].r), 1);

  a = simde_mm256_loadu_ps(test_vec[3].a);
  r = simde_mm256_roundscale_ps(a, INT32_C(          48));
  simde_test_x86_assert_equal_f32x8(r, simde_mm256_loadu_ps(test_vec[3].r), 1);

  a = simde_mm256_loadu_ps(test_vec[4].a);
  r = simde_mm256_roundscale_ps(a, INT32_C(          64));
  simde_test_x86_assert_equal_f32x8(r, simde_mm256_loadu_ps(test_vec[4].r), 1);

  a = simde_mm256_loadu_ps(test_vec[5].a);
  r = simde_mm256_roundscale_ps(a, INT32_C(          80));
  simde_test_x86_assert_equal_f32x8(r, simde_mm256_loadu_ps(test_vec[5].r), 1);

  a = simde_mm256_loadu_ps(test_vec[6].a);
  r = simde_mm256_roundscale_ps(a, INT32_C(          96));
  simde_test_x86_assert_equal_f32x8(r, simde_mm256_loadu_ps(test_vec[6].r), 1);

  a = simde_mm256_loadu_ps(test_vec[7].a);
  r = simde_mm256_roundscale_ps(a, INT32_C(         112));
  simde_test_x86_assert_equal_f32x8(r, simde_mm256_loadu_ps(test_vec[7].r), 1);

  a = simde_mm256_loadu_ps(test_vec[8].a);
  r = simde_mm256_roundscale_ps(a, INT32_C(         128));
  simde_test_x86_assert_equal_f32x8(r, simde_mm256_loadu_ps(test_vec[8].r), 1);

  a = simde_mm256_loadu_ps(test_vec[9].a);
  r = simde_mm256_roundscale_ps(a, INT32_C(         144));
  simde_test_x86_assert_equal_f32x8(r, simde_mm256_loadu_ps(test_vec[9].r), 1);

  a = simde_mm256_loadu_ps(test_vec[10].a);
  r = simde_mm256_roundscale_ps(a, INT32_C(         160));
  simde_test_x86_assert_equal_f32x8(r, simde_mm256_loadu_ps(test_vec[10].r), 1);

  a = simde_mm256_loadu_ps(test_vec[11].a);
  r = simde_mm256_roundscale_ps(a, INT32_C(         176));
  simde_test_x86_assert_equal_f32x8(r, simde_mm256_loadu_ps(test_vec[11].r), 1);

  a = simde_mm256_loadu_ps(test_vec[12].a);
  r = simde_mm256_roundscale_ps(a, INT32_C(         192));
  simde_test_x86_assert_equal_f32x8(r, simde_mm256_loadu_ps(test_vec[12].r), 1);

  a = simde_mm256_loadu_ps(test_vec[13].a);
  r = simde_mm256_roundscale_ps(a, INT32_C(         208));
  simde_test_x86_assert_equal_f32x8(r, simde_mm256_loadu_ps(test_vec[13].r), 1);

  a = simde_mm256_loadu_ps(test_vec[14].a);
  r = simde_mm256_roundscale_ps(a, INT32_C(         224));
  simde_test_x86_assert_equal_f32x8(r, simde_mm256_loadu_ps(test_vec[14].r), 1);

  a = simde_mm256_loadu_ps(test_vec[15].a);
  r = simde_mm256_roundscale_ps(a, INT32_C(         240));
  simde_test_x86_assert_equal_f32x8(r, simde_mm256_loadu_ps(test_vec[15].r), 1);

  a = simde_mm256_loadu_ps(test_vec[16].a);
  r = simde_mm256_roundscale_ps(a, INT32_C(           1));
  simde_test_x86_assert_equal_f32x8(r, simde_mm256_loadu_ps(test_vec[16].r), 1);

  a = simde_mm256_loadu_ps(test_vec[17].a);
  r = simde_mm256_roundscale_ps(a, INT32_C(          17));
  simde_test_x86_assert_equal_f32x8(r, simde_mm256_loadu_ps(test_vec[17].r), 1);

  a = simde_mm256_loadu_ps(test_vec[18].a);
  r = simde_mm256_roundscale_ps(a, INT32_C(          33));
  simde_test_x86_assert_equal_f32x8(r, simde_mm256_loadu_ps(test_vec[18].r), 1);

  a = simde_mm256_loadu_ps(test_vec[19].a);
  r = simde_mm256_roundscale_ps(a, INT32_C(          49));
  simde_test_x86_assert_equal_f32x8(r, simde_mm256_loadu_ps(test_vec[19].r), 1);

  a = simde_mm256_loadu_ps(test_vec[20].a);
  r = simde_mm256_roundscale_ps(a, INT32_C(          65));
  simde_test_x86_assert_equal_f32x8(r, simde_mm256_loadu_ps(test_vec[20].r), 1);

  a = simde_mm256_loadu_ps(test_vec[21].a);
  r = simde_mm256_roundscale_ps(a, INT32_C(          81));
  simde_test_x86_assert_equal_f32x8(r, simde_mm256_loadu_ps(test_vec[21].r), 1);

  a = simde_mm256_loadu_ps(test_vec[22].a);
  r = simde_mm256_roundscale_ps(a, INT32_C(          97));
  simde_test_x86_assert_equal_f32x8(r, simde_mm256_loadu_ps(test_vec[22].r), 1);

  a = simde_mm256_loadu_ps(test_vec[23].a);
  r = simde_mm256_roundscale_ps(a, INT32_C(         113));
  simde_test_x86_assert_equal_f32x8(r, simde_mm256_loadu_ps(test_vec[23].r), 1);

  a = simde_mm256_loadu_ps(test_vec[24].a);
  r = simde_mm256_roundscale_ps(a, INT32_C(         129));
  simde_test_x86_assert_equal_f32x8(r, simde_mm256_loadu_ps(test_vec[24].r), 1);

  a = simde_mm256_loadu_ps(test_vec[25].a);
  r = simde_mm256_roundscale_ps(a, INT32_C(         145));
  simde_test_x86_assert_equal_f32x8(r, simde_mm256_loadu_ps(test_vec[25].r), 1);

  a = simde_mm256_loadu_ps(test_vec[26].a);
  r = simde_mm256_roundscale_ps(a, INT32_C(         161));
  simde_test_x86_assert_equal_f32x8(r, simde_mm256_loadu_ps(test_vec[26].r), 1);

  a = simde_mm256_loadu_ps(test_vec[27].a);
  r = simde_mm256_roundscale_ps(a, INT32_C(         177));
  simde_test_x86_assert_equal_f32x8(r, simde_mm256_loadu_ps(test_vec[27].r), 1);

  a = simde_mm256_loadu_ps(test_vec[28].a);
  r = simde_mm256_roundscale_ps(a, INT32_C(         193));
  simde_test_x86_assert_equal_f32x8(r, simde_mm256_loadu_ps(test_vec[28].r), 1);

  a = simde_mm256_loadu_ps(test_vec[29].a);
  r = simde_mm256_roundscale_ps(a, INT32_C(         209));
  simde_test_x86_assert_equal_f32x8(r, simde_mm256_loadu_ps(test_vec[29].r), 1);

  a = simde_mm256_loadu_ps(test_vec[30].a);
  r = simde_mm256_roundscale_ps(a, INT32_C(         225));
  simde_test_x86_assert_equal_f32x8(r, simde_mm256_loadu_ps(test_vec[30].r), 1);

  a = simde_mm256_loadu_ps(test_vec[31].a);
  r = simde_mm256_roundscale_ps(a, INT32_C(         241));
  simde_test_x86_assert_equal_f32x8(r, simde_mm256_loadu_ps(test_vec[31].r), 1);

  a = simde_mm256_loadu_ps(test_vec[32].a);
  r = simde_mm256_roundscale_ps(a, INT32_C(           2));
  simde_test_x86_assert_equal_f32x8(r, simde_mm256_loadu_ps(test_vec[32].r), 1);

  a = simde_mm256_loadu_ps(test_vec[33].a);
  r = simde_mm256_roundscale_ps(a, INT32_C(          18));
  simde_test_x86_assert_equal_f32x8(r, simde_mm256_loadu_ps(test_vec[33].r), 1);

  a = simde_mm256_loadu_ps(test_vec[34].a);
  r = simde_mm256_roundscale_ps(a, INT32_C(          34));
  simde_test_x86_assert_equal_f32x8(r, simde_mm256_loadu_ps(test_vec[34].r), 1);

  a = simde_mm256_loadu_ps(test_vec[35].a);
  r = simde_mm256_roundscale_ps(a, INT32_C(          50));
  simde_test_x86_assert_equal_f32x8(r, simde_mm256_loadu_ps(test_vec[35].r), 1);

  a = simde_mm256_loadu_ps(test_vec[36].a);
  r = simde_mm256_roundscale_ps(a, INT32_C(          66));
  simde_test_x86_assert_equal_f32x8(r, simde_mm256_loadu_ps(test_vec[36].r), 1);

  a = simde_mm256_loadu_ps(test_vec[37].a);
  r = simde_mm256_roundscale_ps(a, INT32_C(          82));
  simde_test_x86_assert_equal_f32x8(r, simde_mm256_loadu_ps(test_vec[37].r), 1);

  a = simde_mm256_loadu_ps(test_vec[38].a);
  r = simde_mm256_roundscale_ps(a, INT32_C(          98));
  simde_test_x86_assert_equal_f32x8(r, simde_mm256_loadu_ps(test_vec[38].r), 1);

  a = simde_mm256_loadu_ps(test_vec[39].a);
  r = simde_mm256_roundscale_ps(a, INT32_C(         114));
  simde_test_x86_assert_equal_f32x8(r, simde_mm256_loadu_ps(test_vec[39].r), 1);

  a = simde_mm256_loadu_ps(test_vec[40].a);
  r = simde_mm256_roundscale_ps(a, INT32_C(         130));
  simde_test_x86_assert_equal_f32x8(r, simde_mm256_loadu_ps(test_vec[40].r), 1);

  a = simde_mm256_loadu_ps(test_vec[41].a);
  r = simde_mm256_roundscale_ps(a, INT32_C(         146));
  simde_test_x86_assert_equal_f32x8(r, simde_mm256_loadu_ps(test_vec[41].r), 1);

  a = simde_mm256_loadu_ps(test_vec[42].a);
  r = simde_mm256_roundscale_ps(a, INT32_C(         162));
  simde_test_x86_assert_equal_f32x8(r, simde_mm256_loadu_ps(test_vec[42].r), 1);

  a = simde_mm256_loadu_ps(test_vec[43].a);
  r = simde_mm256_roundscale_ps(a, INT32_C(         178));
  simde_test_x86_assert_equal_f32x8(r, simde_mm256_loadu_ps(test_vec[43].r), 1);

  a = simde_mm256_loadu_ps(test_vec[44].a);
  r = simde_mm256_roundscale_ps(a, INT32_C(         194));
  simde_test_x86_assert_equal_f32x8(r, simde_mm256_loadu_ps(test_vec[44].r), 1);

  a = simde_mm256_loadu_ps(test_vec[45].a);
  r = simde_mm256_roundscale_ps(a, INT32_C(         210));
  simde_test_x86_assert_equal_f32x8(r, simde_mm256_loadu_ps(test_vec[45].r), 1);

  a = simde_mm256_loadu_ps(test_vec[46].a);
  r = simde_mm256_roundscale_ps(a, INT32_C(         226));
  simde_test_x86_assert_equal_f32x8(r, simde_mm256_loadu_ps(test_vec[46].r), 1);

  a = simde_mm256_loadu_ps(test_vec[47].a);
  r = simde_mm256_roundscale_ps(a, INT32_C(         242));
  simde_test_x86_assert_equal_f32x8(r, simde_mm256_loadu_ps(test_vec[47].r), 1);

  a = simde_mm256_loadu_ps(test_vec[48].a);
  r = simde_mm256_roundscale_ps(a, INT32_C(           3));
  simde_test_x86_assert_equal_f32x8(r, simde_mm256_loadu_ps(test_vec[48].r), 1);

  a = simde_mm256_loadu_ps(test_vec[49].a);
  r = simde_mm256_roundscale_ps(a, INT32_C(          19));
  simde_test_x86_assert_equal_f32x8(r, simde_mm256_loadu_ps(test_vec[49].r), 1);

  a = simde_mm256_loadu_ps(test_vec[50].a);
  r = simde_mm256_roundscale_ps(a, INT32_C(          35));
  simde_test_x86_assert_equal_f32x8(r, simde_mm256_loadu_ps(test_vec[50].r), 1);

  a = simde_mm256_loadu_ps(test_vec[51].a);
  r = simde_mm256_roundscale_ps(a, INT32_C(          51));
  simde_test_x86_assert_equal_f32x8(r, simde_mm256_loadu_ps(test_vec[51].r), 1);

  a = simde_mm256_loadu_ps(test_vec[52].a);
  r = simde_mm256_roundscale_ps(a, INT32_C(          67));
  simde_test_x86_assert_equal_f32x8(r, simde_mm256_loadu_ps(test_vec[52].r), 1);

  a = simde_mm256_loadu_ps(test_vec[53].a);
  r = simde_mm256_roundscale_ps(a, INT32_C(          83));
  simde_test_x86_assert_equal_f32x8(r, simde_mm256_loadu_ps(test_vec[53].r), 1);

  a = simde_mm256_loadu_ps(test_vec[54].a);
  r = simde_mm256_roundscale_ps(a, INT32_C(          99));
  simde_test_x86_assert_equal_f32x8(r, simde_mm256_loadu_ps(test_vec[54].r), 1);

  a = simde_mm256_loadu_ps(test_vec[55].a);
  r = simde_mm256_roundscale_ps(a, INT32_C(         115));
  simde_test_x86_assert_equal_f32x8(r, simde_mm256_loadu_ps(test_vec[55].r), 1);

  a = simde_mm256_loadu_ps(test_vec[56].a);
  r = simde_mm256_roundscale_ps(a, INT32_C(         131));
  simde_test_x86_assert_equal_f32x8(r, simde_mm256_loadu_ps(test_vec[56].r), 1);

  a = simde_mm256_loadu_ps(test_vec[57].a);
  r = simde_mm256_roundscale_ps(a, INT32_C(         147));
  simde_test_x86_assert_equal_f32x8(r, simde_mm256_loadu_ps(test_vec[57].r), 1);

  a = simde_mm256_loadu_ps(test_vec[58].a);
  r = simde_mm256_roundscale_ps(a, INT32_C(         163));
  simde_test_x86_assert_equal_f32x8(r, simde_mm256_loadu_ps(test_vec[58].r), 1);

  a = simde_mm256_loadu_ps(test_vec[59].a);
  r = simde_mm256_roundscale_ps(a, INT32_C(         179));
  simde_test_x86_assert_equal_f32x8(r, simde_mm256_loadu_ps(test_vec[59].r), 1);

  a = simde_mm256_loadu_ps(test_vec[60].a);
  r = simde_mm256_roundscale_ps(a, INT32_C(         195));
  simde_test_x86_assert_equal_f32x8(r, simde_mm256_loadu_ps(test_vec[60].r), 1);

  a = simde_mm256_loadu_ps(test_vec[61].a);
  r = simde_mm256_roundscale_ps(a, INT32_C(         211));
  simde_test_x86_assert_equal_f32x8(r, simde_mm256_loadu_ps(test_vec[61].r), 1);

  a = simde_mm256_loadu_ps(test_vec[62].a);
  r = simde_mm256_roundscale_ps(a, INT32_C(         227));
  simde_test_x86_assert_equal_f32x8(r, simde_mm256_loadu_ps(test_vec[62].r), 1);

  a = simde_mm256_loadu_ps(test_vec[63].a);
  r = simde_mm256_roundscale_ps(a, INT32_C(         243));
  simde_test_x86_assert_equal_f32x8(r, simde_mm256_loadu_ps(test_vec[63].r), 1);

  a = simde_mm256_loadu_ps(test_vec[64].a);
  r = simde_mm256_roundscale_ps(a, INT32_C(           4));
  simde_test_x86_assert_equal_f32x8(r, simde_mm256_loadu_ps(test_vec[64].r), 1);

  a = simde_mm256_loadu_ps(test_vec[65].a);
  r = simde_mm256_roundscale_ps(a, INT32_C(          20));
  simde_test_x86_assert_equal_f32x8(r, simde_mm256_loadu_ps(test_vec[65].r), 1);

  a = simde_mm256_loadu_ps(test_vec[66].a);
  r = simde_mm256_roundscale_ps(a, INT32_C(          36));
  simde_test_x86_assert_equal_f32x8(r, simde_mm256_loadu_ps(test_vec[66].r), 1);

  a = simde_mm256_loadu_ps(test_vec[67].a);
  r = simde_mm256_roundscale_ps(a, INT32_C(          52));
  simde_test_x86_assert_equal_f32x8(r, simde_mm256_loadu_ps(test_vec[67].r), 1);

  a = simde_mm256_loadu_ps(test_vec[68].a);
  r = simde_mm256_roundscale_ps(a, INT32_C(          68));
  simde_test_x86_assert_equal_f32x8(r, simde_mm256_loadu_ps(test_vec[68].r), 1);

  a = simde_mm256_loadu_ps(test_vec[69].a);
  r = simde_mm256_roundscale_ps(a, INT32_C(          84));
  simde_test_x86_assert_equal_f32x8(r, simde_mm256_loadu_ps(test_vec[69].r), 1);

  a = simde_mm256_loadu_ps(test_vec[70].a);
  r = simde_mm256_roundscale_ps(a, INT32_C(         100));
  simde_test_x86_assert_equal_f32x8(r, simde_mm256_loadu_ps(test_vec[70].r), 1);

  a = simde_mm256_loadu_ps(test_vec[71].a);
  r = simde_mm256_roundscale_ps(a, INT32_C(         116));
  simde_test_x86_assert_equal_f32x8(r, simde_mm256_loadu_ps(test_vec[71].r), 1);

  a = simde_mm256_loadu_ps(test_vec[72].a);
  r = simde_mm256_roundscale_ps(a, INT32_C(         132));
  simde_test_x86_assert_equal_f32x8(r, simde_mm256_loadu_ps(test_vec[72].r), 1);

  a = simde_mm256_loadu_ps(test_vec[73].a);
  r = simde_mm256_roundscale_ps(a, INT32_C(         148));
  simde_test_x86_assert_equal_f32x8(r, simde_mm256_loadu_ps(test_vec[73].r), 1);

  a = simde_mm256_loadu_ps(test_vec[74].a);
  r = simde_mm256_roundscale_ps(a, INT32_C(         164));
  simde_test_x86_assert_equal_f32x8(r, simde_mm256_loadu_ps(test_vec[74].r), 1);

  a = simde_mm256_loadu_ps(test_vec[75].a);
  r = simde_mm256_roundscale_ps(a, INT32_C(         180));
  simde_test_x86_assert_equal_f32x8(r, simde_mm256_loadu_ps(test_vec[75].r), 1);

  a = simde_mm256_loadu_ps(test_vec[76].a);
  r = simde_mm256_roundscale_ps(a, INT32_C(         196));
  simde_test_x86_assert_equal_f32x8(r, simde_mm256_loadu_ps(test_vec[76].r), 1);

  a = simde_mm256_loadu_ps(test_vec[77].a);
  r = simde_mm256_roundscale_ps(a, INT32_C(         212));
  simde_test_x86_assert_equal_f32x8(r, simde_mm256_loadu_ps(test_vec[77].r), 1);

  a = simde_mm256_loadu_ps(test_vec[78].a);
  r = simde_mm256_roundscale_ps(a, INT32_C(         228));
  simde_test_x86_assert_equal_f32x8(r, simde_mm256_loadu_ps(test_vec[78].r), 1);

  a = simde_mm256_loadu_ps(test_vec[79].a);
  r = simde_mm256_roundscale_ps(a, INT32_C(         244));
  simde_test_x86_assert_equal_f32x8(r, simde_mm256_loadu_ps(test_vec[79].r), 1);

  return 0;
#else
  fputc('\n', stdout);
  int round_type[5] = {SIMDE_MM_FROUND_TO_NEAREST_INT, SIMDE_MM_FROUND_TO_NEG_INF, SIMDE_MM_FROUND_TO_POS_INF, SIMDE_MM_FROUND_TO_ZERO, SIMDE_MM_FROUND_CUR_DIRECTION};
  for (int i = 0 ; i < 5 ; i++) {
    for (int j = 0 ; j < 16 ; j++) {
      simde__m256 a = simde_test_x86_random_f32x8(SIMDE_FLOAT32_C(-1000.0), SIMDE_FLOAT32_C(1000.0));
      if((simde_test_codegen_rand() & 1)) {
        if((simde_test_codegen_rand() & 1))
          a = simde_mm256_blend_ps(a, simde_mm256_set1_ps(SIMDE_MATH_NANF), 1);
        else {
          if((simde_test_codegen_rand() & 1))
            a = simde_mm256_blend_ps(a, simde_mm256_set1_ps(SIMDE_MATH_INFINITY), 2);
          else
            a = simde_mm256_blend_ps(a, simde_mm256_set1_ps(-SIMDE_MATH_INFINITY), 2);
        }
      }
      int imm8 = ((j << 4) | round_type[i]) & 255;
      simde__m256 r;
      SIMDE_CONSTIFY_256_(simde_mm256_roundscale_ps, r, simde_mm256_setzero_ps(), imm8, a);

      simde_test_x86_write_f32x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
      simde_test_codegen_write_i32(2, imm8, SIMDE_TEST_VEC_POS_MIDDLE);
      simde_test_x86_write_f32x8(2, r, SIMDE_TEST_VEC_POS_LAST);
    }
  }
  return 1;
#endif
}

static int
test_simde_mm256_mask_roundscale_ps (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const simde_float32 src[8];
    const simde__mmask8 k;
    const simde_float32 a[8];
    const int32_t imm8;
    const simde_float32 r[8];
  } test_vec[] = {
    { { SIMDE_FLOAT32_C(  -382.29), SIMDE_FLOAT32_C(   330.96), SIMDE_FLOAT32_C(  -644.44), SIMDE_FLOAT32_C(  -895.86),
        SIMDE_FLOAT32_C(  -385.41), SIMDE_FLOAT32_C(    71.12), SIMDE_FLOAT32_C(  -739.06), SIMDE_FLOAT32_C(  -344.61) },
      UINT8_C(122),
      {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(  -792.25), SIMDE_FLOAT32_C(  -224.49), SIMDE_FLOAT32_C(  -501.18),
        SIMDE_FLOAT32_C(  -757.05), SIMDE_FLOAT32_C(  -370.84), SIMDE_FLOAT32_C(   682.90), SIMDE_FLOAT32_C(  -710.21) },
       INT32_C(         128),
      { SIMDE_FLOAT32_C(  -382.29), SIMDE_FLOAT32_C(  -792.25), SIMDE_FLOAT32_C(  -644.44), SIMDE_FLOAT32_C(  -501.18),
        SIMDE_FLOAT32_C(  -757.05), SIMDE_FLOAT32_C(  -370.84), SIMDE_FLOAT32_C(   682.90), SIMDE_FLOAT32_C(  -344.61) } },
    { { SIMDE_FLOAT32_C(   148.79), SIMDE_FLOAT32_C(   905.05), SIMDE_FLOAT32_C(  -276.16), SIMDE_FLOAT32_C(   916.96),
        SIMDE_FLOAT32_C(  -272.05), SIMDE_FLOAT32_C(   859.28), SIMDE_FLOAT32_C(  -998.23), SIMDE_FLOAT32_C(  -263.23) },
      UINT8_C( 53),
      { SIMDE_FLOAT32_C(   936.67),      SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(   162.47), SIMDE_FLOAT32_C(   267.63),
        SIMDE_FLOAT32_C(  -153.82), SIMDE_FLOAT32_C(   266.61), SIMDE_FLOAT32_C(   882.21), SIMDE_FLOAT32_C(   917.30) },
       INT32_C(         161),
      { SIMDE_FLOAT32_C(   936.67), SIMDE_FLOAT32_C(   905.05), SIMDE_FLOAT32_C(   162.47), SIMDE_FLOAT32_C(   916.96),
        SIMDE_FLOAT32_C(  -153.82), SIMDE_FLOAT32_C(   266.61), SIMDE_FLOAT32_C(  -998.23), SIMDE_FLOAT32_C(  -263.23) } },
    { { SIMDE_FLOAT32_C(  -254.64), SIMDE_FLOAT32_C(   772.87), SIMDE_FLOAT32_C(   717.70), SIMDE_FLOAT32_C(   -11.69),
        SIMDE_FLOAT32_C(  -597.96), SIMDE_FLOAT32_C(   400.60), SIMDE_FLOAT32_C(   278.10), SIMDE_FLOAT32_C(   809.76) },
      UINT8_C(221),
      { SIMDE_FLOAT32_C(    79.41), SIMDE_FLOAT32_C(   -41.45), SIMDE_FLOAT32_C(  -916.66), SIMDE_FLOAT32_C(   803.25),
        SIMDE_FLOAT32_C(  -124.49), SIMDE_FLOAT32_C(  -188.71), SIMDE_FLOAT32_C(   662.53), SIMDE_FLOAT32_C(  -122.72) },
       INT32_C(         130),
      { SIMDE_FLOAT32_C(    79.41), SIMDE_FLOAT32_C(   772.87), SIMDE_FLOAT32_C(  -916.66), SIMDE_FLOAT32_C(   803.25),
        SIMDE_FLOAT32_C(  -124.49), SIMDE_FLOAT32_C(   400.60), SIMDE_FLOAT32_C(   662.53), SIMDE_FLOAT32_C(  -122.72) } },
    { { SIMDE_FLOAT32_C(  -186.05), SIMDE_FLOAT32_C(  -961.32), SIMDE_FLOAT32_C(   369.76), SIMDE_FLOAT32_C(  -918.43),
        SIMDE_FLOAT32_C(  -115.14), SIMDE_FLOAT32_C(  -363.64), SIMDE_FLOAT32_C(   963.79), SIMDE_FLOAT32_C(  -197.84) },
      UINT8_C(146),
      {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(   799.52), SIMDE_FLOAT32_C(   382.78), SIMDE_FLOAT32_C(   246.75),
        SIMDE_FLOAT32_C(   572.39), SIMDE_FLOAT32_C(   100.49), SIMDE_FLOAT32_C(  -764.95), SIMDE_FLOAT32_C(   974.43) },
       INT32_C(         227),
      { SIMDE_FLOAT32_C(  -186.05), SIMDE_FLOAT32_C(   799.52), SIMDE_FLOAT32_C(   369.76), SIMDE_FLOAT32_C(  -918.43),
        SIMDE_FLOAT32_C(   572.39), SIMDE_FLOAT32_C(  -363.64), SIMDE_FLOAT32_C(   963.79), SIMDE_FLOAT32_C(   974.43) } },
    { { SIMDE_FLOAT32_C(  -320.62), SIMDE_FLOAT32_C(  -407.44), SIMDE_FLOAT32_C(  -257.26), SIMDE_FLOAT32_C(  -237.28),
        SIMDE_FLOAT32_C(  -604.19), SIMDE_FLOAT32_C(   618.25), SIMDE_FLOAT32_C(   574.00), SIMDE_FLOAT32_C(  -941.65) },
      UINT8_C(240),
      { SIMDE_FLOAT32_C(   122.06), SIMDE_FLOAT32_C(  -734.36), SIMDE_FLOAT32_C(   309.48), SIMDE_FLOAT32_C(   160.74),
        SIMDE_FLOAT32_C(   635.39), SIMDE_FLOAT32_C(   391.06), SIMDE_FLOAT32_C(  -954.40), SIMDE_FLOAT32_C(  -728.25) },
       INT32_C(         164),
      { SIMDE_FLOAT32_C(  -320.62), SIMDE_FLOAT32_C(  -407.44), SIMDE_FLOAT32_C(  -257.26), SIMDE_FLOAT32_C(  -237.28),
        SIMDE_FLOAT32_C(   635.39), SIMDE_FLOAT32_C(   391.06), SIMDE_FLOAT32_C(  -954.40), SIMDE_FLOAT32_C(  -728.25) } },
    { { SIMDE_FLOAT32_C(  -564.34), SIMDE_FLOAT32_C(   856.23), SIMDE_FLOAT32_C(  -352.72), SIMDE_FLOAT32_C(   818.44),
        SIMDE_FLOAT32_C(   102.98), SIMDE_FLOAT32_C(  -780.33), SIMDE_FLOAT32_C(   -81.07), SIMDE_FLOAT32_C(   338.03) },
      UINT8_C(186),
      {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(  -148.82), SIMDE_FLOAT32_C(   978.30), SIMDE_FLOAT32_C(  -900.61),
        SIMDE_FLOAT32_C(   443.74), SIMDE_FLOAT32_C(  -278.96), SIMDE_FLOAT32_C(  -137.89), SIMDE_FLOAT32_C(   839.56) },
       INT32_C(         240),
      { SIMDE_FLOAT32_C(  -564.34), SIMDE_FLOAT32_C(  -148.82), SIMDE_FLOAT32_C(  -352.72), SIMDE_FLOAT32_C(  -900.61),
        SIMDE_FLOAT32_C(   443.74), SIMDE_FLOAT32_C(  -278.96), SIMDE_FLOAT32_C(   -81.07), SIMDE_FLOAT32_C(   839.56) } },
    { { SIMDE_FLOAT32_C(  -165.18), SIMDE_FLOAT32_C(   558.18), SIMDE_FLOAT32_C(  -836.46), SIMDE_FLOAT32_C(  -855.69),
        SIMDE_FLOAT32_C(  -281.08), SIMDE_FLOAT32_C(   798.94), SIMDE_FLOAT32_C(   535.36), SIMDE_FLOAT32_C(  -235.48) },
      UINT8_C(245),
      { SIMDE_FLOAT32_C(  -109.79), SIMDE_FLOAT32_C(   612.29), SIMDE_FLOAT32_C(  -493.65), SIMDE_FLOAT32_C(  -253.56),
        SIMDE_FLOAT32_C(  -740.43), SIMDE_FLOAT32_C(  -675.21), SIMDE_FLOAT32_C(   849.42), SIMDE_FLOAT32_C(  -520.76) },
       INT32_C(         161),
      { SIMDE_FLOAT32_C(  -109.79), SIMDE_FLOAT32_C(   558.18), SIMDE_FLOAT32_C(  -493.65), SIMDE_FLOAT32_C(  -855.69),
        SIMDE_FLOAT32_C(  -740.43), SIMDE_FLOAT32_C(  -675.21), SIMDE_FLOAT32_C(   849.42), SIMDE_FLOAT32_C(  -520.76) } },
    { { SIMDE_FLOAT32_C(  -326.65), SIMDE_FLOAT32_C(  -336.27), SIMDE_FLOAT32_C(  -961.37), SIMDE_FLOAT32_C(  -348.35),
        SIMDE_FLOAT32_C(  -236.87), SIMDE_FLOAT32_C(   482.37), SIMDE_FLOAT32_C(   372.69), SIMDE_FLOAT32_C(   625.24) },
      UINT8_C( 34),
      { SIMDE_FLOAT32_C(   711.98),     -SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(   219.84), SIMDE_FLOAT32_C(  -453.20),
        SIMDE_FLOAT32_C(   619.54), SIMDE_FLOAT32_C(   383.38), SIMDE_FLOAT32_C(  -308.89), SIMDE_FLOAT32_C(  -661.54) },
       INT32_C(           2),
      { SIMDE_FLOAT32_C(  -326.65),     -SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(  -961.37), SIMDE_FLOAT32_C(  -348.35),
        SIMDE_FLOAT32_C(  -236.87), SIMDE_FLOAT32_C(   384.00), SIMDE_FLOAT32_C(   372.69), SIMDE_FLOAT32_C(   625.24) } },
  };

  simde__m256 src, a, r;

  src = simde_mm256_loadu_ps(test_vec[0].src);
  a = simde_mm256_loadu_ps(test_vec[0].a);
  r = simde_mm256_mask_roundscale_ps(src, test_vec[0].k, a, INT32_C(         128));
  simde_test_x86_assert_equal_f32x8(r, simde_mm256_loadu_ps(test_vec[0].r), 1);

  src = simde_mm256_loadu_ps(test_vec[1].src);
  a = simde_mm256_loadu_ps(test_vec[1].a);
  r = simde_mm256_mask_roundscale_ps(src, test_vec[1].k, a, INT32_C(         161));
  simde_test_x86_assert_equal_f32x8(r, simde_mm256_loadu_ps(test_vec[1].r), 1);

  src = simde_mm256_loadu_ps(test_vec[2].src);
  a = simde_mm256_loadu_ps(test_vec[2].a);
  r = simde_mm256_mask_roundscale_ps(src, test_vec[2].k, a, INT32_C(         130));
  simde_test_x86_assert_equal_f32x8(r, simde_mm256_loadu_ps(test_vec[2].r), 1);

  src = simde_mm256_loadu_ps(test_vec[3].src);
  a = simde_mm256_loadu_ps(test_vec[3].a);
  r = simde_mm256_mask_roundscale_ps(src, test_vec[3].k, a, INT32_C(         227));
  simde_test_x86_assert_equal_f32x8(r, simde_mm256_loadu_ps(test_vec[3].r), 1);

  src = simde_mm256_loadu_ps(test_vec[4].src);
  a = simde_mm256_loadu_ps(test_vec[4].a);
  r = simde_mm256_mask_roundscale_ps(src, test_vec[4].k, a, INT32_C(         164));
  simde_test_x86_assert_equal_f32x8(r, simde_mm256_loadu_ps(test_vec[4].r), 1);

  src = simde_mm256_loadu_ps(test_vec[5].src);
  a = simde_mm256_loadu_ps(test_vec[5].a);
  r = simde_mm256_mask_roundscale_ps(src, test_vec[5].k, a, INT32_C(         240));
  simde_test_x86_assert_equal_f32x8(r, simde_mm256_loadu_ps(test_vec[5].r), 1);

  src = simde_mm256_loadu_ps(test_vec[6].src);
  a = simde_mm256_loadu_ps(test_vec[6].a);
  r = simde_mm256_mask_roundscale_ps(src, test_vec[6].k, a, INT32_C(         161));
  simde_test_x86_assert_equal_f32x8(r, simde_mm256_loadu_ps(test_vec[6].r), 1);

  src = simde_mm256_loadu_ps(test_vec[7].src);
  a = simde_mm256_loadu_ps(test_vec[7].a);
  r = simde_mm256_mask_roundscale_ps(src, test_vec[7].k, a, INT32_C(           2));
  simde_test_x86_assert_equal_f32x8(r, simde_mm256_loadu_ps(test_vec[7].r), 1);

  return 0;
#else
  fputc('\n', stdout);
  int round_type[5] = {SIMDE_MM_FROUND_TO_NEAREST_INT, SIMDE_MM_FROUND_TO_NEG_INF, SIMDE_MM_FROUND_TO_POS_INF, SIMDE_MM_FROUND_TO_ZERO, SIMDE_MM_FROUND_CUR_DIRECTION};
  for (int i = 0 ; i < 8 ; i++) {
    simde__m256 src = simde_test_x86_random_f32x8(SIMDE_FLOAT32_C(-1000.0), SIMDE_FLOAT32_C(1000.0));
    simde__mmask8 k = simde_test_x86_random_mmask8();
    simde__m256 a = simde_test_x86_random_f32x8(SIMDE_FLOAT32_C(-1000.0), SIMDE_FLOAT32_C(1000.0));
    if((simde_test_codegen_rand() & 1)) {
      if((simde_test_codegen_rand() & 1))
        a = simde_mm256_blend_ps(a, simde_mm256_set1_ps(SIMDE_MATH_NANF), 1);
      else {
        if((simde_test_codegen_rand() & 1))
          a = simde_mm256_blend_ps(a, simde_mm256_set1_ps(SIMDE_MATH_INFINITY), 2);
        else
          a = simde_mm256_blend_ps(a, simde_mm256_set1_ps(-SIMDE_MATH_INFINITY), 2);
      }
    }
    int imm8 = (((simde_test_codegen_rand() & 15) << 4) | round_type[i % 5]) & 255;
    simde__m256 r;
    SIMDE_CONSTIFY_256_(simde_mm256_mask_roundscale_ps, r, simde_mm256_setzero_ps(), imm8, src, k, a);

    simde_test_x86_write_f32x8(2, src, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_mmask8(2, k, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_f32x8(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i32(2, imm8, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_f32x8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm256_maskz_roundscale_ps (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const simde__mmask8 k;
    const simde_float32 a[8];
    const int32_t imm8;
    const simde_float32 r[8];
  } test_vec[] = {
    { UINT8_C(253),
      { SIMDE_FLOAT32_C(  -284.73), SIMDE_FLOAT32_C(   759.36), SIMDE_FLOAT32_C(   863.12), SIMDE_FLOAT32_C(   -25.16),
        SIMDE_FLOAT32_C(  -915.85), SIMDE_FLOAT32_C(   712.53), SIMDE_FLOAT32_C(   454.09), SIMDE_FLOAT32_C(   327.86) },
       INT32_C(           0),
      { SIMDE_FLOAT32_C(  -285.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(   863.00), SIMDE_FLOAT32_C(   -25.00),
        SIMDE_FLOAT32_C(  -916.00), SIMDE_FLOAT32_C(   713.00), SIMDE_FLOAT32_C(   454.00), SIMDE_FLOAT32_C(   328.00) } },
    { UINT8_C(211),
      { SIMDE_FLOAT32_C(   -61.39), SIMDE_FLOAT32_C(  -220.92), SIMDE_FLOAT32_C(  -245.28), SIMDE_FLOAT32_C(  -579.01),
        SIMDE_FLOAT32_C(  -848.23), SIMDE_FLOAT32_C(  -620.04), SIMDE_FLOAT32_C(   742.92), SIMDE_FLOAT32_C(   863.75) },
       INT32_C(          65),
      { SIMDE_FLOAT32_C(   -61.44), SIMDE_FLOAT32_C(  -220.94), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00),
        SIMDE_FLOAT32_C(  -848.25), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(   742.88), SIMDE_FLOAT32_C(   863.75) } },
    { UINT8_C( 80),
      {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(  -653.86), SIMDE_FLOAT32_C(   101.66), SIMDE_FLOAT32_C(  -600.69),
        SIMDE_FLOAT32_C(   528.46), SIMDE_FLOAT32_C(   328.14), SIMDE_FLOAT32_C(   502.30), SIMDE_FLOAT32_C(  -218.53) },
       INT32_C(         162),
      { SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00),
        SIMDE_FLOAT32_C(   528.46), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(   502.30), SIMDE_FLOAT32_C(     0.00) } },
    { UINT8_C( 86),
      { SIMDE_FLOAT32_C(   192.41), SIMDE_FLOAT32_C(  -375.03), SIMDE_FLOAT32_C(  -979.53), SIMDE_FLOAT32_C(  -353.51),
        SIMDE_FLOAT32_C(   952.83), SIMDE_FLOAT32_C(   -79.55), SIMDE_FLOAT32_C(  -226.07), SIMDE_FLOAT32_C(   944.43) },
       INT32_C(           3),
      { SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(  -375.00), SIMDE_FLOAT32_C(  -979.00), SIMDE_FLOAT32_C(     0.00),
        SIMDE_FLOAT32_C(   952.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(  -226.00), SIMDE_FLOAT32_C(     0.00) } },
    { UINT8_C( 65),
      { SIMDE_FLOAT32_C(  -719.95), SIMDE_FLOAT32_C(   704.78), SIMDE_FLOAT32_C(    79.10), SIMDE_FLOAT32_C(  -977.03),
        SIMDE_FLOAT32_C(   568.53), SIMDE_FLOAT32_C(   520.42), SIMDE_FLOAT32_C(   -14.27), SIMDE_FLOAT32_C(   979.08) },
       INT32_C(         244),
      { SIMDE_FLOAT32_C(  -719.95), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00),
        SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(   -14.27), SIMDE_FLOAT32_C(     0.00) } },
    { UINT8_C(149),
      { SIMDE_FLOAT32_C(   980.58),     -SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(  -591.12), SIMDE_FLOAT32_C(   482.88),
        SIMDE_FLOAT32_C(   641.81), SIMDE_FLOAT32_C(  -146.31), SIMDE_FLOAT32_C(   700.45), SIMDE_FLOAT32_C(  -817.37) },
       INT32_C(          32),
      { SIMDE_FLOAT32_C(   980.50), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(  -591.00), SIMDE_FLOAT32_C(     0.00),
        SIMDE_FLOAT32_C(   641.75), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(  -817.25) } },
    { UINT8_C( 12),
      { SIMDE_FLOAT32_C(  -239.56), SIMDE_FLOAT32_C(  -897.46), SIMDE_FLOAT32_C(  -686.72), SIMDE_FLOAT32_C(  -295.14),
        SIMDE_FLOAT32_C(   961.60), SIMDE_FLOAT32_C(   866.29), SIMDE_FLOAT32_C(   404.01), SIMDE_FLOAT32_C(  -758.35) },
       INT32_C(         241),
      { SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(  -686.72), SIMDE_FLOAT32_C(  -295.14),
        SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00) } },
    { UINT8_C(176),
      { SIMDE_FLOAT32_C(   139.60),     -SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(   250.35), SIMDE_FLOAT32_C(   118.68),
        SIMDE_FLOAT32_C(   584.80), SIMDE_FLOAT32_C(  -417.77), SIMDE_FLOAT32_C(  -800.58), SIMDE_FLOAT32_C(   565.38) },
       INT32_C(          18),
      { SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00),
        SIMDE_FLOAT32_C(   585.00), SIMDE_FLOAT32_C(  -417.50), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(   565.50) } },
  };

  simde__m256 a, r;

  a = simde_mm256_loadu_ps(test_vec[0].a);
  r = simde_mm256_maskz_roundscale_ps(test_vec[0].k, a, INT32_C(           0));
  simde_test_x86_assert_equal_f32x8(r, simde_mm256_loadu_ps(test_vec[0].r), 1);

  a = simde_mm256_loadu_ps(test_vec[1].a);
  r = simde_mm256_maskz_roundscale_ps(test_vec[1].k, a, INT32_C(          65));
  simde_test_x86_assert_equal_f32x8(r, simde_mm256_loadu_ps(test_vec[1].r), 1);

  a = simde_mm256_loadu_ps(test_vec[2].a);
  r = simde_mm256_maskz_roundscale_ps(test_vec[2].k, a, INT32_C(         162));
  simde_test_x86_assert_equal_f32x8(r, simde_mm256_loadu_ps(test_vec[2].r), 1);

  a = simde_mm256_loadu_ps(test_vec[3].a);
  r = simde_mm256_maskz_roundscale_ps(test_vec[3].k, a, INT32_C(           3));
  simde_test_x86_assert_equal_f32x8(r, simde_mm256_loadu_ps(test_vec[3].r), 1);

  a = simde_mm256_loadu_ps(test_vec[4].a);
  r = simde_mm256_maskz_roundscale_ps(test_vec[4].k, a, INT32_C(         244));
  simde_test_x86_assert_equal_f32x8(r, simde_mm256_loadu_ps(test_vec[4].r), 1);

  a = simde_mm256_loadu_ps(test_vec[5].a);
  r = simde_mm256_maskz_roundscale_ps(test_vec[5].k, a, INT32_C(          32));
  simde_test_x86_assert_equal_f32x8(r, simde_mm256_loadu_ps(test_vec[5].r), 1);

  a = simde_mm256_loadu_ps(test_vec[6].a);
  r = simde_mm256_maskz_roundscale_ps(test_vec[6].k, a, INT32_C(         241));
  simde_test_x86_assert_equal_f32x8(r, simde_mm256_loadu_ps(test_vec[6].r), 1);

  a = simde_mm256_loadu_ps(test_vec[7].a);
  r = simde_mm256_maskz_roundscale_ps(test_vec[7].k, a, INT32_C(          18));
  simde_test_x86_assert_equal_f32x8(r, simde_mm256_loadu_ps(test_vec[7].r), 1);

  return 0;
#else
  fputc('\n', stdout);
  int round_type[5] = {SIMDE_MM_FROUND_TO_NEAREST_INT, SIMDE_MM_FROUND_TO_NEG_INF, SIMDE_MM_FROUND_TO_POS_INF, SIMDE_MM_FROUND_TO_ZERO, SIMDE_MM_FROUND_CUR_DIRECTION};
  for (int i = 0 ; i < 8 ; i++) {
    simde__mmask8 k = simde_test_x86_random_mmask8();
    simde__m256 a = simde_test_x86_random_f32x8(SIMDE_FLOAT32_C(-1000.0), SIMDE_FLOAT32_C(1000.0));
    if((simde_test_codegen_rand() & 1)) {
      if((simde_test_codegen_rand() & 1))
        a = simde_mm256_blend_ps(a, simde_mm256_set1_ps(SIMDE_MATH_NANF), 1);
      else {
        if((simde_test_codegen_rand() & 1))
          a = simde_mm256_blend_ps(a, simde_mm256_set1_ps(SIMDE_MATH_INFINITY), 2);
        else
          a = simde_mm256_blend_ps(a, simde_mm256_set1_ps(-SIMDE_MATH_INFINITY), 2);
      }
    }
    int imm8 = (((simde_test_codegen_rand() & 15) << 4) | round_type[i % 5]) & 255;
    simde__m256 r;
    SIMDE_CONSTIFY_256_(simde_mm256_maskz_roundscale_ps, r, simde_mm256_setzero_ps(), imm8, k, a);

    simde_test_x86_write_mmask8(2, k, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_f32x8(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i32(2, imm8, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_f32x8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm512_roundscale_ps (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const simde_float32 a[16];
    const int32_t imm8;
    const simde_float32 r[16];
  } test_vec[] = {
    { { SIMDE_FLOAT32_C(  -239.11),     -SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(   583.11), SIMDE_FLOAT32_C(   -63.62),
        SIMDE_FLOAT32_C(  -542.20), SIMDE_FLOAT32_C(  -943.55), SIMDE_FLOAT32_C(   -44.62), SIMDE_FLOAT32_C(   249.90),
        SIMDE_FLOAT32_C(    -0.52), SIMDE_FLOAT32_C(  -935.78), SIMDE_FLOAT32_C(    55.30), SIMDE_FLOAT32_C(   395.77),
        SIMDE_FLOAT32_C(   796.76), SIMDE_FLOAT32_C(   -21.37), SIMDE_FLOAT32_C(   717.43), SIMDE_FLOAT32_C(  -750.04) },
       INT32_C(           0),
      { SIMDE_FLOAT32_C(  -239.00),     -SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(   583.00), SIMDE_FLOAT32_C(   -64.00),
        SIMDE_FLOAT32_C(  -542.00), SIMDE_FLOAT32_C(  -944.00), SIMDE_FLOAT32_C(   -45.00), SIMDE_FLOAT32_C(   250.00),
        SIMDE_FLOAT32_C(    -1.00), SIMDE_FLOAT32_C(  -936.00), SIMDE_FLOAT32_C(    55.00), SIMDE_FLOAT32_C(   396.00),
        SIMDE_FLOAT32_C(   797.00), SIMDE_FLOAT32_C(   -21.00), SIMDE_FLOAT32_C(   717.00), SIMDE_FLOAT32_C(  -750.00) } },
    { {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(  -163.71), SIMDE_FLOAT32_C(   660.29), SIMDE_FLOAT32_C(   213.26),
        SIMDE_FLOAT32_C(  -482.31), SIMDE_FLOAT32_C(   945.57), SIMDE_FLOAT32_C(   854.76), SIMDE_FLOAT32_C(  -622.19),
        SIMDE_FLOAT32_C(   -96.60), SIMDE_FLOAT32_C(  -815.85), SIMDE_FLOAT32_C(  -340.65), SIMDE_FLOAT32_C(  -620.08),
        SIMDE_FLOAT32_C(   -54.96), SIMDE_FLOAT32_C(  -327.42), SIMDE_FLOAT32_C(   963.03), SIMDE_FLOAT32_C(   881.42) },
       INT32_C(          16),
      {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(  -163.50), SIMDE_FLOAT32_C(   660.50), SIMDE_FLOAT32_C(   213.50),
        SIMDE_FLOAT32_C(  -482.50), SIMDE_FLOAT32_C(   945.50), SIMDE_FLOAT32_C(   855.00), SIMDE_FLOAT32_C(  -622.00),
        SIMDE_FLOAT32_C(   -96.50), SIMDE_FLOAT32_C(  -816.00), SIMDE_FLOAT32_C(  -340.50), SIMDE_FLOAT32_C(  -620.00),
        SIMDE_FLOAT32_C(   -55.00), SIMDE_FLOAT32_C(  -327.50), SIMDE_FLOAT32_C(   963.00), SIMDE_FLOAT32_C(   881.50) } },
    { { SIMDE_FLOAT32_C(  -163.20),      SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(    18.96), SIMDE_FLOAT32_C(   -98.98),
        SIMDE_FLOAT32_C(   435.58), SIMDE_FLOAT32_C(  -585.27), SIMDE_FLOAT32_C(  -302.22), SIMDE_FLOAT32_C(  -585.79),
        SIMDE_FLOAT32_C(  -867.84), SIMDE_FLOAT32_C(   -52.26), SIMDE_FLOAT32_C(  -930.06), SIMDE_FLOAT32_C(  -194.61),
        SIMDE_FLOAT32_C(   242.23), SIMDE_FLOAT32_C(   261.45), SIMDE_FLOAT32_C(   641.68), SIMDE_FLOAT32_C(   -97.48) },
       INT32_C(          32),
      { SIMDE_FLOAT32_C(  -163.25),      SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(    19.00), SIMDE_FLOAT32_C(   -99.00),
        SIMDE_FLOAT32_C(   435.50), SIMDE_FLOAT32_C(  -585.25), SIMDE_FLOAT32_C(  -302.25), SIMDE_FLOAT32_C(  -585.75),
        SIMDE_FLOAT32_C(  -867.75), SIMDE_FLOAT32_C(   -52.25), SIMDE_FLOAT32_C(  -930.00), SIMDE_FLOAT32_C(  -194.50),
        SIMDE_FLOAT32_C(   242.25), SIMDE_FLOAT32_C(   261.50), SIMDE_FLOAT32_C(   641.75), SIMDE_FLOAT32_C(   -97.50) } },
    { { SIMDE_FLOAT32_C(  -670.53), SIMDE_FLOAT32_C(  -462.82), SIMDE_FLOAT32_C(   751.50), SIMDE_FLOAT32_C(  -486.38),
        SIMDE_FLOAT32_C(   196.53), SIMDE_FLOAT32_C(  -868.58), SIMDE_FLOAT32_C(   458.66), SIMDE_FLOAT32_C(   869.11),
        SIMDE_FLOAT32_C(  -905.54), SIMDE_FLOAT32_C(   340.08), SIMDE_FLOAT32_C(    -0.51), SIMDE_FLOAT32_C(  -886.06),
        SIMDE_FLOAT32_C(  -823.11), SIMDE_FLOAT32_C(   379.77), SIMDE_FLOAT32_C(   132.91), SIMDE_FLOAT32_C(    77.91) },
       INT32_C(          48),
      { SIMDE_FLOAT32_C(  -670.50), SIMDE_FLOAT32_C(  -462.88), SIMDE_FLOAT32_C(   751.50), SIMDE_FLOAT32_C(  -486.38),
        SIMDE_FLOAT32_C(   196.50), SIMDE_FLOAT32_C(  -868.62), SIMDE_FLOAT32_C(   458.62), SIMDE_FLOAT32_C(   869.12),
        SIMDE_FLOAT32_C(  -905.50), SIMDE_FLOAT32_C(   340.12), SIMDE_FLOAT32_C(    -0.50), SIMDE_FLOAT32_C(  -886.00),
        SIMDE_FLOAT32_C(  -823.12), SIMDE_FLOAT32_C(   379.75), SIMDE_FLOAT32_C(   132.88), SIMDE_FLOAT32_C(    77.88) } },
    { {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(   775.69), SIMDE_FLOAT32_C(   229.57), SIMDE_FLOAT32_C(   679.79),
        SIMDE_FLOAT32_C(  -276.57), SIMDE_FLOAT32_C(   299.51), SIMDE_FLOAT32_C(  -514.82), SIMDE_FLOAT32_C(   965.66),
        SIMDE_FLOAT32_C(  -439.04), SIMDE_FLOAT32_C(  -873.14), SIMDE_FLOAT32_C(  -131.82), SIMDE_FLOAT32_C(    35.67),
        SIMDE_FLOAT32_C(  -713.77), SIMDE_FLOAT32_C(   716.27), SIMDE_FLOAT32_C(   365.14), SIMDE_FLOAT32_C(  -176.59) },
       INT32_C(          64),
      {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(   775.69), SIMDE_FLOAT32_C(   229.56), SIMDE_FLOAT32_C(   679.81),
        SIMDE_FLOAT32_C(  -276.56), SIMDE_FLOAT32_C(   299.50), SIMDE_FLOAT32_C(  -514.81), SIMDE_FLOAT32_C(   965.69),
        SIMDE_FLOAT32_C(  -439.06), SIMDE_FLOAT32_C(  -873.12), SIMDE_FLOAT32_C(  -131.81), SIMDE_FLOAT32_C(    35.69),
        SIMDE_FLOAT32_C(  -713.75), SIMDE_FLOAT32_C(   716.25), SIMDE_FLOAT32_C(   365.12), SIMDE_FLOAT32_C(  -176.56) } },
    { { SIMDE_FLOAT32_C(  -980.06), SIMDE_FLOAT32_C(   599.20), SIMDE_FLOAT32_C(   337.42), SIMDE_FLOAT32_C(   889.05),
        SIMDE_FLOAT32_C(   693.65), SIMDE_FLOAT32_C(  -322.50), SIMDE_FLOAT32_C(  -111.45), SIMDE_FLOAT32_C(   807.60),
        SIMDE_FLOAT32_C(  -145.61), SIMDE_FLOAT32_C(  -731.68), SIMDE_FLOAT32_C(   -59.50), SIMDE_FLOAT32_C(   932.30),
        SIMDE_FLOAT32_C(    83.68), SIMDE_FLOAT32_C(  -511.86), SIMDE_FLOAT32_C(   707.99), SIMDE_FLOAT32_C(  -686.75) },
       INT32_C(          80),
      { SIMDE_FLOAT32_C(  -980.06), SIMDE_FLOAT32_C(   599.19), SIMDE_FLOAT32_C(   337.41), SIMDE_FLOAT32_C(   889.06),
        SIMDE_FLOAT32_C(   693.66), SIMDE_FLOAT32_C(  -322.50), SIMDE_FLOAT32_C(  -111.44), SIMDE_FLOAT32_C(   807.59),
        SIMDE_FLOAT32_C(  -145.62), SIMDE_FLOAT32_C(  -731.69), SIMDE_FLOAT32_C(   -59.50), SIMDE_FLOAT32_C(   932.31),
        SIMDE_FLOAT32_C(    83.69), SIMDE_FLOAT32_C(  -511.88), SIMDE_FLOAT32_C(   708.00), SIMDE_FLOAT32_C(  -686.75) } },
    { {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(   612.76), SIMDE_FLOAT32_C(  -346.88), SIMDE_FLOAT32_C(  -602.92),
        SIMDE_FLOAT32_C(  -826.29), SIMDE_FLOAT32_C(  -220.02), SIMDE_FLOAT32_C(   265.26), SIMDE_FLOAT32_C(   209.38),
        SIMDE_FLOAT32_C(    66.21), SIMDE_FLOAT32_C(   -18.47), SIMDE_FLOAT32_C(  -425.48), SIMDE_FLOAT32_C(   889.62),
        SIMDE_FLOAT32_C(  -550.69), SIMDE_FLOAT32_C(  -546.73), SIMDE_FLOAT32_C(   909.56), SIMDE_FLOAT32_C(  -951.50) },
       INT32_C(          96),
      {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(   612.77), SIMDE_FLOAT32_C(  -346.88), SIMDE_FLOAT32_C(  -602.92),
        SIMDE_FLOAT32_C(  -826.30), SIMDE_FLOAT32_C(  -220.02), SIMDE_FLOAT32_C(   265.27), SIMDE_FLOAT32_C(   209.38),
        SIMDE_FLOAT32_C(    66.20), SIMDE_FLOAT32_C(   -18.47), SIMDE_FLOAT32_C(  -425.48), SIMDE_FLOAT32_C(   889.62),
        SIMDE_FLOAT32_C(  -550.69), SIMDE_FLOAT32_C(  -546.73), SIMDE_FLOAT32_C(   909.56), SIMDE_FLOAT32_C(  -951.50) } },
    { { SIMDE_FLOAT32_C(   742.16), SIMDE_FLOAT32_C(  -531.81), SIMDE_FLOAT32_C(  -312.84), SIMDE_FLOAT32_C(   549.76),
        SIMDE_FLOAT32_C(   322.58), SIMDE_FLOAT32_C(   -44.52), SIMDE_FLOAT32_C(  -509.74), SIMDE_FLOAT32_C(   254.88),
        SIMDE_FLOAT32_C(  -960.84), SIMDE_FLOAT32_C(   -21.60), SIMDE_FLOAT32_C(   -37.13), SIMDE_FLOAT32_C(  -647.59),
        SIMDE_FLOAT32_C(   146.33), SIMDE_FLOAT32_C(   394.29), SIMDE_FLOAT32_C(   965.16), SIMDE_FLOAT32_C(   799.45) },
       INT32_C(         112),
      { SIMDE_FLOAT32_C(   742.16), SIMDE_FLOAT32_C(  -531.81), SIMDE_FLOAT32_C(  -312.84), SIMDE_FLOAT32_C(   549.76),
        SIMDE_FLOAT32_C(   322.58), SIMDE_FLOAT32_C(   -44.52), SIMDE_FLOAT32_C(  -509.74), SIMDE_FLOAT32_C(   254.88),
        SIMDE_FLOAT32_C(  -960.84), SIMDE_FLOAT32_C(   -21.60), SIMDE_FLOAT32_C(   -37.13), SIMDE_FLOAT32_C(  -647.59),
        SIMDE_FLOAT32_C(   146.33), SIMDE_FLOAT32_C(   394.29), SIMDE_FLOAT32_C(   965.16), SIMDE_FLOAT32_C(   799.45) } },
    { { SIMDE_FLOAT32_C(  -861.12), SIMDE_FLOAT32_C(  -420.57), SIMDE_FLOAT32_C(    56.62), SIMDE_FLOAT32_C(   348.26),
        SIMDE_FLOAT32_C(   645.63), SIMDE_FLOAT32_C(  -961.85), SIMDE_FLOAT32_C(   922.78), SIMDE_FLOAT32_C(   535.25),
        SIMDE_FLOAT32_C(  -512.54), SIMDE_FLOAT32_C(  -623.95), SIMDE_FLOAT32_C(   444.81), SIMDE_FLOAT32_C(  -464.04),
        SIMDE_FLOAT32_C(  -833.26), SIMDE_FLOAT32_C(   243.42), SIMDE_FLOAT32_C(  -721.88), SIMDE_FLOAT32_C(  -365.07) },
       INT32_C(         128),
      { SIMDE_FLOAT32_C(  -861.12), SIMDE_FLOAT32_C(  -420.57), SIMDE_FLOAT32_C(    56.62), SIMDE_FLOAT32_C(   348.26),
        SIMDE_FLOAT32_C(   645.63), SIMDE_FLOAT32_C(  -961.85), SIMDE_FLOAT32_C(   922.78), SIMDE_FLOAT32_C(   535.25),
        SIMDE_FLOAT32_C(  -512.54), SIMDE_FLOAT32_C(  -623.95), SIMDE_FLOAT32_C(   444.81), SIMDE_FLOAT32_C(  -464.04),
        SIMDE_FLOAT32_C(  -833.26), SIMDE_FLOAT32_C(   243.42), SIMDE_FLOAT32_C(  -721.88), SIMDE_FLOAT32_C(  -365.07) } },
    { { SIMDE_FLOAT32_C(   827.88), SIMDE_FLOAT32_C(   957.50), SIMDE_FLOAT32_C(  -113.94), SIMDE_FLOAT32_C(  -681.86),
        SIMDE_FLOAT32_C(   212.38), SIMDE_FLOAT32_C(   -74.78), SIMDE_FLOAT32_C(   296.54), SIMDE_FLOAT32_C(  -824.75),
        SIMDE_FLOAT32_C(   277.63), SIMDE_FLOAT32_C(  -557.13), SIMDE_FLOAT32_C(   569.53), SIMDE_FLOAT32_C(   242.79),
        SIMDE_FLOAT32_C(  -757.67), SIMDE_FLOAT32_C(   360.90), SIMDE_FLOAT32_C(   381.66), SIMDE_FLOAT32_C(  -178.25) },
       INT32_C(         144),
      { SIMDE_FLOAT32_C(   827.88), SIMDE_FLOAT32_C(   957.50), SIMDE_FLOAT32_C(  -113.94), SIMDE_FLOAT32_C(  -681.86),
        SIMDE_FLOAT32_C(   212.38), SIMDE_FLOAT32_C(   -74.78), SIMDE_FLOAT32_C(   296.54), SIMDE_FLOAT32_C(  -824.75),
        SIMDE_FLOAT32_C(   277.63), SIMDE_FLOAT32_C(  -557.13), SIMDE_FLOAT32_C(   569.53), SIMDE_FLOAT32_C(   242.79),
        SIMDE_FLOAT32_C(  -757.67), SIMDE_FLOAT32_C(   360.90), SIMDE_FLOAT32_C(   381.66), SIMDE_FLOAT32_C(  -178.25) } },
    { { SIMDE_FLOAT32_C(  -270.08),      SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(  -544.32), SIMDE_FLOAT32_C(  -347.30),
        SIMDE_FLOAT32_C(  -997.36), SIMDE_FLOAT32_C(   -56.86), SIMDE_FLOAT32_C(    28.75), SIMDE_FLOAT32_C(   447.45),
        SIMDE_FLOAT32_C(   479.10), SIMDE_FLOAT32_C(   195.49), SIMDE_FLOAT32_C(  -309.13), SIMDE_FLOAT32_C(   757.23),
        SIMDE_FLOAT32_C(   830.41), SIMDE_FLOAT32_C(  -378.54), SIMDE_FLOAT32_C(   585.10), SIMDE_FLOAT32_C(   787.92) },
       INT32_C(         160),
      { SIMDE_FLOAT32_C(  -270.08),      SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(  -544.32), SIMDE_FLOAT32_C(  -347.30),
        SIMDE_FLOAT32_C(  -997.36), SIMDE_FLOAT32_C(   -56.86), SIMDE_FLOAT32_C(    28.75), SIMDE_FLOAT32_C(   447.45),
        SIMDE_FLOAT32_C(   479.10), SIMDE_FLOAT32_C(   195.49), SIMDE_FLOAT32_C(  -309.13), SIMDE_FLOAT32_C(   757.23),
        SIMDE_FLOAT32_C(   830.41), SIMDE_FLOAT32_C(  -378.54), SIMDE_FLOAT32_C(   585.10), SIMDE_FLOAT32_C(   787.92) } },
    { { SIMDE_FLOAT32_C(  -567.26), SIMDE_FLOAT32_C(   199.78), SIMDE_FLOAT32_C(   175.55), SIMDE_FLOAT32_C(   710.37),
        SIMDE_FLOAT32_C(   642.66), SIMDE_FLOAT32_C(  -254.92), SIMDE_FLOAT32_C(   -46.85), SIMDE_FLOAT32_C(   884.98),
        SIMDE_FLOAT32_C(  -894.02), SIMDE_FLOAT32_C(  -665.18), SIMDE_FLOAT32_C(  -293.26), SIMDE_FLOAT32_C(  -476.50),
        SIMDE_FLOAT32_C(    64.74), SIMDE_FLOAT32_C(   174.12), SIMDE_FLOAT32_C(   -20.82), SIMDE_FLOAT32_C(   717.44) },
       INT32_C(         176),
      { SIMDE_FLOAT32_C(  -567.26), SIMDE_FLOAT32_C(   199.78), SIMDE_FLOAT32_C(   175.55), SIMDE_FLOAT32_C(   710.37),
        SIMDE_FLOAT32_C(   642.66), SIMDE_FLOAT32_C(  -254.92), SIMDE_FLOAT32_C(   -46.85), SIMDE_FLOAT32_C(   884.98),
        SIMDE_FLOAT32_C(  -894.02), SIMDE_FLOAT32_C(  -665.18), SIMDE_FLOAT32_C(  -293.26), SIMDE_FLOAT32_C(  -476.50),
        SIMDE_FLOAT32_C(    64.74), SIMDE_FLOAT32_C(   174.12), SIMDE_FLOAT32_C(   -20.82), SIMDE_FLOAT32_C(   717.44) } },
    { { SIMDE_FLOAT32_C(   922.32), SIMDE_FLOAT32_C(  -253.81), SIMDE_FLOAT32_C(  -375.79), SIMDE_FLOAT32_C(   401.42),
        SIMDE_FLOAT32_C(   941.67), SIMDE_FLOAT32_C(   315.09), SIMDE_FLOAT32_C(   158.65), SIMDE_FLOAT32_C(   772.08),
        SIMDE_FLOAT32_C(   936.54), SIMDE_FLOAT32_C(  -256.25), SIMDE_FLOAT32_C(   560.00), SIMDE_FLOAT32_C(   444.06),
        SIMDE_FLOAT32_C(  -353.00), SIMDE_FLOAT32_C(  -439.70), SIMDE_FLOAT32_C(   876.80), SIMDE_FLOAT32_C(   846.78) },
       INT32_C(         192),
      { SIMDE_FLOAT32_C(   922.32), SIMDE_FLOAT32_C(  -253.81), SIMDE_FLOAT32_C(  -375.79), SIMDE_FLOAT32_C(   401.42),
        SIMDE_FLOAT32_C(   941.67), SIMDE_FLOAT32_C(   315.09), SIMDE_FLOAT32_C(   158.65), SIMDE_FLOAT32_C(   772.08),
        SIMDE_FLOAT32_C(   936.54), SIMDE_FLOAT32_C(  -256.25), SIMDE_FLOAT32_C(   560.00), SIMDE_FLOAT32_C(   444.06),
        SIMDE_FLOAT32_C(  -353.00), SIMDE_FLOAT32_C(  -439.70), SIMDE_FLOAT32_C(   876.80), SIMDE_FLOAT32_C(   846.78) } },
    { { SIMDE_FLOAT32_C(   587.16),      SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(  -519.07), SIMDE_FLOAT32_C(  -459.68),
        SIMDE_FLOAT32_C(   374.42), SIMDE_FLOAT32_C(  -413.09), SIMDE_FLOAT32_C(  -124.87), SIMDE_FLOAT32_C(  -918.84),
        SIMDE_FLOAT32_C(   110.41), SIMDE_FLOAT32_C(   939.87), SIMDE_FLOAT32_C(   255.28), SIMDE_FLOAT32_C(  -910.40),
        SIMDE_FLOAT32_C(   657.31), SIMDE_FLOAT32_C(  -567.96), SIMDE_FLOAT32_C(  -988.08), SIMDE_FLOAT32_C(  -596.51) },
       INT32_C(         208),
      { SIMDE_FLOAT32_C(   587.16),      SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(  -519.07), SIMDE_FLOAT32_C(  -459.68),
        SIMDE_FLOAT32_C(   374.42), SIMDE_FLOAT32_C(  -413.09), SIMDE_FLOAT32_C(  -124.87), SIMDE_FLOAT32_C(  -918.84),
        SIMDE_FLOAT32_C(   110.41), SIMDE_FLOAT32_C(   939.87), SIMDE_FLOAT32_C(   255.28), SIMDE_FLOAT32_C(  -910.40),
        SIMDE_FLOAT32_C(   657.31), SIMDE_FLOAT32_C(  -567.96), SIMDE_FLOAT32_C(  -988.08), SIMDE_FLOAT32_C(  -596.51) } },
    { {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(  -428.01), SIMDE_FLOAT32_C(  -882.75), SIMDE_FLOAT32_C(  -692.12),
        SIMDE_FLOAT32_C(   315.75), SIMDE_FLOAT32_C(   677.25), SIMDE_FLOAT32_C(   751.94), SIMDE_FLOAT32_C(   962.75),
        SIMDE_FLOAT32_C(  -762.45), SIMDE_FLOAT32_C(   628.74), SIMDE_FLOAT32_C(   809.53), SIMDE_FLOAT32_C(   973.39),
        SIMDE_FLOAT32_C(   215.90), SIMDE_FLOAT32_C(   298.97), SIMDE_FLOAT32_C(  -545.68), SIMDE_FLOAT32_C(   756.22) },
       INT32_C(         224),
      {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(  -428.01), SIMDE_FLOAT32_C(  -882.75), SIMDE_FLOAT32_C(  -692.12),
        SIMDE_FLOAT32_C(   315.75), SIMDE_FLOAT32_C(   677.25), SIMDE_FLOAT32_C(   751.94), SIMDE_FLOAT32_C(   962.75),
        SIMDE_FLOAT32_C(  -762.45), SIMDE_FLOAT32_C(   628.74), SIMDE_FLOAT32_C(   809.53), SIMDE_FLOAT32_C(   973.39),
        SIMDE_FLOAT32_C(   215.90), SIMDE_FLOAT32_C(   298.97), SIMDE_FLOAT32_C(  -545.68), SIMDE_FLOAT32_C(   756.22) } },
    { { SIMDE_FLOAT32_C(  -368.65), SIMDE_FLOAT32_C(  -245.45), SIMDE_FLOAT32_C(  -848.36), SIMDE_FLOAT32_C(  -428.78),
        SIMDE_FLOAT32_C(  -990.16), SIMDE_FLOAT32_C(  -758.77), SIMDE_FLOAT32_C(  -771.47), SIMDE_FLOAT32_C(  -558.12),
        SIMDE_FLOAT32_C(  -746.85), SIMDE_FLOAT32_C(  -367.97), SIMDE_FLOAT32_C(   498.14), SIMDE_FLOAT32_C(   666.49),
        SIMDE_FLOAT32_C(   -22.81), SIMDE_FLOAT32_C(   869.48), SIMDE_FLOAT32_C(  -761.51), SIMDE_FLOAT32_C(    94.44) },
       INT32_C(         240),
      { SIMDE_FLOAT32_C(  -368.65), SIMDE_FLOAT32_C(  -245.45), SIMDE_FLOAT32_C(  -848.36), SIMDE_FLOAT32_C(  -428.78),
        SIMDE_FLOAT32_C(  -990.16), SIMDE_FLOAT32_C(  -758.77), SIMDE_FLOAT32_C(  -771.47), SIMDE_FLOAT32_C(  -558.12),
        SIMDE_FLOAT32_C(  -746.85), SIMDE_FLOAT32_C(  -367.97), SIMDE_FLOAT32_C(   498.14), SIMDE_FLOAT32_C(   666.49),
        SIMDE_FLOAT32_C(   -22.81), SIMDE_FLOAT32_C(   869.48), SIMDE_FLOAT32_C(  -761.51), SIMDE_FLOAT32_C(    94.44) } },
    { { SIMDE_FLOAT32_C(   554.23), SIMDE_FLOAT32_C(  -228.31), SIMDE_FLOAT32_C(   929.30), SIMDE_FLOAT32_C(   516.98),
        SIMDE_FLOAT32_C(     9.24), SIMDE_FLOAT32_C(   558.04), SIMDE_FLOAT32_C(   326.51), SIMDE_FLOAT32_C(   -17.36),
        SIMDE_FLOAT32_C(  -226.05), SIMDE_FLOAT32_C(  -374.52), SIMDE_FLOAT32_C(   436.96), SIMDE_FLOAT32_C(  -469.84),
        SIMDE_FLOAT32_C(   298.87), SIMDE_FLOAT32_C(  -521.81), SIMDE_FLOAT32_C(   161.51), SIMDE_FLOAT32_C(  -946.58) },
       INT32_C(           1),
      { SIMDE_FLOAT32_C(   554.00), SIMDE_FLOAT32_C(  -229.00), SIMDE_FLOAT32_C(   929.00), SIMDE_FLOAT32_C(   516.00),
        SIMDE_FLOAT32_C(     9.00), SIMDE_FLOAT32_C(   558.00), SIMDE_FLOAT32_C(   326.00), SIMDE_FLOAT32_C(   -18.00),
        SIMDE_FLOAT32_C(  -227.00), SIMDE_FLOAT32_C(  -375.00), SIMDE_FLOAT32_C(   436.00), SIMDE_FLOAT32_C(  -470.00),
        SIMDE_FLOAT32_C(   298.00), SIMDE_FLOAT32_C(  -522.00), SIMDE_FLOAT32_C(   161.00), SIMDE_FLOAT32_C(  -947.00) } },
    { {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(  -936.74), SIMDE_FLOAT32_C(  -128.94), SIMDE_FLOAT32_C(   961.27),
        SIMDE_FLOAT32_C(  -494.86), SIMDE_FLOAT32_C(   124.21), SIMDE_FLOAT32_C(  -406.70), SIMDE_FLOAT32_C(  -996.73),
        SIMDE_FLOAT32_C(  -209.29), SIMDE_FLOAT32_C(   570.49), SIMDE_FLOAT32_C(   872.75), SIMDE_FLOAT32_C(    29.19),
        SIMDE_FLOAT32_C(  -335.06), SIMDE_FLOAT32_C(  -949.89), SIMDE_FLOAT32_C(  -416.57), SIMDE_FLOAT32_C(   436.63) },
       INT32_C(          17),
      {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(  -937.00), SIMDE_FLOAT32_C(  -129.00), SIMDE_FLOAT32_C(   961.00),
        SIMDE_FLOAT32_C(  -495.00), SIMDE_FLOAT32_C(   124.00), SIMDE_FLOAT32_C(  -407.00), SIMDE_FLOAT32_C(  -997.00),
        SIMDE_FLOAT32_C(  -209.50), SIMDE_FLOAT32_C(   570.00), SIMDE_FLOAT32_C(   872.50), SIMDE_FLOAT32_C(    29.00),
        SIMDE_FLOAT32_C(  -335.50), SIMDE_FLOAT32_C(  -950.00), SIMDE_FLOAT32_C(  -417.00), SIMDE_FLOAT32_C(   436.50) } },
    { {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(   537.46), SIMDE_FLOAT32_C(   426.92), SIMDE_FLOAT32_C(   428.51),
        SIMDE_FLOAT32_C(  -688.59), SIMDE_FLOAT32_C(  -947.61), SIMDE_FLOAT32_C(  -134.53), SIMDE_FLOAT32_C(  -158.43),
        SIMDE_FLOAT32_C(   351.26), SIMDE_FLOAT32_C(   343.66), SIMDE_FLOAT32_C(  -996.91), SIMDE_FLOAT32_C(   404.69),
        SIMDE_FLOAT32_C(   973.48), SIMDE_FLOAT32_C(   735.82), SIMDE_FLOAT32_C(   467.95), SIMDE_FLOAT32_C(  -155.46) },
       INT32_C(          33),
      {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(   537.25), SIMDE_FLOAT32_C(   426.75), SIMDE_FLOAT32_C(   428.50),
        SIMDE_FLOAT32_C(  -688.75), SIMDE_FLOAT32_C(  -947.75), SIMDE_FLOAT32_C(  -134.75), SIMDE_FLOAT32_C(  -158.50),
        SIMDE_FLOAT32_C(   351.25), SIMDE_FLOAT32_C(   343.50), SIMDE_FLOAT32_C(  -997.00), SIMDE_FLOAT32_C(   404.50),
        SIMDE_FLOAT32_C(   973.25), SIMDE_FLOAT32_C(   735.75), SIMDE_FLOAT32_C(   467.75), SIMDE_FLOAT32_C(  -155.50) } },
    { { SIMDE_FLOAT32_C(   968.76), SIMDE_FLOAT32_C(  -709.61), SIMDE_FLOAT32_C(   976.36), SIMDE_FLOAT32_C(  -240.54),
        SIMDE_FLOAT32_C(   860.89), SIMDE_FLOAT32_C(   849.11), SIMDE_FLOAT32_C(   788.66), SIMDE_FLOAT32_C(  -474.18),
        SIMDE_FLOAT32_C(   899.23), SIMDE_FLOAT32_C(  -627.91), SIMDE_FLOAT32_C(   962.45), SIMDE_FLOAT32_C(   878.64),
        SIMDE_FLOAT32_C(  -527.51), SIMDE_FLOAT32_C(  -591.67), SIMDE_FLOAT32_C(   416.11), SIMDE_FLOAT32_C(   899.41) },
       INT32_C(          49),
      { SIMDE_FLOAT32_C(   968.75), SIMDE_FLOAT32_C(  -709.62), SIMDE_FLOAT32_C(   976.25), SIMDE_FLOAT32_C(  -240.62),
        SIMDE_FLOAT32_C(   860.88), SIMDE_FLOAT32_C(   849.00), SIMDE_FLOAT32_C(   788.62), SIMDE_FLOAT32_C(  -474.25),
        SIMDE_FLOAT32_C(   899.12), SIMDE_FLOAT32_C(  -628.00), SIMDE_FLOAT32_C(   962.38), SIMDE_FLOAT32_C(   878.62),
        SIMDE_FLOAT32_C(  -527.62), SIMDE_FLOAT32_C(  -591.75), SIMDE_FLOAT32_C(   416.00), SIMDE_FLOAT32_C(   899.38) } },
    { { SIMDE_FLOAT32_C(   727.51),      SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(  -297.69), SIMDE_FLOAT32_C(  -430.92),
        SIMDE_FLOAT32_C(   303.06), SIMDE_FLOAT32_C(  -954.03), SIMDE_FLOAT32_C(  -427.83), SIMDE_FLOAT32_C(  -292.25),
        SIMDE_FLOAT32_C(  -980.55), SIMDE_FLOAT32_C(  -692.01), SIMDE_FLOAT32_C(  -824.31), SIMDE_FLOAT32_C(  -136.00),
        SIMDE_FLOAT32_C(  -994.91), SIMDE_FLOAT32_C(  -851.22), SIMDE_FLOAT32_C(  -167.25), SIMDE_FLOAT32_C(  -704.52) },
       INT32_C(          65),
      { SIMDE_FLOAT32_C(   727.50),      SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(  -297.75), SIMDE_FLOAT32_C(  -430.94),
        SIMDE_FLOAT32_C(   303.00), SIMDE_FLOAT32_C(  -954.06), SIMDE_FLOAT32_C(  -427.88), SIMDE_FLOAT32_C(  -292.25),
        SIMDE_FLOAT32_C(  -980.56), SIMDE_FLOAT32_C(  -692.06), SIMDE_FLOAT32_C(  -824.31), SIMDE_FLOAT32_C(  -136.00),
        SIMDE_FLOAT32_C(  -994.94), SIMDE_FLOAT32_C(  -851.25), SIMDE_FLOAT32_C(  -167.25), SIMDE_FLOAT32_C(  -704.56) } },
    { { SIMDE_FLOAT32_C(   974.25), SIMDE_FLOAT32_C(   380.88), SIMDE_FLOAT32_C(  -317.81), SIMDE_FLOAT32_C(   873.47),
        SIMDE_FLOAT32_C(   752.96), SIMDE_FLOAT32_C(  -355.35), SIMDE_FLOAT32_C(   752.12), SIMDE_FLOAT32_C(  -774.55),
        SIMDE_FLOAT32_C(    52.97), SIMDE_FLOAT32_C(   168.23), SIMDE_FLOAT32_C(  -875.14), SIMDE_FLOAT32_C(  -110.19),
        SIMDE_FLOAT32_C(  -104.26), SIMDE_FLOAT32_C(  -923.34), SIMDE_FLOAT32_C(   592.12), SIMDE_FLOAT32_C(   464.82) },
       INT32_C(          81),
      { SIMDE_FLOAT32_C(   974.25), SIMDE_FLOAT32_C(   380.88), SIMDE_FLOAT32_C(  -317.81), SIMDE_FLOAT32_C(   873.47),
        SIMDE_FLOAT32_C(   752.94), SIMDE_FLOAT32_C(  -355.38), SIMDE_FLOAT32_C(   752.09), SIMDE_FLOAT32_C(  -774.56),
        SIMDE_FLOAT32_C(    52.97), SIMDE_FLOAT32_C(   168.22), SIMDE_FLOAT32_C(  -875.16), SIMDE_FLOAT32_C(  -110.22),
        SIMDE_FLOAT32_C(  -104.28), SIMDE_FLOAT32_C(  -923.34), SIMDE_FLOAT32_C(   592.09), SIMDE_FLOAT32_C(   464.81) } },
    { { SIMDE_FLOAT32_C(   638.09), SIMDE_FLOAT32_C(  -963.01), SIMDE_FLOAT32_C(  -912.53), SIMDE_FLOAT32_C(   657.54),
        SIMDE_FLOAT32_C(  -655.02), SIMDE_FLOAT32_C(  -736.83), SIMDE_FLOAT32_C(  -478.47), SIMDE_FLOAT32_C(  -649.93),
        SIMDE_FLOAT32_C(  -588.06), SIMDE_FLOAT32_C(   354.29), SIMDE_FLOAT32_C(  -354.45), SIMDE_FLOAT32_C(  -462.92),
        SIMDE_FLOAT32_C(   -53.50), SIMDE_FLOAT32_C(  -198.08), SIMDE_FLOAT32_C(  -488.67), SIMDE_FLOAT32_C(  -672.62) },
       INT32_C(          97),
      { SIMDE_FLOAT32_C(   638.08), SIMDE_FLOAT32_C(  -963.02), SIMDE_FLOAT32_C(  -912.53), SIMDE_FLOAT32_C(   657.53),
        SIMDE_FLOAT32_C(  -655.03), SIMDE_FLOAT32_C(  -736.84), SIMDE_FLOAT32_C(  -478.48), SIMDE_FLOAT32_C(  -649.94),
        SIMDE_FLOAT32_C(  -588.06), SIMDE_FLOAT32_C(   354.28), SIMDE_FLOAT32_C(  -354.45), SIMDE_FLOAT32_C(  -462.92),
        SIMDE_FLOAT32_C(   -53.50), SIMDE_FLOAT32_C(  -198.09), SIMDE_FLOAT32_C(  -488.67), SIMDE_FLOAT32_C(  -672.62) } },
    { { SIMDE_FLOAT32_C(  -615.20), SIMDE_FLOAT32_C(  -919.66), SIMDE_FLOAT32_C(  -871.24), SIMDE_FLOAT32_C(  -863.08),
        SIMDE_FLOAT32_C(  -694.20), SIMDE_FLOAT32_C(   181.73), SIMDE_FLOAT32_C(   305.15), SIMDE_FLOAT32_C(  -569.34),
        SIMDE_FLOAT32_C(  -928.46), SIMDE_FLOAT32_C(  -799.11), SIMDE_FLOAT32_C(  -492.68), SIMDE_FLOAT32_C(   663.66),
        SIMDE_FLOAT32_C(   665.71), SIMDE_FLOAT32_C(   887.04), SIMDE_FLOAT32_C(   301.75), SIMDE_FLOAT32_C(   702.70) },
       INT32_C(         113),
      { SIMDE_FLOAT32_C(  -615.20), SIMDE_FLOAT32_C(  -919.66), SIMDE_FLOAT32_C(  -871.24), SIMDE_FLOAT32_C(  -863.09),
        SIMDE_FLOAT32_C(  -694.20), SIMDE_FLOAT32_C(   181.73), SIMDE_FLOAT32_C(   305.15), SIMDE_FLOAT32_C(  -569.34),
        SIMDE_FLOAT32_C(  -928.46), SIMDE_FLOAT32_C(  -799.12), SIMDE_FLOAT32_C(  -492.69), SIMDE_FLOAT32_C(   663.66),
        SIMDE_FLOAT32_C(   665.70), SIMDE_FLOAT32_C(   887.04), SIMDE_FLOAT32_C(   301.75), SIMDE_FLOAT32_C(   702.70) } },
    { { SIMDE_FLOAT32_C(   -40.71), SIMDE_FLOAT32_C(  -952.32), SIMDE_FLOAT32_C(  -762.32), SIMDE_FLOAT32_C(   480.82),
        SIMDE_FLOAT32_C(  -602.24), SIMDE_FLOAT32_C(  -350.38), SIMDE_FLOAT32_C(  -164.90), SIMDE_FLOAT32_C(    43.31),
        SIMDE_FLOAT32_C(   186.70), SIMDE_FLOAT32_C(   781.61), SIMDE_FLOAT32_C(   845.23), SIMDE_FLOAT32_C(   698.03),
        SIMDE_FLOAT32_C(  -891.01), SIMDE_FLOAT32_C(   329.34), SIMDE_FLOAT32_C(  -917.16), SIMDE_FLOAT32_C(  -810.67) },
       INT32_C(         129),
      { SIMDE_FLOAT32_C(   -40.71), SIMDE_FLOAT32_C(  -952.32), SIMDE_FLOAT32_C(  -762.32), SIMDE_FLOAT32_C(   480.82),
        SIMDE_FLOAT32_C(  -602.24), SIMDE_FLOAT32_C(  -350.38), SIMDE_FLOAT32_C(  -164.90), SIMDE_FLOAT32_C(    43.31),
        SIMDE_FLOAT32_C(   186.70), SIMDE_FLOAT32_C(   781.61), SIMDE_FLOAT32_C(   845.23), SIMDE_FLOAT32_C(   698.03),
        SIMDE_FLOAT32_C(  -891.01), SIMDE_FLOAT32_C(   329.34), SIMDE_FLOAT32_C(  -917.16), SIMDE_FLOAT32_C(  -810.67) } },
    { { SIMDE_FLOAT32_C(  -780.24), SIMDE_FLOAT32_C(  -504.87), SIMDE_FLOAT32_C(  -360.16), SIMDE_FLOAT32_C(   524.91),
        SIMDE_FLOAT32_C(   -74.22), SIMDE_FLOAT32_C(  -288.62), SIMDE_FLOAT32_C(   725.79), SIMDE_FLOAT32_C(   433.10),
        SIMDE_FLOAT32_C(  -624.96), SIMDE_FLOAT32_C(   391.50), SIMDE_FLOAT32_C(   320.14), SIMDE_FLOAT32_C(   676.79),
        SIMDE_FLOAT32_C(    94.20), SIMDE_FLOAT32_C(   294.65), SIMDE_FLOAT32_C(  -363.93), SIMDE_FLOAT32_C(   141.89) },
       INT32_C(         145),
      { SIMDE_FLOAT32_C(  -780.24), SIMDE_FLOAT32_C(  -504.87), SIMDE_FLOAT32_C(  -360.16), SIMDE_FLOAT32_C(   524.91),
        SIMDE_FLOAT32_C(   -74.22), SIMDE_FLOAT32_C(  -288.62), SIMDE_FLOAT32_C(   725.79), SIMDE_FLOAT32_C(   433.10),
        SIMDE_FLOAT32_C(  -624.96), SIMDE_FLOAT32_C(   391.50), SIMDE_FLOAT32_C(   320.14), SIMDE_FLOAT32_C(   676.79),
        SIMDE_FLOAT32_C(    94.20), SIMDE_FLOAT32_C(   294.65), SIMDE_FLOAT32_C(  -363.93), SIMDE_FLOAT32_C(   141.89) } },
    { { SIMDE_FLOAT32_C(  -883.11),      SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(  -818.05), SIMDE_FLOAT32_C(   -48.01),
        SIMDE_FLOAT32_C(  -417.05), SIMDE_FLOAT32_C(   368.66), SIMDE_FLOAT32_C(  -266.40), SIMDE_FLOAT32_C(  -571.82),
        SIMDE_FLOAT32_C(    66.69), SIMDE_FLOAT32_C(  -157.41), SIMDE_FLOAT32_C(   757.52), SIMDE_FLOAT32_C(   149.52),
        SIMDE_FLOAT32_C(    31.92), SIMDE_FLOAT32_C(   215.63), SIMDE_FLOAT32_C(   369.28), SIMDE_FLOAT32_C(   527.05) },
       INT32_C(         161),
      { SIMDE_FLOAT32_C(  -883.11),      SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(  -818.05), SIMDE_FLOAT32_C(   -48.01),
        SIMDE_FLOAT32_C(  -417.05), SIMDE_FLOAT32_C(   368.66), SIMDE_FLOAT32_C(  -266.40), SIMDE_FLOAT32_C(  -571.82),
        SIMDE_FLOAT32_C(    66.69), SIMDE_FLOAT32_C(  -157.41), SIMDE_FLOAT32_C(   757.52), SIMDE_FLOAT32_C(   149.52),
        SIMDE_FLOAT32_C(    31.92), SIMDE_FLOAT32_C(   215.63), SIMDE_FLOAT32_C(   369.28), SIMDE_FLOAT32_C(   527.05) } },
    { { SIMDE_FLOAT32_C(  -433.16),     -SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(   885.93), SIMDE_FLOAT32_C(   -58.11),
        SIMDE_FLOAT32_C(  -988.52), SIMDE_FLOAT32_C(   206.07), SIMDE_FLOAT32_C(  -381.32), SIMDE_FLOAT32_C(   105.68),
        SIMDE_FLOAT32_C(  -499.27), SIMDE_FLOAT32_C(   254.75), SIMDE_FLOAT32_C(  -752.43), SIMDE_FLOAT32_C(  -966.94),
        SIMDE_FLOAT32_C(   371.64), SIMDE_FLOAT32_C(   787.21), SIMDE_FLOAT32_C(  -784.99), SIMDE_FLOAT32_C(  -676.36) },
       INT32_C(         177),
      { SIMDE_FLOAT32_C(  -433.16),     -SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(   885.93), SIMDE_FLOAT32_C(   -58.11),
        SIMDE_FLOAT32_C(  -988.52), SIMDE_FLOAT32_C(   206.07), SIMDE_FLOAT32_C(  -381.32), SIMDE_FLOAT32_C(   105.68),
        SIMDE_FLOAT32_C(  -499.27), SIMDE_FLOAT32_C(   254.75), SIMDE_FLOAT32_C(  -752.43), SIMDE_FLOAT32_C(  -966.94),
        SIMDE_FLOAT32_C(   371.64), SIMDE_FLOAT32_C(   787.21), SIMDE_FLOAT32_C(  -784.99), SIMDE_FLOAT32_C(  -676.36) } },
    { { SIMDE_FLOAT32_C(  -201.66), SIMDE_FLOAT32_C(  -349.65), SIMDE_FLOAT32_C(   899.83), SIMDE_FLOAT32_C(  -444.13),
        SIMDE_FLOAT32_C(   799.88), SIMDE_FLOAT32_C(   -68.25), SIMDE_FLOAT32_C(   771.50), SIMDE_FLOAT32_C(   169.16),
        SIMDE_FLOAT32_C(  -541.21), SIMDE_FLOAT32_C(   626.96), SIMDE_FLOAT32_C(  -936.65), SIMDE_FLOAT32_C(   -88.38),
        SIMDE_FLOAT32_C(  -806.19), SIMDE_FLOAT32_C(  -316.67), SIMDE_FLOAT32_C(  -202.45), SIMDE_FLOAT32_C(   135.69) },
       INT32_C(         193),
      { SIMDE_FLOAT32_C(  -201.66), SIMDE_FLOAT32_C(  -349.65), SIMDE_FLOAT32_C(   899.83), SIMDE_FLOAT32_C(  -444.13),
        SIMDE_FLOAT32_C(   799.88), SIMDE_FLOAT32_C(   -68.25), SIMDE_FLOAT32_C(   771.50), SIMDE_FLOAT32_C(   169.16),
        SIMDE_FLOAT32_C(  -541.21), SIMDE_FLOAT32_C(   626.96), SIMDE_FLOAT32_C(  -936.65), SIMDE_FLOAT32_C(   -88.38),
        SIMDE_FLOAT32_C(  -806.19), SIMDE_FLOAT32_C(  -316.67), SIMDE_FLOAT32_C(  -202.45), SIMDE_FLOAT32_C(   135.69) } },
    { { SIMDE_FLOAT32_C(  -996.37), SIMDE_FLOAT32_C(   754.37), SIMDE_FLOAT32_C(   800.49), SIMDE_FLOAT32_C(  -495.65),
        SIMDE_FLOAT32_C(     9.12), SIMDE_FLOAT32_C(  -951.94), SIMDE_FLOAT32_C(  -462.59), SIMDE_FLOAT32_C(  -619.24),
        SIMDE_FLOAT32_C(   835.28), SIMDE_FLOAT32_C(  -247.58), SIMDE_FLOAT32_C(  -295.60), SIMDE_FLOAT32_C(  -794.56),
        SIMDE_FLOAT32_C(  -663.91), SIMDE_FLOAT32_C(   761.64), SIMDE_FLOAT32_C(     3.78), SIMDE_FLOAT32_C(   -13.56) },
       INT32_C(         209),
      { SIMDE_FLOAT32_C(  -996.37), SIMDE_FLOAT32_C(   754.37), SIMDE_FLOAT32_C(   800.49), SIMDE_FLOAT32_C(  -495.65),
        SIMDE_FLOAT32_C(     9.12), SIMDE_FLOAT32_C(  -951.94), SIMDE_FLOAT32_C(  -462.59), SIMDE_FLOAT32_C(  -619.24),
        SIMDE_FLOAT32_C(   835.28), SIMDE_FLOAT32_C(  -247.58), SIMDE_FLOAT32_C(  -295.60), SIMDE_FLOAT32_C(  -794.56),
        SIMDE_FLOAT32_C(  -663.91), SIMDE_FLOAT32_C(   761.64), SIMDE_FLOAT32_C(     3.78), SIMDE_FLOAT32_C(   -13.56) } },
    { { SIMDE_FLOAT32_C(   559.65),      SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(  -406.79), SIMDE_FLOAT32_C(   331.15),
        SIMDE_FLOAT32_C(   955.48), SIMDE_FLOAT32_C(    52.00), SIMDE_FLOAT32_C(   -41.89), SIMDE_FLOAT32_C(  -981.18),
        SIMDE_FLOAT32_C(   963.62), SIMDE_FLOAT32_C(   151.92), SIMDE_FLOAT32_C(  -297.85), SIMDE_FLOAT32_C(  -238.82),
        SIMDE_FLOAT32_C(  -712.39), SIMDE_FLOAT32_C(   396.96), SIMDE_FLOAT32_C(  -235.20), SIMDE_FLOAT32_C(  -958.02) },
       INT32_C(         225),
      { SIMDE_FLOAT32_C(   559.65),      SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(  -406.79), SIMDE_FLOAT32_C(   331.15),
        SIMDE_FLOAT32_C(   955.48), SIMDE_FLOAT32_C(    52.00), SIMDE_FLOAT32_C(   -41.89), SIMDE_FLOAT32_C(  -981.18),
        SIMDE_FLOAT32_C(   963.62), SIMDE_FLOAT32_C(   151.92), SIMDE_FLOAT32_C(  -297.85), SIMDE_FLOAT32_C(  -238.82),
        SIMDE_FLOAT32_C(  -712.39), SIMDE_FLOAT32_C(   396.96), SIMDE_FLOAT32_C(  -235.20), SIMDE_FLOAT32_C(  -958.02) } },
    { { SIMDE_FLOAT32_C(   245.51), SIMDE_FLOAT32_C(   806.57), SIMDE_FLOAT32_C(   431.86), SIMDE_FLOAT32_C(    80.78),
        SIMDE_FLOAT32_C(  -441.01), SIMDE_FLOAT32_C(  -863.74), SIMDE_FLOAT32_C(   286.22), SIMDE_FLOAT32_C(  -104.92),
        SIMDE_FLOAT32_C(   897.90), SIMDE_FLOAT32_C(  -710.00), SIMDE_FLOAT32_C(   881.52), SIMDE_FLOAT32_C(   559.36),
        SIMDE_FLOAT32_C(   849.65), SIMDE_FLOAT32_C(  -332.16), SIMDE_FLOAT32_C(  -847.43), SIMDE_FLOAT32_C(   180.80) },
       INT32_C(         241),
      { SIMDE_FLOAT32_C(   245.51), SIMDE_FLOAT32_C(   806.57), SIMDE_FLOAT32_C(   431.86), SIMDE_FLOAT32_C(    80.78),
        SIMDE_FLOAT32_C(  -441.01), SIMDE_FLOAT32_C(  -863.74), SIMDE_FLOAT32_C(   286.22), SIMDE_FLOAT32_C(  -104.92),
        SIMDE_FLOAT32_C(   897.90), SIMDE_FLOAT32_C(  -710.00), SIMDE_FLOAT32_C(   881.52), SIMDE_FLOAT32_C(   559.36),
        SIMDE_FLOAT32_C(   849.65), SIMDE_FLOAT32_C(  -332.16), SIMDE_FLOAT32_C(  -847.43), SIMDE_FLOAT32_C(   180.80) } },
    { { SIMDE_FLOAT32_C(   204.57),     -SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(  -357.86), SIMDE_FLOAT32_C(   168.20),
        SIMDE_FLOAT32_C(   290.83), SIMDE_FLOAT32_C(   344.29), SIMDE_FLOAT32_C(   929.37), SIMDE_FLOAT32_C(   578.44),
        SIMDE_FLOAT32_C(  -258.76), SIMDE_FLOAT32_C(  -305.82), SIMDE_FLOAT32_C(   620.43), SIMDE_FLOAT32_C(   938.69),
        SIMDE_FLOAT32_C(   963.33), SIMDE_FLOAT32_C(  -328.47), SIMDE_FLOAT32_C(   184.20), SIMDE_FLOAT32_C(   769.90) },
       INT32_C(           2),
      { SIMDE_FLOAT32_C(   205.00),     -SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(  -357.00), SIMDE_FLOAT32_C(   169.00),
        SIMDE_FLOAT32_C(   291.00), SIMDE_FLOAT32_C(   345.00), SIMDE_FLOAT32_C(   930.00), SIMDE_FLOAT32_C(   579.00),
        SIMDE_FLOAT32_C(  -258.00), SIMDE_FLOAT32_C(  -305.00), SIMDE_FLOAT32_C(   621.00), SIMDE_FLOAT32_C(   939.00),
        SIMDE_FLOAT32_C(   964.00), SIMDE_FLOAT32_C(  -328.00), SIMDE_FLOAT32_C(   185.00), SIMDE_FLOAT32_C(   770.00) } },
    { { SIMDE_FLOAT32_C(  -760.35), SIMDE_FLOAT32_C(   551.21), SIMDE_FLOAT32_C(   223.96), SIMDE_FLOAT32_C(  -862.45),
        SIMDE_FLOAT32_C(   841.21), SIMDE_FLOAT32_C(   105.48), SIMDE_FLOAT32_C(   696.91), SIMDE_FLOAT32_C(   690.87),
        SIMDE_FLOAT32_C(   773.32), SIMDE_FLOAT32_C(   849.48), SIMDE_FLOAT32_C(  -128.33), SIMDE_FLOAT32_C(  -603.37),
        SIMDE_FLOAT32_C(    54.05), SIMDE_FLOAT32_C(    10.58), SIMDE_FLOAT32_C(    38.77), SIMDE_FLOAT32_C(  -777.76) },
       INT32_C(          18),
      { SIMDE_FLOAT32_C(  -760.00), SIMDE_FLOAT32_C(   551.50), SIMDE_FLOAT32_C(   224.00), SIMDE_FLOAT32_C(  -862.00),
        SIMDE_FLOAT32_C(   841.50), SIMDE_FLOAT32_C(   105.50), SIMDE_FLOAT32_C(   697.00), SIMDE_FLOAT32_C(   691.00),
        SIMDE_FLOAT32_C(   773.50), SIMDE_FLOAT32_C(   849.50), SIMDE_FLOAT32_C(  -128.00), SIMDE_FLOAT32_C(  -603.00),
        SIMDE_FLOAT32_C(    54.50), SIMDE_FLOAT32_C(    11.00), SIMDE_FLOAT32_C(    39.00), SIMDE_FLOAT32_C(  -777.50) } },
    { { SIMDE_FLOAT32_C(  -616.94), SIMDE_FLOAT32_C(  -848.38), SIMDE_FLOAT32_C(   879.86), SIMDE_FLOAT32_C(   124.30),
        SIMDE_FLOAT32_C(  -154.21), SIMDE_FLOAT32_C(   500.29), SIMDE_FLOAT32_C(    62.99), SIMDE_FLOAT32_C(  -190.87),
        SIMDE_FLOAT32_C(  -828.18), SIMDE_FLOAT32_C(  -752.81), SIMDE_FLOAT32_C(  -420.98), SIMDE_FLOAT32_C(  -724.79),
        SIMDE_FLOAT32_C(  -487.82), SIMDE_FLOAT32_C(   -92.10), SIMDE_FLOAT32_C(  -485.14), SIMDE_FLOAT32_C(  -936.62) },
       INT32_C(          34),
      { SIMDE_FLOAT32_C(  -616.75), SIMDE_FLOAT32_C(  -848.25), SIMDE_FLOAT32_C(   880.00), SIMDE_FLOAT32_C(   124.50),
        SIMDE_FLOAT32_C(  -154.00), SIMDE_FLOAT32_C(   500.50), SIMDE_FLOAT32_C(    63.00), SIMDE_FLOAT32_C(  -190.75),
        SIMDE_FLOAT32_C(  -828.00), SIMDE_FLOAT32_C(  -752.75), SIMDE_FLOAT32_C(  -420.75), SIMDE_FLOAT32_C(  -724.75),
        SIMDE_FLOAT32_C(  -487.75), SIMDE_FLOAT32_C(   -92.00), SIMDE_FLOAT32_C(  -485.00), SIMDE_FLOAT32_C(  -936.50) } },
    { { SIMDE_FLOAT32_C(  -347.59), SIMDE_FLOAT32_C(   904.60), SIMDE_FLOAT32_C(   237.34), SIMDE_FLOAT32_C(  -650.69),
        SIMDE_FLOAT32_C(   595.46), SIMDE_FLOAT32_C(    10.66), SIMDE_FLOAT32_C(  -801.21), SIMDE_FLOAT32_C(  -532.87),
        SIMDE_FLOAT32_C(   407.29), SIMDE_FLOAT32_C(   252.84), SIMDE_FLOAT32_C(   477.72), SIMDE_FLOAT32_C(  -553.94),
        SIMDE_FLOAT32_C(   475.08), SIMDE_FLOAT32_C(   779.13), SIMDE_FLOAT32_C(  -170.89), SIMDE_FLOAT32_C(   626.70) },
       INT32_C(          50),
      { SIMDE_FLOAT32_C(  -347.50), SIMDE_FLOAT32_C(   904.62), SIMDE_FLOAT32_C(   237.38), SIMDE_FLOAT32_C(  -650.62),
        SIMDE_FLOAT32_C(   595.50), SIMDE_FLOAT32_C(    10.75), SIMDE_FLOAT32_C(  -801.12), SIMDE_FLOAT32_C(  -532.75),
        SIMDE_FLOAT32_C(   407.38), SIMDE_FLOAT32_C(   252.88), SIMDE_FLOAT32_C(   477.75), SIMDE_FLOAT32_C(  -553.88),
        SIMDE_FLOAT32_C(   475.12), SIMDE_FLOAT32_C(   779.25), SIMDE_FLOAT32_C(  -170.88), SIMDE_FLOAT32_C(   626.75) } },
    { {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(  -527.51), SIMDE_FLOAT32_C(   159.28), SIMDE_FLOAT32_C(    16.41),
        SIMDE_FLOAT32_C(   281.62), SIMDE_FLOAT32_C(   331.09), SIMDE_FLOAT32_C(   263.60), SIMDE_FLOAT32_C(   860.64),
        SIMDE_FLOAT32_C(   606.30), SIMDE_FLOAT32_C(   775.77), SIMDE_FLOAT32_C(  -231.46), SIMDE_FLOAT32_C(  -878.84),
        SIMDE_FLOAT32_C(   839.16), SIMDE_FLOAT32_C(   -99.59), SIMDE_FLOAT32_C(  -226.43), SIMDE_FLOAT32_C(   743.75) },
       INT32_C(          66),
      {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(  -527.50), SIMDE_FLOAT32_C(   159.31), SIMDE_FLOAT32_C(    16.44),
        SIMDE_FLOAT32_C(   281.62), SIMDE_FLOAT32_C(   331.12), SIMDE_FLOAT32_C(   263.62), SIMDE_FLOAT32_C(   860.69),
        SIMDE_FLOAT32_C(   606.31), SIMDE_FLOAT32_C(   775.81), SIMDE_FLOAT32_C(  -231.44), SIMDE_FLOAT32_C(  -878.81),
        SIMDE_FLOAT32_C(   839.19), SIMDE_FLOAT32_C(   -99.56), SIMDE_FLOAT32_C(  -226.38), SIMDE_FLOAT32_C(   743.75) } },
    { { SIMDE_FLOAT32_C(   339.22), SIMDE_FLOAT32_C(   148.40), SIMDE_FLOAT32_C(   321.67), SIMDE_FLOAT32_C(   806.35),
        SIMDE_FLOAT32_C(  -444.31), SIMDE_FLOAT32_C(  -425.49), SIMDE_FLOAT32_C(   284.07), SIMDE_FLOAT32_C(     1.75),
        SIMDE_FLOAT32_C(  -950.41), SIMDE_FLOAT32_C(    63.20), SIMDE_FLOAT32_C(   830.86), SIMDE_FLOAT32_C(   676.28),
        SIMDE_FLOAT32_C(  -277.81), SIMDE_FLOAT32_C(   784.28), SIMDE_FLOAT32_C(  -851.22), SIMDE_FLOAT32_C(   881.47) },
       INT32_C(          82),
      { SIMDE_FLOAT32_C(   339.25), SIMDE_FLOAT32_C(   148.41), SIMDE_FLOAT32_C(   321.69), SIMDE_FLOAT32_C(   806.38),
        SIMDE_FLOAT32_C(  -444.28), SIMDE_FLOAT32_C(  -425.47), SIMDE_FLOAT32_C(   284.09), SIMDE_FLOAT32_C(     1.75),
        SIMDE_FLOAT32_C(  -950.41), SIMDE_FLOAT32_C(    63.22), SIMDE_FLOAT32_C(   830.88), SIMDE_FLOAT32_C(   676.28),
        SIMDE_FLOAT32_C(  -277.78), SIMDE_FLOAT32_C(   784.28), SIMDE_FLOAT32_C(  -851.22), SIMDE_FLOAT32_C(   881.50) } },
    { {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(   212.56), SIMDE_FLOAT32_C(  -935.72), SIMDE_FLOAT32_C(   291.04),
        SIMDE_FLOAT32_C(  -181.14), SIMDE_FLOAT32_C(   840.05), SIMDE_FLOAT32_C(  -940.42), SIMDE_FLOAT32_C(   -59.98),
        SIMDE_FLOAT32_C(   679.21), SIMDE_FLOAT32_C(   -40.01), SIMDE_FLOAT32_C(   713.59), SIMDE_FLOAT32_C(   422.96),
        SIMDE_FLOAT32_C(    97.73), SIMDE_FLOAT32_C(  -163.53), SIMDE_FLOAT32_C(  -237.82), SIMDE_FLOAT32_C(  -753.86) },
       INT32_C(          98),
      {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(   212.56), SIMDE_FLOAT32_C(  -935.72), SIMDE_FLOAT32_C(   291.05),
        SIMDE_FLOAT32_C(  -181.12), SIMDE_FLOAT32_C(   840.06), SIMDE_FLOAT32_C(  -940.41), SIMDE_FLOAT32_C(   -59.97),
        SIMDE_FLOAT32_C(   679.22), SIMDE_FLOAT32_C(   -40.00), SIMDE_FLOAT32_C(   713.59), SIMDE_FLOAT32_C(   422.97),
        SIMDE_FLOAT32_C(    97.73), SIMDE_FLOAT32_C(  -163.52), SIMDE_FLOAT32_C(  -237.81), SIMDE_FLOAT32_C(  -753.86) } },
    { { SIMDE_FLOAT32_C(  -198.17), SIMDE_FLOAT32_C(  -267.36), SIMDE_FLOAT32_C(   852.61), SIMDE_FLOAT32_C(   803.57),
        SIMDE_FLOAT32_C(  -217.77), SIMDE_FLOAT32_C(   -84.19), SIMDE_FLOAT32_C(   634.43), SIMDE_FLOAT32_C(  -541.49),
        SIMDE_FLOAT32_C(   638.00), SIMDE_FLOAT32_C(   418.71), SIMDE_FLOAT32_C(  -392.71), SIMDE_FLOAT32_C(   519.47),
        SIMDE_FLOAT32_C(  -780.61), SIMDE_FLOAT32_C(  -962.31), SIMDE_FLOAT32_C(  -267.97), SIMDE_FLOAT32_C(  -716.33) },
       INT32_C(         114),
      { SIMDE_FLOAT32_C(  -198.16), SIMDE_FLOAT32_C(  -267.36), SIMDE_FLOAT32_C(   852.62), SIMDE_FLOAT32_C(   803.57),
        SIMDE_FLOAT32_C(  -217.77), SIMDE_FLOAT32_C(   -84.19), SIMDE_FLOAT32_C(   634.44), SIMDE_FLOAT32_C(  -541.48),
        SIMDE_FLOAT32_C(   638.00), SIMDE_FLOAT32_C(   418.71), SIMDE_FLOAT32_C(  -392.70), SIMDE_FLOAT32_C(   519.48),
        SIMDE_FLOAT32_C(  -780.61), SIMDE_FLOAT32_C(  -962.30), SIMDE_FLOAT32_C(  -267.97), SIMDE_FLOAT32_C(  -716.33) } },
    { { SIMDE_FLOAT32_C(   550.89), SIMDE_FLOAT32_C(  -876.28), SIMDE_FLOAT32_C(   388.30), SIMDE_FLOAT32_C(  -509.09),
        SIMDE_FLOAT32_C(   802.93), SIMDE_FLOAT32_C(  -651.71), SIMDE_FLOAT32_C(  -795.50), SIMDE_FLOAT32_C(   225.90),
        SIMDE_FLOAT32_C(   446.02), SIMDE_FLOAT32_C(    40.97), SIMDE_FLOAT32_C(   988.08), SIMDE_FLOAT32_C(   692.15),
        SIMDE_FLOAT32_C(   199.10), SIMDE_FLOAT32_C(  -443.39), SIMDE_FLOAT32_C(  -506.02), SIMDE_FLOAT32_C(   931.74) },
       INT32_C(         130),
      { SIMDE_FLOAT32_C(   550.89), SIMDE_FLOAT32_C(  -876.28), SIMDE_FLOAT32_C(   388.30), SIMDE_FLOAT32_C(  -509.09),
        SIMDE_FLOAT32_C(   802.93), SIMDE_FLOAT32_C(  -651.71), SIMDE_FLOAT32_C(  -795.50), SIMDE_FLOAT32_C(   225.90),
        SIMDE_FLOAT32_C(   446.02), SIMDE_FLOAT32_C(    40.97), SIMDE_FLOAT32_C(   988.08), SIMDE_FLOAT32_C(   692.15),
        SIMDE_FLOAT32_C(   199.10), SIMDE_FLOAT32_C(  -443.39), SIMDE_FLOAT32_C(  -506.02), SIMDE_FLOAT32_C(   931.74) } },
    { { SIMDE_FLOAT32_C(  -702.45), SIMDE_FLOAT32_C(  -286.03), SIMDE_FLOAT32_C(   325.03), SIMDE_FLOAT32_C(   931.98),
        SIMDE_FLOAT32_C(   172.48), SIMDE_FLOAT32_C(   -36.97), SIMDE_FLOAT32_C(   350.69), SIMDE_FLOAT32_C(   779.77),
        SIMDE_FLOAT32_C(  -517.50), SIMDE_FLOAT32_C(   570.08), SIMDE_FLOAT32_C(   817.46), SIMDE_FLOAT32_C(   214.53),
        SIMDE_FLOAT32_C(   853.75), SIMDE_FLOAT32_C(   146.18), SIMDE_FLOAT32_C(  -234.57), SIMDE_FLOAT32_C(   977.48) },
       INT32_C(         146),
      { SIMDE_FLOAT32_C(  -702.45), SIMDE_FLOAT32_C(  -286.03), SIMDE_FLOAT32_C(   325.03), SIMDE_FLOAT32_C(   931.98),
        SIMDE_FLOAT32_C(   172.48), SIMDE_FLOAT32_C(   -36.97), SIMDE_FLOAT32_C(   350.69), SIMDE_FLOAT32_C(   779.77),
        SIMDE_FLOAT32_C(  -517.50), SIMDE_FLOAT32_C(   570.08), SIMDE_FLOAT32_C(   817.46), SIMDE_FLOAT32_C(   214.53),
        SIMDE_FLOAT32_C(   853.75), SIMDE_FLOAT32_C(   146.18), SIMDE_FLOAT32_C(  -234.57), SIMDE_FLOAT32_C(   977.48) } },
    { {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(   780.41), SIMDE_FLOAT32_C(  -117.23), SIMDE_FLOAT32_C(   460.84),
        SIMDE_FLOAT32_C(     6.31), SIMDE_FLOAT32_C(  -671.21), SIMDE_FLOAT32_C(  -498.20), SIMDE_FLOAT32_C(    -5.62),
        SIMDE_FLOAT32_C(  -979.06), SIMDE_FLOAT32_C(   700.91), SIMDE_FLOAT32_C(   551.00), SIMDE_FLOAT32_C(  -485.08),
        SIMDE_FLOAT32_C(   632.65), SIMDE_FLOAT32_C(   960.22), SIMDE_FLOAT32_C(  -187.53), SIMDE_FLOAT32_C(  -653.38) },
       INT32_C(         162),
      {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(   780.41), SIMDE_FLOAT32_C(  -117.23), SIMDE_FLOAT32_C(   460.84),
        SIMDE_FLOAT32_C(     6.31), SIMDE_FLOAT32_C(  -671.21), SIMDE_FLOAT32_C(  -498.20), SIMDE_FLOAT32_C(    -5.62),
        SIMDE_FLOAT32_C(  -979.06), SIMDE_FLOAT32_C(   700.91), SIMDE_FLOAT32_C(   551.00), SIMDE_FLOAT32_C(  -485.08),
        SIMDE_FLOAT32_C(   632.65), SIMDE_FLOAT32_C(   960.22), SIMDE_FLOAT32_C(  -187.53), SIMDE_FLOAT32_C(  -653.38) } },
    { { SIMDE_FLOAT32_C(   519.10),     -SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(  -904.85), SIMDE_FLOAT32_C(   298.88),
        SIMDE_FLOAT32_C(  -269.23), SIMDE_FLOAT32_C(   665.23), SIMDE_FLOAT32_C(   116.34), SIMDE_FLOAT32_C(   945.30),
        SIMDE_FLOAT32_C(   518.99), SIMDE_FLOAT32_C(  -737.48), SIMDE_FLOAT32_C(  -289.27), SIMDE_FLOAT32_C(   496.46),
        SIMDE_FLOAT32_C(  -202.99), SIMDE_FLOAT32_C(   967.07), SIMDE_FLOAT32_C(   276.87), SIMDE_FLOAT32_C(   679.78) },
       INT32_C(         178),
      { SIMDE_FLOAT32_C(   519.10),     -SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(  -904.85), SIMDE_FLOAT32_C(   298.88),
        SIMDE_FLOAT32_C(  -269.23), SIMDE_FLOAT32_C(   665.23), SIMDE_FLOAT32_C(   116.34), SIMDE_FLOAT32_C(   945.30),
        SIMDE_FLOAT32_C(   518.99), SIMDE_FLOAT32_C(  -737.48), SIMDE_FLOAT32_C(  -289.27), SIMDE_FLOAT32_C(   496.46),
        SIMDE_FLOAT32_C(  -202.99), SIMDE_FLOAT32_C(   967.07), SIMDE_FLOAT32_C(   276.87), SIMDE_FLOAT32_C(   679.78) } },
    { { SIMDE_FLOAT32_C(   929.71), SIMDE_FLOAT32_C(   277.56), SIMDE_FLOAT32_C(  -970.49), SIMDE_FLOAT32_C(   630.62),
        SIMDE_FLOAT32_C(  -171.44), SIMDE_FLOAT32_C(  -455.57), SIMDE_FLOAT32_C(   263.26), SIMDE_FLOAT32_C(  -211.22),
        SIMDE_FLOAT32_C(   356.90), SIMDE_FLOAT32_C(   609.88), SIMDE_FLOAT32_C(  -925.98), SIMDE_FLOAT32_C(  -898.64),
        SIMDE_FLOAT32_C(   128.99), SIMDE_FLOAT32_C(  -677.71), SIMDE_FLOAT32_C(  -803.49), SIMDE_FLOAT32_C(  -572.13) },
       INT32_C(         194),
      { SIMDE_FLOAT32_C(   929.71), SIMDE_FLOAT32_C(   277.56), SIMDE_FLOAT32_C(  -970.49), SIMDE_FLOAT32_C(   630.62),
        SIMDE_FLOAT32_C(  -171.44), SIMDE_FLOAT32_C(  -455.57), SIMDE_FLOAT32_C(   263.26), SIMDE_FLOAT32_C(  -211.22),
        SIMDE_FLOAT32_C(   356.90), SIMDE_FLOAT32_C(   609.88), SIMDE_FLOAT32_C(  -925.98), SIMDE_FLOAT32_C(  -898.64),
        SIMDE_FLOAT32_C(   128.99), SIMDE_FLOAT32_C(  -677.71), SIMDE_FLOAT32_C(  -803.49), SIMDE_FLOAT32_C(  -572.13) } },
    { { SIMDE_FLOAT32_C(   861.75), SIMDE_FLOAT32_C(   544.21), SIMDE_FLOAT32_C(    -1.64), SIMDE_FLOAT32_C(   380.73),
        SIMDE_FLOAT32_C(   806.73), SIMDE_FLOAT32_C(   709.09), SIMDE_FLOAT32_C(  -122.80), SIMDE_FLOAT32_C(  -396.26),
        SIMDE_FLOAT32_C(   676.16), SIMDE_FLOAT32_C(  -845.93), SIMDE_FLOAT32_C(  -716.49), SIMDE_FLOAT32_C(   104.06),
        SIMDE_FLOAT32_C(  -562.75), SIMDE_FLOAT32_C(  -707.92), SIMDE_FLOAT32_C(    33.77), SIMDE_FLOAT32_C(   714.82) },
       INT32_C(         210),
      { SIMDE_FLOAT32_C(   861.75), SIMDE_FLOAT32_C(   544.21), SIMDE_FLOAT32_C(    -1.64), SIMDE_FLOAT32_C(   380.73),
        SIMDE_FLOAT32_C(   806.73), SIMDE_FLOAT32_C(   709.09), SIMDE_FLOAT32_C(  -122.80), SIMDE_FLOAT32_C(  -396.26),
        SIMDE_FLOAT32_C(   676.16), SIMDE_FLOAT32_C(  -845.93), SIMDE_FLOAT32_C(  -716.49), SIMDE_FLOAT32_C(   104.06),
        SIMDE_FLOAT32_C(  -562.75), SIMDE_FLOAT32_C(  -707.92), SIMDE_FLOAT32_C(    33.77), SIMDE_FLOAT32_C(   714.82) } },
    { { SIMDE_FLOAT32_C(  -335.61), SIMDE_FLOAT32_C(  -456.62), SIMDE_FLOAT32_C(  -133.99), SIMDE_FLOAT32_C(   927.65),
        SIMDE_FLOAT32_C(   332.15), SIMDE_FLOAT32_C(  -777.08), SIMDE_FLOAT32_C(   537.54), SIMDE_FLOAT32_C(   406.17),
        SIMDE_FLOAT32_C(  -675.72), SIMDE_FLOAT32_C(  -333.47), SIMDE_FLOAT32_C(   728.46), SIMDE_FLOAT32_C(  -479.21),
        SIMDE_FLOAT32_C(    94.39), SIMDE_FLOAT32_C(  -218.48), SIMDE_FLOAT32_C(  -617.46), SIMDE_FLOAT32_C(  -361.40) },
       INT32_C(         226),
      { SIMDE_FLOAT32_C(  -335.61), SIMDE_FLOAT32_C(  -456.62), SIMDE_FLOAT32_C(  -133.99), SIMDE_FLOAT32_C(   927.65),
        SIMDE_FLOAT32_C(   332.15), SIMDE_FLOAT32_C(  -777.08), SIMDE_FLOAT32_C(   537.54), SIMDE_FLOAT32_C(   406.17),
        SIMDE_FLOAT32_C(  -675.72), SIMDE_FLOAT32_C(  -333.47), SIMDE_FLOAT32_C(   728.46), SIMDE_FLOAT32_C(  -479.21),
        SIMDE_FLOAT32_C(    94.39), SIMDE_FLOAT32_C(  -218.48), SIMDE_FLOAT32_C(  -617.46), SIMDE_FLOAT32_C(  -361.40) } },
    { {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(  -554.67), SIMDE_FLOAT32_C(   488.98), SIMDE_FLOAT32_C(  -359.53),
        SIMDE_FLOAT32_C(    49.07), SIMDE_FLOAT32_C(   165.14), SIMDE_FLOAT32_C(  -205.46), SIMDE_FLOAT32_C(   332.58),
        SIMDE_FLOAT32_C(  -730.80), SIMDE_FLOAT32_C(   231.79), SIMDE_FLOAT32_C(   624.65), SIMDE_FLOAT32_C(   302.97),
        SIMDE_FLOAT32_C(   -53.39), SIMDE_FLOAT32_C(   946.24), SIMDE_FLOAT32_C(   967.36), SIMDE_FLOAT32_C(   489.99) },
       INT32_C(         242),
      {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(  -554.67), SIMDE_FLOAT32_C(   488.98), SIMDE_FLOAT32_C(  -359.53),
        SIMDE_FLOAT32_C(    49.07), SIMDE_FLOAT32_C(   165.14), SIMDE_FLOAT32_C(  -205.46), SIMDE_FLOAT32_C(   332.58),
        SIMDE_FLOAT32_C(  -730.80), SIMDE_FLOAT32_C(   231.79), SIMDE_FLOAT32_C(   624.65), SIMDE_FLOAT32_C(   302.97),
        SIMDE_FLOAT32_C(   -53.39), SIMDE_FLOAT32_C(   946.24), SIMDE_FLOAT32_C(   967.36), SIMDE_FLOAT32_C(   489.99) } },
    { { SIMDE_FLOAT32_C(  -177.86),     -SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(   432.55), SIMDE_FLOAT32_C(  -771.68),
        SIMDE_FLOAT32_C(   359.44), SIMDE_FLOAT32_C(  -900.93), SIMDE_FLOAT32_C(   956.78), SIMDE_FLOAT32_C(   880.23),
        SIMDE_FLOAT32_C(   193.47), SIMDE_FLOAT32_C(  -261.69), SIMDE_FLOAT32_C(  -737.23), SIMDE_FLOAT32_C(   832.07),
        SIMDE_FLOAT32_C(  -481.81), SIMDE_FLOAT32_C(  -973.96), SIMDE_FLOAT32_C(  -722.60), SIMDE_FLOAT32_C(  -992.83) },
       INT32_C(           3),
      { SIMDE_FLOAT32_C(  -177.00),     -SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(   432.00), SIMDE_FLOAT32_C(  -771.00),
        SIMDE_FLOAT32_C(   359.00), SIMDE_FLOAT32_C(  -900.00), SIMDE_FLOAT32_C(   956.00), SIMDE_FLOAT32_C(   880.00),
        SIMDE_FLOAT32_C(   193.00), SIMDE_FLOAT32_C(  -261.00), SIMDE_FLOAT32_C(  -737.00), SIMDE_FLOAT32_C(   832.00),
        SIMDE_FLOAT32_C(  -481.00), SIMDE_FLOAT32_C(  -973.00), SIMDE_FLOAT32_C(  -722.00), SIMDE_FLOAT32_C(  -992.00) } },
    { { SIMDE_FLOAT32_C(   461.05), SIMDE_FLOAT32_C(  -340.96), SIMDE_FLOAT32_C(   441.50), SIMDE_FLOAT32_C(  -307.15),
        SIMDE_FLOAT32_C(  -716.30), SIMDE_FLOAT32_C(  -255.53), SIMDE_FLOAT32_C(   639.46), SIMDE_FLOAT32_C(  -770.07),
        SIMDE_FLOAT32_C(  -288.17), SIMDE_FLOAT32_C(   129.45), SIMDE_FLOAT32_C(    42.18), SIMDE_FLOAT32_C(  -393.15),
        SIMDE_FLOAT32_C(   951.59), SIMDE_FLOAT32_C(  -922.65), SIMDE_FLOAT32_C(  -960.61), SIMDE_FLOAT32_C(  -820.09) },
       INT32_C(          19),
      { SIMDE_FLOAT32_C(   461.00), SIMDE_FLOAT32_C(  -340.50), SIMDE_FLOAT32_C(   441.50), SIMDE_FLOAT32_C(  -307.00),
        SIMDE_FLOAT32_C(  -716.00), SIMDE_FLOAT32_C(  -255.50), SIMDE_FLOAT32_C(   639.00), SIMDE_FLOAT32_C(  -770.00),
        SIMDE_FLOAT32_C(  -288.00), SIMDE_FLOAT32_C(   129.00), SIMDE_FLOAT32_C(    42.00), SIMDE_FLOAT32_C(  -393.00),
        SIMDE_FLOAT32_C(   951.50), SIMDE_FLOAT32_C(  -922.50), SIMDE_FLOAT32_C(  -960.50), SIMDE_FLOAT32_C(  -820.00) } },
    { { SIMDE_FLOAT32_C(  -861.53),     -SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(   317.02), SIMDE_FLOAT32_C(   331.93),
        SIMDE_FLOAT32_C(  -125.00), SIMDE_FLOAT32_C(   579.79), SIMDE_FLOAT32_C(   164.00), SIMDE_FLOAT32_C(   393.19),
        SIMDE_FLOAT32_C(   605.84), SIMDE_FLOAT32_C(   441.40), SIMDE_FLOAT32_C(   400.36), SIMDE_FLOAT32_C(  -727.65),
        SIMDE_FLOAT32_C(  -232.14), SIMDE_FLOAT32_C(  -427.33), SIMDE_FLOAT32_C(   733.40), SIMDE_FLOAT32_C(   426.90) },
       INT32_C(          35),
      { SIMDE_FLOAT32_C(  -861.50),     -SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(   317.00), SIMDE_FLOAT32_C(   331.75),
        SIMDE_FLOAT32_C(  -125.00), SIMDE_FLOAT32_C(   579.75), SIMDE_FLOAT32_C(   164.00), SIMDE_FLOAT32_C(   393.00),
        SIMDE_FLOAT32_C(   605.75), SIMDE_FLOAT32_C(   441.25), SIMDE_FLOAT32_C(   400.25), SIMDE_FLOAT32_C(  -727.50),
        SIMDE_FLOAT32_C(  -232.00), SIMDE_FLOAT32_C(  -427.25), SIMDE_FLOAT32_C(   733.25), SIMDE_FLOAT32_C(   426.75) } },
    { { SIMDE_FLOAT32_C(  -241.35), SIMDE_FLOAT32_C(  -934.30), SIMDE_FLOAT32_C(   940.53), SIMDE_FLOAT32_C(   470.48),
        SIMDE_FLOAT32_C(   195.15), SIMDE_FLOAT32_C(   -17.29), SIMDE_FLOAT32_C(  -922.68), SIMDE_FLOAT32_C(   146.74),
        SIMDE_FLOAT32_C(    60.06), SIMDE_FLOAT32_C(  -883.28), SIMDE_FLOAT32_C(   326.65), SIMDE_FLOAT32_C(  -503.15),
        SIMDE_FLOAT32_C(  -744.81), SIMDE_FLOAT32_C(   463.34), SIMDE_FLOAT32_C(   813.88), SIMDE_FLOAT32_C(   587.12) },
       INT32_C(          51),
      { SIMDE_FLOAT32_C(  -241.25), SIMDE_FLOAT32_C(  -934.25), SIMDE_FLOAT32_C(   940.50), SIMDE_FLOAT32_C(   470.38),
        SIMDE_FLOAT32_C(   195.12), SIMDE_FLOAT32_C(   -17.25), SIMDE_FLOAT32_C(  -922.62), SIMDE_FLOAT32_C(   146.62),
        SIMDE_FLOAT32_C(    60.00), SIMDE_FLOAT32_C(  -883.25), SIMDE_FLOAT32_C(   326.62), SIMDE_FLOAT32_C(  -503.12),
        SIMDE_FLOAT32_C(  -744.75), SIMDE_FLOAT32_C(   463.25), SIMDE_FLOAT32_C(   813.88), SIMDE_FLOAT32_C(   587.00) } },
    { { SIMDE_FLOAT32_C(   393.67), SIMDE_FLOAT32_C(  -248.88), SIMDE_FLOAT32_C(   731.52), SIMDE_FLOAT32_C(    -0.49),
        SIMDE_FLOAT32_C(  -807.48), SIMDE_FLOAT32_C(   131.89), SIMDE_FLOAT32_C(   271.86), SIMDE_FLOAT32_C(   -39.62),
        SIMDE_FLOAT32_C(   704.55), SIMDE_FLOAT32_C(     5.26), SIMDE_FLOAT32_C(  -612.72), SIMDE_FLOAT32_C(   718.72),
        SIMDE_FLOAT32_C(   431.50), SIMDE_FLOAT32_C(  -902.12), SIMDE_FLOAT32_C(  -522.63), SIMDE_FLOAT32_C(   497.20) },
       INT32_C(          67),
      { SIMDE_FLOAT32_C(   393.62), SIMDE_FLOAT32_C(  -248.88), SIMDE_FLOAT32_C(   731.50), SIMDE_FLOAT32_C(    -0.44),
        SIMDE_FLOAT32_C(  -807.44), SIMDE_FLOAT32_C(   131.88), SIMDE_FLOAT32_C(   271.81), SIMDE_FLOAT32_C(   -39.56),
        SIMDE_FLOAT32_C(   704.50), SIMDE_FLOAT32_C(     5.25), SIMDE_FLOAT32_C(  -612.69), SIMDE_FLOAT32_C(   718.69),
        SIMDE_FLOAT32_C(   431.50), SIMDE_FLOAT32_C(  -902.06), SIMDE_FLOAT32_C(  -522.62), SIMDE_FLOAT32_C(   497.19) } },
    { { SIMDE_FLOAT32_C(   947.85),      SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(    21.12), SIMDE_FLOAT32_C(  -974.83),
        SIMDE_FLOAT32_C(   839.09), SIMDE_FLOAT32_C(  -918.82), SIMDE_FLOAT32_C(  -858.11), SIMDE_FLOAT32_C(   165.74),
        SIMDE_FLOAT32_C(  -421.96), SIMDE_FLOAT32_C(  -602.92), SIMDE_FLOAT32_C(  -370.92), SIMDE_FLOAT32_C(  -608.09),
        SIMDE_FLOAT32_C(   984.20), SIMDE_FLOAT32_C(   -32.59), SIMDE_FLOAT32_C(   785.58), SIMDE_FLOAT32_C(  -264.68) },
       INT32_C(          83),
      { SIMDE_FLOAT32_C(   947.84),      SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(    21.09), SIMDE_FLOAT32_C(  -974.81),
        SIMDE_FLOAT32_C(   839.06), SIMDE_FLOAT32_C(  -918.81), SIMDE_FLOAT32_C(  -858.09), SIMDE_FLOAT32_C(   165.72),
        SIMDE_FLOAT32_C(  -421.94), SIMDE_FLOAT32_C(  -602.91), SIMDE_FLOAT32_C(  -370.91), SIMDE_FLOAT32_C(  -608.06),
        SIMDE_FLOAT32_C(   984.19), SIMDE_FLOAT32_C(   -32.56), SIMDE_FLOAT32_C(   785.56), SIMDE_FLOAT32_C(  -264.66) } },
    { { SIMDE_FLOAT32_C(   830.82),      SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(   888.22), SIMDE_FLOAT32_C(   535.37),
        SIMDE_FLOAT32_C(    62.20), SIMDE_FLOAT32_C(  -724.50), SIMDE_FLOAT32_C(   254.09), SIMDE_FLOAT32_C(  -506.30),
        SIMDE_FLOAT32_C(  -626.62), SIMDE_FLOAT32_C(   731.46), SIMDE_FLOAT32_C(   990.91), SIMDE_FLOAT32_C(  -588.21),
        SIMDE_FLOAT32_C(   679.31), SIMDE_FLOAT32_C(  -316.74), SIMDE_FLOAT32_C(   432.91), SIMDE_FLOAT32_C(   704.48) },
       INT32_C(          99),
      { SIMDE_FLOAT32_C(   830.81),      SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(   888.22), SIMDE_FLOAT32_C(   535.36),
        SIMDE_FLOAT32_C(    62.19), SIMDE_FLOAT32_C(  -724.50), SIMDE_FLOAT32_C(   254.08), SIMDE_FLOAT32_C(  -506.30),
        SIMDE_FLOAT32_C(  -626.61), SIMDE_FLOAT32_C(   731.45), SIMDE_FLOAT32_C(   990.91), SIMDE_FLOAT32_C(  -588.20),
        SIMDE_FLOAT32_C(   679.30), SIMDE_FLOAT32_C(  -316.73), SIMDE_FLOAT32_C(   432.91), SIMDE_FLOAT32_C(   704.47) } },
    { { SIMDE_FLOAT32_C(   688.09),      SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(  -756.56), SIMDE_FLOAT32_C(  -682.83),
        SIMDE_FLOAT32_C(  -515.96), SIMDE_FLOAT32_C(  -772.36), SIMDE_FLOAT32_C(   284.58), SIMDE_FLOAT32_C(  -730.38),
        SIMDE_FLOAT32_C(   -37.03), SIMDE_FLOAT32_C(   983.52), SIMDE_FLOAT32_C(    54.72), SIMDE_FLOAT32_C(   890.81),
        SIMDE_FLOAT32_C(   814.34), SIMDE_FLOAT32_C(   111.66), SIMDE_FLOAT32_C(   779.03), SIMDE_FLOAT32_C(   349.71) },
       INT32_C(         115),
      { SIMDE_FLOAT32_C(   688.09),      SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(  -756.55), SIMDE_FLOAT32_C(  -682.83),
        SIMDE_FLOAT32_C(  -515.95), SIMDE_FLOAT32_C(  -772.36), SIMDE_FLOAT32_C(   284.58), SIMDE_FLOAT32_C(  -730.38),
        SIMDE_FLOAT32_C(   -37.02), SIMDE_FLOAT32_C(   983.52), SIMDE_FLOAT32_C(    54.72), SIMDE_FLOAT32_C(   890.80),
        SIMDE_FLOAT32_C(   814.34), SIMDE_FLOAT32_C(   111.66), SIMDE_FLOAT32_C(   779.02), SIMDE_FLOAT32_C(   349.70) } },
    { { SIMDE_FLOAT32_C(  -332.43), SIMDE_FLOAT32_C(  -572.08), SIMDE_FLOAT32_C(  -664.74), SIMDE_FLOAT32_C(  -341.53),
        SIMDE_FLOAT32_C(  -160.29), SIMDE_FLOAT32_C(  -985.43), SIMDE_FLOAT32_C(   341.73), SIMDE_FLOAT32_C(  -727.38),
        SIMDE_FLOAT32_C(   719.05), SIMDE_FLOAT32_C(   864.08), SIMDE_FLOAT32_C(   786.71), SIMDE_FLOAT32_C(   565.42),
        SIMDE_FLOAT32_C(   552.17), SIMDE_FLOAT32_C(   878.84), SIMDE_FLOAT32_C(   808.86), SIMDE_FLOAT32_C(   869.34) },
       INT32_C(         131),
      { SIMDE_FLOAT32_C(  -332.43), SIMDE_FLOAT32_C(  -572.08), SIMDE_FLOAT32_C(  -664.74), SIMDE_FLOAT32_C(  -341.53),
        SIMDE_FLOAT32_C(  -160.29), SIMDE_FLOAT32_C(  -985.43), SIMDE_FLOAT32_C(   341.73), SIMDE_FLOAT32_C(  -727.38),
        SIMDE_FLOAT32_C(   719.05), SIMDE_FLOAT32_C(   864.08), SIMDE_FLOAT32_C(   786.71), SIMDE_FLOAT32_C(   565.42),
        SIMDE_FLOAT32_C(   552.17), SIMDE_FLOAT32_C(   878.84), SIMDE_FLOAT32_C(   808.86), SIMDE_FLOAT32_C(   869.34) } },
    { { SIMDE_FLOAT32_C(  -963.49),     -SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(  -367.49), SIMDE_FLOAT32_C(    -0.53),
        SIMDE_FLOAT32_C(   137.44), SIMDE_FLOAT32_C(   687.22), SIMDE_FLOAT32_C(  -109.71), SIMDE_FLOAT32_C(   -48.23),
        SIMDE_FLOAT32_C(  -201.12), SIMDE_FLOAT32_C(  -330.68), SIMDE_FLOAT32_C(  -698.52), SIMDE_FLOAT32_C(   -27.25),
        SIMDE_FLOAT32_C(  -276.14), SIMDE_FLOAT32_C(   -94.71), SIMDE_FLOAT32_C(   640.31), SIMDE_FLOAT32_C(   151.78) },
       INT32_C(         147),
      { SIMDE_FLOAT32_C(  -963.49),     -SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(  -367.49), SIMDE_FLOAT32_C(    -0.53),
        SIMDE_FLOAT32_C(   137.44), SIMDE_FLOAT32_C(   687.22), SIMDE_FLOAT32_C(  -109.71), SIMDE_FLOAT32_C(   -48.23),
        SIMDE_FLOAT32_C(  -201.12), SIMDE_FLOAT32_C(  -330.68), SIMDE_FLOAT32_C(  -698.52), SIMDE_FLOAT32_C(   -27.25),
        SIMDE_FLOAT32_C(  -276.14), SIMDE_FLOAT32_C(   -94.71), SIMDE_FLOAT32_C(   640.31), SIMDE_FLOAT32_C(   151.78) } },
    { { SIMDE_FLOAT32_C(   255.12), SIMDE_FLOAT32_C(   640.51), SIMDE_FLOAT32_C(  -735.90), SIMDE_FLOAT32_C(   -25.83),
        SIMDE_FLOAT32_C(   504.60), SIMDE_FLOAT32_C(  -949.19), SIMDE_FLOAT32_C(  -460.41), SIMDE_FLOAT32_C(    56.77),
        SIMDE_FLOAT32_C(   929.65), SIMDE_FLOAT32_C(  -651.55), SIMDE_FLOAT32_C(   -73.88), SIMDE_FLOAT32_C(  -707.47),
        SIMDE_FLOAT32_C(  -615.04), SIMDE_FLOAT32_C(  -919.96), SIMDE_FLOAT32_C(   -74.97), SIMDE_FLOAT32_C(   384.43) },
       INT32_C(         163),
      { SIMDE_FLOAT32_C(   255.12), SIMDE_FLOAT32_C(   640.51), SIMDE_FLOAT32_C(  -735.90), SIMDE_FLOAT32_C(   -25.83),
        SIMDE_FLOAT32_C(   504.60), SIMDE_FLOAT32_C(  -949.19), SIMDE_FLOAT32_C(  -460.41), SIMDE_FLOAT32_C(    56.77),
        SIMDE_FLOAT32_C(   929.65), SIMDE_FLOAT32_C(  -651.55), SIMDE_FLOAT32_C(   -73.88), SIMDE_FLOAT32_C(  -707.47),
        SIMDE_FLOAT32_C(  -615.04), SIMDE_FLOAT32_C(  -919.96), SIMDE_FLOAT32_C(   -74.97), SIMDE_FLOAT32_C(   384.43) } },
    { { SIMDE_FLOAT32_C(  -387.75), SIMDE_FLOAT32_C(  -725.28), SIMDE_FLOAT32_C(  -830.75), SIMDE_FLOAT32_C(   411.14),
        SIMDE_FLOAT32_C(   -55.96), SIMDE_FLOAT32_C(  -529.27), SIMDE_FLOAT32_C(  -616.12), SIMDE_FLOAT32_C(   667.90),
        SIMDE_FLOAT32_C(   376.02), SIMDE_FLOAT32_C(  -975.81), SIMDE_FLOAT32_C(  -180.33), SIMDE_FLOAT32_C(  -383.43),
        SIMDE_FLOAT32_C(  -677.02), SIMDE_FLOAT32_C(  -188.84), SIMDE_FLOAT32_C(   871.69), SIMDE_FLOAT32_C(   963.49) },
       INT32_C(         179),
      { SIMDE_FLOAT32_C(  -387.75), SIMDE_FLOAT32_C(  -725.28), SIMDE_FLOAT32_C(  -830.75), SIMDE_FLOAT32_C(   411.14),
        SIMDE_FLOAT32_C(   -55.96), SIMDE_FLOAT32_C(  -529.27), SIMDE_FLOAT32_C(  -616.12), SIMDE_FLOAT32_C(   667.90),
        SIMDE_FLOAT32_C(   376.02), SIMDE_FLOAT32_C(  -975.81), SIMDE_FLOAT32_C(  -180.33), SIMDE_FLOAT32_C(  -383.43),
        SIMDE_FLOAT32_C(  -677.02), SIMDE_FLOAT32_C(  -188.84), SIMDE_FLOAT32_C(   871.69), SIMDE_FLOAT32_C(   963.49) } },
    { { SIMDE_FLOAT32_C(  -154.14), SIMDE_FLOAT32_C(   468.09), SIMDE_FLOAT32_C(   126.06), SIMDE_FLOAT32_C(   385.45),
        SIMDE_FLOAT32_C(  -475.14), SIMDE_FLOAT32_C(    55.71), SIMDE_FLOAT32_C(   733.90), SIMDE_FLOAT32_C(   450.97),
        SIMDE_FLOAT32_C(   348.24), SIMDE_FLOAT32_C(  -881.14), SIMDE_FLOAT32_C(   531.01), SIMDE_FLOAT32_C(  -726.72),
        SIMDE_FLOAT32_C(   503.29), SIMDE_FLOAT32_C(  -251.51), SIMDE_FLOAT32_C(  -114.47), SIMDE_FLOAT32_C(   778.01) },
       INT32_C(         195),
      { SIMDE_FLOAT32_C(  -154.14), SIMDE_FLOAT32_C(   468.09), SIMDE_FLOAT32_C(   126.06), SIMDE_FLOAT32_C(   385.45),
        SIMDE_FLOAT32_C(  -475.14), SIMDE_FLOAT32_C(    55.71), SIMDE_FLOAT32_C(   733.90), SIMDE_FLOAT32_C(   450.97),
        SIMDE_FLOAT32_C(   348.24), SIMDE_FLOAT32_C(  -881.14), SIMDE_FLOAT32_C(   531.01), SIMDE_FLOAT32_C(  -726.72),
        SIMDE_FLOAT32_C(   503.29), SIMDE_FLOAT32_C(  -251.51), SIMDE_FLOAT32_C(  -114.47), SIMDE_FLOAT32_C(   778.01) } },
    { { SIMDE_FLOAT32_C(  -703.33),      SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(   388.48), SIMDE_FLOAT32_C(  -319.45),
        SIMDE_FLOAT32_C(  -610.06), SIMDE_FLOAT32_C(  -235.50), SIMDE_FLOAT32_C(  -295.26), SIMDE_FLOAT32_C(   209.61),
        SIMDE_FLOAT32_C(   381.06), SIMDE_FLOAT32_C(    27.72), SIMDE_FLOAT32_C(  -979.23), SIMDE_FLOAT32_C(   252.75),
        SIMDE_FLOAT32_C(    -8.79), SIMDE_FLOAT32_C(    96.02), SIMDE_FLOAT32_C(  -901.38), SIMDE_FLOAT32_C(  -540.71) },
       INT32_C(         211),
      { SIMDE_FLOAT32_C(  -703.33),      SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(   388.48), SIMDE_FLOAT32_C(  -319.45),
        SIMDE_FLOAT32_C(  -610.06), SIMDE_FLOAT32_C(  -235.50), SIMDE_FLOAT32_C(  -295.26), SIMDE_FLOAT32_C(   209.61),
        SIMDE_FLOAT32_C(   381.06), SIMDE_FLOAT32_C(    27.72), SIMDE_FLOAT32_C(  -979.23), SIMDE_FLOAT32_C(   252.75),
        SIMDE_FLOAT32_C(    -8.79), SIMDE_FLOAT32_C(    96.02), SIMDE_FLOAT32_C(  -901.38), SIMDE_FLOAT32_C(  -540.71) } },
    { { SIMDE_FLOAT32_C(   277.80), SIMDE_FLOAT32_C(   217.97), SIMDE_FLOAT32_C(  -564.87), SIMDE_FLOAT32_C(  -373.96),
        SIMDE_FLOAT32_C(   336.83), SIMDE_FLOAT32_C(   966.14), SIMDE_FLOAT32_C(  -100.68), SIMDE_FLOAT32_C(  -159.88),
        SIMDE_FLOAT32_C(  -285.37), SIMDE_FLOAT32_C(   784.85), SIMDE_FLOAT32_C(  -381.87), SIMDE_FLOAT32_C(   632.37),
        SIMDE_FLOAT32_C(  -918.49), SIMDE_FLOAT32_C(   340.17), SIMDE_FLOAT32_C(    20.85), SIMDE_FLOAT32_C(  -237.94) },
       INT32_C(         227),
      { SIMDE_FLOAT32_C(   277.80), SIMDE_FLOAT32_C(   217.97), SIMDE_FLOAT32_C(  -564.87), SIMDE_FLOAT32_C(  -373.96),
        SIMDE_FLOAT32_C(   336.83), SIMDE_FLOAT32_C(   966.14), SIMDE_FLOAT32_C(  -100.68), SIMDE_FLOAT32_C(  -159.88),
        SIMDE_FLOAT32_C(  -285.37), SIMDE_FLOAT32_C(   784.85), SIMDE_FLOAT32_C(  -381.87), SIMDE_FLOAT32_C(   632.37),
        SIMDE_FLOAT32_C(  -918.49), SIMDE_FLOAT32_C(   340.17), SIMDE_FLOAT32_C(    20.85), SIMDE_FLOAT32_C(  -237.94) } },
    { {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(   466.81), SIMDE_FLOAT32_C(   -60.28), SIMDE_FLOAT32_C(   166.41),
        SIMDE_FLOAT32_C(  -505.47), SIMDE_FLOAT32_C(   -39.51), SIMDE_FLOAT32_C(  -580.84), SIMDE_FLOAT32_C(   485.73),
        SIMDE_FLOAT32_C(  -943.49), SIMDE_FLOAT32_C(  -482.22), SIMDE_FLOAT32_C(   945.03), SIMDE_FLOAT32_C(  -721.41),
        SIMDE_FLOAT32_C(  -998.15), SIMDE_FLOAT32_C(   -70.82), SIMDE_FLOAT32_C(   556.39), SIMDE_FLOAT32_C(   219.82) },
       INT32_C(         243),
      {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(   466.81), SIMDE_FLOAT32_C(   -60.28), SIMDE_FLOAT32_C(   166.41),
        SIMDE_FLOAT32_C(  -505.47), SIMDE_FLOAT32_C(   -39.51), SIMDE_FLOAT32_C(  -580.84), SIMDE_FLOAT32_C(   485.73),
        SIMDE_FLOAT32_C(  -943.49), SIMDE_FLOAT32_C(  -482.22), SIMDE_FLOAT32_C(   945.03), SIMDE_FLOAT32_C(  -721.41),
        SIMDE_FLOAT32_C(  -998.15), SIMDE_FLOAT32_C(   -70.82), SIMDE_FLOAT32_C(   556.39), SIMDE_FLOAT32_C(   219.82) } },
    { { SIMDE_FLOAT32_C(  -443.36),      SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(    81.75), SIMDE_FLOAT32_C(   396.76),
        SIMDE_FLOAT32_C(  -954.92), SIMDE_FLOAT32_C(  -133.40), SIMDE_FLOAT32_C(  -985.11), SIMDE_FLOAT32_C(   677.45),
        SIMDE_FLOAT32_C(   -51.89), SIMDE_FLOAT32_C(   355.06), SIMDE_FLOAT32_C(  -301.70), SIMDE_FLOAT32_C(   710.17),
        SIMDE_FLOAT32_C(    85.17), SIMDE_FLOAT32_C(  -516.36), SIMDE_FLOAT32_C(   176.98), SIMDE_FLOAT32_C(  -975.12) },
       INT32_C(           4),
      { SIMDE_FLOAT32_C(  -443.00),      SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(    82.00), SIMDE_FLOAT32_C(   397.00),
        SIMDE_FLOAT32_C(  -955.00), SIMDE_FLOAT32_C(  -133.00), SIMDE_FLOAT32_C(  -985.00), SIMDE_FLOAT32_C(   677.00),
        SIMDE_FLOAT32_C(   -52.00), SIMDE_FLOAT32_C(   355.00), SIMDE_FLOAT32_C(  -302.00), SIMDE_FLOAT32_C(   710.00),
        SIMDE_FLOAT32_C(    85.00), SIMDE_FLOAT32_C(  -516.00), SIMDE_FLOAT32_C(   177.00), SIMDE_FLOAT32_C(  -975.00) } },
    { { SIMDE_FLOAT32_C(  -930.79), SIMDE_FLOAT32_C(   157.24), SIMDE_FLOAT32_C(    41.88), SIMDE_FLOAT32_C(  -413.01),
        SIMDE_FLOAT32_C(   102.27), SIMDE_FLOAT32_C(   320.47), SIMDE_FLOAT32_C(  -411.16), SIMDE_FLOAT32_C(  -968.55),
        SIMDE_FLOAT32_C(  -123.14), SIMDE_FLOAT32_C(   808.65), SIMDE_FLOAT32_C(   395.76), SIMDE_FLOAT32_C(    59.29),
        SIMDE_FLOAT32_C(  -634.70), SIMDE_FLOAT32_C(  -273.79), SIMDE_FLOAT32_C(  -858.96), SIMDE_FLOAT32_C(   762.06) },
       INT32_C(          20),
      { SIMDE_FLOAT32_C(  -931.00), SIMDE_FLOAT32_C(   157.00), SIMDE_FLOAT32_C(    42.00), SIMDE_FLOAT32_C(  -413.00),
        SIMDE_FLOAT32_C(   102.50), SIMDE_FLOAT32_C(   320.50), SIMDE_FLOAT32_C(  -411.00), SIMDE_FLOAT32_C(  -968.50),
        SIMDE_FLOAT32_C(  -123.00), SIMDE_FLOAT32_C(   808.50), SIMDE_FLOAT32_C(   396.00), SIMDE_FLOAT32_C(    59.50),
        SIMDE_FLOAT32_C(  -634.50), SIMDE_FLOAT32_C(  -274.00), SIMDE_FLOAT32_C(  -859.00), SIMDE_FLOAT32_C(   762.00) } },
    { { SIMDE_FLOAT32_C(     7.64), SIMDE_FLOAT32_C(   776.95), SIMDE_FLOAT32_C(  -551.26), SIMDE_FLOAT32_C(   955.75),
        SIMDE_FLOAT32_C(   132.00), SIMDE_FLOAT32_C(   147.04), SIMDE_FLOAT32_C(   665.92), SIMDE_FLOAT32_C(  -782.83),
        SIMDE_FLOAT32_C(   630.68), SIMDE_FLOAT32_C(  -157.09), SIMDE_FLOAT32_C(  -757.95), SIMDE_FLOAT32_C(   280.74),
        SIMDE_FLOAT32_C(  -485.59), SIMDE_FLOAT32_C(   227.42), SIMDE_FLOAT32_C(   349.95), SIMDE_FLOAT32_C(   671.66) },
       INT32_C(          36),
      { SIMDE_FLOAT32_C(     7.75), SIMDE_FLOAT32_C(   777.00), SIMDE_FLOAT32_C(  -551.25), SIMDE_FLOAT32_C(   955.75),
        SIMDE_FLOAT32_C(   132.00), SIMDE_FLOAT32_C(   147.00), SIMDE_FLOAT32_C(   666.00), SIMDE_FLOAT32_C(  -782.75),
        SIMDE_FLOAT32_C(   630.75), SIMDE_FLOAT32_C(  -157.00), SIMDE_FLOAT32_C(  -758.00), SIMDE_FLOAT32_C(   280.75),
        SIMDE_FLOAT32_C(  -485.50), SIMDE_FLOAT32_C(   227.50), SIMDE_FLOAT32_C(   350.00), SIMDE_FLOAT32_C(   671.75) } },
    { { SIMDE_FLOAT32_C(   936.94), SIMDE_FLOAT32_C(  -226.08), SIMDE_FLOAT32_C(   589.77), SIMDE_FLOAT32_C(  -474.23),
        SIMDE_FLOAT32_C(  -194.62), SIMDE_FLOAT32_C(  -533.37), SIMDE_FLOAT32_C(  -665.57), SIMDE_FLOAT32_C(  -798.86),
        SIMDE_FLOAT32_C(   525.93), SIMDE_FLOAT32_C(  -300.28), SIMDE_FLOAT32_C(   -72.65), SIMDE_FLOAT32_C(   666.97),
        SIMDE_FLOAT32_C(  -538.22), SIMDE_FLOAT32_C(   698.63), SIMDE_FLOAT32_C(  -325.39), SIMDE_FLOAT32_C(  -761.27) },
       INT32_C(          52),
      { SIMDE_FLOAT32_C(   937.00), SIMDE_FLOAT32_C(  -226.12), SIMDE_FLOAT32_C(   589.75), SIMDE_FLOAT32_C(  -474.25),
        SIMDE_FLOAT32_C(  -194.62), SIMDE_FLOAT32_C(  -533.38), SIMDE_FLOAT32_C(  -665.62), SIMDE_FLOAT32_C(  -798.88),
        SIMDE_FLOAT32_C(   525.88), SIMDE_FLOAT32_C(  -300.25), SIMDE_FLOAT32_C(   -72.62), SIMDE_FLOAT32_C(   667.00),
        SIMDE_FLOAT32_C(  -538.25), SIMDE_FLOAT32_C(   698.62), SIMDE_FLOAT32_C(  -325.38), SIMDE_FLOAT32_C(  -761.25) } },
    { { SIMDE_FLOAT32_C(  -369.64), SIMDE_FLOAT32_C(   370.73), SIMDE_FLOAT32_C(   294.42), SIMDE_FLOAT32_C(  -703.72),
        SIMDE_FLOAT32_C(   587.90), SIMDE_FLOAT32_C(   -74.90), SIMDE_FLOAT32_C(   139.19), SIMDE_FLOAT32_C(   829.95),
        SIMDE_FLOAT32_C(  -794.16), SIMDE_FLOAT32_C(   653.60), SIMDE_FLOAT32_C(    57.38), SIMDE_FLOAT32_C(   555.79),
        SIMDE_FLOAT32_C(   325.26), SIMDE_FLOAT32_C(   326.68), SIMDE_FLOAT32_C(   492.72), SIMDE_FLOAT32_C(  -900.82) },
       INT32_C(          68),
      { SIMDE_FLOAT32_C(  -369.62), SIMDE_FLOAT32_C(   370.75), SIMDE_FLOAT32_C(   294.44), SIMDE_FLOAT32_C(  -703.75),
        SIMDE_FLOAT32_C(   587.88), SIMDE_FLOAT32_C(   -74.88), SIMDE_FLOAT32_C(   139.19), SIMDE_FLOAT32_C(   829.94),
        SIMDE_FLOAT32_C(  -794.19), SIMDE_FLOAT32_C(   653.62), SIMDE_FLOAT32_C(    57.38), SIMDE_FLOAT32_C(   555.81),
        SIMDE_FLOAT32_C(   325.25), SIMDE_FLOAT32_C(   326.69), SIMDE_FLOAT32_C(   492.75), SIMDE_FLOAT32_C(  -900.81) } },
    { { SIMDE_FLOAT32_C(  -981.50), SIMDE_FLOAT32_C(   -95.44), SIMDE_FLOAT32_C(   383.09), SIMDE_FLOAT32_C(  -647.07),
        SIMDE_FLOAT32_C(   105.69), SIMDE_FLOAT32_C(   -90.98), SIMDE_FLOAT32_C(    52.65), SIMDE_FLOAT32_C(  -966.96),
        SIMDE_FLOAT32_C(  -424.01), SIMDE_FLOAT32_C(   514.43), SIMDE_FLOAT32_C(   731.68), SIMDE_FLOAT32_C(   250.60),
        SIMDE_FLOAT32_C(   753.15), SIMDE_FLOAT32_C(   879.05), SIMDE_FLOAT32_C(   880.96), SIMDE_FLOAT32_C(   123.88) },
       INT32_C(          84),
      { SIMDE_FLOAT32_C(  -981.50), SIMDE_FLOAT32_C(   -95.44), SIMDE_FLOAT32_C(   383.09), SIMDE_FLOAT32_C(  -647.06),
        SIMDE_FLOAT32_C(   105.69), SIMDE_FLOAT32_C(   -90.97), SIMDE_FLOAT32_C(    52.66), SIMDE_FLOAT32_C(  -966.97),
        SIMDE_FLOAT32_C(  -424.00), SIMDE_FLOAT32_C(   514.44), SIMDE_FLOAT32_C(   731.69), SIMDE_FLOAT32_C(   250.59),
        SIMDE_FLOAT32_C(   753.16), SIMDE_FLOAT32_C(   879.06), SIMDE_FLOAT32_C(   880.97), SIMDE_FLOAT32_C(   123.88) } },
    { {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(  -288.22), SIMDE_FLOAT32_C(  -901.43), SIMDE_FLOAT32_C(   316.43),
        SIMDE_FLOAT32_C(  -458.27), SIMDE_FLOAT32_C(  -695.59), SIMDE_FLOAT32_C(   -29.97), SIMDE_FLOAT32_C(   599.11),
        SIMDE_FLOAT32_C(   860.20), SIMDE_FLOAT32_C(  -704.71), SIMDE_FLOAT32_C(   -74.21), SIMDE_FLOAT32_C(   352.92),
        SIMDE_FLOAT32_C(  -605.53), SIMDE_FLOAT32_C(   842.24), SIMDE_FLOAT32_C(   371.42), SIMDE_FLOAT32_C(   299.03) },
       INT32_C(         100),
      {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(  -288.22), SIMDE_FLOAT32_C(  -901.44), SIMDE_FLOAT32_C(   316.44),
        SIMDE_FLOAT32_C(  -458.27), SIMDE_FLOAT32_C(  -695.59), SIMDE_FLOAT32_C(   -29.97), SIMDE_FLOAT32_C(   599.11),
        SIMDE_FLOAT32_C(   860.20), SIMDE_FLOAT32_C(  -704.70), SIMDE_FLOAT32_C(   -74.20), SIMDE_FLOAT32_C(   352.92),
        SIMDE_FLOAT32_C(  -605.53), SIMDE_FLOAT32_C(   842.23), SIMDE_FLOAT32_C(   371.42), SIMDE_FLOAT32_C(   299.03) } },
    { {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(  -865.66), SIMDE_FLOAT32_C(  -223.00), SIMDE_FLOAT32_C(  -562.24),
        SIMDE_FLOAT32_C(  -289.67), SIMDE_FLOAT32_C(  -708.58), SIMDE_FLOAT32_C(  -830.56), SIMDE_FLOAT32_C(   960.93),
        SIMDE_FLOAT32_C(  -955.42), SIMDE_FLOAT32_C(  -951.51), SIMDE_FLOAT32_C(   841.88), SIMDE_FLOAT32_C(   168.46),
        SIMDE_FLOAT32_C(   221.96), SIMDE_FLOAT32_C(  -980.88), SIMDE_FLOAT32_C(   880.24), SIMDE_FLOAT32_C(   320.54) },
       INT32_C(         116),
      {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(  -865.66), SIMDE_FLOAT32_C(  -223.00), SIMDE_FLOAT32_C(  -562.24),
        SIMDE_FLOAT32_C(  -289.67), SIMDE_FLOAT32_C(  -708.58), SIMDE_FLOAT32_C(  -830.56), SIMDE_FLOAT32_C(   960.93),
        SIMDE_FLOAT32_C(  -955.42), SIMDE_FLOAT32_C(  -951.51), SIMDE_FLOAT32_C(   841.88), SIMDE_FLOAT32_C(   168.46),
        SIMDE_FLOAT32_C(   221.96), SIMDE_FLOAT32_C(  -980.88), SIMDE_FLOAT32_C(   880.24), SIMDE_FLOAT32_C(   320.54) } },
    { {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(  -694.42), SIMDE_FLOAT32_C(  -978.91), SIMDE_FLOAT32_C(   485.15),
        SIMDE_FLOAT32_C(  -399.13), SIMDE_FLOAT32_C(   -53.12), SIMDE_FLOAT32_C(  -161.93), SIMDE_FLOAT32_C(    -4.66),
        SIMDE_FLOAT32_C(  -210.88), SIMDE_FLOAT32_C(  -790.51), SIMDE_FLOAT32_C(  -705.63), SIMDE_FLOAT32_C(  -985.55),
        SIMDE_FLOAT32_C(   933.84), SIMDE_FLOAT32_C(  -300.91), SIMDE_FLOAT32_C(  -851.20), SIMDE_FLOAT32_C(  -289.16) },
       INT32_C(         132),
      {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(  -694.42), SIMDE_FLOAT32_C(  -978.91), SIMDE_FLOAT32_C(   485.15),
        SIMDE_FLOAT32_C(  -399.13), SIMDE_FLOAT32_C(   -53.12), SIMDE_FLOAT32_C(  -161.93), SIMDE_FLOAT32_C(    -4.66),
        SIMDE_FLOAT32_C(  -210.88), SIMDE_FLOAT32_C(  -790.51), SIMDE_FLOAT32_C(  -705.63), SIMDE_FLOAT32_C(  -985.55),
        SIMDE_FLOAT32_C(   933.84), SIMDE_FLOAT32_C(  -300.91), SIMDE_FLOAT32_C(  -851.20), SIMDE_FLOAT32_C(  -289.16) } },
    { { SIMDE_FLOAT32_C(     2.27), SIMDE_FLOAT32_C(   306.30), SIMDE_FLOAT32_C(  -179.94), SIMDE_FLOAT32_C(    46.84),
        SIMDE_FLOAT32_C(   354.79), SIMDE_FLOAT32_C(  -338.06), SIMDE_FLOAT32_C(  -784.70), SIMDE_FLOAT32_C(  -423.25),
        SIMDE_FLOAT32_C(  -318.93), SIMDE_FLOAT32_C(  -904.45), SIMDE_FLOAT32_C(   897.29), SIMDE_FLOAT32_C(  -983.38),
        SIMDE_FLOAT32_C(  -482.48), SIMDE_FLOAT32_C(   522.24), SIMDE_FLOAT32_C(  -677.80), SIMDE_FLOAT32_C(  -461.39) },
       INT32_C(         148),
      { SIMDE_FLOAT32_C(     2.27), SIMDE_FLOAT32_C(   306.30), SIMDE_FLOAT32_C(  -179.94), SIMDE_FLOAT32_C(    46.84),
        SIMDE_FLOAT32_C(   354.79), SIMDE_FLOAT32_C(  -338.06), SIMDE_FLOAT32_C(  -784.70), SIMDE_FLOAT32_C(  -423.25),
        SIMDE_FLOAT32_C(  -318.93), SIMDE_FLOAT32_C(  -904.45), SIMDE_FLOAT32_C(   897.29), SIMDE_FLOAT32_C(  -983.38),
        SIMDE_FLOAT32_C(  -482.48), SIMDE_FLOAT32_C(   522.24), SIMDE_FLOAT32_C(  -677.80), SIMDE_FLOAT32_C(  -461.39) } },
    { { SIMDE_FLOAT32_C(   -76.93),      SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(   845.45), SIMDE_FLOAT32_C(   918.41),
        SIMDE_FLOAT32_C(  -725.38), SIMDE_FLOAT32_C(  -945.05), SIMDE_FLOAT32_C(  -787.22), SIMDE_FLOAT32_C(  -710.93),
        SIMDE_FLOAT32_C(   988.79), SIMDE_FLOAT32_C(   -88.13), SIMDE_FLOAT32_C(  -562.13), SIMDE_FLOAT32_C(  -300.37),
        SIMDE_FLOAT32_C(  -951.27), SIMDE_FLOAT32_C(   297.00), SIMDE_FLOAT32_C(   701.89), SIMDE_FLOAT32_C(   355.03) },
       INT32_C(         164),
      { SIMDE_FLOAT32_C(   -76.93),      SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(   845.45), SIMDE_FLOAT32_C(   918.41),
        SIMDE_FLOAT32_C(  -725.38), SIMDE_FLOAT32_C(  -945.05), SIMDE_FLOAT32_C(  -787.22), SIMDE_FLOAT32_C(  -710.93),
        SIMDE_FLOAT32_C(   988.79), SIMDE_FLOAT32_C(   -88.13), SIMDE_FLOAT32_C(  -562.13), SIMDE_FLOAT32_C(  -300.37),
        SIMDE_FLOAT32_C(  -951.27), SIMDE_FLOAT32_C(   297.00), SIMDE_FLOAT32_C(   701.89), SIMDE_FLOAT32_C(   355.03) } },
    { { SIMDE_FLOAT32_C(  -221.00),     -SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(   286.57), SIMDE_FLOAT32_C(   460.07),
        SIMDE_FLOAT32_C(    59.59), SIMDE_FLOAT32_C(   183.86), SIMDE_FLOAT32_C(   476.68), SIMDE_FLOAT32_C(   577.11),
        SIMDE_FLOAT32_C(  -293.90), SIMDE_FLOAT32_C(   798.88), SIMDE_FLOAT32_C(  -884.27), SIMDE_FLOAT32_C(   713.48),
        SIMDE_FLOAT32_C(  -278.04), SIMDE_FLOAT32_C(   601.22), SIMDE_FLOAT32_C(   558.93), SIMDE_FLOAT32_C(  -359.63) },
       INT32_C(         180),
      { SIMDE_FLOAT32_C(  -221.00),     -SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(   286.57), SIMDE_FLOAT32_C(   460.07),
        SIMDE_FLOAT32_C(    59.59), SIMDE_FLOAT32_C(   183.86), SIMDE_FLOAT32_C(   476.68), SIMDE_FLOAT32_C(   577.11),
        SIMDE_FLOAT32_C(  -293.90), SIMDE_FLOAT32_C(   798.88), SIMDE_FLOAT32_C(  -884.27), SIMDE_FLOAT32_C(   713.48),
        SIMDE_FLOAT32_C(  -278.04), SIMDE_FLOAT32_C(   601.22), SIMDE_FLOAT32_C(   558.93), SIMDE_FLOAT32_C(  -359.63) } },
    { { SIMDE_FLOAT32_C(  -835.10), SIMDE_FLOAT32_C(   602.67), SIMDE_FLOAT32_C(   765.02), SIMDE_FLOAT32_C(  -397.23),
        SIMDE_FLOAT32_C(  -697.70), SIMDE_FLOAT32_C(   813.75), SIMDE_FLOAT32_C(   899.77), SIMDE_FLOAT32_C(  -995.81),
        SIMDE_FLOAT32_C(   168.78), SIMDE_FLOAT32_C(  -983.18), SIMDE_FLOAT32_C(  -247.07), SIMDE_FLOAT32_C(   878.60),
        SIMDE_FLOAT32_C(  -204.18), SIMDE_FLOAT32_C(   716.97), SIMDE_FLOAT32_C(   165.17), SIMDE_FLOAT32_C(  -744.11) },
       INT32_C(         196),
      { SIMDE_FLOAT32_C(  -835.10), SIMDE_FLOAT32_C(   602.67), SIMDE_FLOAT32_C(   765.02), SIMDE_FLOAT32_C(  -397.23),
        SIMDE_FLOAT32_C(  -697.70), SIMDE_FLOAT32_C(   813.75), SIMDE_FLOAT32_C(   899.77), SIMDE_FLOAT32_C(  -995.81),
        SIMDE_FLOAT32_C(   168.78), SIMDE_FLOAT32_C(  -983.18), SIMDE_FLOAT32_C(  -247.07), SIMDE_FLOAT32_C(   878.60),
        SIMDE_FLOAT32_C(  -204.18), SIMDE_FLOAT32_C(   716.97), SIMDE_FLOAT32_C(   165.17), SIMDE_FLOAT32_C(  -744.11) } },
    { { SIMDE_FLOAT32_C(  -650.97), SIMDE_FLOAT32_C(   732.57), SIMDE_FLOAT32_C(  -646.33), SIMDE_FLOAT32_C(    55.13),
        SIMDE_FLOAT32_C(   531.45), SIMDE_FLOAT32_C(  -530.61), SIMDE_FLOAT32_C(  -231.39), SIMDE_FLOAT32_C(  -746.59),
        SIMDE_FLOAT32_C(  -929.39), SIMDE_FLOAT32_C(  -672.46), SIMDE_FLOAT32_C(  -106.23), SIMDE_FLOAT32_C(   946.45),
        SIMDE_FLOAT32_C(   941.42), SIMDE_FLOAT32_C(   746.92), SIMDE_FLOAT32_C(  -888.65), SIMDE_FLOAT32_C(   544.09) },
       INT32_C(         212),
      { SIMDE_FLOAT32_C(  -650.97), SIMDE_FLOAT32_C(   732.57), SIMDE_FLOAT32_C(  -646.33), SIMDE_FLOAT32_C(    55.13),
        SIMDE_FLOAT32_C(   531.45), SIMDE_FLOAT32_C(  -530.61), SIMDE_FLOAT32_C(  -231.39), SIMDE_FLOAT32_C(  -746.59),
        SIMDE_FLOAT32_C(  -929.39), SIMDE_FLOAT32_C(  -672.46), SIMDE_FLOAT32_C(  -106.23), SIMDE_FLOAT32_C(   946.45),
        SIMDE_FLOAT32_C(   941.42), SIMDE_FLOAT32_C(   746.92), SIMDE_FLOAT32_C(  -888.65), SIMDE_FLOAT32_C(   544.09) } },
    { { SIMDE_FLOAT32_C(  -285.88),     -SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(   325.68), SIMDE_FLOAT32_C(  -386.11),
        SIMDE_FLOAT32_C(   850.57), SIMDE_FLOAT32_C(  -505.54), SIMDE_FLOAT32_C(  -369.29), SIMDE_FLOAT32_C(  -396.50),
        SIMDE_FLOAT32_C(  -626.94), SIMDE_FLOAT32_C(   426.53), SIMDE_FLOAT32_C(  -679.53), SIMDE_FLOAT32_C(   538.23),
        SIMDE_FLOAT32_C(   682.42), SIMDE_FLOAT32_C(    97.02), SIMDE_FLOAT32_C(   887.26), SIMDE_FLOAT32_C(   414.99) },
       INT32_C(         228),
      { SIMDE_FLOAT32_C(  -285.88),     -SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(   325.68), SIMDE_FLOAT32_C(  -386.11),
        SIMDE_FLOAT32_C(   850.57), SIMDE_FLOAT32_C(  -505.54), SIMDE_FLOAT32_C(  -369.29), SIMDE_FLOAT32_C(  -396.50),
        SIMDE_FLOAT32_C(  -626.94), SIMDE_FLOAT32_C(   426.53), SIMDE_FLOAT32_C(  -679.53), SIMDE_FLOAT32_C(   538.23),
        SIMDE_FLOAT32_C(   682.42), SIMDE_FLOAT32_C(    97.02), SIMDE_FLOAT32_C(   887.26), SIMDE_FLOAT32_C(   414.99) } },
    { { SIMDE_FLOAT32_C(   920.08), SIMDE_FLOAT32_C(   711.00), SIMDE_FLOAT32_C(   199.85), SIMDE_FLOAT32_C(   990.70),
        SIMDE_FLOAT32_C(  -961.46), SIMDE_FLOAT32_C(  -906.37), SIMDE_FLOAT32_C(   937.15), SIMDE_FLOAT32_C(   979.97),
        SIMDE_FLOAT32_C(   840.55), SIMDE_FLOAT32_C(  -951.50), SIMDE_FLOAT32_C(   524.06), SIMDE_FLOAT32_C(   352.48),
        SIMDE_FLOAT32_C(  -237.38), SIMDE_FLOAT32_C(   370.44), SIMDE_FLOAT32_C(  -321.83), SIMDE_FLOAT32_C(   376.51) },
       INT32_C(         244),
      { SIMDE_FLOAT32_C(   920.08), SIMDE_FLOAT32_C(   711.00), SIMDE_FLOAT32_C(   199.85), SIMDE_FLOAT32_C(   990.70),
        SIMDE_FLOAT32_C(  -961.46), SIMDE_FLOAT32_C(  -906.37), SIMDE_FLOAT32_C(   937.15), SIMDE_FLOAT32_C(   979.97),
        SIMDE_FLOAT32_C(   840.55), SIMDE_FLOAT32_C(  -951.50), SIMDE_FLOAT32_C(   524.06), SIMDE_FLOAT32_C(   352.48),
        SIMDE_FLOAT32_C(  -237.38), SIMDE_FLOAT32_C(   370.44), SIMDE_FLOAT32_C(  -321.83), SIMDE_FLOAT32_C(   376.51) } },
  };

  simde__m512 a, r;

  a = simde_mm512_loadu_ps(test_vec[0].a);
  r = simde_mm512_roundscale_ps(a, INT32_C(           0));
  simde_test_x86_assert_equal_f32x16(r, simde_mm512_loadu_ps(test_vec[0].r), 1);

  a = simde_mm512_loadu_ps(test_vec[1].a);
  r = simde_mm512_roundscale_ps(a, INT32_C(          16));
  simde_test_x86_assert_equal_f32x16(r, simde_mm512_loadu_ps(test_vec[1].r), 1);

  a = simde_mm512_loadu_ps(test_vec[2].a);
  r = simde_mm512_roundscale_ps(a, INT32_C(          32));
  simde_test_x86_assert_equal_f32x16(r, simde_mm512_loadu_ps(test_vec[2].r), 1);

  a = simde_mm512_loadu_ps(test_vec[3].a);
  r = simde_mm512_roundscale_ps(a, INT32_C(          48));
  simde_test_x86_assert_equal_f32x16(r, simde_mm512_loadu_ps(test_vec[3].r), 1);

  a = simde_mm512_loadu_ps(test_vec[4].a);
  r = simde_mm512_roundscale_ps(a, INT32_C(          64));
  simde_test_x86_assert_equal_f32x16(r, simde_mm512_loadu_ps(test_vec[4].r), 1);

  a = simde_mm512_loadu_ps(test_vec[5].a);
  r = simde_mm512_roundscale_ps(a, INT32_C(          80));
  simde_test_x86_assert_equal_f32x16(r, simde_mm512_loadu_ps(test_vec[5].r), 1);

  a = simde_mm512_loadu_ps(test_vec[6].a);
  r = simde_mm512_roundscale_ps(a, INT32_C(          96));
  simde_test_x86_assert_equal_f32x16(r, simde_mm512_loadu_ps(test_vec[6].r), 1);

  a = simde_mm512_loadu_ps(test_vec[7].a);
  r = simde_mm512_roundscale_ps(a, INT32_C(         112));
  simde_test_x86_assert_equal_f32x16(r, simde_mm512_loadu_ps(test_vec[7].r), 1);

  a = simde_mm512_loadu_ps(test_vec[8].a);
  r = simde_mm512_roundscale_ps(a, INT32_C(         128));
  simde_test_x86_assert_equal_f32x16(r, simde_mm512_loadu_ps(test_vec[8].r), 1);

  a = simde_mm512_loadu_ps(test_vec[9].a);
  r = simde_mm512_roundscale_ps(a, INT32_C(         144));
  simde_test_x86_assert_equal_f32x16(r, simde_mm512_loadu_ps(test_vec[9].r), 1);

  a = simde_mm512_loadu_ps(test_vec[10].a);
  r = simde_mm512_roundscale_ps(a, INT32_C(         160));
  simde_test_x86_assert_equal_f32x16(r, simde_mm512_loadu_ps(test_vec[10].r), 1);

  a = simde_mm512_loadu_ps(test_vec[11].a);
  r = simde_mm512_roundscale_ps(a, INT32_C(         176));
  simde_test_x86_assert_equal_f32x16(r, simde_mm512_loadu_ps(test_vec[11].r), 1);

  a = simde_mm512_loadu_ps(test_vec[12].a);
  r = simde_mm512_roundscale_ps(a, INT32_C(         192));
  simde_test_x86_assert_equal_f32x16(r, simde_mm512_loadu_ps(test_vec[12].r), 1);

  a = simde_mm512_loadu_ps(test_vec[13].a);
  r = simde_mm512_roundscale_ps(a, INT32_C(         208));
  simde_test_x86_assert_equal_f32x16(r, simde_mm512_loadu_ps(test_vec[13].r), 1);

  a = simde_mm512_loadu_ps(test_vec[14].a);
  r = simde_mm512_roundscale_ps(a, INT32_C(         224));
  simde_test_x86_assert_equal_f32x16(r, simde_mm512_loadu_ps(test_vec[14].r), 1);

  a = simde_mm512_loadu_ps(test_vec[15].a);
  r = simde_mm512_roundscale_ps(a, INT32_C(         240));
  simde_test_x86_assert_equal_f32x16(r, simde_mm512_loadu_ps(test_vec[15].r), 1);

  a = simde_mm512_loadu_ps(test_vec[16].a);
  r = simde_mm512_roundscale_ps(a, INT32_C(           1));
  simde_test_x86_assert_equal_f32x16(r, simde_mm512_loadu_ps(test_vec[16].r), 1);

  a = simde_mm512_loadu_ps(test_vec[17].a);
  r = simde_mm512_roundscale_ps(a, INT32_C(          17));
  simde_test_x86_assert_equal_f32x16(r, simde_mm512_loadu_ps(test_vec[17].r), 1);

  a = simde_mm512_loadu_ps(test_vec[18].a);
  r = simde_mm512_roundscale_ps(a, INT32_C(          33));
  simde_test_x86_assert_equal_f32x16(r, simde_mm512_loadu_ps(test_vec[18].r), 1);

  a = simde_mm512_loadu_ps(test_vec[19].a);
  r = simde_mm512_roundscale_ps(a, INT32_C(          49));
  simde_test_x86_assert_equal_f32x16(r, simde_mm512_loadu_ps(test_vec[19].r), 1);

  a = simde_mm512_loadu_ps(test_vec[20].a);
  r = simde_mm512_roundscale_ps(a, INT32_C(          65));
  simde_test_x86_assert_equal_f32x16(r, simde_mm512_loadu_ps(test_vec[20].r), 1);

  a = simde_mm512_loadu_ps(test_vec[21].a);
  r = simde_mm512_roundscale_ps(a, INT32_C(          81));
  simde_test_x86_assert_equal_f32x16(r, simde_mm512_loadu_ps(test_vec[21].r), 1);

  a = simde_mm512_loadu_ps(test_vec[22].a);
  r = simde_mm512_roundscale_ps(a, INT32_C(          97));
  simde_test_x86_assert_equal_f32x16(r, simde_mm512_loadu_ps(test_vec[22].r), 1);

  a = simde_mm512_loadu_ps(test_vec[23].a);
  r = simde_mm512_roundscale_ps(a, INT32_C(         113));
  simde_test_x86_assert_equal_f32x16(r, simde_mm512_loadu_ps(test_vec[23].r), 1);

  a = simde_mm512_loadu_ps(test_vec[24].a);
  r = simde_mm512_roundscale_ps(a, INT32_C(         129));
  simde_test_x86_assert_equal_f32x16(r, simde_mm512_loadu_ps(test_vec[24].r), 1);

  a = simde_mm512_loadu_ps(test_vec[25].a);
  r = simde_mm512_roundscale_ps(a, INT32_C(         145));
  simde_test_x86_assert_equal_f32x16(r, simde_mm512_loadu_ps(test_vec[25].r), 1);

  a = simde_mm512_loadu_ps(test_vec[26].a);
  r = simde_mm512_roundscale_ps(a, INT32_C(         161));
  simde_test_x86_assert_equal_f32x16(r, simde_mm512_loadu_ps(test_vec[26].r), 1);

  a = simde_mm512_loadu_ps(test_vec[27].a);
  r = simde_mm512_roundscale_ps(a, INT32_C(         177));
  simde_test_x86_assert_equal_f32x16(r, simde_mm512_loadu_ps(test_vec[27].r), 1);

  a = simde_mm512_loadu_ps(test_vec[28].a);
  r = simde_mm512_roundscale_ps(a, INT32_C(         193));
  simde_test_x86_assert_equal_f32x16(r, simde_mm512_loadu_ps(test_vec[28].r), 1);

  a = simde_mm512_loadu_ps(test_vec[29].a);
  r = simde_mm512_roundscale_ps(a, INT32_C(         209));
  simde_test_x86_assert_equal_f32x16(r, simde_mm512_loadu_ps(test_vec[29].r), 1);

  a = simde_mm512_loadu_ps(test_vec[30].a);
  r = simde_mm512_roundscale_ps(a, INT32_C(         225));
  simde_test_x86_assert_equal_f32x16(r, simde_mm512_loadu_ps(test_vec[30].r), 1);

  a = simde_mm512_loadu_ps(test_vec[31].a);
  r = simde_mm512_roundscale_ps(a, INT32_C(         241));
  simde_test_x86_assert_equal_f32x16(r, simde_mm512_loadu_ps(test_vec[31].r), 1);

  a = simde_mm512_loadu_ps(test_vec[32].a);
  r = simde_mm512_roundscale_ps(a, INT32_C(           2));
  simde_test_x86_assert_equal_f32x16(r, simde_mm512_loadu_ps(test_vec[32].r), 1);

  a = simde_mm512_loadu_ps(test_vec[33].a);
  r = simde_mm512_roundscale_ps(a, INT32_C(          18));
  simde_test_x86_assert_equal_f32x16(r, simde_mm512_loadu_ps(test_vec[33].r), 1);

  a = simde_mm512_loadu_ps(test_vec[34].a);
  r = simde_mm512_roundscale_ps(a, INT32_C(          34));
  simde_test_x86_assert_equal_f32x16(r, simde_mm512_loadu_ps(test_vec[34].r), 1);

  a = simde_mm512_loadu_ps(test_vec[35].a);
  r = simde_mm512_roundscale_ps(a, INT32_C(          50));
  simde_test_x86_assert_equal_f32x16(r, simde_mm512_loadu_ps(test_vec[35].r), 1);

  a = simde_mm512_loadu_ps(test_vec[36].a);
  r = simde_mm512_roundscale_ps(a, INT32_C(          66));
  simde_test_x86_assert_equal_f32x16(r, simde_mm512_loadu_ps(test_vec[36].r), 1);

  a = simde_mm512_loadu_ps(test_vec[37].a);
  r = simde_mm512_roundscale_ps(a, INT32_C(          82));
  simde_test_x86_assert_equal_f32x16(r, simde_mm512_loadu_ps(test_vec[37].r), 1);

  a = simde_mm512_loadu_ps(test_vec[38].a);
  r = simde_mm512_roundscale_ps(a, INT32_C(          98));
  simde_test_x86_assert_equal_f32x16(r, simde_mm512_loadu_ps(test_vec[38].r), 1);

  a = simde_mm512_loadu_ps(test_vec[39].a);
  r = simde_mm512_roundscale_ps(a, INT32_C(         114));
  simde_test_x86_assert_equal_f32x16(r, simde_mm512_loadu_ps(test_vec[39].r), 1);

  a = simde_mm512_loadu_ps(test_vec[40].a);
  r = simde_mm512_roundscale_ps(a, INT32_C(         130));
  simde_test_x86_assert_equal_f32x16(r, simde_mm512_loadu_ps(test_vec[40].r), 1);

  a = simde_mm512_loadu_ps(test_vec[41].a);
  r = simde_mm512_roundscale_ps(a, INT32_C(         146));
  simde_test_x86_assert_equal_f32x16(r, simde_mm512_loadu_ps(test_vec[41].r), 1);

  a = simde_mm512_loadu_ps(test_vec[42].a);
  r = simde_mm512_roundscale_ps(a, INT32_C(         162));
  simde_test_x86_assert_equal_f32x16(r, simde_mm512_loadu_ps(test_vec[42].r), 1);

  a = simde_mm512_loadu_ps(test_vec[43].a);
  r = simde_mm512_roundscale_ps(a, INT32_C(         178));
  simde_test_x86_assert_equal_f32x16(r, simde_mm512_loadu_ps(test_vec[43].r), 1);

  a = simde_mm512_loadu_ps(test_vec[44].a);
  r = simde_mm512_roundscale_ps(a, INT32_C(         194));
  simde_test_x86_assert_equal_f32x16(r, simde_mm512_loadu_ps(test_vec[44].r), 1);

  a = simde_mm512_loadu_ps(test_vec[45].a);
  r = simde_mm512_roundscale_ps(a, INT32_C(         210));
  simde_test_x86_assert_equal_f32x16(r, simde_mm512_loadu_ps(test_vec[45].r), 1);

  a = simde_mm512_loadu_ps(test_vec[46].a);
  r = simde_mm512_roundscale_ps(a, INT32_C(         226));
  simde_test_x86_assert_equal_f32x16(r, simde_mm512_loadu_ps(test_vec[46].r), 1);

  a = simde_mm512_loadu_ps(test_vec[47].a);
  r = simde_mm512_roundscale_ps(a, INT32_C(         242));
  simde_test_x86_assert_equal_f32x16(r, simde_mm512_loadu_ps(test_vec[47].r), 1);

  a = simde_mm512_loadu_ps(test_vec[48].a);
  r = simde_mm512_roundscale_ps(a, INT32_C(           3));
  simde_test_x86_assert_equal_f32x16(r, simde_mm512_loadu_ps(test_vec[48].r), 1);

  a = simde_mm512_loadu_ps(test_vec[49].a);
  r = simde_mm512_roundscale_ps(a, INT32_C(          19));
  simde_test_x86_assert_equal_f32x16(r, simde_mm512_loadu_ps(test_vec[49].r), 1);

  a = simde_mm512_loadu_ps(test_vec[50].a);
  r = simde_mm512_roundscale_ps(a, INT32_C(          35));
  simde_test_x86_assert_equal_f32x16(r, simde_mm512_loadu_ps(test_vec[50].r), 1);

  a = simde_mm512_loadu_ps(test_vec[51].a);
  r = simde_mm512_roundscale_ps(a, INT32_C(          51));
  simde_test_x86_assert_equal_f32x16(r, simde_mm512_loadu_ps(test_vec[51].r), 1);

  a = simde_mm512_loadu_ps(test_vec[52].a);
  r = simde_mm512_roundscale_ps(a, INT32_C(          67));
  simde_test_x86_assert_equal_f32x16(r, simde_mm512_loadu_ps(test_vec[52].r), 1);

  a = simde_mm512_loadu_ps(test_vec[53].a);
  r = simde_mm512_roundscale_ps(a, INT32_C(          83));
  simde_test_x86_assert_equal_f32x16(r, simde_mm512_loadu_ps(test_vec[53].r), 1);

  a = simde_mm512_loadu_ps(test_vec[54].a);
  r = simde_mm512_roundscale_ps(a, INT32_C(          99));
  simde_test_x86_assert_equal_f32x16(r, simde_mm512_loadu_ps(test_vec[54].r), 1);

  a = simde_mm512_loadu_ps(test_vec[55].a);
  r = simde_mm512_roundscale_ps(a, INT32_C(         115));
  simde_test_x86_assert_equal_f32x16(r, simde_mm512_loadu_ps(test_vec[55].r), 1);

  a = simde_mm512_loadu_ps(test_vec[56].a);
  r = simde_mm512_roundscale_ps(a, INT32_C(         131));
  simde_test_x86_assert_equal_f32x16(r, simde_mm512_loadu_ps(test_vec[56].r), 1);

  a = simde_mm512_loadu_ps(test_vec[57].a);
  r = simde_mm512_roundscale_ps(a, INT32_C(         147));
  simde_test_x86_assert_equal_f32x16(r, simde_mm512_loadu_ps(test_vec[57].r), 1);

  a = simde_mm512_loadu_ps(test_vec[58].a);
  r = simde_mm512_roundscale_ps(a, INT32_C(         163));
  simde_test_x86_assert_equal_f32x16(r, simde_mm512_loadu_ps(test_vec[58].r), 1);

  a = simde_mm512_loadu_ps(test_vec[59].a);
  r = simde_mm512_roundscale_ps(a, INT32_C(         179));
  simde_test_x86_assert_equal_f32x16(r, simde_mm512_loadu_ps(test_vec[59].r), 1);

  a = simde_mm512_loadu_ps(test_vec[60].a);
  r = simde_mm512_roundscale_ps(a, INT32_C(         195));
  simde_test_x86_assert_equal_f32x16(r, simde_mm512_loadu_ps(test_vec[60].r), 1);

  a = simde_mm512_loadu_ps(test_vec[61].a);
  r = simde_mm512_roundscale_ps(a, INT32_C(         211));
  simde_test_x86_assert_equal_f32x16(r, simde_mm512_loadu_ps(test_vec[61].r), 1);

  a = simde_mm512_loadu_ps(test_vec[62].a);
  r = simde_mm512_roundscale_ps(a, INT32_C(         227));
  simde_test_x86_assert_equal_f32x16(r, simde_mm512_loadu_ps(test_vec[62].r), 1);

  a = simde_mm512_loadu_ps(test_vec[63].a);
  r = simde_mm512_roundscale_ps(a, INT32_C(         243));
  simde_test_x86_assert_equal_f32x16(r, simde_mm512_loadu_ps(test_vec[63].r), 1);

  a = simde_mm512_loadu_ps(test_vec[64].a);
  r = simde_mm512_roundscale_ps(a, INT32_C(           4));
  simde_test_x86_assert_equal_f32x16(r, simde_mm512_loadu_ps(test_vec[64].r), 1);

  a = simde_mm512_loadu_ps(test_vec[65].a);
  r = simde_mm512_roundscale_ps(a, INT32_C(          20));
  simde_test_x86_assert_equal_f32x16(r, simde_mm512_loadu_ps(test_vec[65].r), 1);

  a = simde_mm512_loadu_ps(test_vec[66].a);
  r = simde_mm512_roundscale_ps(a, INT32_C(          36));
  simde_test_x86_assert_equal_f32x16(r, simde_mm512_loadu_ps(test_vec[66].r), 1);

  a = simde_mm512_loadu_ps(test_vec[67].a);
  r = simde_mm512_roundscale_ps(a, INT32_C(          52));
  simde_test_x86_assert_equal_f32x16(r, simde_mm512_loadu_ps(test_vec[67].r), 1);

  a = simde_mm512_loadu_ps(test_vec[68].a);
  r = simde_mm512_roundscale_ps(a, INT32_C(          68));
  simde_test_x86_assert_equal_f32x16(r, simde_mm512_loadu_ps(test_vec[68].r), 1);

  a = simde_mm512_loadu_ps(test_vec[69].a);
  r = simde_mm512_roundscale_ps(a, INT32_C(          84));
  simde_test_x86_assert_equal_f32x16(r, simde_mm512_loadu_ps(test_vec[69].r), 1);

  a = simde_mm512_loadu_ps(test_vec[70].a);
  r = simde_mm512_roundscale_ps(a, INT32_C(         100));
  simde_test_x86_assert_equal_f32x16(r, simde_mm512_loadu_ps(test_vec[70].r), 1);

  a = simde_mm512_loadu_ps(test_vec[71].a);
  r = simde_mm512_roundscale_ps(a, INT32_C(         116));
  simde_test_x86_assert_equal_f32x16(r, simde_mm512_loadu_ps(test_vec[71].r), 1);

  a = simde_mm512_loadu_ps(test_vec[72].a);
  r = simde_mm512_roundscale_ps(a, INT32_C(         132));
  simde_test_x86_assert_equal_f32x16(r, simde_mm512_loadu_ps(test_vec[72].r), 1);

  a = simde_mm512_loadu_ps(test_vec[73].a);
  r = simde_mm512_roundscale_ps(a, INT32_C(         148));
  simde_test_x86_assert_equal_f32x16(r, simde_mm512_loadu_ps(test_vec[73].r), 1);

  a = simde_mm512_loadu_ps(test_vec[74].a);
  r = simde_mm512_roundscale_ps(a, INT32_C(         164));
  simde_test_x86_assert_equal_f32x16(r, simde_mm512_loadu_ps(test_vec[74].r), 1);

  a = simde_mm512_loadu_ps(test_vec[75].a);
  r = simde_mm512_roundscale_ps(a, INT32_C(         180));
  simde_test_x86_assert_equal_f32x16(r, simde_mm512_loadu_ps(test_vec[75].r), 1);

  a = simde_mm512_loadu_ps(test_vec[76].a);
  r = simde_mm512_roundscale_ps(a, INT32_C(         196));
  simde_test_x86_assert_equal_f32x16(r, simde_mm512_loadu_ps(test_vec[76].r), 1);

  a = simde_mm512_loadu_ps(test_vec[77].a);
  r = simde_mm512_roundscale_ps(a, INT32_C(         212));
  simde_test_x86_assert_equal_f32x16(r, simde_mm512_loadu_ps(test_vec[77].r), 1);

  a = simde_mm512_loadu_ps(test_vec[78].a);
  r = simde_mm512_roundscale_ps(a, INT32_C(         228));
  simde_test_x86_assert_equal_f32x16(r, simde_mm512_loadu_ps(test_vec[78].r), 1);

  a = simde_mm512_loadu_ps(test_vec[79].a);
  r = simde_mm512_roundscale_ps(a, INT32_C(         244));
  simde_test_x86_assert_equal_f32x16(r, simde_mm512_loadu_ps(test_vec[79].r), 1);

  return 0;
#else
  fputc('\n', stdout);
  int round_type[5] = {SIMDE_MM_FROUND_TO_NEAREST_INT, SIMDE_MM_FROUND_TO_NEG_INF, SIMDE_MM_FROUND_TO_POS_INF, SIMDE_MM_FROUND_TO_ZERO, SIMDE_MM_FROUND_CUR_DIRECTION};
  for (int i = 0 ; i < 5 ; i++) {
    for (int j = 0 ; j < 16 ; j++) {
      simde__m512 a = simde_test_x86_random_f32x16(SIMDE_FLOAT32_C(-1000.0), SIMDE_FLOAT32_C(1000.0));
      if((simde_test_codegen_rand() & 1)) {
        if((simde_test_codegen_rand() & 1))
          a = simde_mm512_mask_mov_ps(a, 1, simde_mm512_set1_ps(SIMDE_MATH_NANF));
        else {
          if((simde_test_codegen_rand() & 1))
            a = simde_mm512_mask_mov_ps(a, 2, simde_mm512_set1_ps(SIMDE_MATH_INFINITY));
          else
            a = simde_mm512_mask_mov_ps(a, 2, simde_mm512_set1_ps(-SIMDE_MATH_INFINITY));
        }
      }
      int imm8 = ((j << 4) | round_type[i]) & 255;
      simde__m512 r;
      SIMDE_CONSTIFY_256_(simde_mm512_roundscale_ps, r, simde_mm512_setzero_ps(), imm8, a);

      simde_test_x86_write_f32x16(2, a, SIMDE_TEST_VEC_POS_FIRST);
      simde_test_codegen_write_i32(2, imm8, SIMDE_TEST_VEC_POS_MIDDLE);
      simde_test_x86_write_f32x16(2, r, SIMDE_TEST_VEC_POS_LAST);
    }
  }
  return 1;
#endif
}

static int
test_simde_mm512_mask_roundscale_ps (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const simde_float32 src[16];
    const simde__mmask8 k;
    const simde_float32 a[16];
    const int32_t imm8;
    const simde_float32 r[16];
  } test_vec[] = {
    { { SIMDE_FLOAT32_C(  -368.58), SIMDE_FLOAT32_C(   671.26), SIMDE_FLOAT32_C(   276.81), SIMDE_FLOAT32_C(   341.78),
        SIMDE_FLOAT32_C(   140.72), SIMDE_FLOAT32_C(   547.75), SIMDE_FLOAT32_C(   178.73), SIMDE_FLOAT32_C(   861.61),
        SIMDE_FLOAT32_C(    56.36), SIMDE_FLOAT32_C(  -214.56), SIMDE_FLOAT32_C(   152.99), SIMDE_FLOAT32_C(   284.00),
        SIMDE_FLOAT32_C(  -923.24), SIMDE_FLOAT32_C(  -638.78), SIMDE_FLOAT32_C(    48.36), SIMDE_FLOAT32_C(   907.10) },
      UINT8_C(140),
      { SIMDE_FLOAT32_C(  -196.81),      SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(  -866.78), SIMDE_FLOAT32_C(   796.60),
        SIMDE_FLOAT32_C(   299.16), SIMDE_FLOAT32_C(  -670.80), SIMDE_FLOAT32_C(  -931.45), SIMDE_FLOAT32_C(   327.80),
        SIMDE_FLOAT32_C(  -798.64), SIMDE_FLOAT32_C(  -170.99), SIMDE_FLOAT32_C(    72.32), SIMDE_FLOAT32_C(  -553.91),
        SIMDE_FLOAT32_C(   620.12), SIMDE_FLOAT32_C(   439.08), SIMDE_FLOAT32_C(    77.51), SIMDE_FLOAT32_C(   291.38) },
       INT32_C(          16),
      { SIMDE_FLOAT32_C(  -368.58), SIMDE_FLOAT32_C(   671.26), SIMDE_FLOAT32_C(  -867.00), SIMDE_FLOAT32_C(   796.50),
        SIMDE_FLOAT32_C(   140.72), SIMDE_FLOAT32_C(   547.75), SIMDE_FLOAT32_C(   178.73), SIMDE_FLOAT32_C(   328.00),
        SIMDE_FLOAT32_C(    56.36), SIMDE_FLOAT32_C(  -214.56), SIMDE_FLOAT32_C(   152.99), SIMDE_FLOAT32_C(   284.00),
        SIMDE_FLOAT32_C(  -923.24), SIMDE_FLOAT32_C(  -638.78), SIMDE_FLOAT32_C(    48.36), SIMDE_FLOAT32_C(   907.10) } },
    { { SIMDE_FLOAT32_C(   598.02), SIMDE_FLOAT32_C(  -706.29), SIMDE_FLOAT32_C(   320.00), SIMDE_FLOAT32_C(  -616.54),
        SIMDE_FLOAT32_C(   446.70), SIMDE_FLOAT32_C(  -396.00), SIMDE_FLOAT32_C(  -539.78), SIMDE_FLOAT32_C(   807.92),
        SIMDE_FLOAT32_C(   652.36), SIMDE_FLOAT32_C(  -632.67), SIMDE_FLOAT32_C(   781.30), SIMDE_FLOAT32_C(  -544.45),
        SIMDE_FLOAT32_C(  -180.13), SIMDE_FLOAT32_C(   914.53), SIMDE_FLOAT32_C(  -747.85), SIMDE_FLOAT32_C(  -880.97) },
      UINT8_C(192),
      { SIMDE_FLOAT32_C(  -679.30), SIMDE_FLOAT32_C(   446.83), SIMDE_FLOAT32_C(  -554.92), SIMDE_FLOAT32_C(   149.71),
        SIMDE_FLOAT32_C(  -480.86), SIMDE_FLOAT32_C(  -108.82), SIMDE_FLOAT32_C(  -230.17), SIMDE_FLOAT32_C(   958.22),
        SIMDE_FLOAT32_C(   968.69), SIMDE_FLOAT32_C(  -938.79), SIMDE_FLOAT32_C(  -325.89), SIMDE_FLOAT32_C(  -612.02),
        SIMDE_FLOAT32_C(  -506.69), SIMDE_FLOAT32_C(   -62.25), SIMDE_FLOAT32_C(   985.99), SIMDE_FLOAT32_C(  -212.98) },
       INT32_C(          33),
      { SIMDE_FLOAT32_C(   598.02), SIMDE_FLOAT32_C(  -706.29), SIMDE_FLOAT32_C(   320.00), SIMDE_FLOAT32_C(  -616.54),
        SIMDE_FLOAT32_C(   446.70), SIMDE_FLOAT32_C(  -396.00), SIMDE_FLOAT32_C(  -230.25), SIMDE_FLOAT32_C(   958.00),
        SIMDE_FLOAT32_C(   652.36), SIMDE_FLOAT32_C(  -632.67), SIMDE_FLOAT32_C(   781.30), SIMDE_FLOAT32_C(  -544.45),
        SIMDE_FLOAT32_C(  -180.13), SIMDE_FLOAT32_C(   914.53), SIMDE_FLOAT32_C(  -747.85), SIMDE_FLOAT32_C(  -880.97) } },
    { { SIMDE_FLOAT32_C(  -766.27), SIMDE_FLOAT32_C(  -138.25), SIMDE_FLOAT32_C(  -170.32), SIMDE_FLOAT32_C(  -958.35),
        SIMDE_FLOAT32_C(  -485.89), SIMDE_FLOAT32_C(   197.00), SIMDE_FLOAT32_C(   822.95), SIMDE_FLOAT32_C(   -30.33),
        SIMDE_FLOAT32_C(  -983.13), SIMDE_FLOAT32_C(   737.48), SIMDE_FLOAT32_C(   221.82), SIMDE_FLOAT32_C(  -864.10),
        SIMDE_FLOAT32_C(   981.21), SIMDE_FLOAT32_C(   542.52), SIMDE_FLOAT32_C(   582.73), SIMDE_FLOAT32_C(  -573.71) },
      UINT8_C(151),
      { SIMDE_FLOAT32_C(  -898.13),      SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(   462.06), SIMDE_FLOAT32_C(  -939.91),
        SIMDE_FLOAT32_C(   286.15), SIMDE_FLOAT32_C(   523.26), SIMDE_FLOAT32_C(  -265.80), SIMDE_FLOAT32_C(   674.13),
        SIMDE_FLOAT32_C(  -983.43), SIMDE_FLOAT32_C(   671.95), SIMDE_FLOAT32_C(   660.12), SIMDE_FLOAT32_C(  -196.40),
        SIMDE_FLOAT32_C(   929.70), SIMDE_FLOAT32_C(  -970.42), SIMDE_FLOAT32_C(    37.32), SIMDE_FLOAT32_C(  -208.54) },
       INT32_C(          82),
      { SIMDE_FLOAT32_C(  -898.12),      SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(   462.06), SIMDE_FLOAT32_C(  -958.35),
        SIMDE_FLOAT32_C(   286.16), SIMDE_FLOAT32_C(   197.00), SIMDE_FLOAT32_C(   822.95), SIMDE_FLOAT32_C(   674.16),
        SIMDE_FLOAT32_C(  -983.13), SIMDE_FLOAT32_C(   737.48), SIMDE_FLOAT32_C(   221.82), SIMDE_FLOAT32_C(  -864.10),
        SIMDE_FLOAT32_C(   981.21), SIMDE_FLOAT32_C(   542.52), SIMDE_FLOAT32_C(   582.73), SIMDE_FLOAT32_C(  -573.71) } },
    { { SIMDE_FLOAT32_C(   -98.07), SIMDE_FLOAT32_C(  -724.76), SIMDE_FLOAT32_C(  -926.87), SIMDE_FLOAT32_C(  -360.59),
        SIMDE_FLOAT32_C(   497.06), SIMDE_FLOAT32_C(  -790.97), SIMDE_FLOAT32_C(  -379.38), SIMDE_FLOAT32_C(    39.58),
        SIMDE_FLOAT32_C(   791.75), SIMDE_FLOAT32_C(    46.91), SIMDE_FLOAT32_C(   731.81), SIMDE_FLOAT32_C(   893.62),
        SIMDE_FLOAT32_C(  -635.63), SIMDE_FLOAT32_C(   193.87), SIMDE_FLOAT32_C(   953.71), SIMDE_FLOAT32_C(   650.53) },
      UINT8_C(118),
      { SIMDE_FLOAT32_C(  -312.08), SIMDE_FLOAT32_C(   324.66), SIMDE_FLOAT32_C(  -266.29), SIMDE_FLOAT32_C(  -640.13),
        SIMDE_FLOAT32_C(   -15.22), SIMDE_FLOAT32_C(   537.31), SIMDE_FLOAT32_C(  -710.43), SIMDE_FLOAT32_C(    14.36),
        SIMDE_FLOAT32_C(  -425.37), SIMDE_FLOAT32_C(    81.03), SIMDE_FLOAT32_C(   873.61), SIMDE_FLOAT32_C(   653.60),
        SIMDE_FLOAT32_C(  -613.39), SIMDE_FLOAT32_C(   929.87), SIMDE_FLOAT32_C(  -444.47), SIMDE_FLOAT32_C(  -338.15) },
       INT32_C(         211),
      { SIMDE_FLOAT32_C(   -98.07), SIMDE_FLOAT32_C(   324.66), SIMDE_FLOAT32_C(  -266.29), SIMDE_FLOAT32_C(  -360.59),
        SIMDE_FLOAT32_C(   -15.22), SIMDE_FLOAT32_C(   537.31), SIMDE_FLOAT32_C(  -710.43), SIMDE_FLOAT32_C(    39.58),
        SIMDE_FLOAT32_C(   791.75), SIMDE_FLOAT32_C(    46.91), SIMDE_FLOAT32_C(   731.81), SIMDE_FLOAT32_C(   893.62),
        SIMDE_FLOAT32_C(  -635.63), SIMDE_FLOAT32_C(   193.87), SIMDE_FLOAT32_C(   953.71), SIMDE_FLOAT32_C(   650.53) } },
    { { SIMDE_FLOAT32_C(  -841.09), SIMDE_FLOAT32_C(  -787.98), SIMDE_FLOAT32_C(   815.55), SIMDE_FLOAT32_C(   198.50),
        SIMDE_FLOAT32_C(  -996.22), SIMDE_FLOAT32_C(  -137.54), SIMDE_FLOAT32_C(   -69.69), SIMDE_FLOAT32_C(   897.40),
        SIMDE_FLOAT32_C(   226.83), SIMDE_FLOAT32_C(  -875.82), SIMDE_FLOAT32_C(   851.11), SIMDE_FLOAT32_C(  -122.64),
        SIMDE_FLOAT32_C(  -158.69), SIMDE_FLOAT32_C(  -460.97), SIMDE_FLOAT32_C(  -797.98), SIMDE_FLOAT32_C(   575.02) },
      UINT8_C( 79),
      { SIMDE_FLOAT32_C(   186.80), SIMDE_FLOAT32_C(   112.33), SIMDE_FLOAT32_C(   188.47), SIMDE_FLOAT32_C(  -798.85),
        SIMDE_FLOAT32_C(   686.96), SIMDE_FLOAT32_C(  -730.49), SIMDE_FLOAT32_C(  -925.24), SIMDE_FLOAT32_C(   340.56),
        SIMDE_FLOAT32_C(  -343.89), SIMDE_FLOAT32_C(  -995.37), SIMDE_FLOAT32_C(   896.09), SIMDE_FLOAT32_C(   317.96),
        SIMDE_FLOAT32_C(  -992.38), SIMDE_FLOAT32_C(    91.03), SIMDE_FLOAT32_C(   476.88), SIMDE_FLOAT32_C(  -780.35) },
       INT32_C(          84),
      { SIMDE_FLOAT32_C(   186.81), SIMDE_FLOAT32_C(   112.34), SIMDE_FLOAT32_C(   188.47), SIMDE_FLOAT32_C(  -798.84),
        SIMDE_FLOAT32_C(  -996.22), SIMDE_FLOAT32_C(  -137.54), SIMDE_FLOAT32_C(  -925.25), SIMDE_FLOAT32_C(   897.40),
        SIMDE_FLOAT32_C(   226.83), SIMDE_FLOAT32_C(  -875.82), SIMDE_FLOAT32_C(   851.11), SIMDE_FLOAT32_C(  -122.64),
        SIMDE_FLOAT32_C(  -158.69), SIMDE_FLOAT32_C(  -460.97), SIMDE_FLOAT32_C(  -797.98), SIMDE_FLOAT32_C(   575.02) } },
    { { SIMDE_FLOAT32_C(  -776.58), SIMDE_FLOAT32_C(   769.03), SIMDE_FLOAT32_C(   605.68), SIMDE_FLOAT32_C(  -879.18),
        SIMDE_FLOAT32_C(    -4.13), SIMDE_FLOAT32_C(   729.87), SIMDE_FLOAT32_C(   971.94), SIMDE_FLOAT32_C(   873.22),
        SIMDE_FLOAT32_C(  -428.82), SIMDE_FLOAT32_C(  -489.03), SIMDE_FLOAT32_C(  -924.76), SIMDE_FLOAT32_C(  -853.80),
        SIMDE_FLOAT32_C(   409.86), SIMDE_FLOAT32_C(   262.04), SIMDE_FLOAT32_C(   258.53), SIMDE_FLOAT32_C(  -401.66) },
      UINT8_C( 76),
      { SIMDE_FLOAT32_C(   -54.51), SIMDE_FLOAT32_C(  -132.16), SIMDE_FLOAT32_C(   537.95), SIMDE_FLOAT32_C(  -713.94),
        SIMDE_FLOAT32_C(   523.96), SIMDE_FLOAT32_C(   542.57), SIMDE_FLOAT32_C(  -817.85), SIMDE_FLOAT32_C(  -158.08),
        SIMDE_FLOAT32_C(   550.19), SIMDE_FLOAT32_C(   273.18), SIMDE_FLOAT32_C(  -681.20), SIMDE_FLOAT32_C(   769.84),
        SIMDE_FLOAT32_C(  -820.25), SIMDE_FLOAT32_C(    -5.83), SIMDE_FLOAT32_C(   993.26), SIMDE_FLOAT32_C(   948.79) },
       INT32_C(         144),
      { SIMDE_FLOAT32_C(  -776.58), SIMDE_FLOAT32_C(   769.03), SIMDE_FLOAT32_C(   537.95), SIMDE_FLOAT32_C(  -713.94),
        SIMDE_FLOAT32_C(    -4.13), SIMDE_FLOAT32_C(   729.87), SIMDE_FLOAT32_C(  -817.85), SIMDE_FLOAT32_C(   873.22),
        SIMDE_FLOAT32_C(  -428.82), SIMDE_FLOAT32_C(  -489.03), SIMDE_FLOAT32_C(  -924.76), SIMDE_FLOAT32_C(  -853.80),
        SIMDE_FLOAT32_C(   409.86), SIMDE_FLOAT32_C(   262.04), SIMDE_FLOAT32_C(   258.53), SIMDE_FLOAT32_C(  -401.66) } },
    { { SIMDE_FLOAT32_C(   -55.35), SIMDE_FLOAT32_C(  -670.28), SIMDE_FLOAT32_C(  -913.98), SIMDE_FLOAT32_C(  -182.13),
        SIMDE_FLOAT32_C(   -99.10), SIMDE_FLOAT32_C(  -403.01), SIMDE_FLOAT32_C(  -106.89), SIMDE_FLOAT32_C(    47.11),
        SIMDE_FLOAT32_C(  -993.15), SIMDE_FLOAT32_C(  -844.85), SIMDE_FLOAT32_C(  -694.36), SIMDE_FLOAT32_C(  -394.81),
        SIMDE_FLOAT32_C(   618.34), SIMDE_FLOAT32_C(   251.14), SIMDE_FLOAT32_C(   473.03), SIMDE_FLOAT32_C(   156.28) },
      UINT8_C( 92),
      { SIMDE_FLOAT32_C(    -3.01),     -SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(   719.34), SIMDE_FLOAT32_C(   838.91),
        SIMDE_FLOAT32_C(  -750.95), SIMDE_FLOAT32_C(    -7.48), SIMDE_FLOAT32_C(  -842.29), SIMDE_FLOAT32_C(  -981.11),
        SIMDE_FLOAT32_C(   172.27), SIMDE_FLOAT32_C(   151.88), SIMDE_FLOAT32_C(  -987.85), SIMDE_FLOAT32_C(   121.05),
        SIMDE_FLOAT32_C(   751.73), SIMDE_FLOAT32_C(  -873.77), SIMDE_FLOAT32_C(  -934.29), SIMDE_FLOAT32_C(  -918.54) },
       INT32_C(          17),
      { SIMDE_FLOAT32_C(   -55.35), SIMDE_FLOAT32_C(  -670.28), SIMDE_FLOAT32_C(   719.00), SIMDE_FLOAT32_C(   838.50),
        SIMDE_FLOAT32_C(  -751.00), SIMDE_FLOAT32_C(  -403.01), SIMDE_FLOAT32_C(  -842.50), SIMDE_FLOAT32_C(    47.11),
        SIMDE_FLOAT32_C(  -993.15), SIMDE_FLOAT32_C(  -844.85), SIMDE_FLOAT32_C(  -694.36), SIMDE_FLOAT32_C(  -394.81),
        SIMDE_FLOAT32_C(   618.34), SIMDE_FLOAT32_C(   251.14), SIMDE_FLOAT32_C(   473.03), SIMDE_FLOAT32_C(   156.28) } },
    { { SIMDE_FLOAT32_C(   776.69), SIMDE_FLOAT32_C(  -970.53), SIMDE_FLOAT32_C(  -183.90), SIMDE_FLOAT32_C(   931.85),
        SIMDE_FLOAT32_C(  -664.89), SIMDE_FLOAT32_C(   421.29), SIMDE_FLOAT32_C(   550.18), SIMDE_FLOAT32_C(   586.24),
        SIMDE_FLOAT32_C(  -105.68), SIMDE_FLOAT32_C(  -293.53), SIMDE_FLOAT32_C(   123.44), SIMDE_FLOAT32_C(   891.31),
        SIMDE_FLOAT32_C(   405.32), SIMDE_FLOAT32_C(  -157.22), SIMDE_FLOAT32_C(   730.22), SIMDE_FLOAT32_C(   654.37) },
      UINT8_C(159),
      {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(   673.25), SIMDE_FLOAT32_C(     7.57), SIMDE_FLOAT32_C(    39.80),
        SIMDE_FLOAT32_C(   685.40), SIMDE_FLOAT32_C(  -871.38), SIMDE_FLOAT32_C(  -208.47), SIMDE_FLOAT32_C(   811.64),
        SIMDE_FLOAT32_C(  -805.67), SIMDE_FLOAT32_C(  -127.01), SIMDE_FLOAT32_C(  -976.11), SIMDE_FLOAT32_C(    77.91),
        SIMDE_FLOAT32_C(   855.35), SIMDE_FLOAT32_C(  -166.86), SIMDE_FLOAT32_C(  -145.40), SIMDE_FLOAT32_C(   884.81) },
       INT32_C(         242),
      {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(   673.25), SIMDE_FLOAT32_C(     7.57), SIMDE_FLOAT32_C(    39.80),
        SIMDE_FLOAT32_C(   685.40), SIMDE_FLOAT32_C(   421.29), SIMDE_FLOAT32_C(   550.18), SIMDE_FLOAT32_C(   811.64),
        SIMDE_FLOAT32_C(  -105.68), SIMDE_FLOAT32_C(  -293.53), SIMDE_FLOAT32_C(   123.44), SIMDE_FLOAT32_C(   891.31),
        SIMDE_FLOAT32_C(   405.32), SIMDE_FLOAT32_C(  -157.22), SIMDE_FLOAT32_C(   730.22), SIMDE_FLOAT32_C(   654.37) } },
  };

  simde__m512 src, a, r;

  src = simde_mm512_loadu_ps(test_vec[0].src);
  a = simde_mm512_loadu_ps(test_vec[0].a);
  r = simde_mm512_mask_roundscale_ps(src, test_vec[0].k, a, INT32_C(          16));
  simde_test_x86_assert_equal_f32x16(r, simde_mm512_loadu_ps(test_vec[0].r), 1);

  src = simde_mm512_loadu_ps(test_vec[1].src);
  a = simde_mm512_loadu_ps(test_vec[1].a);
  r = simde_mm512_mask_roundscale_ps(src, test_vec[1].k, a, INT32_C(          33));
  simde_test_x86_assert_equal_f32x16(r, simde_mm512_loadu_ps(test_vec[1].r), 1);

  src = simde_mm512_loadu_ps(test_vec[2].src);
  a = simde_mm512_loadu_ps(test_vec[2].a);
  r = simde_mm512_mask_roundscale_ps(src, test_vec[2].k, a, INT32_C(          82));
  simde_test_x86_assert_equal_f32x16(r, simde_mm512_loadu_ps(test_vec[2].r), 1);

  src = simde_mm512_loadu_ps(test_vec[3].src);
  a = simde_mm512_loadu_ps(test_vec[3].a);
  r = simde_mm512_mask_roundscale_ps(src, test_vec[3].k, a, INT32_C(         211));
  simde_test_x86_assert_equal_f32x16(r, simde_mm512_loadu_ps(test_vec[3].r), 1);

  src = simde_mm512_loadu_ps(test_vec[4].src);
  a = simde_mm512_loadu_ps(test_vec[4].a);
  r = simde_mm512_mask_roundscale_ps(src, test_vec[4].k, a, INT32_C(          84));
  simde_test_x86_assert_equal_f32x16(r, simde_mm512_loadu_ps(test_vec[4].r), 1);

  src = simde_mm512_loadu_ps(test_vec[5].src);
  a = simde_mm512_loadu_ps(test_vec[5].a);
  r = simde_mm512_mask_roundscale_ps(src, test_vec[5].k, a, INT32_C(         144));
  simde_test_x86_assert_equal_f32x16(r, simde_mm512_loadu_ps(test_vec[5].r), 1);

  src = simde_mm512_loadu_ps(test_vec[6].src);
  a = simde_mm512_loadu_ps(test_vec[6].a);
  r = simde_mm512_mask_roundscale_ps(src, test_vec[6].k, a, INT32_C(          17));
  simde_test_x86_assert_equal_f32x16(r, simde_mm512_loadu_ps(test_vec[6].r), 1);

  src = simde_mm512_loadu_ps(test_vec[7].src);
  a = simde_mm512_loadu_ps(test_vec[7].a);
  r = simde_mm512_mask_roundscale_ps(src, test_vec[7].k, a, INT32_C(         242));
  simde_test_x86_assert_equal_f32x16(r, simde_mm512_loadu_ps(test_vec[7].r), 1);

  return 0;
#else
  fputc('\n', stdout);
  int round_type[5] = {SIMDE_MM_FROUND_TO_NEAREST_INT, SIMDE_MM_FROUND_TO_NEG_INF, SIMDE_MM_FROUND_TO_POS_INF, SIMDE_MM_FROUND_TO_ZERO, SIMDE_MM_FROUND_CUR_DIRECTION};
  for (int i = 0 ; i < 8 ; i++) {
    simde__m512 src = simde_test_x86_random_f32x16(SIMDE_FLOAT32_C(-1000.0), SIMDE_FLOAT32_C(1000.0));
    simde__mmask8 k = simde_test_x86_random_mmask8();
    simde__m512 a = simde_test_x86_random_f32x16(SIMDE_FLOAT32_C(-1000.0), SIMDE_FLOAT32_C(1000.0));
    if((simde_test_codegen_rand() & 1)) {
      if((simde_test_codegen_rand() & 1))
        a = simde_mm512_mask_mov_ps(a, 1, simde_mm512_set1_ps(SIMDE_MATH_NANF));
      else {
        if((simde_test_codegen_rand() & 1))
          a = simde_mm512_mask_mov_ps(a, 2, simde_mm512_set1_ps(SIMDE_MATH_INFINITY));
        else
          a = simde_mm512_mask_mov_ps(a, 2, simde_mm512_set1_ps(-SIMDE_MATH_INFINITY));
      }
    }
    int imm8 = (((simde_test_codegen_rand() & 15) << 4) | round_type[i % 5]) & 255;
    simde__m512 r;
    SIMDE_CONSTIFY_256_(simde_mm512_mask_roundscale_ps, r, simde_mm512_setzero_ps(), imm8, src, k, a);

    simde_test_x86_write_f32x16(2, src, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_mmask8(2, k, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_f32x16(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i32(2, imm8, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_f32x16(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm512_maskz_roundscale_ps (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const simde__mmask8 k;
    const simde_float32 a[16];
    const int32_t imm8;
    const simde_float32 r[16];
  } test_vec[] = {
    { UINT8_C(234),
      { SIMDE_FLOAT32_C(   -13.26), SIMDE_FLOAT32_C(   198.00), SIMDE_FLOAT32_C(  -516.28), SIMDE_FLOAT32_C(  -586.06),
        SIMDE_FLOAT32_C(  -522.32), SIMDE_FLOAT32_C(  -834.30), SIMDE_FLOAT32_C(  -963.78), SIMDE_FLOAT32_C(   129.47),
        SIMDE_FLOAT32_C(   364.21), SIMDE_FLOAT32_C(   -20.29), SIMDE_FLOAT32_C(   293.22), SIMDE_FLOAT32_C(  -223.95),
        SIMDE_FLOAT32_C(  -730.48), SIMDE_FLOAT32_C(  -697.92), SIMDE_FLOAT32_C(   411.90), SIMDE_FLOAT32_C(  -489.41) },
       INT32_C(         208),
      { SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(   198.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(  -586.06),
        SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(  -834.30), SIMDE_FLOAT32_C(  -963.78), SIMDE_FLOAT32_C(   129.47),
        SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00),
        SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00) } },
    { UINT8_C( 69),
      { SIMDE_FLOAT32_C(   771.32), SIMDE_FLOAT32_C(   547.03), SIMDE_FLOAT32_C(  -839.90), SIMDE_FLOAT32_C(  -855.36),
        SIMDE_FLOAT32_C(  -639.47), SIMDE_FLOAT32_C(  -711.44), SIMDE_FLOAT32_C(   257.81), SIMDE_FLOAT32_C(  -622.92),
        SIMDE_FLOAT32_C(    48.32), SIMDE_FLOAT32_C(    61.28), SIMDE_FLOAT32_C(  -328.47), SIMDE_FLOAT32_C(   892.68),
        SIMDE_FLOAT32_C(  -951.98), SIMDE_FLOAT32_C(   869.52), SIMDE_FLOAT32_C(  -623.59), SIMDE_FLOAT32_C(  -538.04) },
       INT32_C(         241),
      { SIMDE_FLOAT32_C(   771.32), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(  -839.90), SIMDE_FLOAT32_C(     0.00),
        SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(   257.81), SIMDE_FLOAT32_C(     0.00),
        SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00),
        SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00) } },
    { UINT8_C(219),
      { SIMDE_FLOAT32_C(   476.68),      SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(   477.90), SIMDE_FLOAT32_C(  -230.10),
        SIMDE_FLOAT32_C(  -317.64), SIMDE_FLOAT32_C(   747.41), SIMDE_FLOAT32_C(    71.98), SIMDE_FLOAT32_C(  -905.73),
        SIMDE_FLOAT32_C(  -741.99), SIMDE_FLOAT32_C(  -985.21), SIMDE_FLOAT32_C(  -171.21), SIMDE_FLOAT32_C(   842.79),
        SIMDE_FLOAT32_C(   786.11), SIMDE_FLOAT32_C(  -624.19), SIMDE_FLOAT32_C(  -997.11), SIMDE_FLOAT32_C(   930.75) },
       INT32_C(         114),
      { SIMDE_FLOAT32_C(   476.69),      SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(  -230.09),
        SIMDE_FLOAT32_C(  -317.63), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(    71.98), SIMDE_FLOAT32_C(  -905.73),
        SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00),
        SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00) } },
    { UINT8_C(247),
      { SIMDE_FLOAT32_C(  -750.15),      SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(   232.46), SIMDE_FLOAT32_C(  -702.13),
        SIMDE_FLOAT32_C(   654.48), SIMDE_FLOAT32_C(   608.87), SIMDE_FLOAT32_C(  -240.17), SIMDE_FLOAT32_C(  -998.32),
        SIMDE_FLOAT32_C(  -849.02), SIMDE_FLOAT32_C(   258.02), SIMDE_FLOAT32_C(   478.36), SIMDE_FLOAT32_C(  -942.70),
        SIMDE_FLOAT32_C(  -264.09), SIMDE_FLOAT32_C(  -751.74), SIMDE_FLOAT32_C(  -260.33), SIMDE_FLOAT32_C(  -516.68) },
       INT32_C(          99),
      { SIMDE_FLOAT32_C(  -750.14),      SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(   232.45), SIMDE_FLOAT32_C(     0.00),
        SIMDE_FLOAT32_C(   654.47), SIMDE_FLOAT32_C(   608.86), SIMDE_FLOAT32_C(  -240.16), SIMDE_FLOAT32_C(  -998.31),
        SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00),
        SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00) } },
    { UINT8_C(148),
      { SIMDE_FLOAT32_C(  -415.88), SIMDE_FLOAT32_C(   121.14), SIMDE_FLOAT32_C(  -961.46), SIMDE_FLOAT32_C(  -412.98),
        SIMDE_FLOAT32_C(    51.89), SIMDE_FLOAT32_C(  -225.11), SIMDE_FLOAT32_C(  -121.53), SIMDE_FLOAT32_C(  -759.54),
        SIMDE_FLOAT32_C(   888.31), SIMDE_FLOAT32_C(  -781.75), SIMDE_FLOAT32_C(  -509.69), SIMDE_FLOAT32_C(   673.26),
        SIMDE_FLOAT32_C(   450.72), SIMDE_FLOAT32_C(  -211.82), SIMDE_FLOAT32_C(   327.74), SIMDE_FLOAT32_C(    59.59) },
       INT32_C(         116),
      { SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(  -961.46), SIMDE_FLOAT32_C(     0.00),
        SIMDE_FLOAT32_C(    51.89), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(  -759.54),
        SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00),
        SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00) } },
    { UINT8_C(  6),
      { SIMDE_FLOAT32_C(  -193.97), SIMDE_FLOAT32_C(  -192.22), SIMDE_FLOAT32_C(   267.87), SIMDE_FLOAT32_C(   541.94),
        SIMDE_FLOAT32_C(    56.04), SIMDE_FLOAT32_C(  -992.46), SIMDE_FLOAT32_C(  -974.74), SIMDE_FLOAT32_C(  -623.72),
        SIMDE_FLOAT32_C(  -158.53), SIMDE_FLOAT32_C(  -233.41), SIMDE_FLOAT32_C(   711.32), SIMDE_FLOAT32_C(  -495.81),
        SIMDE_FLOAT32_C(   350.72), SIMDE_FLOAT32_C(  -167.54), SIMDE_FLOAT32_C(  -457.27), SIMDE_FLOAT32_C(   937.73) },
       INT32_C(         128),
      { SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(  -192.22), SIMDE_FLOAT32_C(   267.87), SIMDE_FLOAT32_C(     0.00),
        SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00),
        SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00),
        SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00) } },
    { UINT8_C( 28),
      { SIMDE_FLOAT32_C(  -875.18),     -SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(    34.45), SIMDE_FLOAT32_C(  -384.88),
        SIMDE_FLOAT32_C(  -120.81), SIMDE_FLOAT32_C(  -514.83), SIMDE_FLOAT32_C(   403.30), SIMDE_FLOAT32_C(  -793.07),
        SIMDE_FLOAT32_C(   544.76), SIMDE_FLOAT32_C(   -48.68), SIMDE_FLOAT32_C(   536.35), SIMDE_FLOAT32_C(  -244.67),
        SIMDE_FLOAT32_C(   757.35), SIMDE_FLOAT32_C(  -655.86), SIMDE_FLOAT32_C(  -976.80), SIMDE_FLOAT32_C(   299.28) },
       INT32_C(          97),
      { SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(    34.44), SIMDE_FLOAT32_C(  -384.89),
        SIMDE_FLOAT32_C(  -120.81), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00),
        SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00),
        SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00) } },
    { UINT8_C( 38),
      {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(   487.78), SIMDE_FLOAT32_C(   376.40), SIMDE_FLOAT32_C(   441.86),
        SIMDE_FLOAT32_C(  -679.76), SIMDE_FLOAT32_C(   919.14), SIMDE_FLOAT32_C(   379.59), SIMDE_FLOAT32_C(  -795.40),
        SIMDE_FLOAT32_C(   236.75), SIMDE_FLOAT32_C(  -804.21), SIMDE_FLOAT32_C(  -670.58), SIMDE_FLOAT32_C(  -557.32),
        SIMDE_FLOAT32_C(   230.25), SIMDE_FLOAT32_C(   -55.46), SIMDE_FLOAT32_C(   321.87), SIMDE_FLOAT32_C(   715.42) },
       INT32_C(         146),
      { SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(   487.78), SIMDE_FLOAT32_C(   376.40), SIMDE_FLOAT32_C(     0.00),
        SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(   919.14), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00),
        SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00),
        SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00) } },
  };

  simde__m512 a, r;

  a = simde_mm512_loadu_ps(test_vec[0].a);
  r = simde_mm512_maskz_roundscale_ps(test_vec[0].k, a, INT32_C(         208));
  simde_test_x86_assert_equal_f32x16(r, simde_mm512_loadu_ps(test_vec[0].r), 1);

  a = simde_mm512_loadu_ps(test_vec[1].a);
  r = simde_mm512_maskz_roundscale_ps(test_vec[1].k, a, INT32_C(         241));
  simde_test_x86_assert_equal_f32x16(r, simde_mm512_loadu_ps(test_vec[1].r), 1);

  a = simde_mm512_loadu_ps(test_vec[2].a);
  r = simde_mm512_maskz_roundscale_ps(test_vec[2].k, a, INT32_C(         114));
  simde_test_x86_assert_equal_f32x16(r, simde_mm512_loadu_ps(test_vec[2].r), 1);

  a = simde_mm512_loadu_ps(test_vec[3].a);
  r = simde_mm512_maskz_roundscale_ps(test_vec[3].k, a, INT32_C(          99));
  simde_test_x86_assert_equal_f32x16(r, simde_mm512_loadu_ps(test_vec[3].r), 1);

  a = simde_mm512_loadu_ps(test_vec[4].a);
  r = simde_mm512_maskz_roundscale_ps(test_vec[4].k, a, INT32_C(         116));
  simde_test_x86_assert_equal_f32x16(r, simde_mm512_loadu_ps(test_vec[4].r), 1);

  a = simde_mm512_loadu_ps(test_vec[5].a);
  r = simde_mm512_maskz_roundscale_ps(test_vec[5].k, a, INT32_C(         128));
  simde_test_x86_assert_equal_f32x16(r, simde_mm512_loadu_ps(test_vec[5].r), 1);

  a = simde_mm512_loadu_ps(test_vec[6].a);
  r = simde_mm512_maskz_roundscale_ps(test_vec[6].k, a, INT32_C(          97));
  simde_test_x86_assert_equal_f32x16(r, simde_mm512_loadu_ps(test_vec[6].r), 1);

  a = simde_mm512_loadu_ps(test_vec[7].a);
  r = simde_mm512_maskz_roundscale_ps(test_vec[7].k, a, INT32_C(         146));
  simde_test_x86_assert_equal_f32x16(r, simde_mm512_loadu_ps(test_vec[7].r), 1);

  return 0;
#else
  fputc('\n', stdout);
  int round_type[5] = {SIMDE_MM_FROUND_TO_NEAREST_INT, SIMDE_MM_FROUND_TO_NEG_INF, SIMDE_MM_FROUND_TO_POS_INF, SIMDE_MM_FROUND_TO_ZERO, SIMDE_MM_FROUND_CUR_DIRECTION};
  for (int i = 0 ; i < 8 ; i++) {
    simde__mmask8 k = simde_test_x86_random_mmask8();
    simde__m512 a = simde_test_x86_random_f32x16(SIMDE_FLOAT32_C(-1000.0), SIMDE_FLOAT32_C(1000.0));
    if((simde_test_codegen_rand() & 1)) {
      if((simde_test_codegen_rand() & 1))
        a = simde_mm512_mask_mov_ps(a, 1, simde_mm512_set1_ps(SIMDE_MATH_NANF));
      else {
        if((simde_test_codegen_rand() & 1))
          a = simde_mm512_mask_mov_ps(a, 2, simde_mm512_set1_ps(SIMDE_MATH_INFINITY));
        else
          a = simde_mm512_mask_mov_ps(a, 2, simde_mm512_set1_ps(-SIMDE_MATH_INFINITY));
      }
    }
    int imm8 = (((simde_test_codegen_rand() & 15) << 4) | round_type[i % 5]) & 255;
    simde__m512 r;
    SIMDE_CONSTIFY_256_(simde_mm512_maskz_roundscale_ps, r, simde_mm512_setzero_ps(), imm8, k, a);

    simde_test_x86_write_mmask8(2, k, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_f32x16(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i32(2, imm8, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_f32x16(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm512_roundscale_round_ps (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const simde_float32 a[16];
    const int32_t imm8;
    const int32_t sae;
    const simde_float32 r[16];
  } test_vec[] = {
    { { SIMDE_FLOAT32_C(   420.36), SIMDE_FLOAT32_C(  -392.69), SIMDE_FLOAT32_C(    92.54), SIMDE_FLOAT32_C(  -516.66),
        SIMDE_FLOAT32_C(  -461.28), SIMDE_FLOAT32_C(   334.68), SIMDE_FLOAT32_C(  -795.62), SIMDE_FLOAT32_C(   457.56),
        SIMDE_FLOAT32_C(   838.71), SIMDE_FLOAT32_C(  -818.44), SIMDE_FLOAT32_C(  -257.99), SIMDE_FLOAT32_C(   715.11),
        SIMDE_FLOAT32_C(   338.10), SIMDE_FLOAT32_C(   349.70), SIMDE_FLOAT32_C(  -986.91), SIMDE_FLOAT32_C(   385.06) },
       INT32_C(         128),
       INT32_C(           8),
      { SIMDE_FLOAT32_C(   420.36), SIMDE_FLOAT32_C(  -392.69), SIMDE_FLOAT32_C(    92.54), SIMDE_FLOAT32_C(  -516.66),
        SIMDE_FLOAT32_C(  -461.28), SIMDE_FLOAT32_C(   334.68), SIMDE_FLOAT32_C(  -795.62), SIMDE_FLOAT32_C(   457.56),
        SIMDE_FLOAT32_C(   838.71), SIMDE_FLOAT32_C(  -818.44), SIMDE_FLOAT32_C(  -257.99), SIMDE_FLOAT32_C(   715.11),
        SIMDE_FLOAT32_C(   338.10), SIMDE_FLOAT32_C(   349.70), SIMDE_FLOAT32_C(  -986.91), SIMDE_FLOAT32_C(   385.06) } },
    { { SIMDE_FLOAT32_C(  -102.50),     -SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(   610.23), SIMDE_FLOAT32_C(   712.54),
        SIMDE_FLOAT32_C(  -668.49), SIMDE_FLOAT32_C(   752.35), SIMDE_FLOAT32_C(  -528.74), SIMDE_FLOAT32_C(   -20.66),
        SIMDE_FLOAT32_C(  -980.81), SIMDE_FLOAT32_C(  -208.53), SIMDE_FLOAT32_C(  -940.25), SIMDE_FLOAT32_C(   895.60),
        SIMDE_FLOAT32_C(  -788.17), SIMDE_FLOAT32_C(  -332.94), SIMDE_FLOAT32_C(   -11.86), SIMDE_FLOAT32_C(  -304.83) },
       INT32_C(          65),
       INT32_C(           8),
      { SIMDE_FLOAT32_C(  -102.50),     -SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(   610.19), SIMDE_FLOAT32_C(   712.50),
        SIMDE_FLOAT32_C(  -668.50), SIMDE_FLOAT32_C(   752.31), SIMDE_FLOAT32_C(  -528.75), SIMDE_FLOAT32_C(   -20.69),
        SIMDE_FLOAT32_C(  -980.81), SIMDE_FLOAT32_C(  -208.56), SIMDE_FLOAT32_C(  -940.25), SIMDE_FLOAT32_C(   895.56),
        SIMDE_FLOAT32_C(  -788.19), SIMDE_FLOAT32_C(  -333.00), SIMDE_FLOAT32_C(   -11.88), SIMDE_FLOAT32_C(  -304.88) } },
    { { SIMDE_FLOAT32_C(    81.11),      SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(   876.65), SIMDE_FLOAT32_C(  -580.79),
        SIMDE_FLOAT32_C(  -244.95), SIMDE_FLOAT32_C(   889.73), SIMDE_FLOAT32_C(   804.27), SIMDE_FLOAT32_C(  -859.60),
        SIMDE_FLOAT32_C(   948.64), SIMDE_FLOAT32_C(  -574.10), SIMDE_FLOAT32_C(    37.90), SIMDE_FLOAT32_C(  -975.20),
        SIMDE_FLOAT32_C(  -963.86), SIMDE_FLOAT32_C(  -249.56), SIMDE_FLOAT32_C(  -643.68), SIMDE_FLOAT32_C(   788.49) },
       INT32_C(         226),
       INT32_C(           4),
      { SIMDE_FLOAT32_C(    81.11),      SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(   876.65), SIMDE_FLOAT32_C(  -580.79),
        SIMDE_FLOAT32_C(  -244.95), SIMDE_FLOAT32_C(   889.73), SIMDE_FLOAT32_C(   804.27), SIMDE_FLOAT32_C(  -859.60),
        SIMDE_FLOAT32_C(   948.64), SIMDE_FLOAT32_C(  -574.10), SIMDE_FLOAT32_C(    37.90), SIMDE_FLOAT32_C(  -975.20),
        SIMDE_FLOAT32_C(  -963.86), SIMDE_FLOAT32_C(  -249.56), SIMDE_FLOAT32_C(  -643.68), SIMDE_FLOAT32_C(   788.49) } },
    { {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(  -775.00), SIMDE_FLOAT32_C(  -937.53), SIMDE_FLOAT32_C(  -308.58),
        SIMDE_FLOAT32_C(   -79.83), SIMDE_FLOAT32_C(   268.25), SIMDE_FLOAT32_C(    14.24), SIMDE_FLOAT32_C(   819.73),
        SIMDE_FLOAT32_C(   931.60), SIMDE_FLOAT32_C(   175.77), SIMDE_FLOAT32_C(   -99.16), SIMDE_FLOAT32_C(   336.95),
        SIMDE_FLOAT32_C(    52.42), SIMDE_FLOAT32_C(   320.05), SIMDE_FLOAT32_C(  -908.00), SIMDE_FLOAT32_C(   -57.85) },
       INT32_C(         243),
       INT32_C(           8),
      {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(  -775.00), SIMDE_FLOAT32_C(  -937.53), SIMDE_FLOAT32_C(  -308.58),
        SIMDE_FLOAT32_C(   -79.83), SIMDE_FLOAT32_C(   268.25), SIMDE_FLOAT32_C(    14.24), SIMDE_FLOAT32_C(   819.73),
        SIMDE_FLOAT32_C(   931.60), SIMDE_FLOAT32_C(   175.77), SIMDE_FLOAT32_C(   -99.16), SIMDE_FLOAT32_C(   336.95),
        SIMDE_FLOAT32_C(    52.42), SIMDE_FLOAT32_C(   320.05), SIMDE_FLOAT32_C(  -908.00), SIMDE_FLOAT32_C(   -57.85) } },
    { { SIMDE_FLOAT32_C(   270.29), SIMDE_FLOAT32_C(   -84.41), SIMDE_FLOAT32_C(   586.36), SIMDE_FLOAT32_C(  -979.27),
        SIMDE_FLOAT32_C(   271.91), SIMDE_FLOAT32_C(   374.85), SIMDE_FLOAT32_C(   242.43), SIMDE_FLOAT32_C(  -392.43),
        SIMDE_FLOAT32_C(   182.52), SIMDE_FLOAT32_C(   255.60), SIMDE_FLOAT32_C(  -997.03), SIMDE_FLOAT32_C(  -114.21),
        SIMDE_FLOAT32_C(   480.61), SIMDE_FLOAT32_C(  -934.56), SIMDE_FLOAT32_C(   577.21), SIMDE_FLOAT32_C(  -599.22) },
       INT32_C(          68),
       INT32_C(           4),
      { SIMDE_FLOAT32_C(   270.31), SIMDE_FLOAT32_C(   -84.44), SIMDE_FLOAT32_C(   586.38), SIMDE_FLOAT32_C(  -979.25),
        SIMDE_FLOAT32_C(   271.94), SIMDE_FLOAT32_C(   374.88), SIMDE_FLOAT32_C(   242.44), SIMDE_FLOAT32_C(  -392.44),
        SIMDE_FLOAT32_C(   182.50), SIMDE_FLOAT32_C(   255.62), SIMDE_FLOAT32_C(  -997.00), SIMDE_FLOAT32_C(  -114.19),
        SIMDE_FLOAT32_C(   480.62), SIMDE_FLOAT32_C(  -934.56), SIMDE_FLOAT32_C(   577.19), SIMDE_FLOAT32_C(  -599.25) } },
    { {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(   767.22), SIMDE_FLOAT32_C(   121.34), SIMDE_FLOAT32_C(  -397.76),
        SIMDE_FLOAT32_C(  -180.36), SIMDE_FLOAT32_C(  -558.61), SIMDE_FLOAT32_C(  -305.76), SIMDE_FLOAT32_C(   761.79),
        SIMDE_FLOAT32_C(   565.70), SIMDE_FLOAT32_C(   -73.36), SIMDE_FLOAT32_C(  -347.42), SIMDE_FLOAT32_C(   115.93),
        SIMDE_FLOAT32_C(  -803.07), SIMDE_FLOAT32_C(   568.17), SIMDE_FLOAT32_C(  -297.71), SIMDE_FLOAT32_C(  -782.34) },
       INT32_C(          16),
       INT32_C(           4),
      {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(   767.00), SIMDE_FLOAT32_C(   121.50), SIMDE_FLOAT32_C(  -398.00),
        SIMDE_FLOAT32_C(  -180.50), SIMDE_FLOAT32_C(  -558.50), SIMDE_FLOAT32_C(  -306.00), SIMDE_FLOAT32_C(   762.00),
        SIMDE_FLOAT32_C(   565.50), SIMDE_FLOAT32_C(   -73.50), SIMDE_FLOAT32_C(  -347.50), SIMDE_FLOAT32_C(   116.00),
        SIMDE_FLOAT32_C(  -803.00), SIMDE_FLOAT32_C(   568.00), SIMDE_FLOAT32_C(  -297.50), SIMDE_FLOAT32_C(  -782.50) } },
    { { SIMDE_FLOAT32_C(   259.65),     -SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(   450.62), SIMDE_FLOAT32_C(  -854.55),
        SIMDE_FLOAT32_C(  -803.69), SIMDE_FLOAT32_C(   516.07), SIMDE_FLOAT32_C(   722.66), SIMDE_FLOAT32_C(  -402.91),
        SIMDE_FLOAT32_C(  -150.24), SIMDE_FLOAT32_C(  -685.89), SIMDE_FLOAT32_C(  -182.41), SIMDE_FLOAT32_C(  -884.95),
        SIMDE_FLOAT32_C(  -918.68), SIMDE_FLOAT32_C(   938.93), SIMDE_FLOAT32_C(  -282.71), SIMDE_FLOAT32_C(   -99.04) },
       INT32_C(         209),
       INT32_C(           8),
      { SIMDE_FLOAT32_C(   259.65),     -SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(   450.62), SIMDE_FLOAT32_C(  -854.55),
        SIMDE_FLOAT32_C(  -803.69), SIMDE_FLOAT32_C(   516.07), SIMDE_FLOAT32_C(   722.66), SIMDE_FLOAT32_C(  -402.91),
        SIMDE_FLOAT32_C(  -150.24), SIMDE_FLOAT32_C(  -685.89), SIMDE_FLOAT32_C(  -182.41), SIMDE_FLOAT32_C(  -884.95),
        SIMDE_FLOAT32_C(  -918.68), SIMDE_FLOAT32_C(   938.93), SIMDE_FLOAT32_C(  -282.71), SIMDE_FLOAT32_C(   -99.04) } },
    { {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(    61.95), SIMDE_FLOAT32_C(  -464.91), SIMDE_FLOAT32_C(  -116.51),
        SIMDE_FLOAT32_C(   764.24), SIMDE_FLOAT32_C(  -247.25), SIMDE_FLOAT32_C(   723.58), SIMDE_FLOAT32_C(   841.37),
        SIMDE_FLOAT32_C(  -787.15), SIMDE_FLOAT32_C(   171.22), SIMDE_FLOAT32_C(   101.02), SIMDE_FLOAT32_C(   -71.45),
        SIMDE_FLOAT32_C(  -378.15), SIMDE_FLOAT32_C(   246.47), SIMDE_FLOAT32_C(   124.86), SIMDE_FLOAT32_C(  -862.09) },
       INT32_C(         146),
       INT32_C(           8),
      {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(    61.95), SIMDE_FLOAT32_C(  -464.91), SIMDE_FLOAT32_C(  -116.51),
        SIMDE_FLOAT32_C(   764.24), SIMDE_FLOAT32_C(  -247.25), SIMDE_FLOAT32_C(   723.58), SIMDE_FLOAT32_C(   841.37),
        SIMDE_FLOAT32_C(  -787.15), SIMDE_FLOAT32_C(   171.22), SIMDE_FLOAT32_C(   101.02), SIMDE_FLOAT32_C(   -71.45),
        SIMDE_FLOAT32_C(  -378.15), SIMDE_FLOAT32_C(   246.47), SIMDE_FLOAT32_C(   124.86), SIMDE_FLOAT32_C(  -862.09) } },
  };

  simde__m512 a, r;

  a = simde_mm512_loadu_ps(test_vec[0].a);
  r = simde_mm512_roundscale_round_ps(a, INT32_C(         128), INT32_C(           8));
  simde_test_x86_assert_equal_f32x16(r, simde_mm512_loadu_ps(test_vec[0].r), 1);

  a = simde_mm512_loadu_ps(test_vec[1].a);
  r = simde_mm512_roundscale_round_ps(a, INT32_C(          65), INT32_C(           8));
  simde_test_x86_assert_equal_f32x16(r, simde_mm512_loadu_ps(test_vec[1].r), 1);

  a = simde_mm512_loadu_ps(test_vec[2].a);
  r = simde_mm512_roundscale_round_ps(a, INT32_C(         226), INT32_C(           4));
  simde_test_x86_assert_equal_f32x16(r, simde_mm512_loadu_ps(test_vec[2].r), 1);

  a = simde_mm512_loadu_ps(test_vec[3].a);
  r = simde_mm512_roundscale_round_ps(a, INT32_C(         243), INT32_C(           8));
  simde_test_x86_assert_equal_f32x16(r, simde_mm512_loadu_ps(test_vec[3].r), 1);

  a = simde_mm512_loadu_ps(test_vec[4].a);
  r = simde_mm512_roundscale_round_ps(a, INT32_C(          68), INT32_C(           4));
  simde_test_x86_assert_equal_f32x16(r, simde_mm512_loadu_ps(test_vec[4].r), 1);

  a = simde_mm512_loadu_ps(test_vec[5].a);
  r = simde_mm512_roundscale_round_ps(a, INT32_C(          16), INT32_C(           4));
  simde_test_x86_assert_equal_f32x16(r, simde_mm512_loadu_ps(test_vec[5].r), 1);

  a = simde_mm512_loadu_ps(test_vec[6].a);
  r = simde_mm512_roundscale_round_ps(a, INT32_C(         209), INT32_C(           8));
  simde_test_x86_assert_equal_f32x16(r, simde_mm512_loadu_ps(test_vec[6].r), 1);

  a = simde_mm512_loadu_ps(test_vec[7].a);
  r = simde_mm512_roundscale_round_ps(a, INT32_C(         146), INT32_C(           8));
  simde_test_x86_assert_equal_f32x16(r, simde_mm512_loadu_ps(test_vec[7].r), 1);

  return 0;
#else
  fputc('\n', stdout);
  int round_type[5] = {SIMDE_MM_FROUND_TO_NEAREST_INT, SIMDE_MM_FROUND_TO_NEG_INF, SIMDE_MM_FROUND_TO_POS_INF, SIMDE_MM_FROUND_TO_ZERO, SIMDE_MM_FROUND_CUR_DIRECTION};
  for (int i = 0 ; i < 8 ; i++) {
    simde__m512 a = simde_test_x86_random_f32x16(SIMDE_FLOAT32_C(-1000.0), SIMDE_FLOAT32_C(1000.0));
    if((simde_test_codegen_rand() & 1)) {
      if((simde_test_codegen_rand() & 1))
        a = simde_mm512_mask_mov_ps(a, 1, simde_mm512_set1_ps(SIMDE_MATH_NANF));
      else {
        if((simde_test_codegen_rand() & 1))
          a = simde_mm512_mask_mov_ps(a, 2, simde_mm512_set1_ps(SIMDE_MATH_INFINITY));
        else
          a = simde_mm512_mask_mov_ps(a, 2, simde_mm512_set1_ps(-SIMDE_MATH_INFINITY));
      }
    }
    int imm8 = (((simde_test_codegen_rand() & 15) << 4) | round_type[i % 5]) & 255;
    int sae = (simde_test_codegen_rand() & 1) ? SIMDE_MM_FROUND_CUR_DIRECTION: SIMDE_MM_FROUND_NO_EXC;
    simde__m512 r;
    SIMDE_CONSTIFY_256_NEW(simde_mm512_roundscale_round_ps, r, simde_mm512_setzero_ps(), imm8, sae, a);

    simde_test_x86_write_f32x16(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_codegen_write_i32(2, imm8, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i32(2, sae, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_f32x16(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm512_mask_roundscale_round_ps (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const simde_float32 src[16];
    const simde__mmask8 k;
    const simde_float32 a[16];
    const int32_t imm8;
    const int32_t sae;
    const simde_float32 r[16];
  } test_vec[] = {
    { { SIMDE_FLOAT32_C(  -683.72), SIMDE_FLOAT32_C(   458.47), SIMDE_FLOAT32_C(  -593.60), SIMDE_FLOAT32_C(   433.99),
        SIMDE_FLOAT32_C(   507.21), SIMDE_FLOAT32_C(  -748.26), SIMDE_FLOAT32_C(   930.02), SIMDE_FLOAT32_C(   211.45),
        SIMDE_FLOAT32_C(   545.03), SIMDE_FLOAT32_C(   396.72), SIMDE_FLOAT32_C(   252.12), SIMDE_FLOAT32_C(  -162.44),
        SIMDE_FLOAT32_C(  -909.04), SIMDE_FLOAT32_C(  -524.81), SIMDE_FLOAT32_C(  -182.17), SIMDE_FLOAT32_C(   649.98) },
      UINT8_C(106),
      {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(   420.31), SIMDE_FLOAT32_C(   726.25), SIMDE_FLOAT32_C(  -425.66),
        SIMDE_FLOAT32_C(   519.34), SIMDE_FLOAT32_C(   413.17), SIMDE_FLOAT32_C(   674.22), SIMDE_FLOAT32_C(  -345.82),
        SIMDE_FLOAT32_C(  -228.35), SIMDE_FLOAT32_C(   -30.31), SIMDE_FLOAT32_C(  -791.64), SIMDE_FLOAT32_C(   638.20),
        SIMDE_FLOAT32_C(  -289.44), SIMDE_FLOAT32_C(   644.82), SIMDE_FLOAT32_C(   954.47), SIMDE_FLOAT32_C(  -830.97) },
       INT32_C(          64),
       INT32_C(           4),
      { SIMDE_FLOAT32_C(  -683.72), SIMDE_FLOAT32_C(   420.31), SIMDE_FLOAT32_C(  -593.60), SIMDE_FLOAT32_C(  -425.69),
        SIMDE_FLOAT32_C(   507.21), SIMDE_FLOAT32_C(   413.19), SIMDE_FLOAT32_C(   674.25), SIMDE_FLOAT32_C(   211.45),
        SIMDE_FLOAT32_C(   545.03), SIMDE_FLOAT32_C(   396.72), SIMDE_FLOAT32_C(   252.12), SIMDE_FLOAT32_C(  -162.44),
        SIMDE_FLOAT32_C(  -909.04), SIMDE_FLOAT32_C(  -524.81), SIMDE_FLOAT32_C(  -182.17), SIMDE_FLOAT32_C(   649.98) } },
    { { SIMDE_FLOAT32_C(   318.48), SIMDE_FLOAT32_C(  -112.31), SIMDE_FLOAT32_C(   847.99), SIMDE_FLOAT32_C(  -284.80),
        SIMDE_FLOAT32_C(  -860.19), SIMDE_FLOAT32_C(  -314.45), SIMDE_FLOAT32_C(  -193.84), SIMDE_FLOAT32_C(  -385.00),
        SIMDE_FLOAT32_C(   503.38), SIMDE_FLOAT32_C(  -543.86), SIMDE_FLOAT32_C(   367.57), SIMDE_FLOAT32_C(  -848.04),
        SIMDE_FLOAT32_C(   876.46), SIMDE_FLOAT32_C(    93.82), SIMDE_FLOAT32_C(  -273.70), SIMDE_FLOAT32_C(   395.80) },
      UINT8_C( 50),
      { SIMDE_FLOAT32_C(  -599.48),      SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(   278.64), SIMDE_FLOAT32_C(   370.22),
        SIMDE_FLOAT32_C(  -741.66), SIMDE_FLOAT32_C(   -83.17), SIMDE_FLOAT32_C(  -919.22), SIMDE_FLOAT32_C(   903.16),
        SIMDE_FLOAT32_C(  -128.69), SIMDE_FLOAT32_C(  -750.19), SIMDE_FLOAT32_C(   954.39), SIMDE_FLOAT32_C(  -740.23),
        SIMDE_FLOAT32_C(   926.06), SIMDE_FLOAT32_C(  -742.65), SIMDE_FLOAT32_C(   578.25), SIMDE_FLOAT32_C(  -186.24) },
       INT32_C(         177),
       INT32_C(           4),
      { SIMDE_FLOAT32_C(   318.48),      SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(   847.99), SIMDE_FLOAT32_C(  -284.80),
        SIMDE_FLOAT32_C(  -741.66), SIMDE_FLOAT32_C(   -83.17), SIMDE_FLOAT32_C(  -193.84), SIMDE_FLOAT32_C(  -385.00),
        SIMDE_FLOAT32_C(   503.38), SIMDE_FLOAT32_C(  -543.86), SIMDE_FLOAT32_C(   367.57), SIMDE_FLOAT32_C(  -848.04),
        SIMDE_FLOAT32_C(   876.46), SIMDE_FLOAT32_C(    93.82), SIMDE_FLOAT32_C(  -273.70), SIMDE_FLOAT32_C(   395.80) } },
    { { SIMDE_FLOAT32_C(   568.56), SIMDE_FLOAT32_C(  -705.73), SIMDE_FLOAT32_C(   555.76), SIMDE_FLOAT32_C(   -63.87),
        SIMDE_FLOAT32_C(  -553.77), SIMDE_FLOAT32_C(   432.21), SIMDE_FLOAT32_C(  -970.05), SIMDE_FLOAT32_C(   172.53),
        SIMDE_FLOAT32_C(  -171.99), SIMDE_FLOAT32_C(  -463.06), SIMDE_FLOAT32_C(   573.05), SIMDE_FLOAT32_C(  -122.01),
        SIMDE_FLOAT32_C(   815.58), SIMDE_FLOAT32_C(   -56.73), SIMDE_FLOAT32_C(   136.33), SIMDE_FLOAT32_C(  -267.59) },
      UINT8_C( 31),
      {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(   603.72), SIMDE_FLOAT32_C(   273.86), SIMDE_FLOAT32_C(    -6.12),
        SIMDE_FLOAT32_C(   863.49), SIMDE_FLOAT32_C(   199.92), SIMDE_FLOAT32_C(   251.23), SIMDE_FLOAT32_C(   441.74),
        SIMDE_FLOAT32_C(  -986.32), SIMDE_FLOAT32_C(   356.57), SIMDE_FLOAT32_C(   735.19), SIMDE_FLOAT32_C(   -32.75),
        SIMDE_FLOAT32_C(  -852.54), SIMDE_FLOAT32_C(  -165.20), SIMDE_FLOAT32_C(  -464.19), SIMDE_FLOAT32_C(  -558.27) },
       INT32_C(         242),
       INT32_C(           4),
      {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(   603.72), SIMDE_FLOAT32_C(   273.86), SIMDE_FLOAT32_C(    -6.12),
        SIMDE_FLOAT32_C(   863.49), SIMDE_FLOAT32_C(   432.21), SIMDE_FLOAT32_C(  -970.05), SIMDE_FLOAT32_C(   172.53),
        SIMDE_FLOAT32_C(  -171.99), SIMDE_FLOAT32_C(  -463.06), SIMDE_FLOAT32_C(   573.05), SIMDE_FLOAT32_C(  -122.01),
        SIMDE_FLOAT32_C(   815.58), SIMDE_FLOAT32_C(   -56.73), SIMDE_FLOAT32_C(   136.33), SIMDE_FLOAT32_C(  -267.59) } },
    { { SIMDE_FLOAT32_C(   501.88), SIMDE_FLOAT32_C(  -939.52), SIMDE_FLOAT32_C(  -349.21), SIMDE_FLOAT32_C(  -961.18),
        SIMDE_FLOAT32_C(   633.53), SIMDE_FLOAT32_C(   528.78), SIMDE_FLOAT32_C(   854.40), SIMDE_FLOAT32_C(  -423.20),
        SIMDE_FLOAT32_C(  -334.89), SIMDE_FLOAT32_C(  -413.19), SIMDE_FLOAT32_C(   600.85), SIMDE_FLOAT32_C(   704.60),
        SIMDE_FLOAT32_C(  -809.47), SIMDE_FLOAT32_C(  -125.29), SIMDE_FLOAT32_C(  -301.53), SIMDE_FLOAT32_C(  -945.98) },
      UINT8_C(138),
      { SIMDE_FLOAT32_C(   949.70), SIMDE_FLOAT32_C(   495.77), SIMDE_FLOAT32_C(  -911.69), SIMDE_FLOAT32_C(   306.27),
        SIMDE_FLOAT32_C(   230.96), SIMDE_FLOAT32_C(    55.56), SIMDE_FLOAT32_C(   453.73), SIMDE_FLOAT32_C(  -934.24),
        SIMDE_FLOAT32_C(   591.37), SIMDE_FLOAT32_C(   895.45), SIMDE_FLOAT32_C(  -543.68), SIMDE_FLOAT32_C(    63.30),
        SIMDE_FLOAT32_C(  -216.59), SIMDE_FLOAT32_C(  -720.90), SIMDE_FLOAT32_C(  -434.81), SIMDE_FLOAT32_C(  -156.11) },
       INT32_C(          83),
       INT32_C(           4),
      { SIMDE_FLOAT32_C(   501.88), SIMDE_FLOAT32_C(   495.75), SIMDE_FLOAT32_C(  -349.21), SIMDE_FLOAT32_C(   306.25),
        SIMDE_FLOAT32_C(   633.53), SIMDE_FLOAT32_C(   528.78), SIMDE_FLOAT32_C(   854.40), SIMDE_FLOAT32_C(  -934.22),
        SIMDE_FLOAT32_C(  -334.89), SIMDE_FLOAT32_C(  -413.19), SIMDE_FLOAT32_C(   600.85), SIMDE_FLOAT32_C(   704.60),
        SIMDE_FLOAT32_C(  -809.47), SIMDE_FLOAT32_C(  -125.29), SIMDE_FLOAT32_C(  -301.53), SIMDE_FLOAT32_C(  -945.98) } },
    { { SIMDE_FLOAT32_C(  -541.34), SIMDE_FLOAT32_C(  -541.59), SIMDE_FLOAT32_C(    54.22), SIMDE_FLOAT32_C(   123.77),
        SIMDE_FLOAT32_C(    45.22), SIMDE_FLOAT32_C(  -344.93), SIMDE_FLOAT32_C(  -171.63), SIMDE_FLOAT32_C(   235.75),
        SIMDE_FLOAT32_C(   529.78), SIMDE_FLOAT32_C(   526.84), SIMDE_FLOAT32_C(   289.78), SIMDE_FLOAT32_C(   604.42),
        SIMDE_FLOAT32_C(   476.54), SIMDE_FLOAT32_C(  -214.46), SIMDE_FLOAT32_C(   692.73), SIMDE_FLOAT32_C(  -217.19) },
      UINT8_C(173),
      {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(  -763.46), SIMDE_FLOAT32_C(  -917.74), SIMDE_FLOAT32_C(  -660.34),
        SIMDE_FLOAT32_C(  -868.01), SIMDE_FLOAT32_C(  -461.42), SIMDE_FLOAT32_C(   402.96), SIMDE_FLOAT32_C(   -84.60),
        SIMDE_FLOAT32_C(  -182.32), SIMDE_FLOAT32_C(   968.15), SIMDE_FLOAT32_C(   759.29), SIMDE_FLOAT32_C(   747.56),
        SIMDE_FLOAT32_C(  -427.84), SIMDE_FLOAT32_C(  -763.29), SIMDE_FLOAT32_C(  -793.77), SIMDE_FLOAT32_C(    30.57) },
       INT32_C(         100),
       INT32_C(           4),
      {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(  -541.59), SIMDE_FLOAT32_C(  -917.73), SIMDE_FLOAT32_C(  -660.34),
        SIMDE_FLOAT32_C(    45.22), SIMDE_FLOAT32_C(  -461.42), SIMDE_FLOAT32_C(  -171.63), SIMDE_FLOAT32_C(   -84.59),
        SIMDE_FLOAT32_C(   529.78), SIMDE_FLOAT32_C(   526.84), SIMDE_FLOAT32_C(   289.78), SIMDE_FLOAT32_C(   604.42),
        SIMDE_FLOAT32_C(   476.54), SIMDE_FLOAT32_C(  -214.46), SIMDE_FLOAT32_C(   692.73), SIMDE_FLOAT32_C(  -217.19) } },
    { { SIMDE_FLOAT32_C(  -841.63), SIMDE_FLOAT32_C(   311.54), SIMDE_FLOAT32_C(   475.79), SIMDE_FLOAT32_C(   685.21),
        SIMDE_FLOAT32_C(  -398.68), SIMDE_FLOAT32_C(    80.21), SIMDE_FLOAT32_C(   161.75), SIMDE_FLOAT32_C(   386.86),
        SIMDE_FLOAT32_C(  -227.06), SIMDE_FLOAT32_C(   944.56), SIMDE_FLOAT32_C(   403.36), SIMDE_FLOAT32_C(   521.23),
        SIMDE_FLOAT32_C(  -818.90), SIMDE_FLOAT32_C(   485.62), SIMDE_FLOAT32_C(   860.89), SIMDE_FLOAT32_C(  -686.90) },
      UINT8_C( 71),
      { SIMDE_FLOAT32_C(   263.85),      SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(  -158.11), SIMDE_FLOAT32_C(   231.99),
        SIMDE_FLOAT32_C(   -12.21), SIMDE_FLOAT32_C(  -410.55), SIMDE_FLOAT32_C(   804.15), SIMDE_FLOAT32_C(   224.51),
        SIMDE_FLOAT32_C(  -204.32), SIMDE_FLOAT32_C(  -165.28), SIMDE_FLOAT32_C(  -484.56), SIMDE_FLOAT32_C(  -874.32),
        SIMDE_FLOAT32_C(   -89.50), SIMDE_FLOAT32_C(  -538.55), SIMDE_FLOAT32_C(  -715.95), SIMDE_FLOAT32_C(  -777.95) },
       INT32_C(         240),
       INT32_C(           4),
      { SIMDE_FLOAT32_C(   263.85),      SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(  -158.11), SIMDE_FLOAT32_C(   685.21),
        SIMDE_FLOAT32_C(  -398.68), SIMDE_FLOAT32_C(    80.21), SIMDE_FLOAT32_C(   804.15), SIMDE_FLOAT32_C(   386.86),
        SIMDE_FLOAT32_C(  -227.06), SIMDE_FLOAT32_C(   944.56), SIMDE_FLOAT32_C(   403.36), SIMDE_FLOAT32_C(   521.23),
        SIMDE_FLOAT32_C(  -818.90), SIMDE_FLOAT32_C(   485.62), SIMDE_FLOAT32_C(   860.89), SIMDE_FLOAT32_C(  -686.90) } },
    { { SIMDE_FLOAT32_C(  -789.77), SIMDE_FLOAT32_C(   790.38), SIMDE_FLOAT32_C(    75.57), SIMDE_FLOAT32_C(   613.60),
        SIMDE_FLOAT32_C(   311.61), SIMDE_FLOAT32_C(   256.68), SIMDE_FLOAT32_C(    99.22), SIMDE_FLOAT32_C(   172.50),
        SIMDE_FLOAT32_C(   569.77), SIMDE_FLOAT32_C(   123.43), SIMDE_FLOAT32_C(  -563.65), SIMDE_FLOAT32_C(  -201.73),
        SIMDE_FLOAT32_C(   965.31), SIMDE_FLOAT32_C(   668.34), SIMDE_FLOAT32_C(   786.06), SIMDE_FLOAT32_C(  -445.24) },
      UINT8_C( 96),
      { SIMDE_FLOAT32_C(    10.57), SIMDE_FLOAT32_C(   350.44), SIMDE_FLOAT32_C(  -692.79), SIMDE_FLOAT32_C(   526.01),
        SIMDE_FLOAT32_C(   476.12), SIMDE_FLOAT32_C(   217.72), SIMDE_FLOAT32_C(   987.46), SIMDE_FLOAT32_C(   760.17),
        SIMDE_FLOAT32_C(   439.76), SIMDE_FLOAT32_C(   924.70), SIMDE_FLOAT32_C(   729.42), SIMDE_FLOAT32_C(  -736.87),
        SIMDE_FLOAT32_C(   -57.85), SIMDE_FLOAT32_C(  -139.57), SIMDE_FLOAT32_C(  -526.64), SIMDE_FLOAT32_C(  -267.47) },
       INT32_C(          33),
       INT32_C(           8),
      { SIMDE_FLOAT32_C(  -789.77), SIMDE_FLOAT32_C(   790.38), SIMDE_FLOAT32_C(    75.57), SIMDE_FLOAT32_C(   613.60),
        SIMDE_FLOAT32_C(   311.61), SIMDE_FLOAT32_C(   217.50), SIMDE_FLOAT32_C(   987.25), SIMDE_FLOAT32_C(   172.50),
        SIMDE_FLOAT32_C(   569.77), SIMDE_FLOAT32_C(   123.43), SIMDE_FLOAT32_C(  -563.65), SIMDE_FLOAT32_C(  -201.73),
        SIMDE_FLOAT32_C(   965.31), SIMDE_FLOAT32_C(   668.34), SIMDE_FLOAT32_C(   786.06), SIMDE_FLOAT32_C(  -445.24) } },
    { { SIMDE_FLOAT32_C(   192.68), SIMDE_FLOAT32_C(   186.18), SIMDE_FLOAT32_C(   216.65), SIMDE_FLOAT32_C(  -237.55),
        SIMDE_FLOAT32_C(  -690.39), SIMDE_FLOAT32_C(   653.00), SIMDE_FLOAT32_C(   560.73), SIMDE_FLOAT32_C(  -725.08),
        SIMDE_FLOAT32_C(   321.34), SIMDE_FLOAT32_C(   346.79), SIMDE_FLOAT32_C(  -170.31), SIMDE_FLOAT32_C(  -206.17),
        SIMDE_FLOAT32_C(  -642.64), SIMDE_FLOAT32_C(  -819.87), SIMDE_FLOAT32_C(   101.05), SIMDE_FLOAT32_C(   883.37) },
      UINT8_C(188),
      {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(   870.84), SIMDE_FLOAT32_C(   416.42), SIMDE_FLOAT32_C(   758.53),
        SIMDE_FLOAT32_C(   795.54), SIMDE_FLOAT32_C(   145.85), SIMDE_FLOAT32_C(  -978.34), SIMDE_FLOAT32_C(  -262.31),
        SIMDE_FLOAT32_C(  -993.72), SIMDE_FLOAT32_C(  -504.98), SIMDE_FLOAT32_C(   470.22), SIMDE_FLOAT32_C(   942.28),
        SIMDE_FLOAT32_C(  -418.02), SIMDE_FLOAT32_C(   514.37), SIMDE_FLOAT32_C(   134.96), SIMDE_FLOAT32_C(   768.16) },
       INT32_C(          66),
       INT32_C(           8),
      { SIMDE_FLOAT32_C(   192.68), SIMDE_FLOAT32_C(   186.18), SIMDE_FLOAT32_C(   416.44), SIMDE_FLOAT32_C(   758.56),
        SIMDE_FLOAT32_C(   795.56), SIMDE_FLOAT32_C(   145.88), SIMDE_FLOAT32_C(   560.73), SIMDE_FLOAT32_C(  -262.25),
        SIMDE_FLOAT32_C(   321.34), SIMDE_FLOAT32_C(   346.79), SIMDE_FLOAT32_C(  -170.31), SIMDE_FLOAT32_C(  -206.17),
        SIMDE_FLOAT32_C(  -642.64), SIMDE_FLOAT32_C(  -819.87), SIMDE_FLOAT32_C(   101.05), SIMDE_FLOAT32_C(   883.37) } },
  };

  simde__m512 src, a, r;

  src = simde_mm512_loadu_ps(test_vec[0].src);
  a = simde_mm512_loadu_ps(test_vec[0].a);
  r = simde_mm512_mask_roundscale_round_ps(src, test_vec[0].k, a, INT32_C(          64), INT32_C(           4));
  simde_test_x86_assert_equal_f32x16(r, simde_mm512_loadu_ps(test_vec[0].r), 1);

  src = simde_mm512_loadu_ps(test_vec[1].src);
  a = simde_mm512_loadu_ps(test_vec[1].a);
  r = simde_mm512_mask_roundscale_round_ps(src, test_vec[1].k, a, INT32_C(         177), INT32_C(           4));
  simde_test_x86_assert_equal_f32x16(r, simde_mm512_loadu_ps(test_vec[1].r), 1);

  src = simde_mm512_loadu_ps(test_vec[2].src);
  a = simde_mm512_loadu_ps(test_vec[2].a);
  r = simde_mm512_mask_roundscale_round_ps(src, test_vec[2].k, a, INT32_C(         242), INT32_C(           4));
  simde_test_x86_assert_equal_f32x16(r, simde_mm512_loadu_ps(test_vec[2].r), 1);

  src = simde_mm512_loadu_ps(test_vec[3].src);
  a = simde_mm512_loadu_ps(test_vec[3].a);
  r = simde_mm512_mask_roundscale_round_ps(src, test_vec[3].k, a, INT32_C(          83), INT32_C(           4));
  simde_test_x86_assert_equal_f32x16(r, simde_mm512_loadu_ps(test_vec[3].r), 1);

  src = simde_mm512_loadu_ps(test_vec[4].src);
  a = simde_mm512_loadu_ps(test_vec[4].a);
  r = simde_mm512_mask_roundscale_round_ps(src, test_vec[4].k, a, INT32_C(         100), INT32_C(           4));
  simde_test_x86_assert_equal_f32x16(r, simde_mm512_loadu_ps(test_vec[4].r), 1);

  src = simde_mm512_loadu_ps(test_vec[5].src);
  a = simde_mm512_loadu_ps(test_vec[5].a);
  r = simde_mm512_mask_roundscale_round_ps(src, test_vec[5].k, a, INT32_C(         240), INT32_C(           4));
  simde_test_x86_assert_equal_f32x16(r, simde_mm512_loadu_ps(test_vec[5].r), 1);

  src = simde_mm512_loadu_ps(test_vec[6].src);
  a = simde_mm512_loadu_ps(test_vec[6].a);
  r = simde_mm512_mask_roundscale_round_ps(src, test_vec[6].k, a, INT32_C(          33), INT32_C(           8));
  simde_test_x86_assert_equal_f32x16(r, simde_mm512_loadu_ps(test_vec[6].r), 1);

  src = simde_mm512_loadu_ps(test_vec[7].src);
  a = simde_mm512_loadu_ps(test_vec[7].a);
  r = simde_mm512_mask_roundscale_round_ps(src, test_vec[7].k, a, INT32_C(          66), INT32_C(           8));
  simde_test_x86_assert_equal_f32x16(r, simde_mm512_loadu_ps(test_vec[7].r), 1);

  return 0;
#else
  fputc('\n', stdout);
  int round_type[5] = {SIMDE_MM_FROUND_TO_NEAREST_INT, SIMDE_MM_FROUND_TO_NEG_INF, SIMDE_MM_FROUND_TO_POS_INF, SIMDE_MM_FROUND_TO_ZERO, SIMDE_MM_FROUND_CUR_DIRECTION};
  for (int i = 0 ; i < 8 ; i++) {
    simde__m512 src = simde_test_x86_random_f32x16(SIMDE_FLOAT32_C(-1000.0), SIMDE_FLOAT32_C(1000.0));
    simde__mmask8 k = simde_test_x86_random_mmask8();
    simde__m512 a = simde_test_x86_random_f32x16(SIMDE_FLOAT32_C(-1000.0), SIMDE_FLOAT32_C(1000.0));
    if((simde_test_codegen_rand() & 1)) {
      if((simde_test_codegen_rand() & 1))
        a = simde_mm512_mask_mov_ps(a, 1, simde_mm512_set1_ps(SIMDE_MATH_NANF));
      else {
        if((simde_test_codegen_rand() & 1))
          a = simde_mm512_mask_mov_ps(a, 2, simde_mm512_set1_ps(SIMDE_MATH_INFINITY));
        else
          a = simde_mm512_mask_mov_ps(a, 2, simde_mm512_set1_ps(-SIMDE_MATH_INFINITY));
      }
    }
    int imm8 = (((simde_test_codegen_rand() & 15) << 4) | round_type[i % 5]) & 255;
    int sae = (simde_test_codegen_rand() & 1) ? SIMDE_MM_FROUND_CUR_DIRECTION: SIMDE_MM_FROUND_NO_EXC;
    simde__m512 r;
    SIMDE_CONSTIFY_256_NEW(simde_mm512_mask_roundscale_round_ps, r, simde_mm512_setzero_ps(), imm8, sae, src, k, a);

    simde_test_x86_write_f32x16(2, src, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_mmask8(2, k, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_f32x16(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i32(2, imm8, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i32(2, sae, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_f32x16(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm512_maskz_roundscale_round_ps (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const simde__mmask8 k;
    const simde_float32 a[16];
    const int32_t imm8;
    const int32_t sae;
    const simde_float32 r[16];
  } test_vec[] = {
    { UINT8_C(117),
      { SIMDE_FLOAT32_C(  -647.31),     -SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(  -195.07), SIMDE_FLOAT32_C(   182.38),
        SIMDE_FLOAT32_C(  -500.81), SIMDE_FLOAT32_C(   162.29), SIMDE_FLOAT32_C(   362.51), SIMDE_FLOAT32_C(   600.24),
        SIMDE_FLOAT32_C(    45.66), SIMDE_FLOAT32_C(    18.76), SIMDE_FLOAT32_C(   919.00), SIMDE_FLOAT32_C(   -83.51),
        SIMDE_FLOAT32_C(  -564.82), SIMDE_FLOAT32_C(   677.53), SIMDE_FLOAT32_C(  -287.97), SIMDE_FLOAT32_C(   581.03) },
       INT32_C(         192),
       INT32_C(           4),
      { SIMDE_FLOAT32_C(  -647.31), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(  -195.07), SIMDE_FLOAT32_C(     0.00),
        SIMDE_FLOAT32_C(  -500.81), SIMDE_FLOAT32_C(   162.29), SIMDE_FLOAT32_C(   362.51), SIMDE_FLOAT32_C(     0.00),
        SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00),
        SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00) } },
    { UINT8_C( 15),
      { SIMDE_FLOAT32_C(  -223.80), SIMDE_FLOAT32_C(  -565.68), SIMDE_FLOAT32_C(  -335.46), SIMDE_FLOAT32_C(  -455.64),
        SIMDE_FLOAT32_C(   165.34), SIMDE_FLOAT32_C(  -438.04), SIMDE_FLOAT32_C(  -377.87), SIMDE_FLOAT32_C(   549.36),
        SIMDE_FLOAT32_C(  -979.91), SIMDE_FLOAT32_C(   -25.17), SIMDE_FLOAT32_C(   254.71), SIMDE_FLOAT32_C(  -174.98),
        SIMDE_FLOAT32_C(  -842.79), SIMDE_FLOAT32_C(   753.91), SIMDE_FLOAT32_C(   987.31), SIMDE_FLOAT32_C(   519.72) },
       INT32_C(          65),
       INT32_C(           4),
      { SIMDE_FLOAT32_C(  -223.81), SIMDE_FLOAT32_C(  -565.69), SIMDE_FLOAT32_C(  -335.50), SIMDE_FLOAT32_C(  -455.69),
        SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00),
        SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00),
        SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00) } },
    { UINT8_C( 49),
      { SIMDE_FLOAT32_C(   949.46), SIMDE_FLOAT32_C(   -26.34), SIMDE_FLOAT32_C(   -49.32), SIMDE_FLOAT32_C(  -338.51),
        SIMDE_FLOAT32_C(  -445.32), SIMDE_FLOAT32_C(  -350.13), SIMDE_FLOAT32_C(  -888.78), SIMDE_FLOAT32_C(  -858.02),
        SIMDE_FLOAT32_C(  -155.91), SIMDE_FLOAT32_C(    31.16), SIMDE_FLOAT32_C(   671.57), SIMDE_FLOAT32_C(   620.29),
        SIMDE_FLOAT32_C(   465.48), SIMDE_FLOAT32_C(  -663.89), SIMDE_FLOAT32_C(  -835.35), SIMDE_FLOAT32_C(  -369.18) },
       INT32_C(         226),
       INT32_C(           4),
      { SIMDE_FLOAT32_C(   949.46), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00),
        SIMDE_FLOAT32_C(  -445.32), SIMDE_FLOAT32_C(  -350.13), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00),
        SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00),
        SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00) } },
    { UINT8_C(121),
      { SIMDE_FLOAT32_C(   761.61), SIMDE_FLOAT32_C(   434.89), SIMDE_FLOAT32_C(   743.18), SIMDE_FLOAT32_C(   918.82),
        SIMDE_FLOAT32_C(   188.79), SIMDE_FLOAT32_C(   730.49), SIMDE_FLOAT32_C(   438.54), SIMDE_FLOAT32_C(  -457.06),
        SIMDE_FLOAT32_C(  -236.54), SIMDE_FLOAT32_C(   977.01), SIMDE_FLOAT32_C(   816.09), SIMDE_FLOAT32_C(  -287.08),
        SIMDE_FLOAT32_C(   -49.33), SIMDE_FLOAT32_C(  -233.23), SIMDE_FLOAT32_C(   374.41), SIMDE_FLOAT32_C(   505.35) },
       INT32_C(         147),
       INT32_C(           8),
      { SIMDE_FLOAT32_C(   761.61), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(   918.82),
        SIMDE_FLOAT32_C(   188.79), SIMDE_FLOAT32_C(   730.49), SIMDE_FLOAT32_C(   438.54), SIMDE_FLOAT32_C(     0.00),
        SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00),
        SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00) } },
    { UINT8_C( 82),
      {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(   318.90), SIMDE_FLOAT32_C(   881.02), SIMDE_FLOAT32_C(   982.27),
        SIMDE_FLOAT32_C(   655.01), SIMDE_FLOAT32_C(  -954.33), SIMDE_FLOAT32_C(  -386.91), SIMDE_FLOAT32_C(  -446.92),
        SIMDE_FLOAT32_C(  -167.55), SIMDE_FLOAT32_C(  -206.74), SIMDE_FLOAT32_C(   471.24), SIMDE_FLOAT32_C(  -405.94),
        SIMDE_FLOAT32_C(  -771.85), SIMDE_FLOAT32_C(   214.42), SIMDE_FLOAT32_C(  -487.12), SIMDE_FLOAT32_C(   416.95) },
       INT32_C(         180),
       INT32_C(           4),
      { SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(   318.90), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00),
        SIMDE_FLOAT32_C(   655.01), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(  -386.91), SIMDE_FLOAT32_C(     0.00),
        SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00),
        SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00) } },
    { UINT8_C(134),
      { SIMDE_FLOAT32_C(   775.97), SIMDE_FLOAT32_C(  -578.72), SIMDE_FLOAT32_C(  -120.90), SIMDE_FLOAT32_C(  -457.26),
        SIMDE_FLOAT32_C(   795.69), SIMDE_FLOAT32_C(  -615.55), SIMDE_FLOAT32_C(   959.38), SIMDE_FLOAT32_C(   281.32),
        SIMDE_FLOAT32_C(  -968.22), SIMDE_FLOAT32_C(  -779.89), SIMDE_FLOAT32_C(   798.10), SIMDE_FLOAT32_C(   350.68),
        SIMDE_FLOAT32_C(  -898.87), SIMDE_FLOAT32_C(   780.37), SIMDE_FLOAT32_C(     5.70), SIMDE_FLOAT32_C(  -853.21) },
       INT32_C(         128),
       INT32_C(           4),
      { SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(  -578.72), SIMDE_FLOAT32_C(  -120.90), SIMDE_FLOAT32_C(     0.00),
        SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(   281.32),
        SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00),
        SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00) } },
    { UINT8_C(160),
      { SIMDE_FLOAT32_C(    30.02), SIMDE_FLOAT32_C(   573.31), SIMDE_FLOAT32_C(   414.88), SIMDE_FLOAT32_C(  -755.56),
        SIMDE_FLOAT32_C(  -913.81), SIMDE_FLOAT32_C(  -168.18), SIMDE_FLOAT32_C(   189.35), SIMDE_FLOAT32_C(  -962.39),
        SIMDE_FLOAT32_C(  -208.29), SIMDE_FLOAT32_C(  -102.29), SIMDE_FLOAT32_C(   966.04), SIMDE_FLOAT32_C(  -432.32),
        SIMDE_FLOAT32_C(   318.99), SIMDE_FLOAT32_C(  -154.87), SIMDE_FLOAT32_C(   110.42), SIMDE_FLOAT32_C(   114.68) },
       INT32_C(          65),
       INT32_C(           4),
      { SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00),
        SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(  -168.19), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(  -962.44),
        SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00),
        SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00) } },
    { UINT8_C(113),
      { SIMDE_FLOAT32_C(   289.91),      SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(  -387.95), SIMDE_FLOAT32_C(   391.04),
        SIMDE_FLOAT32_C(   974.47), SIMDE_FLOAT32_C(   617.75), SIMDE_FLOAT32_C(   537.83), SIMDE_FLOAT32_C(  -632.07),
        SIMDE_FLOAT32_C(   176.52), SIMDE_FLOAT32_C(  -482.92), SIMDE_FLOAT32_C(   554.66), SIMDE_FLOAT32_C(  -793.46),
        SIMDE_FLOAT32_C(  -909.62), SIMDE_FLOAT32_C(   -30.47), SIMDE_FLOAT32_C(  -549.02), SIMDE_FLOAT32_C(  -823.43) },
       INT32_C(         130),
       INT32_C(           4),
      { SIMDE_FLOAT32_C(   289.91), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00),
        SIMDE_FLOAT32_C(   974.47), SIMDE_FLOAT32_C(   617.75), SIMDE_FLOAT32_C(   537.83), SIMDE_FLOAT32_C(     0.00),
        SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00),
        SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00) } },
  };

  simde__m512 a, r;

  a = simde_mm512_loadu_ps(test_vec[0].a);
  r = simde_mm512_maskz_roundscale_round_ps(test_vec[0].k, a, INT32_C(         192), INT32_C(           4));
  simde_test_x86_assert_equal_f32x16(r, simde_mm512_loadu_ps(test_vec[0].r), 1);

  a = simde_mm512_loadu_ps(test_vec[1].a);
  r = simde_mm512_maskz_roundscale_round_ps(test_vec[1].k, a, INT32_C(          65), INT32_C(           4));
  simde_test_x86_assert_equal_f32x16(r, simde_mm512_loadu_ps(test_vec[1].r), 1);

  a = simde_mm512_loadu_ps(test_vec[2].a);
  r = simde_mm512_maskz_roundscale_round_ps(test_vec[2].k, a, INT32_C(         226), INT32_C(           4));
  simde_test_x86_assert_equal_f32x16(r, simde_mm512_loadu_ps(test_vec[2].r), 1);

  a = simde_mm512_loadu_ps(test_vec[3].a);
  r = simde_mm512_maskz_roundscale_round_ps(test_vec[3].k, a, INT32_C(         147), INT32_C(           8));
  simde_test_x86_assert_equal_f32x16(r, simde_mm512_loadu_ps(test_vec[3].r), 1);

  a = simde_mm512_loadu_ps(test_vec[4].a);
  r = simde_mm512_maskz_roundscale_round_ps(test_vec[4].k, a, INT32_C(         180), INT32_C(           4));
  simde_test_x86_assert_equal_f32x16(r, simde_mm512_loadu_ps(test_vec[4].r), 1);

  a = simde_mm512_loadu_ps(test_vec[5].a);
  r = simde_mm512_maskz_roundscale_round_ps(test_vec[5].k, a, INT32_C(         128), INT32_C(           4));
  simde_test_x86_assert_equal_f32x16(r, simde_mm512_loadu_ps(test_vec[5].r), 1);

  a = simde_mm512_loadu_ps(test_vec[6].a);
  r = simde_mm512_maskz_roundscale_round_ps(test_vec[6].k, a, INT32_C(          65), INT32_C(           4));
  simde_test_x86_assert_equal_f32x16(r, simde_mm512_loadu_ps(test_vec[6].r), 1);

  a = simde_mm512_loadu_ps(test_vec[7].a);
  r = simde_mm512_maskz_roundscale_round_ps(test_vec[7].k, a, INT32_C(         130), INT32_C(           4));
  simde_test_x86_assert_equal_f32x16(r, simde_mm512_loadu_ps(test_vec[7].r), 1);

  return 0;
#else
  fputc('\n', stdout);
  int round_type[5] = {SIMDE_MM_FROUND_TO_NEAREST_INT, SIMDE_MM_FROUND_TO_NEG_INF, SIMDE_MM_FROUND_TO_POS_INF, SIMDE_MM_FROUND_TO_ZERO, SIMDE_MM_FROUND_CUR_DIRECTION};
  for (int i = 0 ; i < 8 ; i++) {
    simde__mmask8 k = simde_test_x86_random_mmask8();
    simde__m512 a = simde_test_x86_random_f32x16(SIMDE_FLOAT32_C(-1000.0), SIMDE_FLOAT32_C(1000.0));
    if((simde_test_codegen_rand() & 1)) {
      if((simde_test_codegen_rand() & 1))
        a = simde_mm512_mask_mov_ps(a, 1, simde_mm512_set1_ps(SIMDE_MATH_NANF));
      else {
        if((simde_test_codegen_rand() & 1))
          a = simde_mm512_mask_mov_ps(a, 2, simde_mm512_set1_ps(SIMDE_MATH_INFINITY));
        else
          a = simde_mm512_mask_mov_ps(a, 2, simde_mm512_set1_ps(-SIMDE_MATH_INFINITY));
      }
    }
    int imm8 = (((simde_test_codegen_rand() & 15) << 4) | round_type[i % 5]) & 255;
    int sae = (simde_test_codegen_rand() & 1) ? SIMDE_MM_FROUND_CUR_DIRECTION: SIMDE_MM_FROUND_NO_EXC;
    simde__m512 r;
    SIMDE_CONSTIFY_256_NEW(simde_mm512_maskz_roundscale_round_ps, r, simde_mm512_setzero_ps(), imm8, sae, k, a);

    simde_test_x86_write_mmask8(2, k, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_f32x16(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i32(2, imm8, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i32(2, sae, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_f32x16(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm_roundscale_pd (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const simde_float64 a[2];
    const int imm8;
    const simde_float64 r[2];
  } test_vec[] = {
    { { SIMDE_FLOAT64_C(   785.09), SIMDE_FLOAT64_C(  -944.62) },
       INT32_C(           0),
      { SIMDE_FLOAT64_C(   785.00), SIMDE_FLOAT64_C(  -945.00) } },
    { {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(   918.83) },
       INT32_C(          16),
      {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(   919.00) } },
    { {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(   618.81) },
       INT32_C(          32),
      {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(   618.75) } },
    { { SIMDE_FLOAT64_C(  -164.68),        SIMDE_MATH_INFINITY },
       INT32_C(          48),
      { SIMDE_FLOAT64_C(  -164.62),        SIMDE_MATH_INFINITY } },
    { {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(  -996.38) },
       INT32_C(          64),
      {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(  -996.38) } },
    { {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(  -175.51) },
       INT32_C(          80),
      {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(  -175.50) } },
    { { SIMDE_FLOAT64_C(  -402.63), SIMDE_FLOAT64_C(   984.31) },
       INT32_C(          96),
      { SIMDE_FLOAT64_C(  -402.62), SIMDE_FLOAT64_C(   984.31) } },
    { { SIMDE_FLOAT64_C(  -217.00),        SIMDE_MATH_INFINITY },
       INT32_C(         112),
      { SIMDE_FLOAT64_C(  -217.00),        SIMDE_MATH_INFINITY } },
    { { SIMDE_FLOAT64_C(    86.63),       -SIMDE_MATH_INFINITY },
       INT32_C(         128),
      { SIMDE_FLOAT64_C(    86.63),       -SIMDE_MATH_INFINITY } },
    { {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(  -856.07) },
       INT32_C(         144),
      {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(  -856.07) } },
    { { SIMDE_FLOAT64_C(   795.64), SIMDE_FLOAT64_C(  -688.17) },
       INT32_C(         160),
      { SIMDE_FLOAT64_C(   795.64), SIMDE_FLOAT64_C(  -688.17) } },
    { {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(    64.12) },
       INT32_C(         176),
      {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(    64.12) } },
    { { SIMDE_FLOAT64_C(    67.73), SIMDE_FLOAT64_C(   167.14) },
       INT32_C(         192),
      { SIMDE_FLOAT64_C(    67.73), SIMDE_FLOAT64_C(   167.14) } },
    { {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(   991.63) },
       INT32_C(         208),
      {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(   991.63) } },
    { { SIMDE_FLOAT64_C(  -411.00),       -SIMDE_MATH_INFINITY },
       INT32_C(         224),
      { SIMDE_FLOAT64_C(  -411.00),       -SIMDE_MATH_INFINITY } },
    { {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(  -456.55) },
       INT32_C(         240),
      {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(  -456.55) } },
    { { SIMDE_FLOAT64_C(  -471.12), SIMDE_FLOAT64_C(  -358.30) },
       INT32_C(           1),
      { SIMDE_FLOAT64_C(  -472.00), SIMDE_FLOAT64_C(  -359.00) } },
    { {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(  -805.94) },
       INT32_C(          17),
      {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(  -806.00) } },
    { { SIMDE_FLOAT64_C(   979.16),       -SIMDE_MATH_INFINITY },
       INT32_C(          33),
      { SIMDE_FLOAT64_C(   979.00),       -SIMDE_MATH_INFINITY } },
    { {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(   130.56) },
       INT32_C(          49),
      {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(   130.50) } },
    { { SIMDE_FLOAT64_C(  -702.31),       -SIMDE_MATH_INFINITY },
       INT32_C(          65),
      { SIMDE_FLOAT64_C(  -702.31),       -SIMDE_MATH_INFINITY } },
    { {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(  -121.68) },
       INT32_C(          81),
      {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(  -121.69) } },
    { {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(   346.29) },
       INT32_C(          97),
      {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(   346.28) } },
    { {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(    41.41) },
       INT32_C(         113),
      {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(    41.41) } },
    { { SIMDE_FLOAT64_C(  -907.56), SIMDE_FLOAT64_C(   709.24) },
       INT32_C(         129),
      { SIMDE_FLOAT64_C(  -907.56), SIMDE_FLOAT64_C(   709.24) } },
    { { SIMDE_FLOAT64_C(   287.39), SIMDE_FLOAT64_C(   572.34) },
       INT32_C(         145),
      { SIMDE_FLOAT64_C(   287.39), SIMDE_FLOAT64_C(   572.34) } },
    { { SIMDE_FLOAT64_C(  -722.01), SIMDE_FLOAT64_C(   747.27) },
       INT32_C(         161),
      { SIMDE_FLOAT64_C(  -722.01), SIMDE_FLOAT64_C(   747.27) } },
    { {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(   -13.68) },
       INT32_C(         177),
      {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(   -13.68) } },
    { { SIMDE_FLOAT64_C(   293.11), SIMDE_FLOAT64_C(   430.09) },
       INT32_C(         193),
      { SIMDE_FLOAT64_C(   293.11), SIMDE_FLOAT64_C(   430.09) } },
    { { SIMDE_FLOAT64_C(    32.05), SIMDE_FLOAT64_C(   719.42) },
       INT32_C(         209),
      { SIMDE_FLOAT64_C(    32.05), SIMDE_FLOAT64_C(   719.42) } },
    { { SIMDE_FLOAT64_C(   141.27),       -SIMDE_MATH_INFINITY },
       INT32_C(         225),
      { SIMDE_FLOAT64_C(   141.27),       -SIMDE_MATH_INFINITY } },
    { {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(  -825.97) },
       INT32_C(         241),
      {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(  -825.97) } },
    { { SIMDE_FLOAT64_C(   215.44),        SIMDE_MATH_INFINITY },
       INT32_C(           2),
      { SIMDE_FLOAT64_C(   216.00),        SIMDE_MATH_INFINITY } },
    { { SIMDE_FLOAT64_C(   -89.17), SIMDE_FLOAT64_C(  -404.73) },
       INT32_C(          18),
      { SIMDE_FLOAT64_C(   -89.00), SIMDE_FLOAT64_C(  -404.50) } },
    { {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(  -126.74) },
       INT32_C(          34),
      {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(  -126.50) } },
    { { SIMDE_FLOAT64_C(   722.04), SIMDE_FLOAT64_C(   -20.34) },
       INT32_C(          50),
      { SIMDE_FLOAT64_C(   722.12), SIMDE_FLOAT64_C(   -20.25) } },
    { { SIMDE_FLOAT64_C(  -225.17), SIMDE_FLOAT64_C(  -727.23) },
       INT32_C(          66),
      { SIMDE_FLOAT64_C(  -225.12), SIMDE_FLOAT64_C(  -727.19) } },
    { {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(   304.82) },
       INT32_C(          82),
      {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(   304.84) } },
    { { SIMDE_FLOAT64_C(  -553.91), SIMDE_FLOAT64_C(   146.57) },
       INT32_C(          98),
      { SIMDE_FLOAT64_C(  -553.91), SIMDE_FLOAT64_C(   146.58) } },
    { { SIMDE_FLOAT64_C(   624.27), SIMDE_FLOAT64_C(   994.64) },
       INT32_C(         114),
      { SIMDE_FLOAT64_C(   624.27), SIMDE_FLOAT64_C(   994.64) } },
    { { SIMDE_FLOAT64_C(   798.30), SIMDE_FLOAT64_C(   636.47) },
       INT32_C(         130),
      { SIMDE_FLOAT64_C(   798.30), SIMDE_FLOAT64_C(   636.47) } },
    { { SIMDE_FLOAT64_C(    13.74),        SIMDE_MATH_INFINITY },
       INT32_C(         146),
      { SIMDE_FLOAT64_C(    13.74),        SIMDE_MATH_INFINITY } },
    { { SIMDE_FLOAT64_C(  -742.07), SIMDE_FLOAT64_C(   -83.10) },
       INT32_C(         162),
      { SIMDE_FLOAT64_C(  -742.07), SIMDE_FLOAT64_C(   -83.10) } },
    { { SIMDE_FLOAT64_C(  -476.98),       -SIMDE_MATH_INFINITY },
       INT32_C(         178),
      { SIMDE_FLOAT64_C(  -476.98),       -SIMDE_MATH_INFINITY } },
    { { SIMDE_FLOAT64_C(  -506.27),       -SIMDE_MATH_INFINITY },
       INT32_C(         194),
      { SIMDE_FLOAT64_C(  -506.27),       -SIMDE_MATH_INFINITY } },
    { {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(  -928.68) },
       INT32_C(         210),
      {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(  -928.68) } },
    { {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(  -285.92) },
       INT32_C(         226),
      {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(  -285.92) } },
    { { SIMDE_FLOAT64_C(  -291.28), SIMDE_FLOAT64_C(   625.24) },
       INT32_C(         242),
      { SIMDE_FLOAT64_C(  -291.28), SIMDE_FLOAT64_C(   625.24) } },
    { { SIMDE_FLOAT64_C(  -654.81), SIMDE_FLOAT64_C(   436.59) },
       INT32_C(           3),
      { SIMDE_FLOAT64_C(  -654.00), SIMDE_FLOAT64_C(   436.00) } },
    { { SIMDE_FLOAT64_C(   -53.86), SIMDE_FLOAT64_C(  -216.31) },
       INT32_C(          19),
      { SIMDE_FLOAT64_C(   -53.50), SIMDE_FLOAT64_C(  -216.00) } },
    { { SIMDE_FLOAT64_C(  -779.18), SIMDE_FLOAT64_C(    41.62) },
       INT32_C(          35),
      { SIMDE_FLOAT64_C(  -779.00), SIMDE_FLOAT64_C(    41.50) } },
    { { SIMDE_FLOAT64_C(   741.56), SIMDE_FLOAT64_C(   564.64) },
       INT32_C(          51),
      { SIMDE_FLOAT64_C(   741.50), SIMDE_FLOAT64_C(   564.62) } },
    { { SIMDE_FLOAT64_C(   255.64), SIMDE_FLOAT64_C(  -645.42) },
       INT32_C(          67),
      { SIMDE_FLOAT64_C(   255.62), SIMDE_FLOAT64_C(  -645.38) } },
    { { SIMDE_FLOAT64_C(   749.37),       -SIMDE_MATH_INFINITY },
       INT32_C(          83),
      { SIMDE_FLOAT64_C(   749.34),       -SIMDE_MATH_INFINITY } },
    { { SIMDE_FLOAT64_C(   136.81),        SIMDE_MATH_INFINITY },
       INT32_C(          99),
      { SIMDE_FLOAT64_C(   136.80),        SIMDE_MATH_INFINITY } },
    { { SIMDE_FLOAT64_C(   844.12), SIMDE_FLOAT64_C(   832.76) },
       INT32_C(         115),
      { SIMDE_FLOAT64_C(   844.12), SIMDE_FLOAT64_C(   832.76) } },
    { { SIMDE_FLOAT64_C(  -447.16), SIMDE_FLOAT64_C(   458.00) },
       INT32_C(         131),
      { SIMDE_FLOAT64_C(  -447.16), SIMDE_FLOAT64_C(   458.00) } },
    { { SIMDE_FLOAT64_C(  -101.97), SIMDE_FLOAT64_C(  -105.41) },
       INT32_C(         147),
      { SIMDE_FLOAT64_C(  -101.97), SIMDE_FLOAT64_C(  -105.41) } },
    { { SIMDE_FLOAT64_C(   844.18), SIMDE_FLOAT64_C(   678.28) },
       INT32_C(         163),
      { SIMDE_FLOAT64_C(   844.18), SIMDE_FLOAT64_C(   678.28) } },
    { { SIMDE_FLOAT64_C(  -935.00), SIMDE_FLOAT64_C(  -280.09) },
       INT32_C(         179),
      { SIMDE_FLOAT64_C(  -935.00), SIMDE_FLOAT64_C(  -280.09) } },
    { { SIMDE_FLOAT64_C(   806.56), SIMDE_FLOAT64_C(  -715.45) },
       INT32_C(         195),
      { SIMDE_FLOAT64_C(   806.56), SIMDE_FLOAT64_C(  -715.45) } },
    { { SIMDE_FLOAT64_C(    62.19), SIMDE_FLOAT64_C(  -360.86) },
       INT32_C(         211),
      { SIMDE_FLOAT64_C(    62.19), SIMDE_FLOAT64_C(  -360.86) } },
    { {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(   182.98) },
       INT32_C(         227),
      {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(   182.98) } },
    { { SIMDE_FLOAT64_C(  -254.49), SIMDE_FLOAT64_C(  -997.08) },
       INT32_C(         243),
      { SIMDE_FLOAT64_C(  -254.49), SIMDE_FLOAT64_C(  -997.08) } },
    { {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(   667.08) },
       INT32_C(           4),
      {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(   667.00) } },
    { { SIMDE_FLOAT64_C(   499.84), SIMDE_FLOAT64_C(  -734.56) },
       INT32_C(          20),
      { SIMDE_FLOAT64_C(   500.00), SIMDE_FLOAT64_C(  -734.50) } },
    { { SIMDE_FLOAT64_C(   -42.15),        SIMDE_MATH_INFINITY },
       INT32_C(          36),
      { SIMDE_FLOAT64_C(   -42.25),        SIMDE_MATH_INFINITY } },
    { {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(   530.72) },
       INT32_C(          52),
      {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(   530.75) } },
    { { SIMDE_FLOAT64_C(  -749.37), SIMDE_FLOAT64_C(  -385.63) },
       INT32_C(          68),
      { SIMDE_FLOAT64_C(  -749.38), SIMDE_FLOAT64_C(  -385.62) } },
    { { SIMDE_FLOAT64_C(  -464.82), SIMDE_FLOAT64_C(  -795.73) },
       INT32_C(          84),
      { SIMDE_FLOAT64_C(  -464.81), SIMDE_FLOAT64_C(  -795.72) } },
    { {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(   288.75) },
       INT32_C(         100),
      {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(   288.75) } },
    { {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(  -912.54) },
       INT32_C(         116),
      {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(  -912.54) } },
    { {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(   -21.64) },
       INT32_C(         132),
      {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(   -21.64) } },
    { {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(   324.70) },
       INT32_C(         148),
      {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(   324.70) } },
    { {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(  -261.65) },
       INT32_C(         164),
      {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(  -261.65) } },
    { { SIMDE_FLOAT64_C(  -670.05),       -SIMDE_MATH_INFINITY },
       INT32_C(         180),
      { SIMDE_FLOAT64_C(  -670.05),       -SIMDE_MATH_INFINITY } },
    { { SIMDE_FLOAT64_C(   916.34), SIMDE_FLOAT64_C(   951.18) },
       INT32_C(         196),
      { SIMDE_FLOAT64_C(   916.34), SIMDE_FLOAT64_C(   951.18) } },
    { {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(  -844.55) },
       INT32_C(         212),
      {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(  -844.55) } },
    { { SIMDE_FLOAT64_C(   444.20), SIMDE_FLOAT64_C(   830.33) },
       INT32_C(         228),
      { SIMDE_FLOAT64_C(   444.20), SIMDE_FLOAT64_C(   830.33) } },
    { {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(   917.79) },
       INT32_C(         244),
      {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(   917.79) } },
  };

  simde__m128d a, r;

  a = simde_mm_loadu_pd(test_vec[0].a);
  r = simde_mm_roundscale_pd(a, INT32_C(           0));
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[0].r), 1);

  a = simde_mm_loadu_pd(test_vec[1].a);
  r = simde_mm_roundscale_pd(a, INT32_C(          16));
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[1].r), 1);

  a = simde_mm_loadu_pd(test_vec[2].a);
  r = simde_mm_roundscale_pd(a, INT32_C(          32));
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[2].r), 1);

  a = simde_mm_loadu_pd(test_vec[3].a);
  r = simde_mm_roundscale_pd(a, INT32_C(          48));
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[3].r), 1);

  a = simde_mm_loadu_pd(test_vec[4].a);
  r = simde_mm_roundscale_pd(a, INT32_C(          64));
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[4].r), 1);

  a = simde_mm_loadu_pd(test_vec[5].a);
  r = simde_mm_roundscale_pd(a, INT32_C(          80));
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[5].r), 1);

  a = simde_mm_loadu_pd(test_vec[6].a);
  r = simde_mm_roundscale_pd(a, INT32_C(          96));
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[6].r), 1);

  a = simde_mm_loadu_pd(test_vec[7].a);
  r = simde_mm_roundscale_pd(a, INT32_C(         112));
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[7].r), 1);

  a = simde_mm_loadu_pd(test_vec[8].a);
  r = simde_mm_roundscale_pd(a, INT32_C(         128));
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[8].r), 1);

  a = simde_mm_loadu_pd(test_vec[9].a);
  r = simde_mm_roundscale_pd(a, INT32_C(         144));
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[9].r), 1);

  a = simde_mm_loadu_pd(test_vec[10].a);
  r = simde_mm_roundscale_pd(a, INT32_C(         160));
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[10].r), 1);

  a = simde_mm_loadu_pd(test_vec[11].a);
  r = simde_mm_roundscale_pd(a, INT32_C(         176));
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[11].r), 1);

  a = simde_mm_loadu_pd(test_vec[12].a);
  r = simde_mm_roundscale_pd(a, INT32_C(         192));
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[12].r), 1);

  a = simde_mm_loadu_pd(test_vec[13].a);
  r = simde_mm_roundscale_pd(a, INT32_C(         208));
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[13].r), 1);

  a = simde_mm_loadu_pd(test_vec[14].a);
  r = simde_mm_roundscale_pd(a, INT32_C(         224));
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[14].r), 1);

  a = simde_mm_loadu_pd(test_vec[15].a);
  r = simde_mm_roundscale_pd(a, INT32_C(         240));
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[15].r), 1);

  a = simde_mm_loadu_pd(test_vec[16].a);
  r = simde_mm_roundscale_pd(a, INT32_C(           1));
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[16].r), 1);

  a = simde_mm_loadu_pd(test_vec[17].a);
  r = simde_mm_roundscale_pd(a, INT32_C(          17));
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[17].r), 1);

  a = simde_mm_loadu_pd(test_vec[18].a);
  r = simde_mm_roundscale_pd(a, INT32_C(          33));
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[18].r), 1);

  a = simde_mm_loadu_pd(test_vec[19].a);
  r = simde_mm_roundscale_pd(a, INT32_C(          49));
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[19].r), 1);

  a = simde_mm_loadu_pd(test_vec[20].a);
  r = simde_mm_roundscale_pd(a, INT32_C(          65));
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[20].r), 1);

  a = simde_mm_loadu_pd(test_vec[21].a);
  r = simde_mm_roundscale_pd(a, INT32_C(          81));
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[21].r), 1);

  a = simde_mm_loadu_pd(test_vec[22].a);
  r = simde_mm_roundscale_pd(a, INT32_C(          97));
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[22].r), 1);

  a = simde_mm_loadu_pd(test_vec[23].a);
  r = simde_mm_roundscale_pd(a, INT32_C(         113));
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[23].r), 1);

  a = simde_mm_loadu_pd(test_vec[24].a);
  r = simde_mm_roundscale_pd(a, INT32_C(         129));
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[24].r), 1);

  a = simde_mm_loadu_pd(test_vec[25].a);
  r = simde_mm_roundscale_pd(a, INT32_C(         145));
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[25].r), 1);

  a = simde_mm_loadu_pd(test_vec[26].a);
  r = simde_mm_roundscale_pd(a, INT32_C(         161));
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[26].r), 1);

  a = simde_mm_loadu_pd(test_vec[27].a);
  r = simde_mm_roundscale_pd(a, INT32_C(         177));
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[27].r), 1);

  a = simde_mm_loadu_pd(test_vec[28].a);
  r = simde_mm_roundscale_pd(a, INT32_C(         193));
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[28].r), 1);

  a = simde_mm_loadu_pd(test_vec[29].a);
  r = simde_mm_roundscale_pd(a, INT32_C(         209));
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[29].r), 1);

  a = simde_mm_loadu_pd(test_vec[30].a);
  r = simde_mm_roundscale_pd(a, INT32_C(         225));
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[30].r), 1);

  a = simde_mm_loadu_pd(test_vec[31].a);
  r = simde_mm_roundscale_pd(a, INT32_C(         241));
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[31].r), 1);

  a = simde_mm_loadu_pd(test_vec[32].a);
  r = simde_mm_roundscale_pd(a, INT32_C(           2));
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[32].r), 1);

  a = simde_mm_loadu_pd(test_vec[33].a);
  r = simde_mm_roundscale_pd(a, INT32_C(          18));
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[33].r), 1);

  a = simde_mm_loadu_pd(test_vec[34].a);
  r = simde_mm_roundscale_pd(a, INT32_C(          34));
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[34].r), 1);

  a = simde_mm_loadu_pd(test_vec[35].a);
  r = simde_mm_roundscale_pd(a, INT32_C(          50));
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[35].r), 1);

  a = simde_mm_loadu_pd(test_vec[36].a);
  r = simde_mm_roundscale_pd(a, INT32_C(          66));
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[36].r), 1);

  a = simde_mm_loadu_pd(test_vec[37].a);
  r = simde_mm_roundscale_pd(a, INT32_C(          82));
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[37].r), 1);

  a = simde_mm_loadu_pd(test_vec[38].a);
  r = simde_mm_roundscale_pd(a, INT32_C(          98));
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[38].r), 1);

  a = simde_mm_loadu_pd(test_vec[39].a);
  r = simde_mm_roundscale_pd(a, INT32_C(         114));
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[39].r), 1);

  a = simde_mm_loadu_pd(test_vec[40].a);
  r = simde_mm_roundscale_pd(a, INT32_C(         130));
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[40].r), 1);

  a = simde_mm_loadu_pd(test_vec[41].a);
  r = simde_mm_roundscale_pd(a, INT32_C(         146));
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[41].r), 1);

  a = simde_mm_loadu_pd(test_vec[42].a);
  r = simde_mm_roundscale_pd(a, INT32_C(         162));
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[42].r), 1);

  a = simde_mm_loadu_pd(test_vec[43].a);
  r = simde_mm_roundscale_pd(a, INT32_C(         178));
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[43].r), 1);

  a = simde_mm_loadu_pd(test_vec[44].a);
  r = simde_mm_roundscale_pd(a, INT32_C(         194));
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[44].r), 1);

  a = simde_mm_loadu_pd(test_vec[45].a);
  r = simde_mm_roundscale_pd(a, INT32_C(         210));
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[45].r), 1);

  a = simde_mm_loadu_pd(test_vec[46].a);
  r = simde_mm_roundscale_pd(a, INT32_C(         226));
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[46].r), 1);

  a = simde_mm_loadu_pd(test_vec[47].a);
  r = simde_mm_roundscale_pd(a, INT32_C(         242));
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[47].r), 1);

  a = simde_mm_loadu_pd(test_vec[48].a);
  r = simde_mm_roundscale_pd(a, INT32_C(           3));
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[48].r), 1);

  a = simde_mm_loadu_pd(test_vec[49].a);
  r = simde_mm_roundscale_pd(a, INT32_C(          19));
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[49].r), 1);

  a = simde_mm_loadu_pd(test_vec[50].a);
  r = simde_mm_roundscale_pd(a, INT32_C(          35));
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[50].r), 1);

  a = simde_mm_loadu_pd(test_vec[51].a);
  r = simde_mm_roundscale_pd(a, INT32_C(          51));
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[51].r), 1);

  a = simde_mm_loadu_pd(test_vec[52].a);
  r = simde_mm_roundscale_pd(a, INT32_C(          67));
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[52].r), 1);

  a = simde_mm_loadu_pd(test_vec[53].a);
  r = simde_mm_roundscale_pd(a, INT32_C(          83));
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[53].r), 1);

  a = simde_mm_loadu_pd(test_vec[54].a);
  r = simde_mm_roundscale_pd(a, INT32_C(          99));
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[54].r), 1);

  a = simde_mm_loadu_pd(test_vec[55].a);
  r = simde_mm_roundscale_pd(a, INT32_C(         115));
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[55].r), 1);

  a = simde_mm_loadu_pd(test_vec[56].a);
  r = simde_mm_roundscale_pd(a, INT32_C(         131));
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[56].r), 1);

  a = simde_mm_loadu_pd(test_vec[57].a);
  r = simde_mm_roundscale_pd(a, INT32_C(         147));
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[57].r), 1);

  a = simde_mm_loadu_pd(test_vec[58].a);
  r = simde_mm_roundscale_pd(a, INT32_C(         163));
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[58].r), 1);

  a = simde_mm_loadu_pd(test_vec[59].a);
  r = simde_mm_roundscale_pd(a, INT32_C(         179));
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[59].r), 1);

  a = simde_mm_loadu_pd(test_vec[60].a);
  r = simde_mm_roundscale_pd(a, INT32_C(         195));
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[60].r), 1);

  a = simde_mm_loadu_pd(test_vec[61].a);
  r = simde_mm_roundscale_pd(a, INT32_C(         211));
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[61].r), 1);

  a = simde_mm_loadu_pd(test_vec[62].a);
  r = simde_mm_roundscale_pd(a, INT32_C(         227));
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[62].r), 1);

  a = simde_mm_loadu_pd(test_vec[63].a);
  r = simde_mm_roundscale_pd(a, INT32_C(         243));
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[63].r), 1);

  a = simde_mm_loadu_pd(test_vec[64].a);
  r = simde_mm_roundscale_pd(a, INT32_C(           4));
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[64].r), 1);

  a = simde_mm_loadu_pd(test_vec[65].a);
  r = simde_mm_roundscale_pd(a, INT32_C(          20));
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[65].r), 1);

  a = simde_mm_loadu_pd(test_vec[66].a);
  r = simde_mm_roundscale_pd(a, INT32_C(          36));
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[66].r), 1);

  a = simde_mm_loadu_pd(test_vec[67].a);
  r = simde_mm_roundscale_pd(a, INT32_C(          52));
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[67].r), 1);

  a = simde_mm_loadu_pd(test_vec[68].a);
  r = simde_mm_roundscale_pd(a, INT32_C(          68));
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[68].r), 1);

  a = simde_mm_loadu_pd(test_vec[69].a);
  r = simde_mm_roundscale_pd(a, INT32_C(          84));
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[69].r), 1);

  a = simde_mm_loadu_pd(test_vec[70].a);
  r = simde_mm_roundscale_pd(a, INT32_C(         100));
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[70].r), 1);

  a = simde_mm_loadu_pd(test_vec[71].a);
  r = simde_mm_roundscale_pd(a, INT32_C(         116));
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[71].r), 1);

  a = simde_mm_loadu_pd(test_vec[72].a);
  r = simde_mm_roundscale_pd(a, INT32_C(         132));
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[72].r), 1);

  a = simde_mm_loadu_pd(test_vec[73].a);
  r = simde_mm_roundscale_pd(a, INT32_C(         148));
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[73].r), 1);

  a = simde_mm_loadu_pd(test_vec[74].a);
  r = simde_mm_roundscale_pd(a, INT32_C(         164));
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[74].r), 1);

  a = simde_mm_loadu_pd(test_vec[75].a);
  r = simde_mm_roundscale_pd(a, INT32_C(         180));
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[75].r), 1);

  a = simde_mm_loadu_pd(test_vec[76].a);
  r = simde_mm_roundscale_pd(a, INT32_C(         196));
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[76].r), 1);

  a = simde_mm_loadu_pd(test_vec[77].a);
  r = simde_mm_roundscale_pd(a, INT32_C(         212));
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[77].r), 1);

  a = simde_mm_loadu_pd(test_vec[78].a);
  r = simde_mm_roundscale_pd(a, INT32_C(         228));
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[78].r), 1);

  a = simde_mm_loadu_pd(test_vec[79].a);
  r = simde_mm_roundscale_pd(a, INT32_C(         244));
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[79].r), 1);

 return 0;
#else
  fputc('\n', stdout);
  int round_type[5] = {SIMDE_MM_FROUND_TO_NEAREST_INT, SIMDE_MM_FROUND_TO_NEG_INF, SIMDE_MM_FROUND_TO_POS_INF, SIMDE_MM_FROUND_TO_ZERO, SIMDE_MM_FROUND_CUR_DIRECTION};
  for (int i = 0 ; i < 5 ; i++) {
    for (int j = 0 ; j < 16 ; j++) {
      simde__m128d a = simde_test_x86_random_f64x2(SIMDE_FLOAT64_C(-1000.0), SIMDE_FLOAT64_C(1000.0));
      if((simde_test_codegen_rand() & 1)) {
        if((simde_test_codegen_rand() & 1))
          a = simde_mm_blend_pd(a, simde_mm_set1_pd(SIMDE_MATH_NAN), 1);
        else {
          if((simde_test_codegen_rand() & 1))
            a = simde_mm_blend_pd(a, simde_mm_set1_pd(SIMDE_MATH_INFINITY), 2);
          else
            a = simde_mm_blend_pd(a, simde_mm_set1_pd(-SIMDE_MATH_INFINITY), 2);
        }
      }
      int imm8 = ((j << 4) | round_type[i]) & 255;
      simde__m128d r;
      SIMDE_CONSTIFY_256_(simde_mm_roundscale_pd, r, simde_mm_setzero_pd(), imm8, a);

      simde_test_x86_write_f64x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
      simde_test_codegen_write_i32(2, imm8, SIMDE_TEST_VEC_POS_MIDDLE);
      simde_test_x86_write_f64x2(2, r, SIMDE_TEST_VEC_POS_LAST);
    }
  }
  return 1;
#endif
}

static int
test_simde_mm_mask_roundscale_pd (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const simde_float64 src[2];
    const simde__mmask8 k;
    const simde_float64 a[2];
    const int imm8;
    const simde_float64 r[2];
  } test_vec[] = {
    { { SIMDE_FLOAT64_C(    70.53), SIMDE_FLOAT64_C(  -663.37) },
      UINT8_C(228),
      { SIMDE_FLOAT64_C(   964.85), SIMDE_FLOAT64_C(    43.10) },
       INT32_C(         160),
      { SIMDE_FLOAT64_C(    70.53), SIMDE_FLOAT64_C(  -663.37) } },
    { { SIMDE_FLOAT64_C(  -551.58), SIMDE_FLOAT64_C(   772.38) },
      UINT8_C(206),
      {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(   607.68) },
       INT32_C(         209),
      { SIMDE_FLOAT64_C(  -551.58), SIMDE_FLOAT64_C(   607.68) } },
    { { SIMDE_FLOAT64_C(  -485.89), SIMDE_FLOAT64_C(   461.44) },
      UINT8_C(234),
      { SIMDE_FLOAT64_C(   305.64),        SIMDE_MATH_INFINITY },
       INT32_C(         210),
      { SIMDE_FLOAT64_C(  -485.89),        SIMDE_MATH_INFINITY } },
    { { SIMDE_FLOAT64_C(  -966.02), SIMDE_FLOAT64_C(  -869.88) },
      UINT8_C( 76),
      {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(   779.36) },
       INT32_C(         227),
      { SIMDE_FLOAT64_C(  -966.02), SIMDE_FLOAT64_C(  -869.88) } },
    { { SIMDE_FLOAT64_C(   993.79), SIMDE_FLOAT64_C(   944.88) },
      UINT8_C(110),
      { SIMDE_FLOAT64_C(    36.89), SIMDE_FLOAT64_C(  -125.52) },
       INT32_C(         212),
      { SIMDE_FLOAT64_C(   993.79), SIMDE_FLOAT64_C(  -125.52) } },
    { { SIMDE_FLOAT64_C(  -353.14), SIMDE_FLOAT64_C(  -742.71) },
      UINT8_C(176),
      { SIMDE_FLOAT64_C(  -745.46), SIMDE_FLOAT64_C(   731.60) },
       INT32_C(         224),
      { SIMDE_FLOAT64_C(  -353.14), SIMDE_FLOAT64_C(  -742.71) } },
    { { SIMDE_FLOAT64_C(  -754.30), SIMDE_FLOAT64_C(  -174.41) },
      UINT8_C(233),
      { SIMDE_FLOAT64_C(   551.34), SIMDE_FLOAT64_C(  -901.33) },
       INT32_C(         113),
      { SIMDE_FLOAT64_C(   551.34), SIMDE_FLOAT64_C(  -174.41) } },
    { { SIMDE_FLOAT64_C(   395.65), SIMDE_FLOAT64_C(  -432.03) },
      UINT8_C(122),
      { SIMDE_FLOAT64_C(   525.76), SIMDE_FLOAT64_C(   438.68) },
       INT32_C(          82),
      { SIMDE_FLOAT64_C(   395.65), SIMDE_FLOAT64_C(   438.69) } },
  };

  simde__m128d src, a, r;

  src = simde_mm_loadu_pd(test_vec[0].src);
  a = simde_mm_loadu_pd(test_vec[0].a);
  r = simde_mm_mask_roundscale_pd(src, test_vec[0].k, a, INT32_C(         160));
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[0].r), 1);

  src = simde_mm_loadu_pd(test_vec[1].src);
  a = simde_mm_loadu_pd(test_vec[1].a);
  r = simde_mm_mask_roundscale_pd(src, test_vec[1].k, a, INT32_C(         209));
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[1].r), 1);

  src = simde_mm_loadu_pd(test_vec[2].src);
  a = simde_mm_loadu_pd(test_vec[2].a);
  r = simde_mm_mask_roundscale_pd(src, test_vec[2].k, a, INT32_C(         210));
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[2].r), 1);

  src = simde_mm_loadu_pd(test_vec[3].src);
  a = simde_mm_loadu_pd(test_vec[3].a);
  r = simde_mm_mask_roundscale_pd(src, test_vec[3].k, a, INT32_C(         227));
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[3].r), 1);

  src = simde_mm_loadu_pd(test_vec[4].src);
  a = simde_mm_loadu_pd(test_vec[4].a);
  r = simde_mm_mask_roundscale_pd(src, test_vec[4].k, a, INT32_C(         212));
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[4].r), 1);

  src = simde_mm_loadu_pd(test_vec[5].src);
  a = simde_mm_loadu_pd(test_vec[5].a);
  r = simde_mm_mask_roundscale_pd(src, test_vec[5].k, a, INT32_C(         224));
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[5].r), 1);

  src = simde_mm_loadu_pd(test_vec[6].src);
  a = simde_mm_loadu_pd(test_vec[6].a);
  r = simde_mm_mask_roundscale_pd(src, test_vec[6].k, a, INT32_C(         113));
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[6].r), 1);

  src = simde_mm_loadu_pd(test_vec[7].src);
  a = simde_mm_loadu_pd(test_vec[7].a);
  r = simde_mm_mask_roundscale_pd(src, test_vec[7].k, a, INT32_C(          82));
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[7].r), 1);

 return 0;
#else
  fputc('\n', stdout);
  int round_type[5] = {SIMDE_MM_FROUND_TO_NEAREST_INT, SIMDE_MM_FROUND_TO_NEG_INF, SIMDE_MM_FROUND_TO_POS_INF, SIMDE_MM_FROUND_TO_ZERO, SIMDE_MM_FROUND_CUR_DIRECTION};
  for (int i = 0 ; i < 8 ; i++) {
      simde__m128d src = simde_test_x86_random_f64x2(SIMDE_FLOAT64_C(-1000.0), SIMDE_FLOAT64_C(1000.0));
      simde__mmask8 k = simde_test_x86_random_mmask8();
      simde__m128d a = simde_test_x86_random_f64x2(SIMDE_FLOAT64_C(-1000.0), SIMDE_FLOAT64_C(1000.0));
      if((simde_test_codegen_rand() & 1)) {
        if((simde_test_codegen_rand() & 1))
          a = simde_mm_blend_pd(a, simde_mm_set1_pd(SIMDE_MATH_NAN), 1);
        else {
          if((simde_test_codegen_rand() & 1))
            a = simde_mm_blend_pd(a, simde_mm_set1_pd(SIMDE_MATH_INFINITY), 2);
          else
            a = simde_mm_blend_pd(a, simde_mm_set1_pd(-SIMDE_MATH_INFINITY), 2);
        }
      }
      int imm8 = (((simde_test_codegen_rand() & 15) << 4) | round_type[i % 5]) & 255;
      simde__m128d r;
      SIMDE_CONSTIFY_256_(simde_mm_mask_roundscale_pd, r, simde_mm_setzero_pd(), imm8, src, k, a);

      simde_test_x86_write_f64x2(2, src, SIMDE_TEST_VEC_POS_FIRST);
      simde_test_x86_write_mmask8(2, k, SIMDE_TEST_VEC_POS_MIDDLE);
      simde_test_x86_write_f64x2(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
      simde_test_codegen_write_i32(2, imm8, SIMDE_TEST_VEC_POS_MIDDLE);
      simde_test_x86_write_f64x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm_maskz_roundscale_pd (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const simde__mmask8 k;
    const simde_float64 a[2];
    const int imm8;
    const simde_float64 r[2];
  } test_vec[] = {
    { UINT8_C(129),
      { SIMDE_FLOAT64_C(   821.47), SIMDE_FLOAT64_C(  -844.99) },
       INT32_C(          96),
      { SIMDE_FLOAT64_C(   821.47), SIMDE_FLOAT64_C(     0.00) } },
    { UINT8_C( 81),
      { SIMDE_FLOAT64_C(  -873.46), SIMDE_FLOAT64_C(  -359.17) },
       INT32_C(         193),
      { SIMDE_FLOAT64_C(  -873.46), SIMDE_FLOAT64_C(     0.00) } },
    { UINT8_C( 63),
      { SIMDE_FLOAT64_C(   897.95),       -SIMDE_MATH_INFINITY },
       INT32_C(         242),
      { SIMDE_FLOAT64_C(   897.95),       -SIMDE_MATH_INFINITY } },
    { UINT8_C( 76),
      { SIMDE_FLOAT64_C(   389.69),       -SIMDE_MATH_INFINITY },
       INT32_C(          99),
      { SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(     0.00) } },
    { UINT8_C(139),
      { SIMDE_FLOAT64_C(   145.51), SIMDE_FLOAT64_C(   -79.48) },
       INT32_C(         180),
      { SIMDE_FLOAT64_C(   145.51), SIMDE_FLOAT64_C(   -79.48) } },
    { UINT8_C(233),
      { SIMDE_FLOAT64_C(   714.89), SIMDE_FLOAT64_C(   680.04) },
       INT32_C(         128),
      { SIMDE_FLOAT64_C(   714.89), SIMDE_FLOAT64_C(     0.00) } },
    { UINT8_C(171),
      { SIMDE_FLOAT64_C(  -808.91), SIMDE_FLOAT64_C(  -160.34) },
       INT32_C(         241),
      { SIMDE_FLOAT64_C(  -808.91), SIMDE_FLOAT64_C(  -160.34) } },
    { UINT8_C( 19),
      { SIMDE_FLOAT64_C(  -491.94), SIMDE_FLOAT64_C(  -880.40) },
       INT32_C(          34),
      { SIMDE_FLOAT64_C(  -491.75), SIMDE_FLOAT64_C(  -880.25) } },
  };

  simde__m128d a, r;

  a = simde_mm_loadu_pd(test_vec[0].a);
  r = simde_mm_maskz_roundscale_pd(test_vec[0].k, a, INT32_C(          96));
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[0].r), 1);

  a = simde_mm_loadu_pd(test_vec[1].a);
  r = simde_mm_maskz_roundscale_pd(test_vec[1].k, a, INT32_C(         193));
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[1].r), 1);

  a = simde_mm_loadu_pd(test_vec[2].a);
  r = simde_mm_maskz_roundscale_pd(test_vec[2].k, a, INT32_C(         242));
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[2].r), 1);

  a = simde_mm_loadu_pd(test_vec[3].a);
  r = simde_mm_maskz_roundscale_pd(test_vec[3].k, a, INT32_C(          99));
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[3].r), 1);

  a = simde_mm_loadu_pd(test_vec[4].a);
  r = simde_mm_maskz_roundscale_pd(test_vec[4].k, a, INT32_C(         180));
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[4].r), 1);

  a = simde_mm_loadu_pd(test_vec[5].a);
  r = simde_mm_maskz_roundscale_pd(test_vec[5].k, a, INT32_C(         128));
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[5].r), 1);

  a = simde_mm_loadu_pd(test_vec[6].a);
  r = simde_mm_maskz_roundscale_pd(test_vec[6].k, a, INT32_C(         241));
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[6].r), 1);

  a = simde_mm_loadu_pd(test_vec[7].a);
  r = simde_mm_maskz_roundscale_pd(test_vec[7].k, a, INT32_C(          34));
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[7].r), 1);

 return 0;
#else
  fputc('\n', stdout);
  int round_type[5] = {SIMDE_MM_FROUND_TO_NEAREST_INT, SIMDE_MM_FROUND_TO_NEG_INF, SIMDE_MM_FROUND_TO_POS_INF, SIMDE_MM_FROUND_TO_ZERO, SIMDE_MM_FROUND_CUR_DIRECTION};
  for (int i = 0 ; i < 8 ; i++) {
    simde__mmask8 k = simde_test_x86_random_mmask8();
    simde__m128d a = simde_test_x86_random_f64x2(SIMDE_FLOAT64_C(-1000.0), SIMDE_FLOAT64_C(1000.0));
    if((simde_test_codegen_rand() & 1)) {
      if((simde_test_codegen_rand() & 1))
        a = simde_mm_blend_pd(a, simde_mm_set1_pd(SIMDE_MATH_NAN), 1);
      else {
        if((simde_test_codegen_rand() & 1))
          a = simde_mm_blend_pd(a, simde_mm_set1_pd(SIMDE_MATH_INFINITY), 2);
        else
          a = simde_mm_blend_pd(a, simde_mm_set1_pd(-SIMDE_MATH_INFINITY), 2);
      }
    }
    int imm8 = (((simde_test_codegen_rand() & 15) << 4) | round_type[i % 5]) & 255;
    simde__m128d r;
    SIMDE_CONSTIFY_256_(simde_mm_maskz_roundscale_pd, r, simde_mm_setzero_pd(), imm8, k, a);

    simde_test_x86_write_mmask8(2, k, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_f64x2(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i32(2, imm8, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_f64x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm256_roundscale_pd (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const simde_float64 a[4];
    const int32_t imm8;
    const simde_float64 r[4];
  } test_vec[] = {
    { { SIMDE_FLOAT64_C(   478.89),       -SIMDE_MATH_INFINITY, SIMDE_FLOAT64_C(  -353.66), SIMDE_FLOAT64_C(   647.32) },
       INT32_C(           0),
      { SIMDE_FLOAT64_C(   479.00),       -SIMDE_MATH_INFINITY, SIMDE_FLOAT64_C(  -354.00), SIMDE_FLOAT64_C(   647.00) } },
    { { SIMDE_FLOAT64_C(  -139.30), SIMDE_FLOAT64_C(  -585.30), SIMDE_FLOAT64_C(  -212.07), SIMDE_FLOAT64_C(  -727.58) },
       INT32_C(          16),
      { SIMDE_FLOAT64_C(  -139.50), SIMDE_FLOAT64_C(  -585.50), SIMDE_FLOAT64_C(  -212.00), SIMDE_FLOAT64_C(  -727.50) } },
    { { SIMDE_FLOAT64_C(  -424.71),       -SIMDE_MATH_INFINITY, SIMDE_FLOAT64_C(   300.82), SIMDE_FLOAT64_C(  -527.06) },
       INT32_C(          32),
      { SIMDE_FLOAT64_C(  -424.75),       -SIMDE_MATH_INFINITY, SIMDE_FLOAT64_C(   300.75), SIMDE_FLOAT64_C(  -527.00) } },
    { { SIMDE_FLOAT64_C(   759.84),        SIMDE_MATH_INFINITY, SIMDE_FLOAT64_C(  -784.82), SIMDE_FLOAT64_C(  -774.55) },
       INT32_C(          48),
      { SIMDE_FLOAT64_C(   759.88),        SIMDE_MATH_INFINITY, SIMDE_FLOAT64_C(  -784.88), SIMDE_FLOAT64_C(  -774.50) } },
    { { SIMDE_FLOAT64_C(    47.82),        SIMDE_MATH_INFINITY, SIMDE_FLOAT64_C(   320.78), SIMDE_FLOAT64_C(  -567.27) },
       INT32_C(          64),
      { SIMDE_FLOAT64_C(    47.81),        SIMDE_MATH_INFINITY, SIMDE_FLOAT64_C(   320.75), SIMDE_FLOAT64_C(  -567.25) } },
    { { SIMDE_FLOAT64_C(  -134.26),        SIMDE_MATH_INFINITY, SIMDE_FLOAT64_C(   -18.89), SIMDE_FLOAT64_C(   416.85) },
       INT32_C(          80),
      { SIMDE_FLOAT64_C(  -134.25),        SIMDE_MATH_INFINITY, SIMDE_FLOAT64_C(   -18.88), SIMDE_FLOAT64_C(   416.84) } },
    { { SIMDE_FLOAT64_C(   249.32), SIMDE_FLOAT64_C(  -885.77), SIMDE_FLOAT64_C(  -611.79), SIMDE_FLOAT64_C(   824.61) },
       INT32_C(          96),
      { SIMDE_FLOAT64_C(   249.31), SIMDE_FLOAT64_C(  -885.77), SIMDE_FLOAT64_C(  -611.80), SIMDE_FLOAT64_C(   824.61) } },
    { { SIMDE_FLOAT64_C(   689.03),       -SIMDE_MATH_INFINITY, SIMDE_FLOAT64_C(   135.80), SIMDE_FLOAT64_C(  -347.14) },
       INT32_C(         112),
      { SIMDE_FLOAT64_C(   689.03),       -SIMDE_MATH_INFINITY, SIMDE_FLOAT64_C(   135.80), SIMDE_FLOAT64_C(  -347.14) } },
    { {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(   121.08), SIMDE_FLOAT64_C(   589.13), SIMDE_FLOAT64_C(   907.64) },
       INT32_C(         128),
      {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(   121.08), SIMDE_FLOAT64_C(   589.13), SIMDE_FLOAT64_C(   907.64) } },
    { { SIMDE_FLOAT64_C(   620.07),        SIMDE_MATH_INFINITY, SIMDE_FLOAT64_C(    69.68), SIMDE_FLOAT64_C(   839.47) },
       INT32_C(         144),
      { SIMDE_FLOAT64_C(   620.07),        SIMDE_MATH_INFINITY, SIMDE_FLOAT64_C(    69.68), SIMDE_FLOAT64_C(   839.47) } },
    { {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(  -196.65), SIMDE_FLOAT64_C(  -877.94), SIMDE_FLOAT64_C(  -295.05) },
       INT32_C(         160),
      {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(  -196.65), SIMDE_FLOAT64_C(  -877.94), SIMDE_FLOAT64_C(  -295.05) } },
    { {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(  -240.61), SIMDE_FLOAT64_C(  -658.18), SIMDE_FLOAT64_C(   778.88) },
       INT32_C(         176),
      {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(  -240.61), SIMDE_FLOAT64_C(  -658.18), SIMDE_FLOAT64_C(   778.88) } },
    { {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(  -992.29), SIMDE_FLOAT64_C(  -316.30), SIMDE_FLOAT64_C(  -447.51) },
       INT32_C(         192),
      {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(  -992.29), SIMDE_FLOAT64_C(  -316.30), SIMDE_FLOAT64_C(  -447.51) } },
    { { SIMDE_FLOAT64_C(   243.73), SIMDE_FLOAT64_C(  -975.57), SIMDE_FLOAT64_C(   525.76), SIMDE_FLOAT64_C(   151.37) },
       INT32_C(         208),
      { SIMDE_FLOAT64_C(   243.73), SIMDE_FLOAT64_C(  -975.57), SIMDE_FLOAT64_C(   525.76), SIMDE_FLOAT64_C(   151.37) } },
    { {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(  -228.56), SIMDE_FLOAT64_C(  -302.52), SIMDE_FLOAT64_C(   232.39) },
       INT32_C(         224),
      {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(  -228.56), SIMDE_FLOAT64_C(  -302.52), SIMDE_FLOAT64_C(   232.39) } },
    { { SIMDE_FLOAT64_C(    54.64),        SIMDE_MATH_INFINITY, SIMDE_FLOAT64_C(  -262.39), SIMDE_FLOAT64_C(   857.99) },
       INT32_C(         240),
      { SIMDE_FLOAT64_C(    54.64),        SIMDE_MATH_INFINITY, SIMDE_FLOAT64_C(  -262.39), SIMDE_FLOAT64_C(   857.99) } },
    { { SIMDE_FLOAT64_C(   391.80),       -SIMDE_MATH_INFINITY, SIMDE_FLOAT64_C(   262.54), SIMDE_FLOAT64_C(   733.62) },
       INT32_C(           1),
      { SIMDE_FLOAT64_C(   391.00),       -SIMDE_MATH_INFINITY, SIMDE_FLOAT64_C(   262.00), SIMDE_FLOAT64_C(   733.00) } },
    { { SIMDE_FLOAT64_C(   252.12), SIMDE_FLOAT64_C(  -857.84), SIMDE_FLOAT64_C(  -551.83), SIMDE_FLOAT64_C(   804.61) },
       INT32_C(          17),
      { SIMDE_FLOAT64_C(   252.00), SIMDE_FLOAT64_C(  -858.00), SIMDE_FLOAT64_C(  -552.00), SIMDE_FLOAT64_C(   804.50) } },
    { {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(    48.34), SIMDE_FLOAT64_C(    69.93), SIMDE_FLOAT64_C(   910.57) },
       INT32_C(          33),
      {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(    48.25), SIMDE_FLOAT64_C(    69.75), SIMDE_FLOAT64_C(   910.50) } },
    { { SIMDE_FLOAT64_C(  -926.72),       -SIMDE_MATH_INFINITY, SIMDE_FLOAT64_C(   467.98), SIMDE_FLOAT64_C(   305.67) },
       INT32_C(          49),
      { SIMDE_FLOAT64_C(  -926.75),       -SIMDE_MATH_INFINITY, SIMDE_FLOAT64_C(   467.88), SIMDE_FLOAT64_C(   305.62) } },
    { {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(  -300.36), SIMDE_FLOAT64_C(  -781.70), SIMDE_FLOAT64_C(  -663.62) },
       INT32_C(          65),
      {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(  -300.38), SIMDE_FLOAT64_C(  -781.75), SIMDE_FLOAT64_C(  -663.62) } },
    { {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(   539.02), SIMDE_FLOAT64_C(   983.98), SIMDE_FLOAT64_C(   461.80) },
       INT32_C(          81),
      {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(   539.00), SIMDE_FLOAT64_C(   983.97), SIMDE_FLOAT64_C(   461.78) } },
    { { SIMDE_FLOAT64_C(   226.26), SIMDE_FLOAT64_C(   966.84), SIMDE_FLOAT64_C(  -739.41), SIMDE_FLOAT64_C(   674.43) },
       INT32_C(          97),
      { SIMDE_FLOAT64_C(   226.25), SIMDE_FLOAT64_C(   966.83), SIMDE_FLOAT64_C(  -739.42), SIMDE_FLOAT64_C(   674.42) } },
    { { SIMDE_FLOAT64_C(   306.09), SIMDE_FLOAT64_C(  -940.77), SIMDE_FLOAT64_C(  -180.22), SIMDE_FLOAT64_C(  -623.98) },
       INT32_C(         113),
      { SIMDE_FLOAT64_C(   306.09), SIMDE_FLOAT64_C(  -940.77), SIMDE_FLOAT64_C(  -180.23), SIMDE_FLOAT64_C(  -623.98) } },
    { {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(   146.52), SIMDE_FLOAT64_C(  -956.93), SIMDE_FLOAT64_C(   990.64) },
       INT32_C(         129),
      {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(   146.52), SIMDE_FLOAT64_C(  -956.93), SIMDE_FLOAT64_C(   990.64) } },
    { { SIMDE_FLOAT64_C(   572.71), SIMDE_FLOAT64_C(  -423.47), SIMDE_FLOAT64_C(   709.06), SIMDE_FLOAT64_C(  -529.10) },
       INT32_C(         145),
      { SIMDE_FLOAT64_C(   572.71), SIMDE_FLOAT64_C(  -423.47), SIMDE_FLOAT64_C(   709.06), SIMDE_FLOAT64_C(  -529.10) } },
    { {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(  -192.72), SIMDE_FLOAT64_C(   418.37), SIMDE_FLOAT64_C(  -351.20) },
       INT32_C(         161),
      {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(  -192.72), SIMDE_FLOAT64_C(   418.37), SIMDE_FLOAT64_C(  -351.20) } },
    { { SIMDE_FLOAT64_C(  -367.21),       -SIMDE_MATH_INFINITY, SIMDE_FLOAT64_C(   672.09), SIMDE_FLOAT64_C(  -248.78) },
       INT32_C(         177),
      { SIMDE_FLOAT64_C(  -367.21),       -SIMDE_MATH_INFINITY, SIMDE_FLOAT64_C(   672.09), SIMDE_FLOAT64_C(  -248.78) } },
    { { SIMDE_FLOAT64_C(  -102.05),        SIMDE_MATH_INFINITY, SIMDE_FLOAT64_C(  -682.10), SIMDE_FLOAT64_C(   -42.82) },
       INT32_C(         193),
      { SIMDE_FLOAT64_C(  -102.05),        SIMDE_MATH_INFINITY, SIMDE_FLOAT64_C(  -682.10), SIMDE_FLOAT64_C(   -42.82) } },
    { {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(   840.45), SIMDE_FLOAT64_C(   -29.95), SIMDE_FLOAT64_C(   240.29) },
       INT32_C(         209),
      {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(   840.45), SIMDE_FLOAT64_C(   -29.95), SIMDE_FLOAT64_C(   240.29) } },
    { { SIMDE_FLOAT64_C(  -187.00), SIMDE_FLOAT64_C(    31.48), SIMDE_FLOAT64_C(  -972.15), SIMDE_FLOAT64_C(   283.90) },
       INT32_C(         225),
      { SIMDE_FLOAT64_C(  -187.00), SIMDE_FLOAT64_C(    31.48), SIMDE_FLOAT64_C(  -972.15), SIMDE_FLOAT64_C(   283.90) } },
    { { SIMDE_FLOAT64_C(   955.21), SIMDE_FLOAT64_C(  -908.82), SIMDE_FLOAT64_C(   726.01), SIMDE_FLOAT64_C(  -395.99) },
       INT32_C(         241),
      { SIMDE_FLOAT64_C(   955.21), SIMDE_FLOAT64_C(  -908.82), SIMDE_FLOAT64_C(   726.01), SIMDE_FLOAT64_C(  -395.99) } },
    { {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(   236.80), SIMDE_FLOAT64_C(  -376.09), SIMDE_FLOAT64_C(  -644.51) },
       INT32_C(           2),
      {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(   237.00), SIMDE_FLOAT64_C(  -376.00), SIMDE_FLOAT64_C(  -644.00) } },
    { {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(    -0.17), SIMDE_FLOAT64_C(  -254.61), SIMDE_FLOAT64_C(   404.79) },
       INT32_C(          18),
      {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(    -0.00), SIMDE_FLOAT64_C(  -254.50), SIMDE_FLOAT64_C(   405.00) } },
    { {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(  -988.34), SIMDE_FLOAT64_C(  -370.46), SIMDE_FLOAT64_C(  -115.40) },
       INT32_C(          34),
      {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(  -988.25), SIMDE_FLOAT64_C(  -370.25), SIMDE_FLOAT64_C(  -115.25) } },
    { { SIMDE_FLOAT64_C(  -875.10), SIMDE_FLOAT64_C(  -692.94), SIMDE_FLOAT64_C(   918.39), SIMDE_FLOAT64_C(   -62.11) },
       INT32_C(          50),
      { SIMDE_FLOAT64_C(  -875.00), SIMDE_FLOAT64_C(  -692.88), SIMDE_FLOAT64_C(   918.50), SIMDE_FLOAT64_C(   -62.00) } },
    { {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(  -778.21), SIMDE_FLOAT64_C(   646.19), SIMDE_FLOAT64_C(   901.45) },
       INT32_C(          66),
      {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(  -778.19), SIMDE_FLOAT64_C(   646.25), SIMDE_FLOAT64_C(   901.50) } },
    { {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(   -60.39), SIMDE_FLOAT64_C(  -944.41), SIMDE_FLOAT64_C(   742.26) },
       INT32_C(          82),
      {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(   -60.38), SIMDE_FLOAT64_C(  -944.41), SIMDE_FLOAT64_C(   742.28) } },
    { { SIMDE_FLOAT64_C(   730.28),        SIMDE_MATH_INFINITY, SIMDE_FLOAT64_C(  -594.50), SIMDE_FLOAT64_C(  -269.89) },
       INT32_C(          98),
      { SIMDE_FLOAT64_C(   730.28),        SIMDE_MATH_INFINITY, SIMDE_FLOAT64_C(  -594.50), SIMDE_FLOAT64_C(  -269.88) } },
    { {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(   445.25), SIMDE_FLOAT64_C(  -940.50), SIMDE_FLOAT64_C(  -511.53) },
       INT32_C(         114),
      {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(   445.25), SIMDE_FLOAT64_C(  -940.50), SIMDE_FLOAT64_C(  -511.52) } },
    { {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(  -545.25), SIMDE_FLOAT64_C(  -781.33), SIMDE_FLOAT64_C(  -993.56) },
       INT32_C(         130),
      {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(  -545.25), SIMDE_FLOAT64_C(  -781.33), SIMDE_FLOAT64_C(  -993.56) } },
    { { SIMDE_FLOAT64_C(   952.68), SIMDE_FLOAT64_C(   614.43), SIMDE_FLOAT64_C(   203.40), SIMDE_FLOAT64_C(   854.13) },
       INT32_C(         146),
      { SIMDE_FLOAT64_C(   952.68), SIMDE_FLOAT64_C(   614.43), SIMDE_FLOAT64_C(   203.40), SIMDE_FLOAT64_C(   854.13) } },
    { { SIMDE_FLOAT64_C(  -424.40), SIMDE_FLOAT64_C(  -640.41), SIMDE_FLOAT64_C(  -132.99), SIMDE_FLOAT64_C(  -368.81) },
       INT32_C(         162),
      { SIMDE_FLOAT64_C(  -424.40), SIMDE_FLOAT64_C(  -640.41), SIMDE_FLOAT64_C(  -132.99), SIMDE_FLOAT64_C(  -368.81) } },
    { { SIMDE_FLOAT64_C(  -569.47),       -SIMDE_MATH_INFINITY, SIMDE_FLOAT64_C(   832.13), SIMDE_FLOAT64_C(   841.49) },
       INT32_C(         178),
      { SIMDE_FLOAT64_C(  -569.47),       -SIMDE_MATH_INFINITY, SIMDE_FLOAT64_C(   832.13), SIMDE_FLOAT64_C(   841.49) } },
    { { SIMDE_FLOAT64_C(   258.07),       -SIMDE_MATH_INFINITY, SIMDE_FLOAT64_C(   856.76), SIMDE_FLOAT64_C(  -296.68) },
       INT32_C(         194),
      { SIMDE_FLOAT64_C(   258.07),       -SIMDE_MATH_INFINITY, SIMDE_FLOAT64_C(   856.76), SIMDE_FLOAT64_C(  -296.68) } },
    { { SIMDE_FLOAT64_C(  -418.80), SIMDE_FLOAT64_C(  -566.71), SIMDE_FLOAT64_C(   487.92), SIMDE_FLOAT64_C(  -200.13) },
       INT32_C(         210),
      { SIMDE_FLOAT64_C(  -418.80), SIMDE_FLOAT64_C(  -566.71), SIMDE_FLOAT64_C(   487.92), SIMDE_FLOAT64_C(  -200.13) } },
    { { SIMDE_FLOAT64_C(  -119.44),        SIMDE_MATH_INFINITY, SIMDE_FLOAT64_C(  -607.58), SIMDE_FLOAT64_C(  -505.01) },
       INT32_C(         226),
      { SIMDE_FLOAT64_C(  -119.44),        SIMDE_MATH_INFINITY, SIMDE_FLOAT64_C(  -607.58), SIMDE_FLOAT64_C(  -505.01) } },
    { { SIMDE_FLOAT64_C(  -863.93), SIMDE_FLOAT64_C(  -393.86), SIMDE_FLOAT64_C(   289.40), SIMDE_FLOAT64_C(  -232.73) },
       INT32_C(         242),
      { SIMDE_FLOAT64_C(  -863.93), SIMDE_FLOAT64_C(  -393.86), SIMDE_FLOAT64_C(   289.40), SIMDE_FLOAT64_C(  -232.73) } },
    { { SIMDE_FLOAT64_C(   719.93), SIMDE_FLOAT64_C(   809.54), SIMDE_FLOAT64_C(  -459.89), SIMDE_FLOAT64_C(   561.42) },
       INT32_C(           3),
      { SIMDE_FLOAT64_C(   719.00), SIMDE_FLOAT64_C(   809.00), SIMDE_FLOAT64_C(  -459.00), SIMDE_FLOAT64_C(   561.00) } },
    { { SIMDE_FLOAT64_C(   102.35), SIMDE_FLOAT64_C(   559.26), SIMDE_FLOAT64_C(  -484.61), SIMDE_FLOAT64_C(   712.43) },
       INT32_C(          19),
      { SIMDE_FLOAT64_C(   102.00), SIMDE_FLOAT64_C(   559.00), SIMDE_FLOAT64_C(  -484.50), SIMDE_FLOAT64_C(   712.00) } },
    { { SIMDE_FLOAT64_C(   218.71),       -SIMDE_MATH_INFINITY, SIMDE_FLOAT64_C(   761.26), SIMDE_FLOAT64_C(  -748.12) },
       INT32_C(          35),
      { SIMDE_FLOAT64_C(   218.50),       -SIMDE_MATH_INFINITY, SIMDE_FLOAT64_C(   761.25), SIMDE_FLOAT64_C(  -748.00) } },
    { { SIMDE_FLOAT64_C(   763.08),       -SIMDE_MATH_INFINITY, SIMDE_FLOAT64_C(  -379.63), SIMDE_FLOAT64_C(  -879.84) },
       INT32_C(          51),
      { SIMDE_FLOAT64_C(   763.00),       -SIMDE_MATH_INFINITY, SIMDE_FLOAT64_C(  -379.62), SIMDE_FLOAT64_C(  -879.75) } },
    { {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(   537.75), SIMDE_FLOAT64_C(   816.71), SIMDE_FLOAT64_C(   879.38) },
       INT32_C(          67),
      {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(   537.75), SIMDE_FLOAT64_C(   816.69), SIMDE_FLOAT64_C(   879.38) } },
    { { SIMDE_FLOAT64_C(  -412.64), SIMDE_FLOAT64_C(  -452.92), SIMDE_FLOAT64_C(  -606.48), SIMDE_FLOAT64_C(   127.47) },
       INT32_C(          83),
      { SIMDE_FLOAT64_C(  -412.62), SIMDE_FLOAT64_C(  -452.91), SIMDE_FLOAT64_C(  -606.47), SIMDE_FLOAT64_C(   127.47) } },
    { { SIMDE_FLOAT64_C(   650.84),       -SIMDE_MATH_INFINITY, SIMDE_FLOAT64_C(   667.76), SIMDE_FLOAT64_C(  -833.77) },
       INT32_C(          99),
      { SIMDE_FLOAT64_C(   650.83),       -SIMDE_MATH_INFINITY, SIMDE_FLOAT64_C(   667.75), SIMDE_FLOAT64_C(  -833.77) } },
    { { SIMDE_FLOAT64_C(  -675.74),        SIMDE_MATH_INFINITY, SIMDE_FLOAT64_C(   636.82), SIMDE_FLOAT64_C(   287.47) },
       INT32_C(         115),
      { SIMDE_FLOAT64_C(  -675.73),        SIMDE_MATH_INFINITY, SIMDE_FLOAT64_C(   636.81), SIMDE_FLOAT64_C(   287.47) } },
    { {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(   997.00), SIMDE_FLOAT64_C(   170.71), SIMDE_FLOAT64_C(  -299.44) },
       INT32_C(         131),
      {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(   997.00), SIMDE_FLOAT64_C(   170.71), SIMDE_FLOAT64_C(  -299.44) } },
    { { SIMDE_FLOAT64_C(   973.80),        SIMDE_MATH_INFINITY, SIMDE_FLOAT64_C(  -331.94), SIMDE_FLOAT64_C(   853.18) },
       INT32_C(         147),
      { SIMDE_FLOAT64_C(   973.80),        SIMDE_MATH_INFINITY, SIMDE_FLOAT64_C(  -331.94), SIMDE_FLOAT64_C(   853.18) } },
    { {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(   645.56), SIMDE_FLOAT64_C(   568.01), SIMDE_FLOAT64_C(  -867.16) },
       INT32_C(         163),
      {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(   645.56), SIMDE_FLOAT64_C(   568.01), SIMDE_FLOAT64_C(  -867.16) } },
    { { SIMDE_FLOAT64_C(   800.61), SIMDE_FLOAT64_C(   462.62), SIMDE_FLOAT64_C(   740.08), SIMDE_FLOAT64_C(  -115.60) },
       INT32_C(         179),
      { SIMDE_FLOAT64_C(   800.61), SIMDE_FLOAT64_C(   462.62), SIMDE_FLOAT64_C(   740.08), SIMDE_FLOAT64_C(  -115.60) } },
    { { SIMDE_FLOAT64_C(  -935.66),        SIMDE_MATH_INFINITY, SIMDE_FLOAT64_C(  -515.62), SIMDE_FLOAT64_C(   351.80) },
       INT32_C(         195),
      { SIMDE_FLOAT64_C(  -935.66),        SIMDE_MATH_INFINITY, SIMDE_FLOAT64_C(  -515.62), SIMDE_FLOAT64_C(   351.80) } },
    { { SIMDE_FLOAT64_C(  -557.08), SIMDE_FLOAT64_C(   858.00), SIMDE_FLOAT64_C(   573.05), SIMDE_FLOAT64_C(   143.48) },
       INT32_C(         211),
      { SIMDE_FLOAT64_C(  -557.08), SIMDE_FLOAT64_C(   858.00), SIMDE_FLOAT64_C(   573.05), SIMDE_FLOAT64_C(   143.48) } },
    { { SIMDE_FLOAT64_C(  -575.60), SIMDE_FLOAT64_C(   117.28), SIMDE_FLOAT64_C(   620.48), SIMDE_FLOAT64_C(    92.46) },
       INT32_C(         227),
      { SIMDE_FLOAT64_C(  -575.60), SIMDE_FLOAT64_C(   117.28), SIMDE_FLOAT64_C(   620.48), SIMDE_FLOAT64_C(    92.46) } },
    { { SIMDE_FLOAT64_C(    97.75), SIMDE_FLOAT64_C(  -655.51), SIMDE_FLOAT64_C(   411.01), SIMDE_FLOAT64_C(   122.09) },
       INT32_C(         243),
      { SIMDE_FLOAT64_C(    97.75), SIMDE_FLOAT64_C(  -655.51), SIMDE_FLOAT64_C(   411.01), SIMDE_FLOAT64_C(   122.09) } },
    { { SIMDE_FLOAT64_C(   -20.98), SIMDE_FLOAT64_C(   254.94), SIMDE_FLOAT64_C(   286.44), SIMDE_FLOAT64_C(  -223.15) },
       INT32_C(           4),
      { SIMDE_FLOAT64_C(   -21.00), SIMDE_FLOAT64_C(   255.00), SIMDE_FLOAT64_C(   286.00), SIMDE_FLOAT64_C(  -223.00) } },
    { { SIMDE_FLOAT64_C(  -250.94), SIMDE_FLOAT64_C(  -483.07), SIMDE_FLOAT64_C(   939.94), SIMDE_FLOAT64_C(   596.62) },
       INT32_C(          20),
      { SIMDE_FLOAT64_C(  -251.00), SIMDE_FLOAT64_C(  -483.00), SIMDE_FLOAT64_C(   940.00), SIMDE_FLOAT64_C(   596.50) } },
    { { SIMDE_FLOAT64_C(   669.39), SIMDE_FLOAT64_C(  -919.01), SIMDE_FLOAT64_C(   933.07), SIMDE_FLOAT64_C(  -561.56) },
       INT32_C(          36),
      { SIMDE_FLOAT64_C(   669.50), SIMDE_FLOAT64_C(  -919.00), SIMDE_FLOAT64_C(   933.00), SIMDE_FLOAT64_C(  -561.50) } },
    { { SIMDE_FLOAT64_C(  -664.59), SIMDE_FLOAT64_C(  -118.65), SIMDE_FLOAT64_C(   800.00), SIMDE_FLOAT64_C(   908.47) },
       INT32_C(          52),
      { SIMDE_FLOAT64_C(  -664.62), SIMDE_FLOAT64_C(  -118.62), SIMDE_FLOAT64_C(   800.00), SIMDE_FLOAT64_C(   908.50) } },
    { { SIMDE_FLOAT64_C(  -229.64), SIMDE_FLOAT64_C(  -667.13), SIMDE_FLOAT64_C(   142.12), SIMDE_FLOAT64_C(  -609.16) },
       INT32_C(          68),
      { SIMDE_FLOAT64_C(  -229.62), SIMDE_FLOAT64_C(  -667.12), SIMDE_FLOAT64_C(   142.12), SIMDE_FLOAT64_C(  -609.19) } },
    { {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(   488.59), SIMDE_FLOAT64_C(   769.82), SIMDE_FLOAT64_C(   523.59) },
       INT32_C(          84),
      {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(   488.59), SIMDE_FLOAT64_C(   769.81), SIMDE_FLOAT64_C(   523.59) } },
    { { SIMDE_FLOAT64_C(  -497.40), SIMDE_FLOAT64_C(   865.61), SIMDE_FLOAT64_C(    46.32), SIMDE_FLOAT64_C(   279.46) },
       INT32_C(         100),
      { SIMDE_FLOAT64_C(  -497.41), SIMDE_FLOAT64_C(   865.61), SIMDE_FLOAT64_C(    46.31), SIMDE_FLOAT64_C(   279.45) } },
    { {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(   796.38), SIMDE_FLOAT64_C(  -138.90), SIMDE_FLOAT64_C(   392.00) },
       INT32_C(         116),
      {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(   796.38), SIMDE_FLOAT64_C(  -138.90), SIMDE_FLOAT64_C(   392.00) } },
    { { SIMDE_FLOAT64_C(   472.99),       -SIMDE_MATH_INFINITY, SIMDE_FLOAT64_C(   -31.06), SIMDE_FLOAT64_C(   414.99) },
       INT32_C(         132),
      { SIMDE_FLOAT64_C(   472.99),       -SIMDE_MATH_INFINITY, SIMDE_FLOAT64_C(   -31.06), SIMDE_FLOAT64_C(   414.99) } },
    { {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(   875.12), SIMDE_FLOAT64_C(   985.35), SIMDE_FLOAT64_C(  -112.53) },
       INT32_C(         148),
      {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(   875.12), SIMDE_FLOAT64_C(   985.35), SIMDE_FLOAT64_C(  -112.53) } },
    { {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(   129.82), SIMDE_FLOAT64_C(   864.78), SIMDE_FLOAT64_C(  -917.38) },
       INT32_C(         164),
      {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(   129.82), SIMDE_FLOAT64_C(   864.78), SIMDE_FLOAT64_C(  -917.38) } },
    { { SIMDE_FLOAT64_C(   842.49),       -SIMDE_MATH_INFINITY, SIMDE_FLOAT64_C(  -658.93), SIMDE_FLOAT64_C(  -111.19) },
       INT32_C(         180),
      { SIMDE_FLOAT64_C(   842.49),       -SIMDE_MATH_INFINITY, SIMDE_FLOAT64_C(  -658.93), SIMDE_FLOAT64_C(  -111.19) } },
    { { SIMDE_FLOAT64_C(  -768.16), SIMDE_FLOAT64_C(  -876.66), SIMDE_FLOAT64_C(  -923.82), SIMDE_FLOAT64_C(  -390.51) },
       INT32_C(         196),
      { SIMDE_FLOAT64_C(  -768.16), SIMDE_FLOAT64_C(  -876.66), SIMDE_FLOAT64_C(  -923.82), SIMDE_FLOAT64_C(  -390.51) } },
    { { SIMDE_FLOAT64_C(   549.18), SIMDE_FLOAT64_C(   -79.79), SIMDE_FLOAT64_C(   622.77), SIMDE_FLOAT64_C(   -35.84) },
       INT32_C(         212),
      { SIMDE_FLOAT64_C(   549.18), SIMDE_FLOAT64_C(   -79.79), SIMDE_FLOAT64_C(   622.77), SIMDE_FLOAT64_C(   -35.84) } },
    { { SIMDE_FLOAT64_C(   473.06), SIMDE_FLOAT64_C(  -820.85), SIMDE_FLOAT64_C(  -879.06), SIMDE_FLOAT64_C(   348.18) },
       INT32_C(         228),
      { SIMDE_FLOAT64_C(   473.06), SIMDE_FLOAT64_C(  -820.85), SIMDE_FLOAT64_C(  -879.06), SIMDE_FLOAT64_C(   348.18) } },
    { {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(  -634.59), SIMDE_FLOAT64_C(  -459.31), SIMDE_FLOAT64_C(   321.20) },
       INT32_C(         244),
      {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(  -634.59), SIMDE_FLOAT64_C(  -459.31), SIMDE_FLOAT64_C(   321.20) } },
  };

  simde__m256d a, r;

  a = simde_mm256_loadu_pd(test_vec[0].a);
  r = simde_mm256_roundscale_pd(a, INT32_C(           0));
  simde_test_x86_assert_equal_f64x4(r, simde_mm256_loadu_pd(test_vec[0].r), 1);

  a = simde_mm256_loadu_pd(test_vec[1].a);
  r = simde_mm256_roundscale_pd(a, INT32_C(          16));
  simde_test_x86_assert_equal_f64x4(r, simde_mm256_loadu_pd(test_vec[1].r), 1);

  a = simde_mm256_loadu_pd(test_vec[2].a);
  r = simde_mm256_roundscale_pd(a, INT32_C(          32));
  simde_test_x86_assert_equal_f64x4(r, simde_mm256_loadu_pd(test_vec[2].r), 1);

  a = simde_mm256_loadu_pd(test_vec[3].a);
  r = simde_mm256_roundscale_pd(a, INT32_C(          48));
  simde_test_x86_assert_equal_f64x4(r, simde_mm256_loadu_pd(test_vec[3].r), 1);

  a = simde_mm256_loadu_pd(test_vec[4].a);
  r = simde_mm256_roundscale_pd(a, INT32_C(          64));
  simde_test_x86_assert_equal_f64x4(r, simde_mm256_loadu_pd(test_vec[4].r), 1);

  a = simde_mm256_loadu_pd(test_vec[5].a);
  r = simde_mm256_roundscale_pd(a, INT32_C(          80));
  simde_test_x86_assert_equal_f64x4(r, simde_mm256_loadu_pd(test_vec[5].r), 1);

  a = simde_mm256_loadu_pd(test_vec[6].a);
  r = simde_mm256_roundscale_pd(a, INT32_C(          96));
  simde_test_x86_assert_equal_f64x4(r, simde_mm256_loadu_pd(test_vec[6].r), 1);

  a = simde_mm256_loadu_pd(test_vec[7].a);
  r = simde_mm256_roundscale_pd(a, INT32_C(         112));
  simde_test_x86_assert_equal_f64x4(r, simde_mm256_loadu_pd(test_vec[7].r), 1);

  a = simde_mm256_loadu_pd(test_vec[8].a);
  r = simde_mm256_roundscale_pd(a, INT32_C(         128));
  simde_test_x86_assert_equal_f64x4(r, simde_mm256_loadu_pd(test_vec[8].r), 1);

  a = simde_mm256_loadu_pd(test_vec[9].a);
  r = simde_mm256_roundscale_pd(a, INT32_C(         144));
  simde_test_x86_assert_equal_f64x4(r, simde_mm256_loadu_pd(test_vec[9].r), 1);

  a = simde_mm256_loadu_pd(test_vec[10].a);
  r = simde_mm256_roundscale_pd(a, INT32_C(         160));
  simde_test_x86_assert_equal_f64x4(r, simde_mm256_loadu_pd(test_vec[10].r), 1);

  a = simde_mm256_loadu_pd(test_vec[11].a);
  r = simde_mm256_roundscale_pd(a, INT32_C(         176));
  simde_test_x86_assert_equal_f64x4(r, simde_mm256_loadu_pd(test_vec[11].r), 1);

  a = simde_mm256_loadu_pd(test_vec[12].a);
  r = simde_mm256_roundscale_pd(a, INT32_C(         192));
  simde_test_x86_assert_equal_f64x4(r, simde_mm256_loadu_pd(test_vec[12].r), 1);

  a = simde_mm256_loadu_pd(test_vec[13].a);
  r = simde_mm256_roundscale_pd(a, INT32_C(         208));
  simde_test_x86_assert_equal_f64x4(r, simde_mm256_loadu_pd(test_vec[13].r), 1);

  a = simde_mm256_loadu_pd(test_vec[14].a);
  r = simde_mm256_roundscale_pd(a, INT32_C(         224));
  simde_test_x86_assert_equal_f64x4(r, simde_mm256_loadu_pd(test_vec[14].r), 1);

  a = simde_mm256_loadu_pd(test_vec[15].a);
  r = simde_mm256_roundscale_pd(a, INT32_C(         240));
  simde_test_x86_assert_equal_f64x4(r, simde_mm256_loadu_pd(test_vec[15].r), 1);

  a = simde_mm256_loadu_pd(test_vec[16].a);
  r = simde_mm256_roundscale_pd(a, INT32_C(           1));
  simde_test_x86_assert_equal_f64x4(r, simde_mm256_loadu_pd(test_vec[16].r), 1);

  a = simde_mm256_loadu_pd(test_vec[17].a);
  r = simde_mm256_roundscale_pd(a, INT32_C(          17));
  simde_test_x86_assert_equal_f64x4(r, simde_mm256_loadu_pd(test_vec[17].r), 1);

  a = simde_mm256_loadu_pd(test_vec[18].a);
  r = simde_mm256_roundscale_pd(a, INT32_C(          33));
  simde_test_x86_assert_equal_f64x4(r, simde_mm256_loadu_pd(test_vec[18].r), 1);

  a = simde_mm256_loadu_pd(test_vec[19].a);
  r = simde_mm256_roundscale_pd(a, INT32_C(          49));
  simde_test_x86_assert_equal_f64x4(r, simde_mm256_loadu_pd(test_vec[19].r), 1);

  a = simde_mm256_loadu_pd(test_vec[20].a);
  r = simde_mm256_roundscale_pd(a, INT32_C(          65));
  simde_test_x86_assert_equal_f64x4(r, simde_mm256_loadu_pd(test_vec[20].r), 1);

  a = simde_mm256_loadu_pd(test_vec[21].a);
  r = simde_mm256_roundscale_pd(a, INT32_C(          81));
  simde_test_x86_assert_equal_f64x4(r, simde_mm256_loadu_pd(test_vec[21].r), 1);

  a = simde_mm256_loadu_pd(test_vec[22].a);
  r = simde_mm256_roundscale_pd(a, INT32_C(          97));
  simde_test_x86_assert_equal_f64x4(r, simde_mm256_loadu_pd(test_vec[22].r), 1);

  a = simde_mm256_loadu_pd(test_vec[23].a);
  r = simde_mm256_roundscale_pd(a, INT32_C(         113));
  simde_test_x86_assert_equal_f64x4(r, simde_mm256_loadu_pd(test_vec[23].r), 1);

  a = simde_mm256_loadu_pd(test_vec[24].a);
  r = simde_mm256_roundscale_pd(a, INT32_C(         129));
  simde_test_x86_assert_equal_f64x4(r, simde_mm256_loadu_pd(test_vec[24].r), 1);

  a = simde_mm256_loadu_pd(test_vec[25].a);
  r = simde_mm256_roundscale_pd(a, INT32_C(         145));
  simde_test_x86_assert_equal_f64x4(r, simde_mm256_loadu_pd(test_vec[25].r), 1);

  a = simde_mm256_loadu_pd(test_vec[26].a);
  r = simde_mm256_roundscale_pd(a, INT32_C(         161));
  simde_test_x86_assert_equal_f64x4(r, simde_mm256_loadu_pd(test_vec[26].r), 1);

  a = simde_mm256_loadu_pd(test_vec[27].a);
  r = simde_mm256_roundscale_pd(a, INT32_C(         177));
  simde_test_x86_assert_equal_f64x4(r, simde_mm256_loadu_pd(test_vec[27].r), 1);

  a = simde_mm256_loadu_pd(test_vec[28].a);
  r = simde_mm256_roundscale_pd(a, INT32_C(         193));
  simde_test_x86_assert_equal_f64x4(r, simde_mm256_loadu_pd(test_vec[28].r), 1);

  a = simde_mm256_loadu_pd(test_vec[29].a);
  r = simde_mm256_roundscale_pd(a, INT32_C(         209));
  simde_test_x86_assert_equal_f64x4(r, simde_mm256_loadu_pd(test_vec[29].r), 1);

  a = simde_mm256_loadu_pd(test_vec[30].a);
  r = simde_mm256_roundscale_pd(a, INT32_C(         225));
  simde_test_x86_assert_equal_f64x4(r, simde_mm256_loadu_pd(test_vec[30].r), 1);

  a = simde_mm256_loadu_pd(test_vec[31].a);
  r = simde_mm256_roundscale_pd(a, INT32_C(         241));
  simde_test_x86_assert_equal_f64x4(r, simde_mm256_loadu_pd(test_vec[31].r), 1);

  a = simde_mm256_loadu_pd(test_vec[32].a);
  r = simde_mm256_roundscale_pd(a, INT32_C(           2));
  simde_test_x86_assert_equal_f64x4(r, simde_mm256_loadu_pd(test_vec[32].r), 1);

  a = simde_mm256_loadu_pd(test_vec[33].a);
  r = simde_mm256_roundscale_pd(a, INT32_C(          18));
  simde_test_x86_assert_equal_f64x4(r, simde_mm256_loadu_pd(test_vec[33].r), 1);

  a = simde_mm256_loadu_pd(test_vec[34].a);
  r = simde_mm256_roundscale_pd(a, INT32_C(          34));
  simde_test_x86_assert_equal_f64x4(r, simde_mm256_loadu_pd(test_vec[34].r), 1);

  a = simde_mm256_loadu_pd(test_vec[35].a);
  r = simde_mm256_roundscale_pd(a, INT32_C(          50));
  simde_test_x86_assert_equal_f64x4(r, simde_mm256_loadu_pd(test_vec[35].r), 1);

  a = simde_mm256_loadu_pd(test_vec[36].a);
  r = simde_mm256_roundscale_pd(a, INT32_C(          66));
  simde_test_x86_assert_equal_f64x4(r, simde_mm256_loadu_pd(test_vec[36].r), 1);

  a = simde_mm256_loadu_pd(test_vec[37].a);
  r = simde_mm256_roundscale_pd(a, INT32_C(          82));
  simde_test_x86_assert_equal_f64x4(r, simde_mm256_loadu_pd(test_vec[37].r), 1);

  a = simde_mm256_loadu_pd(test_vec[38].a);
  r = simde_mm256_roundscale_pd(a, INT32_C(          98));
  simde_test_x86_assert_equal_f64x4(r, simde_mm256_loadu_pd(test_vec[38].r), 1);

  a = simde_mm256_loadu_pd(test_vec[39].a);
  r = simde_mm256_roundscale_pd(a, INT32_C(         114));
  simde_test_x86_assert_equal_f64x4(r, simde_mm256_loadu_pd(test_vec[39].r), 1);

  a = simde_mm256_loadu_pd(test_vec[40].a);
  r = simde_mm256_roundscale_pd(a, INT32_C(         130));
  simde_test_x86_assert_equal_f64x4(r, simde_mm256_loadu_pd(test_vec[40].r), 1);

  a = simde_mm256_loadu_pd(test_vec[41].a);
  r = simde_mm256_roundscale_pd(a, INT32_C(         146));
  simde_test_x86_assert_equal_f64x4(r, simde_mm256_loadu_pd(test_vec[41].r), 1);

  a = simde_mm256_loadu_pd(test_vec[42].a);
  r = simde_mm256_roundscale_pd(a, INT32_C(         162));
  simde_test_x86_assert_equal_f64x4(r, simde_mm256_loadu_pd(test_vec[42].r), 1);

  a = simde_mm256_loadu_pd(test_vec[43].a);
  r = simde_mm256_roundscale_pd(a, INT32_C(         178));
  simde_test_x86_assert_equal_f64x4(r, simde_mm256_loadu_pd(test_vec[43].r), 1);

  a = simde_mm256_loadu_pd(test_vec[44].a);
  r = simde_mm256_roundscale_pd(a, INT32_C(         194));
  simde_test_x86_assert_equal_f64x4(r, simde_mm256_loadu_pd(test_vec[44].r), 1);

  a = simde_mm256_loadu_pd(test_vec[45].a);
  r = simde_mm256_roundscale_pd(a, INT32_C(         210));
  simde_test_x86_assert_equal_f64x4(r, simde_mm256_loadu_pd(test_vec[45].r), 1);

  a = simde_mm256_loadu_pd(test_vec[46].a);
  r = simde_mm256_roundscale_pd(a, INT32_C(         226));
  simde_test_x86_assert_equal_f64x4(r, simde_mm256_loadu_pd(test_vec[46].r), 1);

  a = simde_mm256_loadu_pd(test_vec[47].a);
  r = simde_mm256_roundscale_pd(a, INT32_C(         242));
  simde_test_x86_assert_equal_f64x4(r, simde_mm256_loadu_pd(test_vec[47].r), 1);

  a = simde_mm256_loadu_pd(test_vec[48].a);
  r = simde_mm256_roundscale_pd(a, INT32_C(           3));
  simde_test_x86_assert_equal_f64x4(r, simde_mm256_loadu_pd(test_vec[48].r), 1);

  a = simde_mm256_loadu_pd(test_vec[49].a);
  r = simde_mm256_roundscale_pd(a, INT32_C(          19));
  simde_test_x86_assert_equal_f64x4(r, simde_mm256_loadu_pd(test_vec[49].r), 1);

  a = simde_mm256_loadu_pd(test_vec[50].a);
  r = simde_mm256_roundscale_pd(a, INT32_C(          35));
  simde_test_x86_assert_equal_f64x4(r, simde_mm256_loadu_pd(test_vec[50].r), 1);

  a = simde_mm256_loadu_pd(test_vec[51].a);
  r = simde_mm256_roundscale_pd(a, INT32_C(          51));
  simde_test_x86_assert_equal_f64x4(r, simde_mm256_loadu_pd(test_vec[51].r), 1);

  a = simde_mm256_loadu_pd(test_vec[52].a);
  r = simde_mm256_roundscale_pd(a, INT32_C(          67));
  simde_test_x86_assert_equal_f64x4(r, simde_mm256_loadu_pd(test_vec[52].r), 1);

  a = simde_mm256_loadu_pd(test_vec[53].a);
  r = simde_mm256_roundscale_pd(a, INT32_C(          83));
  simde_test_x86_assert_equal_f64x4(r, simde_mm256_loadu_pd(test_vec[53].r), 1);

  a = simde_mm256_loadu_pd(test_vec[54].a);
  r = simde_mm256_roundscale_pd(a, INT32_C(          99));
  simde_test_x86_assert_equal_f64x4(r, simde_mm256_loadu_pd(test_vec[54].r), 1);

  a = simde_mm256_loadu_pd(test_vec[55].a);
  r = simde_mm256_roundscale_pd(a, INT32_C(         115));
  simde_test_x86_assert_equal_f64x4(r, simde_mm256_loadu_pd(test_vec[55].r), 1);

  a = simde_mm256_loadu_pd(test_vec[56].a);
  r = simde_mm256_roundscale_pd(a, INT32_C(         131));
  simde_test_x86_assert_equal_f64x4(r, simde_mm256_loadu_pd(test_vec[56].r), 1);

  a = simde_mm256_loadu_pd(test_vec[57].a);
  r = simde_mm256_roundscale_pd(a, INT32_C(         147));
  simde_test_x86_assert_equal_f64x4(r, simde_mm256_loadu_pd(test_vec[57].r), 1);

  a = simde_mm256_loadu_pd(test_vec[58].a);
  r = simde_mm256_roundscale_pd(a, INT32_C(         163));
  simde_test_x86_assert_equal_f64x4(r, simde_mm256_loadu_pd(test_vec[58].r), 1);

  a = simde_mm256_loadu_pd(test_vec[59].a);
  r = simde_mm256_roundscale_pd(a, INT32_C(         179));
  simde_test_x86_assert_equal_f64x4(r, simde_mm256_loadu_pd(test_vec[59].r), 1);

  a = simde_mm256_loadu_pd(test_vec[60].a);
  r = simde_mm256_roundscale_pd(a, INT32_C(         195));
  simde_test_x86_assert_equal_f64x4(r, simde_mm256_loadu_pd(test_vec[60].r), 1);

  a = simde_mm256_loadu_pd(test_vec[61].a);
  r = simde_mm256_roundscale_pd(a, INT32_C(         211));
  simde_test_x86_assert_equal_f64x4(r, simde_mm256_loadu_pd(test_vec[61].r), 1);

  a = simde_mm256_loadu_pd(test_vec[62].a);
  r = simde_mm256_roundscale_pd(a, INT32_C(         227));
  simde_test_x86_assert_equal_f64x4(r, simde_mm256_loadu_pd(test_vec[62].r), 1);

  a = simde_mm256_loadu_pd(test_vec[63].a);
  r = simde_mm256_roundscale_pd(a, INT32_C(         243));
  simde_test_x86_assert_equal_f64x4(r, simde_mm256_loadu_pd(test_vec[63].r), 1);

  a = simde_mm256_loadu_pd(test_vec[64].a);
  r = simde_mm256_roundscale_pd(a, INT32_C(           4));
  simde_test_x86_assert_equal_f64x4(r, simde_mm256_loadu_pd(test_vec[64].r), 1);

  a = simde_mm256_loadu_pd(test_vec[65].a);
  r = simde_mm256_roundscale_pd(a, INT32_C(          20));
  simde_test_x86_assert_equal_f64x4(r, simde_mm256_loadu_pd(test_vec[65].r), 1);

  a = simde_mm256_loadu_pd(test_vec[66].a);
  r = simde_mm256_roundscale_pd(a, INT32_C(          36));
  simde_test_x86_assert_equal_f64x4(r, simde_mm256_loadu_pd(test_vec[66].r), 1);

  a = simde_mm256_loadu_pd(test_vec[67].a);
  r = simde_mm256_roundscale_pd(a, INT32_C(          52));
  simde_test_x86_assert_equal_f64x4(r, simde_mm256_loadu_pd(test_vec[67].r), 1);

  a = simde_mm256_loadu_pd(test_vec[68].a);
  r = simde_mm256_roundscale_pd(a, INT32_C(          68));
  simde_test_x86_assert_equal_f64x4(r, simde_mm256_loadu_pd(test_vec[68].r), 1);

  a = simde_mm256_loadu_pd(test_vec[69].a);
  r = simde_mm256_roundscale_pd(a, INT32_C(          84));
  simde_test_x86_assert_equal_f64x4(r, simde_mm256_loadu_pd(test_vec[69].r), 1);

  a = simde_mm256_loadu_pd(test_vec[70].a);
  r = simde_mm256_roundscale_pd(a, INT32_C(         100));
  simde_test_x86_assert_equal_f64x4(r, simde_mm256_loadu_pd(test_vec[70].r), 1);

  a = simde_mm256_loadu_pd(test_vec[71].a);
  r = simde_mm256_roundscale_pd(a, INT32_C(         116));
  simde_test_x86_assert_equal_f64x4(r, simde_mm256_loadu_pd(test_vec[71].r), 1);

  a = simde_mm256_loadu_pd(test_vec[72].a);
  r = simde_mm256_roundscale_pd(a, INT32_C(         132));
  simde_test_x86_assert_equal_f64x4(r, simde_mm256_loadu_pd(test_vec[72].r), 1);

  a = simde_mm256_loadu_pd(test_vec[73].a);
  r = simde_mm256_roundscale_pd(a, INT32_C(         148));
  simde_test_x86_assert_equal_f64x4(r, simde_mm256_loadu_pd(test_vec[73].r), 1);

  a = simde_mm256_loadu_pd(test_vec[74].a);
  r = simde_mm256_roundscale_pd(a, INT32_C(         164));
  simde_test_x86_assert_equal_f64x4(r, simde_mm256_loadu_pd(test_vec[74].r), 1);

  a = simde_mm256_loadu_pd(test_vec[75].a);
  r = simde_mm256_roundscale_pd(a, INT32_C(         180));
  simde_test_x86_assert_equal_f64x4(r, simde_mm256_loadu_pd(test_vec[75].r), 1);

  a = simde_mm256_loadu_pd(test_vec[76].a);
  r = simde_mm256_roundscale_pd(a, INT32_C(         196));
  simde_test_x86_assert_equal_f64x4(r, simde_mm256_loadu_pd(test_vec[76].r), 1);

  a = simde_mm256_loadu_pd(test_vec[77].a);
  r = simde_mm256_roundscale_pd(a, INT32_C(         212));
  simde_test_x86_assert_equal_f64x4(r, simde_mm256_loadu_pd(test_vec[77].r), 1);

  a = simde_mm256_loadu_pd(test_vec[78].a);
  r = simde_mm256_roundscale_pd(a, INT32_C(         228));
  simde_test_x86_assert_equal_f64x4(r, simde_mm256_loadu_pd(test_vec[78].r), 1);

  a = simde_mm256_loadu_pd(test_vec[79].a);
  r = simde_mm256_roundscale_pd(a, INT32_C(         244));
  simde_test_x86_assert_equal_f64x4(r, simde_mm256_loadu_pd(test_vec[79].r), 1);

  return 0;
#else
  fputc('\n', stdout);
  int round_type[5] = {SIMDE_MM_FROUND_TO_NEAREST_INT, SIMDE_MM_FROUND_TO_NEG_INF, SIMDE_MM_FROUND_TO_POS_INF, SIMDE_MM_FROUND_TO_ZERO, SIMDE_MM_FROUND_CUR_DIRECTION};
  for (int i = 0 ; i < 5 ; i++) {
    for (int j = 0 ; j < 16 ; j++) {
      simde__m256d a = simde_test_x86_random_f64x4(SIMDE_FLOAT64_C(-1000.0), SIMDE_FLOAT64_C(1000.0));
      if((simde_test_codegen_rand() & 1)) {
        if((simde_test_codegen_rand() & 1))
          a = simde_mm256_blend_pd(a, simde_mm256_set1_pd(SIMDE_MATH_NAN), 1);
        else {
          if((simde_test_codegen_rand() & 1))
            a = simde_mm256_blend_pd(a, simde_mm256_set1_pd(SIMDE_MATH_INFINITY), 2);
          else
            a = simde_mm256_blend_pd(a, simde_mm256_set1_pd(-SIMDE_MATH_INFINITY), 2);
        }
      }
      int imm8 = ((j << 4) | round_type[i]) & 255;
      simde__m256d r;
      SIMDE_CONSTIFY_256_(simde_mm256_roundscale_pd, r, simde_mm256_setzero_pd(), imm8, a);

      simde_test_x86_write_f64x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
      simde_test_codegen_write_i32(2, imm8, SIMDE_TEST_VEC_POS_MIDDLE);
      simde_test_x86_write_f64x4(2, r, SIMDE_TEST_VEC_POS_LAST);
    }
  }
  return 1;
#endif
}

static int
test_simde_mm256_mask_roundscale_pd (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const simde_float64 src[4];
    const simde__mmask8 k;
    const simde_float64 a[4];
    const int32_t imm8;
    const simde_float64 r[4];
  } test_vec[] = {
    { { SIMDE_FLOAT64_C(   926.29), SIMDE_FLOAT64_C(   909.09), SIMDE_FLOAT64_C(   774.77), SIMDE_FLOAT64_C(   372.04) },
      UINT8_C(125),
      { SIMDE_FLOAT64_C(   458.74), SIMDE_FLOAT64_C(  -735.76), SIMDE_FLOAT64_C(   634.56), SIMDE_FLOAT64_C(   216.61) },
       INT32_C(          32),
      { SIMDE_FLOAT64_C(   458.75), SIMDE_FLOAT64_C(   909.09), SIMDE_FLOAT64_C(   634.50), SIMDE_FLOAT64_C(   216.50) } },
    { { SIMDE_FLOAT64_C(   808.28), SIMDE_FLOAT64_C(  -973.92), SIMDE_FLOAT64_C(   364.29), SIMDE_FLOAT64_C(   260.83) },
      UINT8_C( 21),
      { SIMDE_FLOAT64_C(   685.29), SIMDE_FLOAT64_C(  -217.73), SIMDE_FLOAT64_C(   979.97), SIMDE_FLOAT64_C(   463.75) },
       INT32_C(          81),
      { SIMDE_FLOAT64_C(   685.28), SIMDE_FLOAT64_C(  -973.92), SIMDE_FLOAT64_C(   979.97), SIMDE_FLOAT64_C(   260.83) } },
    { { SIMDE_FLOAT64_C(   526.14), SIMDE_FLOAT64_C(   931.62), SIMDE_FLOAT64_C(   993.03), SIMDE_FLOAT64_C(   390.55) },
      UINT8_C( 90),
      { SIMDE_FLOAT64_C(  -182.65),        SIMDE_MATH_INFINITY, SIMDE_FLOAT64_C(   177.32), SIMDE_FLOAT64_C(  -823.86) },
       INT32_C(          18),
      { SIMDE_FLOAT64_C(   526.14),        SIMDE_MATH_INFINITY, SIMDE_FLOAT64_C(   993.03), SIMDE_FLOAT64_C(  -823.50) } },
    { { SIMDE_FLOAT64_C(    34.50), SIMDE_FLOAT64_C(   409.65), SIMDE_FLOAT64_C(  -471.60), SIMDE_FLOAT64_C(  -330.93) },
      UINT8_C(230),
      { SIMDE_FLOAT64_C(  -757.14), SIMDE_FLOAT64_C(  -817.96), SIMDE_FLOAT64_C(  -565.47), SIMDE_FLOAT64_C(  -731.06) },
       INT32_C(         163),
      { SIMDE_FLOAT64_C(    34.50), SIMDE_FLOAT64_C(  -817.96), SIMDE_FLOAT64_C(  -565.47), SIMDE_FLOAT64_C(  -330.93) } },
    { { SIMDE_FLOAT64_C(  -509.07), SIMDE_FLOAT64_C(   231.61), SIMDE_FLOAT64_C(  -522.37), SIMDE_FLOAT64_C(  -529.09) },
      UINT8_C( 55),
      {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(   -49.42), SIMDE_FLOAT64_C(  -778.50), SIMDE_FLOAT64_C(   394.59) },
       INT32_C(          84),
      {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(   -49.41), SIMDE_FLOAT64_C(  -778.50), SIMDE_FLOAT64_C(  -529.09) } },
    { { SIMDE_FLOAT64_C(   760.96), SIMDE_FLOAT64_C(  -422.11), SIMDE_FLOAT64_C(  -513.55), SIMDE_FLOAT64_C(   937.10) },
      UINT8_C( 63),
      { SIMDE_FLOAT64_C(   572.86), SIMDE_FLOAT64_C(   888.00), SIMDE_FLOAT64_C(   734.18), SIMDE_FLOAT64_C(  -392.63) },
       INT32_C(          80),
      { SIMDE_FLOAT64_C(   572.88), SIMDE_FLOAT64_C(   888.00), SIMDE_FLOAT64_C(   734.19), SIMDE_FLOAT64_C(  -392.62) } },
    { { SIMDE_FLOAT64_C(   276.43), SIMDE_FLOAT64_C(   923.91), SIMDE_FLOAT64_C(  -494.56), SIMDE_FLOAT64_C(   458.47) },
      UINT8_C(252),
      { SIMDE_FLOAT64_C(  -225.62),        SIMDE_MATH_INFINITY, SIMDE_FLOAT64_C(  -946.20), SIMDE_FLOAT64_C(   265.31) },
       INT32_C(          65),
      { SIMDE_FLOAT64_C(   276.43), SIMDE_FLOAT64_C(   923.91), SIMDE_FLOAT64_C(  -946.25), SIMDE_FLOAT64_C(   265.25) } },
    { { SIMDE_FLOAT64_C(   994.40), SIMDE_FLOAT64_C(  -313.20), SIMDE_FLOAT64_C(   153.28), SIMDE_FLOAT64_C(   388.99) },
      UINT8_C(122),
      {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(  -301.89), SIMDE_FLOAT64_C(   391.38), SIMDE_FLOAT64_C(   343.23) },
       INT32_C(         178),
      { SIMDE_FLOAT64_C(   994.40), SIMDE_FLOAT64_C(  -301.89), SIMDE_FLOAT64_C(   153.28), SIMDE_FLOAT64_C(   343.23) } },
  };

  simde__m256d src, a, r;

  src = simde_mm256_loadu_pd(test_vec[0].src);
  a = simde_mm256_loadu_pd(test_vec[0].a);
  r = simde_mm256_mask_roundscale_pd(src, test_vec[0].k, a, INT32_C(          32));
  simde_test_x86_assert_equal_f64x4(r, simde_mm256_loadu_pd(test_vec[0].r), 1);

  src = simde_mm256_loadu_pd(test_vec[1].src);
  a = simde_mm256_loadu_pd(test_vec[1].a);
  r = simde_mm256_mask_roundscale_pd(src, test_vec[1].k, a, INT32_C(          81));
  simde_test_x86_assert_equal_f64x4(r, simde_mm256_loadu_pd(test_vec[1].r), 1);

  src = simde_mm256_loadu_pd(test_vec[2].src);
  a = simde_mm256_loadu_pd(test_vec[2].a);
  r = simde_mm256_mask_roundscale_pd(src, test_vec[2].k, a, INT32_C(          18));
  simde_test_x86_assert_equal_f64x4(r, simde_mm256_loadu_pd(test_vec[2].r), 1);

  src = simde_mm256_loadu_pd(test_vec[3].src);
  a = simde_mm256_loadu_pd(test_vec[3].a);
  r = simde_mm256_mask_roundscale_pd(src, test_vec[3].k, a, INT32_C(         163));
  simde_test_x86_assert_equal_f64x4(r, simde_mm256_loadu_pd(test_vec[3].r), 1);

  src = simde_mm256_loadu_pd(test_vec[4].src);
  a = simde_mm256_loadu_pd(test_vec[4].a);
  r = simde_mm256_mask_roundscale_pd(src, test_vec[4].k, a, INT32_C(          84));
  simde_test_x86_assert_equal_f64x4(r, simde_mm256_loadu_pd(test_vec[4].r), 1);

  src = simde_mm256_loadu_pd(test_vec[5].src);
  a = simde_mm256_loadu_pd(test_vec[5].a);
  r = simde_mm256_mask_roundscale_pd(src, test_vec[5].k, a, INT32_C(          80));
  simde_test_x86_assert_equal_f64x4(r, simde_mm256_loadu_pd(test_vec[5].r), 1);

  src = simde_mm256_loadu_pd(test_vec[6].src);
  a = simde_mm256_loadu_pd(test_vec[6].a);
  r = simde_mm256_mask_roundscale_pd(src, test_vec[6].k, a, INT32_C(          65));
  simde_test_x86_assert_equal_f64x4(r, simde_mm256_loadu_pd(test_vec[6].r), 1);

  src = simde_mm256_loadu_pd(test_vec[7].src);
  a = simde_mm256_loadu_pd(test_vec[7].a);
  r = simde_mm256_mask_roundscale_pd(src, test_vec[7].k, a, INT32_C(         178));
  simde_test_x86_assert_equal_f64x4(r, simde_mm256_loadu_pd(test_vec[7].r), 1);

  return 0;
#else
  fputc('\n', stdout);
  int round_type[5] = {SIMDE_MM_FROUND_TO_NEAREST_INT, SIMDE_MM_FROUND_TO_NEG_INF, SIMDE_MM_FROUND_TO_POS_INF, SIMDE_MM_FROUND_TO_ZERO, SIMDE_MM_FROUND_CUR_DIRECTION};
  for (int i = 0 ; i < 8 ; i++) {
    simde__m256d src = simde_test_x86_random_f64x4(SIMDE_FLOAT64_C(-1000.0), SIMDE_FLOAT64_C(1000.0));
    simde__mmask8 k = simde_test_x86_random_mmask8();
    simde__m256d a = simde_test_x86_random_f64x4(SIMDE_FLOAT64_C(-1000.0), SIMDE_FLOAT64_C(1000.0));
    if((simde_test_codegen_rand() & 1)) {
      if((simde_test_codegen_rand() & 1))
        a = simde_mm256_blend_pd(a, simde_mm256_set1_pd(SIMDE_MATH_NAN), 1);
      else {
        if((simde_test_codegen_rand() & 1))
          a = simde_mm256_blend_pd(a, simde_mm256_set1_pd(SIMDE_MATH_INFINITY), 2);
        else
          a = simde_mm256_blend_pd(a, simde_mm256_set1_pd(-SIMDE_MATH_INFINITY), 2);
      }
    }
    int imm8 = (((simde_test_codegen_rand() & 15) << 4) | round_type[i % 5]) & 255;
    simde__m256d r;
    SIMDE_CONSTIFY_256_(simde_mm256_mask_roundscale_pd, r, simde_mm256_setzero_pd(), imm8, src, k, a);

    simde_test_x86_write_f64x4(2, src, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_mmask8(2, k, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_f64x4(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i32(2, imm8, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_f64x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm256_maskz_roundscale_pd (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const simde__mmask8 k;
    const simde_float64 a[4];
    const int32_t imm8;
    const simde_float64 r[4];
  } test_vec[] = {
    { UINT8_C(131),
      {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(  -452.58), SIMDE_FLOAT64_C(   364.79), SIMDE_FLOAT64_C(  -485.87) },
       INT32_C(         144),
      {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(  -452.58), SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(     0.00) } },
    { UINT8_C(237),
      { SIMDE_FLOAT64_C(  -900.30), SIMDE_FLOAT64_C(  -203.53), SIMDE_FLOAT64_C(  -910.18), SIMDE_FLOAT64_C(   104.50) },
       INT32_C(         161),
      { SIMDE_FLOAT64_C(  -900.30), SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(  -910.18), SIMDE_FLOAT64_C(   104.50) } },
    { UINT8_C(139),
      { SIMDE_FLOAT64_C(   381.69), SIMDE_FLOAT64_C(    91.35), SIMDE_FLOAT64_C(  -727.30), SIMDE_FLOAT64_C(   376.09) },
       INT32_C(         146),
      { SIMDE_FLOAT64_C(   381.69), SIMDE_FLOAT64_C(    91.35), SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(   376.09) } },
    { UINT8_C(120),
      { SIMDE_FLOAT64_C(   408.57), SIMDE_FLOAT64_C(  -808.69), SIMDE_FLOAT64_C(   463.20), SIMDE_FLOAT64_C(  -200.06) },
       INT32_C(         211),
      { SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(  -200.06) } },
    { UINT8_C(226),
      {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(   405.18), SIMDE_FLOAT64_C(   344.89), SIMDE_FLOAT64_C(  -104.81) },
       INT32_C(          68),
      { SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(   405.19), SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(     0.00) } },
    { UINT8_C(234),
      { SIMDE_FLOAT64_C(  -702.95), SIMDE_FLOAT64_C(    20.62), SIMDE_FLOAT64_C(   510.88), SIMDE_FLOAT64_C(    93.52) },
       INT32_C(          32),
      { SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(    20.50), SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(    93.50) } },
    { UINT8_C(113),
      { SIMDE_FLOAT64_C(  -534.43), SIMDE_FLOAT64_C(   956.30), SIMDE_FLOAT64_C(   325.48), SIMDE_FLOAT64_C(   556.92) },
       INT32_C(         209),
      { SIMDE_FLOAT64_C(  -534.43), SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(     0.00) } },
    { UINT8_C(169),
      { SIMDE_FLOAT64_C(   654.97), SIMDE_FLOAT64_C(   466.66), SIMDE_FLOAT64_C(  -256.36), SIMDE_FLOAT64_C(   846.28) },
       INT32_C(          50),
      { SIMDE_FLOAT64_C(   655.00), SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(   846.38) } },
  };

  simde__m256d a, r;

  a = simde_mm256_loadu_pd(test_vec[0].a);
  r = simde_mm256_maskz_roundscale_pd(test_vec[0].k, a, INT32_C(         144));
  simde_test_x86_assert_equal_f64x4(r, simde_mm256_loadu_pd(test_vec[0].r), 1);

  a = simde_mm256_loadu_pd(test_vec[1].a);
  r = simde_mm256_maskz_roundscale_pd(test_vec[1].k, a, INT32_C(         161));
  simde_test_x86_assert_equal_f64x4(r, simde_mm256_loadu_pd(test_vec[1].r), 1);

  a = simde_mm256_loadu_pd(test_vec[2].a);
  r = simde_mm256_maskz_roundscale_pd(test_vec[2].k, a, INT32_C(         146));
  simde_test_x86_assert_equal_f64x4(r, simde_mm256_loadu_pd(test_vec[2].r), 1);

  a = simde_mm256_loadu_pd(test_vec[3].a);
  r = simde_mm256_maskz_roundscale_pd(test_vec[3].k, a, INT32_C(         211));
  simde_test_x86_assert_equal_f64x4(r, simde_mm256_loadu_pd(test_vec[3].r), 1);

  a = simde_mm256_loadu_pd(test_vec[4].a);
  r = simde_mm256_maskz_roundscale_pd(test_vec[4].k, a, INT32_C(          68));
  simde_test_x86_assert_equal_f64x4(r, simde_mm256_loadu_pd(test_vec[4].r), 1);

  a = simde_mm256_loadu_pd(test_vec[5].a);
  r = simde_mm256_maskz_roundscale_pd(test_vec[5].k, a, INT32_C(          32));
  simde_test_x86_assert_equal_f64x4(r, simde_mm256_loadu_pd(test_vec[5].r), 1);

  a = simde_mm256_loadu_pd(test_vec[6].a);
  r = simde_mm256_maskz_roundscale_pd(test_vec[6].k, a, INT32_C(         209));
  simde_test_x86_assert_equal_f64x4(r, simde_mm256_loadu_pd(test_vec[6].r), 1);

  a = simde_mm256_loadu_pd(test_vec[7].a);
  r = simde_mm256_maskz_roundscale_pd(test_vec[7].k, a, INT32_C(          50));
  simde_test_x86_assert_equal_f64x4(r, simde_mm256_loadu_pd(test_vec[7].r), 1);

  return 0;
#else
  fputc('\n', stdout);
  int round_type[5] = {SIMDE_MM_FROUND_TO_NEAREST_INT, SIMDE_MM_FROUND_TO_NEG_INF, SIMDE_MM_FROUND_TO_POS_INF, SIMDE_MM_FROUND_TO_ZERO, SIMDE_MM_FROUND_CUR_DIRECTION};
  for (int i = 0 ; i < 8 ; i++) {
    simde__mmask8 k = simde_test_x86_random_mmask8();
    simde__m256d a = simde_test_x86_random_f64x4(SIMDE_FLOAT64_C(-1000.0), SIMDE_FLOAT64_C(1000.0));
    if((simde_test_codegen_rand() & 1)) {
      if((simde_test_codegen_rand() & 1))
        a = simde_mm256_blend_pd(a, simde_mm256_set1_pd(SIMDE_MATH_NAN), 1);
      else {
        if((simde_test_codegen_rand() & 1))
          a = simde_mm256_blend_pd(a, simde_mm256_set1_pd(SIMDE_MATH_INFINITY), 2);
        else
          a = simde_mm256_blend_pd(a, simde_mm256_set1_pd(-SIMDE_MATH_INFINITY), 2);
      }
    }
    int imm8 = (((simde_test_codegen_rand() & 15) << 4) | round_type[i % 5]) & 255;
    simde__m256d r;
    SIMDE_CONSTIFY_256_(simde_mm256_maskz_roundscale_pd, r, simde_mm256_setzero_pd(), imm8, k, a);

    simde_test_x86_write_mmask8(2, k, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_f64x4(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i32(2, imm8, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_f64x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm512_roundscale_pd (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const simde_float64 a[8];
    const int32_t imm8;
    const simde_float64 r[8];
  } test_vec[] = {
    { { SIMDE_FLOAT64_C(   646.70), SIMDE_FLOAT64_C(   958.12), SIMDE_FLOAT64_C(  -525.88), SIMDE_FLOAT64_C(    75.95),
        SIMDE_FLOAT64_C(   700.03), SIMDE_FLOAT64_C(  -818.76), SIMDE_FLOAT64_C(  -477.50), SIMDE_FLOAT64_C(  -567.75) },
       INT32_C(           0),
      { SIMDE_FLOAT64_C(   647.00), SIMDE_FLOAT64_C(   958.00), SIMDE_FLOAT64_C(  -526.00), SIMDE_FLOAT64_C(    76.00),
        SIMDE_FLOAT64_C(   700.00), SIMDE_FLOAT64_C(  -819.00), SIMDE_FLOAT64_C(  -478.00), SIMDE_FLOAT64_C(  -568.00) } },
    { {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(  -954.82), SIMDE_FLOAT64_C(   490.74), SIMDE_FLOAT64_C(   590.75),
        SIMDE_FLOAT64_C(   256.04), SIMDE_FLOAT64_C(     2.39), SIMDE_FLOAT64_C(  -125.09), SIMDE_FLOAT64_C(   538.23) },
       INT32_C(          16),
      {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(  -955.00), SIMDE_FLOAT64_C(   490.50), SIMDE_FLOAT64_C(   591.00),
        SIMDE_FLOAT64_C(   256.00), SIMDE_FLOAT64_C(     2.50), SIMDE_FLOAT64_C(  -125.00), SIMDE_FLOAT64_C(   538.00) } },
    { { SIMDE_FLOAT64_C(   838.29), SIMDE_FLOAT64_C(  -236.77), SIMDE_FLOAT64_C(  -534.48), SIMDE_FLOAT64_C(  -282.31),
        SIMDE_FLOAT64_C(     5.53), SIMDE_FLOAT64_C(    43.17), SIMDE_FLOAT64_C(   489.31), SIMDE_FLOAT64_C(  -307.21) },
       INT32_C(          32),
      { SIMDE_FLOAT64_C(   838.25), SIMDE_FLOAT64_C(  -236.75), SIMDE_FLOAT64_C(  -534.50), SIMDE_FLOAT64_C(  -282.25),
        SIMDE_FLOAT64_C(     5.50), SIMDE_FLOAT64_C(    43.25), SIMDE_FLOAT64_C(   489.25), SIMDE_FLOAT64_C(  -307.25) } },
    { { SIMDE_FLOAT64_C(  -796.64), SIMDE_FLOAT64_C(   103.62), SIMDE_FLOAT64_C(  -723.76), SIMDE_FLOAT64_C(   850.06),
        SIMDE_FLOAT64_C(    61.73), SIMDE_FLOAT64_C(  -249.64), SIMDE_FLOAT64_C(   -73.99), SIMDE_FLOAT64_C(  -238.23) },
       INT32_C(          48),
      { SIMDE_FLOAT64_C(  -796.62), SIMDE_FLOAT64_C(   103.62), SIMDE_FLOAT64_C(  -723.75), SIMDE_FLOAT64_C(   850.00),
        SIMDE_FLOAT64_C(    61.75), SIMDE_FLOAT64_C(  -249.62), SIMDE_FLOAT64_C(   -74.00), SIMDE_FLOAT64_C(  -238.25) } },
    { { SIMDE_FLOAT64_C(   448.51), SIMDE_FLOAT64_C(   194.02), SIMDE_FLOAT64_C(   247.85), SIMDE_FLOAT64_C(  -445.94),
        SIMDE_FLOAT64_C(   239.20), SIMDE_FLOAT64_C(  -261.42), SIMDE_FLOAT64_C(  -855.19), SIMDE_FLOAT64_C(  -504.76) },
       INT32_C(          64),
      { SIMDE_FLOAT64_C(   448.50), SIMDE_FLOAT64_C(   194.00), SIMDE_FLOAT64_C(   247.88), SIMDE_FLOAT64_C(  -445.94),
        SIMDE_FLOAT64_C(   239.19), SIMDE_FLOAT64_C(  -261.44), SIMDE_FLOAT64_C(  -855.19), SIMDE_FLOAT64_C(  -504.75) } },
    { {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(  -966.53), SIMDE_FLOAT64_C(    -6.53), SIMDE_FLOAT64_C(   713.46),
        SIMDE_FLOAT64_C(   871.76), SIMDE_FLOAT64_C(   756.71), SIMDE_FLOAT64_C(  -821.02), SIMDE_FLOAT64_C(  -410.55) },
       INT32_C(          80),
      {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(  -966.53), SIMDE_FLOAT64_C(    -6.53), SIMDE_FLOAT64_C(   713.47),
        SIMDE_FLOAT64_C(   871.75), SIMDE_FLOAT64_C(   756.72), SIMDE_FLOAT64_C(  -821.03), SIMDE_FLOAT64_C(  -410.56) } },
    { { SIMDE_FLOAT64_C(  -921.24),       -SIMDE_MATH_INFINITY, SIMDE_FLOAT64_C(  -739.11), SIMDE_FLOAT64_C(  -717.88),
        SIMDE_FLOAT64_C(  -441.36), SIMDE_FLOAT64_C(  -462.87), SIMDE_FLOAT64_C(  -867.82), SIMDE_FLOAT64_C(   620.37) },
       INT32_C(          96),
      { SIMDE_FLOAT64_C(  -921.23),       -SIMDE_MATH_INFINITY, SIMDE_FLOAT64_C(  -739.11), SIMDE_FLOAT64_C(  -717.88),
        SIMDE_FLOAT64_C(  -441.36), SIMDE_FLOAT64_C(  -462.88), SIMDE_FLOAT64_C(  -867.81), SIMDE_FLOAT64_C(   620.38) } },
    { { SIMDE_FLOAT64_C(  -780.91), SIMDE_FLOAT64_C(  -493.29), SIMDE_FLOAT64_C(   576.16), SIMDE_FLOAT64_C(   466.93),
        SIMDE_FLOAT64_C(    60.77), SIMDE_FLOAT64_C(  -184.64), SIMDE_FLOAT64_C(  -794.48), SIMDE_FLOAT64_C(   205.58) },
       INT32_C(         112),
      { SIMDE_FLOAT64_C(  -780.91), SIMDE_FLOAT64_C(  -493.29), SIMDE_FLOAT64_C(   576.16), SIMDE_FLOAT64_C(   466.93),
        SIMDE_FLOAT64_C(    60.77), SIMDE_FLOAT64_C(  -184.64), SIMDE_FLOAT64_C(  -794.48), SIMDE_FLOAT64_C(   205.58) } },
    { { SIMDE_FLOAT64_C(   946.49), SIMDE_FLOAT64_C(  -774.70), SIMDE_FLOAT64_C(   344.06), SIMDE_FLOAT64_C(   -60.04),
        SIMDE_FLOAT64_C(   938.76), SIMDE_FLOAT64_C(   215.82), SIMDE_FLOAT64_C(  -303.33), SIMDE_FLOAT64_C(  -882.26) },
       INT32_C(         128),
      { SIMDE_FLOAT64_C(   946.49), SIMDE_FLOAT64_C(  -774.70), SIMDE_FLOAT64_C(   344.06), SIMDE_FLOAT64_C(   -60.04),
        SIMDE_FLOAT64_C(   938.76), SIMDE_FLOAT64_C(   215.82), SIMDE_FLOAT64_C(  -303.33), SIMDE_FLOAT64_C(  -882.26) } },
    { {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(   339.89), SIMDE_FLOAT64_C(   884.03), SIMDE_FLOAT64_C(   -86.07),
        SIMDE_FLOAT64_C(   600.78), SIMDE_FLOAT64_C(  -833.84), SIMDE_FLOAT64_C(   472.57), SIMDE_FLOAT64_C(  -862.09) },
       INT32_C(         144),
      {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(   339.89), SIMDE_FLOAT64_C(   884.03), SIMDE_FLOAT64_C(   -86.07),
        SIMDE_FLOAT64_C(   600.78), SIMDE_FLOAT64_C(  -833.84), SIMDE_FLOAT64_C(   472.57), SIMDE_FLOAT64_C(  -862.09) } },
    { {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(   356.53), SIMDE_FLOAT64_C(   475.08), SIMDE_FLOAT64_C(   644.49),
        SIMDE_FLOAT64_C(   863.24), SIMDE_FLOAT64_C(    51.24), SIMDE_FLOAT64_C(   111.42), SIMDE_FLOAT64_C(   -75.99) },
       INT32_C(         160),
      {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(   356.53), SIMDE_FLOAT64_C(   475.08), SIMDE_FLOAT64_C(   644.49),
        SIMDE_FLOAT64_C(   863.24), SIMDE_FLOAT64_C(    51.24), SIMDE_FLOAT64_C(   111.42), SIMDE_FLOAT64_C(   -75.99) } },
    { {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(   177.19), SIMDE_FLOAT64_C(   263.43), SIMDE_FLOAT64_C(  -645.10),
        SIMDE_FLOAT64_C(  -478.75), SIMDE_FLOAT64_C(  -796.61), SIMDE_FLOAT64_C(  -706.34), SIMDE_FLOAT64_C(   737.08) },
       INT32_C(         176),
      {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(   177.19), SIMDE_FLOAT64_C(   263.43), SIMDE_FLOAT64_C(  -645.10),
        SIMDE_FLOAT64_C(  -478.75), SIMDE_FLOAT64_C(  -796.61), SIMDE_FLOAT64_C(  -706.34), SIMDE_FLOAT64_C(   737.08) } },
    { { SIMDE_FLOAT64_C(   542.35), SIMDE_FLOAT64_C(  -641.04), SIMDE_FLOAT64_C(   751.29), SIMDE_FLOAT64_C(   426.38),
        SIMDE_FLOAT64_C(   272.89), SIMDE_FLOAT64_C(   352.07), SIMDE_FLOAT64_C(   592.54), SIMDE_FLOAT64_C(  -254.53) },
       INT32_C(         192),
      { SIMDE_FLOAT64_C(   542.35), SIMDE_FLOAT64_C(  -641.04), SIMDE_FLOAT64_C(   751.29), SIMDE_FLOAT64_C(   426.38),
        SIMDE_FLOAT64_C(   272.89), SIMDE_FLOAT64_C(   352.07), SIMDE_FLOAT64_C(   592.54), SIMDE_FLOAT64_C(  -254.53) } },
    { { SIMDE_FLOAT64_C(   890.88), SIMDE_FLOAT64_C(   838.41), SIMDE_FLOAT64_C(   -84.62), SIMDE_FLOAT64_C(   247.41),
        SIMDE_FLOAT64_C(   313.49), SIMDE_FLOAT64_C(  -440.13), SIMDE_FLOAT64_C(   110.66), SIMDE_FLOAT64_C(  -635.26) },
       INT32_C(         208),
      { SIMDE_FLOAT64_C(   890.88), SIMDE_FLOAT64_C(   838.41), SIMDE_FLOAT64_C(   -84.62), SIMDE_FLOAT64_C(   247.41),
        SIMDE_FLOAT64_C(   313.49), SIMDE_FLOAT64_C(  -440.13), SIMDE_FLOAT64_C(   110.66), SIMDE_FLOAT64_C(  -635.26) } },
    { { SIMDE_FLOAT64_C(  -965.33), SIMDE_FLOAT64_C(  -768.67), SIMDE_FLOAT64_C(   -11.77), SIMDE_FLOAT64_C(  -835.73),
        SIMDE_FLOAT64_C(   408.53), SIMDE_FLOAT64_C(  -748.34), SIMDE_FLOAT64_C(  -480.84), SIMDE_FLOAT64_C(   929.78) },
       INT32_C(         224),
      { SIMDE_FLOAT64_C(  -965.33), SIMDE_FLOAT64_C(  -768.67), SIMDE_FLOAT64_C(   -11.77), SIMDE_FLOAT64_C(  -835.73),
        SIMDE_FLOAT64_C(   408.53), SIMDE_FLOAT64_C(  -748.34), SIMDE_FLOAT64_C(  -480.84), SIMDE_FLOAT64_C(   929.78) } },
    { { SIMDE_FLOAT64_C(  -187.18), SIMDE_FLOAT64_C(   666.86), SIMDE_FLOAT64_C(   355.11), SIMDE_FLOAT64_C(   224.22),
        SIMDE_FLOAT64_C(   209.21), SIMDE_FLOAT64_C(   714.08), SIMDE_FLOAT64_C(   -24.49), SIMDE_FLOAT64_C(  -364.41) },
       INT32_C(         240),
      { SIMDE_FLOAT64_C(  -187.18), SIMDE_FLOAT64_C(   666.86), SIMDE_FLOAT64_C(   355.11), SIMDE_FLOAT64_C(   224.22),
        SIMDE_FLOAT64_C(   209.21), SIMDE_FLOAT64_C(   714.08), SIMDE_FLOAT64_C(   -24.49), SIMDE_FLOAT64_C(  -364.41) } },
    { { SIMDE_FLOAT64_C(  -672.42), SIMDE_FLOAT64_C(  -771.87), SIMDE_FLOAT64_C(   732.44), SIMDE_FLOAT64_C(   817.56),
        SIMDE_FLOAT64_C(  -880.99), SIMDE_FLOAT64_C(   570.85), SIMDE_FLOAT64_C(  -267.07), SIMDE_FLOAT64_C(   366.42) },
       INT32_C(           1),
      { SIMDE_FLOAT64_C(  -673.00), SIMDE_FLOAT64_C(  -772.00), SIMDE_FLOAT64_C(   732.00), SIMDE_FLOAT64_C(   817.00),
        SIMDE_FLOAT64_C(  -881.00), SIMDE_FLOAT64_C(   570.00), SIMDE_FLOAT64_C(  -268.00), SIMDE_FLOAT64_C(   366.00) } },
    { { SIMDE_FLOAT64_C(   292.80), SIMDE_FLOAT64_C(  -522.92), SIMDE_FLOAT64_C(   249.08), SIMDE_FLOAT64_C(   -35.91),
        SIMDE_FLOAT64_C(  -488.25), SIMDE_FLOAT64_C(   480.41), SIMDE_FLOAT64_C(   952.32), SIMDE_FLOAT64_C(  -323.98) },
       INT32_C(          17),
      { SIMDE_FLOAT64_C(   292.50), SIMDE_FLOAT64_C(  -523.00), SIMDE_FLOAT64_C(   249.00), SIMDE_FLOAT64_C(   -36.00),
        SIMDE_FLOAT64_C(  -488.50), SIMDE_FLOAT64_C(   480.00), SIMDE_FLOAT64_C(   952.00), SIMDE_FLOAT64_C(  -324.00) } },
    { { SIMDE_FLOAT64_C(  -796.02),        SIMDE_MATH_INFINITY, SIMDE_FLOAT64_C(  -181.28), SIMDE_FLOAT64_C(  -340.97),
        SIMDE_FLOAT64_C(  -992.00), SIMDE_FLOAT64_C(  -514.43), SIMDE_FLOAT64_C(  -985.86), SIMDE_FLOAT64_C(   232.23) },
       INT32_C(          33),
      { SIMDE_FLOAT64_C(  -796.25),        SIMDE_MATH_INFINITY, SIMDE_FLOAT64_C(  -181.50), SIMDE_FLOAT64_C(  -341.00),
        SIMDE_FLOAT64_C(  -992.00), SIMDE_FLOAT64_C(  -514.50), SIMDE_FLOAT64_C(  -986.00), SIMDE_FLOAT64_C(   232.00) } },
    { { SIMDE_FLOAT64_C(  -669.63), SIMDE_FLOAT64_C(  -284.81), SIMDE_FLOAT64_C(  -464.69), SIMDE_FLOAT64_C(  -441.51),
        SIMDE_FLOAT64_C(  -552.37), SIMDE_FLOAT64_C(  -647.13), SIMDE_FLOAT64_C(  -322.50), SIMDE_FLOAT64_C(  -981.53) },
       INT32_C(          49),
      { SIMDE_FLOAT64_C(  -669.75), SIMDE_FLOAT64_C(  -284.88), SIMDE_FLOAT64_C(  -464.75), SIMDE_FLOAT64_C(  -441.62),
        SIMDE_FLOAT64_C(  -552.38), SIMDE_FLOAT64_C(  -647.25), SIMDE_FLOAT64_C(  -322.50), SIMDE_FLOAT64_C(  -981.62) } },
    { {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(   -97.19), SIMDE_FLOAT64_C(  -621.40), SIMDE_FLOAT64_C(  -479.00),
        SIMDE_FLOAT64_C(  -848.11), SIMDE_FLOAT64_C(   342.69), SIMDE_FLOAT64_C(    32.75), SIMDE_FLOAT64_C(   632.30) },
       INT32_C(          65),
      {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(   -97.25), SIMDE_FLOAT64_C(  -621.44), SIMDE_FLOAT64_C(  -479.00),
        SIMDE_FLOAT64_C(  -848.12), SIMDE_FLOAT64_C(   342.69), SIMDE_FLOAT64_C(    32.75), SIMDE_FLOAT64_C(   632.25) } },
    { { SIMDE_FLOAT64_C(  -478.76),        SIMDE_MATH_INFINITY, SIMDE_FLOAT64_C(   -96.06), SIMDE_FLOAT64_C(   339.95),
        SIMDE_FLOAT64_C(  -841.98), SIMDE_FLOAT64_C(   -88.06), SIMDE_FLOAT64_C(   825.52), SIMDE_FLOAT64_C(  -827.83) },
       INT32_C(          81),
      { SIMDE_FLOAT64_C(  -478.78),        SIMDE_MATH_INFINITY, SIMDE_FLOAT64_C(   -96.06), SIMDE_FLOAT64_C(   339.94),
        SIMDE_FLOAT64_C(  -842.00), SIMDE_FLOAT64_C(   -88.06), SIMDE_FLOAT64_C(   825.50), SIMDE_FLOAT64_C(  -827.84) } },
    { {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(   850.67), SIMDE_FLOAT64_C(  -384.42), SIMDE_FLOAT64_C(  -112.78),
        SIMDE_FLOAT64_C(  -590.84), SIMDE_FLOAT64_C(    63.20), SIMDE_FLOAT64_C(   240.09), SIMDE_FLOAT64_C(    86.66) },
       INT32_C(          97),
      {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(   850.66), SIMDE_FLOAT64_C(  -384.42), SIMDE_FLOAT64_C(  -112.78),
        SIMDE_FLOAT64_C(  -590.84), SIMDE_FLOAT64_C(    63.19), SIMDE_FLOAT64_C(   240.08), SIMDE_FLOAT64_C(    86.66) } },
    { { SIMDE_FLOAT64_C(   130.58), SIMDE_FLOAT64_C(   984.49), SIMDE_FLOAT64_C(  -295.51), SIMDE_FLOAT64_C(   651.58),
        SIMDE_FLOAT64_C(  -863.62), SIMDE_FLOAT64_C(  -952.81), SIMDE_FLOAT64_C(  -315.67), SIMDE_FLOAT64_C(   768.68) },
       INT32_C(         113),
      { SIMDE_FLOAT64_C(   130.58), SIMDE_FLOAT64_C(   984.48), SIMDE_FLOAT64_C(  -295.52), SIMDE_FLOAT64_C(   651.58),
        SIMDE_FLOAT64_C(  -863.62), SIMDE_FLOAT64_C(  -952.81), SIMDE_FLOAT64_C(  -315.67), SIMDE_FLOAT64_C(   768.68) } },
    { {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(  -710.09), SIMDE_FLOAT64_C(  -158.80), SIMDE_FLOAT64_C(   297.03),
        SIMDE_FLOAT64_C(   629.87), SIMDE_FLOAT64_C(    -0.78), SIMDE_FLOAT64_C(  -791.02), SIMDE_FLOAT64_C(   455.39) },
       INT32_C(         129),
      {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(  -710.09), SIMDE_FLOAT64_C(  -158.80), SIMDE_FLOAT64_C(   297.03),
        SIMDE_FLOAT64_C(   629.87), SIMDE_FLOAT64_C(    -0.78), SIMDE_FLOAT64_C(  -791.02), SIMDE_FLOAT64_C(   455.39) } },
    { {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(    71.77), SIMDE_FLOAT64_C(  -294.95), SIMDE_FLOAT64_C(  -173.64),
        SIMDE_FLOAT64_C(   687.35), SIMDE_FLOAT64_C(   592.27), SIMDE_FLOAT64_C(   235.52), SIMDE_FLOAT64_C(  -249.45) },
       INT32_C(         145),
      {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(    71.77), SIMDE_FLOAT64_C(  -294.95), SIMDE_FLOAT64_C(  -173.64),
        SIMDE_FLOAT64_C(   687.35), SIMDE_FLOAT64_C(   592.27), SIMDE_FLOAT64_C(   235.52), SIMDE_FLOAT64_C(  -249.45) } },
    { { SIMDE_FLOAT64_C(   832.22), SIMDE_FLOAT64_C(   158.25), SIMDE_FLOAT64_C(   452.77), SIMDE_FLOAT64_C(   816.71),
        SIMDE_FLOAT64_C(   862.74), SIMDE_FLOAT64_C(   104.35), SIMDE_FLOAT64_C(   953.08), SIMDE_FLOAT64_C(   909.93) },
       INT32_C(         161),
      { SIMDE_FLOAT64_C(   832.22), SIMDE_FLOAT64_C(   158.25), SIMDE_FLOAT64_C(   452.77), SIMDE_FLOAT64_C(   816.71),
        SIMDE_FLOAT64_C(   862.74), SIMDE_FLOAT64_C(   104.35), SIMDE_FLOAT64_C(   953.08), SIMDE_FLOAT64_C(   909.93) } },
    { { SIMDE_FLOAT64_C(   721.76), SIMDE_FLOAT64_C(   252.13), SIMDE_FLOAT64_C(  -818.23), SIMDE_FLOAT64_C(  -988.32),
        SIMDE_FLOAT64_C(  -906.67), SIMDE_FLOAT64_C(   478.80), SIMDE_FLOAT64_C(   641.54), SIMDE_FLOAT64_C(    92.55) },
       INT32_C(         177),
      { SIMDE_FLOAT64_C(   721.76), SIMDE_FLOAT64_C(   252.13), SIMDE_FLOAT64_C(  -818.23), SIMDE_FLOAT64_C(  -988.32),
        SIMDE_FLOAT64_C(  -906.67), SIMDE_FLOAT64_C(   478.80), SIMDE_FLOAT64_C(   641.54), SIMDE_FLOAT64_C(    92.55) } },
    { { SIMDE_FLOAT64_C(    96.94),       -SIMDE_MATH_INFINITY, SIMDE_FLOAT64_C(  -959.08), SIMDE_FLOAT64_C(  -927.37),
        SIMDE_FLOAT64_C(   335.70), SIMDE_FLOAT64_C(  -254.03), SIMDE_FLOAT64_C(  -101.01), SIMDE_FLOAT64_C(    23.05) },
       INT32_C(         193),
      { SIMDE_FLOAT64_C(    96.94),       -SIMDE_MATH_INFINITY, SIMDE_FLOAT64_C(  -959.08), SIMDE_FLOAT64_C(  -927.37),
        SIMDE_FLOAT64_C(   335.70), SIMDE_FLOAT64_C(  -254.03), SIMDE_FLOAT64_C(  -101.01), SIMDE_FLOAT64_C(    23.05) } },
    { { SIMDE_FLOAT64_C(   170.60), SIMDE_FLOAT64_C(  -543.31), SIMDE_FLOAT64_C(   605.81), SIMDE_FLOAT64_C(  -671.16),
        SIMDE_FLOAT64_C(   909.46), SIMDE_FLOAT64_C(   422.52), SIMDE_FLOAT64_C(  -808.42), SIMDE_FLOAT64_C(    13.80) },
       INT32_C(         209),
      { SIMDE_FLOAT64_C(   170.60), SIMDE_FLOAT64_C(  -543.31), SIMDE_FLOAT64_C(   605.81), SIMDE_FLOAT64_C(  -671.16),
        SIMDE_FLOAT64_C(   909.46), SIMDE_FLOAT64_C(   422.52), SIMDE_FLOAT64_C(  -808.42), SIMDE_FLOAT64_C(    13.80) } },
    { {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(  -197.52), SIMDE_FLOAT64_C(    97.37), SIMDE_FLOAT64_C(   353.65),
        SIMDE_FLOAT64_C(   -15.75), SIMDE_FLOAT64_C(   109.05), SIMDE_FLOAT64_C(   446.97), SIMDE_FLOAT64_C(  -536.95) },
       INT32_C(         225),
      {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(  -197.52), SIMDE_FLOAT64_C(    97.37), SIMDE_FLOAT64_C(   353.65),
        SIMDE_FLOAT64_C(   -15.75), SIMDE_FLOAT64_C(   109.05), SIMDE_FLOAT64_C(   446.97), SIMDE_FLOAT64_C(  -536.95) } },
    { { SIMDE_FLOAT64_C(  -849.17), SIMDE_FLOAT64_C(   847.53), SIMDE_FLOAT64_C(  -196.55), SIMDE_FLOAT64_C(  -808.25),
        SIMDE_FLOAT64_C(   920.15), SIMDE_FLOAT64_C(  -860.85), SIMDE_FLOAT64_C(   -62.28), SIMDE_FLOAT64_C(  -180.86) },
       INT32_C(         241),
      { SIMDE_FLOAT64_C(  -849.17), SIMDE_FLOAT64_C(   847.53), SIMDE_FLOAT64_C(  -196.55), SIMDE_FLOAT64_C(  -808.25),
        SIMDE_FLOAT64_C(   920.15), SIMDE_FLOAT64_C(  -860.85), SIMDE_FLOAT64_C(   -62.28), SIMDE_FLOAT64_C(  -180.86) } },
    { { SIMDE_FLOAT64_C(   275.96), SIMDE_FLOAT64_C(   -46.36), SIMDE_FLOAT64_C(   -64.20), SIMDE_FLOAT64_C(  -553.44),
        SIMDE_FLOAT64_C(   410.33), SIMDE_FLOAT64_C(  -458.39), SIMDE_FLOAT64_C(  -224.60), SIMDE_FLOAT64_C(   319.79) },
       INT32_C(           2),
      { SIMDE_FLOAT64_C(   276.00), SIMDE_FLOAT64_C(   -46.00), SIMDE_FLOAT64_C(   -64.00), SIMDE_FLOAT64_C(  -553.00),
        SIMDE_FLOAT64_C(   411.00), SIMDE_FLOAT64_C(  -458.00), SIMDE_FLOAT64_C(  -224.00), SIMDE_FLOAT64_C(   320.00) } },
    { {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(  -666.41), SIMDE_FLOAT64_C(   339.73), SIMDE_FLOAT64_C(    68.50),
        SIMDE_FLOAT64_C(   136.07), SIMDE_FLOAT64_C(  -562.90), SIMDE_FLOAT64_C(  -577.86), SIMDE_FLOAT64_C(  -879.68) },
       INT32_C(          18),
      {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(  -666.00), SIMDE_FLOAT64_C(   340.00), SIMDE_FLOAT64_C(    68.50),
        SIMDE_FLOAT64_C(   136.50), SIMDE_FLOAT64_C(  -562.50), SIMDE_FLOAT64_C(  -577.50), SIMDE_FLOAT64_C(  -879.50) } },
    { { SIMDE_FLOAT64_C(  -416.63),       -SIMDE_MATH_INFINITY, SIMDE_FLOAT64_C(  -591.36), SIMDE_FLOAT64_C(  -265.80),
        SIMDE_FLOAT64_C(  -855.74), SIMDE_FLOAT64_C(   212.09), SIMDE_FLOAT64_C(   -74.05), SIMDE_FLOAT64_C(  -935.58) },
       INT32_C(          34),
      { SIMDE_FLOAT64_C(  -416.50),       -SIMDE_MATH_INFINITY, SIMDE_FLOAT64_C(  -591.25), SIMDE_FLOAT64_C(  -265.75),
        SIMDE_FLOAT64_C(  -855.50), SIMDE_FLOAT64_C(   212.25), SIMDE_FLOAT64_C(   -74.00), SIMDE_FLOAT64_C(  -935.50) } },
    { { SIMDE_FLOAT64_C(  -486.55),        SIMDE_MATH_INFINITY, SIMDE_FLOAT64_C(   837.20), SIMDE_FLOAT64_C(   449.24),
        SIMDE_FLOAT64_C(   586.18), SIMDE_FLOAT64_C(   247.53), SIMDE_FLOAT64_C(   990.85), SIMDE_FLOAT64_C(  -638.42) },
       INT32_C(          50),
      { SIMDE_FLOAT64_C(  -486.50),        SIMDE_MATH_INFINITY, SIMDE_FLOAT64_C(   837.25), SIMDE_FLOAT64_C(   449.25),
        SIMDE_FLOAT64_C(   586.25), SIMDE_FLOAT64_C(   247.62), SIMDE_FLOAT64_C(   990.88), SIMDE_FLOAT64_C(  -638.38) } },
    { { SIMDE_FLOAT64_C(   -99.09),        SIMDE_MATH_INFINITY, SIMDE_FLOAT64_C(  -602.94), SIMDE_FLOAT64_C(  -963.02),
        SIMDE_FLOAT64_C(   731.81), SIMDE_FLOAT64_C(  -180.80), SIMDE_FLOAT64_C(  -842.70), SIMDE_FLOAT64_C(   277.96) },
       INT32_C(          66),
      { SIMDE_FLOAT64_C(   -99.06),        SIMDE_MATH_INFINITY, SIMDE_FLOAT64_C(  -602.94), SIMDE_FLOAT64_C(  -963.00),
        SIMDE_FLOAT64_C(   731.81), SIMDE_FLOAT64_C(  -180.75), SIMDE_FLOAT64_C(  -842.69), SIMDE_FLOAT64_C(   278.00) } },
    { { SIMDE_FLOAT64_C(    96.95), SIMDE_FLOAT64_C(   474.88), SIMDE_FLOAT64_C(   718.96), SIMDE_FLOAT64_C(  -690.96),
        SIMDE_FLOAT64_C(  -599.18), SIMDE_FLOAT64_C(   783.38), SIMDE_FLOAT64_C(   660.29), SIMDE_FLOAT64_C(  -735.52) },
       INT32_C(          82),
      { SIMDE_FLOAT64_C(    96.97), SIMDE_FLOAT64_C(   474.91), SIMDE_FLOAT64_C(   718.97), SIMDE_FLOAT64_C(  -690.94),
        SIMDE_FLOAT64_C(  -599.16), SIMDE_FLOAT64_C(   783.41), SIMDE_FLOAT64_C(   660.31), SIMDE_FLOAT64_C(  -735.50) } },
    { {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(   404.11), SIMDE_FLOAT64_C(  -495.87), SIMDE_FLOAT64_C(   622.98),
        SIMDE_FLOAT64_C(    -9.71), SIMDE_FLOAT64_C(   751.66), SIMDE_FLOAT64_C(   613.83), SIMDE_FLOAT64_C(   351.86) },
       INT32_C(          98),
      {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(   404.12), SIMDE_FLOAT64_C(  -495.86), SIMDE_FLOAT64_C(   622.98),
        SIMDE_FLOAT64_C(    -9.70), SIMDE_FLOAT64_C(   751.67), SIMDE_FLOAT64_C(   613.84), SIMDE_FLOAT64_C(   351.88) } },
    { { SIMDE_FLOAT64_C(  -319.58), SIMDE_FLOAT64_C(   219.88), SIMDE_FLOAT64_C(  -136.48), SIMDE_FLOAT64_C(    77.48),
        SIMDE_FLOAT64_C(   256.85), SIMDE_FLOAT64_C(  -404.67), SIMDE_FLOAT64_C(   896.68), SIMDE_FLOAT64_C(   414.16) },
       INT32_C(         114),
      { SIMDE_FLOAT64_C(  -319.58), SIMDE_FLOAT64_C(   219.88), SIMDE_FLOAT64_C(  -136.48), SIMDE_FLOAT64_C(    77.48),
        SIMDE_FLOAT64_C(   256.85), SIMDE_FLOAT64_C(  -404.66), SIMDE_FLOAT64_C(   896.69), SIMDE_FLOAT64_C(   414.16) } },
    { { SIMDE_FLOAT64_C(  -415.00), SIMDE_FLOAT64_C(  -845.17), SIMDE_FLOAT64_C(   447.99), SIMDE_FLOAT64_C(   681.95),
        SIMDE_FLOAT64_C(   629.71), SIMDE_FLOAT64_C(   166.95), SIMDE_FLOAT64_C(   990.99), SIMDE_FLOAT64_C(  -969.47) },
       INT32_C(         130),
      { SIMDE_FLOAT64_C(  -415.00), SIMDE_FLOAT64_C(  -845.17), SIMDE_FLOAT64_C(   447.99), SIMDE_FLOAT64_C(   681.95),
        SIMDE_FLOAT64_C(   629.71), SIMDE_FLOAT64_C(   166.95), SIMDE_FLOAT64_C(   990.99), SIMDE_FLOAT64_C(  -969.47) } },
    { { SIMDE_FLOAT64_C(   651.28), SIMDE_FLOAT64_C(  -704.98), SIMDE_FLOAT64_C(   617.27), SIMDE_FLOAT64_C(   825.02),
        SIMDE_FLOAT64_C(   699.12), SIMDE_FLOAT64_C(  -878.61), SIMDE_FLOAT64_C(   447.99), SIMDE_FLOAT64_C(  -310.59) },
       INT32_C(         146),
      { SIMDE_FLOAT64_C(   651.28), SIMDE_FLOAT64_C(  -704.98), SIMDE_FLOAT64_C(   617.27), SIMDE_FLOAT64_C(   825.02),
        SIMDE_FLOAT64_C(   699.12), SIMDE_FLOAT64_C(  -878.61), SIMDE_FLOAT64_C(   447.99), SIMDE_FLOAT64_C(  -310.59) } },
    { { SIMDE_FLOAT64_C(    61.82), SIMDE_FLOAT64_C(  -958.73), SIMDE_FLOAT64_C(  -807.98), SIMDE_FLOAT64_C(  -369.38),
        SIMDE_FLOAT64_C(  -278.31), SIMDE_FLOAT64_C(   411.89), SIMDE_FLOAT64_C(   494.14), SIMDE_FLOAT64_C(   799.17) },
       INT32_C(         162),
      { SIMDE_FLOAT64_C(    61.82), SIMDE_FLOAT64_C(  -958.73), SIMDE_FLOAT64_C(  -807.98), SIMDE_FLOAT64_C(  -369.38),
        SIMDE_FLOAT64_C(  -278.31), SIMDE_FLOAT64_C(   411.89), SIMDE_FLOAT64_C(   494.14), SIMDE_FLOAT64_C(   799.17) } },
    { { SIMDE_FLOAT64_C(  -910.54), SIMDE_FLOAT64_C(   695.85), SIMDE_FLOAT64_C(  -917.09), SIMDE_FLOAT64_C(   962.76),
        SIMDE_FLOAT64_C(  -719.15), SIMDE_FLOAT64_C(  -762.26), SIMDE_FLOAT64_C(   410.75), SIMDE_FLOAT64_C(   962.80) },
       INT32_C(         178),
      { SIMDE_FLOAT64_C(  -910.54), SIMDE_FLOAT64_C(   695.85), SIMDE_FLOAT64_C(  -917.09), SIMDE_FLOAT64_C(   962.76),
        SIMDE_FLOAT64_C(  -719.15), SIMDE_FLOAT64_C(  -762.26), SIMDE_FLOAT64_C(   410.75), SIMDE_FLOAT64_C(   962.80) } },
    { { SIMDE_FLOAT64_C(  -422.30),        SIMDE_MATH_INFINITY, SIMDE_FLOAT64_C(   897.98), SIMDE_FLOAT64_C(   528.03),
        SIMDE_FLOAT64_C(   605.08), SIMDE_FLOAT64_C(  -807.00), SIMDE_FLOAT64_C(   145.30), SIMDE_FLOAT64_C(   430.09) },
       INT32_C(         194),
      { SIMDE_FLOAT64_C(  -422.30),        SIMDE_MATH_INFINITY, SIMDE_FLOAT64_C(   897.98), SIMDE_FLOAT64_C(   528.03),
        SIMDE_FLOAT64_C(   605.08), SIMDE_FLOAT64_C(  -807.00), SIMDE_FLOAT64_C(   145.30), SIMDE_FLOAT64_C(   430.09) } },
    { {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(   139.74), SIMDE_FLOAT64_C(   939.90), SIMDE_FLOAT64_C(  -377.20),
        SIMDE_FLOAT64_C(   331.76), SIMDE_FLOAT64_C(  -429.48), SIMDE_FLOAT64_C(   344.49), SIMDE_FLOAT64_C(  -256.35) },
       INT32_C(         210),
      {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(   139.74), SIMDE_FLOAT64_C(   939.90), SIMDE_FLOAT64_C(  -377.20),
        SIMDE_FLOAT64_C(   331.76), SIMDE_FLOAT64_C(  -429.48), SIMDE_FLOAT64_C(   344.49), SIMDE_FLOAT64_C(  -256.35) } },
    { { SIMDE_FLOAT64_C(   412.40),       -SIMDE_MATH_INFINITY, SIMDE_FLOAT64_C(  -160.48), SIMDE_FLOAT64_C(   495.31),
        SIMDE_FLOAT64_C(  -883.13), SIMDE_FLOAT64_C(   120.37), SIMDE_FLOAT64_C(   733.05), SIMDE_FLOAT64_C(   527.62) },
       INT32_C(         226),
      { SIMDE_FLOAT64_C(   412.40),       -SIMDE_MATH_INFINITY, SIMDE_FLOAT64_C(  -160.48), SIMDE_FLOAT64_C(   495.31),
        SIMDE_FLOAT64_C(  -883.13), SIMDE_FLOAT64_C(   120.37), SIMDE_FLOAT64_C(   733.05), SIMDE_FLOAT64_C(   527.62) } },
    { { SIMDE_FLOAT64_C(    36.97), SIMDE_FLOAT64_C(   498.48), SIMDE_FLOAT64_C(   633.35), SIMDE_FLOAT64_C(  -357.96),
        SIMDE_FLOAT64_C(   691.48), SIMDE_FLOAT64_C(  -221.35), SIMDE_FLOAT64_C(  -927.87), SIMDE_FLOAT64_C(   583.60) },
       INT32_C(         242),
      { SIMDE_FLOAT64_C(    36.97), SIMDE_FLOAT64_C(   498.48), SIMDE_FLOAT64_C(   633.35), SIMDE_FLOAT64_C(  -357.96),
        SIMDE_FLOAT64_C(   691.48), SIMDE_FLOAT64_C(  -221.35), SIMDE_FLOAT64_C(  -927.87), SIMDE_FLOAT64_C(   583.60) } },
    { {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(  -834.88), SIMDE_FLOAT64_C(   185.08), SIMDE_FLOAT64_C(  -109.89),
        SIMDE_FLOAT64_C(  -212.08), SIMDE_FLOAT64_C(  -483.17), SIMDE_FLOAT64_C(   460.63), SIMDE_FLOAT64_C(  -867.59) },
       INT32_C(           3),
      {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(  -834.00), SIMDE_FLOAT64_C(   185.00), SIMDE_FLOAT64_C(  -109.00),
        SIMDE_FLOAT64_C(  -212.00), SIMDE_FLOAT64_C(  -483.00), SIMDE_FLOAT64_C(   460.00), SIMDE_FLOAT64_C(  -867.00) } },
    { { SIMDE_FLOAT64_C(   276.08), SIMDE_FLOAT64_C(  -327.11), SIMDE_FLOAT64_C(   679.40), SIMDE_FLOAT64_C(  -884.40),
        SIMDE_FLOAT64_C(  -831.81), SIMDE_FLOAT64_C(   796.27), SIMDE_FLOAT64_C(   235.97), SIMDE_FLOAT64_C(   901.24) },
       INT32_C(          19),
      { SIMDE_FLOAT64_C(   276.00), SIMDE_FLOAT64_C(  -327.00), SIMDE_FLOAT64_C(   679.00), SIMDE_FLOAT64_C(  -884.00),
        SIMDE_FLOAT64_C(  -831.50), SIMDE_FLOAT64_C(   796.00), SIMDE_FLOAT64_C(   235.50), SIMDE_FLOAT64_C(   901.00) } },
    { { SIMDE_FLOAT64_C(  -680.86), SIMDE_FLOAT64_C(   501.74), SIMDE_FLOAT64_C(   429.20), SIMDE_FLOAT64_C(   356.10),
        SIMDE_FLOAT64_C(     0.22), SIMDE_FLOAT64_C(    62.55), SIMDE_FLOAT64_C(   998.14), SIMDE_FLOAT64_C(  -308.30) },
       INT32_C(          35),
      { SIMDE_FLOAT64_C(  -680.75), SIMDE_FLOAT64_C(   501.50), SIMDE_FLOAT64_C(   429.00), SIMDE_FLOAT64_C(   356.00),
        SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(    62.50), SIMDE_FLOAT64_C(   998.00), SIMDE_FLOAT64_C(  -308.25) } },
    { { SIMDE_FLOAT64_C(  -929.72), SIMDE_FLOAT64_C(  -724.70), SIMDE_FLOAT64_C(   886.54), SIMDE_FLOAT64_C(    20.49),
        SIMDE_FLOAT64_C(  -559.58), SIMDE_FLOAT64_C(    71.61), SIMDE_FLOAT64_C(   910.60), SIMDE_FLOAT64_C(   228.34) },
       INT32_C(          51),
      { SIMDE_FLOAT64_C(  -929.62), SIMDE_FLOAT64_C(  -724.62), SIMDE_FLOAT64_C(   886.50), SIMDE_FLOAT64_C(    20.38),
        SIMDE_FLOAT64_C(  -559.50), SIMDE_FLOAT64_C(    71.50), SIMDE_FLOAT64_C(   910.50), SIMDE_FLOAT64_C(   228.25) } },
    { { SIMDE_FLOAT64_C(   371.23), SIMDE_FLOAT64_C(   360.76), SIMDE_FLOAT64_C(  -151.06), SIMDE_FLOAT64_C(  -103.49),
        SIMDE_FLOAT64_C(  -363.17), SIMDE_FLOAT64_C(   521.82), SIMDE_FLOAT64_C(  -424.10), SIMDE_FLOAT64_C(  -247.57) },
       INT32_C(          67),
      { SIMDE_FLOAT64_C(   371.19), SIMDE_FLOAT64_C(   360.75), SIMDE_FLOAT64_C(  -151.00), SIMDE_FLOAT64_C(  -103.44),
        SIMDE_FLOAT64_C(  -363.12), SIMDE_FLOAT64_C(   521.81), SIMDE_FLOAT64_C(  -424.06), SIMDE_FLOAT64_C(  -247.56) } },
    { {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(   988.40), SIMDE_FLOAT64_C(   591.26), SIMDE_FLOAT64_C(   696.06),
        SIMDE_FLOAT64_C(  -692.47), SIMDE_FLOAT64_C(    93.00), SIMDE_FLOAT64_C(   125.26), SIMDE_FLOAT64_C(   663.64) },
       INT32_C(          83),
      {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(   988.38), SIMDE_FLOAT64_C(   591.25), SIMDE_FLOAT64_C(   696.03),
        SIMDE_FLOAT64_C(  -692.47), SIMDE_FLOAT64_C(    93.00), SIMDE_FLOAT64_C(   125.25), SIMDE_FLOAT64_C(   663.62) } },
    { {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(  -215.08), SIMDE_FLOAT64_C(  -970.99), SIMDE_FLOAT64_C(   732.06),
        SIMDE_FLOAT64_C(    60.22), SIMDE_FLOAT64_C(   915.55), SIMDE_FLOAT64_C(  -247.45), SIMDE_FLOAT64_C(   500.64) },
       INT32_C(          99),
      {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(  -215.08), SIMDE_FLOAT64_C(  -970.98), SIMDE_FLOAT64_C(   732.05),
        SIMDE_FLOAT64_C(    60.22), SIMDE_FLOAT64_C(   915.55), SIMDE_FLOAT64_C(  -247.44), SIMDE_FLOAT64_C(   500.62) } },
    { { SIMDE_FLOAT64_C(  -271.01), SIMDE_FLOAT64_C(  -424.38), SIMDE_FLOAT64_C(  -965.63), SIMDE_FLOAT64_C(  -910.26),
        SIMDE_FLOAT64_C(   424.55), SIMDE_FLOAT64_C(   -69.12), SIMDE_FLOAT64_C(  -273.42), SIMDE_FLOAT64_C(   -53.63) },
       INT32_C(         115),
      { SIMDE_FLOAT64_C(  -271.01), SIMDE_FLOAT64_C(  -424.38), SIMDE_FLOAT64_C(  -965.62), SIMDE_FLOAT64_C(  -910.26),
        SIMDE_FLOAT64_C(   424.55), SIMDE_FLOAT64_C(   -69.12), SIMDE_FLOAT64_C(  -273.41), SIMDE_FLOAT64_C(   -53.62) } },
    { {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(  -363.61), SIMDE_FLOAT64_C(   878.95), SIMDE_FLOAT64_C(   467.41),
        SIMDE_FLOAT64_C(  -772.35), SIMDE_FLOAT64_C(   575.01), SIMDE_FLOAT64_C(   774.94), SIMDE_FLOAT64_C(   320.65) },
       INT32_C(         131),
      {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(  -363.61), SIMDE_FLOAT64_C(   878.95), SIMDE_FLOAT64_C(   467.41),
        SIMDE_FLOAT64_C(  -772.35), SIMDE_FLOAT64_C(   575.01), SIMDE_FLOAT64_C(   774.94), SIMDE_FLOAT64_C(   320.65) } },
    { {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(  -111.91), SIMDE_FLOAT64_C(   100.36), SIMDE_FLOAT64_C(  -801.21),
        SIMDE_FLOAT64_C(   -82.90), SIMDE_FLOAT64_C(  -167.58), SIMDE_FLOAT64_C(   259.01), SIMDE_FLOAT64_C(  -167.35) },
       INT32_C(         147),
      {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(  -111.91), SIMDE_FLOAT64_C(   100.36), SIMDE_FLOAT64_C(  -801.21),
        SIMDE_FLOAT64_C(   -82.90), SIMDE_FLOAT64_C(  -167.58), SIMDE_FLOAT64_C(   259.01), SIMDE_FLOAT64_C(  -167.35) } },
    { {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(  -751.89), SIMDE_FLOAT64_C(   488.64), SIMDE_FLOAT64_C(  -604.56),
        SIMDE_FLOAT64_C(  -717.52), SIMDE_FLOAT64_C(   578.39), SIMDE_FLOAT64_C(   819.99), SIMDE_FLOAT64_C(   213.36) },
       INT32_C(         163),
      {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(  -751.89), SIMDE_FLOAT64_C(   488.64), SIMDE_FLOAT64_C(  -604.56),
        SIMDE_FLOAT64_C(  -717.52), SIMDE_FLOAT64_C(   578.39), SIMDE_FLOAT64_C(   819.99), SIMDE_FLOAT64_C(   213.36) } },
    { { SIMDE_FLOAT64_C(  -279.86),       -SIMDE_MATH_INFINITY, SIMDE_FLOAT64_C(   402.75), SIMDE_FLOAT64_C(  -400.90),
        SIMDE_FLOAT64_C(   251.38), SIMDE_FLOAT64_C(   630.40), SIMDE_FLOAT64_C(  -825.89), SIMDE_FLOAT64_C(    26.32) },
       INT32_C(         179),
      { SIMDE_FLOAT64_C(  -279.86),       -SIMDE_MATH_INFINITY, SIMDE_FLOAT64_C(   402.75), SIMDE_FLOAT64_C(  -400.90),
        SIMDE_FLOAT64_C(   251.38), SIMDE_FLOAT64_C(   630.40), SIMDE_FLOAT64_C(  -825.89), SIMDE_FLOAT64_C(    26.32) } },
    { { SIMDE_FLOAT64_C(  -635.07), SIMDE_FLOAT64_C(   762.47), SIMDE_FLOAT64_C(   565.26), SIMDE_FLOAT64_C(  -436.28),
        SIMDE_FLOAT64_C(  -320.43), SIMDE_FLOAT64_C(  -602.32), SIMDE_FLOAT64_C(   822.73), SIMDE_FLOAT64_C(   512.22) },
       INT32_C(         195),
      { SIMDE_FLOAT64_C(  -635.07), SIMDE_FLOAT64_C(   762.47), SIMDE_FLOAT64_C(   565.26), SIMDE_FLOAT64_C(  -436.28),
        SIMDE_FLOAT64_C(  -320.43), SIMDE_FLOAT64_C(  -602.32), SIMDE_FLOAT64_C(   822.73), SIMDE_FLOAT64_C(   512.22) } },
    { {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(   332.04), SIMDE_FLOAT64_C(  -769.25), SIMDE_FLOAT64_C(  -928.96),
        SIMDE_FLOAT64_C(   727.48), SIMDE_FLOAT64_C(  -486.77), SIMDE_FLOAT64_C(   649.42), SIMDE_FLOAT64_C(   547.47) },
       INT32_C(         211),
      {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(   332.04), SIMDE_FLOAT64_C(  -769.25), SIMDE_FLOAT64_C(  -928.96),
        SIMDE_FLOAT64_C(   727.48), SIMDE_FLOAT64_C(  -486.77), SIMDE_FLOAT64_C(   649.42), SIMDE_FLOAT64_C(   547.47) } },
    { { SIMDE_FLOAT64_C(  -686.17), SIMDE_FLOAT64_C(  -553.27), SIMDE_FLOAT64_C(   738.36), SIMDE_FLOAT64_C(   716.59),
        SIMDE_FLOAT64_C(    45.83), SIMDE_FLOAT64_C(   -10.26), SIMDE_FLOAT64_C(   346.99), SIMDE_FLOAT64_C(   219.94) },
       INT32_C(         227),
      { SIMDE_FLOAT64_C(  -686.17), SIMDE_FLOAT64_C(  -553.27), SIMDE_FLOAT64_C(   738.36), SIMDE_FLOAT64_C(   716.59),
        SIMDE_FLOAT64_C(    45.83), SIMDE_FLOAT64_C(   -10.26), SIMDE_FLOAT64_C(   346.99), SIMDE_FLOAT64_C(   219.94) } },
    { { SIMDE_FLOAT64_C(  -701.96), SIMDE_FLOAT64_C(  -905.68), SIMDE_FLOAT64_C(  -519.04), SIMDE_FLOAT64_C(  -337.03),
        SIMDE_FLOAT64_C(   856.78), SIMDE_FLOAT64_C(  -953.78), SIMDE_FLOAT64_C(   226.69), SIMDE_FLOAT64_C(  -463.65) },
       INT32_C(         243),
      { SIMDE_FLOAT64_C(  -701.96), SIMDE_FLOAT64_C(  -905.68), SIMDE_FLOAT64_C(  -519.04), SIMDE_FLOAT64_C(  -337.03),
        SIMDE_FLOAT64_C(   856.78), SIMDE_FLOAT64_C(  -953.78), SIMDE_FLOAT64_C(   226.69), SIMDE_FLOAT64_C(  -463.65) } },
    { {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(  -951.42), SIMDE_FLOAT64_C(  -573.46), SIMDE_FLOAT64_C(   631.82),
        SIMDE_FLOAT64_C(   380.62), SIMDE_FLOAT64_C(  -342.71), SIMDE_FLOAT64_C(   702.85), SIMDE_FLOAT64_C(   108.10) },
       INT32_C(           4),
      {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(  -951.00), SIMDE_FLOAT64_C(  -573.00), SIMDE_FLOAT64_C(   632.00),
        SIMDE_FLOAT64_C(   381.00), SIMDE_FLOAT64_C(  -343.00), SIMDE_FLOAT64_C(   703.00), SIMDE_FLOAT64_C(   108.00) } },
    { {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(  -102.88), SIMDE_FLOAT64_C(   306.66), SIMDE_FLOAT64_C(   -30.59),
        SIMDE_FLOAT64_C(   343.85), SIMDE_FLOAT64_C(    45.02), SIMDE_FLOAT64_C(  -314.01), SIMDE_FLOAT64_C(  -610.32) },
       INT32_C(          20),
      {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(  -103.00), SIMDE_FLOAT64_C(   306.50), SIMDE_FLOAT64_C(   -30.50),
        SIMDE_FLOAT64_C(   344.00), SIMDE_FLOAT64_C(    45.00), SIMDE_FLOAT64_C(  -314.00), SIMDE_FLOAT64_C(  -610.50) } },
    { {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(  -949.17), SIMDE_FLOAT64_C(  -668.97), SIMDE_FLOAT64_C(   703.94),
        SIMDE_FLOAT64_C(  -468.20), SIMDE_FLOAT64_C(    -6.00), SIMDE_FLOAT64_C(   560.72), SIMDE_FLOAT64_C(  -421.98) },
       INT32_C(          36),
      {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(  -949.25), SIMDE_FLOAT64_C(  -669.00), SIMDE_FLOAT64_C(   704.00),
        SIMDE_FLOAT64_C(  -468.25), SIMDE_FLOAT64_C(    -6.00), SIMDE_FLOAT64_C(   560.75), SIMDE_FLOAT64_C(  -422.00) } },
    { { SIMDE_FLOAT64_C(    21.92),       -SIMDE_MATH_INFINITY, SIMDE_FLOAT64_C(  -854.35), SIMDE_FLOAT64_C(   448.47),
        SIMDE_FLOAT64_C(   -98.07), SIMDE_FLOAT64_C(   526.27), SIMDE_FLOAT64_C(  -894.24), SIMDE_FLOAT64_C(  -395.22) },
       INT32_C(          52),
      { SIMDE_FLOAT64_C(    21.88),       -SIMDE_MATH_INFINITY, SIMDE_FLOAT64_C(  -854.38), SIMDE_FLOAT64_C(   448.50),
        SIMDE_FLOAT64_C(   -98.12), SIMDE_FLOAT64_C(   526.25), SIMDE_FLOAT64_C(  -894.25), SIMDE_FLOAT64_C(  -395.25) } },
    { { SIMDE_FLOAT64_C(   289.95), SIMDE_FLOAT64_C(  -826.60), SIMDE_FLOAT64_C(   263.71), SIMDE_FLOAT64_C(  -740.65),
        SIMDE_FLOAT64_C(   517.26), SIMDE_FLOAT64_C(  -691.26), SIMDE_FLOAT64_C(   -54.66), SIMDE_FLOAT64_C(   906.94) },
       INT32_C(          68),
      { SIMDE_FLOAT64_C(   289.94), SIMDE_FLOAT64_C(  -826.62), SIMDE_FLOAT64_C(   263.69), SIMDE_FLOAT64_C(  -740.62),
        SIMDE_FLOAT64_C(   517.25), SIMDE_FLOAT64_C(  -691.25), SIMDE_FLOAT64_C(   -54.69), SIMDE_FLOAT64_C(   906.94) } },
    { { SIMDE_FLOAT64_C(   -21.67),       -SIMDE_MATH_INFINITY, SIMDE_FLOAT64_C(  -605.66), SIMDE_FLOAT64_C(   309.35),
        SIMDE_FLOAT64_C(   220.50), SIMDE_FLOAT64_C(   -73.87), SIMDE_FLOAT64_C(  -696.65), SIMDE_FLOAT64_C(  -218.78) },
       INT32_C(          84),
      { SIMDE_FLOAT64_C(   -21.66),       -SIMDE_MATH_INFINITY, SIMDE_FLOAT64_C(  -605.66), SIMDE_FLOAT64_C(   309.34),
        SIMDE_FLOAT64_C(   220.50), SIMDE_FLOAT64_C(   -73.88), SIMDE_FLOAT64_C(  -696.66), SIMDE_FLOAT64_C(  -218.78) } },
    { { SIMDE_FLOAT64_C(  -473.92),       -SIMDE_MATH_INFINITY, SIMDE_FLOAT64_C(    23.94), SIMDE_FLOAT64_C(   974.54),
        SIMDE_FLOAT64_C(  -303.92), SIMDE_FLOAT64_C(  -449.78), SIMDE_FLOAT64_C(  -919.70), SIMDE_FLOAT64_C(   300.86) },
       INT32_C(         100),
      { SIMDE_FLOAT64_C(  -473.92),       -SIMDE_MATH_INFINITY, SIMDE_FLOAT64_C(    23.94), SIMDE_FLOAT64_C(   974.55),
        SIMDE_FLOAT64_C(  -303.92), SIMDE_FLOAT64_C(  -449.78), SIMDE_FLOAT64_C(  -919.70), SIMDE_FLOAT64_C(   300.86) } },
    { {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(   529.99), SIMDE_FLOAT64_C(  -478.38), SIMDE_FLOAT64_C(  -266.11),
        SIMDE_FLOAT64_C(    47.24), SIMDE_FLOAT64_C(  -169.64), SIMDE_FLOAT64_C(   679.23), SIMDE_FLOAT64_C(   -45.82) },
       INT32_C(         116),
      {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(   529.99), SIMDE_FLOAT64_C(  -478.38), SIMDE_FLOAT64_C(  -266.11),
        SIMDE_FLOAT64_C(    47.24), SIMDE_FLOAT64_C(  -169.64), SIMDE_FLOAT64_C(   679.23), SIMDE_FLOAT64_C(   -45.82) } },
    { {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(   568.21), SIMDE_FLOAT64_C(   966.91), SIMDE_FLOAT64_C(   691.24),
        SIMDE_FLOAT64_C(  -505.66), SIMDE_FLOAT64_C(  -729.73), SIMDE_FLOAT64_C(  -527.54), SIMDE_FLOAT64_C(   998.50) },
       INT32_C(         132),
      {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(   568.21), SIMDE_FLOAT64_C(   966.91), SIMDE_FLOAT64_C(   691.24),
        SIMDE_FLOAT64_C(  -505.66), SIMDE_FLOAT64_C(  -729.73), SIMDE_FLOAT64_C(  -527.54), SIMDE_FLOAT64_C(   998.50) } },
    { { SIMDE_FLOAT64_C(  -475.42),        SIMDE_MATH_INFINITY, SIMDE_FLOAT64_C(  -625.30), SIMDE_FLOAT64_C(  -500.88),
        SIMDE_FLOAT64_C(   284.54), SIMDE_FLOAT64_C(   -75.09), SIMDE_FLOAT64_C(  -420.58), SIMDE_FLOAT64_C(  -414.60) },
       INT32_C(         148),
      { SIMDE_FLOAT64_C(  -475.42),        SIMDE_MATH_INFINITY, SIMDE_FLOAT64_C(  -625.30), SIMDE_FLOAT64_C(  -500.88),
        SIMDE_FLOAT64_C(   284.54), SIMDE_FLOAT64_C(   -75.09), SIMDE_FLOAT64_C(  -420.58), SIMDE_FLOAT64_C(  -414.60) } },
    { { SIMDE_FLOAT64_C(  -415.96), SIMDE_FLOAT64_C(   465.99), SIMDE_FLOAT64_C(  -635.07), SIMDE_FLOAT64_C(   317.93),
        SIMDE_FLOAT64_C(  -486.76), SIMDE_FLOAT64_C(   195.29), SIMDE_FLOAT64_C(    -2.84), SIMDE_FLOAT64_C(   467.42) },
       INT32_C(         164),
      { SIMDE_FLOAT64_C(  -415.96), SIMDE_FLOAT64_C(   465.99), SIMDE_FLOAT64_C(  -635.07), SIMDE_FLOAT64_C(   317.93),
        SIMDE_FLOAT64_C(  -486.76), SIMDE_FLOAT64_C(   195.29), SIMDE_FLOAT64_C(    -2.84), SIMDE_FLOAT64_C(   467.42) } },
    { {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(   938.17), SIMDE_FLOAT64_C(   937.37), SIMDE_FLOAT64_C(   621.63),
        SIMDE_FLOAT64_C(   629.41), SIMDE_FLOAT64_C(  -568.29), SIMDE_FLOAT64_C(   891.90), SIMDE_FLOAT64_C(  -898.13) },
       INT32_C(         180),
      {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(   938.17), SIMDE_FLOAT64_C(   937.37), SIMDE_FLOAT64_C(   621.63),
        SIMDE_FLOAT64_C(   629.41), SIMDE_FLOAT64_C(  -568.29), SIMDE_FLOAT64_C(   891.90), SIMDE_FLOAT64_C(  -898.13) } },
    { { SIMDE_FLOAT64_C(   452.62), SIMDE_FLOAT64_C(   -45.21), SIMDE_FLOAT64_C(   274.67), SIMDE_FLOAT64_C(   827.32),
        SIMDE_FLOAT64_C(   453.90), SIMDE_FLOAT64_C(  -440.79), SIMDE_FLOAT64_C(  -247.77), SIMDE_FLOAT64_C(  -966.68) },
       INT32_C(         196),
      { SIMDE_FLOAT64_C(   452.62), SIMDE_FLOAT64_C(   -45.21), SIMDE_FLOAT64_C(   274.67), SIMDE_FLOAT64_C(   827.32),
        SIMDE_FLOAT64_C(   453.90), SIMDE_FLOAT64_C(  -440.79), SIMDE_FLOAT64_C(  -247.77), SIMDE_FLOAT64_C(  -966.68) } },
    { {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(   969.33), SIMDE_FLOAT64_C(   -12.08), SIMDE_FLOAT64_C(   445.77),
        SIMDE_FLOAT64_C(   435.32), SIMDE_FLOAT64_C(   352.85), SIMDE_FLOAT64_C(  -236.30), SIMDE_FLOAT64_C(   948.56) },
       INT32_C(         212),
      {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(   969.33), SIMDE_FLOAT64_C(   -12.08), SIMDE_FLOAT64_C(   445.77),
        SIMDE_FLOAT64_C(   435.32), SIMDE_FLOAT64_C(   352.85), SIMDE_FLOAT64_C(  -236.30), SIMDE_FLOAT64_C(   948.56) } },
    { { SIMDE_FLOAT64_C(   415.98), SIMDE_FLOAT64_C(   -82.70), SIMDE_FLOAT64_C(   415.58), SIMDE_FLOAT64_C(   354.15),
        SIMDE_FLOAT64_C(  -145.33), SIMDE_FLOAT64_C(    37.21), SIMDE_FLOAT64_C(   -16.44), SIMDE_FLOAT64_C(   286.39) },
       INT32_C(         228),
      { SIMDE_FLOAT64_C(   415.98), SIMDE_FLOAT64_C(   -82.70), SIMDE_FLOAT64_C(   415.58), SIMDE_FLOAT64_C(   354.15),
        SIMDE_FLOAT64_C(  -145.33), SIMDE_FLOAT64_C(    37.21), SIMDE_FLOAT64_C(   -16.44), SIMDE_FLOAT64_C(   286.39) } },
    { { SIMDE_FLOAT64_C(    85.42), SIMDE_FLOAT64_C(   716.60), SIMDE_FLOAT64_C(   615.33), SIMDE_FLOAT64_C(  -461.96),
        SIMDE_FLOAT64_C(  -328.62), SIMDE_FLOAT64_C(  -110.00), SIMDE_FLOAT64_C(  -634.64), SIMDE_FLOAT64_C(  -874.71) },
       INT32_C(         244),
      { SIMDE_FLOAT64_C(    85.42), SIMDE_FLOAT64_C(   716.60), SIMDE_FLOAT64_C(   615.33), SIMDE_FLOAT64_C(  -461.96),
        SIMDE_FLOAT64_C(  -328.62), SIMDE_FLOAT64_C(  -110.00), SIMDE_FLOAT64_C(  -634.64), SIMDE_FLOAT64_C(  -874.71) } },
  };

  simde__m512d a, r;

  a = simde_mm512_loadu_pd(test_vec[0].a);
  r = simde_mm512_roundscale_pd(a, INT32_C(           0));
  simde_test_x86_assert_equal_f64x8(r, simde_mm512_loadu_pd(test_vec[0].r), 1);

  a = simde_mm512_loadu_pd(test_vec[1].a);
  r = simde_mm512_roundscale_pd(a, INT32_C(          16));
  simde_test_x86_assert_equal_f64x8(r, simde_mm512_loadu_pd(test_vec[1].r), 1);

  a = simde_mm512_loadu_pd(test_vec[2].a);
  r = simde_mm512_roundscale_pd(a, INT32_C(          32));
  simde_test_x86_assert_equal_f64x8(r, simde_mm512_loadu_pd(test_vec[2].r), 1);

  a = simde_mm512_loadu_pd(test_vec[3].a);
  r = simde_mm512_roundscale_pd(a, INT32_C(          48));
  simde_test_x86_assert_equal_f64x8(r, simde_mm512_loadu_pd(test_vec[3].r), 1);

  a = simde_mm512_loadu_pd(test_vec[4].a);
  r = simde_mm512_roundscale_pd(a, INT32_C(          64));
  simde_test_x86_assert_equal_f64x8(r, simde_mm512_loadu_pd(test_vec[4].r), 1);

  a = simde_mm512_loadu_pd(test_vec[5].a);
  r = simde_mm512_roundscale_pd(a, INT32_C(          80));
  simde_test_x86_assert_equal_f64x8(r, simde_mm512_loadu_pd(test_vec[5].r), 1);

  a = simde_mm512_loadu_pd(test_vec[6].a);
  r = simde_mm512_roundscale_pd(a, INT32_C(          96));
  simde_test_x86_assert_equal_f64x8(r, simde_mm512_loadu_pd(test_vec[6].r), 1);

  a = simde_mm512_loadu_pd(test_vec[7].a);
  r = simde_mm512_roundscale_pd(a, INT32_C(         112));
  simde_test_x86_assert_equal_f64x8(r, simde_mm512_loadu_pd(test_vec[7].r), 1);

  a = simde_mm512_loadu_pd(test_vec[8].a);
  r = simde_mm512_roundscale_pd(a, INT32_C(         128));
  simde_test_x86_assert_equal_f64x8(r, simde_mm512_loadu_pd(test_vec[8].r), 1);

  a = simde_mm512_loadu_pd(test_vec[9].a);
  r = simde_mm512_roundscale_pd(a, INT32_C(         144));
  simde_test_x86_assert_equal_f64x8(r, simde_mm512_loadu_pd(test_vec[9].r), 1);

  a = simde_mm512_loadu_pd(test_vec[10].a);
  r = simde_mm512_roundscale_pd(a, INT32_C(         160));
  simde_test_x86_assert_equal_f64x8(r, simde_mm512_loadu_pd(test_vec[10].r), 1);

  a = simde_mm512_loadu_pd(test_vec[11].a);
  r = simde_mm512_roundscale_pd(a, INT32_C(         176));
  simde_test_x86_assert_equal_f64x8(r, simde_mm512_loadu_pd(test_vec[11].r), 1);

  a = simde_mm512_loadu_pd(test_vec[12].a);
  r = simde_mm512_roundscale_pd(a, INT32_C(         192));
  simde_test_x86_assert_equal_f64x8(r, simde_mm512_loadu_pd(test_vec[12].r), 1);

  a = simde_mm512_loadu_pd(test_vec[13].a);
  r = simde_mm512_roundscale_pd(a, INT32_C(         208));
  simde_test_x86_assert_equal_f64x8(r, simde_mm512_loadu_pd(test_vec[13].r), 1);

  a = simde_mm512_loadu_pd(test_vec[14].a);
  r = simde_mm512_roundscale_pd(a, INT32_C(         224));
  simde_test_x86_assert_equal_f64x8(r, simde_mm512_loadu_pd(test_vec[14].r), 1);

  a = simde_mm512_loadu_pd(test_vec[15].a);
  r = simde_mm512_roundscale_pd(a, INT32_C(         240));
  simde_test_x86_assert_equal_f64x8(r, simde_mm512_loadu_pd(test_vec[15].r), 1);

  a = simde_mm512_loadu_pd(test_vec[16].a);
  r = simde_mm512_roundscale_pd(a, INT32_C(           1));
  simde_test_x86_assert_equal_f64x8(r, simde_mm512_loadu_pd(test_vec[16].r), 1);

  a = simde_mm512_loadu_pd(test_vec[17].a);
  r = simde_mm512_roundscale_pd(a, INT32_C(          17));
  simde_test_x86_assert_equal_f64x8(r, simde_mm512_loadu_pd(test_vec[17].r), 1);

  a = simde_mm512_loadu_pd(test_vec[18].a);
  r = simde_mm512_roundscale_pd(a, INT32_C(          33));
  simde_test_x86_assert_equal_f64x8(r, simde_mm512_loadu_pd(test_vec[18].r), 1);

  a = simde_mm512_loadu_pd(test_vec[19].a);
  r = simde_mm512_roundscale_pd(a, INT32_C(          49));
  simde_test_x86_assert_equal_f64x8(r, simde_mm512_loadu_pd(test_vec[19].r), 1);

  a = simde_mm512_loadu_pd(test_vec[20].a);
  r = simde_mm512_roundscale_pd(a, INT32_C(          65));
  simde_test_x86_assert_equal_f64x8(r, simde_mm512_loadu_pd(test_vec[20].r), 1);

  a = simde_mm512_loadu_pd(test_vec[21].a);
  r = simde_mm512_roundscale_pd(a, INT32_C(          81));
  simde_test_x86_assert_equal_f64x8(r, simde_mm512_loadu_pd(test_vec[21].r), 1);

  a = simde_mm512_loadu_pd(test_vec[22].a);
  r = simde_mm512_roundscale_pd(a, INT32_C(          97));
  simde_test_x86_assert_equal_f64x8(r, simde_mm512_loadu_pd(test_vec[22].r), 1);

  a = simde_mm512_loadu_pd(test_vec[23].a);
  r = simde_mm512_roundscale_pd(a, INT32_C(         113));
  simde_test_x86_assert_equal_f64x8(r, simde_mm512_loadu_pd(test_vec[23].r), 1);

  a = simde_mm512_loadu_pd(test_vec[24].a);
  r = simde_mm512_roundscale_pd(a, INT32_C(         129));
  simde_test_x86_assert_equal_f64x8(r, simde_mm512_loadu_pd(test_vec[24].r), 1);

  a = simde_mm512_loadu_pd(test_vec[25].a);
  r = simde_mm512_roundscale_pd(a, INT32_C(         145));
  simde_test_x86_assert_equal_f64x8(r, simde_mm512_loadu_pd(test_vec[25].r), 1);

  a = simde_mm512_loadu_pd(test_vec[26].a);
  r = simde_mm512_roundscale_pd(a, INT32_C(         161));
  simde_test_x86_assert_equal_f64x8(r, simde_mm512_loadu_pd(test_vec[26].r), 1);

  a = simde_mm512_loadu_pd(test_vec[27].a);
  r = simde_mm512_roundscale_pd(a, INT32_C(         177));
  simde_test_x86_assert_equal_f64x8(r, simde_mm512_loadu_pd(test_vec[27].r), 1);

  a = simde_mm512_loadu_pd(test_vec[28].a);
  r = simde_mm512_roundscale_pd(a, INT32_C(         193));
  simde_test_x86_assert_equal_f64x8(r, simde_mm512_loadu_pd(test_vec[28].r), 1);

  a = simde_mm512_loadu_pd(test_vec[29].a);
  r = simde_mm512_roundscale_pd(a, INT32_C(         209));
  simde_test_x86_assert_equal_f64x8(r, simde_mm512_loadu_pd(test_vec[29].r), 1);

  a = simde_mm512_loadu_pd(test_vec[30].a);
  r = simde_mm512_roundscale_pd(a, INT32_C(         225));
  simde_test_x86_assert_equal_f64x8(r, simde_mm512_loadu_pd(test_vec[30].r), 1);

  a = simde_mm512_loadu_pd(test_vec[31].a);
  r = simde_mm512_roundscale_pd(a, INT32_C(         241));
  simde_test_x86_assert_equal_f64x8(r, simde_mm512_loadu_pd(test_vec[31].r), 1);

  a = simde_mm512_loadu_pd(test_vec[32].a);
  r = simde_mm512_roundscale_pd(a, INT32_C(           2));
  simde_test_x86_assert_equal_f64x8(r, simde_mm512_loadu_pd(test_vec[32].r), 1);

  a = simde_mm512_loadu_pd(test_vec[33].a);
  r = simde_mm512_roundscale_pd(a, INT32_C(          18));
  simde_test_x86_assert_equal_f64x8(r, simde_mm512_loadu_pd(test_vec[33].r), 1);

  a = simde_mm512_loadu_pd(test_vec[34].a);
  r = simde_mm512_roundscale_pd(a, INT32_C(          34));
  simde_test_x86_assert_equal_f64x8(r, simde_mm512_loadu_pd(test_vec[34].r), 1);

  a = simde_mm512_loadu_pd(test_vec[35].a);
  r = simde_mm512_roundscale_pd(a, INT32_C(          50));
  simde_test_x86_assert_equal_f64x8(r, simde_mm512_loadu_pd(test_vec[35].r), 1);

  a = simde_mm512_loadu_pd(test_vec[36].a);
  r = simde_mm512_roundscale_pd(a, INT32_C(          66));
  simde_test_x86_assert_equal_f64x8(r, simde_mm512_loadu_pd(test_vec[36].r), 1);

  a = simde_mm512_loadu_pd(test_vec[37].a);
  r = simde_mm512_roundscale_pd(a, INT32_C(          82));
  simde_test_x86_assert_equal_f64x8(r, simde_mm512_loadu_pd(test_vec[37].r), 1);

  a = simde_mm512_loadu_pd(test_vec[38].a);
  r = simde_mm512_roundscale_pd(a, INT32_C(          98));
  simde_test_x86_assert_equal_f64x8(r, simde_mm512_loadu_pd(test_vec[38].r), 1);

  a = simde_mm512_loadu_pd(test_vec[39].a);
  r = simde_mm512_roundscale_pd(a, INT32_C(         114));
  simde_test_x86_assert_equal_f64x8(r, simde_mm512_loadu_pd(test_vec[39].r), 1);

  a = simde_mm512_loadu_pd(test_vec[40].a);
  r = simde_mm512_roundscale_pd(a, INT32_C(         130));
  simde_test_x86_assert_equal_f64x8(r, simde_mm512_loadu_pd(test_vec[40].r), 1);

  a = simde_mm512_loadu_pd(test_vec[41].a);
  r = simde_mm512_roundscale_pd(a, INT32_C(         146));
  simde_test_x86_assert_equal_f64x8(r, simde_mm512_loadu_pd(test_vec[41].r), 1);

  a = simde_mm512_loadu_pd(test_vec[42].a);
  r = simde_mm512_roundscale_pd(a, INT32_C(         162));
  simde_test_x86_assert_equal_f64x8(r, simde_mm512_loadu_pd(test_vec[42].r), 1);

  a = simde_mm512_loadu_pd(test_vec[43].a);
  r = simde_mm512_roundscale_pd(a, INT32_C(         178));
  simde_test_x86_assert_equal_f64x8(r, simde_mm512_loadu_pd(test_vec[43].r), 1);

  a = simde_mm512_loadu_pd(test_vec[44].a);
  r = simde_mm512_roundscale_pd(a, INT32_C(         194));
  simde_test_x86_assert_equal_f64x8(r, simde_mm512_loadu_pd(test_vec[44].r), 1);

  a = simde_mm512_loadu_pd(test_vec[45].a);
  r = simde_mm512_roundscale_pd(a, INT32_C(         210));
  simde_test_x86_assert_equal_f64x8(r, simde_mm512_loadu_pd(test_vec[45].r), 1);

  a = simde_mm512_loadu_pd(test_vec[46].a);
  r = simde_mm512_roundscale_pd(a, INT32_C(         226));
  simde_test_x86_assert_equal_f64x8(r, simde_mm512_loadu_pd(test_vec[46].r), 1);

  a = simde_mm512_loadu_pd(test_vec[47].a);
  r = simde_mm512_roundscale_pd(a, INT32_C(         242));
  simde_test_x86_assert_equal_f64x8(r, simde_mm512_loadu_pd(test_vec[47].r), 1);

  a = simde_mm512_loadu_pd(test_vec[48].a);
  r = simde_mm512_roundscale_pd(a, INT32_C(           3));
  simde_test_x86_assert_equal_f64x8(r, simde_mm512_loadu_pd(test_vec[48].r), 1);

  a = simde_mm512_loadu_pd(test_vec[49].a);
  r = simde_mm512_roundscale_pd(a, INT32_C(          19));
  simde_test_x86_assert_equal_f64x8(r, simde_mm512_loadu_pd(test_vec[49].r), 1);

  a = simde_mm512_loadu_pd(test_vec[50].a);
  r = simde_mm512_roundscale_pd(a, INT32_C(          35));
  simde_test_x86_assert_equal_f64x8(r, simde_mm512_loadu_pd(test_vec[50].r), 1);

  a = simde_mm512_loadu_pd(test_vec[51].a);
  r = simde_mm512_roundscale_pd(a, INT32_C(          51));
  simde_test_x86_assert_equal_f64x8(r, simde_mm512_loadu_pd(test_vec[51].r), 1);

  a = simde_mm512_loadu_pd(test_vec[52].a);
  r = simde_mm512_roundscale_pd(a, INT32_C(          67));
  simde_test_x86_assert_equal_f64x8(r, simde_mm512_loadu_pd(test_vec[52].r), 1);

  a = simde_mm512_loadu_pd(test_vec[53].a);
  r = simde_mm512_roundscale_pd(a, INT32_C(          83));
  simde_test_x86_assert_equal_f64x8(r, simde_mm512_loadu_pd(test_vec[53].r), 1);

  a = simde_mm512_loadu_pd(test_vec[54].a);
  r = simde_mm512_roundscale_pd(a, INT32_C(          99));
  simde_test_x86_assert_equal_f64x8(r, simde_mm512_loadu_pd(test_vec[54].r), 1);

  a = simde_mm512_loadu_pd(test_vec[55].a);
  r = simde_mm512_roundscale_pd(a, INT32_C(         115));
  simde_test_x86_assert_equal_f64x8(r, simde_mm512_loadu_pd(test_vec[55].r), 1);

  a = simde_mm512_loadu_pd(test_vec[56].a);
  r = simde_mm512_roundscale_pd(a, INT32_C(         131));
  simde_test_x86_assert_equal_f64x8(r, simde_mm512_loadu_pd(test_vec[56].r), 1);

  a = simde_mm512_loadu_pd(test_vec[57].a);
  r = simde_mm512_roundscale_pd(a, INT32_C(         147));
  simde_test_x86_assert_equal_f64x8(r, simde_mm512_loadu_pd(test_vec[57].r), 1);

  a = simde_mm512_loadu_pd(test_vec[58].a);
  r = simde_mm512_roundscale_pd(a, INT32_C(         163));
  simde_test_x86_assert_equal_f64x8(r, simde_mm512_loadu_pd(test_vec[58].r), 1);

  a = simde_mm512_loadu_pd(test_vec[59].a);
  r = simde_mm512_roundscale_pd(a, INT32_C(         179));
  simde_test_x86_assert_equal_f64x8(r, simde_mm512_loadu_pd(test_vec[59].r), 1);

  a = simde_mm512_loadu_pd(test_vec[60].a);
  r = simde_mm512_roundscale_pd(a, INT32_C(         195));
  simde_test_x86_assert_equal_f64x8(r, simde_mm512_loadu_pd(test_vec[60].r), 1);

  a = simde_mm512_loadu_pd(test_vec[61].a);
  r = simde_mm512_roundscale_pd(a, INT32_C(         211));
  simde_test_x86_assert_equal_f64x8(r, simde_mm512_loadu_pd(test_vec[61].r), 1);

  a = simde_mm512_loadu_pd(test_vec[62].a);
  r = simde_mm512_roundscale_pd(a, INT32_C(         227));
  simde_test_x86_assert_equal_f64x8(r, simde_mm512_loadu_pd(test_vec[62].r), 1);

  a = simde_mm512_loadu_pd(test_vec[63].a);
  r = simde_mm512_roundscale_pd(a, INT32_C(         243));
  simde_test_x86_assert_equal_f64x8(r, simde_mm512_loadu_pd(test_vec[63].r), 1);

  a = simde_mm512_loadu_pd(test_vec[64].a);
  r = simde_mm512_roundscale_pd(a, INT32_C(           4));
  simde_test_x86_assert_equal_f64x8(r, simde_mm512_loadu_pd(test_vec[64].r), 1);

  a = simde_mm512_loadu_pd(test_vec[65].a);
  r = simde_mm512_roundscale_pd(a, INT32_C(          20));
  simde_test_x86_assert_equal_f64x8(r, simde_mm512_loadu_pd(test_vec[65].r), 1);

  a = simde_mm512_loadu_pd(test_vec[66].a);
  r = simde_mm512_roundscale_pd(a, INT32_C(          36));
  simde_test_x86_assert_equal_f64x8(r, simde_mm512_loadu_pd(test_vec[66].r), 1);

  a = simde_mm512_loadu_pd(test_vec[67].a);
  r = simde_mm512_roundscale_pd(a, INT32_C(          52));
  simde_test_x86_assert_equal_f64x8(r, simde_mm512_loadu_pd(test_vec[67].r), 1);

  a = simde_mm512_loadu_pd(test_vec[68].a);
  r = simde_mm512_roundscale_pd(a, INT32_C(          68));
  simde_test_x86_assert_equal_f64x8(r, simde_mm512_loadu_pd(test_vec[68].r), 1);

  a = simde_mm512_loadu_pd(test_vec[69].a);
  r = simde_mm512_roundscale_pd(a, INT32_C(          84));
  simde_test_x86_assert_equal_f64x8(r, simde_mm512_loadu_pd(test_vec[69].r), 1);

  a = simde_mm512_loadu_pd(test_vec[70].a);
  r = simde_mm512_roundscale_pd(a, INT32_C(         100));
  simde_test_x86_assert_equal_f64x8(r, simde_mm512_loadu_pd(test_vec[70].r), 1);

  a = simde_mm512_loadu_pd(test_vec[71].a);
  r = simde_mm512_roundscale_pd(a, INT32_C(         116));
  simde_test_x86_assert_equal_f64x8(r, simde_mm512_loadu_pd(test_vec[71].r), 1);

  a = simde_mm512_loadu_pd(test_vec[72].a);
  r = simde_mm512_roundscale_pd(a, INT32_C(         132));
  simde_test_x86_assert_equal_f64x8(r, simde_mm512_loadu_pd(test_vec[72].r), 1);

  a = simde_mm512_loadu_pd(test_vec[73].a);
  r = simde_mm512_roundscale_pd(a, INT32_C(         148));
  simde_test_x86_assert_equal_f64x8(r, simde_mm512_loadu_pd(test_vec[73].r), 1);

  a = simde_mm512_loadu_pd(test_vec[74].a);
  r = simde_mm512_roundscale_pd(a, INT32_C(         164));
  simde_test_x86_assert_equal_f64x8(r, simde_mm512_loadu_pd(test_vec[74].r), 1);

  a = simde_mm512_loadu_pd(test_vec[75].a);
  r = simde_mm512_roundscale_pd(a, INT32_C(         180));
  simde_test_x86_assert_equal_f64x8(r, simde_mm512_loadu_pd(test_vec[75].r), 1);

  a = simde_mm512_loadu_pd(test_vec[76].a);
  r = simde_mm512_roundscale_pd(a, INT32_C(         196));
  simde_test_x86_assert_equal_f64x8(r, simde_mm512_loadu_pd(test_vec[76].r), 1);

  a = simde_mm512_loadu_pd(test_vec[77].a);
  r = simde_mm512_roundscale_pd(a, INT32_C(         212));
  simde_test_x86_assert_equal_f64x8(r, simde_mm512_loadu_pd(test_vec[77].r), 1);

  a = simde_mm512_loadu_pd(test_vec[78].a);
  r = simde_mm512_roundscale_pd(a, INT32_C(         228));
  simde_test_x86_assert_equal_f64x8(r, simde_mm512_loadu_pd(test_vec[78].r), 1);

  a = simde_mm512_loadu_pd(test_vec[79].a);
  r = simde_mm512_roundscale_pd(a, INT32_C(         244));
  simde_test_x86_assert_equal_f64x8(r, simde_mm512_loadu_pd(test_vec[79].r), 1);

  return 0;
#else
  fputc('\n', stdout);
  int round_type[5] = {SIMDE_MM_FROUND_TO_NEAREST_INT, SIMDE_MM_FROUND_TO_NEG_INF, SIMDE_MM_FROUND_TO_POS_INF, SIMDE_MM_FROUND_TO_ZERO, SIMDE_MM_FROUND_CUR_DIRECTION};
  for (int i = 0 ; i < 5 ; i++) {
    for (int j = 0 ; j < 16 ; j++) {
      simde__m512d a = simde_test_x86_random_f64x8(SIMDE_FLOAT64_C(-1000.0), SIMDE_FLOAT64_C(1000.0));
      if((simde_test_codegen_rand() & 1)) {
        if((simde_test_codegen_rand() & 1))
          a = simde_mm512_mask_mov_pd(a, 1, simde_mm512_set1_pd(SIMDE_MATH_NAN));
        else {
          if((simde_test_codegen_rand() & 1))
            a = simde_mm512_mask_mov_pd(a, 2, simde_mm512_set1_pd(SIMDE_MATH_INFINITY));
          else
            a = simde_mm512_mask_mov_pd(a, 2, simde_mm512_set1_pd(-SIMDE_MATH_INFINITY));
        }
      }
      int imm8 = ((j << 4) | round_type[i]) & 255;
      simde__m512d r;
      SIMDE_CONSTIFY_256_(simde_mm512_roundscale_pd, r, simde_mm512_setzero_pd(), imm8, a);

      simde_test_x86_write_f64x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
      simde_test_codegen_write_i32(2, imm8, SIMDE_TEST_VEC_POS_MIDDLE);
      simde_test_x86_write_f64x8(2, r, SIMDE_TEST_VEC_POS_LAST);
    }
  }
  return 1;
#endif
}

static int
test_simde_mm512_mask_roundscale_pd (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const simde_float64 src[8];
    const simde__mmask8 k;
    const simde_float64 a[8];
    const int32_t imm8;
    const simde_float64 r[8];
  } test_vec[] = {
    { { SIMDE_FLOAT64_C(  -157.27), SIMDE_FLOAT64_C(   107.68), SIMDE_FLOAT64_C(   630.83), SIMDE_FLOAT64_C(  -905.04),
        SIMDE_FLOAT64_C(  -496.50), SIMDE_FLOAT64_C(   850.05), SIMDE_FLOAT64_C(  -847.15), SIMDE_FLOAT64_C(  -488.99) },
      UINT8_C( 82),
      { SIMDE_FLOAT64_C(    92.08),        SIMDE_MATH_INFINITY, SIMDE_FLOAT64_C(   673.37), SIMDE_FLOAT64_C(  -818.01),
        SIMDE_FLOAT64_C(  -755.51), SIMDE_FLOAT64_C(  -570.18), SIMDE_FLOAT64_C(  -127.51), SIMDE_FLOAT64_C(    50.84) },
       INT32_C(         192),
      { SIMDE_FLOAT64_C(  -157.27),        SIMDE_MATH_INFINITY, SIMDE_FLOAT64_C(   630.83), SIMDE_FLOAT64_C(  -905.04),
        SIMDE_FLOAT64_C(  -755.51), SIMDE_FLOAT64_C(   850.05), SIMDE_FLOAT64_C(  -127.51), SIMDE_FLOAT64_C(  -488.99) } },
    { { SIMDE_FLOAT64_C(  -447.85), SIMDE_FLOAT64_C(  -701.14), SIMDE_FLOAT64_C(   316.16), SIMDE_FLOAT64_C(   117.46),
        SIMDE_FLOAT64_C(   360.05), SIMDE_FLOAT64_C(   -16.49), SIMDE_FLOAT64_C(   900.84), SIMDE_FLOAT64_C(  -215.65) },
      UINT8_C(133),
      { SIMDE_FLOAT64_C(   239.19), SIMDE_FLOAT64_C(   627.08), SIMDE_FLOAT64_C(   817.84), SIMDE_FLOAT64_C(  -129.99),
        SIMDE_FLOAT64_C(   722.04), SIMDE_FLOAT64_C(  -678.66), SIMDE_FLOAT64_C(  -279.94), SIMDE_FLOAT64_C(   874.89) },
       INT32_C(          81),
      { SIMDE_FLOAT64_C(   239.19), SIMDE_FLOAT64_C(  -701.14), SIMDE_FLOAT64_C(   817.81), SIMDE_FLOAT64_C(   117.46),
        SIMDE_FLOAT64_C(   360.05), SIMDE_FLOAT64_C(   -16.49), SIMDE_FLOAT64_C(   900.84), SIMDE_FLOAT64_C(   874.88) } },
    { { SIMDE_FLOAT64_C(   -33.03), SIMDE_FLOAT64_C(  -990.49), SIMDE_FLOAT64_C(  -243.90), SIMDE_FLOAT64_C(   148.97),
        SIMDE_FLOAT64_C(  -746.00), SIMDE_FLOAT64_C(   185.92), SIMDE_FLOAT64_C(  -978.54), SIMDE_FLOAT64_C(   304.84) },
      UINT8_C(135),
      { SIMDE_FLOAT64_C(   255.00), SIMDE_FLOAT64_C(   685.58), SIMDE_FLOAT64_C(  -123.66), SIMDE_FLOAT64_C(   807.15),
        SIMDE_FLOAT64_C(   984.44), SIMDE_FLOAT64_C(  -807.49), SIMDE_FLOAT64_C(   -75.38), SIMDE_FLOAT64_C(   344.49) },
       INT32_C(         242),
      { SIMDE_FLOAT64_C(   255.00), SIMDE_FLOAT64_C(   685.58), SIMDE_FLOAT64_C(  -123.66), SIMDE_FLOAT64_C(   148.97),
        SIMDE_FLOAT64_C(  -746.00), SIMDE_FLOAT64_C(   185.92), SIMDE_FLOAT64_C(  -978.54), SIMDE_FLOAT64_C(   344.49) } },
    { { SIMDE_FLOAT64_C(  -871.16), SIMDE_FLOAT64_C(   886.18), SIMDE_FLOAT64_C(  -935.35), SIMDE_FLOAT64_C(   755.92),
        SIMDE_FLOAT64_C(   704.02), SIMDE_FLOAT64_C(   -65.34), SIMDE_FLOAT64_C(   477.96), SIMDE_FLOAT64_C(  -974.64) },
      UINT8_C( 57),
      { SIMDE_FLOAT64_C(   352.85), SIMDE_FLOAT64_C(  -142.29), SIMDE_FLOAT64_C(  -262.55), SIMDE_FLOAT64_C(  -680.18),
        SIMDE_FLOAT64_C(  -132.78), SIMDE_FLOAT64_C(   493.55), SIMDE_FLOAT64_C(   468.79), SIMDE_FLOAT64_C(   121.22) },
       INT32_C(          99),
      { SIMDE_FLOAT64_C(   352.84), SIMDE_FLOAT64_C(   886.18), SIMDE_FLOAT64_C(  -935.35), SIMDE_FLOAT64_C(  -680.17),
        SIMDE_FLOAT64_C(  -132.77), SIMDE_FLOAT64_C(   493.55), SIMDE_FLOAT64_C(   477.96), SIMDE_FLOAT64_C(  -974.64) } },
    { { SIMDE_FLOAT64_C(  -573.94), SIMDE_FLOAT64_C(   992.80), SIMDE_FLOAT64_C(  -254.75), SIMDE_FLOAT64_C(  -888.36),
        SIMDE_FLOAT64_C(  -130.86), SIMDE_FLOAT64_C(  -447.59), SIMDE_FLOAT64_C(  -903.92), SIMDE_FLOAT64_C(    61.65) },
      UINT8_C(208),
      { SIMDE_FLOAT64_C(   440.58), SIMDE_FLOAT64_C(  -762.33), SIMDE_FLOAT64_C(  -697.52), SIMDE_FLOAT64_C(   569.41),
        SIMDE_FLOAT64_C(  -876.15), SIMDE_FLOAT64_C(  -632.88), SIMDE_FLOAT64_C(   325.33), SIMDE_FLOAT64_C(   827.87) },
       INT32_C(           4),
      { SIMDE_FLOAT64_C(  -573.94), SIMDE_FLOAT64_C(   992.80), SIMDE_FLOAT64_C(  -254.75), SIMDE_FLOAT64_C(  -888.36),
        SIMDE_FLOAT64_C(  -876.00), SIMDE_FLOAT64_C(  -447.59), SIMDE_FLOAT64_C(   325.00), SIMDE_FLOAT64_C(   828.00) } },
    { { SIMDE_FLOAT64_C(   853.23), SIMDE_FLOAT64_C(   -43.49), SIMDE_FLOAT64_C(  -843.86), SIMDE_FLOAT64_C(  -289.06),
        SIMDE_FLOAT64_C(   693.96), SIMDE_FLOAT64_C(  -524.04), SIMDE_FLOAT64_C(   578.16), SIMDE_FLOAT64_C(   187.50) },
      UINT8_C( 25),
      { SIMDE_FLOAT64_C(  -300.62),        SIMDE_MATH_INFINITY, SIMDE_FLOAT64_C(   435.01), SIMDE_FLOAT64_C(   125.44),
        SIMDE_FLOAT64_C(   859.76), SIMDE_FLOAT64_C(  -819.74), SIMDE_FLOAT64_C(   237.08), SIMDE_FLOAT64_C(  -271.10) },
       INT32_C(         192),
      { SIMDE_FLOAT64_C(  -300.62), SIMDE_FLOAT64_C(   -43.49), SIMDE_FLOAT64_C(  -843.86), SIMDE_FLOAT64_C(   125.44),
        SIMDE_FLOAT64_C(   859.76), SIMDE_FLOAT64_C(  -524.04), SIMDE_FLOAT64_C(   578.16), SIMDE_FLOAT64_C(   187.50) } },
    { { SIMDE_FLOAT64_C(  -226.26), SIMDE_FLOAT64_C(  -971.78), SIMDE_FLOAT64_C(  -487.83), SIMDE_FLOAT64_C(  -656.85),
        SIMDE_FLOAT64_C(  -847.93), SIMDE_FLOAT64_C(  -120.71), SIMDE_FLOAT64_C(   668.48), SIMDE_FLOAT64_C(   979.94) },
      UINT8_C( 89),
      {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(   833.17), SIMDE_FLOAT64_C(   137.58), SIMDE_FLOAT64_C(  -372.09),
        SIMDE_FLOAT64_C(  -455.89), SIMDE_FLOAT64_C(  -168.46), SIMDE_FLOAT64_C(   103.87), SIMDE_FLOAT64_C(  -877.73) },
       INT32_C(         177),
      {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(  -971.78), SIMDE_FLOAT64_C(  -487.83), SIMDE_FLOAT64_C(  -372.09),
        SIMDE_FLOAT64_C(  -455.89), SIMDE_FLOAT64_C(  -120.71), SIMDE_FLOAT64_C(   103.87), SIMDE_FLOAT64_C(   979.94) } },
    { { SIMDE_FLOAT64_C(   886.00), SIMDE_FLOAT64_C(  -516.36), SIMDE_FLOAT64_C(   947.10), SIMDE_FLOAT64_C(   745.77),
        SIMDE_FLOAT64_C(  -336.10), SIMDE_FLOAT64_C(   184.18), SIMDE_FLOAT64_C(  -525.33), SIMDE_FLOAT64_C(   396.56) },
      UINT8_C(254),
      { SIMDE_FLOAT64_C(  -734.78), SIMDE_FLOAT64_C(   606.25), SIMDE_FLOAT64_C(   291.08), SIMDE_FLOAT64_C(  -706.55),
        SIMDE_FLOAT64_C(  -881.59), SIMDE_FLOAT64_C(   634.23), SIMDE_FLOAT64_C(  -554.48), SIMDE_FLOAT64_C(    -2.30) },
       INT32_C(         178),
      { SIMDE_FLOAT64_C(   886.00), SIMDE_FLOAT64_C(   606.25), SIMDE_FLOAT64_C(   291.08), SIMDE_FLOAT64_C(  -706.55),
        SIMDE_FLOAT64_C(  -881.59), SIMDE_FLOAT64_C(   634.23), SIMDE_FLOAT64_C(  -554.48), SIMDE_FLOAT64_C(    -2.30) } },
  };

  simde__m512d src, a, r;

  src = simde_mm512_loadu_pd(test_vec[0].src);
  a = simde_mm512_loadu_pd(test_vec[0].a);
  r = simde_mm512_mask_roundscale_pd(src, test_vec[0].k, a, INT32_C(         192));
  simde_test_x86_assert_equal_f64x8(r, simde_mm512_loadu_pd(test_vec[0].r), 1);

  src = simde_mm512_loadu_pd(test_vec[1].src);
  a = simde_mm512_loadu_pd(test_vec[1].a);
  r = simde_mm512_mask_roundscale_pd(src, test_vec[1].k, a, INT32_C(          81));
  simde_test_x86_assert_equal_f64x8(r, simde_mm512_loadu_pd(test_vec[1].r), 1);

  src = simde_mm512_loadu_pd(test_vec[2].src);
  a = simde_mm512_loadu_pd(test_vec[2].a);
  r = simde_mm512_mask_roundscale_pd(src, test_vec[2].k, a, INT32_C(         242));
  simde_test_x86_assert_equal_f64x8(r, simde_mm512_loadu_pd(test_vec[2].r), 1);

  src = simde_mm512_loadu_pd(test_vec[3].src);
  a = simde_mm512_loadu_pd(test_vec[3].a);
  r = simde_mm512_mask_roundscale_pd(src, test_vec[3].k, a, INT32_C(          99));
  simde_test_x86_assert_equal_f64x8(r, simde_mm512_loadu_pd(test_vec[3].r), 1);

  src = simde_mm512_loadu_pd(test_vec[4].src);
  a = simde_mm512_loadu_pd(test_vec[4].a);
  r = simde_mm512_mask_roundscale_pd(src, test_vec[4].k, a, INT32_C(           4));
  simde_test_x86_assert_equal_f64x8(r, simde_mm512_loadu_pd(test_vec[4].r), 1);

  src = simde_mm512_loadu_pd(test_vec[5].src);
  a = simde_mm512_loadu_pd(test_vec[5].a);
  r = simde_mm512_mask_roundscale_pd(src, test_vec[5].k, a, INT32_C(         192));
  simde_test_x86_assert_equal_f64x8(r, simde_mm512_loadu_pd(test_vec[5].r), 1);

  src = simde_mm512_loadu_pd(test_vec[6].src);
  a = simde_mm512_loadu_pd(test_vec[6].a);
  r = simde_mm512_mask_roundscale_pd(src, test_vec[6].k, a, INT32_C(         177));
  simde_test_x86_assert_equal_f64x8(r, simde_mm512_loadu_pd(test_vec[6].r), 1);

  src = simde_mm512_loadu_pd(test_vec[7].src);
  a = simde_mm512_loadu_pd(test_vec[7].a);
  r = simde_mm512_mask_roundscale_pd(src, test_vec[7].k, a, INT32_C(         178));
  simde_test_x86_assert_equal_f64x8(r, simde_mm512_loadu_pd(test_vec[7].r), 1);

  return 0;
#else
  fputc('\n', stdout);
  int round_type[5] = {SIMDE_MM_FROUND_TO_NEAREST_INT, SIMDE_MM_FROUND_TO_NEG_INF, SIMDE_MM_FROUND_TO_POS_INF, SIMDE_MM_FROUND_TO_ZERO, SIMDE_MM_FROUND_CUR_DIRECTION};
  for (int i = 0 ; i < 8 ; i++) {
    simde__m512d src = simde_test_x86_random_f64x8(SIMDE_FLOAT64_C(-1000.0), SIMDE_FLOAT64_C(1000.0));
    simde__mmask8 k = simde_test_x86_random_mmask8();
    simde__m512d a = simde_test_x86_random_f64x8(SIMDE_FLOAT64_C(-1000.0), SIMDE_FLOAT64_C(1000.0));
    if((simde_test_codegen_rand() & 1)) {
      if((simde_test_codegen_rand() & 1))
        a = simde_mm512_mask_mov_pd(a, 1, simde_mm512_set1_pd(SIMDE_MATH_NAN));
      else {
        if((simde_test_codegen_rand() & 1))
          a = simde_mm512_mask_mov_pd(a, 2, simde_mm512_set1_pd(SIMDE_MATH_INFINITY));
        else
          a = simde_mm512_mask_mov_pd(a, 2, simde_mm512_set1_pd(-SIMDE_MATH_INFINITY));
      }
    }
    int imm8 = (((simde_test_codegen_rand() & 15) << 4) | round_type[i % 5]) & 255;
    simde__m512d r;
    SIMDE_CONSTIFY_256_(simde_mm512_mask_roundscale_pd, r, simde_mm512_setzero_pd(), imm8, src, k, a);

    simde_test_x86_write_f64x8(2, src, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_mmask8(2, k, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_f64x8(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i32(2, imm8, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_f64x8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm512_maskz_roundscale_pd (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const simde__mmask8 k;
    const simde_float64 a[8];
    const int32_t imm8;
    const simde_float64 r[8];
  } test_vec[] = {
    { UINT8_C(216),
      { SIMDE_FLOAT64_C(   774.48), SIMDE_FLOAT64_C(  -741.37), SIMDE_FLOAT64_C(  -683.64), SIMDE_FLOAT64_C(  -597.61),
        SIMDE_FLOAT64_C(  -197.26), SIMDE_FLOAT64_C(   147.89), SIMDE_FLOAT64_C(   506.26), SIMDE_FLOAT64_C(   -74.98) },
       INT32_C(         160),
      { SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(  -597.61),
        SIMDE_FLOAT64_C(  -197.26), SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(   506.26), SIMDE_FLOAT64_C(   -74.98) } },
    { UINT8_C(243),
      {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(    38.53), SIMDE_FLOAT64_C(   693.77), SIMDE_FLOAT64_C(  -201.30),
        SIMDE_FLOAT64_C(   702.42), SIMDE_FLOAT64_C(  -122.05), SIMDE_FLOAT64_C(   273.37), SIMDE_FLOAT64_C(    98.98) },
       INT32_C(         145),
      {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(    38.53), SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(     0.00),
        SIMDE_FLOAT64_C(   702.42), SIMDE_FLOAT64_C(  -122.05), SIMDE_FLOAT64_C(   273.37), SIMDE_FLOAT64_C(    98.98) } },
    { UINT8_C( 32),
      { SIMDE_FLOAT64_C(   832.04), SIMDE_FLOAT64_C(  -176.36), SIMDE_FLOAT64_C(  -679.40), SIMDE_FLOAT64_C(  -722.44),
        SIMDE_FLOAT64_C(   821.34), SIMDE_FLOAT64_C(   623.31), SIMDE_FLOAT64_C(  -296.98), SIMDE_FLOAT64_C(     0.12) },
       INT32_C(         242),
      { SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(     0.00),
        SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(   623.31), SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(     0.00) } },
    { UINT8_C( 37),
      { SIMDE_FLOAT64_C(   800.18), SIMDE_FLOAT64_C(   764.40), SIMDE_FLOAT64_C(  -535.63), SIMDE_FLOAT64_C(   306.44),
        SIMDE_FLOAT64_C(  -310.58), SIMDE_FLOAT64_C(   631.30), SIMDE_FLOAT64_C(   861.33), SIMDE_FLOAT64_C(  -563.91) },
       INT32_C(          67),
      { SIMDE_FLOAT64_C(   800.12), SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(  -535.62), SIMDE_FLOAT64_C(     0.00),
        SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(   631.25), SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(     0.00) } },
    { UINT8_C(113),
      { SIMDE_FLOAT64_C(   482.93),       -SIMDE_MATH_INFINITY, SIMDE_FLOAT64_C(     7.81), SIMDE_FLOAT64_C(  -243.70),
        SIMDE_FLOAT64_C(   701.26), SIMDE_FLOAT64_C(  -596.90), SIMDE_FLOAT64_C(  -705.10), SIMDE_FLOAT64_C(  -593.51) },
       INT32_C(         164),
      { SIMDE_FLOAT64_C(   482.93), SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(     0.00),
        SIMDE_FLOAT64_C(   701.26), SIMDE_FLOAT64_C(  -596.90), SIMDE_FLOAT64_C(  -705.10), SIMDE_FLOAT64_C(     0.00) } },
    { UINT8_C(137),
      { SIMDE_FLOAT64_C(    51.46),       -SIMDE_MATH_INFINITY, SIMDE_FLOAT64_C(   107.51), SIMDE_FLOAT64_C(  -948.42),
        SIMDE_FLOAT64_C(  -568.82), SIMDE_FLOAT64_C(  -930.83), SIMDE_FLOAT64_C(   368.05), SIMDE_FLOAT64_C(  -768.64) },
       INT32_C(          64),
      { SIMDE_FLOAT64_C(    51.44), SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(  -948.44),
        SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(  -768.62) } },
    { UINT8_C(245),
      { SIMDE_FLOAT64_C(   399.14), SIMDE_FLOAT64_C(   -40.92), SIMDE_FLOAT64_C(  -852.05), SIMDE_FLOAT64_C(  -701.01),
        SIMDE_FLOAT64_C(    88.94), SIMDE_FLOAT64_C(   630.88), SIMDE_FLOAT64_C(   -98.73), SIMDE_FLOAT64_C(  -903.25) },
       INT32_C(         225),
      { SIMDE_FLOAT64_C(   399.14), SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(  -852.05), SIMDE_FLOAT64_C(     0.00),
        SIMDE_FLOAT64_C(    88.94), SIMDE_FLOAT64_C(   630.88), SIMDE_FLOAT64_C(   -98.73), SIMDE_FLOAT64_C(  -903.25) } },
    { UINT8_C( 71),
      {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(     9.01), SIMDE_FLOAT64_C(   589.32), SIMDE_FLOAT64_C(  -190.99),
        SIMDE_FLOAT64_C(  -760.86), SIMDE_FLOAT64_C(    -0.61), SIMDE_FLOAT64_C(   213.50), SIMDE_FLOAT64_C(   290.60) },
       INT32_C(         210),
      {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(     9.01), SIMDE_FLOAT64_C(   589.32), SIMDE_FLOAT64_C(     0.00),
        SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(   213.50), SIMDE_FLOAT64_C(     0.00) } },
  };

  simde__m512d a, r;

  a = simde_mm512_loadu_pd(test_vec[0].a);
  r = simde_mm512_maskz_roundscale_pd(test_vec[0].k, a, INT32_C(         160));
  simde_test_x86_assert_equal_f64x8(r, simde_mm512_loadu_pd(test_vec[0].r), 1);

  a = simde_mm512_loadu_pd(test_vec[1].a);
  r = simde_mm512_maskz_roundscale_pd(test_vec[1].k, a, INT32_C(         145));
  simde_test_x86_assert_equal_f64x8(r, simde_mm512_loadu_pd(test_vec[1].r), 1);

  a = simde_mm512_loadu_pd(test_vec[2].a);
  r = simde_mm512_maskz_roundscale_pd(test_vec[2].k, a, INT32_C(         242));
  simde_test_x86_assert_equal_f64x8(r, simde_mm512_loadu_pd(test_vec[2].r), 1);

  a = simde_mm512_loadu_pd(test_vec[3].a);
  r = simde_mm512_maskz_roundscale_pd(test_vec[3].k, a, INT32_C(          67));
  simde_test_x86_assert_equal_f64x8(r, simde_mm512_loadu_pd(test_vec[3].r), 1);

  a = simde_mm512_loadu_pd(test_vec[4].a);
  r = simde_mm512_maskz_roundscale_pd(test_vec[4].k, a, INT32_C(         164));
  simde_test_x86_assert_equal_f64x8(r, simde_mm512_loadu_pd(test_vec[4].r), 1);

  a = simde_mm512_loadu_pd(test_vec[5].a);
  r = simde_mm512_maskz_roundscale_pd(test_vec[5].k, a, INT32_C(          64));
  simde_test_x86_assert_equal_f64x8(r, simde_mm512_loadu_pd(test_vec[5].r), 1);

  a = simde_mm512_loadu_pd(test_vec[6].a);
  r = simde_mm512_maskz_roundscale_pd(test_vec[6].k, a, INT32_C(         225));
  simde_test_x86_assert_equal_f64x8(r, simde_mm512_loadu_pd(test_vec[6].r), 1);

  a = simde_mm512_loadu_pd(test_vec[7].a);
  r = simde_mm512_maskz_roundscale_pd(test_vec[7].k, a, INT32_C(         210));
  simde_test_x86_assert_equal_f64x8(r, simde_mm512_loadu_pd(test_vec[7].r), 1);

  return 0;
#else
  fputc('\n', stdout);
  int round_type[5] = {SIMDE_MM_FROUND_TO_NEAREST_INT, SIMDE_MM_FROUND_TO_NEG_INF, SIMDE_MM_FROUND_TO_POS_INF, SIMDE_MM_FROUND_TO_ZERO, SIMDE_MM_FROUND_CUR_DIRECTION};
  for (int i = 0 ; i < 8 ; i++) {
    simde__mmask8 k = simde_test_x86_random_mmask8();
    simde__m512d a = simde_test_x86_random_f64x8(SIMDE_FLOAT64_C(-1000.0), SIMDE_FLOAT64_C(1000.0));
    if((simde_test_codegen_rand() & 1)) {
      if((simde_test_codegen_rand() & 1))
        a = simde_mm512_mask_mov_pd(a, 1, simde_mm512_set1_pd(SIMDE_MATH_NAN));
      else {
        if((simde_test_codegen_rand() & 1))
          a = simde_mm512_mask_mov_pd(a, 2, simde_mm512_set1_pd(SIMDE_MATH_INFINITY));
        else
          a = simde_mm512_mask_mov_pd(a, 2, simde_mm512_set1_pd(-SIMDE_MATH_INFINITY));
      }
    }
    int imm8 = (((simde_test_codegen_rand() & 15) << 4) | round_type[i % 5]) & 255;
    simde__m512d r;
    SIMDE_CONSTIFY_256_(simde_mm512_maskz_roundscale_pd, r, simde_mm512_setzero_pd(), imm8, k, a);

    simde_test_x86_write_mmask8(2, k, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_f64x8(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i32(2, imm8, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_f64x8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm512_roundscale_round_pd (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const simde_float64 a[8];
    const int32_t imm8;
    const int32_t sae;
    const simde_float64 r[8];
  } test_vec[] = {
    { { SIMDE_FLOAT64_C(  -764.76), SIMDE_FLOAT64_C(   372.30), SIMDE_FLOAT64_C(  -204.93), SIMDE_FLOAT64_C(   187.19),
        SIMDE_FLOAT64_C(   319.82), SIMDE_FLOAT64_C(  -587.65), SIMDE_FLOAT64_C(  -285.97), SIMDE_FLOAT64_C(  -184.26) },
       INT32_C(         224),
       INT32_C(           8),
      { SIMDE_FLOAT64_C(  -764.76), SIMDE_FLOAT64_C(   372.30), SIMDE_FLOAT64_C(  -204.93), SIMDE_FLOAT64_C(   187.19),
        SIMDE_FLOAT64_C(   319.82), SIMDE_FLOAT64_C(  -587.65), SIMDE_FLOAT64_C(  -285.97), SIMDE_FLOAT64_C(  -184.26) } },
    { {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(  -737.42), SIMDE_FLOAT64_C(   189.61), SIMDE_FLOAT64_C(   596.45),
        SIMDE_FLOAT64_C(  -867.46), SIMDE_FLOAT64_C(  -762.70), SIMDE_FLOAT64_C(    52.01), SIMDE_FLOAT64_C(   506.49) },
       INT32_C(         225),
       INT32_C(           8),
      {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(  -737.42), SIMDE_FLOAT64_C(   189.61), SIMDE_FLOAT64_C(   596.45),
        SIMDE_FLOAT64_C(  -867.46), SIMDE_FLOAT64_C(  -762.70), SIMDE_FLOAT64_C(    52.01), SIMDE_FLOAT64_C(   506.49) } },
    { { SIMDE_FLOAT64_C(  -225.83), SIMDE_FLOAT64_C(   341.08), SIMDE_FLOAT64_C(  -924.52), SIMDE_FLOAT64_C(   659.69),
        SIMDE_FLOAT64_C(   637.52), SIMDE_FLOAT64_C(   570.34), SIMDE_FLOAT64_C(  -794.05), SIMDE_FLOAT64_C(   295.70) },
       INT32_C(         114),
       INT32_C(           4),
      { SIMDE_FLOAT64_C(  -225.83), SIMDE_FLOAT64_C(   341.09), SIMDE_FLOAT64_C(  -924.52), SIMDE_FLOAT64_C(   659.70),
        SIMDE_FLOAT64_C(   637.52), SIMDE_FLOAT64_C(   570.34), SIMDE_FLOAT64_C(  -794.05), SIMDE_FLOAT64_C(   295.70) } },
    { { SIMDE_FLOAT64_C(    -7.23), SIMDE_FLOAT64_C(  -101.93), SIMDE_FLOAT64_C(  -496.88), SIMDE_FLOAT64_C(   706.80),
        SIMDE_FLOAT64_C(   713.81), SIMDE_FLOAT64_C(    25.71), SIMDE_FLOAT64_C(  -458.99), SIMDE_FLOAT64_C(  -420.32) },
       INT32_C(          35),
       INT32_C(           4),
      { SIMDE_FLOAT64_C(    -7.00), SIMDE_FLOAT64_C(  -101.75), SIMDE_FLOAT64_C(  -496.75), SIMDE_FLOAT64_C(   706.75),
        SIMDE_FLOAT64_C(   713.75), SIMDE_FLOAT64_C(    25.50), SIMDE_FLOAT64_C(  -458.75), SIMDE_FLOAT64_C(  -420.25) } },
    { {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(   -63.86), SIMDE_FLOAT64_C(  -993.41), SIMDE_FLOAT64_C(   848.39),
        SIMDE_FLOAT64_C(  -557.37), SIMDE_FLOAT64_C(  -180.81), SIMDE_FLOAT64_C(  -935.49), SIMDE_FLOAT64_C(   801.51) },
       INT32_C(         100),
       INT32_C(           4),
      {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(   -63.86), SIMDE_FLOAT64_C(  -993.41), SIMDE_FLOAT64_C(   848.39),
        SIMDE_FLOAT64_C(  -557.38), SIMDE_FLOAT64_C(  -180.81), SIMDE_FLOAT64_C(  -935.48), SIMDE_FLOAT64_C(   801.52) } },
    { { SIMDE_FLOAT64_C(  -501.64), SIMDE_FLOAT64_C(  -219.90), SIMDE_FLOAT64_C(  -472.78), SIMDE_FLOAT64_C(  -295.68),
        SIMDE_FLOAT64_C(  -924.20), SIMDE_FLOAT64_C(  -667.20), SIMDE_FLOAT64_C(  -717.43), SIMDE_FLOAT64_C(  -833.43) },
       INT32_C(          48),
       INT32_C(           8),
      { SIMDE_FLOAT64_C(  -501.62), SIMDE_FLOAT64_C(  -219.88), SIMDE_FLOAT64_C(  -472.75), SIMDE_FLOAT64_C(  -295.62),
        SIMDE_FLOAT64_C(  -924.25), SIMDE_FLOAT64_C(  -667.25), SIMDE_FLOAT64_C(  -717.38), SIMDE_FLOAT64_C(  -833.38) } },
    { { SIMDE_FLOAT64_C(    32.37),       -SIMDE_MATH_INFINITY, SIMDE_FLOAT64_C(   695.40), SIMDE_FLOAT64_C(   573.38),
        SIMDE_FLOAT64_C(   474.12), SIMDE_FLOAT64_C(  -104.66), SIMDE_FLOAT64_C(  -623.03), SIMDE_FLOAT64_C(   243.41) },
       INT32_C(          33),
       INT32_C(           8),
      { SIMDE_FLOAT64_C(    32.25),       -SIMDE_MATH_INFINITY, SIMDE_FLOAT64_C(   695.25), SIMDE_FLOAT64_C(   573.25),
        SIMDE_FLOAT64_C(   474.00), SIMDE_FLOAT64_C(  -104.75), SIMDE_FLOAT64_C(  -623.25), SIMDE_FLOAT64_C(   243.25) } },
    { { SIMDE_FLOAT64_C(  -930.80),        SIMDE_MATH_INFINITY, SIMDE_FLOAT64_C(   557.24), SIMDE_FLOAT64_C(   -49.40),
        SIMDE_FLOAT64_C(  -556.69), SIMDE_FLOAT64_C(  -300.17), SIMDE_FLOAT64_C(   907.48), SIMDE_FLOAT64_C(   -58.33) },
       INT32_C(         210),
       INT32_C(           8),
      { SIMDE_FLOAT64_C(  -930.80),        SIMDE_MATH_INFINITY, SIMDE_FLOAT64_C(   557.24), SIMDE_FLOAT64_C(   -49.40),
        SIMDE_FLOAT64_C(  -556.69), SIMDE_FLOAT64_C(  -300.17), SIMDE_FLOAT64_C(   907.48), SIMDE_FLOAT64_C(   -58.33) } },
  };

  simde__m512d a, r;

  a = simde_mm512_loadu_pd(test_vec[0].a);
  r = simde_mm512_roundscale_round_pd(a, INT32_C(         224), INT32_C(           8));
  simde_test_x86_assert_equal_f64x8(r, simde_mm512_loadu_pd(test_vec[0].r), 1);

  a = simde_mm512_loadu_pd(test_vec[1].a);
  r = simde_mm512_roundscale_round_pd(a, INT32_C(         225), INT32_C(           8));
  simde_test_x86_assert_equal_f64x8(r, simde_mm512_loadu_pd(test_vec[1].r), 1);

  a = simde_mm512_loadu_pd(test_vec[2].a);
  r = simde_mm512_roundscale_round_pd(a, INT32_C(         114), INT32_C(           4));
  simde_test_x86_assert_equal_f64x8(r, simde_mm512_loadu_pd(test_vec[2].r), 1);

  a = simde_mm512_loadu_pd(test_vec[3].a);
  r = simde_mm512_roundscale_round_pd(a, INT32_C(          35), INT32_C(           4));
  simde_test_x86_assert_equal_f64x8(r, simde_mm512_loadu_pd(test_vec[3].r), 1);

  a = simde_mm512_loadu_pd(test_vec[4].a);
  r = simde_mm512_roundscale_round_pd(a, INT32_C(         100), INT32_C(           4));
  simde_test_x86_assert_equal_f64x8(r, simde_mm512_loadu_pd(test_vec[4].r), 1);

  a = simde_mm512_loadu_pd(test_vec[5].a);
  r = simde_mm512_roundscale_round_pd(a, INT32_C(          48), INT32_C(           8));
  simde_test_x86_assert_equal_f64x8(r, simde_mm512_loadu_pd(test_vec[5].r), 1);

  a = simde_mm512_loadu_pd(test_vec[6].a);
  r = simde_mm512_roundscale_round_pd(a, INT32_C(          33), INT32_C(           8));
  simde_test_x86_assert_equal_f64x8(r, simde_mm512_loadu_pd(test_vec[6].r), 1);

  a = simde_mm512_loadu_pd(test_vec[7].a);
  r = simde_mm512_roundscale_round_pd(a, INT32_C(         210), INT32_C(           8));
  simde_test_x86_assert_equal_f64x8(r, simde_mm512_loadu_pd(test_vec[7].r), 1);

  return 0;
#else
  fputc('\n', stdout);
  int round_type[5] = {SIMDE_MM_FROUND_TO_NEAREST_INT, SIMDE_MM_FROUND_TO_NEG_INF, SIMDE_MM_FROUND_TO_POS_INF, SIMDE_MM_FROUND_TO_ZERO, SIMDE_MM_FROUND_CUR_DIRECTION};
  for (int i = 0 ; i < 8 ; i++) {
    simde__m512d a = simde_test_x86_random_f64x8(SIMDE_FLOAT64_C(-1000.0), SIMDE_FLOAT64_C(1000.0));
    if((simde_test_codegen_rand() & 1)) {
      if((simde_test_codegen_rand() & 1))
        a = simde_mm512_mask_mov_pd(a, 1, simde_mm512_set1_pd(SIMDE_MATH_NAN));
      else {
        if((simde_test_codegen_rand() & 1))
          a = simde_mm512_mask_mov_pd(a, 2, simde_mm512_set1_pd(SIMDE_MATH_INFINITY));
        else
          a = simde_mm512_mask_mov_pd(a, 2, simde_mm512_set1_pd(-SIMDE_MATH_INFINITY));
      }
    }
    int imm8 = (((simde_test_codegen_rand() & 15) << 4) | round_type[i % 5]) & 255;
    int sae = (simde_test_codegen_rand() & 1) ? SIMDE_MM_FROUND_CUR_DIRECTION : SIMDE_MM_FROUND_NO_EXC;
    simde__m512d r;
    SIMDE_CONSTIFY_256_NEW(simde_mm512_roundscale_round_pd, r, simde_mm512_setzero_pd(), imm8, sae, a);

    simde_test_x86_write_f64x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_codegen_write_i32(2, imm8, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i32(2, sae, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_f64x8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm512_mask_roundscale_round_pd (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const simde_float64 src[8];
    const simde__mmask8 k;
    const simde_float64 a[8];
    const int32_t imm8;
    const int32_t sae;
    const simde_float64 r[8];
  } test_vec[] = {
    { { SIMDE_FLOAT64_C(   586.90), SIMDE_FLOAT64_C(  -112.94), SIMDE_FLOAT64_C(  -235.54), SIMDE_FLOAT64_C(   172.88),
        SIMDE_FLOAT64_C(  -277.74), SIMDE_FLOAT64_C(   581.03), SIMDE_FLOAT64_C(   348.44), SIMDE_FLOAT64_C(   605.57) },
      UINT8_C( 95),
      { SIMDE_FLOAT64_C(   311.24),        SIMDE_MATH_INFINITY, SIMDE_FLOAT64_C(   137.73), SIMDE_FLOAT64_C(   690.30),
        SIMDE_FLOAT64_C(  -788.97), SIMDE_FLOAT64_C(   105.19), SIMDE_FLOAT64_C(   565.43), SIMDE_FLOAT64_C(   516.54) },
       INT32_C(          16),
       INT32_C(           4),
      { SIMDE_FLOAT64_C(   311.00),        SIMDE_MATH_INFINITY, SIMDE_FLOAT64_C(   137.50), SIMDE_FLOAT64_C(   690.50),
        SIMDE_FLOAT64_C(  -789.00), SIMDE_FLOAT64_C(   581.03), SIMDE_FLOAT64_C(   565.50), SIMDE_FLOAT64_C(   605.57) } },
    { { SIMDE_FLOAT64_C(  -756.52), SIMDE_FLOAT64_C(   407.18), SIMDE_FLOAT64_C(  -238.43), SIMDE_FLOAT64_C(   978.50),
        SIMDE_FLOAT64_C(   941.71), SIMDE_FLOAT64_C(   783.86), SIMDE_FLOAT64_C(  -197.05), SIMDE_FLOAT64_C(  -143.50) },
      UINT8_C(229),
      {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(   743.56), SIMDE_FLOAT64_C(   166.90), SIMDE_FLOAT64_C(   562.73),
        SIMDE_FLOAT64_C(  -534.18), SIMDE_FLOAT64_C(  -252.07), SIMDE_FLOAT64_C(   -88.83), SIMDE_FLOAT64_C(  -928.61) },
       INT32_C(         241),
       INT32_C(           8),
      {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(   407.18), SIMDE_FLOAT64_C(   166.90), SIMDE_FLOAT64_C(   978.50),
        SIMDE_FLOAT64_C(   941.71), SIMDE_FLOAT64_C(  -252.07), SIMDE_FLOAT64_C(   -88.83), SIMDE_FLOAT64_C(  -928.61) } },
    { { SIMDE_FLOAT64_C(   912.72), SIMDE_FLOAT64_C(  -558.33), SIMDE_FLOAT64_C(  -448.66), SIMDE_FLOAT64_C(   478.15),
        SIMDE_FLOAT64_C(   958.21), SIMDE_FLOAT64_C(  -141.38), SIMDE_FLOAT64_C(  -216.49), SIMDE_FLOAT64_C(  -842.28) },
      UINT8_C( 29),
      {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(  -598.80), SIMDE_FLOAT64_C(  -646.62), SIMDE_FLOAT64_C(  -242.27),
        SIMDE_FLOAT64_C(  -620.30), SIMDE_FLOAT64_C(  -704.91), SIMDE_FLOAT64_C(  -458.40), SIMDE_FLOAT64_C(   182.65) },
       INT32_C(           2),
       INT32_C(           4),
      {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(  -558.33), SIMDE_FLOAT64_C(  -646.00), SIMDE_FLOAT64_C(  -242.00),
        SIMDE_FLOAT64_C(  -620.00), SIMDE_FLOAT64_C(  -141.38), SIMDE_FLOAT64_C(  -216.49), SIMDE_FLOAT64_C(  -842.28) } },
    { { SIMDE_FLOAT64_C(  -889.06), SIMDE_FLOAT64_C(   135.23), SIMDE_FLOAT64_C(   360.97), SIMDE_FLOAT64_C(  -141.13),
        SIMDE_FLOAT64_C(  -953.60), SIMDE_FLOAT64_C(   432.35), SIMDE_FLOAT64_C(   167.30), SIMDE_FLOAT64_C(  -731.19) },
      UINT8_C(219),
      { SIMDE_FLOAT64_C(  -386.55), SIMDE_FLOAT64_C(  -818.48), SIMDE_FLOAT64_C(  -895.33), SIMDE_FLOAT64_C(   164.80),
        SIMDE_FLOAT64_C(   659.67), SIMDE_FLOAT64_C(  -937.13), SIMDE_FLOAT64_C(  -976.58), SIMDE_FLOAT64_C(  -556.82) },
       INT32_C(         163),
       INT32_C(           8),
      { SIMDE_FLOAT64_C(  -386.55), SIMDE_FLOAT64_C(  -818.48), SIMDE_FLOAT64_C(   360.97), SIMDE_FLOAT64_C(   164.80),
        SIMDE_FLOAT64_C(   659.67), SIMDE_FLOAT64_C(   432.35), SIMDE_FLOAT64_C(  -976.58), SIMDE_FLOAT64_C(  -556.82) } },
    { { SIMDE_FLOAT64_C(  -378.20), SIMDE_FLOAT64_C(   322.99), SIMDE_FLOAT64_C(   197.08), SIMDE_FLOAT64_C(     1.49),
        SIMDE_FLOAT64_C(   618.08), SIMDE_FLOAT64_C(   738.68), SIMDE_FLOAT64_C(  -815.86), SIMDE_FLOAT64_C(  -230.34) },
      UINT8_C(148),
      { SIMDE_FLOAT64_C(   756.64), SIMDE_FLOAT64_C(   664.81), SIMDE_FLOAT64_C(  -206.35), SIMDE_FLOAT64_C(  -108.13),
        SIMDE_FLOAT64_C(    25.78), SIMDE_FLOAT64_C(   652.52), SIMDE_FLOAT64_C(   -61.74), SIMDE_FLOAT64_C(  -541.86) },
       INT32_C(         132),
       INT32_C(           8),
      { SIMDE_FLOAT64_C(  -378.20), SIMDE_FLOAT64_C(   322.99), SIMDE_FLOAT64_C(  -206.35), SIMDE_FLOAT64_C(     1.49),
        SIMDE_FLOAT64_C(    25.78), SIMDE_FLOAT64_C(   738.68), SIMDE_FLOAT64_C(  -815.86), SIMDE_FLOAT64_C(  -541.86) } },
    { { SIMDE_FLOAT64_C(   433.27), SIMDE_FLOAT64_C(   388.59), SIMDE_FLOAT64_C(  -774.20), SIMDE_FLOAT64_C(  -401.93),
        SIMDE_FLOAT64_C(    48.26), SIMDE_FLOAT64_C(  -711.33), SIMDE_FLOAT64_C(  -378.51), SIMDE_FLOAT64_C(   491.44) },
      UINT8_C(198),
      {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(   930.79), SIMDE_FLOAT64_C(   131.07), SIMDE_FLOAT64_C(   -85.91),
        SIMDE_FLOAT64_C(   127.87), SIMDE_FLOAT64_C(  -867.44), SIMDE_FLOAT64_C(  -467.84), SIMDE_FLOAT64_C(  -133.46) },
       INT32_C(         160),
       INT32_C(           8),
      { SIMDE_FLOAT64_C(   433.27), SIMDE_FLOAT64_C(   930.79), SIMDE_FLOAT64_C(   131.07), SIMDE_FLOAT64_C(  -401.93),
        SIMDE_FLOAT64_C(    48.26), SIMDE_FLOAT64_C(  -711.33), SIMDE_FLOAT64_C(  -467.84), SIMDE_FLOAT64_C(  -133.46) } },
    { { SIMDE_FLOAT64_C(   -33.36), SIMDE_FLOAT64_C(  -657.09), SIMDE_FLOAT64_C(   -34.78), SIMDE_FLOAT64_C(   992.42),
        SIMDE_FLOAT64_C(   995.43), SIMDE_FLOAT64_C(   903.48), SIMDE_FLOAT64_C(  -549.44), SIMDE_FLOAT64_C(  -184.75) },
      UINT8_C( 83),
      { SIMDE_FLOAT64_C(  -428.31), SIMDE_FLOAT64_C(  -751.48), SIMDE_FLOAT64_C(  -500.86), SIMDE_FLOAT64_C(  -202.51),
        SIMDE_FLOAT64_C(  -153.40), SIMDE_FLOAT64_C(   547.40), SIMDE_FLOAT64_C(    86.17), SIMDE_FLOAT64_C(   468.08) },
       INT32_C(          81),
       INT32_C(           8),
      { SIMDE_FLOAT64_C(  -428.31), SIMDE_FLOAT64_C(  -751.50), SIMDE_FLOAT64_C(   -34.78), SIMDE_FLOAT64_C(   992.42),
        SIMDE_FLOAT64_C(  -153.41), SIMDE_FLOAT64_C(   903.48), SIMDE_FLOAT64_C(    86.16), SIMDE_FLOAT64_C(  -184.75) } },
    { { SIMDE_FLOAT64_C(   -30.38), SIMDE_FLOAT64_C(  -273.50), SIMDE_FLOAT64_C(   973.26), SIMDE_FLOAT64_C(  -902.51),
        SIMDE_FLOAT64_C(  -140.94), SIMDE_FLOAT64_C(  -494.57), SIMDE_FLOAT64_C(   -35.97), SIMDE_FLOAT64_C(   175.77) },
      UINT8_C(161),
      { SIMDE_FLOAT64_C(  -486.71), SIMDE_FLOAT64_C(   249.12), SIMDE_FLOAT64_C(  -226.11), SIMDE_FLOAT64_C(  -143.80),
        SIMDE_FLOAT64_C(  -785.67), SIMDE_FLOAT64_C(  -233.68), SIMDE_FLOAT64_C(  -148.38), SIMDE_FLOAT64_C(  -882.19) },
       INT32_C(         210),
       INT32_C(           4),
      { SIMDE_FLOAT64_C(  -486.71), SIMDE_FLOAT64_C(  -273.50), SIMDE_FLOAT64_C(   973.26), SIMDE_FLOAT64_C(  -902.51),
        SIMDE_FLOAT64_C(  -140.94), SIMDE_FLOAT64_C(  -233.68), SIMDE_FLOAT64_C(   -35.97), SIMDE_FLOAT64_C(  -882.19) } },
  };

  simde__m512d src, a, r;

  src = simde_mm512_loadu_pd(test_vec[0].src);
  a = simde_mm512_loadu_pd(test_vec[0].a);
  r = simde_mm512_mask_roundscale_round_pd(src, test_vec[0].k, a, INT32_C(          16), INT32_C(           4));
  simde_test_x86_assert_equal_f64x8(r, simde_mm512_loadu_pd(test_vec[0].r), 1);

  src = simde_mm512_loadu_pd(test_vec[1].src);
  a = simde_mm512_loadu_pd(test_vec[1].a);
  r = simde_mm512_mask_roundscale_round_pd(src, test_vec[1].k, a, INT32_C(         241), INT32_C(           8));
  simde_test_x86_assert_equal_f64x8(r, simde_mm512_loadu_pd(test_vec[1].r), 1);

  src = simde_mm512_loadu_pd(test_vec[2].src);
  a = simde_mm512_loadu_pd(test_vec[2].a);
  r = simde_mm512_mask_roundscale_round_pd(src, test_vec[2].k, a, INT32_C(           2), INT32_C(           4));
  simde_test_x86_assert_equal_f64x8(r, simde_mm512_loadu_pd(test_vec[2].r), 1);

  src = simde_mm512_loadu_pd(test_vec[3].src);
  a = simde_mm512_loadu_pd(test_vec[3].a);
  r = simde_mm512_mask_roundscale_round_pd(src, test_vec[3].k, a, INT32_C(         163), INT32_C(           8));
  simde_test_x86_assert_equal_f64x8(r, simde_mm512_loadu_pd(test_vec[3].r), 1);

  src = simde_mm512_loadu_pd(test_vec[4].src);
  a = simde_mm512_loadu_pd(test_vec[4].a);
  r = simde_mm512_mask_roundscale_round_pd(src, test_vec[4].k, a, INT32_C(         132), INT32_C(           8));
  simde_test_x86_assert_equal_f64x8(r, simde_mm512_loadu_pd(test_vec[4].r), 1);

  src = simde_mm512_loadu_pd(test_vec[5].src);
  a = simde_mm512_loadu_pd(test_vec[5].a);
  r = simde_mm512_mask_roundscale_round_pd(src, test_vec[5].k, a, INT32_C(         160), INT32_C(           8));
  simde_test_x86_assert_equal_f64x8(r, simde_mm512_loadu_pd(test_vec[5].r), 1);

  src = simde_mm512_loadu_pd(test_vec[6].src);
  a = simde_mm512_loadu_pd(test_vec[6].a);
  r = simde_mm512_mask_roundscale_round_pd(src, test_vec[6].k, a, INT32_C(          81), INT32_C(           8));
  simde_test_x86_assert_equal_f64x8(r, simde_mm512_loadu_pd(test_vec[6].r), 1);

  src = simde_mm512_loadu_pd(test_vec[7].src);
  a = simde_mm512_loadu_pd(test_vec[7].a);
  r = simde_mm512_mask_roundscale_round_pd(src, test_vec[7].k, a, INT32_C(         210), INT32_C(           4));
  simde_test_x86_assert_equal_f64x8(r, simde_mm512_loadu_pd(test_vec[7].r), 1);

  return 0;
#else
  fputc('\n', stdout);
  int round_type[5] = {SIMDE_MM_FROUND_TO_NEAREST_INT, SIMDE_MM_FROUND_TO_NEG_INF, SIMDE_MM_FROUND_TO_POS_INF, SIMDE_MM_FROUND_TO_ZERO, SIMDE_MM_FROUND_CUR_DIRECTION};
  for (int i = 0 ; i < 8 ; i++) {
    simde__m512d src = simde_test_x86_random_f64x8(SIMDE_FLOAT64_C(-1000.0), SIMDE_FLOAT64_C(1000.0));
    simde__mmask8 k = simde_test_x86_random_mmask8();
    simde__m512d a = simde_test_x86_random_f64x8(SIMDE_FLOAT64_C(-1000.0), SIMDE_FLOAT64_C(1000.0));
    if((simde_test_codegen_rand() & 1)) {
      if((simde_test_codegen_rand() & 1))
        a = simde_mm512_mask_mov_pd(a, 1, simde_mm512_set1_pd(SIMDE_MATH_NAN));
      else {
        if((simde_test_codegen_rand() & 1))
          a = simde_mm512_mask_mov_pd(a, 2, simde_mm512_set1_pd(SIMDE_MATH_INFINITY));
        else
          a = simde_mm512_mask_mov_pd(a, 2, simde_mm512_set1_pd(-SIMDE_MATH_INFINITY));
      }
    }
    int imm8 = (((simde_test_codegen_rand() & 15) << 4) | round_type[i % 5]) & 255;
    int sae = (simde_test_codegen_rand() & 1) ? SIMDE_MM_FROUND_CUR_DIRECTION : SIMDE_MM_FROUND_NO_EXC;
    simde__m512d r;
    SIMDE_CONSTIFY_256_NEW(simde_mm512_mask_roundscale_round_pd, r, simde_mm512_setzero_pd(), imm8, sae, src, k, a);

    simde_test_x86_write_f64x8(2, src, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_mmask8(2, k, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_f64x8(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i32(2, imm8, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i32(2, sae, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_f64x8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm512_maskz_roundscale_round_pd (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const simde__mmask8 k;
    const simde_float64 a[8];
    const int32_t imm8;
    const int32_t sae;
    const simde_float64 r[8];
  } test_vec[] = {
    { UINT8_C(190),
      { SIMDE_FLOAT64_C(   515.32), SIMDE_FLOAT64_C(    92.71), SIMDE_FLOAT64_C(   -98.65), SIMDE_FLOAT64_C(  -709.07),
        SIMDE_FLOAT64_C(   445.35), SIMDE_FLOAT64_C(  -129.46), SIMDE_FLOAT64_C(   180.22), SIMDE_FLOAT64_C(   747.49) },
       INT32_C(         176),
       INT32_C(           8),
      { SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(    92.71), SIMDE_FLOAT64_C(   -98.65), SIMDE_FLOAT64_C(  -709.07),
        SIMDE_FLOAT64_C(   445.35), SIMDE_FLOAT64_C(  -129.46), SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(   747.49) } },
    { UINT8_C(118),
      {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(  -392.58), SIMDE_FLOAT64_C(  -387.10), SIMDE_FLOAT64_C(    99.02),
        SIMDE_FLOAT64_C(   596.83), SIMDE_FLOAT64_C(  -871.46), SIMDE_FLOAT64_C(  -220.73), SIMDE_FLOAT64_C(   401.93) },
       INT32_C(         193),
       INT32_C(           8),
      { SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(  -392.58), SIMDE_FLOAT64_C(  -387.10), SIMDE_FLOAT64_C(     0.00),
        SIMDE_FLOAT64_C(   596.83), SIMDE_FLOAT64_C(  -871.46), SIMDE_FLOAT64_C(  -220.73), SIMDE_FLOAT64_C(     0.00) } },
    { UINT8_C(143),
      { SIMDE_FLOAT64_C(  -975.69), SIMDE_FLOAT64_C(  -293.66), SIMDE_FLOAT64_C(  -314.85), SIMDE_FLOAT64_C(  -720.20),
        SIMDE_FLOAT64_C(   714.21), SIMDE_FLOAT64_C(  -592.83), SIMDE_FLOAT64_C(   795.13), SIMDE_FLOAT64_C(  -193.07) },
       INT32_C(         146),
       INT32_C(           8),
      { SIMDE_FLOAT64_C(  -975.69), SIMDE_FLOAT64_C(  -293.66), SIMDE_FLOAT64_C(  -314.85), SIMDE_FLOAT64_C(  -720.20),
        SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(  -193.07) } },
    { UINT8_C( 78),
      { SIMDE_FLOAT64_C(   266.27), SIMDE_FLOAT64_C(   999.77), SIMDE_FLOAT64_C(  -432.85), SIMDE_FLOAT64_C(  -229.42),
        SIMDE_FLOAT64_C(   135.60), SIMDE_FLOAT64_C(  -650.90), SIMDE_FLOAT64_C(   385.97), SIMDE_FLOAT64_C(   743.01) },
       INT32_C(         243),
       INT32_C(           4),
      { SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(   999.77), SIMDE_FLOAT64_C(  -432.85), SIMDE_FLOAT64_C(  -229.42),
        SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(   385.97), SIMDE_FLOAT64_C(     0.00) } },
    { UINT8_C(153),
      {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(  -258.22), SIMDE_FLOAT64_C(   643.08), SIMDE_FLOAT64_C(  -777.45),
        SIMDE_FLOAT64_C(   864.04), SIMDE_FLOAT64_C(  -328.14), SIMDE_FLOAT64_C(  -310.52), SIMDE_FLOAT64_C(   888.34) },
       INT32_C(         148),
       INT32_C(           8),
      {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(  -777.45),
        SIMDE_FLOAT64_C(   864.04), SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(   888.34) } },
    { UINT8_C(203),
      { SIMDE_FLOAT64_C(   963.27), SIMDE_FLOAT64_C(   899.35), SIMDE_FLOAT64_C(    90.33), SIMDE_FLOAT64_C(  -950.68),
        SIMDE_FLOAT64_C(  -848.37), SIMDE_FLOAT64_C(   269.40), SIMDE_FLOAT64_C(   315.60), SIMDE_FLOAT64_C(  -848.60) },
       INT32_C(           0),
       INT32_C(           4),
      { SIMDE_FLOAT64_C(   963.00), SIMDE_FLOAT64_C(   899.00), SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(  -951.00),
        SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(   316.00), SIMDE_FLOAT64_C(  -849.00) } },
    { UINT8_C(164),
      { SIMDE_FLOAT64_C(   472.15),        SIMDE_MATH_INFINITY, SIMDE_FLOAT64_C(   147.65), SIMDE_FLOAT64_C(   957.14),
        SIMDE_FLOAT64_C(  -630.15), SIMDE_FLOAT64_C(  -761.81), SIMDE_FLOAT64_C(   221.41), SIMDE_FLOAT64_C(   111.62) },
       INT32_C(          17),
       INT32_C(           8),
      { SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(   147.50), SIMDE_FLOAT64_C(     0.00),
        SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(  -762.00), SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(   111.50) } },
    { UINT8_C(143),
      { SIMDE_FLOAT64_C(   931.35),        SIMDE_MATH_INFINITY, SIMDE_FLOAT64_C(    32.15), SIMDE_FLOAT64_C(    23.77),
        SIMDE_FLOAT64_C(   289.88), SIMDE_FLOAT64_C(    -4.58), SIMDE_FLOAT64_C(   -76.88), SIMDE_FLOAT64_C(  -619.79) },
       INT32_C(          18),
       INT32_C(           4),
      { SIMDE_FLOAT64_C(   931.50),        SIMDE_MATH_INFINITY, SIMDE_FLOAT64_C(    32.50), SIMDE_FLOAT64_C(    24.00),
        SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(  -619.50) } },
  };

  simde__m512d a, r;

  a = simde_mm512_loadu_pd(test_vec[0].a);
  r = simde_mm512_maskz_roundscale_round_pd(test_vec[0].k, a, INT32_C(         176), INT32_C(           8));
  simde_test_x86_assert_equal_f64x8(r, simde_mm512_loadu_pd(test_vec[0].r), 1);

  a = simde_mm512_loadu_pd(test_vec[1].a);
  r = simde_mm512_maskz_roundscale_round_pd(test_vec[1].k, a, INT32_C(         193), INT32_C(           8));
  simde_test_x86_assert_equal_f64x8(r, simde_mm512_loadu_pd(test_vec[1].r), 1);

  a = simde_mm512_loadu_pd(test_vec[2].a);
  r = simde_mm512_maskz_roundscale_round_pd(test_vec[2].k, a, INT32_C(         146), INT32_C(           8));
  simde_test_x86_assert_equal_f64x8(r, simde_mm512_loadu_pd(test_vec[2].r), 1);

  a = simde_mm512_loadu_pd(test_vec[3].a);
  r = simde_mm512_maskz_roundscale_round_pd(test_vec[3].k, a, INT32_C(         243), INT32_C(           4));
  simde_test_x86_assert_equal_f64x8(r, simde_mm512_loadu_pd(test_vec[3].r), 1);

  a = simde_mm512_loadu_pd(test_vec[4].a);
  r = simde_mm512_maskz_roundscale_round_pd(test_vec[4].k, a, INT32_C(         148), INT32_C(           8));
  simde_test_x86_assert_equal_f64x8(r, simde_mm512_loadu_pd(test_vec[4].r), 1);

  a = simde_mm512_loadu_pd(test_vec[5].a);
  r = simde_mm512_maskz_roundscale_round_pd(test_vec[5].k, a, INT32_C(           0), INT32_C(           4));
  simde_test_x86_assert_equal_f64x8(r, simde_mm512_loadu_pd(test_vec[5].r), 1);

  a = simde_mm512_loadu_pd(test_vec[6].a);
  r = simde_mm512_maskz_roundscale_round_pd(test_vec[6].k, a, INT32_C(          17), INT32_C(           8));
  simde_test_x86_assert_equal_f64x8(r, simde_mm512_loadu_pd(test_vec[6].r), 1);

  a = simde_mm512_loadu_pd(test_vec[7].a);
  r = simde_mm512_maskz_roundscale_round_pd(test_vec[7].k, a, INT32_C(          18), INT32_C(           4));
  simde_test_x86_assert_equal_f64x8(r, simde_mm512_loadu_pd(test_vec[7].r), 1);

  return 0;
#else
  fputc('\n', stdout);
  int round_type[5] = {SIMDE_MM_FROUND_TO_NEAREST_INT, SIMDE_MM_FROUND_TO_NEG_INF, SIMDE_MM_FROUND_TO_POS_INF, SIMDE_MM_FROUND_TO_ZERO, SIMDE_MM_FROUND_CUR_DIRECTION};
  for (int i = 0 ; i < 8 ; i++) {
    simde__mmask8 k = simde_test_x86_random_mmask8();
    simde__m512d a = simde_test_x86_random_f64x8(SIMDE_FLOAT64_C(-1000.0), SIMDE_FLOAT64_C(1000.0));
    if((simde_test_codegen_rand() & 1)) {
      if((simde_test_codegen_rand() & 1))
        a = simde_mm512_mask_mov_pd(a, 1, simde_mm512_set1_pd(SIMDE_MATH_NAN));
      else {
        if((simde_test_codegen_rand() & 1))
          a = simde_mm512_mask_mov_pd(a, 2, simde_mm512_set1_pd(SIMDE_MATH_INFINITY));
        else
          a = simde_mm512_mask_mov_pd(a, 2, simde_mm512_set1_pd(-SIMDE_MATH_INFINITY));
      }
    }
    int imm8 = (((simde_test_codegen_rand() & 15) << 4) | round_type[i % 5]) & 255;
    int sae = (simde_test_codegen_rand() & 1) ? SIMDE_MM_FROUND_CUR_DIRECTION : SIMDE_MM_FROUND_NO_EXC;
    simde__m512d r;
    SIMDE_CONSTIFY_256_NEW(simde_mm512_maskz_roundscale_round_pd, r, simde_mm512_setzero_pd(), imm8, sae, k, a);

    simde_test_x86_write_mmask8(2, k, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_f64x8(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i32(2, imm8, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i32(2, sae, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_f64x8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm_roundscale_ss (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const simde_float32 a[4];
    const simde_float32 b[4];
    const int32_t imm8;
    const simde_float32 r[4];
  } test_vec[] = {
    { { SIMDE_FLOAT32_C(   822.63), SIMDE_FLOAT32_C(   440.98), SIMDE_FLOAT32_C(    -7.85), SIMDE_FLOAT32_C(   646.73) },
      { SIMDE_FLOAT32_C(   446.35), SIMDE_FLOAT32_C(  -293.17), SIMDE_FLOAT32_C(   587.62), SIMDE_FLOAT32_C(   860.34) },
       INT32_C(           0),
      { SIMDE_FLOAT32_C(   446.00), SIMDE_FLOAT32_C(   440.98), SIMDE_FLOAT32_C(    -7.85), SIMDE_FLOAT32_C(   646.73) } },
    { { SIMDE_FLOAT32_C(    14.68), SIMDE_FLOAT32_C(   115.83), SIMDE_FLOAT32_C(   -68.33), SIMDE_FLOAT32_C(   366.87) },
      { SIMDE_FLOAT32_C(  -324.24), SIMDE_FLOAT32_C(  -488.69), SIMDE_FLOAT32_C(   -87.18), SIMDE_FLOAT32_C(  -980.26) },
       INT32_C(          16),
      { SIMDE_FLOAT32_C(  -324.00), SIMDE_FLOAT32_C(   115.83), SIMDE_FLOAT32_C(   -68.33), SIMDE_FLOAT32_C(   366.87) } },
    { { SIMDE_FLOAT32_C(   673.86), SIMDE_FLOAT32_C(   884.60), SIMDE_FLOAT32_C(   702.77), SIMDE_FLOAT32_C(  -321.62) },
      { SIMDE_FLOAT32_C(  -887.81), SIMDE_FLOAT32_C(   897.13), SIMDE_FLOAT32_C(   967.53), SIMDE_FLOAT32_C(  -824.56) },
       INT32_C(          32),
      { SIMDE_FLOAT32_C(  -887.75), SIMDE_FLOAT32_C(   884.60), SIMDE_FLOAT32_C(   702.77), SIMDE_FLOAT32_C(  -321.62) } },
    { { SIMDE_FLOAT32_C(  -444.99), SIMDE_FLOAT32_C(   531.19), SIMDE_FLOAT32_C(  -158.59), SIMDE_FLOAT32_C(   -20.00) },
      {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(  -717.61), SIMDE_FLOAT32_C(   972.15), SIMDE_FLOAT32_C(     0.55) },
       INT32_C(          48),
      {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(   531.19), SIMDE_FLOAT32_C(  -158.59), SIMDE_FLOAT32_C(   -20.00) } },
    { { SIMDE_FLOAT32_C(  -411.83), SIMDE_FLOAT32_C(   589.09), SIMDE_FLOAT32_C(   577.76), SIMDE_FLOAT32_C(   602.85) },
      { SIMDE_FLOAT32_C(  -295.09), SIMDE_FLOAT32_C(  -490.58), SIMDE_FLOAT32_C(   -30.29), SIMDE_FLOAT32_C(   380.68) },
       INT32_C(          64),
      { SIMDE_FLOAT32_C(  -295.06), SIMDE_FLOAT32_C(   589.09), SIMDE_FLOAT32_C(   577.76), SIMDE_FLOAT32_C(   602.85) } },
    { { SIMDE_FLOAT32_C(   882.54), SIMDE_FLOAT32_C(   400.42), SIMDE_FLOAT32_C(  -726.72), SIMDE_FLOAT32_C(   556.40) },
      {      SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(   976.05), SIMDE_FLOAT32_C(  -765.22), SIMDE_FLOAT32_C(   397.20) },
       INT32_C(          80),
      {      SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(   400.42), SIMDE_FLOAT32_C(  -726.72), SIMDE_FLOAT32_C(   556.40) } },
    { { SIMDE_FLOAT32_C(  -105.81), SIMDE_FLOAT32_C(  -242.69), SIMDE_FLOAT32_C(   103.84), SIMDE_FLOAT32_C(   735.60) },
      {     -SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(  -542.34), SIMDE_FLOAT32_C(  -982.01), SIMDE_FLOAT32_C(   709.46) },
       INT32_C(          96),
      {     -SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(  -242.69), SIMDE_FLOAT32_C(   103.84), SIMDE_FLOAT32_C(   735.60) } },
    { { SIMDE_FLOAT32_C(  -953.62), SIMDE_FLOAT32_C(   335.83), SIMDE_FLOAT32_C(   966.20), SIMDE_FLOAT32_C(   649.22) },
      { SIMDE_FLOAT32_C(  -959.26), SIMDE_FLOAT32_C(  -524.38), SIMDE_FLOAT32_C(  -381.06), SIMDE_FLOAT32_C(   421.42) },
       INT32_C(         112),
      { SIMDE_FLOAT32_C(  -959.26), SIMDE_FLOAT32_C(   335.83), SIMDE_FLOAT32_C(   966.20), SIMDE_FLOAT32_C(   649.22) } },
    { { SIMDE_FLOAT32_C(  -498.52), SIMDE_FLOAT32_C(  -178.17), SIMDE_FLOAT32_C(   769.63), SIMDE_FLOAT32_C(  -942.12) },
      {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(   745.68), SIMDE_FLOAT32_C(  -707.34), SIMDE_FLOAT32_C(   504.05) },
       INT32_C(         128),
      {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(  -178.17), SIMDE_FLOAT32_C(   769.63), SIMDE_FLOAT32_C(  -942.12) } },
    { { SIMDE_FLOAT32_C(    76.70), SIMDE_FLOAT32_C(  -486.95), SIMDE_FLOAT32_C(   252.28), SIMDE_FLOAT32_C(  -819.47) },
      { SIMDE_FLOAT32_C(  -751.35), SIMDE_FLOAT32_C(   -10.40), SIMDE_FLOAT32_C(  -361.81), SIMDE_FLOAT32_C(  -733.36) },
       INT32_C(         144),
      { SIMDE_FLOAT32_C(  -751.35), SIMDE_FLOAT32_C(  -486.95), SIMDE_FLOAT32_C(   252.28), SIMDE_FLOAT32_C(  -819.47) } },
    { { SIMDE_FLOAT32_C(  -903.60), SIMDE_FLOAT32_C(  -986.62), SIMDE_FLOAT32_C(    87.50), SIMDE_FLOAT32_C(  -857.23) },
      { SIMDE_FLOAT32_C(   349.21), SIMDE_FLOAT32_C(    53.70), SIMDE_FLOAT32_C(   792.00), SIMDE_FLOAT32_C(   389.95) },
       INT32_C(         160),
      { SIMDE_FLOAT32_C(   349.21), SIMDE_FLOAT32_C(  -986.62), SIMDE_FLOAT32_C(    87.50), SIMDE_FLOAT32_C(  -857.23) } },
    { { SIMDE_FLOAT32_C(  -589.06), SIMDE_FLOAT32_C(  -188.63), SIMDE_FLOAT32_C(    25.67), SIMDE_FLOAT32_C(   -87.58) },
      { SIMDE_FLOAT32_C(   633.20), SIMDE_FLOAT32_C(  -204.71), SIMDE_FLOAT32_C(   -29.71), SIMDE_FLOAT32_C(   740.05) },
       INT32_C(         176),
      { SIMDE_FLOAT32_C(   633.20), SIMDE_FLOAT32_C(  -188.63), SIMDE_FLOAT32_C(    25.67), SIMDE_FLOAT32_C(   -87.58) } },
    { { SIMDE_FLOAT32_C(   262.95), SIMDE_FLOAT32_C(   244.10), SIMDE_FLOAT32_C(  -840.17), SIMDE_FLOAT32_C(   757.92) },
      {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(  -327.12), SIMDE_FLOAT32_C(    10.20), SIMDE_FLOAT32_C(  -498.67) },
       INT32_C(         192),
      {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(   244.10), SIMDE_FLOAT32_C(  -840.17), SIMDE_FLOAT32_C(   757.92) } },
    { { SIMDE_FLOAT32_C(   139.52), SIMDE_FLOAT32_C(   188.17), SIMDE_FLOAT32_C(  -301.15), SIMDE_FLOAT32_C(   235.91) },
      { SIMDE_FLOAT32_C(   201.55), SIMDE_FLOAT32_C(   786.35), SIMDE_FLOAT32_C(   378.69), SIMDE_FLOAT32_C(  -449.24) },
       INT32_C(         208),
      { SIMDE_FLOAT32_C(   201.55), SIMDE_FLOAT32_C(   188.17), SIMDE_FLOAT32_C(  -301.15), SIMDE_FLOAT32_C(   235.91) } },
    { { SIMDE_FLOAT32_C(   170.69), SIMDE_FLOAT32_C(   940.71), SIMDE_FLOAT32_C(  -630.64), SIMDE_FLOAT32_C(   581.62) },
      { SIMDE_FLOAT32_C(  -247.93), SIMDE_FLOAT32_C(   395.03), SIMDE_FLOAT32_C(  -505.96), SIMDE_FLOAT32_C(  -614.73) },
       INT32_C(         224),
      { SIMDE_FLOAT32_C(  -247.93), SIMDE_FLOAT32_C(   940.71), SIMDE_FLOAT32_C(  -630.64), SIMDE_FLOAT32_C(   581.62) } },
    { { SIMDE_FLOAT32_C(   464.33), SIMDE_FLOAT32_C(  -874.68), SIMDE_FLOAT32_C(  -268.70), SIMDE_FLOAT32_C(  -272.72) },
      { SIMDE_FLOAT32_C(   369.41), SIMDE_FLOAT32_C(  -108.87), SIMDE_FLOAT32_C(  -514.80), SIMDE_FLOAT32_C(   690.21) },
       INT32_C(         240),
      { SIMDE_FLOAT32_C(   369.41), SIMDE_FLOAT32_C(  -874.68), SIMDE_FLOAT32_C(  -268.70), SIMDE_FLOAT32_C(  -272.72) } },
    { { SIMDE_FLOAT32_C(   495.39), SIMDE_FLOAT32_C(  -808.46), SIMDE_FLOAT32_C(  -514.46), SIMDE_FLOAT32_C(   495.19) },
      {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(   673.71), SIMDE_FLOAT32_C(  -805.96), SIMDE_FLOAT32_C(  -433.04) },
       INT32_C(           1),
      {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(  -808.46), SIMDE_FLOAT32_C(  -514.46), SIMDE_FLOAT32_C(   495.19) } },
    { { SIMDE_FLOAT32_C(   945.65), SIMDE_FLOAT32_C(   426.02), SIMDE_FLOAT32_C(  -179.56), SIMDE_FLOAT32_C(   116.34) },
      {      SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(   189.80), SIMDE_FLOAT32_C(  -302.04), SIMDE_FLOAT32_C(  -881.20) },
       INT32_C(          17),
      {      SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(   426.02), SIMDE_FLOAT32_C(  -179.56), SIMDE_FLOAT32_C(   116.34) } },
    { { SIMDE_FLOAT32_C(  -224.85), SIMDE_FLOAT32_C(  -343.67), SIMDE_FLOAT32_C(  -370.62), SIMDE_FLOAT32_C(   506.44) },
      { SIMDE_FLOAT32_C(   383.61), SIMDE_FLOAT32_C(   998.80), SIMDE_FLOAT32_C(  -602.43), SIMDE_FLOAT32_C(   868.80) },
       INT32_C(          33),
      { SIMDE_FLOAT32_C(   383.50), SIMDE_FLOAT32_C(  -343.67), SIMDE_FLOAT32_C(  -370.62), SIMDE_FLOAT32_C(   506.44) } },
    { { SIMDE_FLOAT32_C(   961.58), SIMDE_FLOAT32_C(   364.20), SIMDE_FLOAT32_C(   880.54), SIMDE_FLOAT32_C(  -552.88) },
      {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(   211.59), SIMDE_FLOAT32_C(  -879.17), SIMDE_FLOAT32_C(    53.42) },
       INT32_C(          49),
      {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(   364.20), SIMDE_FLOAT32_C(   880.54), SIMDE_FLOAT32_C(  -552.88) } },
    { { SIMDE_FLOAT32_C(    33.81), SIMDE_FLOAT32_C(   724.21), SIMDE_FLOAT32_C(  -577.89), SIMDE_FLOAT32_C(   854.25) },
      {      SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(   788.83), SIMDE_FLOAT32_C(    44.04), SIMDE_FLOAT32_C(   538.50) },
       INT32_C(          65),
      {      SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(   724.21), SIMDE_FLOAT32_C(  -577.89), SIMDE_FLOAT32_C(   854.25) } },
    { { SIMDE_FLOAT32_C(  -588.30), SIMDE_FLOAT32_C(  -595.98), SIMDE_FLOAT32_C(   386.83), SIMDE_FLOAT32_C(    41.08) },
      { SIMDE_FLOAT32_C(   910.46), SIMDE_FLOAT32_C(  -229.56), SIMDE_FLOAT32_C(    39.88), SIMDE_FLOAT32_C(  -691.97) },
       INT32_C(          81),
      { SIMDE_FLOAT32_C(   910.44), SIMDE_FLOAT32_C(  -595.98), SIMDE_FLOAT32_C(   386.83), SIMDE_FLOAT32_C(    41.08) } },
    { { SIMDE_FLOAT32_C(  -271.12), SIMDE_FLOAT32_C(  -730.39), SIMDE_FLOAT32_C(  -996.56), SIMDE_FLOAT32_C(  -390.58) },
      {     -SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(  -137.18), SIMDE_FLOAT32_C(   821.01), SIMDE_FLOAT32_C(  -162.44) },
       INT32_C(          97),
      {     -SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(  -730.39), SIMDE_FLOAT32_C(  -996.56), SIMDE_FLOAT32_C(  -390.58) } },
    { { SIMDE_FLOAT32_C(   -49.95), SIMDE_FLOAT32_C(   323.78), SIMDE_FLOAT32_C(  -744.24), SIMDE_FLOAT32_C(  -195.70) },
      { SIMDE_FLOAT32_C(  -835.68), SIMDE_FLOAT32_C(  -955.41), SIMDE_FLOAT32_C(   848.34), SIMDE_FLOAT32_C(   702.82) },
       INT32_C(         113),
      { SIMDE_FLOAT32_C(  -835.69), SIMDE_FLOAT32_C(   323.78), SIMDE_FLOAT32_C(  -744.24), SIMDE_FLOAT32_C(  -195.70) } },
    { { SIMDE_FLOAT32_C(   477.21), SIMDE_FLOAT32_C(  -566.68), SIMDE_FLOAT32_C(  -636.08), SIMDE_FLOAT32_C(   881.23) },
      { SIMDE_FLOAT32_C(   820.15), SIMDE_FLOAT32_C(   405.00), SIMDE_FLOAT32_C(   791.69), SIMDE_FLOAT32_C(  -409.41) },
       INT32_C(         129),
      { SIMDE_FLOAT32_C(   820.15), SIMDE_FLOAT32_C(  -566.68), SIMDE_FLOAT32_C(  -636.08), SIMDE_FLOAT32_C(   881.23) } },
    { { SIMDE_FLOAT32_C(  -900.28), SIMDE_FLOAT32_C(   229.83), SIMDE_FLOAT32_C(   173.76), SIMDE_FLOAT32_C(  -630.67) },
      {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(   783.18), SIMDE_FLOAT32_C(    86.06), SIMDE_FLOAT32_C(  -903.91) },
       INT32_C(         145),
      {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(   229.83), SIMDE_FLOAT32_C(   173.76), SIMDE_FLOAT32_C(  -630.67) } },
    { { SIMDE_FLOAT32_C(  -987.67), SIMDE_FLOAT32_C(   203.76), SIMDE_FLOAT32_C(   757.27), SIMDE_FLOAT32_C(   -37.61) },
      {      SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(  -986.97), SIMDE_FLOAT32_C(   766.68), SIMDE_FLOAT32_C(  -308.15) },
       INT32_C(         161),
      {      SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(   203.76), SIMDE_FLOAT32_C(   757.27), SIMDE_FLOAT32_C(   -37.61) } },
    { { SIMDE_FLOAT32_C(  -990.16), SIMDE_FLOAT32_C(    92.24), SIMDE_FLOAT32_C(  -172.00), SIMDE_FLOAT32_C(  -626.25) },
      {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(  -351.85), SIMDE_FLOAT32_C(   778.75), SIMDE_FLOAT32_C(  -234.84) },
       INT32_C(         177),
      {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(    92.24), SIMDE_FLOAT32_C(  -172.00), SIMDE_FLOAT32_C(  -626.25) } },
    { { SIMDE_FLOAT32_C(  -135.13), SIMDE_FLOAT32_C(  -531.43), SIMDE_FLOAT32_C(   397.38), SIMDE_FLOAT32_C(   234.20) },
      {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(   180.56), SIMDE_FLOAT32_C(  -679.74), SIMDE_FLOAT32_C(   797.93) },
       INT32_C(         193),
      {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(  -531.43), SIMDE_FLOAT32_C(   397.38), SIMDE_FLOAT32_C(   234.20) } },
    { { SIMDE_FLOAT32_C(   810.27), SIMDE_FLOAT32_C(   988.51), SIMDE_FLOAT32_C(  -998.85), SIMDE_FLOAT32_C(  -227.35) },
      {     -SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(  -985.82), SIMDE_FLOAT32_C(  -460.66), SIMDE_FLOAT32_C(   207.90) },
       INT32_C(         209),
      {     -SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(   988.51), SIMDE_FLOAT32_C(  -998.85), SIMDE_FLOAT32_C(  -227.35) } },
    { { SIMDE_FLOAT32_C(  -918.36), SIMDE_FLOAT32_C(   246.61), SIMDE_FLOAT32_C(  -569.43), SIMDE_FLOAT32_C(  -544.61) },
      { SIMDE_FLOAT32_C(  -779.92), SIMDE_FLOAT32_C(    78.72), SIMDE_FLOAT32_C(  -765.86), SIMDE_FLOAT32_C(   -14.77) },
       INT32_C(         225),
      { SIMDE_FLOAT32_C(  -779.92), SIMDE_FLOAT32_C(   246.61), SIMDE_FLOAT32_C(  -569.43), SIMDE_FLOAT32_C(  -544.61) } },
    { { SIMDE_FLOAT32_C(  -542.23), SIMDE_FLOAT32_C(   850.11), SIMDE_FLOAT32_C(  -213.97), SIMDE_FLOAT32_C(   855.15) },
      { SIMDE_FLOAT32_C(    84.31), SIMDE_FLOAT32_C(  -512.14), SIMDE_FLOAT32_C(    35.71), SIMDE_FLOAT32_C(   404.57) },
       INT32_C(         241),
      { SIMDE_FLOAT32_C(    84.31), SIMDE_FLOAT32_C(   850.11), SIMDE_FLOAT32_C(  -213.97), SIMDE_FLOAT32_C(   855.15) } },
    { { SIMDE_FLOAT32_C(   820.46), SIMDE_FLOAT32_C(   648.45), SIMDE_FLOAT32_C(  -903.94), SIMDE_FLOAT32_C(   808.97) },
      { SIMDE_FLOAT32_C(   649.61), SIMDE_FLOAT32_C(  -131.28), SIMDE_FLOAT32_C(  -674.98), SIMDE_FLOAT32_C(   663.79) },
       INT32_C(           2),
      { SIMDE_FLOAT32_C(   650.00), SIMDE_FLOAT32_C(   648.45), SIMDE_FLOAT32_C(  -903.94), SIMDE_FLOAT32_C(   808.97) } },
    { { SIMDE_FLOAT32_C(   532.92), SIMDE_FLOAT32_C(   735.59), SIMDE_FLOAT32_C(   562.42), SIMDE_FLOAT32_C(   135.50) },
      {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(  -190.97), SIMDE_FLOAT32_C(   566.07), SIMDE_FLOAT32_C(  -727.38) },
       INT32_C(          18),
      {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(   735.59), SIMDE_FLOAT32_C(   562.42), SIMDE_FLOAT32_C(   135.50) } },
    { { SIMDE_FLOAT32_C(  -493.23), SIMDE_FLOAT32_C(  -985.67), SIMDE_FLOAT32_C(   -37.75), SIMDE_FLOAT32_C(   -35.47) },
      {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(   748.28), SIMDE_FLOAT32_C(  -180.32), SIMDE_FLOAT32_C(   -51.25) },
       INT32_C(          34),
      {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(  -985.67), SIMDE_FLOAT32_C(   -37.75), SIMDE_FLOAT32_C(   -35.47) } },
    { { SIMDE_FLOAT32_C(  -646.68), SIMDE_FLOAT32_C(  -478.07), SIMDE_FLOAT32_C(   675.84), SIMDE_FLOAT32_C(  -998.23) },
      { SIMDE_FLOAT32_C(  -382.00), SIMDE_FLOAT32_C(   484.81), SIMDE_FLOAT32_C(   651.37), SIMDE_FLOAT32_C(   486.71) },
       INT32_C(          50),
      { SIMDE_FLOAT32_C(  -382.00), SIMDE_FLOAT32_C(  -478.07), SIMDE_FLOAT32_C(   675.84), SIMDE_FLOAT32_C(  -998.23) } },
    { { SIMDE_FLOAT32_C(   315.16), SIMDE_FLOAT32_C(  -105.23), SIMDE_FLOAT32_C(   342.75), SIMDE_FLOAT32_C(    50.75) },
      { SIMDE_FLOAT32_C(  -542.82), SIMDE_FLOAT32_C(  -521.75), SIMDE_FLOAT32_C(  -132.02), SIMDE_FLOAT32_C(   266.21) },
       INT32_C(          66),
      { SIMDE_FLOAT32_C(  -542.81), SIMDE_FLOAT32_C(  -105.23), SIMDE_FLOAT32_C(   342.75), SIMDE_FLOAT32_C(    50.75) } },
    { { SIMDE_FLOAT32_C(   140.61), SIMDE_FLOAT32_C(  -704.69), SIMDE_FLOAT32_C(  -310.89), SIMDE_FLOAT32_C(   647.37) },
      {      SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(   651.36), SIMDE_FLOAT32_C(  -388.09), SIMDE_FLOAT32_C(  -825.91) },
       INT32_C(          82),
      {      SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(  -704.69), SIMDE_FLOAT32_C(  -310.89), SIMDE_FLOAT32_C(   647.37) } },
    { { SIMDE_FLOAT32_C(   635.78), SIMDE_FLOAT32_C(   286.97), SIMDE_FLOAT32_C(   476.15), SIMDE_FLOAT32_C(  -842.29) },
      { SIMDE_FLOAT32_C(   -37.18), SIMDE_FLOAT32_C(   477.92), SIMDE_FLOAT32_C(  -224.29), SIMDE_FLOAT32_C(  -552.37) },
       INT32_C(          98),
      { SIMDE_FLOAT32_C(   -37.17), SIMDE_FLOAT32_C(   286.97), SIMDE_FLOAT32_C(   476.15), SIMDE_FLOAT32_C(  -842.29) } },
    { { SIMDE_FLOAT32_C(  -737.58), SIMDE_FLOAT32_C(  -742.54), SIMDE_FLOAT32_C(  -555.54), SIMDE_FLOAT32_C(   157.18) },
      { SIMDE_FLOAT32_C(   600.21), SIMDE_FLOAT32_C(   495.21), SIMDE_FLOAT32_C(   614.37), SIMDE_FLOAT32_C(  -921.55) },
       INT32_C(         114),
      { SIMDE_FLOAT32_C(   600.21), SIMDE_FLOAT32_C(  -742.54), SIMDE_FLOAT32_C(  -555.54), SIMDE_FLOAT32_C(   157.18) } },
    { { SIMDE_FLOAT32_C(  -119.42), SIMDE_FLOAT32_C(  -877.23), SIMDE_FLOAT32_C(   503.80), SIMDE_FLOAT32_C(   175.89) },
      {     -SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(   151.17), SIMDE_FLOAT32_C(   485.54), SIMDE_FLOAT32_C(  -536.76) },
       INT32_C(         130),
      {     -SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(  -877.23), SIMDE_FLOAT32_C(   503.80), SIMDE_FLOAT32_C(   175.89) } },
    { { SIMDE_FLOAT32_C(   194.66), SIMDE_FLOAT32_C(  -217.55), SIMDE_FLOAT32_C(   498.65), SIMDE_FLOAT32_C(  -518.36) },
      { SIMDE_FLOAT32_C(  -741.39), SIMDE_FLOAT32_C(   656.36), SIMDE_FLOAT32_C(   444.45), SIMDE_FLOAT32_C(   736.52) },
       INT32_C(         146),
      { SIMDE_FLOAT32_C(  -741.39), SIMDE_FLOAT32_C(  -217.55), SIMDE_FLOAT32_C(   498.65), SIMDE_FLOAT32_C(  -518.36) } },
    { { SIMDE_FLOAT32_C(   892.08), SIMDE_FLOAT32_C(  -134.18), SIMDE_FLOAT32_C(  -305.51), SIMDE_FLOAT32_C(  -850.46) },
      {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(   851.67), SIMDE_FLOAT32_C(   749.75), SIMDE_FLOAT32_C(  -194.51) },
       INT32_C(         162),
      {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(  -134.18), SIMDE_FLOAT32_C(  -305.51), SIMDE_FLOAT32_C(  -850.46) } },
    { { SIMDE_FLOAT32_C(   168.68), SIMDE_FLOAT32_C(  -653.38), SIMDE_FLOAT32_C(   950.97), SIMDE_FLOAT32_C(  -327.52) },
      {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(  -237.14), SIMDE_FLOAT32_C(   823.66), SIMDE_FLOAT32_C(     8.05) },
       INT32_C(         178),
      {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(  -653.38), SIMDE_FLOAT32_C(   950.97), SIMDE_FLOAT32_C(  -327.52) } },
    { { SIMDE_FLOAT32_C(  -332.33), SIMDE_FLOAT32_C(    88.98), SIMDE_FLOAT32_C(  -218.60), SIMDE_FLOAT32_C(   450.13) },
      {     -SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(   263.04), SIMDE_FLOAT32_C(   708.73), SIMDE_FLOAT32_C(  -756.01) },
       INT32_C(         194),
      {     -SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(    88.98), SIMDE_FLOAT32_C(  -218.60), SIMDE_FLOAT32_C(   450.13) } },
    { { SIMDE_FLOAT32_C(  -400.43), SIMDE_FLOAT32_C(  -688.92), SIMDE_FLOAT32_C(   370.55), SIMDE_FLOAT32_C(  -250.89) },
      {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(   222.23), SIMDE_FLOAT32_C(  -501.14), SIMDE_FLOAT32_C(  -573.16) },
       INT32_C(         210),
      {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(  -688.92), SIMDE_FLOAT32_C(   370.55), SIMDE_FLOAT32_C(  -250.89) } },
    { { SIMDE_FLOAT32_C(   595.53), SIMDE_FLOAT32_C(    34.89), SIMDE_FLOAT32_C(  -721.97), SIMDE_FLOAT32_C(  -731.99) },
      { SIMDE_FLOAT32_C(  -442.59), SIMDE_FLOAT32_C(    40.89), SIMDE_FLOAT32_C(  -908.33), SIMDE_FLOAT32_C(   565.46) },
       INT32_C(         226),
      { SIMDE_FLOAT32_C(  -442.59), SIMDE_FLOAT32_C(    34.89), SIMDE_FLOAT32_C(  -721.97), SIMDE_FLOAT32_C(  -731.99) } },
    { { SIMDE_FLOAT32_C(   678.40), SIMDE_FLOAT32_C(  -766.87), SIMDE_FLOAT32_C(   355.96), SIMDE_FLOAT32_C(  -540.20) },
      { SIMDE_FLOAT32_C(   683.26), SIMDE_FLOAT32_C(   943.59), SIMDE_FLOAT32_C(   722.84), SIMDE_FLOAT32_C(   391.99) },
       INT32_C(         242),
      { SIMDE_FLOAT32_C(   683.26), SIMDE_FLOAT32_C(  -766.87), SIMDE_FLOAT32_C(   355.96), SIMDE_FLOAT32_C(  -540.20) } },
    { { SIMDE_FLOAT32_C(  -569.67), SIMDE_FLOAT32_C(  -162.75), SIMDE_FLOAT32_C(  -136.35), SIMDE_FLOAT32_C(    29.90) },
      { SIMDE_FLOAT32_C(   148.32), SIMDE_FLOAT32_C(  -765.79), SIMDE_FLOAT32_C(   779.01), SIMDE_FLOAT32_C(  -230.32) },
       INT32_C(           3),
      { SIMDE_FLOAT32_C(   148.00), SIMDE_FLOAT32_C(  -162.75), SIMDE_FLOAT32_C(  -136.35), SIMDE_FLOAT32_C(    29.90) } },
    { { SIMDE_FLOAT32_C(  -722.13), SIMDE_FLOAT32_C(   196.52), SIMDE_FLOAT32_C(  -855.30), SIMDE_FLOAT32_C(  -395.08) },
      {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(   179.60), SIMDE_FLOAT32_C(  -117.04), SIMDE_FLOAT32_C(    60.06) },
       INT32_C(          19),
      {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(   196.52), SIMDE_FLOAT32_C(  -855.30), SIMDE_FLOAT32_C(  -395.08) } },
    { { SIMDE_FLOAT32_C(   151.73), SIMDE_FLOAT32_C(   302.46), SIMDE_FLOAT32_C(  -809.17), SIMDE_FLOAT32_C(  -169.87) },
      {      SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(   546.80), SIMDE_FLOAT32_C(   289.94), SIMDE_FLOAT32_C(   218.85) },
       INT32_C(          35),
      {      SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(   302.46), SIMDE_FLOAT32_C(  -809.17), SIMDE_FLOAT32_C(  -169.87) } },
    { { SIMDE_FLOAT32_C(   677.98), SIMDE_FLOAT32_C(   443.10), SIMDE_FLOAT32_C(   448.09), SIMDE_FLOAT32_C(  -458.37) },
      { SIMDE_FLOAT32_C(  -527.00), SIMDE_FLOAT32_C(  -403.59), SIMDE_FLOAT32_C(  -224.16), SIMDE_FLOAT32_C(  -748.00) },
       INT32_C(          51),
      { SIMDE_FLOAT32_C(  -527.00), SIMDE_FLOAT32_C(   443.10), SIMDE_FLOAT32_C(   448.09), SIMDE_FLOAT32_C(  -458.37) } },
    { { SIMDE_FLOAT32_C(  -767.73), SIMDE_FLOAT32_C(  -470.13), SIMDE_FLOAT32_C(  -437.39), SIMDE_FLOAT32_C(  -623.03) },
      { SIMDE_FLOAT32_C(   134.79), SIMDE_FLOAT32_C(   354.66), SIMDE_FLOAT32_C(   556.57), SIMDE_FLOAT32_C(  -982.25) },
       INT32_C(          67),
      { SIMDE_FLOAT32_C(   134.75), SIMDE_FLOAT32_C(  -470.13), SIMDE_FLOAT32_C(  -437.39), SIMDE_FLOAT32_C(  -623.03) } },
    { { SIMDE_FLOAT32_C(   293.57), SIMDE_FLOAT32_C(   941.60), SIMDE_FLOAT32_C(   566.45), SIMDE_FLOAT32_C(  -403.97) },
      {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(  -603.41), SIMDE_FLOAT32_C(  -868.37), SIMDE_FLOAT32_C(   679.23) },
       INT32_C(          83),
      {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(   941.60), SIMDE_FLOAT32_C(   566.45), SIMDE_FLOAT32_C(  -403.97) } },
    { { SIMDE_FLOAT32_C(   169.62), SIMDE_FLOAT32_C(  -300.70), SIMDE_FLOAT32_C(   961.31), SIMDE_FLOAT32_C(  -152.40) },
      { SIMDE_FLOAT32_C(  -857.60), SIMDE_FLOAT32_C(   409.40), SIMDE_FLOAT32_C(   389.23), SIMDE_FLOAT32_C(  -384.61) },
       INT32_C(          99),
      { SIMDE_FLOAT32_C(  -857.59), SIMDE_FLOAT32_C(  -300.70), SIMDE_FLOAT32_C(   961.31), SIMDE_FLOAT32_C(  -152.40) } },
    { { SIMDE_FLOAT32_C(  -834.93), SIMDE_FLOAT32_C(  -132.61), SIMDE_FLOAT32_C(   371.90), SIMDE_FLOAT32_C(  -602.66) },
      {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(   934.51), SIMDE_FLOAT32_C(  -225.69), SIMDE_FLOAT32_C(  -467.95) },
       INT32_C(         115),
      {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(  -132.61), SIMDE_FLOAT32_C(   371.90), SIMDE_FLOAT32_C(  -602.66) } },
    { { SIMDE_FLOAT32_C(  -450.20), SIMDE_FLOAT32_C(   703.89), SIMDE_FLOAT32_C(   624.45), SIMDE_FLOAT32_C(  -508.60) },
      {     -SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(  -779.51), SIMDE_FLOAT32_C(  -376.17), SIMDE_FLOAT32_C(   666.94) },
       INT32_C(         131),
      {     -SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(   703.89), SIMDE_FLOAT32_C(   624.45), SIMDE_FLOAT32_C(  -508.60) } },
    { { SIMDE_FLOAT32_C(   702.59), SIMDE_FLOAT32_C(   472.68), SIMDE_FLOAT32_C(  -947.24), SIMDE_FLOAT32_C(   663.90) },
      {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(  -804.85), SIMDE_FLOAT32_C(    73.30), SIMDE_FLOAT32_C(   709.52) },
       INT32_C(         147),
      {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(   472.68), SIMDE_FLOAT32_C(  -947.24), SIMDE_FLOAT32_C(   663.90) } },
    { { SIMDE_FLOAT32_C(   874.59), SIMDE_FLOAT32_C(   677.94), SIMDE_FLOAT32_C(  -548.99), SIMDE_FLOAT32_C(  -728.07) },
      {      SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(  -614.48), SIMDE_FLOAT32_C(    46.24), SIMDE_FLOAT32_C(   607.25) },
       INT32_C(         163),
      {      SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(   677.94), SIMDE_FLOAT32_C(  -548.99), SIMDE_FLOAT32_C(  -728.07) } },
    { { SIMDE_FLOAT32_C(   378.59), SIMDE_FLOAT32_C(     1.58), SIMDE_FLOAT32_C(  -351.54), SIMDE_FLOAT32_C(  -351.06) },
      { SIMDE_FLOAT32_C(   222.07), SIMDE_FLOAT32_C(   272.29), SIMDE_FLOAT32_C(  -684.12), SIMDE_FLOAT32_C(   574.18) },
       INT32_C(         179),
      { SIMDE_FLOAT32_C(   222.07), SIMDE_FLOAT32_C(     1.58), SIMDE_FLOAT32_C(  -351.54), SIMDE_FLOAT32_C(  -351.06) } },
    { { SIMDE_FLOAT32_C(   669.34), SIMDE_FLOAT32_C(   276.77), SIMDE_FLOAT32_C(    48.04), SIMDE_FLOAT32_C(   722.09) },
      { SIMDE_FLOAT32_C(   -59.33), SIMDE_FLOAT32_C(   368.32), SIMDE_FLOAT32_C(   917.25), SIMDE_FLOAT32_C(  -986.02) },
       INT32_C(         195),
      { SIMDE_FLOAT32_C(   -59.33), SIMDE_FLOAT32_C(   276.77), SIMDE_FLOAT32_C(    48.04), SIMDE_FLOAT32_C(   722.09) } },
    { { SIMDE_FLOAT32_C(  -272.21), SIMDE_FLOAT32_C(    93.09), SIMDE_FLOAT32_C(   -47.57), SIMDE_FLOAT32_C(  -594.27) },
      { SIMDE_FLOAT32_C(   544.11), SIMDE_FLOAT32_C(   224.35), SIMDE_FLOAT32_C(   480.93), SIMDE_FLOAT32_C(   929.63) },
       INT32_C(         211),
      { SIMDE_FLOAT32_C(   544.11), SIMDE_FLOAT32_C(    93.09), SIMDE_FLOAT32_C(   -47.57), SIMDE_FLOAT32_C(  -594.27) } },
    { { SIMDE_FLOAT32_C(    88.18), SIMDE_FLOAT32_C(   604.33), SIMDE_FLOAT32_C(   647.72), SIMDE_FLOAT32_C(   245.24) },
      {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(  -350.71), SIMDE_FLOAT32_C(   893.70), SIMDE_FLOAT32_C(   631.86) },
       INT32_C(         227),
      {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(   604.33), SIMDE_FLOAT32_C(   647.72), SIMDE_FLOAT32_C(   245.24) } },
    { { SIMDE_FLOAT32_C(   947.73), SIMDE_FLOAT32_C(   445.54), SIMDE_FLOAT32_C(  -258.65), SIMDE_FLOAT32_C(   617.07) },
      { SIMDE_FLOAT32_C(  -277.69), SIMDE_FLOAT32_C(   789.38), SIMDE_FLOAT32_C(   339.16), SIMDE_FLOAT32_C(   662.98) },
       INT32_C(         243),
      { SIMDE_FLOAT32_C(  -277.69), SIMDE_FLOAT32_C(   445.54), SIMDE_FLOAT32_C(  -258.65), SIMDE_FLOAT32_C(   617.07) } },
    { { SIMDE_FLOAT32_C(   256.41), SIMDE_FLOAT32_C(   676.96), SIMDE_FLOAT32_C(  -764.46), SIMDE_FLOAT32_C(   984.20) },
      { SIMDE_FLOAT32_C(  -229.94), SIMDE_FLOAT32_C(   187.97), SIMDE_FLOAT32_C(  -610.07), SIMDE_FLOAT32_C(  -685.83) },
       INT32_C(           4),
      { SIMDE_FLOAT32_C(  -230.00), SIMDE_FLOAT32_C(   676.96), SIMDE_FLOAT32_C(  -764.46), SIMDE_FLOAT32_C(   984.20) } },
    { { SIMDE_FLOAT32_C(   870.86), SIMDE_FLOAT32_C(  -756.20), SIMDE_FLOAT32_C(  -317.08), SIMDE_FLOAT32_C(   -40.96) },
      {     -SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(  -669.37), SIMDE_FLOAT32_C(  -795.72), SIMDE_FLOAT32_C(  -168.95) },
       INT32_C(          20),
      {     -SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(  -756.20), SIMDE_FLOAT32_C(  -317.08), SIMDE_FLOAT32_C(   -40.96) } },
    { { SIMDE_FLOAT32_C(  -148.72), SIMDE_FLOAT32_C(   263.97), SIMDE_FLOAT32_C(  -589.36), SIMDE_FLOAT32_C(  -703.18) },
      { SIMDE_FLOAT32_C(  -994.68), SIMDE_FLOAT32_C(  -972.29), SIMDE_FLOAT32_C(    19.13), SIMDE_FLOAT32_C(   794.70) },
       INT32_C(          36),
      { SIMDE_FLOAT32_C(  -994.75), SIMDE_FLOAT32_C(   263.97), SIMDE_FLOAT32_C(  -589.36), SIMDE_FLOAT32_C(  -703.18) } },
    { { SIMDE_FLOAT32_C(  -317.88), SIMDE_FLOAT32_C(   -47.60), SIMDE_FLOAT32_C(  -376.72), SIMDE_FLOAT32_C(  -640.92) },
      { SIMDE_FLOAT32_C(   187.95), SIMDE_FLOAT32_C(  -392.52), SIMDE_FLOAT32_C(   129.14), SIMDE_FLOAT32_C(  -624.08) },
       INT32_C(          52),
      { SIMDE_FLOAT32_C(   188.00), SIMDE_FLOAT32_C(   -47.60), SIMDE_FLOAT32_C(  -376.72), SIMDE_FLOAT32_C(  -640.92) } },
    { { SIMDE_FLOAT32_C(   443.31), SIMDE_FLOAT32_C(  -211.76), SIMDE_FLOAT32_C(  -131.74), SIMDE_FLOAT32_C(   687.10) },
      {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(   827.30), SIMDE_FLOAT32_C(   535.23), SIMDE_FLOAT32_C(   801.79) },
       INT32_C(          68),
      {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(  -211.76), SIMDE_FLOAT32_C(  -131.74), SIMDE_FLOAT32_C(   687.10) } },
    { { SIMDE_FLOAT32_C(  -218.29), SIMDE_FLOAT32_C(  -870.44), SIMDE_FLOAT32_C(  -170.82), SIMDE_FLOAT32_C(   633.00) },
      {     -SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(   239.82), SIMDE_FLOAT32_C(   929.82), SIMDE_FLOAT32_C(   398.84) },
       INT32_C(          84),
      {     -SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(  -870.44), SIMDE_FLOAT32_C(  -170.82), SIMDE_FLOAT32_C(   633.00) } },
    { { SIMDE_FLOAT32_C(  -365.60), SIMDE_FLOAT32_C(   631.08), SIMDE_FLOAT32_C(  -854.05), SIMDE_FLOAT32_C(   257.67) },
      {     -SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(   333.90), SIMDE_FLOAT32_C(   865.15), SIMDE_FLOAT32_C(   119.30) },
       INT32_C(         100),
      {     -SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(   631.08), SIMDE_FLOAT32_C(  -854.05), SIMDE_FLOAT32_C(   257.67) } },
    { { SIMDE_FLOAT32_C(  -501.95), SIMDE_FLOAT32_C(   730.83), SIMDE_FLOAT32_C(  -750.29), SIMDE_FLOAT32_C(   969.21) },
      {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(   784.94), SIMDE_FLOAT32_C(   771.00), SIMDE_FLOAT32_C(   589.71) },
       INT32_C(         116),
      {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(   730.83), SIMDE_FLOAT32_C(  -750.29), SIMDE_FLOAT32_C(   969.21) } },
    { { SIMDE_FLOAT32_C(   719.27), SIMDE_FLOAT32_C(   -19.60), SIMDE_FLOAT32_C(  -814.29), SIMDE_FLOAT32_C(   112.80) },
      { SIMDE_FLOAT32_C(  -779.77), SIMDE_FLOAT32_C(  -884.47), SIMDE_FLOAT32_C(  -488.36), SIMDE_FLOAT32_C(   487.75) },
       INT32_C(         132),
      { SIMDE_FLOAT32_C(  -779.77), SIMDE_FLOAT32_C(   -19.60), SIMDE_FLOAT32_C(  -814.29), SIMDE_FLOAT32_C(   112.80) } },
    { { SIMDE_FLOAT32_C(   705.18), SIMDE_FLOAT32_C(  -877.85), SIMDE_FLOAT32_C(  -304.44), SIMDE_FLOAT32_C(   851.13) },
      { SIMDE_FLOAT32_C(   379.82), SIMDE_FLOAT32_C(  -314.28), SIMDE_FLOAT32_C(   185.03), SIMDE_FLOAT32_C(   244.98) },
       INT32_C(         148),
      { SIMDE_FLOAT32_C(   379.82), SIMDE_FLOAT32_C(  -877.85), SIMDE_FLOAT32_C(  -304.44), SIMDE_FLOAT32_C(   851.13) } },
    { { SIMDE_FLOAT32_C(  -105.16), SIMDE_FLOAT32_C(  -892.46), SIMDE_FLOAT32_C(  -632.37), SIMDE_FLOAT32_C(   392.89) },
      {      SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(  -382.66), SIMDE_FLOAT32_C(   362.10), SIMDE_FLOAT32_C(   396.50) },
       INT32_C(         164),
      {      SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(  -892.46), SIMDE_FLOAT32_C(  -632.37), SIMDE_FLOAT32_C(   392.89) } },
    { { SIMDE_FLOAT32_C(  -446.50), SIMDE_FLOAT32_C(   685.81), SIMDE_FLOAT32_C(  -294.53), SIMDE_FLOAT32_C(   533.91) },
      {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(   818.27), SIMDE_FLOAT32_C(   754.13), SIMDE_FLOAT32_C(   987.04) },
       INT32_C(         180),
      {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(   685.81), SIMDE_FLOAT32_C(  -294.53), SIMDE_FLOAT32_C(   533.91) } },
    { { SIMDE_FLOAT32_C(    51.52), SIMDE_FLOAT32_C(  -964.91), SIMDE_FLOAT32_C(   364.03), SIMDE_FLOAT32_C(   747.08) },
      {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(  -256.14), SIMDE_FLOAT32_C(  -567.20), SIMDE_FLOAT32_C(    71.25) },
       INT32_C(         196),
      {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(  -964.91), SIMDE_FLOAT32_C(   364.03), SIMDE_FLOAT32_C(   747.08) } },
    { { SIMDE_FLOAT32_C(   966.09), SIMDE_FLOAT32_C(  -903.63), SIMDE_FLOAT32_C(  -394.56), SIMDE_FLOAT32_C(   358.98) },
      {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(   222.78), SIMDE_FLOAT32_C(  -278.91), SIMDE_FLOAT32_C(   331.23) },
       INT32_C(         212),
      {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(  -903.63), SIMDE_FLOAT32_C(  -394.56), SIMDE_FLOAT32_C(   358.98) } },
    { { SIMDE_FLOAT32_C(  -682.56), SIMDE_FLOAT32_C(  -821.44), SIMDE_FLOAT32_C(   539.99), SIMDE_FLOAT32_C(    22.92) },
      { SIMDE_FLOAT32_C(   712.47), SIMDE_FLOAT32_C(   411.50), SIMDE_FLOAT32_C(  -158.81), SIMDE_FLOAT32_C(   466.60) },
       INT32_C(         228),
      { SIMDE_FLOAT32_C(   712.47), SIMDE_FLOAT32_C(  -821.44), SIMDE_FLOAT32_C(   539.99), SIMDE_FLOAT32_C(    22.92) } },
    { { SIMDE_FLOAT32_C(   171.10), SIMDE_FLOAT32_C(  -291.52), SIMDE_FLOAT32_C(  -549.93), SIMDE_FLOAT32_C(   206.19) },
      { SIMDE_FLOAT32_C(  -927.48), SIMDE_FLOAT32_C(  -802.85), SIMDE_FLOAT32_C(    92.41), SIMDE_FLOAT32_C(  -183.62) },
       INT32_C(         244),
      { SIMDE_FLOAT32_C(  -927.48), SIMDE_FLOAT32_C(  -291.52), SIMDE_FLOAT32_C(  -549.93), SIMDE_FLOAT32_C(   206.19) } },
  };

  simde__m128 a, b, r;

  a = simde_mm_loadu_ps(test_vec[0].a);
  b = simde_mm_loadu_ps(test_vec[0].b);
  r = simde_mm_roundscale_ss(a, b, INT32_C(           0));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[0].r), 1);

  a = simde_mm_loadu_ps(test_vec[1].a);
  b = simde_mm_loadu_ps(test_vec[1].b);
  r = simde_mm_roundscale_ss(a, b, INT32_C(          16));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[1].r), 1);

  a = simde_mm_loadu_ps(test_vec[2].a);
  b = simde_mm_loadu_ps(test_vec[2].b);
  r = simde_mm_roundscale_ss(a, b, INT32_C(          32));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[2].r), 1);

  a = simde_mm_loadu_ps(test_vec[3].a);
  b = simde_mm_loadu_ps(test_vec[3].b);
  r = simde_mm_roundscale_ss(a, b, INT32_C(          48));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[3].r), 1);

  a = simde_mm_loadu_ps(test_vec[4].a);
  b = simde_mm_loadu_ps(test_vec[4].b);
  r = simde_mm_roundscale_ss(a, b, INT32_C(          64));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[4].r), 1);

  a = simde_mm_loadu_ps(test_vec[5].a);
  b = simde_mm_loadu_ps(test_vec[5].b);
  r = simde_mm_roundscale_ss(a, b, INT32_C(          80));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[5].r), 1);

  a = simde_mm_loadu_ps(test_vec[6].a);
  b = simde_mm_loadu_ps(test_vec[6].b);
  r = simde_mm_roundscale_ss(a, b, INT32_C(          96));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[6].r), 1);

  a = simde_mm_loadu_ps(test_vec[7].a);
  b = simde_mm_loadu_ps(test_vec[7].b);
  r = simde_mm_roundscale_ss(a, b, INT32_C(         112));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[7].r), 1);

  a = simde_mm_loadu_ps(test_vec[8].a);
  b = simde_mm_loadu_ps(test_vec[8].b);
  r = simde_mm_roundscale_ss(a, b, INT32_C(         128));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[8].r), 1);

  a = simde_mm_loadu_ps(test_vec[9].a);
  b = simde_mm_loadu_ps(test_vec[9].b);
  r = simde_mm_roundscale_ss(a, b, INT32_C(         144));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[9].r), 1);

  a = simde_mm_loadu_ps(test_vec[10].a);
  b = simde_mm_loadu_ps(test_vec[10].b);
  r = simde_mm_roundscale_ss(a, b, INT32_C(         160));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[10].r), 1);

  a = simde_mm_loadu_ps(test_vec[11].a);
  b = simde_mm_loadu_ps(test_vec[11].b);
  r = simde_mm_roundscale_ss(a, b, INT32_C(         176));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[11].r), 1);

  a = simde_mm_loadu_ps(test_vec[12].a);
  b = simde_mm_loadu_ps(test_vec[12].b);
  r = simde_mm_roundscale_ss(a, b, INT32_C(         192));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[12].r), 1);

  a = simde_mm_loadu_ps(test_vec[13].a);
  b = simde_mm_loadu_ps(test_vec[13].b);
  r = simde_mm_roundscale_ss(a, b, INT32_C(         208));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[13].r), 1);

  a = simde_mm_loadu_ps(test_vec[14].a);
  b = simde_mm_loadu_ps(test_vec[14].b);
  r = simde_mm_roundscale_ss(a, b, INT32_C(         224));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[14].r), 1);

  a = simde_mm_loadu_ps(test_vec[15].a);
  b = simde_mm_loadu_ps(test_vec[15].b);
  r = simde_mm_roundscale_ss(a, b, INT32_C(         240));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[15].r), 1);

  a = simde_mm_loadu_ps(test_vec[16].a);
  b = simde_mm_loadu_ps(test_vec[16].b);
  r = simde_mm_roundscale_ss(a, b, INT32_C(           1));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[16].r), 1);

  a = simde_mm_loadu_ps(test_vec[17].a);
  b = simde_mm_loadu_ps(test_vec[17].b);
  r = simde_mm_roundscale_ss(a, b, INT32_C(          17));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[17].r), 1);

  a = simde_mm_loadu_ps(test_vec[18].a);
  b = simde_mm_loadu_ps(test_vec[18].b);
  r = simde_mm_roundscale_ss(a, b, INT32_C(          33));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[18].r), 1);

  a = simde_mm_loadu_ps(test_vec[19].a);
  b = simde_mm_loadu_ps(test_vec[19].b);
  r = simde_mm_roundscale_ss(a, b, INT32_C(          49));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[19].r), 1);

  a = simde_mm_loadu_ps(test_vec[20].a);
  b = simde_mm_loadu_ps(test_vec[20].b);
  r = simde_mm_roundscale_ss(a, b, INT32_C(          65));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[20].r), 1);

  a = simde_mm_loadu_ps(test_vec[21].a);
  b = simde_mm_loadu_ps(test_vec[21].b);
  r = simde_mm_roundscale_ss(a, b, INT32_C(          81));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[21].r), 1);

  a = simde_mm_loadu_ps(test_vec[22].a);
  b = simde_mm_loadu_ps(test_vec[22].b);
  r = simde_mm_roundscale_ss(a, b, INT32_C(          97));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[22].r), 1);

  a = simde_mm_loadu_ps(test_vec[23].a);
  b = simde_mm_loadu_ps(test_vec[23].b);
  r = simde_mm_roundscale_ss(a, b, INT32_C(         113));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[23].r), 1);

  a = simde_mm_loadu_ps(test_vec[24].a);
  b = simde_mm_loadu_ps(test_vec[24].b);
  r = simde_mm_roundscale_ss(a, b, INT32_C(         129));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[24].r), 1);

  a = simde_mm_loadu_ps(test_vec[25].a);
  b = simde_mm_loadu_ps(test_vec[25].b);
  r = simde_mm_roundscale_ss(a, b, INT32_C(         145));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[25].r), 1);

  a = simde_mm_loadu_ps(test_vec[26].a);
  b = simde_mm_loadu_ps(test_vec[26].b);
  r = simde_mm_roundscale_ss(a, b, INT32_C(         161));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[26].r), 1);

  a = simde_mm_loadu_ps(test_vec[27].a);
  b = simde_mm_loadu_ps(test_vec[27].b);
  r = simde_mm_roundscale_ss(a, b, INT32_C(         177));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[27].r), 1);

  a = simde_mm_loadu_ps(test_vec[28].a);
  b = simde_mm_loadu_ps(test_vec[28].b);
  r = simde_mm_roundscale_ss(a, b, INT32_C(         193));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[28].r), 1);

  a = simde_mm_loadu_ps(test_vec[29].a);
  b = simde_mm_loadu_ps(test_vec[29].b);
  r = simde_mm_roundscale_ss(a, b, INT32_C(         209));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[29].r), 1);

  a = simde_mm_loadu_ps(test_vec[30].a);
  b = simde_mm_loadu_ps(test_vec[30].b);
  r = simde_mm_roundscale_ss(a, b, INT32_C(         225));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[30].r), 1);

  a = simde_mm_loadu_ps(test_vec[31].a);
  b = simde_mm_loadu_ps(test_vec[31].b);
  r = simde_mm_roundscale_ss(a, b, INT32_C(         241));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[31].r), 1);

  a = simde_mm_loadu_ps(test_vec[32].a);
  b = simde_mm_loadu_ps(test_vec[32].b);
  r = simde_mm_roundscale_ss(a, b, INT32_C(           2));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[32].r), 1);

  a = simde_mm_loadu_ps(test_vec[33].a);
  b = simde_mm_loadu_ps(test_vec[33].b);
  r = simde_mm_roundscale_ss(a, b, INT32_C(          18));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[33].r), 1);

  a = simde_mm_loadu_ps(test_vec[34].a);
  b = simde_mm_loadu_ps(test_vec[34].b);
  r = simde_mm_roundscale_ss(a, b, INT32_C(          34));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[34].r), 1);

  a = simde_mm_loadu_ps(test_vec[35].a);
  b = simde_mm_loadu_ps(test_vec[35].b);
  r = simde_mm_roundscale_ss(a, b, INT32_C(          50));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[35].r), 1);

  a = simde_mm_loadu_ps(test_vec[36].a);
  b = simde_mm_loadu_ps(test_vec[36].b);
  r = simde_mm_roundscale_ss(a, b, INT32_C(          66));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[36].r), 1);

  a = simde_mm_loadu_ps(test_vec[37].a);
  b = simde_mm_loadu_ps(test_vec[37].b);
  r = simde_mm_roundscale_ss(a, b, INT32_C(          82));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[37].r), 1);

  a = simde_mm_loadu_ps(test_vec[38].a);
  b = simde_mm_loadu_ps(test_vec[38].b);
  r = simde_mm_roundscale_ss(a, b, INT32_C(          98));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[38].r), 1);

  a = simde_mm_loadu_ps(test_vec[39].a);
  b = simde_mm_loadu_ps(test_vec[39].b);
  r = simde_mm_roundscale_ss(a, b, INT32_C(         114));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[39].r), 1);

  a = simde_mm_loadu_ps(test_vec[40].a);
  b = simde_mm_loadu_ps(test_vec[40].b);
  r = simde_mm_roundscale_ss(a, b, INT32_C(         130));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[40].r), 1);

  a = simde_mm_loadu_ps(test_vec[41].a);
  b = simde_mm_loadu_ps(test_vec[41].b);
  r = simde_mm_roundscale_ss(a, b, INT32_C(         146));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[41].r), 1);

  a = simde_mm_loadu_ps(test_vec[42].a);
  b = simde_mm_loadu_ps(test_vec[42].b);
  r = simde_mm_roundscale_ss(a, b, INT32_C(         162));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[42].r), 1);

  a = simde_mm_loadu_ps(test_vec[43].a);
  b = simde_mm_loadu_ps(test_vec[43].b);
  r = simde_mm_roundscale_ss(a, b, INT32_C(         178));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[43].r), 1);

  a = simde_mm_loadu_ps(test_vec[44].a);
  b = simde_mm_loadu_ps(test_vec[44].b);
  r = simde_mm_roundscale_ss(a, b, INT32_C(         194));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[44].r), 1);

  a = simde_mm_loadu_ps(test_vec[45].a);
  b = simde_mm_loadu_ps(test_vec[45].b);
  r = simde_mm_roundscale_ss(a, b, INT32_C(         210));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[45].r), 1);

  a = simde_mm_loadu_ps(test_vec[46].a);
  b = simde_mm_loadu_ps(test_vec[46].b);
  r = simde_mm_roundscale_ss(a, b, INT32_C(         226));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[46].r), 1);

  a = simde_mm_loadu_ps(test_vec[47].a);
  b = simde_mm_loadu_ps(test_vec[47].b);
  r = simde_mm_roundscale_ss(a, b, INT32_C(         242));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[47].r), 1);

  a = simde_mm_loadu_ps(test_vec[48].a);
  b = simde_mm_loadu_ps(test_vec[48].b);
  r = simde_mm_roundscale_ss(a, b, INT32_C(           3));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[48].r), 1);

  a = simde_mm_loadu_ps(test_vec[49].a);
  b = simde_mm_loadu_ps(test_vec[49].b);
  r = simde_mm_roundscale_ss(a, b, INT32_C(          19));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[49].r), 1);

  a = simde_mm_loadu_ps(test_vec[50].a);
  b = simde_mm_loadu_ps(test_vec[50].b);
  r = simde_mm_roundscale_ss(a, b, INT32_C(          35));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[50].r), 1);

  a = simde_mm_loadu_ps(test_vec[51].a);
  b = simde_mm_loadu_ps(test_vec[51].b);
  r = simde_mm_roundscale_ss(a, b, INT32_C(          51));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[51].r), 1);

  a = simde_mm_loadu_ps(test_vec[52].a);
  b = simde_mm_loadu_ps(test_vec[52].b);
  r = simde_mm_roundscale_ss(a, b, INT32_C(          67));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[52].r), 1);

  a = simde_mm_loadu_ps(test_vec[53].a);
  b = simde_mm_loadu_ps(test_vec[53].b);
  r = simde_mm_roundscale_ss(a, b, INT32_C(          83));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[53].r), 1);

  a = simde_mm_loadu_ps(test_vec[54].a);
  b = simde_mm_loadu_ps(test_vec[54].b);
  r = simde_mm_roundscale_ss(a, b, INT32_C(          99));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[54].r), 1);

  a = simde_mm_loadu_ps(test_vec[55].a);
  b = simde_mm_loadu_ps(test_vec[55].b);
  r = simde_mm_roundscale_ss(a, b, INT32_C(         115));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[55].r), 1);

  a = simde_mm_loadu_ps(test_vec[56].a);
  b = simde_mm_loadu_ps(test_vec[56].b);
  r = simde_mm_roundscale_ss(a, b, INT32_C(         131));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[56].r), 1);

  a = simde_mm_loadu_ps(test_vec[57].a);
  b = simde_mm_loadu_ps(test_vec[57].b);
  r = simde_mm_roundscale_ss(a, b, INT32_C(         147));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[57].r), 1);

  a = simde_mm_loadu_ps(test_vec[58].a);
  b = simde_mm_loadu_ps(test_vec[58].b);
  r = simde_mm_roundscale_ss(a, b, INT32_C(         163));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[58].r), 1);

  a = simde_mm_loadu_ps(test_vec[59].a);
  b = simde_mm_loadu_ps(test_vec[59].b);
  r = simde_mm_roundscale_ss(a, b, INT32_C(         179));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[59].r), 1);

  a = simde_mm_loadu_ps(test_vec[60].a);
  b = simde_mm_loadu_ps(test_vec[60].b);
  r = simde_mm_roundscale_ss(a, b, INT32_C(         195));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[60].r), 1);

  a = simde_mm_loadu_ps(test_vec[61].a);
  b = simde_mm_loadu_ps(test_vec[61].b);
  r = simde_mm_roundscale_ss(a, b, INT32_C(         211));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[61].r), 1);

  a = simde_mm_loadu_ps(test_vec[62].a);
  b = simde_mm_loadu_ps(test_vec[62].b);
  r = simde_mm_roundscale_ss(a, b, INT32_C(         227));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[62].r), 1);

  a = simde_mm_loadu_ps(test_vec[63].a);
  b = simde_mm_loadu_ps(test_vec[63].b);
  r = simde_mm_roundscale_ss(a, b, INT32_C(         243));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[63].r), 1);

  a = simde_mm_loadu_ps(test_vec[64].a);
  b = simde_mm_loadu_ps(test_vec[64].b);
  r = simde_mm_roundscale_ss(a, b, INT32_C(           4));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[64].r), 1);

  a = simde_mm_loadu_ps(test_vec[65].a);
  b = simde_mm_loadu_ps(test_vec[65].b);
  r = simde_mm_roundscale_ss(a, b, INT32_C(          20));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[65].r), 1);

  a = simde_mm_loadu_ps(test_vec[66].a);
  b = simde_mm_loadu_ps(test_vec[66].b);
  r = simde_mm_roundscale_ss(a, b, INT32_C(          36));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[66].r), 1);

  a = simde_mm_loadu_ps(test_vec[67].a);
  b = simde_mm_loadu_ps(test_vec[67].b);
  r = simde_mm_roundscale_ss(a, b, INT32_C(          52));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[67].r), 1);

  a = simde_mm_loadu_ps(test_vec[68].a);
  b = simde_mm_loadu_ps(test_vec[68].b);
  r = simde_mm_roundscale_ss(a, b, INT32_C(          68));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[68].r), 1);

  a = simde_mm_loadu_ps(test_vec[69].a);
  b = simde_mm_loadu_ps(test_vec[69].b);
  r = simde_mm_roundscale_ss(a, b, INT32_C(          84));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[69].r), 1);

  a = simde_mm_loadu_ps(test_vec[70].a);
  b = simde_mm_loadu_ps(test_vec[70].b);
  r = simde_mm_roundscale_ss(a, b, INT32_C(         100));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[70].r), 1);

  a = simde_mm_loadu_ps(test_vec[71].a);
  b = simde_mm_loadu_ps(test_vec[71].b);
  r = simde_mm_roundscale_ss(a, b, INT32_C(         116));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[71].r), 1);

  a = simde_mm_loadu_ps(test_vec[72].a);
  b = simde_mm_loadu_ps(test_vec[72].b);
  r = simde_mm_roundscale_ss(a, b, INT32_C(         132));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[72].r), 1);

  a = simde_mm_loadu_ps(test_vec[73].a);
  b = simde_mm_loadu_ps(test_vec[73].b);
  r = simde_mm_roundscale_ss(a, b, INT32_C(         148));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[73].r), 1);

  a = simde_mm_loadu_ps(test_vec[74].a);
  b = simde_mm_loadu_ps(test_vec[74].b);
  r = simde_mm_roundscale_ss(a, b, INT32_C(         164));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[74].r), 1);

  a = simde_mm_loadu_ps(test_vec[75].a);
  b = simde_mm_loadu_ps(test_vec[75].b);
  r = simde_mm_roundscale_ss(a, b, INT32_C(         180));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[75].r), 1);

  a = simde_mm_loadu_ps(test_vec[76].a);
  b = simde_mm_loadu_ps(test_vec[76].b);
  r = simde_mm_roundscale_ss(a, b, INT32_C(         196));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[76].r), 1);

  a = simde_mm_loadu_ps(test_vec[77].a);
  b = simde_mm_loadu_ps(test_vec[77].b);
  r = simde_mm_roundscale_ss(a, b, INT32_C(         212));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[77].r), 1);

  a = simde_mm_loadu_ps(test_vec[78].a);
  b = simde_mm_loadu_ps(test_vec[78].b);
  r = simde_mm_roundscale_ss(a, b, INT32_C(         228));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[78].r), 1);

  a = simde_mm_loadu_ps(test_vec[79].a);
  b = simde_mm_loadu_ps(test_vec[79].b);
  r = simde_mm_roundscale_ss(a, b, INT32_C(         244));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[79].r), 1);

  return 0;
#else
  fputc('\n', stdout);
  int round_type[5] = {SIMDE_MM_FROUND_TO_NEAREST_INT, SIMDE_MM_FROUND_TO_NEG_INF, SIMDE_MM_FROUND_TO_POS_INF, SIMDE_MM_FROUND_TO_ZERO, SIMDE_MM_FROUND_CUR_DIRECTION};
  for (int i = 0 ; i < 5 ; i++) {
    for (int j = 0 ; j < 16 ; j++) {
      simde__m128 a = simde_test_x86_random_f32x4(SIMDE_FLOAT32_C(-1000.0), SIMDE_FLOAT32_C(1000.0));
      simde__m128 b = simde_test_x86_random_f32x4(SIMDE_FLOAT32_C(-1000.0), SIMDE_FLOAT32_C(1000.0));
      if((simde_test_codegen_rand() & 1)) {
        if((simde_test_codegen_rand() & 1))
          b = simde_mm_mask_mov_ps(b, 1, simde_mm_set1_ps(SIMDE_MATH_NAN));
        else {
          if((simde_test_codegen_rand() & 1))
            b = simde_mm_mask_mov_ps(b, 1, simde_mm_set1_ps(SIMDE_MATH_INFINITY));
          else
            b = simde_mm_mask_mov_ps(b, 1, simde_mm_set1_ps(-SIMDE_MATH_INFINITY));
        }
      }
      int imm8 = ((j << 4) | round_type[i]) & 255;
      simde__m128 r;
      SIMDE_CONSTIFY_256_(simde_mm_roundscale_ss, r, simde_mm_setzero_ps(), imm8, a, b);

      simde_test_x86_write_f32x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
      simde_test_x86_write_f32x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
      simde_test_codegen_write_i32(2, imm8, SIMDE_TEST_VEC_POS_MIDDLE);
      simde_test_x86_write_f32x4(2, r, SIMDE_TEST_VEC_POS_LAST);
    }
  }
  return 1;
#endif
}

static int
test_simde_mm_mask_roundscale_ss (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const simde_float32 src[4];
    const simde__mmask8 k;
    const simde_float32 a[4];
    const simde_float32 b[4];
    const int32_t imm8;
    const simde_float32 r[4];
  } test_vec[] = {
    { { SIMDE_FLOAT32_C(  -866.00), SIMDE_FLOAT32_C(  -361.57), SIMDE_FLOAT32_C(  -516.74), SIMDE_FLOAT32_C(  -299.17) },
      UINT8_C(118),
      { SIMDE_FLOAT32_C(  -454.59), SIMDE_FLOAT32_C(   290.73), SIMDE_FLOAT32_C(   910.53), SIMDE_FLOAT32_C(    91.54) },
      { SIMDE_FLOAT32_C(   463.34), SIMDE_FLOAT32_C(   465.84), SIMDE_FLOAT32_C(  -211.43), SIMDE_FLOAT32_C(   429.04) },
       INT32_C(          96),
      { SIMDE_FLOAT32_C(  -866.00), SIMDE_FLOAT32_C(   290.73), SIMDE_FLOAT32_C(   910.53), SIMDE_FLOAT32_C(    91.54) } },
    { { SIMDE_FLOAT32_C(   762.35), SIMDE_FLOAT32_C(   -43.33), SIMDE_FLOAT32_C(  -810.77), SIMDE_FLOAT32_C(  -340.20) },
      UINT8_C(132),
      { SIMDE_FLOAT32_C(   433.68), SIMDE_FLOAT32_C(  -841.73), SIMDE_FLOAT32_C(  -334.46), SIMDE_FLOAT32_C(  -927.21) },
      { SIMDE_FLOAT32_C(   555.23), SIMDE_FLOAT32_C(   678.38), SIMDE_FLOAT32_C(   943.43), SIMDE_FLOAT32_C(  -947.24) },
       INT32_C(          17),
      { SIMDE_FLOAT32_C(   762.35), SIMDE_FLOAT32_C(  -841.73), SIMDE_FLOAT32_C(  -334.46), SIMDE_FLOAT32_C(  -927.21) } },
    { { SIMDE_FLOAT32_C(   523.07), SIMDE_FLOAT32_C(  -723.81), SIMDE_FLOAT32_C(   581.28), SIMDE_FLOAT32_C(  -993.68) },
      UINT8_C(145),
      { SIMDE_FLOAT32_C(  -438.97), SIMDE_FLOAT32_C(  -448.27), SIMDE_FLOAT32_C(  -732.25), SIMDE_FLOAT32_C(  -528.44) },
      { SIMDE_FLOAT32_C(   643.27), SIMDE_FLOAT32_C(   731.10), SIMDE_FLOAT32_C(   937.40), SIMDE_FLOAT32_C(  -568.16) },
       INT32_C(         130),
      { SIMDE_FLOAT32_C(   643.27), SIMDE_FLOAT32_C(  -448.27), SIMDE_FLOAT32_C(  -732.25), SIMDE_FLOAT32_C(  -528.44) } },
    { { SIMDE_FLOAT32_C(  -341.66), SIMDE_FLOAT32_C(   -77.52), SIMDE_FLOAT32_C(  -879.37), SIMDE_FLOAT32_C(  -152.44) },
      UINT8_C(247),
      { SIMDE_FLOAT32_C(   701.96), SIMDE_FLOAT32_C(  -718.75), SIMDE_FLOAT32_C(   740.54), SIMDE_FLOAT32_C(  -632.50) },
      { SIMDE_FLOAT32_C(  -645.96), SIMDE_FLOAT32_C(   295.77), SIMDE_FLOAT32_C(  -954.12), SIMDE_FLOAT32_C(  -702.53) },
       INT32_C(         227),
      { SIMDE_FLOAT32_C(  -645.96), SIMDE_FLOAT32_C(  -718.75), SIMDE_FLOAT32_C(   740.54), SIMDE_FLOAT32_C(  -632.50) } },
    { { SIMDE_FLOAT32_C(   240.32), SIMDE_FLOAT32_C(  -128.41), SIMDE_FLOAT32_C(  -535.73), SIMDE_FLOAT32_C(  -178.40) },
      UINT8_C( 78),
      { SIMDE_FLOAT32_C(   441.29), SIMDE_FLOAT32_C(   382.63), SIMDE_FLOAT32_C(   429.65), SIMDE_FLOAT32_C(   709.04) },
      { SIMDE_FLOAT32_C(   854.19), SIMDE_FLOAT32_C(    72.92), SIMDE_FLOAT32_C(   440.14), SIMDE_FLOAT32_C(   791.59) },
       INT32_C(         100),
      { SIMDE_FLOAT32_C(   240.32), SIMDE_FLOAT32_C(   382.63), SIMDE_FLOAT32_C(   429.65), SIMDE_FLOAT32_C(   709.04) } },
    { { SIMDE_FLOAT32_C(   -44.45), SIMDE_FLOAT32_C(  -836.91), SIMDE_FLOAT32_C(   522.76), SIMDE_FLOAT32_C(    76.18) },
      UINT8_C(115),
      { SIMDE_FLOAT32_C(   105.03), SIMDE_FLOAT32_C(  -221.86), SIMDE_FLOAT32_C(   291.90), SIMDE_FLOAT32_C(  -154.42) },
      { SIMDE_FLOAT32_C(   145.64), SIMDE_FLOAT32_C(   645.93), SIMDE_FLOAT32_C(  -858.66), SIMDE_FLOAT32_C(   191.53) },
       INT32_C(          48),
      { SIMDE_FLOAT32_C(   145.62), SIMDE_FLOAT32_C(  -221.86), SIMDE_FLOAT32_C(   291.90), SIMDE_FLOAT32_C(  -154.42) } },
    { { SIMDE_FLOAT32_C(   379.60), SIMDE_FLOAT32_C(   183.72), SIMDE_FLOAT32_C(  -638.53), SIMDE_FLOAT32_C(   843.87) },
      UINT8_C( 95),
      { SIMDE_FLOAT32_C(   239.38), SIMDE_FLOAT32_C(   285.16), SIMDE_FLOAT32_C(   387.96), SIMDE_FLOAT32_C(  -330.97) },
      { SIMDE_FLOAT32_C(    -5.80), SIMDE_FLOAT32_C(   242.15), SIMDE_FLOAT32_C(   741.95), SIMDE_FLOAT32_C(  -565.66) },
       INT32_C(          49),
      { SIMDE_FLOAT32_C(    -5.88), SIMDE_FLOAT32_C(   285.16), SIMDE_FLOAT32_C(   387.96), SIMDE_FLOAT32_C(  -330.97) } },
    { { SIMDE_FLOAT32_C(    34.62), SIMDE_FLOAT32_C(   989.29), SIMDE_FLOAT32_C(   409.79), SIMDE_FLOAT32_C(  -442.63) },
      UINT8_C(135),
      { SIMDE_FLOAT32_C(  -579.56), SIMDE_FLOAT32_C(   662.41), SIMDE_FLOAT32_C(   843.61), SIMDE_FLOAT32_C(   712.34) },
      { SIMDE_FLOAT32_C(  -492.02), SIMDE_FLOAT32_C(   -10.75), SIMDE_FLOAT32_C(   358.27), SIMDE_FLOAT32_C(  -350.67) },
       INT32_C(         194),
      { SIMDE_FLOAT32_C(  -492.02), SIMDE_FLOAT32_C(   662.41), SIMDE_FLOAT32_C(   843.61), SIMDE_FLOAT32_C(   712.34) } },
  };

  simde__m128 src, a, b, r;

  src = simde_mm_loadu_ps(test_vec[0].src);
  a = simde_mm_loadu_ps(test_vec[0].a);
  b = simde_mm_loadu_ps(test_vec[0].b);
  r = simde_mm_mask_roundscale_ss(src, test_vec[0].k, a, b, INT32_C(          96));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[0].r), 1);

  src = simde_mm_loadu_ps(test_vec[1].src);
  a = simde_mm_loadu_ps(test_vec[1].a);
  b = simde_mm_loadu_ps(test_vec[1].b);
  r = simde_mm_mask_roundscale_ss(src, test_vec[1].k, a, b, INT32_C(          17));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[1].r), 1);

  src = simde_mm_loadu_ps(test_vec[2].src);
  a = simde_mm_loadu_ps(test_vec[2].a);
  b = simde_mm_loadu_ps(test_vec[2].b);
  r = simde_mm_mask_roundscale_ss(src, test_vec[2].k, a, b, INT32_C(         130));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[2].r), 1);

  src = simde_mm_loadu_ps(test_vec[3].src);
  a = simde_mm_loadu_ps(test_vec[3].a);
  b = simde_mm_loadu_ps(test_vec[3].b);
  r = simde_mm_mask_roundscale_ss(src, test_vec[3].k, a, b, INT32_C(         227));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[3].r), 1);

  src = simde_mm_loadu_ps(test_vec[4].src);
  a = simde_mm_loadu_ps(test_vec[4].a);
  b = simde_mm_loadu_ps(test_vec[4].b);
  r = simde_mm_mask_roundscale_ss(src, test_vec[4].k, a, b, INT32_C(         100));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[4].r), 1);

  src = simde_mm_loadu_ps(test_vec[5].src);
  a = simde_mm_loadu_ps(test_vec[5].a);
  b = simde_mm_loadu_ps(test_vec[5].b);
  r = simde_mm_mask_roundscale_ss(src, test_vec[5].k, a, b, INT32_C(          48));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[5].r), 1);

  src = simde_mm_loadu_ps(test_vec[6].src);
  a = simde_mm_loadu_ps(test_vec[6].a);
  b = simde_mm_loadu_ps(test_vec[6].b);
  r = simde_mm_mask_roundscale_ss(src, test_vec[6].k, a, b, INT32_C(          49));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[6].r), 1);

  src = simde_mm_loadu_ps(test_vec[7].src);
  a = simde_mm_loadu_ps(test_vec[7].a);
  b = simde_mm_loadu_ps(test_vec[7].b);
  r = simde_mm_mask_roundscale_ss(src, test_vec[7].k, a, b, INT32_C(         194));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[7].r), 1);

  return 0;
#else
  fputc('\n', stdout);
  int round_type[5] = {SIMDE_MM_FROUND_TO_NEAREST_INT, SIMDE_MM_FROUND_TO_NEG_INF, SIMDE_MM_FROUND_TO_POS_INF, SIMDE_MM_FROUND_TO_ZERO, SIMDE_MM_FROUND_CUR_DIRECTION};
  for (int i = 0 ; i < 8 ; i++) {
    simde__m128 src = simde_test_x86_random_f32x4(SIMDE_FLOAT32_C(-1000.0), SIMDE_FLOAT32_C(1000.0));
    simde__mmask8 k = simde_test_x86_random_mmask8();
    simde__m128 a = simde_test_x86_random_f32x4(SIMDE_FLOAT32_C(-1000.0), SIMDE_FLOAT32_C(1000.0));
    simde__m128 b = simde_test_x86_random_f32x4(SIMDE_FLOAT32_C(-1000.0), SIMDE_FLOAT32_C(1000.0));
    if((simde_test_codegen_rand() & 1)) {
      if((simde_test_codegen_rand() & 1))
        b = simde_mm_mask_mov_ps(b, 1, simde_mm_set1_ps(SIMDE_MATH_NAN));
      else {
        if((simde_test_codegen_rand() & 1))
          b = simde_mm_mask_mov_ps(b, 1, simde_mm_set1_ps(SIMDE_MATH_INFINITY));
        else
          b = simde_mm_mask_mov_ps(b, 1, simde_mm_set1_ps(-SIMDE_MATH_INFINITY));
      }
    }
    int imm8 = (((simde_test_codegen_rand() & 15) << 4) | round_type[i % 5]) & 255;
    simde__m128 r;
    SIMDE_CONSTIFY_256_(simde_mm_mask_roundscale_ss, r, simde_mm_setzero_ps(), imm8, src, k, a, b);

    simde_test_x86_write_f32x4(2, src, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_mmask8(2, k, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_f32x4(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_f32x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i32(2, imm8, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_f32x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm_maskz_roundscale_ss (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const simde__mmask8 k;
    const simde_float32 a[4];
    const simde_float32 b[4];
    const int32_t imm8;
    const simde_float32 r[4];
  } test_vec[] = {
    { UINT8_C(150),
      { SIMDE_FLOAT32_C(   560.38), SIMDE_FLOAT32_C(  -514.60), SIMDE_FLOAT32_C(  -499.34), SIMDE_FLOAT32_C(   404.24) },
      {     -SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(   740.05), SIMDE_FLOAT32_C(  -310.60), SIMDE_FLOAT32_C(   878.68) },
       INT32_C(         224),
      { SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(  -514.60), SIMDE_FLOAT32_C(  -499.34), SIMDE_FLOAT32_C(   404.24) } },
    { UINT8_C(137),
      { SIMDE_FLOAT32_C(  -845.43), SIMDE_FLOAT32_C(   397.73), SIMDE_FLOAT32_C(   152.56), SIMDE_FLOAT32_C(  -856.14) },
      { SIMDE_FLOAT32_C(  -192.48), SIMDE_FLOAT32_C(   709.93), SIMDE_FLOAT32_C(   209.33), SIMDE_FLOAT32_C(   227.96) },
       INT32_C(         129),
      { SIMDE_FLOAT32_C(  -192.48), SIMDE_FLOAT32_C(   397.73), SIMDE_FLOAT32_C(   152.56), SIMDE_FLOAT32_C(  -856.14) } },
    { UINT8_C( 20),
      { SIMDE_FLOAT32_C(   880.32), SIMDE_FLOAT32_C(  -957.81), SIMDE_FLOAT32_C(  -701.42), SIMDE_FLOAT32_C(  -470.36) },
      { SIMDE_FLOAT32_C(  -777.04), SIMDE_FLOAT32_C(   600.26), SIMDE_FLOAT32_C(  -331.16), SIMDE_FLOAT32_C(   783.34) },
       INT32_C(          50),
      { SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(  -957.81), SIMDE_FLOAT32_C(  -701.42), SIMDE_FLOAT32_C(  -470.36) } },
    { UINT8_C( 12),
      { SIMDE_FLOAT32_C(  -423.61), SIMDE_FLOAT32_C(   -90.45), SIMDE_FLOAT32_C(   876.98), SIMDE_FLOAT32_C(  -544.93) },
      {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(   560.58), SIMDE_FLOAT32_C(   575.90), SIMDE_FLOAT32_C(   469.65) },
       INT32_C(          99),
      { SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(   -90.45), SIMDE_FLOAT32_C(   876.98), SIMDE_FLOAT32_C(  -544.93) } },
    { UINT8_C( 12),
      { SIMDE_FLOAT32_C(   874.33), SIMDE_FLOAT32_C(   674.90), SIMDE_FLOAT32_C(  -458.99), SIMDE_FLOAT32_C(    83.66) },
      {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(   913.35), SIMDE_FLOAT32_C(  -863.41), SIMDE_FLOAT32_C(   843.16) },
       INT32_C(         116),
      { SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(   674.90), SIMDE_FLOAT32_C(  -458.99), SIMDE_FLOAT32_C(    83.66) } },
    { UINT8_C( 25),
      { SIMDE_FLOAT32_C(  -598.26), SIMDE_FLOAT32_C(   741.99), SIMDE_FLOAT32_C(    -7.85), SIMDE_FLOAT32_C(  -814.92) },
      { SIMDE_FLOAT32_C(   827.65), SIMDE_FLOAT32_C(  -838.35), SIMDE_FLOAT32_C(   372.66), SIMDE_FLOAT32_C(  -595.96) },
       INT32_C(          96),
      { SIMDE_FLOAT32_C(   827.66), SIMDE_FLOAT32_C(   741.99), SIMDE_FLOAT32_C(    -7.85), SIMDE_FLOAT32_C(  -814.92) } },
    { UINT8_C(213),
      { SIMDE_FLOAT32_C(  -610.18), SIMDE_FLOAT32_C(  -189.78), SIMDE_FLOAT32_C(  -564.99), SIMDE_FLOAT32_C(   859.47) },
      { SIMDE_FLOAT32_C(  -511.25), SIMDE_FLOAT32_C(  -834.52), SIMDE_FLOAT32_C(  -273.15), SIMDE_FLOAT32_C(   319.83) },
       INT32_C(          65),
      { SIMDE_FLOAT32_C(  -511.25), SIMDE_FLOAT32_C(  -189.78), SIMDE_FLOAT32_C(  -564.99), SIMDE_FLOAT32_C(   859.47) } },
    { UINT8_C(140),
      { SIMDE_FLOAT32_C(   123.48), SIMDE_FLOAT32_C(   304.61), SIMDE_FLOAT32_C(   774.19), SIMDE_FLOAT32_C(   260.07) },
      { SIMDE_FLOAT32_C(   147.77), SIMDE_FLOAT32_C(   567.85), SIMDE_FLOAT32_C(   438.85), SIMDE_FLOAT32_C(   289.51) },
       INT32_C(         114),
      { SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(   304.61), SIMDE_FLOAT32_C(   774.19), SIMDE_FLOAT32_C(   260.07) } },
  };

  simde__m128 a, b, r;

  a = simde_mm_loadu_ps(test_vec[0].a);
  b = simde_mm_loadu_ps(test_vec[0].b);
  r = simde_mm_maskz_roundscale_ss(test_vec[0].k, a, b, INT32_C(         224));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[0].r), 1);

  a = simde_mm_loadu_ps(test_vec[1].a);
  b = simde_mm_loadu_ps(test_vec[1].b);
  r = simde_mm_maskz_roundscale_ss(test_vec[1].k, a, b, INT32_C(         129));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[1].r), 1);

  a = simde_mm_loadu_ps(test_vec[2].a);
  b = simde_mm_loadu_ps(test_vec[2].b);
  r = simde_mm_maskz_roundscale_ss(test_vec[2].k, a, b, INT32_C(          50));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[2].r), 1);

  a = simde_mm_loadu_ps(test_vec[3].a);
  b = simde_mm_loadu_ps(test_vec[3].b);
  r = simde_mm_maskz_roundscale_ss(test_vec[3].k, a, b, INT32_C(          99));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[3].r), 1);

  a = simde_mm_loadu_ps(test_vec[4].a);
  b = simde_mm_loadu_ps(test_vec[4].b);
  r = simde_mm_maskz_roundscale_ss(test_vec[4].k, a, b, INT32_C(         116));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[4].r), 1);

  a = simde_mm_loadu_ps(test_vec[5].a);
  b = simde_mm_loadu_ps(test_vec[5].b);
  r = simde_mm_maskz_roundscale_ss(test_vec[5].k, a, b, INT32_C(          96));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[5].r), 1);

  a = simde_mm_loadu_ps(test_vec[6].a);
  b = simde_mm_loadu_ps(test_vec[6].b);
  r = simde_mm_maskz_roundscale_ss(test_vec[6].k, a, b, INT32_C(          65));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[6].r), 1);

  a = simde_mm_loadu_ps(test_vec[7].a);
  b = simde_mm_loadu_ps(test_vec[7].b);
  r = simde_mm_maskz_roundscale_ss(test_vec[7].k, a, b, INT32_C(         114));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[7].r), 1);

  return 0;
#else
  fputc('\n', stdout);
  int round_type[5] = {SIMDE_MM_FROUND_TO_NEAREST_INT, SIMDE_MM_FROUND_TO_NEG_INF, SIMDE_MM_FROUND_TO_POS_INF, SIMDE_MM_FROUND_TO_ZERO, SIMDE_MM_FROUND_CUR_DIRECTION};
  for (int i = 0 ; i < 8 ; i++) {
    simde__mmask8 k = simde_test_x86_random_mmask8();
    simde__m128 a = simde_test_x86_random_f32x4(SIMDE_FLOAT32_C(-1000.0), SIMDE_FLOAT32_C(1000.0));
    simde__m128 b = simde_test_x86_random_f32x4(SIMDE_FLOAT32_C(-1000.0), SIMDE_FLOAT32_C(1000.0));
    if((simde_test_codegen_rand() & 1)) {
      if((simde_test_codegen_rand() & 1))
        b = simde_mm_mask_mov_ps(b, 1, simde_mm_set1_ps(SIMDE_MATH_NAN));
      else {
        if((simde_test_codegen_rand() & 1))
          b = simde_mm_mask_mov_ps(b, 1, simde_mm_set1_ps(SIMDE_MATH_INFINITY));
        else
          b = simde_mm_mask_mov_ps(b, 1, simde_mm_set1_ps(-SIMDE_MATH_INFINITY));
      }
    }
    int imm8 = (((simde_test_codegen_rand() & 15) << 4) | round_type[i % 5]) & 255;
    simde__m128 r;
    SIMDE_CONSTIFY_256_(simde_mm_maskz_roundscale_ss, r, simde_mm_setzero_ps(), imm8, k, a, b);

    simde_test_x86_write_mmask8(2, k, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_f32x4(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_f32x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i32(2, imm8, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_f32x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm_roundscale_round_ss (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const simde_float32 a[4];
    const simde_float32 b[4];
    const int32_t imm8;
    const int32_t sae;
    const simde_float32 r[4];
  } test_vec[] = {
    { { SIMDE_FLOAT32_C(   800.62), SIMDE_FLOAT32_C(     5.17), SIMDE_FLOAT32_C(   547.21), SIMDE_FLOAT32_C(   203.23) },
      { SIMDE_FLOAT32_C(  -972.56), SIMDE_FLOAT32_C(  -577.41), SIMDE_FLOAT32_C(   863.22), SIMDE_FLOAT32_C(  -460.21) },
       INT32_C(          48),
       INT32_C(           8),
      { SIMDE_FLOAT32_C(  -972.50), SIMDE_FLOAT32_C(     5.17), SIMDE_FLOAT32_C(   547.21), SIMDE_FLOAT32_C(   203.23) } },
    { { SIMDE_FLOAT32_C(   180.26), SIMDE_FLOAT32_C(   -68.69), SIMDE_FLOAT32_C(  -107.59), SIMDE_FLOAT32_C(   332.04) },
      { SIMDE_FLOAT32_C(  -720.34), SIMDE_FLOAT32_C(  -229.64), SIMDE_FLOAT32_C(   714.58), SIMDE_FLOAT32_C(  -728.77) },
       INT32_C(          33),
       INT32_C(           8),
      { SIMDE_FLOAT32_C(  -720.50), SIMDE_FLOAT32_C(   -68.69), SIMDE_FLOAT32_C(  -107.59), SIMDE_FLOAT32_C(   332.04) } },
    { { SIMDE_FLOAT32_C(   440.49), SIMDE_FLOAT32_C(  -146.35), SIMDE_FLOAT32_C(   642.47), SIMDE_FLOAT32_C(   445.00) },
      { SIMDE_FLOAT32_C(   258.97), SIMDE_FLOAT32_C(  -557.60), SIMDE_FLOAT32_C(    27.31), SIMDE_FLOAT32_C(   -55.97) },
       INT32_C(          98),
       INT32_C(           4),
      { SIMDE_FLOAT32_C(   258.98), SIMDE_FLOAT32_C(  -146.35), SIMDE_FLOAT32_C(   642.47), SIMDE_FLOAT32_C(   445.00) } },
    { { SIMDE_FLOAT32_C(  -315.92), SIMDE_FLOAT32_C(  -968.83), SIMDE_FLOAT32_C(   976.63), SIMDE_FLOAT32_C(   106.67) },
      {      SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(  -483.58), SIMDE_FLOAT32_C(    91.58), SIMDE_FLOAT32_C(  -501.75) },
       INT32_C(         131),
       INT32_C(           4),
      {      SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(  -968.83), SIMDE_FLOAT32_C(   976.63), SIMDE_FLOAT32_C(   106.67) } },
    { { SIMDE_FLOAT32_C(   709.22), SIMDE_FLOAT32_C(  -852.46), SIMDE_FLOAT32_C(   318.46), SIMDE_FLOAT32_C(   980.46) },
      {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(  -335.06), SIMDE_FLOAT32_C(  -155.61), SIMDE_FLOAT32_C(  -166.44) },
       INT32_C(         132),
       INT32_C(           8),
      {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(  -852.46), SIMDE_FLOAT32_C(   318.46), SIMDE_FLOAT32_C(   980.46) } },
    { { SIMDE_FLOAT32_C(   -70.75), SIMDE_FLOAT32_C(   305.87), SIMDE_FLOAT32_C(   721.59), SIMDE_FLOAT32_C(  -933.87) },
      {     -SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(   670.79), SIMDE_FLOAT32_C(  -249.78), SIMDE_FLOAT32_C(  -835.03) },
       INT32_C(         160),
       INT32_C(           8),
      {     -SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(   305.87), SIMDE_FLOAT32_C(   721.59), SIMDE_FLOAT32_C(  -933.87) } },
    { { SIMDE_FLOAT32_C(  -442.39), SIMDE_FLOAT32_C(  -351.39), SIMDE_FLOAT32_C(   220.31), SIMDE_FLOAT32_C(   987.17) },
      {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(  -175.80), SIMDE_FLOAT32_C(   696.40), SIMDE_FLOAT32_C(  -826.66) },
       INT32_C(          65),
       INT32_C(           8),
      {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(  -351.39), SIMDE_FLOAT32_C(   220.31), SIMDE_FLOAT32_C(   987.17) } },
    { { SIMDE_FLOAT32_C(  -478.76), SIMDE_FLOAT32_C(  -600.03), SIMDE_FLOAT32_C(  -673.80), SIMDE_FLOAT32_C(     8.09) },
      { SIMDE_FLOAT32_C(  -321.46), SIMDE_FLOAT32_C(   103.77), SIMDE_FLOAT32_C(   937.35), SIMDE_FLOAT32_C(   984.41) },
       INT32_C(         146),
       INT32_C(           8),
      { SIMDE_FLOAT32_C(  -321.46), SIMDE_FLOAT32_C(  -600.03), SIMDE_FLOAT32_C(  -673.80), SIMDE_FLOAT32_C(     8.09) } },
  };

  simde__m128 a, b, r;

  a = simde_mm_loadu_ps(test_vec[0].a);
  b = simde_mm_loadu_ps(test_vec[0].b);
  r = simde_mm_roundscale_round_ss(a, b, INT32_C(          48), INT32_C(           8));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[0].r), 1);

  a = simde_mm_loadu_ps(test_vec[1].a);
  b = simde_mm_loadu_ps(test_vec[1].b);
  r = simde_mm_roundscale_round_ss(a, b, INT32_C(          33), INT32_C(           8));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[1].r), 1);

  a = simde_mm_loadu_ps(test_vec[2].a);
  b = simde_mm_loadu_ps(test_vec[2].b);
  r = simde_mm_roundscale_round_ss(a, b, INT32_C(          98), INT32_C(           4));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[2].r), 1);

  a = simde_mm_loadu_ps(test_vec[3].a);
  b = simde_mm_loadu_ps(test_vec[3].b);
  r = simde_mm_roundscale_round_ss(a, b, INT32_C(         131), INT32_C(           4));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[3].r), 1);

  a = simde_mm_loadu_ps(test_vec[4].a);
  b = simde_mm_loadu_ps(test_vec[4].b);
  r = simde_mm_roundscale_round_ss(a, b, INT32_C(         132), INT32_C(           8));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[4].r), 1);

  a = simde_mm_loadu_ps(test_vec[5].a);
  b = simde_mm_loadu_ps(test_vec[5].b);
  r = simde_mm_roundscale_round_ss(a, b, INT32_C(         160), INT32_C(           8));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[5].r), 1);

  a = simde_mm_loadu_ps(test_vec[6].a);
  b = simde_mm_loadu_ps(test_vec[6].b);
  r = simde_mm_roundscale_round_ss(a, b, INT32_C(          65), INT32_C(           8));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[6].r), 1);

  a = simde_mm_loadu_ps(test_vec[7].a);
  b = simde_mm_loadu_ps(test_vec[7].b);
  r = simde_mm_roundscale_round_ss(a, b, INT32_C(         146), INT32_C(           8));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[7].r), 1);

  return 0;
#else
  fputc('\n', stdout);
  int round_type[5] = {SIMDE_MM_FROUND_TO_NEAREST_INT, SIMDE_MM_FROUND_TO_NEG_INF, SIMDE_MM_FROUND_TO_POS_INF, SIMDE_MM_FROUND_TO_ZERO, SIMDE_MM_FROUND_CUR_DIRECTION};
  for (int i = 0 ; i < 8 ; i++) {
    simde__m128 a = simde_test_x86_random_f32x4(SIMDE_FLOAT32_C(-1000.0), SIMDE_FLOAT32_C(1000.0));
    simde__m128 b = simde_test_x86_random_f32x4(SIMDE_FLOAT32_C(-1000.0), SIMDE_FLOAT32_C(1000.0));
    if((simde_test_codegen_rand() & 1)) {
      if((simde_test_codegen_rand() & 1))
        b = simde_mm_mask_mov_ps(b, 1, simde_mm_set1_ps(SIMDE_MATH_NAN));
      else {
        if((simde_test_codegen_rand() & 1))
          b = simde_mm_mask_mov_ps(b, 1, simde_mm_set1_ps(SIMDE_MATH_INFINITY));
        else
          b = simde_mm_mask_mov_ps(b, 1, simde_mm_set1_ps(-SIMDE_MATH_INFINITY));
      }
    }
    int imm8 = (((simde_test_codegen_rand() & 15) << 4) | round_type[i % 5]) & 255;
    int sae = (simde_test_codegen_rand() & 1) ? SIMDE_MM_FROUND_CUR_DIRECTION : SIMDE_MM_FROUND_NO_EXC;
    simde__m128 r;
    SIMDE_CONSTIFY_256_NEW(simde_mm_roundscale_round_ss, r, simde_mm_setzero_ps(), imm8, sae, a, b);

    simde_test_x86_write_f32x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_f32x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i32(2, imm8, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i32(2, sae, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_f32x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm_mask_roundscale_round_ss (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const simde_float32 src[4];
    const simde__mmask8 k;
    const simde_float32 a[4];
    const simde_float32 b[4];
    const int32_t imm8;
    const int32_t sae;
    const simde_float32 r[4];
  } test_vec[] = {
    { { SIMDE_FLOAT32_C(  -901.37), SIMDE_FLOAT32_C(   991.78), SIMDE_FLOAT32_C(  -993.88), SIMDE_FLOAT32_C(   421.48) },
      UINT8_C(125),
      { SIMDE_FLOAT32_C(   705.11), SIMDE_FLOAT32_C(  -569.84), SIMDE_FLOAT32_C(  -299.64), SIMDE_FLOAT32_C(  -705.39) },
      { SIMDE_FLOAT32_C(   431.44), SIMDE_FLOAT32_C(   682.16), SIMDE_FLOAT32_C(   342.34), SIMDE_FLOAT32_C(  -645.40) },
       INT32_C(         160),
       INT32_C(           4),
      { SIMDE_FLOAT32_C(   431.44), SIMDE_FLOAT32_C(  -569.84), SIMDE_FLOAT32_C(  -299.64), SIMDE_FLOAT32_C(  -705.39) } },
    { { SIMDE_FLOAT32_C(   935.70), SIMDE_FLOAT32_C(   772.61), SIMDE_FLOAT32_C(  -364.40), SIMDE_FLOAT32_C(   382.32) },
      UINT8_C(218),
      { SIMDE_FLOAT32_C(   -42.14), SIMDE_FLOAT32_C(   962.15), SIMDE_FLOAT32_C(   558.00), SIMDE_FLOAT32_C(   190.11) },
      {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(   104.40), SIMDE_FLOAT32_C(   182.55), SIMDE_FLOAT32_C(   334.92) },
       INT32_C(          33),
       INT32_C(           4),
      { SIMDE_FLOAT32_C(   935.70), SIMDE_FLOAT32_C(   962.15), SIMDE_FLOAT32_C(   558.00), SIMDE_FLOAT32_C(   190.11) } },
    { { SIMDE_FLOAT32_C(    53.35), SIMDE_FLOAT32_C(  -144.97), SIMDE_FLOAT32_C(   718.45), SIMDE_FLOAT32_C(  -241.54) },
      UINT8_C(243),
      { SIMDE_FLOAT32_C(  -581.19), SIMDE_FLOAT32_C(    53.08), SIMDE_FLOAT32_C(  -283.38), SIMDE_FLOAT32_C(  -899.03) },
      { SIMDE_FLOAT32_C(  -604.58), SIMDE_FLOAT32_C(    71.23), SIMDE_FLOAT32_C(   989.92), SIMDE_FLOAT32_C(  -662.30) },
       INT32_C(          66),
       INT32_C(           8),
      { SIMDE_FLOAT32_C(  -604.56), SIMDE_FLOAT32_C(    53.08), SIMDE_FLOAT32_C(  -283.38), SIMDE_FLOAT32_C(  -899.03) } },
    { { SIMDE_FLOAT32_C(  -529.80), SIMDE_FLOAT32_C(   307.93), SIMDE_FLOAT32_C(  -992.43), SIMDE_FLOAT32_C(   428.06) },
      UINT8_C( 78),
      { SIMDE_FLOAT32_C(   565.57), SIMDE_FLOAT32_C(  -381.83), SIMDE_FLOAT32_C(     4.93), SIMDE_FLOAT32_C(  -330.03) },
      { SIMDE_FLOAT32_C(   800.71), SIMDE_FLOAT32_C(  -660.15), SIMDE_FLOAT32_C(  -384.42), SIMDE_FLOAT32_C(  -152.05) },
       INT32_C(         211),
       INT32_C(           4),
      { SIMDE_FLOAT32_C(  -529.80), SIMDE_FLOAT32_C(  -381.83), SIMDE_FLOAT32_C(     4.93), SIMDE_FLOAT32_C(  -330.03) } },
    { { SIMDE_FLOAT32_C(  -371.56), SIMDE_FLOAT32_C(  -728.57), SIMDE_FLOAT32_C(  -340.23), SIMDE_FLOAT32_C(   913.62) },
      UINT8_C( 96),
      { SIMDE_FLOAT32_C(   712.85), SIMDE_FLOAT32_C(  -369.75), SIMDE_FLOAT32_C(  -208.79), SIMDE_FLOAT32_C(  -891.73) },
      {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(  -218.88), SIMDE_FLOAT32_C(  -554.03), SIMDE_FLOAT32_C(   536.07) },
       INT32_C(         116),
       INT32_C(           8),
      { SIMDE_FLOAT32_C(  -371.56), SIMDE_FLOAT32_C(  -369.75), SIMDE_FLOAT32_C(  -208.79), SIMDE_FLOAT32_C(  -891.73) } },
    { { SIMDE_FLOAT32_C(  -436.15), SIMDE_FLOAT32_C(   434.32), SIMDE_FLOAT32_C(   284.76), SIMDE_FLOAT32_C(  -870.58) },
      UINT8_C( 55),
      { SIMDE_FLOAT32_C(  -710.31), SIMDE_FLOAT32_C(  -200.61), SIMDE_FLOAT32_C(   853.20), SIMDE_FLOAT32_C(  -370.45) },
      { SIMDE_FLOAT32_C(   414.97), SIMDE_FLOAT32_C(  -298.84), SIMDE_FLOAT32_C(  -597.05), SIMDE_FLOAT32_C(   967.94) },
       INT32_C(           0),
       INT32_C(           4),
      { SIMDE_FLOAT32_C(   415.00), SIMDE_FLOAT32_C(  -200.61), SIMDE_FLOAT32_C(   853.20), SIMDE_FLOAT32_C(  -370.45) } },
    { { SIMDE_FLOAT32_C(   262.23), SIMDE_FLOAT32_C(   -54.99), SIMDE_FLOAT32_C(   -70.40), SIMDE_FLOAT32_C(   -24.92) },
      UINT8_C(133),
      { SIMDE_FLOAT32_C(   720.81), SIMDE_FLOAT32_C(    83.35), SIMDE_FLOAT32_C(   276.74), SIMDE_FLOAT32_C(  -498.07) },
      {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(  -187.19), SIMDE_FLOAT32_C(   208.67), SIMDE_FLOAT32_C(  -914.41) },
       INT32_C(         113),
       INT32_C(           4),
      {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(    83.35), SIMDE_FLOAT32_C(   276.74), SIMDE_FLOAT32_C(  -498.07) } },
    { { SIMDE_FLOAT32_C(  -491.89), SIMDE_FLOAT32_C(  -221.14), SIMDE_FLOAT32_C(  -694.11), SIMDE_FLOAT32_C(  -202.20) },
      UINT8_C( 29),
      { SIMDE_FLOAT32_C(  -840.90), SIMDE_FLOAT32_C(   427.35), SIMDE_FLOAT32_C(    -6.78), SIMDE_FLOAT32_C(  -139.75) },
      { SIMDE_FLOAT32_C(   830.30), SIMDE_FLOAT32_C(   -38.84), SIMDE_FLOAT32_C(   462.72), SIMDE_FLOAT32_C(  -138.30) },
       INT32_C(         114),
       INT32_C(           8),
      { SIMDE_FLOAT32_C(   830.30), SIMDE_FLOAT32_C(   427.35), SIMDE_FLOAT32_C(    -6.78), SIMDE_FLOAT32_C(  -139.75) } },
  };

  simde__m128 src, a, b, r;

  src = simde_mm_loadu_ps(test_vec[0].src);
  a = simde_mm_loadu_ps(test_vec[0].a);
  b = simde_mm_loadu_ps(test_vec[0].b);
  r = simde_mm_mask_roundscale_round_ss(src, test_vec[0].k, a, b, INT32_C(         160), INT32_C(           4));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[0].r), 1);

  src = simde_mm_loadu_ps(test_vec[1].src);
  a = simde_mm_loadu_ps(test_vec[1].a);
  b = simde_mm_loadu_ps(test_vec[1].b);
  r = simde_mm_mask_roundscale_round_ss(src, test_vec[1].k, a, b, INT32_C(          33), INT32_C(           4));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[1].r), 1);

  src = simde_mm_loadu_ps(test_vec[2].src);
  a = simde_mm_loadu_ps(test_vec[2].a);
  b = simde_mm_loadu_ps(test_vec[2].b);
  r = simde_mm_mask_roundscale_round_ss(src, test_vec[2].k, a, b, INT32_C(          66), INT32_C(           8));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[2].r), 1);

  src = simde_mm_loadu_ps(test_vec[3].src);
  a = simde_mm_loadu_ps(test_vec[3].a);
  b = simde_mm_loadu_ps(test_vec[3].b);
  r = simde_mm_mask_roundscale_round_ss(src, test_vec[3].k, a, b, INT32_C(         211), INT32_C(           4));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[3].r), 1);

  src = simde_mm_loadu_ps(test_vec[4].src);
  a = simde_mm_loadu_ps(test_vec[4].a);
  b = simde_mm_loadu_ps(test_vec[4].b);
  r = simde_mm_mask_roundscale_round_ss(src, test_vec[4].k, a, b, INT32_C(         116), INT32_C(           8));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[4].r), 1);

  src = simde_mm_loadu_ps(test_vec[5].src);
  a = simde_mm_loadu_ps(test_vec[5].a);
  b = simde_mm_loadu_ps(test_vec[5].b);
  r = simde_mm_mask_roundscale_round_ss(src, test_vec[5].k, a, b, INT32_C(           0), INT32_C(           4));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[5].r), 1);

  src = simde_mm_loadu_ps(test_vec[6].src);
  a = simde_mm_loadu_ps(test_vec[6].a);
  b = simde_mm_loadu_ps(test_vec[6].b);
  r = simde_mm_mask_roundscale_round_ss(src, test_vec[6].k, a, b, INT32_C(         113), INT32_C(           4));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[6].r), 1);

  src = simde_mm_loadu_ps(test_vec[7].src);
  a = simde_mm_loadu_ps(test_vec[7].a);
  b = simde_mm_loadu_ps(test_vec[7].b);
  r = simde_mm_mask_roundscale_round_ss(src, test_vec[7].k, a, b, INT32_C(         114), INT32_C(           8));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[7].r), 1);

  return 0;
#else
  fputc('\n', stdout);
  int round_type[5] = {SIMDE_MM_FROUND_TO_NEAREST_INT, SIMDE_MM_FROUND_TO_NEG_INF, SIMDE_MM_FROUND_TO_POS_INF, SIMDE_MM_FROUND_TO_ZERO, SIMDE_MM_FROUND_CUR_DIRECTION};
  for (int i = 0 ; i < 8 ; i++) {
    simde__m128 src = simde_test_x86_random_f32x4(SIMDE_FLOAT32_C(-1000.0), SIMDE_FLOAT32_C(1000.0));
    simde__mmask8 k = simde_test_x86_random_mmask8();
    simde__m128 a = simde_test_x86_random_f32x4(SIMDE_FLOAT32_C(-1000.0), SIMDE_FLOAT32_C(1000.0));
    simde__m128 b = simde_test_x86_random_f32x4(SIMDE_FLOAT32_C(-1000.0), SIMDE_FLOAT32_C(1000.0));
    if((simde_test_codegen_rand() & 1)) {
      if((simde_test_codegen_rand() & 1))
        b = simde_mm_mask_mov_ps(b, 1, simde_mm_set1_ps(SIMDE_MATH_NAN));
      else {
        if((simde_test_codegen_rand() & 1))
          b = simde_mm_mask_mov_ps(b, 1, simde_mm_set1_ps(SIMDE_MATH_INFINITY));
        else
          b = simde_mm_mask_mov_ps(b, 1, simde_mm_set1_ps(-SIMDE_MATH_INFINITY));
      }
    }
    int imm8 = (((simde_test_codegen_rand() & 15) << 4) | round_type[i % 5]) & 255;
    int sae = (simde_test_codegen_rand() & 1) ? SIMDE_MM_FROUND_CUR_DIRECTION : SIMDE_MM_FROUND_NO_EXC;
    simde__m128 r;
    SIMDE_CONSTIFY_256_NEW(simde_mm_mask_roundscale_round_ss, r, simde_mm_setzero_ps(), imm8, sae, src, k, a, b);

    simde_test_x86_write_f32x4(2, src, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_mmask8(2, k, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_f32x4(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_f32x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i32(2, imm8, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i32(2, sae, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_f32x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm_maskz_roundscale_round_ss (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const simde__mmask8 k;
    const simde_float32 a[4];
    const simde_float32 b[4];
    const int32_t imm8;
    const int32_t sae;
    const simde_float32 r[4];
  } test_vec[] = {
    { UINT8_C(128),
      { SIMDE_FLOAT32_C(   700.03), SIMDE_FLOAT32_C(   381.97), SIMDE_FLOAT32_C(   850.94), SIMDE_FLOAT32_C(  -216.62) },
      {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(  -647.13), SIMDE_FLOAT32_C(  -687.31), SIMDE_FLOAT32_C(   471.52) },
       INT32_C(           0),
       INT32_C(           8),
      { SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(   381.97), SIMDE_FLOAT32_C(   850.94), SIMDE_FLOAT32_C(  -216.62) } },
    { UINT8_C( 36),
      { SIMDE_FLOAT32_C(  -456.00), SIMDE_FLOAT32_C(   293.00), SIMDE_FLOAT32_C(   826.59), SIMDE_FLOAT32_C(  -150.11) },
      {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(   404.84), SIMDE_FLOAT32_C(     8.98), SIMDE_FLOAT32_C(   518.15) },
       INT32_C(          97),
       INT32_C(           4),
      { SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(   293.00), SIMDE_FLOAT32_C(   826.59), SIMDE_FLOAT32_C(  -150.11) } },
    { UINT8_C( 80),
      { SIMDE_FLOAT32_C(  -789.85), SIMDE_FLOAT32_C(  -440.26), SIMDE_FLOAT32_C(  -943.10), SIMDE_FLOAT32_C(  -983.14) },
      { SIMDE_FLOAT32_C(  -310.13), SIMDE_FLOAT32_C(   756.93), SIMDE_FLOAT32_C(   398.83), SIMDE_FLOAT32_C(  -459.18) },
       INT32_C(           2),
       INT32_C(           4),
      { SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(  -440.26), SIMDE_FLOAT32_C(  -943.10), SIMDE_FLOAT32_C(  -983.14) } },
    { UINT8_C(  2),
      { SIMDE_FLOAT32_C(   529.06), SIMDE_FLOAT32_C(  -544.76), SIMDE_FLOAT32_C(   251.28), SIMDE_FLOAT32_C(   819.65) },
      { SIMDE_FLOAT32_C(   240.13), SIMDE_FLOAT32_C(  -700.99), SIMDE_FLOAT32_C(  -636.35), SIMDE_FLOAT32_C(  -466.87) },
       INT32_C(          83),
       INT32_C(           8),
      { SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(  -544.76), SIMDE_FLOAT32_C(   251.28), SIMDE_FLOAT32_C(   819.65) } },
    { UINT8_C(253),
      { SIMDE_FLOAT32_C(  -777.48), SIMDE_FLOAT32_C(  -857.91), SIMDE_FLOAT32_C(   928.50), SIMDE_FLOAT32_C(  -908.25) },
      {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(   287.72), SIMDE_FLOAT32_C(   423.71), SIMDE_FLOAT32_C(   700.70) },
       INT32_C(         180),
       INT32_C(           8),
      {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(  -857.91), SIMDE_FLOAT32_C(   928.50), SIMDE_FLOAT32_C(  -908.25) } },
    { UINT8_C(193),
      { SIMDE_FLOAT32_C(   116.39), SIMDE_FLOAT32_C(    78.15), SIMDE_FLOAT32_C(   777.83), SIMDE_FLOAT32_C(   173.93) },
      {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(  -369.17), SIMDE_FLOAT32_C(  -297.02), SIMDE_FLOAT32_C(  -572.92) },
       INT32_C(         128),
       INT32_C(           4),
      {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(    78.15), SIMDE_FLOAT32_C(   777.83), SIMDE_FLOAT32_C(   173.93) } },
    { UINT8_C(155),
      { SIMDE_FLOAT32_C(  -799.66), SIMDE_FLOAT32_C(  -693.28), SIMDE_FLOAT32_C(  -900.19), SIMDE_FLOAT32_C(  -175.72) },
      { SIMDE_FLOAT32_C(   837.16), SIMDE_FLOAT32_C(  -677.67), SIMDE_FLOAT32_C(   -33.63), SIMDE_FLOAT32_C(   765.66) },
       INT32_C(         241),
       INT32_C(           8),
      { SIMDE_FLOAT32_C(   837.16), SIMDE_FLOAT32_C(  -693.28), SIMDE_FLOAT32_C(  -900.19), SIMDE_FLOAT32_C(  -175.72) } },
    { UINT8_C( 22),
      { SIMDE_FLOAT32_C(  -842.39), SIMDE_FLOAT32_C(   -99.15), SIMDE_FLOAT32_C(   318.40), SIMDE_FLOAT32_C(   875.17) },
      {      SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(  -444.07), SIMDE_FLOAT32_C(    -8.44), SIMDE_FLOAT32_C(  -483.66) },
       INT32_C(          50),
       INT32_C(           8),
      { SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(   -99.15), SIMDE_FLOAT32_C(   318.40), SIMDE_FLOAT32_C(   875.17) } },
  };

  simde__m128 a, b, r;

  a = simde_mm_loadu_ps(test_vec[0].a);
  b = simde_mm_loadu_ps(test_vec[0].b);
  r = simde_mm_maskz_roundscale_round_ss(test_vec[0].k, a, b, INT32_C(           0), INT32_C(           8));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[0].r), 1);

  a = simde_mm_loadu_ps(test_vec[1].a);
  b = simde_mm_loadu_ps(test_vec[1].b);
  r = simde_mm_maskz_roundscale_round_ss(test_vec[1].k, a, b, INT32_C(          97), INT32_C(           4));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[1].r), 1);

  a = simde_mm_loadu_ps(test_vec[2].a);
  b = simde_mm_loadu_ps(test_vec[2].b);
  r = simde_mm_maskz_roundscale_round_ss(test_vec[2].k, a, b, INT32_C(           2), INT32_C(           4));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[2].r), 1);

  a = simde_mm_loadu_ps(test_vec[3].a);
  b = simde_mm_loadu_ps(test_vec[3].b);
  r = simde_mm_maskz_roundscale_round_ss(test_vec[3].k, a, b, INT32_C(          83), INT32_C(           8));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[3].r), 1);

  a = simde_mm_loadu_ps(test_vec[4].a);
  b = simde_mm_loadu_ps(test_vec[4].b);
  r = simde_mm_maskz_roundscale_round_ss(test_vec[4].k, a, b, INT32_C(         180), INT32_C(           8));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[4].r), 1);

  a = simde_mm_loadu_ps(test_vec[5].a);
  b = simde_mm_loadu_ps(test_vec[5].b);
  r = simde_mm_maskz_roundscale_round_ss(test_vec[5].k, a, b, INT32_C(         128), INT32_C(           4));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[5].r), 1);

  a = simde_mm_loadu_ps(test_vec[6].a);
  b = simde_mm_loadu_ps(test_vec[6].b);
  r = simde_mm_maskz_roundscale_round_ss(test_vec[6].k, a, b, INT32_C(         241), INT32_C(           8));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[6].r), 1);

  a = simde_mm_loadu_ps(test_vec[7].a);
  b = simde_mm_loadu_ps(test_vec[7].b);
  r = simde_mm_maskz_roundscale_round_ss(test_vec[7].k, a, b, INT32_C(          50), INT32_C(           8));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[7].r), 1);

  return 0;
#else
  fputc('\n', stdout);
  int round_type[5] = {SIMDE_MM_FROUND_TO_NEAREST_INT, SIMDE_MM_FROUND_TO_NEG_INF, SIMDE_MM_FROUND_TO_POS_INF, SIMDE_MM_FROUND_TO_ZERO, SIMDE_MM_FROUND_CUR_DIRECTION};
  for (int i = 0 ; i < 8 ; i++) {
    simde__mmask8 k = simde_test_x86_random_mmask8();
    simde__m128 a = simde_test_x86_random_f32x4(SIMDE_FLOAT32_C(-1000.0), SIMDE_FLOAT32_C(1000.0));
    simde__m128 b = simde_test_x86_random_f32x4(SIMDE_FLOAT32_C(-1000.0), SIMDE_FLOAT32_C(1000.0));
    if((simde_test_codegen_rand() & 1)) {
      if((simde_test_codegen_rand() & 1))
        b = simde_mm_mask_mov_ps(b, 1, simde_mm_set1_ps(SIMDE_MATH_NAN));
      else {
        if((simde_test_codegen_rand() & 1))
          b = simde_mm_mask_mov_ps(b, 1, simde_mm_set1_ps(SIMDE_MATH_INFINITY));
        else
          b = simde_mm_mask_mov_ps(b, 1, simde_mm_set1_ps(-SIMDE_MATH_INFINITY));
      }
    }
    int imm8 = (((simde_test_codegen_rand() & 15) << 4) | round_type[i % 5]) & 255;
    int sae = (simde_test_codegen_rand() & 1) ? SIMDE_MM_FROUND_CUR_DIRECTION : SIMDE_MM_FROUND_NO_EXC;
    simde__m128 r;
    SIMDE_CONSTIFY_256_NEW(simde_mm_maskz_roundscale_round_ss, r, simde_mm_setzero_ps(), imm8, sae, k, a, b);

    simde_test_x86_write_mmask8(2, k, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_f32x4(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_f32x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i32(2, imm8, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i32(2, sae, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_f32x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm_roundscale_sd (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const simde_float64 a[2];
    const simde_float64 b[2];
    const int32_t imm8;
    const simde_float64 r[2];
  } test_vec[] = {
    { { SIMDE_FLOAT64_C(   538.74), SIMDE_FLOAT64_C(    64.09) },
      { SIMDE_FLOAT64_C(   791.27), SIMDE_FLOAT64_C(  -766.95) },
       INT32_C(           0),
      { SIMDE_FLOAT64_C(   791.00), SIMDE_FLOAT64_C(    64.09) } },
    { { SIMDE_FLOAT64_C(  -678.97), SIMDE_FLOAT64_C(    39.26) },
      { SIMDE_FLOAT64_C(  -965.12), SIMDE_FLOAT64_C(   198.74) },
       INT32_C(          16),
      { SIMDE_FLOAT64_C(  -965.00), SIMDE_FLOAT64_C(    39.26) } },
    { { SIMDE_FLOAT64_C(   569.29), SIMDE_FLOAT64_C(   -63.11) },
      {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(   227.96) },
       INT32_C(          32),
      {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(   -63.11) } },
    { { SIMDE_FLOAT64_C(   570.63), SIMDE_FLOAT64_C(  -299.33) },
      {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(   106.40) },
       INT32_C(          48),
      {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(  -299.33) } },
    { { SIMDE_FLOAT64_C(   206.46), SIMDE_FLOAT64_C(  -483.51) },
      { SIMDE_FLOAT64_C(  -173.23), SIMDE_FLOAT64_C(   300.40) },
       INT32_C(          64),
      { SIMDE_FLOAT64_C(  -173.25), SIMDE_FLOAT64_C(  -483.51) } },
    { { SIMDE_FLOAT64_C(   -29.64), SIMDE_FLOAT64_C(    87.23) },
      { SIMDE_FLOAT64_C(    38.91), SIMDE_FLOAT64_C(  -744.22) },
       INT32_C(          80),
      { SIMDE_FLOAT64_C(    38.91), SIMDE_FLOAT64_C(    87.23) } },
    { { SIMDE_FLOAT64_C(  -897.00), SIMDE_FLOAT64_C(  -952.95) },
      {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(  -896.36) },
       INT32_C(          96),
      {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(  -952.95) } },
    { { SIMDE_FLOAT64_C(  -861.49), SIMDE_FLOAT64_C(   566.82) },
      {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(   707.81) },
       INT32_C(         112),
      {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(   566.82) } },
    { { SIMDE_FLOAT64_C(   -64.23), SIMDE_FLOAT64_C(   759.82) },
      {        SIMDE_MATH_INFINITY, SIMDE_FLOAT64_C(  -493.60) },
       INT32_C(         128),
      {        SIMDE_MATH_INFINITY, SIMDE_FLOAT64_C(   759.82) } },
    { { SIMDE_FLOAT64_C(   -48.69), SIMDE_FLOAT64_C(  -284.86) },
      { SIMDE_FLOAT64_C(  -180.74), SIMDE_FLOAT64_C(   467.80) },
       INT32_C(         144),
      { SIMDE_FLOAT64_C(  -180.74), SIMDE_FLOAT64_C(  -284.86) } },
    { { SIMDE_FLOAT64_C(  -880.34), SIMDE_FLOAT64_C(  -225.76) },
      { SIMDE_FLOAT64_C(  -487.74), SIMDE_FLOAT64_C(   206.89) },
       INT32_C(         160),
      { SIMDE_FLOAT64_C(  -487.74), SIMDE_FLOAT64_C(  -225.76) } },
    { { SIMDE_FLOAT64_C(  -231.96), SIMDE_FLOAT64_C(   832.86) },
      { SIMDE_FLOAT64_C(   916.15), SIMDE_FLOAT64_C(  -184.91) },
       INT32_C(         176),
      { SIMDE_FLOAT64_C(   916.15), SIMDE_FLOAT64_C(   832.86) } },
    { { SIMDE_FLOAT64_C(  -980.22), SIMDE_FLOAT64_C(   183.17) },
      { SIMDE_FLOAT64_C(  -409.84), SIMDE_FLOAT64_C(  -841.70) },
       INT32_C(         192),
      { SIMDE_FLOAT64_C(  -409.84), SIMDE_FLOAT64_C(   183.17) } },
    { { SIMDE_FLOAT64_C(   300.74), SIMDE_FLOAT64_C(   866.11) },
      { SIMDE_FLOAT64_C(   253.70), SIMDE_FLOAT64_C(  -117.14) },
       INT32_C(         208),
      { SIMDE_FLOAT64_C(   253.70), SIMDE_FLOAT64_C(   866.11) } },
    { { SIMDE_FLOAT64_C(    13.51), SIMDE_FLOAT64_C(  -600.29) },
      { SIMDE_FLOAT64_C(   308.28), SIMDE_FLOAT64_C(   474.00) },
       INT32_C(         224),
      { SIMDE_FLOAT64_C(   308.28), SIMDE_FLOAT64_C(  -600.29) } },
    { { SIMDE_FLOAT64_C(   -78.92), SIMDE_FLOAT64_C(  -574.69) },
      { SIMDE_FLOAT64_C(   327.13), SIMDE_FLOAT64_C(   740.34) },
       INT32_C(         240),
      { SIMDE_FLOAT64_C(   327.13), SIMDE_FLOAT64_C(  -574.69) } },
    { { SIMDE_FLOAT64_C(  -130.97), SIMDE_FLOAT64_C(   860.00) },
      { SIMDE_FLOAT64_C(  -332.65), SIMDE_FLOAT64_C(   381.30) },
       INT32_C(           1),
      { SIMDE_FLOAT64_C(  -333.00), SIMDE_FLOAT64_C(   860.00) } },
    { { SIMDE_FLOAT64_C(  -519.50), SIMDE_FLOAT64_C(  -850.66) },
      {        SIMDE_MATH_INFINITY, SIMDE_FLOAT64_C(  -603.35) },
       INT32_C(          17),
      {        SIMDE_MATH_INFINITY, SIMDE_FLOAT64_C(  -850.66) } },
    { { SIMDE_FLOAT64_C(  -852.40), SIMDE_FLOAT64_C(  -818.22) },
      { SIMDE_FLOAT64_C(  -425.27), SIMDE_FLOAT64_C(  -102.41) },
       INT32_C(          33),
      { SIMDE_FLOAT64_C(  -425.50), SIMDE_FLOAT64_C(  -818.22) } },
    { { SIMDE_FLOAT64_C(  -559.16), SIMDE_FLOAT64_C(  -848.72) },
      {        SIMDE_MATH_INFINITY, SIMDE_FLOAT64_C(   242.72) },
       INT32_C(          49),
      {        SIMDE_MATH_INFINITY, SIMDE_FLOAT64_C(  -848.72) } },
    { { SIMDE_FLOAT64_C(  -361.20), SIMDE_FLOAT64_C(   377.06) },
      {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(    64.10) },
       INT32_C(          65),
      {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(   377.06) } },
    { { SIMDE_FLOAT64_C(   -42.79), SIMDE_FLOAT64_C(   573.22) },
      { SIMDE_FLOAT64_C(    72.42), SIMDE_FLOAT64_C(   624.56) },
       INT32_C(          81),
      { SIMDE_FLOAT64_C(    72.41), SIMDE_FLOAT64_C(   573.22) } },
    { { SIMDE_FLOAT64_C(  -860.70), SIMDE_FLOAT64_C(  -894.95) },
      { SIMDE_FLOAT64_C(   103.87), SIMDE_FLOAT64_C(    39.04) },
       INT32_C(          97),
      { SIMDE_FLOAT64_C(   103.86), SIMDE_FLOAT64_C(  -894.95) } },
    { { SIMDE_FLOAT64_C(  -931.70), SIMDE_FLOAT64_C(  -369.34) },
      {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(  -784.10) },
       INT32_C(         113),
      {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(  -369.34) } },
    { { SIMDE_FLOAT64_C(   113.49), SIMDE_FLOAT64_C(  -705.05) },
      { SIMDE_FLOAT64_C(   933.70), SIMDE_FLOAT64_C(   264.77) },
       INT32_C(         129),
      { SIMDE_FLOAT64_C(   933.70), SIMDE_FLOAT64_C(  -705.05) } },
    { { SIMDE_FLOAT64_C(   176.42), SIMDE_FLOAT64_C(  -570.43) },
      {        SIMDE_MATH_INFINITY, SIMDE_FLOAT64_C(   727.42) },
       INT32_C(         145),
      {        SIMDE_MATH_INFINITY, SIMDE_FLOAT64_C(  -570.43) } },
    { { SIMDE_FLOAT64_C(  -867.53), SIMDE_FLOAT64_C(   506.64) },
      {        SIMDE_MATH_INFINITY, SIMDE_FLOAT64_C(    89.68) },
       INT32_C(         161),
      {        SIMDE_MATH_INFINITY, SIMDE_FLOAT64_C(   506.64) } },
    { { SIMDE_FLOAT64_C(  -965.61), SIMDE_FLOAT64_C(   623.64) },
      { SIMDE_FLOAT64_C(  -180.71), SIMDE_FLOAT64_C(   138.25) },
       INT32_C(         177),
      { SIMDE_FLOAT64_C(  -180.71), SIMDE_FLOAT64_C(   623.64) } },
    { { SIMDE_FLOAT64_C(   320.99), SIMDE_FLOAT64_C(   206.55) },
      {       -SIMDE_MATH_INFINITY, SIMDE_FLOAT64_C(  -760.88) },
       INT32_C(         193),
      {       -SIMDE_MATH_INFINITY, SIMDE_FLOAT64_C(   206.55) } },
    { { SIMDE_FLOAT64_C(  -464.06), SIMDE_FLOAT64_C(  -599.26) },
      { SIMDE_FLOAT64_C(   665.68), SIMDE_FLOAT64_C(   800.71) },
       INT32_C(         209),
      { SIMDE_FLOAT64_C(   665.68), SIMDE_FLOAT64_C(  -599.26) } },
    { { SIMDE_FLOAT64_C(  -157.90), SIMDE_FLOAT64_C(  -769.73) },
      {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(  -430.48) },
       INT32_C(         225),
      {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(  -769.73) } },
    { { SIMDE_FLOAT64_C(   769.01), SIMDE_FLOAT64_C(   431.10) },
      { SIMDE_FLOAT64_C(  -204.44), SIMDE_FLOAT64_C(  -819.06) },
       INT32_C(         241),
      { SIMDE_FLOAT64_C(  -204.44), SIMDE_FLOAT64_C(   431.10) } },
    { { SIMDE_FLOAT64_C(   875.43), SIMDE_FLOAT64_C(   665.28) },
      { SIMDE_FLOAT64_C(   235.01), SIMDE_FLOAT64_C(   909.82) },
       INT32_C(           2),
      { SIMDE_FLOAT64_C(   236.00), SIMDE_FLOAT64_C(   665.28) } },
    { { SIMDE_FLOAT64_C(  -945.70), SIMDE_FLOAT64_C(    48.07) },
      {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(   375.29) },
       INT32_C(          18),
      {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(    48.07) } },
    { { SIMDE_FLOAT64_C(   614.41), SIMDE_FLOAT64_C(   677.07) },
      {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(   346.40) },
       INT32_C(          34),
      {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(   677.07) } },
    { { SIMDE_FLOAT64_C(    12.08), SIMDE_FLOAT64_C(  -986.28) },
      {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(   854.18) },
       INT32_C(          50),
      {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(  -986.28) } },
    { { SIMDE_FLOAT64_C(  -576.30), SIMDE_FLOAT64_C(   542.63) },
      {        SIMDE_MATH_INFINITY, SIMDE_FLOAT64_C(  -807.29) },
       INT32_C(          66),
      {        SIMDE_MATH_INFINITY, SIMDE_FLOAT64_C(   542.63) } },
    { { SIMDE_FLOAT64_C(   494.51), SIMDE_FLOAT64_C(   258.93) },
      {        SIMDE_MATH_INFINITY, SIMDE_FLOAT64_C(  -270.47) },
       INT32_C(          82),
      {        SIMDE_MATH_INFINITY, SIMDE_FLOAT64_C(   258.93) } },
    { { SIMDE_FLOAT64_C(  -783.18), SIMDE_FLOAT64_C(   279.46) },
      { SIMDE_FLOAT64_C(  -840.88), SIMDE_FLOAT64_C(  -528.57) },
       INT32_C(          98),
      { SIMDE_FLOAT64_C(  -840.88), SIMDE_FLOAT64_C(   279.46) } },
    { { SIMDE_FLOAT64_C(   773.53), SIMDE_FLOAT64_C(  -851.50) },
      {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(   119.93) },
       INT32_C(         114),
      {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(  -851.50) } },
    { { SIMDE_FLOAT64_C(  -867.99), SIMDE_FLOAT64_C(  -624.77) },
      { SIMDE_FLOAT64_C(  -560.77), SIMDE_FLOAT64_C(   986.19) },
       INT32_C(         130),
      { SIMDE_FLOAT64_C(  -560.77), SIMDE_FLOAT64_C(  -624.77) } },
    { { SIMDE_FLOAT64_C(   738.25), SIMDE_FLOAT64_C(  -590.11) },
      {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(  -673.81) },
       INT32_C(         146),
      {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(  -590.11) } },
    { { SIMDE_FLOAT64_C(   709.69), SIMDE_FLOAT64_C(   -23.76) },
      { SIMDE_FLOAT64_C(  -369.90), SIMDE_FLOAT64_C(   -31.38) },
       INT32_C(         162),
      { SIMDE_FLOAT64_C(  -369.90), SIMDE_FLOAT64_C(   -23.76) } },
    { { SIMDE_FLOAT64_C(   359.63), SIMDE_FLOAT64_C(  -862.63) },
      {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(  -856.54) },
       INT32_C(         178),
      {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(  -862.63) } },
    { { SIMDE_FLOAT64_C(  -697.42), SIMDE_FLOAT64_C(  -174.38) },
      { SIMDE_FLOAT64_C(  -853.10), SIMDE_FLOAT64_C(  -923.89) },
       INT32_C(         194),
      { SIMDE_FLOAT64_C(  -853.10), SIMDE_FLOAT64_C(  -174.38) } },
    { { SIMDE_FLOAT64_C(  -977.92), SIMDE_FLOAT64_C(   196.04) },
      {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(   648.75) },
       INT32_C(         210),
      {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(   196.04) } },
    { { SIMDE_FLOAT64_C(  -912.03), SIMDE_FLOAT64_C(   314.24) },
      { SIMDE_FLOAT64_C(  -669.90), SIMDE_FLOAT64_C(   826.22) },
       INT32_C(         226),
      { SIMDE_FLOAT64_C(  -669.90), SIMDE_FLOAT64_C(   314.24) } },
    { { SIMDE_FLOAT64_C(  -508.05), SIMDE_FLOAT64_C(  -847.60) },
      {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(   627.54) },
       INT32_C(         242),
      {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(  -847.60) } },
    { { SIMDE_FLOAT64_C(  -742.35), SIMDE_FLOAT64_C(  -169.29) },
      {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(   617.27) },
       INT32_C(           3),
      {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(  -169.29) } },
    { { SIMDE_FLOAT64_C(   760.73), SIMDE_FLOAT64_C(   322.27) },
      { SIMDE_FLOAT64_C(  -716.36), SIMDE_FLOAT64_C(  -936.69) },
       INT32_C(          19),
      { SIMDE_FLOAT64_C(  -716.00), SIMDE_FLOAT64_C(   322.27) } },
    { { SIMDE_FLOAT64_C(  -569.46), SIMDE_FLOAT64_C(  -860.58) },
      { SIMDE_FLOAT64_C(   122.02), SIMDE_FLOAT64_C(  -547.38) },
       INT32_C(          35),
      { SIMDE_FLOAT64_C(   122.00), SIMDE_FLOAT64_C(  -860.58) } },
    { { SIMDE_FLOAT64_C(  -542.33), SIMDE_FLOAT64_C(  -898.63) },
      {       -SIMDE_MATH_INFINITY, SIMDE_FLOAT64_C(  -831.46) },
       INT32_C(          51),
      {       -SIMDE_MATH_INFINITY, SIMDE_FLOAT64_C(  -898.63) } },
    { { SIMDE_FLOAT64_C(  -984.44), SIMDE_FLOAT64_C(   701.89) },
      {        SIMDE_MATH_INFINITY, SIMDE_FLOAT64_C(  -832.04) },
       INT32_C(          67),
      {        SIMDE_MATH_INFINITY, SIMDE_FLOAT64_C(   701.89) } },
    { { SIMDE_FLOAT64_C(   331.58), SIMDE_FLOAT64_C(  -124.22) },
      {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(   649.72) },
       INT32_C(          83),
      {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(  -124.22) } },
    { { SIMDE_FLOAT64_C(  -689.12), SIMDE_FLOAT64_C(  -746.21) },
      {       -SIMDE_MATH_INFINITY, SIMDE_FLOAT64_C(  -405.49) },
       INT32_C(          99),
      {       -SIMDE_MATH_INFINITY, SIMDE_FLOAT64_C(  -746.21) } },
    { { SIMDE_FLOAT64_C(  -543.48), SIMDE_FLOAT64_C(  -578.95) },
      { SIMDE_FLOAT64_C(   477.68), SIMDE_FLOAT64_C(   791.98) },
       INT32_C(         115),
      { SIMDE_FLOAT64_C(   477.68), SIMDE_FLOAT64_C(  -578.95) } },
    { { SIMDE_FLOAT64_C(   579.04), SIMDE_FLOAT64_C(  -544.50) },
      { SIMDE_FLOAT64_C(    47.25), SIMDE_FLOAT64_C(   768.38) },
       INT32_C(         131),
      { SIMDE_FLOAT64_C(    47.25), SIMDE_FLOAT64_C(  -544.50) } },
    { { SIMDE_FLOAT64_C(   545.89), SIMDE_FLOAT64_C(   783.94) },
      { SIMDE_FLOAT64_C(  -864.86), SIMDE_FLOAT64_C(  -463.52) },
       INT32_C(         147),
      { SIMDE_FLOAT64_C(  -864.86), SIMDE_FLOAT64_C(   783.94) } },
    { { SIMDE_FLOAT64_C(  -836.24), SIMDE_FLOAT64_C(   154.62) },
      { SIMDE_FLOAT64_C(   981.95), SIMDE_FLOAT64_C(   495.34) },
       INT32_C(         163),
      { SIMDE_FLOAT64_C(   981.95), SIMDE_FLOAT64_C(   154.62) } },
    { { SIMDE_FLOAT64_C(  -157.28), SIMDE_FLOAT64_C(   145.06) },
      {        SIMDE_MATH_INFINITY, SIMDE_FLOAT64_C(  -328.43) },
       INT32_C(         179),
      {        SIMDE_MATH_INFINITY, SIMDE_FLOAT64_C(   145.06) } },
    { { SIMDE_FLOAT64_C(  -949.55), SIMDE_FLOAT64_C(    94.34) },
      {       -SIMDE_MATH_INFINITY, SIMDE_FLOAT64_C(    75.50) },
       INT32_C(         195),
      {       -SIMDE_MATH_INFINITY, SIMDE_FLOAT64_C(    94.34) } },
    { { SIMDE_FLOAT64_C(   342.83), SIMDE_FLOAT64_C(  -578.52) },
      {       -SIMDE_MATH_INFINITY, SIMDE_FLOAT64_C(   798.33) },
       INT32_C(         211),
      {       -SIMDE_MATH_INFINITY, SIMDE_FLOAT64_C(  -578.52) } },
    { { SIMDE_FLOAT64_C(    14.63), SIMDE_FLOAT64_C(   684.54) },
      { SIMDE_FLOAT64_C(  -633.27), SIMDE_FLOAT64_C(   551.11) },
       INT32_C(         227),
      { SIMDE_FLOAT64_C(  -633.27), SIMDE_FLOAT64_C(   684.54) } },
    { { SIMDE_FLOAT64_C(  -469.52), SIMDE_FLOAT64_C(  -294.27) },
      {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(  -974.18) },
       INT32_C(         243),
      {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(  -294.27) } },
    { { SIMDE_FLOAT64_C(   170.88), SIMDE_FLOAT64_C(   259.59) },
      {        SIMDE_MATH_INFINITY, SIMDE_FLOAT64_C(  -373.19) },
       INT32_C(           4),
      {        SIMDE_MATH_INFINITY, SIMDE_FLOAT64_C(   259.59) } },
    { { SIMDE_FLOAT64_C(   131.17), SIMDE_FLOAT64_C(  -922.90) },
      { SIMDE_FLOAT64_C(   752.76), SIMDE_FLOAT64_C(  -317.98) },
       INT32_C(          20),
      { SIMDE_FLOAT64_C(   753.00), SIMDE_FLOAT64_C(  -922.90) } },
    { { SIMDE_FLOAT64_C(  -694.06), SIMDE_FLOAT64_C(  -975.15) },
      {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(  -561.84) },
       INT32_C(          36),
      {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(  -975.15) } },
    { { SIMDE_FLOAT64_C(  -661.24), SIMDE_FLOAT64_C(  -945.24) },
      {       -SIMDE_MATH_INFINITY, SIMDE_FLOAT64_C(  -976.70) },
       INT32_C(          52),
      {       -SIMDE_MATH_INFINITY, SIMDE_FLOAT64_C(  -945.24) } },
    { { SIMDE_FLOAT64_C(   -48.03), SIMDE_FLOAT64_C(  -218.45) },
      {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(   -22.20) },
       INT32_C(          68),
      {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(  -218.45) } },
    { { SIMDE_FLOAT64_C(  -851.32), SIMDE_FLOAT64_C(  -222.73) },
      { SIMDE_FLOAT64_C(  -128.10), SIMDE_FLOAT64_C(  -224.51) },
       INT32_C(          84),
      { SIMDE_FLOAT64_C(  -128.09), SIMDE_FLOAT64_C(  -222.73) } },
    { { SIMDE_FLOAT64_C(   827.27), SIMDE_FLOAT64_C(   452.75) },
      {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(   904.37) },
       INT32_C(         100),
      {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(   452.75) } },
    { { SIMDE_FLOAT64_C(   524.24), SIMDE_FLOAT64_C(   511.46) },
      { SIMDE_FLOAT64_C(  -347.86), SIMDE_FLOAT64_C(   565.59) },
       INT32_C(         116),
      { SIMDE_FLOAT64_C(  -347.86), SIMDE_FLOAT64_C(   511.46) } },
    { { SIMDE_FLOAT64_C(  -524.67), SIMDE_FLOAT64_C(    75.67) },
      {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(  -469.91) },
       INT32_C(         132),
      {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(    75.67) } },
    { { SIMDE_FLOAT64_C(   -48.42), SIMDE_FLOAT64_C(   676.20) },
      { SIMDE_FLOAT64_C(   971.42), SIMDE_FLOAT64_C(   903.55) },
       INT32_C(         148),
      { SIMDE_FLOAT64_C(   971.42), SIMDE_FLOAT64_C(   676.20) } },
    { { SIMDE_FLOAT64_C(   249.54), SIMDE_FLOAT64_C(  -118.65) },
      { SIMDE_FLOAT64_C(   975.42), SIMDE_FLOAT64_C(   -11.24) },
       INT32_C(         164),
      { SIMDE_FLOAT64_C(   975.42), SIMDE_FLOAT64_C(  -118.65) } },
    { { SIMDE_FLOAT64_C(  -247.31), SIMDE_FLOAT64_C(   860.66) },
      {        SIMDE_MATH_INFINITY, SIMDE_FLOAT64_C(   566.79) },
       INT32_C(         180),
      {        SIMDE_MATH_INFINITY, SIMDE_FLOAT64_C(   860.66) } },
    { { SIMDE_FLOAT64_C(   592.31), SIMDE_FLOAT64_C(  -536.22) },
      { SIMDE_FLOAT64_C(  -860.66), SIMDE_FLOAT64_C(   116.54) },
       INT32_C(         196),
      { SIMDE_FLOAT64_C(  -860.66), SIMDE_FLOAT64_C(  -536.22) } },
    { { SIMDE_FLOAT64_C(  -208.51), SIMDE_FLOAT64_C(  -317.87) },
      { SIMDE_FLOAT64_C(   924.86), SIMDE_FLOAT64_C(   266.81) },
       INT32_C(         212),
      { SIMDE_FLOAT64_C(   924.86), SIMDE_FLOAT64_C(  -317.87) } },
    { { SIMDE_FLOAT64_C(  -786.75), SIMDE_FLOAT64_C(   796.90) },
      {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(  -475.07) },
       INT32_C(         228),
      {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(   796.90) } },
    { { SIMDE_FLOAT64_C(  -503.65), SIMDE_FLOAT64_C(  -347.96) },
      { SIMDE_FLOAT64_C(   492.13), SIMDE_FLOAT64_C(   745.89) },
       INT32_C(         244),
      { SIMDE_FLOAT64_C(   492.13), SIMDE_FLOAT64_C(  -347.96) } },
  };

  simde__m128d a, b, r;

  a = simde_mm_loadu_pd(test_vec[0].a);
  b = simde_mm_loadu_pd(test_vec[0].b);
  r = simde_mm_roundscale_sd(a, b, INT32_C(           0));
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[0].r), 1);

  a = simde_mm_loadu_pd(test_vec[1].a);
  b = simde_mm_loadu_pd(test_vec[1].b);
  r = simde_mm_roundscale_sd(a, b, INT32_C(          16));
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[1].r), 1);

  a = simde_mm_loadu_pd(test_vec[2].a);
  b = simde_mm_loadu_pd(test_vec[2].b);
  r = simde_mm_roundscale_sd(a, b, INT32_C(          32));
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[2].r), 1);

  a = simde_mm_loadu_pd(test_vec[3].a);
  b = simde_mm_loadu_pd(test_vec[3].b);
  r = simde_mm_roundscale_sd(a, b, INT32_C(          48));
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[3].r), 1);

  a = simde_mm_loadu_pd(test_vec[4].a);
  b = simde_mm_loadu_pd(test_vec[4].b);
  r = simde_mm_roundscale_sd(a, b, INT32_C(          64));
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[4].r), 1);

  a = simde_mm_loadu_pd(test_vec[5].a);
  b = simde_mm_loadu_pd(test_vec[5].b);
  r = simde_mm_roundscale_sd(a, b, INT32_C(          80));
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[5].r), 1);

  a = simde_mm_loadu_pd(test_vec[6].a);
  b = simde_mm_loadu_pd(test_vec[6].b);
  r = simde_mm_roundscale_sd(a, b, INT32_C(          96));
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[6].r), 1);

  a = simde_mm_loadu_pd(test_vec[7].a);
  b = simde_mm_loadu_pd(test_vec[7].b);
  r = simde_mm_roundscale_sd(a, b, INT32_C(         112));
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[7].r), 1);

  a = simde_mm_loadu_pd(test_vec[8].a);
  b = simde_mm_loadu_pd(test_vec[8].b);
  r = simde_mm_roundscale_sd(a, b, INT32_C(         128));
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[8].r), 1);

  a = simde_mm_loadu_pd(test_vec[9].a);
  b = simde_mm_loadu_pd(test_vec[9].b);
  r = simde_mm_roundscale_sd(a, b, INT32_C(         144));
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[9].r), 1);

  a = simde_mm_loadu_pd(test_vec[10].a);
  b = simde_mm_loadu_pd(test_vec[10].b);
  r = simde_mm_roundscale_sd(a, b, INT32_C(         160));
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[10].r), 1);

  a = simde_mm_loadu_pd(test_vec[11].a);
  b = simde_mm_loadu_pd(test_vec[11].b);
  r = simde_mm_roundscale_sd(a, b, INT32_C(         176));
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[11].r), 1);

  a = simde_mm_loadu_pd(test_vec[12].a);
  b = simde_mm_loadu_pd(test_vec[12].b);
  r = simde_mm_roundscale_sd(a, b, INT32_C(         192));
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[12].r), 1);

  a = simde_mm_loadu_pd(test_vec[13].a);
  b = simde_mm_loadu_pd(test_vec[13].b);
  r = simde_mm_roundscale_sd(a, b, INT32_C(         208));
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[13].r), 1);

  a = simde_mm_loadu_pd(test_vec[14].a);
  b = simde_mm_loadu_pd(test_vec[14].b);
  r = simde_mm_roundscale_sd(a, b, INT32_C(         224));
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[14].r), 1);

  a = simde_mm_loadu_pd(test_vec[15].a);
  b = simde_mm_loadu_pd(test_vec[15].b);
  r = simde_mm_roundscale_sd(a, b, INT32_C(         240));
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[15].r), 1);

  a = simde_mm_loadu_pd(test_vec[16].a);
  b = simde_mm_loadu_pd(test_vec[16].b);
  r = simde_mm_roundscale_sd(a, b, INT32_C(           1));
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[16].r), 1);

  a = simde_mm_loadu_pd(test_vec[17].a);
  b = simde_mm_loadu_pd(test_vec[17].b);
  r = simde_mm_roundscale_sd(a, b, INT32_C(          17));
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[17].r), 1);

  a = simde_mm_loadu_pd(test_vec[18].a);
  b = simde_mm_loadu_pd(test_vec[18].b);
  r = simde_mm_roundscale_sd(a, b, INT32_C(          33));
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[18].r), 1);

  a = simde_mm_loadu_pd(test_vec[19].a);
  b = simde_mm_loadu_pd(test_vec[19].b);
  r = simde_mm_roundscale_sd(a, b, INT32_C(          49));
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[19].r), 1);

  a = simde_mm_loadu_pd(test_vec[20].a);
  b = simde_mm_loadu_pd(test_vec[20].b);
  r = simde_mm_roundscale_sd(a, b, INT32_C(          65));
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[20].r), 1);

  a = simde_mm_loadu_pd(test_vec[21].a);
  b = simde_mm_loadu_pd(test_vec[21].b);
  r = simde_mm_roundscale_sd(a, b, INT32_C(          81));
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[21].r), 1);

  a = simde_mm_loadu_pd(test_vec[22].a);
  b = simde_mm_loadu_pd(test_vec[22].b);
  r = simde_mm_roundscale_sd(a, b, INT32_C(          97));
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[22].r), 1);

  a = simde_mm_loadu_pd(test_vec[23].a);
  b = simde_mm_loadu_pd(test_vec[23].b);
  r = simde_mm_roundscale_sd(a, b, INT32_C(         113));
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[23].r), 1);

  a = simde_mm_loadu_pd(test_vec[24].a);
  b = simde_mm_loadu_pd(test_vec[24].b);
  r = simde_mm_roundscale_sd(a, b, INT32_C(         129));
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[24].r), 1);

  a = simde_mm_loadu_pd(test_vec[25].a);
  b = simde_mm_loadu_pd(test_vec[25].b);
  r = simde_mm_roundscale_sd(a, b, INT32_C(         145));
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[25].r), 1);

  a = simde_mm_loadu_pd(test_vec[26].a);
  b = simde_mm_loadu_pd(test_vec[26].b);
  r = simde_mm_roundscale_sd(a, b, INT32_C(         161));
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[26].r), 1);

  a = simde_mm_loadu_pd(test_vec[27].a);
  b = simde_mm_loadu_pd(test_vec[27].b);
  r = simde_mm_roundscale_sd(a, b, INT32_C(         177));
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[27].r), 1);

  a = simde_mm_loadu_pd(test_vec[28].a);
  b = simde_mm_loadu_pd(test_vec[28].b);
  r = simde_mm_roundscale_sd(a, b, INT32_C(         193));
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[28].r), 1);

  a = simde_mm_loadu_pd(test_vec[29].a);
  b = simde_mm_loadu_pd(test_vec[29].b);
  r = simde_mm_roundscale_sd(a, b, INT32_C(         209));
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[29].r), 1);

  a = simde_mm_loadu_pd(test_vec[30].a);
  b = simde_mm_loadu_pd(test_vec[30].b);
  r = simde_mm_roundscale_sd(a, b, INT32_C(         225));
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[30].r), 1);

  a = simde_mm_loadu_pd(test_vec[31].a);
  b = simde_mm_loadu_pd(test_vec[31].b);
  r = simde_mm_roundscale_sd(a, b, INT32_C(         241));
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[31].r), 1);

  a = simde_mm_loadu_pd(test_vec[32].a);
  b = simde_mm_loadu_pd(test_vec[32].b);
  r = simde_mm_roundscale_sd(a, b, INT32_C(           2));
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[32].r), 1);

  a = simde_mm_loadu_pd(test_vec[33].a);
  b = simde_mm_loadu_pd(test_vec[33].b);
  r = simde_mm_roundscale_sd(a, b, INT32_C(          18));
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[33].r), 1);

  a = simde_mm_loadu_pd(test_vec[34].a);
  b = simde_mm_loadu_pd(test_vec[34].b);
  r = simde_mm_roundscale_sd(a, b, INT32_C(          34));
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[34].r), 1);

  a = simde_mm_loadu_pd(test_vec[35].a);
  b = simde_mm_loadu_pd(test_vec[35].b);
  r = simde_mm_roundscale_sd(a, b, INT32_C(          50));
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[35].r), 1);

  a = simde_mm_loadu_pd(test_vec[36].a);
  b = simde_mm_loadu_pd(test_vec[36].b);
  r = simde_mm_roundscale_sd(a, b, INT32_C(          66));
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[36].r), 1);

  a = simde_mm_loadu_pd(test_vec[37].a);
  b = simde_mm_loadu_pd(test_vec[37].b);
  r = simde_mm_roundscale_sd(a, b, INT32_C(          82));
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[37].r), 1);

  a = simde_mm_loadu_pd(test_vec[38].a);
  b = simde_mm_loadu_pd(test_vec[38].b);
  r = simde_mm_roundscale_sd(a, b, INT32_C(          98));
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[38].r), 1);

  a = simde_mm_loadu_pd(test_vec[39].a);
  b = simde_mm_loadu_pd(test_vec[39].b);
  r = simde_mm_roundscale_sd(a, b, INT32_C(         114));
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[39].r), 1);

  a = simde_mm_loadu_pd(test_vec[40].a);
  b = simde_mm_loadu_pd(test_vec[40].b);
  r = simde_mm_roundscale_sd(a, b, INT32_C(         130));
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[40].r), 1);

  a = simde_mm_loadu_pd(test_vec[41].a);
  b = simde_mm_loadu_pd(test_vec[41].b);
  r = simde_mm_roundscale_sd(a, b, INT32_C(         146));
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[41].r), 1);

  a = simde_mm_loadu_pd(test_vec[42].a);
  b = simde_mm_loadu_pd(test_vec[42].b);
  r = simde_mm_roundscale_sd(a, b, INT32_C(         162));
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[42].r), 1);

  a = simde_mm_loadu_pd(test_vec[43].a);
  b = simde_mm_loadu_pd(test_vec[43].b);
  r = simde_mm_roundscale_sd(a, b, INT32_C(         178));
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[43].r), 1);

  a = simde_mm_loadu_pd(test_vec[44].a);
  b = simde_mm_loadu_pd(test_vec[44].b);
  r = simde_mm_roundscale_sd(a, b, INT32_C(         194));
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[44].r), 1);

  a = simde_mm_loadu_pd(test_vec[45].a);
  b = simde_mm_loadu_pd(test_vec[45].b);
  r = simde_mm_roundscale_sd(a, b, INT32_C(         210));
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[45].r), 1);

  a = simde_mm_loadu_pd(test_vec[46].a);
  b = simde_mm_loadu_pd(test_vec[46].b);
  r = simde_mm_roundscale_sd(a, b, INT32_C(         226));
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[46].r), 1);

  a = simde_mm_loadu_pd(test_vec[47].a);
  b = simde_mm_loadu_pd(test_vec[47].b);
  r = simde_mm_roundscale_sd(a, b, INT32_C(         242));
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[47].r), 1);

  a = simde_mm_loadu_pd(test_vec[48].a);
  b = simde_mm_loadu_pd(test_vec[48].b);
  r = simde_mm_roundscale_sd(a, b, INT32_C(           3));
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[48].r), 1);

  a = simde_mm_loadu_pd(test_vec[49].a);
  b = simde_mm_loadu_pd(test_vec[49].b);
  r = simde_mm_roundscale_sd(a, b, INT32_C(          19));
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[49].r), 1);

  a = simde_mm_loadu_pd(test_vec[50].a);
  b = simde_mm_loadu_pd(test_vec[50].b);
  r = simde_mm_roundscale_sd(a, b, INT32_C(          35));
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[50].r), 1);

  a = simde_mm_loadu_pd(test_vec[51].a);
  b = simde_mm_loadu_pd(test_vec[51].b);
  r = simde_mm_roundscale_sd(a, b, INT32_C(          51));
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[51].r), 1);

  a = simde_mm_loadu_pd(test_vec[52].a);
  b = simde_mm_loadu_pd(test_vec[52].b);
  r = simde_mm_roundscale_sd(a, b, INT32_C(          67));
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[52].r), 1);

  a = simde_mm_loadu_pd(test_vec[53].a);
  b = simde_mm_loadu_pd(test_vec[53].b);
  r = simde_mm_roundscale_sd(a, b, INT32_C(          83));
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[53].r), 1);

  a = simde_mm_loadu_pd(test_vec[54].a);
  b = simde_mm_loadu_pd(test_vec[54].b);
  r = simde_mm_roundscale_sd(a, b, INT32_C(          99));
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[54].r), 1);

  a = simde_mm_loadu_pd(test_vec[55].a);
  b = simde_mm_loadu_pd(test_vec[55].b);
  r = simde_mm_roundscale_sd(a, b, INT32_C(         115));
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[55].r), 1);

  a = simde_mm_loadu_pd(test_vec[56].a);
  b = simde_mm_loadu_pd(test_vec[56].b);
  r = simde_mm_roundscale_sd(a, b, INT32_C(         131));
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[56].r), 1);

  a = simde_mm_loadu_pd(test_vec[57].a);
  b = simde_mm_loadu_pd(test_vec[57].b);
  r = simde_mm_roundscale_sd(a, b, INT32_C(         147));
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[57].r), 1);

  a = simde_mm_loadu_pd(test_vec[58].a);
  b = simde_mm_loadu_pd(test_vec[58].b);
  r = simde_mm_roundscale_sd(a, b, INT32_C(         163));
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[58].r), 1);

  a = simde_mm_loadu_pd(test_vec[59].a);
  b = simde_mm_loadu_pd(test_vec[59].b);
  r = simde_mm_roundscale_sd(a, b, INT32_C(         179));
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[59].r), 1);

  a = simde_mm_loadu_pd(test_vec[60].a);
  b = simde_mm_loadu_pd(test_vec[60].b);
  r = simde_mm_roundscale_sd(a, b, INT32_C(         195));
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[60].r), 1);

  a = simde_mm_loadu_pd(test_vec[61].a);
  b = simde_mm_loadu_pd(test_vec[61].b);
  r = simde_mm_roundscale_sd(a, b, INT32_C(         211));
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[61].r), 1);

  a = simde_mm_loadu_pd(test_vec[62].a);
  b = simde_mm_loadu_pd(test_vec[62].b);
  r = simde_mm_roundscale_sd(a, b, INT32_C(         227));
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[62].r), 1);

  a = simde_mm_loadu_pd(test_vec[63].a);
  b = simde_mm_loadu_pd(test_vec[63].b);
  r = simde_mm_roundscale_sd(a, b, INT32_C(         243));
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[63].r), 1);

  a = simde_mm_loadu_pd(test_vec[64].a);
  b = simde_mm_loadu_pd(test_vec[64].b);
  r = simde_mm_roundscale_sd(a, b, INT32_C(           4));
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[64].r), 1);

  a = simde_mm_loadu_pd(test_vec[65].a);
  b = simde_mm_loadu_pd(test_vec[65].b);
  r = simde_mm_roundscale_sd(a, b, INT32_C(          20));
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[65].r), 1);

  a = simde_mm_loadu_pd(test_vec[66].a);
  b = simde_mm_loadu_pd(test_vec[66].b);
  r = simde_mm_roundscale_sd(a, b, INT32_C(          36));
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[66].r), 1);

  a = simde_mm_loadu_pd(test_vec[67].a);
  b = simde_mm_loadu_pd(test_vec[67].b);
  r = simde_mm_roundscale_sd(a, b, INT32_C(          52));
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[67].r), 1);

  a = simde_mm_loadu_pd(test_vec[68].a);
  b = simde_mm_loadu_pd(test_vec[68].b);
  r = simde_mm_roundscale_sd(a, b, INT32_C(          68));
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[68].r), 1);

  a = simde_mm_loadu_pd(test_vec[69].a);
  b = simde_mm_loadu_pd(test_vec[69].b);
  r = simde_mm_roundscale_sd(a, b, INT32_C(          84));
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[69].r), 1);

  a = simde_mm_loadu_pd(test_vec[70].a);
  b = simde_mm_loadu_pd(test_vec[70].b);
  r = simde_mm_roundscale_sd(a, b, INT32_C(         100));
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[70].r), 1);

  a = simde_mm_loadu_pd(test_vec[71].a);
  b = simde_mm_loadu_pd(test_vec[71].b);
  r = simde_mm_roundscale_sd(a, b, INT32_C(         116));
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[71].r), 1);

  a = simde_mm_loadu_pd(test_vec[72].a);
  b = simde_mm_loadu_pd(test_vec[72].b);
  r = simde_mm_roundscale_sd(a, b, INT32_C(         132));
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[72].r), 1);

  a = simde_mm_loadu_pd(test_vec[73].a);
  b = simde_mm_loadu_pd(test_vec[73].b);
  r = simde_mm_roundscale_sd(a, b, INT32_C(         148));
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[73].r), 1);

  a = simde_mm_loadu_pd(test_vec[74].a);
  b = simde_mm_loadu_pd(test_vec[74].b);
  r = simde_mm_roundscale_sd(a, b, INT32_C(         164));
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[74].r), 1);

  a = simde_mm_loadu_pd(test_vec[75].a);
  b = simde_mm_loadu_pd(test_vec[75].b);
  r = simde_mm_roundscale_sd(a, b, INT32_C(         180));
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[75].r), 1);

  a = simde_mm_loadu_pd(test_vec[76].a);
  b = simde_mm_loadu_pd(test_vec[76].b);
  r = simde_mm_roundscale_sd(a, b, INT32_C(         196));
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[76].r), 1);

  a = simde_mm_loadu_pd(test_vec[77].a);
  b = simde_mm_loadu_pd(test_vec[77].b);
  r = simde_mm_roundscale_sd(a, b, INT32_C(         212));
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[77].r), 1);

  a = simde_mm_loadu_pd(test_vec[78].a);
  b = simde_mm_loadu_pd(test_vec[78].b);
  r = simde_mm_roundscale_sd(a, b, INT32_C(         228));
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[78].r), 1);

  a = simde_mm_loadu_pd(test_vec[79].a);
  b = simde_mm_loadu_pd(test_vec[79].b);
  r = simde_mm_roundscale_sd(a, b, INT32_C(         244));
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[79].r), 1);

  return 0;
#else
  fputc('\n', stdout);
  int round_type[5] = {SIMDE_MM_FROUND_TO_NEAREST_INT, SIMDE_MM_FROUND_TO_NEG_INF, SIMDE_MM_FROUND_TO_POS_INF, SIMDE_MM_FROUND_TO_ZERO, SIMDE_MM_FROUND_CUR_DIRECTION};
  for (int i = 0 ; i < 5 ; i++) {
    for (int j = 0 ; j < 16 ; j++) {
      simde__m128d a = simde_test_x86_random_f64x2(SIMDE_FLOAT64_C(-1000.0), SIMDE_FLOAT64_C(1000.0));
      simde__m128d b = simde_test_x86_random_f64x2(SIMDE_FLOAT64_C(-1000.0), SIMDE_FLOAT64_C(1000.0));
      if((simde_test_codegen_rand() & 1)) {
        if((simde_test_codegen_rand() & 1))
          b = simde_mm_mask_mov_pd(b, 1, simde_mm_set1_pd(SIMDE_MATH_NAN));
        else {
          if((simde_test_codegen_rand() & 1))
            b = simde_mm_mask_mov_pd(b, 1, simde_mm_set1_pd(SIMDE_MATH_INFINITY));
          else
            b = simde_mm_mask_mov_pd(b, 1, simde_mm_set1_pd(-SIMDE_MATH_INFINITY));
        }
      }
      int imm8 = ((j << 4) | round_type[i]) & 255;
      simde__m128d r;
      SIMDE_CONSTIFY_256_(simde_mm_roundscale_sd, r, simde_mm_setzero_pd(), imm8, a, b);

      simde_test_x86_write_f64x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
      simde_test_x86_write_f64x2(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
      simde_test_codegen_write_i32(2, imm8, SIMDE_TEST_VEC_POS_MIDDLE);
      simde_test_x86_write_f64x2(2, r, SIMDE_TEST_VEC_POS_LAST);
    }
  }
  return 1;
#endif
}

static int
test_simde_mm_mask_roundscale_sd (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const simde_float64 src[2];
    const simde__mmask8 k;
    const simde_float64 a[2];
    const simde_float64 b[2];
    const int32_t imm8;
    const simde_float64 r[2];
  } test_vec[] = {
    { { SIMDE_FLOAT64_C(  -152.89), SIMDE_FLOAT64_C(   255.35) },
      UINT8_C(242),
      { SIMDE_FLOAT64_C(   575.09), SIMDE_FLOAT64_C(   308.20) },
      {        SIMDE_MATH_INFINITY, SIMDE_FLOAT64_C(  -284.87) },
       INT32_C(         224),
      { SIMDE_FLOAT64_C(  -152.89), SIMDE_FLOAT64_C(   308.20) } },
    { { SIMDE_FLOAT64_C(  -592.52), SIMDE_FLOAT64_C(   699.67) },
      UINT8_C(134),
      { SIMDE_FLOAT64_C(   489.75), SIMDE_FLOAT64_C(   904.42) },
      { SIMDE_FLOAT64_C(  -814.03), SIMDE_FLOAT64_C(  -202.13) },
       INT32_C(         177),
      { SIMDE_FLOAT64_C(  -592.52), SIMDE_FLOAT64_C(   904.42) } },
    { { SIMDE_FLOAT64_C(   531.17), SIMDE_FLOAT64_C(   420.57) },
      UINT8_C(140),
      { SIMDE_FLOAT64_C(  -721.46), SIMDE_FLOAT64_C(   -85.09) },
      { SIMDE_FLOAT64_C(  -540.17), SIMDE_FLOAT64_C(   877.77) },
       INT32_C(          98),
      { SIMDE_FLOAT64_C(   531.17), SIMDE_FLOAT64_C(   -85.09) } },
    { { SIMDE_FLOAT64_C(  -178.78), SIMDE_FLOAT64_C(  -745.00) },
      UINT8_C( 67),
      { SIMDE_FLOAT64_C(  -923.43), SIMDE_FLOAT64_C(   247.60) },
      {        SIMDE_MATH_INFINITY, SIMDE_FLOAT64_C(   384.78) },
       INT32_C(         179),
      {        SIMDE_MATH_INFINITY, SIMDE_FLOAT64_C(   247.60) } },
    { { SIMDE_FLOAT64_C(   840.86), SIMDE_FLOAT64_C(  -204.15) },
      UINT8_C( 77),
      { SIMDE_FLOAT64_C(   540.53), SIMDE_FLOAT64_C(   -50.72) },
      {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(   444.96) },
       INT32_C(         132),
      {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(   -50.72) } },
    { { SIMDE_FLOAT64_C(    49.85), SIMDE_FLOAT64_C(   550.73) },
      UINT8_C( 67),
      { SIMDE_FLOAT64_C(  -882.69), SIMDE_FLOAT64_C(   829.28) },
      {        SIMDE_MATH_INFINITY, SIMDE_FLOAT64_C(  -422.86) },
       INT32_C(         176),
      {        SIMDE_MATH_INFINITY, SIMDE_FLOAT64_C(   829.28) } },
    { { SIMDE_FLOAT64_C(   530.79), SIMDE_FLOAT64_C(   309.38) },
      UINT8_C( 29),
      { SIMDE_FLOAT64_C(  -221.61), SIMDE_FLOAT64_C(  -325.85) },
      {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(   843.82) },
       INT32_C(         225),
      {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(  -325.85) } },
    { { SIMDE_FLOAT64_C(  -405.09), SIMDE_FLOAT64_C(  -883.54) },
      UINT8_C(139),
      { SIMDE_FLOAT64_C(  -864.56), SIMDE_FLOAT64_C(    65.73) },
      { SIMDE_FLOAT64_C(  -878.07), SIMDE_FLOAT64_C(   580.40) },
       INT32_C(          82),
      { SIMDE_FLOAT64_C(  -878.06), SIMDE_FLOAT64_C(    65.73) } },
  };

  simde__m128d src, a, b, r;

  src = simde_mm_loadu_pd(test_vec[0].src);
  a = simde_mm_loadu_pd(test_vec[0].a);
  b = simde_mm_loadu_pd(test_vec[0].b);
  r = simde_mm_mask_roundscale_sd(src, test_vec[0].k, a, b, INT32_C(         224));
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[0].r), 1);

  src = simde_mm_loadu_pd(test_vec[1].src);
  a = simde_mm_loadu_pd(test_vec[1].a);
  b = simde_mm_loadu_pd(test_vec[1].b);
  r = simde_mm_mask_roundscale_sd(src, test_vec[1].k, a, b, INT32_C(         177));
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[1].r), 1);

  src = simde_mm_loadu_pd(test_vec[2].src);
  a = simde_mm_loadu_pd(test_vec[2].a);
  b = simde_mm_loadu_pd(test_vec[2].b);
  r = simde_mm_mask_roundscale_sd(src, test_vec[2].k, a, b, INT32_C(          98));
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[2].r), 1);

  src = simde_mm_loadu_pd(test_vec[3].src);
  a = simde_mm_loadu_pd(test_vec[3].a);
  b = simde_mm_loadu_pd(test_vec[3].b);
  r = simde_mm_mask_roundscale_sd(src, test_vec[3].k, a, b, INT32_C(         179));
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[3].r), 1);

  src = simde_mm_loadu_pd(test_vec[4].src);
  a = simde_mm_loadu_pd(test_vec[4].a);
  b = simde_mm_loadu_pd(test_vec[4].b);
  r = simde_mm_mask_roundscale_sd(src, test_vec[4].k, a, b, INT32_C(         132));
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[4].r), 1);

  src = simde_mm_loadu_pd(test_vec[5].src);
  a = simde_mm_loadu_pd(test_vec[5].a);
  b = simde_mm_loadu_pd(test_vec[5].b);
  r = simde_mm_mask_roundscale_sd(src, test_vec[5].k, a, b, INT32_C(         176));
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[5].r), 1);

  src = simde_mm_loadu_pd(test_vec[6].src);
  a = simde_mm_loadu_pd(test_vec[6].a);
  b = simde_mm_loadu_pd(test_vec[6].b);
  r = simde_mm_mask_roundscale_sd(src, test_vec[6].k, a, b, INT32_C(         225));
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[6].r), 1);

  src = simde_mm_loadu_pd(test_vec[7].src);
  a = simde_mm_loadu_pd(test_vec[7].a);
  b = simde_mm_loadu_pd(test_vec[7].b);
  r = simde_mm_mask_roundscale_sd(src, test_vec[7].k, a, b, INT32_C(          82));
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[7].r), 1);

  return 0;
#else
  fputc('\n', stdout);
  int round_type[5] = {SIMDE_MM_FROUND_TO_NEAREST_INT, SIMDE_MM_FROUND_TO_NEG_INF, SIMDE_MM_FROUND_TO_POS_INF, SIMDE_MM_FROUND_TO_ZERO, SIMDE_MM_FROUND_CUR_DIRECTION};
  for (int i = 0 ; i < 8 ; i++) {
    simde__m128d src = simde_test_x86_random_f64x2(SIMDE_FLOAT64_C(-1000.0), SIMDE_FLOAT64_C(1000.0));
    simde__mmask8 k = simde_test_x86_random_mmask8();
    simde__m128d a = simde_test_x86_random_f64x2(SIMDE_FLOAT64_C(-1000.0), SIMDE_FLOAT64_C(1000.0));
    simde__m128d b = simde_test_x86_random_f64x2(SIMDE_FLOAT64_C(-1000.0), SIMDE_FLOAT64_C(1000.0));
    if((simde_test_codegen_rand() & 1)) {
      if((simde_test_codegen_rand() & 1))
        b = simde_mm_mask_mov_pd(b, 1, simde_mm_set1_pd(SIMDE_MATH_NAN));
      else {
        if((simde_test_codegen_rand() & 1))
          b = simde_mm_mask_mov_pd(b, 1, simde_mm_set1_pd(SIMDE_MATH_INFINITY));
        else
          b = simde_mm_mask_mov_pd(b, 1, simde_mm_set1_pd(-SIMDE_MATH_INFINITY));
      }
    }
    int imm8 = (((simde_test_codegen_rand() & 15) << 4) | round_type[i % 5]) & 255;
    simde__m128d r;
    SIMDE_CONSTIFY_256_(simde_mm_mask_roundscale_sd, r, simde_mm_setzero_pd(), imm8, src, k, a, b);

    simde_test_x86_write_f64x2(2, src, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_mmask8(2, k, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_f64x2(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_f64x2(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i32(2, imm8, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_f64x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm_maskz_roundscale_sd (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const simde__mmask8 k;
    const simde_float64 a[2];
    const simde_float64 b[2];
    const int32_t imm8;
    const simde_float64 r[2];
  } test_vec[] = {
    { UINT8_C(231),
      { SIMDE_FLOAT64_C(   679.03), SIMDE_FLOAT64_C(   330.13) },
      {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(   170.83) },
       INT32_C(          48),
      {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(   330.13) } },
    { UINT8_C(227),
      { SIMDE_FLOAT64_C(  -640.76), SIMDE_FLOAT64_C(  -486.00) },
      {        SIMDE_MATH_INFINITY, SIMDE_FLOAT64_C(  -204.74) },
       INT32_C(         209),
      {        SIMDE_MATH_INFINITY, SIMDE_FLOAT64_C(  -486.00) } },
    { UINT8_C(219),
      { SIMDE_FLOAT64_C(   264.61), SIMDE_FLOAT64_C(  -297.73) },
      { SIMDE_FLOAT64_C(   370.03), SIMDE_FLOAT64_C(   192.79) },
       INT32_C(         162),
      { SIMDE_FLOAT64_C(   370.03), SIMDE_FLOAT64_C(  -297.73) } },
    { UINT8_C(225),
      { SIMDE_FLOAT64_C(  -946.41), SIMDE_FLOAT64_C(  -365.05) },
      { SIMDE_FLOAT64_C(  -822.97), SIMDE_FLOAT64_C(   822.58) },
       INT32_C(           3),
      { SIMDE_FLOAT64_C(  -822.00), SIMDE_FLOAT64_C(  -365.05) } },
    { UINT8_C( 14),
      { SIMDE_FLOAT64_C(   101.90), SIMDE_FLOAT64_C(  -335.55) },
      {       -SIMDE_MATH_INFINITY, SIMDE_FLOAT64_C(  -727.27) },
       INT32_C(          68),
      { SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(  -335.55) } },
    { UINT8_C(201),
      { SIMDE_FLOAT64_C(   337.11), SIMDE_FLOAT64_C(  -368.49) },
      { SIMDE_FLOAT64_C(   497.71), SIMDE_FLOAT64_C(  -156.35) },
       INT32_C(          32),
      { SIMDE_FLOAT64_C(   497.75), SIMDE_FLOAT64_C(  -368.49) } },
    { UINT8_C(128),
      { SIMDE_FLOAT64_C(   229.27), SIMDE_FLOAT64_C(   805.61) },
      { SIMDE_FLOAT64_C(   385.54), SIMDE_FLOAT64_C(  -400.70) },
       INT32_C(          97),
      { SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(   805.61) } },
    { UINT8_C(193),
      { SIMDE_FLOAT64_C(   -90.84), SIMDE_FLOAT64_C(  -911.13) },
      { SIMDE_FLOAT64_C(   474.67), SIMDE_FLOAT64_C(    86.19) },
       INT32_C(           2),
      { SIMDE_FLOAT64_C(   475.00), SIMDE_FLOAT64_C(  -911.13) } },
  };

  simde__m128d a, b, r;

  a = simde_mm_loadu_pd(test_vec[0].a);
  b = simde_mm_loadu_pd(test_vec[0].b);
  r = simde_mm_maskz_roundscale_sd(test_vec[0].k, a, b, INT32_C(          48));
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[0].r), 1);

  a = simde_mm_loadu_pd(test_vec[1].a);
  b = simde_mm_loadu_pd(test_vec[1].b);
  r = simde_mm_maskz_roundscale_sd(test_vec[1].k, a, b, INT32_C(         209));
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[1].r), 1);

  a = simde_mm_loadu_pd(test_vec[2].a);
  b = simde_mm_loadu_pd(test_vec[2].b);
  r = simde_mm_maskz_roundscale_sd(test_vec[2].k, a, b, INT32_C(         162));
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[2].r), 1);

  a = simde_mm_loadu_pd(test_vec[3].a);
  b = simde_mm_loadu_pd(test_vec[3].b);
  r = simde_mm_maskz_roundscale_sd(test_vec[3].k, a, b, INT32_C(           3));
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[3].r), 1);

  a = simde_mm_loadu_pd(test_vec[4].a);
  b = simde_mm_loadu_pd(test_vec[4].b);
  r = simde_mm_maskz_roundscale_sd(test_vec[4].k, a, b, INT32_C(          68));
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[4].r), 1);

  a = simde_mm_loadu_pd(test_vec[5].a);
  b = simde_mm_loadu_pd(test_vec[5].b);
  r = simde_mm_maskz_roundscale_sd(test_vec[5].k, a, b, INT32_C(          32));
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[5].r), 1);

  a = simde_mm_loadu_pd(test_vec[6].a);
  b = simde_mm_loadu_pd(test_vec[6].b);
  r = simde_mm_maskz_roundscale_sd(test_vec[6].k, a, b, INT32_C(          97));
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[6].r), 1);

  a = simde_mm_loadu_pd(test_vec[7].a);
  b = simde_mm_loadu_pd(test_vec[7].b);
  r = simde_mm_maskz_roundscale_sd(test_vec[7].k, a, b, INT32_C(           2));
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[7].r), 1);

  return 0;
#else
  fputc('\n', stdout);
  int round_type[5] = {SIMDE_MM_FROUND_TO_NEAREST_INT, SIMDE_MM_FROUND_TO_NEG_INF, SIMDE_MM_FROUND_TO_POS_INF, SIMDE_MM_FROUND_TO_ZERO, SIMDE_MM_FROUND_CUR_DIRECTION};
  for (int i = 0 ; i < 8 ; i++) {
    simde__mmask8 k = simde_test_x86_random_mmask8();
    simde__m128d a = simde_test_x86_random_f64x2(SIMDE_FLOAT64_C(-1000.0), SIMDE_FLOAT64_C(1000.0));
    simde__m128d b = simde_test_x86_random_f64x2(SIMDE_FLOAT64_C(-1000.0), SIMDE_FLOAT64_C(1000.0));
    if((simde_test_codegen_rand() & 1)) {
      if((simde_test_codegen_rand() & 1))
        b = simde_mm_mask_mov_pd(b, 1, simde_mm_set1_pd(SIMDE_MATH_NAN));
      else {
        if((simde_test_codegen_rand() & 1))
          b = simde_mm_mask_mov_pd(b, 1, simde_mm_set1_pd(SIMDE_MATH_INFINITY));
        else
          b = simde_mm_mask_mov_pd(b, 1, simde_mm_set1_pd(-SIMDE_MATH_INFINITY));
      }
    }
    int imm8 = (((simde_test_codegen_rand() & 15) << 4) | round_type[i % 5]) & 255;
    simde__m128d r;
    SIMDE_CONSTIFY_256_(simde_mm_maskz_roundscale_sd, r, simde_mm_setzero_pd(), imm8, k, a, b);

    simde_test_x86_write_mmask8(2, k, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_f64x2(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_f64x2(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i32(2, imm8, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_f64x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm_roundscale_round_sd (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const simde_float64 a[2];
    const simde_float64 b[2];
    const int32_t imm8;
    const int32_t sae;
    const simde_float64 r[2];
  } test_vec[] = {
    { { SIMDE_FLOAT64_C(  -922.84), SIMDE_FLOAT64_C(   174.41) },
      {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(  -819.78) },
       INT32_C(          64),
       INT32_C(           8),
      {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(   174.41) } },
    { { SIMDE_FLOAT64_C(  -239.65), SIMDE_FLOAT64_C(  -886.64) },
      {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(  -376.97) },
       INT32_C(          97),
       INT32_C(           4),
      {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(  -886.64) } },
    { { SIMDE_FLOAT64_C(   481.56), SIMDE_FLOAT64_C(  -294.29) },
      { SIMDE_FLOAT64_C(   -38.63), SIMDE_FLOAT64_C(   396.57) },
       INT32_C(         210),
       INT32_C(           8),
      { SIMDE_FLOAT64_C(   -38.63), SIMDE_FLOAT64_C(  -294.29) } },
    { { SIMDE_FLOAT64_C(   243.93), SIMDE_FLOAT64_C(   311.65) },
      {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(   681.34) },
       INT32_C(          19),
       INT32_C(           8),
      {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(   311.65) } },
    { { SIMDE_FLOAT64_C(  -476.93), SIMDE_FLOAT64_C(   188.19) },
      { SIMDE_FLOAT64_C(   352.72), SIMDE_FLOAT64_C(  -296.71) },
       INT32_C(          84),
       INT32_C(           8),
      { SIMDE_FLOAT64_C(   352.72), SIMDE_FLOAT64_C(   188.19) } },
    { { SIMDE_FLOAT64_C(  -150.31), SIMDE_FLOAT64_C(   102.87) },
      {       -SIMDE_MATH_INFINITY, SIMDE_FLOAT64_C(   796.03) },
       INT32_C(         240),
       INT32_C(           4),
      {       -SIMDE_MATH_INFINITY, SIMDE_FLOAT64_C(   102.87) } },
    { { SIMDE_FLOAT64_C(   614.65), SIMDE_FLOAT64_C(  -800.95) },
      {       -SIMDE_MATH_INFINITY, SIMDE_FLOAT64_C(    11.22) },
       INT32_C(          33),
       INT32_C(           8),
      {       -SIMDE_MATH_INFINITY, SIMDE_FLOAT64_C(  -800.95) } },
    { { SIMDE_FLOAT64_C(  -451.36), SIMDE_FLOAT64_C(  -912.02) },
      { SIMDE_FLOAT64_C(  -391.41), SIMDE_FLOAT64_C(    -5.45) },
       INT32_C(         162),
       INT32_C(           8),
      { SIMDE_FLOAT64_C(  -391.41), SIMDE_FLOAT64_C(  -912.02) } },
  };

  simde__m128d a, b, r;

  a = simde_mm_loadu_pd(test_vec[0].a);
  b = simde_mm_loadu_pd(test_vec[0].b);
  r = simde_mm_roundscale_round_sd(a, b, INT32_C(          64), INT32_C(           8));
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[0].r), 1);

  a = simde_mm_loadu_pd(test_vec[1].a);
  b = simde_mm_loadu_pd(test_vec[1].b);
  r = simde_mm_roundscale_round_sd(a, b, INT32_C(          97), INT32_C(           4));
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[1].r), 1);

  a = simde_mm_loadu_pd(test_vec[2].a);
  b = simde_mm_loadu_pd(test_vec[2].b);
  r = simde_mm_roundscale_round_sd(a, b, INT32_C(         210), INT32_C(           8));
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[2].r), 1);

  a = simde_mm_loadu_pd(test_vec[3].a);
  b = simde_mm_loadu_pd(test_vec[3].b);
  r = simde_mm_roundscale_round_sd(a, b, INT32_C(          19), INT32_C(           8));
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[3].r), 1);

  a = simde_mm_loadu_pd(test_vec[4].a);
  b = simde_mm_loadu_pd(test_vec[4].b);
  r = simde_mm_roundscale_round_sd(a, b, INT32_C(          84), INT32_C(           8));
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[4].r), 1);

  a = simde_mm_loadu_pd(test_vec[5].a);
  b = simde_mm_loadu_pd(test_vec[5].b);
  r = simde_mm_roundscale_round_sd(a, b, INT32_C(         240), INT32_C(           4));
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[5].r), 1);

  a = simde_mm_loadu_pd(test_vec[6].a);
  b = simde_mm_loadu_pd(test_vec[6].b);
  r = simde_mm_roundscale_round_sd(a, b, INT32_C(          33), INT32_C(           8));
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[6].r), 1);

  a = simde_mm_loadu_pd(test_vec[7].a);
  b = simde_mm_loadu_pd(test_vec[7].b);
  r = simde_mm_roundscale_round_sd(a, b, INT32_C(         162), INT32_C(           8));
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[7].r), 1);

  return 0;
#else
  fputc('\n', stdout);
  int round_type[5] = {SIMDE_MM_FROUND_TO_NEAREST_INT, SIMDE_MM_FROUND_TO_NEG_INF, SIMDE_MM_FROUND_TO_POS_INF, SIMDE_MM_FROUND_TO_ZERO, SIMDE_MM_FROUND_CUR_DIRECTION};
  for (int i = 0 ; i < 8 ; i++) {
    simde__m128d a = simde_test_x86_random_f64x2(SIMDE_FLOAT64_C(-1000.0), SIMDE_FLOAT64_C(1000.0));
    simde__m128d b = simde_test_x86_random_f64x2(SIMDE_FLOAT64_C(-1000.0), SIMDE_FLOAT64_C(1000.0));
    if((simde_test_codegen_rand() & 1)) {
      if((simde_test_codegen_rand() & 1))
        b = simde_mm_mask_mov_pd(b, 1, simde_mm_set1_pd(SIMDE_MATH_NAN));
      else {
        if((simde_test_codegen_rand() & 1))
          b = simde_mm_mask_mov_pd(b, 1, simde_mm_set1_pd(SIMDE_MATH_INFINITY));
        else
          b = simde_mm_mask_mov_pd(b, 1, simde_mm_set1_pd(-SIMDE_MATH_INFINITY));
      }
    }
    int imm8 = (((simde_test_codegen_rand() & 15) << 4) | round_type[i % 5]) & 255;
    int sae = simde_test_codegen_rand() & 1 ? SIMDE_MM_FROUND_NO_EXC : SIMDE_MM_FROUND_CUR_DIRECTION;
    simde__m128d r;
    SIMDE_CONSTIFY_256_NEW(simde_mm_roundscale_round_sd, r, simde_mm_setzero_pd(), imm8, sae, a, b);

    simde_test_x86_write_f64x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_f64x2(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i32(2, imm8, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i32(2, sae, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_f64x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm_mask_roundscale_round_sd (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const simde_float64 src[2];
    const simde__mmask8 k;
    const simde_float64 a[2];
    const simde_float64 b[2];
    const int32_t imm8;
    const int32_t sae;
    const simde_float64 r[2];
  } test_vec[] = {
    { { SIMDE_FLOAT64_C(   874.86), SIMDE_FLOAT64_C(   394.65) },
      UINT8_C( 58),
      { SIMDE_FLOAT64_C(   201.75), SIMDE_FLOAT64_C(   815.04) },
      { SIMDE_FLOAT64_C(  -159.78), SIMDE_FLOAT64_C(   969.89) },
       INT32_C(         128),
       INT32_C(           8),
      { SIMDE_FLOAT64_C(   874.86), SIMDE_FLOAT64_C(   815.04) } },
    { { SIMDE_FLOAT64_C(  -740.35), SIMDE_FLOAT64_C(  -485.55) },
      UINT8_C( 56),
      { SIMDE_FLOAT64_C(   387.51), SIMDE_FLOAT64_C(  -803.37) },
      { SIMDE_FLOAT64_C(  -180.68), SIMDE_FLOAT64_C(  -444.72) },
       INT32_C(          17),
       INT32_C(           8),
      { SIMDE_FLOAT64_C(  -740.35), SIMDE_FLOAT64_C(  -803.37) } },
    { { SIMDE_FLOAT64_C(  -952.30), SIMDE_FLOAT64_C(   509.81) },
      UINT8_C(124),
      { SIMDE_FLOAT64_C(  -488.08), SIMDE_FLOAT64_C(  -565.90) },
      { SIMDE_FLOAT64_C(   427.29), SIMDE_FLOAT64_C(   560.52) },
       INT32_C(         194),
       INT32_C(           8),
      { SIMDE_FLOAT64_C(  -952.30), SIMDE_FLOAT64_C(  -565.90) } },
    { { SIMDE_FLOAT64_C(  -643.85), SIMDE_FLOAT64_C(   123.00) },
      UINT8_C(217),
      { SIMDE_FLOAT64_C(   346.67), SIMDE_FLOAT64_C(  -675.25) },
      { SIMDE_FLOAT64_C(   842.99), SIMDE_FLOAT64_C(  -813.12) },
       INT32_C(          67),
       INT32_C(           4),
      { SIMDE_FLOAT64_C(   842.94), SIMDE_FLOAT64_C(  -675.25) } },
    { { SIMDE_FLOAT64_C(  -850.89), SIMDE_FLOAT64_C(   -19.24) },
      UINT8_C(208),
      { SIMDE_FLOAT64_C(  -410.70), SIMDE_FLOAT64_C(  -631.73) },
      {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(   408.62) },
       INT32_C(          20),
       INT32_C(           4),
      { SIMDE_FLOAT64_C(  -850.89), SIMDE_FLOAT64_C(  -631.73) } },
    { { SIMDE_FLOAT64_C(  -431.37), SIMDE_FLOAT64_C(   805.13) },
      UINT8_C(  6),
      { SIMDE_FLOAT64_C(    80.55), SIMDE_FLOAT64_C(  -760.78) },
      {        SIMDE_MATH_INFINITY, SIMDE_FLOAT64_C(  -358.93) },
       INT32_C(         160),
       INT32_C(           4),
      { SIMDE_FLOAT64_C(  -431.37), SIMDE_FLOAT64_C(  -760.78) } },
    { { SIMDE_FLOAT64_C(   302.34), SIMDE_FLOAT64_C(  -502.96) },
      UINT8_C(109),
      { SIMDE_FLOAT64_C(   145.33), SIMDE_FLOAT64_C(  -316.07) },
      { SIMDE_FLOAT64_C(   771.91), SIMDE_FLOAT64_C(   866.44) },
       INT32_C(         113),
       INT32_C(           8),
      { SIMDE_FLOAT64_C(   771.91), SIMDE_FLOAT64_C(  -316.07) } },
    { { SIMDE_FLOAT64_C(  -661.10), SIMDE_FLOAT64_C(  -489.68) },
      UINT8_C( 18),
      { SIMDE_FLOAT64_C(  -379.76), SIMDE_FLOAT64_C(   918.95) },
      {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(   141.17) },
       INT32_C(         242),
       INT32_C(           8),
      { SIMDE_FLOAT64_C(  -661.10), SIMDE_FLOAT64_C(   918.95) } },
  };

  simde__m128d src, a, b, r;

  src = simde_mm_loadu_pd(test_vec[0].src);
  a = simde_mm_loadu_pd(test_vec[0].a);
  b = simde_mm_loadu_pd(test_vec[0].b);
  r = simde_mm_mask_roundscale_round_sd(src, test_vec[0].k, a, b, INT32_C(         128), INT32_C(           8));
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[0].r), 1);

  src = simde_mm_loadu_pd(test_vec[1].src);
  a = simde_mm_loadu_pd(test_vec[1].a);
  b = simde_mm_loadu_pd(test_vec[1].b);
  r = simde_mm_mask_roundscale_round_sd(src, test_vec[1].k, a, b, INT32_C(          17), INT32_C(           8));
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[1].r), 1);

  src = simde_mm_loadu_pd(test_vec[2].src);
  a = simde_mm_loadu_pd(test_vec[2].a);
  b = simde_mm_loadu_pd(test_vec[2].b);
  r = simde_mm_mask_roundscale_round_sd(src, test_vec[2].k, a, b, INT32_C(         194), INT32_C(           8));
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[2].r), 1);

  src = simde_mm_loadu_pd(test_vec[3].src);
  a = simde_mm_loadu_pd(test_vec[3].a);
  b = simde_mm_loadu_pd(test_vec[3].b);
  r = simde_mm_mask_roundscale_round_sd(src, test_vec[3].k, a, b, INT32_C(          67), INT32_C(           4));
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[3].r), 1);

  src = simde_mm_loadu_pd(test_vec[4].src);
  a = simde_mm_loadu_pd(test_vec[4].a);
  b = simde_mm_loadu_pd(test_vec[4].b);
  r = simde_mm_mask_roundscale_round_sd(src, test_vec[4].k, a, b, INT32_C(          20), INT32_C(           4));
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[4].r), 1);

  src = simde_mm_loadu_pd(test_vec[5].src);
  a = simde_mm_loadu_pd(test_vec[5].a);
  b = simde_mm_loadu_pd(test_vec[5].b);
  r = simde_mm_mask_roundscale_round_sd(src, test_vec[5].k, a, b, INT32_C(         160), INT32_C(           4));
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[5].r), 1);

  src = simde_mm_loadu_pd(test_vec[6].src);
  a = simde_mm_loadu_pd(test_vec[6].a);
  b = simde_mm_loadu_pd(test_vec[6].b);
  r = simde_mm_mask_roundscale_round_sd(src, test_vec[6].k, a, b, INT32_C(         113), INT32_C(           8));
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[6].r), 1);

  src = simde_mm_loadu_pd(test_vec[7].src);
  a = simde_mm_loadu_pd(test_vec[7].a);
  b = simde_mm_loadu_pd(test_vec[7].b);
  r = simde_mm_mask_roundscale_round_sd(src, test_vec[7].k, a, b, INT32_C(         242), INT32_C(           8));
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[7].r), 1);

  return 0;
#else
  fputc('\n', stdout);
  int round_type[5] = {SIMDE_MM_FROUND_TO_NEAREST_INT, SIMDE_MM_FROUND_TO_NEG_INF, SIMDE_MM_FROUND_TO_POS_INF, SIMDE_MM_FROUND_TO_ZERO, SIMDE_MM_FROUND_CUR_DIRECTION};
  for (int i = 0 ; i < 8 ; i++) {
    simde__m128d src = simde_test_x86_random_f64x2(SIMDE_FLOAT64_C(-1000.0), SIMDE_FLOAT64_C(1000.0));
    simde__mmask8 k = simde_test_x86_random_mmask8();
    simde__m128d a = simde_test_x86_random_f64x2(SIMDE_FLOAT64_C(-1000.0), SIMDE_FLOAT64_C(1000.0));
    simde__m128d b = simde_test_x86_random_f64x2(SIMDE_FLOAT64_C(-1000.0), SIMDE_FLOAT64_C(1000.0));
    if((simde_test_codegen_rand() & 1)) {
      if((simde_test_codegen_rand() & 1))
        b = simde_mm_mask_mov_pd(b, 1, simde_mm_set1_pd(SIMDE_MATH_NAN));
      else {
        if((simde_test_codegen_rand() & 1))
          b = simde_mm_mask_mov_pd(b, 1, simde_mm_set1_pd(SIMDE_MATH_INFINITY));
        else
          b = simde_mm_mask_mov_pd(b, 1, simde_mm_set1_pd(-SIMDE_MATH_INFINITY));
      }
    }
    int imm8 = (((simde_test_codegen_rand() & 15) << 4) | round_type[i % 5]) & 255;
    int sae = simde_test_codegen_rand() & 1 ? SIMDE_MM_FROUND_NO_EXC : SIMDE_MM_FROUND_CUR_DIRECTION;
    simde__m128d r;
    SIMDE_CONSTIFY_256_NEW(simde_mm_mask_roundscale_round_sd, r, simde_mm_setzero_pd(), imm8, sae, src, k, a, b);

    simde_test_x86_write_f64x2(2, src, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_mmask8(2, k, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_f64x2(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_f64x2(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i32(2, imm8, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i32(2, sae, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_f64x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm_maskz_roundscale_round_sd (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const simde__mmask8 k;
    const simde_float64 a[2];
    const simde_float64 b[2];
    const int32_t imm8;
    const int32_t sae;
    const simde_float64 r[2];
  } test_vec[] = {
    { UINT8_C( 24),
      { SIMDE_FLOAT64_C(   182.09), SIMDE_FLOAT64_C(  -254.56) },
      {        SIMDE_MATH_INFINITY, SIMDE_FLOAT64_C(  -862.84) },
       INT32_C(         208),
       INT32_C(           4),
      { SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(  -254.56) } },
    { UINT8_C(155),
      { SIMDE_FLOAT64_C(  -276.68), SIMDE_FLOAT64_C(  -318.19) },
      { SIMDE_FLOAT64_C(   579.53), SIMDE_FLOAT64_C(   929.18) },
       INT32_C(          97),
       INT32_C(           8),
      { SIMDE_FLOAT64_C(   579.52), SIMDE_FLOAT64_C(  -318.19) } },
    { UINT8_C( 46),
      { SIMDE_FLOAT64_C(   499.87), SIMDE_FLOAT64_C(  -856.43) },
      {        SIMDE_MATH_INFINITY, SIMDE_FLOAT64_C(   509.56) },
       INT32_C(         210),
       INT32_C(           8),
      { SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(  -856.43) } },
    { UINT8_C(127),
      { SIMDE_FLOAT64_C(   171.29), SIMDE_FLOAT64_C(  -814.14) },
      { SIMDE_FLOAT64_C(  -592.15), SIMDE_FLOAT64_C(  -646.63) },
       INT32_C(           3),
       INT32_C(           4),
      { SIMDE_FLOAT64_C(  -592.00), SIMDE_FLOAT64_C(  -814.14) } },
    { UINT8_C(  4),
      { SIMDE_FLOAT64_C(   426.00), SIMDE_FLOAT64_C(   297.22) },
      {        SIMDE_MATH_INFINITY, SIMDE_FLOAT64_C(   827.55) },
       INT32_C(         100),
       INT32_C(           4),
      { SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(   297.22) } },
    { UINT8_C( 33),
      { SIMDE_FLOAT64_C(   318.40), SIMDE_FLOAT64_C(     7.60) },
      {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(  -181.73) },
       INT32_C(          64),
       INT32_C(           4),
      {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(     7.60) } },
    { UINT8_C(188),
      { SIMDE_FLOAT64_C(  -686.65), SIMDE_FLOAT64_C(   152.96) },
      { SIMDE_FLOAT64_C(   752.21), SIMDE_FLOAT64_C(  -604.31) },
       INT32_C(         161),
       INT32_C(           4),
      { SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(   152.96) } },
    { UINT8_C(182),
      { SIMDE_FLOAT64_C(  -130.62), SIMDE_FLOAT64_C(   -92.45) },
      {        SIMDE_MATH_INFINITY, SIMDE_FLOAT64_C(  -441.39) },
       INT32_C(          66),
       INT32_C(           8),
      { SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(   -92.45) } },
  };

  simde__m128d a, b, r;

  a = simde_mm_loadu_pd(test_vec[0].a);
  b = simde_mm_loadu_pd(test_vec[0].b);
  r = simde_mm_maskz_roundscale_round_sd(test_vec[0].k, a, b, INT32_C(         208), INT32_C(           4));
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[0].r), 1);

  a = simde_mm_loadu_pd(test_vec[1].a);
  b = simde_mm_loadu_pd(test_vec[1].b);
  r = simde_mm_maskz_roundscale_round_sd(test_vec[1].k, a, b, INT32_C(          97), INT32_C(           8));
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[1].r), 1);

  a = simde_mm_loadu_pd(test_vec[2].a);
  b = simde_mm_loadu_pd(test_vec[2].b);
  r = simde_mm_maskz_roundscale_round_sd(test_vec[2].k, a, b, INT32_C(         210), INT32_C(           8));
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[2].r), 1);

  a = simde_mm_loadu_pd(test_vec[3].a);
  b = simde_mm_loadu_pd(test_vec[3].b);
  r = simde_mm_maskz_roundscale_round_sd(test_vec[3].k, a, b, INT32_C(           3), INT32_C(           4));
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[3].r), 1);

  a = simde_mm_loadu_pd(test_vec[4].a);
  b = simde_mm_loadu_pd(test_vec[4].b);
  r = simde_mm_maskz_roundscale_round_sd(test_vec[4].k, a, b, INT32_C(         100), INT32_C(           4));
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[4].r), 1);

  a = simde_mm_loadu_pd(test_vec[5].a);
  b = simde_mm_loadu_pd(test_vec[5].b);
  r = simde_mm_maskz_roundscale_round_sd(test_vec[5].k, a, b, INT32_C(          64), INT32_C(           4));
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[5].r), 1);

  a = simde_mm_loadu_pd(test_vec[6].a);
  b = simde_mm_loadu_pd(test_vec[6].b);
  r = simde_mm_maskz_roundscale_round_sd(test_vec[6].k, a, b, INT32_C(         161), INT32_C(           4));
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[6].r), 1);

  a = simde_mm_loadu_pd(test_vec[7].a);
  b = simde_mm_loadu_pd(test_vec[7].b);
  r = simde_mm_maskz_roundscale_round_sd(test_vec[7].k, a, b, INT32_C(          66), INT32_C(           8));
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[7].r), 1);

  return 0;
#else
  fputc('\n', stdout);
  int round_type[5] = {SIMDE_MM_FROUND_TO_NEAREST_INT, SIMDE_MM_FROUND_TO_NEG_INF, SIMDE_MM_FROUND_TO_POS_INF, SIMDE_MM_FROUND_TO_ZERO, SIMDE_MM_FROUND_CUR_DIRECTION};
  for (int i = 0 ; i < 8 ; i++) {
    simde__mmask8 k = simde_test_x86_random_mmask8();
    simde__m128d a = simde_test_x86_random_f64x2(SIMDE_FLOAT64_C(-1000.0), SIMDE_FLOAT64_C(1000.0));
    simde__m128d b = simde_test_x86_random_f64x2(SIMDE_FLOAT64_C(-1000.0), SIMDE_FLOAT64_C(1000.0));
    if((simde_test_codegen_rand() & 1)) {
      if((simde_test_codegen_rand() & 1))
        b = simde_mm_mask_mov_pd(b, 1, simde_mm_set1_pd(SIMDE_MATH_NAN));
      else {
        if((simde_test_codegen_rand() & 1))
          b = simde_mm_mask_mov_pd(b, 1, simde_mm_set1_pd(SIMDE_MATH_INFINITY));
        else
          b = simde_mm_mask_mov_pd(b, 1, simde_mm_set1_pd(-SIMDE_MATH_INFINITY));
      }
    }
    int imm8 = (((simde_test_codegen_rand() & 15) << 4) | round_type[i % 5]) & 255;
    int sae = (simde_test_codegen_rand() & 1) ? SIMDE_MM_FROUND_NO_EXC : SIMDE_MM_FROUND_CUR_DIRECTION;
    simde__m128d r;
    SIMDE_CONSTIFY_256_NEW(simde_mm_maskz_roundscale_round_sd, r, simde_mm_setzero_pd(), imm8, sae, k, a, b);

    simde_test_x86_write_mmask8(2, k, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_f64x2(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_f64x2(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i32(2, imm8, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i32(2, sae, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_f64x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

SIMDE_TEST_FUNC_LIST_BEGIN
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_roundscale_ps)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_mask_roundscale_ps)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_maskz_roundscale_ps)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm256_roundscale_ps)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm256_mask_roundscale_ps)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm256_maskz_roundscale_ps)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_roundscale_ps)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_mask_roundscale_ps)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_maskz_roundscale_ps)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_roundscale_round_ps)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_mask_roundscale_round_ps)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_maskz_roundscale_round_ps)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_roundscale_pd)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_mask_roundscale_pd)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_maskz_roundscale_pd)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm256_roundscale_pd)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm256_mask_roundscale_pd)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm256_maskz_roundscale_pd)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_roundscale_pd)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_mask_roundscale_pd)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_maskz_roundscale_pd)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_roundscale_round_pd)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_mask_roundscale_round_pd)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_maskz_roundscale_round_pd)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_roundscale_ss)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_mask_roundscale_ss)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_maskz_roundscale_ss)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_roundscale_round_ss)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_mask_roundscale_round_ss)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_maskz_roundscale_round_ss)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_roundscale_sd)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_mask_roundscale_sd)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_maskz_roundscale_sd)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_roundscale_round_sd)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_mask_roundscale_round_sd)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_maskz_roundscale_round_sd)
SIMDE_TEST_FUNC_LIST_END

#include <test/x86/avx512/test-avx512-footer.h>
