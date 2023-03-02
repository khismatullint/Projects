#include <iostream>
#include <vector>
int main() {
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for (size_t i = 0; i < n; i++) {
        std::cin >> a[i];
    }
    int ans = a[0], ans_l = 0, ans_r = 0, sum = 0, minus_pos = -1;
    for (int r = 0; r < n; ++r) {
        sum += a[r];

        if (sum > ans) {
            ans = sum;
            ans_l = minus_pos + 1;
            ans_r = r;
        }

        if (sum < 0) {
            sum = 0;
            minus_pos = r;
        }
    }
    std::cout << ans_l + 1 << " " << ans_r + 1 << " " << ans << std::endl;
}