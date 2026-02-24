#include <bits/stdc++.h>

using namespace std;

int h,w,ans,dy[]={-1,1,0,0},dx[]={0,0,-1,1};
vector<vector<char>> grd;
vector<vector<bool>> vis;
set<char> key;string S;
queue<pair<int,int>> Q;
bool flag;

void check(int y,int x) {
    if(y<0||y>=h||x<0||x>=w) return;
    
    char &c=grd[y][x];
    if(c=='*') return;
    if(vis[y][x]) return;
    if('A'<=c&&c<='Z') if(key.count(c-'A'+'a')) c='.'; else return;

    if('a'<=c&&c<='z') key.insert(c),c='.',flag=1;
    if(c=='$') c='.',ans++;
    vis[y][x]=1;
    Q.push({y,x});
}

bool BFS() {
    flag=0;
    vis.assign(h,vector<bool>(w));

    for(int i=0;i<h;i++) check(i,0),check(i,w-1);
    for(int i=0;i<w;i++) check(0,i),check(h-1,i);

    while(!Q.empty()) {
        auto [y,x]=Q.front();Q.pop();
        for(int i=0;i<4;i++) check(y+dy[i],x+dx[i]);
    }

    return flag;
}

void solve() {
    cin>>h>>w;
    grd.assign(h,vector<char>(w));
    for(auto &i:grd) for(char &j:i) cin>>j;
    cin>>S;key.clear();for(char s:S) key.insert(s);
    
    ans=0;
    while(BFS());
    cout<<ans<<'\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int T;cin>>T;while(T--) solve();
}