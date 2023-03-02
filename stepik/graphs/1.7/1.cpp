#include <algorithm>;
#include <iostream>;
#include <vector>;
using namespace std;
int cycle_start = -1;
int cycle_end = -1;
vector<int> p;
vector<vector<int>> g;
vector<int> used;
bool dfs(int& v) {
    used[v] = 1;
    for (int to : g[v]) {
        if (used[to] == 0) {
            p[to] = v;
            if (dfs(to)) {
                return true;
            }
        } else if (used[to] == 1) {
            cycle_start = to;
            cycle_end = v;
            return true;
        }
    }
    used[v] = 2;
    return false;
}
int main() {
    int n;
    cin >> n;
    g = vector<vector<int>>(n);
    p = vector<int>(n, -1);
    used = vector<int>(n, 0);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int mark;
            cin >> mark;
            if (mark == 1) {
                g[i].push_back(j);
            }
        }
    }
    for (int i = 0; i < n; i++) {
        if (dfs(i))
            break;
    }
    if (cycle_start == -1) {
        cout << 0;
    } else
        cout << 1;
}