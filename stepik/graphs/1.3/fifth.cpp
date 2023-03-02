#include <iostream>
#include <vector>
int main() {
    int n, m, totalsum = 0;
    std::cin >> n >> m;
    std::vector<std::pair<int, int>> array(m);
    for (int i = 0; i < m; i++) {
        int a, b;
        std::cin >> a >> b;
        array[i] = std::pair<int, int>(a, b);
    }
    int k = 0;
    std::cin >> k;
    k--;
    int first, second;
    first = array[k].first;
    second = array[k].second;
    for (int i = 0; i < m; i++) {
        if ((array[i].first == first) || (array[i].first == second))
            totalsum++;
        if ((array[i].second == second) || (array[i].second == first))
            totalsum++;
    }
    std::cout << totalsum - 2;
}