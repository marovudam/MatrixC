#include <math.h>

#include "matrix.h"

int is_eq(double a, double b) {
  int return_code = 0;
  if (a == b) {
    return_code = 1;
  } else {
    a = a * 10000000;
    b = b * 10000000;
    if (trunc(a) == trunc(b)) return_code = 1;
    if (round(a) == round(b)) return_code = 1;
  }
  return return_code;
}

void get_submatrix(matrix_t *A, matrix_t *result, int ignore_row,
                   int ignore_column) {
  int l = 0;
  for (int i = 0; i < result->rows; i++) {
    int k = 0;
    if (l == ignore_row) l++;
    for (int j = 0; j < result->columns; j++) {
      if (k == ignore_column) k++;
      result->matrix[i][j] = A->matrix[l][k];
      k++;
    }
    l++;
  }
}
