#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int main() {
    int n, m, sum = 0;
    cin >> n >> m;
    vector<pair<int, int>> edges(m);
    for (size_t i = 0; i < m; i++) {
        int from, to;
        cin >> from >> to;
        edges[i].first = from;
        edges[i].second = to;
    }
    int k = 0;
    cin >> k;
    for (size_t i = 0; i < m; i++) {
        if ((edges[i].first == k) || (edges[i].second == k))
            sum++;
    }
    cout << sum;
}