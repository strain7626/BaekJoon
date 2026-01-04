#include <bits/stdc++.h>

using namespace std;

int N, cnt2 = 0, cnt5 = 0;

void cnt(int _N) {
    while (!(_N%2)) {
        _N/=2; cnt2++;
    }
    while (!(_N%5)) {
        _N/=5; cnt5++;
    }
}

int main() {
    cin >> N;
    for (int i = 1; i <= N; i++) cnt(i);
    cout << min(cnt2, cnt5);
}