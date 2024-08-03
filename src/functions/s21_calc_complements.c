#include "../s21_matrix.h"

int s21_calc_complements(matrix_t *A, matrix_t *result) {
  if (A == NULL || A->matrix == NULL || result == NULL) {
    return INCORRECT_MATRIX;
  }
  if (A->rows == 1 || A->columns == 1) {
    return CALCULATION_ERROR;
  }
  if (s21_create_matrix(A->rows, A->columns, result)) {
    return INCORRECT_MATRIX;
  }

  int flag = OK;
  matrix_t temp = {0};
  flag = s21_create_matrix(A->rows - 1, A->columns - 1, &temp);
  if (flag == OK) {
    for (int i = 0; i < A->rows; i++) {
      for (int j = 0; j < A->columns; j++) {
        s21_copy_minor(A, &temp, i, j);
        double determinant = 0;
        flag = s21_determinant(&temp, &determinant);
        result->matrix[i][j] = determinant * pow(-1, i + j);
      }
    }
  }

  s21_remove_matrix(&temp);
  return flag;
}