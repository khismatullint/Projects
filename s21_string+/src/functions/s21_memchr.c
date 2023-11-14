#include "../s21_string.h"

void *s21_memchr(const void *str, int c, s21_size_t n) {
  void *result = S21_NULL;
  char *str1 = (char *)str;
  for (s21_size_t i = 0; i < n; i++)
    if (str1[i] == ((char)c)) {
      result = ((void *)str + i);
      break;
    }
  return result;
}
