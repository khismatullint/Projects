#include "../s21_string.h"

void *s21_memcpy(void *dest, const void *src, s21_size_t n) {
  char *result = (char *)dest, *src2 = (char *)src;
  if (n != 0) {
    for (s21_size_t i = n; i-- > 0;) result[i] = src2[i];
  }
  return result;
}