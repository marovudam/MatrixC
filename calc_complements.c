#include "matrix.h"

int calc_complements(matrix_t *A, matrix_t *result) {
  int return_code = OK;
  if (A->matrix) {
    if (A->rows == A->columns) {
      create_matrix(A->rows, A->columns, result);
      if (A->rows == 1) {
        result->matrix[0][0] = A->matrix[0][0];
      } else {
        matrix_t submatrix;
        create_matrix(A->rows - 1, A->columns - 1, &submatrix);
        for (int i = 0; i < A->rows; i++) {
          for (int j = 0; j < A->columns; j++) {
            get_submatrix(A, &submatrix, i, j);
            double det;
            determinant(&submatrix, &det);
            result->matrix[i][j] = det;
            if ((i + j) % 2) result->matrix[i][j] *= -1;
          }
        }
        remove_matrix(&submatrix);
      }
    } else {
      return_code = INPUT_INCORRECT;
    }
  } else {
    return_code = MATRIX_INCORRECT;
  }
  return return_code;
}