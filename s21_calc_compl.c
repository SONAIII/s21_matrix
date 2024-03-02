#include <math.h>

#include "s21_matrix.h"

int s21_calc_complements(matrix_t *A, matrix_t *result) {
  if (is_null(A) || !result) {
    return MAT_ERROR;
  }
  if (A->rows < 2 || A->columns < 2) {
    return CALC_ERROR;
  }

  int res_code = s21_create_matrix(A->rows, A->columns, result);
  if (res_code != OK) {
    return res_code;
  }

  for (int m = 0; m < A->rows; m++) {
    for (int n = 0; n < A->columns; n++) {
      matrix_t tmp;
      s21_create_matrix(A->rows - 1, A->columns - 1, &tmp);
      for (int i = 0; i < A->rows; i++) {
        for (int j = 0; j < A->columns; j++) {
          if (i != m && j != n) {
            tmp.matrix[i < m ? i : i - 1][j < n ? j : j - 1] = A->matrix[i][j];
          }
        }
      }
      // print_matrix(&tmp);
      s21_determinant(&tmp, &result->matrix[m][n]);
      result->matrix[m][n] = result->matrix[m][n] * pow(-1, m + n);
    }
  }
  return OK;
}
