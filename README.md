# MatrixC
Matrices. In C. With some methods to use then.
+ C11
+ `gcc` compiler used
+ `<check.h>` for testing
+ `gcovr` and `lcov` used to check coverage (which is higher than 80%  for overall lib)

## Makefile targets

+ `all` and `matrix.a` build static library matrix.a
+ `test` builds and runs tests. `<check.h>` is used
+ `clean` deletes all files that could be created by the other targets
+ `lint` checks if code is formatted according to Google Style (uses `clang-format`)
+ `fix-lint` auto-corrects formatting (uses `clang-format`)
+ `mem-leaks` checks for memory leaks that could occure while running tests. `leaks` utility used, target needs library `<check.h>` to build tests correctly

## Methods implemented

| Method | Description |
|--------|-------------|
|`int create_matrix(int rows, int columns, matrix_t *result)`| Creates matrix of `rows * columns` size |
|`void remove_matrix(matrix_t *A)`| Deallocates all memory in matrix, sets the number of rows an columns to a zero|
|`int eq_matrix(matrix_t *A, matrix_t *B)`| checks if matrices and ther values are equal (uses 1e7 precision)|
|`int sum_matrix(matrix_t *A, matrix_t *B, matrix_t *result)`| Sums two matrices if possible|
|`int sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result)`| Subscribes second matrix from the first|
|`int mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result)`| Multiplicates two matrices|
|`int determinant(matrix_t *A, double *result)`| Calculates the determinant of an matrix (if it is possible). _Method uses recursion, might fail at matrices bigger than 10*10 due to stack overflow_|
|`int transpose(matrix_t *A, matrix_t *result)`|Transposes current matrix|
|`int mult_number(matrix_t *A, double number, matrix_t *result)` |Multiplicates all the values of matrix to a given floating point number|
| `int calc_complements(matrix_t *A, matrix_t *result)` | Calculates matrix of algebraic complements |
| `int inverse_matrix(matrix_t *A, matrix_t *result)` |Calculates inverse of an matrix |

There are some utility functions i will not describe ([file](utility.c))