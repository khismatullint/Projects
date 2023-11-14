#include "../s21_string.h"

int s21_strncmp(const char *str1, const char *str2, s21_size_t n) {
  if (n == 0) {
    return 0;
  }

  int result = 0;

  while (n > 0 && (*str1 || *str2)) {
    if (*str1 == *str2) {
      n--;
      str1++;
      str2++;
    } else {
      result = *(unsigned char *)str1 - *(unsigned char *)str2;
      --str1;
      --str2;
      n = 0;
    }
  }

  return result;
}