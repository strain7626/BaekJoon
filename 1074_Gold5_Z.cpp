#include <iostream>

using namespace std;

int N, r, c;

int reculsion(int _N, int _r, int _c) {
    if (_N-- == 0) return 0;
    
    int t = 1 << _N; 
    return t*t*(2*(_r/t) + _c/t) + reculsion(_N, _r%t, _c%t);
}

int main() {
    cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(0);

    cin >> N >> r >> c;

    cout << reculsion(N, r, c);
}