#include <bits/stdc++.h>

using namespace std;

int main() {
    int A,B;
    for (A=1;A<=9;A++) {
        cout << "? A " << A << endl;
        bool res; cin >> res;
        if (res) break;
    }
    for (B=1;B<=9;B++) {
        cout << "? B " << B << endl;
        bool res; cin >> res;
        if (res) break;
    }
    cout << "! " << A+B;
}