#ifndef __S21CALCULATOR__
#define __S21CALCULATOR__

#include <stdio.h>
#include <stdlib.h>

#include "math.h"
#include "string.h"

#define EPS 1e-7

typedef struct node {
  int size;
  long double data_double;
  char data_char;
  int is_char;
  struct node* next;
} s21_node;

typedef struct stack {
  int head;
  long double data_double[256];
  char data_char[256];
} s21_stack;

s21_node* s21_create_list();
int lexems_to_res(s21_node* input, long double* res);
s21_node* list_push_char(s21_node* root, char val);
s21_node* list_push_double(s21_node* root, long double val);
s21_node* list_pop(s21_node** root);
void s21_delete_list(s21_node** root);
int polish_notation(char* input, s21_node* output, long double var_x);
int is_digit(char val);
void make_number(char* input, s21_node* output, size_t* i);
int is_el_greater(char l, char r);
char buf_changing(char* input, s21_node* output, size_t i, int* err);
void dijkstra(char buf, s21_stack* stack, s21_node* output);
s21_stack* s21_create_stack();
void s21_delete_stack(s21_stack* val);
long double stack_pop_double(s21_stack* val);
char stack_pop_char(s21_stack* val);
void stack_push_double(s21_stack* val, long double el);
void stack_push_char(s21_stack* val, char el);
long double stack_head_double(s21_stack* val);
char stack_head_char(s21_stack* val);
int validation(char* input);
int check_functions(const char* str);
#endif