#include "s21_calculator.h"
int check_functions(const char* str) {
  int err = 0;
  size_t size = strlen(str);
  for (size_t i = 0; i < size; i++) {
    if ((strncmp(str + i, "sin", 3) == 0 &&
         (3 + i >= size - 1 || str[3 + i] != '(')) ||
        (strncmp(str + i, "cos", 3) == 0 &&
         (3 + i >= size - 1 || str[3 + i] != '(')) ||
        (strncmp(str + i, "tan", 3) == 0 &&
         (3 + i >= size - 1 || str[3 + i] != '(')) ||
        (strncmp(str + i, "sqrt", 3) == 0 &&
         (4 + i >= size - 1 || str[4 + i] != '(')) ||
        (strncmp(str + i, "ln", 3) == 0 &&
         (2 + i >= size - 1 || str[2 + i] != '(')) ||
        (strncmp(str + i, "log", 3) == 0 &&
         (3 + i >= size - 1 || str[3 + i] != '('))) {
      err = 1;
      break;
    }
  }

  return err;
}

int validation(char* input) {
  int err = 0;
  int count_l = 0, count_r = 0;
  if (strlen(input) > 256 || check_functions(input))
    err = 1;
  else {
    for (size_t i = 0; i < strlen(input); i++) {
      if (err)
        break;
      else if (!strchr("modcsintaqrtlg()+-*/^01234567x89.", input[i]) ||
               (input[i] == '.' && (i == strlen(input) - 1 ||
                                    !strchr("0123456789", input[i + 1]))) ||
               (strchr("+-/*d^(", input[i]) &&
                (i == strlen(input) - 1 || strchr(")=/*^", input[i + 1])))) {
        err = 1;
        break;
      } else if (input[i] == '(')
        count_l++;
      else if (input[i] == ')')
        count_r++;
    }
  }

  return err || (count_l != count_r);
}
