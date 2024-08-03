#include "../s21_matrix.h"

int s21_inverse_matrix(matrix_t *A, matrix_t *result) {
  if (A == NULL || A->matrix == NULL || result == NULL) {
    return INCORRECT_MATRIX;
  }

  int flag = OK;
  double determinant = 0;
  flag = s21_determinant(A, &determinant);
  if (flag == OK && determinant != 0 && s21_is_square_matrix(A)) {
    if (A->rows == 1) {
      flag = s21_create_matrix(A->rows, A->columns, result);
      if (flag == OK) {
        result->matrix[0][0] = 1 / A->matrix[0][0];
      }
    } else {
      matrix_t temp_alg = {0};
      matrix_t temp_transp = {0};
      flag = s21_calc_complements(A, &temp_alg);
      if (flag == OK) {
        flag = s21_transpose(&temp_alg, &temp_transp);
      }
      if (flag == OK) {
        flag = s21_mult_number(&temp_transp, 1 / determinant, result);
      }
      s21_remove_matrix(&temp_alg);
      s21_remove_matrix(&temp_transp);
    }
  } else {
    flag = CALCULATION_ERROR;
  }

  return flag;
}