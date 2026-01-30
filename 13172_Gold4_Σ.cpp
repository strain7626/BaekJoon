#include <bits/stdc++.h>
#define MOD 1'000'000'007

using ll = long long;
using namespace std;

ll M, N, S;

ll mod_rev(ll x) {
    ll y = MOD-2;

    ll res = 1;
    while (y > 0) {
        if (y % 2) res = (res*x)%MOD;
        x = (x*x)%MOD;

        y /= 2;
    }
    return res;
}

ll mod_div(ll a, ll b) {
    ll r_b = mod_rev(b);
    return (a*r_b)%MOD;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> M;
    
    ll ans = 0;
    while (M--) {
        cin >> N >> S;
        ans = (ans+mod_div(S, N))%MOD;
    }
    cout << ans;
}