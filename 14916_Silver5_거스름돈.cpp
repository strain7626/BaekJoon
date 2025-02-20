#include <iostream>
using namespace std;

int main() {
    int n; cin >> n;

    if (n == 1 || n == 3) cout << -1;
    else if (n%5 == 0) cout << n/5;
    else if (n%5 == 1) cout << (n/5)-1 + 3;
    else if (n%5 == 2) cout << (n/5) + 1;
    else if (n%5 == 3) cout << (n/5)-1 + 4;
    else if (n%5 == 4) cout << (n/5) + 2;
}