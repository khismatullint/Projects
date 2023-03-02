#include <iostream>
#include <string>
using namespace std;
int main() {
    int n;
    cin >> n;
    string str = "FBFFBFFBFBFFBFFBFBFFBFFB";
    while (n > 0) {
        int temp;
        cin >> temp;
        string FB;
        cin >> FB;
        if (str.find(FB) != -1)
            cout << "YES\n";
        else
            cout << "NO\n";
        n--;
    }
}