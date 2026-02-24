#include <bits/stdc++.h>

using namespace std;
using ll=long long;

ll N,K,DP[1<<15][100]={1},R[15],X[51]={1};
string S[15];

ll gcd(ll a,ll b) {
    if (b==0) return a;
    return gcd(b,a%b);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> N;
    for (int i=0;i<N;i++) cin >> S[i];
    cin >> K;

    for (int i=0,r=0;i<N;R[i++]=r,r=0) for (int j=0;j<S[i].size();j++) r=(r*10+(S[i][j]-'0'))%K;
    for (int i=1;i<=50;i++) X[i]=X[i-1]*10%K;

    
    for (int i=0;i<(1<<N);i++) for (int j=0;j<K;j++) {
        if (!DP[i][j]) continue;

        for (int k=0;k<N;k++) {
            if (i&(1<<k)) continue;

            DP[i|(1<<k)][(j*X[S[k].size()]+R[k])%K] += DP[i][j];
        }
    }

    ll ans=DP[(1<<N)-1][0],fac=1;
    for (int i=2;i<=N;i++) fac*=i;
    ll G=gcd(fac,ans);

    cout << DP[(1<<N)-1][0]/G << '/' << fac/G;
}