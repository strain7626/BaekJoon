#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll N,S, szA,szB;
int A[20], B[20];
map<ll,ll> setA, setB;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    cin >> N >> S; szA=N/2,szB=N-szA;
    for (int i=0;i<szA;i++) cin >> A[i];
    for (int i=0;i<szB;i++) cin >> B[i];

    for (int i=1;i<(1<<(szA));i++) {
        ll now=i,sum=0;
        for (int j=0;j<szA;j++) {
            if (now%2) sum+=A[j];
            now/=2;
        }
        setA[sum]++;
    }
    for (int i=1;i<(1<<(szB));i++) {
        ll now=i,sum=0;
        for (int j=0;j<szB;j++) {
            if (now%2) sum+=B[j];
            now/=2;
        }
        setB[sum]++;
    }

    ll ans=setA[S]+setB[S];
    for (auto [i,cnt]:setA) ans+=cnt*setB[S-i];

    cout << ans;
}