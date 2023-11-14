#include "s21_math.h"

long double s21_fmod(double x, double y) {
  long double remain = s21_NaN;
  if (y == s21_INFINITY || y == -s21_INFINITY) {
    if (x != s21_INFINITY && x != -s21_INFINITY && x == x) {
      remain = 0;
    }
  } else if (x == s21_INFINITY || x == -s21_INFINITY) {
    remain = s21_NaN;
  } else if (y) {
    long long int personal = x / y;
    remain = x - y * personal;
  }
  return remain;
}