#include "s21_matrix.h"

void print_matrix(matrix_t *A) {
    for (int i = 0; i < A->rows; i++) {
        for (int j = 0; j < A->columns; j++) {
            printf("%lf ", A->matrix[i][j]);
        }
        printf("\n");
    }
}


int is_null(matrix_t *A) {
    if (A == NULL) {
        return 1;
    }
    return 0;
}

int invalid_size(int rows, int columns) {
    if (rows < 1 || columns < 1) {
        return 1;
    }
    return 0;
}

int equal_sizes(matrix_t *A, matrix_t *B) {
    if (A->rows != B->rows || A->columns != B->columns) {
        return 1;
    }
    return 0;
}

int check_multiplication(matrix_t *A, matrix_t *B) {
    if (A->columns != B->rows) {
        return 1;
    }
    return 0;
}