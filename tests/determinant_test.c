#include <check.h>

#include "../matrix.h"

START_TEST(simple_det) {
  matrix_t A1;
  int code1 = create_matrix(1, 1, &A1);
  A1.matrix[0][0] = 9.2132;

  double result = 0.0;

  int res = determinant(&A1, &result);

  double true_result = 9.2132;

  ck_assert_int_eq(code1, 0);
  ck_assert_int_eq(res, 0);
  ck_assert_double_eq(result, true_result);

  remove_matrix(&A1);
}
END_TEST

START_TEST(det_2) {
  matrix_t A1;
  int code1 = create_matrix(2, 2, &A1);
  A1.matrix[0][0] = 1.0;
  A1.matrix[0][1] = -1.0;
  A1.matrix[1][0] = 2.0;
  A1.matrix[1][1] = 3.0;
  double result = 0.0;

  int res = determinant(&A1, &result);

  double true_result = 5.0;

  ck_assert_int_eq(code1, 0);
  ck_assert_int_eq(res, 0);
  ck_assert_double_eq(result, true_result);

  remove_matrix(&A1);
}
END_TEST

START_TEST(det_3) {
  matrix_t A1;
  int code1 = create_matrix(3, 3, &A1);
  A1.matrix[0][0] = 1.0;
  A1.matrix[0][1] = -2.0;
  A1.matrix[0][2] = 3.0;
  A1.matrix[1][0] = 4.0;
  A1.matrix[1][1] = 0.0;
  A1.matrix[1][2] = 6.0;
  A1.matrix[2][0] = -7.0;
  A1.matrix[2][1] = 8.0;
  A1.matrix[2][2] = 9.0;
  double result;

  int res = determinant(&A1, &result);

  double true_result = 204.0;

  ck_assert_int_eq(code1, 0);
  ck_assert_int_eq(res, 0);
  ck_assert_double_eq(result, true_result);

  remove_matrix(&A1);
}
END_TEST

START_TEST(det_4) {
  matrix_t A1;
  int code1 = create_matrix(4, 4, &A1);
  A1.matrix[0][0] = 3.0;
  A1.matrix[0][1] = -3.0;
  A1.matrix[0][2] = -5.0;
  A1.matrix[0][3] = 8.0;
  A1.matrix[1][0] = -3.0;
  A1.matrix[1][1] = 2.0;
  A1.matrix[1][2] = 4.0;
  A1.matrix[1][3] = -6.0;
  A1.matrix[2][0] = 2.0;
  A1.matrix[2][1] = -5.0;
  A1.matrix[2][2] = -7.0;
  A1.matrix[2][3] = 5.0;
  A1.matrix[3][0] = -4.0;
  A1.matrix[3][1] = 3.0;
  A1.matrix[3][2] = 5.0;
  A1.matrix[3][3] = -6.0;

  double result;

  int res = determinant(&A1, &result);

  double true_result = 18.0;

  ck_assert_int_eq(code1, 0);
  ck_assert_int_eq(res, 0);
  ck_assert_double_eq(result, true_result);

  remove_matrix(&A1);
}
END_TEST

START_TEST(det_5) {
  matrix_t A1;
  int code1 = create_matrix(5, 5, &A1);
  A1.matrix[0][0] = 1.0;
  A1.matrix[0][1] = 0.0;
  A1.matrix[0][2] = 1.0;
  A1.matrix[0][3] = 1.0;
  A1.matrix[0][4] = 0.0;
  A1.matrix[1][0] = 1.0;
  A1.matrix[1][1] = 0.0;
  A1.matrix[1][2] = 1.0;
  A1.matrix[1][3] = 0.0;
  A1.matrix[1][4] = 1.0;
  A1.matrix[2][0] = 1.0;
  A1.matrix[2][1] = 1.0;
  A1.matrix[2][2] = 1.0;
  A1.matrix[2][3] = 1.0;
  A1.matrix[2][4] = 0.0;
  A1.matrix[3][0] = 1.0;
  A1.matrix[3][1] = 1.0;
  A1.matrix[3][2] = 0.0;
  A1.matrix[3][3] = 1.0;
  A1.matrix[3][4] = 1.0;
  A1.matrix[4][0] = 1.0;
  A1.matrix[4][1] = 1.0;
  A1.matrix[4][2] = 1.0;
  A1.matrix[4][3] = 0.0;
  A1.matrix[4][4] = 0.0;
  double result = 0.0;

  int res = determinant(&A1, &result);

  double true_result = -1.0;

  ck_assert_int_eq(code1, 0);
  ck_assert_int_eq(res, 0);
  ck_assert_double_eq(result, true_result);

  remove_matrix(&A1);
}
END_TEST

START_TEST(not_square_matrix) {
  matrix_t A1;
  int code1 = create_matrix(4, 5, &A1);
  A1.matrix[0][0] = 1.0;
  A1.matrix[0][1] = 0.0;
  A1.matrix[0][2] = 1.0;
  A1.matrix[0][3] = 1.0;
  A1.matrix[0][4] = 0.0;
  A1.matrix[1][0] = 1.0;
  A1.matrix[1][1] = 0.0;
  A1.matrix[1][2] = 1.0;
  A1.matrix[1][3] = 0.0;
  A1.matrix[1][4] = 1.0;
  A1.matrix[2][0] = 1.0;
  A1.matrix[2][1] = 1.0;
  A1.matrix[2][2] = 1.0;
  A1.matrix[2][3] = 1.0;
  A1.matrix[2][4] = 0.0;
  A1.matrix[3][0] = 1.0;
  A1.matrix[3][1] = 1.0;
  A1.matrix[3][2] = 0.0;
  A1.matrix[3][3] = 1.0;
  A1.matrix[3][4] = 1.0;

  double result = 0.0;

  int res = determinant(&A1, &result);

  ck_assert_int_eq(code1, 0);
  ck_assert_int_eq(res, 2);

  remove_matrix(&A1);
}
END_TEST

Suite* determinant_suite(void) {
  Suite* s;
  TCase* tc_core;

  s = suite_create("determinant");

  tc_core = tcase_create("Core");
  tcase_add_test(tc_core, simple_det);
  tcase_add_test(tc_core, det_2);
  tcase_add_test(tc_core, det_3);
  tcase_add_test(tc_core, det_4);
  tcase_add_test(tc_core, det_5);
  tcase_add_test(tc_core, not_square_matrix);

  suite_add_tcase(s, tc_core);
  return s;
}