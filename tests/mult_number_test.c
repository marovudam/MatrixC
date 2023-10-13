#include <check.h>

#include "../matrix.h"

START_TEST(simple_mul_number) {
  matrix_t A;
  int code1 = create_matrix(2, 1, &A);
  A.matrix[0][0] = 10.5;
  A.matrix[1][0] = -10.0;

  double n = 0.1;

  matrix_t result;
  int mult_code = mult_number(&A, n, &result);

  matrix_t true_result;
  int code2 = create_matrix(2, 1, &true_result);
  true_result.matrix[0][0] = 1.05;
  true_result.matrix[1][0] = -1.0;

  int res = eq_matrix(&true_result, &result);

  ck_assert_int_eq(code1, 0);
  ck_assert_int_eq(code2, 0);

  ck_assert_int_eq(mult_code, 0);
  ck_assert_int_eq(res, 1);

  remove_matrix(&A);
  remove_matrix(&result);
  remove_matrix(&true_result);
}
END_TEST

Suite* mult_number_suite(void) {
  Suite* s;
  TCase* tc_core;

  s = suite_create("mult_number");

  tc_core = tcase_create("core");
  tcase_add_test(tc_core, simple_mul_number);
  suite_add_tcase(s, tc_core);

  return s;
}