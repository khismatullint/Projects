#include <iostream>
#include <vector>
int main() {
    int n, stock = 0, source = 0;
    std::cin >> n;
    std::vector<std::vector<int>> matrix(n, std::vector<int>(n, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            std::cin >> matrix[i][j];
        }
    }
    for (int i = 0; i < n; i++) {
        int tempi = 0;
        int tempj = 0;
        for (int j = 0; j < n; j++) {
            tempi += matrix[i][j];
            tempj += matrix[j][i];
        }
        if (tempi == 0) {
            stock++;
        }
        if (tempj == 0) {
            source++;
        }
    }
    std::cout << source << ' ' << stock;
    return 0;
}