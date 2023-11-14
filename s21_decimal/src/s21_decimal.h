#ifndef __S21_DECIMAL__
#define __S21_DECIMAL__
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct {
  unsigned int bits[4];
} s21_decimal;
typedef struct {
  unsigned int bits[7];
} s21_big;
unsigned int getbit(s21_decimal num, int bit);
unsigned int getbit_big(s21_big num, int bit);
void setbit(s21_decimal *num, int bit, const unsigned int set);
void setbit_big(s21_big *num, int bit, const unsigned int set);
unsigned int sign(s21_decimal num);
void decimal_to_big(s21_decimal *num, s21_big *big);
unsigned int power(s21_decimal num);
void decimalToBinary(unsigned int num);
void power_up(s21_decimal *num, int number);
void normalization(s21_decimal *num, s21_decimal *num1);
void sum(s21_decimal num1, s21_decimal num2, s21_decimal *result, int i,
         unsigned int *temp);
void sub(s21_decimal num1, s21_decimal num2, s21_decimal *result, int i,
         unsigned int *temp);
void shift_to_the_left_big(s21_big *num, int zeros);
void big_to_decimal(s21_big big, s21_decimal *num);
void power_up_big(s21_big *num, int number);
int is_null_decimal(s21_decimal num);
void set_exp(s21_decimal *dst, int exp);
void s21_decimal_init(s21_decimal *dst);
void from_decimal_to_big(s21_decimal src, s21_big *dst);
void big_decimal_init(s21_big *dst);
void max_big_make(s21_big *num, int max_pow);
unsigned int power_big(s21_big num);
void shift_to_the_right_big(s21_big *num, int zeros);
int is_zero(s21_decimal num);

// Функции сравнения децималов
int s21_is_less(s21_decimal num1, s21_decimal num2);
int s21_is_less_or_equal(s21_decimal num1, s21_decimal num2);
int s21_is_greater(s21_decimal num1, s21_decimal num2);
int s21_is_greater_or_equal(s21_decimal num1, s21_decimal num2);
int s21_is_equal(s21_decimal num1, s21_decimal num2);
int s21_is_not_equal(s21_decimal num1, s21_decimal num2);

// Арифметические операции
int s21_add(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
int s21_sub(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
int s21_mul(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
int s21_div(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);

// Конвертеры
int s21_from_float_to_decimal(float src, s21_decimal *dst);
int s21_from_decimal_to_int(s21_decimal src, int *dst);
int s21_from_decimal_to_float(s21_decimal src, float *dst);
int s21_from_int_to_decimal(int src, s21_decimal *dst);

// Округления
int s21_floor(s21_decimal value, s21_decimal *result);
int s21_round(s21_decimal value, s21_decimal *result);
int s21_negate(s21_decimal value, s21_decimal *result);
int s21_truncate(s21_decimal value, s21_decimal *result);
#endif  // __S21_DECIMAL__