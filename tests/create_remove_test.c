#include <check.h>

#include "../matrix.h"

START_TEST(create_and_remove_matrix) {
  matrix_t a;
  int res = create_matrix(7, 4, &a);
  ck_assert_int_eq(res, 0);
  remove_matrix(&a);
}
END_TEST

START_TEST(incorrect_columns) {
  matrix_t a;
  int res = create_matrix(12, -8, &a);
  ck_assert_int_eq(res, 2);
}
END_TEST

START_TEST(incorrect_rows) {
  matrix_t a;
  int res = create_matrix(0, 3, &a);
  ck_assert_int_eq(res, 2);
}
END_TEST

Suite* create_and_remove_suite(void) {
  Suite* t1;
  TCase* tc_core;
  TCase* tc_limits;

  t1 = suite_create("create_and_remove");

  tc_core = tcase_create("Core");
  tcase_add_test(tc_core, create_and_remove_matrix);
  suite_add_tcase(t1, tc_core);

  tc_limits = tcase_create("Limits");
  tcase_add_test(tc_limits, incorrect_rows);
  tcase_add_test(tc_limits, incorrect_columns);
  suite_add_tcase(t1, tc_limits);

  return t1;
}