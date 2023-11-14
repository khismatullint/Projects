#include "s21_math.h"

long double s21_asin(double x) {
  long double value_asin = s21_NaN;
  if (x > -0.9 && x < 0.9) {
    value_asin = x;
    long double row = x;
    int i = 2;
    for (int j = 0; j <= 15000; j++) {
      row = row * x * x * (i - 1) * (i - 1) / (i * (i + 1));
      i += 2;
      value_asin += row;
    }
  } else if (x <= 1.0 && x >= 0.9) {
    value_asin = s21_PI / 2 - s21_asin(s21_sqrt(1 - x * x));
  } else if (x >= -1.0 && x <= -0.9) {
    value_asin = -s21_PI / 2 + s21_asin(s21_sqrt(1 - x * x));
  }
  return value_asin;
}