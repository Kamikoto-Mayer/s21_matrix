#include <math.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct matrix_struct {
  double **matrix;
  int rows;
  int columns;
} matrix_t;

#define OK 0
#define INCORRECT_MATRIX 1
#define CALCULATION_ERROR 2

#define SUCCESS 1
#define FAILURE 0

int s21_create_matrix(int rows, int columns, matrix_t *result);
void s21_remove_matrix(matrix_t *A);
int s21_eq_matrix(matrix_t *A, matrix_t *B);
int s21_sum_matrix(matrix_t *A, matrix_t *B, matrix_t *result);
int s21_sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result);
int s21_mult_number(matrix_t *A, double number, matrix_t *result);
int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result);
int s21_transpose(matrix_t *A, matrix_t *result);
int s21_calc_complements(matrix_t *A, matrix_t *result);
int s21_determinant(matrix_t *A, double *result);
int s21_inverse_matrix(matrix_t *A, matrix_t *result);

// helper functions
void s21_initialize_matrix(matrix_t *A, double start_value,
                           double iteration_step);
void s21_scale_row(int row, int cur_row, double scale, matrix_t *result);
void s21_copy_minor(matrix_t *input, matrix_t *result, int except_row,
                    int except_column);
int s21_is_square_matrix(matrix_t *A);
matrix_t *s21_create_minor(int excluded_row, int excluded_column, matrix_t *A);
