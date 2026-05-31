#include <bits/stdc++.h>

using namespace std;

string N;
int K;
bool vis[20][1<<10][2];

bool dfs(int idx,int bit,bool big,int L,string &cur) {
    int cnt=bitset<10>(bit).count();

    if(cnt+(L-idx)<K) return 0;
    if(cnt>K) return 0;
    if(idx==L) return cnt==K;

    if(vis[idx][bit][big]) return 0;

    for(int i=idx?0:1;i<=9;i++) {
        if(!big&&'0'+i<N[idx]) continue;
        cur.push_back('0'+i);
        if(dfs(idx+1,bit|(1<<i),big||L>N.size()||'0'+i>N[idx],L,cur)) return 1;
        cur.pop_back();
    }

    vis[idx][bit][big]=1;
    return 0;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    cin>>N>>K;

    string ans;
    for(int L=N.size();L<= 20;L++) if(dfs(0,0,L>N.size(),L,ans="")) break;
    cout<<ans;
}