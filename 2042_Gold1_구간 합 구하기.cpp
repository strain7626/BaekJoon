#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int N, M, K, a, b;
ll c;

vector<ll> A,T;

ll make(int n = 1, int s = 0, int e = N-1) {
    if (s==e) return T[n] = A[s];
    return T[n] = make(n*2, s, (s+e)/2) + make(n*2+1, (s+e)/2+1, e);
}

ll update(int idx, ll val, int n = 1, int s = 0, int e = N-1) {
    if (idx<s||e<idx) return T[n];
    if (s==e&&s==idx) return T[n] = val;
    return T[n] = update(idx, val, n*2, s, (s+e)/2) + update(idx, val, n*2+1, (s+e)/2+1, e);
}

ll sum(int left, int right, int n = 1, int s = 0, int e = N-1) {
    if (left<=s&&e<=right) return T[n];
    if (e<left||right<s) return 0;
    return sum(left, right, n*2, s, (s+e)/2) + sum(left, right, n*2+1, (s+e)/2+1, e);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> N >> M >> K;
    A.resize(N); T.resize(N*4);
    for (ll& i : A) cin >> i;
    make();

    for (int i = 0; i < M+K; i++) {
        cin >> a >> b >> c;
        if (a==1) { update(b-1, c); A[b-1] = c; }
        else cout << sum(b-1, c-1) << '\n';
    }
}