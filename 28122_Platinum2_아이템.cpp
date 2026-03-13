#include <bits/stdc++.h>

using namespace std;
using ll = long long;

struct Node{
    int cnt=0;
    Node* chd[2]={nullptr,nullptr};

    ~Node(){if(chd[0]) delete chd[0]; if(chd[1]) delete chd[1];}

    void insert (int bit,ll n) {
        cnt++;
        if(bit==60) return;

        if(!chd[n&1]) chd[n&1]=new Node;
        chd[n&1]->insert(bit+1,n>>1);
    }
};

int ans=0;
void solve(int bit,int cur,Node &n) {
    if(bit==60) {
        ans=max(ans,cur+n.cnt);
        return;
    }

    if(n.chd[0]) solve(bit+1,min(bit,cur+n.cnt-n.chd[0]->cnt),*n.chd[0]);
    if(n.chd[1]) solve(bit+1,min(bit,cur+n.cnt-n.chd[1]->cnt),*n.chd[1]);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    Node trie;
    int N;cin>>N;
    for(int i=0;i<N;i++) {
        ll X;cin>>X;
        trie.insert(0,X);
    }
    solve(0,0,trie);
    cout<<ans;
}