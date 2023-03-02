#include <iostream>
const int mod = 1e6 + 3;
using namespace std;

int main() {
    int n, s1 = 1, s2 = 1, s = 0, k = 0;
    cin >> n;
    for (int i = 0; i <= n; i++) {
        s1 = s2;
        s2 = s;
        s = (s2 + s1) % mod;
    }
    if (s >= 0) {
        cout << s;
    } else {
        cout << (mod + s);
    }
    return 0;
}