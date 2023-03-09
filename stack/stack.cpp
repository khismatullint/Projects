#include "stack.h"
#include <iostream>
#include <stdlib.h>
stack::stack() {
    a = nullptr;
    size = 0;
    w = 0;
}
stack::~stack() {
    free(a);
}
void stack::push(char val) {
    if (w < (int)size) {
        *(a+w) = val;
        ++w;
    }
    if (w==(int)size) {
        a = (char*)realloc(a,(size*2+1)*sizeof(char));
        size = size*2+1;
        *(a+w)=val;
        ++w;
    }
}
void stack::pop() {
    if (w==0) {
        return;
    }
    --w;
    if (2*w<=(int)size) {
        a = (char*)realloc(a,(size/2+1)*sizeof(char));
        size = size/2 +1;
    }
}
char stack::top() {
    if (w==0) return -1;
    return *(a+w-1);
}