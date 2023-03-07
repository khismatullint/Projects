#include "list.h"
#include <iostream>
list::list() : start(nullptr), last(nullptr), size(0){};
list::~list() {
    while (size>0) pop_front();
}
void list::push_front(int _val) {
    node *temp = new node(_val);
    if (size>0) {
        temp->next = start;
        start->prev = temp;
    }
    temp = start;
    size++;
}
void list::push_back(int _val) {
    node *temp = new node(_val);
    if (size > 0) {
        temp->prev = last;
        last->next = temp;
    }
    temp = last;
    size++;
}
void list::pop_front() {
    if (size == 0) return;
    node *deleted = start;
    start = start->next;
    if (start) start->prev = NULL;
    delete deleted;
    size--;
}
void list::pop_back() {
    if (size==0) return;
    node *deleted = last;
    last = last->prev;
    if (last) last->next = NULL;
    delete deleted;
    size--;
}
size_t list::sizet() {
    return size;
}
void list::insert(int pos, int _val) {
    if (pos < size && pos >= 0) {
        if (size / 2 - pos > 0) {
            node *temp = start;
            while (pos > 0) {
                temp = temp -> next;
                pos--;
            }
            node *elem = new node(_val);
            node *next = temp->next;
            elem -> next = next;
            next -> prev = elem;
            elem -> prev = temp;
            temp -> next = elem;
        }
        if (size / 2 - pos <= 0) {
            node *temp = last;
            pos = size - pos;
            while (pos > 0) {
                temp = temp->prev;
                pos--;
            }
            node *elem = new node(_val);
            node *prev = temp->prev;
            elem->prev = prev;
            prev->next = elem;
            elem->next = temp;
            temp->prev = elem;
        }
        size++;
    }
    else if (pos == size) push_back(_val);
    else if (pos == -1) push_front(_val);
}
void list::erase(int pos) {
    if (pos < size && pos >= 0) {
        if (size / 2 - pos > 0) {
            node *temp = start;
            while (pos > 0) {
                temp = temp->next;
                pos--;
            }
            node *deleted = temp->next;
            node *next = deleted->next;
            temp -> next = next;
            next -> prev = temp;
            delete deleted;
            size--;
        }
        if (size / 2 - pos <= 0) {
            pos = size - pos;
            node *temp = last;
            while (pos > 0) {
                temp = temp -> prev;
                pos--;
            }
            node *deleted = temp -> prev;
            node *prev = deleted->prev;
            temp->prev = prev;
            prev->next = temp;
            delete deleted;
            size--;
        }
    }
    else if (pos == size) pop_back();
    else if (pos == -1) pop_front();
}
int list::getnth(int pos) {
    int returned;
    if (pos >= 0 && pos < size) {
        if (size/2 - pos > 0) {
            node *temp = start;
            while (pos > 0) {
                temp = temp->next;
                pos--;
            }
            returned = temp->value;
        }
        if (size/2 - pos <= 0) {
            node *temp = last;
            pos = size - pos;
            while (pos > 0) {
                temp = temp->prev;
                pos--;
            }
            returned = temp->value;
        }
    }
    else returned = -1;
    return returned;
}