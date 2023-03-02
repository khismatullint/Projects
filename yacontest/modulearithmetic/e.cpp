#include <iostream>
int main() {
    const int mod = 1e6 + 7;
    int64_t a, b, sum;
    std::cin >> a >> b;
    int64_t c = (a * a - b * b) % mod;
    if (c >= 0) {
        std::cout << c;
    } else
        std::cout << (mod + c);
}