#ifndef LIST
#define LIST
#include <iostream>
struct forwardlist {
    struct node {
        int value;
        node* next;
        node(int _value) : value(_value), next(nullptr){};
    };
    forwardlist();
    ~forwardlist();
    node* start;
    size_t size;
    void push(int value);
    void pop();
    size_t sizet();
    void insert(int pos, int value);
    int front();
};
#endif