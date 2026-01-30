#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll N,M,T[100001];

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> N >> M;
    for (int t=0;t<N;t++) {
        int x;cin>>x;
        T[x]=t;
    }

    ll CW=0,CCW=0;
    for (int i=1;i<M;i++) CW+=(T[i]+N-(CW%N))%N;
    for (int i=N;i>=M;i--) CCW+=(T[i]+N-(CCW%N))%N;
    if (CW==CCW) cout << "EQ";
    else cout << (CW<CCW?"CW":"CCW");
}