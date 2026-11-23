#include <bits/stdc++.h>
#define all(X) X.begin(),X.end()

using namespace std;

const int MX=2e5+1;

int N,M,A[MX],B[MX];

void solve() {
    cin>>N>>M;
    for(int i=1;i<=N;i++) cin>>A[i];
    for(int i=1;i<=M;i++) cin>>B[i];

    vector<int> tp(M+1);
    vector<vector<int>> cyc={{}};
    
    function<void(int)> dfs=[&](int now) {
        if(tp[now]) return;
        tp[now]=cyc.size()-1;

        cyc.back().push_back(now);
        dfs(B[now]);
    };

    for(int i=1;i<=M;i++) {
        if(!tp[i]) dfs(i);
        cyc.emplace_back();
        sort(all(cyc.back()));
    }
    
    int cur=cyc[tp[A[1]]][0];
    for(int i=2;i<=N;i++) {
        auto nxt=lower_bound(all(cyc[tp[A[i]]]),cur);
        
        if(nxt==cyc[tp[A[i]]].end()) {cout<<"NO\n"; return;}
        cur=*nxt;
    }
    cout<<"YES\n";
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int T; cin>>T; while(T--) solve();
}