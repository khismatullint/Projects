#include "s21_math.h"

long double s21_cos(double x) {
  long double value_cos;
  if (x == s21_INFINITY || x == -s21_INFINITY) {
    value_cos = s21_NaN;
  } else {
    if (x > 2 * s21_PI || x < -2 * s21_PI) x = s21_fmod(x, 2 * s21_PI);
    long double row = 1;
    value_cos = 1;
    int i = 0;
    while (s21_fabs(row) > s21_NEAR_ZERO) {
      row = -row * x * x / ((i + 1) * (i + 2));
      value_cos += row;
      i += 2;
    }
  }
  return value_cos;
}