#include "s21_matrix.h"

int s21_inverse_matrix(matrix_t *A, matrix_t *result) {
  if (is_null(A) || !result) {
    return MAT_ERROR;
  }

  int return_code = OK;
  matrix_t complements;
  double determinant;

  return_code = s21_create_matrix(A->rows, A->columns, result);
  if (return_code) {
    return CALC_ERROR;
  }
  return_code = s21_create_matrix(A->rows, A->columns, &complements);
  if (return_code) {
    return CALC_ERROR;
  }

  return_code = s21_determinant(A, &determinant);
  if (return_code || determinant == 0) {
    return CALC_ERROR;
  }

  if (A->columns == 1 && A->rows == 1) {
    result->matrix[0][0] = 1 / determinant;
    printf("%lf\n", A->matrix[0][0]);
    return OK;
  }

  matrix_t transposed;
  return_code = s21_create_matrix(A->rows, A->columns, &transposed);

  if (return_code) {
    return CALC_ERROR;
  }

  s21_transpose(A, &transposed);

  return_code = s21_calc_complements(&transposed, &complements);
  if (return_code) {
    return CALC_ERROR;
  }

  s21_mult_number(&complements, 1 / determinant, result);

  return OK;
}
