#include "../s21_string.h"

char *s21_strncpy(char *dest, const char *src, s21_size_t n) {
  if (dest == NULL || src == NULL) return NULL;

  if (n > 0) {
    char *new_dest = dest;

    while (*src != '\0' && n > 0) {
      *dest = *src;
      dest++;
      src++;
      n--;
    }

    *dest = '\0';

    return new_dest;
  }
  return dest;
}
