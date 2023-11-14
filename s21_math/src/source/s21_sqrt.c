#include "s21_math.h"

long double s21_sqrt(double x) {
  long double value_sqrt = 0;
  if (x != x) {
    value_sqrt = s21_NaN;
  } else if (x == s21_INFINITY) {
    value_sqrt = s21_INFINITY;
  } else {
    long double end = x;
    if (x < 0 || x == s21_NaN) {
      value_sqrt = s21_NaN;
    } else {
      long double start = 0;
      while (start <= end) {
        long double mid = 0;
        mid = (start + end) / 2;
        if (mid * mid == x) {
          value_sqrt = mid;
          break;
        }
        if (mid * mid < x) {
          value_sqrt = start;
          start = mid + 1;
        } else {
          end = mid - 1;
        }
      }
      long double increment = 0.1;
      for (int i = 0; i <= 6; i++) {
        while (value_sqrt * value_sqrt <= x) {
          value_sqrt += increment;
        }
        value_sqrt = value_sqrt - increment;
        increment = increment / 10;
      }
    }
  }
  return value_sqrt;
}