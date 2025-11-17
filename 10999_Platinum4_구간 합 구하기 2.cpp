#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
using ll = long long;

int N, M, K;
vector<ll> A, T, L;

ll make(int n, int s, int e) {
    if (s == e) return T[n] = A[s];
    return T[n] = make(n*2, s, (s+e)/2) + make(n*2+1, (s+e)/2+1, e);
}

void propagate(int n, int s, int e) {
    if (!L[n]) return;
    T[n] += (e-s+1) * L[n];
    if (s != e) { L[n*2] += L[n]; L[n*2+1] += L[n]; }
    L[n] = 0;
}

ll update(int n, int s, int e, int l, int r, ll diff) {
    propagate(n, s, e);
    if (e<l||r<s) return T[n];
    if (l<=s&&e<=r) { L[n] += diff; propagate(n, s, e); return T[n]; }
    return T[n] = update(n*2, s, (s+e)/2, l, r, diff) + update(n*2+1, (s+e)/2+1, e, l, r, diff);
}

ll query(int n, int s, int e, int l, int r) {
    propagate(n, s, e);
    if (e<l||r<s) return 0;
    if (l<=s&&e<=r) return T[n];
    return query(n*2, s, (s+e)/2, l, r) + query(n*2+1, (s+e)/2+1, e, l, r);
}

int main() {
    cout.tie(0);ios_base::sync_with_stdio(0);
    
    cin >> N >> M >> K; A.resize(N+1);
    for (int i = 1; i <= N; i++) cin >> A[i];
    
    int tmp = 1 << ((int)ceil(log2(N))+1);
    T.resize(tmp); L.resize(tmp);
    make(1, 1, N);

    M += K;
    int a, b, c; ll d;
    while (M--) {
        cin >> a;
        if (a == 1) {
            cin >> b >> c >> d;
            update(1, 1, N, b, c, d);
        } else {
            cin >> b >> c;
            cout << query(1, 1, N, b, c) << '\n';
        }
        // for (ll& a : T) cout << a << ' '; cout << '\n';
        // for (ll& a : L) cout << a << ' '; cout << '\n';
    }   
}