#include "../s21_matrix.h"

int s21_mult_number(matrix_t *A, double number, matrix_t *result) {
  if (A == NULL || A->matrix == NULL || result == NULL) {
    return INCORRECT_MATRIX;
  } else if (!isfinite(number)) {
    return CALCULATION_ERROR;
  }

  int flag = OK;
  flag = s21_create_matrix(A->rows, A->columns, result);
  if (flag == OK) {
    for (int i = 0; i < A->rows; i++) {
      for (int j = 0; j < A->columns; j++) {
        result->matrix[i][j] = A->matrix[i][j] * number;
        if (!isfinite(result->matrix[i][j])) {
          flag = CALCULATION_ERROR;
        }
      }
    }
  }
  return flag;
}