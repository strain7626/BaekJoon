#include <bits/stdc++.h>

using namespace std;

const int MAX=1001;

int N,M,K,grd[MAX][MAX],dy[]={-1,1,0,0},dx[]={0,0,-1,1};
bool vis[MAX][MAX];

bool BFS(int _y,int _x) {
    long long sum[2]={0,0};
    
    queue<pair<int,int>> Q;
    Q.push({_y,_x});
    vis[_y][_x]=1;
    sum[(_y+_x)%2]+=grd[_y][_x];
    
    while(!Q.empty()) {
        auto [y,x]=Q.front();Q.pop();
        
        for(int i=0;i<4;i++) {
            int ny=y+dy[i],nx=x+dx[i];
            if(ny<1||ny>N||nx<1||nx>M) continue;
            if(vis[ny][nx]) continue;
            Q.push({ny,nx});
            vis[ny][nx]=1;
            sum[(ny+nx)%2]+=grd[ny][nx];
        }
    }

    cout<<sum[0]<<' '<<sum[1]<<'\n';

    return sum[0]==sum[1];
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    cin>>N>>M>>K;
    for(int i=1;i<=N;i++) for(int j=1;j<=M;j++) cin>>grd[i][j];
    for(int i=1;i<=N;i++) for(int j=1,a;j<=M;j++) cin>>a,grd[i][j]-=a;

    for(int i=0,y,x;i<K;i++) {
        cin>>y>>x;
        if(grd[y][x]==0) vis[y][x]=1;
        else {
            cout<<"No";
            return 0;
        }
    }

    for(int i=1;i<=N;i++) for(int j=1;j<=M;j++) if(!vis[i][j]) if(!BFS(i,j)) {cout<<"No";return 0;}
    cout<<"Yes";
}