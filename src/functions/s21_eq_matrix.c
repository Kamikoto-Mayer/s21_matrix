#include "../s21_matrix.h"

int s21_eq_matrix(matrix_t *A, matrix_t *B) {
  if (A == NULL || B == NULL || A->matrix == NULL || B->matrix == NULL) {
    return FAILURE;
  }

  int flag = SUCCESS;
  if (A->rows != B->rows || A->columns != B->columns) {
    flag = FAILURE;
  }

  if (flag == SUCCESS) {
    for (int i = 0; i < A->rows; i++) {
      for (int j = 0; j < A->columns; j++) {
        if (A->rows == B->rows && A->columns == B->columns) {
          if (A->matrix[i][j] == B->matrix[i][j]) {
            flag = SUCCESS;
          } else if ((fabs(A->matrix[i][j] - B->matrix[i][j])) >= 1e-7) {
            flag = FAILURE;
          }
        } else {
          flag = FAILURE;
        }
      }
    }
  }

  return flag;
}