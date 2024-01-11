#include "s21_calculator.h"
void make_number(char* input, s21_node* output, size_t* i) {
  char buf_for_number[256] = "";
  double number;
  while ((*i) < strlen(input) && is_digit(input[*i])) {
    char tmp[256];
    sprintf(tmp, "%c", input[*i]);
    strcat(buf_for_number, tmp);
    (*i)++;
  }
  number = atoi(buf_for_number);
  if (input[*i] == '.') {
    strcpy(buf_for_number, "");
    int exp = 0;
    (*i)++;
    while ((*i) < strlen(input) && is_digit(input[*i])) {
      char tmp[256];
      sprintf(tmp, "%c", input[*i]);
      strcat(buf_for_number, tmp);
      (*i)++;
      exp++;
    }
    number += (double)atoi(buf_for_number) / pow(10, exp);
  }
  (*i)--;
  list_push_double(output, number);
}

char buf_changing(char* input, s21_node* output, size_t i, int* err) {
  char buf = input[i];
  switch (buf) {
    case '+':
    case '-':
      if (i == 0 || input[i - 1] == '(') list_push_double(output, 0);
      break;
    case 's':
      if (i < strlen(input) - 1 && input[i + 1] == 'i')
        buf = 'i';
      else if (input[i + 1] == 'q')
        buf = 'r';
      else
        *err = 1;
      break;
    case 'a':
      if (i < strlen(input) - 1 && input[i + 1] == 'c')
        buf = 'q';
      else if (input[i + 1] == 's')
        buf = 'w';
      else if (input[i + 1] == 't')
        buf = 'e';
      else
        *err = 1;
      break;
    case 'l':
      if (i < strlen(input) - 1 && input[i + 1] == 'n')
        buf = 'n';
      else if (input[i + 1] == 'o')
        buf = 'g';
      else
        *err = 1;
      break;
  }
  return buf;
}
void dijkstra(char buf, s21_stack* stack, s21_node* output) {
  if (buf == ')') {
    while (stack_head_char(stack) != '(') {
      list_push_char(output, stack_pop_char(stack));
    }
    stack_pop_char(stack);
  } else {
    while (buf != '(' && stack->head != -1 &&
           !is_el_greater(buf, stack_head_char(stack))) {
      list_push_char(output, stack_pop_char(stack));
    }
    stack_push_char(stack, buf);
  }
}
int polish_notation(char* input, s21_node* output, long double var_x) {
  int err = 0;
  s21_stack* stack = s21_create_stack();
  for (size_t i = 0; i < strlen(input); i++) {
    if (is_digit(input[i]))
      make_number(input, output, &i);
    else if (input[i] == 'x')
      list_push_double(output, var_x);
    else if (strchr("+-()*/^mcstasl", input[i])) {
      char buf = buf_changing(input, output, i, &err);
      while ((strchr("cirtqweng", buf) && input[i + 1] != '(') ||
             (buf == 'm' && input[i] != 'd')) {
        i++;
        if (i == strlen(input) - 1) {
          err = 1;
          break;
        }
      }
      dijkstra(buf, stack, output);

    } else if (input[i] != ' ') {
      err = 1;
      break;
    }
    if (err) break;
  }
  while (stack->head != -1) {
    list_push_char(output, stack_pop_char(stack));
  }
  s21_delete_stack(stack);
  return err;
}
int is_el_greater(char l, char r) {
  int res = 0;
  int index = 4;
  char* buf[5] = {"cirtqweng", "^", "*/m", "+-", "("};
  for (size_t i = 0; i < 5; i++) {
    if (strchr(buf[i], l)) {
      index = i;
      break;
    }
  }
  for (size_t i = index + 1; i < 5; i++) {
    if (strchr(buf[i], r)) {
      res = 1;
      break;
    }
  }

  return res;
}
int is_digit(char val) { return (strchr("0123456789", val)) ? 1 : 0; }

//  m - mod
//  c - cos
//  i - sin
//  r - sqrt
//  t - tan
//  q - acos
//  w - asin
//  e - atan
// n -ln
// g - log
