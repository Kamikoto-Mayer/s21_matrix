#include "../s21_matrix.h"

int s21_sum_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  if (A == NULL || B == NULL || A->matrix == NULL || B->matrix == NULL ||
      result == NULL) {
    return INCORRECT_MATRIX;
  } else if (A->rows != B->rows || A->columns != B->columns) {
    return CALCULATION_ERROR;
  }

  int flag = OK;
  flag = s21_create_matrix(A->rows, A->columns, result);
  if (flag == OK) {
    for (int i = 0; i < A->rows; i++) {
      for (int j = 0; j < A->columns; j++) {
        result->matrix[i][j] = A->matrix[i][j] + B->matrix[i][j];
        if (!isfinite(result->matrix[i][j])) {
          flag = CALCULATION_ERROR;
        }
      }
    }
  }
  return flag;
}