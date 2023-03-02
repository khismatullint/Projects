#include <iostream>;
#include <vector>;
int main() {
    int n, k;
    std::cin >> n >> k;
    std::vector<int> arrayn(n);
    std::vector<int> arrayk(k);
    int left = -1, right = n - 1, middle;
    for (int i = 0; i < n; i++) {
        std::cin >> arrayn[i];
    }
    for (int i = 0; i < k; i++) {
        std::cin >> arrayk[i];
        while (right - left > 1) {
            middle = (right + left) / 2;
            if (arrayn[middle] >= arrayk[i])
                right = middle;
            else
                left = middle;
        }
        if (arrayn[right] == arrayk[i])
            std::cout << "YES"
                      << "\n";
        else
            std::cout << "NO"
                      << "\n";
        left = -1, right = n - 1;
    }
}