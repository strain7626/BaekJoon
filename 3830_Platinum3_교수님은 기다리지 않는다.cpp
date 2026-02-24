#include <bits/stdc++.h>

using namespace std;

int N,M,uni[100001],d[100001];

void find(int n) {
    if(uni[n]==n) return;
    find(uni[n]);
    d[n]+=d[uni[n]];
    uni[n]=uni[uni[n]];
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    while(1) {
        cin>>N>>M;
        if(!N&!M) break;
        for(int i=1;i<=N;i++) uni[i]=i,d[i]=0;

        while(M--) {
            char x;int a,b,w;cin>>x>>a>>b;
            find(a);
            find(b);
            if(x=='!') {
                cin>>w;
                if(uni[a]!=uni[b]) {
                    d[uni[a]]=d[b]-d[a]+w;
                    uni[uni[a]]=uni[b];
                }
            } else {
                if(uni[a]==uni[b]) cout<<d[a]-d[b]<<'\n';
                else cout<<"UNKNOWN\n";
            }
        }
    }
}