#include <algorithm>;
#include <iostream>;
#include <vector>;
int main() {
    int n, k;
    std::cin >> n;
    std::vector<int> arrayn(n);
    for (int i = 0; i < n; i++) {
        std::cin >> arrayn[i];
    }
    std::cin >> k;
    arrayn.push_back(-1000000001);
    std::vector<int> ans(k);
    sort(arrayn.begin(), arrayn.end());
    int left, right, l, r, middle;
    for (int i = 0; i < k; i++) {
        std::cin >> l >> r;
        left = 0;
        right = n + 1;
        while (right - left > 1) {
            middle = (left + right) / 2;
            if (arrayn[middle] < l)
                left = middle;
            else
                right = middle;
        }
        l = left;
        left = 0, right = n + 1;
        while (right - left > 1) {
            middle = (right + left) / 2;
            if (arrayn[middle] <= r)
                left = middle;
            else
                right = middle;
        }
        r = left;
        ans[i] = r - l;
    }
    for (int i = 0; i < k; i++)
        std::cout << ans[i] << " ";
}