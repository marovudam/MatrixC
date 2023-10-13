#include <check.h>

#include "../matrix.h"

START_TEST(equal_matrix) {
  matrix_t A1;
  int code1 = create_matrix(2, 3, &A1);
  A1.matrix[0][0] = 9.2132;
  A1.matrix[0][1] = 4.721398;
  A1.matrix[0][2] = -0.00001;
  A1.matrix[1][0] = 213.9304;
  A1.matrix[1][1] = -293.0;
  A1.matrix[1][2] = 74.9;

  matrix_t A2;
  int code2 = create_matrix(2, 3, &A2);
  A2.matrix[0][0] = 9.2132;
  A2.matrix[0][1] = 4.721398;
  A2.matrix[0][2] = -0.00001;
  A2.matrix[1][0] = 213.9304;
  A2.matrix[1][1] = -293.0;
  A2.matrix[1][2] = 74.9;

  int res = eq_matrix(&A1, &A2);

  ck_assert_int_eq(code1, 0);
  ck_assert_int_eq(code2, 0);

  ck_assert_int_eq(res, 1);

  remove_matrix(&A1);
  remove_matrix(&A2);
}
END_TEST

START_TEST(not_equal_matrix) {
  matrix_t A1;
  int code1 = create_matrix(2, 3, &A1);
  A1.matrix[0][0] = 9.2132;
  A1.matrix[0][1] = 4.721398;
  A1.matrix[0][2] = -0.00001;
  A1.matrix[1][0] = 213.9304;
  A1.matrix[1][1] = -293.0;
  A1.matrix[1][2] = 74.9;

  matrix_t A2;
  int code2 = create_matrix(2, 3, &A2);
  A2.matrix[0][0] = 9.2132;
  A2.matrix[0][1] = 4.721398;
  A2.matrix[0][2] = -0.00001;
  A2.matrix[1][0] = 213.9304;
  A2.matrix[1][1] = -2903.0;
  A2.matrix[1][2] = 74.9;
  // look closely at A[1][1]

  int res = eq_matrix(&A1, &A2);

  ck_assert_int_eq(code1, 0);
  ck_assert_int_eq(code2, 0);

  ck_assert_int_eq(res, 0);

  remove_matrix(&A1);
  remove_matrix(&A2);
}
END_TEST

START_TEST(different_sizing) {
  matrix_t A1;
  int code1 = create_matrix(2, 1, &A1);
  A1.matrix[0][0] = 9.2132;
  A1.matrix[1][0] = 213.9304;

  matrix_t A2;
  int code2 = create_matrix(2, 3, &A2);
  A2.matrix[0][0] = 9.2132;
  A2.matrix[0][1] = 4.721398;
  A2.matrix[0][2] = -0.00001;
  A2.matrix[1][0] = 213.9304;
  A2.matrix[1][1] = -293.0;
  A2.matrix[1][2] = 74.9;

  int res = eq_matrix(&A1, &A2);

  ck_assert_int_eq(code1, 0);
  ck_assert_int_eq(code2, 0);

  ck_assert_int_eq(res, 0);

  remove_matrix(&A1);
  remove_matrix(&A2);
}
END_TEST

START_TEST(eq_seven_digits) {
  matrix_t A1;
  int code1 = create_matrix(2, 1, &A1);
  A1.matrix[0][0] = 9.21325670;
  A1.matrix[1][0] = 213.9304;

  matrix_t A2;
  int code2 = create_matrix(2, 1, &A2);
  A2.matrix[0][0] = 9.21325671;
  A2.matrix[1][0] = 213.9304;

  int res = eq_matrix(&A1, &A2);

  ck_assert_int_eq(code1, 0);
  ck_assert_int_eq(code2, 0);

  ck_assert_int_eq(res, 1);

  remove_matrix(&A1);
  remove_matrix(&A2);
}
END_TEST

Suite* equal_suite(void) {
  Suite* s;
  TCase* tc_core;
  TCase* tc_limits;

  s = suite_create("equal");

  tc_core = tcase_create("Core");
  tcase_add_test(tc_core, equal_matrix);
  tcase_add_test(tc_core, not_equal_matrix);
  tcase_add_test(tc_core, different_sizing);

  tc_limits = tcase_create("Limits");
  tcase_add_test(tc_limits, eq_seven_digits);

  suite_add_tcase(s, tc_core);
  suite_add_tcase(s, tc_limits);
  return s;
}