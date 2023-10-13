#include <check.h>

#include "../matrix.h"

START_TEST(simple_sub) {
  matrix_t A;
  int code1 = create_matrix(2, 2, &A);
  A.matrix[0][0] = -12.2;
  A.matrix[0][1] = 2.2;
  A.matrix[1][0] = -10.0;
  A.matrix[1][1] = -3.0;

  matrix_t B;
  int code2 = create_matrix(2, 2, &B);
  B.matrix[0][0] = -12.1;
  B.matrix[0][1] = -1.2;
  B.matrix[1][0] = -42.1;
  B.matrix[1][1] = 1.1;

  matrix_t result;
  int sub_code = sub_matrix(&A, &B, &result);

  matrix_t true_result;
  int code3 = create_matrix(2, 2, &true_result);
  true_result.matrix[0][0] = -0.1;
  true_result.matrix[0][1] = 3.4;
  true_result.matrix[1][0] = 32.1;
  true_result.matrix[1][1] = -4.1;

  int res = eq_matrix(&true_result, &result);

  ck_assert_int_eq(code1, 0);
  ck_assert_int_eq(code2, 0);
  ck_assert_int_eq(code3, 0);

  ck_assert_int_eq(sub_code, 0);
  ck_assert_int_eq(res, 1);

  remove_matrix(&A);
  remove_matrix(&B);
  remove_matrix(&result);
  remove_matrix(&true_result);
}
END_TEST

START_TEST(columns_not_equal) {
  matrix_t A;
  int code1 = create_matrix(2, 1, &A);
  A.matrix[0][0] = 5.6;
  A.matrix[1][0] = 1.2;

  matrix_t B;
  int code2 = create_matrix(1, 2, &B);
  B.matrix[0][0] = 6.2;
  B.matrix[0][1] = -1.2;

  matrix_t result;
  int sub_code = sub_matrix(&A, &B, &result);

  ck_assert_int_eq(code1, 0);
  ck_assert_int_eq(code2, 0);

  ck_assert_int_eq(sub_code, 2);

  remove_matrix(&A);
  remove_matrix(&B);
}
END_TEST

Suite* sub_suite(void) {
  Suite* s;
  TCase* tc_core;

  s = suite_create("sub");

  tc_core = tcase_create("core");
  tcase_add_test(tc_core, simple_sub);
  tcase_add_test(tc_core, columns_not_equal);
  suite_add_tcase(s, tc_core);

  return s;
}