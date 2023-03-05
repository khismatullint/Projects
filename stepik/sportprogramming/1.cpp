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
        while(size>0) pop();
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
        node *temp = new node(value);
        if (size>0) {
            temp->next = start;
        }
        start = temp;
        size++;
        delete temp;
    }
    void insert(int pos, int value) {
        if (pos!= -1) {
            Flist qurrent;
            for (int i = 0; i < pos; i++) {
                node *temp = qurrent.start;
                qurrent.start = start->next;
            }
            node *val = new node(value);
            qurrent.start = val->next;
        }
        else {
            push(value);
        }
    }
};
int main() {
    int counter;
    cin >> counter;
    while (counter>0) {
        int n;
        cin >> n;
        switch(n) {
            case 1:
        
            case 2:

            case 3:

        }
    }
}