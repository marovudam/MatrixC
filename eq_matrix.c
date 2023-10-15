#include "matrix.h"

int eq_matrix(matrix_t *A, matrix_t *B) {
  int return_code = SUCCESS;
  if (A->rows == B->rows && A->columns == B->columns) {
    for (int i = 0; i < A->rows; i++) {
      for (int j = 0; j < A->columns; j++) {
        if (!is_eq(A->matrix[i][j], B->matrix[i][j])) return_code = FAILURE;
      }
    }
  } else {
    return_code = FAILURE;
  }
  return return_code;
}
