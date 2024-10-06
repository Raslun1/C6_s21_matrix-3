#include "s21_matrix.h"

int s21_calc_complements(matrix_t *A, matrix_t *result) {
  int res = OK;

  if (!is_matrix_norm(A) || result == NULL) res = INCORRECT_MATRIX;

  if (A->columns == 1 || A->rows == 1) res = CALC_ERROR;

  if (res == OK) {
    res = s21_create_matrix(A->rows, A->columns, result);
    matrix_t m = {};
    int sign = 1;
    for (int i = 0; i < A->rows; i++) {
      for (int j = 0; j < A->columns; j++) {
        res = s21_minor(A, &m, i, j);
        if (res == OK) {
          double determinant_result = 0;
          res = s21_determinant(&m, &determinant_result);

          result->matrix[i][j] = determinant_result * sign;
          sign = -sign;

          s21_remove_matrix(&m);
        }
      }
      if (A->columns % 2 == 0) {
        sign = -sign;
      }
    }
  }
  return res;
}