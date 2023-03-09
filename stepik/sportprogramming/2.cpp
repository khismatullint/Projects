#include <iostream>
#include <string>
using namespace std;
struct Flist {
    struct node {
        string name;
        node* next;
        node(string _name) : next(nullptr), name(_name){};
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
    void push(string name) {
        node* temp = new node(name);
        if (size > 0) {
            temp->next = start;
        }
        start = temp;
        size++;
    }
    string getpos(int pos) {
        if (pos < size) {
            node* temp;
            temp = start;
            while (pos > 0) {
                temp = temp->next;
                pos--;
            }
            node* returned = temp;
            return returned->name;
        } else
            return "ERROR";
    }
    void reverse() {
        node *temp = NULL;
        node *prev = NULL;
        node *current = start;
    while (current != NULL) {
        temp = current->next;
        current->next = prev;
        prev = current;
        current = temp;
    }
    start = prev;
    }
    string front() {
        if (size == 0) return "ERROR";
        return start->name;
    }
};
int main() {
    Flist list;
    int counter;
    cin >> counter;
    string name;
    while (counter>0) {
        int menu;
        cin >> menu;
        switch (menu) {
            case 1:
                cin >> name;
                list.push(name);
                break;
            case 2:
                cout << list.front() << endl;
                list.pop();
                break;
            case 3:
                list.reverse();
                break;
        }
        counter--;
    }
}