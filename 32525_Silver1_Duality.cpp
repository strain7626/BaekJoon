#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t;cin>>t;while(t--) {
        int N;cin>>N;
        for(int i=1,x,y;i<=N;i++) cin>>x>>y,cout<<i<<' '<<x+1<<' '<<y+(int)3e8<<'\n';
    }
}