#include "../s21_string.h"

char *s21_strncat(char *dest, const char *src, s21_size_t n) {
  char *dest_end = dest;

  // Находим конец строки в dest
  while (*dest_end != '\0') {
    dest_end++;
  }

  // Копируем символы из src в dest
  while (*src != '\0' && n > 0) {
    *dest_end = *src;
    dest_end++;
    src++;
    n--;
  }

  // Добавляем нулевой символ в конец строки
  *dest_end = '\0';

  return dest;
}
