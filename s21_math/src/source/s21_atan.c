#include "s21_math.h"

long double common(double x) {
  long double res = x, y = x;
  for (int i = 1; s21_fabs(res) > s21_EPSEQ; i++) {
    res = -1 * res * x * x * (2 * i - 1) / (2 * i + 1);
    y += res;
  }
  return y;
}

long double s21_atan(double x) {
  long double y = 0;
  if (s21_fabs(x) < 1) {
    y = common(x);
  } else if (s21_fabs(x) == 1 || x == 0) {
    y = x == 1 ? s21_PI / 4 : x == -1 ? (-s21_PI) / 4 : 0;
  } else {
    y = x > 1 ? s21_PI / 2 - common(1 / x) : (-s21_PI) / 2 - common(1 / x);
  }
  return y;
}
