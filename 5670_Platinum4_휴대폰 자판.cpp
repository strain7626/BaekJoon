#include <bits/stdc++.h>

using namespace std;

struct Node {
    int cnt;
    bool end;
    map<char,Node*> chd;
    
    Node():cnt(0),end(0){}
    ~Node(){for(auto &[a,b]:chd) delete b;}

    void insert(string S,int idx) {
        if(S.size()==idx) {end=1;return;}cnt++;
        if(!chd.count(S[idx])) chd[S[idx]]=new Node;
        chd[S[idx]]->insert(S,idx+1);
    }
};

int solve(Node &n){
    int res=0;
    if(n.end||n.chd.size()>1) res+=n.cnt;
    for(auto &[a,b]:n.chd) res+=solve(*b);
    return res;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cout<<fixed;
    cout.precision(2);

    int N;
    while(cin>>N) {
        Node trie;
        for(int i=0;i<N;i++) {string S;cin>>S;trie.insert(S,0);}

        cout<<double(solve(trie)+(trie.chd.size()==1?trie.cnt:0))/N<<'\n';
    }
}