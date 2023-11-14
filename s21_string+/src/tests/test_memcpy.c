#include <check.h>
#include <string.h>

#include "../s21_test.h"

START_TEST(test_memcpy_1) {
  char src[] = "Never gonna give you up";
  size_t len = strlen(src);
  char dest[len], s21_dest[len];
  ck_assert_mem_eq(memcpy(dest, src, len), s21_memcpy(s21_dest, src, len), len);
}
END_TEST

START_TEST(test_memcpy_2) {
  char src[] = " ";
  size_t len = strlen(src);
  char dest[len], s21_dest[len];
  ck_assert_mem_eq(memcpy(dest, src, len), s21_memcpy(s21_dest, src, len), len);
}
END_TEST

START_TEST(test_memcpy_3) {
  char src[] = "Hello\0";
  size_t len = strlen(src);
  char dest[len], s21_dest[len];
  ck_assert_mem_eq(memcpy(dest, src, len), s21_memcpy(s21_dest, src, len), len);
}
END_TEST

START_TEST(test_memcpy_4) {
  char src[1] = "H";
  size_t len = strlen(src);
  char dest[len], s21_dest[len];
  ck_assert_mem_eq(memcpy(dest, src, len), s21_memcpy(s21_dest, src, len), len);
}
END_TEST

START_TEST(test_memcpy_5) {
  char src[] = "\n";
  size_t len = strlen(src);
  char dest[len], s21_dest[len];
  ck_assert_mem_eq(memcpy(dest, src, len), s21_memcpy(s21_dest, src, len), len);
}
END_TEST

START_TEST(test_memcpy_6) {
  char src[] = "Never gonna give you up";
  size_t len = 0;
  char dest[] = "Never", s21_dest[] = "Never";
  ck_assert_mem_eq(memcpy(dest, src, len), s21_memcpy(s21_dest, src, len), len);
}
END_TEST

START_TEST(test_memcpy_7) {
  char src[] = "435785675";
  size_t len = strlen(src);
  char dest[len], s21_dest[len];
  ck_assert_mem_eq(memcpy(dest, src, len), s21_memcpy(s21_dest, src, len), len);
}
END_TEST

START_TEST(test_memcpy_8) {
  char src[] = "435785675";
  size_t len = 0;
  char dest[len], s21_dest[len];
  ck_assert_mem_eq(memcpy(dest, src, len), s21_memcpy(s21_dest, src, len), len);
}
END_TEST

START_TEST(test_memcpy_9) {
  char src[] = "    Hello";
  size_t len = strlen(src);
  char dest[len], s21_dest[len];
  ck_assert_mem_eq(memcpy(dest, src, len), s21_memcpy(s21_dest, src, len), len);
}
END_TEST

START_TEST(test_memcpy_10) {
  char src[] = "";
  size_t len = 9;
  char dest[len], s21_dest[len];

  ck_assert_mem_eq(memcpy(dest, src, len), s21_memcpy(s21_dest, src, len), len);
}

Suite *test_memcpy() {
  Suite *suite = suite_create("memcpy");
  TCase *tcase = tcase_create("memcpy_tcase");

  tcase_add_test(tcase, test_memcpy_1);
  tcase_add_test(tcase, test_memcpy_2);
  tcase_add_test(tcase, test_memcpy_3);
  tcase_add_test(tcase, test_memcpy_4);
  tcase_add_test(tcase, test_memcpy_5);
  tcase_add_test(tcase, test_memcpy_6);
  tcase_add_test(tcase, test_memcpy_7);
  tcase_add_test(tcase, test_memcpy_8);
  tcase_add_test(tcase, test_memcpy_9);
  tcase_add_test(tcase, test_memcpy_10);

  suite_add_tcase(suite, tcase);
  return suite;
}
