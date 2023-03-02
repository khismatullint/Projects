#include <iostream>;
#include <stack>
#include <vector>
using namespace std;
int k = 0;
void dfs(const int& i, const int& v, const vector<vector<int>>& g,
         vector<int>& used) {
    std::stack<int> stack;
    stack.push(v);
    while (!stack.empty()) {
        int from = stack.top();
        stack.pop();
        used[from] = i;
        for (int to : g[from]) {
            if (!used[to]) {
                stack.push(to);
            }
        }
    }
}
int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    int n, m, index = 0;
    cin >> n >> m;
    int color = 2;
    vector<vector<int>> g(n);
    vector<int> used(n, 0);
    for (int i = 0; i < m; i++) {
        int from = 0, to = 0;
        cin >> from >> to;
        from--;
        to--;
        g[from].push_back(to);
        g[to].push_back(from);
    }
    for (int i = 0; i < n; i++) {
        if (used[i] == 0) {
            if (i != 0) {
                dfs(color, i, g, used);
                color++;
            } else
                dfs(1, i, g, used);
        }
    }
    vector<int> usedi(n, 0);
    for (int i = 0; i < n; i++) {
        usedi[i] = i + 1;
    }
    for (int i = 0; i < n; i++) {
        bool flag = true;
        for (int j = 0; j < n - (i + 1); j++) {
            if (used[j] > used[j + 1]) {
                flag = false;
                swap(used[j], used[j + 1]);
                swap(usedi[j], usedi[j + 1]);
            }
        }
        if (flag) {
            break;
        }
    }
    for (int i = 1; i < n; i++) {
        if (used[i] != used[i - 1])
            k++;
    }
    cout << k + 1;
    cout << '\n';
    vector<int> digitals(k + 1, 0);
    for (int i = 1; i < n; i++) {
        if (used[i] == used[i - 1]) {
            digitals[index]++;
        } else
            index++;
    }
    index = 0;
    int indr = 0;
    int indl = 0;
    for (int i = 1; i < n; i++) {
        if (used[i] != used[i - 1]) {
            indr = i;
            cout << digitals[index] + 1 << '\n';
            for (int j = indl; j < indr; j++) {
                cout << usedi[j] << ' ';
            }
            indl = indr;
            index++;
            cout << '\n';
        }
    }
    cout << digitals[index] + 1 << '\n';
    for (int i = indl; i < n; i++) {
        cout << usedi[i] << ' ';
    }
}