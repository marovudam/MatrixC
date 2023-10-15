#include "matrix.h"

int create_matrix(int rows, int columns, matrix_t *result) {
  int return_code = OK;
  if (rows > 0 && columns > 0) {
    result->matrix = (double **)calloc(rows, sizeof(double *));
    if (result->matrix) {
      for (int i = 0; i < rows; i++) {
        result->matrix[i] = (double *)calloc(columns, sizeof(double));
        if (!(result->matrix[i])) {
          return_code = MATRIX_INCORRECT;
          for (int j = i - 1; j >= 0; j--) {
            free(result->matrix[j]);
          }
          break;
        }
      }
      result->rows = rows;
      result->columns = columns;
    } else {
      return_code = MATRIX_INCORRECT;
    }
  } else {
    return_code = INPUT_INCORRECT;
  }
  return return_code;
}
