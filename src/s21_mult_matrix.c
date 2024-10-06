#include "s21_matrix.h"

int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int res = OK;

  if (!is_matrix_norm(A) || !is_matrix_norm(B)) res = INCORRECT_MATRIX;

  if (A->columns != B->rows) res = CALC_ERROR;

  if (res == OK) {
    res = s21_create_matrix(A->rows, B->columns, result);

    // for (int i = 0; i < A->rows; i++) {
    //   for (int j = 0; j < B->columns; j++) {
    //     for (int k = 0; k < A->columns; k++) {
    //       result->matrix[i][j] += A->matrix[i][k] * B->matrix[k][j];
    //     }
    //   }
    // }
    multic(A, B, result);
  }

  return res;
}

void multic(matrix_t *A, matrix_t *B, matrix_t *result) {
  for (int i = 0; i < A->rows; i++) {
    for (int j = 0; j < B->columns; j++) {
      for (int k = 0; k < A->columns; k++) {
        result->matrix[i][j] += A->matrix[i][k] * B->matrix[k][j];
      }
    }
  }
}