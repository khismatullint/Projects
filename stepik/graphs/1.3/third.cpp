#include <iostream>
#include <vector>
int main() {
    int n, odd = 0, nodd = 0;
    std::cin >> n;
    std::vector<std::vector<int>> matrix(n, std::vector<int>(n, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            std::cin >> matrix[i][j];
        }
    }
    for (int i = 0; i < n; i++) {
        int sum = 0;
        for (int j = 0; j < n; j++) {
            if (matrix[i][j] == 1)
                sum++;
            if (i == j)
                if (matrix[i][j] == 1)
                    sum++;
        }
        if (sum % 2 == 0)
            nodd++;
        else
            odd++;
    }
    std::cout << nodd << ' ' << odd;
    return 0;
}