#include <bits/stdc++.h>

using namespace std;

int main() {
    int A,B;
    for (A=1;A<=10000;A++) {
        if (A==5678) continue;
        if (A==5679) continue;
        if (A==5680) continue;
        cout << "? A " << A << endl;
        bool res; cin >> res;
        if (res) break;
    }
    for (B=1;B<=10000;B++) {
        cout << "? B " << B << endl;
        bool res; cin >> res;
        if (res) break;
    }
    cout << "! " << A+B;
}