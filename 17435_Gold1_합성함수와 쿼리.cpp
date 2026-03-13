#include <bits/stdc++.h>

using namespace std;

int m,Q,n,x,st[200001][20];

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    cin>>m;
    for(int i=1;i<=m;i++) cin>>st[i][0];

    for(int k=1;k<=20;k++) for(int i=1;i<=m;i++) st[i][k]=st[st[i][k-1]][k-1];

    cin>>Q;
    while(Q--) {
        cin>>n>>x;
        for(int k=0;k<20;k++) {
            if(n&1) x=st[x][k];
            n>>=1;
            if(!n) break;
        }
        cout<<x<<'\n';
    }
}