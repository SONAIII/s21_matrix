#include "s21_matrix.h"

int s21_transpose(matrix_t *A, matrix_t *result) {
    if (is_null(A) || is_null(result)) {
        return MAT_ERROR;
    }
    int res_code = s21_create_matrix(A->columns, A->rows, result);
    if (res_code != OK) {
        return res_code;
    }
    for (int m = 0; m < A->rows; m++) {
        for (int n = 0; n < A->columns; n++) {
            result->matrix[n][m] = A->matrix[m][n];
        }
    }
    return OK;
}
