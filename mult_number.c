#include "matrix.h"

int mult_number(matrix_t *A, double number, matrix_t *result) {
  int return_code = OK;
  if (A->matrix) {
    create_matrix(A->rows, A->columns, result);
    for (int i = 0; i < A->rows; i++) {
      for (int j = 0; j < A->columns; j++) {
        result->matrix[i][j] = A->matrix[i][j] * number;
      }
    }
  } else {
    return_code = MATRIX_INCORRECT;
  }
  return return_code;
}
