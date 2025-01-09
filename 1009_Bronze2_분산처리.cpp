#include <iostream>

using namespace std;

int solve() {
    int a,b;
    cin >> a >> b;
    int t = a;
    t %=10;
    while (--b) {
        t *= a;
        t %= 10;
    }
    if (t) return t;
    else return 10;
}

int main() {
    int t;
    cin >> t;
    while(t--) cout << solve() << endl;
    return 0;
}