#include "s21_matrix.h"

int s21_inverse_matrix(matrix_t *A, matrix_t *result) {
    if (is_null(A) || is_null(result)) {
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


    // print_matrix(&complements);
    // print_matrix(&transposed);
    // printf("%lf\n", 1 / determinant);

    s21_mult_number(&complements, 1 / determinant, result);
    
    return OK;
}
