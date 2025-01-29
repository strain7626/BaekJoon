#include <iostream>
#define endl "\n"
using namespace std;

int main() {
    int a = 0;
    for (int i=0;i<8;i++) {
        int t; cin >> t;
        a = a*10+t;
    }
    if (a == 12345678) cout << "ascending";
    else if (a == 87654321) cout << "descending";
    else cout << "mixed";
}