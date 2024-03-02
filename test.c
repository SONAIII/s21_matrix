// #include "s21_matrix.h"

// int main() {
//     matrix_t A, result;
//     int m = 4, n = 4;
//     double arr[] = {1,5, 6, 7, 3, 4, 5, 6, 4, 5, 6, 1, 1, 2, 3, 4};

//     if (!s21_create_matrix(m, n, &A)) {
//         for (int i = 0, count = 0; i < A.rows; i++) {
//             for (int j = 0; j < A.columns; j++, count++) {
//                 A.matrix[i][j] = arr[count];
//             }
//         }
//     }
//     else {
//         printf("Pizdec happened\n");
//     }
//     // s21_determinant(&A, &result);
//     s21_inverse_matrix(&A, &result);
//     // print_matrix(&A);
//     print_matrix(&result);
//     // printf("%lf\n", result);
//     return 0;
// }

//     // matrix_t A,B, result;
//     // int m = 2, n = 2;
//     // double arr[] = {52.92774, 0.000001, 53.9475, -8.3471, 12.97342};

//     // if (!s21_create_matrix(m, n, &A)) {
//     //     for (int i = 0, count = 0; i < A.rows; i++) {
//     //         for (int j = 0; j < A.columns; j++, count++) {
//     //             A.matrix[i][j] = arr[count];
//     //         }
//     //     }
//     // }
//     // else {
//     //     printf("Pizdec happened\n");
//     // }

//     // if (!s21_create_matrix(m, n, &B)) {
//     //     for (int i = 0, count = 0; i < B.rows; i++) {
//     //         for (int j = 0; j < B.columns; j++, count++) {
//     //             B.matrix[i][j] = arr[count];
//     //         }
//     //     }
//     // }
//     // else {
//     //     printf("Pizdec happened\n");
//     // }
//     // int res_eq = s21_eq_matrix(&A, &B);
//     // printf("%d\n", res_eq);
//     // s21_sum_matrix(&A, &B, &result);
//     // print_matrix(&result);
//     // s21_remove_matrix(&A);
//     // s21_remove_matrix(&result);

//     // matrix_t A, result;
//     // int number = 3;
//     // int m = 2, n = 2;
//     // double arr[] = {52.92774, 0.000001, 53.9475, -8.3471, 12.97342};

//     // if (!s21_create_matrix(m, n, &A)) {
//     //     for (int i = 0, count = 0; i < A.rows; i++) {
//     //         for (int j = 0; j < A.columns; j++, count++) {
//     //             A.matrix[i][j] = arr[count];
//     //         }
//     //     }
//     // }
//     // else {
//     //     printf("Pizdec happened\n");
//     // }
//     // s21_mult_number(&A, number, &result);
//     // print_matrix(&result);
//     // s21_remove_matrix(&A);
//     // s21_remove_matrix(&result);

//     //     matrix_t A, result;
//     // int m = 2, n = 3;
//     // double arr[] = {52.92774, 0.000001, 53.9475,
//     -8.3471, 12.97342, 3.3212};

//     // if (!s21_create_matrix(m, n, &A)) {
//     //     for (int i = 0, count = 0; i < A.rows; i++) {
//     //         for (int j = 0; j < A.columns; j++, count++) {
//     //             A.matrix[i][j] = arr[count];
//     //         }
//     //     }
//     // }
//     // else {
//     //     printf("Pizdec happened\n");
//     // }
//     // print_matrix(&A);
//     // s21_transpose(&A, &result);
//     // printf("--------------------\n");
//     // print_matrix(&result);
//     // s21_remove_matrix(&A);
//     // s21_remove_matrix(&result);

//     // matrix_t A,B, result;
//     // int m = 2, n = 3;
//     // double arr[] = {1, 2, 3, 3, 4, 5};

//     // if (!s21_create_matrix(m, n, &A)) {
//     //     for (int i = 0, count = 0; i < A.rows; i++) {
//     //         for (int j = 0; j < A.columns; j++, count++) {
//     //             A.matrix[i][j] = arr[count];
//     //         }
//     //     }
//     // }
//     // else {
//     //     printf("Pizdec happened\n");
//     // }
//     // m = 3;
//     // n = 2;

//     // double arr2[] = {2, 3, 1, 2, 2, 2};

//     // if (!s21_create_matrix(m, n, &B)) {
//     //     for (int i = 0, count = 0; i < B.rows; i++) {
//     //         for (int j = 0; j < B.columns; j++, count++) {
//     //             B.matrix[i][j] = arr2[count];
//     //         }
//     //     }
//     // }
//     // else {
//     //     printf("Pizdec happened\n");
//     // }
//     // print_matrix(&A);
//     // printf("-------------\n");
//     // print_matrix(&B);

//     // printf("-------------\n");

//     // s21_mult_matrix(&A, &B, &result);
//     // print_matrix(&result);