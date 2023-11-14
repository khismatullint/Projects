#include "s21_math.h"

long double s21_acos(double x) {
  if (s21_fabs(x) <= 1) {
    x = s21_PI / 2 - s21_asin(x);
  } else {
    x = s21_NaN;
  }
  return x;
}