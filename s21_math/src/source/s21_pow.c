#include <stdint.h>

#include "s21_math.h"

#define OK 1000.0;
int isInt(double d) { return d == (int64_t)d; };

double helper(double base, double exp) {
  double res = OK;
  if (base == 0.0) {
    if (isNaN(exp)) {
      res = s21_NaN;
    } else if (exp == -s21_NaN) {
      res = -s21_NaN;
    } else if (isNEG_INF(exp)) {
      res = s21_INFINITY;
    } else if (exp == 0.0) {
      res = 1.0;
    } else if (exp < 0) {
      res = s21_INFINITY;
    }
  } else if (base == 1.0) {
    res = 1.0;
  } else if (base == -1.0) {
    if (isINF(exp) || isNEG_INF(exp)) {
      res = 1.0;
    }
  } else if (!isInt(base) && !isINF(base) && !isNEG_INF(base)) {
    if (isINF(exp)) {
      res = 0.0;
    } else if (isNEG_INF(exp)) {
      res = s21_INFINITY;
    }
  } else if (isInt(base)) {
    if (isINF(exp) || isNEG_INF(exp)) {
      res = s21_INFINITY;
    }
  } else if (isINF(base)) {
    if (exp == 0.0) {
      res = 1.0;
    } else if (exp > 0 && isInt(exp)) {
      res = s21_INFINITY;
    } else if (isINF(exp)) {
      res = s21_INFINITY;
    } else if (isNaN(exp)) {
      res = s21_NaN;
    }
  } else if (isNEG_INF(base)) {
    if (exp == 0.0) {
      res = 1.0;
    } else if (exp > 0 && isInt(exp)) {
      res = s21_NEG_INFINITY;
    } else if (isINF(exp)) {
      res = s21_INFINITY;
    } else if (isNaN(exp)) {
      res = s21_NaN;
    }
  }
  return res;
}

long double fast_pow(double base, long long int exp) {
  long double ans = 1.0;
  long long copy = s21_fabs(exp);
  while (copy) {
    ans *= base;
    copy--;
  }
  return (exp < 0) ? 1.0 / ans : ans;
}

long double s21_pow(double base, double exp) {
  long double ans = 1.0;
  if (helper(base, exp) == 1000.0) {
    if (isInt(exp)) {
      ans = fast_pow(base, exp);
    } else {  // exp in not int
      if (base < 0) {
        ans = s21_NaN;
      } else {
        ans = s21_exp(exp * s21_log(base));
      }
    }
  } else {
    ans = helper(base, exp);
  }
  return ans;
}
