#include <iostream>

using namespace std;
typedef long long ll;

ll N,K, MOD = 1000000007LL;

int main() {
    cin >> N >> K;
    ll A=1,B=1;
    
    for (ll i = 2; i <= N; i++) A = A*i%MOD;
    for (ll i = 2; i <= K; i++) B = B*i%MOD;
    for (ll i = 2; i <= N-K; i++) B = B*i%MOD;

    ll t = MOD-2;
    ll r = 1;
    while (t) {
        if (t%2) r = r*B%MOD;
        B = B*B%MOD;
        t/=2;
    }

    cout << A*r%MOD;
    return 0;
}