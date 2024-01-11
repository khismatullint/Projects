#include "test.h"

START_TEST(s21_validation_0) {
  char result[] = "0";
  char my_result[] = "0";
  int error = validation(my_result);
  ck_assert_int_eq(OK, error);
  ck_assert_str_eq(result, my_result);
}
END_TEST

START_TEST(s21_validation_1) {
  char result[] = "0+2";
  char my_result[] = "0+2";
  int error = validation(my_result);
  ck_assert_int_eq(OK, error);
  ck_assert_str_eq(result, my_result);
}
END_TEST

START_TEST(s21_validation_2) {
  char result[] = "-0";
  char my_result[] = "-0";
  int error = validation(my_result);
  ck_assert_int_eq(OK, error);
  ck_assert_str_eq(result, my_result);
}
END_TEST

START_TEST(s21_validation_3) {
  char result[] = "+0";
  char my_result[] = "+0";
  int error = validation(my_result);
  ck_assert_int_eq(OK, error);
  ck_assert_str_eq(result, my_result);
}
END_TEST




START_TEST(s21_validation_error_1) {
  char my_result[255] = "111 222";
  int error = validation(my_result);
  ck_assert_int_eq(ERROR, error);
}
END_TEST

START_TEST(s21_validation_error_2) {
  char my_result[255] = "111. 222";
  int error = validation(my_result);
  ck_assert_int_eq(ERROR, error);
}
END_TEST

START_TEST(s21_validation_error_3) {
  char my_result[255] = "11.1. 222";
  int error = validation(my_result);
  ck_assert_int_eq(ERROR, error);
}
END_TEST

START_TEST(s21_validation_error_4) {
  char my_result[255] = ".";
  int error = validation(my_result);
  ck_assert_int_eq(ERROR, error);
}
END_TEST

START_TEST(s21_validation_error_5) {
  char my_result[255] = "(.)(.)";
  int error = validation(my_result);
  ck_assert_int_eq(ERROR, error);
}
END_TEST

START_TEST(s21_validation_error_6) {
  char my_result[255] = "./.";
  int error = validation(my_result);
  ck_assert_int_eq(ERROR, error);
}
END_TEST

START_TEST(s21_validation_error_7) {
  char my_result[255] = "+-+----+-+";
  int error = validation(my_result);
  ck_assert_int_eq(ERROR, error);
}
END_TEST

START_TEST(s21_validation_error_8) {
  char my_result[255] = "9*/9";
  int error = validation(my_result);
  ck_assert_int_eq(ERROR, error);
}
END_TEST

START_TEST(s21_validation_error_9) {
  char my_result[255] = "           ";
  int error = validation(my_result);
  ck_assert_int_eq(ERROR, error);
}
END_TEST

START_TEST(s21_validation_error_11) {
  char my_result[255] = "8/si n(x)";
  int error = validation(my_result);
  ck_assert_int_eq(ERROR, error);
}
END_TEST

START_TEST(s21_validation_error_12) {
  char my_result[255] = ")(";
  int error = validation(my_result);
  ck_assert_int_eq(ERROR, error);
}
END_TEST

START_TEST(s21_validation_error_13) {
  char my_result[255] = "8mode3";
  int error = validation(my_result);
  ck_assert_int_eq(ERROR, error);
}
END_TEST



START_TEST(s21_validation_error_15) {
  char my_result[255] = "sin(+0-)";
  int error = validation(my_result);
  ck_assert_int_eq(ERROR, error);
}
END_TEST

START_TEST(s21_validation_error_16) {
  char my_result[255] = "*";
  int error = validation(my_result);
  ck_assert_int_eq(ERROR, error);
}
END_TEST

START_TEST(s21_validation_error_17) {
  char my_result[255] = "sin";
  int error = validation(my_result);
  ck_assert_int_eq(ERROR, error);
}
END_TEST

START_TEST(s21_validation_error_18) {
  char my_result[255] = "mod";
  int error = validation(my_result);
  ck_assert_int_eq(ERROR, error);
}
END_TEST

START_TEST(s21_validation_error_19) {
  char my_result[255] = "+";
  int error = validation(my_result);
  ck_assert_int_eq(ERROR, error);
}
END_TEST

START_TEST(s21_validation_error_20) {
  char my_result[255] = "6/";
  int error = validation(my_result);
  ck_assert_int_eq(ERROR, error);
}
END_TEST

START_TEST(s21_validation_error_21) {
  char my_result[255] = "68**7";
  int error = validation(my_result);
  ck_assert_int_eq(ERROR, error);
}
END_TEST

Suite *validation_suite(void) {
  Suite *s = suite_create("validation");
  TCase *tc_error, *tc_normal;

  tc_error = tcase_create("case_validation_error");
  tc_normal = tcase_create("case_validation_normal");

  tcase_add_test(tc_normal, s21_validation_0);
  tcase_add_test(tc_normal, s21_validation_1);
  tcase_add_test(tc_normal, s21_validation_2);
  tcase_add_test(tc_normal, s21_validation_3);

  tcase_add_test(tc_error, s21_validation_error_1);
  tcase_add_test(tc_error, s21_validation_error_2);
  tcase_add_test(tc_error, s21_validation_error_3);
  tcase_add_test(tc_error, s21_validation_error_4);
  tcase_add_test(tc_error, s21_validation_error_5);
  tcase_add_test(tc_error, s21_validation_error_6);
  tcase_add_test(tc_error, s21_validation_error_7);
  tcase_add_test(tc_error, s21_validation_error_8);
  tcase_add_test(tc_error, s21_validation_error_9);
  tcase_add_test(tc_error, s21_validation_error_11);
  tcase_add_test(tc_error, s21_validation_error_12);
  tcase_add_test(tc_error, s21_validation_error_13);
  tcase_add_test(tc_error, s21_validation_error_15);
  tcase_add_test(tc_error, s21_validation_error_16);
  tcase_add_test(tc_error, s21_validation_error_17);
  tcase_add_test(tc_error, s21_validation_error_18);
  tcase_add_test(tc_error, s21_validation_error_19);
  tcase_add_test(tc_error, s21_validation_error_20);
  tcase_add_test(tc_error, s21_validation_error_21);

  suite_add_tcase(s, tc_error);
  suite_add_tcase(s, tc_normal);

  return s;
}
