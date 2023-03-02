#include <iostream>
#include <vector>
int main() {
    int n, k = 0;
    std::cin >> n;
    std::vector<std::vector<int>> matrix(n, std::vector<int>(n, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            std::cin >> matrix[i][j];
        }
    }
    for (int i = 0; i < n; i++) {
        if (matrix[i][i] == 1)
            k++;
    }
    std::cout << k;
    return 0;
}