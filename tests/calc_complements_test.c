#include <check.h>

#include "../matrix.h"

START_TEST(readme_example) {
  matrix_t A1;
  int code1 = create_matrix(3, 3, &A1);
  A1.matrix[0][0] = 1.0;
  A1.matrix[0][1] = 2.0;
  A1.matrix[0][2] = 3.0;
  A1.matrix[1][0] = 0.0;
  A1.matrix[1][1] = 4.0;
  A1.matrix[1][2] = 2.0;
  A1.matrix[2][0] = 5.0;
  A1.matrix[2][1] = 2.0;
  A1.matrix[2][2] = 1.0;

  matrix_t result;
  int c_code = calc_complements(&A1, &result);

  matrix_t true_result;
  int code2 = create_matrix(3, 3, &true_result);
  true_result.matrix[0][0] = 0.0;
  true_result.matrix[0][1] = 10.0;
  true_result.matrix[0][2] = -20.0;
  true_result.matrix[1][0] = 4.0;
  true_result.matrix[1][1] = -14.0;
  true_result.matrix[1][2] = 8.0;
  true_result.matrix[2][0] = -8.0;
  true_result.matrix[2][1] = -2.0;
  true_result.matrix[2][2] = 4.0;

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

START_TEST(not_square_matrix) {
  matrix_t A1;
  int code1 = create_matrix(2, 3, &A1);
  A1.matrix[0][0] = 1.0;
  A1.matrix[0][1] = 2.0;
  A1.matrix[0][2] = 3.0;
  A1.matrix[1][0] = 0.0;
  A1.matrix[1][1] = 4.0;
  A1.matrix[1][2] = 2.0;

  matrix_t result;
  int c_code = calc_complements(&A1, &result);

  ck_assert_int_eq(code1, 0);
  ck_assert_int_eq(c_code, 2);

  remove_matrix(&A1);
}
END_TEST

START_TEST(small_matrix) {
  matrix_t A1;
  int code1 = create_matrix(1, 1, &A1);
  A1.matrix[0][0] = 1.0;

  matrix_t result;
  int c_code = calc_complements(&A1, &result);

  matrix_t true_result;
  int code2 = create_matrix(1, 1, &true_result);
  true_result.matrix[0][0] = 1.0;

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

Suite* calc_complements_suite(void) {
  Suite* s;
  TCase* tc_core;

  s = suite_create("complements");

  tc_core = tcase_create("Core");
  tcase_add_test(tc_core, readme_example);
  tcase_add_test(tc_core, not_square_matrix);
  tcase_add_test(tc_core, small_matrix);

  suite_add_tcase(s, tc_core);
  return s;
}