#ifndef SRC_SOURCE_S21_MATH_H_
#define SRC_SOURCE_S21_MATH_H_

#define s21_PI 3.14159265358979323
#define s21_EXP 2.7182818284590452
#define s21_NaN 0.0 / 0.0
#define s21_NEG_NaN -0.0 / 0.0
#define s21_EPSEQ 1e-17
#define s21_NEAR_ZERO 1E-15
#define s21_INFINITY 1.0 / 0.0
#define s21_NEG_INFINITY -1.0 / 0.0
#define s21_MAX_DOUBLE 9007199254740990
#define s21_LN10 2.30258509299404590109
#define isNaN(x) (x != x)
#define isINF(x) (x == s21_INFINITY)
#define isNEG_INF(x) (x == s21_NEG_INFINITY)

int s21_abs(int x);

// eckhardy
long double s21_asin(double x);
long double s21_ceil(double x);
long double s21_exp(double x);
long double s21_floor(double x);
long double s21_log(double x);
long double s21_sin(double x);
long double s21_tan(double x);

// maricruz
long double s21_acos(double x);
long double s21_atan(double x);
long double s21_cos(double x);
long double s21_fabs(double x);
long double s21_fmod(double x, double y);
long double s21_pow(double base, double exp);
long double s21_sqrt(double x);

#endif /* SRC_SOURCE_S21_MATH_H_ */
