#include "s21_calculator.h"

s21_stack* s21_create_stack() {
  s21_stack* val = (s21_stack*)malloc(sizeof(s21_stack));
  val->head = -1;
  return val;
}
void s21_delete_stack(s21_stack* val) { free(val); }
long double stack_pop_double(s21_stack* val) {
  val->head--;
  return val->data_double[val->head + 1];
}
char stack_pop_char(s21_stack* val) {
  val->head--;
  return val->data_char[val->head + 1];
}
void stack_push_double(s21_stack* val, long double el) {
  val->head++;
  val->data_double[val->head] = el;
}
void stack_push_char(s21_stack* val, char el) {
  val->head++;
  val->data_char[val->head] = el;
}
long double stack_head_double(s21_stack* val) {
  return val->data_double[val->head];
}
char stack_head_char(s21_stack* val) { return val->data_char[val->head]; }