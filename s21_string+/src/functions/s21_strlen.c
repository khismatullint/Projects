#include "../s21_string.h"

s21_size_t s21_strlen(const char *str) {
  // считаем символы пока последний символ не конец строки
  size_t result = 0;
  while (*str != '\0') {
    str++;
    result++;
  }

  return result;
}
