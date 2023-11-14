#include "s21_math.h"

long double s21_exp(double x) {
  long double result = 1, y = 1;
  int minus = x < 0 ? -1 : 1;
  x *= minus;
  for (int i = 1; s21_fabs(result) > s21_EPSEQ; i++) {
    result *= x / i;
    y += result;
    if (y > s21_MAX_DOUBLE) {
      y = s21_INFINITY;
      break;
    }
  }
  y = minus == -1 ? y > s21_MAX_DOUBLE ? 0 : 1.0 / y : y;
  return y > s21_MAX_DOUBLE ? s21_INFINITY : y;
}