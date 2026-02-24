#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    int T; cin >> T; while (T--) {
        int N, K; cin >> N >> K;

        priority_queue<ll> PQ;
        for (int i=0;i<N;i++) { int x; cin >> x; PQ.push(x); }
        while ((N++-1)%(K-1)) PQ.push(0);

        ll ans = 0;
        while (PQ.size() > 1) {
            ll sum = 0;
            for (int i=0;i<K&&!PQ.empty();i++) sum += -PQ.top(), PQ.pop();
            ans += sum;
            PQ.push(-sum);
        }
        cout << ans << '\n';
    }
}