#ifndef STACKH
#define STACKH
#include <iostream>
struct stack {
    size_t size;
    char *a;
    int w;
    stack();
    ~stack();
    void push(char val);
    void pop();
    char top();
};
#endif