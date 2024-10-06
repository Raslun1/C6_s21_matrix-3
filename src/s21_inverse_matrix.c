#include "s21_matrix.h"

int s21_inverse_matrix(matrix_t *A, matrix_t *result) {
  int res = OK;
  if (!is_matrix_norm(A) || result == NULL) {
    res = INCORRECT_MATRIX;
  }

  double determinant = 0.0;
  s21_determinant(A, &determinant);

  if (A->rows != A->columns || determinant == 0.0) {
    res = CALC_ERROR;
  }

  if (res == OK) {
    if (A->rows == 1 && A->matrix[0][0] != 0) {
      s21_create_matrix(A->rows, A->columns, result);
      result->matrix[0][0] = 1 / A->matrix[0][0];
    } else if (A->rows > 1) {
      matrix_t M = {};
      matrix_t transpose_M = {};

      res = s21_calc_complements(A, &M);

      if (res == OK) {
        res = s21_transpose(&M, &transpose_M);
      }
      if (res == OK) {
        res = s21_mult_number(&transpose_M, 1 / determinant, result);
      }
      s21_remove_matrix(&M);
      s21_remove_matrix(&transpose_M);
    }
  }

  return res;
}