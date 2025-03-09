#include <bits/stdc++.h>
using namespace std;

int main() {
    int a,b; cin >> a >> b;
    if (a > b) swap(a,b);

    for (int t = a; t > 0; t--) if (!(a%t) && !(b%t)) {
        cout << t << endl;
        break;
    }
    for (int t = b; t <= a*b; t++) if (!(t%a) && !(t%b)) {
        cout << t << endl;
        break;
    }
}