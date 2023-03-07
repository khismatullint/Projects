#include "list.h"
#include <iostream>
list::list() : start(nullptr), last(nullptr), size(0){};
list::~list() {
    while (size > 0)
        pop_front();
}
void list::push_front(int _val) {
    node* temp = new node(_val);
    if (size > 0) {
        temp->next = start;
        start->prev = temp;
    }
    start = temp;
    if (size == 0)
        last = temp;
    ++size;
}
void list::push_back(int _val) {
    node* temp = new node(_val);
    if (size > 0) {
        temp->prev = last;
        last->next = temp;
    }
    last = temp;
    if (size == 0)
        start = temp;
    ++size;
}
void list::pop_front() {
    if (size == 0)
        return;
    node* deleted = start;
    start = start->next;
    if (start)
        start->prev = NULL;
    delete deleted;
    size--;
}
void list::pop_back() {
    if (size == 0)
        return;
    node* deleted = last;
    last = last->prev;
    if (last)
        last->next = NULL;
    delete deleted;
    size--;
}
size_t list::sizet() { return size; }
void list::insert(int pos, int _val) {
    if (pos == (int)size) {
        push_back(_val);
        return;
    }
    if (pos == -1) {
        push_front(_val);
        return;
    }
    if (pos < (int)size && pos >= 0) {
        if (size == 0) {
            push_front(_val);
            return;
        } else if ((int)size / 2 - pos > 0) {
            node* temp = start;
            while (pos > 0) {
                temp = temp->next;
                pos--;
            }
            node* elem = new node(_val);
            node* next = temp->next;
            elem->next = next;
            next->prev = elem;
            elem->prev = temp;
            temp->next = elem;
            size++;
            return;
        } else if ((int)(size / 2) - pos <= 0) {
            node* temp = last;
            int nth = size - pos;
            while (nth > 0) {
                temp = temp->prev;
                nth--;
            }
            node* elem = new node(_val);
            node* next = temp->next;
            elem->next = next;
            next->prev = elem;
            elem->prev = temp;
            temp->next = elem;
            size++;
            return;
        }
    }
}
void list::erase(int pos) {
    if (pos < (int)size && pos >= 0 && (int)size > 0) {
        if ((int)size / 2 - pos > 0) {
            node* temp = start;
            while (pos > 0) {
                temp = temp->next;
                pos--;
            }
            node* next = temp->next;
            node* prev = temp->prev;
            prev->next = next;
            next->prev = prev;
            delete temp;
            size--;
        }
        if ((int)size / 2 - pos <= 0) {
            pos = size - pos;
            node* temp = last;
            while (pos > 0) {
                temp = temp->prev;
                pos--;
            }
            node* next = temp->next;
            node* prev = temp->prev;
            prev->next = next;
            next->prev = prev;
            delete temp;
            size--;
        }
    } else if (pos == (int)size && (int)size > 0)
        pop_back();
    else if (pos == -1 && size > 0)
        pop_front();
}
int list::getnth(int pos) {
    if (size == 0 || pos > (int)size || pos < 0)
        return -1;
    else {
        if (size == 1)
            return start->value;
        int count = (int)(size / 2);
        if (count - pos >= 0) {
            node* temp = start;
            while (pos > 0) {
                temp = temp->next;
                pos--;
            }
            if (temp)
                return temp->value;
        } else if (count - pos < 0) {
            int nth = count - pos;
            node* temp = last;
            while (nth > 0) {
                temp = temp->prev;
                nth--;
            }
            if (temp)
                return temp->value;
        }
    }
    return -2;
}