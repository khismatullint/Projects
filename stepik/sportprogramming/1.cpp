#include <iostream>
using namespace std;
struct Flist {
    struct node {
        int value;
        node* next;
        node(int _value) : next(nullptr), value(_value){};
    };
    int size;
    node* start;
    Flist() : size(0), start(nullptr){};
    ~Flist() {
        while (size > 0)
            pop();
    }
    void pop() {
        if (size == 0)
            return;
        node* tmp = start;
        start = start->next;
        --size;
        delete tmp;
    }
    void push(int value) {
        node* temp = new node(value);
        if (size > 0) {
            temp->next = start;
        }
        start = temp;
        size++;
    }
    void insert(int pos, int value) {
        if (pos != -1 && pos < size) {
            node* temp;
            temp = start;
            while (pos > 0) {
                temp = temp->next;
                pos--;
            }
            node* val = new node(value);
            val->next = temp->next;
            temp->next = val;
            size++;
        } else if (pos == -1) {
            push(value);
        }
    }
    int getpos(int pos) {
        if (pos < size) {
            node* temp;
            temp = start;
            while (pos > 0) {
                temp = temp->next;
                pos--;
            }
            node* returned = temp;
            return returned->value;
        } else
            return -1;
    }
    int front() {
        if (size != 0) {
            return start->value;
        } else
            return -1;
    }
    void deletepos(int pos) {
        if (pos >= 0 && pos < size && size) {
            node* temp;
            temp = start;
            while (pos > 0) {
                temp = temp->next;
                pos--;
            }
            if (temp->next) {
                node* deleted = temp->next;
                if (deleted->next) {
                    temp->next = deleted->next;
                } else
                    temp->next = NULL;
                delete deleted;
            }
            size--;
        } else if (pos == -1) {
            pop();
        } else
            return;
    }
};
int main() {
    int counter;
    cin >> counter;
    Flist list;
    while (counter > 0) {
        int n;
        cin >> n;
        int pos, value;
        switch (n) {
        case 1:
            cin >> pos >> value;
            list.insert(pos, value);
            break;
        case 2:
            cin >> pos;
            list.deletepos(pos);
            break;
        case 3:
            cin >> pos;
            cout << list.getpos(pos) << '\n';
            break;
        }
        counter--;
    }
}