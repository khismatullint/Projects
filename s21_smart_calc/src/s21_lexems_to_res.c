#include "s21_calculator.h"
int lexems_to_res(s21_node* input, long double* res) {
  int err = 0;
  s21_node* val;
  s21_stack* stack = s21_create_stack();
  while ((val = list_pop(&input)) != NULL) {
    if (!val->is_char)
      stack_push_double(stack, val->data_double);

    else if (stack->head != -1) {
      long double buf = stack_pop_double(stack);
      if (strchr("gnewqtric", val->data_char)) {
        if ((val->data_char == 'r' || val->data_char == 'g' ||
             val->data_char == 'n') &&
            buf < 0) {
          err = 1;
          break;
        } else {
          switch (val->data_char) {
            case 'g':
              stack_push_double(stack, log10l(buf));
              break;
            case 'n':
              stack_push_double(stack, logl(buf));
              break;
            case 'e':
              stack_push_double(stack, atanl(buf));
              break;
            case 'w':
              stack_push_double(stack, asinl(buf));
              break;
            case 'q':
              stack_push_double(stack, acosl(buf));
              break;
            case 't':
              stack_push_double(stack, tanl(buf));
              break;
            case 'r':
              stack_push_double(stack, sqrtl(buf));
              break;
            case 'i':
              stack_push_double(stack, sinl(buf));
              break;
            case 'c':
              stack_push_double(stack, cosl(buf));
              break;
          }
        }
      } else if (stack->head != -1) {
        long double buf2 = stack_pop_double(stack);
        if ((val->data_char == 'm' || val->data_char == '/') && !buf) {
          err = 1;
          break;
        } else {
          switch (val->data_char) {
            case 'm':
              stack_push_double(stack, fmodl(buf2, buf));
              break;
            case '/':
              stack_push_double(stack, buf2 / buf);
              break;
            case '^':
              stack_push_double(stack, powl(buf2, buf));
              break;
            case '+':
              stack_push_double(stack, buf2 + buf);
              break;
            case '-':
              stack_push_double(stack, buf2 - buf);
              break;
            case '*':
              stack_push_double(stack, buf2 * buf);
              break;
          }
        }

      } else {
        err = 1;
        break;
      }
    } else {
      err = 1;
      break;
    }
    if (err)
      break;
    else if (!input) {
      *res = stack_head_double(stack);
      break;
    }
  };
  s21_delete_list(&input);
  s21_delete_stack(stack);
  return err;
};

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
