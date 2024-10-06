#include "s21_matrix.h"

int s21_determinant(matrix_t *A, double *result) {
  int res = OK;
  if (!is_matrix_norm(A)) {
    res = INCORRECT_MATRIX;
  }

  if (A->rows != A->columns) {
    res = CALC_ERROR;
  }

  if (res == OK) {
    double determinant = 0;

    if (A->rows == 1) {
      determinant = A->matrix[0][0];
    } else if (A->rows == 2) {
      determinant = (A->matrix[0][0] * A->matrix[1][1]) -
                    (A->matrix[0][1] * A->matrix[1][0]);
    } else {
      int sign = 1;
      for (int i = 0; i < A->columns; i++) {
        matrix_t M = {};
        res = s21_minor(A, &M, 0, i);

        double minor_result = 0;
        res = s21_determinant(&M, &minor_result);

        determinant += sign * A->matrix[0][i] * minor_result;
        sign = -sign;

        s21_remove_matrix(&M);
      }
    }
    *result = determinant;
  }

  return res;
}
