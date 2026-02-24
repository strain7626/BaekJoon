#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pll = pair<ll,ll>;

ll n;
vector<pll> U,D;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    cin >> n;
    for (int i=0;i<n;i++) {
        ll a,b;cin>>a>>b;
        if (a>b) D.push_back({a,b});
        else U.push_back({a,b});
    }

    sort(U.begin(),U.end());
    sort(D.begin(),D.end(),[](pll a,pll b){return a.second>b.second;});
    U.insert(U.end(),D.begin(),D.end());

    ll ans=0,R=0;
    for (auto [a,b]:U) {
        if (R<a) ans+=a-R,R=a;
        R+=b-a;
    }
    cout << ans;
}