#include "s21_calculator.h"
s21_node* s21_create_list() {
  s21_node* val = (s21_node*)malloc(sizeof(s21_node));
  val->size = 0;
  val->next = NULL;

  return val;
}
s21_node* list_push_char(s21_node* root, char val) {
  if (!root->size) {
    root->data_char = val;
    root->size++;
    root->is_char = 1;

  } else {
    s21_node* p = root;
    while (p->next != NULL) {
      p = p->next;
    }
    p->next = (s21_node*)malloc(sizeof(s21_node));
    p->next->next = NULL;
    p->next->data_char = val;
    p->next->is_char = 1;
    root->size++;
    p->next->size = root->size;
  }
  return root;
}
s21_node* list_push_double(s21_node* root, long double val) {
  if (!root->size) {
    root->data_double = val;
    root->size++;

    root->is_char = 0;
  } else {
    s21_node* p = root;
    while (p->next != NULL) {
      p = p->next;
    }
    p->next = (s21_node*)malloc(sizeof(s21_node));
    p->next->next = NULL;
    p->next->data_double = val;
    p->next->is_char = 0;

    root->size++;
    p->next->size = root->size;
  }
  return root;
}
s21_node* list_pop(s21_node** root) {
  s21_node* p = NULL;
  if (root) {
    p = *root;
    s21_node* root2 = (*root)->next;
    if (root2) root2->size = p->size - 1;
    free(*root);
    *root = root2;
  }

  return p;
}
void s21_delete_list(s21_node** root) {
  while (*root) {
    s21_node* tmp = (*root)->next;
    free(*root);
    *root = tmp;
  }
}
