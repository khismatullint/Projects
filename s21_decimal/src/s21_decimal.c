#include "s21_decimal.h"

unsigned int getbit(s21_decimal num, int bit) {
  int index = bit / 32;
  bit %= 32;
  return (num.bits[index] & 0b1 << bit) >> bit;
}
unsigned int getbit_big(s21_big num, int bit) {
  int index = bit / 32;
  bit %= 32;
  return (num.bits[index] & 0b1 << bit) >> bit;
}
int is_zero(s21_decimal num) {
  return (!num.bits[0] && !num.bits[1] && !num.bits[2]) ? 1 : 0;
}
void setbit(s21_decimal *num, int bit, const unsigned int set) {
  int index = bit / 32;
  bit %= 32;
  num->bits[index] =
      !set ? num->bits[index] & ~(0b1 << bit) : num->bits[index] | (0b1 << bit);
}
void setbit_big(s21_big *num, int bit, const unsigned int set) {
  int index = bit / 32;
  bit %= 32;
  num->bits[index] =
      !set ? num->bits[index] & ~(0b1 << bit) : num->bits[index] | (0b1 << bit);
}
unsigned int power(s21_decimal num) {
  return (num.bits[3] & (255 << 16)) >> 16;
}
unsigned int power_big(s21_big num) {
  return (num.bits[6] & (255 << 16)) >> 16;
}
unsigned int sign(s21_decimal num) { return getbit(num, 127); }
void sum(s21_decimal num1, s21_decimal num2, s21_decimal *result, int i,
         unsigned int *temp) {
  int temp_result = getbit(num1, i) + getbit(num2, i) + *temp;
  if (temp_result == 3) {
    setbit(result, i, 1);
    *temp = 1;
  } else if (temp_result == 2) {
    setbit(result, i, 0);
    *temp = 1;
  } else if (temp_result == 1) {
    setbit(result, i, 1);
    *temp = 0;
  } else if (!temp_result) {
    setbit(result, i, 0);
    *temp = 0;
  }
}
void sum_big(s21_big num1, s21_big num2, s21_big *result, int i,
             unsigned int *temp) {
  int temp_result = getbit_big(num1, i) + getbit_big(num2, i) + *temp;
  if (temp_result == 3) {
    setbit_big(result, i, 1);
    *temp = 1;
  } else if (temp_result == 2) {
    setbit_big(result, i, 0);
    *temp = 1;
  } else if (temp_result == 1) {
    setbit_big(result, i, 1);
    *temp = 0;
  } else if (!temp_result) {
    setbit_big(result, i, 0);
    *temp = 0;
  }
}
void sub_big(s21_big num1, s21_big num2, s21_big *result, int i,
             unsigned int *temp) {
  int temp_result = getbit_big(num1, i) - getbit_big(num2, i);
  if (temp_result == -1 && !*temp) {
    setbit_big(result, i, 1);
    *temp = 1;
  } else if (temp_result == -1 && *temp) {
    setbit_big(result, i, 0);
    *temp = 1;
  } else if (!temp_result && *temp && getbit_big(num1, i)) {
    setbit_big(result, i, 1);
    *temp = 1;
  } else if (temp_result && !*temp) {
    setbit_big(result, i, 1);
    *temp = 0;
  } else if (!temp_result && *temp && !getbit_big(num1, i) &&
             !getbit_big(num2, i)) {
    setbit_big(result, i, 1);
    *temp = 1;
  } else if (!temp_result && !*temp) {
    setbit_big(result, i, 0);
    *temp = 0;
  } else if (temp_result && *temp && !getbit_big(num2, i)) {
    setbit_big(result, i, 0);
    *temp = 0;
  }
}
void power_up(s21_decimal *num, int number) {
  s21_decimal power_one = {{0, 0, 0, 0b00000000000000010000000000000000}};
  for (int i = 0; i < number; i++) {
    s21_decimal temp_decimal = *num;
    unsigned int temp = 0;
    for (int i = 112; i <= 119; i++) {
      sum(temp_decimal, power_one, num, i, &temp);
    }
  }
}
void power_up_big(s21_big *num, int number) {
  s21_big power_one = {{0, 0, 0, 0, 0, 0, 0b00000000000000010000000000000000}};
  int flag = 0;
  if (number < 0) {
    number *= -1;
    flag = 1;
  }
  for (int i = 0; i < number; i++) {
    s21_big temp_decimal = *num;
    unsigned int temp = 0;
    for (int i = 208; i <= 215; i++) {
      if (!flag)
        sum_big(temp_decimal, power_one, num, i, &temp);
      else
        sub_big(temp_decimal, power_one, num, i, &temp);
    }
  }
}
void shift_to_the_left(s21_decimal *num, int zeros) {
  for (int i = 0; i < zeros; i++) {
    for (int j = 94; j > 0 + i; j--) {
      unsigned int temp = getbit(*num, j - 1);
      setbit(num, j, temp);
    }
    setbit(num, i, 0);
  }
}
int check_big_decimal(s21_big num) {
  int result = 0;
  for (int i = 3; i < 6; i++) {
    if (num.bits[i]) {
      result = 1;
      break;
    }
  }
  return result;
}
void shift_to_the_left_big(s21_big *num, int zeros) {
  for (int i = 0; i < zeros; i++) {
    for (int j = 191; j > 0 + i; j--) {
      unsigned int temp = getbit_big(*num, j - 1);
      setbit_big(num, j, temp);
    }
    setbit_big(num, i, 0);
  }
}
void shift_to_the_right_big(s21_big *num, int zeros) {
  for (int i = 0; i < zeros; i++) {
    for (int j = 0; j < 192 - i; j++) {
      unsigned int temp = getbit_big(*num, j + 1);
      setbit_big(num, j, temp);
    }
    setbit_big(num, 191 - i, 0);
  }
}
void decimal_to_big(s21_decimal *num, s21_big *big) {
  for (int i = 0; i < 96; i++) {
    setbit_big(big, i, getbit(*num, i));
  }
  for (int i = 96; i < 128; i++) {
    setbit_big(big, i + (32 * 3), getbit(*num, i));
  }
}
void big_to_decimal(s21_big big, s21_decimal *num) {
  int temp = 0;
  int index_decimal = 95;
  int index_last_bit = 127;
  for (int i = 223; i >= 192; i--) {
    setbit(num, index_last_bit, getbit_big(big, i));
    index_last_bit--;
  }
  for (int i = 191; i >= 0; i--) {
    if (index_decimal < 0) break;
    if ((!temp && getbit_big(big, i)) || i == 95) {
      temp = 1;
    }
    if (!temp && !getbit_big(big, i)) {
      continue;
    }
    if (temp) setbit(num, index_decimal, getbit_big(big, i));
    index_decimal--;
  }
}
void division_by_ten_big(s21_big dec, s21_big *res) {
  unsigned long long buf;
  unsigned long long ost = 0;
  unsigned int max = 0b11111111111111111111111111111111;
  for (int i = 5; i >= 0; i--) {
    buf = dec.bits[i];
    buf |= ost << 32;
    ost = buf % 10;
    buf /= 10;
    res->bits[i] = max & buf;
  }
  if (ost > 4) {
    res->bits[0] += 1;
  }
}
void s21_decimal_div_by_10(s21_decimal *dst) {
  unsigned long long buf = 0;
  unsigned long long ost = 0;
  for (int i = 2; i >= 0; i--) {
    buf += dst->bits[i];
    ost = buf % 10;
    dst->bits[i] = (int)(buf / 10);
    buf = ost << 32;
  }
}

int format_big(s21_big *result_big) {
  int result = 0;
  while (check_big_decimal(*result_big)) {
    if (!power_big(*result_big)) {
      result = !getbit_big(*result_big, 223) ? 1 : 2;
      break;
    }
    division_by_ten_big(*result_big, result_big);
    power_up_big(result_big, -1);
  }
  return result;
}
void normalization_big(s21_big *num, s21_big *num1) {
  unsigned int to_power = 0;
  if (power_big(*num) > power_big(*num1)) {
    to_power = power_big(*num) - power_big(*num1);
    max_big_make(num1, to_power);
  } else {
    to_power = power_big(*num1) - power_big(*num);
    max_big_make(num, to_power);
  }
}
void max_big_make(s21_big *num, int max_pow) {
  s21_big temp_decimal1 = *num;
  s21_big temp_decimal2 = *num;
  if (power_big(*num) < 28) {
    for (int i = 0; i < max_pow; i++) {
      shift_to_the_left_big(&temp_decimal2, 3);
      shift_to_the_left_big(&temp_decimal1, 1);
      unsigned int temp = 0;
      for (int i = 0; i <= 191; i++) {
        sum_big(temp_decimal1, temp_decimal2, num, i, &temp);
      }

      power_up_big(num, 1);
      temp_decimal1 = *num;
      temp_decimal2 = *num;
    }
  }
}
int greater_mantissa_big(s21_big val_1, s21_big val_2) {
  int result = 0;
  for (int i = 191; i > -1; i--) {
    if (getbit_big(val_1, i) > getbit_big(val_2, i)) {
      result = 1;
      break;
    } else if (getbit_big(val_1, i) < getbit_big(val_2, i)) {
      break;
    }
  }
  return result;
}
void sum_full_big(s21_big num1, s21_big num2, s21_big *result_big,
                  unsigned int *temp) {
  for (int i = 0; i <= 191; i++) {
    sum_big(num1, num2, result_big, i, temp);
  }
}
void sub_full_big(s21_big num1, s21_big num2, s21_big *result_big,
                  unsigned int *temp) {
  for (int i = 0; i <= 191; i++) {
    sub_big(num1, num2, result_big, i, temp);
  }
}
int s21_add(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  int return_num = 0;
  s21_big num1 = {{0, 0, 0, 0, 0, 0, 0}};
  s21_big num2 = {{0, 0, 0, 0, 0, 0, 0}};
  s21_big result_big = {{0, 0, 0, 0, 0, 0, 0}};
  unsigned int temp = 0;
  decimal_to_big(&value_1, &num1);
  decimal_to_big(&value_2, &num2);
  normalization_big(&num1, &num2);
  if (sign(value_1) == sign(value_2)) {
    if (sign(value_1) || sign(value_2)) setbit_big(&result_big, 223, 1);
    sum_full_big(num1, num2, &result_big, &temp);
  } else if (greater_mantissa_big(num2, num1)) {
    sub_full_big(num2, num1, &result_big, &temp);
    if (getbit_big(num2, 223)) setbit_big(&result_big, 223, 1);
  } else {
    sub_full_big(num1, num2, &result_big, &temp);
    if (getbit_big(num1, 223)) setbit_big(&result_big, 223, 1);
  }
  power_up_big(&result_big, power_big(num1));
  return_num = format_big(&result_big);
  big_to_decimal(result_big, result);
  return return_num;
}
int s21_sub(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  s21_big num1 = {{0, 0, 0, 0, 0, 0, 0}};
  s21_big num2 = {{0, 0, 0, 0, 0, 0, 0}};
  s21_big result_big = {{0, 0, 0, 0, 0, 0, 0}};
  unsigned int temp = 0;
  int return_num = 0;
  decimal_to_big(&value_1, &num1);
  decimal_to_big(&value_2, &num2);
  normalization_big(&num1, &num2);
  if (!sign(value_1) && !sign(value_2)) {
    if (greater_mantissa_big(num1, num2)) {
      sub_full_big(num1, num2, &result_big, &temp);
    } else {
      sub_full_big(num2, num1, &result_big, &temp);
      setbit_big(&result_big, 223, 1);
    }
  } else if (sign(value_1) && sign(value_2)) {
    if (greater_mantissa_big(num1, num2)) {
      sub_full_big(num1, num2, &result_big, &temp);
      setbit_big(&result_big, 223, 1);
    } else {
      sub_full_big(num2, num1, &result_big, &temp);
    }
  } else if (!sign(value_1) && sign(value_2)) {
    sum_full_big(num1, num2, &result_big, &temp);
  } else if (sign(value_1) && !sign(value_2)) {
    sum_full_big(num1, num2, &result_big, &temp);
    setbit_big(&result_big, 223, 1);
  }
  power_up_big(&result_big, power_big(num1));
  return_num = format_big(&result_big);
  big_to_decimal(result_big, result);
  return return_num;
  return 0;
}
int s21_mul(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  int err = 0;
  s21_big big_res = {{0, 0, 0, 0, 0, 0}};
  s21_big big_value = {{0, 0, 0, 0, 0}};
  decimal_to_big(&value_1, &big_value);
  for (int i = 0; i < 96; i++) {
    if (getbit(value_2, i)) {
      s21_big tmp = big_value;
      shift_to_the_left_big(&tmp, i);
      unsigned int temp = 0;
      sum_full_big(big_res, tmp, &big_res, &temp);
    }
  }
  int res_power = power(value_1) + power(value_2);

  while (res_power > 28 || big_res.bits[5] || big_res.bits[4] ||
         big_res.bits[3]) {
    division_by_ten_big(big_res, &big_res);
    res_power--;
    if (res_power == 0) {
      err = 1;
      break;
    }
  }
  if (!err) {
    big_to_decimal(big_res, result);

    if (big_res.bits[0] || big_res.bits[1] || big_res.bits[2]) {
      power_up(result, res_power);
      setbit(result, 127, !(sign(value_1) == sign(value_2)));
    }
  }

  return err;
}
int s21_is_greater(s21_decimal num1, s21_decimal num2) {
  s21_big num1_big = {{0, 0, 0, 0, 0, 0, 0}};
  s21_big num2_big = {{0, 0, 0, 0, 0, 0, 0}};
  decimal_to_big(&num1, &num1_big);
  decimal_to_big(&num2, &num2_big);
  normalization_big(&num1_big, &num2_big);
  int result = 0;
  if ((greater_mantissa_big(num1_big, num2_big) && !sign(num1) &&
       !sign(num2)) ||
      ((!sign(num1) && sign(num2)) && !is_zero(num1) && !is_zero(num2)))
    result = 1;
  else if (greater_mantissa_big(num2_big, num1_big) && sign(num1) && sign(num2))
    result = 1;
  return result;
}
int s21_is_equal(s21_decimal num1, s21_decimal num2) {
  s21_big num1_big = {{0, 0, 0, 0, 0, 0, 0}};
  s21_big num2_big = {{0, 0, 0, 0, 0, 0, 0}};
  decimal_to_big(&num1, &num1_big);
  decimal_to_big(&num2, &num2_big);
  normalization_big(&num1_big, &num2_big);
  int result = 0;
  for (int i = 0; i < 6; i++) {
    result = 1;
    if (sign(num1) != sign(num2)) {
      result = 0;
      break;
    }
    if ((num1_big.bits[i] != num2_big.bits[i])) {
      result = 0;
      break;
    }
  }
  if (is_zero(num1) && is_zero(num2)) result = 1;
  return result;
}
int s21_is_less(s21_decimal num1, s21_decimal num2) {
  return (!s21_is_greater(num1, num2) && !s21_is_equal(num1, num2)) ? 1 : 0;
}
int s21_is_less_or_equal(s21_decimal num1, s21_decimal num2) {
  return (s21_is_less(num1, num2) || s21_is_equal(num1, num2)) ? 1 : 0;
}
int s21_is_greater_or_equal(s21_decimal num1, s21_decimal num2) {
  return (s21_is_greater(num1, num2) || s21_is_equal(num1, num2)) ? 1 : 0;
}
int s21_is_not_equal(s21_decimal num1, s21_decimal num2) {
  return !s21_is_equal(num1, num2) ? 1 : 0;
}
int s21_floor(s21_decimal value, s21_decimal *result) {
  s21_big result_big = {{0, 0, 0, 0, 0, 0, 0}};
  decimal_to_big(&value, &result_big);
  while (power_big(result_big)) {
    s21_big temp = result_big;
    unsigned long long buf;
    unsigned long long ost = 0;
    unsigned int max = 0b11111111111111111111111111111111;
    for (int i = 5; i >= 0; i--) {
      buf = temp.bits[i];
      buf |= ost << 32;
      ost = buf % 10;
      buf /= 10;
      result_big.bits[i] = max & buf;
    }
    power_up_big(&result_big, -1);
  }
  if (sign(value)) {
    result_big.bits[0] += 1;
  }
  big_to_decimal(result_big, result);
  return 0;
}
int s21_round(s21_decimal value, s21_decimal *result) {
  s21_big result_big = {{0, 0, 0, 0, 0, 0, 0}};
  decimal_to_big(&value, &result_big);
  while (power_big(result_big)) {
    division_by_ten_big(result_big, &result_big);
    power_up_big(&result_big, -1);
  }
  big_to_decimal(result_big, result);
  return 0;
}
int s21_truncate(s21_decimal value, s21_decimal *result) {
  s21_big result_big = {{0, 0, 0, 0, 0, 0, 0}};
  decimal_to_big(&value, &result_big);
  while (power_big(result_big)) {
    s21_big temp = result_big;
    unsigned long long buf;
    unsigned long long ost = 0;
    unsigned int max = 0b11111111111111111111111111111111;
    for (int i = 5; i >= 0; i--) {
      buf = temp.bits[i];
      buf |= ost << 32;
      ost = buf % 10;
      buf /= 10;
      result_big.bits[i] = max & buf;
    }
    power_up_big(&result_big, -1);
  }
  big_to_decimal(result_big, result);
  return 0;
}
int s21_negate(s21_decimal value, s21_decimal *result) {
  *result = value;
  if (getbit(value, 127))
    setbit(result, 127, 0);
  else
    setbit(result, 127, 1);
  return 0;
}
int s21_from_int_to_decimal(int src, s21_decimal *dst) {
  int res = 0;
  if (src > 2147483647 || !dst) {
    res = 1;
  } else {
    s21_decimal_init(dst);

    if (src < 0) {
      setbit(dst, 127, 1);
      src = (src == -2147483648) ? 2147483647 : -src;

    } else {
      setbit(dst, 127, 0);
    }
    dst->bits[0] = src;
  }

  return res;
}

int s21_from_float_to_decimal(float src, s21_decimal *dst) {
  int err = 0;
  if ((fabs(src) > 1e-28 || src == 0.0) && fabs(src) < 2e96 - 1 && dst &&
      fabs(src) != (1.0 / 0.0)) {
    s21_decimal_init(dst);
    if (src < 0) {
      dst->bits[3] |= 1 << 31;
      src = -src;
    }
    char str[97];
    char str_res[8] = "";
    if (src > 9999999) {
      sprintf(str, "%.7lf", src);
    } else {
      sprintf(str, "%.8g", src);
    }

    int power = 0;
    int flag = 0;
    int index = 0;
    if (strchr(str, 'e') || strchr(str, 'E')) {
      if (strchr(str, 'e'))
        index = strchr(str, 'e') - str;
      else if (strchr(str, 'E'))
        index = strchr(str, 'E') - str;
      if (str[index + 1] == '-') {
        char tmp[5] = "";
        sprintf(tmp, "%c", str[index + 2]);
        if (strlen(str) - index - 3)
          sprintf(tmp, "%c%c", str[index + 2], str[index + 3]);
        power = atoi(tmp);
      }
    }
    int temp = 0;
    if (strchr(str, '.')) {
      if (src <= 9999999) flag = 1;
      temp = (strchr(str, '.') - str);
      memmove(&str[temp], &str[temp + 1], strlen(str) - temp);
    }
    if (strlen(str) > 7) {
      strncpy(str_res, str, 7);
      str_res[7] = '\0';
    } else {
      strcpy(str_res, str);
    }
    if (flag) {
      for (int i = 6; str_res[i] == '0'; i--) {
        memmove(&str_res[i], &str_res[i + 1], strlen(str_res) - i);
      }
    }
    dst->bits[0] = atoi(str_res);
    power_up(dst, flag * (power + strlen(str_res) - temp));

  } else {
    err = 1;
  }
  return err;
}
int s21_from_decimal_to_int(s21_decimal src, int *dst) {
  int res = 0;
  if (dst) {
    for (size_t i = 0; i < power(src); i++) {
      s21_decimal_div_by_10(&src);
    }
    if (src.bits[1] || src.bits[2] || !dst) {
      res = 1;
    } else {
      *dst = sign(src) ? -src.bits[0] : src.bits[0];
    }
  } else
    res = 1;

  return res;
}
int s21_from_decimal_to_float(s21_decimal src, float *dst) {
  int err = 0;
  long double res = 0;
  if (dst) {
    for (size_t i = 0; i < 96; i++) {
      if (getbit(src, i)) res += pow(2, i);
    }
    for (size_t i = 0; i < power(src); i++) {
      res /= 10;
    }

    *dst = sign(src) ? -res : res;
  } else
    err = 1;

  return err;
}
int s21_div(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  int err = 0;
  if (is_zero(value_2))
    err = 3;
  else if (power(value_1) > 28 || power(value_2) > 28) {
    err = 2;
  }
  if (!err) {
    s21_decimal_init(result);
    s21_big tmp_value_1;
    s21_big tmp_value_2;
    s21_big tmp;
    s21_big tmp_res;
    big_decimal_init(&tmp_res);
    big_decimal_init(&tmp);
    big_decimal_init(&tmp_value_1);
    big_decimal_init(&tmp_value_2);

    decimal_to_big(&value_2, &tmp_value_2);
    decimal_to_big(&value_1, &tmp_value_1);

    while (!greater_mantissa_big(tmp_value_2, tmp_value_1)) {
      int counter = 0;
      decimal_to_big(&value_2, &tmp);
      while (!greater_mantissa_big(tmp, tmp_value_1)) {
        shift_to_the_left_big(&tmp, 1);
        counter++;
      }
      shift_to_the_right_big(&tmp, 1);
      s21_big pow_tmp;
      s21_decimal pow_tmp_tmpAHAHHA;
      s21_decimal_init(&pow_tmp_tmpAHAHHA);
      pow_tmp_tmpAHAHHA.bits[0] = 1;
      big_decimal_init(&pow_tmp);
      shift_to_the_left(&pow_tmp_tmpAHAHHA, counter - 1);

      decimal_to_big(&pow_tmp_tmpAHAHHA, &pow_tmp);
      unsigned int y = 0;
      sum_full_big(pow_tmp, tmp_res, &tmp_res, &y);

      unsigned int f = 0;
      sub_full_big(tmp_value_1, tmp, &tmp_value_1, &f);
    }

    if (power(value_1) < power(value_2)) {
      max_big_make(&tmp_res, power(value_2) - power(value_1));
      tmp_res.bits[6] = 0;
    } else {
      tmp_res.bits[6] &= ~(0xFFU << 16);
      tmp_res.bits[6] |= ((power(value_1) - power(value_2)) << 16);
    }
    if (getbit(value_1, 127) == getbit(value_2, 127)) {
      setbit_big(&tmp_res, 223, 0);
    } else {
      setbit_big(&tmp_res, 223, 1);
    }

    err = format_big(&tmp_res);
    big_to_decimal(tmp_res, result);

    if (!is_zero(*result)) {
      if (getbit(value_1, 127) == getbit(value_2, 127)) {
        setbit(result, 127, 0);
      } else {
        setbit(result, 127, 1);
      }
    } else {
      result->bits[3] = 0;
    }
  }
  return err;
}
void big_decimal_init(s21_big *dst) {
  for (int i = 0; i < 7; i++) {
    dst->bits[i] = 0;
  }
}
void s21_decimal_init(s21_decimal *dst) {
  for (size_t i = 0; i < 4; i++) {
    dst->bits[i] = 0;
  }
}