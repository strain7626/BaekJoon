#include <bits/stdc++.h>

using namespace std;

int N,adj[1000][1000],ptr[1000];

void DFS(int now) {
    for(int &nxt=ptr[now];nxt<N;) { 
        if(!adj[now][nxt]) {
            nxt++;
            continue;
        }
        adj[now][nxt]--;
        adj[nxt][now]--;
        DFS(nxt);
    }
    cout<<now+1<<' ';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    cin>>N;
    for(int i=0;i<N;i++) for(int j=0;j<N;j++) cin>>adj[i][j];
    
    for(int i=0;i<N;i++) {
        int sum=0;
        for(int j=0;j<N;j++) sum+=adj[i][j];
        if(sum%2) {
            cout<<-1;
            exit(0);
        }
    }

    DFS(0);
}