#include <iostream>
#include <vector>
std::vector<int> used;
std::vector<std::vector<int>> g;
std::vector<int> p;
void dfs(int v, int i) {
    used[v] = i;
    for (int to : g[v]) {
        if (used[to] == 0) {
            dfs(to, i);
        }
    }
}
int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    int n = 0, m = 0;
    std::cin >> n >> m;
    if (m == n - 1) {
        g = std::vector<std::vector<int>>(n);
        used = std::vector<int>(n, 0);
        p = std::vector<int>(n, -1);
        for (size_t i = 0; i < m; i++) {
            int from = 0, to = 0;
            std::cin >> from >> to;
            from--;
            to--;
            g[from].push_back(to);
            g[to].push_back(from);
        };

        int k = 0;
        for (int i = 0; i < n; i++) {
            if (used[i] == 0) {
                k++;
                dfs(i, k);
            }
        }

        if (k > 1) {
            std::cout << "NO";
        } else {
            std::cout << "YES";
        }
        std::cout << std::endl;
        return 0;
    }
    std::cout << "NO" << std::endl;
}