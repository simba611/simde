#define SIMDE_TEST_X86_AVX512_INSN ternarylogic

#include <test/x86/avx512/test-avx512.h>
#include <simde/x86/avx512/set.h>
#include <simde/x86/avx512/ternarylogic.h>

static int
test_simde_mm_ternarylogic_epi32 (SIMDE_MUNIT_TEST_ARGS) {
  return 1;
}

SIMDE_TEST_FUNC_LIST_BEGIN
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_ternarylogic_epi32)
SIMDE_TEST_FUNC_LIST_END

#include <test/x86/avx512/test-avx512-footer.h>
