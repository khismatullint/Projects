#include <algorithm>
#include <iostream>
#include <vector>

long long ammount(long long lenght, const std::vector<long long>& array) {
    long long ammount = 0;
    for (long long i = 0; i < array.size(); ++i) {
        ammount += array[i] / lenght;
    }
    return ammount;
}

long long bin_ser_l(long long val, const std::vector<long long>& array) {

    long long l = 0;
    long long r = 0;
    for (int i = 0; i < array.size(); ++i) {
        r = std::max(r, array[i]);
    }
    ++r;
    // long long r = sum(array) / val + 2*val;
    while (r - l > 1) {
        long long A = ammount((l + r) / 2, array);
        if (ammount((l + r) / 2, array) < val) {
            r = (l + r) / 2;
        } else {
            l = (l + r) / 2;
        }
    }
    return l;
}

int main() {
    long long n, k;
    std::cin >> n >> k;
    std::vector<long long> ropes;
    for (long long i = 0; i < n; ++i) {
        ropes.push_back(0);
        std::cin >> ropes[i];
    }
    std::cout << bin_ser_l(k, ropes) << std::endl;
    return 0;
}