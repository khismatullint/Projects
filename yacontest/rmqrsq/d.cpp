#include <iostream>
#include <vector>
int main() {
    int n = 0, m = 0;
    std::cin >> n >> m;
    std::vector<std::vector<int>> p(n, std::vector<int>(m));
    std::vector<std::vector<int>> a(n + 1, std::vector<int>(m + 1));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            std::cin >> p[i][j];
        }
    }
    int max = 0;
    int it = 0, jt = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (p[i][j] == 1) {
                a[i + 1][j + 1] =
                    std::min(a[i][j + 1], std::min(a[i][j], a[i + 1][j])) + 1;
                if (a[i + 1][j + 1] > max) {
                    max = a[i + 1][j + 1];
                    it = i + 1;
                    jt = j + 1;
                }
            }
        }
    }
    std::cout << max << std::endl;
    std::cout << it - max + 1 << ' ' << jt - max + 1;

    return 0;
}