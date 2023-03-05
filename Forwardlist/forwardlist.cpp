#include "forwardlist.h"
forwardlist::forwardlist() : start(nullptr), size(0){};
forwardlist::~forwardlist() {
    while (size > 0) {
        pop();
    }
}
void forwardlist::push(int value) {
    node* elem = new node(value);

    if (size > 0) {
        elem->next = start;
    }
    start = elem;
    size++;
    delete elem;
}

void forwardlist::pop() {
    if (size == 0)
        return;
    node* tmp = start;
    start = start->next;
    --size;
    delete tmp;
}

size_t forwardlist::sizet() { return size; }

int forwardlist::front() {
    if (size != 0) {
        return start->value;
    } else
        return -1;
}