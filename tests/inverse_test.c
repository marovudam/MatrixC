#include <check.h>

#include "../matrix.h"

START_TEST(readme_example) {
  matrix_t A1;
  int code1 = create_matrix(3, 3, &A1);
  A1.matrix[0][0] = 2.0;
  A1.matrix[0][1] = 5.0;
  A1.matrix[0][2] = 7.0;
  A1.matrix[1][0] = 6.0;
  A1.matrix[1][1] = 3.0;
  A1.matrix[1][2] = 4.0;
  A1.matrix[2][0] = 5.0;
  A1.matrix[2][1] = -2.0;
  A1.matrix[2][2] = -3.0;

  matrix_t result;
  int c_code = inverse_matrix(&A1, &result);

  matrix_t true_result;
  int code2 = create_matrix(3, 3, &true_result);
  true_result.matrix[0][0] = 1.0;
  true_result.matrix[0][1] = -1.0;
  true_result.matrix[0][2] = 1.0;
  true_result.matrix[1][0] = -38.0;
  true_result.matrix[1][1] = 41.0;
  true_result.matrix[1][2] = -34.0;
  true_result.matrix[2][0] = 27.0;
  true_result.matrix[2][1] = -29.0;
  true_result.matrix[2][2] = 24.0;

  int res = eq_matrix(&result, &true_result);
  ck_assert_int_eq(code1, 0);
  ck_assert_int_eq(code2, 0);
  ck_assert_int_eq(res, 1);
  ck_assert_int_eq(c_code, 0);

  remove_matrix(&A1);
  remove_matrix(&result);
  remove_matrix(&true_result);
}
END_TEST

START_TEST(small_matrix) {
  matrix_t A1;
  int code1 = create_matrix(1, 1, &A1);
  A1.matrix[0][0] = 2.0;

  matrix_t result;
  int c_code = inverse_matrix(&A1, &result);

  matrix_t true_result;
  int code2 = create_matrix(1, 1, &true_result);
  true_result.matrix[0][0] = 0.5;

  int res = eq_matrix(&result, &true_result);
  ck_assert_int_eq(code1, 0);
  ck_assert_int_eq(code2, 0);
  ck_assert_int_eq(res, 1);
  ck_assert_int_eq(c_code, 0);

  remove_matrix(&A1);
  remove_matrix(&result);
  remove_matrix(&true_result);
}
END_TEST

START_TEST(not_square) {
  matrix_t A1;
  int code1 = create_matrix(1, 3, &A1);
  A1.matrix[0][0] = 2.0;
  A1.matrix[0][1] = 5.0;
  A1.matrix[0][2] = 7.0;

  matrix_t result;
  int c_code = inverse_matrix(&A1, &result);

  ck_assert_int_eq(code1, 0);
  ck_assert_int_eq(c_code, 2);

  remove_matrix(&A1);
}
END_TEST

START_TEST(zero_determinant) {
  matrix_t A1;
  int code1 = create_matrix(2, 2, &A1);
  A1.matrix[0][0] = 2.0;
  A1.matrix[0][1] = 5.0;
  A1.matrix[1][0] = 2.0;
  A1.matrix[1][1] = 5.0;

  matrix_t result;
  int c_code = inverse_matrix(&A1, &result);

  ck_assert_int_eq(code1, 0);
  ck_assert_int_eq(c_code, 2);

  remove_matrix(&A1);
}
END_TEST

Suite* inverse_matrix_suite(void) {
  Suite* s;
  TCase* tc_core;

  s = suite_create("inverse");

  tc_core = tcase_create("Core");
  tcase_add_test(tc_core, readme_example);
  tcase_add_test(tc_core, not_square);
  tcase_add_test(tc_core, zero_determinant);
  tcase_add_test(tc_core, small_matrix);

  suite_add_tcase(s, tc_core);
  return s;
}