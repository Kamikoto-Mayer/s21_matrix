#include "../s21_matrix.h"

int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  if (A == NULL || B == NULL || A->matrix == NULL || B->matrix == NULL ||
      result == NULL) {
    return INCORRECT_MATRIX;
  }

  if (A->columns != B->rows) {
    return CALCULATION_ERROR;
  }

  int flag = OK;
  flag = s21_create_matrix(A->rows, B->columns, result);
  if (flag == OK) {
    for (int i = 0; i < A->rows; i++) {
      for (int j = 0; j < B->columns; j++) {
        double res = 0.0f;
        for (int k = 0; k < A->columns; k++) {
          res += A->matrix[i][k] * B->matrix[k][j];
        }
        result->matrix[i][j] = res;
        if (!isfinite(result->matrix[i][j])) {
          flag = CALCULATION_ERROR;
        }
      }
    }
  }
  return flag;
}