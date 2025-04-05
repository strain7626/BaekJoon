#include <bits/stdc++.h>
using namespace std;

int N, work[366], h, w, ans;

int main() {
    cin >> N;
    while (N--) {
        int S, E; cin >> S >> E;
        for (int i = S; i <= E; i++) work[i]++;
    }

    for (int i = 1; i <= 365; i++) {
        if (!work[i]) {
            ans += h*w;
            h = w = 0;
            continue;
        }
        h = max(work[i], h);
        w++;
    }

    cout << ans+h*w;
}