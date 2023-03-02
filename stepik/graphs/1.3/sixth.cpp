#include <iostream>
#include <vector>
int main() {
    int n;
    std::cin >> n;
    std::vector<std::vector<int>> matrix(n, std::vector<int>(n, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            std::cin >> matrix[i][j];
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (matrix[i][j] == 1)
                matrix[i][j] = 0;
            else if (i != j)
                matrix[i][j] = 1;
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            std::cout << matrix[i][j] << ' ';
        std::cout << "\n";
    }
}