#include <iostream>
#include <vector>
int main() {
    int n = 0, m = 0, k = 0, r = 0;
    std::cin >> m >> n >> k;
    m++;
    n++;
    k++;
    std::vector<std::vector<std::vector<long long>>> p(
        m,
        std::vector<std::vector<long long>>(n, std::vector<long long>(k, 0)));
    for (int i = 1; i < m; i++) {
        for (int j = 1; j < n; j++) {
            for (int q = 1; q < k; q++) {
                std::cin >> p[i][j][q];
                p[i][j][q] += p[i - 1][j][q] + p[i][j - 1][q] + p[i][j][q - 1] +
                              p[i - 1][j - 1][q - 1] - p[i][j - 1][q - 1] -
                              p[i - 1][j][q - 1] - p[i - 1][j - 1][q];
            }
        }
    }
    std::cin >> r;
    int lx = 0, ly = 0, lz = 0, rx = 0, ry = 0, rz = 0;
    std::vector<long long> res(r);
    for (int i = 0; i < r; i++) {
        std::cin >> lx >> ly >> lz >> rx >> ry >> rz;
        res[i] = p[rx][ry][rz] - p[rx][ly - 1][rz] - p[lx - 1][ry][rz] -
                 p[rx][ry][lz - 1] - p[lx - 1][ly - 1][lz - 1] +
                 p[lx - 1][ly - 1][rz] + p[rx][ly - 1][lz - 1] +
                 p[lx - 1][ry][lz - 1];
    }
    for (int i = 0; i < r; i++)
        std::cout << res[i] << ' ';

    return 0;
}