#include "s21_math.h"

long double s21_ceil(double x) {
  long double y = (long)x;
  double fx = s21_fabs(x);
  if (x != x) {
    y = s21_NaN;
  } else if (fx == s21_INFINITY || fx == 0) {
    y = x;
  } else if (x < 0) {
    if (x > -1) y = -y;
  } else if (x != y) {
    y++;
  }

  return y;
}