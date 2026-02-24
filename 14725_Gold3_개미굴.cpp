#include <bits/stdc++.h>

using namespace std;

int N,K;
struct Node{map<string,Node> C;}B;

void DFS(Node n,string p) {
    for(auto &[a,b]:n.C) cout<<p<<a<<'\n',DFS(b,p+"--");
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin>>N;
    while(N--) {
        cin>>K;
        string S;
        Node *c=&B;
        for(int i=0;i<K;i++) cin>>S,c=&c->C[S];
    }
    DFS(B,"");
}