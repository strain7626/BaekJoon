#include <bits/stdc++.h>
#define INF 1e9
using namespace std;

using pos = tuple<int,int,int,int>;

int N,M,T, vis[500][500][4], dy[]={-1,0,1,0},dx[]={0,-1,0,1};
char G[500][500];

int BFS(pos S) {
    priority_queue<pos,vector<pos>,greater<>> PQ;
    PQ.push(S);
    
    while (!PQ.empty()) {
        auto [t,y,x,d] = PQ.top(); PQ.pop();
        if (G[y][x]=='S') return t;
        if (G[y][x]=='T') {
            int nd=(d+1)%4, ny=y+dy[nd], nx=x+dx[nd];

            if (ny<0||ny>=N||nx<0||nx>=M) continue;
            if (t >= vis[ny][nx][nd]) continue;
            
            vis[ny][nx][nd] = t;
            PQ.push({t,ny,nx,nd});
            continue;
        }
        
        if (t+T < vis[y][x][(d+1)%4]) {
            vis[y][x][(d+1)%4] = t+T;
            PQ.push({t+T,y,x,(d+1)%4});
        }

        for (int td : {(d+1)%4,(d+3)%4}) {
            int ny = y+dy[td], nx = x+dx[td];
            
            if (ny<0||ny>=N||nx<0||nx>=M) continue;
            if (t+1 >= vis[ny][nx][d]) continue;
            
            vis[ny][nx][d] = t+1;
            PQ.push({t+1,ny,nx,d});
        }
    }

    return -1;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    pos S;
    cin >> N >> M >> T;
    for (int i=0;i<N;i++) for (int j=0;j<M;j++) {
        for (int k=0;k<4;k++) vis[i][j][k]=INF;

        char x; cin >> x;
        if ('0'<=x&&x<='3') S={0,i,j,x-'0'},vis[i][j][x-'0']=0,x='.';
        G[i][j] = x;
    }

    cout << BFS(S);
}