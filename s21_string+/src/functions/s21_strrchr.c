#include "../s21_string.h"
char *s21_strrchr(const char *str, int ch) {
  const char *last = S21_NULL;
  while (*str != '\0') {
    if (*str == ch) {
      last = str;
    }
    str++;
  }
  if (ch == '\0') {
    return (char *)str;
  }
  return (char *)last;
}