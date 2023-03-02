#include <algorithm>
#include <iostream>
#include <vector>
bool cmp(std::pair<int, int> a, std::pair<int, int> b) {
    if (a.first == b.first)
        return a.second < b.second;
    return a.first < b.first;
}
int main() {
    int n;
    std::cin >> n;
    std::vector<std::vector<int>> matrix(n, std::vector<int>(n, 0));
    std::vector<std::pair<int, int>> ans(n * n, {-1, -1});
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            std::cin >> matrix[i][j];
    }
    int index = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (matrix[i][j] == 1) {
                ans[index].first = i;
                ans[index].second = j;
                index++;
                matrix[j][i] = 0;
            }
        }
    }
    sort(ans.begin(), ans.end(), cmp);
    for (size_t i = 0; i < ans.size(); i++) {
        if (ans[i].first > -1)
            std::cout << ans[i].first + 1 << ' ' << ans[i].second + 1 << '\n';
    }
}