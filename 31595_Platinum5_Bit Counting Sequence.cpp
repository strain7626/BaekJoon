#include <bits/stdc++.h>

using namespace std;

void solve() {
    int N,A[500000];
    cin>>N;
    for(int i=0;i<N;i++) cin>>A[i];

    long long now=(1LL<<A[N-1])-1;
    for(int i=N-2;i>=0;i--) {
        int cnt=bitset<63>(--now).count();
        if(cnt==A[i]) continue;
        now<<=(A[i]-cnt);
        now+=((1LL<<(A[i]-cnt))-1);
    }

    long long ans=now;
    for(int i=0;i<N;i++) {
        if(bitset<63>(now++).count()==A[i]) continue;
        cout<<-1<<'\n';
        return;
    }
    cout<<ans<<'\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t;cin>>t;while(t--) solve();
}