#include "s21_matrix.h"

bool is_size_normal(matrix_t *A, matrix_t *B) {
  return (A->rows == B->rows && A->columns == B->columns) ? true : false;
}
bool is_matrix_norm(matrix_t *m) {
  return (m != NULL && m->matrix != NULL && m->columns > 0 && m->rows > 0)
             ? true
             : false;
}

int s21_minor(matrix_t *A, matrix_t *M, int crossed_row, int crossed_column) {
  int res = s21_create_matrix(A->rows - 1, A->columns - 1, M);

  int row_2 = 0, column_2 = 0;

  for (int i = 0; i < A->rows; i++) {
    if (crossed_row == i) {
      continue;
    }
    column_2 = 0;
    for (int j = 0; j < A->columns; j++) {
      if (crossed_column != j) {
        M->matrix[row_2][column_2] = A->matrix[i][j];
        column_2++;
      }
    }
    if (crossed_row != i) {
      row_2++;
    }
  }
  return res;
}