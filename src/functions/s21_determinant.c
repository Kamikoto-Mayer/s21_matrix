#include "../s21_matrix.h"

int s21_determinant(matrix_t *A, double *result) {
  if (A == NULL || A->matrix == NULL || result == NULL) {
    return INCORRECT_MATRIX;
  } else if (!s21_is_square_matrix(A)) {
    return CALCULATION_ERROR;
  }

  int flag = OK;
  if (A->rows == 1) {
    *result = A->matrix[0][0];
  }
  if (A->rows == 2) {
    *result =
        A->matrix[0][0] * A->matrix[1][1] - A->matrix[1][0] * A->matrix[0][1];
  }
  if (A->rows > 2) {
    *result = 0;
    flag = OK;
    double temp_det = 0;
    double temp_res = 0;
    for (int i = 0; i < A->columns; i++) {
      matrix_t *minor = s21_create_minor(0, i, A);
      if (minor == NULL) {
        flag = INCORRECT_MATRIX;
      } else {
        flag = s21_determinant(minor, &temp_det);
        if (!flag) {
          temp_res = pow(-1, i) * A->matrix[0][i] * temp_det;
          *result += temp_res;
        }
        s21_remove_matrix(minor);
        free(minor);
        minor = NULL;
      }
    }
  }

  return flag;
}