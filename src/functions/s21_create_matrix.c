#include "../s21_matrix.h"

int s21_create_matrix(int rows, int columns, matrix_t *result) {
  if (rows <= 0 || columns <= 0 || result == NULL) {
    return INCORRECT_MATRIX;
  } else {
    result->rows = rows;
    result->columns = columns;
    result->matrix = (double **)malloc(sizeof(double *) * rows);
    if (result->matrix == NULL) {
      return INCORRECT_MATRIX;
    }
    for (int i = 0; i < rows; i++) {
      result->matrix[i] = (double *)calloc(columns, sizeof(double));
      if (result->matrix[i] == NULL) {
        return INCORRECT_MATRIX;
      }
    }
  }
  result->rows = rows;
  result->columns = columns;
  return OK;
}