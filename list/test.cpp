#include "list.h"
#include <iostream>
using namespace std;
int main() {
    list list;
    list.push_front(1);
    if (list.start->value == 1) {
        cout << list.start->value << " [list.push_front(1)] <- SUCCESS" << endl;
    }
    list.push_front(2);
    if (list.start->value == 2) {
        cout << list.start->value << " [list.push_front(2)] <- SUCCESS" << endl;
    }
    list.push_back(10);
    if (list.last->value == 10) {
        cout << list.last->value << " [list.push_back(10)] <- SUCCESS" << endl;
    }
    list.insert(2, 100);
    if (list.getnth(3) == 100) {
        cout << list.getnth(3) << " [list.insert(2,100)] <- SUCCESS" << endl;
    }
    for (size_t i = 0; i < list.sizet() - 1; i++) {
        cout << '[' << i << "] " << list.getnth(i) << endl;
    }
    cout << '[' << list.sizet() - 1 << "] " << list.getnth(list.sizet() - 1)
         << endl;
    if (list.sizet() == 4) {
        cout << "Size == " << list.sizet() << " <- SUCCESS" << endl;
    }
    list.pop_back();
    if (list.last->value == 100) {
        cout << "last value = " << list.last->value
             << " after [list.pop_back()] <- SUCCESS" << endl;
    }
    for (size_t i = 0; i < list.sizet() - 1; i++) {
        cout << '[' << i << "] " << list.getnth(i) << endl;
    }
    cout << '[' << list.sizet() - 1 << "] " << list.getnth(list.sizet() - 1)
         << endl;
    if (list.sizet() == 3) {
        cout << "Size == " << list.sizet() << " <- SUCCESS" << endl;
    }
}