#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int T,N,K;cin>>T;while(T--) {
        cin>>N>>K;
        if(N>1&&K!=2) {cout<<-1<<'\n';continue;}
        for(int i=2;i<=N;i++) cout<<i<<' ';cout<<1<<'\n';
    }
}