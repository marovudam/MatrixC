#include <check.h>

#include "../matrix.h"

START_TEST(simple_transpose_1) {
  matrix_t A;
  int code1 = create_matrix(2, 2, &A);
  A.matrix[0][0] = -5.6;
  A.matrix[0][1] = 1.2;
  A.matrix[1][0] = 0.0;
  A.matrix[1][1] = -3.0;

  matrix_t result;
  int t_code = transpose(&A, &result);

  matrix_t true_result;
  int code2 = create_matrix(2, 2, &true_result);
  true_result.matrix[0][0] = -5.6;
  true_result.matrix[0][1] = 0.0;
  true_result.matrix[1][0] = 1.2;
  true_result.matrix[1][1] = -3.0;

  int res = eq_matrix(&true_result, &result);

  ck_assert_int_eq(code1, 0);
  ck_assert_int_eq(code2, 0);

  ck_assert_int_eq(t_code, 0);
  ck_assert_int_eq(res, 1);

  remove_matrix(&A);
  remove_matrix(&result);
  remove_matrix(&true_result);
}
END_TEST

START_TEST(simple_transpose_2) {
  matrix_t A;
  int code1 = create_matrix(1, 2, &A);
  A.matrix[0][0] = -5.6;
  A.matrix[0][1] = 1.2;

  matrix_t result;
  int t_code = transpose(&A, &result);

  matrix_t true_result;
  int code2 = create_matrix(2, 1, &true_result);
  true_result.matrix[0][0] = -5.6;
  true_result.matrix[1][0] = 1.2;

  int res = eq_matrix(&true_result, &result);

  ck_assert_int_eq(code1, 0);
  ck_assert_int_eq(code2, 0);

  ck_assert_int_eq(t_code, 0);
  ck_assert_int_eq(res, 1);

  remove_matrix(&A);
  remove_matrix(&result);
  remove_matrix(&true_result);
}
END_TEST

Suite* transpose_suite(void) {
  Suite* s;
  TCase* tc_core;

  s = suite_create("transpose");

  tc_core = tcase_create("core");
  tcase_add_test(tc_core, simple_transpose_1);
  tcase_add_test(tc_core, simple_transpose_2);
  suite_add_tcase(s, tc_core);

  return s;
}