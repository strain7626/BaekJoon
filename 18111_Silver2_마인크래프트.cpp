#include <bits/stdc++.h>

using namespace std;

int N, M, B, H[500][500], ans = 1e9, ans_h;

int main() {
    cin.tie(0);ios_base::sync_with_stdio(0);

    cin >> N >> M >> B;
    for (int n = 0; n < N; n++) for (int m = 0; m < M; m++) cin >> H[n][m];

    for (int h = 0; h <= 256; h++) {
        int t = 0, b = B, d;
        for (int n = 0; n < N; n++) for (int m = 0; m < M; m++) {
            d = H[n][m]-h;
            b += d;
            t += (d < 0 ? -d : d*2);
        }
        if (b < 0 || t > ans) continue;
        ans = t; ans_h = h;
    }

    cout << ans << ' ' << ans_h;
}