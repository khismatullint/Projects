#include "s21_math.h"

long double s21_sin(double x) {
  long double value_sin;
  if (x == s21_INFINITY || x == -s21_INFINITY) {
    value_sin = s21_NaN;
  } else {
    if (x > 2 * s21_PI || x < -2 * s21_PI) x = s21_fmod(x, 2 * s21_PI);
    value_sin = x;
    long double row = x;
    int i = 1;
    while (s21_fabs(row) > s21_NEAR_ZERO) {
      row = -row * x * x / ((i + 1) * (i + 2));
      value_sin += row;
      i += 2;
    }
  }
  return value_sin;
}