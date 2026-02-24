#include <bits/stdc++.h>

using namespace std;
queue<tuple<int,int,int>> Q;

int N,M,K,sx,sy,ex,ey,vis[1001][1001],dx[]={-1,1,0,0},dy[]={0,0,-1,1};
char grd[1001][1001];

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    cin>>N>>M>>K;
    for(int i=1;i<=N;i++) for(int j=1;j<=M;j++) cin>>grd[i][j],vis[i][j]=1e9;
    cin>>sx>>sy>>ex>>ey;

    Q.push({vis[sx][sy]=0,sx,sy});

    while(!Q.empty()) {
        auto [c,x,y]=Q.front();Q.pop();
        if(x==ex&&y==ey) continue;

        for(int i=0;i<4;i++) for(int k=1;k<=K;k++) {
            int nx=x+k*dx[i],ny=y+k*dy[i];

            if(nx<1||nx>N||ny<1||ny>M) break;
            if(grd[nx][ny]=='#') break;
            if(vis[nx][ny]<c+1) break;
            if(vis[nx][ny]==c+1) continue;

            Q.push({vis[nx][ny]=c+1,nx,ny});
        }
    }

    cout<<(vis[ex][ey]==1e9?-1:vis[ex][ey]);
}