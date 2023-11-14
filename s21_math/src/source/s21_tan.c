#include "s21_math.h"

long double s21_tan(double x) {
  long double value;
  if (x >= s21_PI && s21_fmod(x, s21_PI) == 0.)
    value = 0;
  else
    value = s21_sin(x) / s21_cos(x);
  return value;
}