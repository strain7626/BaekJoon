#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int T,N,S,E;cin>>T;while(T--) {
        cin>>N>>S>>E;
        cout<<(N!=2&&abs(S-E)==1?1:2-(S==1||S==N?E==1||E==N?2:1:0))<<'\n';
    }
}