#include "s21_matrix.h"

int s21_eq_matrix(matrix_t *A, matrix_t *B) {
  int res = SUCCESS;
  if (is_size_normal(A, B) && is_matrix_norm(A) && is_matrix_norm(B)) {
    for (int i = 0; i < A->rows && res == SUCCESS; i++) {
      for (int j = 0; j < A->columns && res == SUCCESS; j++) {
        res =
            (fabs(A->matrix[i][j] - B->matrix[i][j]) < EPS) ? SUCCESS : FAILURE;
      }
    }
  } else {
    res = FAILURE;
  }
  return res;
}
