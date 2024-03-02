#include "s21_matrix.h"

int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  if (is_null(A) || is_null(B)) {
    return MAT_ERROR;
  }
  if (check_multiplication(A, B)) {
    return CALC_ERROR;
  }

  s21_create_matrix(A->rows, B->columns, result);
  for (int m = 0; m < A->rows; m++) {
    for (int n = 0; n < B->columns; n++) {
      for (int k = 0; k < A->columns; k++) {
        result->matrix[m][n] += A->matrix[m][k] * B->matrix[k][n];
      }
    }
  }
  return OK;
}
