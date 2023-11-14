#include "../s21_string.h"

void *s21_memset(void *str, int c, s21_size_t n) {
  unsigned char *result = str;
  if (n != 0) {
    for (s21_size_t i = n; i-- > 0;) result[i] = c;
  }
  return result;
}