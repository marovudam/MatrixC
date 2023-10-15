#include "matrix.h"

int sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int return_code = OK;
  if (A->matrix && B->matrix) {
    if (A->rows == B->rows && A->columns == B->columns) {
      return_code = create_matrix(A->rows, A->columns, result);
      if (return_code == OK) {
        for (int i = 0; i < A->rows; i++) {
          for (int j = 0; j < A->columns; j++) {
            result->matrix[i][j] = A->matrix[i][j] - B->matrix[i][j];
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
