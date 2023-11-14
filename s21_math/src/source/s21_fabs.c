#include "s21_math.h"
#include "signbit.h"

long double s21_fabs(double x) { return signbit(x) ? -x : x; }