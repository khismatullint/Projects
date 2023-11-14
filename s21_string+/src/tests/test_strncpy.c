#include <check.h>
#include <string.h>

#include "../s21_test.h"

START_TEST(test1_strncpy) {
  char dest[20] = "Hello, ";
  const char *src = "world!";
  size_t n = strlen(src);
  ck_assert_str_eq(strncpy(dest, src, n), s21_strncpy(dest, src, n));
}

START_TEST(test2_strncpy) {
  char dest[20] = "Hello, world!";
  const char *src = "Good";
  size_t n = strlen(src);
  ck_assert_pstr_eq(strncpy(dest, src, n), s21_strncpy(dest, src, n));
}
END_TEST

START_TEST(test3_strncpy) {
  char dest[20] = "Hello, world!";
  const char *src = "\0";
  size_t n = strlen(src);
  ck_assert_pstr_eq(strncpy(dest, src, n), s21_strncpy(dest, src, n));
}
END_TEST

START_TEST(test4_strncpy) {
  char dest[30] = "Hello, world!";
  const char *src = "test";
  size_t n = 1;
  ck_assert_pstr_eq(strncpy(dest, src, n), s21_strncpy(dest, src, n));
}
END_TEST

START_TEST(test5_strncpy) {
  char dest[10] = "";
  const char *src = "";
  size_t n = 0;
  ck_assert_pstr_eq(strncpy(dest, src, n), s21_strncpy(dest, src, n));
}
END_TEST

START_TEST(test6_strncpy) {
  char dest[10] = "";
  const char *src = "\0";
  size_t n = 0;
  ck_assert_pstr_eq(strncpy(dest, src, n), s21_strncpy(dest, src, n));
}
END_TEST

START_TEST(test7_strncpy) {
  char dest[20] = "";
  const char *src = "big long word";
  size_t n = strlen(src);
  ck_assert_pstr_eq(strncpy(dest, src, n), s21_strncpy(dest, src, n));
}
END_TEST

START_TEST(test8_strncpy) {
  char *dest = NULL;
  const char *src = "big long word";
  size_t n = strlen(src);
  ck_assert_ptr_eq(NULL, s21_strncpy(dest, src, n));
}
END_TEST

Suite *test_strncpy() {
  Suite *suite = suite_create("strncpy");
  TCase *tcase = tcase_create("strncpy_tcase");

  tcase_add_test(tcase, test1_strncpy);
  tcase_add_test(tcase, test2_strncpy);
  tcase_add_test(tcase, test3_strncpy);
  tcase_add_test(tcase, test4_strncpy);
  tcase_add_test(tcase, test5_strncpy);
  tcase_add_test(tcase, test6_strncpy);
  tcase_add_test(tcase, test7_strncpy);
  tcase_add_test(tcase, test8_strncpy);

  suite_add_tcase(suite, tcase);
  return suite;
}
