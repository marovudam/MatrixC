#include "matrix.h"

int mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int return_code = OK;
  if (A->matrix && B->matrix) {
    if (A->columns == B->rows) {
      return_code = create_matrix(A->rows, B->columns, result);
      if (return_code == OK) {
        for (int i = 0; i < result->rows; i++) {
          for (int j = 0; j < result->columns; j++) {
            for (int k = 0; k < A->columns; k++) {
              result->matrix[i][j] += A->matrix[i][k] * B->matrix[k][j];
            }
          }
        }
      }
    } else {
      return_code = INPUT_INCORRECT;
    }
  } else {
    return_code = MATRIX_INCORRECT;
  }
  return return_code;
}