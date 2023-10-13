#include "matrix.h"

int transpose(matrix_t *A, matrix_t *result) {
  int return_code = OK;
  if (A->matrix) {
    create_matrix(A->columns, A->rows, result);
    for (int i = 0; i < A->rows; i++) {
      for (int j = 0; j < A->columns; j++) {
        result->matrix[j][i] = A->matrix[i][j];
      }
    }
  } else {
    return_code = MATRIX_INCORRECT;
  }
  return return_code;
}