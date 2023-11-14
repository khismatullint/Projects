#include "s21_math.h"

/*   Yn+1 = Yn + 2 * (X - exp(Yn)) / (X + exp(Yn))   */

long double s21_log(double x) {
  int exp_pow = 0;
  long double step = 0;
  long double res = 0;
  long double result = res + exp_pow;
  if (isNaN(x)) {
    result = s21_NaN;
  } else if (isINF(x)) {
    result = s21_INFINITY;
  } else if (isNEG_INF(x)) {
    result = -s21_NaN;
  } else {
    if (x > 0) {
      while (x >= s21_EXP) {
        x /= s21_EXP;
        exp_pow++;
      }
      for (int i = 0; i < 150; i++) {
        step = res;
        res = step + 2 * (x - s21_exp(step)) / (x + s21_exp(step));
      }
      result = res + exp_pow;
    } else if (x == 0) {
      result = s21_NEG_INFINITY;
    } else if (x < 0) {
      result = s21_NaN;
    }
  }
  return result;
}
