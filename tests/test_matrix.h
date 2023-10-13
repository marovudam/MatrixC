#ifndef MATRIXC_TESTS_TEST_MATRIX_H_
#define MATRIXC_TESTS_TEST_MATRIX_H_
#include <check.h>

#include "../matrix.h"

Suite* create_and_remove_suite(void);
Suite* equal_suite(void);
Suite* sum_suite(void);
Suite* sub_suite(void);
Suite* mult_number_suite(void);
Suite* transpose_suite(void);
Suite* mult_matrix_suite(void);
Suite* determinant_suite(void);
Suite* calc_complements_suite(void);
Suite* inverse_matrix_suite(void);

#endif  // MATRIXC_TESTS_TEST_MATRIX_H_