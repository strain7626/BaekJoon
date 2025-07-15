#include <iostream>
#include <algorithm>
using namespace std;

int N, M, b[200000];

int near(int a) {
    if (a < b[0]) return b[0]-a;
    if (a > b[N-1]) return a-b[N-1];

    int l = 0, r = N-1, m;
    while (l < r) {
        m = (l+r)/2;
        if (a > b[m]) l = m+1;
        else r = m;
    }
    return min(abs(a-b[r-1]),abs(a-b[r]));
}

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    cin >> N >> M;
    for (int i = 0; i < N; i++) cin >> b[i]; sort(b, b+N);

    int P = 0;
    for (int i = 0; i < M; i++) {
        int a, w; cin >> a >> w;
        P = max(P, near(a)*w);
    }
    cout << P;
}
