#ifndef MATRIX_H_
#define MATRIX_H_

#include <stdlib.h>

#define OK 0
#define MATRIX_INCORRECT 1
#define INPUT_INCORRECT 2

typedef struct matrix_struct {
  double **matrix;
  int rows;
  int columns;
} matrix_t;

void print_matrix(matrix_t A);
int is_eq(double a, double b);
void get_submatrix(matrix_t *A, matrix_t *result, int ignore_row,
                   int ignore_column);

int create_matrix(int rows, int columns, matrix_t *result);
void remove_matrix(matrix_t *A);
int eq_matrix(matrix_t *A, matrix_t *B);
int sum_matrix(matrix_t *A, matrix_t *B, matrix_t *result);
int sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result);
int mult_number(matrix_t *A, double number, matrix_t *result);
int mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result);
int transpose(matrix_t *A, matrix_t *result);
int calc_complements(matrix_t *A, matrix_t *result);
int determinant(matrix_t *A, double *result);
int inverse_matrix(matrix_t *A, matrix_t *result);

#endif  // MATRIX_H_