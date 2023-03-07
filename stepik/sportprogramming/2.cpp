#include <iostream>
#include <string>
using namespace std;
struct list {
    struct node {
        node* next;
        node* prev;
        string name;
        node(string _name) : next(nullptr), prev(nullptr), name(_name){};
    };
    node *start;
    node *last;
    size_t size;
    list() : start(nullptr), size(0), last(nullptr) {};
    ~list() {
        while (size>0) pop_front();
    }
    void push_front(string _name) {
        node *temp = new node(_name);
        if (size > 0) {
            temp->next = start;
            start->prev = temp;
        }
        start = temp;
        ++size;
    }
    void push_back(string _name) {
        node *temp = new node(_name);
        if (size>0) {
            temp -> prev = last;
            last -> next = temp;
        }
        last = temp;
        ++size;
    }
    void pop_front() {
        if (size==0) {
            return;
        }
        node *temp;
        temp = start;
        start = start->next;
        if (start) {
            start->prev = NULL;
        }
        delete temp;
        size--;
    }
    void pop_back() {
        if (size == 0) return;
        node *temp;
        temp = last;
        last = last -> prev;
        if (last) {
            last->next = NULL;
        }
        delete temp;
        size--;
    }
    string back() {
        if (size > 0) return last->name;
        else return "ERROR";
    }
    string front() {
        if (size > 0) return start->name;
        else return "ERROR";
    }
};
int main() {
    
}