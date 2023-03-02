#include "forwardlist.h"
#include <iostream>
int main() {
    forwardlist flist;
    flist.push(1);
    flist.push(2);
    flist.pop();
    flist.push(4);
    if (flist.front() == 4)
        std::cout << "SUCCESS" << '\n';
    if (flist.sizet() == 2)
        std::cout << "SUCCESS" << '\n';
    while (flist.size > 0) {
        std::cout << flist.front() << ' ';
        flist.pop();
    }
}