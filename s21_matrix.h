#ifndef MATRIX
#define MATRIX
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
typedef struct matrix_struct {
    double** matrix;
    int rows;
    int columns;
} matrix_t;

#define OK 0
#define MAT_ERROR 1
#define CALC_ERROR 2
// Defines for compare function
#define SUCCESS 1
#define FAILURE 0


// Functions to do
int s21_create_matrix(int rows, int columns, matrix_t *result);

void s21_remove_matrix(matrix_t *A);

int s21_eq_matrix(matrix_t *A, matrix_t *B);


// Arithmetics
int s21_sum_matrix(matrix_t *A, matrix_t *B, matrix_t *result);
int s21_sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result);
int s21_mult_number(matrix_t *A, double number, matrix_t *result);
int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result);

// Other Operations
int s21_transpose(matrix_t *A, matrix_t *result);

int s21_calc_complements(matrix_t *A, matrix_t *result);

int s21_determinant(matrix_t *A, double *result);

int s21_inverse_matrix(matrix_t *A, matrix_t *result);



// Helpers
int is_null(matrix_t *A);
int invalid_size(int rows, int columns);
int equal_sizes(matrix_t *A, matrix_t *B);
int check_multiplication(matrix_t *A, matrix_t *B);
void print_matrix(matrix_t *A);
#endif


