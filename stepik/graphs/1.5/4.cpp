#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
void dfs(const int& i, const int& v, const vector<vector<int>>& g,
         vector<int>& used) {
    used[v] = i;
    for (int to : g[v]) {
        if (!used[to]) {
            dfs(i, to, g, used);
        }
    }
}
int main() {
    int n, k;
    cin >> n >> k;
    int counter = 0;
    int index = 0;
    int from = 0, to = 0;
    int color = 2;
    vector<vector<int>> g(n);
    vector<int> used(n);
    for (int i = 1; i < n + 1; i++) {
        for (int j = i + 1; j < n + 1; j++) {
            if ((i + j) % k == 0) {
                int from = i;
                int to = j;
                from--;
                to--;
                g[from].push_back(to);
                g[to].push_back(from);
            }
        }
    }
    for (int i = 0; i < n; i++) {
        if (!used[i]) {
            if (i != 0) {
                dfs(color, i, g, used);
                color++;
            } else
                dfs(1, i, g, used);
        }
    }
    sort(used.begin(), used.end());
    for (int i = 1; i < n; i++) {
        if (used[i] != used[i - 1])
            counter++;
    }
    cout << counter + 1;
}