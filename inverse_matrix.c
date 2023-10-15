#include "matrix.h"

int inverse_matrix(matrix_t *A, matrix_t *result) {
  int return_code = OK;
  if (A->matrix) {
    if (A->rows == A->columns) {
      double det;
      determinant(A, &det);
      if (!is_eq(det, 0.0)) {
        if (A->rows == 1) {
          return_code = create_matrix(1, 1, result);
          if (return_code == OK) result->matrix[0][0] = 1 / det;
        } else {
          matrix_t transposed;
          matrix_t invert;
          transpose(A, &transposed);
          calc_complements(&transposed, &invert);
          mult_number(&invert, 1 / det, result);
          remove_matrix(&transposed);
          remove_matrix(&invert);
        }
      } else {
        return_code = INPUT_INCORRECT;
      }
    } else {
      return_code = INPUT_INCORRECT;
    }
  } else {
    return_code = MATRIX_INCORRECT;
  }
  return return_code;
}
