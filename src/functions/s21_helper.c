#include "../s21_matrix.h"

void s21_initialize_matrix(matrix_t *A, double start_value,
                           double iteration_step) {
  if (A != NULL && A->matrix != NULL) {
    double value = start_value;
    for (int i = 0; i < A->rows; i++) {
      for (int j = 0; j < A->columns; j++) {
        A->matrix[i][j] = value;
        value += iteration_step;
      }
    }
  }
}

void s21_scale_row(int row, int cur_row, double scale, matrix_t *result) {
  for (int i = 0; i < result->columns; i++) {
    result->matrix[row][i] =
        result->matrix[row][i] + result->matrix[cur_row][i] * scale;
  }
}

void s21_copy_minor(matrix_t *input, matrix_t *result, int except_row,
                    int except_column) {
  for (int i = 0, result_row = 0; i < input->rows; i++) {
    if (i != except_row) {
      for (int j = 0, result_column = 0; j < input->columns; j++) {
        if (j != except_column) {
          result->matrix[result_row][result_column] = input->matrix[i][j];
          result_column++;
        }
      }
      result_row++;
    }
  }
}

matrix_t *s21_create_minor(int excluded_row, int excluded_column, matrix_t *A) {
  if (A == NULL || A->matrix == NULL) {
    return NULL;
  }

  matrix_t *minor = calloc(1, sizeof(matrix_t));
  if (minor != NULL) {
    if (s21_create_matrix(A->rows - 1, A->columns - 1, minor) == OK) {
      for (int i = 0, minor_row = 0; i < A->rows; i++) {
        if (i != excluded_row) {
          for (int j = 0, minor_column = 0; j < A->columns; j++) {
            if (j != excluded_column) {
              minor->matrix[minor_row][minor_column] = A->matrix[i][j];
              minor_column++;
            }
          }
          minor_row++;
        }
      }
    }
  }

  return minor;
}

int s21_is_square_matrix(matrix_t *A) {
  if (A == NULL || A->matrix == NULL) {
    return 0;
  }
  return A->rows == A->columns ? 1 : 0;
}