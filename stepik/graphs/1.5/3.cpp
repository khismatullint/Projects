#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
void dfs(int v, vector<int>& used, vector<vector<int>>& g) {
    used[v] = 1;
    for (int to : g[v]) {
        if (!used[to]) {
            dfs(to, used, g);
        }
    }
}
int main() {
    int n, m, index = 0;
    cin >> n >> m;
    vector<vector<int>> g(n);
    vector<int> used(n);
    for (int i = 0; i < m; i++) {
        int from = 0, to = 0;
        cin >> from >> to;
        from--;
        to--;
        g[to].push_back(from);
    }
    dfs(0, used, g);
    for (int i = index; i < n; i++) {
        if (used[i] == 1) {
            cout << i + 1 << ' ';
        }
    }
}