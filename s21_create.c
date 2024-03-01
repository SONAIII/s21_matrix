#include "s21_matrix.h"

int s21_create_matrix(int rows, int columns, matrix_t *result) {
    // If the size of matrix is invalid or result is null, return error
    if (invalid_size(rows, columns) || is_null(result)) {
        return MAT_ERROR;
    }
    // Allocate memory for matrix
    result->rows = rows;
    result->columns = columns;
    result->matrix = (double**)calloc(rows, sizeof(double*));  // Allocate memory for rows
    if (result->matrix == NULL) {
        return MAT_ERROR;
    }
    else {
        for (int i = 0; i < rows; i++) {
            result->matrix[i] = (double*)calloc(columns, sizeof(double));  // Allocate memory for columns
            if (result->matrix[i] == NULL) {
                return MAT_ERROR;
            }
        }
    }
    return OK;
}