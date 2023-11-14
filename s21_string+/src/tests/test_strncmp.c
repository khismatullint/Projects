#include <check.h>
#include <string.h>

#include "../s21_test.h"

START_TEST(test1_strncmp) {
  const char *qwe = "Always Day One";
  const char *ewq = "Always Day Three";

  for (int i = -20; i < 20; i++) {
    ck_assert_int_eq(strncmp(qwe, ewq, i), s21_strncmp(qwe, ewq, i));
  }

  for (int b = 20; b > -20; b--) {
    ck_assert_int_eq(strncmp(qwe, ewq, b), s21_strncmp(qwe, ewq, b));
  }
}

Suite *test_strncmp() {
  Suite *suite = suite_create("strncmp");
  TCase *tcase = tcase_create("strncmp_tcase");

  tcase_add_test(tcase, test1_strncmp);

  suite_add_tcase(suite, tcase);
  return suite;
}
