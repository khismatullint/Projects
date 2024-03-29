#ifndef __S21_MATRIX__
#define __S21_MATRIX__

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#define OK 0
#define INCORRECT_MATRIX 1
#define CALCULATION_ERROR 2
#define SUCCESS 1
#define FAILURE 0
#define EPS 1e-7

typedef struct matrix_struct {
  double **matrix;
  int rows;
  int columns;
} matrix_t;

// Вспомогательые функции
int s21_is_correct_matrix(matrix_t val);
int s21_check_for_arithmetic(matrix_t val1, matrix_t val2);
void s21_minor_create(int row, int column, matrix_t val1, matrix_t *val2);

// Основные функции
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
#endif