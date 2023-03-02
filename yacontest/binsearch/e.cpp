#include <iostream>;
int main() {
    uint64_t a, k, b, m, x;
    std::cin >> a >> k >> b >> m >> x;
    uint64_t key, left = 0, right = x / (a + b) * 2 + 1, middle;
    while (right - left > 1) {
        middle = (right + left) / 2;
        uint64_t z = a * (middle - middle / k);
        uint64_t q = b * (middle - middle / m);
        uint64_t c = a * (middle - middle / k) + b * (middle - middle / m);
        if (z + q >= x)
            right = middle;
        else
            left = middle;
    }
    std::cout << right;
}