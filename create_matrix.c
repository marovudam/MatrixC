#include "matrix.h"

int create_matrix(int rows, int columns, matrix_t *result) {
  int return_code = OK;
  if (rows > 0 && columns > 0) {
    result->matrix = (double **)malloc(rows * sizeof(double *));
    if (result->matrix) {
      for (int i = 0; i < rows; i++) {
        result->matrix[i] = (double *)malloc(columns * sizeof(double));
        if (!(result->matrix[i])) {
          return_code = MATRIX_INCORRECT;
        }
      }
      for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
          result->matrix[i][j] = 0.0;
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
