#ifndef DUOLIST
#define DUOLIST
#include <iostream>
struct list {
    struct node {
        node* next;
        node* prev;
        int value;
        node(int _value) : next(nullptr), prev(nullptr), value(_value){};
    };
    node* start;
    node* last;
    size_t size;
    list();
    ~list();
    void pop_front();
    void pop_back();
    void push_front(int _val);
    void push_back(int _val);
    size_t sizet();
    void insert(int pos, int _val);
    void erase(int pos);
    int getnth(int pos);
};
#endif