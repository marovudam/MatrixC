#include "matrix.h"

int determinant(matrix_t *A, double *result) {
  int return_code = OK;
  if (A->matrix) {
    if (A->rows == A->columns) {
      if (A->rows == 1) {
        *result = A->matrix[0][0];
      } else {
        *result = 0.0;
        for (int i = 0; i < A->rows; i++) {
          matrix_t submatrix;
          create_matrix(A->rows - 1, A->columns - 1, &submatrix);
          get_submatrix(A, &submatrix, 0, i);
          double small_det;
          determinant(&submatrix, &small_det);
          if (i % 2 == 0) {
            *result += A->matrix[0][i] * small_det;
          } else {
            *result -= A->matrix[0][i] * small_det;
          }
          remove_matrix(&submatrix);
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
