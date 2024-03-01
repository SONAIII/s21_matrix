#include "s21_matrix.h"

int s21_sum_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
    if (is_null(A) || is_null(B)) {
        return MAT_ERROR;
    }
    if (equal_sizes(A, B)) {
        return CALC_ERROR;
    }

    int res_code = s21_create_matrix(A->rows, A->columns, result);
    if (res_code != OK) {
        return res_code;
    }
    for (int m = 0; m < A->rows; m++) {
        for (int n = 0; n < A->columns; n++) {
            result->matrix[m][n] = A->matrix[m][n] + B->matrix[m][n];
        }
    }
    return OK;
}
