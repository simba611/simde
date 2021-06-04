#if !defined(SIMDE_X86_AVX512_TERNARYLOGIC_H)
#define SIMDE_X86_AVX512_TERNARYLOGIC_H

#include "types.h"

HEDLEY_DIAGNOSTIC_PUSH
SIMDE_DISABLE_UNWANTED_DIAGNOSTICS
SIMDE_BEGIN_DECLS_

SIMDE_FUNCTION_ATTRIBUTES
uint32_t
simde_x_mm_ternarylogic_impl_0x00_() {
  const uint32_t c0 = 0;
  return c0;
}

SIMDE_FUNCTION_ATTRIBUTES
uint32_t
simde_x_mm_ternarylogic_impl_0x01_(uint32_t a, uint32_t b, uint32_t c) {
  const uint32_t t0 = b | c;
  const uint32_t t1 = a | t0;
  const uint32_t t2 = ~t1;
  return t2;
}

SIMDE_FUNCTION_ATTRIBUTES
uint32_t
simde_x_mm_ternarylogic_impl_0x02_(uint32_t a, uint32_t b, uint32_t c) {
  const uint32_t t0 = b | a;
  const uint32_t t1 = ~t0;
  const uint32_t t2 = c & t1;
  return t2;
}

SIMDE_FUNCTION_ATTRIBUTES
uint32_t
simde_x_mm_ternarylogic_impl_0x03_(uint32_t a, uint32_t b) {
  const uint32_t t0 = b | a;
  const uint32_t t1 = ~t0;
  return t1;
}

SIMDE_FUNCTION_ATTRIBUTES
uint32_t
simde_x_mm_ternarylogic_impl_0x04_(uint32_t a, uint32_t b, uint32_t c) {
  const uint32_t t0 = a | c;
  const uint32_t t1 = ~t0;
  const uint32_t t2 = b & t1;
  return t2;
}

SIMDE_FUNCTION_ATTRIBUTES
uint32_t
simde_x_mm_ternarylogic_impl_0x05_(uint32_t a, uint32_t c) {
  const uint32_t t0 = c | a;
  const uint32_t t1 = ~t0;
  return t1;
}

SIMDE_FUNCTION_ATTRIBUTES
uint32_t
simde_x_mm_ternarylogic_impl_0x06_(uint32_t a, uint32_t b, uint32_t c) {
  const uint32_t t0 = ~a;
  const uint32_t t1 = b ^ c;
  const uint32_t t2 = t0 & t1;
  return t2;
}

SIMDE_FUNCTION_ATTRIBUTES
uint32_t
simde_x_mm_ternarylogic_impl_0x07_(uint32_t a, uint32_t b, uint32_t c) {
  const uint32_t t0 = b & c;
  const uint32_t t1 = a | t0;
  const uint32_t t2 = ~t1;
  return t2;
}

SIMDE_FUNCTION_ATTRIBUTES
uint32_t
simde_x_mm_ternarylogic_impl_0x08_(uint32_t a, uint32_t b, uint32_t c) {
  const uint32_t t0 = ~a;
  const uint32_t t1 = t0 & b;
  const uint32_t t2 = t1 & c;
  return t2;
}

SIMDE_FUNCTION_ATTRIBUTES
uint32_t
simde_x_mm_ternarylogic_impl_0x09_(uint32_t a, uint32_t b, uint32_t c) {
  const uint32_t t0 = b ^ c;
  const uint32_t t1 = a | t0;
  const uint32_t t2 = ~t1;
  return t2;
}

SIMDE_FUNCTION_ATTRIBUTES
uint32_t
simde_x_mm_ternarylogic_impl_0x0a_(uint32_t a, uint32_t c) {
  const uint32_t t0 = ~a;
  const uint32_t t1 = c & t0;
  return t1;
}

SIMDE_FUNCTION_ATTRIBUTES
uint32_t
simde_x_mm_ternarylogic_impl_0x0b_(uint32_t a, uint32_t b, uint32_t c) {
  const uint32_t t0 = ~a;
  const uint32_t c1 = UINT32_C(-1);
  const uint32_t t1 = b ^ c1;
  const uint32_t t2 = t1 | c;
  const uint32_t t3 = t0 & t2;
  return t3;
}

SIMDE_FUNCTION_ATTRIBUTES
uint32_t
simde_x_mm_ternarylogic_impl_0x0c_(uint32_t a, uint32_t b) {
  const uint32_t t0 = ~a;
  const uint32_t t1 = b & t0;
  return t1;
}

SIMDE_FUNCTION_ATTRIBUTES
uint32_t
simde_x_mm_ternarylogic_impl_0x0d_(uint32_t a, uint32_t b, uint32_t c) {
  const uint32_t t0 = ~a;
  const uint32_t c1 = UINT32_C(-1);
  const uint32_t t1 = c ^ c1;
  const uint32_t t2 = b | t1;
  const uint32_t t3 = t0 & t2;
  return t3;
}

SIMDE_FUNCTION_ATTRIBUTES
uint32_t
simde_x_mm_ternarylogic_impl_0x0e_(uint32_t a, uint32_t b, uint32_t c) {
  const uint32_t t0 = ~a;
  const uint32_t t1 = b | c;
  const uint32_t t2 = t0 & t1;
  return t2;
}

SIMDE_FUNCTION_ATTRIBUTES
uint32_t
simde_x_mm_ternarylogic_impl_0x0f_(uint32_t a) {
  const uint32_t t0 = ~a;
  return t0;
}

SIMDE_FUNCTION_ATTRIBUTES
uint32_t
simde_x_mm_ternarylogic_impl_0x10_(uint32_t a, uint32_t b, uint32_t c) {
  const uint32_t t0 = b | c;
  const uint32_t t1 = ~t0;
  const uint32_t t2 = a & t1;
  return t2;
}

SIMDE_FUNCTION_ATTRIBUTES
uint32_t
simde_x_mm_ternarylogic_impl_0x11_(uint32_t b, uint32_t c) {
  const uint32_t t0 = c | b;
  const uint32_t t1 = ~t0;
  return t1;
}

SIMDE_FUNCTION_ATTRIBUTES
uint32_t
simde_x_mm_ternarylogic_impl_0x12_(uint32_t a, uint32_t b, uint32_t c) {
  const uint32_t t0 = ~b;
  const uint32_t t1 = a ^ c;
  const uint32_t t2 = t0 & t1;
  return t2;
}

SIMDE_FUNCTION_ATTRIBUTES
uint32_t
simde_x_mm_ternarylogic_impl_0x13_(uint32_t a, uint32_t b, uint32_t c) {
  const uint32_t t0 = a & c;
  const uint32_t t1 = b | t0;
  const uint32_t t2 = ~t1;
  return t2;
}

SIMDE_FUNCTION_ATTRIBUTES
uint32_t
simde_x_mm_ternarylogic_impl_0x14_(uint32_t a, uint32_t b, uint32_t c) {
  const uint32_t t0 = ~c;
  const uint32_t t1 = a ^ b;
  const uint32_t t2 = t0 & t1;
  return t2;
}

SIMDE_FUNCTION_ATTRIBUTES
uint32_t
simde_x_mm_ternarylogic_impl_0x15_(uint32_t a, uint32_t b, uint32_t c) {
  const uint32_t t0 = b & a;
  const uint32_t t1 = c | t0;
  const uint32_t t2 = ~t1;
  return t2;
}

SIMDE_FUNCTION_ATTRIBUTES
uint32_t
simde_x_mm_ternarylogic_impl_0x16_(uint32_t a, uint32_t b, uint32_t c) {
  const uint32_t t0 = b | c;
  const uint32_t t1 = ~t0;
  const uint32_t t2 = a & t1;
  const uint32_t t3 = ~a;
  const uint32_t t4 = b ^ c;
  const uint32_t t5 = t3 & t4;
  const uint32_t t6 = t2 | t5;
  return t6;
}

SIMDE_FUNCTION_ATTRIBUTES
uint32_t
simde_x_mm_ternarylogic_impl_0x17_(uint32_t a, uint32_t b, uint32_t c) {
  const uint32_t t0 = b | c;
  const uint32_t t1 = b & c;
  const uint32_t t2 = (a & t0) | (~a & t1);
  const uint32_t t3 = ~t2;
  return t3;
}

SIMDE_FUNCTION_ATTRIBUTES
uint32_t
simde_x_mm_ternarylogic_impl_0x18_(uint32_t a, uint32_t b, uint32_t c) {
  const uint32_t t0 = a ^ b;
  const uint32_t t1 = a ^ c;
  const uint32_t t2 = t0 & t1;
  return t2;
}

SIMDE_FUNCTION_ATTRIBUTES
uint32_t
simde_x_mm_ternarylogic_impl_0x19_(uint32_t a, uint32_t b, uint32_t c) {
  const uint32_t t0 = b ^ c;
  const uint32_t t1 = b & c;
  const uint32_t t2 = a & t1;
  const uint32_t t3 = t0 ^ t2;
  const uint32_t t4 = ~t3;
  return t4;
}

SIMDE_FUNCTION_ATTRIBUTES
uint32_t
simde_x_mm_ternarylogic_impl_0x1a_(uint32_t a, uint32_t b, uint32_t c) {
  const uint32_t t0 = a & b;
  const uint32_t t1 = ~t0;
  const uint32_t t2 = a ^ c;
  const uint32_t t3 = t1 & t2;
  return t3;
}

SIMDE_FUNCTION_ATTRIBUTES
uint32_t
simde_x_mm_ternarylogic_impl_0x1b_(uint32_t a, uint32_t b, uint32_t c) {
  const uint32_t t0 = ~a;
  const uint32_t t1 = c & t0;
  const uint32_t t2 = ~c;
  const uint32_t t3 = ~b;
  const uint32_t t4 = t2 & t3;
  const uint32_t t5 = t1 | t4;
  return t5;
}

SIMDE_FUNCTION_ATTRIBUTES
uint32_t
simde_x_mm_ternarylogic_impl_0x1c_(uint32_t a, uint32_t b, uint32_t c) {
  const uint32_t t0 = a & c;
  const uint32_t t1 = ~t0;
  const uint32_t t2 = a ^ b;
  const uint32_t t3 = t1 & t2;
  return t3;
}

SIMDE_FUNCTION_ATTRIBUTES
uint32_t
simde_x_mm_ternarylogic_impl_0x1d_(uint32_t a, uint32_t b, uint32_t c) {
  const uint32_t t0 = ~a;
  const uint32_t t1 = b & t0;
  const uint32_t t2 = ~b;
  const uint32_t t3 = ~c;
  const uint32_t t4 = t2 & t3;
  const uint32_t t5 = t1 | t4;
  return t5;
}

SIMDE_FUNCTION_ATTRIBUTES
uint32_t
simde_x_mm_ternarylogic_impl_0x1e_(uint32_t a, uint32_t b, uint32_t c) {
  const uint32_t t0 = b | c;
  const uint32_t t1 = a ^ t0;
  return t1;
}

SIMDE_FUNCTION_ATTRIBUTES
uint32_t
simde_x_mm_ternarylogic_impl_0x1f_(uint32_t a, uint32_t b, uint32_t c) {
  const uint32_t t0 = b | c;
  const uint32_t t1 = a & t0;
  const uint32_t t2 = ~t1;
  return t2;
}

SIMDE_FUNCTION_ATTRIBUTES
uint32_t
simde_x_mm_ternarylogic_impl_0x20_(uint32_t a, uint32_t b, uint32_t c) {
  const uint32_t t0 = ~b;
  const uint32_t t1 = t0 & a;
  const uint32_t t2 = t1 & c;
  return t2;
}

SIMDE_FUNCTION_ATTRIBUTES
uint32_t
simde_x_mm_ternarylogic_impl_0x21_(uint32_t a, uint32_t b, uint32_t c) {
  const uint32_t t0 = a ^ c;
  const uint32_t t1 = b | t0;
  const uint32_t t2 = ~t1;
  return t2;
}

SIMDE_FUNCTION_ATTRIBUTES
uint32_t
simde_x_mm_ternarylogic_impl_0x22_(uint32_t b, uint32_t c) {
  const uint32_t t0 = ~b;
  const uint32_t t1 = c & t0;
  return t1;
}

SIMDE_FUNCTION_ATTRIBUTES
uint32_t
simde_x_mm_ternarylogic_impl_0x23_(uint32_t a, uint32_t b, uint32_t c) {
  const uint32_t t0 = ~b;
  const uint32_t c1 = UINT32_C(-1);
  const uint32_t t1 = a ^ c1;
  const uint32_t t2 = t1 | c;
  const uint32_t t3 = t0 & t2;
  return t3;
}

SIMDE_FUNCTION_ATTRIBUTES
uint32_t
simde_x_mm_ternarylogic_impl_0x24_(uint32_t a, uint32_t b, uint32_t c) {
  const uint32_t t0 = a ^ b;
  const uint32_t t1 = b ^ c;
  const uint32_t t2 = t0 & t1;
  return t2;
}

SIMDE_FUNCTION_ATTRIBUTES
uint32_t
simde_x_mm_ternarylogic_impl_0x25_(uint32_t a, uint32_t b, uint32_t c) {
  const uint32_t t0 = a & b;
  const uint32_t t1 = ~t0;
  const uint32_t c1 = UINT32_C(-1);
  const uint32_t t2 = c ^ c1;
  const uint32_t t3 = a ^ t2;
  const uint32_t t4 = t1 & t3;
  return t4;
}

SIMDE_FUNCTION_ATTRIBUTES
uint32_t
simde_x_mm_ternarylogic_impl_0x26_(uint32_t a, uint32_t b, uint32_t c) {
  const uint32_t t0 = a & b;
  const uint32_t t1 = ~t0;
  const uint32_t t2 = b ^ c;
  const uint32_t t3 = t1 & t2;
  return t3;
}

SIMDE_FUNCTION_ATTRIBUTES
uint32_t
simde_x_mm_ternarylogic_impl_0x27_(uint32_t a, uint32_t b, uint32_t c) {
  const uint32_t t0 = ~b;
  const uint32_t t1 = c & t0;
  const uint32_t t2 = ~c;
  const uint32_t t3 = ~a;
  const uint32_t t4 = t2 & t3;
  const uint32_t t5 = t1 | t4;
  return t5;
}

SIMDE_FUNCTION_ATTRIBUTES
uint32_t
simde_x_mm_ternarylogic_impl_0x28_(uint32_t a, uint32_t b, uint32_t c) {
  const uint32_t t0 = b ^ a;
  const uint32_t t1 = c & t0;
  return t1;
}

SIMDE_FUNCTION_ATTRIBUTES
uint32_t
simde_x_mm_ternarylogic_impl_0x29_(uint32_t a, uint32_t b, uint32_t c) {
  const uint32_t t0 = b ^ a;
  const uint32_t t1 = c & t0;
  const uint32_t t2 = ~c;
  const uint32_t t3 = b | a;
  const uint32_t t4 = ~t3;
  const uint32_t t5 = t2 & t4;
  const uint32_t t6 = t1 | t5;
  return t6;
}

SIMDE_FUNCTION_ATTRIBUTES
uint32_t
simde_x_mm_ternarylogic_impl_0x2a_(uint32_t a, uint32_t b, uint32_t c) {
  const uint32_t t0 = b & a;
  const uint32_t t1 = ~t0;
  const uint32_t t2 = c & t1;
  return t2;
}

SIMDE_FUNCTION_ATTRIBUTES
uint32_t
simde_x_mm_ternarylogic_impl_0x2b_(uint32_t a, uint32_t b, uint32_t c) {
  const uint32_t t0 = b & a;
  const uint32_t t1 = ~t0;
  const uint32_t t2 = c & t1;
  const uint32_t t3 = ~c;
  const uint32_t t4 = b | a;
  const uint32_t t5 = ~t4;
  const uint32_t t6 = t3 & t5;
  const uint32_t t7 = t2 | t6;
  return t7;
}

SIMDE_FUNCTION_ATTRIBUTES
uint32_t
simde_x_mm_ternarylogic_impl_0x2c_(uint32_t a, uint32_t b, uint32_t c) {
  const uint32_t t0 = b | c;
  const uint32_t t1 = a ^ b;
  const uint32_t t2 = t0 & t1;
  return t2;
}

SIMDE_FUNCTION_ATTRIBUTES
uint32_t
simde_x_mm_ternarylogic_impl_0x2d_(uint32_t a, uint32_t b, uint32_t c) {
  const uint32_t t0 = ~c;
  const uint32_t t1 = b | t0;
  const uint32_t t2 = a ^ t1;
  return t2;
}

SIMDE_FUNCTION_ATTRIBUTES
uint32_t
simde_x_mm_ternarylogic_impl_0x2e_(uint32_t a, uint32_t b, uint32_t c) {
  const uint32_t t0 = b | c;
  const uint32_t t1 = a & b;
  const uint32_t t2 = t0 ^ t1;
  return t2;
}

SIMDE_FUNCTION_ATTRIBUTES
uint32_t
simde_x_mm_ternarylogic_impl_0x2f_(uint32_t a, uint32_t b, uint32_t c) {
  const uint32_t t0 = ~a;
  const uint32_t t1 = ~b;
  const uint32_t t2 = t1 & c;
  const uint32_t t3 = t0 | t2;
  return t3;
}

SIMDE_FUNCTION_ATTRIBUTES
uint32_t
simde_x_mm_ternarylogic_impl_0x30_(uint32_t a, uint32_t b) {
  const uint32_t t0 = ~b;
  const uint32_t t1 = a & t0;
  return t1;
}

SIMDE_FUNCTION_ATTRIBUTES
uint32_t
simde_x_mm_ternarylogic_impl_0x31_(uint32_t a, uint32_t b, uint32_t c) {
  const uint32_t t0 = ~b;
  const uint32_t c1 = UINT32_C(-1);
  const uint32_t t1 = c ^ c1;
  const uint32_t t2 = a | t1;
  const uint32_t t3 = t0 & t2;
  return t3;
}

SIMDE_FUNCTION_ATTRIBUTES
uint32_t
simde_x_mm_ternarylogic_impl_0x32_(uint32_t a, uint32_t b, uint32_t c) {
  const uint32_t t0 = ~b;
  const uint32_t t1 = a | c;
  const uint32_t t2 = t0 & t1;
  return t2;
}

SIMDE_FUNCTION_ATTRIBUTES
uint32_t
simde_x_mm_ternarylogic_impl_0x33_(uint32_t b) {
  const uint32_t t0 = ~b;
  return t0;
}

SIMDE_FUNCTION_ATTRIBUTES
uint32_t
simde_x_mm_ternarylogic_impl_0x34_(uint32_t a, uint32_t b, uint32_t c) {
  const uint32_t t0 = b & c;
  const uint32_t t1 = ~t0;
  const uint32_t t2 = a ^ b;
  const uint32_t t3 = t1 & t2;
  return t3;
}

SIMDE_FUNCTION_ATTRIBUTES
uint32_t
simde_x_mm_ternarylogic_impl_0x35_(uint32_t a, uint32_t b, uint32_t c) {
  const uint32_t t0 = ~b;
  const uint32_t t1 = a & t0;
  const uint32_t t2 = ~a;
  const uint32_t t3 = ~c;
  const uint32_t t4 = t2 & t3;
  const uint32_t t5 = t1 | t4;
  return t5;
}

SIMDE_FUNCTION_ATTRIBUTES
uint32_t
simde_x_mm_ternarylogic_impl_0x36_(uint32_t a, uint32_t b, uint32_t c) {
  const uint32_t t0 = a | c;
  const uint32_t t1 = b ^ t0;
  return t1;
}

SIMDE_FUNCTION_ATTRIBUTES
uint32_t
simde_x_mm_ternarylogic_impl_0x37_(uint32_t a, uint32_t b, uint32_t c) {
  const uint32_t t0 = a | c;
  const uint32_t t1 = b & t0;
  const uint32_t t2 = ~t1;
  return t2;
}

SIMDE_FUNCTION_ATTRIBUTES
uint32_t
simde_x_mm_ternarylogic_impl_0x38_(uint32_t a, uint32_t b, uint32_t c) {
  const uint32_t t0 = a | c;
  const uint32_t t1 = a ^ b;
  const uint32_t t2 = t0 & t1;
  return t2;
}

SIMDE_FUNCTION_ATTRIBUTES
uint32_t
simde_x_mm_ternarylogic_impl_0x39_(uint32_t a, uint32_t b, uint32_t c) {
  const uint32_t c1 = UINT32_C(-1);
  const uint32_t t0 = c ^ c1;
  const uint32_t t1 = a | t0;
  const uint32_t t2 = b ^ t1;
  return t2;
}

SIMDE_FUNCTION_ATTRIBUTES
uint32_t
simde_x_mm_ternarylogic_impl_0x3a_(uint32_t a, uint32_t b, uint32_t c) {
  const uint32_t t0 = ~b;
  const uint32_t t1 = a & t0;
  const uint32_t t2 = ~a;
  const uint32_t t3 = t2 & c;
  const uint32_t t4 = t1 | t3;
  return t4;
}

SIMDE_FUNCTION_ATTRIBUTES
uint32_t
simde_x_mm_ternarylogic_impl_0x3b_(uint32_t a, uint32_t b, uint32_t c) {
  const uint32_t t0 = ~a;
  const uint32_t t1 = t0 & c;
  const uint32_t c1 = UINT32_C(-1);
  const uint32_t t2 = b ^ c1;
  const uint32_t t3 = t1 | t2;
  return t3;
}

SIMDE_FUNCTION_ATTRIBUTES
uint32_t
simde_x_mm_ternarylogic_impl_0x3c_(uint32_t a, uint32_t b) {
  const uint32_t t0 = b ^ a;
  return t0;
}

SIMDE_FUNCTION_ATTRIBUTES
uint32_t
simde_x_mm_ternarylogic_impl_0x3d_(uint32_t a, uint32_t b, uint32_t c) {
  const uint32_t t0 = a ^ b;
  const uint32_t t1 = a | c;
  const uint32_t t2 = ~t1;
  const uint32_t t3 = t0 | t2;
  return t3;
}

SIMDE_FUNCTION_ATTRIBUTES
uint32_t
simde_x_mm_ternarylogic_impl_0x3e_(uint32_t a, uint32_t b, uint32_t c) {
  const uint32_t t0 = ~a;
  const uint32_t t1 = t0 & c;
  const uint32_t t2 = a ^ b;
  const uint32_t t3 = t1 | t2;
  return t3;
}

SIMDE_FUNCTION_ATTRIBUTES
uint32_t
simde_x_mm_ternarylogic_impl_0x3f_(uint32_t a, uint32_t b) {
  const uint32_t t0 = b & a;
  const uint32_t t1 = ~t0;
  return t1;
}

SIMDE_FUNCTION_ATTRIBUTES
uint32_t
simde_x_mm_ternarylogic_impl_0x40_(uint32_t a, uint32_t b, uint32_t c) {
  const uint32_t t0 = ~c;
  const uint32_t t1 = t0 & a;
  const uint32_t t2 = t1 & b;
  return t2;
}

SIMDE_FUNCTION_ATTRIBUTES
uint32_t
simde_x_mm_ternarylogic_impl_0x41_(uint32_t a, uint32_t b, uint32_t c) {
  const uint32_t t0 = b ^ a;
  const uint32_t t1 = c | t0;
  const uint32_t t2 = ~t1;
  return t2;
}

SIMDE_FUNCTION_ATTRIBUTES
uint32_t
simde_x_mm_ternarylogic_impl_0x42_(uint32_t a, uint32_t b, uint32_t c) {
  const uint32_t t0 = a ^ c;
  const uint32_t t1 = b ^ c;
  const uint32_t t2 = t0 & t1;
  return t2;
}

SIMDE_FUNCTION_ATTRIBUTES
uint32_t
simde_x_mm_ternarylogic_impl_0x43_(uint32_t a, uint32_t b, uint32_t c) {
  const uint32_t t0 = a & c;
  const uint32_t t1 = ~t0;
  const uint32_t c1 = UINT32_C(-1);
  const uint32_t t2 = b ^ c1;
  const uint32_t t3 = a ^ t2;
  const uint32_t t4 = t1 & t3;
  return t4;
}

SIMDE_FUNCTION_ATTRIBUTES
uint32_t
simde_x_mm_ternarylogic_impl_0x44_(uint32_t b, uint32_t c) {
  const uint32_t t0 = ~c;
  const uint32_t t1 = b & t0;
  return t1;
}

SIMDE_FUNCTION_ATTRIBUTES
uint32_t
simde_x_mm_ternarylogic_impl_0x45_(uint32_t a, uint32_t b, uint32_t c) {
  const uint32_t t0 = ~c;
  const uint32_t c1 = UINT32_C(-1);
  const uint32_t t1 = a ^ c1;
  const uint32_t t2 = t1 | b;
  const uint32_t t3 = t0 & t2;
  return t3;
}

SIMDE_FUNCTION_ATTRIBUTES
uint32_t
simde_x_mm_ternarylogic_impl_0x46_(uint32_t a, uint32_t b, uint32_t c) {
  const uint32_t t0 = a & c;
  const uint32_t t1 = ~t0;
  const uint32_t t2 = b ^ c;
  const uint32_t t3 = t1 & t2;
  return t3;
}

SIMDE_FUNCTION_ATTRIBUTES
uint32_t
simde_x_mm_ternarylogic_impl_0x47_(uint32_t a, uint32_t b, uint32_t c) {
  const uint32_t t0 = ~c;
  const uint32_t t1 = b & t0;
  const uint32_t t2 = ~b;
  const uint32_t t3 = ~a;
  const uint32_t t4 = t2 & t3;
  const uint32_t t5 = t1 | t4;
  return t5;
}

SIMDE_FUNCTION_ATTRIBUTES
uint32_t
simde_x_mm_ternarylogic_impl_0x48_(uint32_t a, uint32_t b, uint32_t c) {
  const uint32_t t0 = a ^ c;
  const uint32_t t1 = b & t0;
  return t1;
}

SIMDE_FUNCTION_ATTRIBUTES
uint32_t
simde_x_mm_ternarylogic_impl_0x49_(uint32_t a, uint32_t b, uint32_t c) {
  const uint32_t t0 = a ^ c;
  const uint32_t t1 = b & t0;
  const uint32_t t2 = ~b;
  const uint32_t t3 = a | c;
  const uint32_t t4 = ~t3;
  const uint32_t t5 = t2 & t4;
  const uint32_t t6 = t1 | t5;
  return t6;
}

SIMDE_FUNCTION_ATTRIBUTES
uint32_t
simde_x_mm_ternarylogic_impl_0x4a_(uint32_t a, uint32_t b, uint32_t c) {
  const uint32_t t0 = b | c;
  const uint32_t t1 = a ^ c;
  const uint32_t t2 = t0 & t1;
  return t2;
}

SIMDE_FUNCTION_ATTRIBUTES
uint32_t
simde_x_mm_ternarylogic_impl_0x4b_(uint32_t a, uint32_t b, uint32_t c) {
  const uint32_t t0 = ~b;
  const uint32_t t1 = t0 | c;
  const uint32_t t2 = a ^ t1;
  return t2;
}

SIMDE_FUNCTION_ATTRIBUTES
uint32_t
simde_x_mm_ternarylogic_impl_0x4c_(uint32_t a, uint32_t b, uint32_t c) {
  const uint32_t t0 = a & c;
  const uint32_t t1 = ~t0;
  const uint32_t t2 = b & t1;
  return t2;
}

SIMDE_FUNCTION_ATTRIBUTES
uint32_t
simde_x_mm_ternarylogic_impl_0x4d_(uint32_t a, uint32_t b, uint32_t c) {
  const uint32_t t0 = a & c;
  const uint32_t t1 = ~t0;
  const uint32_t t2 = b & t1;
  const uint32_t t3 = ~b;
  const uint32_t t4 = a | c;
  const uint32_t t5 = ~t4;
  const uint32_t t6 = t3 & t5;
  const uint32_t t7 = t2 | t6;
  return t7;
}

SIMDE_FUNCTION_ATTRIBUTES
uint32_t
simde_x_mm_ternarylogic_impl_0x4e_(uint32_t a, uint32_t b, uint32_t c) {
  const uint32_t t0 = ~a;
  const uint32_t t1 = c & t0;
  const uint32_t t2 = ~c;
  const uint32_t t3 = t2 & b;
  const uint32_t t4 = t1 | t3;
  return t4;
}

SIMDE_FUNCTION_ATTRIBUTES
uint32_t
simde_x_mm_ternarylogic_impl_0x4f_(uint32_t a, uint32_t b, uint32_t c) {
  const uint32_t t0 = ~a;
  const uint32_t t1 = ~c;
  const uint32_t t2 = b & t1;
  const uint32_t t3 = t0 | t2;
  return t3;
}

SIMDE_FUNCTION_ATTRIBUTES
uint32_t
simde_x_mm_ternarylogic_impl_0x50_(uint32_t a, uint32_t c) {
  const uint32_t t0 = ~c;
  const uint32_t t1 = a & t0;
  return t1;
}

SIMDE_FUNCTION_ATTRIBUTES
uint32_t
simde_x_mm_ternarylogic_impl_0x51_(uint32_t a, uint32_t b, uint32_t c) {
  const uint32_t t0 = ~c;
  const uint32_t c1 = UINT32_C(-1);
  const uint32_t t1 = b ^ c1;
  const uint32_t t2 = a | t1;
  const uint32_t t3 = t0 & t2;
  return t3;
}

SIMDE_FUNCTION_ATTRIBUTES
uint32_t
simde_x_mm_ternarylogic_impl_0x52_(uint32_t a, uint32_t b, uint32_t c) {
  const uint32_t t0 = b & c;
  const uint32_t t1 = ~t0;
  const uint32_t t2 = a ^ c;
  const uint32_t t3 = t1 & t2;
  return t3;
}

SIMDE_FUNCTION_ATTRIBUTES
uint32_t
simde_x_mm_ternarylogic_impl_0x53_(uint32_t a, uint32_t b, uint32_t c) {
  const uint32_t t0 = ~c;
  const uint32_t t1 = a & t0;
  const uint32_t t2 = ~a;
  const uint32_t t3 = ~b;
  const uint32_t t4 = t2 & t3;
  const uint32_t t5 = t1 | t4;
  return t5;
}

SIMDE_FUNCTION_ATTRIBUTES
uint32_t
simde_x_mm_ternarylogic_impl_0x54_(uint32_t a, uint32_t b, uint32_t c) {
  const uint32_t t0 = ~c;
  const uint32_t t1 = a | b;
  const uint32_t t2 = t0 & t1;
  return t2;
}

SIMDE_FUNCTION_ATTRIBUTES
uint32_t
simde_x_mm_ternarylogic_impl_0x55_(uint32_t c) {
  const uint32_t t0 = ~c;
  return t0;
}

SIMDE_FUNCTION_ATTRIBUTES
uint32_t
simde_x_mm_ternarylogic_impl_0x56_(uint32_t a, uint32_t b, uint32_t c) {
  const uint32_t t0 = b | a;
  const uint32_t t1 = c ^ t0;
  return t1;
}

SIMDE_FUNCTION_ATTRIBUTES
uint32_t
simde_x_mm_ternarylogic_impl_0x57_(uint32_t a, uint32_t b, uint32_t c) {
  const uint32_t t0 = b | a;
  const uint32_t t1 = c & t0;
  const uint32_t t2 = ~t1;
  return t2;
}

SIMDE_FUNCTION_ATTRIBUTES
uint32_t
simde_x_mm_ternarylogic_impl_0x58_(uint32_t a, uint32_t b, uint32_t c) {
  const uint32_t t0 = a | b;
  const uint32_t t1 = a ^ c;
  const uint32_t t2 = t0 & t1;
  return t2;
}

SIMDE_FUNCTION_ATTRIBUTES
uint32_t
simde_x_mm_ternarylogic_impl_0x59_(uint32_t a, uint32_t b, uint32_t c) {
  const uint32_t c1 = UINT32_C(-1);
  const uint32_t t0 = b ^ c1;
  const uint32_t t1 = a | t0;
  const uint32_t t2 = c ^ t1;
  return t2;
}

SIMDE_FUNCTION_ATTRIBUTES
uint32_t
simde_x_mm_ternarylogic_impl_0x5a_(uint32_t a, uint32_t c) {
  const uint32_t t0 = c ^ a;
  return t0;
}

SIMDE_FUNCTION_ATTRIBUTES
uint32_t
simde_x_mm_ternarylogic_impl_0x5b_(uint32_t a, uint32_t b, uint32_t c) {
  const uint32_t t0 = a ^ c;
  const uint32_t t1 = a | b;
  const uint32_t c1 = UINT32_C(-1);
  const uint32_t t2 = t1 ^ c1;
  const uint32_t t3 = t0 | t2;
  return t3;
}

SIMDE_FUNCTION_ATTRIBUTES
uint32_t
simde_x_mm_ternarylogic_impl_0x5c_(uint32_t a, uint32_t b, uint32_t c) {
  const uint32_t t0 = ~c;
  const uint32_t t1 = a & t0;
  const uint32_t t2 = ~a;
  const uint32_t t3 = t2 & b;
  const uint32_t t4 = t1 | t3;
  return t4;
}

SIMDE_FUNCTION_ATTRIBUTES
uint32_t
simde_x_mm_ternarylogic_impl_0x5d_(uint32_t a, uint32_t b, uint32_t c) {
  const uint32_t t0 = ~c;
  const uint32_t t1 = ~a;
  const uint32_t t2 = t1 & b;
  const uint32_t t3 = t0 | t2;
  return t3;
}

SIMDE_FUNCTION_ATTRIBUTES
uint32_t
simde_x_mm_ternarylogic_impl_0x5e_(uint32_t a, uint32_t b, uint32_t c) {
  const uint32_t t0 = ~c;
  const uint32_t t1 = t0 & b;
  const uint32_t t2 = a ^ c;
  const uint32_t t3 = t1 | t2;
  return t3;
}

SIMDE_FUNCTION_ATTRIBUTES
uint32_t
simde_x_mm_ternarylogic_impl_0x5f_(uint32_t a, uint32_t c) {
  const uint32_t t0 = c & a;
  const uint32_t t1 = ~t0;
  return t1;
}

SIMDE_FUNCTION_ATTRIBUTES
uint32_t
simde_x_mm_ternarylogic_impl_0x60_(uint32_t a, uint32_t b, uint32_t c) {
  const uint32_t t0 = b ^ c;
  const uint32_t t1 = a & t0;
  return t1;
}

SIMDE_FUNCTION_ATTRIBUTES
uint32_t
simde_x_mm_ternarylogic_impl_0x61_(uint32_t a, uint32_t b, uint32_t c) {
  const uint32_t t0 = b ^ c;
  const uint32_t t1 = a & t0;
  const uint32_t t2 = ~a;
  const uint32_t t3 = b | c;
  const uint32_t t4 = ~t3;
  const uint32_t t5 = t2 & t4;
  const uint32_t t6 = t1 | t5;
  return t6;
}

SIMDE_FUNCTION_ATTRIBUTES
uint32_t
simde_x_mm_ternarylogic_impl_0x62_(uint32_t a, uint32_t b, uint32_t c) {
  const uint32_t t0 = a | c;
  const uint32_t t1 = b ^ c;
  const uint32_t t2 = t0 & t1;
  return t2;
}

SIMDE_FUNCTION_ATTRIBUTES
uint32_t
simde_x_mm_ternarylogic_impl_0x63_(uint32_t a, uint32_t b, uint32_t c) {
  const uint32_t c1 = UINT32_C(-1);
  const uint32_t t0 = a ^ c1;
  const uint32_t t1 = t0 | c;
  const uint32_t t2 = b ^ t1;
  return t2;
}

SIMDE_FUNCTION_ATTRIBUTES
uint32_t
simde_x_mm_ternarylogic_impl_0x64_(uint32_t a, uint32_t b, uint32_t c) {
  const uint32_t t0 = a | b;
  const uint32_t t1 = b ^ c;
  const uint32_t t2 = t0 & t1;
  return t2;
}

SIMDE_FUNCTION_ATTRIBUTES
uint32_t
simde_x_mm_ternarylogic_impl_0x65_(uint32_t a, uint32_t b, uint32_t c) {
  const uint32_t c1 = UINT32_C(-1);
  const uint32_t t0 = a ^ c1;
  const uint32_t t1 = t0 | b;
  const uint32_t t2 = c ^ t1;
  return t2;
}

SIMDE_FUNCTION_ATTRIBUTES
uint32_t
simde_x_mm_ternarylogic_impl_0x66_(uint32_t b, uint32_t c) {
  const uint32_t t0 = c ^ b;
  return t0;
}

SIMDE_FUNCTION_ATTRIBUTES
uint32_t
simde_x_mm_ternarylogic_impl_0x67_(uint32_t a, uint32_t b, uint32_t c) {
  const uint32_t t0 = b ^ c;
  const uint32_t t1 = a | b;
  const uint32_t t2 = ~t1;
  const uint32_t t3 = t0 | t2;
  return t3;
}

SIMDE_FUNCTION_ATTRIBUTES
uint32_t
simde_x_mm_ternarylogic_impl_0x68_(uint32_t a, uint32_t b, uint32_t c) {
  const uint32_t t0 = b ^ c;
  const uint32_t t1 = a & t0;
  const uint32_t t2 = ~a;
  const uint32_t t3 = b & c;
  const uint32_t t4 = t2 & t3;
  const uint32_t t5 = t1 | t4;
  return t5;
}

SIMDE_FUNCTION_ATTRIBUTES
uint32_t
simde_x_mm_ternarylogic_impl_0x69_(uint32_t a, uint32_t b, uint32_t c) {
  const uint32_t t0 = b ^ c;
  const uint32_t t1 = a ^ t0;
  const uint32_t t2 = ~t1;
  return t2;
}

SIMDE_FUNCTION_ATTRIBUTES
uint32_t
simde_x_mm_ternarylogic_impl_0x6a_(uint32_t a, uint32_t b, uint32_t c) {
  const uint32_t t0 = b & a;
  const uint32_t t1 = c ^ t0;
  return t1;
}

SIMDE_FUNCTION_ATTRIBUTES
uint32_t
simde_x_mm_ternarylogic_impl_0x6b_(uint32_t a, uint32_t b, uint32_t c) {
  const uint32_t t0 = ~a;
  const uint32_t t1 = t0 & c;
  const uint32_t c1 = UINT32_C(-1);
  const uint32_t t2 = a ^ c1;
  const uint32_t t3 = b ^ c;
  const uint32_t t4 = t2 ^ t3;
  const uint32_t t5 = t1 | t4;
  return t5;
}

SIMDE_FUNCTION_ATTRIBUTES
uint32_t
simde_x_mm_ternarylogic_impl_0x6c_(uint32_t a, uint32_t b, uint32_t c) {
  const uint32_t t0 = a & c;
  const uint32_t t1 = b ^ t0;
  return t1;
}

SIMDE_FUNCTION_ATTRIBUTES
uint32_t
simde_x_mm_ternarylogic_impl_0x6d_(uint32_t a, uint32_t b, uint32_t c) {
  const uint32_t t0 = ~a;
  const uint32_t t1 = t0 & b;
  const uint32_t c1 = UINT32_C(-1);
  const uint32_t t2 = a ^ c1;
  const uint32_t t3 = b ^ c;
  const uint32_t t4 = t2 ^ t3;
  const uint32_t t5 = t1 | t4;
  return t5;
}

SIMDE_FUNCTION_ATTRIBUTES
uint32_t
simde_x_mm_ternarylogic_impl_0x6e_(uint32_t a, uint32_t b, uint32_t c) {
  const uint32_t t0 = ~a;
  const uint32_t t1 = t0 & b;
  const uint32_t t2 = b ^ c;
  const uint32_t t3 = t1 | t2;
  return t3;
}

SIMDE_FUNCTION_ATTRIBUTES
uint32_t
simde_x_mm_ternarylogic_impl_0x6f_(uint32_t a, uint32_t b, uint32_t c) {
  const uint32_t t0 = b ^ c;
  const uint32_t c1 = UINT32_C(-1);
  const uint32_t t1 = a ^ c1;
  const uint32_t t2 = t0 | t1;
  return t2;
}

SIMDE_FUNCTION_ATTRIBUTES
uint32_t
simde_x_mm_ternarylogic_impl_0x70_(uint32_t a, uint32_t b, uint32_t c) {
  const uint32_t t0 = b & c;
  const uint32_t t1 = ~t0;
  const uint32_t t2 = a & t1;
  return t2;
}

SIMDE_FUNCTION_ATTRIBUTES
uint32_t
simde_x_mm_ternarylogic_impl_0x71_(uint32_t a, uint32_t b, uint32_t c) {
  const uint32_t t0 = b | c;
  const uint32_t t1 = ~t0;
  const uint32_t t2 = b ^ c;
  const uint32_t t3 = a & t2;
  const uint32_t t4 = t1 | t3;
  return t4;
}

SIMDE_FUNCTION_ATTRIBUTES
uint32_t
simde_x_mm_ternarylogic_impl_0x72_(uint32_t a, uint32_t b, uint32_t c) {
  const uint32_t t0 = ~b;
  const uint32_t t1 = c & t0;
  const uint32_t t2 = ~c;
  const uint32_t t3 = t2 & a;
  const uint32_t t4 = t1 | t3;
  return t4;
}

SIMDE_FUNCTION_ATTRIBUTES
uint32_t
simde_x_mm_ternarylogic_impl_0x73_(uint32_t a, uint32_t b, uint32_t c) {
  const uint32_t t0 = ~b;
  const uint32_t t1 = ~c;
  const uint32_t t2 = a & t1;
  const uint32_t t3 = t0 | t2;
  return t3;
}

SIMDE_FUNCTION_ATTRIBUTES
uint32_t
simde_x_mm_ternarylogic_impl_0x74_(uint32_t a, uint32_t b, uint32_t c) {
  const uint32_t t0 = ~c;
  const uint32_t t1 = b & t0;
  const uint32_t t2 = ~b;
  const uint32_t t3 = t2 & a;
  const uint32_t t4 = t1 | t3;
  return t4;
}

SIMDE_FUNCTION_ATTRIBUTES
uint32_t
simde_x_mm_ternarylogic_impl_0x75_(uint32_t a, uint32_t b, uint32_t c) {
  const uint32_t t0 = ~c;
  const uint32_t t1 = ~b;
  const uint32_t t2 = a & t1;
  const uint32_t t3 = t0 | t2;
  return t3;
}

SIMDE_FUNCTION_ATTRIBUTES
uint32_t
simde_x_mm_ternarylogic_impl_0x76_(uint32_t a, uint32_t b, uint32_t c) {
  const uint32_t t0 = ~b;
  const uint32_t t1 = t0 & a;
  const uint32_t t2 = b ^ c;
  const uint32_t t3 = t1 | t2;
  return t3;
}

SIMDE_FUNCTION_ATTRIBUTES
uint32_t
simde_x_mm_ternarylogic_impl_0x77_(uint32_t b, uint32_t c) {
  const uint32_t t0 = c & b;
  const uint32_t t1 = ~t0;
  return t1;
}

SIMDE_FUNCTION_ATTRIBUTES
uint32_t
simde_x_mm_ternarylogic_impl_0x78_(uint32_t a, uint32_t b, uint32_t c) {
  const uint32_t t0 = b & c;
  const uint32_t t1 = a ^ t0;
  return t1;
}

SIMDE_FUNCTION_ATTRIBUTES
uint32_t
simde_x_mm_ternarylogic_impl_0x79_(uint32_t a, uint32_t b, uint32_t c) {
  const uint32_t t0 = ~b;
  const uint32_t t1 = t0 & a;
  const uint32_t c1 = UINT32_C(-1);
  const uint32_t t2 = b ^ c1;
  const uint32_t t3 = a ^ c;
  const uint32_t t4 = t2 ^ t3;
  const uint32_t t5 = t1 | t4;
  return t5;
}

SIMDE_FUNCTION_ATTRIBUTES
uint32_t
simde_x_mm_ternarylogic_impl_0x7a_(uint32_t a, uint32_t b, uint32_t c) {
  const uint32_t t0 = ~b;
  const uint32_t t1 = t0 & a;
  const uint32_t t2 = a ^ c;
  const uint32_t t3 = t1 | t2;
  return t3;
}

SIMDE_FUNCTION_ATTRIBUTES
uint32_t
simde_x_mm_ternarylogic_impl_0x7b_(uint32_t a, uint32_t b, uint32_t c) {
  const uint32_t t0 = ~b;
  const uint32_t t1 = a ^ c;
  const uint32_t t2 = t0 | t1;
  return t2;
}

SIMDE_FUNCTION_ATTRIBUTES
uint32_t
simde_x_mm_ternarylogic_impl_0x7c_(uint32_t a, uint32_t b, uint32_t c) {
  const uint32_t t0 = ~c;
  const uint32_t t1 = t0 & a;
  const uint32_t t2 = a ^ b;
  const uint32_t t3 = t1 | t2;
  return t3;
}

SIMDE_FUNCTION_ATTRIBUTES
uint32_t
simde_x_mm_ternarylogic_impl_0x7d_(uint32_t a, uint32_t b, uint32_t c) {
  const uint32_t t0 = a ^ b;
  const uint32_t c1 = UINT32_C(-1);
  const uint32_t t1 = c ^ c1;
  const uint32_t t2 = t0 | t1;
  return t2;
}

SIMDE_FUNCTION_ATTRIBUTES
uint32_t
simde_x_mm_ternarylogic_impl_0x7e_(uint32_t a, uint32_t b, uint32_t c) {
  const uint32_t t0 = a ^ b;
  const uint32_t t1 = a ^ c;
  const uint32_t t2 = t0 | t1;
  return t2;
}

SIMDE_FUNCTION_ATTRIBUTES
uint32_t
simde_x_mm_ternarylogic_impl_0x7f_(uint32_t a, uint32_t b, uint32_t c) {
  const uint32_t t0 = a & b;
  const uint32_t t1 = t0 & c;
  const uint32_t c1 = UINT32_C(-1);
  const uint32_t t2 = t1 ^ c1;
  return t2;
}

#if defined(SIMDE_X86_AVX512VL_NATIVE) && defined(SIMDE_X86_AVX512F_NATIVE)
  #define simde_mm_ternarylogic_epi32(a, b, c, imm8) _mm_ternarylogic_epi32(a, b, c, imm8)
#else
  SIMDE_FUNCTION_ATTRIBUTES
  simde__m128i
  simde_mm_ternarylogic_epi32(simde__m128i a, simde__m128i b, simde__m128i c, int imm8)
      SIMDE_REQUIRE_CONSTANT_RANGE(imm8, 0, 255) {
    simde__m128i_private
      r_,
      a_ = simde__m128i_to_private(a),
      b_ = simde__m128i_to_private(b),
      c_ = simde__m128i_to_private(c);

    switch(((imm8 & 128) ? ~imm8 : imm8) & 127) {
      case 0:
        SIMDE_VECTORIZE
        for(size_t i = 0 ; i < (sizeof(r_.u32) / sizeof(r_.u32[0])) ; i++) {
          r_.u32[i] = simde_x_mm_ternarylogic_impl_0x00_();
        }
        break;
      case 1:
        SIMDE_VECTORIZE
        for(size_t i = 0 ; i < (sizeof(r_.u32) / sizeof(r_.u32[0])) ; i++) {
          r_.u32[i] = simde_x_mm_ternarylogic_impl_0x01_(a_.u32[i], b_.u32[i], c_.u32[i]);
        }
        break;
      case 2:
        SIMDE_VECTORIZE
        for(size_t i = 0 ; i < (sizeof(r_.u32) / sizeof(r_.u32[0])) ; i++) {
          r_.u32[i] = simde_x_mm_ternarylogic_impl_0x02_(a_.u32[i], b_.u32[i], c_.u32[i]);
        }
        break;
      case 3:
        SIMDE_VECTORIZE
        for(size_t i = 0 ; i < (sizeof(r_.u32) / sizeof(r_.u32[0])) ; i++) {
          r_.u32[i] = simde_x_mm_ternarylogic_impl_0x03_(a_.u32[i], b_.u32[i]);
        }
        break;
      case 4:
        SIMDE_VECTORIZE
        for(size_t i = 0 ; i < (sizeof(r_.u32) / sizeof(r_.u32[0])) ; i++) {
          r_.u32[i] = simde_x_mm_ternarylogic_impl_0x04_(a_.u32[i], b_.u32[i], c_.u32[i]);
        }
        break;
      case 5:
        SIMDE_VECTORIZE
        for(size_t i = 0 ; i < (sizeof(r_.u32) / sizeof(r_.u32[0])) ; i++) {
          r_.u32[i] = simde_x_mm_ternarylogic_impl_0x05_(a_.u32[i], c_.u32[i]);
        }
        break;
      case 6:
        SIMDE_VECTORIZE
        for(size_t i = 0 ; i < (sizeof(r_.u32) / sizeof(r_.u32[0])) ; i++) {
          r_.u32[i] = simde_x_mm_ternarylogic_impl_0x06_(a_.u32[i], b_.u32[i], c_.u32[i]);
        }
        break;
      case 7:
        SIMDE_VECTORIZE
        for(size_t i = 0 ; i < (sizeof(r_.u32) / sizeof(r_.u32[0])) ; i++) {
          r_.u32[i] = simde_x_mm_ternarylogic_impl_0x07_(a_.u32[i], b_.u32[i], c_.u32[i]);
        }
        break;
      case 8:
        SIMDE_VECTORIZE
        for(size_t i = 0 ; i < (sizeof(r_.u32) / sizeof(r_.u32[0])) ; i++) {
          r_.u32[i] = simde_x_mm_ternarylogic_impl_0x08_(a_.u32[i], b_.u32[i], c_.u32[i]);
        }
        break;
      case 9:
        SIMDE_VECTORIZE
        for(size_t i = 0 ; i < (sizeof(r_.u32) / sizeof(r_.u32[0])) ; i++) {
          r_.u32[i] = simde_x_mm_ternarylogic_impl_0x09_(a_.u32[i], b_.u32[i], c_.u32[i]);
        }
        break;
      case 10:
        SIMDE_VECTORIZE
        for(size_t i = 0 ; i < (sizeof(r_.u32) / sizeof(r_.u32[0])) ; i++) {
          r_.u32[i] = simde_x_mm_ternarylogic_impl_0x0a_(a_.u32[i], c_.u32[i]);
        }
        break;
      case 11:
        SIMDE_VECTORIZE
        for(size_t i = 0 ; i < (sizeof(r_.u32) / sizeof(r_.u32[0])) ; i++) {
          r_.u32[i] = simde_x_mm_ternarylogic_impl_0x0b_(a_.u32[i], b_.u32[i], c_.u32[i]);
        }
        break;
      case 12:
        SIMDE_VECTORIZE
        for(size_t i = 0 ; i < (sizeof(r_.u32) / sizeof(r_.u32[0])) ; i++) {
          r_.u32[i] = simde_x_mm_ternarylogic_impl_0x0c_(a_.u32[i], b_.u32[i]);
        }
        break;
      case 13:
        SIMDE_VECTORIZE
        for(size_t i = 0 ; i < (sizeof(r_.u32) / sizeof(r_.u32[0])) ; i++) {
          r_.u32[i] = simde_x_mm_ternarylogic_impl_0x0d_(a_.u32[i], b_.u32[i], c_.u32[i]);
        }
        break;
      case 14:
        SIMDE_VECTORIZE
        for(size_t i = 0 ; i < (sizeof(r_.u32) / sizeof(r_.u32[0])) ; i++) {
          r_.u32[i] = simde_x_mm_ternarylogic_impl_0x0e_(a_.u32[i], b_.u32[i], c_.u32[i]);
        }
        break;
      case 15:
        SIMDE_VECTORIZE
        for(size_t i = 0 ; i < (sizeof(r_.u32) / sizeof(r_.u32[0])) ; i++) {
          r_.u32[i] = simde_x_mm_ternarylogic_impl_0x0f_(a_.u32[i]);
        }
        break;
      case 16:
        SIMDE_VECTORIZE
        for(size_t i = 0 ; i < (sizeof(r_.u32) / sizeof(r_.u32[0])) ; i++) {
          r_.u32[i] = simde_x_mm_ternarylogic_impl_0x10_(a_.u32[i], b_.u32[i], c_.u32[i]);
        }
        break;
      case 17:
        SIMDE_VECTORIZE
        for(size_t i = 0 ; i < (sizeof(r_.u32) / sizeof(r_.u32[0])) ; i++) {
          r_.u32[i] = simde_x_mm_ternarylogic_impl_0x11_(b_.u32[i], c_.u32[i]);
        }
        break;
      case 18:
        SIMDE_VECTORIZE
        for(size_t i = 0 ; i < (sizeof(r_.u32) / sizeof(r_.u32[0])) ; i++) {
          r_.u32[i] = simde_x_mm_ternarylogic_impl_0x12_(a_.u32[i], b_.u32[i], c_.u32[i]);
        }
        break;
      case 19:
        SIMDE_VECTORIZE
        for(size_t i = 0 ; i < (sizeof(r_.u32) / sizeof(r_.u32[0])) ; i++) {
          r_.u32[i] = simde_x_mm_ternarylogic_impl_0x13_(a_.u32[i], b_.u32[i], c_.u32[i]);
        }
        break;
      case 20:
        SIMDE_VECTORIZE
        for(size_t i = 0 ; i < (sizeof(r_.u32) / sizeof(r_.u32[0])) ; i++) {
          r_.u32[i] = simde_x_mm_ternarylogic_impl_0x14_(a_.u32[i], b_.u32[i], c_.u32[i]);
        }
        break;
      case 21:
        SIMDE_VECTORIZE
        for(size_t i = 0 ; i < (sizeof(r_.u32) / sizeof(r_.u32[0])) ; i++) {
          r_.u32[i] = simde_x_mm_ternarylogic_impl_0x15_(a_.u32[i], b_.u32[i], c_.u32[i]);
        }
        break;
      case 22:
        SIMDE_VECTORIZE
        for(size_t i = 0 ; i < (sizeof(r_.u32) / sizeof(r_.u32[0])) ; i++) {
          r_.u32[i] = simde_x_mm_ternarylogic_impl_0x16_(a_.u32[i], b_.u32[i], c_.u32[i]);
        }
        break;
      case 23:
        SIMDE_VECTORIZE
        for(size_t i = 0 ; i < (sizeof(r_.u32) / sizeof(r_.u32[0])) ; i++) {
          r_.u32[i] = simde_x_mm_ternarylogic_impl_0x17_(a_.u32[i], b_.u32[i], c_.u32[i]);
        }
        break;
      case 24:
        SIMDE_VECTORIZE
        for(size_t i = 0 ; i < (sizeof(r_.u32) / sizeof(r_.u32[0])) ; i++) {
          r_.u32[i] = simde_x_mm_ternarylogic_impl_0x18_(a_.u32[i], b_.u32[i], c_.u32[i]);
        }
        break;
      case 25:
        SIMDE_VECTORIZE
        for(size_t i = 0 ; i < (sizeof(r_.u32) / sizeof(r_.u32[0])) ; i++) {
          r_.u32[i] = simde_x_mm_ternarylogic_impl_0x19_(a_.u32[i], b_.u32[i], c_.u32[i]);
        }
        break;
      case 26:
        SIMDE_VECTORIZE
        for(size_t i = 0 ; i < (sizeof(r_.u32) / sizeof(r_.u32[0])) ; i++) {
          r_.u32[i] = simde_x_mm_ternarylogic_impl_0x1a_(a_.u32[i], b_.u32[i], c_.u32[i]);
        }
        break;
      case 27:
        SIMDE_VECTORIZE
        for(size_t i = 0 ; i < (sizeof(r_.u32) / sizeof(r_.u32[0])) ; i++) {
          r_.u32[i] = simde_x_mm_ternarylogic_impl_0x1b_(a_.u32[i], b_.u32[i], c_.u32[i]);
        }
        break;
      case 28:
        SIMDE_VECTORIZE
        for(size_t i = 0 ; i < (sizeof(r_.u32) / sizeof(r_.u32[0])) ; i++) {
          r_.u32[i] = simde_x_mm_ternarylogic_impl_0x1c_(a_.u32[i], b_.u32[i], c_.u32[i]);
        }
        break;
      case 29:
        SIMDE_VECTORIZE
        for(size_t i = 0 ; i < (sizeof(r_.u32) / sizeof(r_.u32[0])) ; i++) {
          r_.u32[i] = simde_x_mm_ternarylogic_impl_0x1d_(a_.u32[i], b_.u32[i], c_.u32[i]);
        }
        break;
      case 30:
        SIMDE_VECTORIZE
        for(size_t i = 0 ; i < (sizeof(r_.u32) / sizeof(r_.u32[0])) ; i++) {
          r_.u32[i] = simde_x_mm_ternarylogic_impl_0x1e_(a_.u32[i], b_.u32[i], c_.u32[i]);
        }
        break;
      case 31:
        SIMDE_VECTORIZE
        for(size_t i = 0 ; i < (sizeof(r_.u32) / sizeof(r_.u32[0])) ; i++) {
          r_.u32[i] = simde_x_mm_ternarylogic_impl_0x1f_(a_.u32[i], b_.u32[i], c_.u32[i]);
        }
        break;
      case 32:
        SIMDE_VECTORIZE
        for(size_t i = 0 ; i < (sizeof(r_.u32) / sizeof(r_.u32[0])) ; i++) {
          r_.u32[i] = simde_x_mm_ternarylogic_impl_0x20_(a_.u32[i], b_.u32[i], c_.u32[i]);
        }
        break;
      case 33:
        SIMDE_VECTORIZE
        for(size_t i = 0 ; i < (sizeof(r_.u32) / sizeof(r_.u32[0])) ; i++) {
          r_.u32[i] = simde_x_mm_ternarylogic_impl_0x21_(a_.u32[i], b_.u32[i], c_.u32[i]);
        }
        break;
      case 34:
        SIMDE_VECTORIZE
        for(size_t i = 0 ; i < (sizeof(r_.u32) / sizeof(r_.u32[0])) ; i++) {
          r_.u32[i] = simde_x_mm_ternarylogic_impl_0x22_(b_.u32[i], c_.u32[i]);
        }
        break;
      case 35:
        SIMDE_VECTORIZE
        for(size_t i = 0 ; i < (sizeof(r_.u32) / sizeof(r_.u32[0])) ; i++) {
          r_.u32[i] = simde_x_mm_ternarylogic_impl_0x23_(a_.u32[i], b_.u32[i], c_.u32[i]);
        }
        break;
      case 36:
        SIMDE_VECTORIZE
        for(size_t i = 0 ; i < (sizeof(r_.u32) / sizeof(r_.u32[0])) ; i++) {
          r_.u32[i] = simde_x_mm_ternarylogic_impl_0x24_(a_.u32[i], b_.u32[i], c_.u32[i]);
        }
        break;
      case 37:
        SIMDE_VECTORIZE
        for(size_t i = 0 ; i < (sizeof(r_.u32) / sizeof(r_.u32[0])) ; i++) {
          r_.u32[i] = simde_x_mm_ternarylogic_impl_0x25_(a_.u32[i], b_.u32[i], c_.u32[i]);
        }
        break;
      case 38:
        SIMDE_VECTORIZE
        for(size_t i = 0 ; i < (sizeof(r_.u32) / sizeof(r_.u32[0])) ; i++) {
          r_.u32[i] = simde_x_mm_ternarylogic_impl_0x26_(a_.u32[i], b_.u32[i], c_.u32[i]);
        }
        break;
      case 39:
        SIMDE_VECTORIZE
        for(size_t i = 0 ; i < (sizeof(r_.u32) / sizeof(r_.u32[0])) ; i++) {
          r_.u32[i] = simde_x_mm_ternarylogic_impl_0x27_(a_.u32[i], b_.u32[i], c_.u32[i]);
        }
        break;
      case 40:
        SIMDE_VECTORIZE
        for(size_t i = 0 ; i < (sizeof(r_.u32) / sizeof(r_.u32[0])) ; i++) {
          r_.u32[i] = simde_x_mm_ternarylogic_impl_0x28_(a_.u32[i], b_.u32[i], c_.u32[i]);
        }
        break;
      case 41:
        SIMDE_VECTORIZE
        for(size_t i = 0 ; i < (sizeof(r_.u32) / sizeof(r_.u32[0])) ; i++) {
          r_.u32[i] = simde_x_mm_ternarylogic_impl_0x29_(a_.u32[i], b_.u32[i], c_.u32[i]);
        }
        break;
      case 42:
        SIMDE_VECTORIZE
        for(size_t i = 0 ; i < (sizeof(r_.u32) / sizeof(r_.u32[0])) ; i++) {
          r_.u32[i] = simde_x_mm_ternarylogic_impl_0x2a_(a_.u32[i], b_.u32[i], c_.u32[i]);
        }
        break;
      case 43:
        SIMDE_VECTORIZE
        for(size_t i = 0 ; i < (sizeof(r_.u32) / sizeof(r_.u32[0])) ; i++) {
          r_.u32[i] = simde_x_mm_ternarylogic_impl_0x2b_(a_.u32[i], b_.u32[i], c_.u32[i]);
        }
        break;
      case 44:
        SIMDE_VECTORIZE
        for(size_t i = 0 ; i < (sizeof(r_.u32) / sizeof(r_.u32[0])) ; i++) {
          r_.u32[i] = simde_x_mm_ternarylogic_impl_0x2c_(a_.u32[i], b_.u32[i], c_.u32[i]);
        }
        break;
      case 45:
        SIMDE_VECTORIZE
        for(size_t i = 0 ; i < (sizeof(r_.u32) / sizeof(r_.u32[0])) ; i++) {
          r_.u32[i] = simde_x_mm_ternarylogic_impl_0x2d_(a_.u32[i], b_.u32[i], c_.u32[i]);
        }
        break;
      case 46:
        SIMDE_VECTORIZE
        for(size_t i = 0 ; i < (sizeof(r_.u32) / sizeof(r_.u32[0])) ; i++) {
          r_.u32[i] = simde_x_mm_ternarylogic_impl_0x2e_(a_.u32[i], b_.u32[i], c_.u32[i]);
        }
        break;
      case 47:
        SIMDE_VECTORIZE
        for(size_t i = 0 ; i < (sizeof(r_.u32) / sizeof(r_.u32[0])) ; i++) {
          r_.u32[i] = simde_x_mm_ternarylogic_impl_0x2f_(a_.u32[i], b_.u32[i], c_.u32[i]);
        }
        break;
      case 48:
        SIMDE_VECTORIZE
        for(size_t i = 0 ; i < (sizeof(r_.u32) / sizeof(r_.u32[0])) ; i++) {
          r_.u32[i] = simde_x_mm_ternarylogic_impl_0x30_(a_.u32[i], b_.u32[i]);
        }
        break;
      case 49:
        SIMDE_VECTORIZE
        for(size_t i = 0 ; i < (sizeof(r_.u32) / sizeof(r_.u32[0])) ; i++) {
          r_.u32[i] = simde_x_mm_ternarylogic_impl_0x31_(a_.u32[i], b_.u32[i], c_.u32[i]);
        }
        break;
      case 50:
        SIMDE_VECTORIZE
        for(size_t i = 0 ; i < (sizeof(r_.u32) / sizeof(r_.u32[0])) ; i++) {
          r_.u32[i] = simde_x_mm_ternarylogic_impl_0x32_(a_.u32[i], b_.u32[i], c_.u32[i]);
        }
        break;
      case 51:
        SIMDE_VECTORIZE
        for(size_t i = 0 ; i < (sizeof(r_.u32) / sizeof(r_.u32[0])) ; i++) {
          r_.u32[i] = simde_x_mm_ternarylogic_impl_0x33_(b_.u32[i]);
        }
        break;
      case 52:
        SIMDE_VECTORIZE
        for(size_t i = 0 ; i < (sizeof(r_.u32) / sizeof(r_.u32[0])) ; i++) {
          r_.u32[i] = simde_x_mm_ternarylogic_impl_0x34_(a_.u32[i], b_.u32[i], c_.u32[i]);
        }
        break;
      case 53:
        SIMDE_VECTORIZE
        for(size_t i = 0 ; i < (sizeof(r_.u32) / sizeof(r_.u32[0])) ; i++) {
          r_.u32[i] = simde_x_mm_ternarylogic_impl_0x35_(a_.u32[i], b_.u32[i], c_.u32[i]);
        }
        break;
      case 54:
        SIMDE_VECTORIZE
        for(size_t i = 0 ; i < (sizeof(r_.u32) / sizeof(r_.u32[0])) ; i++) {
          r_.u32[i] = simde_x_mm_ternarylogic_impl_0x36_(a_.u32[i], b_.u32[i], c_.u32[i]);
        }
        break;
      case 55:
        SIMDE_VECTORIZE
        for(size_t i = 0 ; i < (sizeof(r_.u32) / sizeof(r_.u32[0])) ; i++) {
          r_.u32[i] = simde_x_mm_ternarylogic_impl_0x37_(a_.u32[i], b_.u32[i], c_.u32[i]);
        }
        break;
      case 56:
        SIMDE_VECTORIZE
        for(size_t i = 0 ; i < (sizeof(r_.u32) / sizeof(r_.u32[0])) ; i++) {
          r_.u32[i] = simde_x_mm_ternarylogic_impl_0x38_(a_.u32[i], b_.u32[i], c_.u32[i]);
        }
        break;
      case 57:
        SIMDE_VECTORIZE
        for(size_t i = 0 ; i < (sizeof(r_.u32) / sizeof(r_.u32[0])) ; i++) {
          r_.u32[i] = simde_x_mm_ternarylogic_impl_0x39_(a_.u32[i], b_.u32[i], c_.u32[i]);
        }
        break;
      case 58:
        SIMDE_VECTORIZE
        for(size_t i = 0 ; i < (sizeof(r_.u32) / sizeof(r_.u32[0])) ; i++) {
          r_.u32[i] = simde_x_mm_ternarylogic_impl_0x3a_(a_.u32[i], b_.u32[i], c_.u32[i]);
        }
        break;
      case 59:
        SIMDE_VECTORIZE
        for(size_t i = 0 ; i < (sizeof(r_.u32) / sizeof(r_.u32[0])) ; i++) {
          r_.u32[i] = simde_x_mm_ternarylogic_impl_0x3b_(a_.u32[i], b_.u32[i], c_.u32[i]);
        }
        break;
      case 60:
        SIMDE_VECTORIZE
        for(size_t i = 0 ; i < (sizeof(r_.u32) / sizeof(r_.u32[0])) ; i++) {
          r_.u32[i] = simde_x_mm_ternarylogic_impl_0x3c_(a_.u32[i], b_.u32[i]);
        }
        break;
      case 61:
        SIMDE_VECTORIZE
        for(size_t i = 0 ; i < (sizeof(r_.u32) / sizeof(r_.u32[0])) ; i++) {
          r_.u32[i] = simde_x_mm_ternarylogic_impl_0x3d_(a_.u32[i], b_.u32[i], c_.u32[i]);
        }
        break;
      case 62:
        SIMDE_VECTORIZE
        for(size_t i = 0 ; i < (sizeof(r_.u32) / sizeof(r_.u32[0])) ; i++) {
          r_.u32[i] = simde_x_mm_ternarylogic_impl_0x3e_(a_.u32[i], b_.u32[i], c_.u32[i]);
        }
        break;
      case 63:
        SIMDE_VECTORIZE
        for(size_t i = 0 ; i < (sizeof(r_.u32) / sizeof(r_.u32[0])) ; i++) {
          r_.u32[i] = simde_x_mm_ternarylogic_impl_0x3f_(a_.u32[i], b_.u32[i]);
        }
        break;
      case 64:
        SIMDE_VECTORIZE
        for(size_t i = 0 ; i < (sizeof(r_.u32) / sizeof(r_.u32[0])) ; i++) {
          r_.u32[i] = simde_x_mm_ternarylogic_impl_0x40_(a_.u32[i], b_.u32[i], c_.u32[i]);
        }
        break;
      case 65:
        SIMDE_VECTORIZE
        for(size_t i = 0 ; i < (sizeof(r_.u32) / sizeof(r_.u32[0])) ; i++) {
          r_.u32[i] = simde_x_mm_ternarylogic_impl_0x41_(a_.u32[i], b_.u32[i], c_.u32[i]);
        }
        break;
      case 66:
        SIMDE_VECTORIZE
        for(size_t i = 0 ; i < (sizeof(r_.u32) / sizeof(r_.u32[0])) ; i++) {
          r_.u32[i] = simde_x_mm_ternarylogic_impl_0x42_(a_.u32[i], b_.u32[i], c_.u32[i]);
        }
        break;
      case 67:
        SIMDE_VECTORIZE
        for(size_t i = 0 ; i < (sizeof(r_.u32) / sizeof(r_.u32[0])) ; i++) {
          r_.u32[i] = simde_x_mm_ternarylogic_impl_0x43_(a_.u32[i], b_.u32[i], c_.u32[i]);
        }
        break;
      case 68:
        SIMDE_VECTORIZE
        for(size_t i = 0 ; i < (sizeof(r_.u32) / sizeof(r_.u32[0])) ; i++) {
          r_.u32[i] = simde_x_mm_ternarylogic_impl_0x44_(b_.u32[i], c_.u32[i]);
        }
        break;
      case 69:
        SIMDE_VECTORIZE
        for(size_t i = 0 ; i < (sizeof(r_.u32) / sizeof(r_.u32[0])) ; i++) {
          r_.u32[i] = simde_x_mm_ternarylogic_impl_0x45_(a_.u32[i], b_.u32[i], c_.u32[i]);
        }
        break;
      case 70:
        SIMDE_VECTORIZE
        for(size_t i = 0 ; i < (sizeof(r_.u32) / sizeof(r_.u32[0])) ; i++) {
          r_.u32[i] = simde_x_mm_ternarylogic_impl_0x46_(a_.u32[i], b_.u32[i], c_.u32[i]);
        }
        break;
      case 71:
        SIMDE_VECTORIZE
        for(size_t i = 0 ; i < (sizeof(r_.u32) / sizeof(r_.u32[0])) ; i++) {
          r_.u32[i] = simde_x_mm_ternarylogic_impl_0x47_(a_.u32[i], b_.u32[i], c_.u32[i]);
        }
        break;
      case 72:
        SIMDE_VECTORIZE
        for(size_t i = 0 ; i < (sizeof(r_.u32) / sizeof(r_.u32[0])) ; i++) {
          r_.u32[i] = simde_x_mm_ternarylogic_impl_0x48_(a_.u32[i], b_.u32[i], c_.u32[i]);
        }
        break;
      case 73:
        SIMDE_VECTORIZE
        for(size_t i = 0 ; i < (sizeof(r_.u32) / sizeof(r_.u32[0])) ; i++) {
          r_.u32[i] = simde_x_mm_ternarylogic_impl_0x49_(a_.u32[i], b_.u32[i], c_.u32[i]);
        }
        break;
      case 74:
        SIMDE_VECTORIZE
        for(size_t i = 0 ; i < (sizeof(r_.u32) / sizeof(r_.u32[0])) ; i++) {
          r_.u32[i] = simde_x_mm_ternarylogic_impl_0x4a_(a_.u32[i], b_.u32[i], c_.u32[i]);
        }
        break;
      case 75:
        SIMDE_VECTORIZE
        for(size_t i = 0 ; i < (sizeof(r_.u32) / sizeof(r_.u32[0])) ; i++) {
          r_.u32[i] = simde_x_mm_ternarylogic_impl_0x4b_(a_.u32[i], b_.u32[i], c_.u32[i]);
        }
        break;
      case 76:
        SIMDE_VECTORIZE
        for(size_t i = 0 ; i < (sizeof(r_.u32) / sizeof(r_.u32[0])) ; i++) {
          r_.u32[i] = simde_x_mm_ternarylogic_impl_0x4c_(a_.u32[i], b_.u32[i], c_.u32[i]);
        }
        break;
      case 77:
        SIMDE_VECTORIZE
        for(size_t i = 0 ; i < (sizeof(r_.u32) / sizeof(r_.u32[0])) ; i++) {
          r_.u32[i] = simde_x_mm_ternarylogic_impl_0x4d_(a_.u32[i], b_.u32[i], c_.u32[i]);
        }
        break;
      case 78:
        SIMDE_VECTORIZE
        for(size_t i = 0 ; i < (sizeof(r_.u32) / sizeof(r_.u32[0])) ; i++) {
          r_.u32[i] = simde_x_mm_ternarylogic_impl_0x4e_(a_.u32[i], b_.u32[i], c_.u32[i]);
        }
        break;
      case 79:
        SIMDE_VECTORIZE
        for(size_t i = 0 ; i < (sizeof(r_.u32) / sizeof(r_.u32[0])) ; i++) {
          r_.u32[i] = simde_x_mm_ternarylogic_impl_0x4f_(a_.u32[i], b_.u32[i], c_.u32[i]);
        }
        break;
      case 80:
        SIMDE_VECTORIZE
        for(size_t i = 0 ; i < (sizeof(r_.u32) / sizeof(r_.u32[0])) ; i++) {
          r_.u32[i] = simde_x_mm_ternarylogic_impl_0x50_(a_.u32[i], c_.u32[i]);
        }
        break;
      case 81:
        SIMDE_VECTORIZE
        for(size_t i = 0 ; i < (sizeof(r_.u32) / sizeof(r_.u32[0])) ; i++) {
          r_.u32[i] = simde_x_mm_ternarylogic_impl_0x51_(a_.u32[i], b_.u32[i], c_.u32[i]);
        }
        break;
      case 82:
        SIMDE_VECTORIZE
        for(size_t i = 0 ; i < (sizeof(r_.u32) / sizeof(r_.u32[0])) ; i++) {
          r_.u32[i] = simde_x_mm_ternarylogic_impl_0x52_(a_.u32[i], b_.u32[i], c_.u32[i]);
        }
        break;
      case 83:
        SIMDE_VECTORIZE
        for(size_t i = 0 ; i < (sizeof(r_.u32) / sizeof(r_.u32[0])) ; i++) {
          r_.u32[i] = simde_x_mm_ternarylogic_impl_0x53_(a_.u32[i], b_.u32[i], c_.u32[i]);
        }
        break;
      case 84:
        SIMDE_VECTORIZE
        for(size_t i = 0 ; i < (sizeof(r_.u32) / sizeof(r_.u32[0])) ; i++) {
          r_.u32[i] = simde_x_mm_ternarylogic_impl_0x54_(a_.u32[i], b_.u32[i], c_.u32[i]);
        }
        break;
      case 85:
        SIMDE_VECTORIZE
        for(size_t i = 0 ; i < (sizeof(r_.u32) / sizeof(r_.u32[0])) ; i++) {
          r_.u32[i] = simde_x_mm_ternarylogic_impl_0x55_(c_.u32[i]);
        }
        break;
      case 86:
        SIMDE_VECTORIZE
        for(size_t i = 0 ; i < (sizeof(r_.u32) / sizeof(r_.u32[0])) ; i++) {
          r_.u32[i] = simde_x_mm_ternarylogic_impl_0x56_(a_.u32[i], b_.u32[i], c_.u32[i]);
        }
        break;
      case 87:
        SIMDE_VECTORIZE
        for(size_t i = 0 ; i < (sizeof(r_.u32) / sizeof(r_.u32[0])) ; i++) {
          r_.u32[i] = simde_x_mm_ternarylogic_impl_0x57_(a_.u32[i], b_.u32[i], c_.u32[i]);
        }
        break;
      case 88:
        SIMDE_VECTORIZE
        for(size_t i = 0 ; i < (sizeof(r_.u32) / sizeof(r_.u32[0])) ; i++) {
          r_.u32[i] = simde_x_mm_ternarylogic_impl_0x58_(a_.u32[i], b_.u32[i], c_.u32[i]);
        }
        break;
      case 89:
        SIMDE_VECTORIZE
        for(size_t i = 0 ; i < (sizeof(r_.u32) / sizeof(r_.u32[0])) ; i++) {
          r_.u32[i] = simde_x_mm_ternarylogic_impl_0x59_(a_.u32[i], b_.u32[i], c_.u32[i]);
        }
        break;
      case 90:
        SIMDE_VECTORIZE
        for(size_t i = 0 ; i < (sizeof(r_.u32) / sizeof(r_.u32[0])) ; i++) {
          r_.u32[i] = simde_x_mm_ternarylogic_impl_0x5a_(a_.u32[i], c_.u32[i]);
        }
        break;
      case 91:
        SIMDE_VECTORIZE
        for(size_t i = 0 ; i < (sizeof(r_.u32) / sizeof(r_.u32[0])) ; i++) {
          r_.u32[i] = simde_x_mm_ternarylogic_impl_0x5b_(a_.u32[i], b_.u32[i], c_.u32[i]);
        }
        break;
      case 92:
        SIMDE_VECTORIZE
        for(size_t i = 0 ; i < (sizeof(r_.u32) / sizeof(r_.u32[0])) ; i++) {
          r_.u32[i] = simde_x_mm_ternarylogic_impl_0x5c_(a_.u32[i], b_.u32[i], c_.u32[i]);
        }
        break;
      case 93:
        SIMDE_VECTORIZE
        for(size_t i = 0 ; i < (sizeof(r_.u32) / sizeof(r_.u32[0])) ; i++) {
          r_.u32[i] = simde_x_mm_ternarylogic_impl_0x5d_(a_.u32[i], b_.u32[i], c_.u32[i]);
        }
        break;
      case 94:
        SIMDE_VECTORIZE
        for(size_t i = 0 ; i < (sizeof(r_.u32) / sizeof(r_.u32[0])) ; i++) {
          r_.u32[i] = simde_x_mm_ternarylogic_impl_0x5e_(a_.u32[i], b_.u32[i], c_.u32[i]);
        }
        break;
      case 95:
        SIMDE_VECTORIZE
        for(size_t i = 0 ; i < (sizeof(r_.u32) / sizeof(r_.u32[0])) ; i++) {
          r_.u32[i] = simde_x_mm_ternarylogic_impl_0x5f_(a_.u32[i], c_.u32[i]);
        }
        break;
      case 96:
        SIMDE_VECTORIZE
        for(size_t i = 0 ; i < (sizeof(r_.u32) / sizeof(r_.u32[0])) ; i++) {
          r_.u32[i] = simde_x_mm_ternarylogic_impl_0x60_(a_.u32[i], b_.u32[i], c_.u32[i]);
        }
        break;
      case 97:
        SIMDE_VECTORIZE
        for(size_t i = 0 ; i < (sizeof(r_.u32) / sizeof(r_.u32[0])) ; i++) {
          r_.u32[i] = simde_x_mm_ternarylogic_impl_0x61_(a_.u32[i], b_.u32[i], c_.u32[i]);
        }
        break;
      case 98:
        SIMDE_VECTORIZE
        for(size_t i = 0 ; i < (sizeof(r_.u32) / sizeof(r_.u32[0])) ; i++) {
          r_.u32[i] = simde_x_mm_ternarylogic_impl_0x62_(a_.u32[i], b_.u32[i], c_.u32[i]);
        }
        break;
      case 99:
        SIMDE_VECTORIZE
        for(size_t i = 0 ; i < (sizeof(r_.u32) / sizeof(r_.u32[0])) ; i++) {
          r_.u32[i] = simde_x_mm_ternarylogic_impl_0x63_(a_.u32[i], b_.u32[i], c_.u32[i]);
        }
        break;
      case 100:
        SIMDE_VECTORIZE
        for(size_t i = 0 ; i < (sizeof(r_.u32) / sizeof(r_.u32[0])) ; i++) {
          r_.u32[i] = simde_x_mm_ternarylogic_impl_0x64_(a_.u32[i], b_.u32[i], c_.u32[i]);
        }
        break;
      case 101:
        SIMDE_VECTORIZE
        for(size_t i = 0 ; i < (sizeof(r_.u32) / sizeof(r_.u32[0])) ; i++) {
          r_.u32[i] = simde_x_mm_ternarylogic_impl_0x65_(a_.u32[i], b_.u32[i], c_.u32[i]);
        }
        break;
      case 102:
        SIMDE_VECTORIZE
        for(size_t i = 0 ; i < (sizeof(r_.u32) / sizeof(r_.u32[0])) ; i++) {
          r_.u32[i] = simde_x_mm_ternarylogic_impl_0x66_(b_.u32[i], c_.u32[i]);
        }
        break;
      case 103:
        SIMDE_VECTORIZE
        for(size_t i = 0 ; i < (sizeof(r_.u32) / sizeof(r_.u32[0])) ; i++) {
          r_.u32[i] = simde_x_mm_ternarylogic_impl_0x67_(a_.u32[i], b_.u32[i], c_.u32[i]);
        }
        break;
      case 104:
        SIMDE_VECTORIZE
        for(size_t i = 0 ; i < (sizeof(r_.u32) / sizeof(r_.u32[0])) ; i++) {
          r_.u32[i] = simde_x_mm_ternarylogic_impl_0x68_(a_.u32[i], b_.u32[i], c_.u32[i]);
        }
        break;
      case 105:
        SIMDE_VECTORIZE
        for(size_t i = 0 ; i < (sizeof(r_.u32) / sizeof(r_.u32[0])) ; i++) {
          r_.u32[i] = simde_x_mm_ternarylogic_impl_0x69_(a_.u32[i], b_.u32[i], c_.u32[i]);
        }
        break;
      case 106:
        SIMDE_VECTORIZE
        for(size_t i = 0 ; i < (sizeof(r_.u32) / sizeof(r_.u32[0])) ; i++) {
          r_.u32[i] = simde_x_mm_ternarylogic_impl_0x6a_(a_.u32[i], b_.u32[i], c_.u32[i]);
        }
        break;
      case 107:
        SIMDE_VECTORIZE
        for(size_t i = 0 ; i < (sizeof(r_.u32) / sizeof(r_.u32[0])) ; i++) {
          r_.u32[i] = simde_x_mm_ternarylogic_impl_0x6b_(a_.u32[i], b_.u32[i], c_.u32[i]);
        }
        break;
      case 108:
        SIMDE_VECTORIZE
        for(size_t i = 0 ; i < (sizeof(r_.u32) / sizeof(r_.u32[0])) ; i++) {
          r_.u32[i] = simde_x_mm_ternarylogic_impl_0x6c_(a_.u32[i], b_.u32[i], c_.u32[i]);
        }
        break;
      case 109:
        SIMDE_VECTORIZE
        for(size_t i = 0 ; i < (sizeof(r_.u32) / sizeof(r_.u32[0])) ; i++) {
          r_.u32[i] = simde_x_mm_ternarylogic_impl_0x6d_(a_.u32[i], b_.u32[i], c_.u32[i]);
        }
        break;
      case 110:
        SIMDE_VECTORIZE
        for(size_t i = 0 ; i < (sizeof(r_.u32) / sizeof(r_.u32[0])) ; i++) {
          r_.u32[i] = simde_x_mm_ternarylogic_impl_0x6e_(a_.u32[i], b_.u32[i], c_.u32[i]);
        }
        break;
      case 111:
        SIMDE_VECTORIZE
        for(size_t i = 0 ; i < (sizeof(r_.u32) / sizeof(r_.u32[0])) ; i++) {
          r_.u32[i] = simde_x_mm_ternarylogic_impl_0x6f_(a_.u32[i], b_.u32[i], c_.u32[i]);
        }
        break;
      case 112:
        SIMDE_VECTORIZE
        for(size_t i = 0 ; i < (sizeof(r_.u32) / sizeof(r_.u32[0])) ; i++) {
          r_.u32[i] = simde_x_mm_ternarylogic_impl_0x70_(a_.u32[i], b_.u32[i], c_.u32[i]);
        }
        break;
      case 113:
        SIMDE_VECTORIZE
        for(size_t i = 0 ; i < (sizeof(r_.u32) / sizeof(r_.u32[0])) ; i++) {
          r_.u32[i] = simde_x_mm_ternarylogic_impl_0x71_(a_.u32[i], b_.u32[i], c_.u32[i]);
        }
        break;
      case 114:
        SIMDE_VECTORIZE
        for(size_t i = 0 ; i < (sizeof(r_.u32) / sizeof(r_.u32[0])) ; i++) {
          r_.u32[i] = simde_x_mm_ternarylogic_impl_0x72_(a_.u32[i], b_.u32[i], c_.u32[i]);
        }
        break;
      case 115:
        SIMDE_VECTORIZE
        for(size_t i = 0 ; i < (sizeof(r_.u32) / sizeof(r_.u32[0])) ; i++) {
          r_.u32[i] = simde_x_mm_ternarylogic_impl_0x73_(a_.u32[i], b_.u32[i], c_.u32[i]);
        }
        break;
      case 116:
        SIMDE_VECTORIZE
        for(size_t i = 0 ; i < (sizeof(r_.u32) / sizeof(r_.u32[0])) ; i++) {
          r_.u32[i] = simde_x_mm_ternarylogic_impl_0x74_(a_.u32[i], b_.u32[i], c_.u32[i]);
        }
        break;
      case 117:
        SIMDE_VECTORIZE
        for(size_t i = 0 ; i < (sizeof(r_.u32) / sizeof(r_.u32[0])) ; i++) {
          r_.u32[i] = simde_x_mm_ternarylogic_impl_0x75_(a_.u32[i], b_.u32[i], c_.u32[i]);
        }
        break;
      case 118:
        SIMDE_VECTORIZE
        for(size_t i = 0 ; i < (sizeof(r_.u32) / sizeof(r_.u32[0])) ; i++) {
          r_.u32[i] = simde_x_mm_ternarylogic_impl_0x76_(a_.u32[i], b_.u32[i], c_.u32[i]);
        }
        break;
      case 119:
        SIMDE_VECTORIZE
        for(size_t i = 0 ; i < (sizeof(r_.u32) / sizeof(r_.u32[0])) ; i++) {
          r_.u32[i] = simde_x_mm_ternarylogic_impl_0x77_(b_.u32[i], c_.u32[i]);
        }
        break;
      case 120:
        SIMDE_VECTORIZE
        for(size_t i = 0 ; i < (sizeof(r_.u32) / sizeof(r_.u32[0])) ; i++) {
          r_.u32[i] = simde_x_mm_ternarylogic_impl_0x78_(a_.u32[i], b_.u32[i], c_.u32[i]);
        }
        break;
      case 121:
        SIMDE_VECTORIZE
        for(size_t i = 0 ; i < (sizeof(r_.u32) / sizeof(r_.u32[0])) ; i++) {
          r_.u32[i] = simde_x_mm_ternarylogic_impl_0x79_(a_.u32[i], b_.u32[i], c_.u32[i]);
        }
        break;
      case 122:
        SIMDE_VECTORIZE
        for(size_t i = 0 ; i < (sizeof(r_.u32) / sizeof(r_.u32[0])) ; i++) {
          r_.u32[i] = simde_x_mm_ternarylogic_impl_0x7a_(a_.u32[i], b_.u32[i], c_.u32[i]);
        }
        break;
      case 123:
        SIMDE_VECTORIZE
        for(size_t i = 0 ; i < (sizeof(r_.u32) / sizeof(r_.u32[0])) ; i++) {
          r_.u32[i] = simde_x_mm_ternarylogic_impl_0x7b_(a_.u32[i], b_.u32[i], c_.u32[i]);
        }
        break;
      case 124:
        SIMDE_VECTORIZE
        for(size_t i = 0 ; i < (sizeof(r_.u32) / sizeof(r_.u32[0])) ; i++) {
          r_.u32[i] = simde_x_mm_ternarylogic_impl_0x7c_(a_.u32[i], b_.u32[i], c_.u32[i]);
        }
        break;
      case 125:
        SIMDE_VECTORIZE
        for(size_t i = 0 ; i < (sizeof(r_.u32) / sizeof(r_.u32[0])) ; i++) {
          r_.u32[i] = simde_x_mm_ternarylogic_impl_0x7d_(a_.u32[i], b_.u32[i], c_.u32[i]);
        }
        break;
      case 126:
        SIMDE_VECTORIZE
        for(size_t i = 0 ; i < (sizeof(r_.u32) / sizeof(r_.u32[0])) ; i++) {
          r_.u32[i] = simde_x_mm_ternarylogic_impl_0x7e_(a_.u32[i], b_.u32[i], c_.u32[i]);
        }
        break;
      case 127:
        SIMDE_VECTORIZE
        for(size_t i = 0 ; i < (sizeof(r_.u32) / sizeof(r_.u32[0])) ; i++) {
          r_.u32[i] = simde_x_mm_ternarylogic_impl_0x7f_(a_.u32[i], b_.u32[i], c_.u32[i]);
        }
        break;
    }

    if(imm8 & 128)
      r_ = simde__m128i_to_private(simde_mm_castps_si128(simde_x_mm_not_ps(simde_mm_castsi128_ps(simde__m128i_from_private(r_)))));

    return simde__m128i_from_private(r_);
  }
#endif
#if defined(SIMDE_X86_AVX512VL_ENABLE_NATIVE_ALIASES) && defined(SIMDE_X86_AVX512F_ENABLE_NATIVE_ALIASES)
  #undef _mm_ternarylogic_epi32
  #define _mm_ternarylogic_epi32(a, b, c, imm8) simde_mm_ternarylogic_epi32(a, b, c, imm8)
#endif


SIMDE_END_DECLS_
HEDLEY_DIAGNOSTIC_POP

#endif /* !defined(SIMDE_X86_AVX512_TERNARYLOGIC_H) */
