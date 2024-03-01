#include "s21_matrix.h"

int zero_column(matrix_t *A, int column) {
    int code = 1;
    for (int i = 0; i < A->rows; i++) {
        if (A->matrix[i][column] != 0) {
            code = 0;
            break;
        }
    }
    return code;
}

void swap_rows(matrix_t *A, int row1, int row2) {
    for (int i = 0; i < A->columns; i++) {
        double temp = A->matrix[row1][i];
        A->matrix[row1][i] = A->matrix[row2][i];
        A->matrix[row2][i] = temp;
    }
}

int find_row_and_swap(matrix_t *A, int row) {
    for (int i = row + 1; i < A->rows; i++) {
        if (A->matrix[i][row] != 0) {
            swap_rows(A, i, row);
            return OK;
        }
    }
    return CALC_ERROR;
}

int s21_determinant(matrix_t *A, double *result) {
    int sign = 1;
    if (is_null(A) || result == NULL) {
        return MAT_ERROR;
    }
    if (A->rows != A->columns) {
        return CALC_ERROR;
    }
    matrix_t B;
    s21_create_matrix(A->rows, A->columns, &B);

    for (int i = 0; i < A->rows; i++) {
        for (int j = 0; j < A->columns; j++) {
            B.matrix[i][j] = A->matrix[i][j];
        }
    }

    for (int cur_col = 0; cur_col < B.columns; cur_col++) {
        // print_matrix(A);
        if (zero_column(&B, cur_col)) {
            *result = 0;
            return OK;
        }
        else {
            if (B.matrix[cur_col][cur_col] == 0) {
                find_row_and_swap(&B, cur_col);
                sign = -1 * sign;

            }
            // printf("%lf\n", B.matrix[cur_col][cur_col]);
            for (int row = cur_col + 1; row < B.rows; row++) {
                double x = B.matrix[row][cur_col] / B.matrix[cur_col][cur_col] * -1.0;
                // printf("%lf %d\n", x, row);
                for (int col = cur_col; col < B.columns; col++) {
                    B.matrix[row][col] += B.matrix[cur_col][col] * x;
                }
            }
        }
    }
    // print_matrix(A);
    *result = 1 * sign;
    for (int i = 0; i < B.rows; i++) {
        *result *= B.matrix[i][i];
    }
    return OK;
}
