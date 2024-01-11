#include "s21_matrix.h"
int s21_is_correct_matrix(matrix_t val) {
  int res = 1;
  if (val.columns <= 0 || val.rows <= 0 || !val.matrix) {
    res = 0;
  }
  return res;
}
int s21_check_for_arithmetic(matrix_t val1, matrix_t val2) {
  int err = 0;
  if (!s21_is_correct_matrix(val1) || !s21_is_correct_matrix(val2)) {
    err = 1;
  } else if (val1.columns != val2.columns || val1.rows != val2.rows) {
    err = 2;
  }
  return err;
}
int s21_create_matrix(int rows, int columns, matrix_t *result) {
  int err = 0;
  if (rows > 0 && columns > 0 && result) {
    result->matrix = (double **)calloc(rows, sizeof(double *));
    for (int i = 0; i < rows; i++) {
      result->matrix[i] = (double *)calloc(columns, sizeof(double));
    }
    result->columns = columns;
    result->rows = rows;

  } else {
    err = 1;
  }
  return err;
}
void s21_remove_matrix(matrix_t *A) {
  if (A != NULL) {
    if (A->matrix != NULL) {
      for (int i = 0; i < A->rows; i++) {
        free(A->matrix[i]);
      }
      free(A->matrix);
      A->matrix = NULL;
      A->columns = 0;
      A->rows = 0;
    }
  }
}

int s21_eq_matrix(matrix_t *A, matrix_t *B) {
  int res = 1;
  if (A == NULL || B == NULL || A->columns != B->columns ||
      A->rows != B->rows || !s21_is_correct_matrix(*A) ||
      !s21_is_correct_matrix(*B)) {
    res = 0;
  } else {
    for (int i = 0; i < A->rows; i++) {
      for (int j = 0; j < A->columns; j++) {
        if (fabs(A->matrix[i][j] - B->matrix[i][j]) > EPS) {
          res = 0;
          break;
        }
      }
      if (!res) {
        break;
      }
    }
  }

  return res;
}

int s21_sum_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int err = s21_check_for_arithmetic(*A, *B);
  if (!err) {
    s21_create_matrix(A->rows, A->columns, result);
    for (int i = 0; i < A->rows; i++) {
      for (int j = 0; j < A->columns; j++) {
        result->matrix[i][j] = A->matrix[i][j] + B->matrix[i][j];
      }
    }
  }
  return err;
}

int s21_sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int err = s21_check_for_arithmetic(*A, *B);
  if (A == NULL || B == NULL) {
    err = 1;
  } else if (!err) {
    s21_create_matrix(A->rows, A->columns, result);
    for (int i = 0; i < A->rows; i++) {
      for (int j = 0; j < A->columns; j++) {
        result->matrix[i][j] = A->matrix[i][j] - B->matrix[i][j];
      }
    }
  }
  return err;
}

int s21_mult_number(matrix_t *A, double number, matrix_t *result) {
  int err = 0;
  if (A == NULL || !s21_is_correct_matrix(*A)) {
    err = 1;
  } else {
    s21_create_matrix(A->rows, A->columns, result);
    for (int i = 0; i < A->rows; i++) {
      for (int j = 0; j < A->columns; j++) {
        result->matrix[i][j] = A->matrix[i][j] * number;
      }
    }
  }
  return err;
}

int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int err = 0;
  if (A == NULL || B == NULL || !s21_is_correct_matrix(*A) ||
      !s21_is_correct_matrix(*B)) {
    err = 1;
  } else if (A->columns != B->rows) {
    err = 2;
  } else {
    s21_create_matrix(A->rows, B->columns, result);
    for (int i = 0; i < A->rows; i++) {
      for (int j = 0; j < B->columns; j++) {
        for (int q = 0; q < A->columns; q++) {
          result->matrix[i][j] += (A->matrix[i][q]) * (B->matrix[q][j]);
        }
      }
    }
  }
  return err;
}
int s21_transpose(matrix_t *A, matrix_t *result) {
  int err = !s21_is_correct_matrix(*A);
  if (A == NULL) {
    err = 1;
  } else if (!err) {
    s21_create_matrix(A->columns, A->rows, result);
    for (int i = 0; i < A->rows; i++) {
      for (int j = 0; j < A->columns; j++) {
        result->matrix[j][i] = A->matrix[i][j];
      }
    }
  }
  return err;
}

int s21_calc_complements(matrix_t *A, matrix_t *result) {
  int err = 0;
  if (A == NULL || !s21_is_correct_matrix(*A)) {
    err = 1;
  } else if (A->rows != A->columns) {
    err = 2;
  } else {
    s21_create_matrix(A->rows, A->columns, result);
    for (int i = 0; i < A->rows; i++) {
      for (int j = 0; j < A->columns; j++) {
        matrix_t minor;
        s21_minor_create(i, j, *A, &minor);
        double tmp_res = 0;
        s21_determinant(&minor, &tmp_res);
        result->matrix[i][j] = pow(-1, i + j) * tmp_res;
        s21_remove_matrix(&minor);
      }
    }
  }
  return err;
}
void s21_minor_create(int row, int column, matrix_t val1, matrix_t *val2) {
  int size = val1.columns - 1;
  s21_create_matrix(size, size, val2);
  int k = 0;
  for (int i = 0; i < val1.rows; i++) {
    if (i == row) {
      continue;
    }
    int q = 0;
    for (int j = 0; j < val1.columns; j++) {
      if (j != column) {
        val2->matrix[k][q] = val1.matrix[i][j];
        q++;
      }
    }
    k++;
  }
}

int s21_determinant(matrix_t *A, double *result) {
  int err = 0;
  if (A == NULL || !s21_is_correct_matrix(*A)) {
    err = 1;
  } else if (A->columns != A->rows) {
    err = 2;
  } else if (A->columns == 1) {
    *result = A->matrix[0][0];
  } else {
    *result = 0;
    for (int i = 0; i < A->columns; i++) {
      double temp_result = 0;
      matrix_t minor;
      s21_minor_create(0, i, *A, &minor);
      s21_determinant(&minor, &temp_result);
      s21_remove_matrix(&minor);
      *result += pow(-1, i) * A->matrix[0][i] * temp_result;
    }
  }

  return err;
}

int s21_inverse_matrix(matrix_t *A, matrix_t *result) {
  int err = 0;
  if (A == NULL || !s21_is_correct_matrix(*A)) {
    err = 1;
  } else if (A->columns != A->rows) {
    err = 2;
  } else {
    double det;
    s21_determinant(A, &det);
    if (fabs(det) >= EPS) {
      if (A->rows == 1 && A->columns == 1) {
        err = s21_create_matrix(1, 1, result);
        if (!err) {
          result->matrix[0][0] = 1 / A->matrix[0][0];
        }
      } else {
        matrix_t calc;

        s21_calc_complements(A, &calc);
        matrix_t transpose;
        s21_transpose(&calc, &transpose);
        printf("------'%lf'----------\n", 1 / det);
        s21_mult_number(&transpose, 1 / det, result);
        s21_remove_matrix(&calc);
        s21_remove_matrix(&transpose);
      }

    } else {
      err = 2;
    }
  }
  return err;
}