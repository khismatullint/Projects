#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
vector<vector<int>> g;
vector<int> used;
void dfs(int v) {
    used[v] = 1;
    for (int to : g[v]) {
        if (!used[to]) {
            dfs(to);
        }
    }
}
int main() {
    int n, m, k = 0;
    cin >> n >> m;
    g = vector<vector<int>>(n);
    used = vector<int>(n);
    for (int i = 0; i < m; i++) {
        int from = 0, to = 0;
        cin >> from >> to;
        from--;
        to--;
        g[from].push_back(to);
        g[to].push_back(from);
    }
    dfs(0);
    for (int i = 0; i < n; i++) {
        if (used[i] == 1) {
            k++;
        }
    }
    cout << k << '\n';
    for (int i = 0; i < n; i++) {
        if (used[i] == 1) {
            cout << i + 1 << ' ';
        }
    }
}