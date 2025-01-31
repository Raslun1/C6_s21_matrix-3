#include "s21_matrix.h"

int s21_sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int res = OK;
  if (!is_matrix_norm(A) || !is_matrix_norm(B)) res = INCORRECT_MATRIX;
  if (!is_size_normal(A, B)) res = CALC_ERROR;
  if (res == OK) {
    res = s21_create_matrix(A->rows, A->columns, result);
    for (int i = 0; i < A->rows; i++) {
      for (int j = 0; j < A->columns; j++) {
        result->matrix[i][j] = A->matrix[i][j] - B->matrix[i][j];
      }
    }
  }

  return res;
}