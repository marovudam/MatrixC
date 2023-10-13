#include <check.h>
#include <stdio.h>
#include <stdlib.h>

#include "tests/test_matrix.h"

int main() {
  int no_failed = 0;
  Suite *create, *equal, *sum, *sub, *mult_number, *mult_matrix, *transpose,
      *complements, *determinant, *inverse;
  SRunner* runner;

  create = create_and_remove_suite();
  equal = equal_suite();
  sum = sum_suite();
  sub = sub_suite();
  mult_number = mult_number_suite();
  mult_matrix = mult_matrix_suite();
  transpose = transpose_suite();
  complements = calc_complements_suite();
  determinant = determinant_suite();
  inverse = inverse_matrix_suite();

  runner = srunner_create(create);
  srunner_add_suite(runner, equal);
  srunner_add_suite(runner, sum);
  srunner_add_suite(runner, sub);
  srunner_add_suite(runner, mult_number);
  srunner_add_suite(runner, mult_matrix);
  srunner_add_suite(runner, transpose);
  srunner_add_suite(runner, complements);
  srunner_add_suite(runner, determinant);
  srunner_add_suite(runner, inverse);

  srunner_run_all(runner, CK_NORMAL);

  no_failed = srunner_ntests_failed(runner);
  srunner_free(runner);
  return (no_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}