#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int main() {
    int n, m, k = 0;
    cin >> n >> m;
    bool flag = true;
    vector<vector<int>> matrix(n, vector<int>(n, 0));
    for (size_t i = 0; i < m; i++) {
        int from, to;
        cin >> from >> to;
        from--;
        to--;
        matrix[from][to] += 1;
    }
    for (size_t i = 0; i < n; i++) {
        for (size_t j = 0; j < n; j++) {
            if ((matrix[i][j] + matrix[j][i]) >= 2)
                k++;
        }
    }
    cout << k / 2;
}