#include "test_main.h"

#define SUCCESS 1
#define FAILURE 0
#define OK 0
#define ERROR 2

// void s21_gen_matrix(matrix_t *A) {
//     double num = 1;
//     for (int i = 0; i < A->rows; i++) {
//         for (int j = 0; j < A->columns; j++, num++) {
//             A->matrix[i][j] = num;
//         }
//     }
// }

// void s21_anti_gen_matrix(matrix_t *A) {
//     double num = 32;
//     for (int i = 0; i < A->rows; i++) {
//         for (int j = 0; j < A->columns; j++, num--) {
//             A->matrix[i][j] = num;
//         }
//     }
// }

START_TEST(test_s21_create_matrix) {
  matrix_t my_matrix;
  int ret = s21_create_matrix(4, 4, &my_matrix);
  ck_assert_int_eq(ret, 0);
  s21_remove_matrix(&my_matrix);

  ret = s21_create_matrix(-4, 4, &my_matrix);
  ck_assert_int_eq(ret, 1);

  ret = s21_create_matrix(-4, 0, &my_matrix);
  ck_assert_int_eq(ret, 1);
}
END_TEST

START_TEST(test_s21_eq_matrix) {
  matrix_t matrix_1, matrix_2;
  s21_create_matrix(4, 4, &matrix_1);
  s21_create_matrix(4, 4, &matrix_2);
  int ret = s21_eq_matrix(&matrix_1, &matrix_2);
  ck_assert_int_eq(ret, 1);
  s21_remove_matrix(&matrix_1);
  s21_remove_matrix(&matrix_2);

  ret = s21_eq_matrix(&matrix_1, &matrix_2);
  ck_assert_int_eq(ret, 0);

  s21_create_matrix(4, 4, &matrix_1);
  s21_create_matrix(10, 10, &matrix_2);
  ret = s21_eq_matrix(&matrix_1, &matrix_2);
  ck_assert_int_eq(ret, 0);
  s21_remove_matrix(&matrix_1);
  s21_remove_matrix(&matrix_2);

  s21_create_matrix(4, 4, &matrix_1);
  s21_create_matrix(4, 4, &matrix_2);
  matrix_1.matrix[2][3] = -7;
  ret = s21_eq_matrix(&matrix_1, &matrix_2);
  ck_assert_int_eq(ret, 0);
  s21_remove_matrix(&matrix_1);
  s21_remove_matrix(&matrix_2);

  s21_create_matrix(4, 4, &matrix_1);
  s21_create_matrix(4, 4, &matrix_2);
  matrix_1.matrix[2][3] = -7;
  matrix_2.matrix[2][3] = -7;
  ret = s21_eq_matrix(&matrix_1, &matrix_2);
  ck_assert_int_eq(ret, 1);
  s21_remove_matrix(&matrix_1);
  s21_remove_matrix(&matrix_2);
}
END_TEST

START_TEST(test_s21_sum_matrix) {
  matrix_t matrix_1, matrix_2, res_my, res_org;
  s21_create_matrix(4, 4, &matrix_1);
  s21_create_matrix(4, 4, &matrix_2);
  s21_create_matrix(4, 4, &res_org);
  int ret = s21_sum_matrix(&matrix_1, &matrix_2, &res_my);
  ck_assert_int_eq(ret, 0);
  ret = s21_eq_matrix(&res_my, &res_org);
  ck_assert_int_eq(ret, 1);
  s21_remove_matrix(&matrix_1);
  s21_remove_matrix(&matrix_2);
  s21_remove_matrix(&res_my);
  s21_remove_matrix(&res_org);

  s21_create_matrix(4, 5, &matrix_1);
  s21_create_matrix(4, 4, &matrix_2);
  ret = s21_sum_matrix(&matrix_1, &matrix_2, &res_my);
  ck_assert_int_eq(ret, 2);
  s21_remove_matrix(&matrix_1);
  s21_remove_matrix(&matrix_2);

  s21_create_matrix(4, 5, &matrix_1);
  s21_create_matrix(4, 4, &matrix_2);
  ret = s21_sum_matrix(&matrix_1, &matrix_2, &res_my);
  ck_assert_int_eq(ret, 2);
  s21_remove_matrix(&matrix_1);
  s21_remove_matrix(&matrix_2);

  s21_create_matrix(4, 4, &matrix_1);
  s21_create_matrix(4, 4, &matrix_2);
  s21_create_matrix(4, 4, &res_org);
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      matrix_1.matrix[i][j] = i + j;
      res_org.matrix[i][j] = i + j;
    }
  }
  ret = s21_sum_matrix(&matrix_1, &matrix_2, &res_my);
  ck_assert_int_eq(ret, 0);
  ret = s21_eq_matrix(&res_my, &res_org);
  ck_assert_int_eq(ret, 1);
  s21_remove_matrix(&matrix_1);
  s21_remove_matrix(&matrix_2);
  s21_remove_matrix(&res_my);
  s21_remove_matrix(&res_org);

  s21_create_matrix(4, 4, &matrix_1);
  s21_create_matrix(4, 4, &matrix_2);
  s21_create_matrix(4, 4, &res_org);
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      matrix_1.matrix[i][j] = i + j;
      matrix_2.matrix[i][j] = i + j;
      res_org.matrix[i][j] = (i + j) * 2;
    }
  }
  ret = s21_sum_matrix(&matrix_1, &matrix_2, &res_my);
  ck_assert_int_eq(ret, 0);
  ret = s21_eq_matrix(&res_my, &res_org);
  ck_assert_int_eq(ret, 1);
  s21_remove_matrix(&matrix_1);
  s21_remove_matrix(&matrix_2);
  s21_remove_matrix(&res_my);
  s21_remove_matrix(&res_org);
}
END_TEST

START_TEST(test_s21_sub_matrix) {
  matrix_t matrix_1, matrix_2, res_my, res_org;
  s21_create_matrix(4, 4, &matrix_1);
  s21_create_matrix(4, 4, &matrix_2);
  s21_create_matrix(4, 4, &res_org);
  int ret = s21_sub_matrix(&matrix_1, &matrix_2, &res_my);
  ck_assert_int_eq(ret, 0);
  ret = s21_eq_matrix(&res_my, &res_org);
  ck_assert_int_eq(ret, 1);
  s21_remove_matrix(&matrix_1);
  s21_remove_matrix(&matrix_2);
  s21_remove_matrix(&res_my);
  s21_remove_matrix(&res_org);

  s21_create_matrix(4, 5, &matrix_1);
  s21_create_matrix(4, 4, &matrix_2);
  ret = s21_sub_matrix(&matrix_1, &matrix_2, &res_my);
  ck_assert_int_eq(ret, 2);
  s21_remove_matrix(&matrix_1);
  s21_remove_matrix(&matrix_2);

  s21_create_matrix(4, 4, &matrix_2);
  ret = s21_sub_matrix(&matrix_1, &matrix_2, &res_my);
  ck_assert_int_eq(ret, 1);
  s21_remove_matrix(&matrix_1);
  s21_remove_matrix(&matrix_2);

  s21_create_matrix(4, 4, &matrix_1);
  s21_create_matrix(4, 4, &matrix_2);
  s21_create_matrix(4, 4, &res_org);
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      matrix_1.matrix[i][j] = i + j;
      res_org.matrix[i][j] = i + j;
    }
  }
  ret = s21_sub_matrix(&matrix_1, &matrix_2, &res_my);
  ck_assert_int_eq(ret, 0);
  ret = s21_eq_matrix(&res_my, &res_org);
  ck_assert_int_eq(ret, 1);
  s21_remove_matrix(&matrix_1);
  s21_remove_matrix(&matrix_2);
  s21_remove_matrix(&res_my);
  s21_remove_matrix(&res_org);

  s21_create_matrix(4, 4, &matrix_1);
  s21_create_matrix(4, 4, &matrix_2);
  s21_create_matrix(4, 4, &res_org);
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      matrix_1.matrix[i][j] = i + j;
      matrix_2.matrix[i][j] = i + j;
    }
  }
  ret = s21_sub_matrix(&matrix_1, &matrix_2, &res_my);
  ck_assert_int_eq(ret, 0);
  ret = s21_eq_matrix(&res_my, &res_org);
  ck_assert_int_eq(ret, 1);
  s21_remove_matrix(&matrix_1);
  s21_remove_matrix(&matrix_2);
  s21_remove_matrix(&res_my);
  s21_remove_matrix(&res_org);
}
END_TEST

START_TEST(test_s21_mult_number) {
  matrix_t matrix_1, res_my, res_org;
  s21_create_matrix(4, 4, &matrix_1);
  s21_create_matrix(4, 4, &res_org);
  int ret = s21_mult_number(&matrix_1, 5, &res_my);
  ck_assert_int_eq(ret, 0);
  ret = s21_eq_matrix(&res_my, &res_org);
  ck_assert_int_eq(ret, 1);
  s21_remove_matrix(&matrix_1);
  s21_remove_matrix(&res_my);
  s21_remove_matrix(&res_org);

  s21_create_matrix(4, 4, &matrix_1);
  s21_create_matrix(4, 4, &res_org);
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      matrix_1.matrix[i][j] = i + j;
      res_org.matrix[i][j] = (i + j) * (-3);
    }
  }
  ret = s21_mult_number(&matrix_1, -3, &res_my);
  ck_assert_int_eq(ret, 0);
  ret = s21_eq_matrix(&res_my, &res_org);
  ck_assert_int_eq(ret, 1);
  s21_remove_matrix(&res_my);
  s21_remove_matrix(&res_org);

  s21_create_matrix(4, 4, &res_org);
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      matrix_1.matrix[i][j] = i + j;
    }
  }
  ret = s21_mult_number(&matrix_1, 0, &res_my);
  ck_assert_int_eq(ret, 0);
  ret = s21_eq_matrix(&res_my, &res_org);
  ck_assert_int_eq(ret, 1);
  s21_remove_matrix(&matrix_1);
  s21_remove_matrix(&res_my);
  s21_remove_matrix(&res_org);
}
END_TEST

START_TEST(test_s21_mult_matrix) {
  matrix_t mat_1, mat_2, res_mat, res_org;

  s21_create_matrix(2, 2, &mat_1);
  s21_create_matrix(2, 2, &mat_2);
  s21_create_matrix(2, 2, &res_org);
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 2; j++) {
      mat_1.matrix[i][j] = i + j + 1;
      mat_2.matrix[i][j] = i + j + 1;
    }
  }
  res_org.matrix[0][0] = 5;
  res_org.matrix[0][1] = 8;
  res_org.matrix[1][0] = 8;
  res_org.matrix[1][1] = 13;
  int ret = s21_mult_matrix(&mat_1, &mat_2, &res_mat);
  ck_assert_int_eq(ret, 0);
  ret = s21_eq_matrix(&res_mat, &res_org);
  ck_assert_int_eq(ret, 1);
  s21_remove_matrix(&mat_1);
  s21_remove_matrix(&mat_2);
  s21_remove_matrix(&res_mat);
  s21_remove_matrix(&res_org);

  s21_create_matrix(3, 2, &mat_1);
  s21_create_matrix(2, 2, &mat_2);
  s21_create_matrix(3, 2, &res_org);
  ret = s21_mult_matrix(&mat_1, &mat_2, &res_mat);
  ck_assert_int_eq(ret, 0);
  ret = s21_eq_matrix(&res_mat, &res_org);
  ck_assert_int_eq(ret, 1);
  s21_remove_matrix(&mat_1);
  s21_remove_matrix(&mat_2);
  s21_remove_matrix(&res_mat);
  s21_remove_matrix(&res_org);

  s21_create_matrix(2, 7, &mat_1);
  s21_create_matrix(2, 2, &mat_2);
  ret = s21_mult_matrix(&mat_1, &mat_2, &res_mat);
  ck_assert_int_eq(ret, 2);
  s21_remove_matrix(&mat_1);
  s21_remove_matrix(&mat_2);
}
END_TEST

START_TEST(test_s21_transpose) {
  matrix_t mat_1, res_mat, res_org;

  s21_create_matrix(2, 2, &mat_1);
  s21_create_matrix(2, 2, &res_org);
  mat_1.matrix[0][0] = 1;
  mat_1.matrix[0][1] = 2;
  mat_1.matrix[1][0] = 3;
  mat_1.matrix[1][1] = 4;
  res_org.matrix[0][0] = 1;
  res_org.matrix[0][1] = 3;
  res_org.matrix[1][0] = 2;
  res_org.matrix[1][1] = 4;
  int ret = s21_transpose(&mat_1, &res_mat);
  ck_assert_int_eq(ret, 0);
  ret = s21_eq_matrix(&res_mat, &res_org);
  ck_assert_int_eq(ret, 1);
  s21_remove_matrix(&mat_1);
  s21_remove_matrix(&res_mat);
  s21_remove_matrix(&res_org);

  double matrix[2][2] = {
      {1, 2},
      {3, 4},
  };
  double res[2][2] = {{1, 3}, {2, 4}};
  s21_create_matrix(2, 2, &mat_1);
  s21_create_matrix(2, 2, &res_org);
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 2; j++) {
      mat_1.matrix[i][j] = matrix[i][j];
    }
  }
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 2; j++) {
      res_org.matrix[i][j] = res[i][j];
    }
  }
  ret = s21_transpose(&mat_1, &res_mat);
  ck_assert_int_eq(ret, 0);
  ret = s21_eq_matrix(&res_mat, &res_org);
  ck_assert_int_eq(ret, 1);
  s21_remove_matrix(&mat_1);
  s21_remove_matrix(&res_mat);
  s21_remove_matrix(&res_org);
}
END_TEST

START_TEST(test_s21_determinant) {
  matrix_t matrix;
  s21_create_matrix(3, 3, &matrix);
  int count = 1;
  for (int i = 0; i < matrix.rows; i++) {
    for (int j = 0; j < matrix.columns; j++) {
      matrix.matrix[i][j] = count++;
    }
  }
  matrix.matrix[2][2] = 10;
  double res;
  int ret = s21_determinant(&matrix, &res);
  ck_assert_uint_eq(res, -3);
  ck_assert_int_eq(ret, 0);
  s21_remove_matrix(&matrix);
}
END_TEST

START_TEST(test_s21_determinant_2) {
  double matrix[3][3] = {{1, 2, 3}, {-6, 0, -2}, {9, 4, 3}};

  matrix_t matrix2;
  s21_create_matrix(3, 3, &matrix2);

  for (int i = 0; i < matrix2.rows; i++) {
    for (int j = 0; j < matrix2.columns; j++) {
      matrix2.matrix[i][j] = matrix[i][j];
      ;
    }
  }

  double res;
  int ret = s21_determinant(&matrix2, &res);
  ck_assert_double_eq_tol(res, -64.0, 1e-6);

  ck_assert_int_eq(ret, 0);
  s21_remove_matrix(&matrix2);
}
END_TEST

START_TEST(test_s21_calc_complements) {
  double m[3][3] = {{1, 2, 3}, {0, 4, 2}, {5, 2, 1}};
  double r[3][3] = {{0, 10, -20}, {4, -14, 8}, {-8, -2, 4}};
  matrix_t matrix, res_org, res_my;
  s21_create_matrix(3, 3, &matrix);
  s21_create_matrix(3, 3, &res_org);
  for (int i = 0; i < matrix.rows; i++) {
    for (int j = 0; j < matrix.columns; j++) {
      matrix.matrix[i][j] = m[i][j];
    }
  }
  for (int i = 0; i < matrix.rows; i++) {
    for (int j = 0; j < matrix.columns; j++) {
      res_org.matrix[i][j] = r[i][j];
    }
  }
  int ret = s21_calc_complements(&matrix, &res_my);
  ck_assert_int_eq(ret, 0);
  ret = s21_eq_matrix(&res_org, &res_my);
  ck_assert_int_eq(ret, 1);
  s21_remove_matrix(&matrix);
  s21_remove_matrix(&res_my);
  s21_remove_matrix(&res_org);
}
END_TEST

START_TEST(test_s21_inverse_matrix) {
  double m[3][3] = {{2, 5, 7}, {6, 3, 4}, {5, -2, -3}};
  double r[3][3] = {{1, -1, 1}, {-38, 41, -34}, {27, -29, 24}};
  matrix_t matrix, res_org, res_my;
  s21_create_matrix(3, 3, &matrix);
  s21_create_matrix(3, 3, &res_org);
  for (int i = 0; i < matrix.rows; i++) {
    for (int j = 0; j < matrix.columns; j++) {
      matrix.matrix[i][j] = m[i][j];
    }
  }

  for (int i = 0; i < matrix.rows; i++) {
    for (int j = 0; j < matrix.columns; j++) {
      res_org.matrix[i][j] = r[i][j];
    }
  }
  // printf("Исходная \n");
  // s21_print_matrix(&matrix);
  // printf("\n");

  int ret = s21_inverse_matrix(&matrix, &res_my);

  ck_assert_int_eq(ret, 0);
  ret = s21_eq_matrix(&res_org, &res_my);
  ck_assert_int_eq(ret, 1);
  s21_remove_matrix(&matrix);
  s21_remove_matrix(&res_my);
  s21_remove_matrix(&res_org);
}
END_TEST

START_TEST(s21_create_matrix_1) {
  // success creation
  matrix_t A = {};
  ck_assert_int_eq(s21_create_matrix(5, 5, &A), OK);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_create_matrix_2) {
  // failure null pointer
  ck_assert_int_eq(s21_create_matrix(5, 5, NULL), MAT_ERROR);
}
END_TEST

START_TEST(s21_create_matrix_3) {
  // failure incorrect rows/columns
  matrix_t A = {};
  ck_assert_int_eq(s21_create_matrix(5, 0, &A), MAT_ERROR);
}
END_TEST

START_TEST(s21_remove_matrix_1) {
  // success remove
  matrix_t A = {};
  s21_create_matrix(5, 5, &A);
  s21_remove_matrix(&A);
  ck_assert_ptr_null(A.matrix);
}
END_TEST

START_TEST(s21_remove_matrix_2) {
  // failure handle null pointer
  s21_remove_matrix(NULL);
  ck_assert_int_eq(1, 1);
}
END_TEST

START_TEST(s21_remove_matrix_3) {
  // failure handle MAT_ERROR structure
  matrix_t A = {};
  s21_remove_matrix(&A);
  ck_assert_int_eq(1, 1);
}
END_TEST

START_TEST(s21_eq_matrix_1) {
  // success with initialized values
  matrix_t A = {};
  matrix_t B = {};
  s21_create_matrix(5, 5, &A);
  s21_create_matrix(5, 5, &B);
  s21_initialize_matrix(&A, 21, 21);
  s21_initialize_matrix(&B, 21, 21);
  ck_assert_int_eq(s21_eq_matrix(&A, &B), SUCCESS);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(s21_eq_matrix_2) {
  // success with uninitialized values
  matrix_t A = {};
  matrix_t B = {};
  s21_create_matrix(5, 5, &A);
  s21_create_matrix(5, 5, &B);
  ck_assert_int_eq(s21_eq_matrix(&A, &B), SUCCESS);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(s21_eq_matrix_3) {
  // success with a difference of less than 1e-7
  matrix_t A = {};
  matrix_t B = {};
  s21_create_matrix(5, 5, &A);
  s21_create_matrix(5, 5, &B);
  s21_initialize_matrix(&A, 1, 0.000000001);
  s21_initialize_matrix(&B, 1, 0.000000002);
  ck_assert_int_eq(s21_eq_matrix(&A, &B), SUCCESS);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(s21_eq_matrix_4) {
  // failure with different dimensions of matrices
  matrix_t A = {};
  matrix_t B = {};
  s21_create_matrix(5, 5, &A);
  s21_create_matrix(3, 4, &B);
  ck_assert_int_eq(s21_eq_matrix(&A, &B), FAILURE);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(s21_eq_matrix_5) {
  // failure with MAT_ERROR
  matrix_t A = {};
  matrix_t B = {};
  s21_create_matrix(5, 5, &A);
  ck_assert_int_eq(s21_eq_matrix(&A, &B), FAILURE);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_eq_matrix_6) {
  // failure with different values
  matrix_t A = {};
  matrix_t B = {};
  s21_create_matrix(5, 5, &A);
  s21_create_matrix(5, 5, &B);
  s21_initialize_matrix(&A, 21, 1);
  s21_initialize_matrix(&B, 42, 1);
  ck_assert_int_eq(s21_eq_matrix(&A, &B), FAILURE);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(s21_sum_matrix_1) {
  // failure error with wrong matrices
  matrix_t A = {};
  matrix_t B = {};
  ck_assert_int_eq(s21_sum_matrix(&A, &B, NULL), MAT_ERROR);
}
END_TEST

START_TEST(s21_sum_matrix_2) {
  // failure with different dimensions of matrices
  matrix_t A = {};
  matrix_t B = {};
  matrix_t result = {};
  s21_create_matrix(4, 4, &A);
  s21_create_matrix(5, 5, &B);
  ck_assert_int_eq(s21_sum_matrix(&A, &B, &result), CALC_ERROR);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(s21_sum_matrix_3) {
  // failure with non-finite value
  matrix_t A = {};
  matrix_t B = {};
  matrix_t result = {};
  s21_create_matrix(5, 5, &A);
  s21_create_matrix(5, 5, &B);
  s21_initialize_matrix(&A, 1, 1);
  s21_initialize_matrix(&B, 1, 1);
  B.matrix[3][3] = INFINITY;
  A.matrix[3][3] = INFINITY;
  ck_assert_int_eq(s21_sum_matrix(&A, &B, &result), 0);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(s21_sum_matrix_4) {
  // sucess with initialized values
  matrix_t A = {};
  matrix_t B = {};
  matrix_t result = {};
  matrix_t eq_matrix = {};
  s21_create_matrix(5, 5, &A);
  s21_create_matrix(5, 5, &B);
  s21_create_matrix(5, 5, &eq_matrix);
  s21_initialize_matrix(&A, 1, 1);
  s21_initialize_matrix(&B, 1, 1);
  s21_initialize_matrix(&eq_matrix, 2, 2);
  ck_assert_int_eq(s21_sum_matrix(&A, &B, &result), OK);
  ck_assert_int_eq(s21_eq_matrix(&result, &eq_matrix), SUCCESS);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result);
  s21_remove_matrix(&eq_matrix);
}
END_TEST

START_TEST(s21_sum_matrix_5) {
  // sucess with uninitialized values
  matrix_t A = {};
  matrix_t B = {};
  matrix_t result = {};
  matrix_t eq_matrix = {};
  s21_create_matrix(5, 5, &A);
  s21_create_matrix(5, 5, &B);
  s21_create_matrix(5, 5, &eq_matrix);
  ck_assert_int_eq(s21_sum_matrix(&A, &B, &result), OK);
  ck_assert_int_eq(s21_eq_matrix(&result, &eq_matrix), SUCCESS);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result);
  s21_remove_matrix(&eq_matrix);
}
END_TEST

START_TEST(s21_sum_matrix_6) {
  // sucess with task refence
  matrix_t A = {};
  matrix_t B = {};
  matrix_t result = {};
  matrix_t eq_matrix = {};
  s21_create_matrix(3, 3, &A);
  s21_create_matrix(3, 3, &B);
  s21_create_matrix(3, 3, &eq_matrix);
  A.matrix[0][0] = 1, A.matrix[0][1] = 2, A.matrix[0][2] = 3;
  A.matrix[1][0] = 0, A.matrix[1][1] = 4, A.matrix[1][2] = 5;
  A.matrix[2][0] = 0, A.matrix[2][1] = 0, A.matrix[2][2] = 6;
  B.matrix[0][0] = 1, B.matrix[0][1] = 0, B.matrix[0][2] = 0;
  B.matrix[1][0] = 2, B.matrix[1][1] = 0, B.matrix[1][2] = 0;
  B.matrix[2][0] = 3, B.matrix[2][1] = 4, B.matrix[2][2] = 1;
  ck_assert_int_eq(s21_sum_matrix(&A, &B, &result), OK);
  eq_matrix.matrix[0][0] = 2, eq_matrix.matrix[0][1] = 2,
  eq_matrix.matrix[0][2] = 3;
  eq_matrix.matrix[1][0] = 2, eq_matrix.matrix[1][1] = 4,
  eq_matrix.matrix[1][2] = 5;
  eq_matrix.matrix[2][0] = 3, eq_matrix.matrix[2][1] = 4,
  eq_matrix.matrix[2][2] = 7;
  ck_assert_int_eq(s21_eq_matrix(&result, &eq_matrix), SUCCESS);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result);
  s21_remove_matrix(&eq_matrix);
}
END_TEST

START_TEST(s21_sub_matrix_1) {
  // failure error with wrong matrices
  matrix_t A = {};
  matrix_t B = {};
  ck_assert_int_eq(s21_sub_matrix(&A, &B, NULL), MAT_ERROR);
}
END_TEST

START_TEST(s21_sub_matrix_2) {
  // failure with different dimensions of matrices
  matrix_t A = {};
  matrix_t B = {};
  matrix_t result = {};
  s21_create_matrix(4, 4, &A);
  s21_create_matrix(5, 5, &B);
  ck_assert_int_eq(s21_sub_matrix(&A, &B, &result), CALC_ERROR);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(s21_sub_matrix_4) {
  // sucess with initialized values
  matrix_t A = {};
  matrix_t B = {};
  matrix_t result = {};
  matrix_t eq_matrix = {};
  s21_create_matrix(5, 5, &A);
  s21_create_matrix(5, 5, &B);
  s21_create_matrix(5, 5, &eq_matrix);
  s21_initialize_matrix(&A, 1, 1);
  s21_initialize_matrix(&B, 1, 1);
  ck_assert_int_eq(s21_sub_matrix(&A, &B, &result), OK);
  ck_assert_int_eq(s21_eq_matrix(&result, &eq_matrix), SUCCESS);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result);
  s21_remove_matrix(&eq_matrix);
}
END_TEST

START_TEST(s21_sub_matrix_5) {
  // sucess with uninitialized values
  matrix_t A = {};
  matrix_t B = {};
  matrix_t result = {};
  matrix_t eq_matrix = {};
  s21_create_matrix(5, 5, &A);
  s21_create_matrix(5, 5, &B);
  s21_create_matrix(5, 5, &eq_matrix);
  ck_assert_int_eq(s21_sub_matrix(&A, &B, &result), OK);
  ck_assert_int_eq(s21_eq_matrix(&result, &eq_matrix), SUCCESS);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result);
  s21_remove_matrix(&eq_matrix);
}
END_TEST

START_TEST(s21_sub_matrix_6) {
  // sucess with task refence
  matrix_t A = {};
  matrix_t B = {};
  matrix_t result = {};
  matrix_t eq_matrix = {};
  s21_create_matrix(3, 3, &A);
  s21_create_matrix(3, 3, &B);
  s21_create_matrix(3, 3, &eq_matrix);
  A.matrix[0][0] = 1, A.matrix[0][1] = 2, A.matrix[0][2] = 3;
  A.matrix[1][0] = 0, A.matrix[1][1] = 4, A.matrix[1][2] = 5;
  A.matrix[2][0] = 0, A.matrix[2][1] = 0, A.matrix[2][2] = 6;
  B.matrix[0][0] = 1, B.matrix[0][1] = 0, B.matrix[0][2] = 0;
  B.matrix[1][0] = 2, B.matrix[1][1] = 0, B.matrix[1][2] = 0;
  B.matrix[2][0] = 3, B.matrix[2][1] = 4, B.matrix[2][2] = 1;
  ck_assert_int_eq(s21_sub_matrix(&A, &B, &result), OK);
  eq_matrix.matrix[0][0] = 0, eq_matrix.matrix[0][1] = 2,
  eq_matrix.matrix[0][2] = 3;
  eq_matrix.matrix[1][0] = -2, eq_matrix.matrix[1][1] = 4,
  eq_matrix.matrix[1][2] = 5;
  eq_matrix.matrix[2][0] = -3, eq_matrix.matrix[2][1] = -4,
  eq_matrix.matrix[2][2] = 5;
  ck_assert_int_eq(s21_eq_matrix(&result, &eq_matrix), SUCCESS);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result);
  s21_remove_matrix(&eq_matrix);
}
END_TEST

START_TEST(s21_mult_number_1) {
  // failure with MAT_ERROR
  matrix_t A = {};
  double number = 3.14;
  s21_create_matrix(3, 3, &A);
  s21_initialize_matrix(&A, 1, 1);
  ck_assert_int_eq(s21_mult_number(&A, number, NULL), MAT_ERROR);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_mult_number_4) {
  // success with uninitialized values
  matrix_t A = {};
  matrix_t result = {};
  matrix_t eq_matrix = {};
  double number = 3;
  s21_create_matrix(3, 3, &A);
  s21_create_matrix(3, 3, &eq_matrix);
  ck_assert_int_eq(s21_mult_number(&A, number, &result), OK);
  ck_assert_int_eq(s21_eq_matrix(&result, &eq_matrix), SUCCESS);
  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
  s21_remove_matrix(&eq_matrix);
}
END_TEST

START_TEST(s21_mult_number_5) {
  // success with initialized values
  matrix_t A = {};
  matrix_t result = {};
  matrix_t eq_matrix = {};
  double number = 3;
  s21_create_matrix(3, 3, &A);
  s21_initialize_matrix(&A, 1, 1);
  s21_create_matrix(3, 3, &eq_matrix);
  s21_initialize_matrix(&eq_matrix, 3, 3);
  ck_assert_int_eq(s21_mult_number(&A, number, &result), OK);
  ck_assert_int_eq(s21_eq_matrix(&result, &eq_matrix), SUCCESS);
  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
  s21_remove_matrix(&eq_matrix);
}
END_TEST

START_TEST(s21_mult_number_6) {
  // success with task reference values
  matrix_t A = {};
  matrix_t result = {};
  matrix_t eq_matrix = {};
  double number = 2;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 1, A.matrix[0][1] = 2, A.matrix[0][2] = 3;
  A.matrix[1][0] = 0, A.matrix[1][1] = 4, A.matrix[1][2] = 2;
  A.matrix[2][0] = 2, A.matrix[2][1] = 3, A.matrix[2][2] = 4;
  s21_create_matrix(3, 3, &eq_matrix);
  eq_matrix.matrix[0][0] = 2, eq_matrix.matrix[0][1] = 4,
  eq_matrix.matrix[0][2] = 6;
  eq_matrix.matrix[1][0] = 0, eq_matrix.matrix[1][1] = 8,
  eq_matrix.matrix[1][2] = 4;
  eq_matrix.matrix[2][0] = 4, eq_matrix.matrix[2][1] = 6,
  eq_matrix.matrix[2][2] = 8;
  ck_assert_int_eq(s21_mult_number(&A, number, &result), OK);
  ck_assert_int_eq(s21_eq_matrix(&result, &eq_matrix), SUCCESS);
  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
  s21_remove_matrix(&eq_matrix);
}
END_TEST

START_TEST(s21_mult_matrix_1) {
  // failure with MAT_ERROR
  matrix_t A = {};
  s21_create_matrix(3, 3, &A);
  s21_initialize_matrix(&A, 1, 1);
  ck_assert_int_eq(s21_mult_matrix(&A, NULL, NULL), MAT_ERROR);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_mult_matrix_3) {
  // failure with different dimensions of matrices
  matrix_t A = {};
  matrix_t B = {};
  matrix_t result = {};
  s21_create_matrix(3, 2, &A);
  s21_create_matrix(3, 2, &B);
  ck_assert_int_eq(s21_mult_matrix(&A, &B, &result), CALC_ERROR);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(s21_mult_matrix_4) {
  // success with uninitialized values
  matrix_t A = {};
  matrix_t B = {};
  matrix_t result = {};
  matrix_t eq_matrix = {};
  s21_create_matrix(3, 3, &A);
  s21_create_matrix(3, 3, &B);
  s21_create_matrix(3, 3, &eq_matrix);
  ck_assert_int_eq(s21_mult_matrix(&A, &B, &result), OK);
  ck_assert_int_eq(s21_eq_matrix(&result, &eq_matrix), SUCCESS);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result);
  s21_remove_matrix(&eq_matrix);
}
END_TEST

START_TEST(s21_mult_matrix_5) {
  // success with initialized values
  matrix_t A = {};
  matrix_t B = {};
  matrix_t result = {};
  matrix_t eq_matrix = {};
  s21_create_matrix(3, 3, &A);
  s21_initialize_matrix(&A, 1, 1);
  s21_create_matrix(3, 3, &B);
  s21_initialize_matrix(&B, 1, 1);
  s21_create_matrix(3, 3, &eq_matrix);
  eq_matrix.matrix[0][0] = 30, eq_matrix.matrix[0][1] = 36,
  eq_matrix.matrix[0][2] = 42;
  eq_matrix.matrix[1][0] = 66, eq_matrix.matrix[1][1] = 81,
  eq_matrix.matrix[1][2] = 96;
  eq_matrix.matrix[2][0] = 102, eq_matrix.matrix[2][1] = 126,
  eq_matrix.matrix[2][2] = 150;
  ck_assert_int_eq(s21_mult_matrix(&A, &B, &result), OK);
  ck_assert_int_eq(s21_eq_matrix(&result, &eq_matrix), SUCCESS);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result);
  s21_remove_matrix(&eq_matrix);
}
END_TEST

START_TEST(s21_mult_matrix_6) {
  // success with task reference values
  matrix_t A = {};
  matrix_t B = {};
  matrix_t result = {};
  matrix_t eq_matrix = {};
  s21_create_matrix(3, 2, &A);
  A.matrix[0][0] = 1, A.matrix[0][1] = 4;
  A.matrix[1][0] = 2, A.matrix[1][1] = 5;
  A.matrix[2][0] = 3, A.matrix[2][1] = 6;
  s21_create_matrix(2, 3, &B);
  B.matrix[0][0] = 1, B.matrix[0][1] = -1, B.matrix[0][2] = 1;
  B.matrix[1][0] = 2, B.matrix[1][1] = 3, B.matrix[1][2] = 4;
  s21_create_matrix(3, 3, &eq_matrix);
  eq_matrix.matrix[0][0] = 9, eq_matrix.matrix[0][1] = 11,
  eq_matrix.matrix[0][2] = 17;
  eq_matrix.matrix[1][0] = 12, eq_matrix.matrix[1][1] = 13,
  eq_matrix.matrix[1][2] = 22;
  eq_matrix.matrix[2][0] = 15, eq_matrix.matrix[2][1] = 15,
  eq_matrix.matrix[2][2] = 27;
  ck_assert_int_eq(s21_mult_matrix(&A, &B, &result), OK);
  ck_assert_int_eq(s21_eq_matrix(&result, &eq_matrix), SUCCESS);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result);
  s21_remove_matrix(&eq_matrix);
}
END_TEST

START_TEST(s21_transpose_1) {
  // failure with MAT_ERROR
  matrix_t A = {};
  matrix_t result = {};
  ck_assert_int_eq(s21_transpose(&A, &result), MAT_ERROR);
}
END_TEST

START_TEST(s21_transpose_2) {
  // success with unininitialized matrix 3x2
  matrix_t A = {};
  matrix_t result = {};
  s21_create_matrix(3, 2, &A);
  ck_assert_int_eq(s21_transpose(&A, &result), OK);
  ck_assert_int_eq(result.rows, 2);
  ck_assert_int_eq(result.columns, 3);
  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(s21_transpose_3) {
  // success with unininitialized matrix 2x3
  matrix_t A = {};
  matrix_t result = {};
  s21_create_matrix(2, 3, &A);
  ck_assert_int_eq(s21_transpose(&A, &result), OK);
  ck_assert_int_eq(result.rows, 3);
  ck_assert_int_eq(result.columns, 2);
  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(s21_transpose_4) {
  // success with initialized matrix 2x3
  matrix_t A = {};
  matrix_t result = {};
  matrix_t eq_matrix = {};
  s21_create_matrix(2, 3, &A);
  s21_create_matrix(3, 2, &eq_matrix);
  s21_initialize_matrix(&A, 1, 1);
  ck_assert_int_eq(s21_transpose(&A, &result), OK);
  eq_matrix.matrix[0][0] = 1, eq_matrix.matrix[0][1] = 4;
  eq_matrix.matrix[1][0] = 2, eq_matrix.matrix[1][1] = 5;
  eq_matrix.matrix[2][0] = 3, eq_matrix.matrix[2][1] = 6;
  ck_assert_int_eq(s21_eq_matrix(&result, &eq_matrix), SUCCESS);
  ck_assert_int_eq(result.rows, 3);
  ck_assert_int_eq(result.columns, 2);
  s21_remove_matrix(&A);
  s21_remove_matrix(&eq_matrix);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(s21_transpose_5) {
  // success with task reference values and 3x2 matrix
  matrix_t A = {};
  matrix_t result = {};
  matrix_t eq_matrix = {};
  s21_create_matrix(3, 2, &A);
  s21_create_matrix(2, 3, &eq_matrix);
  A.matrix[0][0] = 1, A.matrix[0][1] = 4;
  A.matrix[1][0] = 2, A.matrix[1][1] = 5;
  A.matrix[2][0] = 3, A.matrix[2][1] = 6;
  ck_assert_int_eq(s21_transpose(&A, &result), OK);
  eq_matrix.matrix[0][0] = 1, eq_matrix.matrix[0][1] = 2,
  eq_matrix.matrix[0][2] = 3;
  eq_matrix.matrix[1][0] = 4, eq_matrix.matrix[1][1] = 5,
  eq_matrix.matrix[1][2] = 6;
  ck_assert_int_eq(s21_eq_matrix(&result, &eq_matrix), SUCCESS);
  ck_assert_int_eq(result.rows, 2);
  ck_assert_int_eq(result.columns, 3);
  s21_remove_matrix(&A);
  s21_remove_matrix(&eq_matrix);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(s21_calc_complements_1) {
  // failure with MAT_ERROR
  matrix_t A = {};
  s21_create_matrix(3, 3, &A);
  ck_assert_int_eq(s21_calc_complements(&A, NULL), MAT_ERROR);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_calc_complements_2) {
  // failure with vector matrix (rows or cols == 1)
  matrix_t A = {};
  matrix_t result = {};
  s21_create_matrix(1, 3, &A);
  s21_initialize_matrix(&A, 1, 3);
  ck_assert_int_eq(s21_calc_complements(&A, &result), CALC_ERROR);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_calc_complements_3) {
  // success with task reference values
  matrix_t A = {};
  matrix_t result = {};
  matrix_t eq_matrix = {};
  s21_create_matrix(3, 3, &A);
  s21_create_matrix(3, 3, &eq_matrix);
  A.matrix[0][0] = 1, A.matrix[0][1] = 2, A.matrix[0][2] = 3;
  A.matrix[1][0] = 0, A.matrix[1][1] = 4, A.matrix[1][2] = 2;
  A.matrix[2][0] = 5, A.matrix[2][1] = 2, A.matrix[2][2] = 1;
  ck_assert_int_eq(s21_calc_complements(&A, &result), OK);
  eq_matrix.matrix[0][0] = 0, eq_matrix.matrix[0][1] = 10,
  eq_matrix.matrix[0][2] = -20;
  eq_matrix.matrix[1][0] = 4, eq_matrix.matrix[1][1] = -14,
  eq_matrix.matrix[1][2] = 8;
  eq_matrix.matrix[2][0] = -8, eq_matrix.matrix[2][1] = -2,
  eq_matrix.matrix[2][2] = 4;
  ck_assert_int_eq(s21_eq_matrix(&result, &eq_matrix), SUCCESS);
  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
  s21_remove_matrix(&eq_matrix);
}
END_TEST

START_TEST(s21_determinant_1) {
  // failure with MAT_ERROR
  matrix_t A = {};
  double det = 0;
  ck_assert_int_eq(s21_determinant(&A, &det), MAT_ERROR);
}
END_TEST

START_TEST(s21_determinant_2) {
  // failure with non-square matrix
  matrix_t A = {};
  double det = 0;
  s21_create_matrix(3, 2, &A);
  s21_initialize_matrix(&A, 1, 1);
  ck_assert_int_eq(s21_determinant(&A, &det), CALC_ERROR);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_3) {
  // success with task reference values
  matrix_t A = {};
  double det = 0;
  s21_create_matrix(3, 3, &A);
  s21_initialize_matrix(&A, 1, 1);
  ck_assert_int_eq(s21_determinant(&A, &det), OK);
  ck_assert_double_eq(det, 0);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_4) {
  // success with 2x2 matrix
  matrix_t A = {};
  double det = 0;
  s21_create_matrix(2, 2, &A);
  s21_initialize_matrix(&A, 3, 3);
  ck_assert_int_eq(s21_determinant(&A, &det), OK);
  ck_assert_double_eq(det, -18);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_5) {
  // success with 1x1 matrix
  matrix_t A = {};
  double det = 0;
  s21_create_matrix(1, 1, &A);
  A.matrix[0][0] = 21;
  ck_assert_int_eq(s21_determinant(&A, &det), OK);
  ck_assert_double_eq(det, 21);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_6) {
  double matrix[3][3] = {{1, 2, 3}, {-6, 0, -2}, {9, 4, 3}};

  matrix_t matrix2;
  s21_create_matrix(3, 3, &matrix2);

  for (int i = 0; i < matrix2.rows; i++) {
    for (int j = 0; j < matrix2.columns; j++) {
      matrix2.matrix[i][j] = matrix[i][j];
      ;
    }
  }

  double res;
  int ret = s21_determinant(&matrix2, &res);

  ck_assert_double_eq_tol(res, -64.0, 1e-6);
  ck_assert_int_eq(ret, 0);
  s21_remove_matrix(&matrix2);
}
END_TEST

START_TEST(s21_inverse_matrix_1) {
  // failure with MAT_ERROR
  matrix_t A = {};
  matrix_t result = {};
  ck_assert_int_eq(s21_inverse_matrix(&A, &result), MAT_ERROR);
}
END_TEST

START_TEST(s21_inverse_matrix_2) {
  // failure when matrix has determinant equal to zero
  matrix_t A = {};
  matrix_t result = {};
  s21_create_matrix(3, 3, &A);
  s21_initialize_matrix(&A, 1, 1);
  ck_assert_int_eq(s21_inverse_matrix(&A, &result), CALC_ERROR);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_inverse_matrix_3) {
  // failure with non-square matrix
  matrix_t A = {};
  matrix_t result = {};
  s21_create_matrix(5, 3, &A);
  s21_initialize_matrix(&A, 1, 1);
  ck_assert_int_eq(s21_inverse_matrix(&A, &result), CALC_ERROR);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_inverse_matrix_4) {
  // success matrix 1x1
  matrix_t A = {};
  matrix_t result = {};
  matrix_t eq_matrix = {};
  s21_create_matrix(1, 1, &A);
  s21_create_matrix(1, 1, &eq_matrix);
  A.matrix[0][0] = 21;
  eq_matrix.matrix[0][0] = 1.0 / 21.0;
  ck_assert_int_eq(s21_inverse_matrix(&A, &result), OK);
  ck_assert_int_eq(s21_eq_matrix(&result, &eq_matrix), SUCCESS);
  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
  s21_remove_matrix(&eq_matrix);
}
END_TEST

START_TEST(s21_inverse_matrix_5) {
  // success with task reference values
  matrix_t A = {};
  matrix_t result = {};
  matrix_t eq_matrix = {};
  s21_create_matrix(3, 3, &A);
  s21_create_matrix(3, 3, &eq_matrix);
  A.matrix[0][0] = 2, A.matrix[0][1] = 5, A.matrix[0][2] = 7;
  A.matrix[1][0] = 6, A.matrix[1][1] = 3, A.matrix[1][2] = 4;
  A.matrix[2][0] = 5, A.matrix[2][1] = -2, A.matrix[2][2] = -3;
  eq_matrix.matrix[0][0] = 1, eq_matrix.matrix[0][1] = -1,
  eq_matrix.matrix[0][2] = 1;
  eq_matrix.matrix[1][0] = -38, eq_matrix.matrix[1][1] = 41,
  eq_matrix.matrix[1][2] = -34;
  eq_matrix.matrix[2][0] = 27, eq_matrix.matrix[2][1] = -29,
  eq_matrix.matrix[2][2] = 24;
  ck_assert_int_eq(s21_inverse_matrix(&A, &result), OK);
  ck_assert_int_eq(s21_eq_matrix(&result, &eq_matrix), SUCCESS);
  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
  s21_remove_matrix(&eq_matrix);
}
END_TEST

Suite *s21_matrix_suite() {
  Suite *s = suite_create("s21_matrix_test");

  TCase *tc_s21_create_matrix = tcase_create("test_s21_create_matrix");
  tcase_add_test(tc_s21_create_matrix, test_s21_create_matrix);
  tcase_add_test(tc_s21_create_matrix, s21_create_matrix_1);
  tcase_add_test(tc_s21_create_matrix, s21_create_matrix_2);
  tcase_add_test(tc_s21_create_matrix, s21_create_matrix_3);
  suite_add_tcase(s, tc_s21_create_matrix);

  TCase *core_of_remove_matrix = tcase_create("core_of_remove_matrix");
  suite_add_tcase(s, core_of_remove_matrix);
  tcase_add_test(core_of_remove_matrix, s21_remove_matrix_1);
  tcase_add_test(core_of_remove_matrix, s21_remove_matrix_2);
  tcase_add_test(core_of_remove_matrix, s21_remove_matrix_3);

  TCase *tc_s21_eq_matrix = tcase_create("test_s21_eq_matrix");
  suite_add_tcase(s, tc_s21_eq_matrix);
  tcase_add_test(tc_s21_eq_matrix, test_s21_eq_matrix);
  tcase_add_test(tc_s21_eq_matrix, s21_eq_matrix_1);
  tcase_add_test(tc_s21_eq_matrix, s21_eq_matrix_2);
  tcase_add_test(tc_s21_eq_matrix, s21_eq_matrix_3);
  tcase_add_test(tc_s21_eq_matrix, s21_eq_matrix_4);
  tcase_add_test(tc_s21_eq_matrix, s21_eq_matrix_5);
  tcase_add_test(tc_s21_eq_matrix, s21_eq_matrix_6);

  TCase *tc_s21_sum_matrix = tcase_create("test_s21_sum_matrix");
  suite_add_tcase(s, tc_s21_sum_matrix);
  tcase_add_test(tc_s21_sum_matrix, test_s21_sum_matrix);
  tcase_add_test(tc_s21_sum_matrix, s21_sum_matrix_1);
  tcase_add_test(tc_s21_sum_matrix, s21_sum_matrix_2);
  tcase_add_test(tc_s21_sum_matrix, s21_sum_matrix_3);
  tcase_add_test(tc_s21_sum_matrix, s21_sum_matrix_4);
  tcase_add_test(tc_s21_sum_matrix, s21_sum_matrix_5);
  tcase_add_test(tc_s21_sum_matrix, s21_sum_matrix_6);

  TCase *tc_s21_sub_matrix = tcase_create("test_s21_sub_matrix");
  suite_add_tcase(s, tc_s21_sub_matrix);
  tcase_add_test(tc_s21_sub_matrix, test_s21_sub_matrix);
  tcase_add_test(tc_s21_sub_matrix, s21_sub_matrix_1);
  tcase_add_test(tc_s21_sub_matrix, s21_sub_matrix_2);
  tcase_add_test(tc_s21_sub_matrix, s21_sub_matrix_4);
  tcase_add_test(tc_s21_sub_matrix, s21_sub_matrix_5);
  tcase_add_test(tc_s21_sub_matrix, s21_sub_matrix_6);

  TCase *tc_s21_mult_number = tcase_create("test_s21_mult_number");
  suite_add_tcase(s, tc_s21_mult_number);
  tcase_add_test(tc_s21_mult_number, test_s21_mult_number);
  tcase_add_test(tc_s21_mult_number, s21_mult_number_1);
  tcase_add_test(tc_s21_mult_number, s21_mult_number_4);
  tcase_add_test(tc_s21_mult_number, s21_mult_number_5);
  tcase_add_test(tc_s21_mult_number, s21_mult_number_6);

  TCase *tc_s21_mult_matrix = tcase_create("test_s21_mult_matrix");
  suite_add_tcase(s, tc_s21_mult_matrix);
  tcase_add_test(tc_s21_mult_matrix, test_s21_mult_matrix);
  tcase_add_test(tc_s21_mult_matrix, s21_mult_matrix_1);
  tcase_add_test(tc_s21_mult_matrix, s21_mult_matrix_3);
  tcase_add_test(tc_s21_mult_matrix, s21_mult_matrix_4);
  tcase_add_test(tc_s21_mult_matrix, s21_mult_matrix_5);
  tcase_add_test(tc_s21_mult_matrix, s21_mult_matrix_6);

  TCase *tc_s21_transpose = tcase_create("test_s21_transpose");
  suite_add_tcase(s, tc_s21_transpose);
  tcase_add_test(tc_s21_transpose, test_s21_transpose);
  tcase_add_test(tc_s21_transpose, s21_transpose_1);
  tcase_add_test(tc_s21_transpose, s21_transpose_2);
  tcase_add_test(tc_s21_transpose, s21_transpose_3);
  tcase_add_test(tc_s21_transpose, s21_transpose_4);
  tcase_add_test(tc_s21_transpose, s21_transpose_5);

  TCase *tc_s21_determinant = tcase_create("test_s21_determinant");
  suite_add_tcase(s, tc_s21_determinant);
  tcase_add_test(tc_s21_determinant, test_s21_determinant);
  tcase_add_test(tc_s21_determinant, test_s21_determinant_2);
  tcase_add_test(tc_s21_determinant, s21_determinant_1);
  tcase_add_test(tc_s21_determinant, s21_determinant_2);
  tcase_add_test(tc_s21_determinant, s21_determinant_3);
  tcase_add_test(tc_s21_determinant, s21_determinant_4);
  tcase_add_test(tc_s21_determinant, s21_determinant_5);
  tcase_add_test(tc_s21_determinant, s21_determinant_6);

  TCase *tc_s21_calc_complements = tcase_create("test_s21_calc_complements");
  suite_add_tcase(s, tc_s21_calc_complements);
  tcase_add_test(tc_s21_calc_complements, test_s21_calc_complements);
  tcase_add_test(tc_s21_calc_complements, s21_calc_complements_1);
  tcase_add_test(tc_s21_calc_complements, s21_calc_complements_2);
  tcase_add_test(tc_s21_calc_complements, s21_calc_complements_3);

  TCase *tc_s21_inverse_matrix = tcase_create("test_s21_inverse_matrix");
  suite_add_tcase(s, tc_s21_inverse_matrix);
  tcase_add_test(tc_s21_inverse_matrix, test_s21_inverse_matrix);
  tcase_add_test(tc_s21_inverse_matrix, s21_inverse_matrix_1);
  tcase_add_test(tc_s21_inverse_matrix, s21_inverse_matrix_2);
  tcase_add_test(tc_s21_inverse_matrix, s21_inverse_matrix_3);
  tcase_add_test(tc_s21_inverse_matrix, s21_inverse_matrix_4);
  tcase_add_test(tc_s21_inverse_matrix, s21_inverse_matrix_5);

  return s;
}

int main(void) {
  int failed = 0;

  SRunner *sr = srunner_create(s21_matrix_suite());
  srunner_set_fork_status(sr, CK_NOFORK);
  srunner_run_all(sr, CK_NORMAL);

  failed += srunner_ntests_failed(sr);
  srunner_free(sr);
  printf("========= FAILED: %d =========\n", failed);

  return failed == 0 ? 0 : 1;
}
