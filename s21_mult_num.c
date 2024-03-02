#include <math.h>

#include "s21_matrix.h"

int s21_mult_number(matrix_t *A, double number, matrix_t *result) {
  if (is_null(A) || !result) {
    return MAT_ERROR;
  }

  int res_code = s21_create_matrix(A->rows, A->columns, result);
  if (res_code != OK) {
    return res_code;
  }
  for (int m = 0; m < A->rows; m++) {
    for (int n = 0; n < A->columns; n++) {
      result->matrix[m][n] = A->matrix[m][n] * number;
    }
  }
  return OK;
}
