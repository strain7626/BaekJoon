#include <bits/stdc++.h>

using namespace std;

int N,ans;
string P;
vector<pair<int,char>> adj[500001];
int pi[500000],aut[500000][26];

void DFS(int u,int cnt) {
    if(cnt==P.size()) ans++,cnt=pi[cnt-1];
    for(auto& [v,c]:adj[u]) DFS(v,aut[cnt][c-'a']);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin>>N;
    for(int i=1;i<N;i++) {
        int u,v;char c;
        cin>>u>>v>>c;
        adj[u].push_back({v,c});
    }
    cin>>P;

    for(int i=1,cnt=0;i<P.size();i++) {
        while(cnt&&P[cnt]!=P[i]) cnt=pi[cnt-1];
        if(P[cnt]==P[i]) cnt++;
        pi[i]=cnt;
    }
    for(int i=0;i<P.size();i++) for(int c=0;c<26;c++) {
        if(c+'a'==P[i]) aut[i][c]=i+1;
        else aut[i][c]=(i?aut[pi[i-1]][c]:0);
    }

    DFS(1,0);
    cout<<ans;
}