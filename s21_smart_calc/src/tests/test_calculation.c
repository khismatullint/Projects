#include "test.h"

START_TEST(s21_calculation_0) {
  char result[] = "0";
  double  x = 0, right_answer = 0;
  long double answer;
  int error = calculation(result, x, &answer);
  ck_assert_int_eq(OK, error);
  ck_assert_ldouble_eq_tol(answer, right_answer, TOLERANCY);
}
END_TEST

START_TEST(s21_calculation_1) {
  char result[] = "5mod(2)";
  double  x = 0, right_answer = 1;
  long double answer;
  int error = calculation(result, x, &answer);
  ck_assert_int_eq(OK, error);
  ck_assert_ldouble_eq_tol(answer, right_answer, TOLERANCY);
}
END_TEST

START_TEST(s21_calculation_3) {
  char result[] = "8+4*2";
  long double answer;
  double x = 0, right_answer = 16;
  int error = calculation(result, x, &answer);
  ck_assert_int_eq(OK, error);
  ck_assert_ldouble_eq_tol(answer, right_answer, TOLERANCY);
}
END_TEST
START_TEST(s21_calculation_4) {
  char result[] = "111mod22";
  long double answer;
  double x = 0, right_answer = 1;
  int error = calculation(result, x, &answer);
  ck_assert_int_eq(OK, error);
  ck_assert_ldouble_eq_tol(answer, right_answer, TOLERANCY);
}
END_TEST

START_TEST(s21_calculation_8) {
  char result[] = "99/8";
  long double answer;
  double x = 0, right_answer = 12.375;
  int error = calculation(result, x, &answer);
  ck_assert_int_eq(OK, error);
  ck_assert_ldouble_eq_tol(answer, right_answer, TOLERANCY);
}
END_TEST
START_TEST(s21_calculation_9) {
  char result[] = "acos(1)+log(4)";
  long double answer;
  double x = 8, right_answer = 0.60205999;
  int error = calculation(result, x, &answer);
  ck_assert_int_eq(OK, error);
  ck_assert_ldouble_eq_tol(answer, right_answer, TOLERANCY);
}
END_TEST
START_TEST(s21_calculation_10) {
  char result[] = "2^3+sqrt(1)";
  long double answer;
  double x = 8, right_answer = 9;
  int error = calculation(result, x, &answer);
  ck_assert_int_eq(OK, error);
  ck_assert_ldouble_eq_tol(answer, right_answer, TOLERANCY);
}
START_TEST(s21_calculation_11) {
  char result[] = "2^3+sqrt(1)+sin(0)";
  long double answer;
  double x = 8, right_answer = 9;
  int error = calculation(result, x, &answer);
  ck_assert_int_eq(OK, error);
  ck_assert_ldouble_eq_tol(answer, right_answer, TOLERANCY);
}
END_TEST
START_TEST(s21_calculation_15) {
  char result[] = "2/1+2+3+4*5*6^7-12+((1000+500*2)*201)";
   long double answer;
   double x = 0, right_answer = 6000715;
  int error = calculation(result, x, &answer);
  ck_assert_int_eq(OK, error);
  ck_assert_ldouble_eq_tol(answer, right_answer, TOLERANCY);
}
END_TEST
START_TEST(s21_calculation_16) {
  char result[] = "atan((8))";
  long double answer;
  double x = 8, right_answer = 1.44644133;
  int error = calculation(result, x, &answer);
  ck_assert_int_eq(OK, error);
  ck_assert_ldouble_eq_tol(answer, right_answer, TOLERANCY);
}
END_TEST
START_TEST(s21_calculation_17) {
  char result[] = "tan((8))";
  long double answer;
  double x = 8, right_answer = -6.799711;
  int error = calculation(result, x, &answer);
  ck_assert_int_eq(OK, error);
  ck_assert_ldouble_eq_tol(answer, right_answer, TOLERANCY);
}
END_TEST

START_TEST(s21_calculation_18) {
  char result[] = "acos(1)+ln(4)";
  long double answer;
  double x = 8, right_answer = 1.386294;
  int error = calculation(result, x, &answer);
  ck_assert_int_eq(OK, error);
  ck_assert_ldouble_eq_tol(answer, right_answer, TOLERANCY);
}
END_TEST




Suite *calculation_suite(void) {
  Suite *s = suite_create("calculation");
  TCase *tc_error, *tc_normal;

  tc_error = tcase_create("case_calculation_error");
  tc_normal = tcase_create("case_calculation_normal");

  tcase_add_test(tc_normal, s21_calculation_0);
   tcase_add_test(tc_normal, s21_calculation_1);
  tcase_add_test(tc_normal, s21_calculation_3);
  tcase_add_test(tc_normal, s21_calculation_4);
  tcase_add_test(tc_normal, s21_calculation_8);
  tcase_add_test(tc_normal, s21_calculation_9);
  tcase_add_test(tc_normal, s21_calculation_10);
  tcase_add_test(tc_normal, s21_calculation_11);
  tcase_add_test(tc_normal, s21_calculation_15);
  tcase_add_test(tc_normal, s21_calculation_16);
  tcase_add_test(tc_normal, s21_calculation_17);
  tcase_add_test(tc_normal, s21_calculation_18);


  suite_add_tcase(s, tc_error);
  suite_add_tcase(s, tc_normal);

  return s;
}
