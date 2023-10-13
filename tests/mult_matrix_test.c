#include <check.h>

#include "../matrix.h"

START_TEST(cannot_mult_those) {
  matrix_t A;
  int code1 = create_matrix(1, 2, &A);
  A.matrix[0][0] = 1.0;
  A.matrix[0][1] = 4.0;

  matrix_t B;
  int code2 = create_matrix(1, 2, &B);
  B.matrix[0][0] = 1.0;
  B.matrix[0][1] = -1.0;

  matrix_t result;
  int mul_code = mult_matrix(&A, &B, &result);

  ck_assert_int_eq(code1, 0);
  ck_assert_int_eq(code2, 0);

  ck_assert_int_eq(mul_code, 2);

  remove_matrix(&A);
  remove_matrix(&B);
}
END_TEST

START_TEST(not_an_readme_mult) {
  matrix_t A;
  int code1 = create_matrix(2, 2, &A);
  A.matrix[0][0] = 1.0;
  A.matrix[0][1] = 4.0;
  A.matrix[1][0] = 2.0;
  A.matrix[1][1] = 0.0;

  matrix_t B;
  int code2 = create_matrix(2, 2, &B);
  B.matrix[0][0] = 1.0;
  B.matrix[0][1] = -1.0;
  B.matrix[1][0] = 2.0;
  B.matrix[1][1] = 3.0;

  matrix_t result;
  int mul_code = mult_matrix(&A, &B, &result);

  matrix_t true_result;
  int code3 = create_matrix(2, 2, &true_result);
  true_result.matrix[0][0] = 9.0;
  true_result.matrix[0][1] = 11.0;
  true_result.matrix[1][0] = 2.0;
  true_result.matrix[1][1] = -2.0;

  int res = eq_matrix(&true_result, &result);

  ck_assert_int_eq(code1, 0);
  ck_assert_int_eq(code2, 0);
  ck_assert_int_eq(code3, 0);

  ck_assert_int_eq(mul_code, 0);
  ck_assert_int_eq(res, 1);

  remove_matrix(&A);
  remove_matrix(&B);
  remove_matrix(&result);
  remove_matrix(&true_result);
}
END_TEST

START_TEST(readme_mult) {
  matrix_t A;
  int code1 = create_matrix(3, 2, &A);
  A.matrix[0][0] = 1.0;
  A.matrix[0][1] = 4.0;
  A.matrix[1][0] = 2.0;
  A.matrix[1][1] = 5.0;
  A.matrix[2][0] = 3.0;
  A.matrix[2][1] = 6.0;

  matrix_t B;
  int code2 = create_matrix(2, 3, &B);
  B.matrix[0][0] = 1.0;
  B.matrix[0][1] = -1.0;
  B.matrix[0][2] = 1.0;
  B.matrix[1][0] = 2.0;
  B.matrix[1][1] = 3.0;
  B.matrix[1][2] = 4.0;

  matrix_t result;
  int mul_code = mult_matrix(&A, &B, &result);

  matrix_t true_result;
  int code3 = create_matrix(3, 3, &true_result);
  true_result.matrix[0][0] = 9.0;
  true_result.matrix[0][1] = 11.0;
  true_result.matrix[0][2] = 17.0;
  true_result.matrix[1][0] = 12.0;
  true_result.matrix[1][1] = 13.0;
  true_result.matrix[1][2] = 22.0;
  true_result.matrix[2][0] = 15.0;
  true_result.matrix[2][1] = 15.0;
  true_result.matrix[2][2] = 27.0;

  int res = eq_matrix(&true_result, &result);

  ck_assert_int_eq(code1, 0);
  ck_assert_int_eq(code2, 0);
  ck_assert_int_eq(code3, 0);

  ck_assert_int_eq(mul_code, 0);
  ck_assert_int_eq(res, 1);

  remove_matrix(&A);
  remove_matrix(&B);
  remove_matrix(&result);
  remove_matrix(&true_result);
}
END_TEST

Suite* mult_matrix_suite(void) {
  Suite* s;
  TCase* tc_core;

  s = suite_create("mult_matrix");

  tc_core = tcase_create("core");
  tcase_add_test(tc_core, not_an_readme_mult);
  tcase_add_test(tc_core, readme_mult);
  tcase_add_test(tc_core, cannot_mult_those);
  suite_add_tcase(s, tc_core);

  return s;
}