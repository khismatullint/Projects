#include <algorithm>
#include <iostream>
#include <vector>
int main() {
    int n, m, sum = 1;
    std::cin >> n >> m;
    std::vector<int> array(n, 0);
    for (int i = 0; i < m; i++) {
        int from, to;
        std::cin >> from >> to;
        from--;
        to--;
        array[from]++;
        array[to]++;
    }
    sort(array.begin(), array.end());
    for (size_t i = 1; i < n; i++) {
        if (array[i] != array[i - 1]) {
            sum++;
        }
    }
    std::cout << sum;
}