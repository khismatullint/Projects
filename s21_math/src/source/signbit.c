#include "s21_math.h"

int signbit(double x) {
  return (((const char*)&x)[sizeof(double) - 1] & 0x100) != 0;
}