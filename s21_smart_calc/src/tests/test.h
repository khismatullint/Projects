#ifndef TEST_TEST_H_
#define TEST_TEST_H_

#include <check.h>

#include "../s21_calculator.h"
#define TOLERANCY 0.000001

#define ERROR 1

#define OK 0
#define REPLACE_PLUS 2
#define REPLACE_MINUS 3
Suite *validation_suite(void);
Suite *calculation_suite(void);
int calculation(char* result,double x, long double* answer);
#endif  // TEST_TEST_H_