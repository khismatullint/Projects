#include <iostream>;
int main() {
    int right;
    std::cin >> right;
    int left = 0, k = 0;
    while (right - left > 1) {
        int M = (right + left) / 2;
        left = M;
        k++;
    }
    std::cout << k;
}